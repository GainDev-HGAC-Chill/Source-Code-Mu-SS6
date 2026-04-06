#include "stdafx.h"
#if (RESETCHANGE==1)
#include "ResetSystem.h"
#include "Interface.h"
#include "Protect.h"
#include "Defines.h"
#include "Protocol.h"
#include "User.h"
#include "Central.h"
#include "PrintPlayer.h"


CResetChange gResetChange;
// -------------------------------------------------------------------------------

CResetChange::CResetChange()
{

}
// -------------------------------------------------------------------------------

CResetChange::~CResetChange()
{
	// ----
}

void CResetChange::DrawResetChange()
{
	if (!gInterface.Data[eRESETCHANGE].OnShow)
	{
		return;
	}

	pSetCursorFocus = true;
	this->ChangeButtons[0] = 1;
	this->ChangeButtons[1] = 1;
	this->ChangeButtons[2] = 1;
	this->ChangeButtons[3] = 1;
	this->ChangeButtons[4] = 1;

	float MainWidth = 230.0;
	float MainHeight = 300.0;
	float StartY = ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (float)(29.0 / 2);
	//--
	gInterface.Data[eRESETCHANGE].MaxX = StartX + MainWidth;
	gInterface.Data[eRESETCHANGE].MaxY = StartY + MainHeight;

	//gCentral.PrintDropBox(StartX, StartY, MainWidth, MainHeight, 0, 0);
	gCentral.gDrawWindowCustom(StartX, StartY, MainWidth, MainHeight, eRESETCHANGE, "Hệ Thống Đổi Reset");

	//gInterface.DrawFormat(eGold, (int)StartX + 10, (int)StartY + 10, 210, 3, "Change Reset");
	// -- 
	gInterface.DrawFormat(eGold, (int)StartX + 10, (int)StartY + 35, 210, 3, "Thông Tin Của Bạn");

	//		gInterface.DrawFormat(eWhite, (int)StartX + 87, (int)StartY + 55, 40, 1, "Wcoin:");
	//		gInterface.DrawFormat(eGold, (int)StartX + 115, (int)StartY + 55, 40, 1, "%d", Coin1);

	gInterface.DrawFormat(eWhite, (int)StartX + 25, (int)StartY + 55, 50, 1, "WCoinC:");
	gInterface.DrawFormat(eGold, (int)StartX + 55, (int)StartY + 55, 50, 1, "%d", Coin1);

	gInterface.DrawFormat(eWhite, (int)StartX + 152, (int)StartY + 55, 50, 1, "Reset:");
	gInterface.DrawFormat(eGold, (int)StartX + 176, (int)StartY + 55, 50, 1, "%d", ViewReset);
	// --

	pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2), StartY + 75, 200, 1); //-- Divisor

	float CurrentMove;
	int BtCount = -1;
	int BtStart = StartY + 88;

	int ObjectIDs[5] =
	{
		eBOTON1,
		eBOTON2,
		eBOTON3,
		eBOTON4,
		eBOTON5,
	};

	for (int n = 0; n < 5; n++)
	{
		if (this->ChangeButtons[n] == 1)
		{
			BtCount++;
		}
		else
		{
			continue;
		}

		CurrentMove = 0.0;
		if (gInterface.IsWorkZone(ObjectIDs[n]))
		{
			if (gInterface.Data[ObjectIDs[n]].OnClick)
			{
				PlayBuffer(25, 0, 0);
				CurrentMove = 30.5f;
			}
		}
		gInterface.DrawButton(ObjectIDs[n], StartX + (MainWidth / 2) - (108 / 2) + 100, BtStart + (33.0f * BtCount), 0, CurrentMove);
		gInterface.DrawFormat(eWhite, StartX + (MainWidth / 2) - (108 / 2) + 73, BtStart + (33.0f * BtCount) + 6, 108, 3, "Đổi Reset");
	}

	gInterface.DrawFormat(eWhite, StartX + (MainWidth / 2) - (108 / 2) - 50, BtStart + 0.0f + 6, 158, 3, "Đổi %d Reset Lấy %d WcoinC", ReqReset1, RewardWC1);
	gInterface.DrawFormat(eWhite, StartX + (MainWidth / 2) - (108 / 2) - 50, BtStart + 33.0f + 6, 158, 3, "Đổi %d Reset Lấy %d WcoinC", ReqReset2, RewardWC2);
	gInterface.DrawFormat(eWhite, StartX + (MainWidth / 2) - (108 / 2) - 50, BtStart + 66.0f + 6, 158, 3, "Đổi %d Reset Lấy %d WcoinC", ReqReset3, RewardWC3);
	gInterface.DrawFormat(eWhite, StartX + (MainWidth / 2) - (108 / 2) - 50, BtStart + 99.0f + 6, 158, 3, "Đổi %d Reset Lấy %d WcoinC", ReqReset4, RewardWC4);
	gInterface.DrawFormat(eWhite, StartX + (MainWidth / 2) - (108 / 2) - 50, BtStart + 132.0f + 6, 158, 3, "Đổi %d Reset Lấy %d WcoinC", ReqReset5, RewardWC5);

	pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2), StartY + MainHeight - 40, 200, 1); //-- Divisor

	if (gInterface.IsWorkZone(eMenu_CLOSE))
	{
		if (gInterface.Data[eMenu_CLOSE].OnClick)
		{
			PlayBuffer(25, 0, 0);
			gInterface.DrawButtonRender(eMenu_CLOSE, StartX + (MainWidth / 2) - (59 / 2), StartY + MainHeight - 32, 0, 28);
		}
		else
		{
			gInterface.DrawButtonRender(eMenu_CLOSE, StartX + (MainWidth / 2) - (59 / 2), StartY + MainHeight - 32, 0, 0);
		}
	}
	else
	{
		gInterface.DrawButtonRender(eMenu_CLOSE, StartX + (MainWidth / 2) - (59 / 2), StartY + MainHeight - 32, 0, 0);
	}
	gInterface.DrawFormat(eWhite, StartX + (MainWidth / 2) - (59 / 2), StartY + MainHeight - 25, 59, 3, "Close");
}

