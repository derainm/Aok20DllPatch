#include <windows.h>
#include "Hookbase.h"

char _007DB7BD[100] = "TCP";
char _007DB7C5[100] = "empires2:%s.%d";
DWORD ___005FCE14 = 0x05FCE14;
DWORD _00605C40 = 0x0605C40;
DWORD _7A5800;
DWORD _7A5144;
DWORD _7A5140;
DWORD _7A5154;
DWORD _7A5158;
DWORD _7A515C;
DWORD _7A5148;
DWORD _7A5150;
DWORD _7A5160;
DWORD _7A5164;
DWORD _7A5168;
DWORD _7A514C;
DWORD _7A5854;
DWORD _7A5858;
DWORD _7A585C;
DWORD _7A5860;
DWORD _7A5810;
DWORD _7A5814;
DWORD _7A5818;
DWORD _7A581C;
DWORD _7A5820;
DWORD _7A5824;
DWORD _7A5828;
DWORD _7A582C;
DWORD _7A5830;
DWORD _7A5834;
DWORD _7A5838;
DWORD _7A583C;
DWORD _7A5840;
DWORD _7A5844;
DWORD _7A5848;
DWORD _7A584C;
DWORD _7A5850;
DWORD _7A5870;
DWORD _7A5874;

void __declspec(naked) PortForwarding_007DB530()
{
	__asm {

		SUB ESP, 40h
		MOV EAX, DWORD PTR SS : [ESP + 44h]
		MOV EDX, DWORD PTR SS : [ESP + 48h]
		LEA ECX, DWORD PTR DS : [EDX * 4h + 7DB7BDh]
		LEA EDX, DWORD PTR SS : [ESP]
		PUSH EAX
		PUSH ECX
		PUSH offset _007DB7C5; ASCII "age2_x1:%s.%d"
		PUSH EDX
		//CALL age2_x1.0061442B
		CALL ___005FCE14
		ADD ESP, 10h
		MOV EDX, DWORD PTR SS : [ESP + 48h]
		LEA ECX, DWORD PTR DS : [EDX * 4h + 7DB7BDh]
		LEA EDX, DWORD PTR SS : [ESP]
		LEA EAX, DWORD PTR SS : [ESP + 0Ch]
		PUSH 0h
		PUSH 0h
		PUSH ECX
		PUSH EDX
		MOV EDX, DWORD PTR DS : [_7A5148]
		PUSH EDX
		PUSH EAX
		PUSH EAX
		MOV ECX, DWORD PTR DS : [_7A5144]
		MOV EAX, DWORD PTR DS : [_7A5140]
		PUSH ECX
		PUSH EAX
		CALL DWORD PTR DS : [_7A5154]
		ADD ESP, 64h
		RETN 8h
		ADD BYTE PTR DS : [EBX + 448B40ECh] , AL
		AND AL, 44h
		LEA EDX, DWORD PTR SS : [ESP]
		PUSH EAX
		PUSH offset _007DB7BD; ASCII "TCP"
		PUSH offset _007DB7C5; ASCII "age2_x1:%s.%d"
		PUSH EDX
		//CALL age2_x1.0061442B
		CALL ___005FCE14
		ADD ESP, 10h
		MOV EDX, DWORD PTR SS : [ESP + 48h]
		LEA ECX, DWORD PTR DS : [EDX * 4h + 7DB7BDh]
		LEA EAX, DWORD PTR SS : [ESP + 0Ch]
		PUSH 0h
		PUSH ECX
		PUSH EAX
		MOV ECX, DWORD PTR DS : [_7A5144]
		MOV EAX, DWORD PTR DS : [_7A5140]
		PUSH ECX
		PUSH EAX
		CALL DWORD PTR DS : [_7A5158]
		ADD ESP, 54h
		RETN 8h
		ADD BYTE PTR DS : [EAX] , AL
		ADD BYTE PTR DS : [EAX] , AL
		ADD BYTE PTR DS : [EAX] , AL
		SUB ESP, 40h
		MOV EAX, DWORD PTR SS : [ESP + 44h]
		LEA EDX, DWORD PTR SS : [ESP]
		PUSH EAX
		PUSH offset _007DB7BD; ASCII "TCP"
		PUSH offset _007DB7C5; ASCII "age2_x1:%s.%d"
		PUSH EDX
		//CALL age2_x1.0061442B
		CALL ___005FCE14
		ADD ESP, 10h
		XOR EAX, EAX
		LEA ECX, DWORD PTR SS : [ESP + 20h]
		LEA EDX, DWORD PTR SS : [ESP + 30h]
		MOV DWORD PTR DS : [ECX] , EAX
		PUSH EAX
		PUSH EAX
		PUSH EAX
		PUSH EDX
		PUSH ECX
		MOV EDX, DWORD PTR SS : [ESP + 5Ch]
		LEA ECX, DWORD PTR DS : [EDX * 4h + 7DB7BDh]
		LEA EAX, DWORD PTR SS : [ESP + 20h]
		PUSH ECX
		PUSH EAX
		MOV ECX, DWORD PTR DS : [_7A5144]
		MOV EAX, DWORD PTR DS : [_7A5140]
		PUSH ECX
		PUSH EAX
		CALL DWORD PTR DS : [_7A515C]
		TEST EAX, EAX
		JE short _007DB642
		MOV EAX, 1h
		ADD ESP, 64h
		RETN 8h
		_007DB642:
		LEA ECX, DWORD PTR SS : [ESP + 54h]
		LEA EDX, DWORD PTR SS : [ESP + 30h]
		PUSH ECX
		PUSH EDX
		//CALL age2_x1.0061CD70
		CALL _00605C40
		TEST EAX, EAX
		JE short _007DB660
		MOV EAX, 2h
		ADD ESP, 6Ch
		RETN 8h
		_007DB660:
		LEA ECX, DWORD PTR SS : [ESP + 4Ch]
		MOV EDX, DWORD PTR DS : [_7A5148]
		PUSH ECX
		PUSH EDX
		//CALL age2_x1.0061CD70
		CALL _00605C40
		NEG EAX
		SBB EAX, EAX
		AND EAX, 0FFFFFFFEh
		ADD EAX, 2h
		ADD ESP, 74h
		RETN 8h


	}
}


