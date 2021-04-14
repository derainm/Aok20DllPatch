#include <Windows.h>
#include "Hookbase.h"

//DWORD _004DCA13 = 0x04DCA13;

//get player position
//00422A87 | . 8B9C24 0C0C0000     MOV EBX, DWORD PTR SS : [ESP + C0C]
//	00422A80
DWORD player_position;
DWORD _00422A86 = 0x0422A86;


void __declspec(naked)  getplayerPositionn()
{

	__asm {
		MOV EAX, DWORD PTR SS : [ESP + 0Ch]
		CMP EAX,-1
		JNZ normale
		MOV player_position, 1h
		SUB ESP, 0C00h
		JMP _00422A86

		normale:
		MOV player_position, EAX
		SUB ESP, 0C00h
		JMP _00422A86 
	}
}
 
 
//004DCA3B  |. 68 FF000000         |PUSH 0FF                                          ; |Arg3 = 000000FF

//004DCA3B  |. 68 FF000000         |PUSH 0FF                                          ; |Arg3 = 000000FF
//cpt--?
//004DCA37  |. 8D4C24 34           |LEA ECX,DWORD PTR SS:[ESP+34]                     ; |

DWORD h_EAX;
DWORD h_ECX;
DWORD h_EDX;
DWORD h_EBX;
DWORD h_ESP;
DWORD h_EBP;
DWORD h_ESI;
DWORD h_EDI;

DWORD _004DCA40 = 0x04DCA40;

DWORD colors[8];
DWORD cpt = 0;

DWORD pos;

void updateColor()
{

}
void __declspec(naked)  chatColor004DCA37()
{
	__asm {
		LEA ECX, DWORD PTR SS : [ESP + 34h]

		//save register
		MOV h_EAX, EAX
		MOV h_ECX, ECX
		MOV h_EDX, EDX
		MOV h_EBX, EBX
		//MOV h_ESP, ESP
		MOV h_EBP, EBP
		MOV h_ESI, ESI
		MOV h_EDI, EDI

		MOV EDX,0h
		MOV EDX, DWORD PTR DS : [ESI]
		CMP EDX,8h
		JG norm
		MOV pos,EDX

		MOV EDX, DWORD PTR DS : [6645C4h]
		MOV ECX, DWORD PTR DS : [EDX + 41Ch]
		MOV EDX, DWORD PTR DS : [ECX + 4Ch]
		MOV EAX, pos
		MOV ECX, DWORD PTR DS : [EDX + 4 * EAX]

		ADD ECX, 158h
		MOV ECX, DWORD PTR DS : [ECX]
		ADD ECX, 10h
		MOV EAX, 0h
		MOV al, BYTE PTR DS : [ECX]

		CMP EAX, 0F2h
		JNZ  standartColor
		MOV EAX, 15h
		standartColor :

		PUSH EAX//color

		//restaure register
		MOV  EAX, h_EAX
		MOV  ECX, h_ECX
		MOV  EDX, h_EDX
		MOV  EBX, h_EBX
		//MOV  ESP, h_ESP
		MOV  EBP, h_EBP
		MOV  ESI, h_ESI
		MOV  EDI, h_EDI

		JMP _004DCA40

		norm: 
		push 0FFh
		//restaure register
		MOV  EAX, h_EAX
		MOV  ECX, h_ECX
		MOV  EDX, h_EDX
		MOV  EBX, h_EBX
		//MOV  ESP, h_ESP
		MOV  EBP, h_EBP
		MOV  ESI, h_ESI
		MOV  EDI, h_EDI

		JMP _004DCA40
	}
}
//  --Villager Created--
//set white
//005B5FF5  |> 8B0D 24456600  MOV ECX,DWORD PTR DS:[664524]                        ; |
DWORD _005B5FFB = 0x05B5FFB;
DWORD flagCreated = 0x0;
void __declspec(naked)  chatColor005B5FF5()
{
	__asm {
		MOV ECX, DWORD PTR DS : [664524h]
		MOV flagCreated, 1h
		JMP _005B5FFB
	}
}
//0x053D5AB
DWORD _00422A80 = 0x0422A80;
DWORD _0053D5B0 = 0x053D5B0;
void __declspec(naked)  chatColor053D5AB()
{
	__asm {
		CALL _00422A80; \empires2.00422A80
		MOV flagCreated, 1h
		JMP _0053D5B0 
	}
}


//players structs MOV ECX,DWORD PTR DS:[6645C4]
//0041F840  /$ 8B81 1C040000           MOV EAX,DWORD PTR DS:[ECX+41C]
//004DC860 / $ 81EC 08010000             SUB ESP, 108
//fuction called when user or game user console


DWORD c_EAX;
DWORD c_ECX;
DWORD c_EDX;
DWORD c_EBX;
DWORD c_ESP;
DWORD c_EBP;
DWORD c_ESI;
DWORD c_EDI;

DWORD _0041F840 = 0x041F840;
DWORD* nameAdr;
char* name;
DWORD _004DCACA = 0x04DCACA ;


//004DCAC1 | . 8D4C24 34      LEA ECX, DWORD PTR SS : [ESP + 34] ; |
//004DCAC5     68 F1000000    PUSH 0F1

DWORD basePlayersAdress;
BYTE color;


