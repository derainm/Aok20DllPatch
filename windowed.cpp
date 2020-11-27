#include <Windows.h>
#include "Hookbase.h"




void windowedMod()
{
	LoadLibraryA("wndmode.dll");
	BYTE c_6690[] =
	{
	0x66,0x90
	};
	BYTE c_9090[] =
	{
	0x90,0x90,0x90,0x90,0x90,0x90
	};
	writeData(0x41f80A, c_6690, 2);
	writeData(0x48AD1D, c_6690, 2);
	writeData(0x5D95F8, c_6690, 2);
	writeData(0x5DF91B, c_6690, 2);
	writeData(0x4f00de, c_9090, 6);

}