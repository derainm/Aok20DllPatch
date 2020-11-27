#include <Windows.h>
#include "Hookbase.h"


#pragma region Add Rms
DWORD _782A00;
DWORD _004B2940;
DWORD _7829F0;
DWORD _7829E0;
DWORD _7829D0;
DWORD _782A10;
DWORD _782A20;
DWORD _004FD755;
void __declspec(naked)  AddRMS4FD743()
{
	__asm {
		MOV _782A00, 15h
		MOV ECX, DWORD PTR DS : [ESI + 0AF4h]
		PUSH 18h
		PUSH 02A8Ah
		CALL _004B2940
		MOV _7829F0, EAX
		MOV _7829E0, ECX
		MOV _7829D0, EDX
		MOV _782A10, 018h
		MOV _782A20, 02A7Bh//  10875, 	"Arabia"
		_007E0E3D :
		MOV EDX, _782A00
		MOV EAX, _782A10
		MOV ECX, _782A20
		ADD EAX, 01h
		DEC ECX
		MOV _782A10, EAX
		MOV _782A20, ECX
		PUSH EAX
		PUSH ECX
		MOV ECX, DWORD PTR DS : [ESI + 0AF4h]
		DEC EDX
		MOV _782A00, EDX
		CALL _004B2940
		CMP _782A00, 0h
		JNZ _007E0E3D
		JMP[_004FD755]
	}
}
//when start game 
//0x05996AD
DWORD _00599729;
void __declspec(naked)  AddRMS5996AD()
{
	__asm {
		JA SHORT _007E0F00
		JMP DWORD PTR DS : [EAX * 4h + 05997D8h]
		_007E0F00 :
		MOV _782A00, 15h
		MOV _7829F0, EAX
		MOV _7829E0, ECX
		MOV _7829D0, EDX
		MOV ECX, 02710h
		ADD ECX, _782A00
		SUB EAX, 0Fh
		SUB ECX, EAX
		MOV ESI, ECX
		PUSH 02F98Ch// PUSH 2F98C                               ;  Default case of switch 005996A7
		JMP[_00599729]
	}
}
//0x506878
DWORD _0050687D;
void __declspec(naked)  AddRMS506878()
{
	__asm {
		MOV _782A00, 15h
		CALL _004B2940
		MOV _7829F0, EAX
		MOV _7829E0, ECX
		MOV _7829D0, EDX
		MOV _782A10, 018h
		MOV _782A20, 02A7Bh//  10875, 	"Arabia"
		_007E102A :
		MOV EDX, _782A00
		MOV EAX, _782A10
		MOV ECX, _782A20
		ADD EAX, 01h
		DEC ECX
		MOV _782A10, EAX
		MOV _782A20, ECX
		PUSH EAX
		PUSH ECX
		MOV ECX, DWORD PTR DS : [ESI]
		DEC EDX
		MOV _782A00, EDX
		CALL _004B2940
		CMP _782A00, 0h
		JNZ _007E102A
		JMP[_0050687D]
	}
}
#pragma endregion


void AddRms()
{
	//0x04FD743  
	_782A00 = 0x0782A00;
	_004B2940 = 0x04B2940;
	_7829F0 = 0x07829F0;
	_7829E0 = 0x07829E0;
	_7829D0 = 0x07829D0;
	_782A10 = 0x0782A10;
	_782A20 = 0x0782A20;
	_004FD755 = 0x04FD755;
	setHook((void*)0x04FD743, AddRMS4FD743);
	//688CF90200
	//00599724   > 68 8CF90200    PUSH 2F98C                               ;  Default case of switch 005996A7
	writeDwordF(0x0599724, 0x8CF90200);
	//0x05996AD
	_00599729 = 0x0599729;
	setHook((void*)0x05996AD, AddRMS5996AD);
	//0x506878
	//on scenario screen
	_0050687D = 0x050687D;
	setHook((void*)0x506878, AddRMS506878);
}