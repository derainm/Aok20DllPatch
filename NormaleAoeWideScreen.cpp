#include <Windows.h>
#include "Hookbase.h"



//auto widescreen
#pragma region   Modify resolution systems
#pragma region resize interface slp

//00457ED0  |. E8 BB7E0000    CALL empires2.0045FD90
//0045FD90  /$ 56             PUSH ESI
DWORD _0045FD90;
void __declspec(naked)  AddWideScreenPanel457ED0()
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
		JMP[_0045FD90]
	}
}
//004580A9  |. 8B86 700E0000  MOV EAX,DWORD PTR DS:[ESI+0xE70]
//004580AF  |. 8BAE 780E0000  MOV EBP,DWORD PTR DS:[ESI+0xE78]

DWORD _004DB740;
DWORD _004580BD;
//004580A4  |. E8 476F0C00    CALL empires2.0051EFF0
DWORD _004580A4;
DWORD _004580A9;
DWORD _0051EFF0;
//DWORD _007C08C0;
DWORD _AddWideScreenPanel7C08C0;
void __declspec(naked)  AddWideScreenPanel4580A4()
{
	__asm {
		CALL _0051EFF0
		MOV EAX, DWORD PTR DS : [ESI + 0DC0h]
		MOV ECX, DWORD PTR DS : [ESI + 0EE4h]
		MOV EDX, DWORD PTR DS : [ESI + 0DC4h]
		MOV EBP, DWORD PTR DS : [ESI + 0EE8h]
		ADD EAX, ECX
		MOV ECX, DWORD PTR DS : [ESI + 01C5Ch]
		ADD EDX, EBP
		TEST ECX, ECX
		JE _005ABBE9
		JMP[_AddWideScreenPanel7C08C0]
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
			JMP _005ABBE4//005ABBCF   . EB 13          JMP SHORT age2_x1.005ABBE4// _004580A4
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
		CALL _0051EFF0// _004DB740
			_005ABBE9 :
		JMP[_004580A9]
			//MOV EAX, DWORD PTR DS : [ESI + 0E70h]
			//MOV EBP, DWORD PTR DS : [ESI + 0xE78]
			//MOV EBX, DWORD PTR DS : [ESI + 0xDC0]
			//PUSH 0x0
			Jmp[_004580A9]//004580A9     8B86 700E0000  MOV EAX,DWORD PTR DS:[ESI+0xE70]

	}
}
//MOV EAX,DWORD PTR DS:[0x6645C4]
//004580A9     8B86 700E0000  MOV EAX,DWORD PTR DS:[ESI+0xE70]
//004A23E0  /$ 81EC C80C0000  SUB ESP,0xCC8
DWORD _6645C4;//7912A0
//DWORD _0051EFF0;
//DWORD _004580A9;
DWORD _004A23E0;
void __declspec(naked)  AddWideScreenPanel7C08C0()
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
		CALL _0051EFF0
			JMP _004580A9
	}
}
//004E1C38   . 8B56 20        MOV EDX,DWORD PTR DS:[ESI+0x20]
//004E1C45   . 68 AC446500    PUSH empires2.006544AC                   ;  ASCII "scr_game::draw3"
DWORD _005223C2;//004E1C45

void __declspec(naked)  AddWideScreenPanel004E1C38()
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
		PUSH _005223C2//004E1C45
		JMP _0051EFF0//age2_x1.004DB740


	}
}
//004E1C0E
DWORD _007C1C78;
DWORD _007C1D90;
void __declspec(naked)  AddWideScreenPanel004E1C0E()
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
		JNZ  __007C1C78
		CMP EBX, 300h
		JL  __007C1C78
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
			CALL _007C1D90
			MOV EDX, DWORD PTR SS : [EBP + 34h]
			MOV EAX, EBX
			MOV DWORD PTR DS : [774038h] , 1C7h
			SUB EAX, EDX
			MOV DWORD PTR SS : [ESP + 10h] , EDX
			MOV DWORD PTR SS : [ESP + 8h] , EAX
			CALL _007C1D90
			ADD ESP, 28h
			POP EBP
			POP EBX
			POP EDI
			POP ESI
			RETN
			__007C1C78 :
		JMP[_007C1C78]
	}
}

//00774000  =795000
void __declspec(naked)  AddWideScreenPanel007C1C78()
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
			CALL _007C1D90
			MOV DWORD PTR DS : [774038h] , 0h
			MOV EDX, DWORD PTR SS : [EBP + 30h]
			SUB ESI, EDX
			ADD ESI, 190h
			AND ESI, ESI
			JG _007C1CCC
			MOV DWORD PTR SS : [ESP + 4h] , 0h
			CALL _007C1D90
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
			CALL _007C1D90
			MOV EDX, DWORD PTR SS : [EBP + 30h]
			ADD EBX, EDX
			_007C1D3A :
		MOV DWORD PTR SS : [ESP + 1Ch] , 2h
			MOV DWORD PTR DS : [774038h] , 1C7h
			MOV DWORD PTR SS : [ESP + 4h] , ESI
			CALL _007C1D90
			MOV DWORD PTR SS : [ESP + 1Ch] , 0h
			MOV DWORD PTR DS : [774038h] , 1C7h
			MOV DWORD PTR SS : [ESP + 4h] , EBX
			CALL _007C1D90
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
DWORD _00619BC0;
DWORD _00619C48;
void __declspec(naked)  AddWideScreenPanel007C1D90()
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
		//JMP [_00619BC0]
		JMP[_00619C48]
	}
}
//clean purple 
//0x51a3b7
//004DA6E7  |. 8B46 14        MOV EAX,DWORD PTR DS:[ESI+0x14]
DWORD Cord_X;
DWORD Cord_Y;
DWORD _004DA6EA;
DWORD _4DA6CC;
//004DA6E7     8B46 14        MOV EAX, DWORD PTR DS : [ESI + 0x14]
//004DA6EA | . 3D 00050000    CMP EAX, 0x500
//004DA6EF | . 0F85 4C030000  JNZ empires2.004DAA41


void __declspec(naked)  AddWideScreenPanelreadXY()
{
	__asm {
		JNZ __4DA6CC
		MOV EAX, DWORD PTR DS : [ESI + 18h]//Y            
		MOV Cord_Y, EAX
		MOV EAX, DWORD PTR DS : [ESI + 14h]//X
		MOV Cord_X, EAX
		//CMP EAX, 0x500
		JMP _004DA6EA
		__4DA6CC :
		JMP  _4DA6CC
	};
}

