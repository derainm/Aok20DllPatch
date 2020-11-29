#include <windows.h>
#include "Hookbase.h"


///resize  screen 
#pragma region resize  screen 
////00448551  |. 8B6C24 4C      MOV EBP,DWORD PTR SS:[ESP+0x4C]
//004A5230  /$ 6A FF          PUSH -0x1
//004A55F0  /$ 56             PUSH ESI
//004A55F0  /$ 56             PUSH ESI
//007BF900   8B6C24 4C         MOV EBP,DWORD PTR SS:[ESP+0x4C]
DWORD u_00448925;
DWORD u_004A5230;
DWORD u_007BF980;
DWORD u_004A55F0;
DWORD u_0044869C;//0044869C  |> 6A 00          PUSH 0x0                                 ; /Arg11 = 00000000

void __declspec(naked)  u_AddWideScreenPanel00448551()
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
		CALL u_004A5230//0055E9E0
		TEST EAX, EAX
		JE _u_00448925 // 005BBCFA
		MOV ECX, DWORD PTR DS : [EDI]
		PUSH 14h
		LEA EAX, DWORD PTR DS : [ESI + 88Ch]
		PUSH ECX
		PUSH EAX
		MOV ECX, ESI
		CALL u_004A55F0 //0055EDA0
		TEST EAX, EAX
		JE _u_00448925 // 005BBCFA
		MOV ECX, DWORD PTR DS : [ESI + 888h]
		PUSH ECX
		CALL u_007BF980 //age2_x1.007BF980
		JMP u_0044869C //age2_x1.005BBA15
		_u_00448925 :
		JMP[u_00448925]
	}
}
//007BF980
WORD u_7A5608;
DWORD u_004BD5E0;//004BD5E0   $ 8B01           MOV EAX,DWORD PTR DS:[ECX]
DWORD u_7912A0;
DWORD u_007BF9D0;
void __declspec(naked)  u_AddWideScreenPanel007BF980()
{
	__asm {
		MOV ECX, DWORD PTR SS : [ESP + 4h]
		XOR EAX, EAX
		MOV  WORD PTR DS : [u_7A5608] , 20h//WORD PTR DS : [
		MOV DWORD PTR DS : [ECX + 174h] , EAX//[ECX + 174h] 
		CALL u_004BD5E0 //00547A00
		_007BF99A :
		MOV ECX, u_7912A0
			MOV ECX, DWORD PTR DS : [ECX]
			MOV EDX, DWORD PTR DS : [ECX + 68h]//[ECX + 6Ch]
			MOV ECX, DWORD PTR SS : [ESP + 4h]
			MOV EAX, DWORD PTR DS : [EDX + 18h]
			PUSH u_007BF9D0//age2_x1.007BF9D0
			PUSH ECX
			PUSH 0h
			MOV ECX, DWORD PTR DS : [EAX]
			PUSH 0h
			PUSH EAX
			CALL DWORD PTR DS : [ECX + 20h]
			CMP  WORD PTR DS : [u_7A5608] , 20h
			MOV BYTE PTR DS : [u_7A5608] , 8h
			JE _007BF99A
			RETN 4h
	}
}
DWORD u_7A5609;
DWORD u_004BCF90;
DWORD u_004BCEB0;
DWORD u_005FCE14;
DWORD u_04BBF20;
char u_printRes[] = "%d x %d";
void __declspec(naked)  u_AddWideScreenPanel007BF9D0()
{
	__asm {
		PUSH ESI
		PUSH EDI
		PUSH EBX
		MOV EAX, DWORD PTR DS : [u_7A5608]
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
		PUSH offset  u_printRes//_007BFA70; ASCII "%d x %d"
		PUSH ECX
		CALL u_005FCE14// age2_x1.0061442B  005FCE14  /$ 55             PUSH EBP
		ADD ESP, 10h
		LEA EDX, DWORD PTR SS : [ESP]
		MOV ECX, EBX
		XOR EAX, EAX
		PUSH EAX
		PUSH EDI
		MOV WORD PTR SS : [ESP + 2h] , SI
		PUSH EDX
		CALL u_004BCF90 //age2_x1.005473A0 
		ADD ESP, 20h
		//MOV BYTE PTR DS:[_7A5609]  , 1h
		MOV BYTE PTR DS : [u_7A5608 + 1] , 1h
		MOV ECX, u_7912A0
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
		CALL u_004BCEB0 //age2_x1.005472B0
		MOV ECX, EBX
		PUSH 1h
		PUSH 0h
		PUSH 7h
		CALL u_04BBF20//age2_x1.00546250
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
DWORD u_004BD5A0;
DWORD u_00448F37;
void __declspec(naked)  u_AddWideScreenPanel0448EE8()
{
	__asm {
		MOV ECX, DWORD PTR DS : [ESI + 888h]
		CALL u_004BD5A0 //age2_x1.005479C0
		MOV EDI, EAX
		XOR EBP, EBP
		MOV BP, AX
		SHR EDI, 10h
		JMP u_00448F37 //age2_x1.005BC2EE //00448F37   > 6A 00          PUSH 0x0
	}
}

//004EC54E  |. 0F84 F4080000  JE empires2.004ECE48

DWORD u_004A4570;
DWORD u_004ECE48;
//DWORD u_004A5230;
DWORD u_004EC554;
DWORD u_00948;
DWORD u_00968;
DWORD u_0096C;

void __declspec(naked)  u_AddWideScreenPanelBegingGame004EC54E()
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
		LEA EAX, u_00948 //DWORD PTR SS : [EBP +  948h]
		PUSH  2531h
		PUSH EAX
		PUSH EBP
		MOV ECX, EBP
		CALL  u_004A4570 //age2_x1.0055DD20
		TEST EAX, EAX
		JE __004ECE48 //age2_x1.0050CE74
		PUSH  0Ah
		PUSH  5Dh
		PUSH  80h
		PUSH  184h
		LEA ESI, u_00968//DWORD PTR SS : [EBP +  968h]
		PUSH  1C2h
		PUSH ESI
		PUSH EBP
		MOV ECX, EBP
		CALL u_004A5230 //age2_x1.0055E9E0
		TEST EAX, EAX
		JE __004ECE48 //age2_x1.0050CE74
		MOV ECX, DWORD PTR DS : [ESI]
		PUSH  14h
		LEA EAX, u_0096C//DWORD PTR SS : [EBP +  96Ch]
		PUSH ECX
		PUSH EAX
		MOV ECX, EBP
		CALL u_004A55F0 //0055EDA0 age2_x1.0055EDA0
		TEST EAX, EAX
		JE __004ECE48// age2_x1.0050CE74
		JMP u_004EC554 //004EC554| . 8B0E           MOV ECX, DWORD PTR DS : [ESI]
		__004ECE48 :
		JMP u_004ECE48

	}
}
//004ED45E  |. 8B01           |MOV EAX,DWORD PTR DS:[ECX]

