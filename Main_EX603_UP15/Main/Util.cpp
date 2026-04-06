#include "stdafx.h"
#include "Util.h"
#include "../../Util/CCRC32.h"
#include "Protocol.h"
#include "Offset.h"
#include "Import.h"
#include "Defines.h"
BYTE NewAddressData1[240];
BYTE NewAddressData2[240];
BYTE NewAddressData3[6000];

//--
void SetJmp(DWORD offset, DWORD size, LPVOID function)
{
	MemorySet(offset, 0x90, size);
	SetCompleteHook(0xE9, offset, function);
}

void SetByte(DWORD offset, BYTE value) // OK
{
	DWORD OldProtect;

	VirtualProtect((void*)offset, 1, PAGE_EXECUTE_READWRITE, &OldProtect);

	*(BYTE*)(offset) = value;

	VirtualProtect((void*)offset, 1, OldProtect, &OldProtect);
}

void SetWord(DWORD offset, WORD value) // OK
{
	DWORD OldProtect;

	VirtualProtect((void*)offset, 2, PAGE_EXECUTE_READWRITE, &OldProtect);

	*(WORD*)(offset) = value;

	VirtualProtect((void*)offset, 2, OldProtect, &OldProtect);
}

void SetDword(DWORD offset, DWORD value) // OK
{
	DWORD OldProtect;

	VirtualProtect((void*)offset, 4, PAGE_EXECUTE_READWRITE, &OldProtect);

	*(DWORD*)(offset) = value;

	VirtualProtect((void*)offset, 4, OldProtect, &OldProtect);
}

void SetFloat(DWORD offset, float value) // OK
{
	DWORD OldProtect;

	VirtualProtect((void*)offset, 4, PAGE_EXECUTE_READWRITE, &OldProtect);

	*(float*)(offset) = value;

	VirtualProtect((void*)offset, 4, OldProtect, &OldProtect);
}

void SetDouble(DWORD offset, double value) // OK
{
	DWORD OldProtect;

	VirtualProtect((void*)offset, 8, PAGE_EXECUTE_READWRITE, &OldProtect);

	*(double*)(offset) = value;

	VirtualProtect((void*)offset, 8, OldProtect, &OldProtect);
}

void SetCompleteHook(BYTE head, DWORD offset, ...) // OK
{
	DWORD OldProtect;

	VirtualProtect((void*)offset, 5, PAGE_EXECUTE_READWRITE, &OldProtect);

	if (head != 0xFF)
	{
		*(BYTE*)(offset) = head;
	}

	DWORD* function = &offset + 1;

	*(DWORD*)(offset + 1) = (*function) - (offset + 5);

	VirtualProtect((void*)offset, 5, OldProtect, &OldProtect);
}

void MemoryCpy(DWORD offset, void* value, DWORD size) // OK
{
	DWORD OldProtect;

	VirtualProtect((void*)offset, size, PAGE_EXECUTE_READWRITE, &OldProtect);

	memcpy((void*)offset, value, size);

	VirtualProtect((void*)offset, size, OldProtect, &OldProtect);
}

void MemorySet(DWORD offset, DWORD value, DWORD size) // OK
{
	DWORD OldProtect;

	VirtualProtect((void*)offset, size, PAGE_EXECUTE_READWRITE, &OldProtect);

	memset((void*)offset, value, size);

	VirtualProtect((void*)offset, size, OldProtect, &OldProtect);
}

void VirtualizeOffset(DWORD offset, DWORD size) // OK
{
	DWORD OldProtect;

	VirtualProtect((void*)offset, size, PAGE_EXECUTE_READWRITE, &OldProtect);

	DWORD HookAddr = (DWORD)malloc(size + 5);

	memcpy((void*)HookAddr, (void*)offset, size);

	*(BYTE*)(HookAddr + size) = 0xE9;

	*(DWORD*)(HookAddr + size + 1) = (offset + size) - ((HookAddr + size) + 5);

	*(BYTE*)(offset) = 0xE9;

	*(DWORD*)(offset + 1) = HookAddr - (offset + 5);

	memset((void*)(offset + 5), 0x90, (size - 5));

	VirtualProtect((void*)offset, size, OldProtect, &OldProtect);
}

