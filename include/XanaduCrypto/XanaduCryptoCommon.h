//
// Created by Administrator on 2021/1/20.
//

#ifndef			_XANADU_CRYPTO_COMMON_H_
#define			_XANADU_CRYPTO_COMMON_H_

#include <XanaduCrypto/XanaduCryptoHeader.h>

/// A generic class for encryption and decryption.
/// This is the basis of all Xanadu series encryption and decryption libraries.
/// This collection provides common operations such as file reading and writing and result return.
class XANADU_CRYPTO_EXPORT XCryptoCommon
{
public:
	/// Structure
	XCryptoCommon() XANADU_NOTHROW;

	/// Virtual destructor
	virtual ~XCryptoCommon() XANADU_NOTHROW;

public:
	/// clear
	virtual void clear() XANADU_NOTHROW;

	/// result
	virtual XByteArray result() const XANADU_NOTHROW;
};

#endif /// _XANADU_CRYPTO_COMMON_H_
