#pragma once
#include "Object.h"
#include "w_ObjectInfo.h"
#define		MAX_JOINTS 5000

struct JOINT
{
	bool Live;
	int Type;
	int TexType;
	int SubType;
	BYTE RenderType;
	BYTE RenderFace;
	float Scale;
	vec3_t Position;
	vec3_t StartPosition;
	vec3_t Angle;
	vec3_t HeadAngle;
	vec3_t Light;
	OBJECT *Target;
	vec3_t TargetPosition;
	BYTE byOnlyOneRender;
	int NumTails;
	int MaxTails;
	vec3_t Tails[50][4];
	int LifeTime;
	bool Collision;
	float Velocity;
	vec3_t Direction;
	__int16 PKKey;
	WORD Skill;
	BYTE Weapon;
	int MultiUse;
	bool bTileMapping;
	BYTE m_byReverseUV;
	bool m_bCreateTails;
	int TargetIndex[5];
	BYTE m_bySkillSerialNum;
	int m_iChaIndex;
	__int16 m_sTargetIndex;
};

enum
{
	RENDER_TYPE_NONE = 0,
	RENDER_TYPE_ALPHA_BLEND,
	RENDER_TYPE_ALPHA_TEST,
	RENDER_TYPE_ALPHA_BLEND_MINUS,
	RENDER_TYPE_ALPHA_BLEND_OTHER,
};

class cIncreaseEffects
{
public:
	cIncreaseEffects();
	~cIncreaseEffects();
	void Hook();
	DWORD GetAddressJoints();
	JOINT     Joints[MAX_JOINTS];
	void zCreateJoint(int Type, vec3_t Position, vec3_t TargetPosition, vec3_t Angle, int SubType = 0, OBJECT *Target = NULL, float Scale = 10.f, short PK = -1, WORD SkillIndex = 0, WORD SkillSerialNum = 0, int iChaIndex = -1, const float* vColor = NULL, short int sTargetIndex = -1);
private:

};

extern cIncreaseEffects IncreaseEffects;