__declspec(naked) int __stdcall getWindowX()
{
	__asm
	{
		MOV EAX, DWORD PTR DS : [Cord_X]
		ret
	}
}
//
__declspec(naked) int __stdcall getWindowY()
{
	__asm
	{
		mov     eax, DWORD PTR DS : [Cord_Y]
		ret
	}
}



char map1280[] = "map1280.bmp";
char map1024[] = "map1024.bmp";
char map800[] = "map800.bmp";
DWORD _00443B50;
DWORD _005A6870;
DWORD _004AF4D0;
DWORD _004DB0EA;


#pragma endregion resize interface slp



///resize  screen 
#pragma region resize  screen 
////00448551  |. 8B6C24 4C      MOV EBP,DWORD PTR SS:[ESP+0x4C]
//004A5230  /$ 6A FF          PUSH -0x1
//004A55F0  /$ 56             PUSH ESI
//004A55F0  /$ 56             PUSH ESI
//007BF900   8B6C24 4C         MOV EBP,DWORD PTR SS:[ESP+0x4C]
DWORD _00448925;
DWORD _004A5230;
DWORD _007BF980;
DWORD _004A55F0;
DWORD _0044869C;//0044869C  |> 6A 00          PUSH 0x0                                 ; /Arg11 = 00000000

void __declspec(naked)  AddWideScreenPanel00448551()
{
	__asm {
		MOV EBP, DWORD PTR SS : [ESP + 4Ch]
		XOR EDI, EDI
		PUSH 0Ah
		PUSH 73h
		PUSH 80h
		PUSH 0F7h
		PUSH 4Bh
		LEA EDI, DWORD PTR DS : [ESI + 888h]
		PUSH EDI
		PUSH ESI
		MOV ECX, ESI
		CALL _004A5230//0055E9E0
		TEST EAX, EAX
		JE __00448925 // 005BBCFA
		MOV ECX, DWORD PTR DS : [EDI]
		PUSH 14h
		LEA EAX, DWORD PTR DS : [ESI + 88Ch]
		PUSH ECX
		PUSH EAX
		MOV ECX, ESI
		CALL _004A55F0 //0055EDA0
		TEST EAX, EAX
		JE __00448925 // 005BBCFA
		MOV ECX, DWORD PTR DS : [ESI + 888h]
		PUSH ECX
		CALL _007BF980 //age2_x1.007BF980
		JMP _0044869C //age2_x1.005BBA15
		__00448925 :
		JMP[_00448925]
	}
}
//007BF980
WORD _7A5608;
DWORD _004BD5E0;//004BD5E0   $ 8B01           MOV EAX,DWORD PTR DS:[ECX]
DWORD _7912A0;
DWORD _007BF9D0;
void __declspec(naked)  AddWideScreenPanel007BF980()
{
	__asm {
		MOV ECX, DWORD PTR SS : [ESP + 4h]
		XOR EAX, EAX
		MOV  WORD PTR DS : [_7A5608] , 20h//WORD PTR DS : [
		MOV DWORD PTR DS : [ECX + 174h] , EAX//[ECX + 174h] 
		CALL _004BD5E0 //00547A00
		_007BF99A :
		MOV ECX, _7912A0
			MOV ECX, DWORD PTR DS : [ECX]
			MOV EDX, DWORD PTR DS : [ECX + 68h]//[ECX + 6Ch]
			MOV ECX, DWORD PTR SS : [ESP + 4h]
			MOV EAX, DWORD PTR DS : [EDX + 18h]
			PUSH _007BF9D0//age2_x1.007BF9D0
			PUSH ECX
			PUSH 0h
			MOV ECX, DWORD PTR DS : [EAX]
			PUSH 0h
			PUSH EAX
			CALL DWORD PTR DS : [ECX + 20h]
			CMP  WORD PTR DS : [_7A5608] , 20h
			MOV BYTE PTR DS : [_7A5608] , 8h
			JE _007BF99A
			RETN 4h
	}
}
DWORD _7A5609;
DWORD _004BCF90;
DWORD _004BCEB0;
DWORD _005FCE14;
DWORD _04BBF20;
char printRes[] = "%d x %d";
void __declspec(naked)  AddWideScreenPanel007BF9D0()
{
	__asm {
		PUSH ESI
		PUSH EDI
		PUSH EBX
		MOV EAX, DWORD PTR DS : [_7A5608]
		MOV ECX, DWORD PTR SS : [ESP + 10h]
		CMP AL, BYTE PTR DS : [ECX + 54h]
		JNZ _007BFA69
		MOV ESI, DWORD PTR DS : [ECX + 0Ch]
		CMP ESI, 320h
		JL _007BFA69
		MOV EDI, DWORD PTR DS : [ECX + 8h]
		CMP EDI, 258h
		JL _007BFA69
		MOV EBX, DWORD PTR SS : [ESP + 14h]
		SUB ESP, 20h
		LEA ECX, DWORD PTR SS : [ESP]
		PUSH EDI
		PUSH ESI
		PUSH offset  printRes//_007BFA70; ASCII "%d x %d"
		PUSH ECX
		CALL _005FCE14// age2_x1.0061442B  005FCE14  /$ 55             PUSH EBP
		ADD ESP, 10h
		LEA EDX, DWORD PTR SS : [ESP]
		MOV ECX, EBX
		XOR EAX, EAX
		PUSH EAX
		PUSH EDI
		MOV WORD PTR SS : [ESP + 2h] , SI
		PUSH EDX
		CALL _004BCF90 //age2_x1.005473A0 
		ADD ESP, 20h
		//MOV BYTE PTR DS:[_7A5609]  , 1h
		MOV BYTE PTR DS : [_7A5608 + 1] , 1h
		MOV ECX, _7912A0
		MOV ECX, DWORD PTR DS : [ECX]
		MOV ECX, DWORD PTR DS : [ECX + 24h]
		CMP DWORD PTR DS : [ECX + 8F4h] , ESI
		JNZ _007BFA69
		CMP DWORD PTR DS : [ECX + 8FCh] , EDI
		JNZ _007BFA69
		MOV ECX, EBX
		MOVSX EAX, WORD PTR DS : [ECX + 0FCh]
		DEC EAX
		PUSH EAX
		CALL _004BCEB0 //age2_x1.005472B0
		MOV ECX, EBX
		PUSH 1h
		PUSH 0h
		PUSH 7h
		CALL _04BBF20//age2_x1.00546250
		_007BFA69 :
		POP EBX
			POP EDI
			POP ESI
			RETN 8h
			NOP
			//_007BFA70:
			//db "%d x %d", 0
	}
}
//0x0448EE8
DWORD _004BD5A0;
DWORD _00448F37;
void __declspec(naked)  AddWideScreenPanel0448EE8()
{
	__asm {
		MOV ECX, DWORD PTR DS : [ESI + 888h]
		CALL _004BD5A0 //age2_x1.005479C0
		MOV EDI, EAX
		XOR EBP, EBP
		MOV BP, AX
		SHR EDI, 10h
		JMP _00448F37 //age2_x1.005BC2EE //00448F37   > 6A 00          PUSH 0x0
	}
}

