#ifndef			_XANADU_CRYPTO_HEADER_H_
#define			_XANADU_CRYPTO_HEADER_H_

#include <XanaduRuntime/Xanadu.h>
#include <XanaduCore/Xanadu.h>

#ifndef			_XANADU_CRYPTO_BUILD_STATIC
#ifdef			_XANADU_CRYPTO_BUILD_SHARED
#if defined(_XANADU_SYSTEM_WINDOWS)
#define			XANADU_CRYPTO_EXPORT					__declspec(dllexport)
#else
#define			XANADU_CRYPTO_EXPORT					__attribute__((visibility("default")))
#endif
#else
#if defined(_XANADU_SYSTEM_WINDOWS)
#define			XANADU_CRYPTO_EXPORT					__declspec(dllimport)
#else
#define			XANADU_CRYPTO_EXPORT					__attribute__((visibility("default")))
#endif
#endif
#else
#define			XANADU_CRYPTO_EXPORT
#endif
#define			XANADU_CRYPTO_LOCAL

#endif