void __declspec(naked) PortForwarding_007DB5E0()
{
	__asm {
		SUB ESP, 40h
		MOV EAX, DWORD PTR SS : [ESP + 44h]
		LEA EDX, DWORD PTR SS : [ESP]
		PUSH EAX
		PUSH offset _007DB7BD; ASCII "TCP"
		PUSH offset _007DB7C5; ASCII "age2_x1:%s.%d"
		PUSH EDX
		//CALL age2_x1.0061442B
		CALL ___005FCE14
		ADD ESP, 10h
		XOR EAX, EAX
		LEA ECX, DWORD PTR SS : [ESP + 20h]
		LEA EDX, DWORD PTR SS : [ESP + 30h]
		MOV DWORD PTR DS : [ECX] , EAX
		PUSH EAX
		PUSH EAX
		PUSH EAX
		PUSH EDX
		PUSH ECX
		MOV EDX, DWORD PTR SS : [ESP + 5Ch]
		LEA ECX, DWORD PTR DS : [EDX * 4h + 7DB7BDh]
		LEA EAX, DWORD PTR SS : [ESP + 20h]
		PUSH ECX
		PUSH EAX
		MOV ECX, DWORD PTR DS : [_7A5144]
		MOV EAX, DWORD PTR DS : [_7A5140]
		PUSH ECX
		PUSH EAX
		CALL DWORD PTR DS : [_7A515C]
		TEST EAX, EAX
		JE short _007DB642
		MOV EAX, 1h
		ADD ESP, 64h
		RETN 8h
		_007DB642:
		LEA ECX, DWORD PTR SS : [ESP + 54h]
		LEA EDX, DWORD PTR SS : [ESP + 30h]
		PUSH ECX
		PUSH EDX
		//CALL age2_x1.0061CD70
		CALL _00605C40
		TEST EAX, EAX
		JE short _007DB660
		MOV EAX, 2h
		ADD ESP, 6Ch
		RETN 8h
		_007DB660:
		LEA ECX, DWORD PTR SS : [ESP + 4Ch]
		MOV EDX, DWORD PTR DS : [_7A5148]
		PUSH ECX
		PUSH EDX
		//CALL age2_x1.0061CD70
		CALL _00605C40
		NEG EAX
		SBB EAX, EAX
		AND EAX, 0FFFFFFFEh
		ADD EAX, 2h
		ADD ESP, 74h
		RETN 8h


	}
}



DWORD _007DB5E0 =(DWORD)PortForwarding_007DB5E0;
DWORD _007DB530 =(DWORD)PortForwarding_007DB530;
void __declspec(naked) PortForwarding_007DB6F0()
{
	__asm {
		PUSH 0h
		PUSH 0BA08h
		CALL _007DB5E0
		CMP EAX, 1h
		JNZ short _007DB71F
		PUSH 0h
		PUSH 0BA08h
		CALL _007DB530
		MOV EDX, DWORD PTR DS : [_7A514C]
		MOV BYTE PTR DS : [EDX + 0CAh] , 1h
		MOV EAX, 1h
		_007DB71F:
		RETN
	}

}

//0042E901 | .E8 DA070000    CALL empires2.0042F0E0
DWORD _0042F0E0 = 0x042F0E0;

DWORD  _0042E906 = 0x042E906;
DWORD  _007DB6F0 = (DWORD)PortForwarding_007DB6F0;
//dynamic jump
//007DB09B   E9 604F82FF      JMP 00000000
DWORD _007DB09B;
//007DB0A0   E8 0B01E0FF      CALL age2_x1_.005DB1B0

void __declspec(naked) PortForwarding_0042E901()
{
	__asm {
		CALL _0042F0E0
		MOV EAX, DWORD PTR DS : [_7A514C]
		TEST EAX, EAX
		JE short _007DB0B3
		CALL _007DB6F0
		_007DB0B3:
		JMP _0042E906
	}
}

void __declspec(naked) PortForwarding_007DB690()
{
	__asm {

		MOV EDX, DWORD PTR SS : [ESP + 8h]
		MOV EAX, DWORD PTR SS : [ESP + 4h]
		PUSH EDX
		PUSH EAX
		CALL _007DB5E0
		CMP EAX, 1h
		JNZ short _007DB6DF
		MOV EDX, DWORD PTR SS : [ESP + 8h]
		MOV EAX, DWORD PTR SS : [ESP + 4h]
		PUSH EDX
		PUSH EAX
		CALL _007DB530
		MOV EDX, DWORD PTR SS : [ESP + 8h]
		NEG EDX
		SBB EDX, EDX
		AND EDX, 0FFFFFF9Bh
		ADD EDX, 65h
		MOV EAX, DWORD PTR SS : [ESP + 4h]
		SUB EAX, 8FCh
		ADD EAX, EDX
		MOV EDX, DWORD PTR DS : [_7A514C]
		MOV ECX, 1h
		MOV BYTE PTR DS : [EAX + EDX] , CL
		MOV EAX, ECX
		_007DB6DF :
		RETN 8h


	}
}
//007DB020   83EC 20          SUB ESP,20
DWORD EAX_007DB09B;
DWORD _007DB690 = (DWORD)PortForwarding_007DB690;
void __declspec(naked) PortForwarding_007DB020()
{
	__asm {
		SUB ESP, 20h
		MOV ECX, DWORD PTR SS : [ESP + 28h]
		MOVZX EAX, WORD PTR DS : [ECX + 2h]
		ROR AX, 8h
		CMP AX, 8FCh
		JB short _007DB093
		CMP AX, 960h
		JA short _007DB093
		MOV DWORD PTR SS : [ESP + 14h] , EAX
		MOV EAX, DWORD PTR SS : [ESP + 24h]
		LEA ECX, DWORD PTR SS : [ESP + 10h]
		LEA EDX, DWORD PTR SS : [ESP]
		MOV DWORD PTR DS : [ECX] , 10h
		PUSH ECX
		PUSH EDX
		PUSH 1008h
		PUSH 0FFFFh
		PUSH EAX
		CALL DWORD PTR DS : [_7A5164]
		TEST EAX, EAX
		JNZ short _007DB093
		MOV EAX, DWORD PTR SS : [ESP]
		DEC EAX
		AND EAX, 1h
		MOV EDX, DWORD PTR SS : [ESP + 14h]
		PUSH EAX
		PUSH EDX
		CALL _007DB690
		TEST EAX, EAX
		JNZ short _007DB093
		PUSH 271Dh
		CALL DWORD PTR DS : [_7A5168]
		MOV EAX, -1h
		ADD ESP, 20h
		RETN 0Ch
		_007DB093 :
		ADD ESP, 20h
		MOV EDI, EDI
		PUSH EBP
		MOV EBP, ESP
		//007DB09B   E9 604F82FF      JMP 00000000
		/*MOV EAX_007DB09B, EAX
		MOV EAX, __007DB09B
		MOV _007DB09B, EAX
		MOV  EAX, EAX_007DB09B
		__007DB09B :*/
		//dynamic jump
		JMP _007DB09B //00000000h


	}
}


