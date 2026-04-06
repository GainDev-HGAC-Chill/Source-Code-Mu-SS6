#include "stdafx.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------
#include "DanhHieu.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------
#include "CustomMessage.h"
#include "Defines.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------
#include "Interface.h"
#include "User.h"
#include "Protocol.h"
#include "Config.h"
#include "PrintPlayer.h"
#include "SItemOption.h"
#include "Central.h"

#if(DANH_HIEU_NEW == 1)
//-----------------------------------------------------------------------------------------------------------------------------------------------------
BEXO_DANH_HIEU G_BEXO_DANH_HIEU;
//-----------------------------------------------------------------------------------------------------------------------------------------------------

#define MAX_TRANG_DANH_HIEU    12  // OK

//-----------------------------------------------------------------------------------------------------------------------------------------------------
BEXO_DANH_HIEU::BEXO_DANH_HIEU()
{
	TRANG_DANH_HIEU = 1;
	//--------------------------------------------------------------
	HIENTHIDANH_HIEU = false;
	MainWidth = 640;
	MainHeight = 429;
	StartY = 0;
	StartX = 0;
	ClickTick = 0;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void BEXO_DANH_HIEU::DRAW_DANH_HIEU()
{
	DRAW_WINDOW_DANH_HIEU();
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void BEXO_DANH_HIEU::BEXO_CLICK_TRANG_DANH_HIEU(DWORD ClickMouse)
{
	if (!gInterface.Data[EXBEXO_DANH_HIEU_MAIN].OnShow)
	{
		return;
	}
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - ClickTick);
	if (gInterface.Data[EXBEXO_DANH_HIEU_MAIN].OnShow && gInterface.IsWorkZone(eDANH_HIEU1))
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
		if (1 < TRANG_DANH_HIEU && TRANG_DANH_HIEU <= MAX_TRANG_DANH_HIEU)
		{
			TRANG_DANH_HIEU--;
		}
		ClickTick = GetTickCount();
	}
	if (gInterface.Data[EXBEXO_DANH_HIEU_MAIN].OnShow && gInterface.IsWorkZone(eDANH_HIEU2))

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
		if (1 <= TRANG_DANH_HIEU && TRANG_DANH_HIEU < MAX_TRANG_DANH_HIEU)
		{
			TRANG_DANH_HIEU++;
		}
		ClickTick = GetTickCount();
	}
	if (TRANG_DANH_HIEU < 1)
	{
		TRANG_DANH_HIEU = 1;
	}
	if (TRANG_DANH_HIEU > TRANG_DANH_HIEU)
	{
		TRANG_DANH_HIEU = TRANG_DANH_HIEU;
	}
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------

