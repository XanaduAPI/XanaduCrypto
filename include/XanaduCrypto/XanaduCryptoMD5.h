//
// Created by Administrator on 2021/1/20.
//

#ifndef			_XANADU_CRYPTO_MD5_H_
#define			_XANADU_CRYPTO_MD5_H_

#include <XanaduCrypto/XanaduCryptoHeader.h>
#include <XanaduCrypto/XanaduCryptoCommon.h>

/// An MD5 - encoded operation library.
/// Provides encoding and violence enumeration decoding function.
class XANADU_CRYPTO_EXPORT XCryptoMD5 : public XCryptoCommon
{
public:
	/// Structure
	XCryptoMD5() XANADU_NOTHROW;

	/// Virtual destructor
	virtual ~XCryptoMD5() XANADU_NOTHROW;
};

#endif /// _XANADU_CRYPTO_MD5_H_
