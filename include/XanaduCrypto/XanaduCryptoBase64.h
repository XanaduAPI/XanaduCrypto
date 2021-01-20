//
// Created by Administrator on 2021/1/20.
//

#ifndef			_XANADU_CRYPTO_BASE64_H_
#define			_XANADU_CRYPTO_BASE64_H_

#include <XanaduCrypto/XanaduCryptoHeader.h>

/// A Base64 - encoded operation library.
/// Provides encoding and decoding functions.
class XANADU_CRYPTO_EXPORT XCryptoBase64
{
public:
	/// Structure
	XCryptoBase64() XANADU_NOTHROW;

	/// Virtual destructor
	virtual ~XCryptoBase64() XANADU_NOTHROW;
};

#endif /// _XANADU_CRYPTO_BASE64_H_
