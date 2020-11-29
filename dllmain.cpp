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
//resize slp interface
#pragma region resize interface slp

//00457ED0  |. E8 BB7E0000    CALL empires2.0045FD90
//0045FD90  /$ 56             PUSH ESI
DWORD u_0045FD90;
void __declspec(naked)  u_AddWideScreenPanel457ED0()
{
	__asm {
		MOV ECX, DWORD PTR DS : [ECX + 3Ch]
		SUB ESP, 64h
		XOR EAX, EAX
		MOV DWORD PTR SS : [ESP] , 64h
		MOV DWORD PTR SS : [ESP + 50h] , EAX
		PUSH ESP
		PUSH 1000400h
		PUSH EAX
		PUSH EAX
		MOV EDX, DWORD PTR DS : [ECX]
		PUSH EAX
		PUSH ECX
		CALL DWORD PTR DS : [EDX + 014h]
		ADD ESP, 064h
		MOV ECX, DWORD PTR DS : [ESI + 020h]
		JMP[u_0045FD90]
	}
}
//004580A9  |. 8B86 700E0000  MOV EAX,DWORD PTR DS:[ESI+0xE70]
//004580AF  |. 8BAE 780E0000  MOV EBP,DWORD PTR DS:[ESI+0xE78]

DWORD u_004DB740;
DWORD u_004580BD;
//004580A4  |. E8 476F0C00    CALL empires2.0051EFF0
DWORD u_004580A4;
DWORD u_004580A9;
DWORD u_0051EFF0;
//DWORD _007C08C0;
DWORD uf_AddWideScreenPanel7C08C0;
void __declspec(naked)  u_AddWideScreenPanel4580A4()
{
	__asm {
		CALL u_0051EFF0
		MOV EAX, DWORD PTR DS : [ESI + 0DC0h]
		MOV ECX, DWORD PTR DS : [ESI + 0EE4h]
		MOV EDX, DWORD PTR DS : [ESI + 0DC4h]
		MOV EBP, DWORD PTR DS : [ESI + 0EE8h]
		ADD EAX, ECX
		MOV ECX, DWORD PTR DS : [ESI + 01C5Ch]
		ADD EDX, EBP
		TEST ECX, ECX
		JE _005ABBE9
		JMP[uf_AddWideScreenPanel7C08C0]
		JE _005ABBD1
		CMP EBX, 400h
		JE SHORT _005ABBBC
		CMP EBX, 0500h
		JNZ _005ABBE9
		PUSH 0h
		ADD EDX, 039Eh
		PUSH 0h
		PUSH EDX
		ADD EAX, 79h
		JMP[_005ABBDF]
		_005ABBBC:
		PUSH 0h
			ADD EDX, 299h
			PUSH 0h
			PUSH EDX
			MOV EDX, DWORD PTR DS : [ESI + 20h]
			ADD EAX, 71h
			PUSH EAX
			PUSH EDX
			JMP _005ABBE4//005ABBCF   . EB 13          JMP SHORT age2_x1.005ABBE4// u_004580A4
			_005ABBD1 :
		PUSH 0h
			ADD EDX, 210h
			PUSH 0h
			PUSH EDX
			ADD EAX, 66h
			_005ABBDF :
		PUSH EAX
			MOV EAX, DWORD PTR DS : [ESI + 20h]
			PUSH EAX
			_005ABBE4 :
		CALL u_0051EFF0// u_004DB740
			_005ABBE9 :
		JMP[u_004580A9]
			//MOV EAX, DWORD PTR DS : [ESI + 0E70h]
			//MOV EBP, DWORD PTR DS : [ESI + 0xE78]
			//MOV EBX, DWORD PTR DS : [ESI + 0xDC0]
			//PUSH 0x0
			Jmp[u_004580A9]//004580A9     8B86 700E0000  MOV EAX,DWORD PTR DS:[ESI+0xE70]

	}
}
//MOV EAX,DWORD PTR DS:[0x6645C4]
//004580A9     8B86 700E0000  MOV EAX,DWORD PTR DS:[ESI+0xE70]
//004A23E0  /$ 81EC C80C0000  SUB ESP,0xCC8
DWORD u_6645C4;//7912A0
//DWORD u_0051EFF0;
//DWORD u_004580A9;
DWORD u_004A23E0;
void __declspec(naked)  u_AddWideScreenPanel7C08C0()
{
	__asm {
		MOV EBX, DWORD PTR DS : [ESI + 0E6Ch]
		INC EBX
		IMUL EBX, EBX, 20h
		MOV EBP, DWORD PTR DS : [ESI + 1C60h]
		MOV EBP, DWORD PTR SS : [EBP + 0Ch]
		MOV EBX, DWORD PTR DS : [EBX + EBP + 14h]
		CMP EBX, 300h
		JL SHORT _007C0911
		CMP EBX, 400h
		JL SHORT _007C08FC
		PUSH 0h
		ADD EDX, 39Eh
		PUSH 0h
		PUSH EDX
		ADD EAX, 79h
		PUSH EAX
		MOV EAX, DWORD PTR DS : [ESI + 20h]
		PUSH EAX
		JMP[_007C0924]
		_007C08FC :
		PUSH 0h
		ADD EDX, 299h
		PUSH 0h
		PUSH EDX
		MOV EDX, DWORD PTR DS : [ESI + 20h]
		ADD EAX, 71h
		PUSH EAX
		PUSH EDX
		JMP[_007C0924]
		_007C0911 :
		PUSH 0h
		ADD EDX, 210h
		PUSH 0h
		PUSH EDX
		ADD EAX, 66h
		PUSH EAX
		MOV EAX, DWORD PTR DS : [ESI + 20h]
		PUSH EAX
		_007C0924 :
		CALL u_0051EFF0
			JMP u_004580A9
	}
}
//004E1C38   . 8B56 20        MOV EDX,DWORD PTR DS:[ESI+0x20]
//004E1C45   . 68 AC446500    PUSH empires2.006544AC                   ;  ASCII "scr_game::draw3"
DWORD u_005223C2;//004E1C45

