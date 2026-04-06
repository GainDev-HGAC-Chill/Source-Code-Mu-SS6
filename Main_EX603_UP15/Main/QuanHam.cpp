#include "stdafx.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------
#include "QuanHam.h"
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
#if(QUAN_HAM_NEW == 1)
//-----------------------------------------------------------------------------------------------------------------------------------------------------
BEXO_QUAN_HAM G_BEXO_QUAN_HAM;
//-----------------------------------------------------------------------------------------------------------------------------------------------------

#define MAX_TRANG_QUAN_HAM    10  // OK

//-----------------------------------------------------------------------------------------------------------------------------------------------------
BEXO_QUAN_HAM::BEXO_QUAN_HAM()
{
	TRANG_QUAN_HAM = 1;
	//--------------------------------------------------------------
	HIENTHIQUAN_HAM = false;
	MainWidth = 640;
	MainHeight = 429;
	StartY = 0;
	StartX = 0;
	ClickTick = 0;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void BEXO_QUAN_HAM::DRAW_QUAN_HAM()
{
	DRAW_WINDOW_QUAN_HAM();
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void BEXO_QUAN_HAM::BEXO_CLICK_TRANG_QUAN_HAM(DWORD ClickMouse)
{
	if (!gInterface.Data[EXBEXO_QUAN_HAM_MAIN].OnShow)
	{
		return;
	}
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - ClickTick);
	if (gInterface.Data[EXBEXO_QUAN_HAM_MAIN].OnShow && gInterface.IsWorkZone(eQUAN_HAM1))
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
		if (1 < TRANG_QUAN_HAM && TRANG_QUAN_HAM <= MAX_TRANG_QUAN_HAM)
		{
			TRANG_QUAN_HAM--;
		}
		ClickTick = GetTickCount();
	}
	if (gInterface.Data[EXBEXO_QUAN_HAM_MAIN].OnShow && gInterface.IsWorkZone(eQUAN_HAM2))

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
		if (1 <= TRANG_QUAN_HAM && TRANG_QUAN_HAM < MAX_TRANG_QUAN_HAM)
		{
			TRANG_QUAN_HAM++;
		}
		ClickTick = GetTickCount();
	}
	if (TRANG_QUAN_HAM < 1)
	{
		TRANG_QUAN_HAM = 1;
	}
	if (TRANG_QUAN_HAM > TRANG_QUAN_HAM)
	{
		TRANG_QUAN_HAM = TRANG_QUAN_HAM;
	}
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------

