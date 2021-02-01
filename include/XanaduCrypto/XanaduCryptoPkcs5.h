#ifndef			_XANADU_CRYPTO_PKCS5_H_
#define			_XANADU_CRYPTO_PKCS5_H_

#include <XanaduCrypto/XanaduCryptoHeader.h>

/// Some encryption and decryption in PKCS5
class XANADU_CRYPTO_EXPORT XCryptoPkcs5
{
public:
	/// Structure
	XCryptoPkcs5() XANADU_NOTHROW;

	/// Virtual destructor
	virtual ~XCryptoPkcs5() XANADU_NOTHROW;

public:
	/// 计算
	static XByteArray PBKDF2(const XByteArray& _Salt, const XByteArray& _Password, int32U _IterationCount) XANADU_NOTHROW;
};

#endif /// _XANADU_CRYPTO_PKCS5_H_