//DWORD _004ED45E;
DWORD u_004ED464; // | > 8B0B | MOV ECX, DWORD PTR DS : [EBX]


void __declspec(naked)  u_AddWideScreenPanelBegingGame004ED45E()
{
	__asm {
		MOV EAX, DWORD PTR SS : [ESP + 14h]
		CMP EAX, 3h
		JNZ __004ED464//age2_x1.0050D3BC
		MOV EAX, DWORD PTR DS : [ECX]
		PUSH EDI
		CALL DWORD PTR DS : [EAX + 14h]
		JMP u_004ED464 //age2_x1.0050D3BC
		__004ED464 :
		JMP u_004ED464
	}
}
//0044862F  |> E8 3C720600    CALL empires2.004AF870
//DWORD u_007BF9D0;
DWORD u_00448634;
void __declspec(naked)  u_AddWideScreenPanelBegingGame0044862F()
{
	__asm {
		//MOV ECX, DWORD PTR DS : [EBX + 0964h]//968
		//MOV ECX, DWORD PTR DS : [EBX]
		MOV ECX, DWORD PTR DS : [ESI + 88Ch]
		PUSH ECX
		CALL u_007BF9D0// age2_x1.007BF980
		JMP u_00448634//age2_x1.0050F3C8
	}
}
//004EEFF1   . 8B8D 58090000  MOV ECX,DWORD PTR SS:[EBP+0x958]

DWORD u_004EF058;
DWORD u_004EF06F;
//void __declspec(naked)  AddWideScreenPanelBegingGame004EEFF1()
//{
//	__asm {
//		MOV ECX, DWORD PTR SS : [EBP + 958h]//964h
//		CMP EAX, ECX
//		JNZ _007BF8EE
//		CALL u_004BD5A0 //age2_x1.005479C0
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
DWORD u_004EEAFF;
//004EEAE8   > 8B0D C4456600  MOV ECX,DWORD PTR DS:[0x6645C4]
DWORD u_004EEAE8;
//004BD5A0  /$ 0FBF81 0401000>MOVSX EAX,WORD PTR DS:[ECX+0x104]
//DWORD u_004BD5A0;


void __declspec(naked)  u_AddWideScreenPanelBegingGame004EEA81()
{
	__asm {
		MOV ECX, DWORD PTR SS : [EBP + 958h]//964h
		CMP EAX, ECX
		JNZ _007BF8EE
		CALL u_004BD5A0 //age2_x1.005479C0
		MOV ESI, EAX
		XOR EDI, EDI
		MOV DI, AX
		SHR ESI, 10h
		JMP u_004EEAE8 //age2_x1.0050EAFE
		_007BF8EE :
		JMP u_004EEAFF //age2_x1.0050EB18
			NOP
	}
}
#pragma endregion resize screen

