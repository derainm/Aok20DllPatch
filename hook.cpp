
#include "Hookbase.h"
bool Hook(void* toHook, void* ourFunct, int len) {
	if (len < 5) {
		return false;
	}

	DWORD curProtection;
	VirtualProtect(toHook, len, PAGE_EXECUTE_READWRITE, &curProtection);

	memset(toHook, 0x90, len);

	DWORD relativeAddress = ((DWORD)ourFunct - (DWORD)toHook) - 5;

	*(BYTE*)toHook = 0xE9;
	*(DWORD*)((DWORD)toHook + 1) = relativeAddress;

	DWORD temp;
	VirtualProtect(toHook, len, curProtection, &temp);

	return true;
}
void __cdecl setHook(void* addr, void* newAddr)
{

	unsigned long c;
	unsigned char j = 0xE9;
	WriteProcessMemory(GetCurrentProcess(), addr, &j, 1, (SIZE_T*)&c);
	char* r = (char*)newAddr - (char*)addr + (char*)-5;
	WriteProcessMemory(GetCurrentProcess(), (char*)addr + 1, &r, 4, (SIZE_T*)&c);

}
//long Je
void __cdecl setHookJE(void* addr, void* newAddr)
{
	unsigned long c;
	unsigned char j = 0x0F;
	unsigned char jg = 0x84;
	WriteProcessMemory(GetCurrentProcess(), addr, &j, 1, (SIZE_T*)&c);
	WriteProcessMemory(GetCurrentProcess(), (char*)addr + 1, &jg, 1, (SIZE_T*)&c);
	char* r = (char*)newAddr - (char*)addr + (char*)-5 - 1;
	WriteProcessMemory(GetCurrentProcess(), (char*)addr + 2, &r, 4, (SIZE_T*)&c);

}
void __cdecl setHookJA(void* addr, void* newAddr)
{
	unsigned long c;
	unsigned char j = 0x0F;
	unsigned char jg = 0x87;
	WriteProcessMemory(GetCurrentProcess(), addr, &j, 1, (SIZE_T*)&c);
	WriteProcessMemory(GetCurrentProcess(), (char*)addr + 1, &jg, 1, (SIZE_T*)&c);
	char* r = (char*)newAddr - (char*)addr + (char*)-5 - 1;
	WriteProcessMemory(GetCurrentProcess(), (char*)addr + 2, &r, 4, (SIZE_T*)&c);

}
void __cdecl setHookCall(void* addr, void* newAddr)
{
	unsigned long c;
	unsigned char j = 0xE8;
	WriteProcessMemory(GetCurrentProcess(), addr, &j, 1, (SIZE_T*)&c);
	char* r = (char*)newAddr - (char*)addr + (char*)-5;
	WriteProcessMemory(GetCurrentProcess(), (char*)addr + 1, &r, 4, (SIZE_T*)&c);

}
void __cdecl writeByte(DWORD addr, BYTE val)
{
	WriteProcessMemory(GetCurrentProcess(), (void*)addr, &val, 1, 0);
}
void __cdecl writeData(DWORD addr, void* data, int len)
{
	WriteProcessMemory(GetCurrentProcess(), (void*)addr, data, len, 0);
}

void __cdecl writeDwordF(DWORD addr, DWORD val)
{
	WriteProcessMemory(GetCurrentProcess(), (void*)(addr + 0x400000 + 1), &val, 3, 0);
}
void __cdecl writeDwordF1(DWORD addr, DWORD val)
{
	WriteProcessMemory(GetCurrentProcess(), (void*)(addr + 0x400000+1), &val, 3, 0);
}
void __cdecl writeDword(DWORD addr, DWORD val)
{
	WriteProcessMemory(GetCurrentProcess(), (void*)addr, &val, 4, 0);
}