void __declspec(naked)  chatColor004DCAC1()
{
	__asm {


		//save register
		MOV c_EAX, EAX
		MOV c_ECX, ECX
		MOV c_EDX, EDX
		MOV c_EBX, EBX
		MOV c_ESP, ESP
		MOV c_EBP, EBP
		MOV c_ESI, ESI
		MOV c_EDI, EDI
 
		
		CMP flagCreated, 1h
		JE white

		MOV EDX, DWORD PTR DS : [6645C4h]
		MOV ECX, DWORD PTR DS : [EDX + 41Ch]
		MOV EDX, DWORD PTR DS : [ECX + 4Ch]
		MOV EAX, player_position
		MOV ECX, DWORD PTR DS : [EDX + 4 * EAX]

		ADD ECX, 158h
		MOV ECX, DWORD PTR DS : [ECX]
		ADD ECX, 10h
		MOV EAX, 0h
		MOV al, BYTE PTR DS : [ECX]
		MOV color, al
		//restaure register
		MOV  EAX, c_EAX
		MOV  ECX, c_ECX
		MOV  EDX, c_EDX
		MOV  EBX, c_EBX
		MOV  ESP, c_ESP
		MOV  EBP, c_EBP
		MOV  ESI, c_ESI
		MOV  EDI, c_EDI
		REP MOVS BYTE PTR ES : [EDI] , BYTE PTR DS : [ESI]
		MOV EAX, 0h
		MOV  EAX, player_position
		MOV BYTE PTR DS : [ESI] , AL
		MOV  EAX, c_EAX
		PUSH 0h
		PUSH 0h


		LEA ECX, DWORD PTR SS : [ESP + 34h]
		CMP color, 0F2h
		JNZ  standartColor
		MOV color,15h
		standartColor:
		push color
		JMP _004DCACA
		white:
 
		//restaure register
		MOV  EAX, c_EAX
		MOV  ECX, c_ECX
		MOV  EDX, c_EDX
		MOV  EBX, c_EBX
		MOV  ESP, c_ESP
		MOV  EBP, c_EBP
		MOV  ESI, c_ESI
		MOV  EDI, c_EDI
		REP MOVS BYTE PTR ES : [EDI] , BYTE PTR DS : [ESI]
		PUSH 0h
		PUSH 0h


		LEA ECX, DWORD PTR SS : [ESP + 34h]
		push 0FFh
		MOV flagCreated,0h
		JMP _004DCACA


	}
}

//0044DFD7     90             NOP                                                  ; |Arg10
//0044DD72  |. 0F84 38050000  |JE empires2.0044E2B0

//0044DE42  |> 8B4424 10      |MOV EAX,DWORD PTR SS:[ESP+10]
//0040B55E > -E9 104C3A00    JMP age2_x1_.007B0173



//005E4D08  |> 8B0D C4456600  |MOV ECX,DWORD PTR DS:[6645C4]
DWORD _004217B0 = 0x04217B0;
DWORD _0042E360 = 0x042E360;
DWORD _00422220 = 0x0422220;
DWORD _005E4D3E = 0x05E4D3E;
DWORD _005E4D4F = 0x05E4D4F;
void __declspec(naked)  PannelColor005E4D08()
{
	__asm {
		//MOV ECX, DWORD PTR DS : [7912A0]
		MOV ECX, DWORD PTR DS : [6645C4h]
		MOV BYTE PTR SS : [ESP + EAX + 34h] , 0h
		//CALL age2_x1_.005EAE80
		CALL _004217B0
		TEST EAX, EAX
		JNZ short _007B0190
		MOV EAX, DWORD PTR SS : [ESP + 10h]
		CMP EAX, 4h
		JL short _007B01A1
		_007B0190:
		LEA EDX, DWORD PTR SS : [ESP + 34h]
		//MOV ECX, DWORD PTR DS : [791200]
		MOV ECX, DWORD PTR DS : [664520]
		PUSH EDX
		PUSH EBX
		//CALL age2_x1_.005DA430
		CALL _0042E360
		_007B01A1:
		MOV ECX, DWORD PTR SS : [ESP + 30h]
		PUSH ECX
		//MOV ECX, DWORD PTR DS : [7912A0]
		MOV ECX, DWORD PTR DS : [6645C4h]
		PUSH EBX
		//CALL age2_x1_.005EB8F0
		CALL _00422220
		//MOV ECX, DWORD PTR DS : [7912A0]
		MOV ECX, DWORD PTR DS : [6645C4h]
		//CALL age2_x1_.005EAE80
		CALL _004217B0
		TEST EAX, EAX
		JNZ _0040B594
		JMP _005E4D4F

		_0040B594:
		JMP _005E4D3E 
	}
}
//005B4911   .-E9 E2B71F00    JMP age2_x1_.007B00F8
//004FF1E4     EB 26          JMP SHORT age2_x1.004FF20C






void chatchatColorFixe()
{
	//direct message color
	setHook((void*)0x04DCABB , chatColor004DCAC1);
	// 004DCA37
	setHook((void*)0x04DCA37, chatColor004DCA37);
	// set -- white
	setHook((void*)0x05B5FF5, chatColor005B5FF5);
	// --shepp found
	setHook((void*)0x053D5AB , chatColor053D5AB);
	//player position
	setHook((void*)0x0422A80, getplayerPositionn);
	////set pannnel color
	//setHook((void*)0x05E4D08, PannelColor005E4D08);
}

 //message writed on list 
//00422BCB | . 8BFE           MOV EDI, ESI
//00422BCD | . 83C9 FF        OR ECX, FFFFFFFF
//



//when hosting room
//player position ?
//0042A860  |. 8B8424 2801000>MOV EAX,DWORD PTR SS:[ESP+128]
//
//15F80020
//15F80178  58 B3 6A 02              X³j
//
//0042A860 | . 8B8424 28010000     MOV EAX, DWORD PTR SS : [ESP + 128]
//
