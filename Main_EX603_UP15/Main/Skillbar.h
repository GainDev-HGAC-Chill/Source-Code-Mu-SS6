#pragma once
#include "Interface.h"

#define JCLoadSkill				            ((void(__thiscall*)(int a1, int a5, float a6, float a7, float a8, float a9)) 0x00813DC0)
#define dword_8128AC8						*(DWORD*)0x8128AC8
#define byte_8793384						*(BYTE*)0x8793384
#define byte_8793380						*(BYTE*)0x8793380
#define dword_8128ABC						*(DWORD*)0x8128ABC
#define JCMultiSkillLine					((void(__thiscall*)(int a1, float a5, int a6, int a7, int a8, int a9)) 0x00772EA0)
#define JCTimerSkillBar 		((void(__stdcall*)(int a1, float a2, float a3, float a4, float a5)) 0x00814F30)

class SkillBox
{
public:
	SkillBox();
	~SkillBox();
	void Load();
}; extern SkillBox gSkillBox;
