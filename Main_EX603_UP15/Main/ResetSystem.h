#if (RESETCHANGE==1)
#pragma once
// -------------------------------------------------------------------------------

#include "Protocol.h"
// -------------------------------------------------------------------------------

struct RESETCHANGE_REQ
{
	PSBMSG_HEAD h;
	int	numchange;
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
	~CResetChange();

	void		DrawResetChange();
	void        OpenResetChange();
	void        CloseResetChange();
	void        ButtonResetChange(DWORD Event);
	void RecibirResetChange(PMSG_RESET_CHANGE * aRecv);
	void ResetChange(int numchange);

	DWORD ChangeButtons[5];

private:
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

};
extern CResetChange gResetChange;
#endif