void PacketArgumentEncrypt(char* out_buff, char* in_buff, int size) // OK
{
	BYTE XorTable[3] = { 0xFC, 0xCF, 0xAB };

	for (int n = 0; n < size; n++)
	{
		out_buff[n] = in_buff[n] ^ XorTable[n % 3];
	}
}

char* ConvertModuleFileName(char* name) // OK
{
	static char buff[MAX_PATH] = { 0 };

	for (int n = strlen(name); n > 0; n--)
	{
		if (name[n] == '\\')
		{
			strcpy_s(buff, sizeof(buff), &name[(n + 1)]);
			break;
		}
	}

	return buff;
}

void LoadReferenceAddressTable(HMODULE mod, char* name, DWORD address) // OK
{
	if (IS_INTRESOURCE(name) == 0)
	{
		return;
	}

	HRSRC resource = FindResource(mod, name, "BIN");

	if (resource == 0)
	{
		return;
	}

	if (SizeofResource(mod, resource) < sizeof(REFERENCE_INFO))
	{
		return;
	}

	HGLOBAL data = LoadResource(mod, resource);

	if (data == 0)
	{
		return;
	}

	REFERENCE_INFO* ReferenceInfo = (REFERENCE_INFO*)LockResource(data);

	if (ReferenceInfo == 0)
	{
		FreeResource(data);
		return;
	}

	if (ReferenceInfo->start == ReferenceInfo->end)
	{
		if (SizeofResource(mod, resource) < (sizeof(REFERENCE_INFO)+(ReferenceInfo->count*sizeof(REFERENCE_BASE))))
		{
			return;
		}

		REFERENCE_BASE* ReferenceBase = (REFERENCE_BASE*)((DWORD)ReferenceInfo + sizeof(REFERENCE_INFO));

		for (DWORD n = 0; n < ReferenceInfo->count; n++)
		{
			SetDword(ReferenceBase[n].address, address);
		}
	}
	else
	{
		if (SizeofResource(mod, resource) < (sizeof(REFERENCE_INFO)+(ReferenceInfo->count*sizeof(REFERENCE_DATA))))
		{
			return;
		}

		REFERENCE_DATA* ReferenceData = (REFERENCE_DATA*)((DWORD)ReferenceInfo + sizeof(REFERENCE_INFO));

		for (DWORD n = 0; n < ReferenceInfo->count; n++)
		{
			SetDword(ReferenceData[n].address, (address + ReferenceData[n].value));
		}
	}

	FreeResource(data);
}


void MsgBox(char* message, ...) // OK
{
	char buff[256];

	memset(buff, 0, sizeof(buff));

	va_list arg;
	va_start(arg, message);
	vsprintf_s(buff, message, arg);
	va_end(arg);

	MessageBox(0, buff, "Error", MB_OK | MB_ICONERROR);
}

DWORD WriteMemory2(const LPVOID lpAddress, const LPVOID lpBuf, const UINT uSize)
{
	DWORD dwErrorCode = 0;
	DWORD dwOldProtect = 0;
	// ----
	int iRes = VirtualProtect(lpAddress, uSize, PAGE_EXECUTE_READWRITE, &dwOldProtect);
	// ----
	if (iRes == 0)
	{
		dwErrorCode = GetLastError();
		return dwErrorCode;
	}
	// ----
	memcpy(lpAddress, lpBuf, uSize);
	// ----
	DWORD dwBytes = 0;
	// ----
	iRes = VirtualProtect(lpAddress, uSize, dwOldProtect, &dwBytes);
	// ----
	if (iRes == 0)
	{
		dwErrorCode = GetLastError();
		return dwErrorCode;
	}
	// ----
	return 0x00;
};