void userPatchWideScreen(int H, int V)
{
	
	//writeDwordF(0x00E494A, V - 54);
	/*
		writeDwordF(0x001BCC6,	H + 0	   );
		writeDwordF(0x001BD0C,	V + 0	   );
		writeDwordF(0x001BD13,	H + 1	   );
		writeDwordF(0x001D355,	H + 0	   );
		writeDwordF(0x001D36F,	V + 0	   );
		writeDwordF(0x001D392,	H + 1	   );
		writeDwordF(0x001D94C,	H + 0	   );
		writeDwordF(0x001D97B,	V + 0	   );
		writeDwordF(0x001D985,	H + 1	   );
		writeDwordF(0x0048610,	H + 0	   );
		writeDwordF(0x0048617,	H + 1	   );
		writeDwordF(0x004865C,	H + 0	   );
		writeDwordF(0x0048681,	H + 1	   );
		writeDwordF(0x0048F07,	H + 0	   );
		writeDwordF(0x0048F0C,	V + 0	   );
		writeDwordF(0x0048F22,	H + 1	   );
		writeDwordF(0x0048F27,	V + 1	   );
		writeDwordF(0x0048F67,	H + 2	   );
		writeDwordF(0x0050B28,	V + 0	   );
		writeDwordF(0x0050C00,	V + 1	   );
		writeDwordF(0x0050DA3,	V + 2	   );
		writeDwordF(0x00510B3,	V + 0	   );
		writeDwordF(0x00510CD,	V + 1	   );
		writeDwordF(0x005DF7B, 	H + 0	   );
		writeDwordF(0x005DF86, 	H + 1	   );
		writeDwordF(0x005E030, 	H + 0	   );
		writeDwordF(0x005E039,	V + 0	   );
		writeDwordF(0x005E04B, 	H + 1	   );
		writeDwordF(0x005E054,	V + 1	   );
		writeDwordF(0x005E066, 	H + 2	   );
		writeDwordF(0x005E06F, 	V + 2	   );
		writeDwordF(0x005E105, 	H + 0	   );
		writeDwordF(0x005E10E, 	V + 0	   );
		writeDwordF(0x005E1AD, 	H + 0	   );
		writeDwordF(0x005E1B6, 	V + 0	   );
		writeDwordF(0x005E25B, 	H + 0	   );
		writeDwordF(0x005E264,	V + 0	   );
		writeDwordF(0x005E2CE, 	H + 0	   );
		writeDwordF(0x005E324, 	H + 1	   );
		writeDwordF(0x005E32B, 	H + 2	   );
		writeDwordF(0x005E394, 	H + 0	   );
		writeDwordF(0x005E39B,	H + 2	   );
		writeDwordF(0x005E416,	H + 0	   );
		writeDwordF(0x005E41D,	H + 2	   );
		writeDwordF(0x005E490,	H + 0	   );
		writeDwordF(0x005E497,	H + 2	   );
		writeDwordF(0x00DA6EB,	H + 1	   );
		writeDwordF(0x00DA707,	H + 1	   );
		writeDwordF(0x00DA71C,	V - 279	   );
		writeDwordF(0x00DA72E,	V - 249	   );
		writeDwordF(0x00DA733,	H + 1	   );
		writeDwordF(0x00DA767,	V - 206	   );
		writeDwordF(0x00DA7CA,	V - 196	   );
		writeDwordF(0x00DA7D9,	V - 178	   );
		writeDwordF(0x00DA811,	V - 55	   );
		writeDwordF(0x00DA918,	H - 301	   );
		writeDwordF(0x00DA92E,	H - 241	   );
		writeDwordF(0x00DA944,	H - 181	   );
		writeDwordF(0x00DA95A,	H - 121	   );
		writeDwordF(0x00DA970,	H - 62	   );
		writeDwordF(0x00DA982,	V - 194	   );
		writeDwordF(0x00DA99B,	V - 67	   );
		writeDwordF(0x00DA9B4,	V - 197	   );
		writeDwordF(0x00DA9CD,	V - 197	   );
		writeDwordF(0x00DA9E6,	V - 167	   );
		writeDwordF(0x00DA9FF,	V - 77	   );
		writeDwordF(0x00DAA18,	V - 48	   );
		writeDwordF(0x00DAA31,	V - 44	   );
		writeDwordF(0x00DAA42,	H + 0	   );
		writeDwordF(0x00DAA5E,	H + 0	   );
		writeDwordF(0x00DAA73,	V - 230	   );
		writeDwordF(0x00DAA85,	V - 200	   );
		writeDwordF(0x00DAA8A,	H + 0	   );
		writeDwordF(0x00DAABE,	V - 169	   );
		writeDwordF(0x00DAAC5,	H - 336	   );
		writeDwordF(0x00DAAF3,	H / 2 - 112);
		writeDwordF(0x00DAB1C, 	H - 649    );
		writeDwordF(0x00DAB21,	V - 152	   );
		writeDwordF(0x00DAB30,	V - 144	   );
		writeDwordF(0x00DAB68,	V - 21	   );
		writeDwordF(0x00DAC6F,	H - 303	   );
		writeDwordF(0x00DAC85,	H - 243	   );
		writeDwordF(0x00DAC9B,	H - 183	   );
		writeDwordF(0x00DACB1,	H - 123	   );
		writeDwordF(0x00DACC7,	H - 64	   );
		writeDwordF(0x00DACD9,	V - 154	   );
		writeDwordF(0x00DACE0,	H - 308	   );
		writeDwordF(0x00DACF2,	V - 49	   );
		writeDwordF(0x00DACF9,	H - 309	   );
		writeDwordF(0x00DAD0B,	V - 156	   );
		writeDwordF(0x00DAD12,	H - 96	   );
		writeDwordF(0x00DAD24,	V - 162	   );
		writeDwordF(0x00DAD2B,	H - 69	   );
		writeDwordF(0x00DAD3D,	V - 137	   );
		writeDwordF(0x00DAD44,	H - 60	   );
		writeDwordF(0x00DAD56,	V - 59	   );
		writeDwordF(0x00DAD5D,	H - 61	   );
		writeDwordF(0x00DAD6F,	V - 35	   );
		writeDwordF(0x00DAD76,	H - 74	   );
		writeDwordF(0x00DAD88,	V - 39	   );
		writeDwordF(0x00DAD8F,	H - 102	   );
		writeDwordF(0x00DF4E6,	H + 2	   );
		writeDwordF(0x00DF4EF,	V + 2	   );
		writeDwordF(0x00DF514,	H + 1	   );
		writeDwordF(0x00DF51D,	V + 1	   );
		writeDwordF(0x00DF551,	H + 0	   );
		writeDwordF(0x00DF55A,	V + 0	   );
		writeDwordF(0x00E1C30,	H + 1	   );
		writeDwordF(0x00E471A,	H + 1	   );
		writeDwordF(0x00E4732,	V - 171	   );
		writeDwordF(0x00E4748,	V - 138	   );
		writeDwordF(0x00E478A,	V - 138	   );
		writeDwordF(0x00E475E,	V - 118	   );
		writeDwordF(0x00E47A0,	V - 118	   );
		writeDwordF(0x00E4774,	V - 98	   );
		writeDwordF(0x00E47B6,	V - 98	   );
		writeDwordF(0x00E47CC,	V - 59	   );
		writeDwordF(0x00E47E2,	V - 59	   );
		writeDwordF(0x00E47F8,	V - 59	   );
		writeDwordF(0x00E4811,	V - 59	   );
		writeDwordF(0x00E482C,	V - 59	   );
		writeDwordF(0x00E4855,	V - 144	   );
		writeDwordF(0x00E48AB,	V - 118	   );
		writeDwordF(0x00E4869,	V - 118	   );
		writeDwordF(0x00E487F,	V - 98	   );
		writeDwordF(0x00E48C1,	V - 98	   );
		writeDwordF(0x00E4895,	V - 78	   );
		writeDwordF(0x00E48D7,	V - 78	   );
		writeDwordF(0x00E48ED,	V - 54	   );
		writeDwordF(0x00E4903,	V - 54	   );
		writeDwordF(0x00E4919,	V - 54	   );
		writeDwordF(0x00E4932,	V - 54	   );
		writeDwordF(0x00E494B,	V - 54	   );
		writeDwordF(0x00E4841,	H + 0	   );
		writeDwordF(0x00ED127,	H + 0	   );
		writeDwordF(0x00ED14E,	H + 1	   );
		writeDwordF(0x00EEAC4,	H + 0	   );
		writeDwordF(0x00EEAC9,	V + 0	   );
		writeDwordF(0x00EEADF,	H + 1	   );
		writeDwordF(0x00EEAE4,	V + 1	   );
		writeDwordF(0x01A6BC5,	H + 1	   );*/

writeDwordF(0x001BCC5, H + 0);//1024
writeDwordF(0x001BD06, V + 0);//768
//writeDwordF(0x001BD12,	H + 1);//1280
writeDwordF(0x001D354, H + 0);//1024
writeDwordF(0x001D369, V + 0);//768
//writeDwordF(0x001D38C,	H + 1);//1280
writeDwordF(0x001D94B, H + 0);//1024
writeDwordF(0x001D975, V + 0);//768
//writeDwordF(0x001D984,	H + 1);//1280
writeDwordF(0x004860F, H + 0);//1024
//writeDwordF(0x0048616,	H + 1);//1280
writeDwordF(0x004865B, H + 0);//1024
//writeDwordF(0x004867F,	H + 1);//1280
writeDwordF(0x0048F06, H + 0);//1024
writeDwordF(0x0048F0B, V + 0);//768
//writeDwordF(0x0048F21,	H + 1);//1280
//writeDwordF(0x0048F26,	V + 1);//1024
//writeDwordF(0x0048F65,	H + 2);//1600
writeDwordF(0x0050B27, V + 0);//768
//writeDwordF(0x0050BFF,	V + 1);//1024
//writeDwordF(0x0050DA2,	V + 2);//1200
writeDwordF(0x00510B2, V + 0);//768
//writeDwordF(0x00510CC,	V + 1);//1024
writeDwordF(0x005DF79, H + 0);//1024
//writeDwordF(0x005DF84, 	H + 1);//1280
writeDwordF(0x005E02E, H + 0);//1024
writeDwordF(0x005E036, V + 0);//768
//writeDwordF(0x005E049, 	H + 1);//1280
//writeDwordF(0x005E051,	V + 1);//1024
//writeDwordF(0x005E064, 	H + 2);//1600
//writeDwordF(0x005E06C, 	V + 2);//1200
writeDwordF(0x005E103, H + 0);//1024
writeDwordF(0x005E10B, V + 0);//768
writeDwordF(0x005E1AB, H + 0);//1024
writeDwordF(0x005E1B3, V + 0);//768
writeDwordF(0x005E259, H);//1024   /////
writeDwordF(0x005E261, V + 0);//768
writeDwordF(0x005E2CD, H + 0);//1024
//writeDwordF(0x005E323, 	H + 1);//1280
//writeDwordF(0x005E32A, 	H + 2);//1600
writeDwordF(0x005E393, H + 0);//1024
//writeDwordF(0x005E39A,	H + 2);//1600
writeDwordF(0x005E415, H + 0);//1024
//writeDwordF(0x005E41C,	H + 2);//1600
writeDwordF(0x005E48F, H + 0);//1024
//writeDwordF(0x005E496,	H + 2);//1600
//writeDwordF(0x00DA6EA,	H + 1);//1280
//writeDwordF(0x00DA706,	H + 1);//1280
writeDwordF(0x00DA71B, V - 279);
writeDwordF(0x00DA72D, V - 249);
//writeDwordF(0x00DA732,	H +	1  );//1280
writeDwordF(0x00DA766, V - 206);
writeDwordF(0x00DA7C9, V - 196);
writeDwordF(0x00DA7D8, V - 178);
writeDwordF(0x00DA80F, V - 55);
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
writeDwordF(0x00DAA17, V - 48);
writeDwordF(0x00DAA30, V - 44);
writeDwordF(0x00DAA41, H + 0);//1024
writeDwordF(0x00DAA5D, H + 0);//1024
writeDwordF(0x00DAA72, V - 230);
writeDwordF(0x00DAA84, V - 200);
writeDwordF(0x00DAA89, H + 0);//1024
writeDwordF(0x00DAABD, V - 169);
writeDwordF(0x00DAAC4, H - 336);
writeDwordF(0x00DAAF2, H / 2 - 112);
writeDwordF(0x00DAB1B, H - 649);
writeDwordF(0x00DAB20, V - 152);
writeDwordF(0x00DAB2F, V - 144);
//writeDwordF(0x00DAB67, V - 21);//
writeDwordF(0x00DAC6E, H - 303);
writeDwordF(0x00DAC84, H - 243);
writeDwordF(0x00DAC9A, H - 183);
writeDwordF(0x00DACB0, H - 123);
writeDwordF(0x00DACC6, H - 64);
writeDwordF(0x00DACD8, V - 154);
writeDwordF(0x00DACDF, H - 308);
writeDwordF(0x00DACF1, V - 49);
writeDwordF(0x00DACF8, H - 309);
writeDwordF(0x00DAD0A, V - 156);
writeDwordF(0x00DAD11, H - 96);
writeDwordF(0x00DAD23, V - 162);
writeDwordF(0x00DAD2A, H - 69);
writeDwordF(0x00DAD3C, V - 137);
writeDwordF(0x00DAD43, H - 60);
writeDwordF(0x00DAD55, V - 59);
writeDwordF(0x00DAD5C, H - 61);
writeDwordF(0x00DAD6E, V - 35);
writeDwordF(0x00DAD75, H - 74);
writeDwordF(0x00DAD87, V - 39);
writeDwordF(0x00DAD8E, H - 102);
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
//writeDwordF(0x00DF4E5,	H + 2  );//1600
//writeDwordF(0x00DF4EC,	V + 2  );//1200
//writeDwordF(0x00DF513,	H + 1  );//1280
//writeDwordF(0x00DF51A,	V + 1  );//1024
writeDwordF(0x00DF550, H + 0);//1024
writeDwordF(0x00DF557, V + 0);//768
//writeDwordF(0x00E1C2F,	H + 1  );//1280
//writeDwordF(0x00E4719,	H + 1  );//1280

writeDwordF(0x00E4840, H + 0);//1024
writeDwordF(0x00ED126, H + 0);//1024
//writeDwordF(0x00ED14D,	H + 1  );//1280
writeDwordF(0x00EEAC3, H + 0);//1024
writeDwordF(0x00EEAC8, V + 0);//768
//writeDwordF(0x00EEADE,	H + 1  );//1280
//writeDwordF(0x00EEAE3,	V + 1  );//1024
//writeDwordF(0x01A6BC4,	H + 1  );//1280

}


