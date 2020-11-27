#include <windows.h>



//007AF400   0FBF56 48        MOVSX EDX,WORD PTR DS:[ESI+48]

//005CD441  |. 8D78 97        LEA EDI,DWORD PTR DS:[EAX-69]
// [6645C4]  = [7912A0]
//005CD639  |> 5F             POP EDI                                  ;  Default case of switch 005CD1DE

DWORD _005CD639 = 0x05CD639;
void __declspec(naked)  FixTorpedoCheatCrashBugHoock()
{
	__asm {
/*
		MOVSX EBX, WORD PTR SS : [ESP + 14]

		MOVSX EDX, WORD PTR DS : [ESI + 48h]
		ADD EDI, -69h
		CMP EDI, EDX
		JGE _005CD639 //age2_x1.0042C3E3
		TEST EDI, EDI
		JLE _005CD639 //age2_x1.0042C3E3
		MOV EAX, DWORD PTR DS : [ESI + 4Ch]
		MOV ECX, DWORD PTR DS : [EAX + EDI * 4h]
		TEST ECX, ECX
		JE _005CD639 //age2_x1.0042C3E3
		CMP EDI, EBX
		JMP age2_x1.0042C09A*/
		
		//MOV ECX, DWORD PTR DS : [6645C4h]
		//CALL age2_x1.005E7560
		//MOV EDX, DWORD PTR DS : [EAX + 9Ch]
		//XOR EDX, 1
		//MOV ECX, DWORD PTR DS : [7912A0]
		//MOV EAX, DWORD PTR DS : [ECX]
		//PUSH EDX
		//CALL DWORD PTR DS : [EAX + 14h]
		//JMP age2_x1.0042C29C
	}
}

void FixTorpedoCheatCrashBug()
{

}