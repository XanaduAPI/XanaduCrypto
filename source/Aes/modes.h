#ifndef			_XANADU_FUNCTION_AES_MODES_HEADER_H_
#define			_XANADU_FUNCTION_AES_MODES_HEADER_H_

#include <XanaduCrypto/Header.h>

typedef void (*block128_f) (const unsigned char _In[16], unsigned char _Out[16], const void* _Key);

typedef void (*cbc128_f) (const unsigned char* _In, unsigned char* _Out, size_t _Length, const void* _Key, unsigned char _ivec[16], int _Enc);

//CRYPTO_cbc128_encrypt
void CRYPTO_cbc128_encrypt(const unsigned char* _In, unsigned char* _Out, size_t _Length, const void* _Key, unsigned char _ivec[16], block128_f _Block);

//CRYPTO_cbc128_decrypt
void CRYPTO_cbc128_decrypt(const unsigned char* _In, unsigned char* _Out, size_t _Length, const void* _Key, unsigned char _ivec[16], block128_f _Block);

#endif//_XANADU_FUNCTION_AES_MODES_HEADER_H_