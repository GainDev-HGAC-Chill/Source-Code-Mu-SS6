// CustomGreatPK.h: interface for the CCustomGreatPK class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#include "DefaultClassInfo.h"
#include "Protocol.h"
#include "User.h"

#define MAX_CUSTOM_GREATPK 30
#define MAX_CUSTOM_GREATPK_USER 100
#define CacheTop 15
enum eCustomGreatPKState
{
	CUSTOM_GREATPK_STATE_BLANK = 0,
	CUSTOM_GREATPK_STATE_EMPTY = 1,
	CUSTOM_GREATPK_STATE_STAND = 2,
	CUSTOM_GREATPK_STATE_START = 3,
	CUSTOM_GREATPK_STATE_CLEAN = 4,
};

struct CUSTOM_GREATPK_START_TIME
{
	int Year;
	int Month;
	int Day;
	int DayOfWeek;
	int Hour;
	int Minute;
	int Second;
};

struct CUSTOM_GREATPK_USER
{
	void Reset() // OK
	{
		this->Index = -1;
		this->Score = 0;
		this->Rank = 0;
		this->UserKillCount = 0;
		this->UserKillStreak = 0;
		this->UserDeathCount = 0;
		this->UserDeathStreak = 0;
	}

	int Index;
	int Score;
	int Rank;
	int UserKillCount;
	int UserKillStreak;
	int UserDeathCount;
	int UserDeathStreak;
};

struct CUSTOM_GREATPK_RULE_INFO
{
	char Name[32];
	int AlarmTime;
	int StandTime;
	int EventTime;
	int CloseTime;
	int StartGate;
	int FinalGate;
	int MinUser;
	int MaxUser;
	int MaxDeath;
	int MinLevel;
	int MaxLevel;
	int MinMasterLevel;
	int MaxMasterLevel;
	int MinReset;
	int MaxReset;
	int MinMasterReset;
	int MaxMasterReset;
	int RequireClass[MAX_CLASS];
	int EventItemBag[5];
	int WC[5];
	//==Check Item
	int EventItemID;
	int EventItemCount;
	int mWC;

};

struct CUSTOM_GREATPK_INFO
{
	int Index;
	int State;
	int RemainTime;
	int TargetTime;
	int TickCount;
	int EnterEnabled;
	int AlarmMinSave;
	int AlarmMinLeft;
	CUSTOM_GREATPK_RULE_INFO RuleInfo;
	CUSTOM_GREATPK_USER User[MAX_CUSTOM_GREATPK_USER];
	std::vector<CUSTOM_GREATPK_START_TIME> StartTime;
};

struct MESSAGE_INFO_GREATPK
{
	int Index;
	char Message[256];
};
#pragma pack(push, 1)
struct GREATPKEVENT_INFO
{
	PSBMSG_HEAD	 header;
	WORD		Rank;
	WORD		Score;
	DWORD		Time;
	BYTE		State;
};
#pragma pack(pop)
struct GREATPKEVENT_BXH
{
	int Rank;
	int Score;
	char Name[11];
};
#pragma pack(push, 1)
struct RECVGREATPKEVENT_BXH
{
	PSWMSG_HEAD header;
	int Count;
	int Type;
};
#pragma pack(pop)

class CCustomGreatPK
{
public:
	CCustomGreatPK();
	virtual ~CCustomGreatPK();
	void Init();
	void ReadCustomGreatPKInfo(char* section, char* path);
	void Load(char* path);
	void MainProc();
	void ProcState_BLANK(CUSTOM_GREATPK_INFO* lpInfo);
	void ProcState_EMPTY(CUSTOM_GREATPK_INFO* lpInfo);
	void ProcState_STAND(CUSTOM_GREATPK_INFO* lpInfo);
	void ProcState_START(CUSTOM_GREATPK_INFO* lpInfo);
	void ProcState_CLEAN(CUSTOM_GREATPK_INFO* lpInfo);
	void SetState(CUSTOM_GREATPK_INFO* lpInfo, int state);
	void SetState_BLANK(CUSTOM_GREATPK_INFO* lpInfo);
	void SetState_EMPTY(CUSTOM_GREATPK_INFO* lpInfo);
	void SetState_STAND(CUSTOM_GREATPK_INFO* lpInfo);
	void SetState_START(CUSTOM_GREATPK_INFO* lpInfo);
	void SetState_CLEAN(CUSTOM_GREATPK_INFO* lpInfo);
	void CheckSync(CUSTOM_GREATPK_INFO* lpInfo);
	int GetState(int index);
	int GetRemainTime(int index);
	int GetEnterEnabled(int index);
	int GetEnteredUserCount(int index);
	bool CheckEnteredUser(int index, int aIndex);
	bool CheckEnterEnabled(LPOBJ lpObj, int gate);
	bool CheckPlayerJoined(LPOBJ lpObj, LPOBJ lpTarget);
	bool CheckPlayerTarget(LPOBJ lpObj, LPOBJ lpTarget);
	bool AddUser(CUSTOM_GREATPK_INFO* lpInfo, int aIndex);
	bool DelUser(CUSTOM_GREATPK_INFO* lpInfo, int aIndex);
	CUSTOM_GREATPK_USER* GetUser(CUSTOM_GREATPK_INFO* lpInfo, int aIndex);
	void CleanUser(CUSTOM_GREATPK_INFO* lpInfo);
	void ClearUser(CUSTOM_GREATPK_INFO* lpInfo);
	void CheckUser(CUSTOM_GREATPK_INFO* lpInfo);
	int GetUserCount(CUSTOM_GREATPK_INFO* lpInfo);
	void CalcUserRank(CUSTOM_GREATPK_INFO* lpInfo);
	bool GetUserRespawnLocation(LPOBJ lpObj, int* gate, int* map, int* x, int* y, int* dir, int* level);
	bool UserDieProc(LPOBJ lpObj, LPOBJ lpTarget);
	void NoticeSendToAll(CUSTOM_GREATPK_INFO* lpInfo, int type, char* message, ...);
	void DataSendToAll(CUSTOM_GREATPK_INFO* lpInfo, BYTE* lpMsg, int size);
	void StartCustomGreatPK(int index);
	char* GetArenaName(int index);
	bool CheckReqItems(int index, LPOBJ lpObj);
	int MapEvent[MAX_CUSTOM_GREATPK];
	int IndexEventHienTai;
	void SendUserInfoEvent(CUSTOM_GREATPK_INFO* lpInfo);
	//===Mess
	std::map<int, MESSAGE_INFO_GREATPK> m_MessageInfoBP;
	char* GetMessage(int index);
	void SendBXHInfo(int aIndex);
	int mIndexRank[CacheTop];
public:
	int SoLuotChet;
	int m_CustomGreatPKSwitch;
	int m_CustomGreatPKVictimScoreDecrease;
	int m_CustomGreatPKKillerScoreIncrease;
	CUSTOM_GREATPK_INFO m_CustomGreatPKInfo[MAX_CUSTOM_GREATPK];
};

extern CCustomGreatPK gCustomGreatPK;
