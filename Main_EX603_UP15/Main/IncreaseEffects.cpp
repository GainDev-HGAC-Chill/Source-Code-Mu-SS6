#include "stdafx.h"
#include "zzzmathlib.h"
#include "IncreaseEffects.h"
#include "Util.h"
#include "Import.h"
#include "Interface.h"

cIncreaseEffects IncreaseEffects;

cIncreaseEffects::cIncreaseEffects()
{
	for (int i = 0; i < MAX_JOINTS; i++)
	{
		this->Joints[i].Live = 0;
	}
	this->Hook();
}

cIncreaseEffects::~cIncreaseEffects()
{
}

DWORD cIncreaseEffects::GetAddressJoints()
{
	return (DWORD)&IncreaseEffects.Joints;
}

void _MoveJoints()
{
	//create new joins effect here
	((void(__cdecl*)())0x00747D00)();
}

void cIncreaseEffects::Hook()
{
	DWORD AddressJoints = this->GetAddressJoints();

	SetDword(0x005F308B + 2, AddressJoints);
	SetDword(0x006F80FF + 2, AddressJoints);
	SetDword(0x0072D1E2 + 2, AddressJoints);
	SetDword(0x00735E8E + 2, AddressJoints);
	SetDword(0x00735F3A + 2, AddressJoints);
	SetDword(0x00735F9A + 2, AddressJoints);
	SetDword(0x00747D2A + 2, AddressJoints);
	SetDword(0x00747D91 + 2, AddressJoints);

	//SetCompleteHook(0xE8, 0x4D959C, _MoveJoints);

	SetDword(0x00747D18 + 3, MAX_JOINTS);
	SetDword(0x0072D1CC + 3, MAX_JOINTS);
	SetDword(0x00735F88 + 3, MAX_JOINTS);
	SetDword(0x00735F28 + 3, MAX_JOINTS);
	SetDword(0x00735E78 + 3, MAX_JOINTS);
	SetDword(0x005F3079 + 3, MAX_JOINTS);
}

int FindCharacterIndex(int i)
{
	return ((int(__cdecl*)(int)) 0x57D9A0)(i);
}