//004EC54E  |. 0F84 F4080000  JE empires2.004ECE48

DWORD _004A4570;
DWORD _004ECE48;
//DWORD _004A5230;
DWORD _004EC554;
DWORD _00948;
DWORD _00968;
DWORD _0096C;

void __declspec(naked)  AddWideScreenPanelBegingGame004EC54E()
{
	__asm {
		PUSH  1h
		PUSH  1h
		PUSH EBX
		PUSH  0Bh
		PUSH  12h
		PUSH  0A1h
		PUSH  172h
		PUSH  1C2h
		LEA EAX, _00948 //DWORD PTR SS : [EBP +  948h]
		PUSH  2531h
		PUSH EAX
		PUSH EBP
		MOV ECX, EBP
		CALL  _004A4570 //age2_x1.0055DD20
		TEST EAX, EAX
		JE __004ECE48 //age2_x1.0050CE74
		PUSH  0Ah
		PUSH  5Dh
		PUSH  80h
		PUSH  184h
		LEA ESI, _00968//DWORD PTR SS : [EBP +  968h]
		PUSH  1C2h
		PUSH ESI
		PUSH EBP
		MOV ECX, EBP
		CALL _004A5230 //age2_x1.0055E9E0
		TEST EAX, EAX
		JE __004ECE48 //age2_x1.0050CE74
		MOV ECX, DWORD PTR DS : [ESI]
		PUSH  14h
		LEA EAX, _0096C//DWORD PTR SS : [EBP +  96Ch]
		PUSH ECX
		PUSH EAX
		MOV ECX, EBP
		CALL _004A55F0 //0055EDA0 age2_x1.0055EDA0
		TEST EAX, EAX
		JE __004ECE48// age2_x1.0050CE74
		JMP _004EC554 //004EC554| . 8B0E           MOV ECX, DWORD PTR DS : [ESI]
		__004ECE48 :
		JMP _004ECE48

	}
}
//004ED45E  |. 8B01           |MOV EAX,DWORD PTR DS:[ECX]

//DWORD _004ED45E;
DWORD _004ED464; // | > 8B0B | MOV ECX, DWORD PTR DS : [EBX]


void __declspec(naked)  AddWideScreenPanelBegingGame004ED45E()
{
	__asm {
		MOV EAX, DWORD PTR SS : [ESP + 14h]
		CMP EAX, 3h
		JNZ __004ED464//age2_x1.0050D3BC
		MOV EAX, DWORD PTR DS : [ECX]
		PUSH EDI
		CALL DWORD PTR DS : [EAX + 14h]
		JMP _004ED464 //age2_x1.0050D3BC
		__004ED464 :
		JMP _004ED464
	}
}
//0044862F  |> E8 3C720600    CALL empires2.004AF870
//DWORD _007BF9D0;
DWORD _00448634;
void __declspec(naked)  AddWideScreenPanelBegingGame0044862F()
{
	__asm {
		//MOV ECX, DWORD PTR DS : [EBX + 0964h]//968
		//MOV ECX, DWORD PTR DS : [EBX]
		MOV ECX, DWORD PTR DS : [ESI + 88Ch]
		PUSH ECX
		CALL _007BF9D0// age2_x1.007BF980
		JMP _00448634//age2_x1.0050F3C8
	}
}
//004EEFF1   . 8B8D 58090000  MOV ECX,DWORD PTR SS:[EBP+0x958]

DWORD _004EF058;
DWORD _004EF06F;
//void __declspec(naked)  AddWideScreenPanelBegingGame004EEFF1()
//{
//	__asm {
//		MOV ECX, DWORD PTR SS : [EBP + 958h]//964h
//		CMP EAX, ECX
//		JNZ _007BF8EE
//		CALL _004BD5A0 //age2_x1.005479C0
//		MOV ESI, EAX
//		XOR EDI, EDI
//		MOV DI, AX
//		SHR ESI, 10h
//		JMP _004EF058 //age2_x1.0050EAFE
//		_007BF8EE :
//		JMP _004EF06F //age2_x1.0050EB18
//		NOP
//	}
//}
//004EEA81   . 8B8D 58090000  MOV ECX,DWORD PTR SS:[EBP+0x958]
//004EEAFF   > 8B8D 64090000  MOV ECX,DWORD PTR SS:[EBP+0x964]
DWORD _004EEAFF;
//004EEAE8   > 8B0D C4456600  MOV ECX,DWORD PTR DS:[0x6645C4]
DWORD _004EEAE8;
//004BD5A0  /$ 0FBF81 0401000>MOVSX EAX,WORD PTR DS:[ECX+0x104]
//DWORD _004BD5A0;


void __declspec(naked)  AddWideScreenPanelBegingGame004EEA81()
{
	__asm {
		MOV ECX, DWORD PTR SS : [EBP + 958h]//964h
		CMP EAX, ECX
		JNZ _007BF8EE
		CALL _004BD5A0 //age2_x1.005479C0
		MOV ESI, EAX
		XOR EDI, EDI
		MOV DI, AX
		SHR ESI, 10h
		JMP _004EEAE8 //age2_x1.0050EAFE
		_007BF8EE :
		JMP _004EEAFF //age2_x1.0050EB18
			NOP
	}
}
#pragma endregion resize screen
//004E1C09   . 8B46 20        MOV EAX,DWORD PTR DS:[ESI+0x20]

