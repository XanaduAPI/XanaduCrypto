//
// Created by Administrator on 2021/1/20.
//

#include <XanaduCrypto/XanaduCryptoHash.h>
#include "MD5/XanaduCryptoHashMD5.h"
#include "SHA1/XanaduCryptoHashSHA1.h"
#include "SHA2/XanaduCryptoHashSHA2.h"

/// Structure
XCryptoHash::XCryptoHash(Algorithm _Algorithm) XANADU_NOTHROW
{
}

/// Virtual destructor
XCryptoHash::~XCryptoHash() XANADU_NOTHROW
{
}




/// Empty data
void XCryptoHash::Reset() XANADU_NOTHROW
{
}

/// Add Data
void XCryptoHash::AppendData(const void* _Data, int64U _Length) XANADU_NOTHROW
{
}

/// Add Data
void XCryptoHash::AppendData(const XByteArray& _Bytes) XANADU_NOTHROW
{
	XCryptoHash::AppendData(_Bytes.data(), _Bytes.length());
}

/// View the results
XByteArray XCryptoHash::Result() const XANADU_NOTHROW
{
	return XByteArray();
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
			return 32;
		case SHA1:
			return 40;
		default:
			return 0;
	}
}