void cIncreaseEffects::zCreateJoint(int Type, vec3_t Position, vec3_t TargetPosition, vec3_t Angle, int SubType, OBJECT *Target, float Scale, short PKKey,
	WORD SkillIndex, WORD SkillSerialNum, int iChaIndex, const float* vPriorColor, short int sTargetindex)
{
	JOINT *o;
	for (int i = 0;; ++i)
	{
		if (i >= MAX_JOINTS)
			return;
		o = &Joints[i];
		if (!o->Live)
		{
			break;
		}
	}
	o->Live = 1;
	o->Type = Type;
	o->TexType = o->Type;
	o->SubType = SubType;
	o->RenderType = 1;
	o->RenderFace = 3;
	o->Collision = 0;
	o->PKKey = PKKey;
	o->Skill = SkillIndex;
	o->Velocity = 0.0;
	o->Target = 0;
	o->m_bCreateTails = 1;
	o->byOnlyOneRender = 0;
	o->bTileMapping = 0;
	o->m_byReverseUV = 0;
	o->m_bySkillSerialNum = SkillSerialNum;
	o->m_sTargetIndex = sTargetindex;
	VectorCopy(Position, o->Position);
	VectorCopy(Angle, o->Angle);
	if (vPriorColor)
	{
		VectorCopy(vPriorColor, o->Light);
	}
	else
	{
		Vector(1.f, 1.f, 1.f, o->Light);
	}
	Vector(0.f, 0.f, 0.f, o->Direction);
	if (Target)
	{
		if (Type != 322 || o->SubType != 2)
		{
			if (Type != 322 || o->SubType != 4 && o->SubType != 9)
			{
				if (Type != 322 || o->SubType != 10 && o->SubType != 11)
				{
					o->Target = Target;
				}
				else
				{
					if (iChaIndex != -1)
					{
						int v139 = FindCharacterIndex(iChaIndex);
						if (v139 != 400)
							o->m_iChaIndex = v139;
					}
					o->Target = Target;
				}
			}
			else
			{
				if (iChaIndex != -1)
					o->m_iChaIndex = iChaIndex;
				o->Target = Target;
			}
		}
		else
		{
			VectorCopy(TargetPosition, o->TargetPosition);
			o->Target = Target;
		}
	}
	else
	{
		VectorCopy(TargetPosition, o->TargetPosition);
	}

	o->NumTails = 0;
	float Matrix[3][4];
	vec3_t p;

	bool bCreateStartTail = true;
	if (Type != 32132 || o->SubType != 8)
	{
		if (Type == 32256)
		{
			bCreateStartTail = 0;
			o->NumTails = -1;
		}
		else if (Type != 32223 || o->SubType != 10 && o->SubType != 11)
		{
			if (Type != 32223 || o->SubType != 14 && o->SubType != 15)
			{
				if (Type != 32223 || o->SubType != 55 && o->SubType != 56)
				{
					if (Type != 32223 || o->SubType != 57)
					{
						if (Type == 32499)
						{
							bCreateStartTail = 0;
							o->NumTails = -1;
						}
					}
					else
					{
						bCreateStartTail = 0;
						o->NumTails = -1;
					}
				}
				else
				{
					bCreateStartTail = 0;
					o->NumTails = -1;
				}
			}
			else
			{
				bCreateStartTail = 0;
				o->NumTails = -1;
			}
		}
		else
		{
			bCreateStartTail = 0;
			o->NumTails = -1;
		}
	}
	else
	{
		bCreateStartTail = 0;
		o->NumTails = -1;
	}
	if (Type == 32230 && (o->SubType == 5 || o->SubType == 6 || o->SubType == 7))
		bCreateStartTail = 0;
	if (Type == 322 && (o->SubType == 5 || o->SubType == 6 || o->SubType == 7))
		bCreateStartTail = 0;
	if (Type == 32236 && o->SubType == 6)
		bCreateStartTail = 0;

	if (bCreateStartTail)
	{
		AngleMatrix(o->Angle, Matrix);
		Vector(-o->Scale*0.5f, 0.f, 0.f, Position);
		VectorRotate(Position, Matrix, p);
		VectorAdd(o->Position, p, o->Tails[0][0]);
		Vector(o->Scale*0.5f, 0.f, 0.f, Position);
		VectorRotate(Position, Matrix, p);
		VectorAdd(o->Position, p, o->Tails[0][1]);
		Vector(0.f, 0.f, -o->Scale*0.5f, Position);
		VectorRotate(Position, Matrix, p);
		VectorAdd(o->Position, p, o->Tails[0][2]);
		Vector(0.f, 0.f, o->Scale*0.5f, Position);
		VectorRotate(Position, Matrix, p);
		VectorAdd(o->Position, p, o->Tails[0][3]);
	}

	switch (Type)
	{
	case 32224:
		o->LifeTime = 12;
		o->Scale = Scale;
		o->MaxTails = 2;
		o->Velocity = 0.f;

		if (o->SubType == 4)
		{
			o->LifeTime = 30;
			Vector((float)(rand() % 64 - 32), -10.f, 0.f, o->TargetPosition);
		}
		else if (o->SubType == 5)
		{
			o->Scale += rand() % 10 - 5;
			o->Velocity = (float)(rand() % 20 + 6);
			o->LifeTime = rand() % 8 + 8;
			o->MaxTails = 8;
		}
		else if (o->SubType == 6)
		{
			o->MaxTails = 4;
		}
		else if (o->SubType == 7)
		{
			o->MaxTails = 4;
		}
		else if (o->SubType == 8)
		{
			o->LifeTime = 17;
			o->MaxTails = 3;
			VectorCopy(TargetPosition, o->TargetPosition);
			o->TargetPosition[2] += 100.f;
		}
		else if (o->SubType == 9)
		{
			o->LifeTime = 90;
			o->MaxTails = 20;
			o->NumTails = 0;
			o->MultiUse = (int)o->Angle[2];
			o->Velocity = 0.f;
			o->Direction[0] = 50.f;
			VectorCopy(o->Target->Position, o->TargetPosition);
			VectorCopy(o->TargetPosition, o->Position);
		}
		else if (o->SubType == 10)
		{
			o->LifeTime = 50;
			o->MaxTails = 20;
			o->NumTails = 0;
			o->MultiUse = (int)o->Angle[2];
			o->Velocity = 0.f;
			o->Direction[0] = 60.f;
			if (o->MultiUse == 225 || o->MultiUse == 405)
			{
				o->Collision = true;
			}
			else
			{
				o->Collision = false;
			}

		}
		else if (o->SubType == 13)
		{
			o->LifeTime = 17;
			o->MaxTails = 10;
			VectorCopy(TargetPosition, o->TargetPosition);
			o->TargetPosition[2] += 200.f;
		}
		else if (o->SubType == 14)
		{
			o->LifeTime = 10;
			o->MaxTails = 10;
			VectorCopy(TargetPosition, o->TargetPosition);
		}
		else if (o->SubType == 15)
		{
			o->LifeTime = 10;
			o->Scale = Scale;
			o->MaxTails = 2;
			o->Velocity = 0.f;
		}
		else if (o->SubType == 16)
		{
			o->LifeTime = 10;
			o->Scale = Scale;
			o->MaxTails = 2;
			o->Velocity = 0.f;
			o->RenderType = RENDER_TYPE_ALPHA_BLEND_MINUS;
		}
		else if (o->SubType == 17)
		{
			o->LifeTime = 17;
			o->MaxTails = 3;
			VectorCopy(TargetPosition, o->TargetPosition);
			o->TargetPosition[2] += 100.f;
		}
		else if (o->SubType == 18)
		{
			o->LifeTime = 80;
			o->MaxTails = 20;
			o->NumTails = 0;
			o->MultiUse = (int)o->Angle[2];
			o->Velocity = 0.f;
			o->Direction[0] = 20.f;
			if (o->MultiUse == 225 || o->MultiUse == 405)
			{
				o->Collision = true;
			}
			else
			{
				o->Collision = false;
			}

			VectorCopy(o->Target->Position, o->TargetPosition);
			VectorCopy(o->TargetPosition, o->Position);
		}
		break;
	}
}