//00774000  =795000

void __declspec(naked)  AddWideScreenPanelSLP()
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
			CALL _007C1D90
			MOV EDX, DWORD PTR SS : [EBP + 34h]
			MOV EAX, EBX
			MOV DWORD PTR DS : [774038h] , 1C7h
			SUB EAX, EDX
			MOV DWORD PTR SS : [ESP + 10h] , EDX
			MOV DWORD PTR SS : [ESP + 8h] , EAX
			CALL _007C1D90
			ADD ESP, 28h
			POP EBP
			POP EBX
			POP EDI
			POP ESI
			RETN
			__007C1C78 :
		JMP  _007C1C78
	}
}

//004DAB6E  |. 8B8E 5C100000  MOV ECX,DWORD PTR DS:[ESI+0x105C]

DWORD _004DAB6E;
//DWORD _005A6870;
DWORD refwidth = 0x500;
DWORD refheight = 0x90;
void __declspec(naked) UnitFormationPrinteInWideScreen()
{
	__asm {

		MOV EBP, DWORD PTR DS : [ESI + 18h] ; Y
		SUB EBP, refheight
		LEA EDI, DWORD PTR DS : [ESI + 1074h]
		_007C0F71 :
		MOV EBX, DWORD PTR DS : [ESI + 14h] ; X
		SUB EBX, refwidth
		SHR EBX, 1h
		ADD EBX, 25h
		_007C0F82 :
		MOV ECX, DWORD PTR DS : [EDI]
			PUSH  28h
			PUSH  28h
			PUSH EBP
			MOV EAX, DWORD PTR DS : [ECX]
			PUSH EBX
			CALL DWORD PTR DS : [EAX + 1Ch]
			MOV ECX, DWORD PTR DS : [EDI]
			PUSH  24h
			CALL  _005A6870
			ADD EBX, 29h
			ADD EDI, 4h
			MOV EAX, DWORD PTR DS : [ESI + 14h] ; X
			SUB EAX, refwidth
			SHR EAX, 1h
			ADD EAX, 0F2h
			CMP EBX, EAX
			JL _007C0F82
			MOV EBX, DWORD PTR DS : [ESI + 18h]
			SUB EBX, 15h
			ADD EBP, 29h
			CMP EBP, EBX
			JL _007C0F71
			JMP _004DAB6E

	}
}

//DWORD _6645C4;

//004D9984 | . 8B4E 18        MOV ECX, DWORD PTR DS : [ESI + 0x18]
DWORD MyresX;
DWORD MyresY;
//004D7562  |. 50             PUSH EAX
//004D7568  |. 85C0           TEST EAX,EAX
DWORD _004D7568;
DWORD _004B9B60;
DWORD _PrecEax;
DWORD _PrecEcx;
DWORD _PrecEdx;


void __declspec(naked) SetResolution004D7562()
{
	__asm {

		MOV _PrecEax, EAX;
		MOV _PrecEcx, ECX;
		MOV _PrecEdx, EDX;

		//MOV EAX, DWORD PTR FS : [0]
		LEA ECX, DWORD PTR SS : [ESP + 18h]
			MOV EAX, DWORD PTR DS : [ECX + 24h]
			MOV  EDX, MyresX;
		MOV DWORD PTR DS : [EAX + 8F4h] , EDX
			//MOV  EAX, DWORD PTR DS : [EAX + 1Ch] ;
			LEA ECX, DWORD PTR SS : [ESP + 18h]
			MOV EAX, DWORD PTR DS : [ECX + 24h]
			MOV EDX, MyresY;
		MOV DWORD PTR DS : [ECX + 8FCh] , EDX



			MOV  EAX, _PrecEax;
		MOV  ECX, _PrecEcx;
		MOV  EDX, _PrecEdx;

		//mov DWORD PTR DS : [EAX + 18h] , MyresY
		//mov DWORD PTR DS : [EAX + 14h] , MyresX
		PUSH EAX
			CALL _004B9B60


			JMP _004D7568





	}
}

