#pragma once
#include <psapi.h>
#pragma comment(lib,"Psapi.lib")
#include <shlwapi.h>
#include <string>
#include "Protocol.h"
#define MAX_FRAME_VALUE		400
#define MAX_LEVEL_VALUE		10
#define MAX_SPEED_LIMIT		100
#define MAX_STAT_LIMIT		1000
enum TypeHack
{
	eHackPlayerEditor,
	eHackSpeedMove,
	eHackSpeedCheck,
	eHackFrameSpeedCheck,
	eHackCheckInject,
};
enum eCheckStatMember
{
	emLevel = 0,
	emLevelPoint = 1,
	emStrength = 2,
	emDexterity = 3,
	emVitality = 4,
	emEnergy = 5,
	emLeadership = 6,
	emAttackSpeed = 7,
	emMagicSpeed = 8,
	emFrameValue = 9,
	emAnimation = 10,
	//====
	emPetSlot = 11,
	emHelmSlot = 12,
	emArmorSlot = 13,
	emPantsSlot = 14,
	emGlovesSlot = 15,
	emBootsSlot = 16,
	emWeaponFirstSlot = 17,
	emWeaponSecondSlot = 18,
	emWingsSlot = 19,
	//====
	emEditGame = 20,
	emMaxCheckVars,
};
#pragma pack(push, 1)
struct BGUARD_REQ_CHECK
{
	PSWMSG_HEAD header;

	short		Level;
	int			LevelPoint;
	int  		Strength;
	int  		Dexterity;
	int  		Vitality;
	int  		Energy;
	int  		Leadership;
	int			AttackSpeed;
	int			MagicSpeed;
	short		CharSetItem[10];
};
#pragma pack(pop)
#pragma pack(push, 1)
struct BGUARD_ANS_DATA
{
	bool		Status;
	int			Value;
};
#pragma pack(pop)
#pragma pack(push, 1)
struct BGUARD_ANS_CHECK
{
	PSBMSG_HEAD header; // C3:F3:03

	BGUARD_ANS_DATA Data[emMaxCheckVars];
};
//====Moudule Inject
struct MODULE_DATA
{
	int Index;
	char NameModule[60];
};

struct PMSG_MODULE_DATA_SEND
{
	PSWMSG_HEAD header;
	int count;
};
struct RECV_MODULE
{
	PSBMSG_HEAD header; // C3:F3:03
	WORD TypeRecv;
	char LogRecv[128];
};
#pragma pack(pop)
#pragma pack(push, 1)
struct USESKILL_LOG
{
	PSBMSG_HEAD header; // C3:F3:03
	WORD SkillID;
	float FameSpeed;

};
#pragma pack(pop)

class CBAntihack
{
public:
	CBAntihack();
	virtual ~CBAntihack();
	void CBAntihack::LoadBB();
	int CBAntihack::GetLargerFrame();
	void CBAntihack::RecvGSInfo(BGUARD_REQ_CHECK* pRequest);
	int BLevelCache;
	void CBAntihack::SendLogUseSkill(WORD mSkillID, float mFameSpeed);
	static int __thiscall SendPacketAttack(unsigned __int16* This, int a2, int a3);
	void CBAntihack::GetModuleInject();
	std::string HackLogSendGS;
	BOOL CBAntihack::CheckMuduleName(char* NameModule);
	std::vector<std::string> mListModuleItem;
	void CBAntihack::RecvMouduleDataInfo(PMSG_MODULE_DATA_SEND* lpMsg);
	int isHackDetect;
private:

};

extern CBAntihack gBAntihack;