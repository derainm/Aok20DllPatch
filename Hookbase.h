//#include "hook.cpp"
//#include "hook.cpp"
#include "pch.h"
#include <wtypes.h>
#pragma once
bool Hook(void* toHook, void* ourFunct, int len);
void __cdecl setHook(void* addr, void* newAddr);
void __cdecl setHookJE(void* addr, void* newAddr);
void __cdecl setHookJA(void* addr, void* newAddr);
void __cdecl setHookCall(void* addr, void* newAddr);
void __cdecl writeByte(DWORD addr, BYTE val);
void __cdecl writeData(DWORD addr, void* data, int len);
void __cdecl writeDwordF(DWORD addr, DWORD val);
void __cdecl writeDwordF1(DWORD addr, DWORD val);
void __cdecl writeDword(DWORD addr, DWORD val);
