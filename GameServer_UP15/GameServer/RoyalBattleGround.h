#pragma once
#include "Protocol.h"
#define		RBG_MAX_PLAYER	100

/*
blank			-> wait to event time
open			-> allowed to join
prepare			-> wait to start battle
battle_stage_1	->
battle_stage_2	->
battle_stage_3	->
reward			->
clear			->
*/
enum RBG_STATE
{
	RBG_STATE_BLANK = 0,
	RBG_STATE_OPEN = 1,
	RBG_STATE_PREPARE = 2,
	RBG_STATE_BATTLE_STAGE_1 = 3,
	RBG_STATE_BATTLE_STAGE_2 = 4,
	RBG_STATE_BATTLE_STAGE_3 = 5,
	RBG_STATE_BATTLE_END = 6,
	RBG_STATE_REWARD = 7,
	RBG_STATE_CLEAR = 8,
};

struct ROYAL_BATTLE_GROUND_START_TIME
{
	int Year;
	int Month;
	int Day;
	int DayOfWeek;
	int Hour;
	int Minute;
	int Second;
};

struct ROYAL_BATTLE_GROUND_ITEM
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

struct ROYAL_BATTLE_GROUND_REWARD
{
	short Top;
	short Rate;
	int IDItemBag;
};

struct RBG_Player
{
	void Reset() // OK
	{
		Index = -1;
		Rank = 0;
		Regen = 0;
		Live = 0;
	}
	bool  Live;
	short Index;
	int	  Point;
	int	  Regen;
	int	  Rank;
};

struct RBG_Phase
{
	short	id;
	short	W;
	short	H;
	int		HP;
	float	HPrate;
	short	ItemCnt;
	int		ItemLoop;
	int		Coint;
	int		Type;
};
struct SKILLBLOCK_INFO_SINHTON
{
	int Index;
	int IDSkill;
};
struct PSWMSG_ROYAL_BATTLE_GROUND_PHASE_SEND {
	PSWMSG_HEAD header;
	int		Phase;
	int		Remain;
	int		Map;
	short	Zone[4];
};

struct PSWMSG_ROYAL_BATTLE_GROUND_POINT_SEND {
	PSWMSG_HEAD header;
	int		Alive;
	int		Kill;
	int		LiveCount;
	int		Total;
	int		Top;
};

struct PSWMSG_ROYAL_BATTLE_GROUND_ZONE_SEND {
	PSWMSG_HEAD header;
	float X;
	float Y;
	float W;
	float H;
};

struct PSWMSG_ROYAL_BATTLE_GROUND_KILL_SEND {
	PSWMSG_HEAD header;
	int		ComboKill;
	int		Rank;
	char	Player[11];
	char	Target[11];
};

struct PMSG_ROYAL_BATTLE_GROUND_REQUEST_RECV
{
	PBMSG_HEAD2_Origin h;
	BYTE type;
	int  value;
};


struct BACKUPOBJECTSTRUCT_HEADER
{
	BACKUPOBJECTSTRUCT_HEADER() // OK
	{
		this->CommonStruct = new OBJECTSTRUCT;

		for (int n = 0; n < MAX_OBJECT; n++){ this->ObjectStruct[n] = this->CommonStruct; }
	}

	OBJECTSTRUCT& operator[](int index) // OK
	{
		return (*this->ObjectStruct[index]);
	}

