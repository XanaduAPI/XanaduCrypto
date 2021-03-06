#include <XanaduCrypto/XanaduCryptoCbc.h>
#include "Aes/aes.h"

XCryptoCbc::XCryptoCbc() noexcept
{
}

XCryptoCbc::~XCryptoCbc() noexcept
{
}



// 加密ZeroPadding
XByteArray XCryptoCbc::EncryptZero(const unsigned char* _Key, const unsigned char* _IV, const void* _Buffer, int32S _Length) noexcept
{
	return XCryptoCbc::EncryptZero(_Key, _IV, XByteArray((const char*)_Buffer, _Length));
}

// 解密ZeroPadding
XByteArray XCryptoCbc::DecryptZero(const unsigned char* _Key, const unsigned char* _IV, const void* _Buffer, int32S _Length) noexcept
{
	return XCryptoCbc::DecryptZero(_Key, _IV, XByteArray((const char*)_Buffer, _Length));
}

// 加密ZeroPadding
XByteArray XCryptoCbc::EncryptZero(const unsigned char* _Key, const unsigned char* _IV, const XByteArray& _Buffer) noexcept
{
	XANADU_CHECK_RETURN(_Key, XByteArray());
	XANADU_CHECK_RETURN(_IV, XByteArray());

	unsigned char	vIV[AES_BLOCK_SIZE] = { 0 };
	AES_KEY		vHandle;
	if(AES_set_encrypt_key(_Key, 256, &vHandle) < 0)
	{
		return XByteArray();
	}
	//ZeroPadding
	auto		vSync = XByteArray();
	auto		vLength = ((_Buffer.size() / AES_BLOCK_SIZE) + 1) * AES_BLOCK_SIZE;
	auto		vBufferIN = XANADU_NEW unsigned char[vLength];
	auto		vBufferOUT = XANADU_NEW unsigned char[vLength];

	if(vBufferIN && vBufferOUT)
	{
		Xanadu::memcpy(vIV, _IV, AES_BLOCK_SIZE);
		Xanadu::memset(vBufferIN, 0, vLength);
		Xanadu::memcpy(vBufferIN, _Buffer.data(), _Buffer.size());
		Xanadu::memset(vBufferOUT, 0, vLength);

		AES_cbc_encrypt(vBufferIN, vBufferOUT, _Buffer.size(), &vHandle, vIV, AES_ENCRYPT);
		vSync = XByteArray((const char*)vBufferOUT, _Buffer.size());
	}
	XANADU_DELETE_ARR(vBufferIN);
	XANADU_DELETE_ARR(vBufferOUT);
	return vSync;
}

// 解密ZeroPadding
XByteArray XCryptoCbc::DecryptZero(const unsigned char* _Key, const unsigned char* _IV, const XByteArray& _Buffer) noexcept
{
	XANADU_CHECK_RETURN(_Key, XByteArray());
	XANADU_CHECK_RETURN(_IV, XByteArray());

	XANADU_CHECK_RETURN(_Key, XByteArray());
	XANADU_CHECK_RETURN(_IV, XByteArray());

	unsigned char	vIV[AES_BLOCK_SIZE] = { 0 };
	AES_KEY		vHandle;
	if(AES_set_decrypt_key(_Key, 256, &vHandle) < 0)
	{
		return XByteArray();
	}

	//ZeroPadding
	auto		vSync = XByteArray();
	auto		vLength = _Buffer.size() + AES_BLOCK_SIZE;
	auto		vBufferIN = XANADU_NEW unsigned char[vLength];
	auto		vBufferOUT = XANADU_NEW unsigned char[vLength];

	if(vBufferIN && vBufferOUT)
	{
		Xanadu::memcpy(vIV, _IV, AES_BLOCK_SIZE);
		Xanadu::memset(vBufferIN, 0, vLength);
		Xanadu::memcpy(vBufferIN, _Buffer.data(), _Buffer.size());
		Xanadu::memset(vBufferOUT, 0, vLength);

		AES_cbc_encrypt(vBufferIN, vBufferOUT, _Buffer.size(), &vHandle, vIV, AES_DECRYPT);
		vSync = XByteArray((const char*)vBufferOUT, _Buffer.size());
	}
	XANADU_DELETE_ARR(vBufferIN);
	XANADU_DELETE_ARR(vBufferOUT);
	return vSync;
}