void __declspec(naked)  u_AddWideScreenPanel004E1C38()
{
	__asm {
		MOV EAX, DWORD PTR DS : [ESI + 14h]
		PUSH 0h
		PUSH 2h
		SUB EAX, 500h
		SHR EAX, 1
		LEA EDX, DWORD PTR DS : [EAX + 2ACh]
		MOV EAX, DWORD PTR DS : [ESI + 18h]
		LEA EAX, DWORD PTR DS : [EAX - 2Ah]
		PUSH EAX
		PUSH EDX
		MOV EDX, DWORD PTR DS : [ESI + 20h]
		PUSH EDX
		PUSH u_005223C2//004E1C45
		JMP u_0051EFF0//age2_x1.004DB740


	}
}
//004E1C0E
DWORD u_007C1C78;
DWORD u_007C1D90;
void __declspec(naked)  u_AddWideScreenPanel004E1C0E()
{
	__asm {
		PUSH ESI
		PUSH EDI
		PUSH EBX
		PUSH EBP
		SUB ESP, 8h
		MOV EDI, DWORD PTR DS : [ESI + 20h]
		MOV ECX, DWORD PTR DS : [ESI + 100Ch]
		MOV EDX, DWORD PTR DS : [EDI + 0C0h]
		MOV EBX, DWORD PTR DS : [EDI + 0D0h]
		MOV DWORD PTR DS : [774000h] , EDX //00774000  =795000
		MOV EAX, DWORD PTR DS : [EBX + 3Ch]
		MOV EDX, DWORD PTR DS : [EBX + 40h]
		MOV DWORD PTR DS : [774004h] , EAX
		MOV DWORD PTR DS : [774008h] , EDX
		MOV EDI, DWORD PTR DS : [ESI + 14h]
		MOV EBX, DWORD PTR DS : [ESI + 18]
		MOV EBP, DWORD PTR DS : [ECX + 0Ch]
		LEA EAX, DWORD PTR DS : [EBX - 1h]
		LEA EDX, DWORD PTR DS : [EDI - 1h]
		MOV DWORD PTR DS : [774080h] , 0h
		MOV DWORD PTR DS : [774084h] , EAX
		MOV DWORD PTR DS : [774088h] , 0h
		MOV DWORD PTR DS : [77408Ch] , EDX
		MOV DWORD PTR DS : [774038h] , 0h
		CMP EDI, 320h
		JE  _007C1C35
		CMP EDI, 400h
		JNZ  _u_007C1C78
		CMP EBX, 300h
		JL  _u_007C1C78
		_007C1C35 :
		MOV EDX, DWORD PTR SS : [EBP + 24h]
			MOV EAX, DWORD PTR SS : [EBP + 20h]
			PUSH 0h
			PUSH EDX
			PUSH EAX
			MOV EDX, DWORD PTR SS : [EBP + 30h]
			PUSH 19h
			PUSH EDX
			PUSH 0h
			PUSH 0h
			PUSH EBP
			CALL u_007C1D90
			MOV EDX, DWORD PTR SS : [EBP + 34h]
			MOV EAX, EBX
			MOV DWORD PTR DS : [774038h] , 1C7h
			SUB EAX, EDX
			MOV DWORD PTR SS : [ESP + 10h] , EDX
			MOV DWORD PTR SS : [ESP + 8h] , EAX
			CALL u_007C1D90
			ADD ESP, 28h
			POP EBP
			POP EBX
			POP EDI
			POP ESI
			RETN
			_u_007C1C78 :
		JMP[u_007C1C78]
	}
}