void WideScreen(int H, int V)
{
	//unit formation button print
	if (V >= 1024)
	{
		refwidth = 0x500;
		refheight = 0xB0;
	}
	else if (V >= 768 && V < 1024)
	{
		refwidth = 0x400;
		refheight = 0x90;
	}
	else if (V >= 600 && V < 768)
	{
		refwidth = 0x400;
		refheight = 0x90;
	}
	//todo check if work
	if (H > 1024)
	{
		writeDwordF(0x0DAA41, H + 0);//1024
		writeDwordF(0x0DAA5D, H + 0);//1024
		writeDwordF(0x0DAA89, H + 0);//1024
	}
	if (H == 1024)
	{
		writeDwordF(0x0DAA41, H + 0);//1024
		writeDwordF(0x0DAA5D, H + 0);//1024
		writeDwordF(0x0DAA89, H + 0);//1024

		writeDwordF(0x0DA6EA, H + 1);//1280
		writeDwordF(0x0DA706, H + 1);//1280
		writeDwordF(0x0DA732, H + 1);//1280
		writeDwordF(0x0DA732, H + 1);//1280
		writeDwordF(0x0050DA3, V + 2);//1200
	}



	if (H > 1280)
	{

		writeDwordF(0x0DA6EA, H + 1);//1280
		writeDwordF(0x0DA706, H + 1);//1280
		writeDwordF(0x0DA732, H + 1);//1280
		writeDwordF(0x0DA732, H + 1);//1280

	}

	if (V > 1200)
		writeDwordF(0x0050DA3, V + 2);//1200

		////purple up band
		////004DAA8E     6A 49                   PUSH 0x49



	if (V >= 1024)
	{
		writeDwordF(0x00DAA84, V - 250);
		writeByte(0x04DAA8F, 0x20);
		//precY = 1024;
	}
	else if (V >= 768 && V < 1024)
	{
		writeDwordF(0x00DAA84, V - 200);
		writeByte(0x04DAA8F, 0x19);
		//precY = 768;
	}
	else if (V >= 600 && V < 768)
	{
		//writeDwordF(0x00DAA84, V - 230);
		writeDwordF(0x00DAA84, V - 200);
		writeByte(0x04DAA8F, 0x19);
		//writeByte(0x04DA6EF + 1, 0x84);
		//writeByte(0x04DAD9D + 1, 0x84);
	}

	//if (V >= 600 && V < 768)
	//	precY = 600;


	int ratioV = 0;
	int ratioH = 0;
	if (V >= 1024)
	{
		ratioH = -(H - 1024 - 169) / 2;
		ratioV = -20;
	}
	else if (V < 1024 && V >= 768)
	{
		ratioH = -(H - 800 - 219) / 2;
	}
	//else if (V < 768 && V >= 600)
	//{
	//	ratioH = -(H - 800 ) / 2;
	//}

	writeDwordF(0x00DA71B, V - 279);
	writeDwordF(0x00DA72D, V - 249);
	writeDwordF(0x00DA766, V - 206);
	writeDwordF(0x00DA7C9, V - 196);
	writeDwordF(0x00DA7D8, V - 178);
	//writeDwordF(0x00DA810, V - 55);//0f
	writeDwordF(0x00DA917, H - 301);
	writeDwordF(0x00DA92D, H - 241);
	writeDwordF(0x00DA943, H - 181);
	writeDwordF(0x00DA959, H - 121);
	writeDwordF(0x00DA96F, H - 62);

	writeDwordF(0x00DA981, V - 194);
	writeDwordF(0x00DA99A, V - 67);
	writeDwordF(0x00DA9B3, V - 197);
	writeDwordF(0x00DA9CC, V - 197);
	writeDwordF(0x00DA9E5, V - 167);
	writeDwordF(0x00DA9FE, V - 77);

	/*		writeDwordF(0x00DAA17, V - 48);
			writeDwordF(0x00DAA30, V - 44);*/


			//writeDwordF(0x00DAA41, H + 0);//1024
			//writeDwordF(0x00DAA5D, H + 0);//1024
	writeDwordF(0x00DAA72, V + ratioV - 230);
	//writeDwordF(0x00DAA84, V - 200);

	//writeDwordF(0x00DAA89, H + ratioH + 0);//1024
	//mini map 
	if (V >= 1024)
	{
		writeDwordF(0x00DAABD, V + ratioV - 187);
		writeDwordF(0x00DAAC4, H + ratioH - 369);
	}
	else if (V < 1024 && V >= 600)
	{
		writeDwordF(0x00DAABD, V + ratioV - 169);
		writeDwordF(0x00DAAC4, H + ratioH - 336);
	}
	//else if (V >= 600 && V < 768)
	//{
	//	//writeDwordF(0x00DAABD, V + ratioV - 169);
	//	//writeDwordF(0x00DAAC4, H + ratioH - 336);
	//	writeDwordF(0x00DAABD, V + ratioV - 187);
	//	writeDwordF(0x00DAAC4, H + ratioH - 369);
	//}

	//mini map size
	//004DAAD2     68 E9C40000            PUSH 0xC4E9
	if (V > 1024)
	{
		writeDwordF(0xDAAD2, 0xC4E9);
		//004DAAB8     68 8A010000    PUSH 0x18A
		writeDwordF(0x0DAAB8, 0x18A);
		//004DAAB3     68 C6000000    PUSH 0xC6
		writeDwordF(0x0DAAB3, 0x0C6);

	}
	else if (V < 1024 && V >= 768)
	{
		writeDwordF(0xDAAD2, 0xC4E8);
		//004DAAB8     68 8A010000    PUSH 0x18A
		//004DAAB8     68 8A010000    PUSH 0x18A
		writeDwordF(0x0DAAB8, 0x146);
		//004DAAB3     68 C6000000    PUSH 0xC6
		writeDwordF(0x0DAAB3, 0x0A4);
	}
	else if (V < 768 && V >= 600)
	{

		writeDwordF(0xDAAD2, 0xC4EB);
		//004DAAB8     68 8A010000    PUSH 0x18A
		//004DAAB8     68 8A010000    PUSH 0x18A
		writeDwordF(0x0DAAB8, 0x10A);
		//004DAAB3     68 C6000000    PUSH 0xC6
		writeDwordF(0x0DAAB3, 0x086);
	}
	//current age label
	writeDwordF(0x00DAAF2, H / 2 - 112);
	//formation + villager build button?

	writeDwordF(0x00DAB2F, V + ratioV - 144);
	writeDwordF(0x00DAB67, V + ratioV - 21);//21




	//selection

	int ratioSH = 0;
	if (V >= 1024)
	{
		ratioSH = -(H - 1024 / 2) / 2 - 1024 / 2 - 50;
		//x
		writeDwordF(0x00DAB20, V + ratioV - 162);
	}
	else if (V < 1024 && V >= 768)
	{
		ratioSH = -(H - 800) / 2 - 800 / 2 - 230;
		//x
		writeDwordF(0x00DAB20, V + ratioV - 152);
	}
	//else if (V < 768 && V >= 600)
	//{
	//	ratioSH = -(H - 800) / 2 - 800 / 2 ;
	//	//x
	//	writeDwordF(0x00DAB20, V + ratioV - 152);
	//}

	writeDwordF(0x0DAB27, H + ratioSH);//
	int ratioSHeight = 0;
	if (V >= 1024)
	{
		ratioSHeight = (1024 / 2);
	}
	else if (V < 1024 && V >= 768)
	{
		ratioSHeight = (800) / 2;
	}
	//else if (V < 768 && V >= 600)
	//{
	//	ratioSHeight = (800) / 2;
	//}
	//size of army selection
	writeDwordF(0x00DAB1B, ratioSHeight);


	//diplomatie button
	writeDwordF(0x00DAC6E, H - 303);
	writeDwordF(0x00DAC84, H - 243);
	writeDwordF(0x00DAC9A, H - 183);
	writeDwordF(0x00DACB0, H - 123);
	writeDwordF(0x00DACC6, H - 64);
	//mini map button
	int ratioVm = 0;

	if (V >= 1024)
	{
		ratioVm = -40;
	}
	//flashing x button 
	writeDwordF(0x00DACD8, V + ratioVm - 154);
	writeDwordF(0x00DACDF, H + ratioH - 308);
	//idle button
	writeDwordF(0x00DACF1, V + -49);
	writeDwordF(0x00DACF8, H + ratioH - 309);
	//player name button
	writeDwordF(0x00DAD0A, V + ratioVm - 156);
	writeDwordF(0x00DAD11, H + ratioH - 96);
	//

	if (V >= 1024)
	{
		writeDwordF(0x00DAD2A, H + ratioH - 29);
		writeDwordF(0x00DAD23, V + ratioVm - 142);
	}
	else if (V < 1024 && V >= 768)
	{
		writeDwordF(0x00DAD2A, H + ratioH - 50);
		writeDwordF(0x00DAD23, V + -132);
	}

	//ok
	writeDwordF(0x00DAD3C, V + ratioVm - 156);
	writeDwordF(0x00DAD43, H + ratioH - 66);
	//
	writeDwordF(0x00DAD55, V - 59);
	writeDwordF(0x00DAD5C, H + ratioH - 61);
	//
	writeDwordF(0x00DAD6E, V - 35);
	writeDwordF(0x00DAD75, H + ratioH - 74);
	//idel show
	writeDwordF(0x00DAD87, V - 39);
	writeDwordF(0x00DAD8E, H + ratioH - 102);
	////ressources number Y
	////004DAAA4     6A 20                   PUSH 0x20
	//writeDwordF(0x0DAAA4, 1);
	////ressources X
	////004DAAA8     6A 10                   PUSH 0x10
	////writeDwordF(0x0DAAA8, 1);



	writeDwordF(0x00E4731, V - 171);
	writeDwordF(0x00E4747, V - 138);
	writeDwordF(0x00E4789, V - 138);
	writeDwordF(0x00E475D, V - 118);
	writeDwordF(0x00E4790, V - 118);
	writeDwordF(0x00E4773, V - 98);
	writeDwordF(0x00E47B5, V - 98);
	writeDwordF(0x00E47CB, V - 59);
	writeDwordF(0x00E47E1, V - 59);
	writeDwordF(0x00E47F7, V - 59);
	writeDwordF(0x00E4810, V - 59);
	writeDwordF(0x00E482B, V - 59);
	writeDwordF(0x00E4854, V - 144);
	writeDwordF(0x00E48AA, V - 118);
	writeDwordF(0x00E4868, V - 118);
	writeDwordF(0x00E487E, V - 98);
	writeDwordF(0x00E48C0, V - 98);
	writeDwordF(0x00E4894, V - 78);
	writeDwordF(0x00E48D6, V - 78);
	writeDwordF(0x00E48EC, V - 54);
	writeDwordF(0x00E4902, V - 54);
	writeDwordF(0x00E4918, V - 54);
	writeDwordF(0x00E4931, V - 54);
	writeDwordF(0x00E494A, V - 54);


}


