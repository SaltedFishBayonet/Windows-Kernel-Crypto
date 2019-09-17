#pragma once

// 应用层使用时注释下面这行，内核使用时启用这个
#define R0_MODEL_CRYPTO 1



#ifdef R0_MODEL_CRYPTO

extern "C" {
#include <ntddk.h>
}
#ifndef ExAllocatePool_

#define ExAllocatePool_(t,o)		ExAllocatePool((t),(o))
#define ExAllocatePool_2(o)			ExAllocatePool(NonPagedPool,(o))
#define ExFreePool_(t)				if((t)!=NULL) {ExFreePool((t));(t)=NULL;}

#endif // !ExAllocatePool_

#else

#include <iostream>
#include <windows.h>
#define ExAllocatePool_(t,o)		malloc((o))
#define ExAllocatePool_2(o)			malloc((o))
#define ExFreePool_(t)				if((t)!=NULL) {free((t));(t)=NULL;}

#ifndef ANSI_STRING
typedef struct _STRING {
	USHORT Length;
	USHORT MaximumLength;
	PCHAR Buffer;
} ANSI_STRING, *PANSI_STRING;
#endif // !ANSI_STRING

#ifndef POOL_TYPE
typedef enum _POOL_TYPE {
	NonPagedPool,
	NonPagedPoolExecute = NonPagedPool,
	PagedPool,
}  POOL_TYPE;
typedef enum _POOL_TYPE POOL_TYPE;
#endif // !POOL_TYPE

#ifndef RtlInitAnsiString
#define RtlInitAnsiString(p,str)	(p)->Buffer = (PCHAR)(str); (p)->Length = (p)->MaximumLength = (USHORT)strlen((str));
#endif // !RtlInitAnsiString

#ifndef DbgPrint
#define DbgPrint(formatStr,p)	{																			\
									char arr[1024] = { 0 };													\
									char *mid = strstr((char*)(formatStr), "%Z");							\
									memcpy(arr, (formatStr), mid - (formatStr));							\
									printf("%s", arr);														\
									for (auto i = 0; i < (p)->Length; ++i) std::cout << (p)->Buffer[i];		\
									memset(arr, 0, mid - formatStr);										\
									memcpy(arr, mid + 1, strlen((formatStr)) - (mid - (formatStr) + 1));	\
									printf("%s", arr);														\
								}
#endif // !DbgPrint
#endif // R0_MODEL_CRYPTO


namespace base64 {
	// Base 64 Table
	CONST CHAR _B64_TABLE[] = {
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
	'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
	'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
	'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
	'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
	'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
	'w', 'x', 'y', 'z', '0', '1', '2', '3',
	'4', '5', '6', '7', '8', '9', '+', '/'
	};

	UCHAR __GetIndexByValue(CHAR ch) {
		if (ch >= 'A' && ch <= 'Z') {
			return ch - 'A';
		}
		if (ch >= 'a'&& ch <= 'z') {
			return ch - 'a' + 26;
		}
		if (ch >= '0'&& ch <= '9') {
			return ch - '0' + 52;
		}
		if (ch == '+') {
			return 62;
		}
		if (ch == '/') {
			return 63;
		}
		return 0xFF; // ERROR Value
	}

