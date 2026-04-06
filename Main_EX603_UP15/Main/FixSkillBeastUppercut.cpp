#include "stdafx.h"
#include "FixSkillBeastUppercut.h"
#include "Util.h"

cFixSkillBeastUppercut FixSkillBeastUppercut;

cFixSkillBeastUppercut::cFixSkillBeastUppercut()
{
}

cFixSkillBeastUppercut::~cFixSkillBeastUppercut()
{
}

void cFixSkillBeastUppercut::Init()
{
	Hook();
}

_declspec(naked) void FixBeastUpperL()
{
	static DWORD jumpOUT = 0x0071AF22;
	_asm {
		jmp jumpOUT;
	}
}

_declspec(naked) void FixBeastUpperR()
{
	static DWORD jumpOUT = 0x0071B233;
	_asm {
		jmp jumpOUT;
	}
}

void cFixSkillBeastUppercut::Hook()
{
	SetCompleteHook(0xE9, 0x0071AE9E, FixBeastUpperL);
	SetCompleteHook(0xE9, 0x0071B1AF, FixBeastUpperR);
}