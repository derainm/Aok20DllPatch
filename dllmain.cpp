// dllmain.cpp : Définit le point d'entrée de l'application DLL.
#include "pch.h"
#include <windows.h>
#include <iostream>
#include "Hookbase.h"
#include "windowed.h"
#include "chatColor.h"
#include "MiniMapColor.h"
#include "AddNewBittonFormation.h"
#include "AddRms.h"
#include "NormaleAoeWideScreen.h"
#include "UserPatchWideScreen.h"
using namespace std;


DWORD myCord_X;
DWORD myCord_Y;
DWORD WINAPI MainThread(LPVOID param) {
	LoadLibraryA("wndmode.dll");
	windowedMod();
	NormaleAoeWideScreen(&myCord_X, &myCord_Y);
	//UserPatchWideScreen(&myCord_X, &myCord_Y);
	//chatColor();
	//chatchatColorFixe();
	miniMapColor();
	AddNewBittonFormation();
	AddRms();


	//let the process live until close
	//while (true) {

	//}
	int precY = 0;
	while (true) {
		//if (GetAsyncKeyState(VK_ESCAPE)) break;
		//Sleep(50);


		//int V = (int)Cord_Y;
		//int H = (int)Cord_X;


		//if (GetAsyncKeyState(VK_ESCAPE)) break;
		//Sleep(50);
		int V = (int)myCord_X;
		int H = (int)myCord_Y;
		int cpt = 0;
		if ((V == 0 && H == 0))
		{
			V = GetSystemMetrics(SM_CYSCREEN);
			H = GetSystemMetrics(SM_CXSCREEN);
		}
		//start with full resolution
		//0041BCE1     C780 F4080000 >MOV DWORD PTR DS:[EAX+0x8F4],0x780
		//0041BCEE     C781 FC080000 >MOV DWORD PTR DS:[ECX+0x8FC],0x438
		writeDwordF(0x01BCE7 -1,H);//  1024      1024    set
		writeDwordF(0x01BCF4 -1, V);//   768       768    set


		if (V > 0 && H > 0 && H > 800)
		{

			// 1024  -> au chose interface 
			//1280x600
			//1280x720

			WideScreen(H, V);
			//patchEXE(GetSystemMetrics(SM_CYSCREEN), GetSystemMetrics(SM_CXSCREEN));


		}
	}
	FreeLibraryAndExitThread((HMODULE)param, 0);

	return 0;
}


BOOL WINAPI DllMain(HINSTANCE hModule, DWORD dwReason, LPVOID lpReserved) {
	switch (dwReason) {
	case DLL_PROCESS_ATTACH:
		//DisableThreadLibraryCalls(hModule);
		//if (AllocConsole()) {
		//	freopen("CONOUT$", "w", stdout);
		//	SetConsoleTitle(L"Statistics spy");
		//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		//}
		CreateThread(0, 0, MainThread, hModule, 0, 0);
		break;
	}

	return TRUE;
}


