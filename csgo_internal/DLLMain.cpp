#include "Cheat.h"

void CheatThread()
{
    LOG_INIT;
	U::Setup();
}

DWORD WINAPI DllMain(HMODULE hDll, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
	{
		while (!(G::Window = FindWindowA(charenc("Valve001"), NULL)))
			Sleep(200);

		Hooks::oldWindowProc = (WNDPROC)SetWindowLongPtr(G::Window, GWL_WNDPROC, (LONG_PTR)Hooks::WndProc);

		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)CheatThread, NULL, NULL, NULL);

		G::Dll = hDll;

		return TRUE;
	}
	case DLL_PROCESS_DETACH:
	{
		return TRUE;
	}

	return FALSE;
	}
}