// 加密PKCS5Padding
XByteArray XCryptoCbc::EncryptPKCS5(const unsigned char* _Key, const unsigned char* _IV, const void* _Buffer, int32S _Length) noexcept
{
	return XCryptoCbc::EncryptPKCS5(_Key, _IV, XByteArray((const char*)_Buffer, _Length));
}

// 解密PKCS5Padding
XByteArray XCryptoCbc::DecryptPKCS5(const unsigned char* _Key, const unsigned char* _IV, const void* _Buffer, int32S _Length) noexcept
{
	return XCryptoCbc::DecryptPKCS5(_Key, _IV, XByteArray((const char*)_Buffer, _Length));
}

// 加密PKCS5Padding
XByteArray XCryptoCbc::EncryptPKCS5(const unsigned char* _Key, const unsigned char* _IV, const XByteArray& _Buffer) noexcept
{
	XANADU_CHECK_RETURN(_Key, XByteArray());
	XANADU_CHECK_RETURN(_IV, XByteArray());

	unsigned char	vIV[AES_BLOCK_SIZE] = { 0 };
	AES_KEY		vHandle;
	if(AES_set_encrypt_key(_Key, 256, &vHandle) < 0)
	{
		return XByteArray();
	}
	//PKCS5Padding
	auto		vSync = XByteArray();
	auto		vLength = ((_Buffer.size() / AES_BLOCK_SIZE) + 1) * AES_BLOCK_SIZE;
	auto		vBufferIN = XANADU_NEW unsigned char[vLength];
	auto		vBufferOUT = XANADU_NEW unsigned char[vLength];

	if(vBufferIN && vBufferOUT)
	{
		Xanadu::memcpy(vIV, _IV, AES_BLOCK_SIZE);
		Xanadu::memset(vBufferIN, AES_BLOCK_SIZE - (_Buffer.size() % AES_BLOCK_SIZE), vLength);
		Xanadu::memcpy(vBufferIN, _Buffer.data(), _Buffer.size());
		Xanadu::memset(vBufferOUT, 0, vLength);

		AES_cbc_encrypt(vBufferIN, vBufferOUT, vLength, &vHandle, vIV, AES_ENCRYPT);
		vSync = XByteArray((const char*)vBufferOUT, vLength);
	}
	XANADU_DELETE_ARR(vBufferIN);
	XANADU_DELETE_ARR(vBufferOUT);
	return vSync;
}

// 解密PKCS5Padding
XByteArray XCryptoCbc::DecryptPKCS5(const unsigned char* _Key, const unsigned char* _IV, const XByteArray& _Buffer) noexcept
{
	XANADU_CHECK_RETURN(_Key, XByteArray());
	XANADU_CHECK_RETURN(_IV, XByteArray());

	XANADU_CHECK_RETURN(_Key, XByteArray());
	XANADU_CHECK_RETURN(_IV, XByteArray());

	unsigned char	vIV[AES_BLOCK_SIZE] = { 0 };
	AES_KEY		vHandle;
	if(AES_set_decrypt_key(_Key, 256, &vHandle) < 0)
	{
		return XByteArray();
	}

	//PKCS5Padding
	auto		vSync = XByteArray();
	auto		vLength = _Buffer.size() + AES_BLOCK_SIZE;
	auto		vBufferIN = XANADU_NEW unsigned char[vLength];
	auto		vBufferOUT = XANADU_NEW unsigned char[vLength];

	if(vBufferIN && vBufferOUT)
	{
		Xanadu::memcpy(vIV, _IV, AES_BLOCK_SIZE);
		Xanadu::memset(vBufferIN, 0, vLength);
		Xanadu::memcpy(vBufferIN, _Buffer.data(), _Buffer.size());
		Xanadu::memset(vBufferOUT, 0, vLength);

		AES_cbc_encrypt(vBufferIN, vBufferOUT, _Buffer.size(), &vHandle, vIV, AES_DECRYPT);
		vSync = XByteArray((const char*)vBufferOUT, _Buffer.size() - vBufferOUT[_Buffer.size() - 1]);
	}
	XANADU_DELETE_ARR(vBufferIN);
	XANADU_DELETE_ARR(vBufferOUT);
	return vSync;
}

