extern "C" {
#include <ntddk.h>
}
#include "crypto_base64.hpp"

/* 使用示例 */
VOID Test_Base64() {
	ANSI_STRING str;
	RtlInitAnsiString(&str, "abc test 测试 123456");
	DbgPrint("输入(input):%Z \r\n", &str);

	ANSI_STRING cipher = { 0 };
	base64::Encode(&cipher, &str);
	DbgPrint("编码后(Encode):%Z \r\n", &cipher);

	ANSI_STRING decode = { 0 };
	base64::Decode(&decode, &cipher);
	DbgPrint("解码结果(Decode):%Z \r\n", &decode);

	ExFreePool_(cipher.Buffer);
	ExFreePool_(decode.Buffer);
}

NTSTATUS DriverUnload(IN struct _DRIVER_OBJECT *pDri) {
	return STATUS_SUCCESS;
}

EXTERN_C NTSTATUS DriverEntry(PDRIVER_OBJECT pDri, PUNICODE_STRING regPath) {
	NTSTATUS status = STATUS_SUCCESS;
	pDri->DriverUnload = (PDRIVER_UNLOAD)DriverUnload;

	Test_Base64();

	return status;
}