//0041BEE2  |. FF15 10C16100  CALL DWORD PTR DS:[<&KERNEL32.LoadLibraryA>]    ; \LoadLibraryA
DWORD* _LoadLibrarAddr =(DWORD*) 0x061C110;//LoadLibraryA
DWORD _LoadLibrar =*_LoadLibrarAddr;//LoadLibraryA
DWORD* _GetProcAddr = (DWORD*)0x61C0D8;
DWORD _GetProc = *_GetProcAddr;
//0041B9FB  |. FF15 B4C16100  CALL DWORD PTR DS:[<&KERNEL32.GetCurrentDirectoryA>]   ; \GetCurrentDirectoryA
DWORD* _GetProcCurrentAddr = (DWORD*)0x61C130;
DWORD _GetProcCurrent = *_GetProcCurrentAddr;


DWORD* _FreeLibraryAddr = (DWORD*)0x061C1A0;
DWORD _FreeLibrary = *_FreeLibraryAddr;

char _007DB805[100] = "ws2_32.dll";
char _007DB7D3[100] = "kernel32.dll";
char _007DB7E0[100] = "FlushInstructionCache";
char _007DB7F6[100] = "VirtualProtect";
char _007DB837[100] = "listen";
char _007DB83E[100] = "bind";
char _007DB810[100] = "getsockname";
char _007DB81C[100] = "getsockopt";
char _007DB827[100] = "WSASetLastError";
DWORD _VirtualProtec;
DWORD _007DB020 =(DWORD)PortForwarding_007DB020;
DWORD __007DB09B =(DWORD)PortForwarding_007DB020 + 0x87;
DWORD ourFunct; 
DWORD toHook = _007DB020;
DWORD toHook2;
void __declspec(naked) PortForwarding_007DB2E0()
{
	__asm {
		PUSH ESI
		PUSH EDI
		PUSH EBX
		PUSH EBP
		SUB ESP, 20h
		PUSH offset _007DB805; ASCII "ws2_32.dll"
		//CALL DWORD PTR DS : [<&KERNEL32.LoadLibraryA>] ; KERNEL32.LoadLibraryA
		CALL DWORD PTR DS : [_LoadLibrar] ; KERNEL32.LoadLibraryA
		MOV ESI, EAX
		TEST ESI, ESI
		JE _007DB44D
		PUSH offset _007DB7D3; ASCII "kernel32.dll"
		//CALL DWORD PTR DS : [<&KERNEL32.LoadLibraryA>] ; KERNEL32.LoadLibraryA
		CALL DWORD PTR DS : [_LoadLibrar] ; KERNEL32.LoadLibraryA
		MOV EDI, EAX
		TEST EDI, EDI
		JE _007DB446
		//MOV EBP, DWORD PTR DS : [<&KERNEL32.GetProcAddress>] ; KERNEL32.GetProcAddress
		MOV EBP, DWORD PTR DS : [_GetProc] ; KERNEL32.GetProcAddress
		PUSH  offset _007DB7E0; ASCII "FlushInstructionCache"
		PUSH EDI
		CALL EBP
		TEST EAX, EAX
		JE _007DB43F
		MOV DWORD PTR SS : [ESP + 4h] , EAX
		PUSH offset _007DB7F6; ASCII "VirtualProtect"
		PUSH EDI
		CALL EBP
		TEST EAX, EAX
		MOV _VirtualProtec, EAX
		JE _007DB43F
		MOV DWORD PTR SS : [ESP + 8h] , EAX
		PUSH offset _007DB837; ASCII "listen"
		PUSH ESI
		CALL EBP
		TEST EAX, EAX
		JE _007DB43F
		MOV DWORD PTR SS : [ESP + 0Ch] , EAX
		PUSH offset _007DB83E; ASCII "bind"
		PUSH ESI
		CALL EBP
		TEST EAX, EAX
		JE _007DB43F
		MOV DWORD PTR SS : [ESP + 10h] , EAX
		PUSH offset _007DB810; ASCII "getsockname"
		PUSH ESI
		CALL EBP
		TEST EAX, EAX
		JE _007DB43F
		MOV DWORD PTR DS : [_7A5160] , EAX
		PUSH offset _007DB81C; ASCII "getsockopt"
		PUSH ESI
		CALL EBP
		TEST EAX, EAX
		JE _007DB43F
		MOV DWORD PTR DS : [_7A5164] , EAX
		PUSH offset _007DB827; ASCII "WSASetLastError"
		PUSH ESI
		CALL EBP
		TEST EAX, EAX
		JE _007DB43F
		MOV DWORD PTR DS : [_7A5168] , EAX

		//CALL DWORD PTR DS : [<&KERNEL32.GetCurrent>; KERNEL32.GetCurrentProcess
		CALL DWORD PTR DS : [_GetProcCurrent] ; KERNEL32.GetCurrentProcess
		MOV DWORD PTR SS : [ESP] , EAX
		LEA EAX, DWORD PTR SS : [ESP + 18h]
		MOV ECX, DWORD PTR SS : [ESP + 10h]
		MOV ourFunct,ECX
		/*PUSH EAX
		PUSH 40h
		PUSH 5h
		PUSH ECX
		CALL DWORD PTR SS : [ESP + 18h]
		LEA EAX, DWORD PTR SS : [ESP + 1Ch]
		PUSH EAX
		PUSH 40h
		PUSH 5h
		PUSH __007DB09B
		CALL DWORD PTR SS : [ESP + 18h]
		MOV EAX, DWORD PTR SS : [ESP + 10h]
		LEA ECX, DWORD PTR DS : [EAX + 5h]
		LEA EDX, DWORD PTR DS : [ECX + 0FF824FE0h]*/
	}
	Hook((void*)ourFunct, (void*)toHook,5);
	__asm {
		/*NEG EDX
		MOV BYTE PTR DS : [EAX] , 0E9h//hook jmp
		MOV DWORD PTR DS : [EAX + 1h] , EDX
		*/
		MOV EAX, __007DB09B
		//LEA EDX, DWORD PTR DS : [EAX + 5h]
		MOV EAX, DWORD PTR SS : [ESP + 10h]
		LEA ECX, DWORD PTR DS : [EAX + 5h]
		MOV toHook2, ECX
	}
	Hook((void*)__007DB09B, (void*)toHook2, 5);
	__asm{


		/*SUB ECX, EDX
		MOV BYTE PTR DS : [EAX] , 0E9h//hook jmp
		MOV DWORD PTR DS : [EAX + 1h] , ECX*/
		MOV ECX, DWORD PTR SS : [ESP + 10h]
		MOV EAX, DWORD PTR SS : [ESP]
		PUSH 5h
		PUSH ECX
		PUSH EAX
		CALL DWORD PTR SS : [ESP + 10h]
		LEA EAX, DWORD PTR SS : [ESP + 18h]
		MOV EDX, DWORD PTR DS : [EAX]
		MOV ECX, DWORD PTR SS : [ESP + 10h]
		PUSH EAX
		PUSH EDX
		PUSH 5h
		PUSH ECX
		CALL DWORD PTR SS : [ESP + 18h]
		MOV EAX, DWORD PTR SS : [ESP]
		PUSH 5h
		PUSH __007DB09B
		PUSH EAX
		CALL DWORD PTR SS : [ESP + 10h]
		LEA EAX, DWORD PTR SS : [ESP + 1Ch]
		MOV EDX, DWORD PTR DS : [EAX]
		/*PUSH EAX
		PUSH EDX
		PUSH 5h
		PUSH __007DB09B
		CALL DWORD PTR SS : [ESP + 18h]*/
		_007DB43F :
		/*PUSH EDI*/
		//CALL DWORD PTR DS : [<&KERNEL32.FreeLibrar>; KERNEL32.FreeLibrary
		/*CALL DWORD PTR DS : [_FreeLibrary] ; KERNEL32.FreeLibrary*/
		_007DB446 :
		/*PUSH ESI*/
		//CALL DWORD PTR DS : [<&KERNEL32.FreeLibrar>; KERNEL32.FreeLibrary
		/*CALL DWORD PTR DS : [_FreeLibrary] ; KERNEL32.FreeLibrary*/
		_007DB44D :
		ADD ESP, 20h
		POP EBP
		POP EBX
		POP EDI
		POP ESI
		RETN

	}
}

