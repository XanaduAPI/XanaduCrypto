#ifndef			_XANADU_CRYPTO_PKCS5_H_
#define			_XANADU_CRYPTO_PKCS5_H_

#include <XanaduCrypto/Header.h>

// Some encryption and decryption in PKCS5
class XANADU_CRYPTO_EXPORT XCryptoPkcs5
{
public:
	// Structure
	XCryptoPkcs5() noexcept;

	// Virtual destructor
	virtual ~XCryptoPkcs5() noexcept;

public:
	// 计算
	static XByteArray PBKDF2(const XByteArray& _Salt, const XByteArray& _Password, int32U _IterationCount) noexcept;
};

#endif