DWORD SetOp(const DWORD dwEnterFunction, const LPVOID dwJMPAddress, const BYTE cmd)
{
	BYTE btBuf[5];
	DWORD dwShift = (ULONG_PTR)dwJMPAddress - (ULONG_PTR)dwEnterFunction - 5;
	// ----
	btBuf[0] = cmd;
	memcpy((LPVOID)& btBuf[1], (LPVOID)& dwShift, sizeof(ULONG_PTR));
	// ----
	return WriteMemory2((PVOID)dwEnterFunction, (LPVOID)btBuf, sizeof(btBuf));
};

DWORD SetRange(const DWORD dwAddress, const USHORT wCount, const BYTE btValue)
{
	BYTE * lpBuf = new BYTE[wCount];
	// ----
	memset(lpBuf, btValue, wCount);
	// ----
	return WriteMemory2((PVOID)dwAddress, (LPVOID)lpBuf, wCount);
}

void ErrorMessageBox(char* message, ...) // OK
{
	char buff[256];

	memset(buff, 0, sizeof(buff));

	va_list arg;
	va_start(arg, message);
	vsprintf_s(buff, message, arg);
	va_end(arg);

	MessageBox(0, buff, "Error", MB_OK | MB_ICONERROR);

	ExitProcess(0);
}

bool FileExist(LPCSTR path)
{
	HANDLE file = CreateFile(path, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, 0);

	if (file == INVALID_HANDLE_VALUE)
	{
		CloseHandle(file);
		return 0;
	}

	CloseHandle(file);
	return true;
}

char* GetRewardTextByType(int type)
{
	//(0: Zen, 1: WCoinC, 2: WCoinP, 3: WCoinG, 4: Credits, 5: SuperPoints)

	switch (type)
	{
	case 1:
		return "WCoin(C)";
	case 2:
		return "WCoin(P)";
	case 3:
		return "Goblin Points";
	case 4:
		return "Credits";
	case 5:
		return "SuperPoints";
	default:
		return "Zen";
	}
}

void CG_RequestSend(BYTE head, BYTE subh)
{
	PMSG_REQUEST pMsg;
	pMsg.header.set(head, subh, sizeof(pMsg));
	DataSend((BYTE*)&pMsg, pMsg.header.size);
}

void GetFormat(char* str, char oldval, char newval)
{
	std::string Buff;
	Buff = str;
	std::replace(Buff.begin(), Buff.end(), oldval, newval);
	memcpy(str, Buff.c_str(), Buff.size());
}

short GetSymbolFromVK(WPARAM wParam)
{
	BYTE btKeyState[256];
	HKL hklLayout = GetKeyboardLayout(0);
	WORD Symbol;
	GetKeyboardState(btKeyState);
	if ((ToAsciiEx(wParam, MapVirtualKey(wParam, 0), btKeyState, &Symbol, 0, hklLayout) == 1))
	{
		return Symbol;
	}
	return 0;
}

DWORD GetFileCRC(const char* szFileName)
{
	CCRC32 CRC32;

	DWORD Buffer;

	if (CRC32.FileCRC(szFileName, &Buffer, 1024) == 0)
	{
		return 0;
	}

	return Buffer;
}

char* ParseReducedValue(DWORD Num)
{
	char Text[50];
	if (Num >= 10000000000)
		sprintf(Text, "%ldkkk", Num / 1000000000);
	else if (Num >= 10000000)
		sprintf(Text, "%ldkk", Num / 1000000);
	else if (Num >= 10000)
		sprintf(Text, "%ldk", Num / 1000);
	else
		sprintf(Text, "%ld", Num);

	return strdup(Text);
}

DWORD WriteMemoryT(const LPVOID lpAddress, const LPVOID lpBuf, const UINT uSize)
{
	DWORD dwErrorCode = 0;
	DWORD dwOldProtect = 0;

	int iRes = VirtualProtect(lpAddress, uSize, PAGE_EXECUTE_READWRITE, &dwOldProtect);

	if (iRes == 0)
	{
		dwErrorCode = GetLastError();
		return dwErrorCode;
	}

	memcpy(lpAddress, lpBuf, uSize);

	DWORD dwBytes = 0;

	iRes = VirtualProtect(lpAddress, uSize, dwOldProtect, &dwBytes);

	if (iRes == 0)
	{
		dwErrorCode = GetLastError();
		return dwErrorCode;
	}

	return 0x00;
}

