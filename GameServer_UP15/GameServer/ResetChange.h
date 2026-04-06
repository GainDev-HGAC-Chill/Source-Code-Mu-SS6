// CustomItem.h: interface for the CCustomItem class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#if (RESETCHANGE == 1)

#define MAX_RESET_CHANGE 5
#include "Protocol.h"

struct RESETCHANGE_REQ
{
	PSBMSG_HEAD h;
	int	numchange;
};

struct RESETCHANGE_INFO
{
	int Index;
	int ReqReset;
	int Coin1;
};

struct PMSG_RESET_CHANGE
{
#pragma pack(1)
	PSBMSG_HEAD h;
	int ReqReset1;
	int RewardWC1;
	int ReqReset2;
	int RewardWC2;
	int ReqReset3;
	int RewardWC3;
	int ReqReset4;
	int RewardWC4;
	int ReqReset5;
	int RewardWC5;
#pragma pack()
};

class CResetChange
{
public:
	CResetChange();
	virtual ~CResetChange();
	void Init();
	void EnvioResetChange(int aIndex);
	void Load(char* path);
	void SetInfo(RESETCHANGE_INFO info);
	RESETCHANGE_INFO* GetInfo(int index);
	void ResetChange(int aIndex, RESETCHANGE_REQ* lpMsg);
public:
	RESETCHANGE_INFO m_CustomResetChangeInfo[MAX_RESET_CHANGE];
};

extern CResetChange gResetChange;

#endif