//00774000  =795000
void __declspec(naked)  u_AddWideScreenPanel007C1C78()
{
	__asm {
		MOV ESI, EDI
		MOV ECX, DWORD PTR SS : [EBP + 24h]
		MOV EAX, DWORD PTR SS : [EBP + 20h]
		MOV EDX, DWORD PTR SS : [EBP + 30h]
		PUSH 0h
		PUSH ECX
		PUSH EAX
		PUSH 19h
		PUSH EDX
		PUSH 0h
		PUSH ESI
		PUSH EBP
		CMP EDX, 400h
		JE _007C1CA8
		CMP EDX, 500h
		JE _007C1CB2
		MOV DWORD PTR SS : [ESP + 20h] , 0D6h
		JMP _007C1CC2
		_007C1CA8 :
		MOV DWORD PTR SS : [ESP + 20h] , 116h
			JMP _007C1CC2
			_007C1CB2 :
		MOV DWORD PTR SS : [ESP + 10h] , 20h
			MOV DWORD PTR SS : [ESP + 20h] , 158h
			_007C1CC2 :
		SUB ESI, EDX
			AND ESI, ESI
			JL _007C1D7C
			_007C1CCC :
		MOV DWORD PTR SS : [ESP + 4h] , ESI
			CALL u_007C1D90
			MOV DWORD PTR DS : [774038h] , 0h
			MOV EDX, DWORD PTR SS : [EBP + 30h]
			SUB ESI, EDX
			ADD ESI, 190h
			AND ESI, ESI
			JG _007C1CCC
			MOV DWORD PTR SS : [ESP + 4h] , 0h
			CALL u_007C1D90
			MOV EDX, DWORD PTR SS : [EBP + 30h]
			MOV EAX, EDI
			SUB EAX, EDX
			SHR EAX, 1h
			SUB EAX, EDX
			MOV ESI, EAX
			MOV EAX, EBX
			LEA EBX, DWORD PTR DS : [EDX + ESI]
			MOV EDX, DWORD PTR SS : [EBP + 34h]
			SUB EAX, EDX
			MOV DWORD PTR SS : [ESP + 10h] , EDX
			MOV DWORD PTR SS : [ESP + 8h] , EAX
			MOV DWORD PTR SS : [ESP + 1Ch] , 0h
			MOV DWORD PTR DS : [774038h] , 1C7h
			MOV DWORD PTR SS : [ESP + 4h] , EBX
			CALL u_007C1D90
			MOV EDX, DWORD PTR SS : [EBP + 30h]
			ADD EBX, EDX
			_007C1D3A :
		MOV DWORD PTR SS : [ESP + 1Ch] , 2h
			MOV DWORD PTR DS : [774038h] , 1C7h
			MOV DWORD PTR SS : [ESP + 4h] , ESI
			CALL u_007C1D90
			MOV DWORD PTR SS : [ESP + 1Ch] , 0h
			MOV DWORD PTR DS : [774038h] , 1C7h
			MOV DWORD PTR SS : [ESP + 4h] , EBX
			CALL u_007C1D90
			MOV EAX, DWORD PTR SS : [ESP + 20h]
			SUB ESI, EAX
			ADD EBX, EAX
			CMP EBX, EDI
			JL _007C1D3A
			_007C1D7C :
		ADD ESP, 28h
			POP EBP
			POP EBX
			POP EDI
			POP ESI
			RETN
	}
}
//007C1D90
//00619BC0   55               PUSH EBP
DWORD u_00619BC0;
DWORD u_00619C48;
void __declspec(naked)  u_AddWideScreenPanel007C1D90()
{
	__asm {
		PUSH EBP
		MOV EBP, ESP
		PUSH EBX
		PUSH ESI
		PUSH EDI
		XOR EDX, EDX
		MOV ECX, DWORD PTR SS : [EBP + 0Ch]
		MOV EAX, DWORD PTR SS : [EBP + 14h]
		MOV DWORD PTR DS : [774024h] , ECX
		LEA ECX, DWORD PTR DS : [EAX + ECX - 1h]
		MOV DWORD PTR DS : [774028h] , ECX
		//JMP [u_00619BC0]
		JMP[u_00619C48]
	}
}
//clean purple 
//0x51a3b7
//004DA6E7  |. 8B46 14        MOV EAX,DWORD PTR DS:[ESI+0x14]
DWORD u_Cord_X;
DWORD u_Cord_Y;
DWORD u_004DA6EA;
DWORD u_4DA6CC;
//004DA6E7     8B46 14        MOV EAX, DWORD PTR DS : [ESI + 0x14]
//004DA6EA | . 3D 00050000    CMP EAX, 0x500
//004DA6EF | . 0F85 4C030000  JNZ empires2.004DAA41