#pragma endregion

	//H 1024
	//V 768
	//0045E259     8180 07000000 >ADD DWORD PTR DS:[EAX+0x7],0x38811675


	//writeDwordF(0x001BD12,	H + 1);//1280

	//writeDwordF(0x001D38C,	H + 1);//1280

	//writeDwordF(0x001D984,	H + 1);//1280

	//writeDwordF(0x0048616,	H + 1);//1280

	//writeDwordF(0x004867F,	H + 1);//1280

	//writeDwordF(0x0048F21,	H + 1);//1280
	//writeDwordF(0x0048F26,	V + 1);//1024
	//writeDwordF(0x0048F65,	H + 2);//1600

	//writeDwordF(0x0050BFF,	V + 1);//1024
	//writeDwordF(0x0050DA2,	V + 2);//1200

	//writeDwordF(0x00510CC,	V + 1);//1024

	//writeDwordF(0x005DF84, 	H + 1);//1280

	//writeDwordF(0x005E049, 	H + 1);//1280
	//writeDwordF(0x005E051,	V + 1);//1024
	//writeDwordF(0x005E064, 	H + 2);//1600
	//writeDwordF(0x005E06C, 	V + 2);//1200

	//writeDwordF(0x005E323, 	H + 1);//1280
	//writeDwordF(0x005E32A, 	H + 2);//1600

	//writeDwordF(0x005E39A,	H + 2);//1600

	//writeDwordF(0x005E41C,	H + 2);//1600

	//writeDwordF(0x005E496,	H + 2);//1600
	//writeDwordF(0x00DA6EA,	H + 1);//1280
	//writeDwordF(0x00DA706,	H + 1);//1280

	//writeDwordF(0x00DA732,	H +	1  );//1280

	//writeDwordF(0x00DF4E5,	H + 2  );//1600
	//writeDwordF(0x00DF4EC,	V + 2  );//1200
	//writeDwordF(0x00DF513,	H + 1  );//1280
	//writeDwordF(0x00DF51A,	V + 1  );//1024

	//writeDwordF(0x00E1C2F,	H + 1  );//1280
	//writeDwordF(0x00E4719,	H + 1  );//1280


	//writeDwordF(0x00ED14D,	H + 1  );//1280

	//writeDwordF(0x00EEADE,	H + 1  );//1280
	//writeDwordF(0x00EEAE3,	V + 1  );//1024
	//writeDwordF(0x01A6BC4,	H + 1  );//1280

	//004DAB6E  |. 8B8E 5C100000  MOV ECX,DWORD PTR DS:[ESI+0x105C]

