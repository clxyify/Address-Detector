#include "pch.h"
#include <Windows.h>
#include <string>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996);

VOID MAIN()
{
    BOOL VALID;
    DWORD ADDRESS = (0UL); /* Paste your address to check if it exists! */

    VirtualProtect((PVOID)&FreeConsole, 1, PAGE_EXECUTE_READWRITE, new unsigned long);
    *(BYTE*)(&FreeConsole) = 0xC3;
    AllocConsole();
    SetConsoleTitleA("Roblox Address Checker - Developed By Clxyify!");
    freopen("CONOUT$", "w", stdout);
    freopen("CONIN$", "r", stdin);
    ::SetWindowPos(GetConsoleWindow(), HWND_TOPMOST, 0, 0, 0, 0, SWP_DRAWFRAME | SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);
    ::ShowWindow(GetConsoleWindow(), SW_NORMAL);
    
    if (!ADDRESS) /* If address is not found */
    {
        VALID = FALSE;
        std::cout << "Sorry, the address is not valid!\n";
        std::cout << "You're address is not in Roblox!\n";
    }
    else /* If address was found */
    {
        VALID = TRUE;
        std::cout << "Congrats, the address is valid!\n";
        std::cout << "You're address was found in Roblox!\n";
    }

    if (ADDRESS == NULL) {
        VALID = FALSE;
        std::cout << "Address format cannot be 0 (NULL)!\n";
        std::cout << "Insert a correct format and try again!\n";
    }
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        MAIN();
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