void __declspec(naked)  u_AddWideScreenPanelreadXY()
{
	__asm {
		JNZ _u_4DA6CC
		MOV EAX, DWORD PTR DS : [ESI + 18h]//Y            
		MOV u_Cord_Y, EAX
		MOV EAX, DWORD PTR DS : [ESI + 14h]//X
		MOV u_Cord_X, EAX
		//CMP EAX, 0x500
		JMP u_004DA6EA
		_u_4DA6CC :
		JMP  u_4DA6CC
	};
}

__declspec(naked) int __stdcall u_getWindowX()
{
	__asm
	{
		MOV EAX, DWORD PTR DS : [u_Cord_X]
		ret
	}
}
//
__declspec(naked) int __stdcall u_getWindowY()
{
	__asm
	{
		mov     eax, DWORD PTR DS : [u_Cord_Y]
		ret
	}
}



char umap1280[] = "map1280.bmp";
char umap1024[] = "map1024.bmp";
char umap800[] = "map800.bmp";
DWORD u_00443B50;
DWORD uu_005A6870;
DWORD u_004AF4D0;
DWORD u_004DB0EA;

//004E1C09   . 8B46 20        MOV EAX,DWORD PTR DS:[ESI+0x20]

//00774000  =795000

void __declspec(naked)  u_AddWideScreenPanelSLP()
{
	__asm {
		PUSH ESI
		PUSH EDI
		PUSH EBX
		PUSH EBP
		SUB ESP, 8h
		MOV EDI, DWORD PTR DS : [ESI + 20h]
		MOV ECX, DWORD PTR DS : [ESI + 1008h]
		MOV EDX, DWORD PTR DS : [EDI + 0C0h]
		MOV EBX, DWORD PTR DS : [EDI + 0D0h]
		MOV DWORD PTR DS : [774000h] , EDX
		MOV EAX, DWORD PTR DS : [EBX + 3Ch]
		MOV EDX, DWORD PTR DS : [EBX + 40h]
		MOV DWORD PTR DS : [774004h] , EAX
		MOV DWORD PTR DS : [774008h] , EDX
		MOV EDI, DWORD PTR DS : [ESI + 14h]
		MOV EBX, DWORD PTR DS : [ESI + 18h]
		MOV EBP, DWORD PTR DS : [ECX + 0Ch]
		LEA EAX, DWORD PTR DS : [EBX - 1h]
		LEA EDX, DWORD PTR DS : [EDI - 1h]
		MOV DWORD PTR DS : [774080h] , 0h
		MOV DWORD PTR DS : [774084h] , EAX
		MOV DWORD PTR DS : [774088h] , 0h
		MOV DWORD PTR DS : [77408Ch] , EDX
		MOV DWORD PTR DS : [774038h] , 0h
		CMP EDI, 320h
		JE _007C1C35
		CMP EDI, 400h
		JNZ __007C1C78
		CMP EBX, 300h
		JL __007C1C78
		_007C1C35 :
		MOV EDX, DWORD PTR SS : [EBP + 24h]
			MOV EAX, DWORD PTR SS : [EBP + 20h]
			PUSH 0h
			PUSH EDX
			PUSH EAX
			MOV EDX, DWORD PTR SS : [EBP + 30h]
			PUSH 19h
			PUSH EDX
			PUSH 0h
			PUSH 0h
			PUSH EBP
			CALL u_007C1D90
			MOV EDX, DWORD PTR SS : [EBP + 34h]
			MOV EAX, EBX
			MOV DWORD PTR DS : [774038h] , 1C7h
			SUB EAX, EDX
			MOV DWORD PTR SS : [ESP + 10h] , EDX
			MOV DWORD PTR SS : [ESP + 8h] , EAX
			CALL u_007C1D90
			ADD ESP, 28h
			POP EBP
			POP EBX
			POP EDI
			POP ESI
			RETN
			__007C1C78 :
		JMP  u_007C1C78
	}
}
#pragma endregion resize interface slp

