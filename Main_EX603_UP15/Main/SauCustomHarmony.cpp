// CustomMenu.cpp: implementation of the SauCustomHarmony class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#if (CUSTOM_HARMONY)
#include "SauCustomHarmony.h"
#include "MemScript.h"
#include "Util.h"
#include "Interface.h"
#include "Central.h"
#include "Defines.h"
#include "InterfaceElemental.h"
#include "User.h"
#include "CBUtil.h"
SauCustomHarmony gSauCustomHarmony;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SauCustomHarmony::SauCustomHarmony()
{
	this->Init();
}


SauCustomHarmony::~SauCustomHarmony()
{
}

void SauCustomHarmony::Init()
{
	this->m_HarmonyInfoList.clear();
	this->Harmony_ActiveMix = false;
	this->Harmony_EffectsMix = false;
	this->SetStateHarmony = false;
	this->Rate = 100;
	this->Price = 0;
	this->PriceType = -1;
	this->SoLuongDaTaoHoa = 0;
	this->IndexRandom = -1;
	memset(this->ItemChuaEp, 0, sizeof(this->ItemChuaEp));

}

char* SauCustomHarmony::GetNamePrice()
{
	switch (this->PriceType)
	{
	case 1:
		return "WC";
		break;
	case 2:
		return "WP";
		break;
	case 3:
		return "GP";
		break;
	}
	return "Zen";
}

