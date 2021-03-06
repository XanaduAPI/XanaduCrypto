#ifndef			_XANADU_CRYPTO_CBC_H_
#define			_XANADU_CRYPTO_CBC_H_

#include <XanaduCrypto/XanaduCryptoHeader.h>

// Some encryption and decryption in CBC
class XANADU_CRYPTO_EXPORT XCryptoCbc
{
public:
	// Structure
	XCryptoCbc() noexcept;

	// Virtual destructor
	virtual ~XCryptoCbc() noexcept;

public:
	// 加密ZeroPadding
	static XByteArray EncryptZero(const unsigned char* _Key, const unsigned char* _IV, const void* _Buffer, int32S _Length) noexcept;

	// 解密ZeroPadding
	static XByteArray DecryptZero(const unsigned char* _Key, const unsigned char* _IV, const void* _Buffer, int32S _Length) noexcept;

	// 加密ZeroPadding
	static XByteArray EncryptZero(const unsigned char* _Key, const unsigned char* _IV, const XByteArray& _Buffer) noexcept;

	// 解密ZeroPadding
	static XByteArray DecryptZero(const unsigned char* _Key, const unsigned char* _IV, const XByteArray& _Buffer) noexcept;

	// 加密PKCS5Padding
	static XByteArray EncryptPKCS5(const unsigned char* _Key, const unsigned char* _IV, const void* _Buffer, int32S _Length) noexcept;

	// 解密PKCS5Padding
	static XByteArray DecryptPKCS5(const unsigned char* _Key, const unsigned char* _IV, const void* _Buffer, int32S _Length) noexcept;

	// 加密PKCS5Padding
	static XByteArray EncryptPKCS5(const unsigned char* _Key, const unsigned char* _IV, const XByteArray& _Buffer) noexcept;

	// 解密PKCS5Padding
	static XByteArray DecryptPKCS5(const unsigned char* _Key, const unsigned char* _IV, const XByteArray& _Buffer) noexcept;

	// 加密PKCS7Padding
	static XByteArray EncryptPKCS7(const unsigned char* _Key, const unsigned char* _IV, const void* _Buffer, int32S _Length) noexcept;

	// 解密PKCS7Padding
	static XByteArray DecryptPKCS7(const unsigned char* _Key, const unsigned char* _IV, const void* _Buffer, int32S _Length) noexcept;

	// 加密PKCS7Padding
	static XByteArray EncryptPKCS7(const unsigned char* _Key, const unsigned char* _IV, const XByteArray& _Buffer) noexcept;

	// 解密PKCS7Padding
	static XByteArray DecryptPKCS7(const unsigned char* _Key, const unsigned char* _IV, const XByteArray& _Buffer) noexcept;
};

#endif // _XANADU_CRYPTO_CBC_H_
