#ifndef			_XANADU_FUNCTION_AES_PKCS5_PBKDF2_HMAC_H_
#define			_XANADU_FUNCTION_AES_PKCS5_PBKDF2_HMAC_H_

#include <XanaduCrypto/XanaduCryptoHeader.h>

//PKCS5_PBKDF2_HMAC
void PKCS5_PBKDF2_HMAC(const unsigned char* _Password, size_t _LenPW, const unsigned char* _Salt, size_t _LenSA, const unsigned long _IterationCount, const unsigned long _LeyLength, unsigned char* _Output);

#endif//_XANADU_FUNCTION_AES_PKCS5_PBKDF2_HMAC_H_