void patchEXE_(int V, int H)
{

	//unit formation button print
	if (V >= 1024)
	{
		refwidth = 0x500;
		refheight = 0xB0;
	}
	else if (V >= 768 && V < 1024)
	{
		refwidth = 0x400;
		refheight = 0x90;
	}
	else if (V >= 600 && V < 768)
	{
		refwidth = 0x400;
		refheight = 0x90;
	}
	//todo check if work
	if (H > 1024)
	{
		writeDwordF(0x0DAA41, H + 0);//1024
		writeDwordF(0x0DAA5D, H + 0);//1024
		writeDwordF(0x0DAA89, H + 0);//1024
	}
	if (H == 1024)
	{
		writeDwordF(0x0DAA41, H + 0);//1024
		writeDwordF(0x0DAA5D, H + 0);//1024
		writeDwordF(0x0DAA89, H + 0);//1024

		writeDwordF(0x0DA6EA, H + 1);//1280
		writeDwordF(0x0DA706, H + 1);//1280
		writeDwordF(0x0DA732, H + 1);//1280
		writeDwordF(0x0DA732, H + 1);//1280
		writeDwordF(0x0050DA3, V + 2);//1200
	}



	if (H > 1280)
	{

		writeDwordF(0x0DA6EA, H + 1);//1280
		writeDwordF(0x0DA706, H + 1);//1280
		writeDwordF(0x0DA732, H + 1);//1280
		writeDwordF(0x0DA732, H + 1);//1280

	}

	if (V > 1200)
		writeDwordF(0x0050DA3, V + 2);//1200

		////purple up band
		////004DAA8E     6A 49                   PUSH 0x49



	if (V >= 1024)
	{
		writeDwordF(0x00DAA84, V - 250);
		writeByte(0x04DAA8F, 0x20);
		//precY = 1024;
	}
	else if (V >= 768 && V < 1024)
	{
		writeDwordF(0x00DAA84, V - 200);
		writeByte(0x04DAA8F, 0x19);
		//precY = 768;
	}
	else if (V >= 600 && V < 768)
	{
		writeDwordF(0x00DAA84, V - 230);
	}
	//if (V >= 600 && V < 768)
	//	precY = 600;



	//else if (V < 768 && V >= 600)
	//{
	//	ratioH = -(H - 800 ) / 2;
	//}

	writeDwordF(0x00DA71B, V - 279);
	writeDwordF(0x00DA72D, V - 249);
	writeDwordF(0x00DA766, V - 206);
	writeDwordF(0x00DA7C9, V - 196);
	writeDwordF(0x00DA7D8, V - 178);
	//writeDwordF(0x00DA810, V - 55);//0f
	writeDwordF(0x00DA917, H - 301);
	writeDwordF(0x00DA92D, H - 241);
	writeDwordF(0x00DA943, H - 181);
	writeDwordF(0x00DA959, H - 121);
	writeDwordF(0x00DA96F, H - 62);

	writeDwordF(0x00DA981, V - 194);
	writeDwordF(0x00DA99A, V - 67);
	writeDwordF(0x00DA9B3, V - 197);
	writeDwordF(0x00DA9CC, V - 197);
	writeDwordF(0x00DA9E5, V - 167);
	writeDwordF(0x00DA9FE, V - 77);

	/*		writeDwordF(0x00DAA17, V - 48);
			writeDwordF(0x00DAA30, V - 44);*/


			//writeDwordF(0x00DAA41, H + 0);//1024
			//writeDwordF(0x00DAA5D, H + 0);//1024
	writeDwordF(0x00DAA72, V  - 230);
	//writeDwordF(0x00DAA84, V - 200);

	//writeDwordF(0x00DAA89, H + ratioH + 0);//1024
	//mini map 
	if (V >= 1024)
	{
		writeDwordF(0x00DAABD, V  - 187);
		writeDwordF(0x00DAAC4, H  - 369);
	}
	else if (V < 1024 && V >= 768)
	{
		writeDwordF(0x00DAABD, V  - 169);
		writeDwordF(0x00DAAC4, H  - 336);
	}

	////mini map size
	////004DAAD2     68 E9C40000            PUSH 0xC4E9
	//if (V > 1024)
	//{
	//	writeDwordF(0xDAAD2, 0xC4E9);
	//	//004DAAB8     68 8A010000    PUSH 0x18A
	//	writeDwordF(0x0DAAB8, 0x18A);
	//	//004DAAB3     68 C6000000    PUSH 0xC6
	//	writeDwordF(0x0DAAB3, 0x0C6);

	//}
	//else if (V < 1024 && V >= 768)
	//{
	//	writeDwordF(0xDAAD2, 0xC4E8);
	//	//004DAAB8     68 8A010000    PUSH 0x18A
	//	//004DAAB8     68 8A010000    PUSH 0x18A
	//	writeDwordF(0x0DAAB8, 0x146);
	//	//004DAAB3     68 C6000000    PUSH 0xC6
	//	writeDwordF(0x0DAAB3, 0x0A4);
	//}
	//else if (V < 768 && V >= 600)
	//{
	//	writeDwordF(0xDAAD2, 0xC4EB);
	//	//004DAAB8     68 8A010000    PUSH 0x18A
	//	//004DAAB8     68 8A010000    PUSH 0x18A
	//	writeDwordF(0x0DAAB8, 0x10A);
	//	//004DAAB3     68 C6000000    PUSH 0xC6
	//	writeDwordF(0x0DAAB3, 0x086);
	//}
	//current age label
	writeDwordF(0x00DAAF2, H / 2 - 112);
	//formation + villager build button?

	writeDwordF(0x00DAB2F, V  - 144);
	writeDwordF(0x00DAB67, V  - 21);//21




	//selection

	int ratioSH = 0;
	if (V >= 1024)
	{
		//ratioSH = -(H - 1024 / 2) / 2 - 1024 / 2 - 50;
		//x
		writeDwordF(0x00DAB20, V  - 162);
	}
	else if (V < 1024 && V >= 768)
	{
		//ratioSH = -(H - 800) / 2 - 800 / 2 - 230;
		//x
		writeDwordF(0x00DAB20, V  - 152);
	}
	//else if (V < 768 && V >= 600)
	//{
	//	ratioSH = -(H - 800) / 2 - 800 / 2 ;
	//	//x
	//	writeDwordF(0x00DAB20, V + ratioV - 152);
	//}

	writeDwordF(0x0DAB27, H - 230);//
	int ratioSHeight = 0;

	//else if (V < 768 && V >= 600)
	//{
	//	ratioSHeight = (800) / 2;
	//}
	//size of army selection
	writeDwordF(0x00DAB1B, ratioSHeight);


	//diplomatie button
	writeDwordF(0x00DAC6E, H - 303);
	writeDwordF(0x00DAC84, H - 243);
	writeDwordF(0x00DAC9A, H - 183);
	writeDwordF(0x00DACB0, H - 123);
	writeDwordF(0x00DACC6, H - 64);
	//mini map button
	int ratioVm = 0;


	//flashing x button 
	writeDwordF(0x00DACD8, V  - 154);
	writeDwordF(0x00DACDF, H  - 308);
	//idle button
	writeDwordF(0x00DACF1, V  -49);
	writeDwordF(0x00DACF8, H  - 309);
	//player name button
	writeDwordF(0x00DAD0A, V  - 156);
	writeDwordF(0x00DAD11, H - 96);
	//

	if (V >= 1024)
	{
		writeDwordF(0x00DAD2A, H  - 29);
		writeDwordF(0x00DAD23, V  - 142);
	}
	else if (V < 1024 && V >= 768)
	{
		writeDwordF(0x00DAD2A, H  - 50);
		writeDwordF(0x00DAD23, V + -132);
	}

	//ok
	writeDwordF(0x00DAD3C, V  - 156);
	writeDwordF(0x00DAD43, H  - 66);
	//
	writeDwordF(0x00DAD55, V - 59);
	writeDwordF(0x00DAD5C, H  - 61);
	//
	writeDwordF(0x00DAD6E, V - 35);
	writeDwordF(0x00DAD75, H  - 74);
	//idel show
	writeDwordF(0x00DAD87, V - 39);
	writeDwordF(0x00DAD8E, H  - 102);
	////ressources number Y
	////004DAAA4     6A 20                   PUSH 0x20
	//writeDwordF(0x0DAAA4, 1);
	////ressources X
	////004DAAA8     6A 10                   PUSH 0x10
	////writeDwordF(0x0DAAA8, 1);



	writeDwordF(0x00E4731, V - 171);
	writeDwordF(0x00E4747, V - 138);
	writeDwordF(0x00E4789, V - 138);
	writeDwordF(0x00E475D, V - 118);
	writeDwordF(0x00E4790, V - 118);
	writeDwordF(0x00E4773, V - 98);
	writeDwordF(0x00E47B5, V - 98);
	writeDwordF(0x00E47CB, V - 59);
	writeDwordF(0x00E47E1, V - 59);
	writeDwordF(0x00E47F7, V - 59);
	writeDwordF(0x00E4810, V - 59);
	writeDwordF(0x00E482B, V - 59);
	writeDwordF(0x00E4854, V - 144);
	writeDwordF(0x00E48AA, V - 118);
	writeDwordF(0x00E4868, V - 118);
	writeDwordF(0x00E487E, V - 98);
	writeDwordF(0x00E48C0, V - 98);
	writeDwordF(0x00E4894, V - 78);
	writeDwordF(0x00E48D6, V - 78);
	writeDwordF(0x00E48EC, V - 54);
	writeDwordF(0x00E4902, V - 54);
	writeDwordF(0x00E4918, V - 54);
	writeDwordF(0x00E4931, V - 54);
	writeDwordF(0x00E494A, V - 54);





}
#pragma endregion
void NormaleAoeWideScreen(DWORD* myCord_X , DWORD* myCord_Y)
{
#pragma region   Modify resolution systems
#pragma region resize interface slp
	//457ED0
	_0045FD90 = 0x045FD90;
	//0x4580A4
	_004580A9 = 0x04580A9;
	_004580A4 = 0x04580A4;
	_004DB740 = 0x04DB740;
	_004580BD = 0x04580BD;
	_0051EFF0 = 0x051EFF0;
	//7C08C0
	_6645C4 = 0x06645C4;//7912A0
	_0051EFF0 = 0x051EFF0;
	_004580A9 = 0x04580A9;
	_004A23E0 = 0x004A23E0;
	//_AddWideScreenPanel7C08C0 = (DWORD) AddWideScreenPanel7C08C0;
	//setHook((void*)0x457ED0, AddWideScreenPanel457ED0);
	//// call 7C08C0
	//setHook((void*)0x4580A4, AddWideScreenPanel4580A4);
	////4E1C38
	_005223C2 = 0x04E1C45;
	//setHook((void*)0x04E1C38, AddWideScreenPanel004E1C38);

	////007C1D90
	_007C1C78 = (DWORD)AddWideScreenPanel007C1C78;
	_00619C48 = 0x0619C48;
	_007C1D90 = (DWORD)AddWideScreenPanel007C1D90;

	_00619BC0 = 0x0619BC0;
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



	_004DA6EA = 0x04DA6EA;
	_4DA6CC = 0x04DA6CC;
	//004DA6E7  |. 8B46 14        MOV EAX,DWORD PTR DS:[ESI+0x14]   -> X 
	setHook((void*)0x04DA6E5, AddWideScreenPanelreadXY);

	//004E1C0E     90             NOP
	setHook((void*)0x04E1C0E, AddWideScreenPanelSLP);
	BYTE PUSH_4E1C20[] = { 0x68,0x20,0x1C,0x4E,0x00 };
	writeData(0x04E1C09, PUSH_4E1C20, 5);
	writeByte(0x04E1C13, 0x90);



#pragma endregion resize interface slp

	///resize  screen 
#pragma region resize  screen 
		//00448066  |. 6A 69          |PUSH 0x69                               ; |Arg4 = 00000069
	writeByte(0x0448067, 0x6E);
	//00448095  |. 6A 46          |PUSH 0x46                               ; |Arg3 = 00000046
	writeByte(0x0448096, 0x4B);
	//00448F6B   . 74 26          JE SHORT empires2.00448F93
	writeByte(0x0448F6B, 0x66);
	writeByte(0x0448F6C, 0x90);
	_7912A0 = 0x06645C4;//7912A0
	//00448551  |. 8B6C24 4C      MOV EBP,DWORD PTR SS:[ESP+0x4C]
	setHook((void*)0x0448551, AddWideScreenPanel00448551);
	//007BF980
	_00448925 = 0x0448925;
	_004A5230 = 0x04A5230;
	_0044869C = 0x044869C;
	_004BCF90 = 0x04BCF90;
	_004BCEB0 = 0x04BCEB0;
	_005FCE14 = 0x05FCE14;
	_04BBF20 = 0x04BBF20;
	_004A55F0 = 0x04A55F0;
	_004BD5E0 = 0x04BD5E0;
	_007BF980 = (DWORD)AddWideScreenPanel007BF980;
	_007BF9D0 = (DWORD)AddWideScreenPanel007BF9D0;
	//00448EE8   > 8B8E 84080000  MOV ECX,DWORD PTR DS:[ESI+0x884]
	_004BD5A0 = 0x04BD5A0;
	_00448F37 = 0x0448F37;
	setHook((void*)0x0448EE8, AddWideScreenPanel0448EE8);
	//game start panel
	//
	//
	//todo

	/*
	_004A4570 = 0x04A4570;
	_004ECE48 = 0x04ECE48;
	_004A5230 = 0x04A5230;
	_004EC554 = 0x04EC554;
	//0x04EC54E
	setHook((void*)0x04EC54E, AddWideScreenPanelBegingGame004EC54E);
	//004ED45C  |. 74 06          |JE SHORT empires2.004ED464
	_004ED464 = 0x04ED464;
	setHook((void*)0x04ED45E, AddWideScreenPanelBegingGame004ED45E);
	//004ED677  |> E8 4426FCFF    CALL Empires2.004AFCC0
	//_004ED45E = 0x04ED45E;
	_00448634 = 0x0448634;

	setHook((void*)0x0044862F, AddWideScreenPanelBegingGame0044862F);
	//004EEFF1   . 8B8D 58090000  MOV ECX,DWORD PTR SS:[EBP+0x958]
	_004EF058 = 0x04EF058;
	_004EF06F = 0x04EF06F;
	//004EEA81   . 8B8D 58090000  MOV ECX,DWORD PTR SS:[EBP+0x958]

	_004EEAFF= 0x04EEAFF;
	//004EEAE8   > 8B0D C4456600  MOV ECX,DWORD PTR DS:[0x6645C4]
	_004EEAE8= 0x04EEAE8;

	setHook((void*)0x04EEA81, AddWideScreenPanelBegingGame004EEA81);
	//004EF3FF
	BYTE _83C40C6690[] = {0x83,0xC4,0x0C,0x66,0x90};
	writeData(0x04EF3FF, _83C40C6690, 5);
	//004EF414
	writeData(0x04EF414, _83C40C6690, 5);
	//004EF429
	writeData(0x04EF429, _83C40C6690, 5);
	*/
#pragma endregion resize  screen 

#pragma endregion
	//Formation button pront X and Y
	_004DAB6E = 0x04DAB6E;
	_005A6870 = 0x05A6870;
	//004DAB3A     BB 50020000    MOV EBX,0x250
	//writeDwordF(0x04DAB3A, V + ratioV - 400);//21
	setHook((void*)0x04DAB3A, UnitFormationPrinteInWideScreen);
	//WideScreen(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));


	*myCord_X = Cord_X;
	*myCord_Y = Cord_Y;

	//fix bug  1280 force to jum 1024x768
//004DA6F5     E9 52030000    JMP 004DAA4C
	BYTE _004DAA4C[] = { 0xE9,0x52,0x03,0x00,0x00,0x90 };
	writeData(0x04DA6F5, _004DAA4C, 6);
}