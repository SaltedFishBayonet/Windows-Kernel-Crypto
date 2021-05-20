<p align="center" >
    <a href="https://github.com/SaltedFishBayonet/Windows-Kernel-Crypto"><img src="http://120.53.223.74:8848/wkc.jpg" width="80%"></a>
</p>
<p align="center">
  <strong>Extensible,high-performance,single file,dependent kernel encryption solution for all Windows kernels</strong>
</p>
<p align="center">
  English | <a href="https://github.com/SaltedFishBayonet/Windows-Kernel-Crypto/blob/master/README_CN.md">简体中文</a>
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


Feature
=========================
- Cryptography library for the `Windows` kernel, also support application layer
- support `AES256`、`AES256+CBC`、`RSA512`、`RSA1024`、`RSA2048`
- Very pleasantly surprised, especially support `ECC256`, its performance is excellent, can replace the performance of a little less `RSA2048`
- As a base encoding, `base64` is also supported, of course
- The project is integrated into a single file with no annoying dependencies, configuration, just `#include "KernelCrypto.hpp"`
- 99% of the code is implemented in pure `C` language to ensure compatibility and stability, using only two `C++`related content, where`namespace` is only used for package management, and `.hpp`is used for integration into a single file, without any additional project configuration changes
- Refer to cryptography related papers, refer to the native implementation after `OpenSSL` and `OepnJDK` to resist known cryptography attacks
- In a large-scale physical machine test, no memory Leak has been found, and the`Visual Leak Detector` and `Continuous Integration` have passed
- A new experience, full of silky


Build
=========================
- Don't be picky about your environment, use your current development environment, if not, then just pay attention to the `Windows` version,`Windows SDK` version, `Visual Studio` version and `Windows Driver Kit` version,See:
<p align="left">
	<a target="_blank" href="https://docs.microsoft.com/en-us/windows-hardware/drivers/other-wdk-downloads">
		<img src="http://120.53.223.74:8848/Environment_English_blue.svg" />
	</a>
	<a target="_blank" href="https://docs.microsoft.com/zh-cn/windows-hardware/drivers/other-wdk-downloads">
		<img src="http://120.53.223.74:8848/Environment_Chinese_blue.svg" />
	</a>
</p>


Preview
=========================
base64: 
<p align="center">
<img  src="https://github.com/SaltedFishBayonet/Windows-Kernel-Crypto/blob/master/base64.gif" alt="Awesome-Cryptography">
</p>


FAQ
=========================
#### 1.Can a pure C kernel project be used?
Visual Studio is a C++ compiler by default, so you can use it directly.
If you really need the `.h`and`.c`file, then delete the`namespace`from them

#### 2.Which versions of Windows are available？
Applicable to all versions of `windows`, because it is a native implementation, independent of the system



Boss Look At This
=========================
- Except for the coding part, cryptography is not open source
- source + after-sales + continuous update, selling price `20000` RMB, do not support bargaining, if you are the one
- contact(Base64)：VGVuY2VudCBRUToxMDMxMTU0NzI0LCBFbWFpbDp1bnVzZWQwQHZpcC5xcS5jb20=
- Online Base64 decoding：
<p align="left">
	<a target="_blank" href="https://www.google.com/search?q=base64+online">
		<img src="http://120.53.223.74:8848/click_me_en.svg" />
	</a>
	<a target="_blank" href="https://cn.bing.com/search?q=base64+online">
		<img src="http://120.53.223.74:8848/click_me_ch.svg" />
	</a>
</p>

