#include <Windows.h>
#include "Hookbase.h"
#pragma region Add unit button formation
//0x4DEE9A 
DWORD _004E6070;

void __declspec(naked)  AddunitFormation4DEE9A()
{
	__asm {
		MOV ECX, 51h
		XOR EDX, EDX
		MOV DL, BYTE PTR DS : [ECX + 4DF018h]
		CMP EAX, 0AEh
		PUSH 5h  //fusion formation
		MOV ECX, ESI
		CALL _004E6070
		MOV ECX, DWORD PTR SS : [ESP + 4h]
		MOV DWORD PTR FS : [0h] , ECX
		POP ESI
		ADD ESP, 0Ch
		RETN 0Ch
	}
}
//4E5C57
DWORD _004E5C5C;
DWORD _004DFF50;
void __declspec(naked)  AddunitFormation4E5C57()
{
	__asm {
		CALL _004DFF50
		PUSH 0h
		PUSH 0h
		MOV EDX, DWORD PTR DS : [ESI + 101Ch]
		PUSH 0h
		PUSH 0h
		PUSH 0h
		PUSH - 1h
		PUSH 0A03Fh
		PUSH 0h
		PUSH 0AFh
		PUSH 2Ch
		PUSH 0Eh
		PUSH EDX
		MOV ECX, ESI
		CALL _004DFF50
		JMP[_004E5C5C]
	}
}
//0x5B30BD
void __declspec(naked)  AddunitFormation5B30BD()
{
	__asm {
		CMP EDX, 0AFh
		JNZ SHORT _007E5119
		MOV EDX, DWORD PTR SS : [ESP + 20h]
		MOV EAX, DWORD PTR DS : [ECX]
		PUSH EDX
		PUSH ESI
		PUSH 9C59h
		CALL DWORD PTR DS : [EAX + 24h]
		POP EDI
		POP ESI
		POP EBP
		RETN 14h
		_007E5119 :
		MOV BYTE PTR DS : [EBP + ESI - 1h] , 0h
		MOV EAX, ESI
		POP EDI
		POP ESI
		POP EBP
		RETN 14h
	}
}
//0053AE42
DWORD _00472E50;
void __declspec(naked)  AddunitFormation53AE42()
{
	__asm {
		CMP EDX, 0AFh
		JNZ _007E5175
		LEA EAX, DWORD PTR SS : [ESP + 3h]
		LEA EDX, DWORD PTR SS : [ESP + 3h]
		PUSH EAX
		LEA EAX, DWORD PTR SS : [ESP + 7h]
		PUSH EDX
		PUSH EAX
		PUSH 6h
		PUSH 0Ch
		CALL _00472E50
		POP ECX
		RETN 4h
		_007E5175 :
		XOR EAX, EAX
		POP ECX
		RETN 4h
	}
}
//0045E259   > 8180 07000000 >ADD DWORD PTR DS:[EAX+0x7],0x38811675


#pragma endregion


void AddNewBittonFormation()
{

	//0x04E5C57  
	_004E5C5C = 0x04E5C5C;
	_004DFF50 = 0x04DFF50;
	setHook((void*)0x04E5C57, AddunitFormation4E5C57);
	//0x4DEE9A
	_004E6070 = 0x04E6070;
	setHook((void*)0x04DEE9A, AddunitFormation4DEE9A);
	//0x05B30BD
	setHookJA((void*)0x05B30BD, AddunitFormation5B30BD);
	//0053AE42
	_00472E50 = 0x0472E50;
	setHookJA((void*)0x053AE42, AddunitFormation53AE42);

}