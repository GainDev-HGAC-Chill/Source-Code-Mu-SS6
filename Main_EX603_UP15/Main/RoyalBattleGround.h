#pragma once
#include "Protocol.h"
#include <vector>

#define		RBG_MAX_KILL_LOG	6

typedef void(*PUSHEVENT_CALLBACK_LPVOID)(LPVOID);

struct PSWMSG_ROYAL_BATTLE_GROUND_PHASE_RECV {
	PSWMSG_HEAD header;
	int		Phase;
	int		Remain;
	int		Map;
	short	Zone[4];
};

struct PSWMSG_ROYAL_BATTLE_GROUND_POINT_RECV {
	PSWMSG_HEAD header;
	int		Alive;
	int		Kill;
	int		LiveCount;
	int		Total;
	int		Top;
};

struct PSWMSG_ROYAL_BATTLE_GROUND_ZONE_RECV {
	PSWMSG_HEAD header;
	float X;
	float Y;
	float W;
	float H;
};

struct PMSG_ROYAL_BATTLE_GROUND_REQUEST_SEND
{
	PBMSG_HEAD2 h;
	BYTE type;
	int  value;
};

struct PSWMSG_ROYAL_BATTLE_GROUND_KILL_RECV {
	PSWMSG_HEAD header;
	int		ComboKill;
	int		Rank;
	char	Player[11];
	char	Target[11];
};

struct RBG_KILLS
{
	int		ComboKill;
	int		Rank;
	char	Player[11];
	char	Target[11];
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
	void Draw();
	void DrawJoin();
	void DrawInfo();
	void DrawKill();
	void DrawMap();
	char* GetPhaseName();
	char* GetTimeRemain();
	void PhaseRecv(BYTE*);
	void PointRecv(BYTE*);
	void KillRecv(BYTE*);
	void ZoneRecv(BYTE*);
	void ClearSession();
	void SetRect(float a1, float a2, float a3, float a4);
	void SetZone(float a1, float a2, float a3, float a4);
	bool IsWorkZone(float, float, float, float, bool mode = false);
	bool IsOnWindow();
	bool CheckRect();
	bool GetDrawing() { return this->m_DrawingJoin; }
	void SetDrawing(bool a1) { this->m_DrawingJoin = a1; }
	void ToggleDrawing() { this->m_DrawingJoin = !this->m_DrawingJoin; }
	void DrawButton(int IMGcode, float x, float y, float w, float h, float a6, float a7, PUSHEVENT_CALLBACK_LPVOID pCallbackFunc);
	void DrawButton(int IMGcode, float x, float y, float w, float h, float a6, float a7, PUSHEVENT_CALLBACK_LPVOID pCallbackFunc, float uw, float uh);
	static void JoinAction(LPVOID pClass);
	void SendRequest(BYTE type, int value);
	GLvoid GetDrawCircle(int ID, float X, float Y, float W, float CurrenX, float CurrenY, float SetScale, int ScaleSize, int ScalePosicion, float Alpha);
	void DrawBXH();
	float x;
	float y;
	bool drawmap;
	float w;
	float h;
	float zoneX;
	float zoneY;
	float zoneW;
	float zoneH;
	bool m_DrawingJoin;
	int m_State;
	int m_RemainTime;
	int m_Alive;
	int m_Total;
	int m_Top;
	int m_Kill;
	int m_LiveCount;
	int m_TickCount;
	int m_KillTickCount;
	int m_MapEvent;
	int SinhTonBXHC;
	std::vector<RBG_KILLS> m_RBGKillLog;
	BEVENTDATA_BXH m_SinhTonBXH[10];
	void cRoyalBattleGround::BEventSinhTon_BXC(PMSG_NEW_HEALTH_BAR_RECV* lpMsg);
};

#define TERRAIN_SCALE     100.f
#define TERRAIN_SIZE      256
#define TERRAIN_SIZE_MASK 255

inline int TERRAIN_INDEX(int x, int y)
{
	return (y)*TERRAIN_SIZE + (x);
}

inline int BTERRAIN_INDEX(int x, int y)
{
	return (256 - x)*TERRAIN_SIZE + (y);
}

inline int BTERRAIN_INDEX_REPEAT(int x, int y)
{
	return ((256 - x)&TERRAIN_SIZE_MASK)*TERRAIN_SIZE + (y&TERRAIN_SIZE_MASK);
}

extern cRoyalBattleGround RoyalBattleGround;