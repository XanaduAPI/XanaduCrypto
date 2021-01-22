#include "aes.h"
#include "aes_locl.h"

//AES_ecb_encrypt
void AES_ecb_encrypt(const unsigned char* _In, unsigned char* _Out, const AES_KEY* _Key, const int _Enc)
{
	assert(_In && _Out && _Key);
	assert((AES_ENCRYPT == _Enc) || (AES_DECRYPT == _Enc));

	if(AES_ENCRYPT == _Enc)
	{
		AES_encrypt(_In, _Out, _Key);
	}
	else
	{
		AES_decrypt(_In, _Out, _Key);
	}
}