void BackItemHarmony(int Type)
{
	if ((GetTickCount() - gInterface.Data[eWindowHarmony].EventTick) > 300)
	{
		XULY_CGPACKET pMsg;
		pMsg.header.set(0xD5, 0x2C, sizeof(pMsg));
		pMsg.ThaoTac = Type; //
		DataSend((LPBYTE)&pMsg, pMsg.header.size);
		gInterface.Data[eWindowHarmony].EventTick = GetTickCount();
	}
}
extern void* BCacheInfoItemDD;
extern DWORD CacheTimeShowInfoItem;
DWORD HarmonyEffect = 0;
extern void RenderMixEffect(int type, int x, int y, int w = 2, int h = 4);
void SauCustomHarmony::DrawHarmony()
{

	// ----
	if (gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::FriendList)
		|| gInterface.CheckWindow(ObjWindow::MoveList)
		|| gInterface.CheckWindow(ObjWindow::Party)
		|| gInterface.CheckWindow(ObjWindow::Quest)
		|| gInterface.CheckWindow(ObjWindow::NPC_Devin)
		|| gInterface.CheckWindow(ObjWindow::Guild)
		|| gInterface.CheckWindow(ObjWindow::Trade)
		|| gInterface.CheckWindow(ObjWindow::Warehouse)
		|| gInterface.CheckWindow(ObjWindow::ChaosBox)
		|| gInterface.CheckWindow(ObjWindow::CommandWindow)
		|| gInterface.CheckWindow(ObjWindow::PetInfo)
		|| gInterface.CheckWindow(ObjWindow::Shop)
		//|| gInterface.CheckWindow(ObjWindow::Inventory)
		|| gInterface.CheckWindow(ObjWindow::Store)
		|| gInterface.CheckWindow(ObjWindow::OtherStore)
		|| gInterface.CheckWindow(ObjWindow::Character)
		|| gInterface.CheckWindow(ObjWindow::DevilSquare)
		|| gInterface.CheckWindow(ObjWindow::BloodCastle)
		|| gInterface.CheckWindow(ObjWindow::CreateGuild)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC)
		|| gInterface.CheckWindow(ObjWindow::SeniorNPC)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC2)
		|| gInterface.CheckWindow(ObjWindow::CastleGateSwitch)
		|| gInterface.CheckWindow(ObjWindow::CatapultNPC)
		|| gInterface.CheckWindow(ObjWindow::CrywolfGate)
		|| gInterface.CheckWindow(ObjWindow::IllusionTemple)
		|| gInterface.CheckWindow(ObjWindow::HeroList)
		|| gInterface.CheckWindow(ObjWindow::ChatWindow)
		|| gInterface.CheckWindow(ObjWindow::FastMenu)
		|| gInterface.CheckWindow(ObjWindow::Options)
		|| gInterface.CheckWindow(ObjWindow::Help)
		|| gInterface.CheckWindow(ObjWindow::FastDial)
		|| gInterface.CheckWindow(ObjWindow::SkillTree)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher1)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher2)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin1)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin2)
		|| gInterface.CheckWindow(ObjWindow::NPC_Duel)
		|| gInterface.CheckWindow(ObjWindow::NPC_Titus)
		|| gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::Lugard)
		|| gInterface.CheckWindow(ObjWindow::QuestList1)
		|| gInterface.CheckWindow(ObjWindow::QuestList2)
		|| gInterface.CheckWindow(ObjWindow::Jerint)
		|| gInterface.CheckWindow(ObjWindow::FullMap)
		|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)
		|| gInterface.CheckWindow(ObjWindow::GensInfo)
		|| gInterface.CheckWindow(ObjWindow::NPC_Julia)
		|| gInterface.CheckWindow(ObjWindow::NPC_ChaosMix)
		|| gInterface.CheckWindow(ObjWindow::ExpandInventory)
		|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse)
		|| gInterface.CheckWindow(ObjWindow::MuHelper))
	{
		if (gInterface.Data[eWindowHarmony].OnShow == true)
		{
			gInterface.Data[eWindowHarmony].OnShow = false;
			pSetCursorFocus = false;
			return;
		}
	}

	if (!gInterface.Data[eWindowHarmony].OnShow)
	{
		if (gSauCustomHarmony.SetStateHarmony == 1)
		{

			XULY_CGPACKET pMsg;
			pMsg.header.set(0xD5, 0x2A, sizeof(pMsg));
			pMsg.ThaoTac = 111; //
			DataSend((LPBYTE)&pMsg, pMsg.header.size);
			this->SetStateHarmony = false;
			this->Harmony_ActiveMix = false;
			this->Harmony_EffectsMix = false;
		}

		return;
	}
	if (pCheckWindow(pWindowThis(), Inventory) == false)
	{
		pOpenWindow(pWindowThis(), Inventory);
	}
	if (pCheckWindow(pWindowThis(), Character) == true)
	{
		pCloseWindow(pWindowThis(), Character);
	}

	float StartX = 10;
	float StartY = 20;
	float WindowW = 280;
	float WindowH = 280;
	int CheckItemOK = 0;
	gElemental.gDrawWindowCustom(StartX, StartY, WindowW, WindowH, eWindowHarmony, "Harmony");
	//if (!gCentral.GiaoDienCash( &StartX, &StartY, WindowW, WindowH,"Harmony"))
	{

		float BoxItemWH = 35;
		//===Item Chinh
		float PosXGroup1 = StartX + 20;
		float PosYGroup1 = StartY + 40;
		gElemental.gInfoBox(PosXGroup1 - 10, PosYGroup1 - 5, WindowW - 30, 90, 0x00000096, 0, 0);

		gElemental.gInfoBox(PosXGroup1 - 10, PosYGroup1 - 5 + 120, WindowW - 30, 90, 0x00000096, 0, 0);

		gElemental.DrawText((HFONT)pFontBold, PosXGroup1, PosYGroup1 + 5, 0xEBA000FF, 0x0, 0, 0, 1, "Item Ép Tạo Hoá");//

		//===Box Item Chinh
		gElemental.gInfoBox(PosXGroup1 + 20, PosYGroup1 + 20, BoxItemWH, BoxItemWH, 0x00000096, 0, 0); // Chinh

		ObjectItem* CTItemChinh = &*(ObjectItem*)(BPConvertByteItem(*(DWORD*)(GetInstance() + 36), gSauCustomHarmony.ItemChuaEp));
		if (CTItemChinh->ItemID > 0)
		{
			gCBUtil.DrawItem3D(PosXGroup1 + 20, (PosYGroup1 + 20) + 7, BoxItemWH, BoxItemWH, CTItemChinh->ItemID, CTItemChinh->Level, CTItemChinh->ExcellentOption, CTItemChinh->AncientOption, 0, 1.0);//BMD MOdel
			if (pCheckMouseOver(PosXGroup1 + 20, PosYGroup1 + 20, 50, 50) == 1)
			{
				BCacheInfoItemDD = CTItemChinh;
				CacheTimeShowInfoItem = GetTickCount() + 50;
				if (GetKeyState(VK_RBUTTON) & 0x8000)
				{
					BackItemHarmony(0);
				}
			}
		}
		pDrawColorButton(71520, PosXGroup1, PosYGroup1 + 75, (WindowW - 40), 1, 0, 0, pMakeColor(158, 158, 158, 130));//-- Divisor
		gElemental.gInfoBox(PosXGroup1 + ((WindowW - 40) / 2) + 70, PosYGroup1 + 20, BoxItemWH, BoxItemWH, 0x00000096, 0, 0); //
		gCBUtil.DrawItem3D(PosXGroup1 + ((WindowW - 40) / 2) + 70, (PosYGroup1 + 20) + 7, BoxItemWH, BoxItemWH, 7210, 0, 0, 0, 0, 1.0);//BMD MOdel
		gElemental.DrawText((HFONT)pFontBold, PosXGroup1 + 170, PosYGroup1 + 5, 0xEBA000FF, 0x0, 0, 0, 1, "Số Ngọc [%s]/1", BNumberFormat(this->SoLuongDaTaoHoa));//

		gElemental.DrawText((HFONT)pFontBold, PosXGroup1 + 120, PosYGroup1 + 70, 0xEBA000FF, 0x0, 0, 0, 1, "[%s]", BNumberFormat(this->Price));//
		gElemental.DrawText((HFONT)pFontBold, PosXGroup1 + 60, PosYGroup1 + 70, 0xEBA000FF, 0x0, 0, 0, 1, "Cần Có [%s]", this->GetNamePrice());//
		float ButtonW = 80;
		float ButtonH = 25;
		float ButtonX = PosXGroup1 + ((WindowW - 40) / 2) - (ButtonW / 2);
		float ButtonY = (StartY + WindowH) - 20 - ButtonH;
		//if (gElemental.gDrawButton(ButtonX, ButtonY, ButtonW, 12, "Dung Luyện")) //Dung Luyen
		if (this->Harmony_EffectsMix && HarmonyEffect > GetTickCount() && HarmonyEffect != 0)
		{
			RenderMixEffect(this->Harmony_EffectsMix, PosXGroup1 + 50, PosYGroup1 + 120, 5, 1);
			RenderMixEffect(this->Harmony_EffectsMix, PosXGroup1 + 50, PosYGroup1 + 140, 5, 1);
			RenderMixEffect(this->Harmony_EffectsMix, PosXGroup1 + 50, PosYGroup1 + 160, 5, 1);

			RenderMixEffect(this->Harmony_EffectsMix, PosXGroup1 + 50, PosYGroup1 + 180, 5, 1);

			gElemental.DrawText((HFONT)pFontBold, PosXGroup1 - 10, PosYGroup1 + 120, 0xEBA000FF, 0x0, WindowW, 0, 3, "[%s]", m_HarmonyInfoList[rand() % this->m_HarmonyInfoList.size()].Name);//
			gElemental.DrawText((HFONT)pFontBold, PosXGroup1 - 10, PosYGroup1 + 140, 0xEBA000FF, 0x0, WindowW, 0, 3, "[%s]", m_HarmonyInfoList[rand() % this->m_HarmonyInfoList.size()].Name);//
			gElemental.DrawText((HFONT)pFontBold, PosXGroup1 - 10, PosYGroup1 + 160, 0xEBA000FF, 0x0, WindowW, 0, 3, "[%s]", m_HarmonyInfoList[rand() % this->m_HarmonyInfoList.size()].Name);//
			gElemental.DrawText((HFONT)pFontBold, PosXGroup1 - 10, PosYGroup1 + 180, 0xEBA000FF, 0x0, WindowW, 0, 3, "[%s]", m_HarmonyInfoList[rand() % this->m_HarmonyInfoList.size()].Name);//

		}
		else if (HarmonyEffect != 0)
		{


			HarmonyEffect = 0;
			if (this->Harmony_ActiveMix)
			{
				if ((GetTickCount() - gInterface.Data[eWindowHarmony].EventTick) > 300 && HarmonyEffect == 0)
				{
					XULY_CGPACKET pMsg;
					pMsg.header.set(0xD5, 0x2D, sizeof(pMsg));
					pMsg.ThaoTac = 113; //
					DataSend((LPBYTE)&pMsg, pMsg.header.size);
					gInterface.Data[eWindowHarmony].EventTick = GetTickCount();

				}


			}
		}
		if (this->IndexRandom != -1)
		{
			gElemental.DrawText((HFONT)pFontBold, PosXGroup1 - 10, PosYGroup1 + 150, 0xEBA000FF, 0x0, WindowW, 0, 3, "[%s]", m_HarmonyInfoList[this->IndexRandom].Name);//
		}

		if (gElemental.gDrawButton(ButtonX - 70, ButtonY + 20, ButtonW, 12, "Xoay"))
		{
			if (this->Harmony_ActiveMix)
			{

				this->Harmony_EffectsMix = 1;

			}
			else
			{
				gElemental.OpenMessageBox("Error", "Vui Long Cho");
			}
			HarmonyEffect = GetTickCount() + 2000;
			this->IndexRandom = -1;

		}

		if (gElemental.gDrawButton(ButtonX + 80, ButtonY + 20, ButtonW, 12, "Nhận"))
		{
			BackItemHarmony(4);
		}


	}
}

void SauCustomHarmony::RecvHarmony(CSEV_COUNTLIST* lpMsg) // OK
{
	m_HarmonyInfoList.clear();

	for (int n = 0; n < lpMsg->Count; n++)
	{
		OPTITEM* lpInfo = (OPTITEM*)(((BYTE*)lpMsg) + sizeof(CSEV_COUNTLIST)+(sizeof(OPTITEM)* n));

		m_HarmonyInfoList.push_back(*lpInfo);


	}

}
#endif