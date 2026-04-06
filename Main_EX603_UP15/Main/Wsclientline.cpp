#include "StdAfx.h"
#include "Wsclientline.h"

CStreamPacketEngine::CStreamPacketEngine(void)
{
	((void(__thiscall*)(BYTE**)) 0x00404B40)(&this->thisa);
}

CStreamPacketEngine::~CStreamPacketEngine(void)
{
}

void CStreamPacketEngine::Init(BYTE byType, BYTE byHeadCode)
{
	((void(__thiscall*)(BYTE**, BYTE, BYTE)) 0x00404B90)(&this->thisa, byType, byHeadCode);
}

void CStreamPacketEngine::Rightshift1(BYTE bits)
{
	((void(__thiscall*)(BYTE**, BYTE)) 0x004050D0)(&this->thisa, bits);
}

void CStreamPacketEngine::Rightshift2(DWORD bits)
{
	((void(__thiscall*)(BYTE**, DWORD)) 0x0040BCA0)(&this->thisa, bits);
}

void CStreamPacketEngine::Rightshift3(INT bits)
{
	((void(__thiscall*)(BYTE**, INT)) 0x00474180)(&this->thisa, bits);
}

void CStreamPacketEngine::AddData(void *pSrc, WORD wSize, BOOL bXor)
{
	((void(__thiscall*)(BYTE**, void *, WORD, BOOL)) 0x00404C10)(&this->thisa, pSrc, wSize, bXor);
}

void CStreamPacketEngine::Send(BOOL bEncrypt, BOOL bForceC4)
{
	((void(__thiscall*)(int, BOOL, BOOL)) 0x00404D70)((int)&this->thisa, bEncrypt, bForceC4);
}