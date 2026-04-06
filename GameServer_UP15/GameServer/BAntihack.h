#pragma once
#include "DefaultClassInfo.h"
#include "User.h"
#include "Protocol.h"



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



struct MESSAGE_INFO_ANTIHACK
{
	int Index;
	char Message[256];
};
struct DATA_CONFIG
{
	int DebugLog;
	int Enabled;
	int NoticeMess;
	int DetectCount;
	int TypeCheck;
	int BlockSkillDelay;
	void Clear()
	{
		DebugLog = 0;
		Enabled = 0;
		NoticeMess = 0;
		DetectCount = 0;
		TypeCheck = 0;
		BlockSkillDelay = 0;
	}
};
struct DATA_CONFIG_SPEEDMOVE
{
	int DebugLog;
	int Enabled;
	int NoticeMess;
	int DetectCount;
	int GateMove;
	float SpeedNormal;
	float SpeedPet;
	float SpeedWing;
	void Clear()
	{
		DebugLog = 0;
		Enabled = 0;
		NoticeMess = 0;
		DetectCount = 0;
		GateMove = 0;
		SpeedNormal = 0;
		SpeedPet = 0;
		SpeedWing = 0;
	}
};

//===================Check Auto Skill
#pragma pack(push, 1)
struct USESKILL_LOG
{
	PSBMSG_HEAD header; // C3:F3:03
	WORD SkillID;
	float FameSpeed;

};
#pragma pack(pop)
//======================

struct HACKSPEED_DATA
{
	int m_SkillID;
	int m_SkillType;
	int m_HitDetect;
	int m_DelayCountMin;
	int m_DelayMinMs;
	int m_DelayType;
	int m_DelayValue;
	int m_DelayGroup;
	int m_XDmgAI;
};
struct XDAMEHACK_DATA
{
	int Group;
	int MinSpeed;
	int MaxSpeed;
	int MaxCount;
};

class CBAntihack
{
public:
	CBAntihack();
	virtual ~CBAntihack();
	//==
	DATA_CONFIG* HackPlayerEditor;
	void CBAntihack::SendPlayerEditor(int aIndex);
	void CBAntihack::GetResultPlayerEditor(BGUARD_ANS_CHECK* pResult, int aIndex);

	DATA_CONFIG_SPEEDMOVE* HackSpeedMove;
	DATA_CONFIG* HackSpeedCheck;
	DATA_CONFIG* HackCheckInject;

	int RandomSend;
	int GhiLogHack;
	int DelayScan;
	int DelayClear;
	void LoadFileXML(char* FilePath);

	void ViewportProc(int aIndex);
	void CBAntihack::SetUserZeroCache(int aIndex);
	BOOL CBAntihack::BAntihackPacketRecv(BYTE head, BYTE* recvlpMsg, int size, int aIndex, int encrypt, int serial);
	BOOL CBAntihack::CheckAttackBlock(int aIndex);
	bool CheckUserMove(LPOBJ lpObj);
private:
	void CBAntihack::BPModuleDataSend(int Index);
	void CBAntihack::RecvClientModule(RECV_MODULE* pResult, int aIndex);
	//===Mess
	std::map<int, MESSAGE_INFO_ANTIHACK> m_MessageInfoBP;
	char* GetMessage(int index);
	void CBAntihack::ClearDetectCount(int aIndex);

	void CBAntihack::LoadDBAntihack();
	std::map<int, HACKSPEED_DATA> m_HackSpeedCheckDB;
	std::vector<XDAMEHACK_DATA> m_XDameData;
	std::map<int, MODULE_DATA> m_HackCheckInjectDB;
	int CBAntihack::GetCountXDmgInSpeed(LPOBJ lpObj, int Group);
	HACKSPEED_DATA* GetDataHackSpeed(int SkillID, int SkillType);
	void CBAntihack::CalculateSkillFloat(int aIndex);
	BOOL CBAntihack::bpSpeedHackCheck(int aIndex, int bIndex, WORD functionID, WORD mskill);
};

extern CBAntihack gBAntihack;