void getxy()
{
#pragma region resize interface slp

	//457ED0
	u_0045FD90 = 0x045FD90;
	//0x4580A4
	u_004580A9 = 0x04580A9;
	u_004580A4 = 0x04580A4;
	u_004DB740 = 0x04DB740;
	u_004580BD = 0x04580BD;
	u_0051EFF0 = 0x051EFF0;
	//7C08C0
	u_6645C4 = 0x06645C4;//7912A0
	u_0051EFF0 = 0x051EFF0;
	u_004580A9 = 0x04580A9;
	u_004A23E0 = 0x004A23E0;
	//_AddWideScreenPanel7C08C0 = (DWORD) u_AddWideScreenPanel7C08C0;
	//setHook((void*)0x457ED0, AddWideScreenPanel457ED0);
	//// call 7C08C0
	//setHook((void*)0x4580A4, AddWideScreenPanel4580A4);
	////4E1C38
	u_005223C2 = 0x04E1C45;
	//setHook((void*)0x04E1C38, AddWideScreenPanel004E1C38);

	////007C1D90
	u_007C1C78 = (DWORD)  u_AddWideScreenPanel007C1C78;
	u_00619C48 = 0x0619C48;
	u_007C1D90 = (DWORD)u_AddWideScreenPanel007C1D90;

	u_00619BC0 = 0x0619BC0;
	//writeByte(0x41f80A,0x9066);
	////004E1C0E     90             NOP
	//setHook((void*)0x04E1C0E, AddWideScreenPanel004E1C0E);
	////to do ajouter la partie manquante
	////004E1C12 
	//writeByte(0x04E1C13, 0x90);
	//BYTE _04E1C14[] =
	//{
	//	0x68,0x20,0x1C,0x4E,0x00
	//};
	//writeData(0x04E1C09, _04E1C14, 5);
	////004E1C2A     8B46 18        MOV EAX,DWORD PTR DS:[ESI+0x18]
	//writeByte(0x04E1C2C, 0x18);
	////004E1C2F   . 3D 00050000    CMP EAX,0x500
	//writeByte(0x04E1C31, 0x04);



	u_004DA6EA = 0x04DA6EA;
	u_4DA6CC = 0x04DA6CC;
	//004DA6E7  |. 8B46 14        MOV EAX,DWORD PTR DS:[ESI+0x14]   -> X 
	setHook((void*)0x04DA6E5, u_AddWideScreenPanelreadXY);

	//004E1C0E     90             NOP
	/*setHook((void*)0x04E1C0E, u_AddWideScreenPanelSLP);
	BYTE u_PUSH_4E1C20[] = { 0x68,0x20,0x1C,0x4E,0x00 };
	writeData(0x04E1C09, u_PUSH_4E1C20, 5);
	writeByte(0x04E1C13, 0x90);*/




#pragma endregion resize interface slp
}
DWORD myCord_X;
DWORD myCord_Y;