	/* 需在外部手动释放  OUT PANSI_STRING out 中buffer的内存 */
	inline VOID Encode(OUT PANSI_STRING out, IN PANSI_STRING src, IN LONG shfit = 0, IN POOL_TYPE type = NonPagedPool) {
		USHORT oldSize = src->Length;
		USHORT outSize = ((oldSize + 2) / 3) * 4;
		out->Buffer = (PCHAR)ExAllocatePool_(type, outSize);
		RtlZeroMemory(out->Buffer, outSize);
		out->Length = outSize;
		out->MaximumLength = outSize;
		PUCHAR data = (PUCHAR)(src->Buffer);
		PUCHAR enc = (PUCHAR)(out->Buffer);
		ULONG j = 0;

		for (ULONG i = 0; i < oldSize; i += 3) {
			enc[j++] = _B64_TABLE[data[i] >> 2];
			if (i + 2 < oldSize) {	// 至少还剩 3 byte
				enc[j++] = _B64_TABLE[((data[i] & 0x03) << 4) + (data[i + 1] >> 4)];
				enc[j++] = _B64_TABLE[((data[i + 1] & 0x0F) << 2) + (data[i + 2] >> 6)];
				enc[j++] = _B64_TABLE[data[i + 2] & 0x3F];
			}
			else if (i + 1 < oldSize) {	// 剩 2 byte
				enc[j++] = _B64_TABLE[((data[i] & 0x03) << 4) + (data[i + 1] >> 4)];
				enc[j++] = _B64_TABLE[((data[i + 1] & 0x0F) << 2) + 0];
				enc[j++] = '=';
			}
			else {	// 剩 1 byte
				enc[j++] = _B64_TABLE[((data[i] & 0x03) << 4) + 0];
				enc[j++] = '=';
				enc[j++] = '=';
			}
		}
	}

	/* 需在外部 手动释放 OUT PANSI_STRING out 中 buffer 的内存  */
	inline VOID Decode(OUT PANSI_STRING out, IN PANSI_STRING enc, IN LONG shfit = 0, IN POOL_TYPE type = NonPagedPool) {
		USHORT encSize = enc->Length;
		PUCHAR data = (PUCHAR)(enc->Buffer);
		USHORT fix = 0;
		fix = data[encSize - 2] == '=' ? 2 : (data[encSize - 1] == '=' ? 1 : 0);
		USHORT outSize = (encSize / 4) * 3 - fix;
		out->Buffer = (PCHAR)ExAllocatePool_(type, outSize);
		RtlZeroMemory(out->Buffer, outSize);
		out->Length = outSize;
		out->MaximumLength = outSize;
		PUCHAR decode = (PUCHAR)(out->Buffer);
		ULONG j = 0;

		UCHAR ch2 = 0;
		UCHAR ch3 = 0;
		for (ULONG i = 0; i < encSize; i += 4) {
			ch2 = __GetIndexByValue(data[i + 1]);
			ch3 = __GetIndexByValue(data[i + 2]);

			decode[j++] = (__GetIndexByValue(data[i]) << 2) + (ch2 >> 4); // 解码得到1字符

			// 如果 不是最后4个字符的解码 ，则继续解码，得到后面2个字符
			// 或者 没有 = 的情况下(没有补位)，也继续解码后面2字符
			if (i + 4 < encSize || fix == 0) {
				decode[j++] = ((ch2 & 0x0F) << 4) + ((ch3 & 0x3C) >> 2);
				decode[j++] = ((ch3 & 0x03) << 6) + (__GetIndexByValue(data[i + 3]) & 0x3F);
			}
			else if (fix == 1) {
				// 最后4个字符 且 有一个 = 
				decode[j++] = ((ch2 & 0x0F) << 4) + ((ch3 & 0x3C) >> 2);
			}
			// 若遇到最后 2 个 = 时，只用生成一个明文字符，已经提出去了，这里不处理

		}
	}

	/* 使用示例 */
	//VOID Test_Base64() {
	//	ANSI_STRING str;
	//	RtlInitAnsiString(&str, "abc test 测试 123456");
	//	DbgPrint("输入(input):%Z \r\n", &str);

	//	ANSI_STRING cipher = { 0 };
	//	base64::Encode(&cipher, &str);
	//	DbgPrint("编码后(Encode):%Z \r\n", &cipher);

	//	ANSI_STRING decode = { 0 };
	//	base64::Decode(&decode, &cipher);
	//	DbgPrint("解码结果(Decode):%Z \r\n", &decode);

	//	ExFreePool_(cipher.Buffer);
	//	ExFreePool_(decode.Buffer);
	//}

}