DWORD u_004DAB6E;
DWORD u_005A6870;
DWORD u_refwidth = 0x500;
DWORD u_refheight = 0x90;
void __declspec(naked) u_UnitFormationPrinteInWideScreen()
{
	__asm {

		MOV EBP, DWORD PTR DS : [ESI + 18h] ; Y
		SUB EBP, u_refheight
		LEA EDI, DWORD PTR DS : [ESI + 1074h]
		_007C0F71 :
		MOV EBX, DWORD PTR DS : [ESI + 14h] ; X
		SUB EBX, u_refwidth
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
		CALL  u_005A6870
		ADD EBX, 29h
		ADD EDI, 4h
		MOV EAX, DWORD PTR DS : [ESI + 14h] ; X
		SUB EAX, u_refwidth
		SHR EAX, 1h
		ADD EAX, 0F2h
		CMP EBX, EAX
		JL _007C0F82
		MOV EBX, DWORD PTR DS : [ESI + 18h]
		SUB EBX, 15h
		ADD EBP, 29h
		CMP EBP, EBX
		JL _007C0F71
		JMP u_004DAB6E

	}
}

// V = Y
// H = X
void patchEXE( int H, int V)
{

	//unit formation button print
	if (V >= 1024)
	{
		u_refwidth = 0x500;
		u_refheight = 0xB0;
	}
	else if (V >= 768 && V < 1024)
	{
		u_refwidth = 0x400;
		u_refheight = 0x90;
	}
	else if (V >= 600 && V < 768)
	{
		u_refwidth = 0x400;
		u_refheight = 0x90;
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
		//writeDwordF(0x00DAA84, V - 250);
		writeDwordF(0x00DAA84, V - 200);
		//writeByte(0x04DAA8F, 0x20);
		writeByte(0x04DAA8F, 0x19);
		//precY = 1024;
	}
	else if (V >= 768 && V < 1024)
	{
		//writeDwordF(0x00DAA84, V - 200);
		writeDwordF(0x00DAA84, V - 200);
		//writeByte(0x04DAA8F, 0x19);
		writeByte(0x04DAA8F, 0x18);
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
	writeDwordF(0x00DAA72, V - 230);
	//writeDwordF(0x00DAA84, V - 200);

	//writeDwordF(0x00DAA89, H + ratioH + 0);//1024
	//mini map 
	/*if (V >= 1024)
	{
		writeDwordF(0x00DAABD, V - 187);
		writeDwordF(0x00DAAC4, H - 369);
	}
	else if (V < 1024 && V >= 768)
	{
		writeDwordF(0x00DAABD, V - 169);
		writeDwordF(0x00DAAC4, H - 336);
	}*/
	//writeDwordF(0x00DAABD, V - 169);
	//writeDwordF(0x00DAAC4, H - 336);



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

	writeDwordF(0x00DAB2F, V - 144);
	writeDwordF(0x00DAB67, V - 21);//21




	//selection
	writeDwordF(0x00DAB20, V - 152);
	int ratioSH = 0;
	/*if (V >= 1024)
	{
		//ratioSH = -(H - 1024 / 2) / 2 - 1024 / 2 - 50;
		//x
		writeDwordF(0x00DAB20, V - 162);
	}
	else if (V < 1024 && V >= 768)
	{
		//ratioSH = -(H - 800) / 2 - 800 / 2 - 230;
		//x
		writeDwordF(0x00DAB20, V - 152);
	}*/
	//else if (V < 768 && V >= 600)
	//{
	//	ratioSH = -(H - 800) / 2 - 800 / 2 ;
	//	//x
	//	writeDwordF(0x00DAB20, V + ratioV - 152);
	//}

	//writeDwordF(0x0DAB27, H - 230);//
	int ratioSHeight = 0;

	//else if (V < 768 && V >= 600)
	//{
	//	ratioSHeight = (800) / 2;
	//}
	//size of army selection
	//writeDwordF(0x00DAB1B, ratioSHeight);
	//writeDwordF(0x00DAB1B, H - 649);
	writeDwordF(0x00DAABD, V - 169);
	writeDwordF(0x00DAAC4, H - 336);
	writeDwordF(0x00DAB1B, H - 649);
	writeDwordF(0x00DAB20, V - 152);
	writeDwordF(0x00DAB2F, V - 144);
	//diplomatie button
	writeDwordF(0x00DAC6E, H - 303);
	writeDwordF(0x00DAC84, H - 243);
	writeDwordF(0x00DAC9A, H - 183);
	writeDwordF(0x00DACB0, H - 123);
	writeDwordF(0x00DACC6, H - 64);
	//mini map button
	int ratioVm = 0;


	//flashing x button 
	writeDwordF(0x00DACD8, V - 154);
	writeDwordF(0x00DACDF, H - 308);
	//idle button
	writeDwordF(0x00DACF1, V - 49);
	writeDwordF(0x00DACF8, H - 309);
	//player name button
	writeDwordF(0x00DAD0A, V - 156);
	writeDwordF(0x00DAD11, H - 96);
	//

	if (V >= 1024)
	{
		writeDwordF(0x00DAD2A, H - 29);
		writeDwordF(0x00DAD23, V - 142);
	}
	else if (V < 1024 && V >= 768)
	{
		writeDwordF(0x00DAD2A, H - 50);
		writeDwordF(0x00DAD23, V + -132);
	}

	//ok
	writeDwordF(0x00DAD3C, V - 156);
	writeDwordF(0x00DAD43, H - 66);
	//
	writeDwordF(0x00DAD55, V - 59);
	writeDwordF(0x00DAD5C, H - 61);
	//
	writeDwordF(0x00DAD6E, V - 35);
	writeDwordF(0x00DAD75, H - 74);
	//idel show
	writeDwordF(0x00DAD87, V - 39);
	writeDwordF(0x00DAD8E, H - 102);
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
DWORD u_7A5500 ;
DWORD uu_00632C48= 0x0632C48;
DWORD uu_00619C48 = 0x0619C48;
void __declspec(naked) u_UserPatchResolution007C1EF0()
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
		//JMP [uu_00632C48]
		JMP[uu_00619C48]
	}
}

