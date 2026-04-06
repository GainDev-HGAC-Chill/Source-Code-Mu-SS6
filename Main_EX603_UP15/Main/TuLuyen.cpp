#include "stdafx.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------
#include "TuLuyen.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------
#include "CustomMessage.h"
#include "Defines.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------
#include "Interface.h"
#include "User.h"
#include "Protocol.h"
#include "PrintPlayer.h"
#include "SItemOption.h"
#include "Config.h"
#include "Central.h"

#if(TU_LUYEN_NEW == 1)

//-----------------------------------------------------------------------------------------------------------------------------------------------------
BEXO_TU_LUYEN G_BEXO_TU_LUYEN;
//-----------------------------------------------------------------------------------------------------------------------------------------------------

#define MAX_TRANG_TU_LUYEN    20  // OK

//-----------------------------------------------------------------------------------------------------------------------------------------------------
BEXO_TU_LUYEN::BEXO_TU_LUYEN()
{
	TRANG_TU_LUYEN = 1;
	//--------------------------------------------------------------
	HIENTHITU_LUYEN = false;
	MainWidth = 640;
	MainHeight = 429;
	StartY = 0;
	StartX = 0;
	ClickTick = 0;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void BEXO_TU_LUYEN::DRAW_TU_LUYEN()
{
	DRAW_WINDOW_TU_LUYEN();
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void BEXO_TU_LUYEN::BEXO_CLICK_TRANG_TU_LUYEN(DWORD ClickMouse)
{
	if (!gInterface.Data[EXBEXO_TU_LUYEN_MAIN].OnShow)
	{
		return;
	}
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - ClickTick);
	if (gInterface.Data[EXBEXO_TU_LUYEN_MAIN].OnShow && gInterface.IsWorkZone(eTU_LUYEN1))
	{
		if (ClickMouse == WM_LBUTTONDOWN)
		{
			pSetCursorFocus = true;
			return;
		}
		pSetCursorFocus = false;
		if (Delay < 300)
		{
			return;
		}
		if (1 < TRANG_TU_LUYEN && TRANG_TU_LUYEN <= MAX_TRANG_TU_LUYEN)
		{
			TRANG_TU_LUYEN--;
		}
		ClickTick = GetTickCount();
	}
	if (gInterface.Data[EXBEXO_TU_LUYEN_MAIN].OnShow && gInterface.IsWorkZone(eTU_LUYEN2))

	{
		if (ClickMouse == WM_LBUTTONDOWN)
		{
			pSetCursorFocus = true;
			return;
		}
		pSetCursorFocus = false;
		if (Delay < 300)
		{
			return;
		}
		if (1 <= TRANG_TU_LUYEN && TRANG_TU_LUYEN < MAX_TRANG_TU_LUYEN)
		{
			TRANG_TU_LUYEN++;
		}
		ClickTick = GetTickCount();
	}
	if (TRANG_TU_LUYEN < 1)
	{
		TRANG_TU_LUYEN = 1;
	}
	if (TRANG_TU_LUYEN > TRANG_TU_LUYEN)
	{
		TRANG_TU_LUYEN = TRANG_TU_LUYEN;
	}
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------

void BEXO_TU_LUYEN::DRAW_WINDOW_TU_LUYEN()
{

	if (gInterface.CheckWindow(CashShop)
		|| gInterface.CheckWindow(SkillTree)
		|| gInterface.CheckWindow(FullMap)
		|| gInterface.CheckWindow(MoveList)
		|| gInterface.CheckWindow(Inventory)
		|| gInterface.CheckWindow(ExpandInventory)
		|| gInterface.CheckWindow(Store)
		|| gInterface.CheckWindow(Inventory)
		|| gInterface.CheckWindow(Party)
		|| gInterface.CheckWindow(Trade)
		|| gInterface.CheckWindow(Warehouse)
		|| gInterface.CheckWindow(ExpandWarehouse))
	{
		return;
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (!gInterface.Data[EXBEXO_TU_LUYEN_MAIN].OnShow)
	{
		return;
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (gProtect.m_MainInfo.CustomInterfaceType == 0 || gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		pDrawGUFULL(0x0899, StartX + 70, StartY + 50, 900, 550, 0, 0, 1, 1, 1, 1, 0.0); // MENU
	}
	if (gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		gCentral.PrintDropBox(StartX + 70, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 50, 495, 300, 0.0, 0);

		gCentral.PrintDropBox(StartX + 95, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 85, 450, 60, 0.0, 0);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (gInterface.IsWorkZone(StartX, StartY, StartX + MainWidth, StartY + MainHeight)) // nếu chuột trong khu vực bảng shop thì ko click di chuyển nv
	{
		pSetCursorFocus = true;
	}
	else pSetCursorFocus = false;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	//pDrawMessage("", 0); // Không Cho Hiện Thông Báo Trên Màn Hình
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawFormat(eWhite, StartX + 280, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 60, 210, 1, "Nâng cấp Tu Luyện");

	gInterface.DrawFormat(eWhite, StartX + 115, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 90, 210, 1, gConfig.TextVN_TuLuyen[0]);

	//---- wcoin nâng cấp


	gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 105, 210, 1, gConfig.TextVN_TuLuyen[1], gObjUser.TU_LUYEN_WCOINC);


	//----
	gInterface.DrawFormat(eSocket, StartX + 105, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 120, 210, 1, gConfig.TextVN_TuLuyen[2]);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawGUI(EXBEXO_TU_LUYEN_NANG_CAP, StartX + 435, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 100);

	if (gInterface.IsWorkZone(EXBEXO_TU_LUYEN_NANG_CAP))
	{
		DWORD Color = eGray150;

		gInterface.DrawColoredGUI(EXBEXO_TU_LUYEN_NANG_CAP, gInterface.Data[EXBEXO_TU_LUYEN_NANG_CAP].X, gInterface.Data[EXBEXO_TU_LUYEN_NANG_CAP].Y, Color);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawFormat(eAncient, StartX + 455, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 110, 210, 1, gConfig.TextVN_TuLuyen[3]);

	gInterface.DrawFormat(eYellow, StartX + 270, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 132, 210, 1, gConfig.TextVN_TuLuyen[4], gInterface.m_TuLuyen);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawGUI(eTU_LUYEN1, StartX + 70, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210);

	if (gInterface.IsWorkZone(eTU_LUYEN1))
	{
		DWORD Color = eGray150;

		gInterface.DrawColoredGUI(eTU_LUYEN1, gInterface.Data[eTU_LUYEN1].X, gInterface.Data[eTU_LUYEN1].Y, Color);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawGUI(eTU_LUYEN2, StartX + 535, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210);

	if (gInterface.IsWorkZone(eTU_LUYEN2))
	{
		DWORD Color = eGray150;

		gInterface.DrawColoredGUI(eTU_LUYEN2, gInterface.Data[eTU_LUYEN2].X, gInterface.Data[eTU_LUYEN2].Y, Color);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawGUI(EXBEXO_TU_LUYEN_CLOSE, StartX + 532, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 52);
	if (gInterface.IsWorkZone(EXBEXO_TU_LUYEN_CLOSE))
	{
		DWORD Color = eGray150;
		gInterface.DrawColoredGUI(EXBEXO_TU_LUYEN_CLOSE, gInterface.Data[EXBEXO_TU_LUYEN_CLOSE].X, gInterface.Data[EXBEXO_TU_LUYEN_CLOSE].Y, Color);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	// Thanh Xanh Coin
	RenderBitmap(0x0897, StartX + 197, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 109, 210, 14, 0, 0, 1, 1, 1, 1, 0.0);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawFormat(eRed, StartX + 270, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 108, 210, 1, "WCoinC %d", Coin1);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		// Nền đen nằm text
		RenderBitmap(0x0896, StartX + 96, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(0x0896, StartX + 208, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(0x0896, StartX + 320, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(0x0896, StartX + 432, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	switch (TRANG_TU_LUYEN) //====================================================================================================================================
	{
		//=============================================================================================================================================================	
	case 1:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gInterface.m_TuLuyen >= 1)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 2)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 3)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 4)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(20128, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20129, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20130, StartX + 337, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20131, StartX + 447, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);

		gInterface.DrawFormat(eWhite, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[6]);
		gInterface.DrawFormat(eWhite, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[7]);
		gInterface.DrawFormat(eWhite, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[8]);
		gInterface.DrawFormat(eWhite, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[9]);
		gInterface.DrawFormat(eWhite, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[10]);

		gInterface.DrawFormat(eWhite, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[11]);
		gInterface.DrawFormat(eWhite, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[12]);
		gInterface.DrawFormat(eWhite, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[13]);
		gInterface.DrawFormat(eWhite, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[14]);
		gInterface.DrawFormat(eWhite, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[15]);

		gInterface.DrawFormat(eWhite, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[16]);
		gInterface.DrawFormat(eWhite, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[17]);
		gInterface.DrawFormat(eWhite, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[18]);
		gInterface.DrawFormat(eWhite, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[19]);
		gInterface.DrawFormat(eWhite, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[20]);

		gInterface.DrawFormat(eWhite, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[21]);
		gInterface.DrawFormat(eWhite, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[22]);
		gInterface.DrawFormat(eWhite, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[23]);
		gInterface.DrawFormat(eWhite, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[24]);
		gInterface.DrawFormat(eWhite, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[25]);

		//=============================================================================================================================================================	
		break;
	case 2:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gInterface.m_TuLuyen >= 5)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 6)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 7)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 8)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(20132, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20133, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20134, StartX + 337, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20135, StartX + 447, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eBlue, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[26]);
		gInterface.DrawFormat(eBlue, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[27]);
		gInterface.DrawFormat(eBlue, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[28]);
		gInterface.DrawFormat(eBlue, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[29]);
		gInterface.DrawFormat(eBlue, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[30]);

		gInterface.DrawFormat(eBlue, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[31]);
		gInterface.DrawFormat(eBlue, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[32]);
		gInterface.DrawFormat(eBlue, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[33]);
		gInterface.DrawFormat(eBlue, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[34]);
		gInterface.DrawFormat(eBlue, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[35]);

		gInterface.DrawFormat(eBlue, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[36]);
		gInterface.DrawFormat(eBlue, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[37]);
		gInterface.DrawFormat(eBlue, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[38]);
		gInterface.DrawFormat(eBlue, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[39]);
		gInterface.DrawFormat(eBlue, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[40]);

		gInterface.DrawFormat(eBlue, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[41]);
		gInterface.DrawFormat(eBlue, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[42]);
		gInterface.DrawFormat(eBlue, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[43]);
		gInterface.DrawFormat(eBlue, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[44]);
		gInterface.DrawFormat(eBlue, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[45]);
		//=============================================================================================================================================================	
		break;
	case 3:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gInterface.m_TuLuyen >= 9)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 10)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 11)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 12)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(20136, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20137, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20138, StartX + 337, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20139, StartX + 447, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[46]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[47]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[48]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[49]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[50]);

		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[51]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[52]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[53]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[54]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[55]);

		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[56]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[57]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[58]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[59]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[60]);

		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[61]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[62]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[63]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[64]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[65]);
		//=============================================================================================================================================================	
		break;
	case 4:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gInterface.m_TuLuyen >= 13)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 14)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 15)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 16)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(20140, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20141, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20142, StartX + 337, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20143, StartX + 447, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[66]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[67]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[68]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[69]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[70]);

		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[71]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[72]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[73]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[74]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[75]);

		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[76]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[77]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[78]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[79]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[80]);

		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[81]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[82]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[83]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[84]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[85]);
		//=============================================================================================================================================================	
		break;
	case 5:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gInterface.m_TuLuyen >= 17)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 18)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 19)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 20)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(20144, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20145, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20146, StartX + 337, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20147, StartX + 447, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[86]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[87]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[88]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[89]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[90]);

		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[91]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[92]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[93]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[94]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[95]);

		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[96]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[97]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[98]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[99]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[100]);

		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[101]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[102]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[103]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[104]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[105]);
		//=============================================================================================================================================================	
		break;
	case 6:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gInterface.m_TuLuyen >= 21)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 22)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 23)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 24)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(20148, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20149, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20150, StartX + 337, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20151, StartX + 447, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[106]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[107]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[108]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[109]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[110]);

		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[111]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[112]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[113]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[114]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[115]);

		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[116]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[117]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[118]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[119]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[120]);

		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[121]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[122]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[123]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[124]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[125]);
		//=============================================================================================================================================================	
		break;
	case 7:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gInterface.m_TuLuyen >= 25)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 26)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 27)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 28)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(20152, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20153, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20154, StartX + 337, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20155, StartX + 447, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[126]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[127]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[128]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[129]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[130]);

		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[131]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[132]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[133]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[134]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[135]);

		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[136]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[137]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[138]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[139]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[140]);

		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[141]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[142]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[143]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[144]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[145]);
		//=============================================================================================================================================================	
		break;
	case 8:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gInterface.m_TuLuyen >= 29)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 30)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 31)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 32)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(20156, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20157, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20158, StartX + 337, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20159, StartX + 447, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[146]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[147]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[148]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[149]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[150]);

		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[151]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[152]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[153]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[154]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[155]);

		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[156]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[157]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[158]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[159]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[160]);

		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[161]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[162]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[163]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[164]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[165]);
		//=============================================================================================================================================================	
		break;
	case 9:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gInterface.m_TuLuyen >= 33)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 34)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 35)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 36)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(20160, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20161, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20162, StartX + 337, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20163, StartX + 447, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[166]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[167]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[168]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[169]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[170]);

		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[171]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[172]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[173]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[174]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[175]);

		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[176]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[177]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[178]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[179]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[180]);

		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[181]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[182]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[183]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[184]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[185]);
		//=============================================================================================================================================================	
		break;
	case 10:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gInterface.m_TuLuyen >= 37)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 38)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 39)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 40)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(20164, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20165, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20166, StartX + 337, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20167, StartX + 447, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[186]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[187]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[188]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[189]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[190]);

		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[191]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[192]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[193]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[194]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[195]);

		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[196]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[197]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[198]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[199]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[200]);

		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[201]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[202]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[203]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[204]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[205]);
		//=============================================================================================================================================================	
		break;



		//=============================================================================================================================================================	
	case 11:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gInterface.m_TuLuyen >= 41)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 42)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 43)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 44)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(20168, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20169, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20170, StartX + 337, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20171, StartX + 447, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);

		gInterface.DrawFormat(eWhite, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[206]);
		gInterface.DrawFormat(eWhite, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[207]);
		gInterface.DrawFormat(eWhite, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[208]);
		gInterface.DrawFormat(eWhite, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[209]);
		gInterface.DrawFormat(eWhite, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[210]);

		gInterface.DrawFormat(eWhite, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[211]);
		gInterface.DrawFormat(eWhite, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[212]);
		gInterface.DrawFormat(eWhite, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[213]);
		gInterface.DrawFormat(eWhite, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[214]);
		gInterface.DrawFormat(eWhite, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[215]);

		gInterface.DrawFormat(eWhite, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[216]);
		gInterface.DrawFormat(eWhite, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[217]);
		gInterface.DrawFormat(eWhite, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[218]);
		gInterface.DrawFormat(eWhite, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[219]);
		gInterface.DrawFormat(eWhite, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[220]);

		gInterface.DrawFormat(eWhite, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[221]);
		gInterface.DrawFormat(eWhite, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[222]);
		gInterface.DrawFormat(eWhite, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[223]);
		gInterface.DrawFormat(eWhite, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[224]);
		gInterface.DrawFormat(eWhite, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[225]);

		//=============================================================================================================================================================	
		break;
	case 12:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gInterface.m_TuLuyen >= 45)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 46)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 47)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 48)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(20172, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20173, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20174, StartX + 337, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20175, StartX + 447, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eBlue, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[226]);
		gInterface.DrawFormat(eBlue, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[227]);
		gInterface.DrawFormat(eBlue, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[228]);
		gInterface.DrawFormat(eBlue, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[229]);
		gInterface.DrawFormat(eBlue, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[230]);

		gInterface.DrawFormat(eBlue, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[231]);
		gInterface.DrawFormat(eBlue, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[232]);
		gInterface.DrawFormat(eBlue, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[233]);
		gInterface.DrawFormat(eBlue, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[234]);
		gInterface.DrawFormat(eBlue, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[235]);

		gInterface.DrawFormat(eBlue, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[236]);
		gInterface.DrawFormat(eBlue, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[237]);
		gInterface.DrawFormat(eBlue, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[238]);
		gInterface.DrawFormat(eBlue, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[239]);
		gInterface.DrawFormat(eBlue, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[240]);

		gInterface.DrawFormat(eBlue, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[241]);
		gInterface.DrawFormat(eBlue, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[242]);
		gInterface.DrawFormat(eBlue, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[243]);
		gInterface.DrawFormat(eBlue, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[244]);
		gInterface.DrawFormat(eBlue, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[245]);
		//=============================================================================================================================================================	
		break;
	case 13:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gInterface.m_TuLuyen >= 49)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 50)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 51)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 52)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(20176, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20177, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20178, StartX + 337, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20179, StartX + 447, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[246]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[247]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[248]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[249]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[250]);

		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[251]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[252]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[253]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[254]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[255]);

		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[256]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[257]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[258]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[259]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[260]);

		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[261]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[262]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[263]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[264]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[265]);
		//=============================================================================================================================================================	
		break;
	case 14:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gInterface.m_TuLuyen >= 53)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 54)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 55)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 56)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(20180, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20181, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20182, StartX + 337, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20183, StartX + 447, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[266]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[267]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[268]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[269]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[270]);

		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[271]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[272]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[273]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[274]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[275]);

		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[276]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[277]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[278]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[279]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[280]);

		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[281]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[282]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[283]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[284]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[285]);
		//=============================================================================================================================================================	
		break;
	case 15:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gInterface.m_TuLuyen >= 57)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 58)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 59)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 60)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(20184, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20185, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20186, StartX + 337, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20187, StartX + 447, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[286]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[287]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[288]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[289]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[290]);

		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[291]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[292]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[293]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[294]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[295]);

		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[296]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[297]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[298]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[299]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[300]);

		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[301]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[302]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[303]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[304]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[305]);
		//=============================================================================================================================================================	
		break;
	case 16:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gInterface.m_TuLuyen >= 61)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 62)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 63)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 64)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(20188, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20189, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20190, StartX + 337, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20191, StartX + 447, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[306]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[307]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[308]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[309]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[310]);

		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[311]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[312]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[313]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[314]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[315]);

		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[316]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[317]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[318]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[319]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[320]);

		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[321]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[322]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[323]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[324]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[325]);
		//=============================================================================================================================================================	
		break;
	case 17:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gInterface.m_TuLuyen >= 65)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 66)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 67)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 68)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(20192, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20193, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20194, StartX + 337, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20195, StartX + 447, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[326]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[327]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[328]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[329]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[330]);

		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[331]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[332]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[333]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[334]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[335]);

		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[336]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[337]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[338]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[339]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[340]);

		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[341]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[342]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[343]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[344]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[345]);
		//=============================================================================================================================================================	
		break;
	case 18:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gInterface.m_TuLuyen >= 69)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 70)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 71)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 72)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(20196, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20197, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20198, StartX + 337, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20199, StartX + 447, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[346]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[347]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[348]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[349]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[350]);

		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[351]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[352]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[353]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[354]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[355]);

		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[356]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[357]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[358]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[359]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[360]);

		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[361]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[362]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[363]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[364]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[365]);
		//=============================================================================================================================================================	
		break;
	case 19:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gInterface.m_TuLuyen >= 73)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 74)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 75)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 76)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(20200, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20201, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20202, StartX + 337, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20203, StartX + 447, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[366]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[367]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[368]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[369]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[370]);

		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[371]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[372]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[373]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[374]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[375]);

		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[376]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[377]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[378]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[379]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[380]);

		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[381]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[382]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[383]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[384]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[385]);
		//=============================================================================================================================================================	
		break;
	case 20:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gInterface.m_TuLuyen >= 77)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 78)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 79)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_TuLuyen >= 80)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(20204, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20205, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20206, StartX + 337, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(20207, StartX + 447, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 168, 100, 28, 0, 0, 1, 1, 1, 1, 0.0);
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[386]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[387]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[388]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[389]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[390]);

		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[391]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[392]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[393]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[394]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[395]);

		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[396]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[397]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[398]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[399]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[400]);

		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 210, 210, 1, gConfig.TextVN_TuLuyen[401]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 230, 210, 1, gConfig.TextVN_TuLuyen[402]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 250, 210, 1, gConfig.TextVN_TuLuyen[403]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 270, 210, 1, gConfig.TextVN_TuLuyen[404]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_TU_LUYEN_MAIN].Y + 290, 210, 1, gConfig.TextVN_TuLuyen[405]);
		//=============================================================================================================================================================	
		break;






	default:
		break;
	}
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
bool BEXO_TU_LUYEN::MAIN_TU_LUYEN(DWORD Event)
{
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	DWORD CurrentTick = GetTickCount();
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	this->CLOSE_TU_LUYEN(Event);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	// TRANG 1
	if (gInterface.Data[EXBEXO_TU_LUYEN_MAIN].OnShow && gInterface.IsWorkZone(EXBEXO_TU_LUYEN_NANG_CAP))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[EXBEXO_TU_LUYEN_NANG_CAP].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[EXBEXO_TU_LUYEN_NANG_CAP].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[EXBEXO_TU_LUYEN_NANG_CAP].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 100)
		{
			return false;
		}
		gInterface.Data[EXBEXO_TU_LUYEN_NANG_CAP].EventTick = GetTickCount();

		this->BUY_TU_LUYEN(gInterface.m_TuLuyen);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
bool BEXO_TU_LUYEN::CLOSE_TU_LUYEN(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[EXBEXO_TU_LUYEN_CLOSE].EventTick);
	// ----
	if (!gInterface.Data[EXBEXO_TU_LUYEN_MAIN].OnShow || !gInterface.IsWorkZone(EXBEXO_TU_LUYEN_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[EXBEXO_TU_LUYEN_CLOSE].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[EXBEXO_TU_LUYEN_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[EXBEXO_TU_LUYEN_CLOSE].EventTick = GetTickCount();
	G_BEXO_TU_LUYEN.CLOSE_WINDOW_TU_LUYEN();
	// ----
	return false;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void BEXO_TU_LUYEN::BUY_TU_LUYEN(int Number)
{
	BUY_TU_LUYEN_REQ pMsg;
	pMsg.h.set(0xFC, 0x05, sizeof(pMsg)); // Gửi Xuống Server Protocol.cpp
	pMsg.Number = Number + 1;
	DataSend((BYTE*)&pMsg, pMsg.h.size);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
#endif