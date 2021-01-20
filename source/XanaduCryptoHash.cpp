//
// Created by Administrator on 2021/1/20.
//

#include <XanaduCrypto/XanaduCryptoHash.h>
#include "MD5/XanaduCryptoHashMD5.h"
#include "SHA1/XanaduCryptoHashSHA1.h"
#include "SHA2/XanaduCryptoHashSHA2.h"

class XCryptoHashPrivate
{
public:
	XCryptoHash::Algorithm		_Algorithm;
	union
	{
		XANADU_CRYPTO_MD5_CONTEXT	_MD5Context;
		XANADU_CRYPTO_SHA1_CONTEXT	_SHA1Context;
	};
	XByteArray			_Result;
};

/// Structure
XCryptoHash::XCryptoHash(Algorithm _Algorithm) XANADU_NOTHROW
{
	this->_Info = XANADU_NEW XCryptoHashPrivate();
	this->_Info->_Algorithm = _Algorithm;
	this->Reset();
}

/// Virtual destructor
XCryptoHash::~XCryptoHash() XANADU_NOTHROW
{
	XANADU_DELETE_PTR(this->_Info);
}




/// Empty data
void XCryptoHash::Reset() XANADU_NOTHROW
{
	switch (this->_Info->_Algorithm)
	{
		case MD5:
			Xanadu::MD5_Init(&(this->_Info->_MD5Context));
			break;
		case SHA1:
			Xanadu::sha1_begin(&(this->_Info->_SHA1Context));
			break;
	}
}

/// Add Data
void XCryptoHash::AppendData(const void* _Data, int64U _Length) XANADU_NOTHROW
{
	switch (this->_Info->_Algorithm)
	{
		case MD5:
			Xanadu::MD5_Update(&(this->_Info->_MD5Context), _Data, _Length);
			break;
		case SHA1:
			Xanadu::sha1_hash((const unsigned char*)_Data, _Length, &(this->_Info->_SHA1Context));
			break;
	}
}

/// Add Data
void XCryptoHash::AppendData(const XByteArray& _Bytes) XANADU_NOTHROW
{
	XCryptoHash::AppendData(_Bytes.data(), _Bytes.length());
}

/// View the results
XByteArray XCryptoHash::Result() const XANADU_NOTHROW
{
	if (this->_Info->_Result.isEmpty())
	{
		unsigned char 		vResult[128] = {0};
		switch (this->_Info->_Algorithm)
		{
			case MD5:
				Xanadu::MD5_Final(vResult, &(this->_Info->_MD5Context));
				break;
			case SHA1:
				Xanadu::sha1_end(vResult, &(this->_Info->_SHA1Context));
				break;
		}
		this->_Info->_Result = XByteArray((const char*)vResult, XCryptoHash::HashLength(this->_Info->_Algorithm));
	}
	return this->_Info->_Result;
}





/// Static method: Calculates the hash value
XByteArray XCryptoHash::Hash(const XByteArray& _Bytes, Algorithm _Algorithm) XANADU_NOTHROW
{
	auto		vClass = XCryptoHash(_Algorithm);
	auto		vResult = XByteArray();
	vClass.Reset();
	vClass.AppendData(_Bytes);
	vResult = vClass.Result();
	return XByteArray();
}

/// Static method: Calculates the hash value
XByteArray XCryptoHash::Hash(const XString& _File, Algorithm _Algorithm) XANADU_NOTHROW
{
	auto		vClass = XCryptoHash(_Algorithm);
	auto		vResult = XByteArray();
	auto		vHandle = Xanadu::wfopen(_File.data(), L"rb");
	if (vHandle)
	{
		auto		vMemory = XANADU_NEW char[XANADU_SIZE_MB];
		if(vMemory)
		{
			vClass.Reset();
			while(!Xanadu::feof(vHandle))
			{
				auto		vSync = Xanadu::fread(vMemory, 1, XANADU_SIZE_MB, vHandle);
				if(vSync <= 0)
				{
					break;
				}
				vClass.AppendData(vMemory, vSync);
			};
			vResult = vClass.Result();
			XANADU_DELETE_ARR(vMemory);
		}
		Xanadu::fclose(vHandle);
	}
	return XByteArray();
}

/// Static method: Gets the result length of the specified algorithm
int32S XCryptoHash::HashLength(Algorithm _Algorithm) XANADU_NOTHROW
{
	switch (_Algorithm)
	{
		case MD5:
			return 16;
		case SHA1:
			return 20;
		default:
			return 0;
	}
}