//007DB0C0   55               PUSH EBP
char _007DB720[100] = "miniupnpc.dll";
char _007DB736[100] = "upnpDiscover";
char _007DB743[100] = "UPNP_GetValidIGD";
char _007DB754[100] = "UPNP_AddPortMapping";
char _007DB768[100] = "UPNP_DeletePortMapping";
char _007DB77F[100] = "UPNP_GetSpecificPortMappingEntry";
char _007DB7A0[100] = "FreeUPNPUrls";
char _007DB7AD[100] = "freeUPNPDevlist";
//0042369D  |. E8 3E511E00    CALL <JMP.&WSOCK32.#115>                 ; \WSAStartup
DWORD _WSOCK32_WSAStartup = 0x06087E0;
//004237C2  |. E8 1F501E00    CALL <JMP.&WSOCK32.#116>                 ; [WSACleanup
DWORD _WSOCK32_WSACleanup = 0x06087E6;

DWORD _006137C9 = 0x05F8FF0;//DWORD uu_006137C9 = 0x05F8FF0; heap alloc 
DWORD _007DB2E0 = (DWORD)PortForwarding_007DB2E0;
void __declspec(naked) PortForwarding_007DB0C0()
{
	__asm {
		PUSH EBP
		MOV EBP, ESP
		SUB ESP, 0F00h
		PUSH EBX
		PUSH ESI
		PUSH EDI
		LEA EAX, DWORD PTR SS : [ESP + 38h]
		PUSH EAX
		PUSH 101h
		MOV DWORD PTR SS : [ESP + 28h] , 0h
		//CALL DWORD PTR DS : [<&WSOCK32.#115>] ; WS2_32.WSAStartup
		CALL DWORD PTR DS : [_WSOCK32_WSAStartup] ; WS2_32.WSAStartup
		TEST EAX, EAX
		JNZ _007DB2C9
		PUSH offset _007DB720; ASCII "age2_x1\miniupnpc.dll"
		CALL DWORD PTR DS : [_LoadLibrar]; KERNEL32.LoadLibraryA
		MOV EDI, EAX
		TEST EDI, EDI
		JE _007DB2C3
		MOV DWORD PTR DS : [_7A5150] , EDI
		MOV ESI, DWORD PTR DS : [_GetProc]; KERNEL32.GetProcAddress
		PUSH offset _007DB736; ASCII "upnpDiscover"
		PUSH EDI
		CALL ESI
		PUSH offset _007DB743; ASCII "UPNP_GetValidIGD"
		PUSH EDI
		MOV EBX, EAX
		CALL ESI
		PUSH  offset _007DB754; ASCII "UPNP_AddPortMapping"
		PUSH EDI
		MOV DWORD PTR SS : [ESP + 1Ch] , EAX
		CALL ESI
		PUSH offset _007DB768; ASCII "UPNP_DeletePortMapping"
		PUSH EDI
		MOV DWORD PTR SS : [ESP + 20h] , EAX
		CALL ESI
		PUSH offset _007DB77F; ASCII "UPNP_GetSpecificPortMappingEntry"
		PUSH EDI
		MOV DWORD PTR SS : [ESP + 24h] , EAX
		CALL ESI
		PUSH offset _007DB7A0; ASCII "FreeUPNPUrls"
		PUSH EDI
		MOV DWORD PTR SS : [ESP + 28h] , EAX
		CALL ESI
		PUSH offset _007DB7AD; ASCII "freeUPNPDevlist"
		PUSH EDI
		MOV DWORD PTR SS : [ESP + 18h] , EAX
		CALL ESI
		MOV ESI, EAX
		TEST EBX, EBX
		JE _007DB2C3
		CMP DWORD PTR SS : [ESP + 14h] , 0h
		JE _007DB2C3
		CMP DWORD PTR SS : [ESP + 18h] , 0h
		JE _007DB2C3
		CMP DWORD PTR SS : [ESP + 1Ch] , 0h
		JE _007DB2C3
		CMP DWORD PTR SS : [ESP + 20h] , 0h
		JE _007DB2C3
		CMP DWORD PTR SS : [ESP + 10h] , 0h
		JE _007DB2C3
		TEST ESI, ESI
		JE _007DB2C3
		MOV EAX, DWORD PTR SS : [ESP + 18h]
		MOV ECX, DWORD PTR SS : [ESP + 1Ch]
		MOV EDX, DWORD PTR SS : [ESP + 20h]
		MOV DWORD PTR DS : [_7A5154] , EAX
		MOV DWORD PTR DS : [_7A5158] , ECX
		MOV DWORD PTR DS : [_7A515C] , EDX
		XOR EAX, EAX
		LEA ECX, DWORD PTR SS : [ESP + 20h]
		MOV DWORD PTR DS : [ECX] , EAX
		PUSH ECX
		PUSH EAX
		PUSH EAX
		PUSH EAX
		PUSH EAX
		PUSH 3E8h
		CALL EBX
		MOV EBX, EAX
		ADD ESP, 18h
		TEST EBX, EBX
		JE _007DB2C3
		PUSH 40h
		LEA EDX, DWORD PTR SS : [ESP + 0D54h]
		PUSH EDX
		LEA EAX, DWORD PTR SS : [ESP + 1D0h]
		PUSH EAX
		LEA ECX, DWORD PTR SS : [ESP + 30h]
		PUSH ECX
		PUSH EBX
		CALL DWORD PTR SS : [ESP + 28h]
		ADD ESP, 14h
		MOV DWORD PTR SS : [ESP + 20h] , EAX
		TEST EAX, EAX
		JE _007DB2BD
		CMP EAX, 1h
		JNZ _007DB2B1
		PUSH 100h
		PUSH 1h
		CALL _006137C9
		ADD ESP, 8h
		TEST EAX, EAX
		JE _007DB2B1
		MOV DWORD PTR DS : [_7A5140] , EAX
		MOV ECX, DWORD PTR SS : [ESP + 24h]
		PUSH ECX
		PUSH EAX
		//CALL age2_x1.0061442B
		CALL ___005FCE14
		ADD ESP, 8h
		PUSH 100h
		PUSH 1h
		CALL _006137C9
		ADD ESP, 8h
		TEST EAX, EAX
		JE short _007DB2B1
		MOV DWORD PTR DS : [_7A5144] , EAX
		LEA ECX, DWORD PTR SS : [ESP + 6CCh]
		PUSH ECX
		PUSH EAX
		//CALL age2_x1.0061442B
		CALL ___005FCE14
		ADD ESP, 8h
		PUSH 40h
		PUSH 1h
		CALL _006137C9
		ADD ESP, 8h
		TEST EAX, EAX
		JE short _007DB2B1
		MOV DWORD PTR DS : [_7A5148] , EAX
		LEA ECX, DWORD PTR SS : [ESP + 0D50h]
		PUSH ECX
		PUSH EAX
		//CALL age2_x1.0061442B
		CALL ___005FCE14
		ADD ESP, 8h
		PUSH 0CBh
		PUSH 1h
		CALL _006137C9
		ADD ESP, 8h
		TEST EAX, EAX
		JE short _007DB2B1
		MOV DWORD PTR DS : [_7A514C] , EAX
		CALL _007DB2E0
		_007DB2B1:
		LEA ECX, DWORD PTR SS : [ESP + 24h]
		PUSH ECX
		CALL DWORD PTR SS : [ESP + 14h]
		ADD ESP, 4h
		_007DB2BD:
		PUSH EBX
		CALL ESI
		ADD ESP, 4h
		_007DB2C3:
		CALL DWORD PTR DS : [_WSOCK32_WSACleanup] ; WS2_32.WSACleanup
		_007DB2C9:
		XOR EAX, EAX
		POP EDI
		POP ESI
		POP EBX
		MOV ESP, EBP
		POP EBP
		RETN


	}
}
void __declspec(naked) PortForwarding_007DB590()
{
	__asm {

		SUB ESP, 40h
		MOV EAX, DWORD PTR SS : [ESP + 44h]
		LEA EDX, DWORD PTR SS : [ESP]
		PUSH EAX
		PUSH offset _007DB7BD; ASCII "TCP"
		PUSH offset _007DB7C5; ASCII "age2_x1:%s.%d"
		PUSH EDX
		//CALL age2_x1_.0061442B
		CALL ___005FCE14
		ADD ESP, 10
		MOV EDX, DWORD PTR SS : [ESP + 48h]
		LEA ECX, DWORD PTR DS : [EDX * 4h + 7DB7BDh]
		LEA EAX, DWORD PTR SS : [ESP + 0Ch]
		PUSH 0h
		PUSH ECX
		PUSH EAX
		MOV ECX, DWORD PTR DS : [_7A5144]
		MOV EAX, DWORD PTR DS : [_7A5140]
		PUSH ECX
		PUSH EAX
		CALL DWORD PTR DS : [_7A5158]
		ADD ESP, 54h
		RETN 8h
	}
}
DWORD _007DB590 = (DWORD)PortForwarding_007DB590;
DWORD _006139B4 = 0x058FA7E;
void __declspec(naked) PortForwarding_007DB460()
{
	__asm {
		PUSH ESI
		PUSH EDI
		SUB ESP, 200h
		MOV EDI, 0CAh
		MOV ESI, DWORD PTR DS : [_7A514C]
		TEST ESI, ESI
		JE short _007DB4D7
		LEA EAX, DWORD PTR SS : [ESP]
		PUSH EAX
		PUSH 101h
		//CALL DWORD PTR DS : [<&WSOCK32.#115>] ; WS2_32.WSAStartup
		CALL DWORD PTR DS : [_WSOCK32_WSAStartup] ; WS2_32.WSAStartup
		TEST EAX, EAX
		JNZ short _007DB4D7
		MOV AL, BYTE PTR DS : [ESI + EDI]
		DEC EDI
		TEST AL, AL
		JE short _007DB49E
		PUSH 0h
		PUSH 0BA08h
		CALL _007DB590
		_007DB49E:
		MOV AL, BYTE PTR DS : [ESI + EDI]
		TEST AL, AL
		JE short _007DB4B3
		LEA EAX, DWORD PTR DS : [EDI + 897h]
		PUSH 0
		PUSH EAX
		CALL _007DB590
		_007DB4B3:
		DEC EDI
		CMP EDI, 65h
		JGE short _007DB49E
		_007DB4B9:
		MOV AL, BYTE PTR DS : [ESI + EDI]
		TEST AL, AL
		JE short _007DB4CE
		LEA EAX, DWORD PTR DS : [EDI + 8FCh]
		PUSH 1h
		PUSH EAX
		CALL _007DB590
		_007DB4CE:
		DEC EDI
		JGE short _007DB4B9
		//CALL DWORD PTR DS : [<&WSOCK32.#116>] ; WS2_32.WSACleanup
		CALL DWORD PTR DS : [_WSOCK32_WSACleanup] ; WS2_32.WSACleanup
		_007DB4D7:
		ADD ESP, 200h
		MOV EAX, DWORD PTR DS : [_7A514C]
		PUSH EAX
		CALL _006139B4
		ADD ESP, 4h
		MOV EAX, DWORD PTR DS : [_7A5148]
		PUSH EAX
		CALL _006139B4
		ADD ESP, 4h
		MOV EAX, DWORD PTR DS : [_7A5144]
		PUSH EAX
		CALL _006139B4
		ADD ESP, 4h
		MOV EAX, DWORD PTR DS : [_7A5140]
		PUSH EAX
		CALL _006139B4
		ADD ESP, 4h
		MOV EAX, DWORD PTR DS : [_7A5150]
		TEST EAX, EAX
		JE short _007DB525
		PUSH EAX
		CALL DWORD PTR DS : [_FreeLibrary] ; KERNEL32.FreeLibrary
		//CALL DWORD PTR DS : [<&KERNEL32.FreeLibrary>] ; KERNEL32.FreeLibrary
		_007DB525:
		POP EDI
		POP ESI
		RETN


	}
}