void BEXO_DANH_HIEU::DRAW_WINDOW_DANH_HIEU()
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
	if (!gInterface.Data[EXBEXO_DANH_HIEU_MAIN].OnShow)
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
		gCentral.PrintDropBox(StartX + 70, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 50, 495, 300, 0.0, 0);

		gCentral.PrintDropBox(StartX + 95, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 85, 450, 60, 0.0, 0);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (gInterface.IsWorkZone(StartX, StartY, StartX + MainWidth, StartY + MainHeight)) // nếu chuột trong khu vực bảng shop thì ko click di chuyển nv
	{
		pSetCursorFocus = true;
	}
	else pSetCursorFocus = false;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	//pDrawMessage("", 0); // Không Cho Hiện Thông Báo Trên Màn Hình
	//-----------------------------------------------------------------------------------------------------------------------------------------------------

	gInterface.DrawFormat(eWhite, StartX + 280, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 60, 210, 1, "Nâng cấp Danh Hiệu");

	gInterface.DrawFormat(eWhite, StartX + 115, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 90, 210, 1, gConfig.TextVN_DanhHieu[0]);

	//---- wcoin nâng cấp

	gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 105, 210, 1, gConfig.TextVN_DanhHieu[1], gObjUser.DANH_HIEU_WCOINC);




	//----
	gInterface.DrawFormat(eSocket, StartX + 105, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 120, 210, 1, gConfig.TextVN_DanhHieu[2]);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawGUI(EXBEXO_DANH_HIEU_NANG_CAP, StartX + 435, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 100);

	if (gInterface.IsWorkZone(EXBEXO_DANH_HIEU_NANG_CAP))
	{
		DWORD Color = eGray150;

		gInterface.DrawColoredGUI(EXBEXO_DANH_HIEU_NANG_CAP, gInterface.Data[EXBEXO_DANH_HIEU_NANG_CAP].X, gInterface.Data[EXBEXO_DANH_HIEU_NANG_CAP].Y, Color);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawFormat(eAncient, StartX + 450, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 110, 210, 1, gConfig.TextVN_DanhHieu[3]);

	gInterface.DrawFormat(eYellow, StartX + 270, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 132, 210, 1, gConfig.TextVN_DanhHieu[4], gInterface.m_DanhHieu);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawGUI(eDANH_HIEU1, StartX + 70, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210);

	if (gInterface.IsWorkZone(eDANH_HIEU1))
	{
		DWORD Color = eGray150;

		gInterface.DrawColoredGUI(eDANH_HIEU1, gInterface.Data[eDANH_HIEU1].X, gInterface.Data[eDANH_HIEU1].Y, Color);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawGUI(eDANH_HIEU2, StartX + 535, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210);

	if (gInterface.IsWorkZone(eDANH_HIEU2))
	{
		DWORD Color = eGray150;

		gInterface.DrawColoredGUI(eDANH_HIEU2, gInterface.Data[eDANH_HIEU2].X, gInterface.Data[eDANH_HIEU2].Y, Color);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawGUI(EXBEXO_DANH_HIEU_CLOSE, StartX + 532, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 52);
	if (gInterface.IsWorkZone(EXBEXO_DANH_HIEU_CLOSE))
	{
		DWORD Color = eGray150;
		gInterface.DrawColoredGUI(EXBEXO_DANH_HIEU_CLOSE, gInterface.Data[EXBEXO_DANH_HIEU_CLOSE].X, gInterface.Data[EXBEXO_DANH_HIEU_CLOSE].Y, Color);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	// Thanh Xanh Coin
	RenderBitmap(0x0897, StartX + 197, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 109, 210, 14, 0, 0, 1, 1, 1, 1, 0.0);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawFormat(eRed, StartX + 270, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 108, 210, 1, "WCoinC %d", Coin1);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		// Nền đen nằm text
		RenderBitmap(0x0896, StartX + 96, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(0x0896, StartX + 208, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(0x0896, StartX + 320, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(0x0896, StartX + 432, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	switch (TRANG_DANH_HIEU) //====================================================================================================================================
	{
		//=============================================================================================================================================================	
	case 1:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gInterface.m_DanhHieu >= 1)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu >= 2)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu >= 3)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu >= 4)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(90101, StartX + 100, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 160, 130, 50, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(90102, StartX + 210, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 160, 130, 50, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(90103, StartX + 320, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 160, 130, 50, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(90104, StartX + 430, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 160, 130, 50, 0, 0, 1, 1, 1, 1, 0.0);

		gInterface.DrawFormat(eWhite, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gConfig.TextVN_DanhHieu[6]);
		gInterface.DrawFormat(eWhite, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gConfig.TextVN_DanhHieu[7]);
		gInterface.DrawFormat(eWhite, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gConfig.TextVN_DanhHieu[8]);
		gInterface.DrawFormat(eWhite, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gConfig.TextVN_DanhHieu[9]);
		gInterface.DrawFormat(eWhite, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gConfig.TextVN_DanhHieu[10]);

		gInterface.DrawFormat(eWhite, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gConfig.TextVN_DanhHieu[11]);
		gInterface.DrawFormat(eWhite, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gConfig.TextVN_DanhHieu[12]);
		gInterface.DrawFormat(eWhite, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gConfig.TextVN_DanhHieu[13]);
		gInterface.DrawFormat(eWhite, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gConfig.TextVN_DanhHieu[14]);
		gInterface.DrawFormat(eWhite, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gConfig.TextVN_DanhHieu[15]);

		gInterface.DrawFormat(eWhite, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gConfig.TextVN_DanhHieu[16]);
		gInterface.DrawFormat(eWhite, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gConfig.TextVN_DanhHieu[17]);
		gInterface.DrawFormat(eWhite, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gConfig.TextVN_DanhHieu[18]);
		gInterface.DrawFormat(eWhite, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gConfig.TextVN_DanhHieu[19]);
		gInterface.DrawFormat(eWhite, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gConfig.TextVN_DanhHieu[20]);

		gInterface.DrawFormat(eWhite, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gConfig.TextVN_DanhHieu[21]);
		gInterface.DrawFormat(eWhite, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gConfig.TextVN_DanhHieu[22]);
		gInterface.DrawFormat(eWhite, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gConfig.TextVN_DanhHieu[23]);
		gInterface.DrawFormat(eWhite, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gConfig.TextVN_DanhHieu[24]);
		gInterface.DrawFormat(eWhite, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gConfig.TextVN_DanhHieu[25]);

		//=============================================================================================================================================================	
		break;
	case 2:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gInterface.m_DanhHieu >= 5)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu >= 6)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu >= 7)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu >= 8)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(90105, StartX + 100, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 160, 130, 45, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(90106, StartX + 210, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 160, 140, 50, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(90107, StartX + 320, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 160, 130, 45, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(90108, StartX + 430, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 160, 140, 45, 0, 0, 1, 1, 1, 1, 0.0);
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eBlue, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gConfig.TextVN_DanhHieu[26]);
		gInterface.DrawFormat(eBlue, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gConfig.TextVN_DanhHieu[27]);
		gInterface.DrawFormat(eBlue, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gConfig.TextVN_DanhHieu[28]);
		gInterface.DrawFormat(eBlue, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gConfig.TextVN_DanhHieu[29]);
		gInterface.DrawFormat(eBlue, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gConfig.TextVN_DanhHieu[30]);

		gInterface.DrawFormat(eBlue, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gConfig.TextVN_DanhHieu[31]);
		gInterface.DrawFormat(eBlue, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gConfig.TextVN_DanhHieu[32]);
		gInterface.DrawFormat(eBlue, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gConfig.TextVN_DanhHieu[33]);
		gInterface.DrawFormat(eBlue, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gConfig.TextVN_DanhHieu[34]);
		gInterface.DrawFormat(eBlue, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gConfig.TextVN_DanhHieu[35]);

		gInterface.DrawFormat(eBlue, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gConfig.TextVN_DanhHieu[36]);
		gInterface.DrawFormat(eBlue, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gConfig.TextVN_DanhHieu[37]);
		gInterface.DrawFormat(eBlue, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gConfig.TextVN_DanhHieu[38]);
		gInterface.DrawFormat(eBlue, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gConfig.TextVN_DanhHieu[39]);
		gInterface.DrawFormat(eBlue, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gConfig.TextVN_DanhHieu[40]);

		gInterface.DrawFormat(eBlue, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gConfig.TextVN_DanhHieu[41]);
		gInterface.DrawFormat(eBlue, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gConfig.TextVN_DanhHieu[42]);
		gInterface.DrawFormat(eBlue, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gConfig.TextVN_DanhHieu[43]);
		gInterface.DrawFormat(eBlue, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gConfig.TextVN_DanhHieu[44]);
		gInterface.DrawFormat(eBlue, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gConfig.TextVN_DanhHieu[45]);
		//=============================================================================================================================================================	
		break;
	case 3:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gInterface.m_DanhHieu >= 9)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu >= 10)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu >= 11)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu >= 12)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(90109, StartX + 100, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 160, 130, 45, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(90110, StartX + 210, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 160, 130, 50, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(90111, StartX + 320, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 160, 130, 50, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(90112, StartX + 430, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 160, 140, 50, 0, 0, 1, 1, 1, 1, 0.0);

		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gConfig.TextVN_DanhHieu[46]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gConfig.TextVN_DanhHieu[47]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gConfig.TextVN_DanhHieu[48]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gConfig.TextVN_DanhHieu[49]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gConfig.TextVN_DanhHieu[50]);

		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gConfig.TextVN_DanhHieu[51]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gConfig.TextVN_DanhHieu[52]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gConfig.TextVN_DanhHieu[53]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gConfig.TextVN_DanhHieu[54]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gConfig.TextVN_DanhHieu[55]);

		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gConfig.TextVN_DanhHieu[56]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gConfig.TextVN_DanhHieu[57]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gConfig.TextVN_DanhHieu[58]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gConfig.TextVN_DanhHieu[59]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gConfig.TextVN_DanhHieu[60]);

		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gConfig.TextVN_DanhHieu[61]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gConfig.TextVN_DanhHieu[62]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gConfig.TextVN_DanhHieu[63]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gConfig.TextVN_DanhHieu[64]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gConfig.TextVN_DanhHieu[65]);
		//=============================================================================================================================================================	
		break;
	case 4:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gInterface.m_DanhHieu >= 13)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu >= 14)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu >= 15)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu >= 16)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(90113, StartX + 100, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 160, 130, 50, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(90114, StartX + 210, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 160, 130, 50, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(90115, StartX + 320, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 160, 130, 50, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(90116, StartX + 430, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 160, 140, 50, 0, 0, 1, 1, 1, 1, 0.0);


		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gConfig.TextVN_DanhHieu[66]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gConfig.TextVN_DanhHieu[67]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gConfig.TextVN_DanhHieu[68]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gConfig.TextVN_DanhHieu[69]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gConfig.TextVN_DanhHieu[70]);

		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gConfig.TextVN_DanhHieu[71]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gConfig.TextVN_DanhHieu[72]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gConfig.TextVN_DanhHieu[73]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gConfig.TextVN_DanhHieu[74]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gConfig.TextVN_DanhHieu[75]);

		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gConfig.TextVN_DanhHieu[76]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gConfig.TextVN_DanhHieu[77]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gConfig.TextVN_DanhHieu[78]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gConfig.TextVN_DanhHieu[79]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gConfig.TextVN_DanhHieu[80]);

		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gConfig.TextVN_DanhHieu[81]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gConfig.TextVN_DanhHieu[82]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gConfig.TextVN_DanhHieu[83]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gConfig.TextVN_DanhHieu[84]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gConfig.TextVN_DanhHieu[85]);
		//=============================================================================================================================================================	
		break;

	case 5:
		if (gInterface.m_DanhHieu >= 17)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu >= 18)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu >= 19)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu >= 20)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(90117, StartX + 100, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 160, 130, 50, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(90118, StartX + 210, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 160, 130, 50, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(90119, StartX + 320, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 160, 130, 50, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(90120, StartX + 430, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 160, 130, 40, 0, 0, 1, 1, 1, 1, 0.0);


		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eBlue, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gConfig.TextVN_DanhHieu[86]);
		gInterface.DrawFormat(eBlue, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gConfig.TextVN_DanhHieu[87]);
		gInterface.DrawFormat(eBlue, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gConfig.TextVN_DanhHieu[88]);
		gInterface.DrawFormat(eBlue, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gConfig.TextVN_DanhHieu[89]);
		gInterface.DrawFormat(eBlue, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gConfig.TextVN_DanhHieu[90]);

		gInterface.DrawFormat(eBlue, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gConfig.TextVN_DanhHieu[91]);
		gInterface.DrawFormat(eBlue, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gConfig.TextVN_DanhHieu[92]);
		gInterface.DrawFormat(eBlue, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gConfig.TextVN_DanhHieu[93]);
		gInterface.DrawFormat(eBlue, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gConfig.TextVN_DanhHieu[94]);
		gInterface.DrawFormat(eBlue, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gConfig.TextVN_DanhHieu[95]);

		gInterface.DrawFormat(eBlue, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gConfig.TextVN_DanhHieu[96]);
		gInterface.DrawFormat(eBlue, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gConfig.TextVN_DanhHieu[97]);
		gInterface.DrawFormat(eBlue, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gConfig.TextVN_DanhHieu[98]);
		gInterface.DrawFormat(eBlue, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gConfig.TextVN_DanhHieu[99]);
		gInterface.DrawFormat(eBlue, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gConfig.TextVN_DanhHieu[100]);

		gInterface.DrawFormat(eBlue, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gConfig.TextVN_DanhHieu[101]);
		gInterface.DrawFormat(eBlue, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gConfig.TextVN_DanhHieu[102]);
		gInterface.DrawFormat(eBlue, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gConfig.TextVN_DanhHieu[103]);
		gInterface.DrawFormat(eBlue, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gConfig.TextVN_DanhHieu[104]);
		gInterface.DrawFormat(eBlue, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gConfig.TextVN_DanhHieu[105]);
		//=============================================================================================================================================================	
		break;

	case 6:
		if (gInterface.m_DanhHieu >= 21)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu >= 22)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu >= 23)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu >= 24)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(90121, StartX + 85, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(90122, StartX + 200, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(90123, StartX + 313, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(90124, StartX + 423, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);


		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gConfig.TextVN_DanhHieu[106]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gConfig.TextVN_DanhHieu[107]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gConfig.TextVN_DanhHieu[108]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gConfig.TextVN_DanhHieu[109]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gConfig.TextVN_DanhHieu[110]);

		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gConfig.TextVN_DanhHieu[111]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gConfig.TextVN_DanhHieu[112]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gConfig.TextVN_DanhHieu[113]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gConfig.TextVN_DanhHieu[114]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gConfig.TextVN_DanhHieu[115]);

		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gConfig.TextVN_DanhHieu[116]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gConfig.TextVN_DanhHieu[117]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gConfig.TextVN_DanhHieu[118]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gConfig.TextVN_DanhHieu[119]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gConfig.TextVN_DanhHieu[120]);

		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gConfig.TextVN_DanhHieu[121]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gConfig.TextVN_DanhHieu[122]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gConfig.TextVN_DanhHieu[123]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gConfig.TextVN_DanhHieu[124]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gConfig.TextVN_DanhHieu[125]);
		//=============================================================================================================================================================	
		break;


	case 7:
		if (gInterface.m_DanhHieu >= 25)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu >= 26)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu >= 27)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu >= 28)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(90125, StartX + 85, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(90126, StartX + 200, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(90127, StartX + 313, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(90128, StartX + 423, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);


		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gConfig.TextVN_DanhHieu[126]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gConfig.TextVN_DanhHieu[127]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gConfig.TextVN_DanhHieu[128]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gConfig.TextVN_DanhHieu[129]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gConfig.TextVN_DanhHieu[130]);

		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gConfig.TextVN_DanhHieu[131]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gConfig.TextVN_DanhHieu[132]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gConfig.TextVN_DanhHieu[133]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gConfig.TextVN_DanhHieu[134]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gConfig.TextVN_DanhHieu[135]);

		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gConfig.TextVN_DanhHieu[136]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gConfig.TextVN_DanhHieu[137]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gConfig.TextVN_DanhHieu[138]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gConfig.TextVN_DanhHieu[139]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gConfig.TextVN_DanhHieu[140]);

		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gConfig.TextVN_DanhHieu[141]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gConfig.TextVN_DanhHieu[142]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gConfig.TextVN_DanhHieu[143]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gConfig.TextVN_DanhHieu[144]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gConfig.TextVN_DanhHieu[145]);
		//=============================================================================================================================================================	
		break;


	case 8:
		if (gInterface.m_DanhHieu >= 29)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu >= 30)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu >= 31)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu >= 32)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(90129, StartX + 85, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(90130, StartX + 200, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(90131, StartX + 313, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(90132, StartX + 423, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);


		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gConfig.TextVN_DanhHieu[146]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gConfig.TextVN_DanhHieu[147]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gConfig.TextVN_DanhHieu[148]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gConfig.TextVN_DanhHieu[149]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gConfig.TextVN_DanhHieu[150]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gConfig.TextVN_DanhHieu[151]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gConfig.TextVN_DanhHieu[152]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gConfig.TextVN_DanhHieu[163]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gConfig.TextVN_DanhHieu[154]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gConfig.TextVN_DanhHieu[155]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gConfig.TextVN_DanhHieu[156]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gConfig.TextVN_DanhHieu[157]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gConfig.TextVN_DanhHieu[158]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gConfig.TextVN_DanhHieu[159]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gConfig.TextVN_DanhHieu[160]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gConfig.TextVN_DanhHieu[161]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gConfig.TextVN_DanhHieu[162]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gConfig.TextVN_DanhHieu[163]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gConfig.TextVN_DanhHieu[164]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gConfig.TextVN_DanhHieu[165]);
		//=============================================================================================================================================================	
		break;

	case 9:
		if (gInterface.m_DanhHieu >= 33)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu >= 34)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu >= 35)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu >= 36)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(90133, StartX + 85, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(90134, StartX + 200, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(90135, StartX + 313, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(90136, StartX + 423, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);


		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gConfig.TextVN_DanhHieu[166]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gConfig.TextVN_DanhHieu[167]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gConfig.TextVN_DanhHieu[168]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gConfig.TextVN_DanhHieu[169]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gConfig.TextVN_DanhHieu[170]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gConfig.TextVN_DanhHieu[171]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gConfig.TextVN_DanhHieu[172]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gConfig.TextVN_DanhHieu[173]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gConfig.TextVN_DanhHieu[174]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gConfig.TextVN_DanhHieu[175]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gConfig.TextVN_DanhHieu[176]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gConfig.TextVN_DanhHieu[177]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gConfig.TextVN_DanhHieu[178]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gConfig.TextVN_DanhHieu[179]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gConfig.TextVN_DanhHieu[180]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gConfig.TextVN_DanhHieu[181]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gConfig.TextVN_DanhHieu[182]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gConfig.TextVN_DanhHieu[183]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gConfig.TextVN_DanhHieu[184]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gConfig.TextVN_DanhHieu[185]);
		//=============================================================================================================================================================	
		break;


	case 10:
		if (gInterface.m_DanhHieu >= 37)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu >= 38)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu >= 39)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu >= 40)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(90137, StartX + 85, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(90138, StartX + 200, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(90139, StartX + 313, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(90140, StartX + 423, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);


		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gConfig.TextVN_DanhHieu[186]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gConfig.TextVN_DanhHieu[187]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gConfig.TextVN_DanhHieu[188]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gConfig.TextVN_DanhHieu[189]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gConfig.TextVN_DanhHieu[190]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gConfig.TextVN_DanhHieu[191]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gConfig.TextVN_DanhHieu[192]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gConfig.TextVN_DanhHieu[193]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gConfig.TextVN_DanhHieu[194]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gConfig.TextVN_DanhHieu[195]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gConfig.TextVN_DanhHieu[196]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gConfig.TextVN_DanhHieu[197]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gConfig.TextVN_DanhHieu[198]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gConfig.TextVN_DanhHieu[199]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gConfig.TextVN_DanhHieu[200]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gConfig.TextVN_DanhHieu[201]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gConfig.TextVN_DanhHieu[202]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gConfig.TextVN_DanhHieu[203]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gConfig.TextVN_DanhHieu[204]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gConfig.TextVN_DanhHieu[205]);
		//=============================================================================================================================================================	
		break;


	case 11:
		if (gInterface.m_DanhHieu >= 41)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu >= 42)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu >= 43)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu >= 44)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(90141, StartX + 85, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(90142, StartX + 200, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(90143, StartX + 313, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(90144, StartX + 423, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);


		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gConfig.TextVN_DanhHieu[206]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gConfig.TextVN_DanhHieu[207]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gConfig.TextVN_DanhHieu[208]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gConfig.TextVN_DanhHieu[209]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gConfig.TextVN_DanhHieu[210]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gConfig.TextVN_DanhHieu[211]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gConfig.TextVN_DanhHieu[212]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gConfig.TextVN_DanhHieu[213]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gConfig.TextVN_DanhHieu[214]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gConfig.TextVN_DanhHieu[215]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gConfig.TextVN_DanhHieu[216]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gConfig.TextVN_DanhHieu[217]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gConfig.TextVN_DanhHieu[218]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gConfig.TextVN_DanhHieu[219]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gConfig.TextVN_DanhHieu[220]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gConfig.TextVN_DanhHieu[221]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gConfig.TextVN_DanhHieu[222]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gConfig.TextVN_DanhHieu[223]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gConfig.TextVN_DanhHieu[224]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gConfig.TextVN_DanhHieu[225]);
		//=============================================================================================================================================================	
		break;


	case 12:
		if (gInterface.m_DanhHieu >= 45)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu >= 46)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu >= 47)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu >= 48)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(90145, StartX + 85, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(90146, StartX + 200, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(90147, StartX + 313, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(90148, StartX + 423, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 155, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);




		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gConfig.TextVN_DanhHieu[226]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gConfig.TextVN_DanhHieu[227]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gConfig.TextVN_DanhHieu[228]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gConfig.TextVN_DanhHieu[229]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gConfig.TextVN_DanhHieu[230]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gConfig.TextVN_DanhHieu[231]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gConfig.TextVN_DanhHieu[232]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gConfig.TextVN_DanhHieu[233]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gConfig.TextVN_DanhHieu[234]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gConfig.TextVN_DanhHieu[235]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gConfig.TextVN_DanhHieu[236]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gConfig.TextVN_DanhHieu[237]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gConfig.TextVN_DanhHieu[238]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gConfig.TextVN_DanhHieu[239]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gConfig.TextVN_DanhHieu[240]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 210, 210, 1, gConfig.TextVN_DanhHieu[241]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 230, 210, 1, gConfig.TextVN_DanhHieu[242]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 250, 210, 1, gConfig.TextVN_DanhHieu[243]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 270, 210, 1, gConfig.TextVN_DanhHieu[244]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_DANH_HIEU_MAIN].Y + 290, 210, 1, gConfig.TextVN_DanhHieu[245]);
		//=============================================================================================================================================================	
		break;


	default:
		break;
	}
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------
bool BEXO_DANH_HIEU::MAIN_DANH_HIEU(DWORD Event)
{
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	DWORD CurrentTick = GetTickCount();
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	this->CLOSE_DANH_HIEU(Event);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	// TRANG 1
	if (gInterface.Data[EXBEXO_DANH_HIEU_MAIN].OnShow && gInterface.IsWorkZone(EXBEXO_DANH_HIEU_NANG_CAP))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[EXBEXO_DANH_HIEU_NANG_CAP].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[EXBEXO_DANH_HIEU_NANG_CAP].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[EXBEXO_DANH_HIEU_NANG_CAP].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[EXBEXO_DANH_HIEU_NANG_CAP].EventTick = GetTickCount();
		//this->BUY_DANH_HIEU(1);
		this->BUY_DANH_HIEU(gInterface.m_DanhHieu);

	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
bool BEXO_DANH_HIEU::CLOSE_DANH_HIEU(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[EXBEXO_DANH_HIEU_CLOSE].EventTick);
	// ----
	if (!gInterface.Data[EXBEXO_DANH_HIEU_MAIN].OnShow || !gInterface.IsWorkZone(EXBEXO_DANH_HIEU_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[EXBEXO_DANH_HIEU_CLOSE].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[EXBEXO_DANH_HIEU_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[EXBEXO_DANH_HIEU_CLOSE].EventTick = GetTickCount();
	G_BEXO_DANH_HIEU.CLOSE_WINDOW_DANH_HIEU();
	// ----
	return false;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------
void BEXO_DANH_HIEU::BUY_DANH_HIEU(int Number)
{
	BUY_DANH_HIEU_REQ pMsg;
	pMsg.h.set(0xFC, 0x03, sizeof(pMsg)); // Gửi Xuống Server Protocol.cpp
	pMsg.Number = Number + 1;
	DataSend((BYTE*)&pMsg, pMsg.h.size);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------

#endif