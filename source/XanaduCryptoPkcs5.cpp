﻿//
// Created by Administrator on 2021/1/14.
//

#include <XanaduCrypto/XanaduCryptoPkcs5.h>
#include "Aes/PKCS5_PBKDF2_HMAC.h"

XCryptoPkcs5::XCryptoPkcs5() XANADU_NOTHROW
{
}

XCryptoPkcs5::~XCryptoPkcs5() XANADU_NOTHROW
{
}



/// 计算
XByteArray XCryptoPkcs5::PBKDF2(const XByteArray& _Salt, const XByteArray& _Password, int32U _IterationCount) XANADU_NOTHROW
{
	char			vBuffer[XANADU_PATH] = { 0 };
	unsigned char		vOutput[20] = { 0 };
	PKCS5_PBKDF2_HMAC((const unsigned char*)_Password.data(), _Password.size(), (const unsigned char*)_Salt.data(), _Salt.size(), _IterationCount, 20, vOutput);

	for(auto vIndex = 0; vIndex < 20; ++vIndex)
	{
		sprintf(vBuffer + (vIndex * 2), "%02X", vOutput[vIndex]);
	}
	return XByteArray((const char*)vBuffer);
}
