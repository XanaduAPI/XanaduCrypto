#ifndef			_XANADU_CRYPTO_HEADER_H_
#define			_XANADU_CRYPTO_HEADER_H_

#include <XanaduRuntime/XanaduRuntime.h>
#include <XanaduCore/XanaduCore.h>

#ifndef			_XANADU_CRYPTO_BUILD_STATIC
#ifdef			_XANADU_CRYPTO_BUILD_SHARED
#ifdef XANADU_SYSTEM_WINDOWS
#define			XANADU_CRYPTO_EXPORT					__declspec(dllexport)
#else
#define			XANADU_CRYPTO_EXPORT					__attribute__((visibility("default")))
#endif // XANADU_SYSTEM_WINDOWS
#else
#ifdef XANADU_SYSTEM_WINDOWS
#define			XANADU_CRYPTO_EXPORT					__declspec(dllimport)
#else
#define			XANADU_CRYPTO_EXPORT					__attribute__((visibility("default")))
#endif // XANADU_SYSTEM_WINDOWS
#endif // _XANADU_CRYPTO_BUILD_SHARED
#else
#define			XANADU_CRYPTO_EXPORT
#endif // _XANADU_CRYPTO_BUILD_STATIC
#define			XANADU_CRYPTO_LOCAL

#endif // _XANADU_CRYPTO_HEADER_H_
