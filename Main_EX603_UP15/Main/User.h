#pragma once
#include "Object.h"
#include "Protocol.h"
#include "Defines.h"

#if(B_HON_HOAN)
#define CSParts2D				((float *(__thiscall*)(float * thisa, int a4, int a5, char a6, float a7, float a8, float a9, float a10, float a11, float a12)) 0x004EFFF0)
#define Operator_new			((float *(__cdecl*)(unsigned int a4)) 0x009D00C5)
#endif

#pragma pack(push, 1)
struct PMSG_TARGETDATA_REQ
{
	PSWMSG_HEAD header;
	int			aIndex;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct PMSG_TARGETDATA_ANS
{
	PSWMSG_HEAD header;
	int aIndex;
    bool isMonster;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct PMSG_TARGET_MONSTER_DATA : PMSG_TARGETDATA_ANS
{
    int Life;
    int MaxLife;
    short Level;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct PMSG_TARGET_PLAYER_DATA : PMSG_TARGET_MONSTER_DATA
{
    int SD;
    int MaxSD;
    short Reset;
	short RankTitle;
	short Long;
};
#pragma pack(pop)

struct CUSTOM_LOGO
{
	int Active;
	int	X;
	int	Y;
};
struct TINH_NANG_REQ
{
	PSBMSG_HEAD h;
	int			Number;
};

class User
{
public:
	int CoordenadaX;
	int CoordenadaY;
	int getLevel;
	int getReset;
	char getName[11];
	//-- post item
	int				PostItemID;
	int				PostItemLV;
	int				PostItemExc;
	int				PostItemAcc;
	int				PostItemHarmony;
	int				PostItem380;
	char*			PostItemSocket;
	int				PostItemX;
	int				PostItemY;
	int				GetPet;
	//--
	void			Load();
	static void ChangeCharInfo(LPVOID This);
	void			Refresh();	
	bool			GetTarget();
	void			ToggleAuto();
	void			ToggleAutoTron();
	lpCharObj		lpPlayer;
	lpViewObj		lpViewPlayer;
	lpViewObj		lpViewTarget;
	BYTE			m_TargetType;	//1 - npc, 2 - attack
	int				m_MapNumber;
	int				m_CursorX;
	int				MagickAttack;
	int				m_CursorY;
	DWORD			m_TargetUpdateTick;
	int DanhHieu;
	int QuanHam;
	int TuLuyen;

	int SurvivorKill;
	int SurvivorDie;
	int SurvivorTotal;


#if(DANH_HIEU_NEW == 1)
	int DANH_HIEU_WCOINC;
	int DANH_HIEU;
#endif

#if(QUAN_HAM_NEW == 1)
	int QUAN_HAM_WCOINC;
	int QUAN_HAM;
#endif

#if(TU_LUYEN_NEW == 1)
	int TU_LUYEN_WCOINC;
	//4-04-2022
	int TU_LUYEN;

#endif

	bool InSafeZone;
	static void	AllInOne();
	//--
	void DrawHP();
	void DrawRank();
	void SetTargetData(PMSG_TARGETDATA_ANS * lpMsg);
	int GetActiveSkill();
	static void	SetEventEffect(int PreviewStruct);
	BOOL        is_auto;
	BOOL        is_autotron;
	CUSTOM_LOGO m_Logo[400];

	//Auto Sendmove
	DWORD		IsSendMove;
	DWORD			MoveToX;
	DWORD			MoveToY;
	BYTE		KhongDiDuoc;
	//--
#if(B_HON_HOAN)
	void      CBRenderCharacter(DWORD ObjectPointer, int Effect, float SizeX, float SizeY, vec3_t Color, int Type = 0);
#endif

#if(FLAG_SKIN)
	static bool TestFlag(ObjectPreview* pChar);
	static bool CreateManyFlag(ObjectPreview* pChar);
	static void __cdecl HoolCreateManyFlay(ObjectPreview* pChar);
#endif

};
extern User gObjUser;