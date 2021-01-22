#include "aes.h"
#include "modes.h"

//AES_cbc_encrypt
void AES_cbc_encrypt(const unsigned char* _In, unsigned char* _Out, size_t _Length, const AES_KEY* _Key, unsigned char* _ivec, const int _Enc)
{
	if(_Enc)
	{
		CRYPTO_cbc128_encrypt(_In, _Out, _Length, _Key, _ivec, (block128_f)AES_encrypt);
	}
	else
	{
		CRYPTO_cbc128_decrypt(_In, _Out, _Length, _Key, _ivec, (block128_f)AES_decrypt);
	}
}