void __declspec(naked) u_UserPatchResolution007C1F20()
{
	__asm {
		PUSH EBP
		MOV EBP, ESP
		PUSH EBX
		PUSH ESI
		PUSH EDI
		MOV EBX, DWORD PTR DS : [u_7A5500]
		XOR EDX, EDX
		AND EBX, EBX
		JE short uu_007C1F4A
		MOV DWORD PTR DS : [774004h] , EBX
		MOV DWORD PTR DS : [774008h] , EBX
		MOV ECX, DWORD PTR SS : [EBP + 30h]
		MOV EAX, DWORD PTR SS : [EBP + 34h]
		MOV DWORD PTR DS : [EBX + 8h] , ECX
		MOV DWORD PTR DS : [EBX + 0Ch] , EAX
		uu_007C1F4A:
		MOV ECX, DWORD PTR SS : [EBP + 0Ch]
		MOV EAX, DWORD PTR SS : [EBP + 14h]
		MOV DWORD PTR DS : [774024h] , ECX
		LEA ECX, DWORD PTR DS : [EAX + ECX - 1h]
		MOV DWORD PTR DS : [774028h] , ECX
		//JMP [uu_00632C48]
		JMP[uu_00619C48]
	}
}
void __declspec(naked)  uu_AddWideScreenPanel007C1D90()
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
		JMP[uu_00619C48]
	}
}
DWORD uu_007C1D90 = (DWORD)uu_AddWideScreenPanel007C1D90;
//__declspec(naked) void resources_changed_hook(short int res_type, float usage_type, int unused) {
//	__asm {
//		pushad
//		mov eax, temp_pointer
//		mov dword ptr[eax], ecx         //temp_pointer->base_pointer points to calling class
//	}
//	//temp_pointer = (item_set*)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(item_set));
//
//	temp_pointer->player_name = (char*)(*(temp_pointer->base_pointer + (0x98 / sizeof(DWORD_PTR))));
//	temp_pointer->player_stat = (player_stats*)(*(temp_pointer->base_pointer + (0xA8 / sizeof(DWORD_PTR))));
//	if (items_insert(&base_pointers, temp_pointer) == true)
//		temp_pointer = (item_set*)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(item_set));
//
//	__asm {
//		popad
//		jmp resources_changed
//	}
//}
//007C1CD2   E8 DD1CE5FF      CALL age2_x1.006139B4
//we need this to alloc picture
//00607A94 | > 8325 8C2A7700 > AND DWORD PTR DS : [772A8C] , 0
//00607A9B | . 8325 902A7700 > AND DWORD PTR DS : [772A90] , 0
//

void __declspec(naked) u_UserPatchResolution_006178C8()//heap free
{
	__asm {
			//MOV EAX,DWORD PTR DS:[793144]
		    MOV EAX, DWORD PTR DS : [772A90h] 
			LEA ECX,DWORD PTR DS:[EAX+EAX*4h]
			//MOV EAX,DWORD PTR DS:[793148]
			MOV EAX,DWORD PTR DS:[772A94h]
			LEA ECX,DWORD PTR DS:[EAX+ECX*4h]
			_006178D8:
			CMP EAX,ECX
			JNB short _006178F0
			MOV EDX,DWORD PTR SS:[ESP+4h]
			SUB EDX,DWORD PTR DS:[EAX+0Ch]
			CMP EDX,100000h
			JB short _006178F2
			ADD EAX,14
			JMP short _006178D8
			_006178F0:
			XOR EAX,EAX
			_006178F2:
			RETN
	}
}




//564A2BF7   50               PUSH EAX
//564A2BF8   6A 00            PUSH 0
//564A2BFA   A3 58564A56      MOV DWORD PTR DS : [test] , EAX
//564A2BFF   FF15 18404A56    CALL DWORD PTR DS : [<&KERNEL32.GetProcessHeap>] ; KERNEL32.GetProcessHeap
//564A2C05   50               PUSH EAX
//564A2C06   FF15 10404A56    CALL DWORD PTR DS : [<&KERNEL32.HeapFree>] ; KERNEL32.HeapFree
//

//without GetProcessHeap
//564A2BF7   50               PUSH EAX
//564A2BF8   6A 00            PUSH 0
//564A2BFA   FF35 BC564A56    PUSH DWORD PTR DS : [han] //HANDLE
//564A2C00 > A3 58564A56      MOV DWORD PTR DS : [test] , EAX
//564A2C05   FF15 10404A56    CALL DWORD PTR DS : [<&KERNEL32.HeapFree>] ; KERNEL32.HeapFree

//DWORD hHeap =0x772A98;
//DWORD _006178C8 = (DWORD)u_UserPatchResolution_006178C8;
////PUSH DWORD PTR DS : [772A98] ; / hHeap = NULL
//void __declspec(naked) u_UserPatchResolution_006139B4()//heap free
//{
//	__asm {
//		PUSH ESI
//		MOV ESI, DWORD PTR SS : [ESP + 8h]
//		TEST ESI, ESI
//		JE short _006139E1
//		PUSH ESI
//		CALL _006178C8
//		POP ECX
//		TEST EAX, EAX
//		PUSH ESI
//		JE SHORT age2_x1.006139D3
//		PUSH EAX
//		CALL age2_x1.006178F3
//		POP ECX
//		POP ECX
//		POP ESI
//		RETN
//	}
//	HeapFree(han, 0, test);
//	__asm
//	{
//	_006139E1:
//	POP ESI
//	RETN
//
//
//		/*
//
//		   PUSH 0; | Flags = 0
//		   PUSH DWORD PTR DS : [79314C] ; | hHeap = NULL
//		   CALL DWORD PTR DS : [<&KERNEL32.HeapFree>] ; \HeapFree
//		   POP ESI
//		   RETN
//*/
//
//	}
//	HeapFree(han, 0, test);
//}
void __declspec(naked) u_UserPatchResolution_006137C9()//heap alloc
{
	__asm {

	}
}
//006139B4  /$ 56             PUSH ESI
//0058FA7E  |. E8 2D960600    |CALL Empires2.005F90B0

//0058F2A0  |. E8 4B9D0600    CALL Empires2.005F8FF0
//00401210  |. E8 B4252100    CALL age2_x1.006137C9



//006139B4   ==  0058FA7E