CRITICAL_SECTION cs_Cord_X;
CRITICAL_SECTION cs_Cord_Y;

DWORD WINAPI MainThread(LPVOID param) {
	LoadLibraryA("wndmode.dll");
	windowedMod();
	//NormaleAoeWideScreen(&myCord_X, &myCord_Y);
	UserPatchWideScreen();// &myCord_X, & myCord_Y);
	//chatColor();
	//chatchatColorFixe();
	miniMapColor();
	AddNewBittonFormation();
	AddRms();
	InitializeCriticalSection(&cs_Cord_X);
	InitializeCriticalSection(&cs_Cord_Y);


	getxy();

	//let the process live until close
	//while (true) {

	//}
	int precY = 0;
	int precX = 0;
	int V = 0;
	int H = 0;

	while (true) {
		//if (GetAsyncKeyState(VK_ESCAPE)) break;
		//Sleep(50);


		//int V = (int)Cord_Y;
		//int H = (int)Cord_X;

		//HKEY_CURRENT_USER\Software\Microsoft\Microsoft Games\Age of Empires\2.0
		//if (GetAsyncKeyState(VK_ESCAPE)) break;
		//Sleep(50);

		int cpt = 0;



		//start with full resolution
		//0041BCE1     C780 F4080000 >MOV DWORD PTR DS:[EAX+0x8F4],0x780
		//0041BCEE     C781 FC080000 >MOV DWORD PTR DS:[ECX+0x8FC],0x438
		writeDwordF(0x01BCE7 -1,H);//  1024      1024    set
		writeDwordF(0x01BCF4 -1, V);//   768       768    set

		EnterCriticalSection(&cs_Cord_Y);
		V = (int)u_Cord_Y;
		LeaveCriticalSection(&cs_Cord_Y);
		EnterCriticalSection(&cs_Cord_X);
		H = (int)u_Cord_X;
		EnterCriticalSection(&cs_Cord_X);

		if ((V == 0 && H == 0) && (V == 600 && H == 800))
		{
			u_Cord_Y = GetSystemMetrics(SM_CYSCREEN);
			u_Cord_X = GetSystemMetrics(SM_CXSCREEN);
		}
		if (V > 0 && H > 0)// && H > 800
		{


				patchEXE(H, V);



			// 1024  -> au chose interface 
			//1280x600
			//1280x720

			//WideScreen(H, V);

			//patchEXE(GetSystemMetrics(SM_CYSCREEN), GetSystemMetrics(SM_CXSCREEN));
			//patchEXE(H, V);



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


