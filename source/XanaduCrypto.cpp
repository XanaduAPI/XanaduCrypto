#include <XanaduCrypto/XanaduCrypto.h>

bool XANADUAPI Xanadu_Crypto_Initialize() XANADU_NOTHROW
{
	return true;
};

void XANADUAPI Xanadu_Crypto_Release() XANADU_NOTHROW
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
__attribute((constructor)) void Xanadu_Crypto_Library_Init(void)
{
	Xanadu_Crypto_Initialize();
};

__attribute((destructor)) void Xanadu_Crypto_Library_Fini(void)
{
	Xanadu_Crypto_Release();
};
#endif//XANADU_SYSTEM_WINDOWS
