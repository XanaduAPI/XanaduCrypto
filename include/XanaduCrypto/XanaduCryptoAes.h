#ifndef			_XANADU_CRYPTO_AES_H_
#define			_XANADU_CRYPTO_AES_H_

#include <XanaduCrypto/XanaduCryptoHeader.h>

// Some encryption and decryption in AES
class XANADU_CRYPTO_EXPORT XCryptoAes
{
public:
	// Structure
	XCryptoAes() noexcept;

	// Virtual destructor
	virtual ~XCryptoAes() noexcept;
};

#endif // _XANADU_CRYPTO_AES_H_
