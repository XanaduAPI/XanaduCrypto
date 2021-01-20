﻿/*
 * This is an OpenSSL-compatible implementation of the RSA Data Security, Inc.
 * MD5 Message-Digest Algorithm (RFC 1321).
 */

#ifndef			_XANADU_CRYPTO_HASH_MD5_H_
#define			_XANADU_CRYPTO_HASH_MD5_H_

#include <XanaduCrypto/XanaduCryptoHeader.h>

/// MD5 context
typedef struct _XANADU_CRYPTO_MD5_CONTEXT
{
	int32U			lo;
	int32U			hi;
	int32U			a;
	int32U			b;
	int32U			c;
	int32U			d;
	unsigned char		buffer[64];
	int32U			block[16];
}XANADU_CRYPTO_MD5_CONTEXT;

namespace Xanadu
{
	/// MD5 initialization
	XANADU_CRYPTO_EXPORT void XANADUAPI MD5_Init(XANADU_CRYPTO_MD5_CONTEXT* _Context) XANADU_NOTHROW;

	/// MD5 updates the data
	XANADU_CRYPTO_EXPORT void XANADUAPI MD5_Update(XANADU_CRYPTO_MD5_CONTEXT* _Context, const void* _Data, int64U _Size) XANADU_NOTHROW;

	/// MD5 retrieves the results
	XANADU_CRYPTO_EXPORT void XANADUAPI MD5_Final(unsigned char* _Result, XANADU_CRYPTO_MD5_CONTEXT* _Context) XANADU_NOTHROW;
};

#endif /// _XANADU_CRYPTO_HASH_MD5_H_
