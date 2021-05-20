<p align="center" >
    <a href="https://github.com/SaltedFishBayonet/Windows-Kernel-Crypto"><img src="http://120.53.223.74:8848/wkc.jpg" width="80%"></a>
</p>
<p align="center">
  <strong>适用于所有windows内核的可扩展、高性能、单文件、无依赖的内核加密解决方案</strong>
</p>
<p align="center">
  <a href="https://github.com/SaltedFishBayonet/Windows-Kernel-Crypto">English</a> | 简体中文
</p>

<p align="center">
	<a target="_blank" href="https://github.com/SaltedFishBayonet/Windows-Kernel-Crypto">
		<img src="http://120.53.223.74:8848/win_version.svg" />
	</a>
	<a target="_blank" href="https://github.com/SaltedFishBayonet/Windows-Kernel-Crypto">
		<img src="http://120.53.223.74:8848/License_Apache_2_0.svg" />
	</a>
	<a target="_blank" href="https://github.com/SaltedFishBayonet/Windows-Kernel-Crypto">
		<img src="http://120.53.223.74:8848/License_Anti_996_blue.svg" />
	</a>
	<a target="_blank" href="https://996.icu">
		<img src="http://120.53.223.74:8848/link_996_icu.svg" />
	</a>
	<a target="_blank" href="https://github.com/SaltedFishBayonet/Windows-Kernel-Crypto">
		<img src="http://120.53.223.74:8848/code_quality.svg" />
	</a>
	<a target="_blank" href="https://github.com/SaltedFishBayonet/Windows-Kernel-Crypto">
		<img src="http://120.53.223.74:8848/ci_passing.svg" />
</p>



特性
=========================
- 用于`windows`内核的密码学库，也支持应用层
- 支持`AES256`、`AES256+CBC`、`RSA512`、`RSA1024`、`RSA2048`
- 非常惊喜，特别支持了`ECC256`，它的性能表现极佳，可以代替性能略显欠缺的`RSA2048`
- 作为基础编码，当然也支持`base64`
- 项目整合到单文件形式，没有令人头疼的依赖、配置，只需要`#include "KernelCrypto.hpp"`
- 基本用纯粹的C语言实现，保证兼容性和稳定性，仅用到2个了`C++`相关的内容，其中`namespace`仅用于包管理，而`.hpp`用于整合到单文件，无需任何额外的项目配置改动
- 查阅密码学相关论文，参考`OpenSSL`和`OepnJDK`后的原生实现，抵御已知密码学攻击
- 在大规模的物理机上测试，无内存泄露，并通过了`Visual Leak Detector`、`Continuous Integration`
- 全新体验，尽享丝滑



编译环境
=========================
- 对环境不挑剔，使用你现在的开发环境即可，如果没有，那么仅需注意`Windows` 版本、`Windows SDK`版本、`Visual Studio` 版本和 `Windows Driver Kit` 版本，详见：
<p align="left">
	<a target="_blank" href="https://docs.microsoft.com/en-us/windows-hardware/drivers/other-wdk-downloads">
		<img src="http://120.53.223.74:8848/Environment_English_blue.svg" />
	</a>
	<a target="_blank" href="https://docs.microsoft.com/zh-cn/windows-hardware/drivers/other-wdk-downloads">
		<img src="http://120.53.223.74:8848/Environment_Chinese_blue.svg" />
	</a>
</p>



预览
=========================
base64: 
<p align="center">
<img  src="https://github.com/SaltedFishBayonet/Windows-Kernel-Crypto/blob/master/base64.gif" alt="Awesome-Cryptography">
</p>



常见问题解答
=========================
#### 1.纯C的内核项目可以使用么？
VIsual Studio默认是C++编译器，所以可以直接使用。
如果确实需要`.h`和`.c`形式，那么删掉其中的`namespace`即可

#### 2.适用于哪些windows版本？
适用于`windows`所有版本，因为是原生实现，无关系统



老板看这里
=========================
- 除了编码部分，密码学并不开源
- 源码+售后+持续更新，售价`20000`RMB，不支持讲价，非诚勿扰
- 联系方式(Base64)：VGVuY2VudCBRUToxMDMxMTU0NzI0LCBFbWFpbDp1bnVzZWQwQHZpcC5xcS5jb20=
- 在线base64解码：
<p align="left">
	<a target="_blank" href="https://www.google.com/search?q=base64+online">
		<img src="http://120.53.223.74:8848/click_me_en.svg" />
	</a>
	<a target="_blank" href="https://cn.bing.com/search?q=base64+online">
		<img src="http://120.53.223.74:8848/click_me_ch.svg" />
	</a>
</p>


