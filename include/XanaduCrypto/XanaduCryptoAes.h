#ifndef			_XANADU_CRYPTO_AES_H_
#define			_XANADU_CRYPTO_AES_H_

#include <XanaduCrypto/XanaduCryptoHeader.h>

/// Some encryption and decryption in AES
class XANADU_CRYPTO_EXPORT XCryptoAes
{
public:
	/// Structure
	XCryptoAes() XANADU_NOTHROW;

	/// Virtual destructor
	virtual ~XCryptoAes() XANADU_NOTHROW;
};

#endif /// _XANADU_CRYPTO_AES_H_
