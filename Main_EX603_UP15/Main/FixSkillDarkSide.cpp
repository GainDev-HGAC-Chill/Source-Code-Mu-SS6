#include "stdafx.h"
#include "FixSkillDarkSide.h"
#include "Util.h"

cFixDarkSide FixDarkSide;

cFixDarkSide::cFixDarkSide()
{
	Hook();
}

cFixDarkSide::~cFixDarkSide()
{
}

_declspec(naked) void FakeReceiveStraightAttack()
{
	static DWORD jumpBACK = 0x00663567;
	_asm {
		mov		dword ptr[ebp - 0x18], eax;
		cmp		dword ptr[ebp - 0x18], 0x190;
		je		falseCase;
		jmp		jumpBACK;
	falseCase:
		mov		eax, dword ptr[ebp - 0x10];
		mov		dword ptr[ebp - 0x18], eax;
		jmp		jumpBACK;
	}
}

void cFixDarkSide::Hook()
{
	MemorySet(0x0066355B, 0x90, 0x0C);
	SetCompleteHook(0xE9, 0x0066355B, FakeReceiveStraightAttack);
	//0066367F
}