DWORD SendPacked(const LPVOID dwEnterFunction, const LPVOID dwJMPAddress, const BYTE cmd)
{
	BYTE btBuf[5];
	// ----
	btBuf[0] = cmd;
	memcpy((LPVOID)& btBuf[1], (LPVOID)dwJMPAddress, sizeof(ULONG_PTR));
	// ----
	return WriteMemoryT(dwEnterFunction, (LPVOID)btBuf, sizeof(btBuf));
}

DWORD SendPacked(const LPVOID dwEnterFunction, const LPVOID dwJMPAddress, const BYTE cmd, const BYTE cmd2)
{
	BYTE btBuf[6];
	// ----
	btBuf[0] = cmd;
	btBuf[1] = cmd2;
	memcpy((LPVOID)& btBuf[2], (LPVOID)dwJMPAddress, sizeof(ULONG_PTR));
	// ----
	return WriteMemoryT(dwEnterFunction, (LPVOID)btBuf, sizeof(btBuf));
}

DWORD SendPacked(const LPVOID dwEnterFunction, const LPVOID dwJMPAddress, const BYTE cmd, const BYTE cmd2, const BYTE cmd3)
{
	BYTE btBuf[7];
	// ----
	btBuf[0] = cmd;
	btBuf[1] = cmd2;
	btBuf[2] = cmd3;
	memcpy((LPVOID)& btBuf[3], (LPVOID)dwJMPAddress, sizeof(ULONG_PTR));
	// ----
	return WriteMemoryT(dwEnterFunction, (LPVOID)btBuf, sizeof(btBuf));
}

//===Fucn Call 3D Character

#define pBGetItemName					((const char(__cdecl*)(int ItemID, const char * Level, char * Buffer)) 0x005C2430)
char* BGetItemName(int ItemType, int Level)
{
	char ItemNameGet[100];
	memset(ItemNameGet, 0, sizeof(ItemNameGet));
	pBGetItemName(ItemType, (const char*)(GET_ITEMOPT_LEVEL(Level)), (char*)ItemNameGet);
	std::string a(ItemNameGet);
	return strdup(a.c_str());
}


#define GET_ITEMOPT_LEVEL(x)		((x >> 3) & 0xF)
#define pBGetItemName1					((const char(__cdecl*)(int ItemID, const char * Level, char * Buffer)) 0x005C2430)
//-----------------------------------------------------------------------------------------------------------------------------------------------------
char* BGetItemName3(int ItemType, int Level)
{
	char ItemNameGet[100];
	memset(ItemNameGet, 0, sizeof(ItemNameGet));
	pBGetItemName1(ItemType, (const char*)(GET_ITEMOPT_LEVEL(Level)), (char*)ItemNameGet);
	std::string a(ItemNameGet);
	return strdup(a.c_str());
}


char* BNumberFormat(int Number)
{


	if (Number < 0) { return "0"; }

	char OutPut[15];

	if (Number < 1000) {
		sprintf(OutPut, "%d", Number);
		return strdup(OutPut);
	}
	else if (Number < 1000000) {
		int part1 = Number % 1000;
		int part2 = (Number - part1) / 1000;
		sprintf(OutPut, "%d,%03d", part2, part1);
		return strdup(OutPut);
	}
	else if (Number < 1000000000) {
		int part1 = Number % 1000;
		Number = (Number - part1) / 1000;
		int part2 = Number % 1000;
		Number = (Number - part2) / 1000;
		int part3 = Number % 1000;

		sprintf(OutPut, "%d,%03d,%03d", part3, part2, part1);
		return strdup(OutPut);
	}
	else {
		int part1 = Number % 1000;
		Number = (Number - part1) / 1000;
		int part2 = Number % 1000;
		Number = (Number - part2) / 1000;
		int part3 = Number % 1000;
		int part4 = (Number - part3) / 1000;

		sprintf(OutPut, "%d,%03d,%03d,%03d", part4, part3, part2, part1);
		return strdup(OutPut);
	}
	return "0";
}