DWORD* _WaitForSingleObjectAddr = (DWORD*)0x061C1DC;
DWORD _WaitForSingleObject = *_WaitForSingleObjectAddr;
//DWORD _PostMessageA = 0x061C32C;
void __declspec(naked) PortForwarding_007E66E0()
{
	__asm {

		MOV EAX, DWORD PTR DS : [_7A5870]
		PUSH - 1h
		PUSH EAX
		MOV DWORD PTR DS : [_7A5874] , 0
		//CALL DWORD PTR DS : [<&KERNEL32.WaitForSingleObject>] ; KERNEL32.WaitForSingleObject
		CALL DWORD PTR DS : [_WaitForSingleObject] ; KERNEL32.WaitForSingleObject
		RETN
		

	}
}

DWORD _7A5880[100];
DWORD _007E66E0 = (DWORD)PortForwarding_007E66E0;
DWORD ECX_007E63E0;
void __declspec(naked) PortForwarding_007E63E0()
{
	__asm {
		PUSH EDI
		CALL _007E66E0
		MOV EDI, 1Fh
		_007E63EB:
		MOV ECX_007E63E0,ECX
		MOV ECX, _7A5880
		//MOV EAX, DWORD PTR DS : [EDI * 4 + 7A5880]
		MOV EAX, DWORD PTR DS : [EDI * 4h + ECX]
		MOV ECX, ECX_007E63E0

		PUSH EAX
		CALL _006139B4

		MOV ECX_007E63E0, ECX
		MOV ECX, _7A5880
		//MOV DWORD PTR DS : [EDI * 4 + 7A5880] , 0h
		MOV DWORD PTR DS : [EDI * 4 + ECX] , 0h
		MOV ECX, ECX_007E63E0

		ADD ESP, 4h
		DEC EDI
		JGE short _007E63EB
		MOV EAX, DWORD PTR DS : [_7A5810]
		TEST EAX, EAX
		JE short _007E6419
		PUSH EAX
		//CALL DWORD PTR DS : [<&KERNEL32.FreeLibrary>] ; KERNEL32.FreeLibrary
		CALL DWORD PTR DS : [_FreeLibrary] ; KERNEL32.FreeLibrary
		_007E6419:
		//MOV EAX, DWORD PTR DS : [7A5800]
		//todo check if is correct
		MOV EAX, DWORD PTR DS : [_7A5800]
		TEST EAX, EAX
		JE short _007E6429
		PUSH EAX
		//CALL DWORD PTR DS : [<&KERNEL32.FreeLibrary>] ; KERNEL32.FreeLibrary
		CALL DWORD PTR DS : [_FreeLibrary] ; KERNEL32.FreeLibrary
		_007E6429:
		XOR EAX, EAX
		//MOV EDI, age2_x1_.007A5800
		MOV EDI, _7A5880
		MOV ECX, 20h
		REP STOS DWORD PTR ES : [EDI]
		POP EDI
		RETN

	}
}
//initialize socket thread ?

