#include "stdafx.h"
#include "d3d11hook.h"

const LPCWSTR AppWindowTitle = L"Window Title"; // Targeted D11 Application Window Title.

DWORD WINAPI MainThread(HMODULE hModule)
{
	ImplHookDX11_Init(hModule, FindWindow(0, AppWindowTitle));

	return S_OK;
}


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)MainThread, hModule, NULL, NULL);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