	OBJECTSTRUCT* CommonStruct;
	OBJECTSTRUCT* ObjectStruct[MAX_OBJECT];
};
struct BEVENTDATA_BXH
{
	char szName[11];
	int Kill;
};
class cRoyalBattleGround
{
public:
	cRoyalBattleGround();
	~cRoyalBattleGround();
	void Init();
	void Read(char* configFile);
	void MainProc();
	void CheckSync();
	void SetState(int);
	void BlankProc();
	void OpenProc();
	void PrepareProc();
	void Stage1Proc();
	void Stage2Proc();
	void Stage3Proc();
	void StageEndProc();
	void RewardProc();
	void ClearProc();
	void ClearSection();
	void ChangeUserInfo(int aIndex);
	void ChangeUserInfo();
	void MoveUserPosition();
	bool CheckUserPostion(int aIndex);
	bool CheckUserList(int aIndex);
	void RemoveObject();
	int  GetPoint(int aIndex);
	void SendPointToUser(int aIndex);
	void SendPointToEventUsers();
	void SendPhaseToUser(int aIndex, bool Close = true);
	void SendPhaseToAllUsers();
	void SendPhaseToEventUsers();
	void SendKillToEventUsers(int aIndex, int bIndex);
	void KillProc(int aIndex, int bIndex);
	void AddPlayerPoint(int aIndex, int point);
	void SetPlayerPoint(int aIndex, int point);
	//void RewardProc(int aIndex);
	void MemberRequestJoin(int aIndex);
	bool AddMember(int aIndex);
	bool DelMember(int aIndex);
	bool DelAllMembers();
	int  CountMember();
	bool GetEnabled();
	int  GetState();
	bool IsOpen();
	bool IsPlaying();
	int  GetOpenRemainTime();
	int  GetPlayRemainTime();
	int  GetRemainTime();
	void RecvRequest(BYTE* lpMsg, int aIndex);
	RBG_Phase* GetPhase(int id);
	void MakeZonePhase(int id);
	void SetZone(short X, short Y, short W, short H);
	void MakeDropItem();
	void DangerousZone();
	void ZoneHitUser(int aIndex);
	bool CheckSafeZone(int aIndex);
	bool BackupAddUser(int aIndex);
	OBJECTSTRUCT BackupGetUser(int aIndex);
	bool BackupDelUser(int aIndex);
	bool RollBackCharacterInfo(int aIndex);
	void StartBattle();
	bool CheckPrepareZone(int aIndex);
	void UserMoveOut(int aIndex);
	bool IsOnMapEvent(int aIndex);
	bool UserDieProc(LPOBJ lpObj, LPOBJ lpTarget);
	RBG_Player* GetUser(int aIndex);
	void CalcUserRank();
	bool GetPosRandomFromBo(int* x, int* y);
	bool GetUserRespawnLocation(LPOBJ lpObj, int* gate, int* map, int* x, int* y, int* dir, int* level);
	int  GetTop(int aIndex);
	void EventTeleport(int aIndex, int map, int x, int y);
private:
	bool m_Enable;
	int m_Timer_Open;
	int m_Timer_Prepare;
	int m_Timer_Stage1;
	int m_Timer_Stage2;
	int m_Timer_Stage3;
	int m_Timer_StageEnd;
	int m_State;
	int m_RemainTime;
	int m_TargetTime;
	int m_EndTime;
	int m_TickCount;
	int m_TotalPlayer;
	int m_TotalPlayerJoin;
	int m_Map;
	int m_GateIn;
	int m_GateOut;
	int m_RewardBonus;
	int m_Zone[4];
	int m_PhaseLastDrop;
	int m_PhaseDropCount;
	int m_PhaseDropDelay;
	int m_ZoneHP;
	int m_RegenMax;
	float m_ZoneHPrate;
	DWORD m_TotalReward;
	DWORD m_JoinCost;
	int  m_TypeCoin;
	DWORD m_MaxPlayer;

	RBG_Player		Player[RBG_MAX_PLAYER];
	std::vector<ROYAL_BATTLE_GROUND_START_TIME> m_RBGStartTime;
	std::vector<ROYAL_BATTLE_GROUND_ITEM> m_RBG_Items;
	std::vector<RBG_Phase> m_RBG_Phases;
	std::vector<OBJECTSTRUCT> m_BackupCharacter;
	std::vector<SKILLBLOCK_INFO_SINHTON> m_SinhTonSkillBlock;
	std::map<int, ROYAL_BATTLE_GROUND_REWARD> m_Reward;
	OBJECTSTRUCT_HEADER bObj;
	int mIndexRank[10];
	void SendBXH(int aIndex);
	void ThuongCoin(int State);
};

extern cRoyalBattleGround RoyalBattleGround;