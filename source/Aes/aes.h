#ifndef			_XANADU_FUNCTION_AES_HEADER_H_
#define			_XANADU_FUNCTION_AES_HEADER_H_

#include <XanaduCrypto/XanaduCryptoHeader.h>
#include <assert.h>

#define		AES_ENCRYPT			1
#define		AES_DECRYPT			0
#define		AES_MAXNR			14
#define		AES_BLOCK_SIZE			16

//aes_key_st
struct aes_key_st
{
#ifdef AES_LONG
	unsigned long rd_key[4 * (AES_MAXNR + 1)];
#else
	unsigned int rd_key[4 * (AES_MAXNR + 1)];
#endif
	int rounds;
};
typedef		struct aes_key_st		AES_KEY;

//AES_set_encrypt_key
int AES_set_encrypt_key(const unsigned char* _UserKey, const int _Bits, AES_KEY* _Key);

//AES_set_decrypt_key
int AES_set_decrypt_key(const unsigned char* _UserKey, const int _Bits, AES_KEY* _Key);

//AES_encrypt
void AES_encrypt(const unsigned char* _In, unsigned char* _Out, const AES_KEY* _Key);

//AES_decrypt
void AES_decrypt(const unsigned char* _In, unsigned char* _Out, const AES_KEY* _Key);

//AES_ecb_encrypt
void AES_ecb_encrypt(const unsigned char* _In, unsigned char* _Out, const AES_KEY* _Key, const int _Enc);

//AES_cbc_encrypt
void AES_cbc_encrypt(const unsigned char* _In, unsigned char* _Out, size_t _Length, const AES_KEY* _Key, unsigned char* _ivec, const int _Enc);

#endif//_XANADU_FUNCTION_AES_HEADER_H_