DWORD _007E63E0 =(DWORD)PortForwarding_007E63E0;
char _007E6DBD[100] = "kernel32.dll";
char _007E6DCA[100] = "CreateThread";
char _007E6DD7[100] = "Sleep";
char _007E6DDD[100] = "InterlockedIncrement";
char _007E6DF2[100] = "InterlockedDecrement";
char _007E6E07[100] = "ws2_32.dll";
char _007E6E12[100] = "WSAStartup";
char _007E6E1D[100] = "WSACleanup";
char _007E6E28[100] = "__WSAFDIsSet";
char _007E6E35[100] = "getaddrinfo";
char _007E6E41[100] = "freeaddrinfo";
char _007E6E4E[100] = "socket";
char _007E6E55[100] = "bind";
char _007E6E5A[100] = "setsockopt";
char _007E6E65[100] = "listen";
char _007E6E6C[100] = "shutdown";
char _007E6E75[100] = "closesocket";
char _007E6E81[100] = "select";
char _007E6E88[100] = "WSAAccept";
char _007E6E92[100] = "send";
char _007E6E97[100] = "recv";
char _007E6E9C[100] = "WSAIoctl";

DWORD ECX_007E61C0;
void __declspec(naked) PortForwarding_007E61C0()
{
	__asm {
		PUSH ESI
		PUSH EDI
		CALL _007E63E0
		PUSH offset _007E6DBD; ASCII "kernel32.dll"
		//MOV EDI, DWORD PTR DS : [<&KERNEL32.GetProcAddress>] ; KERNEL32.GetProcAddress
		MOV EDI, DWORD PTR DS : [_GetProc] ; KERNEL32.GetProcAddress
		//CALL DWORD PTR DS : [<&KERNEL32.LoadLibraryA>] ; KERNEL32.LoadLibraryA
		CALL DWORD PTR DS : [_LoadLibrar] ; KERNEL32.LoadLibraryA
		MOV ESI, EAX
		TEST EAX, EAX
		JE _007E63D4
		MOV DWORD PTR DS : [_7A5800] , EAX
		PUSH offset _007E6DCA; ASCII "CreateThread"
		PUSH ESI
		CALL EDI
		TEST EAX, EAX
		JE _007E63D4
		MOV DWORD PTR DS : [_7A5854] , EAX
		PUSH offset _007E6DD7; ASCII "Sleep"
		PUSH ESI
		CALL EDI
		TEST EAX, EAX
		JE _007E63D4
		MOV DWORD PTR DS : [_7A5858] , EAX
		PUSH offset _007E6DDD; ASCII "InterlockedIncrement"
		PUSH ESI
		CALL EDI
		TEST EAX, EAX
		JE _007E63D4
		MOV DWORD PTR DS : [_7A585C] , EAX
		PUSH offset _007E6DF2; ASCII "InterlockedDecrement"
		PUSH ESI
		CALL EDI
		TEST EAX, EAX
		JE _007E63D4
		MOV DWORD PTR DS : [_7A5860] , EAX
		PUSH offset _007E6E07; ASCII "ws2_32.dll"
		//MOV EDI, DWORD PTR DS : [<&KERNEL32.GetProcAddress>] ; KERNEL32.GetProcAddress
		MOV EDI, DWORD PTR DS : [_GetProc] ; KERNEL32.GetProcAddress
		//CALL DWORD PTR DS : [<&KERNEL32.LoadLibraryA>] ; KERNEL32.LoadLibraryA
		CALL DWORD PTR DS : [_LoadLibrar] ; KERNEL32.LoadLibraryA
		MOV ESI, EAX
		TEST EAX, EAX
		JE _007E63D4
		MOV DWORD PTR DS : [_7A5810] , EAX
		PUSH offset _007E6E12; ASCII "WSAStartup"
		PUSH ESI
		CALL EDI
		TEST EAX, EAX
		JE _007E63D4
		MOV DWORD PTR DS : [_7A5814] , EAX
		push offset _007E6E1D; ASCII "WSACleanup"
		PUSH ESI
		CALL EDI
		TEST EAX, EAX
		JE _007E63D4
		MOV DWORD PTR DS : [_7A5818] , EAX
		push offset _007E6E28; ASCII "__WSAFDIsSet"
		PUSH ESI
		CALL EDI
		TEST EAX, EAX
		JE _007E63D4
		MOV DWORD PTR DS : [_7A581C] , EAX
		push offset _007E6E35; ASCII "getaddrinfo"
		PUSH ESI
		CALL EDI
		TEST EAX, EAX
		JE _007E63D4
		MOV DWORD PTR DS : [_7A5820] , EAX
		push offset _007E6E41; ASCII "freeaddrinfo"
		PUSH ESI
		CALL EDI
		TEST EAX, EAX
		JE _007E63D4
		MOV DWORD PTR DS : [_7A5824] , EAX
		push offset _007E6E4E; ASCII "socket"
		PUSH ESI
		CALL EDI
		TEST EAX, EAX
		JE _007E63D4
		MOV DWORD PTR DS : [_7A5828] , EAX
		push offset _007E6E55; ASCII "bind"
		PUSH ESI
		CALL EDI
		TEST EAX, EAX
		JE _007E63D4
		MOV DWORD PTR DS : [_7A582C] , EAX
		push offset _007E6E5A; ASCII "setsockopt"
		PUSH ESI
		CALL EDI
		TEST EAX, EAX
		JE _007E63D4
		MOV DWORD PTR DS : [_7A5830] , EAX
		push offset _007E6E65; ASCII "listen"
		PUSH ESI
		CALL EDI
		TEST EAX, EAX
		JE _007E63D4
		MOV DWORD PTR DS : [_7A5834] , EAX
		push offset _007E6E6C; ASCII "shutdown"
		PUSH ESI
		CALL EDI
		TEST EAX, EAX
		JE _007E63D4
		MOV DWORD PTR DS : [_7A5838] , EAX
		push offset _007E6E75; ASCII "closesocket"
		PUSH ESI
		CALL EDI
		TEST EAX, EAX
		JE _007E63D4
		MOV DWORD PTR DS : [_7A583C] , EAX
		push offset _007E6E81; ASCII "select"
		PUSH ESI
		CALL EDI
		TEST EAX, EAX
		JE short _007E63D4
		MOV DWORD PTR DS : [_7A5840] , EAX
		push offset _007E6E88; ASCII "WSAAccept"
		PUSH ESI
		CALL EDI
		TEST EAX, EAX
		JE short _007E63D4
		MOV DWORD PTR DS : [_7A5844] , EAX
		push offset _007E6E92; ASCII "send"
		PUSH ESI
		CALL EDI
		TEST EAX, EAX
		JE short _007E63D4
		MOV DWORD PTR DS : [_7A5848] , EAX
		push offset _007E6E97; ASCII "recv"
		PUSH ESI
		CALL EDI
		TEST EAX, EAX
		JE short _007E63D4
		MOV DWORD PTR DS : [_7A584C] , EAX
		push offset _007E6E9C; ASCII "WSAIoctl"
		PUSH ESI
		CALL EDI
		TEST EAX, EAX
		JE short _007E63D4
		MOV DWORD PTR DS : [_7A5850] , EAX
		XOR EDI, EDI
		_007E63AF:
		PUSH 20h
		PUSH 1h
		CALL _006137C9

		MOV	ECX_007E61C0,ECX
		MOV ECX, _7A5880
		//MOV DWORD PTR DS : [EDI * 4 + 7A5880] , EAX
		MOV DWORD PTR DS : [EDI * 4 + ECX] , EAX
		MOV	ECX_007E61C0, ECX

		ADD ESP, 8h
		INC EDI
		TEST EAX, EAX
		JE short _007E63CE
		CMP EDI, 20h
		JL short _007E63AF
		JMP short _007E63D4
		_007E63CE:
		MOV DWORD PTR DS : [_7A5850] , EAX
		_007E63D4:
		POP EDI
		POP ESI
		RETN


	}
}