void CResetChange::ButtonResetChange(DWORD Event)
{
	DWORD Delay = (GetTickCount() - gInterface.Data[eRESETCHANGE].EventTick);


	if (gInterface.Data[eRESETCHANGE].OnShow)
	{
		if (gInterface.ButtonEx(Event, eMenu_CLOSE, false))
		{
			this->CloseResetChange();
			return;
		}

		if (gInterface.ButtonEx(Event, eBOTON1, false))
		{
			this->ResetChange(1);
			gInterface.Data[eRESETCHANGE].OnShow ^= 1;
			return;
		}

		if (gInterface.ButtonEx(Event, eBOTON2, false))
		{
			this->ResetChange(2);
			gInterface.Data[eRESETCHANGE].OnShow ^= 1;
			return;
		}

		if (gInterface.ButtonEx(Event, eBOTON3, false))
		{
			this->ResetChange(3);
			gInterface.Data[eRESETCHANGE].OnShow ^= 1;
			return;
		}

		if (gInterface.ButtonEx(Event, eBOTON4, false))
		{
			this->ResetChange(4);
			gInterface.Data[eRESETCHANGE].OnShow ^= 1;
			return;
		}

		if (gInterface.ButtonEx(Event, eBOTON5, false))
		{
			this->ResetChange(5);
			gInterface.Data[eRESETCHANGE].OnShow ^= 1;
			return;
		}

	}

}

void CResetChange::OpenResetChange()
{

	if ((GetTickCount() - gInterface.Data[eRESETCHANGE].EventTick) > 300)
	{
		gInterface.Data[eRESETCHANGE].EventTick = GetTickCount();

		if (gInterface.Data[eRESETCHANGE].OnShow)
		{
			gInterface.Data[eRESETCHANGE].OnShow = 0;

			return;
		}
		gInterface.Data[eRESETCHANGE].OnShow ^= 1;
	}

}

void CResetChange::CloseResetChange()
{

	if (gInterface.Data[eRESETCHANGE].OnShow == true)
	{
		gInterface.Data[eRESETCHANGE].OnShow = false;
		pSetCursorFocus = false;
		return;
	}

	DWORD CurrentTick = GetTickCount();

	gInterface.Data[eRESETCHANGE].EventTick = GetTickCount();
	gInterface.Data[eRESETCHANGE].OnShow = false;

}

// -------------------------------------------------------------------------------

void CResetChange::ResetChange(int numchange)
{
	RESETCHANGE_REQ pRequest;
	pRequest.h.set(0xF3, 0xD9, sizeof(pRequest));
	pRequest.numchange = numchange;
	DataSend((LPBYTE)&pRequest, pRequest.h.size);
}

void CResetChange::RecibirResetChange(PMSG_RESET_CHANGE * aRecv)
{
	if (aRecv == NULL)
	{
		return;
	}
	// ---
	this->ReqReset1 = aRecv->ReqReset1;
	this->RewardWC1 = aRecv->RewardWC1;
	this->ReqReset2 = aRecv->ReqReset2;
	this->RewardWC2 = aRecv->RewardWC2;
	this->ReqReset3 = aRecv->ReqReset3;
	this->RewardWC3 = aRecv->RewardWC3;
	this->ReqReset4 = aRecv->ReqReset4;
	this->RewardWC4 = aRecv->RewardWC4;
	this->ReqReset5 = aRecv->ReqReset5;
	this->RewardWC5 = aRecv->RewardWC5;
}

#endif