// 加密PKCS7Padding
XByteArray XCryptoCbc::EncryptPKCS7(const unsigned char* _Key, const unsigned char* _IV, const void* _Buffer, int32S _Length) noexcept
{
	return XCryptoCbc::EncryptPKCS7(_Key, _IV, XByteArray((const char*)_Buffer, _Length));
}

// 解密PKCS7Padding
XByteArray XCryptoCbc::DecryptPKCS7(const unsigned char* _Key, const unsigned char* _IV, const void* _Buffer, int32S _Length) noexcept
{
	return XCryptoCbc::DecryptPKCS7(_Key, _IV, XByteArray((const char*)_Buffer, _Length));
}

// 加密PKCS7Padding
XByteArray XCryptoCbc::EncryptPKCS7(const unsigned char* _Key, const unsigned char* _IV, const XByteArray& _Buffer) noexcept
{
	XANADU_CHECK_RETURN(_Key, XByteArray());
	XANADU_CHECK_RETURN(_IV, XByteArray());

	unsigned char	vIV[AES_BLOCK_SIZE] = { 0 };
	AES_KEY		vHandle;
	if(AES_set_encrypt_key(_Key, 256, &vHandle) < 0)
	{
		return XByteArray();
	}
	//PKCS7Padding
	auto		vSync = XByteArray();
	auto		vLength = ((_Buffer.size() / AES_BLOCK_SIZE) + 1) * AES_BLOCK_SIZE;
	auto		vBufferIN = XANADU_NEW unsigned char[vLength];
	auto		vBufferOUT = XANADU_NEW unsigned char[vLength];

	if(vBufferIN && vBufferOUT)
	{
		Xanadu::memcpy(vIV, _IV, AES_BLOCK_SIZE);
		Xanadu::memset(vBufferIN, AES_BLOCK_SIZE - (_Buffer.size() % AES_BLOCK_SIZE), vLength);
		Xanadu::memcpy(vBufferIN, _Buffer.data(), _Buffer.size());
		Xanadu::memset(vBufferOUT, 0, vLength);

		AES_cbc_encrypt(vBufferIN, vBufferOUT, vLength, &vHandle, vIV, AES_ENCRYPT);
		vSync = XByteArray((const char*)vBufferOUT, vLength);
	}
	XANADU_DELETE_ARR(vBufferIN);
	XANADU_DELETE_ARR(vBufferOUT);
	return vSync;
}

// 解密PKCS7Padding
XByteArray XCryptoCbc::DecryptPKCS7(const unsigned char* _Key, const unsigned char* _IV, const XByteArray& _Buffer) noexcept
{
	XANADU_CHECK_RETURN(_Key, XByteArray());
	XANADU_CHECK_RETURN(_IV, XByteArray());

	XANADU_CHECK_RETURN(_Key, XByteArray());
	XANADU_CHECK_RETURN(_IV, XByteArray());

	unsigned char	vIV[AES_BLOCK_SIZE] = { 0 };
	AES_KEY		vHandle;
	if(AES_set_decrypt_key(_Key, 256, &vHandle) < 0)
	{
		return XByteArray();
	}

	//PKCS7Padding
	auto		vSync = XByteArray();
	auto		vLength = _Buffer.size() + AES_BLOCK_SIZE;
	auto		vBufferIN = XANADU_NEW unsigned char[vLength];
	auto		vBufferOUT = XANADU_NEW unsigned char[vLength];

	if(vBufferIN && vBufferOUT)
	{
		Xanadu::memcpy(vIV, _IV, AES_BLOCK_SIZE);
		Xanadu::memset(vBufferIN, 0, vLength);
		Xanadu::memcpy(vBufferIN, _Buffer.data(), _Buffer.size());
		Xanadu::memset(vBufferOUT, 0, vLength);

		AES_cbc_encrypt(vBufferIN, vBufferOUT, _Buffer.size(), &vHandle, vIV, AES_DECRYPT);
		vSync = XByteArray((const char*)vBufferOUT, _Buffer.size() - vBufferOUT[_Buffer.size() - 1]);
	}
	XANADU_DELETE_ARR(vBufferIN);
	XANADU_DELETE_ARR(vBufferOUT);
	return vSync;
}