//007DB020   83EC 20          SUB ESP,20    where it is called?


//00586BB7   >-E9 44BC2300    JMP age2_x1_.007C2800
//0x7c2870
//007C2875   E8 46390200      CALL age2_x1_.007E61C0
//0x7c288a

//loaded
//007C2870   E8 4B880100      CALL age2_x1_.007DB0C0
//007C2875   E8 46390200      CALL age2_x1_.007E61C0

//when game exist free library
//005873B7   . 6A 10          PUSH 10; / Style = MB_OK | MB_ICONHAND | MB_APPLMODAL
//005873B9   . 8D8C24 A01A000 > LEA ECX, DWORD PTR SS : [ESP + 1AA0] ; |
//005873C0   . 50             PUSH EAX; | Title
//005873C1   . 51             PUSH ECX; | Text
//005873C2   . 53             PUSH EBX; | hOwner
//005873C3.FF15 34536300  CALL DWORD PTR DS : [<&USER32.MessageBoxA>] ; \MessageBoxA
//005873C9 > -E9 B2B42300    JMP age2_x1_.007C2880


//007C2880   E8 ABC0DCFF      CALL age2_x1_.0058E930
//007C2885   E8 563B0200      CALL age2_x1_.007E63E0
//007C288A   E8 D18B0100      CALL age2_x1_.007DB460
//007C288F   E8 4C380000      CALL age2_x1_.007C60E0



