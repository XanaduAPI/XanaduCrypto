#include "modes.h"

#if !defined(STRICT_ALIGNMENT) && !defined(PEDANTIC)
# define STRICT_ALIGNMENT 0
#endif

//CRYPTO_cbc128_encrypt
void CRYPTO_cbc128_encrypt(const unsigned char* _In, unsigned char* _Out, size_t _Length, const void* _Key, unsigned char _ivec[16], block128_f _Block)
{
	size_t n;
	const unsigned char* iv = _ivec;

	if(_Length == 0)
		return;

#if !defined(OPENSSL_SMALL_FOOTPRINT)
	if(STRICT_ALIGNMENT && ((size_t)_In | (size_t)_Out | (size_t)_ivec) % sizeof(size_t) != 0)
	{
		while(_Length >= 16)
		{
			for(n = 0; n < 16; ++n)
				_Out[n] = _In[n] ^ iv[n];
			(*_Block) (_Out, _Out, _Key);
			iv = _Out;
			_Length -= 16;
			_In += 16;
			_Out += 16;
		}
	}
	else
	{
		while(_Length >= 16)
		{
			for(n = 0; n < 16; n += sizeof(size_t))
				*(size_t*)(_Out + n) =
				*(size_t*)(_In + n) ^ *(size_t*)(iv + n);
			(*_Block) (_Out, _Out, _Key);
			iv = _Out;
			_Length -= 16;
			_In += 16;
			_Out += 16;
		}
	}
#endif
	while(_Length)
	{
		for(n = 0; n < 16 && n < _Length; ++n)
			_Out[n] = _In[n] ^ iv[n];
		for(; n < 16; ++n)
			_Out[n] = iv[n];
		(*_Block) (_Out, _Out, _Key);
		iv = _Out;
		if(_Length <= 16)
			break;
		_Length -= 16;
		_In += 16;
		_Out += 16;
	}
	memcpy(_ivec, iv, 16);
}

//CRYPTO_cbc128_decrypt
void CRYPTO_cbc128_decrypt(const unsigned char* _In, unsigned char* _Out, size_t _Length, const void* _Key, unsigned char _ivec[16], block128_f _Block)
{
	size_t n;
	union
	{
		size_t t[16 / sizeof(size_t)];
		unsigned char c[16];
	} tmp;

	if(_Length == 0)
		return;

#if !defined(OPENSSL_SMALL_FOOTPRINT)
	if(_In != _Out)
	{
		const unsigned char* iv = _ivec;

		if(STRICT_ALIGNMENT && ((size_t)_In | (size_t)_Out | (size_t)_ivec) % sizeof(size_t) != 0)
		{
			while(_Length >= 16)
			{
				(*_Block) (_In, _Out, _Key);
				for(n = 0; n < 16; ++n)
					_Out[n] ^= iv[n];
				iv = _In;
				_Length -= 16;
				_In += 16;
				_Out += 16;
			}
		}
		else if(16 % sizeof(size_t) == 0)
		{ /* always true */
			while(_Length >= 16)
			{
				size_t* out_t = (size_t*)_Out, * iv_t = (size_t*)iv;

				(*_Block) (_In, _Out, _Key);
				for(n = 0; n < 16 / sizeof(size_t); n++)
					out_t[n] ^= iv_t[n];
				iv = _In;
				_Length -= 16;
				_In += 16;
				_Out += 16;
			}
		}
		memcpy(_ivec, iv, 16);
	}
	else
	{
		if(STRICT_ALIGNMENT &&
			((size_t)_In | (size_t)_Out | (size_t)_ivec) % sizeof(size_t) != 0)
		{
			unsigned char c;
			while(_Length >= 16)
			{
				(*_Block) (_In, tmp.c, _Key);
				for(n = 0; n < 16; ++n)
				{
					c = _In[n];
					_Out[n] = tmp.c[n] ^ _ivec[n];
					_ivec[n] = c;
				}
				_Length -= 16;
				_In += 16;
				_Out += 16;
			}
		}
		else if(16 % sizeof(size_t) == 0)
		{ /* always true */
			while(_Length >= 16)
			{
				size_t c, * out_t = (size_t*)_Out, * ivec_t = (size_t*)_ivec;
				const size_t* in_t = (const size_t*)_In;

				(*_Block) (_In, tmp.c, _Key);
				for(n = 0; n < 16 / sizeof(size_t); n++)
				{
					c = in_t[n];
					out_t[n] = tmp.t[n] ^ ivec_t[n];
					ivec_t[n] = c;
				}
				_Length -= 16;
				_In += 16;
				_Out += 16;
			}
		}
	}
#endif
	while(_Length)
	{
		unsigned char c;
		(*_Block) (_In, tmp.c, _Key);
		for(n = 0; n < 16 && n < _Length; ++n)
		{
			c = _In[n];
			_Out[n] = tmp.c[n] ^ _ivec[n];
			_ivec[n] = c;
		}
		if(_Length <= 16)
		{
			for(; n < 16; ++n)
				_ivec[n] = _In[n];
			break;
		}
		_Length -= 16;
		_In += 16;
		_Out += 16;
	}
}