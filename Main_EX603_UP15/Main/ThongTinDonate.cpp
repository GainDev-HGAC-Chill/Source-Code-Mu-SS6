#include "stdafx.h"
#include "ThongTinDonate.h"
#include "User.h"
#include "Interface.h"
#include "WindowsStruct.h"
#include "Defines.h"
#include "Offset.h"
#include "Central.h"
#include "Util.h"
#include "TMemory.h"
#include "OffTrade.h"
#include "SItemOption.h"
#include "PrintPlayer.h"
#include "CustomFont.h"
#include "Font.h"

ThongTinDonate gThongTinDonate;

ThongTinDonate::ThongTinDonate()
{
}

ThongTinDonate::~ThongTinDonate()
{
}

void ThongTinDonate::ThongTinDonateOpen()
{
	if (!gInterface.Data[eThongTinDonnate].OnShow)
	{
		return;
	}

	float StartX = 220.0f;
	float StartY = 45.0;
	//--
	float WindowW = 210.0f;
	float WindowH = 300;
	//--
	gCentral.gDrawWindowCustom(StartX, StartY, WindowW, WindowH, eThongTinDonnate, "DONATE");


	//CustomFont.Draw(CustomFont.FontBold, StartX + 20, StartY + 40, 0xFFDE26FF, 0x0, 125, 0, 3, "★Ủng Hộ Donate Game★");
	//CustomFont.Draw(CustomFont.FontBold, StartX + 20, StartY + 50, 0xFFDE26FF, 0x0, 125, 0, 3, "★STK: 109874947481★");
	//CustomFont.Draw(CustomFont.FontBold, StartX + 20, StartY + 60, 0xFFDE26FF, 0x0, 125, 0, 3, "★Ngân Hàng: VIETINBANK★");
	//CustomFont.Draw(CustomFont.FontBold, StartX + 20, StartY + 70, 0xFFDE26FF, 0x0, 125, 0, 3, "★Tên Tài Khoản: VU VAN HIEU★");
	//CustomFont.Draw(CustomFont.FontBold, StartX + 20, StartY + 80, 0xFFDE26FF, 0x0, 125, 0, 3, "★SDT: 0962.895.867★");


	if (gInterface.gDrawButtonThongTinDonate(StartX + 60, StartY + 260)) //
	{
		if (GetForegroundWindow() == pGameWindow)
		{
			if (GetForegroundWindow() == pGameWindow)
			{
				ShellExecute(NULL, "open", gCustomMessage.GetMessage(173), NULL, NULL, SW_MAXIMIZE); //FACEBOOOK
			}
		}
	}


}

void ThongTinDonate::Load()
{

}