//to heap alloc 24444
DWORD uu_006139B4 = 0x058FA7E;//(DWORD)u_UserPatchResolution_006139B4;
DWORD uu_006137C9 = 0x05F8FF0;
DWORD uu_007C1EF0 = (DWORD)u_UserPatchResolution007C1EF0;
DWORD uu_007C1F20 = (DWORD)u_UserPatchResolution007C1F20;
DWORD* test ;
HANDLE  han ;
DWORD _005F8FF0 = 0x05F8FF0;
DWORD __005FCE14 = 0x05FCE14;
void __declspec(naked) u_UserPatchResolution07C1C38()
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
			JGE short uu_007C1C60
			MOV DWORD PTR SS : [ESP + 20h] , 0D6h
			JMP short uu_007C1C68
			uu_007C1C60 :
			MOV DWORD PTR SS : [ESP + 20h] , 116h
			uu_007C1C68 :
			SUB ESI, EDX
			AND ESI, ESI
			JL uu_007C1EE3
			uu_007C1C72 :
			MOV DWORD PTR SS : [ESP + 4h] , ESI
			CALL uu_007C1EF0
			//MOV DWORD PTR DS : [795038] , 0h
			MOV DWORD PTR DS : [774038h] , 0h
			MOV EDX, DWORD PTR SS : [EBP + 30h]
			SUB ESI, EDX
			ADD ESI, 190h
			AND ESI, ESI
			JG short uu_007C1C72
			MOV DWORD PTR SS : [ESP + 4h] , 0h
			CALL uu_007C1EF0
			//MOV ECX, DWORD PTR DS : [795004]
			MOV ECX, DWORD PTR DS : [774004h]
			MOV EAX, DWORD PTR SS : [EBP + 30h]
			MOV EDX, DWORD PTR SS : [EBP + 34h]
			MOV DWORD PTR SS : [ESP + 38h] , ECX
			MOV DWORD PTR SS : [ESP + 3Ch] , EAX
			MOV DWORD PTR SS : [ESP + 40h] , EDX
			MOV DWORD PTR SS : [ESP + 44h] , EDI
			MOV DWORD PTR SS : [ESP + 48h] , EBX
			MOV ESI, EBX
			MOV EAX, DWORD PTR DS : [u_7A5500]
			TEST EAX, EAX
			JE short uu_007C1CDA
			CMP DWORD PTR DS : [EAX + 10h] , ESI
			JGE short uu_007C1D0D
			PUSH EAX
			CALL uu_006139B4
			//CALL __005FCE14
			ADD ESP, 4h
			uu_007C1CDA :
			SHL ESI, 2h
			ADD ESI, 14h
			PUSH ESI
			PUSH 1h
			//CALL uu_006137C9
			CALL _005F8FF0 // age2_x1.006137C9 heap alloc 
			ADD ESP, 8h
			MOV DWORD PTR DS : [u_7A5500] , EAX
			TEST EAX, EAX
			JE uu_007C1EE3
			LEA ECX, DWORD PTR DS : [ESI - 14h]
			LEA EDI, DWORD PTR DS : [EAX + 14h]
			MOV EDX, ECX
			SHR ECX, 2h
			REP STOS DWORD PTR ES : [EDI]
			MOV EDI, DWORD PTR SS : [ESP + 44h]
			MOV DWORD PTR DS : [EAX + 10h] , EBX
			uu_007C1D0D:
			MOV EDX, DWORD PTR SS : [ESP + 3Ch]
			MOV EAX, EDI
			SUB EAX, EDX
			SHR EAX, 1h
			SUB EAX, EDX
			MOV ESI, EAX
			MOV EAX, EBX
			LEA EBX, DWORD PTR DS : [EDX + ESI]
			MOV EDX, DWORD PTR SS : [ESP + 40h]
			SUB EAX, EDX
			MOV DWORD PTR SS : [ESP + 10h] , EDX
			MOV DWORD PTR SS : [ESP + 8h] , EAX
			MOV ECX, DWORD PTR SS : [ESP + 38h]
			MOV EDX, DWORD PTR SS : [ESP + 48h]
			LEA ESI, DWORD PTR DS : [ECX + EDX * 4h - 1B8h]
			CMP DWORD PTR DS : [ESI] , 0h
			JNZ short uu_007C1D56
			ADD ESI, 78h
			CMP DWORD PTR DS : [ESI] , 0h
			JNZ short uu_007C1D56
			ADD ESI, 78h
			CMP DWORD PTR DS : [ESI] , 0h
			JE uu_007C1EE3
			uu_007C1D56 :
			MOV EAX, DWORD PTR DS : [ESI]
			MOV EDX, DWORD PTR SS : [ESP + 3Ch]
			MOV DWORD PTR SS : [ESP + 24h] , EAX
			MOV EAX, EDI
			SUB EAX, EDX
			LEA ECX, DWORD PTR DS : [EDI - 198h]
			LEA EDX, DWORD PTR DS : [EDI - 1h]
			MOV DWORD PTR SS : [ESP + 1Ch] , 0h
			//MOV DWORD PTR DS : [795038] , 1C7
			MOV DWORD PTR DS : [774038h] , 1C7h
			MOV DWORD PTR SS : [ESP + 2Ch] , EDX
			MOV DWORD PTR SS : [ESP + 28h] , ECX
			MOV DWORD PTR SS : [ESP + 4h] , EAX
			CALL uu_007C1EF0
			MOV EAX, DWORD PTR SS : [ESP + 24h]
			MOV EDX, DWORD PTR SS : [ESP + 3Ch]
			MOV ECX, DWORD PTR DS : [EAX + 0Ch]
			CMP DWORD PTR SS : [ESP + 20h] , 116h
			JE short uu_007C1DBD
			MOV ESI, 0DAh
			LEA EBX, DWORD PTR DS : [EDI - 128h]
			MOV EDI, -26h
			LEA EBP, DWORD PTR DS : [EDX - 434h]
			JMP short uu_007C1DD3
			uu_007C1DBD :
			MOV ESI, 119h
			LEA EBX, DWORD PTR DS : [EDI - 160h]
			MOV EDI, -2Ah
			LEA EBP, DWORD PTR DS : [EDX - 576h]
			uu_007C1DD3 :
			XOR EDX, EDX
			LEA EAX, DWORD PTR DS : [ESI - 1h]
			MOV DWORD PTR SS : [ESP + 1Ch] , EDX
			//MOV DWORD PTR DS : [795038] , 1C7h
			MOV DWORD PTR DS : [774038h] , 1C7h
			MOV DWORD PTR SS : [ESP + 2Ch] , EAX
			MOV DWORD PTR SS : [ESP + 28h] , EDX
			MOV DWORD PTR SS : [ESP + 4h] , EDX
			MOV EDX, DWORD PTR SS : [ESP + 44h]
			LEA EAX, DWORD PTR DS : [EBX + 40h]
			DEC EDX
			CMP ECX, EAX
			JL short uu_007C1E09
			CMP ECX, EDX
			JNZ short uu_007C1E18
			CALL uu_007C1F20
			JMP short uu_007C1E18
			uu_007C1E09 :
			MOV ECX, DWORD PTR SS : [ESP + 38h]
			//MOV DWORD PTR DS : [795004] , ECX
			MOV DWORD PTR DS : [774004h] , ECX
			CALL uu_007C1EF0
			uu_007C1E18 :
			MOV EAX, DWORD PTR SS : [ESP + 24h]
			CMP DWORD PTR DS : [EAX + 0Ch] , ESI
			JL uu_007C1EE3
			CMP DWORD PTR DS : [EAX + 8h] , EBX
			JG uu_007C1EE3
			LEA EDX, DWORD PTR DS : [ESI + 30h]
			uu_007C1E31 :
			MOV DWORD PTR SS : [ESP + 1Ch] , 0h
			//MOV DWORD PTR DS : [795038] , 1C7h
			MOV DWORD PTR DS : [774038h] , 1C7h
			MOV DWORD PTR SS : [ESP + 2Ch] , EDX
			MOV DWORD PTR SS : [ESP + 28h] , ESI
			MOV DWORD PTR SS : [ESP + 4h] , EDI
			CALL uu_007C1F20
			ADD EDI, 30h
			ADD ESI, 30h
			ADD EBP, 30h
			LEA EDX, DWORD PTR DS : [ESI + 30h]
			CMP EDX, EBX
			JGE short uu_007C1EBE
			MOV DWORD PTR SS : [ESP + 1Ch] , 2h
			//MOV DWORD PTR DS : [795038] , 1C7h
			MOV DWORD PTR DS : [774038h] , 1C7h
			MOV DWORD PTR SS : [ESP + 2Ch] , EDX
			MOV DWORD PTR SS : [ESP + 28h] , ESI
			MOV DWORD PTR SS : [ESP + 4h] , EBP
			CALL uu_007C1F20
			ADD EDI, 30h
			ADD ESI, 30h
			ADD EBP, 30h
			LEA EDX, DWORD PTR DS : [ESI + 30h]
			CMP EDX, EBX
			JLE short uu_007C1E31
			MOV EDX, EBX
			MOV DWORD PTR SS : [ESP + 1Ch] , 0h
			//MOV DWORD PTR DS : [795038] , 1C7
			MOV DWORD PTR DS : [774038h] , 1C7h
			MOV DWORD PTR SS : [ESP + 2Ch] , EDX
			MOV DWORD PTR SS : [ESP + 28h] , ESI
			MOV DWORD PTR SS : [ESP + 4h] , EDI
			CALL uu_007C1F20
			JMP short uu_007C1EE3
			uu_007C1EBE :
			MOV EDX, EBX
			MOV DWORD PTR SS : [ESP + 1Ch] , 2h
			//MOV DWORD PTR DS : [795038] , 1C7
			MOV DWORD PTR DS : [774038h] , 1C7h
			MOV DWORD PTR SS : [ESP + 2Ch] , EDX
			MOV DWORD PTR SS : [ESP + 28h] , ESI
			MOV DWORD PTR SS : [ESP + 4h] , EBP
			CALL uu_007C1F20
			uu_007C1EE3:
			ADD ESP, 50h
			POP EBP
			POP EBX
			POP EDI
			POP ESI
			RETN
	}
	//test = (DWORD*)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(DWORD));
	//HeapFree(han, 0, test);
}
//7A362BE6   6A 04            PUSH 4
//7A362BE8   6A 08            PUSH 8
//7A362BEA   FF15 1440367A    CALL DWORD PTR DS : [<&KERNEL32.GetProcessHeap>] ; KERNEL32.GetProcessHeap
//7A362BF0   50               PUSH EAX
//7A362BF1   FF15 1040367A    CALL DWORD PTR DS : [<&KERNEL32.HeapAlloc>] ; ntdll.RtlAllocateHeap


