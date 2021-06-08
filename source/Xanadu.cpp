#include <XanaduCrypto/Xanadu.h>

bool XANADUAPI Xanadu_Crypto_Initialize() noexcept
{
	return true;
};

void XANADUAPI Xanadu_Crypto_Release() noexcept
{
};


#ifdef XANADU_SYSTEM_WINDOWS
extern "C" BOOL WINAPI DllMain(HANDLE _HDllHandle, DWORD _Reason, LPVOID _Reserved)
{
	XANADU_UNPARAMETER(_HDllHandle);
	XANADU_UNPARAMETER(_Reserved);

	switch(_Reason)
	{
		case DLL_PROCESS_ATTACH:
			Xanadu_Crypto_Initialize();
			break;
		case DLL_THREAD_ATTACH:
			break;
		case DLL_THREAD_DETACH:
			break;
		case DLL_PROCESS_DETACH:
			Xanadu_Crypto_Release();
			break;
		default:
			break;
	}
	return TRUE;
}
#else
__attribute((constructor)) void _XANADU_CRYPTO_BUILD_SHAREDrary_Init(void)
{
	Xanadu_Crypto_Initialize();
};

__attribute((destructor)) void _XANADU_CRYPTO_BUILD_SHAREDrary_Fini(void)
{
	Xanadu_Crypto_Release();
};
#endif // XANADU_SYSTEM_WINDOWS
