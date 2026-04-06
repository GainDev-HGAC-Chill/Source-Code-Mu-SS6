#pragma once

#include "Protocol.h"

#define MAX_RANK 11

static char* Message_BXH[] =
{
	"Top All",
	"Top Master",
	"Top Săn Boss",
	"Top Huyết Lâu",
	"Top Quảng Trường Qủy",
	"Top Hỗn Nguyên Lâu",
	"Top Danh Hiệu",
	"Top Quân Hàm",
	"Top Tu Luyện",
	"Top Hồn Hoàn",
	"Top Point",
};

struct PMSG_CUSTOM_RANKING_RECV
{
	PSWMSG_HEAD h;
	int index;
	char rankname[60];
	char col1[20];
	char col2[20];
	char col3[20];
	int count;
};

struct PMSG_CUSTOM_RANKING_COUNT_RECV
{
	PSBMSG_HEAD header; // C1:BF:51
	int count;
	int CustomRankingSwitch;
};

struct PMSG_CUSTOM_RANKING_COUNT_SEND
{
	PSBMSG_HEAD header; // C1:BF:51
};

struct PMSG_CUSTOM_RANKING_SEND
{
	PSBMSG_HEAD header; // C1:BF:51
	BYTE type;
};

struct CUSTOM_RANKING_DATA
{
	char Value1[20];
	char Value2[30];
	char Value3[30];
};

class CCustomRanking
{
public:
	CCustomRanking();
	void ClearCustomRanking();
	void GCReqRanking(PMSG_CUSTOM_RANKING_RECV* lpMsg);
	void GCReqRankingCount(PMSG_CUSTOM_RANKING_COUNT_RECV* lpMsg);
	void DrawRankPanelWindow();
	bool EventRankingNext(DWORD Event);
	bool EventRankingBack(DWORD Event);
	int RankingType;
	int RankEnable;
	int RankingCount;
	bool EventVipWindow_Close(DWORD Event);
	void OpenWindow();
	void ImageLoad();
	void BinObeject();
	void EventSelect(DWORD Event);
	// tvt
#if(DH_TOP_CT)
	int GetTopChienTruong(char* name);
	void GetTopChienTruong2();
#endif
	void getTatMo();
	DWORD OpenTestDelay;

private:
	char rankname[60];
	char col1[20];
	char col2[20];
	char col3[20];
	int count;
	CUSTOM_RANKING_DATA gCustomRanking[MAX_RANK];
	int RankLoad;
	int CustomRankingSwitch;
	// tvt
	char top1chientruong[20];

};
extern CCustomRanking gCustomRanking;