void BEXO_QUAN_HAM::DRAW_WINDOW_QUAN_HAM()
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
	if (!gInterface.Data[EXBEXO_QUAN_HAM_MAIN].OnShow)
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
		gCentral.PrintDropBox(StartX + 70, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 50, 495, 300, 0.0, 0);

		gCentral.PrintDropBox(StartX + 95, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 85, 450, 60, 0.0, 0);
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

	gInterface.DrawFormat(eWhite, StartX + 280, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 60, 210, 1, "Nâng cấp Quân Hàm");

	gInterface.DrawFormat(eWhite, StartX + 115, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 90, 210, 1, gConfig.TextVN_QuanHam[0]);


	gInterface.DrawFormat(eYellow, StartX + 105, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 105, 210, 1, gConfig.TextVN_QuanHam[1], gObjUser.QUAN_HAM_WCOINC);


	gInterface.DrawFormat(eSocket, StartX + 105, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 120, 210, 1, gConfig.TextVN_QuanHam[2]);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawGUI(EXBEXO_QUAN_HAM_NANG_CAP, StartX + 435, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 100);

	if (gInterface.IsWorkZone(EXBEXO_QUAN_HAM_NANG_CAP))
	{
		DWORD Color = eGray150;

		gInterface.DrawColoredGUI(EXBEXO_QUAN_HAM_NANG_CAP, gInterface.Data[EXBEXO_QUAN_HAM_NANG_CAP].X, gInterface.Data[EXBEXO_QUAN_HAM_NANG_CAP].Y, Color);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawFormat(eAncient, StartX + 450, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 110, 210, 1, gConfig.TextVN_QuanHam[3]);

	gInterface.DrawFormat(eYellow, StartX + 270, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 132, 210, 1, gConfig.TextVN_QuanHam[4], gInterface.m_QuanHam);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawGUI(eQUAN_HAM1, StartX + 70, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 210);

	if (gInterface.IsWorkZone(eQUAN_HAM1))
	{
		DWORD Color = eGray150;

		gInterface.DrawColoredGUI(eQUAN_HAM1, gInterface.Data[eQUAN_HAM1].X, gInterface.Data[eQUAN_HAM1].Y, Color);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawGUI(eQUAN_HAM2, StartX + 535, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 210);

	if (gInterface.IsWorkZone(eQUAN_HAM2))
	{
		DWORD Color = eGray150;

		gInterface.DrawColoredGUI(eQUAN_HAM2, gInterface.Data[eQUAN_HAM2].X, gInterface.Data[eQUAN_HAM2].Y, Color);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawGUI(EXBEXO_QUAN_HAM_CLOSE, StartX + 532, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 52);
	if (gInterface.IsWorkZone(EXBEXO_QUAN_HAM_CLOSE))
	{
		DWORD Color = eGray150;
		gInterface.DrawColoredGUI(EXBEXO_QUAN_HAM_CLOSE, gInterface.Data[EXBEXO_QUAN_HAM_CLOSE].X, gInterface.Data[EXBEXO_QUAN_HAM_CLOSE].Y, Color);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	// Thanh Xanh Coin
	RenderBitmap(0x0897, StartX + 197, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 109, 210, 14, 0, 0, 1, 1, 1, 1, 0.0);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawFormat(eRed, StartX + 270, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 108, 210, 1, "WCoinC %d", Coin1);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		// Nền đen nằm text
		RenderBitmap(0x0896, StartX + 96, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(0x0896, StartX + 208, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(0x0896, StartX + 320, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(0x0896, StartX + 432, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	switch (TRANG_QUAN_HAM) //====================================================================================================================================
	{
		//=============================================================================================================================================================	
	case 1:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gInterface.m_QuanHam >= 1)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_QuanHam >= 2)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_QuanHam >= 3)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_QuanHam >= 4)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(10108, StartX + 100, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 165, 100, 40, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10109, StartX + 210, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 165, 100, 40, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10110, StartX + 325, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 165, 100, 40, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10111, StartX + 435, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 165, 100, 40, 0, 0, 1, 1, 1, 1, 0.0);

		gInterface.DrawFormat(eWhite, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 210, 210, 1, gConfig.TextVN_QuanHam[6]);
		gInterface.DrawFormat(eWhite, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 230, 210, 1, gConfig.TextVN_QuanHam[7]);
		gInterface.DrawFormat(eWhite, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 250, 210, 1, gConfig.TextVN_QuanHam[8]);
		gInterface.DrawFormat(eWhite, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 270, 210, 1, gConfig.TextVN_QuanHam[9]);
		gInterface.DrawFormat(eWhite, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 290, 210, 1, gConfig.TextVN_QuanHam[10]);

		gInterface.DrawFormat(eWhite, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 210, 210, 1, gConfig.TextVN_QuanHam[11]);
		gInterface.DrawFormat(eWhite, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 230, 210, 1, gConfig.TextVN_QuanHam[12]);
		gInterface.DrawFormat(eWhite, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 250, 210, 1, gConfig.TextVN_QuanHam[13]);
		gInterface.DrawFormat(eWhite, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 270, 210, 1, gConfig.TextVN_QuanHam[14]);
		gInterface.DrawFormat(eWhite, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 290, 210, 1, gConfig.TextVN_QuanHam[15]);

		gInterface.DrawFormat(eWhite, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 210, 210, 1, gConfig.TextVN_QuanHam[16]);
		gInterface.DrawFormat(eWhite, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 230, 210, 1, gConfig.TextVN_QuanHam[17]);
		gInterface.DrawFormat(eWhite, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 250, 210, 1, gConfig.TextVN_QuanHam[18]);
		gInterface.DrawFormat(eWhite, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 270, 210, 1, gConfig.TextVN_QuanHam[19]);
		gInterface.DrawFormat(eWhite, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 290, 210, 1, gConfig.TextVN_QuanHam[20]);

		gInterface.DrawFormat(eWhite, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 210, 210, 1, gConfig.TextVN_QuanHam[21]);
		gInterface.DrawFormat(eWhite, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 230, 210, 1, gConfig.TextVN_QuanHam[22]);
		gInterface.DrawFormat(eWhite, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 250, 210, 1, gConfig.TextVN_QuanHam[23]);
		gInterface.DrawFormat(eWhite, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 270, 210, 1, gConfig.TextVN_QuanHam[24]);
		gInterface.DrawFormat(eWhite, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 290, 210, 1, gConfig.TextVN_QuanHam[25]);

		//=============================================================================================================================================================	
		break;
	case 2:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gInterface.m_QuanHam >= 5)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_QuanHam >= 6)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_QuanHam >= 7)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_QuanHam >= 8)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(10112, StartX + 100, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 165, 100, 40, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10113, StartX + 210, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 165, 100, 40, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10114, StartX + 325, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 165, 100, 40, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10115, StartX + 435, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 165, 100, 40, 0, 0, 1, 1, 1, 1, 0.0);

		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eBlue, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 210, 210, 1, gConfig.TextVN_QuanHam[26]);
		gInterface.DrawFormat(eBlue, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 230, 210, 1, gConfig.TextVN_QuanHam[27]);
		gInterface.DrawFormat(eBlue, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 250, 210, 1, gConfig.TextVN_QuanHam[28]);
		gInterface.DrawFormat(eBlue, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 270, 210, 1, gConfig.TextVN_QuanHam[29]);
		gInterface.DrawFormat(eBlue, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 290, 210, 1, gConfig.TextVN_QuanHam[30]);

		gInterface.DrawFormat(eBlue, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 210, 210, 1, gConfig.TextVN_QuanHam[31]);
		gInterface.DrawFormat(eBlue, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 230, 210, 1, gConfig.TextVN_QuanHam[32]);
		gInterface.DrawFormat(eBlue, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 250, 210, 1, gConfig.TextVN_QuanHam[33]);
		gInterface.DrawFormat(eBlue, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 270, 210, 1, gConfig.TextVN_QuanHam[34]);
		gInterface.DrawFormat(eBlue, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 290, 210, 1, gConfig.TextVN_QuanHam[35]);

		gInterface.DrawFormat(eBlue, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 210, 210, 1, gConfig.TextVN_QuanHam[36]);
		gInterface.DrawFormat(eBlue, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 230, 210, 1, gConfig.TextVN_QuanHam[37]);
		gInterface.DrawFormat(eBlue, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 250, 210, 1, gConfig.TextVN_QuanHam[38]);
		gInterface.DrawFormat(eBlue, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 270, 210, 1, gConfig.TextVN_QuanHam[39]);
		gInterface.DrawFormat(eBlue, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 290, 210, 1, gConfig.TextVN_QuanHam[40]);

		gInterface.DrawFormat(eBlue, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 210, 210, 1, gConfig.TextVN_QuanHam[41]);
		gInterface.DrawFormat(eBlue, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 230, 210, 1, gConfig.TextVN_QuanHam[42]);
		gInterface.DrawFormat(eBlue, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 250, 210, 1, gConfig.TextVN_QuanHam[43]);
		gInterface.DrawFormat(eBlue, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 270, 210, 1, gConfig.TextVN_QuanHam[44]);
		gInterface.DrawFormat(eBlue, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 290, 210, 1, gConfig.TextVN_QuanHam[45]);
		//=============================================================================================================================================================	
		break;
	case 3:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gInterface.m_QuanHam >= 9)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_QuanHam >= 10)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_QuanHam >= 11)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_QuanHam >= 12)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(10116, StartX + 100, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 165, 100, 40, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10117, StartX + 210, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 165, 100, 40, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10118, StartX + 325, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 165, 100, 40, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10119, StartX + 435, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 165, 100, 40, 0, 0, 1, 1, 1, 1, 0.0);

		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 210, 210, 1, gConfig.TextVN_QuanHam[46]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 230, 210, 1, gConfig.TextVN_QuanHam[47]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 250, 210, 1, gConfig.TextVN_QuanHam[48]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 270, 210, 1, gConfig.TextVN_QuanHam[49]);
		gInterface.DrawFormat(eShinyGreen, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 290, 210, 1, gConfig.TextVN_QuanHam[50]);

		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 210, 210, 1, gConfig.TextVN_QuanHam[51]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 230, 210, 1, gConfig.TextVN_QuanHam[52]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 250, 210, 1, gConfig.TextVN_QuanHam[53]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 270, 210, 1, gConfig.TextVN_QuanHam[54]);
		gInterface.DrawFormat(eShinyGreen, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 290, 210, 1, gConfig.TextVN_QuanHam[55]);

		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 210, 210, 1, gConfig.TextVN_QuanHam[56]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 230, 210, 1, gConfig.TextVN_QuanHam[57]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 250, 210, 1, gConfig.TextVN_QuanHam[58]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 270, 210, 1, gConfig.TextVN_QuanHam[59]);
		gInterface.DrawFormat(eShinyGreen, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 290, 210, 1, gConfig.TextVN_QuanHam[60]);

		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 210, 210, 1, gConfig.TextVN_QuanHam[61]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 230, 210, 1, gConfig.TextVN_QuanHam[62]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 250, 210, 1, gConfig.TextVN_QuanHam[63]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 270, 210, 1, gConfig.TextVN_QuanHam[64]);
		gInterface.DrawFormat(eShinyGreen, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 290, 210, 1, gConfig.TextVN_QuanHam[65]);
		//=============================================================================================================================================================	
		break;
	case 4:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gInterface.m_QuanHam >= 13)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_QuanHam >= 14)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_QuanHam >= 15)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_QuanHam >= 16)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------

		RenderBitmap(10120, StartX + 100, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 165, 100, 40, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10121, StartX + 210, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 165, 100, 40, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10122, StartX + 325, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 165, 100, 40, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10123, StartX + 435, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 165, 100, 40, 0, 0, 1, 1, 1, 1, 0.0);

		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 210, 210, 1, gConfig.TextVN_QuanHam[66]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 230, 210, 1, gConfig.TextVN_QuanHam[67]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 250, 210, 1, gConfig.TextVN_QuanHam[68]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 270, 210, 1, gConfig.TextVN_QuanHam[69]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 290, 210, 1, gConfig.TextVN_QuanHam[70]);

		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 210, 210, 1, gConfig.TextVN_QuanHam[71]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 230, 210, 1, gConfig.TextVN_QuanHam[72]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 250, 210, 1, gConfig.TextVN_QuanHam[73]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 270, 210, 1, gConfig.TextVN_QuanHam[74]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 290, 210, 1, gConfig.TextVN_QuanHam[75]);

		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 210, 210, 1, gConfig.TextVN_QuanHam[76]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 230, 210, 1, gConfig.TextVN_QuanHam[77]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 250, 210, 1, gConfig.TextVN_QuanHam[78]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 270, 210, 1, gConfig.TextVN_QuanHam[79]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 290, 210, 1, gConfig.TextVN_QuanHam[80]);

		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 210, 210, 1, gConfig.TextVN_QuanHam[81]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 230, 210, 1, gConfig.TextVN_QuanHam[82]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 250, 210, 1, gConfig.TextVN_QuanHam[83]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 270, 210, 1, gConfig.TextVN_QuanHam[84]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 290, 210, 1, gConfig.TextVN_QuanHam[85]);
		//=============================================================================================================================================================	
		break;

	case 5:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gInterface.m_QuanHam >= 17)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_QuanHam >= 18)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_QuanHam >= 19)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_QuanHam >= 20)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(10124, StartX + 100, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 165, 100, 40, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10125, StartX + 210, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 165, 100, 40, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10126, StartX + 325, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 165, 100, 40, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10127, StartX + 435, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 165, 100, 40, 0, 0, 1, 1, 1, 1, 0.0);
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 210, 210, 1, gConfig.TextVN_QuanHam[86]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 230, 210, 1, gConfig.TextVN_QuanHam[87]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 250, 210, 1, gConfig.TextVN_QuanHam[88]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 270, 210, 1, gConfig.TextVN_QuanHam[89]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 290, 210, 1, gConfig.TextVN_QuanHam[90]);

		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 210, 210, 1, gConfig.TextVN_QuanHam[91]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 230, 210, 1, gConfig.TextVN_QuanHam[92]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 250, 210, 1, gConfig.TextVN_QuanHam[93]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 270, 210, 1, gConfig.TextVN_QuanHam[94]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 290, 210, 1, gConfig.TextVN_QuanHam[95]);

		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 210, 210, 1, gConfig.TextVN_QuanHam[96]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 230, 210, 1, gConfig.TextVN_QuanHam[97]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 250, 210, 1, gConfig.TextVN_QuanHam[98]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 270, 210, 1, gConfig.TextVN_QuanHam[99]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 290, 210, 1, gConfig.TextVN_QuanHam[100]);

		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 210, 210, 1, gConfig.TextVN_QuanHam[101]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 230, 210, 1, gConfig.TextVN_QuanHam[102]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 250, 210, 1, gConfig.TextVN_QuanHam[103]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 270, 210, 1, gConfig.TextVN_QuanHam[104]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 290, 210, 1, gConfig.TextVN_QuanHam[105]);
		//=============================================================================================================================================================	
		break;
	case 6:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gInterface.m_QuanHam >= 21)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_QuanHam >= 22)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_QuanHam >= 23)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_QuanHam >= 24)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(10128, StartX + 100, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 165, 100, 40, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10129, StartX + 210, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 165, 100, 40, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10130, StartX + 325, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 165, 100, 40, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10131, StartX + 435, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 165, 100, 40, 0, 0, 1, 1, 1, 1, 0.0);
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 210, 210, 1, gConfig.TextVN_QuanHam[106]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 230, 210, 1, gConfig.TextVN_QuanHam[107]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 250, 210, 1, gConfig.TextVN_QuanHam[108]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 270, 210, 1, gConfig.TextVN_QuanHam[109]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 290, 210, 1, gConfig.TextVN_QuanHam[110]);

		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 210, 210, 1, gConfig.TextVN_QuanHam[111]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 230, 210, 1, gConfig.TextVN_QuanHam[112]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 250, 210, 1, gConfig.TextVN_QuanHam[113]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 270, 210, 1, gConfig.TextVN_QuanHam[114]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 290, 210, 1, gConfig.TextVN_QuanHam[115]);

		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 210, 210, 1, gConfig.TextVN_QuanHam[116]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 230, 210, 1, gConfig.TextVN_QuanHam[117]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 250, 210, 1, gConfig.TextVN_QuanHam[118]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 270, 210, 1, gConfig.TextVN_QuanHam[119]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 290, 210, 1, gConfig.TextVN_QuanHam[120]);

		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 210, 210, 1, gConfig.TextVN_QuanHam[121]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 230, 210, 1, gConfig.TextVN_QuanHam[122]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 250, 210, 1, gConfig.TextVN_QuanHam[123]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 270, 210, 1, gConfig.TextVN_QuanHam[124]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 290, 210, 1, gConfig.TextVN_QuanHam[125]);
		//=============================================================================================================================================================	
		break;
	case 7:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gInterface.m_QuanHam >= 25)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_QuanHam >= 26)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_QuanHam >= 27)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_QuanHam >= 28)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(10132, StartX + 100, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 165, 100, 40, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10133, StartX + 210, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 165, 100, 40, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10134, StartX + 325, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 165, 100, 40, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10135, StartX + 435, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 165, 100, 40, 0, 0, 1, 1, 1, 1, 0.0);
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 210, 210, 1, gConfig.TextVN_QuanHam[126]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 230, 210, 1, gConfig.TextVN_QuanHam[127]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 250, 210, 1, gConfig.TextVN_QuanHam[128]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 270, 210, 1, gConfig.TextVN_QuanHam[129]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 290, 210, 1, gConfig.TextVN_QuanHam[130]);

		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 210, 210, 1, gConfig.TextVN_QuanHam[131]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 230, 210, 1, gConfig.TextVN_QuanHam[132]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 250, 210, 1, gConfig.TextVN_QuanHam[133]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 270, 210, 1, gConfig.TextVN_QuanHam[134]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 290, 210, 1, gConfig.TextVN_QuanHam[135]);

		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 210, 210, 1, gConfig.TextVN_QuanHam[136]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 230, 210, 1, gConfig.TextVN_QuanHam[137]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 250, 210, 1, gConfig.TextVN_QuanHam[138]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 270, 210, 1, gConfig.TextVN_QuanHam[139]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 290, 210, 1, gConfig.TextVN_QuanHam[140]);

		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 210, 210, 1, gConfig.TextVN_QuanHam[141]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 230, 210, 1, gConfig.TextVN_QuanHam[142]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 250, 210, 1, gConfig.TextVN_QuanHam[143]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 270, 210, 1, gConfig.TextVN_QuanHam[144]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 290, 210, 1, gConfig.TextVN_QuanHam[145]);
		//=============================================================================================================================================================	
		break;
	case 8:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gInterface.m_QuanHam >= 29)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_QuanHam >= 30)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_QuanHam >= 31)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_QuanHam >= 32)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(10136, StartX + 100, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 165, 100, 40, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10137, StartX + 210, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 165, 100, 40, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10138, StartX + 325, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 165, 100, 40, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10139, StartX + 435, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 165, 100, 40, 0, 0, 1, 1, 1, 1, 0.0);
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 210, 210, 1, gConfig.TextVN_QuanHam[146]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 230, 210, 1, gConfig.TextVN_QuanHam[147]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 250, 210, 1, gConfig.TextVN_QuanHam[148]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 270, 210, 1, gConfig.TextVN_QuanHam[149]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 290, 210, 1, gConfig.TextVN_QuanHam[150]);

		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 210, 210, 1, gConfig.TextVN_QuanHam[151]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 230, 210, 1, gConfig.TextVN_QuanHam[152]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 250, 210, 1, gConfig.TextVN_QuanHam[153]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 270, 210, 1, gConfig.TextVN_QuanHam[154]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 290, 210, 1, gConfig.TextVN_QuanHam[155]);

		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 210, 210, 1, gConfig.TextVN_QuanHam[156]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 230, 210, 1, gConfig.TextVN_QuanHam[157]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 250, 210, 1, gConfig.TextVN_QuanHam[158]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 270, 210, 1, gConfig.TextVN_QuanHam[159]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 290, 210, 1, gConfig.TextVN_QuanHam[160]);

		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 210, 210, 1, gConfig.TextVN_QuanHam[161]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 230, 210, 1, gConfig.TextVN_QuanHam[162]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 250, 210, 1, gConfig.TextVN_QuanHam[163]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 270, 210, 1, gConfig.TextVN_QuanHam[164]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 290, 210, 1, gConfig.TextVN_QuanHam[165]);
		//=============================================================================================================================================================	
		break;
	case 9:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gInterface.m_QuanHam >= 33)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_QuanHam >= 34)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_QuanHam >= 35)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_QuanHam >= 36)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(10140, StartX + 100, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 165, 100, 40, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10141, StartX + 210, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 165, 100, 40, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10142, StartX + 325, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 165, 100, 40, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10143, StartX + 435, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 165, 100, 40, 0, 0, 1, 1, 1, 1, 0.0);
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 210, 210, 1, gConfig.TextVN_QuanHam[166]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 230, 210, 1, gConfig.TextVN_QuanHam[167]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 250, 210, 1, gConfig.TextVN_QuanHam[168]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 270, 210, 1, gConfig.TextVN_QuanHam[169]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 290, 210, 1, gConfig.TextVN_QuanHam[170]);

		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 210, 210, 1, gConfig.TextVN_QuanHam[171]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 230, 210, 1, gConfig.TextVN_QuanHam[172]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 250, 210, 1, gConfig.TextVN_QuanHam[173]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 270, 210, 1, gConfig.TextVN_QuanHam[174]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 290, 210, 1, gConfig.TextVN_QuanHam[175]);

		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 210, 210, 1, gConfig.TextVN_QuanHam[176]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 230, 210, 1, gConfig.TextVN_QuanHam[177]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 250, 210, 1, gConfig.TextVN_QuanHam[178]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 270, 210, 1, gConfig.TextVN_QuanHam[179]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 290, 210, 1, gConfig.TextVN_QuanHam[180]);

		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 210, 210, 1, gConfig.TextVN_QuanHam[181]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 230, 210, 1, gConfig.TextVN_QuanHam[182]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 250, 210, 1, gConfig.TextVN_QuanHam[183]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 270, 210, 1, gConfig.TextVN_QuanHam[184]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 290, 210, 1, gConfig.TextVN_QuanHam[185]);
		//=============================================================================================================================================================	
		break;
	case 10:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gInterface.m_QuanHam >= 37)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_QuanHam >= 38)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_QuanHam >= 39)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_QuanHam >= 40)
		{
			RenderBitmap(0x0898, StartX + 432, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(10144, StartX + 100, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 165, 100, 40, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10145, StartX + 210, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 165, 100, 40, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10146, StartX + 325, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 165, 100, 40, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10147, StartX + 435, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 165, 100, 40, 0, 0, 1, 1, 1, 1, 0.0);
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 210, 210, 1, gConfig.TextVN_QuanHam[186]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 230, 210, 1, gConfig.TextVN_QuanHam[187]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 250, 210, 1, gConfig.TextVN_QuanHam[188]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 270, 210, 1, gConfig.TextVN_QuanHam[189]);
		gInterface.DrawFormat(eYellow, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 290, 210, 1, gConfig.TextVN_QuanHam[190]);

		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 210, 210, 1, gConfig.TextVN_QuanHam[191]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 230, 210, 1, gConfig.TextVN_QuanHam[192]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 250, 210, 1, gConfig.TextVN_QuanHam[193]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 270, 210, 1, gConfig.TextVN_QuanHam[194]);
		gInterface.DrawFormat(eYellow, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 290, 210, 1, gConfig.TextVN_QuanHam[195]);

		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 210, 210, 1, gConfig.TextVN_QuanHam[196]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 230, 210, 1, gConfig.TextVN_QuanHam[197]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 250, 210, 1, gConfig.TextVN_QuanHam[198]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 270, 210, 1, gConfig.TextVN_QuanHam[199]);
		gInterface.DrawFormat(eYellow, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 290, 210, 1, gConfig.TextVN_QuanHam[200]);

		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 210, 210, 1, gConfig.TextVN_QuanHam[201]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 230, 210, 1, gConfig.TextVN_QuanHam[202]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 250, 210, 1, gConfig.TextVN_QuanHam[203]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 270, 210, 1, gConfig.TextVN_QuanHam[204]);
		gInterface.DrawFormat(eYellow, StartX + 448, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 290, 210, 1, gConfig.TextVN_QuanHam[205]);
		//=============================================================================================================================================================	
		break;
	default:
		break;
	}
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
bool BEXO_QUAN_HAM::MAIN_QUAN_HAM(DWORD Event)
{
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	DWORD CurrentTick = GetTickCount();
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	this->CLOSE_QUAN_HAM(Event);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	// TRANG 1
	if (gInterface.Data[EXBEXO_QUAN_HAM_MAIN].OnShow && gInterface.IsWorkZone(EXBEXO_QUAN_HAM_NANG_CAP))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[EXBEXO_QUAN_HAM_NANG_CAP].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[EXBEXO_QUAN_HAM_NANG_CAP].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[EXBEXO_QUAN_HAM_NANG_CAP].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[EXBEXO_QUAN_HAM_NANG_CAP].EventTick = GetTickCount();
		//this->BUY_QUAN_HAM(1);
		this->BUY_QUAN_HAM(gInterface.m_QuanHam);

	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
bool BEXO_QUAN_HAM::CLOSE_QUAN_HAM(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[EXBEXO_QUAN_HAM_CLOSE].EventTick);
	// ----
	if (!gInterface.Data[EXBEXO_QUAN_HAM_MAIN].OnShow || !gInterface.IsWorkZone(EXBEXO_QUAN_HAM_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[EXBEXO_QUAN_HAM_CLOSE].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[EXBEXO_QUAN_HAM_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[EXBEXO_QUAN_HAM_CLOSE].EventTick = GetTickCount();
	G_BEXO_QUAN_HAM.CLOSE_WINDOW_QUAN_HAM();
	// ----
	return false;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------
void BEXO_QUAN_HAM::BUY_QUAN_HAM(int Number)
{
	BUY_QUAN_HAM_REQ pMsg;
	pMsg.h.set(0xFC, 0x04, sizeof(pMsg)); // Gửi Xuống Server Protocol.cpp
	pMsg.Number = Number + 1;
	DataSend((BYTE*)&pMsg, pMsg.h.size);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------

#endif