DWORD u_007C1C38 = (DWORD)u_UserPatchResolution07C1C38;

void __declspec(naked) u_UserPatchResolution007C1B70()
{
	__asm {
			PUSH ESI
			PUSH EDI
			PUSH EBX
			PUSH EBP
			SUB ESP, 30h
			MOV EDI, DWORD PTR DS : [ESI + 20h]
			MOV ECX, DWORD PTR DS : [ESI + 1008h]
			//MOV ECX, DWORD PTR DS : [ESI + 100Ch]
			MOV EDX, DWORD PTR DS : [EDI + 0C0h]
			MOV EBX, DWORD PTR DS : [EDI + 0D0h]
			MOV DWORD PTR DS : [774000h] , EDX //00774000  =795000
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
			CALL uu_007C1D90
			MOV EDX, DWORD PTR SS : [EBP + 34h]
			MOV EAX, EBX
			MOV DWORD PTR DS : [774038h] , 1C7h
			SUB EAX, EDX
			MOV DWORD PTR SS : [ESP + 10h] , EDX
			MOV DWORD PTR SS : [ESP + 8h] , EAX
			CALL uu_007C1D90
			ADD ESP, 50h
			POP EBP
			POP EBX
			POP EDI
			POP ESI
			RETN
			_u_007C1C78 :
			JMP[u_007C1C38]




	}
}
//004E1C09   . 8B46 20        MOV EAX, DWORD PTR DS : [ESI + 20]
//004E1C0C   . 8B8E 08100000  MOV ECX, DWORD PTR DS : [ESI + 1008]
//004E1C12   . 6A 00          PUSH 0
//PUSH 522368  == push 004E1C20 
DWORD _007C1B70 = (DWORD)u_UserPatchResolution007C1B70;
void __declspec(naked) u_UserPatchResolution()
{
	__asm {
		//push 004E1C20h
		JMP _007C1B70
	}
}

// DWORD * myCord_X, DWORD* myCord_Y
void UserPatchWideScreen()//DWORD* myCord_X, DWORD* myCord_Y)
{



	///resize  screen 
#pragma region resize  screen 
		//00448066  |. 6A 69          |PUSH 0x69                               ; |Arg4 = 00000069
	writeByte(0x0448067, 0x6E);
	//00448095  |. 6A 46          |PUSH 0x46                               ; |Arg3 = 00000046
	writeByte(0x0448096, 0x4B);
	//00448F6B   . 74 26          JE SHORT empires2.00448F93
	writeByte(0x0448F6B, 0x66);
	writeByte(0x0448F6C, 0x90);
	u_7912A0 = 0x06645C4;//7912A0
	//00448551  |. 8B6C24 4C      MOV EBP,DWORD PTR SS:[ESP+0x4C]
	setHook((void*)0x0448551, u_AddWideScreenPanel00448551);
	//007BF980
	u_00448925 = 0x0448925;
	u_004A5230 = 0x04A5230;
	u_0044869C = 0x044869C;
	u_004BCF90 = 0x04BCF90;
	u_004BCEB0 = 0x04BCEB0;
	u_005FCE14 = 0x05FCE14;
	u_04BBF20 = 0x04BBF20;
	u_004A55F0 = 0x04A55F0;
	u_004BD5E0 = 0x04BD5E0;
	u_007BF980 = (DWORD)u_AddWideScreenPanel007BF980;
	u_007BF9D0 = (DWORD)u_AddWideScreenPanel007BF9D0;
	//00448EE8   > 8B8E 84080000  MOV ECX,DWORD PTR DS:[ESI+0x884]
	u_004BD5A0 = 0x04BD5A0;
	u_00448F37 = 0x0448F37;
	setHook((void*)0x0448EE8, u_AddWideScreenPanel0448EE8);
	//game start panel
	//
	//
	//todo

	/*
	_004A4570 = 0x04A4570;
	_004ECE48 = 0x04ECE48;
	u_004A5230 = 0x04A5230;
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
	/*
	//Formation button pront X and Y
	u_004DAB6E = 0x04DAB6E;
	u_005A6870 = 0x05A6870;
	//004DAB3A     BB 50020000    MOV EBX,0x250
	//writeDwordF(0x04DAB3A, V + ratioV - 400);//21
	setHook((void*)0x04DAB3A, u_UnitFormationPrinteInWideScreen);
	//WideScreen(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
	*/




	
	//user patch ress
	setHook((void*)0x04E1C0E  , u_UserPatchResolution);
	BYTE u_PUSH_4E1C20[] = { 0x68,0x20,0x1C,0x4E,0x00 };
	writeData(0x04E1C09, u_PUSH_4E1C20, 5);
	writeByte(0x04E1C13, 0x90);
	//004DF521  |. 7C 2D          JL SHORT empires2.004DF550
	writeByte(0x04DF521, 0xEB);
	
	
	
}