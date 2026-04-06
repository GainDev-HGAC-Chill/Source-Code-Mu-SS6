#include "stdafx.h"
#include "CustomRanking.h"
#include "Defines.h"
#include "HealthBar.h"
#include "Interface.h"
#include "Util.h"
#include "Object.h"
#include "Import.h"
#include "Central.h"
#include "WindowsStruct.h"
#include "CustomFont.h"
#include "GLFont.h"
#include "Config.h"

CCustomRanking::CCustomRanking()
{
}

CCustomRanking gCustomRanking;

void CCustomRanking::ImageLoad()
{
	pLoadImage("Custom\\Interface\\BXH.tga", 56038, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\top1.tga", 56039, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\top2.tga", 56040, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\top3.tga", 56041, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\top4.tga", 56043, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\btn_arrows.tga", 56042, 0x2601, 0x2901, 1, 0);

}

void CCustomRanking::BinObeject()
{
	gInterface.BindObject(eRanking_MAIN, 56038, 400, 400, -1, -1);
	gInterface.BindObject(eRanking_Top1, 56039, 380, 22, -1, -1);
	gInterface.BindObject(eRanking_Top2, 56040, 380, 22, -1, -1);
	gInterface.BindObject(eRanking_Top3, 56041, 380, 22, -1, -1);
	gInterface.BindObject(eRanking_Top4, 56043, 380, 22, -1, -1);
	gInterface.BindObject(eRanking_Select, 31461, 15, 15, -1, -1);
	gInterface.BindObject(eRanking_BXH1, 31461, 108, 30.5f, -1, -1);
	gInterface.BindObject(eRanking_BXH2, 31461, 108, 30.5f, -1, -1);
	gInterface.BindObject(eRanking_BXH3, 31461, 108, 30.5f, -1, -1);
	gInterface.BindObject(eRanking_BXH4, 31461, 108, 30.5f, -1, -1);
	gInterface.BindObject(eRanking_BXH5, 31461, 108, 30.5f, -1, -1);
	gInterface.BindObject(eRanking_BXH6, 31461, 108, 30.5f, -1, -1);
	gInterface.BindObject(eRanking_BXH7, 31461, 108, 30.5f, -1, -1);
	gInterface.BindObject(eRanking_BXH8, 31461, 108, 30.5f, -1, -1);
	gInterface.BindObject(eRanking_BXH9, 31461, 108, 30.5f, -1, -1);
	gInterface.BindObject(eRanking_BXH10, 31461, 108, 30.5f, -1, -1);
	gInterface.BindObject(eRanking_BXH11, 31461, 108, 30.5f, -1, -1);
	gInterface.BindObject(eRanking_BXH12, 31461, 108, 30.5f, -1, -1);
	gInterface.BindObject(eRanking_BXH13, 31461, 108, 30.5f, -1, -1);
	gInterface.BindObject(eRanking_BXH14, 31461, 108, 30.5f, -1, -1);
	gInterface.BindObject(eRanking_BXH15, 31461, 108, 30.5f, -1, -1);
	gInterface.BindObject(eRanking_CLOSE, 0x7EC5, 36, 29, -1, -1);
}

void CCustomRanking::ClearCustomRanking() // OK
{
	for (int n = 0; n < MAX_RANK; n++)
	{
		memset(gCustomRanking[n].Value1, 0, sizeof(gCustomRanking[n].Value1));
		memset(gCustomRanking[n].Value2, 0, sizeof(gCustomRanking[n].Value2));
		memset(gCustomRanking[n].Value3, 0, sizeof(gCustomRanking[n].Value3));
	}
	this->RankEnable = 0;
}

void CCustomRanking::GCReqRanking(PMSG_CUSTOM_RANKING_RECV* lpMsg) // OK
{
	memcpy(this->rankname, lpMsg->rankname, sizeof(this->rankname));
	memcpy(this->col1, lpMsg->col1, sizeof(this->col1));
	memcpy(this->col2, lpMsg->col2, sizeof(this->col2));
	memcpy(this->col3, lpMsg->col3, sizeof(this->col3));
	this->RankEnable = 1;

	this->count = lpMsg->count;

	for (int n = 0; n < lpMsg->count; n++)
	{
		CUSTOM_RANKING_DATA* lpInfo = (CUSTOM_RANKING_DATA*)(((BYTE*)lpMsg) + sizeof(PMSG_CUSTOM_RANKING_RECV) + (sizeof(CUSTOM_RANKING_DATA)*n));

		memcpy(gCustomRanking[n].Value1, lpInfo->Value1, sizeof(gCustomRanking[n].Value1));
		memcpy(gCustomRanking[n].Value2, lpInfo->Value2, sizeof(gCustomRanking[n].Value2));
		memcpy(gCustomRanking[n].Value3, lpInfo->Value3, sizeof(gCustomRanking[n].Value3));
	}
}

void CCustomRanking::GCReqRankingCount(PMSG_CUSTOM_RANKING_COUNT_RECV* lpMsg) // OK
{
	this->RankingCount = (lpMsg->count > 0) ? lpMsg->count : 0;
	this->CustomRankingSwitch = lpMsg->CustomRankingSwitch;

	if (this->CustomRankingSwitch == 1)
	{
		this->OpenWindow();
	}
}

bool showSelect = false;
void CCustomRanking::DrawRankPanelWindow()
{
	if (!gInterface.Data[eRankPANEL_MAIN].OnShow)
	{
		return;
	}

	float MainWidth = 400.0;
	float MainHeight = 400.0;
	float StartBody = ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
	float StartY = ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (float)(29.0 / 2);
	//--

	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	pSetCursorFocus = true;		// nếu chuột trong khu vực bảng shop thì ko click di chuyển nv

	DWORD Color = eGray100;

	gInterface.DrawGUI(eRanking_MAIN, StartX, StartY + (float)2.0);

	gInterface.DrawFormat(eGold, (int)StartX + 100, (int)StartBody + 30, 210, 3, "%s", this->rankname);

	if (this->count > 0)
		gInterface.DrawGUI(eRanking_Top1, StartX + 10, StartY + 85);
	if (this->count > 1)
		gInterface.DrawGUI(eRanking_Top2, StartX + 10, StartY + 106);
	if (this->count > 2)
		gInterface.DrawGUI(eRanking_Top3, StartX + 10, StartY + 127);

	if (this->RankEnable == 1)
	{
		gInterface.DrawFormat(eWhite, StartX + 25, StartBody + 65, 110, 1, "Top");

		gInterface.DrawFormat(eWhite, StartX + 60, StartBody + 65, 110, 1, "%s", this->col1);

		gInterface.DrawFormat(eWhite, StartX + 140, StartBody + 65, 110, 1, "%s", this->col2);

		gInterface.DrawFormat(eWhite, StartX + 250, StartBody + 65, 110, 1, "%s", this->col3);

		char* name = (char*)(oUserPreviewStruct + 0x38);

		for (int i = 0; i < this->count; i++)
		{
			Color = eWhite;

			if (i>2)
			{
				gInterface.DrawFormat(Color, StartX + 20, StartBody + 95 + (20 * i), 52, 2, "Top %d", (i + 1));
			}
			else
			{

				Color = eGold;
			}
			if (strcmp(name, this->gCustomRanking[i].Value1) == 0)
			{
				Color = eExcellent;
			}

			gInterface.DrawGUI(eRanking_Top4, StartX + 10, StartY + 85 + (20 * i));

			if (pCheckMouseOver(StartX + 10, StartY + 85 + (20 * i), Return2X(TransForX(380)), ReturnY(TransForY(20))))
			{
				pDrawColorButton(0x7980, StartX + 12, StartY + 87 + (20 * i), 376, 17, NULL, NULL, Color4f(43, 237, 5, 100));
			}

			if (i>2)
			{
				CustomFont.Draw(CustomFont.FontSize15, StartX + 60, StartBody + 95 + (20 * i), 0x80B3FFFF, 0x0, 150, 0, 1, "%s", this->gCustomRanking[i].Value1);
				CustomFont.Draw(CustomFont.FontSize15, StartX + 140, StartBody + 95 + (20 * i), 0x80B3FFFF, 0x0, 150, 0, 1, "%s", this->gCustomRanking[i].Value2);
				CustomFont.Draw(CustomFont.FontSize15, StartX + 250, StartBody + 95 + (20 * i), 0x80B3FFFF, 0x0, 150, 0, 1, "%s", this->gCustomRanking[i].Value3);
			}
			else
			{
				CustomFont.Draw(CustomFont.FontBold, StartX + 60, StartBody + 95 + (20 * i), 0xFFFFFFFF, 0x0, 150, 0, 1, "%s", this->gCustomRanking[i].Value1);
				CustomFont.Draw(CustomFont.FontBold, StartX + 140, StartBody + 95 + (20 * i), 0xFFFFFFFF, 0x0, 150, 0, 1, "%s", this->gCustomRanking[i].Value2);
				CustomFont.Draw(CustomFont.FontBold, StartX + 250, StartBody + 95 + (20 * i), 0xFFFFFFFF, 0x0, 150, 0, 1, "%s", this->gCustomRanking[i].Value3);
			}
		}
	}

	gInterface.DrawGUI(eRanking_Select, ButtonX + 250, gInterface.Data[eRanking_MAIN].Y + 45);

	RenderBitmap(31563, ButtonX + 175, gInterface.Data[eRanking_MAIN].Y + 43, 90, 18, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);
	if (showSelect)
	{
		pDrawButton(56042, ButtonX + 250, gInterface.Data[eRanking_MAIN].Y + 45, 15, 15, 0, 0);
	}
	else
	{
		pDrawButton(56042, ButtonX + 250, gInterface.Data[eRanking_MAIN].Y + 45, 15, 15, 0, 15);
	}

	for (int i = 0; i < 15; i++)
	{
		if (i == RankingType)
			gInterface.DrawFormat(eGold, ButtonX + 105, gInterface.Data[eRanking_MAIN].Y + 48, 210, 3, Message_BXH[i]);
	}

	if (showSelect)
	{
		int mainSelect = 0;

		for (int i = 0; i < MAX_RANK; i++)
		{
			mainSelect++;
		}
		int mu8x = 0;
		pDrawColorButton(0x9913, ButtonX + 175, gInterface.Data[eRanking_MAIN].Y + 63, 90, 18 * mainSelect, 0, 0, eBlack);

		for (int i = 0; i < MAX_RANK; i++)
		{
			gInterface.DrawButton(eRanking_BXH1 + i, ButtonX + 180, gInterface.Data[eRanking_MAIN].Y + 65 + (18 * mu8x), 0, 0);

			int TickCount;
			if (pCheckMouseOver(ButtonX + 175, gInterface.Data[eRanking_MAIN].Y + 60 + (18 * mu8x), 90, 18) == 1)
			{
				glColor4f(0.0f, 1.0f, 1.0f, 1.0f);	//xanh
				RenderBitmap(31563, ButtonX + 175, gInterface.Data[eRanking_MAIN].Y + 60 + (18 * mu8x), 90, 18, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);
				if (GetTickCount() - TickCount > 300)
				{
					if (GetKeyState(1) & 0x8000)
					{
						glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
						TickCount = GetTickCount();
					}
				}
				glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
			}
			else
			{
				glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
				RenderBitmap(31563, ButtonX + 175, gInterface.Data[eRanking_MAIN].Y + 60 + (18 * mu8x), 90, 18, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);

			}
			glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
			gInterface.DrawFormat(eWhite, ButtonX + 180, gInterface.Data[eRanking_MAIN].Y + 65 + (18 * mu8x), 210, 1, Message_BXH[i]);

			if (i == RankingType)
			{
				RenderBitmap(31563, ButtonX + 175, gInterface.Data[eRanking_MAIN].Y + 60 + (18 * mu8x), 90, 18, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);
				gInterface.DrawFormat(eRed, ButtonX + 180, gInterface.Data[eRanking_MAIN].Y + 65 + (18 * mu8x), 210, 1, Message_BXH[i]);	//text
			}

			if (ppMousePress(VK_LBUTTON) && pCheckMouseOver(ButtonX + 175, gInterface.Data[eRanking_MAIN].Y + 60 + (18 * mu8x), 90, 18))
			{
				PMSG_CUSTOM_RANKING_SEND pMsg;
				pMsg.header.set(0xF3, 0xE6, sizeof(pMsg));
				RankingType = i;
				pMsg.type = i;
				DataSend((BYTE*)&pMsg, pMsg.header.size);
				showSelect = false;
			}

			mu8x++;
		}
	}

	gInterface.DrawGUI(eRanking_CLOSE, StartX + MainWidth - gInterface.Data[eRanking_CLOSE].Width + 5, gInterface.Data[eRanking_MAIN].Y + 15);
	// ----
	if (gInterface.IsWorkZone(eRanking_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (gInterface.Data[eRanking_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		gInterface.DrawToolTip(gInterface.Data[eRanking_CLOSE].X + 5, gInterface.Data[eRanking_MAIN].Y + 48, "Đóng");

	}
}

bool CCustomRanking::EventVipWindow_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eRanking_CLOSE].EventTick);
	// ----
	if (!gInterface.Data[eRankPANEL_MAIN].OnShow || !gInterface.IsWorkZone(eRanking_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eRanking_CLOSE].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eRanking_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eRanking_CLOSE].EventTick = GetTickCount();
	gInterface.Data[eRankPANEL_MAIN].OnShow = false;

	if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
	// ----
	return false;
}

void CCustomRanking::OpenWindow()
{

	if (this->CustomRankingSwitch == 0)
	{
		return;
	}

	if ((GetTickCount() - gInterface.Data[eRankPANEL_MAIN].EventTick) < 1500)
	{
		return;
	}

	gInterface.Data[eRankPANEL_MAIN].EventTick = GetTickCount();

	if (gInterface.Data[eRankPANEL_MAIN].OnShow == true)
	{
		gInterface.Data[eRankPANEL_MAIN].OnShow = false;

		if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
		{
			pSetCursorFocus = false;
		}
		return;
	}

	gInterface.CloseCustomWindow();

	this->ClearCustomRanking();

	this->RankingCount = 0;

	PMSG_CUSTOM_RANKING_SEND pMsg;

	pMsg.header.set(0xF3, 0xE6, sizeof(pMsg));

	this->RankingType = 0;

	pMsg.type = 0;

	DataSend((BYTE*)&pMsg, pMsg.header.size);

	gInterface.Data[eRankPANEL_MAIN].OnShow = true;

	if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}

}

void CCustomRanking::EventSelect(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eRanking_Select].EventTick);
	// ----
	if (!gInterface.Data[eRankPANEL_MAIN].OnShow || !gInterface.IsWorkZone(eRanking_Select))
	{
		return;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eRanking_Select].OnClick = true;
		return;
	}
	// ----
	gInterface.Data[eRanking_Select].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return;
	}
	// ----
	gInterface.Data[eRanking_Select].EventTick = GetTickCount();

	showSelect = !showSelect;

}

void CCustomRanking::getTatMo()
{
	PMSG_CUSTOM_RANKING_COUNT_SEND pMsg1;

	pMsg1.header.set(0xF3, 0xE7, sizeof(pMsg1));

	DataSend((BYTE*)&pMsg1, pMsg1.header.size);
}