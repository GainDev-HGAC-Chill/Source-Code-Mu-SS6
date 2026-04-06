#pragma once


#include "User.h"
#include "Protocol.h"
#include "OfflineMode.h"

#define MAX_BATTLEROYALE_USER 100

enum eRoyalState
{
	ROYAL_STATE_BLANK = 0,
	ROYAL_STATE_EMPTY = 1,
	ROYAL_STATE_STAND = 2,
	ROYAL_STATE_START = 3,
	ROYAL_STATE_CLEAN = 4,
};


struct BATTLEROYALE_EVENT_START_TIME
{
	int Year;
	int Month;
	int Day;
	int DayOfWeek;
	int Hour;
	int Minute;
	int Second;
};

struct BATTLEROYALE_EVENT_USER
{
	void Reset() // OK
	{
		this->Index = -1;
		this->Available = false;
		this->Kills = 0;
		this->Deaths = 0;
		this->Rank = 0;
	}

	int Index;
	bool Available;
	int Kills;
	int Deaths;
	int Rank;
};

struct BATTLEROYALE_TIME
{
	int Year;
	int Month;
	int Day;
	int DayOfWeek;
	int Hour;
	int Minute;
	int Second;
};

struct MESSAGE_INFO_ROYAL
{
	int Index;
	char Message[256];
};

struct PMSG_COUNTLIST_ROYAL
{
	PSWMSG_HEAD header;
	int Count;
	BYTE OpenBXHWindow;
};

struct BATTLEROYALE_BXH
{
	char Name[11];
	int Kill;
	int Team;
};

struct BATTLEROYALE_ITEM
{
	short Index;
	short Level;
	short Skill;
	short Luck;
	short Opt;
	short Exc;
	short Anc;
	short Socket[5];
	short SocketBonus;
};


class CBattleRoyale
{
public:
	CBattleRoyale();
	virtual ~CBattleRoyale();
	void Init();
	void Clear();
	void Load(char * FilePath);
	void MainProc();
	void ProcState_BLANK();
	void ProcState_EMPTY();
	void ProcState_STAND();
	void ProcState_START();
	void ProcState_CLEAN();
	void SetState(int state);
	void SetState_BLANK();
	void SetState_EMPTY();
	void SetState_STAND();
	void SetState_START();
	void SetState_CLEAN();
	void CheckSync();
	int GetState();
	bool Dialog(LPOBJ lpObj, LPOBJ lpNpc);
	bool CheckEnterEnabled(LPOBJ lpObj);
	bool CheckReqItems(LPOBJ lpObj);
	int GetEnterEnabled();
	int GetEnteredUserCount();
	bool CheckEnteredUser(int aIndex);
	bool CheckPlayerTarget(LPOBJ lpObj);
	bool CheckPlayerJoined(LPOBJ lpObj, LPOBJ lpTarget);
	bool gObjGetRelationShip(LPOBJ lpObj, LPOBJ lpTarget);

	bool AddUser(int aIndex);
	bool DelUser(int aIndex);
	BATTLEROYALE_EVENT_USER* GetUser(int aIndex);
	void CleanUser();
	void ClearUser();
	void CheckUser();
	int GetUserCount();
	bool GetUserRespawnLocation(LPOBJ lpObj, int* gate, int* map, int* x, int* y, int* dir, int* level);
	int ReturnMaxReset();
	void UserDieProc(LPOBJ lpObj, LPOBJ lpTarget);
	void NoticeSendToAll(int type, char* message, ...);
	void StartTM();
	void SetNPC();


	int TotalPlayer;
	int m_RemainTime;
	int m_State;
	int m_EventTime;
	int m_BattleRoyaleEnable;
	int m_BattleRoyaleMinUsers;
	int m_BattleRoyaleMaxUsers;
	int m_Point;
	int m_MaxDie;
	int m_BattleRoyaleNPC;
	int m_BattleRoyaleNPCMap;
	int m_BattleRoyaleNPCX;
	int m_BattleRoyaleNPCY;
	int m_BattleRoyaleNPCDir;
	void CGOpenWindowNPC(XULY_CGPACKET2* aRecv, int aIndex);
	void SendTimeEventAll(int time, int State);
	void CalcUserRank();
	void SendBXHVeClient();
	int EventMap;
private:


	//	int m_State;
	//int m_RemainTime;
	int m_StandTime;
	int m_CloseTime;
	int m_TickCount;
	int m_WarningTime;
	//int m_EventTime;
	int EnterEnabled;
	int AlarmMinSave;
	int AlarmMinLeft;
	int TargetTime;
	void ClearConfigCache();
	;



	int WaitingGate;
	int EventGate;
	int SetSkin;
	//=== Yeu Cau
	int ReqZen;
	int ReqWC;
	int ReqWP;
	int ReqGP;
	int ReqItemIndex;
	int ReqItemLevel;
	int ReqItemCount;
	int MinLevel;
	int MaxLevel;
	int MinReset;
	int MaxReset;
	int MinMasterReset;
	int MaxMasterReset;

	int BonusKill[3];
	int ItemBag;

	int Coin1[3];
	int Coin2[3];
	int Coin3[3];
	int Bag[3];
	int mIndexRank[10];
	int S_SetZone[4];
	int DelayDrop;
	int DropCount;

	int m_PhaseLastDrop;
	int m_PhaseDropCount;
	int m_PhaseDropDelay;
	int m_Zone[4];
	void SetZone(short X, short Y, short W, short H);
	std::vector<OBJECTSTRUCT> m_BackupCharacterBattleRoyale;
	std::vector<BATTLEROYALE_ITEM> m_BattleRoyale_Items;
	bool BackupAddUser(int aIndex);
	bool BackupDelUser(int aIndex);
	void ChangeUserInfo(int aIndex);
	void ChangeUserInfo();
	bool RollBackCharacterInfo(int aIndex);
	OBJECTSTRUCT BackupGetUser(int aIndex);
	void MakeDropItem();

	BATTLEROYALE_EVENT_USER User[MAX_BATTLEROYALE_USER];
	std::vector<BATTLEROYALE_TIME> m_BattleRoyaleStartTime;
	//===Mess
	std::map<int, MESSAGE_INFO_ROYAL> m_MessageInfoBP;
	char* GetMessage(int index);
};
extern CBattleRoyale gBattleRoyale;