//0047AEBC  |. BF 4C306500    MOV EDI,empires2.0065304C                       ;  ASCII "00.14.14.0914"
DWORD _005FE370 = 0x05FE370;


DWORD _0047AEBC_EAX;
DWORD _0047AEBC_ECX;
DWORD _0047AEBC_EDX;
DWORD _0047AEBC_EBX;
DWORD _0047AEBC_ESP;
DWORD _0047AEBC_EBP;
DWORD _0047AEBC_ESI;
DWORD _0047AEBC_EDI;
//0047AE20  /$ B8 881B0000    MOV EAX,1B88
DWORD _0047AE2A = 0x047AE2A;
void __declspec(naked) PortForwarding_0047AEBC()
{
	__asm {
		//save register
		MOV _0047AEBC_EAX, EAX
		MOV _0047AEBC_ECX, ECX
		MOV _0047AEBC_EDX, EDX
		MOV _0047AEBC_EBX, EBX
		MOV _0047AEBC_ESP, ESP
		MOV _0047AEBC_EBP, EBP
		MOV _0047AEBC_ESI, ESI
		MOV _0047AEBC_EDI, EDI

		call PortForwarding_007DB0C0
		//call PortForwarding_007E61C0
		//restaure register
		MOV  EAX, _0047AEBC_EAX
		MOV  ECX, _0047AEBC_ECX
		MOV  EDX, _0047AEBC_EDX
		MOV  EBX, _0047AEBC_EBX
		MOV  ESP, _0047AEBC_ESP
		MOV  EBP, _0047AEBC_EBP
		MOV  ESI, _0047AEBC_ESI
		MOV  EDI, _0047AEBC_EDI

		MOV EAX, 1B88h
		CALL _005FE370
		JMP _0047AE2A

	}
}


//0060034A  
void setPortForwardingHook()
{
	setHook((void*)0x042E901, PortForwarding_0042E901);
	//00586BB7   >-E9 44BC2300    JMP age2_x1_.007C2800
	//0047AEBC  |. BF 4C306500    MOV EDI,empires2.0065304C                       ;  ASCII "00.14.14.0914"
	setHook((void*)0x047AE20, PortForwarding_0047AEBC);



}