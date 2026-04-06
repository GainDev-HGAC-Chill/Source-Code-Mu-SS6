#include "stdafx.h"
#include "Common.h"
#include "CustomCommandInfo.h"
#include "CustomEventTime.h"
#include "CustomRanking.h"
#include "Interface.h"
#include "Import.h"
#include "Reconnect.h"
#include "TMemory.h"
#include "Defines.h"
#include "OffTrade.h"
#include "Protect.h"
#include "Protocol.h"
#include "PrintPlayer.h"
#include "User.h"
#include "Util.h"
#include "array.h"
#include "Offset.h"
#include "StatsAdvance.h"
#include "CustomCloak.h"
#include "ChatExpanded.h"
#include "Camera.h"
#include "TrayModeNew.h"
#include "Controller.h"
#include "postInterface.h"
#include "Ruud.h"
#include "Inter3.h"
#include "InterEx.h"
#include "Central.h"
#include "NPCRuud.h"
#include "CustomFont.h"
#include "CustomEventTime.h"
#include "CMacroUIEx.h"
#include "PartySearchSettings.h"
#include "PartySearch.h"
#include "Config.h"
#include "time.h"
#include "SItemOption.h"
#include "EmojiSystem.h"
#include "MiniMap.h"
#include "WindowsStruct.h"
#include "DanhHieu.h"
#include "QuanHam.h"
#include "TuLuyen.h"
#include "HuyHieuCuongHoa.h"
#include "CustomRankUser.h"
#include "ThueFlag.h"
#include "CustomOfflineMode.h"
#include "RoyalBattleGround.h"
#include "NewInterface.h"
#include "UIControl.h"
#include "ResetSystem.h"
#include "GuildUpgrade.h"
#include "ThongTinDonate.h"

#include "CBUtil.h"
#include "CBNewUiEx.h"
#include "InterfaceElemental.h"
#include "SauCustomHarmony.h"
#include "UIController.h"
#include "CNewUIWindowsClient.h"
#if(THONG_TIN_BOSS)
#include "ActiveInvasions.h"
#endif

Interface gInterface;

Interface::Interface()
{
}

Interface::~Interface()
{
}



void Interface::RenderObjectSystem()
{
	if (gProtect.m_MainInfo.MonitorMS == 1){
		gInterface.lastReport = GetTickCount();
		gInterface.frameCount = 0;
	}

	if (gProtect.m_MainInfo.MonitorFPS == 1){
		gInterface.iniciador = 1;
	}
	this->BindObject(eMenu_MAIN, 0x7A5A, 222, 300, 205, -1);
	this->BindObject(eMenu_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eMenu_OPT1, 0x7A5E, 108, 30.5f, -1, -1);
	this->BindObject(eMenu_OPT2, 0x7A5E, 108, 30.5f, -1, -1);
	this->BindObject(eMenu_OPT3, 0x7A5E, 108, 30.5f, -1, -1);
	this->BindObject(eMenu_OPT4, 0x7A5E, 108, 30.5f, -1, -1);
	this->BindObject(eMenu_OPT5, 0x7A5E, 108, 30.5f, -1, -1);
	this->BindObject(eMenu_OPT6, 0x7A5E, 108, 30.5f, -1, -1);
	this->BindObject(eMenu_OPT7, 0x7A5E, 108, 30.5f, -1, -1);
	this->BindObject(eMenu_OPT8, 0x7A5E, 108, 30.5f, -1, -1);
	this->BindObject(eMenu_OPT9, 0x7A5E, 108, 30.5f, -1, -1);
	this->BindObject(eMenu_OPT10, 0x7A5E, 108, 30.5f, -1, -1);
	this->BindObject(eMenu_OPT11, 0x7A5E, 108, 30.5f, -1, -1);
	this->BindObject(eMenu_OPT12, 0x7A5E, 108, 30.5f, -1, -1);
	this->BindObject(eMenu_OPT13, 0x7A5E, 108, 30.5f, -1, -1);
	this->BindObject(eMenu_OPT14, 0x7A5E, 108, 30.5f, -1, -1);
	this->BindObject(eMenu_OPT15, 0x7A5E, 108, 30.5f, -1, -1);
	this->BindObject(eMenu_OPT16, 0x7A5E, 108, 30.5f, -1, -1);
	this->BindObject(eMenu_OPT17, 0x7A5E, 108, 30.5f, -1, -1);

	//button event
	//--
	this->BindObject(eTIME, 0x787F, 131, 70, -10, 349);
	this->BindObject(eFlag01, 0x7880, 78, 78, -1, -1);
	this->BindObject(eFlag02, 0x7881, 78, 78, -1, -1);
	this->BindObject(eFlag03, 0x7882, 78, 78, -1, -1);
	this->BindObject(eFlag04, 0x7883, 78, 78, -1, -1);
	this->BindObject(eFlag05, 0x7884, 78, 78, -1, -1);
	this->BindObject(eFlag06, 0x7885, 78, 78, -1, -1);
	this->BindObject(eFlag07, 0x7886, 78, 78, -1, -1);
	this->BindObject(eFlag08, 0x7887, 78, 78, -1, -1);
	this->BindObject(eFlag09, 0x7888, 78, 78, -1, -1);
	this->BindObject(eFlag10, 0x7889, 78, 78, -1, -1);
	this->BindObject(eFlag11, 0x7890, 78, 78, -1, -1);
	this->BindObject(eFlag12, 0x7891, 78, 78, -1, -1);
	this->BindObject(eFlag13, 0x7892, 78, 78, -1, -1);
	this->BindObject(eFlag14, 0x7893, 78, 78, -1, -1);
	this->BindObject(eFlag15, 0x7894, 78, 78, -1, -1);
	this->BindObject(eFlag16, 0x7895, 78, 78, -1, -1);
	this->BindObject(eFlag17, 0x7896, 78, 78, -1, -1);
	this->BindObject(eFlag18, 0x7897, 78, 78, -1, -1);
	this->BindObject(eFlag19, 0x7898, 78, 78, -1, -1);
	this->BindObject(eFlag20, 0x7899, 78, 78, -1, -1);
	this->BindObject(eFlag21, 0x7900, 78, 78, -1, -1);

	this->BindObject(eFlag22, 0x7901, 78, 78, -1, -1);
	this->BindObject(eFlag23, 0x7911, 78, 78, -1, -1);
	this->BindObject(eFlag24, 0x7912, 78, 78, -1, -1);
	this->BindObject(eFlag25, 0x7913, 78, 78, -1, -1);
	this->BindObject(eFlag26, 0x7914, 78, 78, -1, -1);
	this->BindObject(eFlag27, 0x7915, 78, 78, -1, -1);
	this->BindObject(eFlag28, 0x7916, 78, 78, -1, -1);
	this->BindObject(eFlag29, 0x7917, 78, 78, -1, -1);
	this->BindObject(eFlag30, 0x7918, 78, 78, -1, -1);
	this->BindObject(eFlag31, 0x7919, 78, 78, -1, -1);

	//--
	this->BindObject(eRanking, 0x7902, 179, 27, -1, -1);
	this->BindObject(eSAMPLEBUTTON, 0x7903, 25, 40, -1, -1);
	this->BindObject(eSAMPLEBUTTON2, 0x7904, 25, 40, -1, -1);
	//--
	this->BindObject(eVip_MAIN, 0x7A5A, 222, 300, 205, -1);
	this->BindObject(eVip_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eVip_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eVip_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eVip_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eVip_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eVip_BRONZE, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eVip_SILVER, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eVip_GOLD, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eVip_PLATINUM, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eVip_STATUS, 0x7A5E, 108, 29, -1, -1);

	//--
	this->BindObject(eCommand_MAIN, 0x7A5A, 222, 300, 205, -1);
	this->BindObject(eCommand_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eCommand_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eCommand_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eCommand_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eCommand_CLOSE, 0x7EC5, 36, 29, -1, -1);
	//--
#if(RANKINGGOC == 1)
	//this->BindObject(eRanking_MAIN, 0x7A5A, 222, 300, 205, -1);
	//this->BindObject(eRanking_CLOSE, 0x7EC5, 36, 29, -1, -1);
#endif
	this->BindObject(eEventTime_MAIN, 0x7A5A, 222, 300, 205, -1);
	this->BindObject(eEventTime_CLOSE, 0x7EC5, 36, 29, -1, -1);
	//--
	this->BindObject(eCONFIRM_MAIN, 0x7A5A, 222, 120, 205, -1);
	this->BindObject(eCONFIRM_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eCONFIRM_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eCONFIRM_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eCONFIRM_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eCONFIRM_BTN_OK, 0x7A5B, 54, 30, -1, -1);
	this->BindObject(eCONFIRM_BTN_CANCEL, 0x7A5C, 54, 30, -1, -1);
	this->BindObject(eLogo, 0x7905, 150, 114, -1, -1);
	//Custom Store
	if (gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		this->BindObject(eOFFTRADE_JoB, 51522, 40, 17, -1, -1);
		this->BindObject(eOFFTRADE_JoS, 51522, 40, 17, -1, -1);
		this->BindObject(eOFFTRADE_JoC, 51522, 40, 17, -1, -1);
		this->BindObject(eOFFTRADE_WCC, 51522, 40, 17, -1, -1);
		this->BindObject(eOFFTRADE_WCP, 51522, 40, 17, -1, -1);
		this->BindObject(eOFFTRADE_WCG, 51522, 40, 17, -1, -1);
		this->BindObject(eOFFTRADE_OPEN, 51522, 108, 30, -1, -1);
	}
	else
	{
		this->BindObject(eOFFTRADE_JoB, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_JoS, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_JoC, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_WCC, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_WCP, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_WCG, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_OPEN, 0x7BFD, 108, 30, -1, -1);
	}
	//-- custom
	this->BindObject(eSTORE_CLOSE, 0x7BFD, 108, 30, -1, -1);
	//Minimap
	this->BindObject(ePLAYER_POINT, 31460, 3, 3, -1, -1);
	this->BindObject(eNULL_MAP, 31461, 128, 128, -1, -1);
	this->BindObject(eLORENCIA_MAP, 31462, 128, 128, -1, -1);
	this->BindObject(eDUNGEON_MAP, 31463, 128, 128, -1, -1);
	this->BindObject(eDEVIAS_MAP, 31464, 128, 128, -1, -1);
	this->BindObject(eNORIA_MAP, 31465, 128, 128, -1, -1);
	this->BindObject(eLOSTTOWER_MAP, 31466, 128, 128, -1, -1);
	this->BindObject(eSTADIUM_MAP, 61465, 128, 128, -1, -1);
	this->BindObject(eATLANS_MAP, 31467, 128, 128, -1, -1);
	this->BindObject(eTarkan_MAP, 31468, 128, 128, -1, -1);
	this->BindObject(eElbeland_MAP, 31469, 128, 128, -1, -1);
	this->BindObject(eICARUS_MAP, 31470, 128, 128, -1, -1);
	this->BindObject(eLANDOFTRIALS_MAP, 31461, 128, 128, -1, -1);
	this->BindObject(eAIDA_MAP, 31472, 128, 128, -1, -1);
	this->BindObject(eCRYWOLF_MAP, 31473, 128, 128, -1, -1);
	this->BindObject(eKANTRU_MAP, 31474, 128, 128, -1, -1);
	this->BindObject(eKANTRU3_MAP, 31475, 128, 128, -1, -1);
	this->BindObject(eBARRACKS_MAP, 31476, 128, 128, -1, -1);
	this->BindObject(eCALMNESS_MAP, 31477, 128, 128, -1, -1);
	this->BindObject(eRAKLION_MAP, 31478, 128, 128, -1, -1);
	this->BindObject(eVULCANUS_MAP, 31479, 128, 128, -1, -1);
	this->BindObject(eKALRUTAN_MAP, 31480, 128, 128, -1, -1);
	this->BindObject(eKALRUTAN2_MAP, 31481, 128, 128, -1, -1);
	this->BindObject(eNextCommand, 31659, 17, 18, -1, -1);
	this->BindObject(ePrevCommand, 31658, 17, 18, -1, -1);
	this->BindObject(eNextEvent, 31659, 17, 18, -1, -1);
	this->BindObject(ePrevEvent, 31658, 17, 18, -1, -1);
	this->BindObject(eCamera3DInit, 31659, 17, 18, -1, -1);
	this->BindObject(eCamera3DSwitch, 31659, 17, 18, -1, -1);

	this->Data[eTIME].OnShow = true;
	if (gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4)
	{
		this->BindObject(ButtonSettings, 51522, 19, 19, -1, -1);
		this->BindObject(ButtonStart, 51522, 19, 19, -1, -1);
		this->BindObject(ButtonStop, 51522, 19, 19, -1, -1);
	}
	else
	{
		this->BindObject(ButtonSettings, 31761, 18, 13.3, -1, -1);
		this->BindObject(ButtonStart, 31762, 18, 13.3, -1, -1);
		this->BindObject(ButtonStop, 31763, 18, 13.3, -1, -1);
	}
	this->BindObject(ButtonStartAttack, 31593, 15, 15, -15, -15);
	//--

	this->BindObject(eButtonOption1, 31593, 15, 15, -1, -1);
	this->BindObject(eButtonOption2, 31593, 15, 15, -1, -1);
	this->BindObject(eButtonOption3, 31593, 15, 15, -1, -1);
	this->BindObject(eButtonOption4, 31593, 15, 15, -1, -1);
	this->BindObject(eButtonOption5, 31593, 15, 15, -1, -1);
	this->BindObject(eButtonOption6, 31593, 15, 15, -1, -1);
	this->BindObject(eButtonOption7, 31593, 15, 15, -1, -1);
	this->BindObject(eButtonOption8, 31593, 15, 15, -1, -1);
	//this->BindObject(eCloseOption, 71521, 59, 28, -1, -1);



	switch (gProtect.m_MainInfo.CustomInterfaceType)
	{
	case 1:
	case 2:
		//--
		if (gProtect.m_MainInfo.CustomMenuType == 1)
		{
			this->BindObject(eMenu, 0x7906, 102, 29, -1, -1);
		}
		else
		{
			this->BindObject(eMenu, 0x7906, 16, 12, -1, -1);
			this->BindObject(eMenuBG, 0x7907, 36, 18, 174, 0);
		}
		//--

		//newminimap
		this->BindObject(MINIMAP_FRAME, 31608, 154, 162, -10, 359);

		this->BindObject(MINIMAP_TIME_FRAME, 31609, 134.0, 37.0, -10, 359);
		this->BindObject(MINIMAP_BUTTOM, 31617, 38.0f, 24.0f, -10, 569);
		//---
		this->BindObject(eDragonLeft, 2337, 108.0, 45.0, 0.0, 385);
		this->BindObject(eDragonRight, 2336, 108.0, 45.0, 532.0, 385);
		this->BindObject(eParty, iNewParty, 25, 25, 348, 449);
		this->BindObject(eCharacter, iNewCharacter, 25, 25, 379, 449);
		this->BindObject(eInventory, iNewInventory, 25, 25, 409, 449);
		this->BindObject(eFriend, iNewWinpush, 52, 18, 581, 432);

		if (gProtect.m_MainInfo.CustomInterfaceType == 2)
		{
			this->BindObject(eFastMenu, iNewFastMenu, 53, 19, 5, 432);
		}
		this->BindObject(eGuild, iNewGuild, 52, 18, 581, 454);
		break;
	case 3:
	case 4:
		this->BindObject(eButton1, 61525, 43.0f, 17.0f, -43.0f, -17.0f);
		this->BindObject(eButton2, 61525, 43.0f, 17.0f, -43.0f, -17.0f);
		this->BindObject(eButton3, 61525, 43.0f, 17.0f, -43.0f, -17.0f);
		this->BindObject(eButton4, 61525, 43.0f, 17.0f, -43.0f, -17.0f);
		this->BindObject(eButton5, 61525, 43.0f, 17.0f, -43.0f, -17.0f);

		if (gProtect.m_MainInfo.CustomMenuType == 1)
		{
			this->BindObject(eMenu, 0x7906, 102, 29, -1, -1);
		}
		else
		{
			this->BindObject(eMenu, 0x7906, 16, 12, -1, -1);
			this->BindObject(eMenuBG, 0x7907, 36, 18, 174, 0);
		}
		//Ex700
		this->BindObject(chatbackground, 51545, 300.0f, 128.0f, -10, 569);
		this->BindObject(eShop, 51522, 19.5f, 19.5f, -1, -1);
		this->BindObject(eCharacter, 51522, 19.5f, 19.5f, -1, -1);
		this->BindObject(eInventory, 51522, 19.5f, 19.5f, -1, -1);
		this->BindObject(eQuest, 51522, 19.5f, 19.5f, -1, -1);
		this->BindObject(eCommunity, 51522, 19.5f, 19.5f, -1, -1);
		this->BindObject(eSystem, 51522, 19.5f, 19.5f, -1, -1);
		break;
	default:
		if (gProtect.m_MainInfo.CustomMenuType == 1)
		{
			this->BindObject(eMenu, 0x7906, 102, 29, -1, -1);
		}
		else
		{
			this->BindObject(eMenu, 0x7906, 16, 12, -1, -1);
			this->BindObject(eMenuBG, 0x7907, 36, 18, 174, 0);
		}
		break;
	}
	if (gProtect.m_MainInfo.InventoryUPGRADE == 1)
	{
		this->BindObject(eMoney1, 0x7909, 75, 13, -1, -1);
		this->BindObject(eMoney2, 0x7910, 75, 13, -1, -1);
	}
	if (gProtect.m_MainInfo.DisableAdvance == 0)
	{
		gInterface.BindObject(eADVANCE_STAT_INFO, ex_INFO_2, 35, 30, -1, -1);
	}


	//========================================================================
	//==Skin Model
	this->BindObject(eWindow_SkinModelNext, 0x7903, 25, 40, -1, -1);
	this->BindObject(eWindow_SkinModelPREV, 0x7904, 25, 40, -1, -1);

#if(EXBEXO_LOAD_SEND_TINH_NANG)
	this->BindObject(EXBEXO_AUTORESET_INTERFACE, 0x313A, 78, 22, -1, -1);
	this->BindObject(EXBEXO_QUESTCLASS_INTERFACE, 0x313A, 78, 22, -1, -1);
	this->BindObject(EXBEXO_OFFATTACK_INTERFACE, 0x313A, 78, 22, -1, -1);
	this->BindObject(EXBEXO_UYTHAC_INTERFACE, 0x313A, 78, 22, -1, -1);
	this->BindObject(EXBEXO_TAYDIEM_INTERFACE, 0x313A, 78, 22, -1, -1);
	this->BindObject(EXBEXO_TAYDIEMMASTER_INTERFACE, 0x313A, 78, 22, -1, -1);
#endif

	////new
	this->BindObject(eNEWS_MAIN, 0x7A5A, 222, 303, -1, -1);
	this->BindObject(eNEWS_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eNEWS_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eNEWS_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eNEWS_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eNEWS_INFOBG, 0x787D, 170, 21, -1, -1);
	this->BindObject(eNEWS_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eNEWS_BACK, 0x7A5E, 128, 29, -1, -1);


	//51522
	//==============================================================>
#if(DANH_HIEU_NEW == 1)
	this->BindObject(EXBEXO_DANH_HIEU_MAIN, 0x0899, 560, 279, -1, -1);
	this->BindObject(EXBEXO_DANH_HIEU_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(EXBEXO_DANH_HIEU_NANG_CAP, 0x7A5E, 108, 29, -1, -1);

	this->BindObject(eDANH_HIEU2, 0x7903, 25, 40, -1, -1);
	this->BindObject(eDANH_HIEU1, 0x7904, 25, 40, -1, -1);
#endif

#if(QUAN_HAM_NEW == 1)
	this->BindObject(EXBEXO_QUAN_HAM_MAIN, 0x0899, 560, 279, -1, -1);
	this->BindObject(EXBEXO_QUAN_HAM_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(EXBEXO_QUAN_HAM_NANG_CAP, 0x7A5E, 108, 29, -1, -1);

	this->BindObject(eQUAN_HAM2, 0x7903, 25, 40, -1, -1);
	this->BindObject(eQUAN_HAM1, 0x7904, 25, 40, -1, -1);
#endif

#if(TU_LUYEN_NEW == 1)
	this->BindObject(EXBEXO_TU_LUYEN_MAIN, 0x0899, 560, 279, -1, -1);
	this->BindObject(EXBEXO_TU_LUYEN_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(EXBEXO_TU_LUYEN_NANG_CAP, 0x7A5E, 108, 29, -1, -1);

	this->BindObject(eTU_LUYEN2, 0x7903, 25, 40, -1, -1);
	this->BindObject(eTU_LUYEN1, 0x7904, 25, 40, -1, -1);
#endif




#if (RESETCHANGE == 1)
	this->BindObject(eRESETCHANGE, 0x7A5A, 222, 320, 205, -1);
	this->BindObject(eMenu_CLOSE, 71521, 59, 28, -1, -1);
	this->BindObject(eBOTON1, 71521, 59, 28, -1, -1);
	this->BindObject(eBOTON2, 71521, 59, 28, -1, -1);
	this->BindObject(eBOTON3, 71521, 59, 28, -1, -1);
	this->BindObject(eBOTON4, 71521, 59, 28, -1, -1);
	this->BindObject(eBOTON5, 71521, 59, 28, -1, -1);
#endif


#if(OFFLINE_MODE_NEW)
	this->BindObject(eOFFEXP_MAIN, 31461, 900, 1000, -1, -1);  // 31461
	this->BindObject(eOFFEXP_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eOFFEXP_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eOFFEXP_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eOFFEXP_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eOFFEXP_POINT, 0x7B68, 10, 10, -1, -1);
	this->BindObject(eOFFEXP_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eOFFEXP_CHECKBOX_BUFF, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(eOFFEXP_CHECKBOX_PICK_ZEN, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(eOFFEXP_CHECKBOX_PICK_JEWELS, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(eOFFEXP_CHECKBOX_PICK_EXC, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(eOFFEXP_CHECKBOX_PICK_ANC, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(eOFFEXP_CHECKBOX_SELECTED_HELPER, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(eOFFEXP_BTN_OK, 0x7A5E, 106, 29, -1, -1);

	this->BindObject(eOFFEXP_SKILL1, 0x7A4C, 20, 28, -1, -1);
	this->BindObject(eOFFEXP_SKILL2, 0x7A4C, 20, 28, -1, -1);
	this->BindObject(eOFFEXP_SKILL3, 0x7A4C, 20, 28, -1, -1);
#endif


	//----------------------------------------------------------------------------------------

	this->BindObject(eTVTHUD, 0x9912, 200, 27, -1, -1);


	//button event

	this->BindObject(eMenu_OPT21, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT22, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT23, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT24, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT25, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT26, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT27, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT28, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT29, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT30, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT31, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT32, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT33, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT34, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT35, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT36, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT37, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT38, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT39, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT40, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT41, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT42, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT43, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT44, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT45, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT46, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT47, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT48, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT49, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT50, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT51, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT52, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT53, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT54, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT55, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT56, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT57, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT58, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT59, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT60, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT61, 0x7906, 16, 12, -1, -1);
	this->BindObject(eMenu_OPT62, 0x7906, 16, 12, -1, -1);



#if(CAMERA)
	this->BindObject(eCAMERA_MAIN, 0x787A, 72, 18, 174, 0);
	// ----
	this->BindObject(eCAMERA_BUTTON1, 0x787B, 16, 12, 185.5, 1);
	this->BindObject(eCAMERA_BUTTON2, 0x787C, 16, 12, 202.5, 1);

	this->BindObject(eCAMERA_BUTTON_UP1, 51556, 16, 12, 185.5, 1);
	this->BindObject(eCAMERA_BUTTON_UP2, 51557, 16, 12, 202.5, 1);
#endif
	this->BindObject(eConfigHelper, 31463, 17, 18, -1, -1);

	SetRange((LPVOID)0x00842086, 5, ASM::NOP);
	SetRange((LPVOID)0x0084234F, 5, ASM::NOP);
	SetRange((LPVOID)0x008423C3, 5, ASM::NOP);
	SetOp((LPVOID)oLoadSomeForm_Call, this->LoadImages, ASM::CALL);
	SetCompleteHook(0xFF, 0x00633FFB, &this->LoadModels);
	SetOp((LPVOID)oDrawInterface_Call, this->Work, ASM::CALL);

	if (gProtect.m_MainInfo.InventoryUPGRADE == 1)
	{
		SetRange((LPVOID)0x00835116, 5, ASM::NOP);
		SetOp((LPVOID)0x00835116, this->DrawZenAndRud, ASM::CALL);
	}
	//SetRange((LPVOID)0x00835116, 5, ASM::NOP);
	//SetOp((LPVOID)0x00835116, this->DrawZenAndRud, ASM::CALL);

	gEmojis.AddTextures(); //> Agregar esto
	gHuyHieuCuongHoa.BinObeject();
	gCustomRanking.BinObeject();
#if(PARTYSEARCH==1)
	gPartySearch.loadBind();
#endif
	gNewInterface.Load();
#if(FLAG_SKIN)
	ThueFlag.Bind();
#endif
	gInterface.mGreatPKBXHData.clear();
	gInterface.mGreatPKClearInfo();

	gInterface.mDauTruongBXHData.clear();
	gInterface.mDauTruongClearInfo();

}
void Interface::NewLoadInterface()
{

	gHuyHieuCuongHoa.DrawHuyHieu();

}
void Interface::DrawItemToolTipText(void * item, int x, int y)
{
	static DWORD mem = 0;
	_asm
	{
		PUSH 0
			PUSH 0
			PUSH 0
			PUSH item
			PUSH y
			PUSH x
			MOV mem, 0x00861110
			CALL mem
			MOV ECX, EAX
			MOV mem, 0x00861AA0
			CALL mem
			MOV ECX, EAX
			MOV mem, 0x007E3E30
			CALL mem
	}
}

void Interface::DrawZenAndRud(int a1, int a2, int a3, int a4)
{
	int v10;
	int v11;
	DWORD v23;
	v10 = *(DWORD*)(a1 + 40);
	v11 = *(DWORD*)(a1 + 36);
	v23 = *(DWORD*)(*(DWORD*)0x8128AC4 + 5956);
	*(float*)(0x00D24E88); //Width

	char MoneyBuff1[50], MoneyBuff2[50], MoneyBuff3[50], MoneyBuff4[50], test[50];
	ZeroMemory(MoneyBuff1, sizeof(MoneyBuff1));
	ZeroMemory(MoneyBuff2, sizeof(MoneyBuff2));
	ZeroMemory(MoneyBuff3, sizeof(MoneyBuff3));
	ZeroMemory(MoneyBuff4, sizeof(MoneyBuff4));

	pGetMoneyFormat(v23, MoneyBuff1, 0);
	pGetMoneyFormat(Coin3, MoneyBuff2, 0);
	pGetMoneyFormat(Coin1, MoneyBuff3, 0);
	pGetMoneyFormat(Coin2, MoneyBuff4, 0);

	gInterface.DrawFormat(eWhite, v11, v10 + 12, 190, 3, pGetTextLine(pTextLineThis, 223));
	//--
	gInterface.DrawGUI(eMoney1, v11 + 18, v10 + 365);
	//gInterface.DrawFormat(eBlack, v11 + 20, v10 + 367, 20, 1, "Zen");
	CustomFont.DrawMultipleColor(CustomFont.FontBold, v11 + 20, v10 + 367, 0x0, 0, 0, 0, "Zen");

	//gInterface.DrawFormat(eRed, v11 + 40, v10 + 367, 50, 4, "%s", MoneyBuff1);
	CustomFont.DrawMultipleColor(CustomFont.FontBold, v11 + 40, v10 + 367, 0x0, 0, 0, 0, "%s", MoneyBuff1);

	//--
	gInterface.DrawGUI(eMoney2, v11 + 102, v10 + 365);
	//gInterface.DrawFormat(eBlack, v11 + 104, v10 + 367, 20, 1, "GP");
	CustomFont.DrawMultipleColor(CustomFont.FontBold, v11 + 105, v10 + 367, 0x0, 0, 0, 0, "GP");
	//gInterface.DrawFormat(eWhite, v11 + 128, v10 + 367, 45, 4, "%s", MoneyBuff2);
	CustomFont.DrawMultipleColor(CustomFont.FontBold, v11 + 128, v10 + 367, 0x0, 0, 0, 0, "%s", MoneyBuff2);
	//--
	gInterface.DrawGUI(eMoney2, v11 + 18, v10 + 378);
	//gInterface.DrawFormat(eBlack, v11 + 20, v10 + 380, 20, 1, "WC");
	CustomFont.DrawMultipleColor(CustomFont.FontBold, v11 + 20, v10 + 380, 0x0, 0, 0, 0, "WC");
	//gInterface.DrawFormat(eGold, v11 + 38, v10 + 381, 50, 4, "%s", MoneyBuff3);
	CustomFont.DrawMultipleColor(CustomFont.FontBold, v11 + 40, v10 + 381, 0x0, 0, 0, 0, "%s", MoneyBuff3);
	//--
	gInterface.DrawGUI(eMoney2, v11 + 102, v10 + 378);
	//gInterface.DrawFormat(eBlack, v11 + 101, v10 + 380, 20, 1, "WCP");
	CustomFont.DrawMultipleColor(CustomFont.FontBold, v11 + 101, v10 + 380, 0x0, 0, 0, 0, "WCP");
	//gInterface.DrawFormat(eBlue, v11 + 128, v10 + 381, 45, 4, "%s", MoneyBuff4);

	CustomFont.DrawMultipleColor(CustomFont.FontBold, v11 + 128, v10 + 381, 0x0, 0, 0, 0, "%s", MoneyBuff4);

	float Hieux;

	float MainWidth = 200.0;
	float MainHeight = 180.0;
	float StartY = ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);

	if (gProtect.m_MainInfo.CustomInterfaceType == 0 || gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4)
	{
		if (gInterface.CheckWindow(Character))
		{
			Hieux = StartX - 190;
		}
		else
		{
			Hieux = StartX;
		}
	}
	else
	{
		Hieux = StartX;
	}

	if (gInterface.CheckWindow(Inventory))
	{
		if (gProtect.m_MainInfo.CustomInterfaceType == 0 || gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4)
		{
			if (gHuyHieuCuongHoa.huyhieu >= 1)
			{
				pDrawGUI(59990, Hieux + 347, StartY - 37, 22, 22);
			}
			else
			{
				pDrawGUI(59999, Hieux + 347, StartY - 37, 22, 22);
			}
		}
		if (gProtect.m_MainInfo.CustomInterfaceType == 0 || gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4)
		{
			if (gHuyHieuCuongHoa.huyhieu >= 1)
			{
				pDrawGUI(59990, Hieux + 347, StartY - 37, 22, 22);
			}
			else
			{
				pDrawGUI(59999, Hieux + 347, StartY - 37, 22, 22);
			}
		}

	}

#if OLD_PKNOTICE
	gInterface.m_KillLog.clear();
	gInterface.m_KillInterface = GetTickCount();
#endif


}


//void Interface::DrawZenAndRud(int a1, int a2, int a3, int a4)
//{
//	int v10;
//	int v11;
//	DWORD v23;
//	v10 = *(DWORD*)(a1 + 40);
//	v11 = *(DWORD*)(a1 + 36);
//	v23 = *(DWORD*)(*(DWORD*)0x8128AC4 + 5956);
//	*(float*)(0x00D24E88); //Width
//
//	char MoneyBuff1[50], MoneyBuff2[50], MoneyBuff3[50], MoneyBuff4[50], test[50];
//	ZeroMemory(MoneyBuff1, sizeof(MoneyBuff1));
//	ZeroMemory(MoneyBuff2, sizeof(MoneyBuff2));
//	ZeroMemory(MoneyBuff3, sizeof(MoneyBuff3));
//	ZeroMemory(MoneyBuff4, sizeof(MoneyBuff4));
//
//	pGetMoneyFormat(v23, MoneyBuff1, 0);
//	pGetMoneyFormat(Coin3, MoneyBuff2, 0);
//	pGetMoneyFormat(Coin1, MoneyBuff3, 0);
//	pGetMoneyFormat(Coin2, MoneyBuff4, 0);
//
//	gInterface.DrawFormat(eWhite, v11, v10 + 12, 190, 3, pGetTextLine(pTextLineThis, 223));
//	//--
//	gInterface.DrawGUI(eMoney1, v11 + 18, v10 + 365);
//	gInterface.DrawFormat(eBlack, v11 + 18, v10 + 367, 20, 1, "Zen");
//	gInterface.DrawFormat(eRed, v11 + 40, v10 + 367, 50, 3, "%s", MoneyBuff1);
//	//--
//	gInterface.DrawGUI(eMoney2, v11 + 102, v10 + 365);
//	gInterface.DrawFormat(eBlack, v11 + 102, v10 + 367, 20, 1, "GP");
//	gInterface.DrawFormat(eWhite, v11 + 128, v10 + 367, 45, 4, "%s", MoneyBuff2);
//	//--
//	gInterface.DrawGUI(eMoney2, v11 + 18, v10 + 378);
//	gInterface.DrawFormat(eBlack, v11 + 17, v10 + 380, 20, 1, "WC");
//	gInterface.DrawFormat(eGold, v11 + 38, v10 + 381, 50, 4, "%s", MoneyBuff3);
//	//--
//	gInterface.DrawGUI(eMoney2, v11 + 102, v10 + 378);
//	gInterface.DrawFormat(eBlack, v11 + 98, v10 + 380, 20, 1, "WCP");
//	gInterface.DrawFormat(eBlue, v11 + 128, v10 + 381, 45, 4, "%s", MoneyBuff4);
//}


void Interface::LoadModels()
{
	pLoadModel(406, "Data\\Custom\\Bmd\\VIP1\\", "musign", -1);
	pLoadTexture(406, "Custom\\Bmd\\VIP1\\", 0x2901, 0x2600, 1);
	pLoadModel(407, "Data\\Custom\\Bmd\\VIP2\\", "musign", -1);
	pLoadTexture(407, "Custom\\Bmd\\VIP2\\", 0x2901, 0x2600, 1);
	pLoadModel(408, "Data\\Custom\\Bmd\\VIP3\\", "musign", -1);
	pLoadTexture(408, "Custom\\Bmd\\VIP3\\", 0x2901, 0x2600, 1);
	// ----

	if (gProtect.m_MainInfo.MenuButtons[12] == 1)
	{

		//===Test Load SKin
		pLoadModel(2000 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "Skin1", -1);
		pLoadTexture(2000 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);
		// ----
		pLoadModel(2001 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "Skin2", -1);
		pLoadTexture(2001 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);
		// ----
		pLoadModel(2002 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "Skin3", -1);
		pLoadTexture(2002 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);
		// ----
		pLoadModel(2003 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "Skin4", -1);
		pLoadTexture(2003 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);
		// ----
		pLoadModel(2004 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "Skin5", -1);
		pLoadTexture(2004 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);
		// ----
		pLoadModel(2005 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "Skin6", -1);
		pLoadTexture(2005 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);
		// ----
		pLoadModel(2006 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "Skin7", -1);
		pLoadTexture(2006 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);
		// ----
		pLoadModel(2007 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "Skin8", -1);
		pLoadTexture(2007 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);
		// ----
		pLoadModel(2008 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "Skin9", -1);
		pLoadTexture(2008 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);
		// ----
		pLoadModel(2009 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "Skin10", -1);
		pLoadTexture(2009 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);
		// ----
		pLoadModel(2010 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "Skin11", -1);
		pLoadTexture(2010 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);
		// ----
		pLoadModel(2011 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "Skin12", -1);
		pLoadTexture(2011 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);
		// ----
		pLoadModel(2012 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "Skin13", -1);
		pLoadTexture(2012 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);
		// ----
		pLoadModel(2013 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "Skin19", -1);
		pLoadTexture(2013 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);
		// ----
		pLoadModel(2014 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "Skin21", -1);
		pLoadTexture(2014 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);
		// ----
		pLoadModel(2015 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "Skin22", -1);
		pLoadTexture(2015 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);
		// ----
		pLoadModel(2016 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "Skin23", -1);
		pLoadTexture(2016 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);
		// ----
		pLoadModel(2017 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "Skin24", -1);
		pLoadTexture(2017 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);
		// ----
		pLoadModel(2018 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "Skin25", -1);
		pLoadTexture(2018 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);

		// ----
		pLoadModel(2019 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "Bigmoon", -1);
		pLoadTexture(2019 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);

		// ----
		pLoadModel(2020 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "Doflamingo", -1);
		pLoadTexture(2020 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);
		// ----
		pLoadModel(2021 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "Shirohige", -1);
		pLoadTexture(2021 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);

		// ----
		pLoadModel(2022 + MODELSKINFIX, "Data\\Custom\\Bmd\\Skin\\", "skinsbakugo", -1);
		pLoadTexture(2022 + MODELSKINFIX, "Custom\\Bmd\\Skin\\", 0x2901, 0x2600, 1);

	}
	pInitModelData2();
	gInterface.SelectInfoSkin = false;

}


int Interface::LoadImg(char * Folder, DWORD ID){
	return pLoadImage(Folder, ID, GL_LINEAR, GL_CLAMP, 1, 0);
}


void Interface::LoadImages()
{

	if (gProtect.m_MainInfo.InventoryUPGRADE == 1)
	{
		pLoadImage("Custom\\Interface\\Money\\item_money.tga", 0x7909, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Interface\\Money\\item_money2.tga", 0x7910, 0x2601, 0x2901, 1, 0);
	}
	//
	pLoadImage("Custom\\RankTitle\\Rank\\Rank01.tga", 0x7880, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\RankTitle\\Rank\\Rank02.tga", 0x7881, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\RankTitle\\Rank\\Rank03.tga", 0x7882, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\RankTitle\\Rank\\Rank04.tga", 0x7883, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\RankTitle\\Rank\\Rank05.tga", 0x7884, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\RankTitle\\Rank\\Rank06.tga", 0x7885, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\RankTitle\\Rank\\Rank07.tga", 0x7886, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\RankTitle\\Rank\\Rank08.tga", 0x7887, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\RankTitle\\Rank\\Rank09.tga", 0x7888, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\RankTitle\\Rank\\Rank10.tga", 0x7889, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\RankTitle\\Rank\\Rank11.tga", 0x7890, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\RankTitle\\Rank\\Rank12.tga", 0x7891, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\RankTitle\\Rank\\Rank13.tga", 0x7892, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\RankTitle\\Rank\\Rank14.tga", 0x7893, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\RankTitle\\Rank\\Rank15.tga", 0x7894, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\RankTitle\\Rank\\Rank16.tga", 0x7895, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\RankTitle\\Rank\\Rank17.tga", 0x7896, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\RankTitle\\Rank\\Rank18.tga", 0x7897, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\RankTitle\\Rank\\Rank19.tga", 0x7898, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\RankTitle\\Rank\\Rank20.tga", 0x7899, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\RankTitle\\Rank\\Rank21.tga", 0x7900, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\RankTitle\\Rank\\Rank22.tga", 0x7901, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Ranking.tga", 0x7902, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Next.tga", 0x7903, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Previous.tga", 0x7904, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\MU-logo.tga", 0x7905, 0x2601, 0x2901, 1, 0);

	pLoadImage("Custom\\Interface\\Button.tga", 0x7908, 0x2601, 0x2900, 1, 0);

#if(DANH_HIEU_NEW == 1)
	if (gProtect.m_MainInfo.MenuButtons[9] == 1)
	{
		pLoadImage("Custom\\RankTitle\\DanhHieu\\Main.tga", 0x0899, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\RankTitle\\DanhHieu\\Successful.tga", 0x0898, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\RankTitle\\DanhHieu\\Progress.tga", 0x0897, 0x2601, 0x2901, 1, 0);

		pLoadImage("Custom\\RankTitle\\DanhHieu\\1.tga", 90101, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\DanhHieu\\2.tga", 90102, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\DanhHieu\\3.tga", 90103, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\DanhHieu\\4.tga", 90104, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\DanhHieu\\5.tga", 90105, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\DanhHieu\\6.tga", 90106, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\DanhHieu\\7.tga", 90107, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\DanhHieu\\8.tga", 90108, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\DanhHieu\\9.tga", 90109, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\DanhHieu\\10.tga", 90110, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\DanhHieu\\11.tga", 90111, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\DanhHieu\\12.tga", 90112, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\DanhHieu\\13.tga", 90113, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\DanhHieu\\14.tga", 90114, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\DanhHieu\\15.tga", 90115, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\DanhHieu\\16.tga", 90116, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\DanhHieu\\17.tga", 90117, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\DanhHieu\\18.tga", 90118, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\DanhHieu\\19.tga", 90119, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\DanhHieu\\20.tga", 90120, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\DanhHieu\\21.tga", 90121, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\DanhHieu\\22.tga", 90122, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\DanhHieu\\23.tga", 90123, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\DanhHieu\\24.tga", 90124, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\DanhHieu\\25.tga", 90125, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\DanhHieu\\26.tga", 90126, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\DanhHieu\\27.tga", 90127, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\DanhHieu\\28.tga", 90128, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\DanhHieu\\29.tga", 90129, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\DanhHieu\\30.tga", 90130, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\DanhHieu\\31.tga", 90131, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\DanhHieu\\32.tga", 90132, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\DanhHieu\\33.tga", 90133, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\DanhHieu\\34.tga", 90134, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\DanhHieu\\35.tga", 90135, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\DanhHieu\\36.tga", 90136, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\DanhHieu\\37.tga", 90137, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\DanhHieu\\38.tga", 90138, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\DanhHieu\\39.tga", 90139, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\DanhHieu\\40.tga", 90140, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\DanhHieu\\41.tga", 90141, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\DanhHieu\\42.tga", 90142, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\DanhHieu\\43.tga", 90143, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\DanhHieu\\44.tga", 90144, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\DanhHieu\\45.tga", 90145, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\DanhHieu\\46.tga", 90146, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\DanhHieu\\47.tga", 90147, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\DanhHieu\\48.tga", 90148, 0x2601, 0x2900, 1, 0);

	}
#endif

#if(QUAN_HAM_NEW == 1)
	if (gProtect.m_MainInfo.MenuButtons[10] == 1)
	{
		pLoadImage("Custom\\RankTitle\\QuanHam\\QuanHam_1.tga", 10108, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\QuanHam\\QuanHam_2.tga", 10109, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\QuanHam\\QuanHam_3.tga", 10110, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\QuanHam\\QuanHam_4.tga", 10111, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\QuanHam\\QuanHam_5.tga", 10112, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\QuanHam\\QuanHam_6.tga", 10113, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\QuanHam\\QuanHam_7.tga", 10114, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\QuanHam\\QuanHam_8.tga", 10115, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\QuanHam\\QuanHam_9.tga", 10116, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\QuanHam\\QuanHam_10.tga", 10117, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\QuanHam\\QuanHam_11.tga", 10118, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\QuanHam\\QuanHam_12.tga", 10119, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\QuanHam\\QuanHam_13.tga", 10120, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\QuanHam\\QuanHam_14.tga", 10121, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\QuanHam\\QuanHam_15.tga", 10122, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\QuanHam\\QuanHam_16.tga", 10123, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\QuanHam\\QuanHam_17.tga", 10124, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\QuanHam\\QuanHam_18.tga", 10125, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\QuanHam\\QuanHam_19.tga", 10126, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\QuanHam\\QuanHam_20.tga", 10127, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\QuanHam\\QuanHam_21.tga", 10128, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\QuanHam\\QuanHam_22.tga", 10129, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\QuanHam\\QuanHam_23.tga", 10130, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\QuanHam\\QuanHam_24.tga", 10131, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\QuanHam\\QuanHam_25.tga", 10132, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\QuanHam\\QuanHam_26.tga", 10133, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\QuanHam\\QuanHam_27.tga", 10134, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\QuanHam\\QuanHam_28.tga", 10135, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\QuanHam\\QuanHam_29.tga", 10136, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\QuanHam\\QuanHam_30.tga", 10137, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\QuanHam\\QuanHam_31.tga", 10138, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\QuanHam\\QuanHam_32.tga", 10139, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\QuanHam\\QuanHam_33.tga", 10140, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\QuanHam\\QuanHam_34.tga", 10141, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\QuanHam\\QuanHam_35.tga", 10142, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\QuanHam\\QuanHam_36.tga", 10143, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\QuanHam\\QuanHam_37.tga", 10144, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\QuanHam\\QuanHam_38.tga", 10145, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\QuanHam\\QuanHam_39.tga", 10146, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\QuanHam\\QuanHam_40.tga", 10147, 0x2601, 0x2900, 1, 0);
	}
#endif

#if(TU_LUYEN_NEW == 1)
	if (gProtect.m_MainInfo.MenuButtons[11] == 1)
	{
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_1.tga", 20128, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_2.tga", 20129, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_3.tga", 20130, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_4.tga", 20131, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_5.tga", 20132, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_6.tga", 20133, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_7.tga", 20134, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_8.tga", 20135, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_9.tga", 20136, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_10.tga", 20137, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_11.tga", 20138, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_12.tga", 20139, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_13.tga", 20140, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_14.tga", 20141, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_15.tga", 20142, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_16.tga", 20143, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_17.tga", 20144, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_18.tga", 20145, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_19.tga", 20146, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_20.tga", 20147, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_21.tga", 20148, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_22.tga", 20149, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_23.tga", 20150, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_24.tga", 20151, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_25.tga", 20152, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_26.tga", 20153, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_27.tga", 20154, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_28.tga", 20155, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_29.tga", 20156, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_30.tga", 20157, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_31.tga", 20158, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_32.tga", 20159, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_33.tga", 20160, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_34.tga", 20161, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_35.tga", 20162, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_36.tga", 20163, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_37.tga", 20164, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_38.tga", 20165, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_39.tga", 20166, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_40.tga", 20167, 0x2601, 0x2900, 1, 0);


		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_41.tga", 20168, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_42.tga", 20169, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_43.tga", 20170, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_44.tga", 20171, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_45.tga", 20172, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_46.tga", 20173, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_47.tga", 20174, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_48.tga", 20175, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_49.tga", 20176, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_50.tga", 20177, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_51.tga", 20178, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_52.tga", 20179, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_53.tga", 20180, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_54.tga", 20181, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_55.tga", 20182, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_56.tga", 20183, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_57.tga", 20184, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_58.tga", 20185, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_59.tga", 20186, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_60.tga", 20187, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_61.tga", 20188, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_62.tga", 20189, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_63.tga", 20190, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_64.tga", 20191, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_65.tga", 20192, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_66.tga", 20193, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_67.tga", 20194, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_68.tga", 20195, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_69.tga", 20196, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_70.tga", 20197, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_71.tga", 20198, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_72.tga", 20199, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_73.tga", 20200, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_74.tga", 20201, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_75.tga", 20202, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_76.tga", 20203, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_77.tga", 20204, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_78.tga", 20205, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_79.tga", 20206, 0x2601, 0x2900, 1, 0);
		pLoadImage("Custom\\RankTitle\\TuLuyen\\TuLuyen_80.tga", 20207, 0x2601, 0x2900, 1, 0);

	}
#endif

#if(B_HON_HOAN)

	if (gProtect.m_MainInfo.MenuButtons[13] == 1)
	{
		//=== Hon Hoan
		pLoadImage("Custom\\HonHoan\\1.jpg", eImgHonHoan, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\2.jpg", eImgHonHoan + 1, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\3.jpg", eImgHonHoan + 2, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\4.jpg", eImgHonHoan + 3, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\5.jpg", eImgHonHoan + 4, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\6.jpg", eImgHonHoan + 5, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\7.jpg", eImgHonHoan + 6, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\8.jpg", eImgHonHoan + 7, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\9.jpg", eImgHonHoan + 8, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\10.jpg", eImgHonHoan + 9, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\11.jpg", eImgHonHoan + 10, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\12.jpg", eImgHonHoan + 11, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\13.jpg", eImgHonHoan + 12, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\14.jpg", eImgHonHoan + 13, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\15.jpg", eImgHonHoan + 14, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\16.jpg", eImgHonHoan + 15, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\17.jpg", eImgHonHoan + 16, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\18.jpg", eImgHonHoan + 17, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\19.jpg", eImgHonHoan + 18, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\20.jpg", eImgHonHoan + 19, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\21.jpg", eImgHonHoan + 20, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\22.jpg", eImgHonHoan + 21, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\23.jpg", eImgHonHoan + 22, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\24.jpg", eImgHonHoan + 23, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\25.jpg", eImgHonHoan + 24, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\26.jpg", eImgHonHoan + 25, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\27.jpg", eImgHonHoan + 26, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\28.jpg", eImgHonHoan + 27, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\29.jpg", eImgHonHoan + 28, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\30.jpg", eImgHonHoan + 29, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\31.jpg", eImgHonHoan + 30, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\32.jpg", eImgHonHoan + 31, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\33.jpg", eImgHonHoan + 32, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\34.jpg", eImgHonHoan + 33, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\35.jpg", eImgHonHoan + 34, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\36.jpg", eImgHonHoan + 35, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\37.jpg", eImgHonHoan + 36, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\38.jpg", eImgHonHoan + 37, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\39.jpg", eImgHonHoan + 38, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\40.jpg", eImgHonHoan + 39, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\41.jpg", eImgHonHoan + 40, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\42.jpg", eImgHonHoan + 41, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\43.jpg", eImgHonHoan + 42, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\44.jpg", eImgHonHoan + 43, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\45.jpg", eImgHonHoan + 44, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\46.jpg", eImgHonHoan + 45, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\47.jpg", eImgHonHoan + 46, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\48.jpg", eImgHonHoan + 47, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\49.jpg", eImgHonHoan + 48, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\50.jpg", eImgHonHoan + 49, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\HonHoan\\DemoHonHoan.tga", eDemoHonHoan, GL_LINEAR, GL_CLAMP, 1, 0);
#endif

	}
#if(JEWELBANKVER2)
	pLoadImage("Interface\\newui_SW_Minimap_Bt_group.tga", 31618, 0x2601, 0x2900, 1, 0);
#endif
	pLoadImage("Custom\\Interface\\LuckyWheel\\itembackpanel.tga", 0x9326, 0x2601, 0x2900, 1, 0);
	//	pLoadImage("Custom\\Interface\\LuckyWheel\\topmenutabbt1.tga", 0x9327, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Interface\\LuckyWheel\\ui_dialog_e.tga", 0x9328, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Interface\\LuckyWheel\\Nut_XoaHomDo.tga", 0x9327, 0x2601, 0x2900, 1, 0);

	//

	if (gProtect.m_MainInfo.CustomMenuType == 1)
	{
		pLoadImage("Custom\\Interface\\Menu1.tga", 0x7906, 0x2601, 0x2901, 1, 0);
	}
	else
	{
		pLoadImage("Custom\\Interface\\Menu2.tga", 0x7906, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Interface\\Menu_BG.tga", 0x7907, 0x2601, 0x2901, 1, 0);
	}


	pLoadImage("Custom\\Interface\\Button.tga", 0x7908, 0x2601, 0x2900, 1, 0);
	//MiniMap
	pLoadImage("Custom\\Maps\\PlayerPoint.jpg", 31460, 0x2600, 0x2900, 1, 0);
	pLoadImage("Custom\\Interface\\none.tga", 31461, 0x2601, 0x2900, 1, 0);



#if(CAMERA)	
	pLoadImage("Custom\\Interface\\CameraUI_BG.tga", 0x787A, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Interface\\CameraUI_Switch.tga", 0x787B, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Interface\\CameraUI_Reset.tga", 0x787C, 0x2601, 0x2900, 1, 0);

#endif


	//=== CTC Mini UI ==//
	pLoadImage("Custom\\CTCMini\\UiCtc.tga", 32584, 9729, 10496, 1, 0);
	pLoadImage("Custom\\CTCMini\\CTCMiniMap.tga", 32583, 9729, 10496, 1, 0);
	pLoadImage("Custom\\CTCMini\\StartCTC.tga", 32585, 9729, 10496, 1, 0);
	pLoadImage("Custom\\CTCMini\\WinCTC.tga", 32586, 9729, 10496, 1, 0);
	pLoadImage("Custom\\CTCMini\\LoseCTC.tga", 32589, 9729, 10496, 1, 0); //Trung voi ID effect 32587
	pLoadImage("Custom\\CTCMini\\DialogCTC.tga", 32588, 9729, 10496, 1, 0);
	pLoadImage("Custom\\CTCMini\\CharPoint.tga", 32506, 9729, 10496, 1, 0);
	pLoadImage("Custom\\CTCMini\\OtherCharPoint.tga", 32507, 9729, 10496, 1, 0);
	//==============================//

	pLoadImage("Custom\\Interface\\tvt_hud.tga", 0x9912, 0x2601, 0x2900, 1, 0);


	LoadBitmapA("Custom\\Desig\\Login.tga", 71621, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\1.tga", 71622, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\2.tga", 71623, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\3.tga", 71624, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\4.tga", 71625, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\5.tga", 71626, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\6.tga", 71627, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\8.tga", 71629, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\9.tga", 71630, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\10.tga", 71630, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\login_back.tga", 71631, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\reloadcap.jpg", 71632, GL_LINEAR, GL_CLAMP, 1, 0);

#if(CAMERA)	
	LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_BCamera.tga", 51556, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_BReset.tga", 51557, GL_LINEAR, GL_CLAMP, 1, 0);
#endif



#if(PARTYSEARCH==1)
	gInterface.LoadImg("Custom\\Interface\\PartySearch_Title.tga", 0x7E98);
	gInterface.LoadImg("Custom\\Interface\\Info_Block.tga", 0x7E99);
#endif

	LoadBitmapA("Custom\\Interface\\Nut.tga", 61535, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Interface\\Nut_80_25.tga", 0x313A, 0x2601, 0x2900, 1, 0); // NÚT BUTTON

	//--
	//--Interface MiniMap 97/99/S2/S6
	if (MiniMapType == 0)
	{
		pLoadImage("Custom\\Maps\\edBtUcx_old.tga", 31463, 0x2601, 0x2900, 1, 0); //-- Dungeon
		pLoadImage("Custom\\Maps\\timeold.tga", 31458, 0x2601, 0x2900, 1, 0); //-- Dungeon
	}
	//--Interface MiniMap ex700/Legends
	if (MiniMapType == 1)
	{
		pLoadImage("Custom\\Maps\\edBtUcx.tga", 31463, 0x2601, 0x2900, 1, 0); //-- Dungeon
		pLoadImage("Custom\\Maps\\time700.tga", 31458, 0x2601, 0x2900, 1, 0); //-- Dungeon
	}
	//--
	pLoadImage("Custom\\Maps\\edBtUcx_2.tga", 31464, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\edBtUcx_1.tga", 31459, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\YYB6BUk.tga", 31465, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\mini_map_ui_blacksmith.tga", 31466, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\mini_map_ui_Potion.tga", 31467, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\mini_map_ui_baul.tga", 31468, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\mini_map_ui_Que.tga", 31469, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\mini_map_ui_monsterred.tga", 31471, 0x2601, 0x2900, 1, 0); //-- Dungeon Red
	pLoadImage("Custom\\Maps\\mini_map_ui_monsterblue.tga", 31472, 0x2601, 0x2900, 1, 0); //-- Dungeon Blue
	pLoadImage("Custom\\Maps\\mini_map_ui_monstergold.tga", 31473, 0x2601, 0x2900, 1, 0); //-- Dungeon Gold

	pLoadImage("Interface\\mini_map_ui_party.tga", 61520, 0x2601, 0x2901, 1, 0); //esquina abajo derecha

	if (gProtect.m_MakeViewTRSData.TooltipS15 == 1)
	{
		//-- itemtooltip
		pLoadImage("Interface\\GFx\\tooltip_bg01.tga", 61511, 0x2601, 0x2901, 1, 0); //esquina arriba izquierda
		pLoadImage("Interface\\GFx\\tooltip_bg02.tga", 61512, 0x2601, 0x2901, 1, 0);
		pLoadImage("Interface\\GFx\\tooltip_bg03.tga", 61513, 0x2601, 0x2901, 1, 0); //esquina arriba derecha
		pLoadImage("Interface\\GFx\\tooltip_bg04.tga", 61514, 0x2601, 0x2901, 1, 0);
		pLoadImage("Interface\\GFx\\tooltip_bg06.tga", 61515, 0x2601, 0x2901, 1, 0);
		pLoadImage("Interface\\GFx\\tooltip_bg07.tga", 61516, 0x2601, 0x2901, 1, 0); //esquina abajo izquierda
		pLoadImage("Interface\\GFx\\tooltip_bg08.tga", 61517, 0x2601, 0x2901, 1, 0);
		pLoadImage("Interface\\GFx\\tooltip_bg09.tga", 61518, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	}
	//-- itemtooltip
	pLoadImage("Interface\\GFx\\popupbg01.tga", 71511, 0x2601, 0x2901, 1, 0); //esquina arriba izquierda
	pLoadImage("Interface\\GFx\\popupbg02.tga", 71512, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\GFx\\popupbg03.tga", 71513, 0x2601, 0x2901, 1, 0); //esquina arriba derecha
	pLoadImage("Interface\\GFx\\popupbg04.tga", 71514, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\GFx\\popupbg06.tga", 71515, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\GFx\\popupbg07.tga", 71516, 0x2601, 0x2901, 1, 0); //esquina abajo izquierda
	pLoadImage("Interface\\GFx\\popupbg08.tga", 71517, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\GFx\\popupbg09.tga", 71518, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	//--
	pLoadImage("Interface\\GFx\\popup_line_m.tga", 71519, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	pLoadImage("Interface\\GFx\\popup_line_s.tga", 71520, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	//--
	pLoadImage("Interface\\GFx\\Render_buttom_1.tga", 71521, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	pLoadImage("Interface\\GFx\\Render_buttom_2.tga", 71522, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	pLoadImage("Interface\\GFx\\Render_buttom_3.tga", 71524, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	//--
	pLoadImage("Interface\\GFx\\RenderBits_Sound.tga", 71523, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	pLoadImage("Interface\\GFx\\newui_option_volume01.tga", 31596, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	pLoadImage("Interface\\GFx\\newui_option_volume02.tga", 31597, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	//--
	//Party Bar 97/99/S2/S6
	if (MiniMapType == 0)
	{
		LoadBitmapA("Custom\\Party\\PartyBar.tga", 81525, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Party\\newui_Party_Back.tga", 81520, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Party\\newui_Party_flag.tga", 81521, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Party\\newui_Party_HpBar.jpg", 81522, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Party\\newui_Party_ManaBar.jpg", 81523, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Party\\newui_Party_X.tga", 81524, 0x2601, 0x2901, 1, 0);
	}
	//--
	//--Party Bar ex700/Legends
	if (MiniMapType == 1)
	{
		LoadBitmapA("Custom\\Party\\Ex700\\PartyBar.tga", 81525, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Party\\Ex700\\newui_Party_Back.tga", 81520, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Party\\Ex700\\newui_Party_flag.tga", 81521, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Party\\Ex700\\newui_Party_HpBar.jpg", 81522, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Party\\Ex700\\newui_Party_ManaBar.jpg", 81523, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Party\\Ex700\\newui_Party_X.tga", 81524, 0x2601, 0x2901, 1, 0);
	}
	//--
	LoadBitmapA("Interface\\newui_number1.tga", 31337, 9729, 10496, 1, 0);

	//newminimap
	LoadBitmapA("Interface\\newui_SW_Minimap_Frame.tga", 31608, GL_LINEAR, GL_CLAMP, 1, 0);

	LoadBitmapA("Interface\\newui_SW_Time_Frame.tga", 31609, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\newui_SW_MiniMap_Bt_clearness.jpg", 31617, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\InventoryFrame_RuudShop.tga", 61560, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\Menu_RuudShopFrame.tga", 61561, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\Menu_Button03.tga", 61562, GL_LINEAR, GL_CLAMP, 1, 0);
	//

	//Interface Minimapa 97/99
	//LoadBitmapA("Interface\\newui_SW_Minimap_Frame.tga", 31608, GL_LINEAR, GL_CLAMP, 1, 0);
	if (gProtect.m_MainInfo.CustomInterfaceType == 0 || gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2 || gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4)
	{
		LoadBitmapA("Interface\\newui_SW_Time_Frame.tga", 31609, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\newui_SW_MiniMap_Bt_clearness.jpg", 31617, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\InventoryFrame_RuudShop.tga", 61560, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Menu_RuudShopFrame.tga", 61561, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Menu_Button03.tga", 61562, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\newSytemButton.tga", 61542, GL_LINEAR, GL_CLAMP, 1, 0);
	}
	//-- Pet Bar ex700/Legends
	if (MiniMapType == 1)
	{
		LoadBitmapA("Interface\\GFx\\winPet_I1.tga", 61545, GL_LINEAR, GL_CLAMP, 1, 0);
	}
	//-- Pet Bar 97/99/S2/S6
	if (MiniMapType == 0)
	{
		LoadBitmapA("Custom\\Party\\winPet_I1.tga", 61545, GL_LINEAR, GL_CLAMP, 1, 0);
	}

	switch (gProtect.m_MainInfo.CustomInterfaceType)
	{
	case 1:
	case 2:
		//--
		LoadBitmapA("Custom\\InterfaceS2\\Item_Back01.tga", 61522, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 51522, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Custom\\InterfaceS2\\DragonRight.tga", 2336, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\DragonLeft.tga", 2337, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		if (gProtect.m_MainInfo.CustomInterfaceType == 1)
		{
			LoadBitmapA("Custom\\InterfaceS2\\Menu_left97.jpg", 31292, GL_LINEAR, GL_CLAMP, 1, 0); //replace
			LoadBitmapA("Custom\\Interface\\none.tga", 31300, GL_LINEAR, GL_CLAMP, 1, 0);
		}
		else
		{
			LoadBitmapA("Custom\\InterfaceS2\\Menu_left.jpg", 31292, GL_LINEAR, GL_CLAMP, 1, 0); //replace
			LoadBitmapA("Custom\\InterfaceS2\\Menu_SD.jpg", 31300, GL_LINEAR, GL_CLAMP, 1, 0);
		}

		LoadBitmapA("Custom\\InterfaceS2\\Menu_right.jpg", 31294, GL_LINEAR, GL_CLAMP, 1, 0); //replace
		LoadBitmapA("Custom\\InterfaceS2\\Menu_middle.jpg", 31293, GL_LINEAR, GL_CLAMP, 1, 0); //replace
		//--
		LoadBitmapA("Custom\\InterfaceS2\\Menu_Red.jpg", 0x7A42, GL_LINEAR, GL_CLAMP, 1, 0);//replace
		LoadBitmapA("Custom\\InterfaceS2\\Menu_Green.jpg", 0x7A41, GL_LINEAR, GL_CLAMP, 1, 0);//replace
		LoadBitmapA("Custom\\InterfaceS2\\Menu_Blue.jpg", 0x7A40, GL_LINEAR, GL_CLAMP, 1, 0);//replace
		LoadBitmapA("Custom\\InterfaceS2\\Menu_AG.jpg", 31299, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Custom\\InterfaceS2\\Boton\\Menu_fastmenu.jpg", iNewFastMenu, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31295, GL_LINEAR, GL_CLAMP, 1, 0); //replace
		LoadBitmapA("Custom\\InterfaceS2\\Boton\\Menu_Inventory.jpg", iNewInventory, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Boton\\Menu_Character.jpg", iNewCharacter, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Boton\\Menu_Party.jpg", iNewParty, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Boton\\Menu_friend.jpg", iNewWinpush, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Boton\\Menu_guild.jpg", iNewGuild, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Custom\\InterfaceS2\\skillboxR.jpg", 0x700003, 0x2601, 0x2901, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_skill.jpg", 31308, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_skill2.jpg", 31309, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_skill3.jpg", 31311, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_command.jpg", 31310, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_non_skill.jpg", 31314, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_non_skill2.jpg", 31315, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_non_skill3.jpg", 31317, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Custom\\InterfaceS2\\newui_skillbox.jpg", 31312, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_skillbox2.jpg", 31313, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		//Interface Character
		LoadBitmapA("Custom\\InterfaceS2\\Menu\\Stats.jpg", 31352, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Menu\\StatsDL.jpg", 51291, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Menu\\Stats2.jpg", 51292, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Menu\\Level_box.jpg", 35353, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Menu\\Level_button.jpg", 51290, GL_LINEAR, GL_CLAMP, 1, 0);
		//-- chat
		LoadBitmapA("Custom\\InterfaceS2\\chat\\nis_vframe.jpg", 51551, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\chat\\nis_rsframe.tga", 51552, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\chat\\nis_rsframe_up.jpg", 51553, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\chat\\nis_rsframe_m.jpg", 51554, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\chat\\nis_rsframe_down.jpg", 51555, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\chat\\nis_hframe.jpg", 31275, 9729, 10496, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Chat\\dialogue1.tga", 51530, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Chat\\dialogue2.tga", 51531, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Chat\\dialogue2_1.jpg", 51532, GL_LINEAR, GL_CLAMP, 1, 0);
		break;
	case 3:
		//--
		LoadBitmapA("Interface\\GFx\\ex700\\InventoryFrame_I1.tga", 61522, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\InventoryFrame_I2.tga", 61523, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\InventoryFrame_I3.tga", 61524, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Frame_I3.tga", 61526, GL_LINEAR, GL_CLAMP, 1, 0); //-- All Window
		LoadBitmapA("Interface\\GFx\\ex700\\InventoryFrame_I4.tga", 61527, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Draw_money.tga", 61528, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\button_close.tga", 61529, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Interface\\GFx\\ex700\\CharacterInfoFrame_I1.tga", 61532, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\newui_chainfo_btn_level.tga", 61533, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\ButtonCharacterInfo.tga", 61535, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Interface\\GFx\\ex700\\CharacterInfoFrame_I2.tga", 61538, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\BaulFrame_I1.tga", 61539, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\BaulFrame_I2.tga", 61540, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\ShopFrame_I1.tga", 61541, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\newSytemButton.tga", 61542, GL_LINEAR, GL_CLAMP, 1, 0); //Boton Shop Ruud
		LoadBitmapA("Interface\\GFx\\ex700\\ShopFrame_I2.tga", 61543, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\StoreFrame_I1.tga", 61544, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Interface\\GFx\\ex700\\Main_IE.tga", 31293, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Main_IE_Exp.tga", 59000, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Main_I1.tga", 31296, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Main_I4.jpg", 31300, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Main_I5.jpg", 31299, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\newui_skillbox2.tga", 31313, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\newui_skillbox.tga", 31312, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Main_Skillbox.tga", 51500, GL_LINEAR, GL_CLAMP, 1, 0);

		LoadBitmapA("Interface\\GFx\\ex700\\guege_mp.tga", 31296, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\guege_mp_1.tga", 51501, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\guege_hp_green.tga", 31297, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\guege_hp.tga", 31298, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\guege_hp_1.tga", 51502, GL_LINEAR, GL_CLAMP, 1, 0);
		goto LOAD_GFX;
	case 4:
		LoadBitmapA("Interface\\GFx\\Legends\\Main_IE.tga", 31293, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\Main_I3.tga", 31298, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\guege_mp.tga", 31296, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\guege_mp_1.tga", 51501, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\guege_hp_green.tga", 31297, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\guege_hp.tga", 31298, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\guege_hp_1.tga", 51502, GL_LINEAR, GL_CLAMP, 1, 0);

		LoadBitmapA("Interface\\GFx\\Legends\\Main_I5.jpg", 31299, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\Main_I4.jpg", 31300, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Interface\\GFx\\Legends\\newui_skillbox2.tga", 31313, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\newui_skillbox.tga", 31312, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\Main_Skillbox.tga", 51500, GL_LINEAR, GL_CLAMP, 1, 0);
	LOAD_GFX:
		LoadBitmapA("Interface\\GFx\\Buttom_empty_small.tga", 61525, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\newui_number1.tga", 6829, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\chat_bg01.tga", 61550, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\chat_bg02.tga", 61551, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\chat_bg03.tga", 61534, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Chat_I5.tga", 61548, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\newui_chat_back.tga", 61549, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Main_IE_Buttons.tga", 0x901, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\skill_render.tga", 61546, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\winPet_I1.tga", 61545, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\item_pbtnbg.tga", 61547, GL_LINEAR, GL_CLAMP, 1, 0);
		//-- Folder MacroUI
		LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_Main.tga", 51550, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_BSetup.tga", 51546, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_BStart.tga", 51547, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_Stop.tga", 51548, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_Bar.jpg", 51549, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_Menu.tga", 51553, GL_LINEAR, GL_CLAMP, 1, 0);

		//-- Botones del Main
		LoadBitmapA("Custom\\Interface\\none.tga", 31303, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31304, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31305, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31306, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31307, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Custom\\Interface\\none.tga", 51522, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31294, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31295, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31292, GL_LINEAR, GL_CLAMP, 1, 0);
		break;
	}

	pLoadImage("Logo\\Mu-logo_g.jpg", 531019, GL_LINEAR, GL_REPEAT, 1, 0);
	pLoadImage("Logo\\Mu-logo.tga", 531018, GL_LINEAR, GL_REPEAT, 1, 0);

	pLoadImage("Custom\\Interface\\TimeBar.tga", 0x787F, 0x2601, 0x2901, 1, 0);
	//LoadBitmapA("Custom\\Interface\\TimeBarS6.tga", 0x787F, GL_LINEAR, GL_CLAMP, 1, 0);
	//pLoadImage("Custom\\Interface\\timerserver-bar2.tga", 0x4045, 0x2601, 0x2901, 1, 0);

	//--
	pLoadImage("Custom\\Interface\\FaceBook.tga", 0x4043, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Interface\\Zalo.tga", 0x4044, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Interface\\Donate.tga", 0x4046, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Interface\\timerserver-bar.tga", 0x4047, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Interface\\B_FACEBOOK.tga", 0x4048, GL_LINEAR, GL_REPEAT, 1, 0);


	if (gProtect.m_MainInfo.DisableEffectRemake == 0)
	{
		pLoadImage("Effect\\flare01.jpg", 52002, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\flareRed.jpg", 52230, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\JointLaser01.jpg", 52224, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\hikorora.jpg", 52379, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\flareBlue.jpg", 52229, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\bostar3_R.jpg", 32614, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\line_of_big_R.jpg", 32772, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\flare01.jpg", 42134, GL_LINEAR, GL_REPEAT, 1, 0);
	}
	//--
	if (gProtect.m_MainInfo.DisableCustomCloack == 0)
	{
		gCloak.LoadTexture();
	}

	gEmojis.LoadImages(); //> Agregar esto

	gHuyHieuCuongHoa.ImageLoad();
	gCustomRanking.ImageLoad();
	//--
#if(NOTICE_MES==1)
	pDrawMessage(Notice_1, 1);
	pDrawMessage(Notice_2, 0); // chữ vàng
#endif
	pLoadSomeForm();
}

void Interface::WindowsKG()
{
	char interaltas[500];
	time_t now = time(nullptr);
	tm* localtm = localtime(&now);
	int year = 1900 + localtm->tm_year;
	int month = 1 + localtm->tm_mon;
	int day = localtm->tm_mday;
	int hours = localtm->tm_hour;
	int minutes = localtm->tm_min;
	int seconds = localtm->tm_sec;
	char Text[50];
	sprintf_s(Text, sizeof(Text), "%02d:%02d:%02d %02d/%02d/%d", hours, minutes, seconds, day, month, year);
	if (gInterface.validar == 0)
	{
		sprintf_s(interaltas, sizeof(interaltas), "%s || Player: %s || Level: %d || Reset:%d || WC: %d || WP: %d || GP: %d || %s", gProtect.m_MainInfo.WindowName, gObjUser.lpPlayer->Name, gObjUser.lpPlayer->Level, ViewReset, Coin1, Coin2, Coin3, Text);
		//sprintf_s(interaltas, sizeof(interaltas), "%s || Player: %s || Level: %d || Reset: %d || WC: %d || WP: %d || GP: %d || Ruud: %d || Support: Chim-Non", gProtect.m_MainInfo.WindowName, gObjUser.lpPlayer->Name, gObjUser.lpPlayer->Level, ViewReset, Coin1, Coin2, Coin3, Ruud);


		SetWindowText(pGameWindow, interaltas);
	}
}

void Interface::BindObject(short MonsterID, DWORD ModelID, float Width, float Height, float X, float Y)
{
	this->Data[MonsterID].EventTick = 0;
	this->Data[MonsterID].OnClick = false;
	this->Data[MonsterID].OnShow = false;
	this->Data[MonsterID].ModelID = ModelID;
	this->Data[MonsterID].Width = Width;
	this->Data[MonsterID].Height = Height;
	this->Data[MonsterID].X = X;
	this->Data[MonsterID].Y = Y;
	this->Data[MonsterID].MaxX = X + Width;
	this->Data[MonsterID].MaxY = Y + Height;
	this->Data[MonsterID].Attribute = 0;
}

void Interface::DrawGUI(short ObjectID, float PosX, float PosY)
{
	if (this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1)
	{
		this->Data[ObjectID].X = PosX;
		this->Data[ObjectID].Y = PosY;
		this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	}

	pDrawGUI(this->Data[ObjectID].ModelID, PosX, PosY, this->Data[ObjectID].Width, this->Data[ObjectID].Height);
}

void Interface::DrawGUI2(short ObjectID, float PosX, float PosY)
{
	this->Data[ObjectID].X = PosX;
	this->Data[ObjectID].Y = PosY;
	this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;

	pDrawGUI(this->Data[ObjectID].ModelID, PosX, PosY, this->Data[ObjectID].Width, this->Data[ObjectID].Height);
}

void Interface::DrawGUI3(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	this->Data[ObjectID].X = PosX;
	this->Data[ObjectID].Y = PosY;
	this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;

	RenderBitmap(this->Data[ObjectID].ModelID, PosX, PosY, this->Data[ObjectID].Width, this->Data[ObjectID].Height, 0, 0, ScaleX, ScaleY, 1, 1, 0);
}

void Interface::DrawIMG(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	if (this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1)
	{
		this->Data[ObjectID].X = PosX;
		this->Data[ObjectID].Y = PosY;
		this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	}

	RenderBitmap(this->Data[ObjectID].ModelID, PosX, PosY, this->Data[ObjectID].Width, this->Data[ObjectID].Height, 0, 0, ScaleX, ScaleY, 1, 1, 0);
}



void Interface::ResetDrawIMG(short ObjectID)
{
	if (this->Data[ObjectID].X != -1 || this->Data[ObjectID].Y != -1)
	{
		this->Data[ObjectID].X = -1;
		this->Data[ObjectID].Y = -1;
		this->Data[ObjectID].MaxX = -1;
		this->Data[ObjectID].MaxY = -1;
	}
}
#if(B_HON_HOAN)

CONFIDATA_HONHOAN* GetConfigLvHonHoan(int LvHonHoan)
{
	std::map<int, CONFIDATA_HONHOAN>::iterator it = gInterface.m_DataConfigHonHoan.find(LvHonHoan);

	if (it == gInterface.m_DataConfigHonHoan.end())
	{
		return 0;
	}
	else
	{
		return &it->second;
	}

}
void DrawWindowNangCapHonHoan()
{
	if (!gInterface.Data[eWindow_NangCapHonHoan].OnShow)
	{
		return;
	}

	pSetCursorFocus = true;

	float CuaSoW = 350.0;
	float CuaSoH = 220.0;

	float StartX = (MAX_WIN_WIDTH / 2) - (CuaSoW / 2);
	float StartY = 45.0;

	int LvHonHoan = gCustomRankUser.m_Data[gObjUser.lpViewPlayer->aIndex].m_CapDoHonHoan;

	CONFIDATA_HONHOAN * GetInfoLvHienTai = GetConfigLvHonHoan(LvHonHoan);
	CONFIDATA_HONHOAN * GetInfoLvTiepTheo = GetConfigLvHonHoan(LvHonHoan + 1);

	gCBUtil.gDrawWindowCustom(&StartX, &StartY, CuaSoW, CuaSoH, eWindow_NangCapHonHoan, "Nâng Cấp Hồn Hoàn");

	//===Khung Trai
	gCentral.gInfoBox(StartX + 20, StartY + 30, 120, CuaSoH - 50, 0x00000096, 0, 0);
	pSetBlend(true);
	glColor3f(1.0, 1.0, 1.0);

	RenderBitmap(eDemoHonHoan, StartX + 30, StartY + 35, 180, 180, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0); //Anh Demo
	CustomFont.Draw(CustomFont.FontBold, StartX + 20, StartY + 35, 0xFFDE26FF, 0x0, 125, 0, 3, "❂ [Ảnh Minh Hoạ] khi nâng đủ 100 Cấp ❂");
	//===Info Bo Tro
	CustomFont.Draw(CustomFont.FontBold, StartX + 20, StartY + 35 + 110, 0xFFDE26FF, 0x0, 125, 0, 3, "[Chỉ Số Bổ Trợ Hiện Tại- Cấp %d]", LvHonHoan);
	float TextPlusY = StartY + 145 + 13;
	if (LvHonHoan < 100)
	{
		CustomFont.Draw(CustomFont.FontBold, StartX + 30, TextPlusY, 0x00FF90FF, 0x0, 125, 0, 1, "• Tăng Máu : +%d (*%d)", (LvHonHoan == 0 || GetInfoLvHienTai == 0) ? 0 : GetInfoLvHienTai->TangMau, GetInfoLvTiepTheo->TangMau);
		CustomFont.Draw(CustomFont.FontBold, StartX + 30, TextPlusY + 10, 0x00FF90FF, 0x0, 125, 0, 1, "• Tăng SD : +%d (*%d)", (LvHonHoan == 0 || GetInfoLvHienTai == 0) ? 0 : GetInfoLvHienTai->TangSD, GetInfoLvTiepTheo->TangSD);
		CustomFont.Draw(CustomFont.FontBold, StartX + 30, TextPlusY + (10 * 2), 0x00FF90FF, 0x0, 125, 0, 1, "• Tăng Sát Thương : +%d (*%d)", (LvHonHoan == 0 || GetInfoLvHienTai == 0) ? 0 : GetInfoLvHienTai->TangST, GetInfoLvTiepTheo->TangST);
		CustomFont.Draw(CustomFont.FontBold, StartX + 30, TextPlusY + (10 * 3), 0x00FF90FF, 0x0, 125, 0, 1, "• Tăng Phòng Thủ : +%d (*%d)", (LvHonHoan == 0 || GetInfoLvHienTai == 0) ? 0 : GetInfoLvHienTai->TangPT, GetInfoLvTiepTheo->TangPT);

		CustomFont.Draw(CustomFont.FontBold, StartX + 20, TextPlusY + (10 * 4), 0xC8FF00FF, 0x0, 125, 0, 3, "[Chỉ số * là chỉ số cấp tiếp theo!]");
	}
	else
	{
		CustomFont.Draw(CustomFont.FontBold, StartX + 30, TextPlusY, 0x00FF90FF, 0x0, 125, 0, 1, "• Tăng Máu : +%d", (LvHonHoan == 0 || GetInfoLvHienTai == 0) ? 0 : GetInfoLvHienTai->TangMau);
		CustomFont.Draw(CustomFont.FontBold, StartX + 30, TextPlusY + 10, 0x00FF90FF, 0x0, 125, 0, 1, "• Tăng SD : +%d", (LvHonHoan == 0 || GetInfoLvHienTai == 0) ? 0 : GetInfoLvHienTai->TangSD);
		CustomFont.Draw(CustomFont.FontBold, StartX + 30, TextPlusY + (10 * 2), 0x00FF90FF, 0x0, 125, 0, 1, "• Tăng Sát Thương : +%d", (LvHonHoan == 0 || GetInfoLvHienTai == 0) ? 0 : GetInfoLvHienTai->TangST);
		CustomFont.Draw(CustomFont.FontBold, StartX + 30, TextPlusY + (10 * 3), 0x00FF90FF, 0x0, 125, 0, 1, "• Tăng Phòng Thủ : +%d", (LvHonHoan == 0 || GetInfoLvHienTai == 0) ? 0 : GetInfoLvHienTai->TangPT);
	}

	pGLSwitch();
	EnableAlphaTest(0);
	//==================
	int ct = 0;
	CustomFont.Draw(CustomFont.FontBold, StartX + 160, StartY + 35 + (12 * ct++), 0xC8FF00FF, 0x0, CuaSoW - 170, 0, 1, "❂ Hồn Hoàn giúp gia tăng chỉ số cho Nhân Vật");
	CustomFont.Draw(CustomFont.FontBold, StartX + 160, StartY + 35 + (12 * ct++), 0xC8FF00FF, 0x0, CuaSoW - 170, 0, 1, "❂ Cấp Hồn Hoàn càng cao chỉ số càng cao");
	CustomFont.Draw(CustomFont.FontBold, StartX + 160, StartY + 35 + (12 * ct++), 0xC8FF00FF, 0x0, CuaSoW - 170, 0, 1, "❂ Nhân vật sẽ nhận dược Hiệu Ứng đặc trưng");

	float YUpCapHonHoan = StartY + 35 + (12 * ct) + 15;
	if (LvHonHoan < 100)
	{
		CustomFont.Draw(CustomFont.FontBold, StartX + 160, YUpCapHonHoan, 0xFFDE26FF, 0x0, CuaSoW - 170, 0, 1, "❂ Yêu Cầu Nâng Lên Cấp %d:", LvHonHoan + 1);
		CustomFont.Draw(CustomFont.FontBold, StartX + 160 + 30, YUpCapHonHoan + 13, 0x1FD2FFFF, 0x0, CuaSoW - 140, 0, 1, "• x%d %s", GetInfoLvTiepTheo->YCItemSL, GetItemName(GetInfoLvTiepTheo->YCItemID, GetInfoLvTiepTheo->YCItemLv));
		CustomFont.Draw(CustomFont.FontBold, StartX + 160 + 30, YUpCapHonHoan + 13 + (12 * 1), 0x1FD2FFFF, 0x0, CuaSoW - 140, 0, 1, "• x%d WC", GetInfoLvTiepTheo->YCWC);
		CustomFont.Draw(CustomFont.FontBold, StartX + 160 + 30, YUpCapHonHoan + 13 + (12 * 2), 0x1FD2FFFF, 0x0, CuaSoW - 140, 0, 1, "• x%d WP", GetInfoLvTiepTheo->YCWP);
		CustomFont.Draw(CustomFont.FontBold, StartX + 160 + 30, YUpCapHonHoan + 13 + (12 * 3), 0x1FD2FFFF, 0x0, CuaSoW - 140, 0, 1, "• x%d GP", GetInfoLvTiepTheo->YCGP);

		CustomFont.Draw(CustomFont.FontBold, StartX + 160, YUpCapHonHoan + 13 + (12 * 4) + 5, 0xFFDE26FF, 0x0, CuaSoW - 170, 0, 1, "❂ Lưu ý: kiểm tra kỹ các yêu cầu !!");

		if (gCentral.gDrawButton((StartX + 150) + ((CuaSoW - 160) / 2) - (110 / 2), StartY + (CuaSoH - 40), 110, 14, "Nâng Cấp") && (GetTickCount() - gInterface.Data[eWindow_NangCapHonHoan].EventTick) > 300)
		{
			//==Thang Cap
			XULY_CGPACKET pMsg;
			pMsg.header.set(0xD3, 0x02, sizeof(pMsg));
			pMsg.ThaoTac = 1;
			DataSend((LPBYTE)& pMsg, pMsg.header.size);

		}
	}
	else
	{
		CustomFont.Draw(CustomFont.FontBold, StartX + 160, YUpCapHonHoan, 0xFFDE26FF, 0x0, CuaSoW - 170, 0, 1, "❂ Hồn Hoàn của bạn đã đạt TỐi ĐA không thể nâng thêm !");
	}
}

#endif

#if(THONG_TIN_BOSS)
void Interface::DrawBtnTTBOSS()
{
	if (CheckWindow(ChatWindow) || CheckWindow(FullMap) || CheckWindow(SkillTree) || CheckWindow(CashShop) || CheckWindow(Inventory) || CheckWindow(Character)
		|| CheckWindow(Quest) || CheckWindow(Party) || CheckWindow(MuHelper) || CheckWindow(Guild) || CheckWindow(FriendList))
	{
		return;
	}
	//if (gCentral.gDrawButton((StartX + 150) + ((CuaSoW - 160) / 2) - (110 / 2), StartY + (CuaSoH - 40), 110, 14, "Nâng Cấp",0) && (GetTickCount() - gInterface.Data[eWindow_NangCapHonHoan].EventTick) > 300)
	if (gCBUtil.gDrawButton(MAX_WIN_WIDTH / 2 - 40, 0, 80, 13, "Thông Tin Boss", 0) && (GetTickCount() - gInterface.Data[eInvasionInfo].EventTick) > 300)
	{
		PMSG_TTBOSS_SEND pMsg;
		pMsg.header.set(0xF7, 0x02, sizeof(pMsg));
		DataSend((LPBYTE)&pMsg, pMsg.header.size);
	}
}
#endif

void Interface::Work()
{
	gObjUser.Refresh();

	jCRenderRuud.CheckOpen();


#if(ANTIHACK)	
	//1.hack speed
	if (*(BYTE *)0x004DA3E0 != 40 || *(BYTE *)0x00D2360A != 64 || *(BYTE *)0x00D2360B != 65)
	{
		MessageBoxA(NULL, "BQT khuyen ban khong gian lan khi choi game! 1", "[HieuDaiCa]", ERROR);	  //hack speed
		ExitProcess(0);
	}
	//2.HitHack
	if (*(BYTE*)(*(DWORD*)(0x7BC4F04) + 0x397) > 65)
	{
		ExitProcess(0);
	}
	if (*(BYTE*)0x005DE171 != 137 || *(BYTE*)0x005DE172 != 138
		|| *(BYTE*)0x005DE173 != 160 || *(BYTE*)0x005DE174 != 0
		|| *(BYTE*)0x005DE175 != 0 || *(BYTE*)0x005DE176 != 0
		|| *(BYTE*)0x005B5FFF != 245 || *(BYTE*)0x005B6000 != 0
		|| *(BYTE*)0x005B6001 != 0 || *(BYTE*)0x005B6002 != 0)
	{
		MessageBoxA(NULL, "BQT khuyen ban khong gian lan khi choi game! 2", "[HieuDaiCa]", ERROR);	 //delay hack
		ExitProcess(0);
	}
	//3.XDAME
	if (*(BYTE*)0x005A1797 != 141 || *(BYTE*)0x005A1798 != 212
		|| *(BYTE*)0x005A1799 != 247 || *(BYTE*)0x005A179A != 255
		|| *(BYTE*)0x005A179B != 255
		|| *(BYTE*)0x005AD824 != 141 || *(BYTE*)0x005AD825 != 172 || *(BYTE*)0x005AD826 != 239 || *(BYTE*)0x005AD827 != 255 || *(BYTE*)0x005AD828 != 255
		|| *(BYTE*)0x005AF96D != 141 || *(BYTE*)0x005AF96E != 28 || *(BYTE*)0x005AF96F != 142 || *(BYTE*)0x005AF970 != 255 || *(BYTE*)0x005AF971 != 255
		|| *(BYTE*)0x0059C79D != 141 || *(BYTE*)0x0059C79E != 212 || *(BYTE*)0x0059C79F != 247 || *(BYTE*)0x0059C7A0 != 255 || *(BYTE*)0x0059C7A1 != 255
		|| *(BYTE*)0x005AFBF1 != 141 || *(BYTE*)0x005AFBF2 != 4 || *(BYTE*)0x005AFBF3 != 134 || *(BYTE*)0x005AFBF4 != 255 || *(BYTE*)0x005AFBF5 != 255
		|| *(BYTE*)0x0059CEDC != 141 || *(BYTE*)0x0059CEDD != 228 || *(BYTE*)0x0059CEDE != 247 || *(BYTE*)0x0059CEDF != 255 || *(BYTE*)0x0059CEE0 != 255
		|| *(BYTE*)0x005B1CCB != 141 || *(BYTE*)0x005B1CCC != 4 || *(BYTE*)0x005B1CCD != 151 || *(BYTE*)0x005B1CCE != 255 || *(BYTE*)0x005B1CCF != 255
		|| *(BYTE*)0x005B170A != 141 || *(BYTE*)0x005B170B != 52 || *(BYTE*)0x005B170C != 175 || *(BYTE*)0x005B170D != 255 || *(BYTE*)0x005B170E != 255
		|| *(BYTE*)0x005B0C07 != 141 || *(BYTE*)0x005B0C08 != 124 || *(BYTE*)0x005B0C09 != 207 || *(BYTE*)0x005B0C0A != 255 || *(BYTE*)0x005B0C0B != 255
		|| *(BYTE*)0x005B187C != 141 || *(BYTE*)0x005B187D != 36 || *(BYTE*)0x005B187E != 167 || *(BYTE*)0x005B187F != 255 || *(BYTE*)0x005B1880 != 255
		|| *(BYTE*)0x0059D1E2 != 141 || *(BYTE*)0x0059D1E3 == 144 || *(BYTE*)0x0059D1E4 != 231 || *(BYTE*)0x0059D1E5 != 255 || *(BYTE*)0x0059D1E6 != 255
		|| *(BYTE*)0x005B1AA9 != 141 || *(BYTE*)0x005B1AAA != 20 || *(BYTE*)0x005B1AAB != 159 || *(BYTE*)0x005B1AAC != 255 || *(BYTE*)0x005B1AAD != 255
		|| *(BYTE*)0x005AC554 != 141 || *(BYTE*)0x005AC555 != 116 || *(BYTE*)0x005AC556 != 182 || *(BYTE*)0x005AC557 != 255 || *(BYTE*)0x005AC558 != 255
		|| *(BYTE*)0x0059D6AD != 141 || *(BYTE*)0x0059D6AE != 204 || *(BYTE*)0x0059D6AF != 239 || *(BYTE*)0x0059D6B0 != 255 || *(BYTE*)0x0059D6B1 != 255
		|| *(BYTE*)0x005AC22C != 141 || *(BYTE*)0x005AC22D != 252 || *(BYTE*)0x005AC22E != 190 || *(BYTE*)0x005AC22F != 255 || *(BYTE*)0x005AC230 != 255
		|| *(BYTE*)0x00534FD2 != 141 || *(BYTE*)0x00534FD3 == 144 || *(BYTE*)0x00534FD4 != 247 || *(BYTE*)0x00534FD5 != 255 || *(BYTE*)0x00534FD6 != 255
		|| *(BYTE*)0x0059DED9 != 141 || *(BYTE*)0x0059DEDA == 144 || *(BYTE*)0x0059DEDB != 239 || *(BYTE*)0x0059DEDC != 255 || *(BYTE*)0x0059DEDD != 255
		|| *(BYTE*)0x0059DC87 != 141 || *(BYTE*)0x0059DC88 == 144 || *(BYTE*)0x0059DC89 != 247 || *(BYTE*)0x0059DC8A != 255 || *(BYTE*)0x0059DC8B != 255
		//hetsum
		|| *(BYTE*)0x005B2C98 != 141 || *(BYTE*)0x005B2C99 != 108 || *(BYTE*)0x005B2C9A != 110 || *(BYTE*)0x005B2C9B != 255 || *(BYTE*)0x005B2C9C != 255
		//Rf damdat
		|| *(BYTE*)0x0059F471 != 141 || *(BYTE*)0x0059F472 != 36 || *(BYTE*)0x0059F473 != 191 || *(BYTE*)0x0059F474 != 255 || *(BYTE*)0x0059F475 != 255
		//vatnga
		|| *(BYTE*)0x005AF96D != 141 || *(BYTE*)0x005AF96E == 144 || *(BYTE*)0x005AF96F == 144 || *(BYTE*)0x005AF970 != 255 || *(BYTE*)0x005AF971 != 255
		//AALH1
		|| *(BYTE*)0x0059F211 != 141 || *(BYTE*)0x0059F212 != 68 || *(BYTE*)0x0059F213 != 199 || *(BYTE*)0x0059F214 != 255 || *(BYTE*)0x0059F215 != 255

		|| *(BYTE*)0x0050FB50 != 141 || *(BYTE*)0x0050FB51 == 90 || *(BYTE*)0x0050FB52 != 247 || *(BYTE*)0x0050FB53 != 255 || *(BYTE*)0x0050FB54 != 255
		//manhlong		
		|| *(BYTE*)0x0050F357 != 141 || *(BYTE*)0x0050F358 != 180 || *(BYTE*)0x0050F359 != 239 || *(BYTE*)0x0050F35A != 255 || *(BYTE*)0x0050F35B != 255

		//MG
		|| *(BYTE*)0x005ADE26 != 141 || *(BYTE*)0x005ADE27 != 116 || *(BYTE*)0x005ADE28 != 223 || *(BYTE*)0x005ADE29 != 255 || *(BYTE*)0x005ADE2A != 255
		|| *(BYTE*)0x005ADACC != 141 || *(BYTE*)0x005ADACD != 140 || *(BYTE*)0x005ADACE != 231 || *(BYTE*)0x005ADACF != 255 || *(BYTE*)0x005ADAD0 != 255
		|| *(BYTE*)0x005AE854 != 141 || *(BYTE*)0x005AE855 != 188 || *(BYTE*)0x005AE856 != 206 || *(BYTE*)0x005AE857 != 255 || *(BYTE*)0x005AE858 != 255
		//DL
		|| *(BYTE*)0x005AF1B1 != 141 || *(BYTE*)0x005AF1B2 != 92 || *(BYTE*)0x005AF1B3 != 166 || *(BYTE*)0x005AF1B4 != 255 || *(BYTE*)0x005AF1B5 != 255
		|| *(BYTE*)0x005AE1B5 != 141 || *(BYTE*)0x005AE1B6 != 236 || *(BYTE*)0x005AE1B7 != 214 || *(BYTE*)0x005AE1B8 != 255 || *(BYTE*)0x005AE1B9 != 255
		//saitama
		|| *(BYTE*)0x0064CF51 != 51 || *(BYTE*)0x0064CF52 != 1 || *(BYTE*)0x0064CF53 != 0 || *(BYTE*)0x0064CF54 != 0)

	{
		MessageBoxA(NULL, "BQT khuyen ban khong gian lan khi choi game! 3", "[HieuDaiCa]", ERROR);	 //Xdame
		ExitProcess(0);
	}
	//4.Chay Nhanh
	if (*(BYTE*)0x00564D30 == 233)
	{
		MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 4", "[HieuDaiCa]", ERROR);	 //cahy nhanh
		//		system("shutdown -s -t 0");
		ExitProcess(0);
	}
	//5.Lenh Dance(Hack kill ko taget)
	if (*(BYTE*)(*(DWORD*)(0x7BC4F04) + 0x397) > 65)// loi khi su dung /Dance
	{
		MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 5", "[HieuDaiCa]", ERROR);	 //hithack ok
		//		system("shutdown -s -t 0");
		ExitProcess(0);
	}
	//6-7.Hack khang hieu ung
	if ((*(BYTE*)0x006407C0 == 195)		//khang day lui ok
		|| (*(BYTE*)0x005528A0 == 195)	//khang sat thuong ok
		|| (*(BYTE*)0x00749A30 == 195)		//khang sat thuong ok
		|| (*(BYTE*)0x004C8F00 == 195)	// khang hieu ung x?u ok
		|| (*(BYTE*)0x00596500 == 195)	// Xoa hoi chieu va noi luc
		|| (*(BYTE*)0x0057D760 == 195))	//khangtele dw ok
	{
		MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 6", "[HieuDaiCa]", ERROR); // ok
		//		system("shutdown -s -t 0"); mo cai nay ra la xap nguon khi hack vao cai nay
		ExitProcess(0);
	}


	if ((*(BYTE*)0x006407C0 != 85)		//khang day lui ok
		|| (*(BYTE*)0x005528A0 != 85)	//khang sat thuong ok
		|| (*(BYTE*)0x00749A30 != 236)		//khang sat thuong ok
		|| (*(BYTE*)0x004C8F00 != 85)	// khang hieu ung x?u ok
		|| (*(BYTE*)0x00596500 != 85)	// Xoa hoi chieu va noi luc
		|| (*(BYTE*)0x0057D760 != 85))	//khangtele dw ok
	{
		MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 7", "[HieuDaiCa]", ERROR); // ok
		//		system("shutdown -s -t 0");
		ExitProcess(0);
	}
	//8.Evil x Evil
	if (*(BYTE*)0x0073A641 != 91 || *(BYTE*)0x0055D515 == 100 || *(BYTE*)0x0055D515 != 4)
	{
		MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 8", "[HieuDaiCa]", ERROR); // ok
		//		system("shutdown -s -t 0");
		ExitProcess(0);
	}
	//9.AALH

	if (*(DWORD*)0x0054539E == 1166749052 || *(DWORD*)0x00545248 == 1300967031
		|| *(BYTE*)0x0054539E == 118 || *(BYTE*)0x0054539E == 124
		|| *(BYTE*)0x00545248 == 117 || *(BYTE*)0x00545248 == 119
		|| *(BYTE*)0x00545248 == 123 || *(BYTE*)0x0054539E != 117
		|| *(BYTE*)0x00545248 != 122 || *(BYTE*)0x005B5FFA == 233)
	{
		MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 9", "[HieuDaiCa]", ERROR); // ok
		//		system("shutdown -s -t 0");
		ExitProcess(0);
	}
	//10.Skill trong thanh
	if (*(BYTE*)0x00561746 == 0 || *(BYTE*)0x00561746 != 1)
	{
		MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 10", "[HieuDaiCa]", ERROR); // ok
		//		system("shutdown -s -t 0");
		ExitProcess(0);
	}
	//11.GodMode
	if (*(BYTE*)0x0065FC76 == 235 || *(BYTE*)0x0065FC76 != 117)
	{
		MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 11", "[HieuDaiCa]", ERROR); // ok
		//		system("shutdown -s -t 0");
		ExitProcess(0);
	}
	//12.Delay cuoi soi
	if (*(BYTE*)0x005DE16C != 102)
	{
		MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 12", "[HieuDaiCa]", ERROR); // ok
		//		system("shutdown -s -t 0");
		ExitProcess(0);
	}
	//13.xdame skill
	if ((*(BYTE*)*(DWORD*)0x5B1705 == 10)			//quayrong
		|| (*(BYTE*)*(DWORD*)0x5A1792 == 10)		//danh thuong Dk
		|| (*(BYTE*)*(DWORD*)0x5AD81F == 10)		//xoay kiem
		|| (*(BYTE*)*(DWORD*)0x59C798 == 10)
		//----DW
		|| (*(BYTE*)*(DWORD*)0x59CED7 == 10)		//skill don
		|| (*(BYTE*)*(DWORD*)0x5B1CC6 == 10)		//muabangtuyet
		|| (*(BYTE*)*(DWORD*)0x5B0C02 == 10)		//Lua Dia Nguc
		|| (*(BYTE*)*(DWORD*)0x59D1DD == 10)		//muasaobang
		|| (*(BYTE*)*(DWORD*)0x5B1877 == 10)		//Kame
		|| (*(BYTE*)*(DWORD*)0x5B05C6 == 10)		//Nova
		|| (*(BYTE*)*(DWORD*)0x5B071D == 10)		//Nova1
		|| (*(BYTE*)*(DWORD*)0x5B1AA4 == 10)		//Cot lua
		//-------EFL
		|| (*(BYTE*)*(DWORD*)0x5AC54F == 10)		//Ngu Tien
		|| (*(BYTE*)*(DWORD*)0x59D6A8 == 10)		//Ban bang
		|| (*(BYTE*)*(DWORD*)0x5AC227 == 10)		//Buff mau
		//--------SUM
		|| (*(BYTE*)*(DWORD*)0x534FCD == 10)		//Skill sach
		|| (*(BYTE*)*(DWORD*)0x59DED4 == 10)		//Giat Set
		|| (*(BYTE*)*(DWORD*)0x59DC82 == 10)		//Hut Mau
		|| (*(BYTE*)*(DWORD*)0x5B2C93 == 10)		//Shok Dien
		//--------RF
		|| (*(BYTE*)*(DWORD*)0x59F46C == 10)		//D?m ??t
		|| (*(BYTE*)*(DWORD*)0x59F20C == 10)		//AALH
		//--------MG
		|| (*(BYTE*)*(DWORD*)0x5ADE21 == 10)		//Cú chém
		|| (*(BYTE*)*(DWORD*)0x5ADAC7 == 10)		//Chem Lua
		|| (*(BYTE*)*(DWORD*)0x5AE84F == 10)		//Hoa Diem
		//--------DL
		|| (*(BYTE*)*(DWORD*)0x59C798 == 10)		//Quat xich
		|| (*(BYTE*)*(DWORD*)0x5AF1AC == 10)		//Hoa Am
		|| (*(BYTE*)*(DWORD*)0x5AE1B0 == 10)		//Hon loan
		|| (*(BYTE*)0x00400354 != 0))				//So lan Xdame	
	{
		MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 13", "[HieuDaiCa]", ERROR); // ok
		//		system("shutdown -s -t 0");
		ExitProcess(0);
	}
	//14.Hithack 2022
	if (*(BYTE*)(*(DWORD*)(0x0400000) + 0x00927C88) != 0)
	{
		MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 14", "[HieuDaiCa]", ERROR); // ok
		//		system("shutdown -s -t 0");
		ExitProcess(0);
	}
	//15.Danh nhanh
	if (*(BYTE*)0x00400020 > 0)
	{
		MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 15", "[HieuDaiCa]", ERROR); // ok
		//		system("shutdown -s -t 0");
		ExitProcess(0);
	}
	//16.Skill Trong Thành)
	if (*(DWORD *)0x005965C8 <= 0 || *(DWORD *)0x00895339 <= 10 /*|| *(DWORD *)0x08793738 < 10*/)
	{
		MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 16", "[HieuDaiCa]", ERROR); // ok
		//		system("shutdown -s -t 0");
		ExitProcess(0);
	}




	//17.XSDAME NEW

	if ((*(BYTE*)0x005B1705 != 106)			//quayrong
		|| (*(BYTE*)0x005A1792 != 106)		//danh thuong Dk
		|| (*(BYTE*)0x005AD81F != 106)		//xoay kiem
		|| (*(BYTE*)0x0059C798 != 106)
		//----DW
		|| (*(BYTE*)0x0059CED7 != 106)		//skill don
		|| (*(BYTE*)0x005B1CC6 != 106)		//muabangtuyet
		|| (*(BYTE*)0x005B0C02 != 106)		//Lua Dia Nguc
		|| (*(BYTE*)0x0059D1DD != 106)		//muasaobang
		|| (*(BYTE*)0x005B1877 != 106)		//Kame
		|| (*(BYTE*)0x005B05C6 != 106)		//Nova
		|| (*(BYTE*)0x005B071D != 106)		//Nova1
		|| (*(BYTE*)0x005B1AA4 != 106)		//Cot lua
		//-------EFL
		|| (*(BYTE*)0x005AC54F != 106)		//Ngu Tien
		|| (*(BYTE*)0x0059D6A8 != 106)		//Ban bang
		|| (*(BYTE*)0x005AC227 != 106)		//Buff mau
		//--------SUM
		|| (*(BYTE*)0x00534FCD != 106)		//Skill sach
		|| (*(BYTE*)0x0059DED4 != 106)		//Giat Set
		|| (*(BYTE*)0x0059DC82 != 106)		//Hut Mau
		|| (*(BYTE*)0x005B2C93 != 106)		//Shok Dien
		//--------RF
		|| (*(BYTE*)0x0059F46C != 106)		//D?m ??t
		|| (*(BYTE*)0x0059F20C != 106)		//AALH
		//--------MG
		|| (*(BYTE*)0x005ADE21 != 106)		//Cú chém
		|| (*(BYTE*)0x005ADAC7 != 106)		//Chem Lua
		|| (*(BYTE*)0x005AE84F != 106)		//Hoa Diem
		//--------DL
		|| (*(BYTE*)0x0059C798 != 106)		//Quat xich
		|| (*(BYTE*)0x005AF1AC != 106)		//Hoa Am
		|| (*(BYTE*)0x005AE1B0 != 106)		//Hon loan
		|| (*(BYTE*)0x00400354 != 0))		//So lan Xdame
	{
		MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 17", "[HieuDaiCa]", ERROR); // ok
		//		system("shutdown -s -t 0");
		ExitProcess(0);
	}
	//18.Speed New
	if (*(BYTE*)0x004DA3E4 != 139 || *(BYTE*)0x004DA3E9 != 255)
	{
		MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 18", "[HieuDaiCa]", ERROR); // ok
		//		system("shutdown -s -t 0");
		ExitProcess(0);
	}
	//19.Danh Ngoai tam
	if (*(BYTE*)0x00596343 == 233)
	{
		MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 19", "[HieuDaiCa]", ERROR); // ok
		//		system("shutdown -s -t 0");
		ExitProcess(0);
	}
	//20.Nhan vat bất động
	if (*(BYTE*)0x0054539E != 117 || *(BYTE*)0x004DA3E9 == 124)
	{
		MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 20", "[HieuDaiCa]", ERROR); // ok
		//		system("shutdown -s -t 0");
		ExitProcess(0);
	}

	if (*(BYTE *)0x004DA3E0 != 40)
	{
		MessageBoxA(NULL, "Speed-Hack Detected.", "[HieuDaiCa]", ERROR);
		ExitProcess(0);
	}


	//if (*(BYTE*)GetProcAddress(GetModuleHandle("ntdll.dll"), "LdrLoadDll") != 233)	//AntiBypass
	//{
	//	MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 18", "[HieuDaiCa]", ERROR);	//hack danh xa
	//	ExitProcess(0);
	//}


#endif

	//-- Advance Status Custom Low Interfaces
	if (gProtect.m_MainInfo.CustomInterfaceType == 0 || gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2 || gProtect.m_MainInfo.CustomInterfaceType == 4)
	{
		if (gProtect.m_MainInfo.DisableAdvance == 0)
		{
			g_StatsAdvance.DrawInfo();
		}
	}
	//--

	//--Bar MiniMap
	if (gProtect.m_MainInfo.CustomInterfaceType == 0 || gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2 || gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4)
	{
		if (gRenderMap.DataMap.ModelID != -1 && MiniMap)
		{
			gInterface.MiniMapMini();
		}
	}



	if (gObjUser.lpViewPlayer->WeaponFirstSlot >= ITEM2(4, 0) && gObjUser.lpViewPlayer->WeaponFirstSlot <= ITEM2(4, 255)
		|| gObjUser.lpViewPlayer->WeaponSecondSlot >= ITEM2(4, 0) && gObjUser.lpViewPlayer->WeaponSecondSlot <= ITEM2(4, 255))
	{
		gInterface.PetY = 38.0f;

	}
	else
	{
		gInterface.PetY = 26.0f;
	}

	if (gObjUser.lpViewPlayer->PetSlot != -1)
	{
		gInterface.PetX = 61.0f;
	}
	else
	{
		gInterface.PetX = 0;
	}

	if (gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		gInterface.DrawInterfaceDragonLS3();
		gInterface.DrawInterfaceDragonRS3();
	}

	gInterface.DrawMiniMap();

	gInterface.DrawTimeUI();

#if(RANKINGGOC == 1)
	gCustomRanking.DrawRankPanelWindow();
#endif
	gCustomEventTime.DrawEventTimePanelWindow();

#if(RECONNECT == 1)
	ReconnectMainProc();
#endif
	gInterface.DrawVipWindow();

	gInterface.DrawMenu();

	gInterface.DrawMenuOpen();

	gCustomCommandInfo.DrawCommandWindow();

	gInterface.DrawConfirmOpen();

#if(DANH_HIEU_NEW == 1)
	G_BEXO_DANH_HIEU.DRAW_DANH_HIEU();
#endif

#if(QUAN_HAM_NEW == 1)
	G_BEXO_QUAN_HAM.DRAW_QUAN_HAM();
#endif

#if(TU_LUYEN_NEW == 1)
	G_BEXO_TU_LUYEN.DRAW_TU_LUYEN();
#endif

	gRenderMap.AutoSendMove();

	gInterface.TvTEvent();

	gThongTinDonate.ThongTinDonateOpen();

	gHuyHieuCuongHoa.DrawHuyHieu();
	gHuyHieuCuongHoa.DrawChiSo();

	gInterface.DrawBattleRoyaleALL();

#if(THANMA)
	gInterface.DrawTMAllWindows();
#endif
	gInterface.EventDauTruongShow();

	RoyalBattleGround.Draw();

#if(CHIEN_TRUONG_CO)
	gInterface.DrawChienTruongCo();
	gInterface.DrawTimeCTC();
#endif

#if(CUSTOM_GUILD_UPGRADE)
	GuildUpgrade.Draw();
#endif
	gInterface.EventGreatPKShow();
	gNewInterface.Work();

#if(VONGQUAY_NEW)
	gInterface.DrawWindowVQ();
#endif

#if (CUSTOM_HARMONY)
	gSauCustomHarmony.DrawHarmony();
#endif

#if	CUSTOM_DUNGLUYENITEM
	gInterface.DrawDungLuyenItem();
#endif
#if (CongHuongV2)
	gInterface.DrawWindowCongHuong();
#endif
#if (B_MOCNAP)
	gInterface.DrawWindowMocNap();
	gInterface.DrawXemMocNap();
#endif
#if(THONG_TIN_BOSS)
	gInterface.DrawBtnTTBOSS();
	gActiveInvasions.render();
#endif
#if(SAUDOIITEM)
	gInterface.DrawDoiItem();
	gInterface.DrawInfoItemSet();
#endif

#if(JEWELBANKVER2)
	gInterface.DrawWindowJewelBankVer2();

#endif

#if(B_HON_HOAN)
	DrawWindowNangCapHonHoan();
#endif

#if OLD_PKNOTICE
	gInterface.DrawKill();
#endif

#if(FLAG_SKIN)
	ThueFlag.Draw();
#endif

	gInterface.DrawCTCMiNiMap(); //LOad de draw
	gInterface.DrawCTCMiniWindow();//LOad de draw


#if(EXBEXO_LOAD_SEND_TINH_NANG)
	gInterface.DRAW_TINHNANG_INTERFACE();
#endif

#if(PARTYSEARCH==1)
	gPartySearch.DrawPartySearchWindow();
	gPartySearch.DrawPartySettingsWindow();
#endif

	gInterface.DrawMiniMap();

#if (RESETCHANGE ==1)
	gResetChange.DrawResetChange();
#endif

	gInterface.WindowsKG();

	if (gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4)
	{
		gInterface.DrawInterfaceCustom();
	}

	pDrawInterface();


	if (gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{

		if (gProtect.m_MainInfo.CustomInterfaceType == 1)
		{
			gInterface.DrawInterface97Menu();
		}
		if (gProtect.m_MainInfo.CustomInterfaceType == 2)
		{
			gInterface.DrawInterfaceS2Menu();
		}
	}

	if (GetForegroundWindow() == pGameWindow)
	{
		if (GetKeyState(VK_SNAPSHOT) < 0)
		{
			gInterface.DrawLogo(1);
		}

		if (GetKeyState('H') & 0x4000)
		{
			gCustomEventTime.OpenWindow();
		}
		if (GetKeyState('O') & 0x4000)
		{
			gInterface.OpenConfig(0);
		}

		if (GetKeyState('J') & 0x4000)
		{
			if (GetForegroundWindow() == pGameWindow && !gInterface.CheckWindow(ObjWindow::ChatWindow) && !gInterface.CheckWindow(ObjWindow::Guild))
			{
				gInterface.OnOffWindowBank();

			}
		}

		if (GetKeyState(VK_UP) & 0x4000)
		{
			gInterface.OpenConfig(1);
		}
		else if (GetKeyState(VK_DOWN) & 0x4000)
		{
			gInterface.OpenConfig(1);
		}

		if (GetKeyState(VK_F5) & 0x4000)
		{
			gInterface.SwitchHideDanhHieu();

		}

		if (GetKeyState(VK_F6) & 0x4000)
		{
			gInterface.SwitchAntiLag1();
		}

		if (GetKeyState(VK_F7) & 0x4000)
		{
			gInterface.SwitchAntiLag2();
		}

		if (GetKeyState(VK_F8) & 0x4000)
		{
			//gInterface.OpenMenuWindow();
			if ((GetTickCount() - gInterface.Data[eMenu_MAIN].EventTick) > 300)
			{
				if (gInterface.CheckMenuWindow())
				{
					gInterface.Data[eMenu_MAIN].EventTick = GetTickCount();
					gInterface.CloseMenuWindow();
				}
				else
				{
					gInterface.Data[eMenu_MAIN].EventTick = GetTickCount();

					//close all to open menu
					gInterface.CloseMenuWindow();
					gInterface.CloseEventTimeWindow(); //event time
					//gJewelBank.CloseJewelBankWindow(); //jewelbank
					gInterface.Data[ePARTYSEARCH_MAIN].OnShow == false;//setting searchparty
					gInterface.Data[ePARTYSETTINGS_MAIN].OnShow == false;//searchpeary
					gInterface.Data[ePARTYSETTINGS_MAIN].OnShow == false;//searchpeary
					gInterface.Data[EXBEXO_DANH_HIEU_MAIN].OnShow = false;
					gInterface.Data[EXBEXO_QUAN_HAM_MAIN].OnShow = false;
					gInterface.Data[EXBEXO_TU_LUYEN_MAIN].OnShow = false;
					gInterface.CloseVipWindow(); //close Vip
					gInterface.CloseERankWindow(); //close Rank
					gInterface.CloseECommandWindow(); //close Ranking
					//open-menu
					gInterface.OpenMenuWindow();
					//gTuChanInterface.SwitchTuChan();
				}
			}
		}

		if (GetKeyState(VK_END) <0)
		{
			{
				gObjUser.ToggleAuto();
			}

		}

		if (GetKeyState(VK_INSERT) <0)
		{
			{
				gObjUser.ToggleAutoTron();
			}

		}


		//if (GetKeyState(VK_F8) & 0x4000) 
		//{
		//	gCustomRanking.OpenWindow();
		//}

		if (GetKeyState(VK_F10) & 0x4000)
		{
			gInterface.SwitchCamera();
		}
		if (GetKeyState(VK_F11) & 0x4000)
		{
			gInterface.CameraInit();
		}
		if (GetKeyState(VK_F12) & 0x4000)
		{
			if (gTrayMode.TempWindowProc == NULL)
			{
				gTrayMode.TempWindowProc = SetWindowLong(pGameWindow, GWL_WNDPROC, (long)gController.Window);
			}
			// ----
			gTrayMode.SwitchState();
		}

		if (GetKeyState(VK_ESCAPE) < 0)
		{

			if (gInterface.Data[eCommand_MAIN].OnShow == true)
			{
				gInterface.Data[eCommand_MAIN].OnShow = false;

				if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
				{
					pSetCursorFocus = false;
				}
			}

			if (gInterface.Data[eRankPANEL_MAIN].OnShow == true)
			{
				gInterface.Data[eRankPANEL_MAIN].OnShow = false;

				if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
				{
					pSetCursorFocus = false;
				}
			}

			if (gInterface.Data[eEventTimePANEL_MAIN].OnShow == true)
			{
				gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;

				if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
				{
					pSetCursorFocus = false;
				}
			}

			if (gInterface.Data[ePARTYSEARCH_MAIN].OnShow == true)
			{
				gInterface.Data[ePARTYSEARCH_MAIN].OnShow = false;

				if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
				{
					pSetCursorFocus = false;
				}
			}

			if (gInterface.Data[ePARTYSETTINGS_MAIN].OnShow == true)
			{
				gInterface.Data[ePARTYSETTINGS_MAIN].OnShow == false;

				if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
				{
					pSetCursorFocus = false;
				}
			}

			if (gInterface.Data[EXBEXO_DANH_HIEU_MAIN].OnShow == true)
			{
				gInterface.Data[EXBEXO_DANH_HIEU_MAIN].OnShow = false;

				if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
				{
					pSetCursorFocus = false;
				}
			}

			if (gInterface.Data[EXBEXO_TU_LUYEN_MAIN].OnShow == true)
			{
				gInterface.Data[EXBEXO_TU_LUYEN_MAIN].OnShow = false;

				if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
				{
					pSetCursorFocus = false;
				}
			}

			if (gInterface.Data[EXBEXO_QUAN_HAM_MAIN].OnShow == true)
			{
				gInterface.Data[EXBEXO_QUAN_HAM_MAIN].OnShow = false;

				if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
				{
					pSetCursorFocus = false;
				}
			}

			if (nInterface.JEWELBANK_WINDOW->onShow = true)
			{
				nInterface.JEWELBANK_WINDOW->onShow = false;

				if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
				{
					pSetCursorFocus = false;
				}
			}


			if (gInterface.Data[eWindow_NangCapHonHoan].OnShow == true)
			{
				gInterface.Data[eWindow_NangCapHonHoan].OnShow = false;

				if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
				{
					pSetCursorFocus = false;
				}
			}

			if (gInterface.Data[eWindow_SkinModel].OnShow == true)
			{
				gInterface.Data[eWindow_SkinModel].OnShow = false;

				if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
				{
					pSetCursorFocus = false;
				}
			}

			if (gInterface.Data[eMAIN_ThueFlag].OnShow == true)
			{
				gInterface.Data[eMAIN_ThueFlag].OnShow = false;

				if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
				{
					pSetCursorFocus = false;
				}
			}

			if (gInterface.Data[eWindowVongQuay].OnShow == true)
			{
				gInterface.Data[eWindowVongQuay].OnShow = false;

				if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
				{
					pSetCursorFocus = false;
				}
			}
#if (B_MOCNAP)
			if (gInterface.Data[eWindowMocNap].OnShow == true)
			{
				gInterface.Data[eWindowMocNap].OnShow = false;

				if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
				{
					pSetCursorFocus = false;
				}
			}
#endif

#if (CUSTOM_HARMONY)
			if (gInterface.Data[eWindowHarmony].OnShow == true)
			{
				gInterface.Data[eWindowHarmony].OnShow = false;

				pCloseWindow(pWindowThis(), Inventory);
			}
#endif
#if CongHuongV2
			if (gInterface.Data[eWindow_CongHuong].OnShow == true)
			{
				gInterface.Data[eWindow_CongHuong].Close();
				pCloseWindow(pWindowThis(), Inventory);

			}
#endif

#if SAUDOIITEM
			if (gInterface.Data[eWindowDoiItem].OnShow == true)
			{
				gInterface.Data[eWindowDoiItem].Close();
				pCloseWindow(pWindowThis(), Inventory);

			}
#endif

#if CUSTOM_DUNGLUYENITEM
			if (gInterface.Data[eWindowDungLuyenItem].OnShow == true)
			{
				gInterface.Data[eWindowDungLuyenItem].Close();
				pCloseWindow(pWindowThis(), Inventory);

			}
#endif

			if (gInterface.CheckVipWindow())
			{
				gInterface.CloseVipWindow();
			}

			if (gInterface.CheckMenuWindow())
			{
				gInterface.CloseMenuWindow();
			}
		}
	}

	gInterface.DrawLogo(0);
	gInterface.DrawShowIcon();
	////-----------------------------------------------------------------------------------------------------------------------
	//char Text1[1024];
	//char Text2[1024];
	//char Text3[1024];
	//char Text4[1024];
	//sprintf(Text1, "X: %d", gObjUser.m_CursorX);
	//sprintf(Text2, "Y: %d", gObjUser.m_CursorY);
	//
	//gInterface.DrawFormat(eYellow, 615, 10, 200, 1, Text1);
	//gInterface.DrawFormat(eYellow, 615, 20, 200, 1, Text2);
	////gInterface.DrawFormat(eYellow, 300, 10, 200, 1, "X: %d", gObjUser.m_CursorX);
	////gInterface.DrawFormat(eYellow, 300, 20, 200, 1, "Y: %d", gObjUser.m_CursorY);

	//int ToaDoX = gObjUser.CoordenadaX;
	//int ToaDoY = gObjUser.CoordenadaY;
	//if ( gObjUser.CoordenadaX != 0 || gObjUser.CoordenadaY != 0 )
	//{
	//	
	//	

	//	if((GetTickCount() - gInterface.Data[ePLAYER_POINT].EventTick) >= 10000)
	//	{
	//		if ( (ToaDoX - gObjUser.CoordenadaX) > 5 || (ToaDoX - gObjUser.CoordenadaX) < 5  )
	//	{
	//		//ExitProcess(0);
	//		gInterface.DrawFormat(eYellow, 300, 10, 200, 1, "ToaDoX: %d", ToaDoX);
	//		gInterface.DrawFormat(eYellow, 300, 20, 200, 1, "ToaDoY: %d", ToaDoY);
	//	}
	//		gInterface.Data[ePLAYER_POINT].EventTick = GetTickCount();
	//	}
	//	
	//	//if ( (ToaDoY - gObjUser.CoordenadaY) > 5 || (ToaDoY - gObjUser.CoordenadaY) < 5  )
	//	//{
	//	//	ExitProcess(0);
	//	//}

	//	
	//	
	//}

	//-----------------------------------------------------------------------------------------------------------------------


	//gInterface.DrawFormat(eGold, 200, 50, 25, 5, "X: %d ", gInterface.m_PartyNumber);





}


void Interface::DrawShowIcon()
{
	if (this->Data[eMenu_MAIN].OnShow == true)
	{
		return;
	}


	//if (gInterface.CheckWindow(FullMap)||
	//	gInterface.CheckWindow(CashShop) ||
	//	gInterface.CheckWindow(MoveList) ||
	//	gInterface.CheckWindow(SkillTree))
	//{
	//	return;
	//}


	if (gProtect.m_MainInfo.CustomInterfaceType >= 0)
	{
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
			|| gInterface.CheckWindow(ObjWindow::Inventory)
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
			|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)
			|| gInterface.CheckWindow(ObjWindow::GensInfo)
			|| gInterface.CheckWindow(ObjWindow::NPC_Julia)
			|| gInterface.CheckWindow(ObjWindow::NPC_ChaosMix)
			|| gInterface.CheckWindow(ObjWindow::ExpandInventory)
			|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse)
			|| gInterface.CheckWindow(ObjWindow::MuHelper)
			|| pMapNumber == 34
			|| pMapNumber == 30)
		{
			return;
		}


		if (pCheckMouseOver(180, 20, 20, 20))
		{
			if (*(BYTE*)0x8793386)
			{
				RenderBitmap(0x4043, 180, 20, 30, 30, 0, 0, 1.0, 1.0, 1, 1, 0.0);
				PlayBuffer(25, 0, 0);

				if (GetTickCount() >= gInterface.TimeInterface + 150)
				{
					ShellExecute(0, 0, gCustomMessage.GetMessage(85), 0, 0, SW_SHOW);


					gInterface.TimeInterface = GetTickCount();
				}

			}
			else { RenderBitmap(0x4043, 180, 20, 31, 31, 0, 0, 1.0, 1.0, 1, 1, 0.0); }
		}
		else { RenderBitmap(0x4043, 180, 20, 30, 30, 0, 0, 1.0, 1.0, 1, 1, 0.0); }



		if (pCheckMouseOver(200, 20, 20, 20))
		{
			if (*(BYTE*)0x8793386)
			{
				RenderBitmap(0x4044, 200, 20, 30, 30, 0, 0, 1.0, 1.0, 1, 1, 0.0);
				PlayBuffer(25, 0, 0);

				if (GetTickCount() >= gInterface.TimeInterface + 150)
				{
					ShellExecute(0, 0, gCustomMessage.GetMessage(86), 0, 0, SW_SHOW);


					gInterface.TimeInterface = GetTickCount();
				}

			}
			else { RenderBitmap(0x4044, 200, 20, 31, 31, 0, 0, 1.0, 1.0, 1, 1, 0.0); }
		}
		else { RenderBitmap(0x4044, 200, 20, 30, 30, 0, 0, 1.0, 1.0, 1, 1, 0.0); }

	}



	if (gProtect.m_MainInfo.EnableNutDonate == 1)
	{
		static float HieuX = 0.87;
		static float HieuY = 0.87;

		if (pCheckMouseOver(220, 2, 80, 15))
		{
			if (*(BYTE*)0x8793386)
			{
				RenderBitmap(0x4045, 210, 2, 100, 15, 0, 0, HieuX, HieuY, 1, 1, 0.0);
				PlayBuffer(25, 0, 0);

				if (GetTickCount() >= gInterface.TimeInterface + 150)
				{
					//ShellExecute(0, 0, gCustomMessage.GetMessage(86), 0, 0, SW_SHOW);				
					gThongTinDonate.OpenThongTinDonateOK();

					gInterface.TimeInterface = GetTickCount();
				}

			}
			else { RenderBitmap(0x4045, 210, 2, 101, 16, 0, 0, HieuX, HieuY, 1, 1, 0.0); }
		}
		else { RenderBitmap(0x4045, 210, 2, 100, 15, 0, 0, HieuX, HieuY, 1, 1, 0.0); }

		CustomFont.Draw(CustomFont.FontNormal, 230, 5, 0xFFDD00FF, 0x00000050, 0, 0, 3, "Thông Tin Donate"); //Move Daily Reward - 70 lados - 60 arriba
	}

	if (gProtect.m_MainInfo.EnableNutSuKien == 1)
	{
		static float HieuX = 0.87;
		static float HieuY = 0.87;
		if (pCheckMouseOver(310, 2, 85, 15))
		{
			if (*(BYTE*)0x8793386)
			{
				RenderBitmap(0x4045, 300, 2, 100, 15, 0, 0, HieuX, HieuY, 1, 1, 0.0);
				PlayBuffer(25, 0, 0);

				if (GetTickCount() >= gInterface.TimeInterface + 150)
				{
					//ShellExecute(0, 0, gCustomMessage.GetMessage(86), 0, 0, SW_SHOW);
					gCustomEventTime.OpenWindow();

					gInterface.TimeInterface = GetTickCount();
				}

			}
			else { RenderBitmap(0x4045, 300, 2, 101, 16, 0, 0, HieuX, HieuY, 1, 1, 0.0); }
		}
		else { RenderBitmap(0x4045, 300, 2, 100, 15, 0, 0, HieuX, HieuY, 1, 1, 0.0); }

		CustomFont.Draw(CustomFont.FontNormal, 320, 5, 0xFFDD00FF, 0x00000050, 0, 0, 3, "Sự Kiện Hằng Ngày"); //Move Daily Reward - 70 lados - 60 arriba
	}



	if (gProtect.m_MainInfo.EnableNutThongTin == 1)
	{
		static float HieuX = 0.87;
		static float HieuY = 0.87;

		if (pCheckMouseOver(400, 2, 85, 15))
		{
			if (*(BYTE*)0x8793386)
			{
				RenderBitmap(0x4045, 390, 2, 100, 15, 0, 0, HieuX, HieuY, 1, 1, 0.0);
				PlayBuffer(25, 0, 0);

				if (GetTickCount() >= gInterface.TimeInterface + 150)
				{
					//ShellExecute(0, 0, gCustomMessage.GetMessage(86), 0, 0, SW_SHOW);
					//gNewsBoard.ReqOpenMain();

					gInterface.TimeInterface = GetTickCount();
				}

			}
			else { RenderBitmap(0x4045, 390, 2, 101, 16, 0, 0, HieuX, HieuY, 1, 1, 0.0); }
		}
		else { RenderBitmap(0x4045, 390, 2, 100, 15, 0, 0, HieuX, HieuY, 1, 1, 0.0); }

		CustomFont.Draw(CustomFont.FontNormal, 410, 5, 0xFFDD00FF, 0x00000050, 0, 0, 3, "Thông Tin Server"); //Move Daily Reward - 70 lados - 60 arriba
	}
}

bool Interface::gDrawButtonThongTinDonate(float PosX, float PosY)
{
	float StartX = PosX;
	float StartY = PosY;
	bool mreturn = false;



	if (pCheckMouseOver(StartX, StartY, 100, 20))
	{
		gInterface.DrawToolTip(StartX - 20, StartY + 35, "Thông Tin Hỗ Trợ");

		if (GetTickCount() - gInterface.Data[eWindowMessageBox].EventTick > 300) //Nut
		{
			if (GetKeyState(1) & 0x8000)
			{
				gInterface.Data[eWindowMessageBox].EventTick = GetTickCount();
				mreturn = true;
			}
		}
		else {
		}
	}

	RenderBitmap(0x4047, 250, 85, 150, 25, 0, 0, 0.87, 0.87, 1, 1, 0); //Khung Thông Tin
	CustomFont.Draw(CustomFont.FontBold, 260, 95, 0xFFDE26FF, 0x0, 130, 0, 3, "★THÔNG TIN NHẬN DONATE SERVER★");
	CustomFont.Draw(CustomFont.FontNormal, 265, 115, 0xffffffff, 0xff222299, 120, 0, 3, gCustomMessage.GetMessage(170));
	CustomFont.Draw(CustomFont.FontNormal, 265, 125, 0xffffffff, 0xff222299, 120, 0, 3, gCustomMessage.GetMessage(171));
	CustomFont.Draw(CustomFont.FontNormal, 265, 135, 0xffffffff, 0xff222299, 120, 0, 3, gCustomMessage.GetMessage(172));

	RenderBitmap(0x4046, StartX - 25, StartY - 150, 180, 180, 0, 0, 1, 1, 1, 1, 0);

	//RenderBitmap(0x4046, 260, 150, 150, 100, 0, 0, 0.87, 0.87, 1, 1, 0); //Hình Ảnh Mã QR 
	RenderBitmap(0x4048, 270, 280, 200, 70, 0, 0, 0.87, 0.87, 1, 1, 0); //Hình Ảnh FaceBook



	return mreturn;
}



void Interface::SwitchMiniMap()
{
	if ((GetTickCount() - gInterface.Data[eNULL_MAP].EventTick) < 1000 || this->CheckWindow(ChatWindow))
	{
		return;
	}

	gInterface.Data[eNULL_MAP].EventTick = GetTickCount();

	if (MiniMap != 0)
	{
		gInterface.DrawMessage(1, "MiniMap Window [OFF]");
		MiniMap = 0;
		WritePrivateProfileStringA("Graphics", "MiniMap", "0", "./Settings.ini");
	}
	else
	{
		gInterface.DrawMessage(1, "MiniMap Window [ON]");
		MiniMap = 1;
		WritePrivateProfileStringA("Graphics", "MiniMap", "1", "./Settings.ini");
	}

}


float Interface::ImagesNumber(BYTE Color, float x, float y, int iNum, float fScale)
{
	EnableAlphaTest(1);
	if (fScale < 0.3f)
	{
		return x;
	}

	char strText[32];
	itoa(iNum, strText, 10);
	int iLength = (int)strlen(strText);

	if (Color == 1) // 
	{
		float width = 11.f * (fScale - 0.3f);
		float height = 17.3f * (fScale - 0.3f);
		x -= width * iLength / 2;
		for (int i = 0; i<iLength; ++i)
		{
			float fU = (float)(strText[i] - 48) * 12.f / 128.f;
			RenderBitmap(31337, x, y, width, height, fU, 0.f, 12.f / 128.f, 14.f / 16.f, 1, 1, 0.0);
			x += width * 0.8f;
		}
	}
	if (Color == 2) //
	{
		float width = 11.f * (fScale - 0.3f);
		float height = 17.3f * (fScale - 0.3f);
		x -= width * iLength / 2;
		for (int i = 0; i<iLength; ++i)
		{
			float fU = (float)(strText[i] - 48) * 12.f / 128.f;
			RenderBitmap(31337, x, y, width, height, fU, 0.f, 12.f / 128.f, 14.f / 16.f, 1, 1, 0.0);
			x += width * 0.8f;
		}
		RenderBitmap(41004, x, y, width + 3, height, 0.f, 0.f, 9.f / 16.f, 14.f / 16.f, 1, 1, 0.0);
	}
	return x;
}


int Thongbao = 100;
int a = 10;
void Interface::DrawTimeUI()
{
	//	if(gProtect.m_MainInfo.CustomInterfaceType >= 0 && gProtect.m_MainInfo.CustomInterfaceType <= 2)
	//	{
	//		return;
	//	}


	//if (TimerBar == 0 
	//	|| (this->CheckWindow(ObjWindow::CashShop) || this->CheckWindow(ObjWindow::FullMap) 
	//	|| this->CheckWindow(ObjWindow::ChatWindow) || this->CheckWindow(ObjWindow::SkillTree)
	//	|| this->CheckWindow(ObjWindow::MoveList) || pMapNumber == 34 || pMapNumber == 30))
	//{
	//	return;
	//}

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
		|| gInterface.CheckWindow(ObjWindow::Inventory)
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
		|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)
		|| gInterface.CheckWindow(ObjWindow::GensInfo)
		|| gInterface.CheckWindow(ObjWindow::NPC_Julia)
		|| gInterface.CheckWindow(ObjWindow::NPC_ChaosMix)
		|| gInterface.CheckWindow(ObjWindow::ExpandInventory)
		|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse)
		|| gInterface.CheckWindow(ObjWindow::MuHelper)
		|| pMapNumber == 34
		|| pMapNumber == 30)

	{
		return;
	}





	//--
	//	this->DrawGUI(eTIME, this->Data[eTIME].X, this->Data[eTIME].Y + 10);
	if (gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4)
	{
		this->DrawGUI(eTIME, this->Data[eTIME].X, this->Data[eTIME].Y + 10); //27
	}

	if (gProtect.m_MainInfo.CustomInterfaceType == 0 || gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		this->DrawGUI(eTIME, this->Data[eTIME].X, this->Data[eTIME].Y + 10);
	}
	// -----
	time_t TimeServer, TimeLocal;
	struct tm * ServerT, *LocalT;
	time(&TimeServer);
	time(&TimeLocal);
	// ----
	ServerT = gmtime(&TimeServer);
	// ----
	char ServerTimeName[25] = "Giờ Server:";
	char ServerTime[30];

	sprintf(ServerTime, "%2d:%02d:%02d", (ServerT->tm_hour + GMT) % 24, ServerT->tm_min, ServerT->tm_sec);

	// -----
	LocalT = localtime(&TimeLocal);
	// -----
	char LocalTimeName[25] = "Giờ Máy Tính:";
	char LocalTime[30];
	sprintf(LocalTime, "%2d:%02d:%02d", LocalT->tm_hour, LocalT->tm_min, LocalT->tm_sec);
	// -----
	if (gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4)
	{

		this->DrawFormat(eShinyGreen, 5, 390, 50, 1, ServerTimeName);
		this->DrawFormat(eGold, 55, 390, 100, 1, ServerTime);
		// ----
		this->DrawFormat(eShinyGreen, 5, 413, 50, 1, LocalTimeName);
		this->DrawFormat(eGold, 55, 413, 100, 1, LocalTime);


		//this->DrawFormat(eShinyGreen, 5, 414, 50, 1, ServerTimeName);
		//this->DrawFormat(eGold, 55, 414, 100, 1, ServerTime);
		// ----
		//this->DrawFormat(eShinyGreen, 5, 422, 50, 1, LocalTimeName);
		//this->DrawFormat(eGold, 55, 422, 100, 1, LocalTime);

		//this->DrawFormat(eGold, 5, 399, 50, 1, ServerTimeName);
		//this->DrawFormat(eWhite, 55, 399, 100, 1, ServerTime);
		//this->DrawFormat(eGold, 5, 423, 50, 1, LocalTimeName);
		//this->DrawFormat(eWhite, 55, 423, 100, 1, LocalTime);
	}

	if (gProtect.m_MainInfo.CustomInterfaceType == 0 || gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		this->DrawFormat(eShinyGreen, 5, 390, 50, 1, ServerTimeName);
		this->DrawFormat(eGold, 55, 390, 100, 1, ServerTime);
		// ----
		this->DrawFormat(eShinyGreen, 5, 413, 50, 1, LocalTimeName);
		this->DrawFormat(eGold, 55, 413, 100, 1, LocalTime);



		//this->DrawFormat(eOrange, 110, 380, 300, 1, gCustomMessage.GetMessage(97));
		//this->DrawFormat(eExcellent, 110, 390, 300, 1, gCustomMessage.GetMessage(98));
		//this->DrawFormat(eBlue250, 110, 401, 300, 1, gCustomMessage.GetMessage(99));
		//this->DrawFormat(eYellow, 110, 415, 300, 1, gCustomMessage.GetMessage(100));




	}
}

int Interface::DrawFormat(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen = sizeof(Buff)-1;
	ZeroMemory(Buff, BuffLen);

	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);

	int LineCount = 0;

	char * Line = strtok(Buff, "\n");

	while (Line != NULL)
	{
		pDrawColorText(Line, PosX, PosY, Width, 0, Color, 0, Align);
		PosY += 10;
		Line = strtok(NULL, "\n");
	}

	return PosY;
}

bool Interface::CheckWindow(int WindowID)
{
	return pCheckWindow(pWindowThis(), WindowID);
}
int Interface::CloseWindow(int WindowID)
{
	return pCloseWindow(pWindowThis(), WindowID);
}
int Interface::OpenWindow(int WindowID)
{
	return pOpenWindow(pWindowThis(), WindowID);
}

bool Interface::IsWorkZone4(float x, float y, float x2, float y2)
{
	bool result = GetForegroundWindow() == pGameWindow && pCursorX >= x && pCursorX <= x + x2 && pCursorY >= y && pCursorY <= y + y2;
	return result;
}

bool Interface::IsWorkZone69(float x, float y, float x2, float y2)
{
	return pCursorX >= x && pCursorX <= x + x2 && pCursorY >= y && pCursorY <= y + y2; //GetForegroundWindow() == pGameWindow &&
}

bool Interface::IsWorkZone2(float X, float Y, float MaxX, float MaxY)
{
	if ((gObjUser.m_CursorX < X || gObjUser.m_CursorX > MaxX)
		|| (gObjUser.m_CursorY < Y || gObjUser.m_CursorY > MaxY))
	{
		return false;
	}
	// ----
	return true;
}
bool Interface::IsWorkZone(float X, float Y, float MaxX, float MaxY, bool a5)
{
	if (a5)
	{
		if ((pCursorX < X || pCursorX > X + MaxX) || (pCursorY < Y || pCursorY > Y + MaxY))
			return false;
		return true;
	}
	if ((pCursorX < X || pCursorX > MaxX) || (pCursorY < Y || pCursorY > MaxY))
		return false;
	return true;
}

bool Interface::IsWorkZone(short ObjectID)
{
	if ((pCursorX < this->Data[ObjectID].X || pCursorX > this->Data[ObjectID].MaxX) || (pCursorY < this->Data[ObjectID].Y || pCursorY > this->Data[ObjectID].MaxY))
		return false;

	return true;
}
float Interface::GetResizeX(short ObjectID)
{
	if (pWinWidth == 800)
	{
		return this->Data[ObjectID].X + 16.0;
	}
	else if (pWinWidth != 1024)
	{
		return this->Data[ObjectID].X - 16.0;
	}

	return this->Data[ObjectID].X;
}

int Interface::DrawToolTip(int X, int Y, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen = sizeof(Buff);
	ZeroMemory(Buff, BuffLen);

	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);

	return pDrawToolTip(X, Y, Buff);
}

int Interface::DrawMessage(int Mode, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen = sizeof(Buff);
	ZeroMemory(Buff, BuffLen);
	// ----
	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	// ----
	return pDrawMessage(Buff, Mode);
}

#if (FIX_SAVESCREEN)
void SaveScreen_fix()
{
	*reinterpret_cast<bool*>(0x87933FB) = true; // GrabFirst = true;

	auto Buffer = new unsigned char[pWinWidth * pWinHeight * 4];

	glReadPixels(0, 0, pWinWidth, pWinHeight, GL_RGBA, GL_UNSIGNED_BYTE, &Buffer[0]);

	auto BufferNew = new unsigned char[pWinWidth * pWinHeight * 3];

	int counter = 0;
	for (int i = 0; i < pWinWidth * pWinHeight * 4; i += 4)
	{
		BufferNew[counter + 0] = Buffer[i + 0];
		BufferNew[counter + 1] = Buffer[i + 1];
		BufferNew[counter + 2] = Buffer[i + 2];

		counter += 3;
	}

	WriteJpeg(reinterpret_cast<char*>(0x8793278), pWinWidth, pWinHeight, BufferNew, 100);

	SAFE_DELETE_ARRAY(Buffer)
		SAFE_DELETE_ARRAY(BufferNew)

		* reinterpret_cast<int*>(0x8793404) = *reinterpret_cast<int*>(0x8793404) + 1; // GrabScreen++;
	*reinterpret_cast<int*>(0x8793404) = *reinterpret_cast<int*>(0x8793404) % 10000; // GrabScreen %= 10000;
}
#endif


//CẤM BẢNG NÀO VÌ || NÓ VÀO ĐÂY LÀ DC! NHƯNG TRƯỚC TIÊN ÔNG PHẢI SỬA - cấm di chuyễn cái bảng nào thì thêm tên bảng đó vào đây
void Interface::SetCursorFocus()
{
	if (gInterface.CheckWindow(Shop))

	{
		if (!pSetCursorFocus)
			pSetCursorFocus = true;
	}

}

void Interface::DrawVipWindow()
{

	if (!this->Data[eVip_MAIN].OnShow)
	{
		return;
	}

	if (gProtect.m_MainInfo.EnableVipShop != 1)
	{
		this->CloseVipWindow();
		return;
	}

	if (this->CheckWindow(ObjWindow::MoveList) || this->CheckWindow(ObjWindow::CashShop) || this->CheckWindow(ObjWindow::SkillTree) || this->CheckWindow(ObjWindow::FullMap)
		|| (this->CheckWindow(Inventory)
		&& this->CheckWindow(ExpandInventory)
		&& this->CheckWindow(Store))
		|| (this->CheckWindow(Inventory)
		&& this->CheckWindow(Warehouse)
		&& this->CheckWindow(ExpandWarehouse)))
	{
		CloseVipWindow();
		return;
	}

	// ----
	float MainWidth = 230.0;
	float MainHeight = 320.0;
	float StartBody = ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
	float StartY = ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (float)(29.0 / 2);
	// ----


	//gCentral.PrintDropBox(StartX, StartY, MainWidth, MainHeight, 0, 0);

	gCBUtil.gDrawWindowCustom(&StartX, &StartY, MainWidth, MainHeight, eVip_MAIN, "VÍP TÀI KHOẢN");

	//pDrawGUFULL(0x9333, StartX - 10, StartY - 10, 250, 300, 0, 0, 1, 1, 1, 1, 0.0); // MENU


	// ----
	this->DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 10, 210, 3, gCustomMessage.GetMessage(5));
	int LineY = this->DrawFormat(eWhite, (int)StartX + 30, (int)StartBody + 35, 210, 1, gCustomMessage.GetMessage(6), gObjUser.lpPlayer->Name);
	LineY = this->DrawFormat(eGold, (int)StartX + 30, (int)LineY, 210, 1, gCustomMessage.GetMessage(14));
	LineY = this->DrawFormat(eWhite, (int)StartX + 30, (int)LineY, 210, 1, gCustomMessage.GetMessage(7));
	LineY = this->DrawFormat(eWhite, (int)StartX + 30, (int)LineY, 210, 1, gCustomMessage.GetMessage(8));
	//--
	pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2), StartBody + 85, 200, 1); //-- Divisor
	//--
	this->DrawFormat(eGold, (int)StartX + 30, (int)StartBody + 95 - 2, 210, 1, "Loại");
	this->DrawFormat(eGold, (int)StartX + 80, (int)StartBody + 95 - 2, 210, 1, "Exp");
	this->DrawFormat(eGold, (int)StartX + 130, (int)StartBody + 95 - 2, 210, 1, "Drop");
	this->DrawFormat(eGold, (int)StartX + 170, (int)StartBody + 95 - 2, 210, 1, "Thời Gian");
	// ----

	if (gProtect.m_MainInfo.VipTypes < 1 || gProtect.m_MainInfo.VipTypes > 3)
	{
		gProtect.m_MainInfo.VipTypes = 3;
	}

	for (int i = 0; i < (int)gProtect.m_MainInfo.VipTypes; i++)
	{
		this->DrawFormat(eWhite, (int)StartX + 30, (int)StartBody + 110 + (12 * i) - 5, 210, 1, gCustomBuyVip.m_CustomBuyVipInfo[i].VipName);
		// ----
		this->DrawFormat(eWhite, (int)StartX + 80, (int)StartBody + 110 + (12 * i) - 5, 210, 1, "+%d%%", gCustomBuyVip.m_CustomBuyVipInfo[i].Exp);
		// ----
		this->DrawFormat(eWhite, (int)StartX + 130, (int)StartBody + 110 + (12 * i) - 5, 210, 1, "+%d%%", gCustomBuyVip.m_CustomBuyVipInfo[i].Drop);
		// ----
		this->DrawFormat(eWhite, (int)StartX + 170, (int)StartBody + 110 + (12 * i) - 5, 210, 1, "%d day(s)", gCustomBuyVip.m_CustomBuyVipInfo[i].Days);

		pDrawGUI(0x7B5E, StartX + 30, StartBody + 110 + (12 * i) + 9 - 5, 82.0, 2.0);
		pDrawGUI(0x7B5E, StartX + 30 + 82, StartBody + 110 + (12 * i) + 9 - 5, 82.0, 2.0);
	}

	if (gProtect.m_MainInfo.VipTypes > 0)
	{
		// ---- bronze start 
		if (IsWorkZone(eVip_BRONZE))
		{
			if (this->Data[eVip_BRONZE].OnClick)
				this->DrawButton(eVip_BRONZE, StartX + 64, 220, 0, 58);
			else
				this->DrawButton(eVip_BRONZE, StartX + 64, 220, 0, 29);
			// ----
			this->DrawFormat(eGold, (int)StartX + 30, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(10));
			this->DrawFormat(eGold, (int)StartX + 70, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(11), gCustomBuyVip.m_CustomBuyVipInfo[0].Coin1);
			this->DrawFormat(eGold, (int)StartX + 120, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(12), gCustomBuyVip.m_CustomBuyVipInfo[0].Coin2);
			this->DrawFormat(eGold, (int)StartX + 160, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(13), gCustomBuyVip.m_CustomBuyVipInfo[0].Coin3);
		}
		else
			this->DrawButton(eVip_BRONZE, StartX + 64, 220, 0, 0);
		// ----
		this->DrawFormat(eWhite, (int)StartX + 90, 220 + 9, 160, 1, gCustomMessage.GetMessage(9), gCustomBuyVip.m_CustomBuyVipInfo[0].VipName);
		// ---- bronze end ------------------------------------
	}

	if (gProtect.m_MainInfo.VipTypes > 1)
	{
		// ---- Silver start ------------------------------------
		if (IsWorkZone(eVip_SILVER))
		{
			if (this->Data[eVip_SILVER].OnClick)
				this->DrawButton(eVip_SILVER, StartX + 64, 250, 0, 58);
			else
				this->DrawButton(eVip_SILVER, StartX + 64, 250, 0, 29);
			// ----
			this->DrawFormat(eGold, (int)StartX + 30, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(10));
			this->DrawFormat(eGold, (int)StartX + 70, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(11), gCustomBuyVip.m_CustomBuyVipInfo[1].Coin1);
			this->DrawFormat(eGold, (int)StartX + 120, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(12), gCustomBuyVip.m_CustomBuyVipInfo[1].Coin2);
			this->DrawFormat(eGold, (int)StartX + 160, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(13), gCustomBuyVip.m_CustomBuyVipInfo[1].Coin3);
		}
		else
			this->DrawButton(eVip_SILVER, StartX + 64, 250, 0, 0);

		this->DrawFormat(eWhite, (int)StartX + 90, 250 + 9, 160, 1, gCustomMessage.GetMessage(9), gCustomBuyVip.m_CustomBuyVipInfo[1].VipName);
		// ---- silver end ------------------------------------
	}

	if (gProtect.m_MainInfo.VipTypes > 2)
	{
		// ---- gold start ------------------------------------
		if (IsWorkZone(eVip_GOLD))
		{
			if (this->Data[eVip_GOLD].OnClick)
				this->DrawButton(eVip_GOLD, StartX + 64, 280, 0, 58);
			else
				this->DrawButton(eVip_GOLD, StartX + 64, 280, 0, 29);
			// ----
			this->DrawFormat(eGold, (int)StartX + 30, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(10));
			this->DrawFormat(eGold, (int)StartX + 70, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(11), gCustomBuyVip.m_CustomBuyVipInfo[2].Coin1);
			this->DrawFormat(eGold, (int)StartX + 120, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(12), gCustomBuyVip.m_CustomBuyVipInfo[2].Coin2);
			this->DrawFormat(eGold, (int)StartX + 160, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(13), gCustomBuyVip.m_CustomBuyVipInfo[2].Coin3);
		}
		else
			this->DrawButton(eVip_GOLD, StartX + 64, 280, 0, 0);

		this->DrawFormat(eWhite, (int)StartX + 90, 280 + 9, 160, 1, gCustomMessage.GetMessage(9), gCustomBuyVip.m_CustomBuyVipInfo[2].VipName);
		// ---- gold end ------------------------------------
	}

	pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2), 280 + 55, 200, 1); //-- Divisor
}



bool Interface::EventVipWindow_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eVip_CLOSE].EventTick);
	// ----
	if (!this->Data[eVip_MAIN].OnShow || !IsWorkZone(eVip_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eVip_CLOSE].OnClick = true;
		return true;
	}
	// ----
	this->Data[eVip_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eVip_CLOSE].EventTick = GetTickCount();
	this->CloseVipWindow();
	// ----
	return false;
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventVipWindow_Bronze(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eVip_BRONZE].EventTick);
	// ----
	if (!this->Data[eVip_MAIN].OnShow || !IsWorkZone(eVip_BRONZE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eVip_BRONZE].OnClick = true;
		return true;
	}
	// ----
	this->Data[eVip_BRONZE].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eVip_BRONZE].EventTick = GetTickCount();
	gCustomBuyVip.BuyStatus(1);
	this->CloseVipWindow();
	// ----
	return false;
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventVipWindow_Silver(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eVip_SILVER].EventTick);
	// ----
	if (!this->Data[eVip_MAIN].OnShow || !IsWorkZone(eVip_SILVER))
	{
		return false;
	}
	if (gProtect.m_MainInfo.VipTypes < 2)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eVip_SILVER].OnClick = true;
		return true;
	}
	// ----
	this->Data[eVip_SILVER].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eVip_SILVER].EventTick = GetTickCount();
	gCustomBuyVip.BuyStatus(2);
	this->CloseVipWindow();
	// ----
	return false;
}

// ----------------------------------------------------------------------------------------------
bool Interface::EventVipWindow_Gold(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eVip_GOLD].EventTick);
	// ----
	if (!this->Data[eVip_MAIN].OnShow || !IsWorkZone(eVip_GOLD))
	{
		return false;
	}
	if (gProtect.m_MainInfo.VipTypes < 3)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eVip_GOLD].OnClick = true;
		return true;
	}
	// ----
	this->Data[eVip_GOLD].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eVip_GOLD].EventTick = GetTickCount();
	gCustomBuyVip.BuyStatus(3);
	this->CloseVipWindow();
	// ----
	return false;
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventVipWindow_Main(DWORD Event)
{
	this->EventVipWindow_Close(Event);
	this->EventVipWindow_Bronze(Event);
	this->EventVipWindow_Silver(Event);
	this->EventVipWindow_Gold(Event);
	// ----
	return true;
}

float Interface::DrawRepeatGUI(short MonsterID, float X, float Y, int Count)
{
	float StartY = Y;
	// ----
	for (int i = 0; i < Count; i++)
	{
		pDrawGUI(this->Data[MonsterID].ModelID, X, StartY,
			this->Data[MonsterID].Width, this->Data[MonsterID].Height);
		// ----
		StartY += this->Data[MonsterID].Height;
	}
	// ----
	return StartY;
}

float Interface::DrawRepeatGUIScale(short MonsterID, float X, float Y, float ScaleX, float ScaleY, int Count)
{
	float StartY = Y;
	// ----
	for (int i = 0; i < Count; i++)
	{
		this->DrawIMG(this->Data[MonsterID].ModelID, X, StartY, ScaleX, ScaleY);
		// ----
		StartY += this->Data[MonsterID].Height;
	}
	// ----
	return StartY;
}

void Interface::DrawButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	if (this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1)
	{
		this->Data[ObjectID].X = PosX;
		this->Data[ObjectID].Y = PosY;
		this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	}
	// ----
	pDrawButton(this->Data[ObjectID].ModelID, PosX, PosY,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, ScaleX, ScaleY);
}

void Interface::DrawButtonRender(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	this->Data[ObjectID].X = PosX;
	this->Data[ObjectID].Y = PosY;
	this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	// ----
	pDrawButton(this->Data[ObjectID].ModelID, PosX, PosY,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, ScaleX, ScaleY);
}

void Interface::DrawColoredGUI(short ObjectID, float X, float Y, DWORD Color)
{
	if (this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1)
	{
		this->Data[ObjectID].X = X;
		this->Data[ObjectID].Y = Y;
		this->Data[ObjectID].MaxX = X + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY = Y + this->Data[ObjectID].Height;
	}
	// ----
	pDrawColorButton(this->Data[ObjectID].ModelID, X, Y,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, 0, 0, Color);
}

void Interface::DrawLogo(bool active)
{
	if (gProtect.m_MainInfo.PrintLogo != 0)
	{

		if (active == 1)
		{
			this->Data[eLogo].EventTick = GetTickCount() + 1500;
		}

		if (gInterface.Data[eLogo].EventTick > GetTickCount())
		{
			if (gProtect.m_MainInfo.PrintLogo == 1)
			{
				this->DrawGUI(eLogo, 10, 10);
			}

			if (gProtect.m_MainInfo.PrintLogo == 2)
			{
				this->DrawGUI(eLogo, MAX_WIN_WIDTH - 160, 10);

			}

			if (gProtect.m_MainInfo.PrintLogo == 3)
			{
				this->DrawGUI(eLogo, 10, MAX_WIN_HEIGHT - 144);
			}

			if (gProtect.m_MainInfo.PrintLogo == 4)
			{
				this->DrawGUI(eLogo, MAX_WIN_WIDTH - 160, MAX_WIN_HEIGHT - 144);
			}

			if (gProtect.m_MainInfo.PrintLogo == 5)
			{
				this->DrawGUI(eLogo, (MAX_WIN_WIDTH / 2) - (150 / 2), (MAX_WIN_HEIGHT / 2) - (114 / 2));
			}
		}
	}
}

void Interface::DrawMenu()
{
	if (gProtect.m_MainInfo.CustomMenuSwitch != 1)
	{
		return;
	}

	if (this->Data[eMenu].OnShow)
	{
		this->Data[eMenu].OnShow = false;
	}

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
		|| gInterface.CheckWindow(ObjWindow::Inventory)
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
		CloseMenuWindow();
		return;
	}

	this->Data[eMenu].OnShow = true;
}

bool Interface::EventDrawMenu_Open(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu].EventTick);
	// ----
	if (!this->Data[eMenu].OnShow || !IsWorkZone(eMenu))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{

		if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
		{
			pSetCursorFocus = false;
		}
		this->Data[eMenu].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}

	// ----
	this->Data[eMenu].EventTick = GetTickCount();

	if (CheckMenuWindow())
	{
		CloseMenuWindow();
	}
	else
	{
		CloseCustomWindow();
		OpenMenuWindow();
	}
	// ----
	return false;
}

void Interface::DrawMenuOpen()
{
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
		|| gInterface.CheckWindow(ObjWindow::Inventory)
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
		return;
	}
	//--
	if (gProtect.m_MainInfo.CustomMenuSwitch != 1 || !this->Data[eMenu_MAIN].OnShow || pCheckWindow(pWindowThis(), 35))
	{
		return;
	}

	float MainWidth = 250.0;
	float MainHeight = 340.0;
	float StartY = ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (float)(29.0 / 2);
	//--
	//---------------------------------------------------------------------------------------//
	if (gInterface.IsWorkZone(eMenu_MAIN)) // nếu chuột trong khu vực bảng shop thì ko click di chuyển nv
	{
		pSetCursorFocus = true;
	}
	else pSetCursorFocus = false;
	//---------------------------------------------------------------------------------------//
	pDrawMessage("", 0); // Không Cho Hiện Thông Báo Trên Màn Hình
	//---------------------------------------------------------------------------------------//



	this->Data[eMenu_MAIN].MaxX = StartX + MainWidth;
	this->Data[eMenu_MAIN].MaxY = StartY + MainHeight;

	gCBUtil.gDrawWindowCustom(&StartX, &StartY, MainWidth, MainHeight, eMenu_MAIN, "Menu - F8");

	//gCentral.PrintDropBox(StartX, StartY, MainWidth, MainHeight, 0, 0);

	//this->DrawFormat(eGold, (int)StartX + 10, (int)StartY + 10, 210, 3, "Menu - F5");

	//CustomFont.DrawMultipleColor(CustomFont.FontSize18, (int)StartX + 100, (int)StartY + 10, 0x0, 0, 0, 0, "Menu - F8");

	if (gProtect.m_MainInfo.EnableCoinStatus == 1)
	{
		this->DrawFormat(eGold, (int)StartX + 10, (int)StartY + 35, 210, 3, gCustomMessage.GetMessage(50));

		this->DrawFormat(eWhite, (int)StartX + 25, (int)StartY + 55, 40, 1, gCustomMessage.GetMessage(51));
		this->DrawFormat(eGold, (int)StartX + 50, (int)StartY + 55, 40, 1, "%d", Coin1);

		this->DrawFormat(eWhite, (int)StartX + 90, (int)StartY + 55, 40, 1, gCustomMessage.GetMessage(52));
		this->DrawFormat(eGold, (int)StartX + 115, (int)StartY + 55, 40, 1, "%d", Coin2);

		this->DrawFormat(eWhite, (int)StartX + 153, (int)StartY + 55, 40, 1, gCustomMessage.GetMessage(53));
		this->DrawFormat(eGold, (int)StartX + 176, (int)StartY + 55, 40, 1, "%d", Coin3);
	}
	else
	{
		this->DrawFormat(eGold, (int)StartX + 10, (int)StartY + 45, 210, 3, gCustomMessage.GetMessage(54));
	}

	pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2), StartY + 75, 200, 1); //-- Divisor

	float CurrentMove;
	int BtCount = -1;
	int BtStart = StartY + 88;
	int BtDistance = 28;

	int ObjectIDs[17] =
	{
		eMenu_OPT1,
		eMenu_OPT2,
		eMenu_OPT3,
		eMenu_OPT4,
		eMenu_OPT5,
		eMenu_OPT6,
		eMenu_OPT7,
		eMenu_OPT8,
		eMenu_OPT9,
		eMenu_OPT10,
		eMenu_OPT11,
		eMenu_OPT12,
		eMenu_OPT13,
		eMenu_OPT14,
		eMenu_OPT15,
		eMenu_OPT16,
		eMenu_OPT17,

	};

	for (int n = 0; n < 17; n++)
	{
		if (gProtect.m_MainInfo.MenuButtons[n] == 1)
		{
			BtCount++;
		}
		else
		{
			continue;
		}

		CurrentMove = 0.0;
		if (IsWorkZone(ObjectIDs[n]))
		{
			if (this->Data[ObjectIDs[n]].OnClick)
			{
				if (gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4)
				{
					PlayBuffer(25, 0, 0);
					CurrentMove = 30.5f;
				}
				else
				{
					CurrentMove = 29;
				}
			}
		}

		/*float MainWidth = 280.0;
		float MainHeight = 370.0;
		float StartY = ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
		float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
		float MainCenter = StartX + (MainWidth / 3);
		float ButtonX = MainCenter - (float)(29.0 / 2);*/

		int SoButton = 17;
		if (gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4)
		{
			if (BtCount % 2 == 0)
			{
				this->DrawButton(ObjectIDs[n], StartX + 10, BtStart + (30.0f * (BtCount / 2)), 0, CurrentMove);
				//this->DrawFormat(eWhite, StartX  + 10, BtStart + (30.0f * (BtCount/2)) + 9, 108, 3,gCustomMessage.GetMessage(( n == 8) ? 44 : 25 + n));
				this->DrawFormat(eWhite, StartX + 10, BtStart + (30.0f * (BtCount / 2)) + 9, 108, 3, gConfig.TextVN[((n == SoButton) ? 40 : 1 + n)]);
			}
			else
			{
				this->DrawButton(ObjectIDs[n], StartX + (MainWidth)-(108) - 10, BtStart + (30.0f * (BtCount / 2)), 0, CurrentMove);
				this->DrawFormat(eWhite, StartX + (MainWidth)-(108) - 10, BtStart + (30.0f * (BtCount / 2)) + 9, 108, 3, gConfig.TextVN[((n == SoButton) ? 40 : 1 + n)]);
			}

		}
		else
		{
			if (BtCount % 2 == 0)
			{
				this->DrawButton(ObjectIDs[n], StartX + 10, BtStart + (29 * (BtCount / 2)), 0, CurrentMove);
				//this->DrawFormat(eWhite, StartX  + 10, BtStart + (30.0f * (BtCount/2)) + 9, 108, 3,gCustomMessage.GetMessage(( n == 8) ? 44 : 25 + n));
				this->DrawFormat(eWhite, StartX + 10, BtStart + (29 * (BtCount / 2)) + 9, 108, 3, gConfig.TextVN[((n == SoButton) ? 40 : 1 + n)]);
			}
			else
			{
				this->DrawButton(ObjectIDs[n], StartX + (MainWidth)-(108) - 10, BtStart + (29 * (BtCount / 2)), 0, CurrentMove);
				this->DrawFormat(eWhite, StartX + (MainWidth)-(108) - 10, BtStart + (29 * (BtCount / 2)) + 9, 108, 3, gConfig.TextVN[((n == SoButton) ? 40 : 1 + n)]);
			}
		}


		//this->DrawButton(ObjectIDs[n], StartX + (MainWidth / 5) - (108 / 5), BtStart + (33.0f * BtCount), 0, CurrentMove);
		//this->DrawFormat(eWhite, StartX + (MainWidth / 5) - (108 / 5), BtStart + (33.0f * BtCount) + 9, 108, 3,gCustomMessage.GetMessage(( n == 8) ? 44 : 25 + n));


	}


	pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2), StartY + MainHeight - 40, 200, 1); //-- Divisor


	//--
	BtStart += BtDistance;

	if (IsWorkZone(eMenu_CLOSE))
	{
		if (this->Data[eMenu_CLOSE].OnClick)
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
	gInterface.DrawFormat(eWhite, StartX + (MainWidth / 2) - (59 / 2), StartY + MainHeight - 25, 59, 3, "Đóng");
}

bool Interface::EventDrawMenu_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_CLOSE].EventTick);
	// ----
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_CLOSE].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_CLOSE].EventTick = GetTickCount();
	this->CloseMenuWindow();
	// ----
	return false;
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventDrawMenu_Op1(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT1].EventTick);
	// ----
	if (gInterface.CheckWindow(Character)
		|| gInterface.CheckWindow(Warehouse)
		|| gInterface.CheckWindow(ChaosBox)
		|| gInterface.CheckWindow(Store)
		|| gInterface.CheckWindow(OtherStore)
		|| gInterface.CheckWindow(ExpandInventory)
		|| gInterface.CheckWindow(Shop)
		|| gInterface.CheckWindow(Trade)
		|| gInterface.CheckWindow(LuckyCoin1)
		|| gInterface.CheckWindow(NPC_ChaosMix))
	{
		return false;
	}
	//--
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT1))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT1].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT1].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT1].EventTick = GetTickCount();

	this->CloseMenuWindow();

	gCustomEventTime.OpenWindow();
	// ----
	return false;

}

bool Interface::EventDrawMenu_Op2(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT2].EventTick);
	// ----
	if (gInterface.CheckWindow(Character)
		|| gInterface.CheckWindow(Warehouse)
		|| gInterface.CheckWindow(ChaosBox)
		|| gInterface.CheckWindow(Store)
		|| gInterface.CheckWindow(OtherStore)
		|| gInterface.CheckWindow(ExpandInventory)
		|| gInterface.CheckWindow(Shop)
		|| gInterface.CheckWindow(Trade)
		|| gInterface.CheckWindow(LuckyCoin1)
		|| gInterface.CheckWindow(NPC_ChaosMix))
	{
		return false;
	}
	//--
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT2))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT2].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT2].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT2].EventTick = GetTickCount();

	this->CloseCustomWindow();

	this->OpenVipWindow();
	// ----
	return false;
}

bool Interface::EventDrawMenu_Op3(DWORD Event)
{

	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT3].EventTick);
	// ----
	if (gInterface.CheckWindow(Character)
		|| gInterface.CheckWindow(Warehouse)
		|| gInterface.CheckWindow(ChaosBox)
		|| gInterface.CheckWindow(Store)
		|| gInterface.CheckWindow(OtherStore)
		|| gInterface.CheckWindow(ExpandInventory)
		|| gInterface.CheckWindow(Shop)
		|| gInterface.CheckWindow(Trade)
		|| gInterface.CheckWindow(LuckyCoin1)
		|| gInterface.CheckWindow(NPC_ChaosMix))
	{
		return false;
	}
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT3))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT3].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT3].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT3].EventTick = GetTickCount();

	this->CloseMenuWindow();

	gCustomRanking.getTatMo();


	// ----
	return false;

}

bool Interface::EventDrawMenu_Op4(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT4].EventTick);
	// ----
	if (gInterface.CheckWindow(Character)
		|| gInterface.CheckWindow(Warehouse)
		|| gInterface.CheckWindow(ChaosBox)
		|| gInterface.CheckWindow(Store)
		|| gInterface.CheckWindow(OtherStore)
		|| gInterface.CheckWindow(ExpandInventory)
		|| gInterface.CheckWindow(Shop)
		|| gInterface.CheckWindow(Trade)
		|| gInterface.CheckWindow(LuckyCoin1)
		|| gInterface.CheckWindow(NPC_ChaosMix))
	{
		return false;
	}
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT4))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT4].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT4].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT4].EventTick = GetTickCount();

	this->CloseMenuWindow();

	gCustomCommandInfo.OpenCommandWindow();
	// ----
	return false;
}

bool Interface::EventDrawMenu_Op5(DWORD Event)
{

	//if(gProtect.m_MainInfo.MenuButtons[n] == 1)

	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT5].EventTick);
	// ----
	if (gInterface.CheckWindow(Character)
		|| gInterface.CheckWindow(Warehouse)
		|| gInterface.CheckWindow(ChaosBox)
		|| gInterface.CheckWindow(Store)
		|| gInterface.CheckWindow(OtherStore)
		|| gInterface.CheckWindow(ExpandInventory)
		|| gInterface.CheckWindow(Shop)
		|| gInterface.CheckWindow(Trade)
		|| gInterface.CheckWindow(LuckyCoin1)
		|| gInterface.CheckWindow(NPC_ChaosMix))
	{
		return false;
	}
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT5))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT5].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT5].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT5].EventTick = GetTickCount();

	this->CloseMenuWindow();

	gInterface.OnOffWindowBank();

	// ----

	return false;

}


bool Interface::EventDrawMenu_Op6(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT6].EventTick);
	// ----
	if (gInterface.CheckWindow(Character)
		|| gInterface.CheckWindow(Warehouse)
		|| gInterface.CheckWindow(ChaosBox)
		|| gInterface.CheckWindow(Store)
		|| gInterface.CheckWindow(OtherStore)
		|| gInterface.CheckWindow(ExpandInventory)
		|| gInterface.CheckWindow(Shop)
		|| gInterface.CheckWindow(Trade)
		|| gInterface.CheckWindow(LuckyCoin1)
		|| gInterface.CheckWindow(NPC_ChaosMix))
	{
		return false;
	}
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT6))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT6].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT6].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT6].EventTick = GetTickCount();

	this->CloseMenuWindow();

	gInterface.SwitchOffExpWindoState();

	// ----
	return false;
}

bool Interface::EventDrawMenu_Op7(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT7].EventTick);
	// ----
	if (gInterface.CheckWindow(Character)
		|| gInterface.CheckWindow(Warehouse)
		|| gInterface.CheckWindow(ChaosBox)
		|| gInterface.CheckWindow(Store)
		|| gInterface.CheckWindow(OtherStore)
		|| gInterface.CheckWindow(ExpandInventory)
		|| gInterface.CheckWindow(Shop)
		|| gInterface.CheckWindow(Trade)
		|| gInterface.CheckWindow(LuckyCoin1)
		|| gInterface.CheckWindow(NPC_ChaosMix))
	{
		return false;
	}
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT7))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT7].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT7].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT7].EventTick = GetTickCount();

	this->CloseMenuWindow();

	if (GetForegroundWindow() == pGameWindow)
	{
		gPartySearch.SwitchPartySettingsWindowState();
	}
	// ----
	return false;
}
bool Interface::EventDrawMenu_Op8(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT8].EventTick);
	// ----
	if (gInterface.CheckWindow(Character)
		|| gInterface.CheckWindow(Warehouse)
		|| gInterface.CheckWindow(ChaosBox)
		|| gInterface.CheckWindow(Store)
		|| gInterface.CheckWindow(OtherStore)
		|| gInterface.CheckWindow(ExpandInventory)
		|| gInterface.CheckWindow(Shop)
		|| gInterface.CheckWindow(Trade)
		|| gInterface.CheckWindow(LuckyCoin1)
		|| gInterface.CheckWindow(NPC_ChaosMix))
	{
		return false;
	}
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT8))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT8].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT8].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT8].EventTick = GetTickCount();

	this->CloseMenuWindow();



	//gPartySearch.SwitchPartySearchWindowState();
	if (GetForegroundWindow() == pGameWindow)
	{
		UP_PARTYSEARCH_REQ pMsg;
		pMsg.h.set(0xF3, 0x25, sizeof(pMsg));
		DataSend((BYTE*)&pMsg, pMsg.h.size);
		pSetCursorFocus = false;
	}

	return false;
}

bool Interface::EventDrawMenu_Op9(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT9].EventTick);
	// ----
	if (gInterface.CheckWindow(Character)
		|| gInterface.CheckWindow(Warehouse)
		|| gInterface.CheckWindow(ChaosBox)
		|| gInterface.CheckWindow(Store)
		|| gInterface.CheckWindow(OtherStore)
		|| gInterface.CheckWindow(ExpandInventory)
		|| gInterface.CheckWindow(Shop)
		|| gInterface.CheckWindow(Trade)
		|| gInterface.CheckWindow(LuckyCoin1)
		|| gInterface.CheckWindow(NPC_ChaosMix))
	{
		return false;
	}
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT9))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT9].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT9].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT9].EventTick = GetTickCount();

	this->CloseMenuWindow();

	if (GetForegroundWindow() == pGameWindow)

#if(VONGQUAY_NEW)
		gInterface.OpenWindowVongQuay();
#endif

	// ----
	return false;
}

bool Interface::EventDrawMenu_Op10(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT10].EventTick);
	// ----
	if (gInterface.CheckWindow(Character)
		|| gInterface.CheckWindow(Warehouse)
		|| gInterface.CheckWindow(ChaosBox)
		|| gInterface.CheckWindow(Store)
		|| gInterface.CheckWindow(OtherStore)
		|| gInterface.CheckWindow(ExpandInventory)
		|| gInterface.CheckWindow(Shop)
		|| gInterface.CheckWindow(Trade)
		|| gInterface.CheckWindow(LuckyCoin1)
		|| gInterface.CheckWindow(NPC_ChaosMix))
	{
		return false;
	}
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT10))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT10].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT10].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT10].EventTick = GetTickCount();

	this->CloseMenuWindow();

	if (GetForegroundWindow() == pGameWindow)
	{
		G_BEXO_DANH_HIEU.OPEN_WINDOW_DANH_HIEU();
	}
	// ----
	return false;
}



bool Interface::EventDrawMenu_Op11(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT11].EventTick);
	// ----
	if (gInterface.CheckWindow(Character)
		|| gInterface.CheckWindow(Warehouse)
		|| gInterface.CheckWindow(ChaosBox)
		|| gInterface.CheckWindow(Store)
		|| gInterface.CheckWindow(OtherStore)
		|| gInterface.CheckWindow(ExpandInventory)
		|| gInterface.CheckWindow(Shop)
		|| gInterface.CheckWindow(Trade)
		|| gInterface.CheckWindow(LuckyCoin1)
		|| gInterface.CheckWindow(NPC_ChaosMix))
	{
		return false;
	}
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT11))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT11].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT11].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT11].EventTick = GetTickCount();

	this->CloseMenuWindow();

	if (GetForegroundWindow() == pGameWindow)
	{
		G_BEXO_QUAN_HAM.OPEN_WINDOW_QUAN_HAM();

	}
	// ----
	return false;
}

bool Interface::EventDrawMenu_Op12(DWORD Event)
{
	EventDrawMenu_Op13(Event);

	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT12].EventTick);
	// ----
	if (gInterface.CheckWindow(Character)
		|| gInterface.CheckWindow(Warehouse)
		|| gInterface.CheckWindow(ChaosBox)
		|| gInterface.CheckWindow(Store)
		|| gInterface.CheckWindow(OtherStore)
		|| gInterface.CheckWindow(ExpandInventory)
		|| gInterface.CheckWindow(Shop)
		|| gInterface.CheckWindow(Trade)
		|| gInterface.CheckWindow(LuckyCoin1)
		|| gInterface.CheckWindow(NPC_ChaosMix))
	{
		return false;
	}
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT12))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT12].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT12].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT12].EventTick = GetTickCount();

	this->CloseMenuWindow();

	G_BEXO_TU_LUYEN.OPEN_WINDOW_TU_LUYEN();


	// ----
	return false;
}

bool Interface::EventDrawMenu_Op13(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT13].EventTick);
	// ----
	if (gInterface.CheckWindow(Character)
		|| gInterface.CheckWindow(Warehouse)
		|| gInterface.CheckWindow(ChaosBox)
		|| gInterface.CheckWindow(Store)
		|| gInterface.CheckWindow(OtherStore)
		|| gInterface.CheckWindow(ExpandInventory)
		|| gInterface.CheckWindow(Shop)
		|| gInterface.CheckWindow(Trade)
		|| gInterface.CheckWindow(LuckyCoin1)
		|| gInterface.CheckWindow(NPC_ChaosMix))
	{
		return false;
	}
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT13))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT13].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT13].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT13].EventTick = GetTickCount();

	this->CloseMenuWindow();

	gInterface.Data[eWindow_SkinModel].OnShow ^= 1;

	// ----
	return false;
}

bool Interface::EventDrawMenu_Op14(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT14].EventTick);
	// ----
	if (gInterface.CheckWindow(Character)
		|| gInterface.CheckWindow(Warehouse)
		|| gInterface.CheckWindow(ChaosBox)
		|| gInterface.CheckWindow(Store)
		|| gInterface.CheckWindow(OtherStore)
		|| gInterface.CheckWindow(ExpandInventory)
		|| gInterface.CheckWindow(Shop)
		|| gInterface.CheckWindow(Trade)
		|| gInterface.CheckWindow(LuckyCoin1)
		|| gInterface.CheckWindow(NPC_ChaosMix))
	{
		return false;
	}
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT14))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT14].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT14].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT14].EventTick = GetTickCount();

	this->CloseMenuWindow();

	if (GetForegroundWindow() == pGameWindow)
	{
		//==Open Window hon Hoan
		XULY_CGPACKET pMsg;
		pMsg.header.set(0xD3, 0x01, sizeof(pMsg));
		pMsg.ThaoTac = 1;
		DataSend((LPBYTE)& pMsg, pMsg.header.size);
	}
	// ----
	return false;
}

bool Interface::EventDrawMenu_Op15(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT15].EventTick);
	// ----
	if (gInterface.CheckWindow(Character)
		|| gInterface.CheckWindow(Warehouse)
		|| gInterface.CheckWindow(ChaosBox)
		|| gInterface.CheckWindow(Store)
		|| gInterface.CheckWindow(OtherStore)
		|| gInterface.CheckWindow(ExpandInventory)
		|| gInterface.CheckWindow(Shop)
		|| gInterface.CheckWindow(Trade)
		|| gInterface.CheckWindow(LuckyCoin1)
		|| gInterface.CheckWindow(NPC_ChaosMix))
	{
		return false;
	}
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT15))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT15].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT15].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT15].EventTick = GetTickCount();

	this->CloseMenuWindow();

	ThueFlag.Drawing = !ThueFlag.Drawing;

	if (!ThueFlag.Drawing)
	{
		ThueFlag.SendRequest(0x2, 0);

	}
	else
	{
		ThueFlag.SendRequest(0x0, ThueFlag.Selected);
	}
	// ----
	return false;
}
bool Interface::EventDrawMenu_Op16(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT16].EventTick);
	// ----
	if (gInterface.CheckWindow(Character)
		|| gInterface.CheckWindow(Warehouse)
		|| gInterface.CheckWindow(ChaosBox)
		|| gInterface.CheckWindow(Store)
		|| gInterface.CheckWindow(OtherStore)
		|| gInterface.CheckWindow(ExpandInventory)
		|| gInterface.CheckWindow(Shop)
		|| gInterface.CheckWindow(Trade)
		|| gInterface.CheckWindow(LuckyCoin1)
		|| gInterface.CheckWindow(NPC_ChaosMix))
	{
		return false;
	}
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT16))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT16].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT16].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT16].EventTick = GetTickCount();

	this->CloseMenuWindow();

	gResetChange.OpenResetChange();
	// ----
	return false;
}

bool Interface::EventDrawMenu_Op17(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT17].EventTick);
	// ----
	if (gInterface.CheckWindow(Character)
		|| gInterface.CheckWindow(Warehouse)
		|| gInterface.CheckWindow(ChaosBox)
		|| gInterface.CheckWindow(Store)
		|| gInterface.CheckWindow(OtherStore)
		|| gInterface.CheckWindow(ExpandInventory)
		|| gInterface.CheckWindow(Shop)
		|| gInterface.CheckWindow(Trade)
		|| gInterface.CheckWindow(LuckyCoin1)
		|| gInterface.CheckWindow(NPC_ChaosMix))
	{
		return false;
	}
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT17))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT17].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT17].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT17].EventTick = GetTickCount();

	this->CloseMenuWindow();

	gInterface.OpenWindowMocNap();
	// ----
	return false;
}

bool Interface::MiniMapCheck()
{
	bool visual = false;

	if (gInterface.CheckWindow(13) && gInterface.CheckWindow(Character)
		|| gInterface.CheckWindow(8)
		|| gInterface.CheckWindow(12)
		|| gInterface.CheckWindow(9)
		|| gInterface.CheckWindow(7)
		|| gInterface.CheckWindow(14)
		|| gInterface.CheckWindow(15)
		|| gInterface.CheckWindow(60)
		|| gInterface.CheckWindow(76))
	{
		visual = true;
	}
	else
	{
		if (gInterface.CheckWindow(16) && (gInterface.CheckWindow(4) || gInterface.CheckWindow(69)))
		{
			visual = true;
		}
		else
		{
			if (gInterface.CheckWindow(16) && gInterface.CheckWindow(11))
			{
				visual = true;
			}
			else
			{
				if (gInterface.CheckWindow(27))
				{
					visual = true;
				}
				else
				{
					if (gInterface.CheckWindow(13)
						|| gInterface.CheckWindow(16)
						|| gInterface.CheckWindow(3)
						|| gInterface.CheckWindow(21)
						|| gInterface.CheckWindow(6)
						|| gInterface.CheckWindow(22)
						|| gInterface.CheckWindow(23)
						|| gInterface.CheckWindow(24)
						|| gInterface.CheckWindow(4)
						|| gInterface.CheckWindow(18)
						|| gInterface.CheckWindow(10)
						|| gInterface.CheckWindow(5)
						|| gInterface.CheckWindow(25)
						|| gInterface.CheckWindow(26)
						|| gInterface.CheckWindow(19)
						|| gInterface.CheckWindow(20)
						|| gInterface.CheckWindow(58)
						|| gInterface.CheckWindow(59)
						|| gInterface.CheckWindow(62)
						|| gInterface.CheckWindow(73)
						|| gInterface.CheckWindow(68)
						|| gInterface.CheckWindow(69)
						|| gInterface.CheckWindow(70)
						|| gInterface.CheckWindow(66)
						|| gInterface.CheckWindow(75)
						|| gInterface.CheckWindow(74))
					{
						visual = true;
					}
					else
					{
						if (gInterface.CheckWindow(79))
						{
							if (gInterface.CheckWindow(80))
							{
								visual = true;
							}
							else
							{
								visual = true;
							}
						}
					}
				}
			}
		}
	}

	if (gInterface.CheckWindow(77))
	{
		if (gInterface.CheckWindow(Warehouse) ||
			gInterface.CheckWindow(ChaosBox) ||
			gInterface.CheckWindow(Store) ||
			gInterface.CheckWindow(OtherStore) ||
			gInterface.CheckWindow(Character))
		{
			visual = true;
		}
		else
		{
			visual = true;
		}
	}
	else if (gInterface.CheckWindow(78))
	{
		visual = true;
	}
	return visual;
}

bool Interface::CombinedChecks()
{
	if ((this->CheckWindow(Inventory)
		&& this->CheckWindow(ExpandInventory)
		&& this->CheckWindow(Store)) ||
		(this->CheckWindow(Inventory)
		&& this->CheckWindow(Warehouse)
		&& this->CheckWindow(ExpandWarehouse)) ||
		(this->CheckWindow(Inventory)
		&& this->CheckWindow(Character)
		&& this->CheckWindow(Store)))
		return true;
	return false;
}

//bool Interface::CheckMap()
//{
//	switch(gObjUser.m_MapNumber)
//	{
//		case eMapNumber::Lorencia:
//			return false;
//			break;
//		case eMapNumber::Dungeon:
//			return false;
//			break;
//		case eMapNumber::Devias:
//			return false;
//			break;
//		case eMapNumber::Noria:
//			return false;
//			break;
//		case eMapNumber::LostTower:
//			return false;
//			break;
//		case eMapNumber::Stadium:
//			return false;
//		case eMapNumber::Atlans:
//			return false;
//			break;
//		case eMapNumber::Tarkan:
//			return false;
//			break;
//		case eMapNumber::Elbeland:
//			return false;
//			break;
//		case eMapNumber::Icarus:
//			return false;
//			break;
//		case eMapNumber::Trials:
//			return false;
//			break;
//		case eMapNumber::Aida:
//			return false;
//			break;
//		case eMapNumber::Crywolf:
//			return false;
//			break;
//		case eMapNumber::Kanturu1:
//			return false;
//			break;
//		case eMapNumber::Kanturu3:
//			return false;
//			break;
//		case eMapNumber::Barracks:
//			return false;
//			break;
//		case eMapNumber::Calmness:
//			return false;
//			break;
//		case eMapNumber::Raklion:
//			return false;
//			break;
//		case eMapNumber::Vulcanus:
//			return false;
//			break;
//		case eMapNumber::Karutan1:
//			return false;
//			break;
//		case eMapNumber::Karutan2:
//			return false;
//			break;
//		default:
//			return true;
//			break;
//	}
//}

void Interface::CloseCustomWindow() // đóng tất cả các bảng khác đang mở
{
	this->CloseMenuWindow();
	this->CloseVipWindow();
	this->Data[eRankPANEL_MAIN].OnShow = false;
	this->Data[eEventTimePANEL_MAIN].OnShow = false;
	this->Data[eCommand_MAIN].OnShow = false;

	if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
}

void Interface::DrawItem(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse)
{

	if (this->CheckWindow(ObjWindow::MoveList) || this->CheckWindow(ObjWindow::CashShop) || this->CheckWindow(ObjWindow::SkillTree) || this->CheckWindow(ObjWindow::FullMap)
		|| (this->CheckWindow(Inventory)
		&& this->CheckWindow(ExpandInventory)
		&& this->CheckWindow(Store))
		|| (this->CheckWindow(Inventory)
		&& this->CheckWindow(Warehouse)
		&& this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	pSetBlend(true);
	glMatrixMode(0x1701);
	glPushMatrix();
	glLoadIdentity();

	sub_6363D0_Addr(0, 0, *(GLsizei*)MAIN_RESOLUTION_X, *(GLsizei*)MAIN_RESOLUTION_Y);

	float v2 = *(float*)MAIN_RESOLUTION_X / *(float*)MAIN_RESOLUTION_Y;

	if (ItemID == 406)
	{
		sub_6358A0_Addr(0.4, v2, *(float*)0xE61E38, *(float*)0xE61E3C); //tamanho do bmd
	}
	else if (ItemID == 407)
	{
		sub_6358A0_Addr(0.5, v2, *(float*)0xE61E38, *(float*)0xE61E3C); //tamanho do bmd
	}
	else
	{
		sub_6358A0_Addr(0.7, v2, *(float*)0xE61E38, *(float*)0xE61E3C); //tamanho do bmd
	}

	glMatrixMode(0x1700);
	glPushMatrix();
	glLoadIdentity();

	sub_635830_Addr((LPVOID)0x87933A0);
	sub_635DE0_Addr();
	sub_635E40_Addr();

	glClear(0x100);

	VAngle v45;

	unsigned __int8 v44 = 1; //0 = parado / 1 = girando

	sub_6359B0_Addr(PosX, PosY, (int)&v45, 0); //vi tri bmd
	sub_5CA0D0_Addr(ItemID, Level, Excl, Anc, (int)&v45, v44, 0); //chức năng hiển thị BMD

	sub_636720_Addr();

	glMatrixMode(0x1700);
	glPopMatrix();
	glMatrixMode(0x1701);
	glPopMatrix();

	sub_637770_Addr();

	glColor3f(1, 1, 1);
	pSetBlend(false);
}

void Interface::DrawConfirmOpen()
{
	if (!this->CheckWindow(Shop) && this->Data[eCONFIRM_MAIN].OnShow == true)
	{
		this->Data[eCONFIRM_MAIN].OnShow = false;
	}

	if ((GetTickCount() - this->Data[eCONFIRM_BTN_OK].EventTick) < 100)
	{
		this->Data[eCONFIRM_MAIN].OnShow = false;
	}

	if ((GetTickCount() - this->Data[eCONFIRM_BTN_CANCEL].EventTick) < 100)
	{
		this->Data[eCONFIRM_MAIN].OnShow = false;
	}

	if (!this->Data[eCONFIRM_MAIN].OnShow)
	{
		return;
	}

	float StartX;
	if (gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		StartX = 205.0f;
	}
	else
	{
		StartX = 25.0f;
	}

	float MainWidth = 230.0;
	float MainHeight = 130.0;
	float StartBody = 90.0;
	float StartY = 90.0;

	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (float)(29.0 / 2);

	//gCentral.PrintDropBox(StartX, StartY, MainWidth, MainHeight, 0, 0);

	gCentral.gDrawWindowCustom(StartX, StartY, MainWidth, MainHeight, eCONFIRM_MAIN, "");


	this->DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 10, 210, 3, gCustomMessage.GetMessage(66));

	this->DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 40, 210, 3, gCustomMessage.GetMessage(67));

	this->DrawButton(eCONFIRM_BTN_OK, (int)StartX + 40, (int)StartBody + 70, 0, 0);

	if (this->IsWorkZone(eCONFIRM_BTN_OK))
	{
		int ScaleY = 30;
		// ----
		if (this->Data[eCONFIRM_BTN_OK].OnClick)
		{
			ScaleY = 60;
		}
		// ----
		this->DrawButton(eCONFIRM_BTN_OK, (int)StartX + 40, (int)StartBody + 70, 0, ScaleY);
	}

	this->DrawButton(eCONFIRM_BTN_CANCEL, (int)StartX + 140, (int)StartBody + 70, 0, 0);

	if (this->IsWorkZone(eCONFIRM_BTN_CANCEL))
	{
		int ScaleY = 30;
		// ----
		if (this->Data[eCONFIRM_BTN_CANCEL].OnClick)
		{
			ScaleY = 60;
		}
		// ----
		this->DrawButton(eCONFIRM_BTN_CANCEL, (int)StartX + 140, (int)StartBody + 70, 0, ScaleY);
	}

}


bool Interface::EventConfirm_OK(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCONFIRM_BTN_OK].EventTick);
	// ----
	if (!this->Data[eCONFIRM_MAIN].OnShow || !IsWorkZone(eCONFIRM_BTN_OK))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCONFIRM_BTN_OK].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCONFIRM_BTN_OK].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCONFIRM_BTN_OK].EventTick = GetTickCount();

	PMSG_ITEM_BUY_RECV pMsg;

	pMsg.header.set(0xF3, 0xED, sizeof(pMsg));

	pMsg.slot = this->ConfirmSlot;

	DataSend((BYTE*)&pMsg, pMsg.header.size);

	this->Data[eCONFIRM_MAIN].OnShow = false;

	if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
	// ----
	return false;
}

bool Interface::EventConfirm_CANCEL(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCONFIRM_BTN_CANCEL].EventTick);
	// ----
	if (!this->Data[eCONFIRM_MAIN].OnShow || !IsWorkZone(eCONFIRM_BTN_CANCEL))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCONFIRM_BTN_CANCEL].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCONFIRM_BTN_CANCEL].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCONFIRM_BTN_CANCEL].EventTick = GetTickCount();

	this->Data[eCONFIRM_MAIN].OnShow = false;

	if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
	// ----
	return false;
}

//-- advance
void Interface::DrawBarForm(float PosX, float PosY, float Width, float Height, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
	pSetBlend(true);
	glColor4f((GLfloat)0.0, (GLfloat)0.0, (GLfloat)0.0, (float)0.8);
	pDrawBarForm(PosX, PosY, Width, Height, 0.0f, 0);
	pGLSwitchBlend();
	pGLSwitch();
	glColor3f(1.0, 1.0, 1.0);
	pSetBlend(false);
}
// ----------------------------------------------------------------------------------------------
bool Interface::CheckWindowEx(int WindowID)
{
	if (WindowID < 0 || WindowID > MAX_WINDOW_EX)
	{
		return 0;
	}
	return this->WindowEx[WindowID];
}

//---- cosas peladas

void Interface::UPDATE_FPS(){
	gInterface.frameCount++;
	if (GetTickCount() - gInterface.lastReport >= 1000)
	{
		gInterface.frameRate = gInterface.frameCount / ((GetTickCount() - gInterface.lastReport) / 1000);
		sprintf(gInterface.FPS_REAL, "FPS: %d", gInterface.frameRate);
		gInterface.lastReport = GetTickCount();
		gInterface.frameCount = 0;
	}

	if (this->MiniMapCheck() || this->CombinedChecks() || this->CheckWindow(FullMap) || this->CheckWindow(FriendList) || this->CheckWindow(SkillTree) || this->CheckWindow(CashShop))
	{
		return;
	}

	this->DrawFormat(eGold, 600, 5, 80, 1, gInterface.FPS_REAL);
}

void Interface::guiMonitore(){
	if (this->MiniMapCheck() || this->CombinedChecks() || this->CheckWindow(FullMap) || this->CheckWindow(FriendList) || this->CheckWindow(SkillTree) || this->CheckWindow(CashShop))
	{
		return;
	}
	pSetBlend(true);
	glColor4f((GLfloat)0.0, (GLfloat)0.0, (GLfloat)0.0, (float)0.8);
	pDrawBarForm(460.0, 0.0, 180.0, 20.0, 0.0f, 0);
	pGLSwitchBlend();
	pGLSwitch();
	glColor3f(1.0, 1.0, 1.0);
	pSetBlend(false);
}

void Interface::DrawPing()
{
	gInterface.msPing = GetTickCount() - gInterface.lastSend;
	gInterface.iniciador = 3;
}

struct PMSG_PING
{
	PBMSG_HEAD h;
};

void Interface::SendPingRecv()
{
	if (gInterface.iniciador == 1)
	{
		PMSG_PING pMsgPing;
		pMsgPing.h.set(0xFF, sizeof(pMsgPing));
		gInterface.lastSend = GetTickCount();
		DataSend((BYTE*)&pMsgPing, sizeof(pMsgPing));
		gInterface.iniciador = 2;
	}
	else if (gInterface.iniciador == 3)
	{
		if (GetTickCount() >= gInterface.lastSend + 1000){
			PMSG_PING pMsgPing;
			pMsgPing.h.set(0xFF, sizeof(pMsgPing));
			gInterface.lastSend = GetTickCount();
			DataSend((BYTE*)&pMsgPing, sizeof(pMsgPing));
			gInterface.iniciador = 2;
		}
	}

	if (this->MiniMapCheck() || this->CombinedChecks() || this->CheckWindow(FullMap) || this->CheckWindow(FriendList) || this->CheckWindow(SkillTree) || this->CheckWindow(CashShop))
	{
		return;
	}
	sprintf(gInterface.ServerRTT, "RTT: %d ms", gInterface.msPing);
	sprintf(gInterface.ServerPing, "PING: %d ms", (gInterface.msPing / 2));
	// ----
	gInterface.validar = 0;

	if (gInterface.msPing > 0){
		//----
		this->DrawFormat(eGold, 470, 5, 120, 1, gInterface.ServerRTT);
		this->DrawFormat(eGold, 530, 5, 120, 1, gInterface.ServerPing);
		//--
		sprintf(gInterface.ultimoRTT, gInterface.ServerRTT);
		sprintf(gInterface.ultimoPing, gInterface.ServerPing);
		//--
		gInterface.ultimo_RTT = gInterface.msPing;
		gInterface.validar = 1;
	}

	if (gInterface.validar == 0)
	{
		if (gInterface.ultimo_RTT > 0)
		{
			this->DrawFormat(eGold, 470, 5, 80, 1, gInterface.ultimoRTT);
			this->DrawFormat(eGold, 530, 5, 120, 1, gInterface.ultimoPing);
		}
		else
		{
			this->DrawFormat(eGold, 470, 5, 120, 1, gInterface.ServerRTT);
			this->DrawFormat(eGold, 530, 5, 120, 1, gInterface.ServerPing);
		}
	}
}

void Interface::SwitchChatExpand()
{

	if ((GetTickCount() - gInterface.Data[chatbackground].EventTick) < 1000 || this->CheckWindow(ChatWindow))
	{
		return;
	}

	gInterface.Data[chatbackground].EventTick = GetTickCount();

	if (SeparateChat != 0)
	{
		gInterface.DrawMessage(1, "Chat Window Separate [OFF]");
		SeparateChat = 0;
		WritePrivateProfileStringA("Setting", "SeparateChat", "0", "./Settings.ini");
	}
	else
	{
		gInterface.DrawMessage(1, "Chat Window Separate [ON]");
		SeparateChat = 1;
		WritePrivateProfileStringA("Setting", "SeparateChat", "1", "./Settings.ini");
	}
	gChatExpanded.Switch();
}

void Interface::SwitchHideDanhHieu()
{
	if ((GetTickCount() - gInterface.Data[ePLAYER_POINT].EventTick) < 1000 || this->CheckWindow(ChatWindow))
	{
		return;
	}

	gInterface.Data[ePLAYER_POINT].EventTick = GetTickCount();

	if (MinimizarOfRank == 0)
	{
		MinimizarOfRank = 1;
		pDrawMessage("Ẩn Danh Hiệu: [Tắt]", 1);
	}
	else
	{
		MinimizarOfRank = 0;
		pDrawMessage("Ẩn Danh Hiệu: [Bật]", 1);
	}
}

void Interface::OpenConfig(int type)
{
	if (type == 0)
	{
		if ((GetTickCount() - gInterface.Data[ePLAYER_POINT].EventTick) < 400
			|| this->CheckWindow(ChatWindow)
			|| this->CheckWindow(MuHelper)
			|| this->CheckWindow(Inventory)
			|| this->CheckWindow(Store)
			|| this->CheckWindow(Character)
			|| this->CheckWindow(CreateGuild))
		{
			return;
		}

		gInterface.Data[ePLAYER_POINT].EventTick = GetTickCount();

		if (pCheckWindow(pWindowThis(), 35))
		{
			pCloseWindow(pWindowThis(), 35);
		}
		else
		{
			pOpenWindow(pWindowThis(), 35);
		}
	}
	else if (type = 1)
	{
		if ((GetTickCount() - gInterface.Data[ePLAYER_POINT].EventTick) < 400 || OpenSwicthSkill == 0)
		{
			return;
		}

		gInterface.Data[ePLAYER_POINT].EventTick = GetTickCount();

		if (SkillPage == 1)
		{
			SkillPage = 2;
		}
		else
		{
			SkillPage = 1;
		}
	}

	PlayBuffer(25, 0, 0);
}
//-- SwitchCamera
void Interface::SwitchCamera()
{

	if (gProtect.m_MainInfo.DisableHelper == 0)
	{
		if ((GetTickCount() - gInterface.Data[eCamera3DSwitch].EventTick) < 1000)
		{
			return;
		}

		if (pMapNumber == 62)
		{
			gInterface.DrawMessage(1, CameraNotAc);
			gCamera.Restore();
		}

		gInterface.Data[eCamera3DSwitch].EventTick = GetTickCount();

		gCamera.Toggle();

		if (gCamera.getEnabled())
		{
			gInterface.DrawMessage(1, CameraOn);
		}
		else
		{
			gInterface.DrawMessage(1, CameraOff);
		}
	}
}

//gym chuot
//-- CameraInit
void Interface::CameraInit(){

	if ((GetTickCount() - gInterface.Data[eCamera3DInit].EventTick) < 1000)
	{
		return;
	}

	gInterface.Data[eCamera3DInit].EventTick = GetTickCount();

	if (gCamera.getEnabled())
	{
		gInterface.DrawMessage(1, CameraDefault);
		gCamera.Restore();
	}
}

bool Interface::Button(DWORD Event, int WinID, int ButtonID, bool Type)
{
	if (!this->IsWorkZone(ButtonID))
	{
		return false;
	}

	if (Type == true)
	{
		if (!this->Data[ButtonID].Attribute)
		{
			return false;
		}
	}

	// ----
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[ButtonID].EventTick);
	// ----

	if (Event == WM_LBUTTONDOWN  && this->Data[ButtonID].OnClick == false)
	{
		this->Data[ButtonID].OnClick = true;
	}

	if (Event == WM_LBUTTONUP && this->Data[ButtonID].OnClick == true)
	{
		this->Data[ButtonID].OnClick = false;
		return true;
	}
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[ButtonID].OnClick = false;
	// ----
	this->Data[ButtonID].EventTick = GetTickCount();
	// ----
	return false;
}

void Interface::DrawInterfaceS2Menu()
{
	if (IsWorkZone(eParty))
	{
		this->DrawToolTip(345, 420, "Party");
	}
	if (this->CheckWindow(Party))
	{
		gInterface.DrawButton(eParty, 348, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eCharacter))
	{
		this->DrawToolTip(375, 420, "Character");
	}
	if (this->CheckWindow(Character))
	{
		gInterface.DrawButton(eCharacter, 378.5f, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eInventory))
	{
		this->DrawToolTip(405, 420, "Inventory");
	}
	if (this->CheckWindow(Inventory))
	{
		gInterface.DrawButton(eInventory, 409, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eShop))
	{
		this->DrawToolTip(430, 420, "CashShop");
	}
	if (this->CheckWindow(CashShop))
	{
		gInterface.DrawButton(eShop, 439.5f, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eFriend))
	{
		this->DrawToolTip(580, 420, "Friends");
	}
	if (this->CheckWindow(FriendList))
	{
		gInterface.DrawButton(eFriend, 581, 433, 0.0, 0.0);
	}
	if (IsWorkZone(eGuild))
	{
		this->DrawToolTip(580, 444, "Guild");
	}
	if (this->CheckWindow(Guild))
	{
		gInterface.DrawButton(eGuild, 581, 457, 0.0, 0.0);
	}
	if (IsWorkZone(eFastMenu))
	{
		this->DrawToolTip(13, 420, "System");
	}
	if (this->CheckWindow(FastMenu))
	{
		gInterface.DrawButton(eFastMenu, 6, 433, 0.0, 0.0);
	}
}
//--------------------------------------
void Interface::DrawInterface97Menu()
{
	if (IsWorkZone(eParty))
	{
		this->DrawToolTip(345, 420, "Party");
	}
	if (this->CheckWindow(Party))
	{
		gInterface.DrawButton(eParty, 348, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eCharacter))
	{
		this->DrawToolTip(375, 420, "Character");
	}
	if (this->CheckWindow(Character))
	{
		gInterface.DrawButton(eCharacter, 378.5f, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eInventory))
	{
		this->DrawToolTip(405, 420, "Inventory");
	}
	if (this->CheckWindow(Inventory))
	{
		gInterface.DrawButton(eInventory, 409, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eShop))
	{
		this->DrawToolTip(430, 420, "CashShop");
	}
	if (this->CheckWindow(CashShop))
	{
		gInterface.DrawButton(eShop, 439.5f, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eFriend))
	{
		this->DrawToolTip(580, 420, "Friends");
	}
	if (this->CheckWindow(FriendList))
	{
		gInterface.DrawButton(eFriend, 581, 433, 0.0, 0.0);
	}
	if (IsWorkZone(eGuild))
	{
		this->DrawToolTip(580, 444, "Guild");
	}
	if (this->CheckWindow(Guild))
	{
		gInterface.DrawButton(eGuild, 581, 457, 0.0, 0.0);
	}
}
//--------------------------------------
void Interface::EventNewInterface_All(DWORD Event){
	DWORD CurrentTick = GetTickCount();
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
		|| gInterface.CheckWindow(ObjWindow::Inventory)
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
		return;
	}

	if (IsWorkZone(eFastMenu))
	{
		DWORD Delay = (CurrentTick - this->Data[eFastMenu].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eFastMenu].OnClick = true;
			return;
		}
		this->Data[eFastMenu].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eFastMenu].EventTick = GetTickCount();
		if (this->CheckWindow(FastMenu)) {
			this->CloseWindow(FastMenu);
		}
		else {
			this->OpenWindow(FastMenu);
		}
	}
	else if (IsWorkZone(eParty))
	{
		DWORD Delay = (CurrentTick - this->Data[eParty].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eParty].OnClick = true;
			return;
		}
		this->Data[eParty].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eParty].EventTick = GetTickCount();
		if (this->CheckWindow(Party)) {
			this->CloseWindow(Party);
		}
		else {
			this->OpenWindow(Party);
		}
	}

	else if (IsWorkZone(eCharacter))
	{
		DWORD Delay = (CurrentTick - this->Data[eCharacter].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eCharacter].OnClick = true;
			return;
		}
		this->Data[eCharacter].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eCharacter].EventTick = GetTickCount();
		if (this->CheckWindow(Character)) {
			this->CloseWindow(Character);
		}
		else {
			this->OpenWindow(Character);
		}
	}
	else if (IsWorkZone(eInventory))
	{
		DWORD Delay = (CurrentTick - this->Data[eInventory].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eInventory].OnClick = true;
			return;
		}
		this->Data[eInventory].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eInventory].EventTick = GetTickCount();
		if (this->CheckWindow(Inventory)) {
			this->CloseWindow(Inventory);
		}
		else {
			this->OpenWindow(Inventory);
		}
	}
	else if (IsWorkZone(eFriend))
	{
		DWORD Delay = (CurrentTick - this->Data[eFriend].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eFriend].OnClick = true;
			return;
		}
		this->Data[eFriend].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eFriend].EventTick = GetTickCount();
		if (this->CheckWindow(FriendList)) {
			this->CloseWindow(FriendList);
		}
		else {
			this->OpenWindow(FriendList);
		}
	}
	else if (IsWorkZone(eGuild))
	{
		DWORD Delay = (CurrentTick - this->Data[eGuild].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eGuild].OnClick = true;
			return;
		}
		this->Data[eGuild].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eGuild].EventTick = GetTickCount();
		if (this->CheckWindow(Guild)) {
			this->CloseWindow(Guild);
		}
		else {
			this->OpenWindow(Guild);
		}
	}
}
void Interface::EventNewInterface97_All(DWORD Event){
	DWORD CurrentTick = GetTickCount();
	if (this->CheckWindow(ChaosBox))
	{
		return;
	}

	if (IsWorkZone(eParty))
	{
		DWORD Delay = (CurrentTick - this->Data[eParty].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eParty].OnClick = true;
			return;
		}
		this->Data[eParty].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eParty].EventTick = GetTickCount();
		if (this->CheckWindow(Party)) {
			this->CloseWindow(Party);
		}
		else {
			this->OpenWindow(Party);
		}
	}

	else if (IsWorkZone(eCharacter))
	{
		DWORD Delay = (CurrentTick - this->Data[eCharacter].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eCharacter].OnClick = true;
			return;
		}
		this->Data[eCharacter].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eCharacter].EventTick = GetTickCount();
		if (this->CheckWindow(Character)) {
			this->CloseWindow(Character);
		}
		else {
			this->OpenWindow(Character);
		}
	}
	else if (IsWorkZone(eInventory))
	{
		DWORD Delay = (CurrentTick - this->Data[eInventory].EventTick);
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eInventory].OnClick = true;
			return;
		}
		this->Data[eInventory].OnClick = false;
		if (Delay < 500)
		{
			return;
		}
		this->Data[eInventory].EventTick = GetTickCount();
		if (this->CheckWindow(Inventory))
		{
			this->CloseWindow(Inventory);
		}
		else {
			this->OpenWindow(Inventory);
		}
	}
	else if (IsWorkZone(eFriend))
	{
		DWORD Delay = (CurrentTick - this->Data[eFriend].EventTick);
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eFriend].OnClick = true;
			return;
		}
		this->Data[eFriend].OnClick = false;
		if (Delay < 500)
		{
			return;
		}
		this->Data[eFriend].EventTick = GetTickCount();
		if (this->CheckWindow(FriendList))
		{
			this->CloseWindow(FriendList);
		}
		else {
			this->OpenWindow(FriendList);
		}
	}
	else if (IsWorkZone(eGuild))
	{
		DWORD Delay = (CurrentTick - this->Data[eGuild].EventTick);
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eGuild].OnClick = true;
			return;
		}
		this->Data[eGuild].OnClick = false;
		if (Delay < 500)
		{
			return;
		}
		this->Data[eGuild].EventTick = GetTickCount();
		if (this->CheckWindow(Guild))
		{
			this->CloseWindow(Guild);
		}
		else {
			this->OpenWindow(Guild);
		}
	}
}

void Interface::DrawInterfaceDragonLS3()
{
	if (this->CheckWindow(ObjWindow::CashShop)
		|| this->CheckWindow(ObjWindow::FullMap)
		|| this->CheckWindow(ObjWindow::SkillTree)
		|| this->CheckWindow(ObjWindow::MoveList)
		)
	{
		return;
	}
	this->DrawGUI(eDragonLeft, this->Data[eDragonLeft].X, this->Data[eDragonLeft].Y);
}

void Interface::DrawInterfaceDragonRS3()
{
	if (this->MiniMapCheck() || (this->CheckWindow(SkillTree) || this->CheckWindow(CashShop) || this->CheckWindow(FullMap)
		|| this->CheckWindow(FastMenu) || this->CheckWindow(FriendList))
		|| pMapNumber == 39 //Kanturu
		|| pMapNumber == 58 //Selupam
		|| pMapNumber == 64 //Duel Arena
		|| pMapNumber == 65 //Doppelganger
		|| pMapNumber == 66 //Doppelganger
		|| pMapNumber == 67 //Doppelganger
		|| pMapNumber == 68 //Doppelganger
		|| pMapNumber == 69 //Imperial Guardian
		|| pMapNumber == 70 //Imperial Guardian
		|| pMapNumber == 71 //Imperial Guardian
		|| pMapNumber == 72 //Imperial Guardian
		|| pMapNumber == 11	//Blood Castle
		|| pMapNumber == 12	//Blood Castle
		|| pMapNumber == 13	//Blood Castle
		|| pMapNumber == 14	//Blood Castle
		|| pMapNumber == 15	//Blood Castle
		|| pMapNumber == 16	//Blood Castle
		|| pMapNumber == 17	//Blood Castle
		|| pMapNumber == 52	//Blood Castle
		|| pMapNumber == 9	//Devil Square
		|| pMapNumber == 32	//Devil Square
		|| pMapNumber == 18	//Chaos Castle
		|| pMapNumber == 19	//Chaos Castle
		|| pMapNumber == 20	//Chaos Castle
		|| pMapNumber == 21	//Chaos Castle
		|| pMapNumber == 22	//Chaos Castle
		|| pMapNumber == 23	//Chaos Castle
		|| pMapNumber == 53	//Chaos Castle
		|| pMapNumber == 45	//Illusion Temple
		|| pMapNumber == 46	//Illusion Temple
		|| pMapNumber == 47	//Illusion Temple
		|| pMapNumber == 48	//Illusion Temple
		|| pMapNumber == 49	//Illusion Temple
		|| pMapNumber == 50	//Illusion Temple
		|| pMapNumber == 18	//Chaos Castle
		|| pMapNumber == 19	//Chaos Castle
		|| pMapNumber == 20	//Chaos Castle
		|| pMapNumber == 21	//Chaos Castle
		|| pMapNumber == 22	//Chaos Castle
		|| pMapNumber == 23	//Chaos Castle
		|| pMapNumber == 53	//Chaos Castle
		|| pMapNumber == 34 //Crywolf
		|| pMapNumber == 30 //Valley/CastleSiege
		|| pMapNumber == 65 /*DuelArena*/)
	{
		return;
	}
	this->DrawGUI(eDragonRight, this->Data[eDragonRight].X, this->Data[eDragonRight].Y);
}

void Interface::DrawCoord()
{
	gObjUser.Refresh();

	if (*(DWORD*)MAIN_SCREEN_STATE == 5)
	{
		glColor3f(1.0f, 1.0f, 1.0f);
		pDrawInterfaceNumBer(22, 461, gObjUser.lpViewPlayer->MapPosX, 1);
		pDrawInterfaceNumBer(46, 461, gObjUser.lpViewPlayer->MapPosY, 1);

	}
}



int Interface::DrawToolTipEx(DWORD Color, int PosX, int PosY, int Width, int Height, int Align, LPCSTR Text, ...)
{
	char Buff[2048];
	char Buff2[2048];
	int BuffLen = sizeof(Buff);
	ZeroMemory(Buff, BuffLen);
	// ----
	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	// ----

	int LineCount = 0;

	strcpy(Buff2, Buff);

	char* Line = strtok(Buff2, "\n");
	// ----
	while (Line != NULL)
	{
		LineCount++;
		Line = strtok(NULL, "\n");
	}

	pSetBlend(true);
	glColor4f(0.0, 0.0, 0.0, 1.0);
	pDrawBarForm(PosX, PosY, Width, LineCount * 10, 0.0f, 0);
	pGLSwitchBlend();
	pGLSwitch();

	glColor3f(1.0, 1.0, 1.0);
	pSetBlend(false);

	this->DrawText(eWhite, PosX, PosY, Width, Align, Buff);
	return 0;
}
void Interface::DrawText(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...) // OK
{
	char Buff[2048];
	const int BuffLen = sizeof(Buff)-1;
	ZeroMemory(Buff, BuffLen);

	va_list args;
	va_start(args, Text);
	vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);

	char* Line = strtok(Buff, "\n");

	while (Line != nullptr)
	{
		DrawInterfaceText(Line, PosX, PosY, Width, 0, Color, 0, Align);
		PosY += 10;
		Line = strtok(NULL, "\n");
	}
}



bool Interface::ButtonEx(DWORD Event, int ButtonID, bool Type)
{
	if (!this->IsWorkZone(ButtonID))
	{
		return false;
	}

	if (Type == true)
	{
		if (!this->Data[ButtonID].Attribute)
		{
			return false;
		}
	}

	// ----
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[ButtonID].EventTick);
	// ----

	if (Event == WM_LBUTTONDOWN && this->Data[ButtonID].OnClick == false)
	{
		this->Data[ButtonID].OnClick = true;
		//return false;
	}

	if (Event == WM_LBUTTONUP && this->Data[ButtonID].OnClick == true)
	{
		this->Data[ButtonID].OnClick = false;
		return true;
	}
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[ButtonID].OnClick = false;
	// ----
	this->Data[ButtonID].EventTick = GetTickCount();
	// ----
	return false;
}

void testfunc()
{
	glMatrixMode(0x1700u);
	glPopMatrix();
	glMatrixMode(0x1701u);
	glPopMatrix();
}

void Interface::DrawItem2(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse)
{
	glMatrixMode(0x1701);
	glPushMatrix();
	glLoadIdentity();

	sub_6363D0_Addr(0, 0, *(GLsizei*)MAIN_RESOLUTION_X, *(GLsizei*)MAIN_RESOLUTION_Y);

	float v2 = *(float*)MAIN_RESOLUTION_X / *(float*)MAIN_RESOLUTION_Y;
	sub_6358A0_Addr(1.0, v2, *(float*)0xE61E38, *(float*)0xE61E3C);

	glMatrixMode(0x1700);
	glPushMatrix();
	glLoadIdentity();

	sub_635830_Addr((LPVOID)0x87933A0);
	sub_635DE0_Addr();
	sub_635E40_Addr();

	pDrawItemModel(PosX, PosY, Width, Height, ItemID, Level, Excl, Anc, OnMouse);

	glMatrixMode(0x1700u);
	glPopMatrix();
	glMatrixMode(0x1701u);
	glPopMatrix();

	glColor3f(1, 1, 1);
	pSetBlend(false);
}

void Interface::LoadImages2(char * Folder, int Code, int Arg3, int Arg4, int Arg5)
{
	pLoadImage(Folder, Code, Arg3, Arg4, Arg5, 0);
}
void Interface::DrawWindow(int ObjMain, int ObjTitle, int ObjFrame, int ObjFooter, int Repeat, float X, float Y, char* Text)
{
	float StartY = Y;
	float StartX = X;

	gInterface.DrawGUI(ObjMain, StartX, StartY + 2);
	gInterface.DrawGUI(ObjTitle, StartX, StartY);
	StartY = gInterface.DrawRepeatGUI(ObjFrame, StartX, StartY + 67.0, Repeat);
	gInterface.DrawGUI(ObjFooter, StartX, StartY);

	gInterface.DrawFormat(eGold, StartX + 10, Y + 10, 210, 3, Text);
}


bool Interface::IsWorkZone1(float x, float y, float x2, float y2)
{
	return pCursorX >= x && pCursorX <= x + x2 && pCursorY >= y && pCursorY <= y + y2; //GetForegroundWindow() == pGameWindow &&
}

char* Interface::NumberFormat(int Number) {


	if (Number < 0) { return "0"; }

	char OutPut[15];

	if (Number < 1000) {
		sprintf(OutPut, "%d", Number);
		return strdup(OutPut);
	}
	else if (Number < 1000000) {
		int part1 = Number % 1000;
		int part2 = (Number - part1) / 1000;
		sprintf(OutPut, "%d,%03d", part2, part1);
		return strdup(OutPut);
	}
	else if (Number < 1000000000) {
		int part1 = Number % 1000;
		Number = (Number - part1) / 1000;
		int part2 = Number % 1000;
		Number = (Number - part2) / 1000;
		int part3 = Number % 1000;

		sprintf(OutPut, "%d,%03d,%03d", part3, part2, part1);
		return strdup(OutPut);
	}
	else {
		int part1 = Number % 1000;
		Number = (Number - part1) / 1000;
		int part2 = Number % 1000;
		Number = (Number - part2) / 1000;
		int part3 = Number % 1000;
		int part4 = (Number - part3) / 1000;

		sprintf(OutPut, "%d,%03d,%03d,%03d", part4, part3, part2, part1);
		return strdup(OutPut);
	}
	return "0";
}

char* Interface::NumberFormat(DWORD Number) {


	if (Number < 0) { return "0"; }

	char OutPut[15];

	if (Number < 1000) {
		sprintf(OutPut, "%u", Number);
		return strdup(OutPut);
	}
	else if (Number < 1000000) {
		int part1 = Number % 1000;
		int part2 = (Number - part1) / 1000;
		sprintf(OutPut, "%u,%03u", part2, part1);
		return strdup(OutPut);
	}
	else if (Number < 1000000000) {
		int part1 = Number % 1000;
		Number = (Number - part1) / 1000;
		int part2 = Number % 1000;
		Number = (Number - part2) / 1000;
		int part3 = Number % 1000;

		sprintf(OutPut, "%u,%03u,%03u", part3, part2, part1);
		return strdup(OutPut);
	}
	else {
		int part1 = Number % 1000;
		Number = (Number - part1) / 1000;
		int part2 = Number % 1000;
		Number = (Number - part2) / 1000;
		int part3 = Number % 1000;
		int part4 = (Number - part3) / 1000;

		sprintf(OutPut, "%u,%03u,%03u,%03u", part4, part3, part2, part1);
		return strdup(OutPut);
	}
	return "0";
}



#if(EXBEXO_LOAD_SEND_TINH_NANG)
void Interface::DRAW_TINHNANG_INTERFACE()
{

	if (gProtect.m_MainInfo.EnableNutC != 0)
	{

		float MainWidth = 30.0;
		float MainHeight = 20.0;
		float StartY = 20.0;
		float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
		if (this->CheckWindow(ObjWindow::Character))
		{
			// AutoReset
			this->DrawGUI(EXBEXO_AUTORESET_INTERFACE, StartX + 160, StartY + 52);
			//--------------------------------------------------------------------------------------------
			HFONT TextFontBold_Autoreset = CreateFontA(15, 0, 0, 0, 700, 0, 0, 0, 0x1, 0, 0, 3, 0, "Tahoma");
			pSetTextFont(pTextThis(), TextFontBold_Autoreset); //set font
			pSetTextColor(pTextThis(), 255, 255, 0, 255); // MÀU
			pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
			pDrawText(pTextThis(), 473, 77, gCustomMessage.GetMessage(160), 150, 0, (LPINT)0, 0); // "Tự động Reset"
			//Giải phóng
			DeleteObject(TextFontBold_Autoreset);
			//--------------------------------------------------------------------------------------------
			// QuestClass
			this->DrawGUI(EXBEXO_QUESTCLASS_INTERFACE, StartX + 239, StartY + 52);
			//--------------------------------------------------------------------------------------------
			HFONT TextFontBold_NhiemVu = CreateFontA(15, 0, 0, 0, 700, 0, 0, 0, 0x1, 0, 0, 3, 0, "Tahoma");
			pSetTextFont(pTextThis(), TextFontBold_NhiemVu); //set font
			pSetTextColor(pTextThis(), 0, 255, 255, 255); // MÀU
			pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
			pDrawText(pTextThis(), 558, 77, gCustomMessage.GetMessage(161), 150, 0, (LPINT)0, 0); // "Làm Nhiệm Vụ"
			//Giải phóng
			DeleteObject(TextFontBold_NhiemVu);
			//--------------------------------------------------------------------------------------------
			// OffAttack
			this->DrawGUI(EXBEXO_OFFATTACK_INTERFACE, StartX + 160, StartY + 74);
			//--------------------------------------------------------------------------------------------
			HFONT TextFontBold_OffAttack = CreateFontA(15, 0, 0, 0, 700, 0, 0, 0, 0x1, 0, 0, 3, 0, "Tahoma");
			pSetTextFont(pTextThis(), TextFontBold_OffAttack); //set font
			pSetTextColor(pTextThis(), 255, 0, 0, 255); // MÀU
			pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
			pDrawText(pTextThis(), 473, 100, gCustomMessage.GetMessage(162), 150, 0, (LPINT)0, 0); // "ATTACK"
			//Giải phóng
			DeleteObject(TextFontBold_OffAttack);
			//--------------------------------------------------------------------------------------------
			// UyThac
			this->DrawGUI(EXBEXO_UYTHAC_INTERFACE, StartX + 239, StartY + 74);
			//--------------------------------------------------------------------------------------------
			HFONT TextFontBold_UyThac = CreateFontA(15, 0, 0, 0, 700, 0, 0, 0, 0x1, 0, 0, 3, 0, "Tahoma");
			pSetTextFont(pTextThis(), TextFontBold_UyThac); //set font
			pSetTextColor(pTextThis(), 0, 255, 0, 255); // MÀU
			pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
			pDrawText(pTextThis(), 558, 100, gCustomMessage.GetMessage(163), 150, 0, (LPINT)0, 0); // "OFF ATTACK"
			//Giải phóng
			DeleteObject(TextFontBold_UyThac);
			//--------------------------------------------------------------------------------------------
			// TayDiem
			this->DrawGUI(EXBEXO_TAYDIEM_INTERFACE, StartX + 159, StartY + 351);
			//--------------------------------------------------------------------------------------------
			HFONT TextFontBold_TayDiem = CreateFontA(15, 0, 0, 0, 700, 0, 0, 0, 0x1, 0, 0, 3, 0, "Tahoma");
			pSetTextFont(pTextThis(), TextFontBold_TayDiem); //set font
			pSetTextColor(pTextThis(), 0, 255, 255, 255); // MÀU
			pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
			pDrawText(pTextThis(), 488, 377, gCustomMessage.GetMessage(164), 150, 0, (LPINT)0, 0); // "Tẩy Điểm"
			//Giải phóng
			DeleteObject(TextFontBold_TayDiem);
			//--------------------------------------------------------------------------------------------
			// TayDiemMaster
			this->DrawGUI(EXBEXO_TAYDIEMMASTER_INTERFACE, StartX + 239, StartY + 351);
			//--------------------------------------------------------------------------------------------
			HFONT TextFontBold_TayDiemMaster = CreateFontA(15, 0, 0, 0, 700, 0, 0, 0, 0x1, 0, 0, 3, 0, "Tahoma");
			pSetTextFont(pTextThis(), TextFontBold_TayDiemMaster); //set font
			pSetTextColor(pTextThis(), 0, 255, 255, 255); // MÀU
			pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
			pDrawText(pTextThis(), 565, 377, gCustomMessage.GetMessage(165), 150, 0, (LPINT)0, 0); // "Tẩy Điểm Master"
			//Giải phóng
			DeleteObject(TextFontBold_TayDiemMaster);
			//--------------------------------------------------------------------------------------------
		}
		//----------------------------------------------------------------------------------------------------------------------
		if (this->CheckWindow(ObjWindow::Character))
		if (gInterface.IsWorkZone(EXBEXO_AUTORESET_INTERFACE))
		{
			DWORD Color = eGray150;
			gInterface.DrawColoredGUI(EXBEXO_AUTORESET_INTERFACE, gInterface.Data[EXBEXO_AUTORESET_INTERFACE].X, gInterface.Data[EXBEXO_AUTORESET_INTERFACE].Y, Color);
		}
		//----------------------------------------------------------------------------------------------------------------------
		if (this->CheckWindow(ObjWindow::Character))
		if (gInterface.IsWorkZone(EXBEXO_QUESTCLASS_INTERFACE))
		{
			DWORD Color = eGray150;
			gInterface.DrawColoredGUI(EXBEXO_QUESTCLASS_INTERFACE, gInterface.Data[EXBEXO_QUESTCLASS_INTERFACE].X, gInterface.Data[EXBEXO_QUESTCLASS_INTERFACE].Y, Color);
		}
		//----------------------------------------------------------------------------------------------------------------------
		if (this->CheckWindow(ObjWindow::Character))
		if (gInterface.IsWorkZone(EXBEXO_OFFATTACK_INTERFACE))
		{
			DWORD Color = eGray150;
			gInterface.DrawColoredGUI(EXBEXO_OFFATTACK_INTERFACE, gInterface.Data[EXBEXO_OFFATTACK_INTERFACE].X, gInterface.Data[EXBEXO_OFFATTACK_INTERFACE].Y, Color);
		}
		//----------------------------------------------------------------------------------------------------------------------
		if (this->CheckWindow(ObjWindow::Character))
		if (gInterface.IsWorkZone(EXBEXO_UYTHAC_INTERFACE))
		{
			DWORD Color = eGray150;
			gInterface.DrawColoredGUI(EXBEXO_UYTHAC_INTERFACE, gInterface.Data[EXBEXO_UYTHAC_INTERFACE].X, gInterface.Data[EXBEXO_UYTHAC_INTERFACE].Y, Color);
		}
		//----------------------------------------------------------------------------------------------------------------------
		if (this->CheckWindow(ObjWindow::Character))
		if (gInterface.IsWorkZone(EXBEXO_TAYDIEM_INTERFACE))
		{
			DWORD Color = eGray150;
			gInterface.DrawColoredGUI(EXBEXO_TAYDIEM_INTERFACE, gInterface.Data[EXBEXO_TAYDIEM_INTERFACE].X, gInterface.Data[EXBEXO_TAYDIEM_INTERFACE].Y, Color);
		}
		//----------------------------------------------------------------------------------------------------------------------
		if (this->CheckWindow(ObjWindow::Character))
		if (gInterface.IsWorkZone(EXBEXO_TAYDIEMMASTER_INTERFACE))
		{
			DWORD Color = eGray150;
			gInterface.DrawColoredGUI(EXBEXO_TAYDIEMMASTER_INTERFACE, gInterface.Data[EXBEXO_TAYDIEMMASTER_INTERFACE].X, gInterface.Data[EXBEXO_TAYDIEMMASTER_INTERFACE].Y, Color);
		}
	}
}

bool Interface::EVENT_TINHNANG_INTERFACE(DWORD Event)
{
	this->EVENT_AUTORESET_INTERFACE(Event);
	this->EVENT_LAMNHIEMVU_INTERFACE(Event);
	this->EVENT_OFFATTACK_INTERFACE(Event);
	this->EVENT_UYTHAC_INTERFACE(Event);
	this->EVENT_TAYDIEM_INTERFACE(Event);
	this->EVENT_TAYDIEM_MASTER_INTERFACE(Event);
	return true;
}
bool Interface::EVENT_AUTORESET_INTERFACE(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[EXBEXO_AUTORESET_INTERFACE].EventTick);
	if (!this->CheckWindow(ObjWindow::Character) || !IsWorkZone(EXBEXO_AUTORESET_INTERFACE))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[EXBEXO_AUTORESET_INTERFACE].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[EXBEXO_AUTORESET_INTERFACE].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[EXBEXO_AUTORESET_INTERFACE].EventTick = GetTickCount();
	PMSG_TICKET_SEND pMsg;
	pMsg.header.set(0xFC, 0x23, sizeof(pMsg));
	DataSend((BYTE*)&pMsg, pMsg.header.size);
	//gInterface.CloseWindow(Character);

	return true;

}
// ----------------------------------------------------------------------------------------------
bool Interface::EVENT_LAMNHIEMVU_INTERFACE(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[EXBEXO_QUESTCLASS_INTERFACE].EventTick);
	if (!this->CheckWindow(ObjWindow::Character) || !IsWorkZone(EXBEXO_QUESTCLASS_INTERFACE))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[EXBEXO_QUESTCLASS_INTERFACE].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[EXBEXO_QUESTCLASS_INTERFACE].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[EXBEXO_QUESTCLASS_INTERFACE].EventTick = GetTickCount();
	PMSG_TICKET_SEND pMsg;
	pMsg.header.set(0xFC, 0x24, sizeof(pMsg));
	DataSend((BYTE*)&pMsg, pMsg.header.size);
	//gInterface.CloseWindow(Character);
	return true;
}
// ----------------------------------------------------------------------------------------------
bool Interface::EVENT_OFFATTACK_INTERFACE(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[EXBEXO_OFFATTACK_INTERFACE].EventTick);
	if (!this->CheckWindow(ObjWindow::Character) || !IsWorkZone(EXBEXO_OFFATTACK_INTERFACE))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[EXBEXO_OFFATTACK_INTERFACE].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[EXBEXO_OFFATTACK_INTERFACE].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[EXBEXO_OFFATTACK_INTERFACE].EventTick = GetTickCount();
	PMSG_TICKET_SEND pMsg;
	pMsg.header.set(0xFC, 0x25, sizeof(pMsg));
	DataSend((BYTE*)&pMsg, pMsg.header.size);
	//gInterface.CloseWindow(Character);
	return true;
}
// ----------------------------------------------------------------------------------------------
bool Interface::EVENT_UYTHAC_INTERFACE(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[EXBEXO_UYTHAC_INTERFACE].EventTick);
	if (!this->CheckWindow(ObjWindow::Character) || !IsWorkZone(EXBEXO_UYTHAC_INTERFACE))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[EXBEXO_UYTHAC_INTERFACE].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[EXBEXO_UYTHAC_INTERFACE].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[EXBEXO_UYTHAC_INTERFACE].EventTick = GetTickCount();
	PMSG_TICKET_SEND pMsg;
	pMsg.header.set(0xFC, 0x26, sizeof(pMsg));
	DataSend((BYTE*)&pMsg, pMsg.header.size);
	//gInterface.CloseWindow(Character);
	return true;
}
// ----------------------------------------------------------------------------------------------
bool Interface::EVENT_TAYDIEM_INTERFACE(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[EXBEXO_TAYDIEM_INTERFACE].EventTick);
	if (!this->CheckWindow(ObjWindow::Character) || !IsWorkZone(EXBEXO_TAYDIEM_INTERFACE))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[EXBEXO_TAYDIEM_INTERFACE].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[EXBEXO_TAYDIEM_INTERFACE].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[EXBEXO_TAYDIEM_INTERFACE].EventTick = GetTickCount();
	PMSG_TICKET_SEND pMsg;
	pMsg.header.set(0xFC, 0x27, sizeof(pMsg));
	DataSend((BYTE*)&pMsg, pMsg.header.size);
	//gInterface.CloseWindow(Character);
	return true;
}
// ----------------------------------------------------------------------------------------------
bool Interface::EVENT_TAYDIEM_MASTER_INTERFACE(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[EXBEXO_TAYDIEMMASTER_INTERFACE].EventTick);
	if (!this->CheckWindow(ObjWindow::Character) || !IsWorkZone(EXBEXO_TAYDIEMMASTER_INTERFACE))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[EXBEXO_TAYDIEMMASTER_INTERFACE].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[EXBEXO_TAYDIEMMASTER_INTERFACE].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[EXBEXO_TAYDIEMMASTER_INTERFACE].EventTick = GetTickCount();
	PMSG_TICKET_SEND pMsg;
	pMsg.header.set(0xFC, 0x28, sizeof(pMsg));
	DataSend((BYTE*)&pMsg, pMsg.header.size);
	//gInterface.CloseWindow(Character);
	return true;
}
// ----------------------------------------------------------------------------------------------
#endif
DWORD	SetInvisibleEffect_PointerYYYYY;
DWORD	SetInvisibleEffect_BuffYYYYY;
DWORD	SetInvisibleEffect_PointerYYYY;
DWORD	SetInvisibleEffect_BuffYYYY;

__declspec(naked) void ItemInvisible11(){
	static DWORD m_aaaaab = 0x0060B37A;
	_asm{
		mov SetInvisibleEffect_BuffYYYYY, esi
			mov ecx, dword ptr ss : [ebp + 8]
			mov esi, dword ptr ds : [ecx + 0x30]
			mov SetInvisibleEffect_PointerYYYYY, esi
			mov esi, SetInvisibleEffect_BuffYYYYY
	}
	if (SetInvisibleEffect_PointerYYYYY != 0x1EA5
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(12, 15)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(12, 30)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(12, 31)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(12, 136)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(12, 137)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(12, 138)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(12, 139)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(12, 140)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(12, 141)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(12, 142)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(12, 143)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(14, 13)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(14, 14)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(14, 16)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(14, 31)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(14, 42)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(14, 13)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(14, 41)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(14, 43)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(14, 44))
	{
		_asm{
			jmp[m_aaaaab]
		}
	}
}
__declspec(naked) void ItemInvisible22(){
	static DWORD m_aaaaaa = 0x0060B41D;
	_asm{
		mov SetInvisibleEffect_BuffYYYY, esi
			mov ecx, dword ptr ss : [ebp + 8]
			mov esi, dword ptr ds : [ecx + 0x30]
			jmp[m_aaaaaa]
	}
}
DWORD	SetInvisibleEffect_PointerXXX;
DWORD	SetInvisibleEffect_BuffXXX;

Naked(InvisibleEffectXX){
	_asm{
		mov SetInvisibleEffect_BuffXXX, esi
			mov ecx, dword ptr ss : [ebp + 8]
			mov esi, dword ptr ds : [ecx + 0x30]
			mov SetInvisibleEffect_PointerXXX, esi
			mov esi, SetInvisibleEffect_BuffXXX
	}
	if (SetInvisibleEffect_PointerXXX == 0x1EA5 || SetInvisibleEffect_PointerXXX == ITEM2(13, 18)){
		_asm{
			mov SetInvisibleEffect_BuffXXX, 0x0060B37A
				jmp SetInvisibleEffect_BuffXXX
		}
	}
	else{
		_asm{
			mov SetInvisibleEffect_BuffXXX, 0x0060B41D
				jmp SetInvisibleEffect_BuffXXX
		}
	}
}

void InvisibleItem11(){
	SetCompleteHook(0xE9, 0x0060B36A, &ItemInvisible11);
}
void InvisibleItem22(){
	SetCompleteHook(0xE9, 0x0060B36A, &ItemInvisible22);
}
void InvisibleItemXX(){
	SetRange((LPVOID)0x0060B36A, 10, ASM::NOP); //12
	SetCompleteHook(0xE9, 0x0060B36A, &InvisibleEffectXX);
}


void Interface::SwitchAntiLag1()
{
	if ((GetTickCount() - gInterface.Data[ePLAYER_POINT].EventTick) < 1000 || this->CheckWindow(ChatWindow))
	{
		return;
	}

	gInterface.Data[ePLAYER_POINT].EventTick = GetTickCount();

	if (GetForegroundWindow() == pGameWindow && !gInterface.CheckWindow(ObjWindow::ChatWindow))
	{
		if (AntiLag1 != 0)
		{
			gInterface.DrawMessage(1, "AntiLag 1 [OFF]");

			AntiLag1 = 0;
			SetByte(0x0074CD30, 0x55); //Enable Dynamic Effects
			SetByte(0x00771310, 0x55); //Enable Static Effects
			SetByte(0x00608200, 0x55); //Enable Glow Effects
			SetByte(0x00608FB0, 0x55); //Enable Skills Effects
			//SetByte(0x005EDFE0, 0x55); //Enable Objects
			//SetByte(0x0054A270, 0x55); //Shadows

		}
		else
		{
			gInterface.DrawMessage(1, "AntiLag 1 [ON]");
			AntiLag1 = 1;
			SetByte(0x0074CD30, 0xC3); //Disable Dynamic Effects
			SetByte(0x00771310, 0xC3); //Disable Static Effects
			SetByte(0x00608200, 0xC3); //Disable Glow Effects
			SetByte(0x00608FB0, 0xC3); //Disable Skills Effects
			//SetByte(0x0054A270, 0xC3); //Disable Shadows

		}
	}
}
void Interface::SwitchAntiLag2()
{
	if (pPlayerState < GameProcess)
	{
		return;
	}
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
		|| gInterface.CheckWindow(ObjWindow::Inventory)
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
		return;
	}
	if ((GetTickCount() - gInterface.Data[ePLAYER_POINT].EventTick) < 1000 || this->CheckWindow(ChatWindow))
	{
		return;
	}

	gInterface.Data[ePLAYER_POINT].EventTick = GetTickCount();

	if (GetForegroundWindow() == pGameWindow && !gInterface.CheckWindow(ObjWindow::ChatWindow))
	{
		if (AntiLag2 != 0)
		{
			gInterface.DrawMessage(1, "[F7] Antilag [OFF]");

			AntiLag2 = 0;
			InvisibleItem22();
			InvisibleItemXX();

			SetByte((0x0074CD80 + 2), (this->AntiLag2 == 0) ? 1 : 0); // DisableDynamicEffect
			SetByte((0x00771359 + 3), (this->AntiLag2 == 0) ? 1 : 0); // DisableStaticEffect
			DisableGlowEffect == this->AntiLag2 == 1;
			DisableShadow = this->AntiLag2 == 1;
			SetCompleteHook(0xE8, 0x00588661, 0x005655C0); // Dis Wings
			SetCompleteHook(0xE8, 0x00576DDB, 0x005655C0); //Enable Weapons
			SetCompleteHook(0xE8, 0x005883F4, 0x005655C0); //Enable Weapons
			SetByte(0x0051EE20, 0x55); //Enable Cloaks

		}
		else
		{
			gInterface.DrawMessage(1, "[F7] Antilag [ON]");

			InvisibleItem11();

			SetByte((0x0074CD80 + 2), (this->AntiLag2 == 1) ? 1 : 0); // DisableDynamicEffect
			SetByte((0x00771359 + 3), (this->AntiLag2 == 1) ? 1 : 0); // DisableStaticEffect

			DisableGlowEffect == this->AntiLag2 == 0;
			DisableShadow = this->AntiLag2 == 0;

			MemorySet(0x00588661, 0x90, 0x05); // On Wing
			MemorySet(0x00576DDB, 0x90, 0x05); //Disable Weapons
			MemorySet(0x005883F4, 0x90, 0x05); //Disable Weapons
			SetByte(0x0051EE20, 0xC3); //Disable Cloaks

			AntiLag2 = 1;
		}
	}
}


DWORD ClickTickCount = 0;
#if(CHIEN_TRUONG_CO)
void Interface::DrawChienTruongCo()
{
	if (!this->Data[eCuaSoCTC].OnShow)
	{
		return;
	}

	float CuaSoW = 230.0;
	float CuaSoH = 200.0;

	float StartX = (MAX_WIN_WIDTH / 2) - (CuaSoW / 2);
	float StartY = 45.0;

	gCBUtil.gDrawWindowCustom(&StartX, &StartY, CuaSoW, CuaSoH, eCuaSoCTC, "Chiến Trường Cổ");

	//gCentral.PrintDropBox(StartX, StartY, CuaSoW, CuaSoH, 0, 0);


	if (gInterface.IsWorkZone(StartX, StartY, CuaSoW, CuaSoH)) // nếu chuột trong khu vực bảng shop thì ko click di chuyển nv
	{
		pSetCursorFocus = true;
	}
	else pSetCursorFocus = false;

	////======Close
	//int CloseX = StartX + CuaSoW - 40;
	//int CloseY = StartY;
	//pDrawGUI(0x7EC5, CloseX, CloseY, 36.0f, 29.0f);
	//if (pCheckMouseOver(CloseX, CloseY, 36, 36) == 1)
	//{
	//	if (GetTickCount() - ClickTickCount > 300)
	//	{
	//		if (GetKeyState(1) & 0x8000)
	//		{
	//			glColor3f(1.0f, 0.0f, 0.0f);
	//			gInterface.Data[eCuaSoCTC].OnShow ^= 1;
	//			ClickTickCount = GetTickCount();
	//		}
	//	}
	//	pDrawColorButton(0x7EC5, CloseX, CloseY, 36, 29, 0, 0, pMakeColor(255, 204, 20, 130));
	//	gInterface.DrawFormat(eGold, CloseX + 15, CloseY + 30, 0, 1, "Đóng");
	//}
	//================================================
	//CustomFont.Draw(CustomFont.FontBold, StartX, StartY + 5, 0xB8E600FF, 0x0, CuaSoW, 0, 3, "Chiến Trường Cổ"); //
	//pDrawGUI(71520, StartX + (CuaSoW / 2) - (200 / 2), StartY + 30, 200, 1); //-- Divisor
	StartX = StartX + (CuaSoW / 8);
	StartY = StartY + 45;
	//====================================
	int hours = CTC_TimeConLai / 3600;
	int minutes = (CTC_TimeConLai / 60) % 60;
	int seconds = CTC_TimeConLai % 60;
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY, 0xE6FCF7FF, 0x0, CuaSoW, 0, 1, "Thời gian còn lại:"); //
	CustomFont.Draw(CustomFont.FontBold, StartX + 70, StartY, 0x16FAC1FF, 0x0, CuaSoW, 0, 1, "%02d:%02d:%02d", hours, minutes, seconds); //
	//===================================
	StartY = StartY + 15;
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY, 0xFFDE26FF, 0x0, CuaSoW, 0, 1, "- Tiêu Diệt Đủ %d Quái Nhận 1 Ngọc Ngẫu Nhiên", CTC_MonterYeuCau); //
	StartY = StartY + 15;
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY, 0xFFDE26FF, 0x0, CuaSoW, 0, 1, "- Mỗi Ngày Miễn Phí 40 Phút", CTC_PartyKillPoint); //
	StartY = StartY + 15;
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY, 0xFFDE26FF, 0x0, CuaSoW, 0, 1, "- Mua Thêm 60 Phút Mất 50k Wcoin", CTC_PointKillQuai); //
	StartY = StartY + 15;
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY, 0x26FFD0FF, 0x0, CuaSoW, 0, 1, "- Có Khả Năng Rớt Lông Vũ, HHHT"); //
	StartY = StartY + 15;
	CustomFont.Draw(CustomFont.FontBold, StartX, StartY, 0xFF7226FF, 0x0, CuaSoW, 0, 1, "Lưu Ý : Khu vực PK Tự Do, Hãy Cẩn Thận"); //


	//============Button
	float SizeButtonW = 95.0;
	float SizeButtonH = 19.0;
	StartX = StartX - 10;
	//=====================Button 1
	if (pCheckMouseOver(StartX, StartY + 40, SizeButtonW, SizeButtonH) == 1)
	{
		glColor3f(1.0f, 0.6742f, 0.15f);
		if (GetTickCount() - gInterface.Data[eCuaSoCTC].EventTick > 300) //Click
		{
			if (GetKeyState(1) & 0x8000)
			{

				glColor3f(0.72f, 0.438f, 0.0432f);


				XULY_CGPACKET pMsg;
				pMsg.header.set(0xF3, 0x38, sizeof(pMsg));
				pMsg.ThaoTac = 1;
				DataSend((LPBYTE)&pMsg, pMsg.header.size);
				this->Data[eCuaSoCTC].OnShow = 0;
				gInterface.Data[eCuaSoCTC].EventTick = GetTickCount();
				//pDrawMessage ( "Button 2", 0 );
			}
		}
	}
	else {
		glColor3f(1.0f, 1.0f, 1.0f);

	}
	RenderBitmap(31563, StartX, StartY + 40, SizeButtonW, SizeButtonH, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + 40 + (SizeButtonH / 4), 0xE6FCF7FF, 0x0, SizeButtonW, 0, 3, "Bước Vào"); //Buoc Vao

	//=====================================
	//=====================Button 2
	if (pCheckMouseOver(StartX + SizeButtonW + 5, StartY + 40, SizeButtonW, SizeButtonH) == 1)
	{
		glColor3f(1.0f, 0.6742f, 0.15f);
		if (GetTickCount() - gInterface.Data[eCuaSoCTC].EventTick > 300) //Click
		{
			if (GetKeyState(1) & 0x8000)
			{
				glColor3f(0.72f, 0.438f, 0.0432f);

				XULY_CGPACKET pMsg;
				pMsg.header.set(0xF3, 0x38, sizeof(pMsg));
				pMsg.ThaoTac = 2;
				DataSend((LPBYTE)&pMsg, pMsg.header.size);
				//pDrawMessage ( "Button 2", 0 );		  
				gInterface.Data[eCuaSoCTC].EventTick = GetTickCount();
			}
		}
	}
	else {
		glColor3f(1.0f, 1.0f, 1.0f);

	}
	RenderBitmap(31563, StartX + SizeButtonW + 5, StartY + 40, SizeButtonW, SizeButtonH, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);
	CustomFont.Draw(CustomFont.FontNormal, StartX + SizeButtonW + 5, StartY + 40 + (SizeButtonH / 4), 0xE6FCF7FF, 0x0, SizeButtonW, 0, 3, "Thêm Thời Gian"); //
	//=====================================
	glColor3f(1.0f, 1.0f, 1.0f); //Xoa mau

}



void Interface::DrawTimeCTC()
{

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
		|| gInterface.CheckWindow(ObjWindow::Inventory)
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
		return;
	}
	if (pMapNumber != 97) {
		return;
	}
	float CuaSoW = 130.0;
	float CuaSoH = 81.0;

	float StartX = 516.0;
	float StartY = 348.0;
	//RenderBitmap(31566, StartX, StartY, CuaSoW, CuaSoH, 0.0, 0.0, 1.0, 1.0, 1, 1, 0);
	pDrawGUI(31650, 412.0f, 342.0f, 227.0f, 87.0f);
	int PhanTramKill;
	if (CTC_MonterYeuCau > 0) {
		PhanTramKill = (CTC_QuaiVatDaKill * 100) / CTC_MonterYeuCau;
		if (PhanTramKill > 100) { PhanTramKill = 100; }
		CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + 5, 0xFF7226FF, 0x0, CuaSoW, 0, 3, "Đã Tiêu Diệt: %d/%d Quái", CTC_QuaiVatDaKill, CTC_MonterYeuCau); //
	}
	//================ Tinh Toan Time
	if ((GetTickCount() - gInterface.Data[eTimeCTC].EventTick) > 1000)
	{
		if (CTC_TimeConLai > 0)
		{
			CTC_TimeConLai = CTC_TimeConLai - 1;
		}
		gInterface.Data[eTimeCTC].EventTick = GetTickCount();
	}

	int hours = CTC_TimeConLai / 3600;
	int minutes = (CTC_TimeConLai / 60) % 60;
	int seconds = CTC_TimeConLai % 60;
	CustomFont.Draw(CustomFont.FontBold, StartX, StartY + 35, 0x16FAC1FF, 0x0, CuaSoW, 0, 3, "Thời Gian Còn Lại : %02d:%02d:%02d", hours, minutes, seconds); //
	//=================================
	float TyLeTGA = (166.0 * PhanTramKill) / 100;
	if (TyLeTGA > 166.0) { TyLeTGA = 166.0; }
	pDrawGUI(31653, 471.5f, 421.0f, TyLeTGA, 7.0f);


}
#endif



//===========
void CGMoveCTCMini(int Type)
{
	if (Type > 0)
	{
		CTCMINI_CGPACKET pMsg;
		pMsg.header.set(0xF3, 0x39, sizeof(pMsg));
		pMsg.CongVao = Type - 1;
		DataSend((LPBYTE)&pMsg, pMsg.header.size);
	}
}


void Interface::DrawCTCMiniWindow()
{

	if (!this->Data[eCTCMiniWindow].OnShow)
	{
		return;
	}

	pSetCursorFocus = true;

	float CuaSoW = 250.0;
	float CuaSoH = 250.0;

	float StartX = (MAX_WIN_WIDTH / 2) - (CuaSoW / 2);
	float StartY = 95.0;

	gCBUtil.gDrawWindowCustom(&StartX, &StartY, CuaSoW, CuaSoH, eCTCMiniWindow, "Công Thành Chiến Mini");

	//gCentral.PrintDropBox(StartX, StartY, CuaSoW, CuaSoH, 0, 0);

	////======Close
	//int CloseX = StartX + CuaSoW - 40;
	//int CloseY = StartY;
	//pDrawGUI(0x7EC5, CloseX, CloseY, 36.0f, 29.0f);
	//if (pCheckMouseOver(CloseX, CloseY, 36, 36) == 1)
	//{
	//	if (GetTickCount() - ClickTickCount > 300)
	//	{
	//		if (GetKeyState(1) & 0x8000)
	//		{
	//			glColor3f(1.0f, 0.0f, 0.0f);
	//			gInterface.Data[eCTCMiniWindow].OnShow ^= 1;
	//			ClickTickCount = GetTickCount();
	//		}
	//	}
	//	pDrawColorButton(0x7EC5, CloseX, CloseY, 36, 29, 0, 0, pMakeColor(255, 204, 20, 130));
	//	gInterface.DrawFormat(eGold, CloseX + 15, CloseY + 30, 0, 1, "Close");
	//}
	////================================================
	//CustomFont.Draw(CustomFont.FontBold, StartX, StartY + 5, 0xB8E600FF, 0x0, CuaSoW, 0, 3, "CTC Mini"); // cái đó em sửa sau 
	//pDrawGUI(71520, StartX + (CuaSoW / 2) - (200 / 2), StartY + 30, 200, 1); //-- Divisor
	//====================================
	StartY = StartY + 45;
	CustomFont.Draw(CustomFont.FontNormal, StartX + (CuaSoW / 10), StartY, 0xFFDE26FF, 0x0, CuaSoW, 0, 1, "- Cả guild: +25000 cống hiến khi Phá Cổng"); //
	StartY = StartY + 12;
	CustomFont.Draw(CustomFont.FontNormal, StartX + (CuaSoW / 10), StartY, 0xFFDE26FF, 0x0, CuaSoW, 0, 1, "- Cả guild: +30000 cống hiến khi Chiếm Trụ"); //
	StartY = StartY + 12;
	CustomFont.Draw(CustomFont.FontNormal, StartX + (CuaSoW / 10), StartY, 0xFFDE26FF, 0x0, CuaSoW, 0, 1, "- Cả guild: +10000 cống hiến khi Thắng Sự Kiện"); //
	StartY = StartY + 12;
	CustomFont.Draw(CustomFont.FontBold, StartX + (CuaSoW / 10), StartY, 0x00FFCCFF, 0x0, CuaSoW, 0, 1, "Lưu ý: Guild Chiếm 2 trụ trở lên sẽ thắng."); //
	StartY = StartY + 12;
	CustomFont.Draw(CustomFont.FontBold, StartX + (CuaSoW / 10), StartY, 0x00FF90FF, 0x0, CuaSoW, 0, 1, "Guild Chiến Thắng Sự Kiện Trước Sẽ Được Vào 'Lãnh Địa'"); //
	StartY = StartY + 25;
	pDrawGUI(32583, StartX, StartY, 128.0f, 128.0f); //Huong Dan CTC

	//============Button
	StartY = StartY + 10;
	float SizeButtonW = 95.0;
	float SizeButtonH = 19.0;
	StartX = StartX + (CuaSoW / 2);
	//=====================Button 1
	if (pCheckMouseOver(StartX, StartY, SizeButtonW, SizeButtonH) == 1)
	{
		glColor3f(1.0f, 0.6742f, 0.15f);
		if (GetTickCount() - gInterface.Data[eCTCMiniWindow].EventTick > 300) //Click
		{
			if (GetKeyState(1) & 0x8000)
			{

				glColor3f(0.72f, 0.438f, 0.0432f);
				CGMoveCTCMini(1);
				this->Data[eCTCMiniWindow].OnShow = 0;
				gInterface.Data[eCTCMiniWindow].EventTick = GetTickCount();
				//pDrawMessage ( "Button 2", 0 );
			}
		}
	}
	else {
		glColor3f(1.0f, 1.0f, 1.0f);

	}
	RenderBitmap(31563, StartX, StartY, SizeButtonW, SizeButtonH, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + (SizeButtonH / 4), 0xE6FCF7FF, 0x0, SizeButtonW, 0, 3, "Cổng 1"); //Buoc Vao
	//=====================================
	StartY = StartY + 22;
	//=====================Button 2
	if (pCheckMouseOver(StartX, StartY, SizeButtonW, SizeButtonH) == 1)
	{
		glColor3f(1.0f, 0.6742f, 0.15f);
		if (GetTickCount() - gInterface.Data[eCTCMiniWindow].EventTick > 300) //Click
		{
			if (GetKeyState(1) & 0x8000)
			{

				glColor3f(0.72f, 0.438f, 0.0432f);


				CGMoveCTCMini(2);
				this->Data[eCTCMiniWindow].OnShow = 0;
				gInterface.Data[eCTCMiniWindow].EventTick = GetTickCount();
			}
		}
	}
	else {
		glColor3f(1.0f, 1.0f, 1.0f);

	}
	RenderBitmap(31563, StartX, StartY, SizeButtonW, SizeButtonH, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + (SizeButtonH / 4), 0xE6FCF7FF, 0x0, SizeButtonW, 0, 3, "Cổng 2"); //Buoc Vao
	//=====================================
	StartY = StartY + 22;
	//=====================Button 3
	if (pCheckMouseOver(StartX, StartY, SizeButtonW, SizeButtonH) == 1)
	{
		glColor3f(1.0f, 0.6742f, 0.15f);
		if (GetTickCount() - gInterface.Data[eCTCMiniWindow].EventTick > 300) //Click
		{
			if (GetKeyState(1) & 0x8000)
			{

				glColor3f(0.72f, 0.438f, 0.0432f);


				CGMoveCTCMini(3);
				this->Data[eCTCMiniWindow].OnShow = 0;
				gInterface.Data[eCTCMiniWindow].EventTick = GetTickCount();
			}
		}
	}
	else {
		glColor3f(1.0f, 1.0f, 1.0f);

	}
	RenderBitmap(31563, StartX, StartY, SizeButtonW, SizeButtonH, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + (SizeButtonH / 4), 0xE6FCF7FF, 0x0, SizeButtonW, 0, 3, "Cổng 3"); //Buoc Vao
	//=====================================
	StartY = StartY + 22;
	//=====================Button 4
	if (pCheckMouseOver(StartX, StartY, SizeButtonW, SizeButtonH) == 1)
	{
		glColor3f(1.0f, 0.6742f, 0.15f);
		if (GetTickCount() - gInterface.Data[eCTCMiniWindow].EventTick > 300) //Click
		{
			if (GetKeyState(1) & 0x8000)
			{

				glColor3f(0.72f, 0.438f, 0.0432f);


				CGMoveCTCMini(4);
				this->Data[eCTCMiniWindow].OnShow = 0;
				gInterface.Data[eCTCMiniWindow].EventTick = GetTickCount();
				//pDrawMessage ( "Button 2", 0 );
			}
		}
	}
	else {
		glColor3f(1.0f, 1.0f, 1.0f);

	}
	RenderBitmap(31563, StartX, StartY, SizeButtonW, SizeButtonH, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + (SizeButtonH / 4), 0xE6FCF7FF, 0x0, SizeButtonW, 0, 3, "Cổng 4"); //Buoc Vao
	//=====================================
	StartY = StartY + 22;
	//=====================Button Lanh Dia
	if (pCheckMouseOver(StartX, StartY, SizeButtonW, SizeButtonH) == 1 && CheckVaoLanhDia)
	{
		glColor3f(1.0f, 0.6742f, 0.15f);
		if (GetTickCount() - gInterface.Data[eCTCMiniWindow].EventTick > 300) //Click
		{
			if (GetKeyState(1) & 0x8000)
			{

				glColor3f(0.72f, 0.438f, 0.0432f);


				CGMoveCTCMini(5);
				this->Data[eCTCMiniWindow].OnShow = 0;
				gInterface.Data[eCTCMiniWindow].EventTick = GetTickCount();
			}
		}
	}
	else if (!CheckVaoLanhDia) {
		glColor3f(0.42f, 0.42f, 0.42f);
	}
	else {
		glColor3f(1.0f, 1.0f, 1.0f);

	}
	RenderBitmap(31563, StartX, StartY, SizeButtonW, SizeButtonH, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + (SizeButtonH / 4), 0xE6FCF7FF, 0x0, SizeButtonW, 0, 3, "Lãnh Địa"); //Buoc Vao
	//=====================================
	//=====================================
	glColor3f(1.0f, 1.0f, 1.0f); //Xoa mau
}

void Interface::DrawCTCMiNiMap()
{
	if (pPlayerState < GameProcess)
	{
		return;
	}
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
		|| gInterface.CheckWindow(ObjWindow::Inventory)
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
		return;
	}
	if (gObjUser.m_MapNumber != 98)
	{
		return;
	}
	float MainWidth = 138.0;
	float MainHeight = 265.0;
	float StartY = 264.0;
	float StartX = 512.0; //512

	pDrawGUI(32584, StartX, StartY, 128.0f, 157.0f); //UI
	pDrawGUI(32583, StartX, StartY + 28.0, 128.0f, 128.0f); //MAP

	//================ Tinh Toan Time
	if ((GetTickCount() - gInterface.Data[eTimeCTC].EventTick) > 1000)
	{
		if (CTCMINI_TimeCTCMini > 0)
		{
			CTCMINI_TimeCTCMini = CTCMINI_TimeCTCMini - 1;
		}
		gInterface.Data[eTimeCTC].EventTick = GetTickCount();
	}

	int hours = CTCMINI_TimeCTCMini / 3600;
	int minutes = (CTCMINI_TimeCTCMini / 60) % 60;
	int seconds = CTCMINI_TimeCTCMini % 60;
	CustomFont.Draw(CustomFont.FontBold, StartX + 10, StartY + 10, 0x16FAC1FF, 0x0, 100, 0, 3, " %02d:%02d:%02d", hours, minutes, seconds); //
	//=================================

	//== Cong Vao 1
	if (CTCMINI_Cong[0] == 0) {
		RenderBitmap(31681, (float)(StartX - 3 + 96 / 2), (float)(294 - 5 + (255 - 130) / 2), 7.0, 7.0, 0.0, 0.0, 0.875, 0.875, 1, 1, 0.0);
	}
	//== Cong Vao 2
	if (CTCMINI_Cong[1] == 0) {
		RenderBitmap(31681, (float)(StartX - 3 + 128 / 2), (float)(294 - 5 + (255 - 130) / 2), 7.0, 7.0, 0.0, 0.0, 0.875, 0.875, 1, 1, 0.0);
	}
	//== Cong Vao 3
	if (CTCMINI_Cong[2] == 0) {
		RenderBitmap(31681, (float)(StartX - 2.5 + 161 / 2), (float)(294 - 5 + (255 - 130) / 2), 7.0, 7.0, 0.0, 0.0, 0.875, 0.875, 1, 1, 0.0);
	}

	//Tru Chua Cong 1 //31683 Thuoc Ve Guild
	if (CTCMINI_Tru[0] == 0) {
		RenderBitmap(31680, (float)(StartX - 4.5 + 96 / 2), (float)(294 - 6 + (255 - 165) / 2), 9.0, 8.0, 0.0, 0.0, 0.5625, 1.0, 1, 1, 0.0);
	}
	else  {
		RenderBitmap(31683, (float)(StartX - 4.5 + 96 / 2), (float)(294 - 6 + (255 - 165) / 2), 9.0, 8.0, 0.0, 0.0, 0.5625, 1.0, 1, 1, 0.0);
	}
	//Tru Chua Cong 2
	if (CTCMINI_Tru[1] == 0) {
		RenderBitmap(31680, (float)(StartX - 4.5 + 128 / 2), (float)(294 - 6 + (255 - 165) / 2), 9.0, 8.0, 0.0, 0.0, 0.5625, 1.0, 1, 1, 0.0);
	}
	else  {
		RenderBitmap(31683, (float)(StartX - 4.5 + 128 / 2), (float)(294 - 6 + (255 - 165) / 2), 9.0, 8.0, 0.0, 0.0, 0.5625, 1.0, 1, 1, 0.0);
	}
	//Tru Chua Cong 3
	if (CTCMINI_Tru[2] == 0) {
		RenderBitmap(31680, (float)(StartX - 4.5 + 161 / 2), (float)(294 - 6 + (255 - 165) / 2), 9.0, 8.0, 0.0, 0.0, 0.5625, 1.0, 1, 1, 0.0);
	}
	else  {
		RenderBitmap(31683, (float)(StartX - 4.5 + 161 / 2), (float)(294 - 6 + (255 - 165) / 2), 9.0, 8.0, 0.0, 0.0, 0.5625, 1.0, 1, 1, 0.0);
	}

	//pDrawGUI(32585, 640/2-(210/2), 480/2-(94/2),210,94);

	int Model;

	for (int i = 0; i < 400; i++)
	{
		Model = pGetPreviewStruct(pPreviewThis(), i);
		if (!Model) {
			continue;
		}
		if (Model
			&& *(BYTE *)(Model + 780)
			&& *(BYTE *)(Model + 800) == emPlayer
			)
		{
			if (Model != *(DWORD *)0x7BC4F04)
			{
				this->DrawGUI(ePLAYER_POINT, (float)(StartX - 1 + *(DWORD *)(Model + 172) / 2), (float)(294 - 1 + (255 - *(DWORD *)(Model + 176)) / 2));
			}
			else {
				this->DrawGUI(ePLAYER_POINT, (float)(StartX - 1 + *(DWORD *)(Model + 172) / 2), (float)(294 - 1 + (255 - *(DWORD *)(Model + 176)) / 2));
			}

		}
	}
}

//=========================================================================================================================================
//=========================================================================================================================================
void Interface::TvTEventEx(PMSG_TVTEVENT_UPD * aRecv)
{
	this->m_ScoreBlue = 0;
	this->m_ScoreBlue = aRecv->ScoreBlue;
	this->m_ScoreRed = 0;
	this->m_ScoreRed = aRecv->ScoreRed;
	this->m_KillCount = 0;
	this->m_KillCount = aRecv->KillCount;
	this->m_DieCount = 0;
	this->m_DieCount = aRecv->DieCount;
	this->m_TotalPlayer = 0;
	this->m_TotalPlayer = aRecv->TotalPlayer;
}



//=========================================================================================================================================
//=========================================================================================================================================
void Interface::TvTEvent()
{

	if (this->CheckWindow(ObjWindow::CashShop)
		|| this->CheckWindow(ObjWindow::SkillTree)
		|| this->CheckWindow(ObjWindow::ChatWindow)
		|| this->CheckWindow(ObjWindow::Store)
		|| this->CheckWindow(ObjWindow::Character)
		|| this->CheckWindow(ObjWindow::Inventory)
		|| this->CheckWindow(ObjWindow::Quest)
		|| this->CheckWindow(ObjWindow::MoveList))
	{
		return;
	}

	float MainWidth = 230.0;
	float MainHeight = 313.0;
	float StartY = 100.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	//===================================================================================================
	if (pMapNumber == 82)
	{
		this->DrawGUI(eTVTHUD, MAX_WIN_WIDTH - 210, 0);
		this->DrawGUI(eTVTHUD, MAX_WIN_WIDTH - 162, 0);
		gCentral.PrintDropBox(MAX_WIN_WIDTH - 197, 3, 40, 13, 0.0, 0);


		//================ Tinh Toan Time
		if ((GetTickCount() - gInterface.Data[eTVTHUD].EventTick) > 1000)
		{
			if (TvTEvent_TimeConLai > 0)
			{
				TvTEvent_TimeConLai = TvTEvent_TimeConLai - 1;
			}
			gInterface.Data[eTVTHUD].EventTick = GetTickCount();
		}
		int minutes = (TvTEvent_TimeConLai / 60) % 60;
		int seconds = TvTEvent_TimeConLai % 60;
		this->DrawFormat(eWhite, MAX_WIN_WIDTH - 210, 4, 70, 3, "%02d:%02d", minutes, seconds);
		//=================================

		this->DrawFormat(eRed, MAX_WIN_WIDTH - 176, 3, 70, 3, "%d", this->m_ScoreRed);
		this->DrawFormat(eBlue, MAX_WIN_WIDTH - 150, 3, 70, 3, "%d", this->m_ScoreBlue);
		this->DrawFormat(eWhite, MAX_WIN_WIDTH - 112, 3, 70, 3, "%d", this->m_KillCount);
		this->DrawFormat(eWhite, MAX_WIN_WIDTH - 82, 3, 70, 3, "%d", this->m_DieCount);
		this->DrawFormat(eWhite, MAX_WIN_WIDTH - 52, 3, 70, 3, "%d", this->m_TotalPlayer);

		SetByte(0x0059AF53 + 2, 0);
		SetByte(0x0059B248 + 2, 0);

	}
	//===================================================================================================
	if (pMapNumber == 88)
	{
		this->DrawGUI(eTVTHUD, MAX_WIN_WIDTH - 162, 0);

		//================ Tinh Toan Time
		if ((GetTickCount() - gInterface.Data[eTVTHUD].EventTick) > 1000)
		{
			if (PKEvent_TimeConLai > 0)
			{
				PKEvent_TimeConLai = PKEvent_TimeConLai - 1;
			}
			gInterface.Data[eTVTHUD].EventTick = GetTickCount();
		}

		gCentral.PrintDropBox(MAX_WIN_WIDTH - 152, 3, 47, 13, 0.0, 0);
		int minutes = (PKEvent_TimeConLai / 60) % 60;
		int seconds = PKEvent_TimeConLai % 60;
		this->DrawFormat(eWhite, MAX_WIN_WIDTH - 165, 4, 70, 3, "%02d:%02d", minutes, seconds);
		//=================================

		this->DrawFormat(eWhite, MAX_WIN_WIDTH - 112, 3, 70, 3, "%d", gObjUser.SurvivorKill);
		this->DrawFormat(eWhite, MAX_WIN_WIDTH - 82, 3, 70, 3, "%d", gObjUser.SurvivorDie);
		this->DrawFormat(eWhite, MAX_WIN_WIDTH - 52, 3, 70, 3, "%d", gObjUser.SurvivorTotal);

		SetByte(0x0059AF53 + 2, 0);
		SetByte(0x0059B248 + 2, 0);
	}
}
//===========


void Interface::GetInfoClient(PMSG_CLIENT_UPD * aRecv)
{

	this->m_DanhHieu = aRecv->DanhHieu;
	this->m_QuanHam = aRecv->QuanHam;
	this->m_TuLuyen = aRecv->TuLuyen;
	this->m_PartyNumber = aRecv->PartyNumberD;

}

#if(THANMA)
void DrawTMPoint() //<<< Draw Bang POint PK
{
	if (pMapNumber != gInterface.m_EventTMMap || gInterface.m_EventTMTimeCount == 0)
	{
		return;
	}
	//Test
	float ChieuRong = 150.0f;
	float ChieuDai = 10.0f;
	float ViTriX = ((int)pWinWidth / pWinHeightReal / 2) - (ChieuRong / 2);
	float ViTriY = 5;

	int DiemA = gInterface.m_TMScoreAcQuy;
	int DiemB = gInterface.m_TMScoreThienThan;
	float TyLeTGA = 0;

	if (gCentral.gDrawButton(ViTriX + ChieuRong + 5, 2, 75, 12, gConfig.TextTM_ThanMaChien[18]) && (GetTickCount() - gInterface.Data[eWindowNPC_ThanMaChien].EventTick) > 300)
	{
		////===BXH
		gInterface.Data[eWindowBXH_ThanMaChien].OnShow ^= 1;
	}

	EnableAlphaTest(1);
	glColor4f(1.0, 1.0, 1.0, 1.0);

	glColor4f(0.79, 0.5467, 0.1264, 0.3);
	pDrawBarForm(ViTriX - 2, ViTriY - 2, ChieuRong + 4, ChieuDai + 4, 0.0, 0); //Nen Goc
	EnableAlphaTest(1);

	glColor4f(1.0, 0.0, 0.0, 0.7);
	pDrawBarForm(ViTriX, ViTriY, ChieuRong, ChieuDai, 0.0, 0); //Ac Quy
	EnableAlphaTest(1);

	if (DiemA == 0 && DiemB == 0)
	{
		TyLeTGA = ChieuRong / 2;
	}
	else
	{
		TyLeTGA = (ChieuRong * ((DiemA * 100) / (DiemA + DiemB))) / 100;
	}

	glColor4f(0.0, 0.5, 1.0, 0.7);
	pDrawBarForm(ViTriX, ViTriY, TyLeTGA, ChieuDai, 0.0, 0); //Thien Than
	EnableAlphaTest(1);
	pGLSupremo();

	//=== TInh Time Event
	if ((GetTickCount() - gInterface.mCalcTimeEventTick) > 1000)
	{
		if (gInterface.m_EventTMTimeCount > 0)
		{
			gInterface.m_EventTMTimeCount = gInterface.m_EventTMTimeCount - 1;
		}
		gInterface.mCalcTimeEventTick = GetTickCount();
	}
	char text1[120];
	int totalseconds;
	int hours;
	int minutes;
	int seconds;
	int days;

	totalseconds = gInterface.m_EventTMTimeCount;
	hours = totalseconds / 3600;
	minutes = (totalseconds / 60) % 60;
	seconds = totalseconds % 60;

	if (hours > 23)
	{
		days = hours / 24;
		wsprintf(text1, "%d day(s)+", days);
	}
	else
	{
		wsprintf(text1, "%02d:%02d", minutes, seconds);
	}
	//==Text
	HFONT FontTextTMPoint = CreateFontA(12.5, Main_Font_Width, 0, 0, 400, 0, 0, 0, 1u, 0, 0, 3u, 0, "Arial");

	CustomFont.Draw(FontTextTMPoint, ViTriX, ViTriY + (ChieuDai / 2) - 4, 0xFFFFFFFF, 0x0, ChieuRong, 0, 3, "Time: %s", text1);
	//==Ben Trai
	CustomFont.Draw(FontTextTMPoint, ViTriX, ViTriY + (ChieuDai / 2) - 4, 0xFFFFFFFF, 0x0, (ChieuRong / 2), 0, 3, "[%s] : %d", gConfig.TextTM_ThanMaChien[16], DiemA);
	//==Ben Phai
	CustomFont.Draw(FontTextTMPoint, ViTriX + (ChieuRong / 2), ViTriY + (ChieuDai / 2) - 4, 0xFFFFFFFF, 0x0, (ChieuRong / 2), 0, 3, "[%s] : %d", gConfig.TextTM_ThanMaChien[17], DiemB);
	DeleteObject(FontTextTMPoint);
	return;
}
void DrawWindowNPCTM()
{
	if (!gInterface.Data[eWindowNPC_ThanMaChien].OnShow)
	{
		return;
	}
	float CuaSoW = 300.0;
	float CuaSoH = 250.0;

	float StartX = (MAX_WIN_WIDTH / 2) - (CuaSoW / 2);
	float StartY = 45.0;

	gCBUtil.gDrawWindowCustom(&StartX, &StartY, CuaSoW, CuaSoH, eWindowNPC_ThanMaChien, gConfig.TextTM_ThanMaChien[0]);


	if (gInterface.IsWorkZone(StartX, StartY, CuaSoW, CuaSoH)) // nếu chuột trong khu vực bảng shop thì ko click di chuyển nv
	{
		pSetCursorFocus = true;
	}
	else pSetCursorFocus = false;

	if (gCentral.gDrawButton(StartX + (CuaSoW / 2) - (115 / 2), StartY + (CuaSoH - 45), 115, 14, gConfig.TextTM_ThanMaChien[1]) && (GetTickCount() - gInterface.Data[eWindowNPC_ThanMaChien].EventTick) > 300)
	{
		//==Tham Gia Than Ma
		XULY_CGPACKET pMsg;
		pMsg.header.set(0xFF, 0x92, sizeof(pMsg));
		pMsg.ThaoTac = 1;
		DataSend((LPBYTE)& pMsg, pMsg.header.size);
		gInterface.Data[eWindowNPC_ThanMaChien].OnShow ^= 1;
		////===BXH
		//gInterface.Data[eWindowBXH_ThanMaChien].OnShow ^= 1;
	}
	HFONT FontTextTMB = CreateFontA(13, Main_Font_Width, 0, 0, 700, Main_Font_Italic, Main_Font_Underline, Main_Font_StrikeOut, 0x1, 0, 0, Main_Font_Quality, 0, "Tahoma");
	HFONT FontTextTM = CreateFontA(13, Main_Font_Width, 0, 0, 400, Main_Font_Italic, Main_Font_Underline, Main_Font_StrikeOut, 0x1, 0, 0, Main_Font_Quality, 0, "Tahoma");
	float TextStartY = StartY + 33;
	for (int ct = 0; ct < 14; ct++)
	{
		if (ct == 0 || ct == 1 || ct == 5 || ct == 11)
		{
			CustomFont.Draw(FontTextTMB, (StartX + (CuaSoW / 10)) - 15, TextStartY + (12 * ct), 0xFFDE26FF, 0x0, CuaSoW, 0, 1, gConfig.TextTM_ThanMaChien[2 + ct]); //
		}
		else if (ct == 10)
		{
			CustomFont.Draw(FontTextTMB, (StartX + (CuaSoW / 10)) - 15, TextStartY + (12 * ct), 0x00FBFFFF, 0x0, CuaSoW, 0, 1, gConfig.TextTM_ThanMaChien[2 + ct]); //
		}
		else {
			CustomFont.Draw(FontTextTM, (StartX + (CuaSoW / 10)) - 15, TextStartY + (12 * ct), 0xEBFFFBFF, 0x0, CuaSoW, 0, 1, gConfig.TextTM_ThanMaChien[2 + ct]); //
		}

	}
	DeleteObject(FontTextTMB);
	DeleteObject(FontTextTM);
}
void DrawWindowBXHTM()
{
	if (!gInterface.Data[eWindowBXH_ThanMaChien].OnShow)
	{
		return;
	}
	float CuaSoW = 250.0;
	float CuaSoH = 200.0;

	float StartX = (MAX_WIN_WIDTH / 2) - (CuaSoW / 2);
	float StartY = 45.0;

	gCentral.gDrawWindowCustom(StartX, StartY, CuaSoW, CuaSoH, eWindowBXH_ThanMaChien, gConfig.TextTM_ThanMaChien[18]);



	//====================================
	CustomFont.Draw(CustomFont.FontBold, StartX, StartY + 40, 0xFABB00FF, 0x0, CuaSoW / 4, 0, 3, "Top"); //
	CustomFont.Draw(CustomFont.FontBold, StartX + CuaSoW / 4, StartY + 40, 0xFABB00FF, 0x0, CuaSoW / 4, 0, 3, "Name"); //
	CustomFont.Draw(CustomFont.FontBold, StartX + ((CuaSoW / 4) * 2), StartY + 40, 0xFABB00FF, 0x0, CuaSoW / 4, 0, 3, "Kill"); //
	CustomFont.Draw(CustomFont.FontBold, StartX + ((CuaSoW / 4) * 3), StartY + 40, 0xFABB00FF, 0x0, CuaSoW / 4, 0, 3, "Team"); //


	DWORD ColorTextRank = 0xE0DFDCFF;

	for (int i = 0; i < gInterface.m_TMChienBXHC; i++)
	{
		if (i % 2)
		{
			ColorTextRank = 0xA3A3A3FF;
		}
		else {
			ColorTextRank = 0xE0DFDCFF;
		}
		if (i < 3) { ColorTextRank = 0xFFE240FF; }
		CustomFont.Draw(CustomFont.FontBold, StartX, StartY + 55 + (i * 12), ColorTextRank, (i < 3) ? 0xFFE2400F : 0x0, CuaSoW / 4, 0, 3, "%d", i + 1); //
		CustomFont.Draw(CustomFont.FontBold, StartX + CuaSoW / 4, StartY + 55 + (i * 12), ColorTextRank, (i < 3) ? 0xFFE2400F : 0x0, CuaSoW / 4, 0, 3, "%s", gInterface.m_ThanMaChienBXH[i].Name); //
		CustomFont.Draw(CustomFont.FontBold, StartX + ((CuaSoW / 4) * 2), StartY + 55 + (i * 12), ColorTextRank, (i < 3) ? 0xFFE2400F : 0x0, CuaSoW / 4, 0, 3, "%d", gInterface.m_ThanMaChienBXH[i].Kill); //
		CustomFont.Draw(CustomFont.FontBold, StartX + ((CuaSoW / 4) * 3), StartY + 55 + (i * 12), ColorTextRank, (i < 3) ? 0xFFE2400F : 0x0, CuaSoW / 4, 0, 3, "%s", (gInterface.m_ThanMaChienBXH[i].Team > 0) ? gConfig.TextTM_ThanMaChien[15 + gInterface.m_ThanMaChienBXH[i].Team] : "NULL"); //

	}
}
#include "Character.h"
bool CacheSkinSet = false;
int NumberSelect = -1;
void SkinModelGetInfo()
{
	XULY_CGPACKET pMsg;
	pMsg.header.set(0xD3, 0x11, sizeof(pMsg));
	pMsg.ThaoTac = gInterface.m_SkinModelData[NumberSelect].SkinIndex; //
	DataSend((LPBYTE)& pMsg, pMsg.header.size);
}
void SkinModelBuyAndReset(int SkinID)
{
	XULY_CGPACKET pMsg;
	pMsg.header.set(0xD3, 0x12, sizeof(pMsg));
	pMsg.ThaoTac = SkinID; //
	DataSend((LPBYTE)& pMsg, pMsg.header.size);
}
void DrawWindowSkinModel()
{
	if (!gInterface.Data[eWindow_SkinModel].OnShow)
	{
		if (CacheSkinSet)
		{
			NumberSelect = -1;
			character.SetChangeSkin(-1);
			CacheSkinSet = false;
		}
		return;
	}
	float CuaSoW = 350.0;
	float CuaSoH = 220.0;

	float StartX = (MAX_WIN_WIDTH / 2) - (CuaSoW / 2);
	float StartY = 45.0;


	gCBUtil.gDrawWindowCustom(&StartX, &StartY, CuaSoW, CuaSoH, eWindow_SkinModel, "Hệ Thống Thời Trang");


	character.DrawHero(StartX + (CuaSoW)-170, StartY + 10, 150, 150, oHero1);



	CustomFont.Draw(CustomFont.FontNormal, StartX + 25, StartY + 20 + (25 * 1), 0x0, 0x87CEFA, 100, 15, 0, " ");
	CustomFont.Draw(CustomFont.FontNormal, StartX + 25, StartY + 20 + (25 * 2), 0x0, 0x00F5FF, 100, 15, 0, " ");
	CustomFont.Draw(CustomFont.FontNormal, StartX + 25, StartY + 20 + (25 * 3), 0x0, 0x00FA9A, 100, 15, 0, " ");
	CustomFont.Draw(CustomFont.FontNormal, StartX + 25, StartY + 20 + (25 * 4), 0x0, 0xCAFF70, 100, 15, 0, " ");
	CustomFont.Draw(CustomFont.FontNormal, StartX + 25, StartY + 20 + (25 * 5), 0x0, 0xFF6A6A, 100, 15, 0, " ");
	CustomFont.Draw(CustomFont.FontNormal, StartX + 20, StartY + 20 + (25 * 6), 0x0, 0xed260cff, 130, 15, 0, " ");
	if (gInterface.SelectInfoSkin && NumberSelect != -1)
	{
		CustomFont.Draw(CustomFont.FontNormal, StartX + (CuaSoW)-170, StartY + 50, 0xffffffff, 0x000000C8, 150, 0, 3, "%s", gInterface.m_SkinModelInfoSelect[0].NameSkin);
		CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + 50, 0xffffffff, 0x0, 150, 0, 3, "Giá Mua (WcoinP) : %d", gInterface.m_SkinModelInfoSelect[0].Coin);
		CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + 75, 0xffffffff, 0x0, 150, 0, 3, "Sát Thương: %d", gInterface.m_SkinModelInfoSelect[0].ValueOp[0]);
		CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + 100, 0xffffffff, 0x0, 150, 0, 3, "Phòng Thủ: %d", gInterface.m_SkinModelInfoSelect[0].ValueOp[1]);
		CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + 125, 0xffffffff, 0x0, 150, 0, 3, "Máu: %d", gInterface.m_SkinModelInfoSelect[0].ValueOp[2]);
		CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + 150, 0xffffffff, 0x0, 150, 0, 3, "Mana: %d", gInterface.m_SkinModelInfoSelect[0].ValueOp[3]);
		CustomFont.Draw(CustomFont.FontNormal, StartX + 10, StartY + 175, 0xffffffff, 0x0, 150, 0, 3, "Mua Được Nhiều Trang Phục Dùng !");
	}
	else {
		CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + 50, 0xffffffff, 0x0, 150, 0, 3, "Giá Mua (WcoinP) : NULL");
		CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + 75, 0xffffffff, 0x0, 150, 0, 3, "Sát Thương: NULL");
		CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + 100, 0xffffffff, 0x0, 150, 0, 3, "Phòng Thủ: NULL");
		CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + 125, 0xffffffff, 0x0, 150, 0, 3, "Máu: NULL");
		CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + 150, 0xffffffff, 0x0, 150, 0, 3, "Mana: NULL");
		CustomFont.Draw(CustomFont.FontNormal, StartX + 10, StartY + 175, 0xffffffff, 0x0, 150, 0, 3, "Chọn trang phục để hiển thị thông tin !");

	}
	//==Next
	gInterface.DrawGUI(eWindow_SkinModelNext, StartX + (CuaSoW)-40, StartY + 80);
	if (gInterface.IsWorkZone(eWindow_SkinModelNext))
	{
		DWORD Color = eGray150;
		gInterface.DrawColoredGUI(eWindow_SkinModelNext, gInterface.Data[eWindow_SkinModelNext].X, gInterface.Data[eWindow_SkinModelNext].Y, Color);
		if (GetTickCount() - gInterface.Data[eTIME].EventTick > 300) //Click
		{
			if (GetKeyState(1) & 0x8000)
			{
				gInterface.Data[eTIME].EventTick = GetTickCount();
				if (NumberSelect < (gInterface.m_SkinModelData.size() - 1) && NumberSelect != -1)
				{
					NumberSelect += 1;
					character.SetChangeSkin(gInterface.m_SkinModelData[NumberSelect].SkinIndex + MODELSKINFIX);
					CacheSkinSet = true;
					SkinModelGetInfo();
				}


			}
		}
	}

	gInterface.DrawGUI(eWindow_SkinModelPREV, StartX + (CuaSoW)-180, StartY + 80);

	if (gInterface.IsWorkZone(eWindow_SkinModelPREV))
	{
		DWORD Color = eGray150;
		gInterface.DrawColoredGUI(eWindow_SkinModelPREV, gInterface.Data[eWindow_SkinModelPREV].X, gInterface.Data[eWindow_SkinModelPREV].Y, Color);
		if (GetTickCount() - gInterface.Data[eTIME].EventTick > 300) //Click
		{
			if (GetKeyState(1) & 0x8000)
			{
				//character.SetChangeSkin(-1); //<<<<<
				gInterface.Data[eTIME].EventTick = GetTickCount();
				if (NumberSelect > 0 && NumberSelect != -1)
				{
					NumberSelect -= 1;
					character.SetChangeSkin(gInterface.m_SkinModelData[NumberSelect].SkinIndex + MODELSKINFIX);
					CacheSkinSet = true;
					SkinModelGetInfo();

				}


			}
		}
	}
	CustomFont.Draw(CustomFont.FontNormal, StartX + (CuaSoW)-130, StartY + (CuaSoH - 45), 0xffffffff, 0x0, 75, 0, 3, "%d/%d", NumberSelect + 1, gInterface.m_SkinModelData.size());
	//===BUy
	if (gCentral.gDrawButton(StartX + (CuaSoW)-130, StartY + (CuaSoH - 37), 75, 14, "  ") && (GetTickCount() - gInterface.Data[eWindow_SkinModel].EventTick) > 300)
	{
		SkinModelBuyAndReset(gInterface.m_SkinModelData[NumberSelect].SkinIndex);
	}
	CustomFont.Draw(CustomFont.FontNormal, StartX + (CuaSoW)-130, StartY + (CuaSoH - 32), 0xffffffff, 0x0, 75, 0, 3, (CBGetStatusBuySkin(gInterface.m_SkinModelData[NumberSelect].SkinIndex)) ? "Kích Hoạt" : "Mua Trang Phục");

	//===Huy Kich Hoat
	if (gCentral.gDrawButton(StartX + (CuaSoW)-130, StartY + (CuaSoH - 19), 75, 14, "  ") && (GetTickCount() - gInterface.Data[eWindow_SkinModel].EventTick) > 300)
	{
		SkinModelBuyAndReset(-1);
	}
	CustomFont.Draw(CustomFont.FontNormal, StartX + (CuaSoW)-130, StartY + (CuaSoH - 14), 0xffffffff, 0x0, 75, 0, 3, "Huỷ Kích Hoạt");

	if (NumberSelect == -1 && ((int(__cdecl*)(int)) 0x57D9A0)(oHero1) != 400)
	{
		character.SetChangeSkin(gInterface.m_SkinModelData[0].SkinIndex + MODELSKINFIX);
		NumberSelect = 0;
		SkinModelGetInfo();

	}
}
void Interface::DrawTMAllWindows()
{
	DrawTMPoint();
	DrawWindowNPCTM();
	DrawWindowBXHTM();
	DrawWindowSkinModel();
}
#endif



void Interface::gInfoBox(float PosX, float PosY, float Width, float Height, DWORD bkcolor, float Arg5, int Arg6)
{
	float Red = (float)((bkcolor & 0xff000000) >> 24) / 255.0f;
	float Green = (float)((bkcolor & 0x00ff0000) >> 16) / 255.0f;
	float Blue = (float)((bkcolor & 0x0000ff00) >> 8) / 255.0f;
	float Alpha = (float)(bkcolor & 0x000000ff) / 255.0f;
	pSetBlend(1);
	if (bkcolor)
	{
		glColor4f(Red, Green, Blue, Alpha);
		pDrawBarForm(PosX, PosY, Width + 6.5, Height + 5, Arg5, Arg6); //central
	}
	float RightX = PosX - 2.0f;
	float LeftX = (PosX + Width) - 2.0f;
	float TopY = PosY - 2.0f;
	float DownY = (PosY + Height) - 2.0f;
	bool horizontal = true;
	bool vertical = true;
	//--
	float IniciarX = PosX - 2.0f;
	float w = 14.0f;
	//--
	float IniciarY = PosY - 2.0f;
	float H = 14.0f;

	pSetBlend(true);
	glColor3f(1.0, 1.0, 1.0);

	while (vertical || horizontal)
	{
		if (vertical)
		{
			IniciarX += 14.0f;

			if ((IniciarX + w) > LeftX)
			{
				vertical = false;
				w = LeftX - IniciarX;
			}
			pDrawGUI(31344, IniciarX, TopY, w, 14.0f); //Ngang

			pDrawGUI(31345, IniciarX, DownY, w, 14.0f); //Ngang 2
		}
		//-- abajo
		if (horizontal)
		{
			IniciarY += 14.0f;

			if ((IniciarY + H) > DownY)
			{
				horizontal = false;
				H = DownY - IniciarY;
			}

			pDrawGUI(31346, RightX, IniciarY, 14.0f, H); // Doc 1

			pDrawGUI(31347, LeftX, IniciarY, 14.0f, H); //Doc 2
		}
	}

	pDrawGUI(31340, RightX, TopY, 14.0f, 14.0f); //Goc tren ben trai

	pDrawGUI(31341, LeftX, TopY, 14.0f, 14.0f); //Goc tren ben phai

	pDrawGUI(31342, RightX, DownY, 14.0f, 14.0f);  //Goc duoi trai

	pDrawGUI(31343, LeftX, DownY, 14.0f, 14.0f);  //Goc Duoi phai

	pGLSwitch();
	EnableAlphaTest(0);
}

bool Interface::gDrawButton(float PosX, float PosY, float SizeButton, int FontSize, char* ButtonText)
{
	pSetBlend(true);
	glColor3f(1.0, 1.0, 1.0);
	//============Button
	float SizeButtonW = SizeButton;
	float SizeButtonH = (SizeButton * 20) / 100;
	float StartX = PosX;
	float StartY = PosY;
	bool mreturn = false;
	HFONT FontTextButton = CreateFontA(FontSize, Main_Font_Width, 0, 0, 700, Main_Font_Italic, Main_Font_Underline, Main_Font_StrikeOut, 0x1, 0, 0, Main_Font_Quality, 0, "Tahoma");
	//=====================Button 1
	if (pCheckMouseOver(StartX, StartY, SizeButtonW, SizeButtonH) == 1)
	{
		pSetCursorFocus = true;
		glColor3f(1.0f, 0.6742f, 0.15f);
		if (GetTickCount() - gInterface.Data[eTIME].EventTick > 50) //Click
		{
			if (GetKeyState(1) & 0x8000)
			{

				glColor3f(0.72f, 0.438f, 0.0432f);


				gInterface.Data[eTIME].EventTick = GetTickCount();
				mreturn = true;
			}
		}
	}
	else {
		glColor3f(1.0f, 1.0f, 1.0f);

	}
	RenderBitmap(31563, StartX, StartY, SizeButtonW, SizeButtonH, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);
	CustomFont.Draw(FontTextButton, StartX, StartY + (SizeButtonH / 2) - (FontSize / 2.5), 0xE6FCF7FF, 0x0, SizeButtonW, 0, 3, ButtonText); //Buoc Vao
	//=====================================
	glColor3f(1.0f, 1.0f, 1.0f); //Xoa mau
	DeleteObject(FontTextButton);
	DeleteObject(ButtonText);
	pGLSwitch();
	EnableAlphaTest(0);
	return mreturn;
}

void Interface::DrawFrame(DWORD ModelID, float X, float Y, float W, float H, float SourceX, float SourceY, float SourceW, float SourceH, float ScaleW, float ScaleH, bool ScaleUp) {
	float v1, v2;

	if (W) {
		W /= ScaleW;
		v1 = ScaleW / (SourceW / W);
	}
	else {
		v1 = ScaleW;
	}

	if (H) {
		H /= ScaleH;
		v2 = ScaleH / (SourceH / H);
	}
	else {
		v2 = ScaleH;
	}
	RenderBitmap(ModelID, X, Y, W, H, SourceX / SourceW, SourceY / SourceH, v1, v2, ScaleUp, 1, 0.0);
}


void Interface::gDrawWindowCustom(float StartX, float StartY, float CuaSoW, float CuaSoH, int eNumWindow, char* WindowName)
{
	if (!gInterface.Data[eNumWindow].OnShow)
	{
		return;
	}
	pSetCursorFocus = true; //Khoa Chuot

	if (pCheckMouseOver(StartX, StartY, CuaSoW, CuaSoH) == 1)
	{
		gInterface.LockMouseMoveClick = GetTickCount() + 500;
	}

	float ScaleW = (225 / CuaSoW) / pWinWidthReal;
	float ScaleH = (225 / CuaSoH) / pWinHeightReal;

	pSetBlend(true);
	glColor3f(1.0, 1.0, 1.0);

	gInterface.DrawFrame(31322, StartX, StartY, 225, 225, 0.0, 0.0, 270, 225, ScaleW, ScaleH); //khung goc ben trai tren

	//==== NGang Tren va Duoi
	for (int i = StartX + 10; i < (StartX + CuaSoW) - 10; i += 10)
	{
		pDrawButton(31353, i, StartY, 10.0, 64.0, 60.0, 0); //khung goc ben trai tren
		pDrawButton(31357, i, (StartY + CuaSoH) - 45.0, 10.0, 45.0, 60.0, 0); //khung goc ben trai tren
	}

	//=== Nen va thanh doc 2 trai phai
	for (int doc = StartY + 10; doc < (StartY + CuaSoH) - 10; doc += 10)
	{
		pDrawButton(31355, StartX, doc, 21.0, 10, 0, 0); //Khung giua ben trai
		pDrawButton(31356, (StartX + CuaSoW) - 21.0, doc, 21.0, 10, 0, 0); //Khung giua ben phai
	}
	pDrawButton(31353, StartX, StartY, 60.0, 64.0, 0, 0); //khung goc ben trai tren
	pDrawButton(31353, (StartX + CuaSoW) - 60.0, StartY, 60.0, 64.0, 130.0, 0); //khung goc ben phai tren

	pDrawButton(31357, StartX, (StartY + CuaSoH) - 45.0, 60.0, 45.0, 0, 0); //khung goc ben trai duoi
	pDrawButton(31357, (StartX + CuaSoW) - 60.0, (StartY + CuaSoH) - 45.0, 60.0, 45.0, 130.0, 0); //khung goc ben phai duoi
	//======Close
	int CloseX = StartX + CuaSoW - 33.0f;
	int CloseY = StartY;
	pDrawGUI(0x7EC5, CloseX, CloseY, 36.0f, 29.0f);
	if (pCheckMouseOver(CloseX, CloseY, 36, 29) == 1)
	{
		pSetCursorFocus = true;
		if (pIsKeyPress(VK_LBUTTON) && GetTickCount() - gInterface.Data[eNumWindow].EventTick > 300)
		{

			PlayBuffer(25, 0, 0);
			glColor3f(1.0f, 0.0f, 0.0f);
			gInterface.LockMouseMoveClick = GetTickCount() + 500;
			gInterface.Data[eNumWindow].OnShow ^= 1;
			gInterface.Data[eNumWindow].EventTick = GetTickCount();
			pSetCursorFocus = false; // mo khoa

		}
		pDrawColorButton(0x7EC5, CloseX, CloseY, 36, 29, 0, 0, pMakeColor(255, 204, 20, 130));
		gInterface.DrawToolTip(gObjUser.m_CursorX + 20, gObjUser.m_CursorY, "Close");
	}
	//================================================

	gInterface.DrawFormat(eGold, StartX, StartY + 12, CuaSoW, 3, WindowName);
	pGLSwitch();
	EnableAlphaTest(0);
}

void TVQ_TimeCountDown(float x, float y, float w, int MatchTime)
{
	char lpszStr[256];
	char lpszStrS[10];
	int iMinute = MatchTime / 60;
	DWORD ColorText = 0xE6FCF7FF;
	wsprintf(lpszStr, " %.2d :", iMinute);

	int iSecondTime = MatchTime - (iMinute * 60);
	if (iSecondTime >= 0)
	{
		wsprintf(lpszStrS, " %.2d", iSecondTime);
		strcat(lpszStr, lpszStrS);
	}

	if (iMinute < 5)
	{
		ColorText = 0xFF2121FF;
	}
	if (iMinute < 15)
	{
		wsprintf(lpszStrS, ": %.2d", ((int)WorldTime % 60));
		strcat(lpszStr, lpszStrS);
	}
	HFONT FontTextTime = CreateFontA(15, Main_Font_Width, 0, 0, 700, Main_Font_Italic, Main_Font_Underline, Main_Font_StrikeOut, 0x1, 0, 0, Main_Font_Quality, 0, "Arial");
	CustomFont.Draw(FontTextTime, x, y, ColorText, 0x0, w, 0, 3, lpszStr); //
	DeleteObject(FontTextTime);

}

char* TextStateGreatPK[5] = { "NULL", "Gia Nhập", "Chuẩn Bị", "Đang Diễn Ra", "Tổng Kết" };

void Interface::EventGreatPKShow()
{
	//==Show Khung Info & Time
	if (gInterface.mGreatPK_Time > 0 && gInterface.mGreatPK_State > 0 && gInterface.mGreatPK_State < 5)
	{
		if (gInterface.CheckWindow(ObjWindow::CommandWindow)
			|| gInterface.CheckWindow(ObjWindow::PetInfo)
			|| gInterface.CheckWindow(ObjWindow::Shop)
			|| gInterface.CheckWindow(ObjWindow::Inventory)
			|| gInterface.CheckWindow(ObjWindow::Store)
			|| gInterface.CheckWindow(ObjWindow::OtherStore)
			|| gInterface.CheckWindow(ObjWindow::Character)
			|| gInterface.CheckWindow(ObjWindow::MuHelper))
		{
			goto NextInfo;
		}

#if WIDE
		int JCResto = pWinWidth / pWinHeightReal / 2 - 320; // toa do wide + them
#else
		int JCResto = 0;
#endif

		float InfoW = 100;
		float InfoH = 40;
		float InfoX = MAX_WIN_WIDTH - (InfoW + 20) + 10 + JCResto;
		float InfoY = MAX_WIN_HEIGHT - (InfoH + 60);


		if (pMapNumber == 85)
		{
			gInterface.gInfoBox(InfoX, InfoY, InfoW, InfoH, 0x00000096, 0, 0);

			CustomFont.Draw(CustomFont.FontBold, InfoX, InfoY + 3, 0xE6FCF7FF, 0x0, InfoW + 7, 0, 3, "%s", TextStateGreatPK[gInterface.mGreatPK_State]);
			CustomFont.Draw(CustomFont.FontBold, InfoX, InfoY + 13, 0xE6FCF7FF, 0xFFE50064, InfoW + 7, 0, 3, "Top: %d [%d Điểm]", gInterface.mGreatPK_Rank, gInterface.mGreatPK_Score);
			CustomFont.Draw(CustomFont.FontBold, InfoX, (InfoY + InfoH) - 17, 0xE6FCF7FF, 0x70707064, InfoW + 7, 0, 3, "Thời Gian Còn Lại");
			TVQ_TimeCountDown(InfoX, (InfoY + InfoH) - 7, InfoW + 10, gInterface.mGreatPK_Time);

			if (gInterface.gDrawButton(InfoX, InfoY - 25, InfoW + 8, 13, "Bảng Xếp Hạng") && (GetTickCount() - gInterface.Data[eFlag10].EventTick) > 1000)
			{
				pSetCursorFocus = true;
				if (gInterface.Data[eWindowEventGreatPK].OnShow)
				{
					gInterface.Data[eWindowEventGreatPK].OnShow = 0;
				}
				else {
					//==Tham Gia
					XULY_CGPACKET pMsg;
					pMsg.header.set(0xD3, 0x34, sizeof(pMsg));
					pMsg.ThaoTac = 1;
					DataSend((LPBYTE)& pMsg, pMsg.header.size);
					gInterface.Data[eFlag10].EventTick = GetTickCount();
				}
			}

		}
	}

NextInfo:

	if (!gInterface.Data[eWindowEventGreatPK].OnShow)
	{
		return;
	}

	float CuaSoW = 175;
	float CuaSoH = 250;

	float StartX = (MAX_WIN_WIDTH / 2) - (CuaSoW / 2);
	float StartY = 45.0;
	gInterface.gDrawWindowCustom(StartX, StartY, CuaSoW, CuaSoH, eWindowEventGreatPK, "Xếp Hạng");

	float BXHPosX = StartX + 5;
	float BXHPosY = StartY;
	float BXHPosW = CuaSoW - 10;
	//===Info BXH
	CustomFont.Draw(CustomFont.FontBold, BXHPosX, BXHPosY + 40, 0xFABB00FF, 0x0, BXHPosW / 3, 0, 3, "Top"); //
	CustomFont.Draw(CustomFont.FontBold, BXHPosX + BXHPosW / 3, BXHPosY + 40, 0xFABB00FF, 0x0, BXHPosW / 3, 0, 3, "Name"); //
	CustomFont.Draw(CustomFont.FontBold, BXHPosX + ((BXHPosW / 3) * 2), BXHPosY + 40, 0xFABB00FF, 0x0, BXHPosW / 3, 0, 3, "Score"); //
	DWORD ColorTextRank = 0xE0DFDCFF;

	for (int i = 0; i < gInterface.mGreatPKBXHData.size(); i++)
	{
		if (i % 2)
		{
			ColorTextRank = 0xA3A3A3FF;
		}
		else {
			ColorTextRank = 0xE0DFDCFF;
		}
		if (i < 3) { ColorTextRank = 0xFFE240FF; }
		CustomFont.Draw(CustomFont.FontBold, BXHPosX, BXHPosY + 55 + (i * 12), ColorTextRank, (i < 3) ? 0xFFE2400F : 0x0, BXHPosW / 3, 0, 3, "%d", gInterface.mGreatPKBXHData[i].Rank); //
		CustomFont.Draw(CustomFont.FontBold, BXHPosX + BXHPosW / 3, BXHPosY + 55 + (i * 12), ColorTextRank, (i < 3) ? 0xFFE2400F : 0x0, BXHPosW / 3, 0, 3, gInterface.mGreatPKBXHData[i].Name); //
		CustomFont.Draw(CustomFont.FontBold, BXHPosX + ((BXHPosW / 3) * 2), BXHPosY + 55 + (i * 12), ColorTextRank, (i < 3) ? 0xFFE2400F : 0x0, BXHPosW / 3, 0, 3, "%d", gInterface.mGreatPKBXHData[i].Score); //
	}
}

#if(OFFLINE_MODE_NEW)
void Interface::DrawOffExpWindow()
{
	if (!this->Data[eOFFEXP_MAIN].OnShow)
	{
		return;
	}
	// ----
	DWORD ItemNameColor = eWhite;
	float MainWidth = 230.0;
	float MainHeight = 313.0;
	float StartY = 50.0; // 100.0
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);
	// ----
	//---------------------------------------------------------------------------------------//
	if (this->IsWorkZone(eOFFEXP_MAIN)) // nếu chuột trong khu vực bảng shop thì ko click di chuyển nv
	{
		pSetCursorFocus = true;
	}
	else pSetCursorFocus = false;
	//---------------------------------------------------------------------------------------//
	//pDrawMessage("", 0); // Không Cho Hiện Thông Báo Trên Màn Hình
	//---------------------------------------------------------------------------------------//
	this->DrawGUI(eOFFEXP_MAIN, StartX, StartY + 20);

	//gCentral.PrintDropBox(StartX - 15, gInterface.Data[eOFFEXP_MAIN].Y + 20, 260, 280, 0.0, 150);
	//gCItemSetOption.ItemTooltipS15(StartX - 15, gInterface.Data[eOFFEXP_MAIN].Y + 30, 260, 260, 0.0, 150);

	gCBUtil.gDrawWindowCustom(&StartX, &StartY, MainWidth, MainHeight, eOFFEXP_MAIN, "Hệ Thống Treo OFF");


	//this->DrawGUI(eOFFEXP_TITLE, StartX, StartY);
	//StartY = this->DrawRepeatGUI(eOFFEXP_FRAME, StartX, StartY + 67.0, 13);
	//this->DrawGUI(eOFFEXP_FOOTER, StartX, StartY);

	this->DrawGUI(eOFFEXP_CLOSE, StartX + 216, this->Data[eOFFEXP_MAIN].Y + 28);
	// ----
	if (this->IsWorkZone(eOFFEXP_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eOFFEXP_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eOFFEXP_CLOSE, this->Data[eOFFEXP_CLOSE].X, this->Data[eOFFEXP_CLOSE].Y, Color);
		this->DrawToolTip(this->Data[eOFFEXP_CLOSE].X + 5, this->Data[eOFFEXP_CLOSE].Y + 25, "Close");
	}
	// ----

	this->DrawFormat(eGold, StartX + 10, this->Data[eOFFEXP_MAIN].Y + 5, 210, 3, "Treo Máy Offline"); // Treo Máy Offline

	this->DrawFormat(eWhite, StartX + 10, this->Data[eOFFEXP_MAIN].Y + 35, 210, 3, "Chào[%s]!Bạn đang bận việc và muốn treo máy ?", gObjUser.lpPlayer->Name); // "Chào [%s]! Bạn đang bận việc và muốn treo máy?"

	this->DrawFormat(eWhite, StartX + 10, this->Data[eOFFEXP_MAIN].Y + 55, 210, 3, "Ở chế độ này, bạn có thể cày level khi máy tính của bạn đã tắt."); // "Ở chế độ này, bạn có thể cày level khi máy tính của bạn đã tắt."

	pDrawGUI(0x7B5E, StartX + 30, this->Data[eOFFEXP_MAIN].Y + 78, 82.0, 2.0); // Äåëèòåëü ìåëêèé 1
	pDrawGUI(0x7B5E, StartX + 30 + 82, this->Data[eOFFEXP_MAIN].Y + 78, 82.0, 2.0); // Äåëèòåëü ìåëêèé 2


	int ObjectIDs[7] =
	{
		eOFFEXP_CHECKBOX_BUFF,
		0,
		eOFFEXP_CHECKBOX_PICK_ZEN,
		eOFFEXP_CHECKBOX_PICK_JEWELS,
		eOFFEXP_CHECKBOX_PICK_EXC,
		eOFFEXP_CHECKBOX_PICK_ANC,
		eOFFEXP_CHECKBOX_SELECTED_HELPER
	};

	char szText[7][64] =
	{
		"Tự động Buff",
		"NULL",
		"Nhặt Zen",
		"Nhặt Ngọc",
		"Nhặt Item Hoàn hảo",
		"Nhặt Items Thần",
		"Nhặt Items có trong danh sách Auto train"
	};

	for (int i = 0; i<8; i++)
	{
		pDrawGUI(0x7B5E, StartX + 30, this->Data[eOFFEXP_MAIN].Y + 114 + (20 * i), 82.0, 2.0); // Äåëèòåëü ìåëêèé 1
		pDrawGUI(0x7B5E, StartX + 30 + 82, this->Data[eOFFEXP_MAIN].Y + 114 + (20 * i), 82.0, 2.0); // Äåëèòåëü ìåëêèé 2

		if (i != 1 && i != 7)
		{
			int btn = 1;
			if (i == 0 && gOfflineMode.DrawBuff == 0)
			{
				btn = 0;
			}

			if ((i >= 2 && i <= 6) && gOfflineMode.DrawPick == 0)
			{
				btn = 0;
			}

			this->DrawGUI(eOFFEXP_POINT, StartX + 30, this->Data[eOFFEXP_MAIN].Y + 120 + (20 * i)); //
			this->DrawFormat(eWhite, StartX + 45, this->Data[eOFFEXP_MAIN].Y + 121 + (20 * i), 200, 1, szText[i]);
			if (btn == 1)
			{
				this->DrawButton(ObjectIDs[i], ButtonX + 117, this->Data[eOFFEXP_MAIN].Y + 117 + (20 * i), 0, 15 * gOfflineMode.GetCheckBox(i));
			}
			else
			{
				//				this->DrawColoredButton(ObjectIDs[i], ButtonX + 117, this->Data[eOFFEXP_MAIN].Y + 117 + (20 * i), 0, 15 * gOfflineMode.GetCheckBox(i), eGray150);
			}

		}
	}

	this->DrawFormat(eGold, StartX + 10, this->Data[eOFFEXP_MAIN].Y + 141, 210, 3, "Tùy chọn nhặt Item chỉ sử dụng cho tài khoản Vip."); // "Tùy chọn nhặt Item chỉ sử dụng cho tài khoản Vip."

	this->DrawGUI(eOFFEXP_BTN_OK, ButtonX - 3, this->Data[eOFFEXP_MAIN].Y + 260);
	this->DrawFormat(eWhite, StartX + 5, this->Data[eOFFEXP_MAIN].Y + 270, 210, 3, "Bắt Đầu"); // "Bắt Đầu"

	if (IsWorkZone(eOFFEXP_BTN_OK))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eOFFEXP_BTN_OK].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eOFFEXP_BTN_OK, this->Data[eOFFEXP_BTN_OK].X, this->Data[eOFFEXP_BTN_OK].Y, Color);
	}

	gOfflineMode.DrawSkill(0, StartX);
	gOfflineMode.DrawSkill(1, StartX);
	gOfflineMode.DrawSkill(2, StartX);

	for (int i = 0; i <= 2; i++)
	{
		if (gOfflineMode.SkillsIndex[i] == 0)
		{
			continue;
		}

		if (this->IsWorkZone(StartX + (50 * (i + 1)), this->Data[eOFFEXP_MAIN].Y + 83, StartX + (50 * (i + 1)) + 20, this->Data[eOFFEXP_MAIN].Y + 83 + 28))
		{
			this->DrawToolTipEx(eWhite, StartX + (50 * (i + 1)) - 14, this->Data[eOFFEXP_MAIN].Y + 123, 50, 30, 3, gOfflineMode.SkillsName[i]);
		}
	}

	//if ((gObjUser.lpPlayer->Class & 7) == DarkWizard)
	//{
	//	pDrawGUI(0x1000, StartX + 50, this->Data[eOFFEXP_MAIN].Y + 84, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1001, StartX + 100, this->Data[eOFFEXP_MAIN].Y + 83, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1002, StartX + 150, this->Data[eOFFEXP_MAIN].Y + 83, 20, 27); // Äåëèòåëü ìåëêèé 1
	//}
	//else if ((gObjUser.lpPlayer->Class & 7) == DarkKnight)
	//{
	//	pDrawGUI(0x1003, StartX + 50, this->Data[eOFFEXP_MAIN].Y + 84, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1004, StartX + 100, this->Data[eOFFEXP_MAIN].Y + 83, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1005, StartX + 150, this->Data[eOFFEXP_MAIN].Y + 83, 20, 27); // Äåëèòåëü ìåëêèé 1
	//}
	//else if ((gObjUser.lpPlayer->Class & 7) == Elf)
	//{
	//	pDrawGUI(0x1006, StartX + 50, this->Data[eOFFEXP_MAIN].Y + 84, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1007, StartX + 100, this->Data[eOFFEXP_MAIN].Y + 83, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1008, StartX + 150, this->Data[eOFFEXP_MAIN].Y + 84, 20, 27); // Äåëèòåëü ìåëêèé 1
	//}
	//else if ((gObjUser.lpPlayer->Class & 7) == MagicGladiator)
	//{
	//	pDrawGUI(0x1009, StartX + 50, this->Data[eOFFEXP_MAIN].Y + 84, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1010, StartX + 100, this->Data[eOFFEXP_MAIN].Y + 83, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1011, StartX + 150, this->Data[eOFFEXP_MAIN].Y + 84, 20, 27); // Äåëèòåëü ìåëêèé 1
	//}
	//else if ((gObjUser.lpPlayer->Class & 7) == DarkLord)
	//{
	//	pDrawGUI(0x1012, StartX + 50, this->Data[eOFFEXP_MAIN].Y + 84, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1013, StartX + 100, this->Data[eOFFEXP_MAIN].Y + 83, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1014, StartX + 150, this->Data[eOFFEXP_MAIN].Y + 84, 20, 27); // Äåëèòåëü ìåëêèé 1
	//}
	//else if ((gObjUser.lpPlayer->Class & 7) == Summoner)
	//{
	//	pDrawGUI(0x1015, StartX + 50, this->Data[eOFFEXP_MAIN].Y + 84, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1016, StartX + 100, this->Data[eOFFEXP_MAIN].Y + 83, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1017, StartX + 150, this->Data[eOFFEXP_MAIN].Y + 83, 20, 27); // Äåëèòåëü ìåëêèé 1
	//}
	//else if ((gObjUser.lpPlayer->Class & 7) == Monk)
	//{
	//	pDrawGUI(0x1018, StartX + 50, this->Data[eOFFEXP_MAIN].Y + 84, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1019, StartX + 100, this->Data[eOFFEXP_MAIN].Y + 84, 20, 27); // Äåëèòåëü ìåëêèé 1
	//}

}
// ----------------------------------------------------------------------------------------------
bool Interface::EventOffExpWindow_Main(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();

	if (!this->Data[eOFFEXP_MAIN].OnShow)
	{
		return false;
	}

	if (IsWorkZone(eOFFEXP_CLOSE))
	{
		DWORD Delay = (CurrentTick - this->Data[eOFFEXP_CLOSE].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eOFFEXP_CLOSE].OnClick = true;
			return true;
		}
		// ----
		this->Data[eOFFEXP_CLOSE].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		// ----
		this->Data[eOFFEXP_CLOSE].EventTick = GetTickCount();

		this->SwitchOffExpWindoState();
		// ----
		return false;
	}

	if (IsWorkZone(eOFFEXP_BTN_OK))
	{
		DWORD Delay = (CurrentTick - this->Data[eOFFEXP_BTN_OK].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eOFFEXP_BTN_OK].OnClick = true;
			return true;
		}
		// ----
		this->Data[eOFFEXP_BTN_OK].OnClick = false;;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		// ----
		this->Data[eOFFEXP_BTN_OK].EventTick = GetTickCount();
		gOfflineMode.SendOffExpData();
		this->SwitchOffExpWindoState();
	}

	int ObjectIDs[7] =
	{
		eOFFEXP_CHECKBOX_BUFF,
		0,
		eOFFEXP_CHECKBOX_PICK_ZEN,
		eOFFEXP_CHECKBOX_PICK_JEWELS,
		eOFFEXP_CHECKBOX_PICK_EXC,
		eOFFEXP_CHECKBOX_PICK_ANC,
		eOFFEXP_CHECKBOX_SELECTED_HELPER
	};

	for (int i = 0; i<7; i++)
	{
		if (i == 1) continue;

		if (i == 0 && gOfflineMode.DrawBuff == 0)
		{
			continue;
		}

		if ((i >= 2 && i <= 6) && gOfflineMode.DrawPick == 0)
		{
			continue;
		}

		if (this->IsWorkZone(ObjectIDs[i]))
		{
			DWORD Delay = (CurrentTick - this->Data[ObjectIDs[i]].EventTick);
			// ----
			if (!this->Data[eOFFEXP_MAIN].OnShow)
			{
				return false;
			}
			// ----
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[ObjectIDs[i]].OnClick = true;
				return false;
			}
			// ----
			this->Data[ObjectIDs[i]].OnClick = false;
			// ----
			if (Delay < 200)
			{
				return false;
			}
			// ----
			this->Data[ObjectIDs[i]].EventTick = GetTickCount();
			gOfflineMode.ChangeCheckBox(i);
		}
	}

	for (int i = 0; i <= 2; i++)
	{
		if (gOfflineMode.SkillsIndex[i] == 0)
		{
			continue;
		}

		float X = gOfflineMode.GetSkillX(i);
		float Y = gOfflineMode.GetSkillY(i);

		if (this->IsWorkZone(X, Y, X + 20, Y + 28))
		{
			DWORD Delay = (CurrentTick - gOfflineMode.m_SkillCoord[i].EventTick);

			if (Event == WM_LBUTTONDOWN)
			{
				continue;
			}
			// ----
			if (Delay < 500)
			{
				continue;
			}

			gOfflineMode.m_SkillCoord[i].EventTick = GetTickCount();

			if (gOfflineMode.SkillsData[i] == 0)
			{
				return false;
			}

			gOfflineMode.ClearSelectedSkill();
			gOfflineMode.SelectedSkill[i] = true;
		}
	}
	return false;
}
#endif

#if OLD_PKNOTICE
#define		RBG_MAX_KILL_LOG	5
void Interface::KillRecv(BYTE* lpMsg)
{
	PSWMSG_KILL_RECV* Data = (PSWMSG_KILL_RECV*)lpMsg;

	INFO_KILLS kill = { 0 };

	memcpy(kill.Player, Data->Player, sizeof(Data->Player));
	memcpy(kill.Target, Data->Target, sizeof(Data->Target));
	gInterface.mKillON = Data->ON;
	if (gInterface.m_KillLog.size() >= RBG_MAX_KILL_LOG)
	{
		gInterface.m_KillLog.erase(gInterface.m_KillLog.begin());
	}
	gInterface.m_KillLog.push_back(kill);
}





void Interface::DrawKill()
{
	if (gInterface.mKillON != 1)
	{
		return;
	}
	if (this->m_KillInterface + 30000 <= GetTickCount())
	{
		if (this->m_KillLog.size())
		{
			this->m_KillLog.erase(this->m_KillLog.begin());
		}
		this->m_KillInterface = GetTickCount();
	}

	int Dat_Y = 0;

	if (gInterface.m_PartyNumber > 1)
	{
		Dat_Y = 10 + (25 * gInterface.m_PartyNumber);
	}


	for (int i = 0; i < this->m_KillLog.size(); i++)
	{

		pDrawColorButton(0x7980, MAX_WIN_WIDTH - 155, Dat_Y + 15 + 13 * i, 155, 10, NULL, NULL, Color4f(0, 0, 0, 100));
		CustomFont.Draw(CustomFont.FontBold, MAX_WIN_WIDTH - 155, Dat_Y + 15 + 13 * i, 0xFFDD00FF, 0x0, 155.0, 0, 3, "[%s] Đã Hạ Gục [%s]", this->m_KillLog[i].Player, this->m_KillLog[i].Target);

	}
}
#endif






#include "SEASON3B.h"
float fAlpha = 0.1f;
void BRenderTimeCountDown(float x, float y, float w, int MatchTime)
{
	char lpszStr[256];
	char lpszStrS[10];
	int iMinute = MatchTime / 60;
	DWORD ColorText = 0xE6FCF7FF;
	wsprintf(lpszStr, " %.2d :", iMinute);

	int iSecondTime = MatchTime - (iMinute * 60);
	if (iSecondTime >= 0)
	{
		wsprintf(lpszStrS, " %.2d", iSecondTime);
		strcat(lpszStr, lpszStrS);
	}

	if (iMinute < 5)
	{
		ColorText = 0xFF2121FF;
	}
	if (iMinute < 15)
	{
		wsprintf(lpszStrS, ": %.2d", ((int)WorldTime % 60));
		strcat(lpszStr, lpszStrS);
	}
	HFONT FontTextTime = CreateFontA(14, Main_Font_Width, 0, 0, 700, Main_Font_Italic, Main_Font_Underline, Main_Font_StrikeOut, 0x1, 0, 0, Main_Font_Quality, 0, "Tahoma");
	CustomFont.Draw(FontTextTime, x, y, 0xE6FCF7FF, 0x0, w, 0, 3, lpszStr); //Buoc Vao
	DeleteObject(FontTextTime);

}


char* TextState[9] = { "NULL", "Gia Nhập", "Chuẩn Bị", "Vòng Loại", "Chờ Bán Kết", "Bán Kết", "Chờ Chung Kết", "Chung Kết", "Tổng Kết" };
void Interface::EventDauTruongShow()
{
	//==Show Khung Info & Time
	if (gInterface.mDauTruong_Time > 0 && gInterface.mDauTruong_State > 0 && gInterface.mDauTruong_State < 9)
	{

		if (gInterface.CheckWindow(ObjWindow::CommandWindow)
			|| gInterface.CheckWindow(ObjWindow::PetInfo)
			|| gInterface.CheckWindow(ObjWindow::Shop)
			|| gInterface.CheckWindow(ObjWindow::Inventory)
			|| gInterface.CheckWindow(ObjWindow::Store)
			|| gInterface.CheckWindow(ObjWindow::OtherStore)
			|| gInterface.CheckWindow(ObjWindow::Character)
			|| gInterface.CheckWindow(ObjWindow::MuHelper))
		{
			goto NextInfo;
		}

		float InfoW = 100;
		float InfoH = 40;
		float InfoX = MAX_WIN_WIDTH - (InfoW + 20) + 10;
		float InfoY = MAX_WIN_HEIGHT - (InfoH + 60);

		if (pMapNumber == 102)
		{
			gInterface.gInfoBox(InfoX, InfoY, InfoW, InfoH, 0x00000096, 0, 0);
			CustomFont.Draw(CustomFont.FontBold, InfoX, InfoY + 3, 0xE6FCF7FF, 0x0, InfoW + 7, 0, 3, "%s", TextState[gInterface.mDauTruong_State]);
			CustomFont.Draw(CustomFont.FontBold, InfoX, InfoY + 13, 0xE6FCF7FF, 0xFFE50064, InfoW + 7, 0, 3, "Top: %d [%d Điểm]", gInterface.mDauTruong_Rank, gInterface.mDauTruong_Score);
			CustomFont.Draw(CustomFont.FontBold, InfoX, (InfoY + InfoH) - 17, 0xE6FCF7FF, 0x70707064, InfoW + 7, 0, 3, "Thời Gian Còn Lại");
			BRenderTimeCountDown(InfoX, (InfoY + InfoH) - 7, InfoW + 10, gInterface.mDauTruong_Time);

			if (gInterface.gDrawButton(InfoX, InfoY - 25, InfoW + 8, 14, "Bảng Xếp Hạng") && (GetTickCount() - gInterface.Data[eFlag10].EventTick) > 1000)
			{
				if (gInterface.Data[eWindowEventDauTruong].OnShow)
				{
					gInterface.Data[eWindowEventDauTruong].OnShow = 0;
				}
				else {
					//==Tham Gia
					XULY_CGPACKET pMsg;
					pMsg.header.set(0xD3, 0x33, sizeof(pMsg));
					pMsg.ThaoTac = 1;
					DataSend((LPBYTE)& pMsg, pMsg.header.size);
					gInterface.Data[eFlag10].EventTick = GetTickCount();
				}
			}
		}
	}
NextInfo:

	if (!gInterface.Data[eWindowEventDauTruong].OnShow)
	{
		return;
	}
	//gInterface.mDauTruong_State = 4;
	if (gInterface.mDauTruong_State >= 4) //BXH Tranh Dau
	{
		float CuaSoW = 315;
		float CuaSoH = 270;

		float StartX = (MAX_WIN_WIDTH / 2) - (CuaSoW / 2);
		float StartY = 45.0;
		gInterface.gDrawWindowCustom(StartX, StartY, CuaSoW, CuaSoH, eWindowEventDauTruong, "Xếp Cặp Đấu Loại");

		float KhungCapStartX = StartX + 15;
		float KhungCapStartY = StartY + 45;
		float KhungCapDauW = 70;
		float KhungCapDauH = 50;
		//1 vs 3 , 2 vs 4
		HFONT FONTTEXT_VS = CreateFontA(15, Main_Font_Width, 0, 0, 700, 0, 0, 0, 1u, 0, 0, 3u, 0, "Arial");
		gInterface.gInfoBox(KhungCapStartX, KhungCapStartY, KhungCapDauW, KhungCapDauH, 0x00000096, 0, 0); //1vs3
		gInterface.gInfoBox(KhungCapStartX, KhungCapStartY + 140, KhungCapDauW, KhungCapDauH, 0x00000096, 0, 0); //2vs4
		gInterface.gInfoBox(KhungCapStartX + 80, KhungCapStartY + 70, KhungCapDauW, KhungCapDauH, 0x00000096, 0, 0); //1vs2
		gInterface.gInfoBox(KhungCapStartX + 200, KhungCapStartY + 70 + 15, KhungCapDauW, (KhungCapDauH / 2), 0x00000096, 0, 0); //Top 1

		EnableAlphaTest(1);
		glColor4f(1.0, 1.0, 1.0, 1.0);
		RenderBitmap(31542, KhungCapStartX + 80, KhungCapStartY + 25, 42, 31, 0.f, 0.f, 0.6528125, 0.98, true, true, 0); //>>> 1vs3
		RenderBitmap(31542, KhungCapStartX + 80, KhungCapStartY + 140, 42, 31, 0.f, 0.98, 0.6528125, -0.98, true, true, 0); //>>> 2vs4
		RenderBitmap(31538, KhungCapStartX + 165, KhungCapStartY + 95, 28, 7, 0.f, 0.f, 0.88, 0.88, true, true, 0); //>>> 1
		pGLSwitch();
		EnableAlphaTest(0);

		CustomFont.Draw(CustomFont.FontBold, KhungCapStartX, KhungCapStartY + (KhungCapDauH / 2) - 1, 0x0, 0x7D787064, KhungCapDauW + 8, 0, 3, "      "); // ==== 1vs3
		CustomFont.Draw(FONTTEXT_VS, KhungCapStartX, KhungCapStartY + (KhungCapDauH / 2) - 2, 0xFFC45EFF, 0x0, KhungCapDauW + 8, 0, 3, "VS"); // ==== 1vs  3

		CustomFont.Draw(CustomFont.FontBold, KhungCapStartX, KhungCapStartY + 6, 0xE6FCF7FF, 0x0, KhungCapDauW + 8, 0, 3, (gInterface.mDauTruongBXHData.size() < 1) ? "NULL" : gInterface.mDauTruongBXHData[0].Name); // ==== Name 1
		CustomFont.Draw(CustomFont.FontBold, KhungCapStartX, KhungCapStartY + ((KhungCapDauH / 2) - 2) + 15, 0xE6FCF7FF, 0x0, KhungCapDauW + 8, 0, 3, (gInterface.mDauTruongBXHData.size() < 3) ? "NULL" : gInterface.mDauTruongBXHData[2].Name); // ==== Name 3

		CustomFont.Draw(CustomFont.FontBold, KhungCapStartX, KhungCapStartY + 140 + (KhungCapDauH / 2) - 1, 0x0, 0x7D787064, KhungCapDauW + 8, 0, 3, "      "); // ==== 2vs4
		CustomFont.Draw(FONTTEXT_VS, KhungCapStartX, KhungCapStartY + 140 + (KhungCapDauH / 2) - 2, 0xFFC45EFF, 0x0, KhungCapDauW + 8, 0, 3, "VS"); // ==== 2vs  4

		CustomFont.Draw(CustomFont.FontBold, KhungCapStartX, KhungCapStartY + 140 + 6, 0xE6FCF7FF, 0x0, KhungCapDauW + 8, 0, 3, (gInterface.mDauTruongBXHData.size() < 2) ? "NULL" : gInterface.mDauTruongBXHData[1].Name); // ==== Name 2
		CustomFont.Draw(CustomFont.FontBold, KhungCapStartX, KhungCapStartY + 140 + ((KhungCapDauH / 2) - 2) + 15, 0xE6FCF7FF, 0x0, KhungCapDauW + 8, 0, 3, (gInterface.mDauTruongBXHData.size() < 4) ? "NULL" : gInterface.mDauTruongBXHData[3].Name); // ==== Name 4


		CustomFont.Draw(CustomFont.FontBold, KhungCapStartX + 80, KhungCapStartY + 70 + (KhungCapDauH / 2) - 1, 0x0, 0x7D787064, KhungCapDauW + 8, 0, 3, "      "); // ==== 1vs2
		CustomFont.Draw(FONTTEXT_VS, KhungCapStartX + 80, KhungCapStartY + 70 + (KhungCapDauH / 2) - 2, 0xFFC45EFF, 0x0, KhungCapDauW + 8, 0, 3, "VS"); // ==== 1vs  2
		if (gInterface.mDauTruong_State > 5)
		{
			CustomFont.Draw(CustomFont.FontBold, KhungCapStartX + 80, KhungCapStartY + 70 + 6, 0xE6FCF7FF, 0x0, KhungCapDauW + 8, 0, 3, (gInterface.mDauTruongBXHData.size() < 1) ? "NULL" : gInterface.mDauTruongBXHData[0].Name); // ==== Name 1
			CustomFont.Draw(CustomFont.FontBold, KhungCapStartX + 80, KhungCapStartY + 70 + ((KhungCapDauH / 2) - 2) + 15, 0xE6FCF7FF, 0x0, KhungCapDauW + 8, 0, 3, (gInterface.mDauTruongBXHData.size() < 2) ? "NULL" : gInterface.mDauTruongBXHData[1].Name); // ==== Name 2
		}

		CustomFont.Draw(CustomFont.FontBold, KhungCapStartX + 200, KhungCapStartY + 70 + 14, 0x0, 0x7D787064, KhungCapDauW + 8, 0, 3, "      "); // ==== 1
		CustomFont.Draw(FONTTEXT_VS, KhungCapStartX + 200, KhungCapStartY + 70 + 14, 0xFFC45EFF, 0x0, KhungCapDauW + 8, 0, 3, "TOP 1"); // ==== 1
		if (gInterface.mDauTruong_State > 7)
		{
			CustomFont.Draw(CustomFont.FontBold, KhungCapStartX + 200, KhungCapStartY + 70 + 30, 0xE6FCF7FF, 0x0, KhungCapDauW + 8, 0, 3, (gInterface.mDauTruongBXHData.size() < 1) ? "NULL" : gInterface.mDauTruongBXHData[0].Name); // ==== Name 1
		}
		DeleteObject(FONTTEXT_VS);
	}
	else
	{
		float CuaSoW = 175;
		float CuaSoH = 200;

		float StartX = (MAX_WIN_WIDTH / 2) - (CuaSoW / 2);
		float StartY = 45.0;
		gInterface.gDrawWindowCustom(StartX, StartY, CuaSoW, CuaSoH, eWindowEventDauTruong, "Xếp Hạng Đấu Trường");

		//gInterfacegInfoBox(StartX + 7, StartY + 30, CuaSoW - 23, 110, 0x00000096, 0, 0);

		float BXHPosX = StartX + 5;
		float BXHPosY = StartY;
		float BXHPosW = CuaSoW - 10;
		//===Info BXH
		CustomFont.Draw(CustomFont.FontBold, BXHPosX, BXHPosY + 40, 0xFABB00FF, 0x0, BXHPosW / 3, 0, 3, "Top"); //
		CustomFont.Draw(CustomFont.FontBold, BXHPosX + BXHPosW / 3, BXHPosY + 40, 0xFABB00FF, 0x0, BXHPosW / 3, 0, 3, "Name"); //
		CustomFont.Draw(CustomFont.FontBold, BXHPosX + ((BXHPosW / 3) * 2), BXHPosY + 40, 0xFABB00FF, 0x0, BXHPosW / 3, 0, 3, "Score"); //
		DWORD ColorTextRank = 0xE0DFDCFF;

		for (int i = 0; i < gInterface.mDauTruongBXHData.size(); i++)
		{
			if (i % 2)
			{
				ColorTextRank = 0xA3A3A3FF;
			}
			else {
				ColorTextRank = 0xE0DFDCFF;
			}
			if (i < 3) { ColorTextRank = 0xFFE240FF; }
			CustomFont.Draw(CustomFont.FontBold, BXHPosX, BXHPosY + 55 + (i * 12), ColorTextRank, (i < 3) ? 0xFFE2400F : 0x0, BXHPosW / 3, 0, 3, "%d", gInterface.mDauTruongBXHData[i].Rank); //
			CustomFont.Draw(CustomFont.FontBold, BXHPosX + BXHPosW / 3, BXHPosY + 55 + (i * 12), ColorTextRank, (i < 3) ? 0xFFE2400F : 0x0, BXHPosW / 3, 0, 3, gInterface.mDauTruongBXHData[i].Name); //
			CustomFont.Draw(CustomFont.FontBold, BXHPosX + ((BXHPosW / 3) * 2), BXHPosY + 55 + (i * 12), ColorTextRank, (i < 3) ? 0xFFE2400F : 0x0, BXHPosW / 3, 0, 3, "%d", gInterface.mDauTruongBXHData[i].Score); //

		}
	}

}



#if(EventSinhTon)
void DrawBattleRoyalePoint() //<<< Draw Bang POint PK
{
	if (pMapNumber != gInterface.m_EventBattleRoyaleMap || gInterface.m_EventBattleRoyaleTimeCount == 0)
	{
		return;
	}

	if (gInterface.CheckWindow(CashShop)
		|| gInterface.CheckWindow(SkillTree)
		|| gInterface.CheckWindow(FullMap)
		|| gInterface.CheckWindow(MoveList)
		|| gInterface.CheckWindow(Inventory)
		|| gInterface.CheckWindow(ExpandInventory)
		|| gInterface.CheckWindow(Store)
		|| gInterface.CheckWindow(Inventory)
		|| gInterface.CheckWindow(Character) //-- 13 & 16
		|| gInterface.CheckWindow(Party)
		|| gInterface.CheckWindow(Trade)
		|| gInterface.CheckWindow(Warehouse)
		|| gInterface.CheckWindow(ExpandWarehouse))
	{
		return;
	}
	//Test
	float ChieuRong = 250.0f;
	float ChieuDai = 10.0f;
	float ViTriX = ((int)pWinWidth / pWinHeightReal / 2) - (ChieuRong / 2);
	float ViTriY = 5;

	char* Vong[5] = { "NULL", "Gia Nhập ", "Chuẩn Bị", "Chiến Đấu", "Trao Giải" };


	float InfoW = 100;
	float InfoH = 40;
	float InfoX = MAX_WIN_WIDTH - (InfoW + 20) + 5;
	float InfoY = MAX_WIN_HEIGHT - (InfoH + 100);
	RenderBitmap(31672, InfoX, InfoY, 110, 83.0, 0, 0, 0.95, 0.6, 1, 1, 0.0);
	if (gInterface.gDrawButton(InfoX, InfoY - 20, 110, 12, "Bảng Xếp Hạng") && (GetTickCount() - gInterface.Data[eWindowBXH_BattleRoyale].EventTick) > 300)
	{
		////===BXH
		gInterface.Data[eWindowBXH_BattleRoyale].OnShow ^= 1;
		gInterface.Data[eWindowBXH_BattleRoyale].EventTick = GetTickCount();

	}
	CustomFont.Draw(CustomFont.FontNormal, InfoX, InfoY + 13, 0xE6FCF7FF, 0x0, InfoW + 7, 0, 3, "%s", Vong[gInterface.m_EventBattleRoyaleState]);
	InfoY += 15;

	CustomFont.Draw(CustomFont.FontNormal, InfoX, InfoY + 23, 0xE6FCF7FF, 0xff222299, InfoW + 7, 0, 3, "Giết %d Chết %d", gInterface.m_DiemGiet, gInterface.m_DiemChet);
	CustomFont.Draw(CustomFont.FontNormal, InfoX, (InfoY + 33), 0xE6FCF7FF, 0xFFE50064, InfoW + 7, 0, 3, "Thời Gian Còn Lại");
	BRenderTimeCountDown(InfoX, (InfoY + 48), InfoW + 10, gInterface.m_EventBattleRoyaleTimeCount);

}

void DrawWindowBXHBattleRoyale()
{
	if (!gInterface.Data[eWindowBXH_BattleRoyale].OnShow)
	{
		return;
	}

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
	float CuaSoW = 250.0;
	float CuaSoH = 200.0;

	float StartX = (MAX_WIN_WIDTH / 2) - (CuaSoW / 2);
	float StartY = 45.0;


	gCentral.gDrawWindowCustom(StartX, StartY, CuaSoW, CuaSoH, eWindowBXH_BattleRoyale, "Bảng Xếp Hạng Battle Royale Event");


	//====================================
	CustomFont.Draw(CustomFont.FontBold, StartX, StartY + 40, 0xFABB00FF, 0x0, CuaSoW / 4, 0, 3, "Top"); //
	CustomFont.Draw(CustomFont.FontBold, StartX + CuaSoW / 4, StartY + 40, 0xFABB00FF, 0x0, CuaSoW / 4, 0, 3, "Name"); //
	CustomFont.Draw(CustomFont.FontBold, StartX + ((CuaSoW / 4) * 2), StartY + 40, 0xFABB00FF, 0x0, CuaSoW / 4, 0, 3, "Giết"); //
	CustomFont.Draw(CustomFont.FontBold, StartX + ((CuaSoW / 4) * 3), StartY + 40, 0xFABB00FF, 0x0, CuaSoW / 4, 0, 3, "Chết"); //

	DWORD ColorTextRank = 0xE0DFDCFF;

	for (int i = 0; i < gInterface.m_BattleRoyaleBXHC; i++)
	{
		if (i % 2)
		{
			ColorTextRank = 0xA3A3A3FF;
		}
		else {
			ColorTextRank = 0xE0DFDCFF;
		}
		if (i < 3) { ColorTextRank = 0xFFE240FF; }
		CustomFont.Draw(CustomFont.FontBold, StartX, StartY + 55 + (i * 12), ColorTextRank, (i < 3) ? 0xFFE2400F : 0x0, CuaSoW / 4, 0, 3, "%d", i + 1); //
		CustomFont.Draw(CustomFont.FontBold, StartX + CuaSoW / 4, StartY + 55 + (i * 12), ColorTextRank, (i < 3) ? 0xFFE2400F : 0x0, CuaSoW / 4, 0, 3, "%s", gInterface.m_BattleRoyaleBXH[i].Name); //
		CustomFont.Draw(CustomFont.FontBold, StartX + ((CuaSoW / 4) * 2), StartY + 55 + (i * 12), ColorTextRank, (i < 3) ? 0xFFE2400F : 0x0, CuaSoW / 4, 0, 3, "%d", gInterface.m_BattleRoyaleBXH[i].Kill); //
		CustomFont.Draw(CustomFont.FontBold, StartX + ((CuaSoW / 4) * 3), StartY + 55 + (i * 12), ColorTextRank, (i < 3) ? 0xFFE2400F : 0x0, CuaSoW / 4, 0, 3, "%d", gInterface.m_BattleRoyaleBXH[i].Death);

	}

}

void DrawWindowNPCBattleRoyale()
{
	if (!gInterface.Data[eWindowNPC_BattleRoyale].OnShow)
	{
		return;
	}

	float CuaSoW = 300.0;
	float CuaSoH = 220.0;
	int JCResto = pWinWidth / pWinHeightReal / 2 - 320;
	float StartX = (MAX_WIN_WIDTH / 2) - (CuaSoW / 2);
	float StartY = 45.0;
	//gCentral.gDrawWindowCustom(StartX, StartY, CuaSoW, CuaSoH, eWindowNPC_GPK, 0, "Sự Kiện Sinh Tồn");

	gCBUtil.gDrawWindowCustom(&StartX, &StartY, CuaSoW, CuaSoH, eWindowNPC_BattleRoyale, "Battle Royale Event");


	if (gCentral.gDrawButton(StartX + (CuaSoW / 2) - (115 / 2), StartY + (CuaSoH - 45), 115, 14, "Tham Gia") && (GetTickCount() - gInterface.Data[eWindowNPC_BattleRoyale].EventTick) > 300)
	{
		//==Tham Gia Than Ma
		XULY_CGPACKET pMsg;
		pMsg.header.set(0xFD, 0x93, sizeof(pMsg));
		pMsg.ThaoTac = 1;
		DataSend((LPBYTE)& pMsg, pMsg.header.size);
		gInterface.Data[eWindowNPC_BattleRoyale].OnShow ^= 1;

	}
	HFONT FontTextTMB = CreateFontA(13, Main_Font_Width, 0, 0, 700, Main_Font_Italic, Main_Font_Underline, Main_Font_StrikeOut, 0x1, 0, 0, Main_Font_Quality, 0, "Tahoma");
	HFONT FontTextTM = CreateFontA(13, Main_Font_Width, 0, 0, 400, Main_Font_Italic, Main_Font_Underline, Main_Font_StrikeOut, 0x1, 0, 0, Main_Font_Quality, 0, "Tahoma");
	float TextStartY = StartY + 33;

	//CustomFont.Draw(FontTextTMB, (StartX + (CuaSoW / 10)) - 15, TextStartY + (12 * 0), 0xFFDE26FF, 0x0, CuaSoW, 0, 1, "111111111111111"); //
	//CustomFont.Draw(FontTextTMB, (StartX + (CuaSoW / 10)) - 15, TextStartY + (12 * 1), 0xFFDE26FF, 0x0, CuaSoW, 0, 1, "2211"); //
	//CustomFont.Draw(FontTextTMB, (StartX + (CuaSoW / 10)) - 15, TextStartY + (12 * 3), 0xFFDE26FF, 0x0, CuaSoW, 0, 1, "44441111"); //


	CustomFont.Draw(FontTextTMB, (StartX + (CuaSoW / 10)) - 15, TextStartY + (12 * 1), 0xFFDE26FF, 0x0, CuaSoW, 0, 1, "- Battle Royale Event");

	CustomFont.Draw(FontTextTMB, (StartX + (CuaSoW / 10)) - 15, TextStartY + (12 * 2), 0xFFDE26FF, 0x0, CuaSoW, 0, 1, "- Người Chơi Sau Khi Tham Gia Sẽ Trở Về Nhân Vật Mặc Định");

	CustomFont.Draw(FontTextTMB, (StartX + (CuaSoW / 10)) - 15, TextStartY + (12 * 3), 0xFFDE26FF, 0x0, CuaSoW, 0, 1, "- Vào Event Người Chơi Sẽ Có 15.000 Point");

	CustomFont.Draw(FontTextTMB, (StartX + (CuaSoW / 10)) - 15, TextStartY + (12 * 4), 0xFFDE26FF, 0x0, CuaSoW, 0, 1, "- Khi Tham Gia Sự Kiện Nhanh Chóng Tăng Điểm ");

	CustomFont.Draw(FontTextTMB, (StartX + (CuaSoW / 10)) - 15, TextStartY + (12 * 5), 0xFFDE26FF, 0x0, CuaSoW, 0, 1, "- Khi Sự Kiện Bắt Đầu Người Chơi Sẽ Được Dịch Chuyển Ngẫu Nhiên");

	CustomFont.Draw(FontTextTMB, (StartX + (CuaSoW / 10)) - 15, TextStartY + (12 * 6), 0xFFDE26FF, 0x0, CuaSoW, 0, 1, "- Thu Thập Vũ Khí,Wing .. Được Thả Ở Xung Quanh Map");

	CustomFont.Draw(FontTextTMB, (StartX + (CuaSoW / 10)) - 15, TextStartY + (12 * 7), 0xFFDE26FF, 0x0, CuaSoW, 0, 1, "- Các Người Chơi Sẽ PK Với Nhau Để Giành Chiến Thắng Sau Cùng");

	CustomFont.Draw(FontTextTMB, (StartX + (CuaSoW / 10)) - 15, TextStartY + (12 * 8), 0xFFDE26FF, 0x0, CuaSoW, 0, 1, "- Phần Thưởng Sẽ Được Thêm Vào Cho Tốp 1 2 3");

	CustomFont.Draw(FontTextTMB, (StartX + (CuaSoW / 10)) - 15, TextStartY + (12 * 9), 0xFFDE26FF, 0x0, CuaSoW, 0, 1, "- Hãy Sử Dụng Chiến Thuật Chiến Đấu Cẩn Thận Để Giành Chiến Thắng");

	CustomFont.Draw(FontTextTMB, (StartX + (CuaSoW / 10)) - 15, TextStartY + (12 * 10), 0xFFDE26FF, 0x0, CuaSoW, 0, 1, "- Chúc Các Bạn Tham Gia Event Vui Vẻ");





	DeleteObject(FontTextTMB);
	DeleteObject(FontTextTM);

}

void Interface::DrawBattleRoyaleALL()
{
	DrawBattleRoyalePoint();
	DrawWindowBXHBattleRoyale();
	DrawWindowNPCBattleRoyale();
}
#endif


#if(SAUDOIITEM)

struct JCCoord
{
	int X;
	int Y;
};

#define BPConvertByteItem ((int (__thiscall*)(int a1, void *lp)) 0x7E1B10)
#define BPDrawInfoItem			((signed int (__thiscall*)(int a1, JCCoord a5, int a6, int a7, int a8, int a9)) 0x007E3E30)
void* BCacheInfoItemDD;
DWORD CacheTimeShowInfoItem = 0;
#define sub_7E3E30 ((signed int (__thiscall*)(int a1, JCCoord a5, int a6, int a7, int a8, int a9)) 0x007E3E30)

void Interface::DrawInfoItemSet()
{
	if (*(DWORD*)(MAIN_SCREEN_STATE) == ObjState::GameProcess)
	{
		if (BCacheInfoItemDD && CacheTimeShowInfoItem > GetTickCount())
		{
			JCCoord JCShowSellItem;

			JCShowSellItem.X = pCursorX + 50;
			JCShowSellItem.Y = pCursorY;
			pSetBlend(true);
			glColor3f(1.0, 1.0, 1.0);
			sub_7E3E30(*(DWORD*)(GetInstance() + 308), JCShowSellItem, (int)BCacheInfoItemDD, 0, 0, 0);
			pGLSwitch();
			pSetBlend(false);
		}
		else if (BCacheInfoItemDD)
		{
			BCacheInfoItemDD = nullptr;
		}

	}
}



void BackDoiItem(int Type)
{
	if ((GetTickCount() - gInterface.Data[eWindowDoiItem].EventTick) > 300)
	{

		XULY_CGPACKET pMsg;
		pMsg.header.set(0xD3, 0x6C, sizeof(pMsg));
		pMsg.ThaoTac = Type; //
		DataSend((LPBYTE)& pMsg, pMsg.header.size);
		gInterface.Data[eWindowDoiItem].EventTick = GetTickCount();
	}
}
int DoiItem = -1;
void Interface::DrawDoiItem()

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
		if (gInterface.Data[eWindowDoiItem].OnShow == true)
		{
			gInterface.Data[eWindowDoiItem].OnShow = false;
			pSetCursorFocus = false;
			return;
		}
	}


	if (!gInterface.Data[eWindowDoiItem].OnShow)
	{
		if (gInterface.SetStateDoiItem == 1)
		{
			XULY_CGPACKET pMsg;
			pMsg.header.set(0xD3, 0x6A, sizeof(pMsg));
			pMsg.ThaoTac = 111; //
			DataSend((LPBYTE)& pMsg, pMsg.header.size);
			gInterface.SetStateDoiItem = false;
			gInterface.SAU_EffectsMix = false;
			gInterface.SAU_ActiveMix = false;
			gInterface.RateSAU = false;
			DoiItem = -1;
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
	float WindowW = 350;
	float WindowH = 400;
	int CheckItemOK = 0;

	gCBUtil.gDrawWindowCustom(&StartX, &StartY, WindowW, WindowH, eWindowDoiItem, "Đổi Item");
	{

		float BoxItemWH = 35;
		//===Item Chinh
		float PosXGroup1 = StartX + 20;
		float PosYGroup1 = StartY + 40;
		gCBUtil.gInfoBox(PosXGroup1 - 10, PosYGroup1 - 5, WindowW - 30, 240, 0x00000096, 0, 0);

		CustomFont.Draw((HFONT)pFontBold, PosXGroup1, PosYGroup1 + 5, 0xEBA000FF, 0x0, 0, 0, 1, "Chức năng Đổi Item Class");//
		//===Box Item Chinh
		gCBUtil.gInfoBox(PosXGroup1 + ((WindowW - 40) / 2) - (BoxItemWH / 2), PosYGroup1 + 20, BoxItemWH, BoxItemWH, 0x00000096, 0, 0); // Chinh

		ObjectItem * CTItemChinh = &*(ObjectItem*)(BPConvertByteItem(*(DWORD*)(GetInstance() + 36), gInterface.SAU_ItemChinh));
		if (CTItemChinh->ItemID > 0)
		{
			gCBUtil.DrawItem3D((PosXGroup1 + ((WindowW - 40) / 2) - (BoxItemWH / 2) + 7), (PosYGroup1 + 20) + 7, BoxItemWH, BoxItemWH, CTItemChinh->ItemID, CTItemChinh->Level, CTItemChinh->ExcellentOption, CTItemChinh->AncientOption, 0, 1.4);//BMD MOdel
			if (pCheckMouseOver(PosXGroup1 + ((WindowW - 40) / 2) - (BoxItemWH / 2), PosYGroup1 + 20, 50, 50) == 1)
			{
				BCacheInfoItemDD = CTItemChinh;
				CacheTimeShowInfoItem = GetTickCount() + 50;
				if (GetKeyState(VK_RBUTTON) & 0x8000)
				{
					BackDoiItem(0);
				}
			}
		}
		//pDrawColorButton(71520, PosXGroup1, PosYGroup1 + 75, (WindowW - 40), 1, 0, 0, pMakeColor(158, 158, 158, 130));//-- Divisor

		//===Item Phu
		float PosYGroup2 = PosYGroup1 + 85;
		CustomFont.Draw((HFONT)pFontBold, PosXGroup1, PosYGroup2, 0xEBA000FF, 0x0, 0, 0, 1, "Item Nhận Được");//
		//===Box Item Phu
		if (DoiItem == 1)
		{
			gCBUtil.gInfoBox(PosXGroup1 + 50, PosYGroup2 + 20, BoxItemWH, BoxItemWH, 0x26E0A596, 0, 0); //Phu 1
		}
		gCBUtil.gInfoBox(PosXGroup1 + 50, PosYGroup2 + 20, BoxItemWH, BoxItemWH, 0x00000096, 0, 0); //Phu 1
		//====
		ObjectItem* CTItemPhu1 = &*(ObjectItem*)(BPConvertByteItem(*(DWORD*)(GetInstance() + 36), gInterface.SAU_ItemKetQua[0]));
		if (CTItemPhu1->ItemID > 0)
		{

			gCBUtil.DrawItem3D((PosXGroup1 + 50) + 7, (PosYGroup2 + 20) + 7, BoxItemWH, BoxItemWH, CTItemPhu1->ItemID, CTItemPhu1->Level, CTItemPhu1->ExcellentOption, CTItemPhu1->AncientOption, 0, 1.4);//BMD MOdel
			if (pCheckMouseOver((PosXGroup1 + 50), PosYGroup2 + 20, 50, 50) == 1)
			{
				BCacheInfoItemDD = CTItemPhu1;
				CacheTimeShowInfoItem = GetTickCount() + 50;
				if (GetKeyState(VK_LBUTTON) & 0x8000)
				{
					DoiItem = 1;
					//BackDoiItem(1);
				}
			}
		}
		//====
		if (DoiItem == 2)
		{
			gCBUtil.gInfoBox(PosXGroup1 + ((WindowW - 40) / 2) - (BoxItemWH / 2), PosYGroup2 + 20, BoxItemWH, BoxItemWH, 0x26E0A596, 0, 0); //Phu 2
		}
		gCBUtil.gInfoBox(PosXGroup1 + ((WindowW - 40) / 2) - (BoxItemWH / 2), PosYGroup2 + 20, BoxItemWH, BoxItemWH, 0x00000096, 0, 0); //Phu 2
		//====
		ObjectItem* CTItemPhu2 = &*(ObjectItem*)(BPConvertByteItem(*(DWORD*)(GetInstance() + 36), gInterface.SAU_ItemKetQua[1]));
		if (CTItemPhu2->ItemID > 0)
		{

			gCBUtil.DrawItem3D((PosXGroup1 + ((WindowW - 40) / 2) - (BoxItemWH / 2)) + 7, (PosYGroup2 + 20) + 7, BoxItemWH, BoxItemWH, CTItemPhu2->ItemID, CTItemPhu2->Level, CTItemPhu2->ExcellentOption, CTItemPhu2->AncientOption, 0, 1.4);//BMD MOdel
			if (pCheckMouseOver((PosXGroup1 + ((WindowW - 40) / 2) - (BoxItemWH / 2)), PosYGroup2 + 20, 50, 50) == 1)
			{
				BCacheInfoItemDD = CTItemPhu2;
				CacheTimeShowInfoItem = GetTickCount() + 50;
				if (GetKeyState(VK_LBUTTON) & 0x8000)
				{
					DoiItem = 2;
					//BackDoiItem(2);
				}
			}
		}
		//====
		if (DoiItem == 3)
		{
			gCBUtil.gInfoBox(PosXGroup1 + ((WindowW - 40) / 2) + 70, PosYGroup2 + 20, BoxItemWH, BoxItemWH, 0x26E0A596, 0, 0); //Phu 3
		}
		gCBUtil.gInfoBox(PosXGroup1 + ((WindowW - 40) / 2) + 70, PosYGroup2 + 20, BoxItemWH, BoxItemWH, 0x00000096, 0, 0); //Phu 3
		//====
		ObjectItem* CTItemPhu3 = &*(ObjectItem*)(BPConvertByteItem(*(DWORD*)(GetInstance() + 36), gInterface.SAU_ItemKetQua[2]));
		if (CTItemPhu3->ItemID > 0)
		{

			gCBUtil.DrawItem3D((PosXGroup1 + ((WindowW - 40) / 2) + 70) + 5, (PosYGroup2 + 20) + 7, BoxItemWH, BoxItemWH, CTItemPhu3->ItemID, CTItemPhu3->Level, CTItemPhu3->ExcellentOption, CTItemPhu3->AncientOption, 0, 1.4);//BMD MOdel
			if (pCheckMouseOver(PosXGroup1 + ((WindowW - 40) / 2) + 70, PosYGroup2 + 20, 50, 50) == 1)
			{
				BCacheInfoItemDD = CTItemPhu3;
				CacheTimeShowInfoItem = GetTickCount() + 50;
				if (GetKeyState(VK_LBUTTON) & 0x8000)
				{
					DoiItem = 3;
					//BackDoiItem(3);
				}
			}
		}
		//====

		pDrawColorButton(71520, PosXGroup1, PosYGroup2 + 75, (WindowW - 40), 1, 0, 0, pMakeColor(158, 158, 158, 130));//-- Divisor	

		//===Item Ket Qua
		float PosYGroup3 = PosYGroup2 + 85;
		//CustomFont.Draw((HFONT)pFontBold, PosXGroup1, PosYGroup3, 0xEBA000FF, 0x0, 0, 0, 1, gOther.Text_Event[43]);//
		//===Box Item KetQua
		//	gCentral.gInfoBox(PosXGroup1 + ((WindowW - 40) / 2) - (BoxItemWH / 2), PosYGroup3 + 20, BoxItemWH, BoxItemWH, 0x00000096, 0, 0); //
		//====

		if (DoiItem == 4)
		{
			gCBUtil.gInfoBox(PosXGroup1 + 50, PosYGroup3 + 20, BoxItemWH, BoxItemWH, 0x26E0A596, 0, 0); //Phu 4
		}
		gCBUtil.gInfoBox(PosXGroup1 + 50, PosYGroup3 + 20, BoxItemWH, BoxItemWH, 0x00000096, 0, 0); //Phu 4

		ObjectItem* CTItemKQ1 = &*(ObjectItem*)(BPConvertByteItem(*(DWORD*)(GetInstance() + 36), gInterface.SAU_ItemKetQua[3]));
		if (CTItemKQ1->ItemID > 0)
		{

			gCBUtil.DrawItem3D((PosXGroup1 + 50) + 7, (PosYGroup3 + 20) + 7, BoxItemWH, BoxItemWH, CTItemKQ1->ItemID, CTItemKQ1->Level, CTItemKQ1->ExcellentOption, CTItemKQ1->AncientOption, 0, 1.4);//BMD MOdel
			if (pCheckMouseOver((PosXGroup1 + 50), PosYGroup3 + 20, 50, 50) == 1)
			{
				BCacheInfoItemDD = CTItemKQ1;
				CacheTimeShowInfoItem = GetTickCount() + 50;
				if (GetKeyState(VK_LBUTTON) & 0x8000)
				{
					DoiItem = 4;
					//BackDoiItem(4);
				}
			}
		}
		//====
		if (DoiItem == 5)
		{
			gCBUtil.gInfoBox(PosXGroup1 + ((WindowW - 40) / 2) - (BoxItemWH / 2), PosYGroup3 + 20, BoxItemWH, BoxItemWH, 0x26E0A596, 0, 0); //Phu 5
		}
		gCBUtil.gInfoBox(PosXGroup1 + ((WindowW - 40) / 2) - (BoxItemWH / 2), PosYGroup3 + 20, BoxItemWH, BoxItemWH, 0x00000096, 0, 0); //Phu 5
		//====
		ObjectItem* CTItemKQ2 = &*(ObjectItem*)(BPConvertByteItem(*(DWORD*)(GetInstance() + 36), gInterface.SAU_ItemKetQua[4]));
		if (CTItemPhu2->ItemID > 0)
		{

			gCBUtil.DrawItem3D((PosXGroup1 + ((WindowW - 40) / 2) - (BoxItemWH / 2)) + 7, (PosYGroup3 + 20) + 7, BoxItemWH, BoxItemWH, CTItemKQ2->ItemID, CTItemKQ2->Level, CTItemKQ2->ExcellentOption, CTItemKQ2->AncientOption, 0, 1.4);//BMD MOdel
			if (pCheckMouseOver((PosXGroup1 + ((WindowW - 40) / 2) - (BoxItemWH / 2)), PosYGroup3 + 20, 50, 50) == 1)
			{
				BCacheInfoItemDD = CTItemKQ2;
				CacheTimeShowInfoItem = GetTickCount() + 50;
				if (GetKeyState(VK_LBUTTON) & 0x8000)
				{
					DoiItem = 5;
					//BackDoiItem(5);
				}
			}
		}
		//====
		if (DoiItem == 6)
		{
			gCBUtil.gInfoBox(PosXGroup1 + ((WindowW - 40) / 2) + 70, PosYGroup3 + 20, BoxItemWH, BoxItemWH, 0x26E0A596, 0, 0); //Phu 6
		}

		gCBUtil.gInfoBox(PosXGroup1 + ((WindowW - 40) / 2) + 70, PosYGroup3 + 20, BoxItemWH, BoxItemWH, 0x00000096, 0, 0); //Phu 6
		//====
		ObjectItem* CTItemKQ3 = &*(ObjectItem*)(BPConvertByteItem(*(DWORD*)(GetInstance() + 36), gInterface.SAU_ItemKetQua[5]));
		if (CTItemKQ3->ItemID > 0)
		{

			gCBUtil.DrawItem3D((PosXGroup1 + ((WindowW - 40) / 2) + 70) + 5, (PosYGroup3 + 20) + 7, BoxItemWH, BoxItemWH, CTItemKQ3->ItemID, CTItemKQ3->Level, CTItemKQ3->ExcellentOption, CTItemKQ3->AncientOption, 0, 1.4);//BMD MOdel
			if (pCheckMouseOver(PosXGroup1 + ((WindowW - 40) / 2) + 70, PosYGroup3 + 20, 50, 50) == 1)
			{
				BCacheInfoItemDD = CTItemKQ3;
				CacheTimeShowInfoItem = GetTickCount() + 50;
				if (GetKeyState(VK_LBUTTON) & 0x8000)
				{
					DoiItem = 6;
					//BackDoiItem(6);
				}
			}
		}
		//====




		//====
		//pDrawColorButton(71520, PosXGroup1, PosYGroup3 + 75, (WindowW - 40), 1, 0, 0, pMakeColor(158, 158, 158, 130));//-- Divisor
		gCBUtil.gInfoBox(PosXGroup1 - 10, PosYGroup3 + 80, WindowW - 30, 90, 0x00000096, 0, 0);
		//===Info Text
		float PosYTextInfo = PosYGroup3 + 85;
		int CountText = 0;
		CustomFont.Draw((HFONT)pFontBold, PosXGroup1, PosYTextInfo + (10 * CountText++), 0xEBA000FF, 0x0, 0, 0, 1, "Đổi Vật Phẩm Theo Tùy Chọn Class");//

		CustomFont.Draw((HFONT)pFontBold, PosXGroup1, PosYTextInfo + (20 * CountText++), 0xEBA000FF, 0x0, 0, 0, 1, "Click Chuột Trái Vào Item Để Chọn");//

		CustomFont.Draw((HFONT)pFontBold, PosXGroup1, PosYTextInfo + (20 * CountText++), 0xEBA000FF, 0x0, 0, 0, 1, "WCoin");//

		CustomFont.Draw((HFONT)pFontBold, PosXGroup1 + 110, PosYTextInfo + (20 * 2), 0x62FF00FF, 0x0, 0, 0, 1, "%s", BNumberFormat(gInterface.RateSAU));//
		float ButtonW = 115;
		float ButtonH = 25;
		float ButtonX = PosXGroup1 + ((WindowW - 40) / 2) - (ButtonW / 2);
		float ButtonY = (StartY + WindowH) - 20 - ButtonH;
		//if (gCentral.gDrawButton(ButtonX, ButtonY, ButtonW, 12, "Dung Luyện")) //Dung Luyen

		if (gElemental.gDrawButton(ButtonX, ButtonY, ButtonW, Main_Font_Height, "Đổi Item"))
		{
			PlayBuffer(25, 0, 0);
			BackDoiItem(DoiItem);
			DoiItem = -1;
			gInterface.Data[eWindowDoiItem].OnShow ^= 1;
		}
	}
}

#endif


#if(CUSTOM_DUNGLUYENITEM)
void RenderMixEffect(int type, int x, int y, int w = 2, int h = 4)
{
	int result; // eax
	float v4; // [esp+28h] [ebp-48h]
	float v5; // [esp+30h] [ebp-40h]
	GLfloat red; // [esp+44h] [ebp-2Ch]
	GLfloat green; // [esp+4Ch] [ebp-24h]
	float v8; // [esp+58h] [ebp-18h]
	float v9; // [esp+5Ch] [ebp-14h]
	float v10; // [esp+60h] [ebp-10h]
	float v11; // [esp+64h] [ebp-Ch]
	int j; // [esp+68h] [ebp-8h]
	int i; // [esp+6Ch] [ebp-4h]

	if (type > 0)
	{
		for (i = 1; i <= h; ++i)
		{
			for (j = 1; j <= w; ++j)
			{
				pSetBlend(1);
				pGLSwitchBlend();
				green = (double)(rand() % 4 + 4) * 0.1000000014901161;
				red = (double)(rand() % 6 + 6) * 0.1000000014901161;
				glColor3f(red, green, 0.2);
				v11 = (double)((int)0x5EF5A1C % 100) * 20.0;
				v8 = (double)(rand() % 10) + 5.0;
				v9 = (float)(x + rand() % (20 * j + 1));
				v10 = (float)(y + rand() % (20 * i + 1));
				sub_637E80(32113, LODWORD(v9), LODWORD(v10), LODWORD(v8), LODWORD(v8), 0.0, 0.0, 0.0, 1.0, 1.0);
				sub_637E80(32113, LODWORD(v9), LODWORD(v10), LODWORD(v8), LODWORD(v8), LODWORD(v11), 0.0, 0.0, 1.0, 1.0);
				v5 = v8 * 3.0;
				sub_637E80(32114, LODWORD(v9), LODWORD(v10), LODWORD(v5), LODWORD(v5), LODWORD(v11), 0.0, 0.0, 1.0, 1.0);
				v4 = v8 * 6.0;
				sub_637E80(32002, LODWORD(v9), LODWORD(v10), LODWORD(v4), LODWORD(v4), 0.0, 0.0, 0.0, 1.0, 1.0);
				pGLSwitch();
				glColor4f(1.0, 1.0, 1.0, 1.0);
				pSetBlend(0);
			}
		}
	}
}

void BackItemDungLuyen(int Type)
{
	if ((GetTickCount() - gInterface.Data[eWindowDungLuyenItem].EventTick) > 300)
	{
		XULY_CGPACKET pMsg;
		pMsg.header.set(0xD3, 0x2C, sizeof(pMsg));
		pMsg.ThaoTac = Type; //
		DataSend((LPBYTE)& pMsg, pMsg.header.size);
		gInterface.Data[eWindowDungLuyenItem].EventTick = GetTickCount();
	}
}
DWORD DungLuyenEffect = 0;

CNewUIScrollBar* DungLuyenListScrollBar = NULL;
int DungLuyenListMaxPerPage = 5;
bool UpdateMaxPosDL = false;

void Interface::DrawDungLuyenItem()
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
		if (gInterface.Data[eWindowDungLuyenItem].OnShow == true)
		{
			gInterface.Data[eWindowDungLuyenItem].OnShow = false;
			pSetCursorFocus = false;
			return;
		}
	}


	if (!gInterface.Data[eWindowDungLuyenItem].OnShow)
	{
		if (gInterface.SetStateDungLuyen == 1)
		{
			XULY_CGPACKET pMsg;
			pMsg.header.set(0xD3, 0x2A, sizeof(pMsg));
			pMsg.ThaoTac = 111; //
			DataSend((LPBYTE)& pMsg, pMsg.header.size);
			gInterface.SetStateDungLuyen = false;
			gInterface.DL_EffectsMix = false;
			gInterface.DL_ActiveMix = false;
			gInterface.RateDL = false;
			gInterface.TypeDL = false;
		}
		if (DungLuyenListScrollBar)
		{
			DungLuyenListScrollBar = NULL;

		}

		memset(gInterface.DL_ItemChinh, 0, sizeof(gInterface.DL_ItemChinh));
		memset(gInterface.DL_ItemPhu, 0, sizeof(gInterface.DL_ItemPhu));
		memset(gInterface.DL_ItemKetQua, 0, sizeof(gInterface.DL_ItemKetQua));
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
	float WindowH = 400;
	int CheckItemOK = 0;
	//#if S15
	//	gCBUtil.PrintDropBox2(StartX, StartY, WindowW, WindowH,eWindowDungLuyenItem, "Dung Luyện");
	//#else
	//	gElemental.gDrawWindowCustom(StartX, StartY, WindowW, WindowH, eWindowDungLuyenItem, "Dung Luyện");
	//#endif

	gCBUtil.gDrawWindowCustom(&StartX, &StartY, WindowW, WindowH, eWindowDungLuyenItem, "Dung Luyện");

	//if (!gCBUtil.GiaoDienCash(eWindowDungLuyenItem, &StartX, &StartY, WindowW, WindowH, gOther.Text_Event[40]))
	{


		float BoxItemWH = 35;
		//===Item Chinh
		float PosXGroup1 = StartX + 20;
		float PosYGroup1 = StartY + 40;
		gCBUtil.gInfoBox(PosXGroup1 - 10, PosYGroup1 - 5, WindowW - 30, 160, 0x00000096, 0, 0);

		CustomFont.Draw((HFONT)pFontBold, PosXGroup1, PosYGroup1 + 5, 0xEBA000FF, 0x0, 0, 0, 1, "1. Item Chính (Đồ Hoàn Hảo +9 trở lên):");//
		CustomFont.Draw((HFONT)pFontBold, PosXGroup1 + 180, PosYGroup1 + 5, 0xEBA000FF, 0x0, 0, 0, 1, "3. Kết Quả:");//
		RenderBitmap(31538, PosXGroup1 + 110, PosYGroup1 + 40, 32, 15, 0.f, 0.f, 0.85, 0.85, true, true, 0); //>>> 1
		//===Box Item Chinh
		gCBUtil.gInfoBox(PosXGroup1 + 20, PosYGroup1 + 20, BoxItemWH, BoxItemWH, 0x00000096, 0, 0); // Chinh

		ObjectItem * CTItemChinh = &*(ObjectItem*)(BPConvertByteItem(*(DWORD*)(GetInstance() + 36), gInterface.DL_ItemChinh));
		if (CTItemChinh->ItemID > 0)
		{
			gCBUtil.DrawItem3D(PosXGroup1 + 20, (PosYGroup1 + 20) + 7, BoxItemWH, BoxItemWH, CTItemChinh->ItemID, CTItemChinh->Level, CTItemChinh->ExcellentOption, CTItemChinh->AncientOption, 0, 2.0);//BMD MOdel
			if (pCheckMouseOver(PosXGroup1 + 20, PosYGroup1 + 20, 50, 50) == 1)
			{
				BCacheInfoItemDD = CTItemChinh;
				CacheTimeShowInfoItem = GetTickCount() + 50;
				if (GetKeyState(VK_RBUTTON) & 0x8000)
				{
					BackItemDungLuyen(0);
				}
			}
		}
		pDrawColorButton(71520, PosXGroup1, PosYGroup1 + 75, (WindowW - 40), 1, 0, 0, pMakeColor(158, 158, 158, 130));//-- Divisor

		//===Item Phu
		float PosYGroup2 = PosYGroup1 + 85;
		CustomFont.Draw((HFONT)pFontBold, PosXGroup1, PosYGroup2, 0xEBA000FF, 0x0, 0, 0, 1, "2. Item Phụ (Đồ Hoàn Hảo):");//
		//===Box Item Phu
		gCBUtil.gInfoBox(PosXGroup1 + 20, PosYGroup2 + 20, BoxItemWH, BoxItemWH, 0x00000096, 0, 0); //Phu 1
		//====
		ObjectItem* CTItemPhu1 = &*(ObjectItem*)(BPConvertByteItem(*(DWORD*)(GetInstance() + 36), gInterface.DL_ItemPhu[0]));
		if (CTItemPhu1->ItemID > 0)
		{

			gCBUtil.DrawItem3D((PosXGroup1 + 20) + 7, (PosYGroup2 + 20) + 7, BoxItemWH, BoxItemWH, CTItemPhu1->ItemID, CTItemPhu1->Level, CTItemPhu1->ExcellentOption, CTItemPhu1->AncientOption, 0, 2.0);//BMD MOdel
			if (pCheckMouseOver((PosXGroup1 + 20), PosYGroup2 + 20, 50, 50) == 1)
			{
				BCacheInfoItemDD = CTItemPhu1;
				CacheTimeShowInfoItem = GetTickCount() + 50;
				if (GetKeyState(VK_RBUTTON) & 0x8000)
				{
					BackItemDungLuyen(1);
				}
			}
		}
		//====
		gCBUtil.gInfoBox(PosXGroup1 + ((WindowW - 40) / 2) - (BoxItemWH / 2), PosYGroup2 + 20, BoxItemWH, BoxItemWH, 0x00000096, 0, 0); //Phu 2
		//====
		ObjectItem* CTItemPhu2 = &*(ObjectItem*)(BPConvertByteItem(*(DWORD*)(GetInstance() + 36), gInterface.DL_ItemPhu[1]));
		if (CTItemPhu2->ItemID > 0)
		{

			gCBUtil.DrawItem3D((PosXGroup1 + ((WindowW - 40) / 2) - (BoxItemWH / 2)) + 7, (PosYGroup2 + 20) + 7, BoxItemWH, BoxItemWH, CTItemPhu2->ItemID, CTItemPhu2->Level, CTItemPhu2->ExcellentOption, CTItemPhu2->AncientOption, 0, 2.0);//BMD MOdel
			if (pCheckMouseOver((PosXGroup1 + ((WindowW - 40) / 2) - (BoxItemWH / 2)), PosYGroup2 + 20, 50, 50) == 1)
			{
				BCacheInfoItemDD = CTItemPhu2;
				CacheTimeShowInfoItem = GetTickCount() + 50;
				if (GetKeyState(VK_RBUTTON) & 0x8000)
				{
					BackItemDungLuyen(2);
				}
			}
		}
		//====
		gCBUtil.gInfoBox(PosXGroup1 + ((WindowW - 40) / 2) + 70, PosYGroup2 + 20, BoxItemWH, BoxItemWH, 0x00000096, 0, 0); //Phu 3
		//====
		ObjectItem* CTItemPhu3 = &*(ObjectItem*)(BPConvertByteItem(*(DWORD*)(GetInstance() + 36), gInterface.DL_ItemPhu[2]));
		if (CTItemPhu3->ItemID > 0)
		{

			gCBUtil.DrawItem3D((PosXGroup1 + ((WindowW - 40) / 2) + 70) + 5, (PosYGroup2 + 20) + 7, BoxItemWH, BoxItemWH, CTItemPhu3->ItemID, CTItemPhu3->Level, CTItemPhu3->ExcellentOption, CTItemPhu3->AncientOption, 0, 2.0);//BMD MOdel
			if (pCheckMouseOver(PosXGroup1 + ((WindowW - 40) / 2) + 70, PosYGroup2 + 20, 50, 50) == 1)
			{
				BCacheInfoItemDD = CTItemPhu3;
				CacheTimeShowInfoItem = GetTickCount() + 50;
				if (GetKeyState(VK_RBUTTON) & 0x8000)
				{
					BackItemDungLuyen(3);
				}
			}
		}
		//====

		pDrawColorButton(71520, PosXGroup1, PosYGroup2 + 75, (WindowW - 40), 1, 0, 0, pMakeColor(158, 158, 158, 130));//-- Divisor	

		//===Item Ket Qua
		float PosYGroup3 = PosYGroup2 + 85;

		//===Box Item KetQua
		gCBUtil.gInfoBox(PosXGroup1 + ((WindowW - 40) / 2) + 70, PosYGroup1 + 20, BoxItemWH, BoxItemWH, 0x00000096, 0, 0); //
		//====
		ObjectItem* CTItemKetQua = &*(ObjectItem*)(BPConvertByteItem(*(DWORD*)(GetInstance() + 36), gInterface.DL_ItemKetQua));
		if (CTItemKetQua->ItemID > 0)
		{

			gCBUtil.DrawItem3D(PosXGroup1 + ((WindowW - 40) / 2) + 70, (PosYGroup1 + 20) + 7, BoxItemWH, BoxItemWH, CTItemKetQua->ItemID, CTItemKetQua->Level, CTItemKetQua->ExcellentOption, CTItemKetQua->AncientOption, 0, 2.0);//BMD MOdel
			if (pCheckMouseOver(PosXGroup1 + ((WindowW - 40) / 2) + 70, PosYGroup1 + 20, 50, 50) == 1)
			{
				BCacheInfoItemDD = CTItemKetQua;
				CacheTimeShowInfoItem = GetTickCount() + 50;
				if (GetKeyState(VK_RBUTTON) & 0x8000)
				{
					BackItemDungLuyen(4);
				}
			}
		}
		gCBUtil.gInfoBox(PosXGroup1 - 10, PosYGroup3 - 2, WindowW - 30, 70, 0x00000096, 0, 0);
		CustomFont.Draw((HFONT)pFontBold, PosXGroup1, PosYGroup3, 0xEBA000FF, 0x0, 0, 0, 1, "- Item Cần Để Dung Luyện");//

		float TextX = PosXGroup1 - 10;
		float TextY = PosYGroup3 - 2;
		float TextW = WindowW - 30;

		//===ScrollBar
		int DataListItem = gInterface.m_DungLuyenInfoList.size();

		if (DungLuyenListScrollBar == NULL)
		{
			DungLuyenListScrollBar = new CNewUIScrollBar();
			DungLuyenListScrollBar->Create(TextX, PosYGroup3 - 2, 70);
			if (DungLuyenListScrollBar)
			{
				DungLuyenListScrollBar->SetMaxPos((DataListItem <= DungLuyenListMaxPerPage) ? 0 : (DataListItem / DungLuyenListMaxPerPage) - 1);
				DungLuyenListScrollBar->SetPos(TextX + (WindowW - 20), TextY);
			}
		}
		if (DungLuyenListScrollBar)
		{
			if (UpdateMaxPosDL)
			{
				DungLuyenListScrollBar->SetMaxPos((DataListItem <= DungLuyenListMaxPerPage) ? 0 : (DataListItem / DungLuyenListMaxPerPage) - 1);
				UpdateMaxPosDL = false;
			}

			DungLuyenListScrollBar->MouseWheelWindow = pCheckMouseOver(TextX, TextY, WindowW, WindowH);
			DungLuyenListScrollBar->Render();
			DungLuyenListScrollBar->UpdateMouseEvent();
			DungLuyenListScrollBar->Update();
		}
		//===ScrollBar END

		//RenderBitmap(31539, 100- 40, KhungKhamY + WHKungKham, 32, 15, 0.0, 0.0, 0.855, 0.855, 1, 1, 0); //<<

		int Count = 0;
		int VipCharListPage = DungLuyenListScrollBar->GetCurPos();
		for (int n = (VipCharListPage * DungLuyenListMaxPerPage); n < DataListItem; n++)
		{
			if (Count >= DungLuyenListMaxPerPage) break;
			CustomFont.Draw((HFONT)pFontNormal, TextX + 10, TextY + (Count * 12) + 12, 0xFFDD00FF, 0x0, TextW, 0, 1, "1. (%s)", BGetItemName(gInterface.m_DungLuyenInfoList[n].IndexItem, SET_ITEMOPT_LEVEL((gInterface.m_DungLuyenInfoList[n].Level == 255) ? 0 : gInterface.m_DungLuyenInfoList[n].Level)));//

			if (gInterface.m_DungLuyenInfoList[n].Luck >= 1)
			{
				CustomFont.Draw((HFONT)pFontNormal, TextX - 50, TextY + (Count * 12) + 12, 0xFFDD00FF, 0x0, TextW, 0, 4, "+(M.Mắn)");//
			}

			if (gInterface.m_DungLuyenInfoList[n].Exc >= 1)
			{
				CustomFont.Draw((HFONT)pFontNormal, TextX - 85, TextY + (Count * 12) + 12, 0xFFDD00FF, 0x0, TextW, 0, 4, "+(H.Hoản)");//
			}

			//if (gInterface.m_DungLuyenInfoList[n].Option >= 1)
			//{
			//	CustomFont.Draw((HFONT)pFontNormal, TextX - 50, TextY + (Count * 12) + 12, 0xFFDD00FF, 0x0, TextW, 0, 4, "+ %d (Opt)", gInterface.m_DungLuyenInfoList[n].Option);//
			//}


			if (gInterface.m_DungLuyenInfoList[n].Dur >= 1)
			{
				CustomFont.Draw((HFONT)pFontBold, TextX, TextY + (Count * 12) + 12, 0xFFDD00FF, 0x0, TextW, 0, 4, "%s Stack", BNumberFormat(gInterface.m_DungLuyenInfoList[n].Dur));//
			}
			Count++;

		}


		//====
		pDrawColorButton(71520, PosXGroup1, PosYGroup3 + 75, (WindowW - 40), 1, 0, 0, pMakeColor(158, 158, 158, 130));//-- Divisor
		gCBUtil.gInfoBox(PosXGroup1 - 10, PosYGroup3 + 80, WindowW - 30, 90, 0x00000096, 0, 0);
		//===Info Text
		float PosYTextInfo = PosYGroup3 + 85;
		int CountText = 0;


		CustomFont.Draw((HFONT)pFontBold, PosXGroup1, PosYTextInfo + (10 * CountText++), 0xEBA000FF, 0x0, 0, 0, 1, "Dung Luyện Vật Phẩm:");//

		if (gInterface.RateDL != 0)
		{
			CustomFont.Draw((HFONT)pFontBold, PosXGroup1 + 110, PosYTextInfo, 0xB752FFFF, 0x0, 0, 0, 1, "[%s]", gInterface.TextDL);//
		}
		CustomFont.Draw((HFONT)pFontBold, PosXGroup1, PosYTextInfo + (20 * 1), 0xEBA000FF, 0x0, 0, 0, 1, "Thất Bại:");//
		if (gInterface.TypeDL == 0)
		{
			CustomFont.Draw((HFONT)pFontBold, PosXGroup1 + 110, PosYTextInfo + (20 * CountText++), 0xFF6600FF, 0x0, 0, 0, 1, "Trả lại item chính");//
		}
		else
			CustomFont.Draw((HFONT)pFontBold, PosXGroup1 + 110, PosYTextInfo + (20 * CountText++), 0x62FF00FF, 0x0, 0, 0, 1, "Mất toàn bộ");//

		CustomFont.Draw((HFONT)pFontBold, PosXGroup1, PosYTextInfo + (20 * CountText++), 0xEBA000FF, 0x0, 0, 0, 1, "Tỉ Lệ Thành Công");//


		{
			CustomFont.Draw((HFONT)pFontBold, PosXGroup1 + 110, PosYTextInfo + (20 * 2), 0x62FF00FF, 0x0, 0, 0, 1, "%d%%", gInterface.RateDL);//
		}

		//==Button
		float ButtonW = 115;
		float ButtonH = 25;
		float ButtonX = PosXGroup1 + ((WindowW - 40) / 2) - (ButtonW / 2);
		float ButtonY = (StartY + WindowH) - 20 - ButtonH;
		//if (gElemental.gDrawButton(ButtonX, ButtonY, ButtonW, 12, "Dung Luyện")) //Dung Luyen
		if (gInterface.DL_EffectsMix && DungLuyenEffect > GetTickCount() && DungLuyenEffect != 0)
		{
			RenderMixEffect(gInterface.DL_EffectsMix, PosXGroup1 + ((WindowW - 40) / 2) + 70, PosYGroup1 + 20, 3, 3);
		}
		else if (DungLuyenEffect != 0)
		{
			DungLuyenEffect = 0;
			if (gInterface.DL_ActiveMix)
			{
				if ((GetTickCount() - gInterface.Data[eWindowDungLuyenItem].EventTick) > 300 && DungLuyenEffect == 0)
				{
					XULY_CGPACKET pMsg;
					pMsg.header.set(0xD3, 0x2D, sizeof(pMsg));
					pMsg.ThaoTac = 113; //
					DataSend((LPBYTE)& pMsg, pMsg.header.size);
					gInterface.Data[eWindowDungLuyenItem].EventTick = GetTickCount();
				}
			}
		}
		if (gElemental.gDrawButton(ButtonX, ButtonY, ButtonW, Main_Font_Height, "Dung Luyện"))
		{
			//if (nInterface.BDrawButton(ButtonX, ButtonY, ButtonW, ButtonH, FALSE, gOther.Text_Event[49]))
			//{
			if (gInterface.DL_ActiveMix)
			{

				gInterface.DL_EffectsMix = 1;


			}
			else
			{
				gElemental.OpenMessageBox("Error", "Vui lòng đặt thêm Item !");
			}
			DungLuyenEffect = GetTickCount() + 2000;
		}


	}

}

void Interface::NhanListItemDungLuyen(CSEV_COUNTLIST* lpMsg) // OK
{
	m_DungLuyenInfoList.clear();

	for (int n = 0; n < lpMsg->Count; n++)
	{
		ITEM_INFO_DATA* lpInfo = (ITEM_INFO_DATA*)(((BYTE*)lpMsg) + sizeof(CSEV_COUNTLIST)+(sizeof(ITEM_INFO_DATA)* n));

		m_DungLuyenInfoList.push_back(*lpInfo);
	}

}


#endif


#if (CongHuongV2)
#define BPConvertByteItem ((int (__thiscall*)(int a1, void *lp)) 0x7E1B10)
#define BPDrawInfoItem			((signed int (__thiscall*)(int a1, JCCoord a5, int a6, int a7, int a8, int a9)) 0x007E3E30)
#define pIsKeyRepeat	((bool(*)(int))0x00791090)

//=====================================================================================================================
void Interface::XoaDataCongHuong()
{

	gInterface.m_ScrollPos = 0;

	gInterface.CH_EffectMixOn = 0;
	gInterface.CH_TyLeThanhCong = -1;
	gInterface.CH_ResetMix = -1;
	gInterface.CH_TypeMix = -1;
	gInterface.CH_CheckLvItem = 0;
	for (int n = 0; n < 3; n++)
	{
		gInterface.CH_IndexItem[n] = -1;
		gInterface.CH_CoinMix[n] = -1;
		ZeroMemory(gInterface.CH_InfoItem[n], sizeof(gInterface.CH_InfoItem[n]));
	}
	//==== Del Cache Item
	XULY_CGPACKET pMsg;
	pMsg.header.set(0xFA, 0x16, sizeof(pMsg));
	pMsg.ThaoTac = 0; //RollBack Item
	DataSend((LPBYTE)& pMsg, pMsg.header.size);
	//pDrawMessage("XoaDataCongHuong",1);
}
int mViTriScroll = 0;
void Interface::EventScrollPos(MOUSEHOOKSTRUCTEX* Mouse, WPARAM wParam) //Load Cac Cua So Custom
{
	if (gInterface.Data[eWindow_CongHuong].OnShow == 1 && IsWorkZone2(5 + 190, 45 + 35, 140, 295))
	{
		if (wParam == WM_MOUSEWHEEL)
		{
			if ((int)Mouse->mouseData > 0)
			{
				if (this->m_ScrollPos > 0)
				{
					this->m_ScrollPos--;
				}
			}

			if ((int)Mouse->mouseData < 0)
			{
				if (this->m_ScrollPos < gItemManager.GetCountPhoiCongHuong(gInterface.CH_IndexItem[0], gInterface.CH_TypeMix) && mViTriScroll < 245)
				{
					this->m_ScrollPos++;
				}
			}
			return;
		}

	}
}
//=== Draw Cong Huong WIndow
void Interface::DrawWindowCongHuong()
{
	// ----
	// ----
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
		if (gInterface.Data[eWindow_CongHuong].OnShow == true)
		{
			gInterface.Data[eWindow_CongHuong].OnShow = false;
			pSetCursorFocus = false;
			return;
		}
	}
	if (gInterface.Data[eWindow_CongHuong].OnShow == false)
	{
		if (gInterface.CH_IndexItem[0] != -1 || gInterface.CH_IndexItem[1] != -1 || gInterface.CH_IndexItem[2] != -1)
		{
			gInterface.XoaDataCongHuong();
		}
		return;
	}
	gInterface.OpenWindow(ObjWindow::Inventory);
	pSetCursorFocus = true;
	float CuaSoW = 340;
	float CuaSoH = 345;
	float StartX = 20.0;
	float StartY = 45.0;
	int GetInfoLoadItem = 0;
	pSetBlend(true);

	//gElemental.gDrawWindowCustom(StartX - 5, StartY, CuaSoW, CuaSoH, eWindow_CongHuong, "Cộng Hưởng Trang Bị");

	gCBUtil.gDrawWindowCustom(&StartX, &StartY, CuaSoW, CuaSoH, eWindow_CongHuong, "Cộng Hưởng Trang Bị");


	//=== Draw Cong Huong
	gCBUtil.gInfoBox(StartX + 7, StartY + 35, 170, 130, 0x00000096, 0, 0);
	CustomFont.Draw(CustomFont.FontNormal, StartX + 7, StartY + 39, 0xFFFFFFFF, 0x0, 170, 0, 3, "Dùng Chuột Phải Để Thao Tác");// "(Dung Chuot Phai De Thao Tac)"); //
	//==== Khung INV
	gCBUtil.gItemBoxInv(StartX + 12, StartY + 55, 4, 2, (gInterface.CH_IndexItem[0] > -1) ? 1 : 0); //Item Chinh
	gCBUtil.gItemBoxInv(StartX + 12 + 50, StartY + 55, 4, 2, (gInterface.CH_IndexItem[1] > -1) ? 1 : 0); //Phoi
	pDrawButton(31538, StartX + 12 + 50 + 45, StartY + 90, 15.0, 7.0, 13.0, 0); //-->>
	gCBUtil.gItemBoxInv(StartX + 12 + 50 + 45 + 20, StartY + 55, 4, 2, (gInterface.CH_IndexItem[2] > -1) ? 1 : 0); //Xem Truoc
	//====
	CustomFont.Draw(CustomFont.FontNormal, StartX + 12, StartY + 55 + (21 * 4), 0xFFFFFFFF, 0x0, 45, 0, 3, "Item Gốc");//"Item Chinh"); //
	CustomFont.Draw(CustomFont.FontNormal, StartX + 12, StartY + 55 + (21 * 4) + 10, ((gInterface.CH_IndexItem[0] > -1) ? 0x2B8EFFFF : 0xDE1616FF), 0x0, 45, 0, 3, "%d/1", (gInterface.CH_IndexItem[0] > -1) ? 1 : 0); //

	if (gInterface.CH_IndexItem[0] != -1)
	{
		GetInfoLoadItem = BPConvertByteItem(*(DWORD*)(GetInstance() + 36), gInterface.CH_InfoItem[0]);
		//===Draw Img Item

		gPostInterface.DrawItemIMG(StartX + 12, StartY + 22, (21 * 2), (21 * 4), *(WORD*)GetInfoLoadItem, *(DWORD*)(GetInfoLoadItem + 2), *(BYTE*)(GetInfoLoadItem + 23), *(BYTE*)(GetInfoLoadItem + 24), 0);
	}
	//===Draw Img Item
	if (gInterface.CH_IndexItem[1] != -1)
	{
		GetInfoLoadItem = BPConvertByteItem(*(DWORD*)(GetInstance() + 36), gInterface.CH_InfoItem[1]);
		//===Draw Img Item
		gPostInterface.DrawItemIMG(StartX + 12 + 50, StartY + 22, (21 * 2), (21 * 4), *(WORD*)GetInfoLoadItem, *(DWORD*)(GetInfoLoadItem + 2), *(BYTE*)(GetInfoLoadItem + 23), *(BYTE*)(GetInfoLoadItem + 24), 0);
	}
	CustomFont.Draw(CustomFont.FontNormal, StartX + 12 + 50, StartY + 55 + (21 * 4), 0xFFFFFFFF, 0x0, 45, 0, 3, "Item Phụ");//"Item Phoi"); //
	CustomFont.Draw(CustomFont.FontNormal, StartX + 12 + 50, StartY + 55 + (21 * 4) + 10, ((gInterface.CH_IndexItem[1] > -1) ? 0x2B8EFFFF : 0xDE1616FF), 0x0, 45, 0, 3, "%d/1", (gInterface.CH_IndexItem[1] > -1) ? 1 : 0); //


	CustomFont.Draw(CustomFont.FontNormal, StartX + 12 + 50 + 45 + 20, StartY + 55 + (21 * 4), 0xFFFFFFFF, 0x0, 45, 0, 3, "Kết Quả");//"Xem Truoc"); //
	//===Draw Img Item
	if (gInterface.CH_IndexItem[2] != -1)
	{
		GetInfoLoadItem = BPConvertByteItem(*(DWORD*)(GetInstance() + 36), gInterface.CH_InfoItem[2]);
		//===Draw Img Item
		gPostInterface.DrawItemIMG(StartX + 12 + 50 + 45 + 20, StartY + 22, (21 * 2), (21 * 4), *(WORD*)GetInfoLoadItem, *(DWORD*)(GetInfoLoadItem + 2), *(BYTE*)(GetInfoLoadItem + 23), *(BYTE*)(GetInfoLoadItem + 24), 0);
	}


	//== Draw List Phoi
	gCBUtil.gInfoBox(StartX + 190, StartY + 35, 120, 295, 0x00000096, 0, 0);
	CustomFont.Draw(CustomFont.FontBold, StartX + 195, StartY + 40, 0xFFBA19FF, 0x0, 90, 0, 1, "Danh Sách Item Phụ");//"Danh Sach Phoi:"); //
	int iMaxScrollCount = 0;
	int CountItem = 0;
	if (gInterface.CH_IndexItem[0] != -1)
	{
		std::map<int, ITEM_INFO>::iterator itemgoc = gItemManager.m_ItemInfo.find(gInterface.CH_IndexItem[0]);

		if (itemgoc != gItemManager.m_ItemInfo.end())
		{
			for (std::map<int, ITEM_INFO>::iterator it = gItemManager.m_ItemInfo.begin(); it != gItemManager.m_ItemInfo.end(); it++)
			{
				if (it == gItemManager.m_ItemInfo.end() || (CountItem - gInterface.m_ScrollPos) > 20)
				{
					break;
				}
				if ((it->second.ItemIndex / 512) == (itemgoc->second.ItemIndex / 512))
				{
					if (it->second.Level >= (itemgoc->second.Level) && gInterface.CH_TypeMix == 1)
					{
						iMaxScrollCount++;
					}
					else if (gInterface.CH_TypeMix == 0)
					{
						iMaxScrollCount++;
					}
					else if (gInterface.CH_TypeMix == 2 && itemgoc->second.ItemIndex == it->second.ItemIndex)
					{
						iMaxScrollCount++;
					}
					else {
						continue;
					}
					if (iMaxScrollCount < gInterface.m_ScrollPos)
					{
						continue;
					}

					CustomFont.Draw(CustomFont.FontNormal, StartX + 195, StartY + 55 + (13 * CountItem), 0x2B8EFFFF, 0x0, 120, 0, 1, "- %s", it->second.Name); //
					CountItem++;

				}
				if (CountItem >= 21)
				{
					break;
				}

			}
		}
	}
	else
	{
		CustomFont.Draw(CustomFont.FontNormal, StartX + 195, StartY + 55 + (13 * CountItem), 0xDE1616FF, 0x0, 120, 0, 1, ""); //Cần Đặt Item Chính Vào Trước !
	}
	float flScrollDiv = 0;

	if (gItemManager.GetCountPhoiCongHuong(gInterface.CH_IndexItem[0], gInterface.CH_TypeMix) > 0)
	{
		flScrollDiv = (10 * 30) / gItemManager.GetCountPhoiCongHuong(gInterface.CH_IndexItem[0], gInterface.CH_TypeMix);	//
	}
	pDrawButton(0x7A29, StartX + 310, StartY + 55 + (gInterface.m_ScrollPos * flScrollDiv), 15, 30, 0, 0); //Scroll
	mViTriScroll = (int)(gInterface.m_ScrollPos * flScrollDiv);
	if (pCheckMouseOver(StartX + 310, StartY + 55 + (gInterface.m_ScrollPos * flScrollDiv), 15, 30) == 1)
	{
		if (pIsKeyPress(VK_LBUTTON) && GetTickCount() - gInterface.Data[eWindow_CongHuong].EventTick > 10)
		{
			PlayBuffer(25, 0, 0);
			glColor3f(1.0f, 0.0f, 0.0f);
			gInterface.Data[eWindow_CongHuong].EventTick = GetTickCount();
		}
		else if (pIsKeyRepeat(VK_LBUTTON))
		{
			int mSrollY = (int)(StartY + 55 + (gInterface.m_ScrollPos * flScrollDiv) + 15);
			if ((pCursorY - mSrollY) > 5 && gInterface.m_ScrollPos < gItemManager.GetCountPhoiCongHuong(gInterface.CH_IndexItem[0], gInterface.CH_TypeMix) && mViTriScroll < 245)
			{
				gInterface.m_ScrollPos++;
				//ScorllY = pCursorY;
			}
			else if ((mSrollY - pCursorY) > 5 && gInterface.m_ScrollPos > 0)
			{
				gInterface.m_ScrollPos--;
				//ScorllY = pCursorY;
			}

		}

		pDrawColorButton(0x7A29, StartX + 310, StartY + 55 + (gInterface.m_ScrollPos * flScrollDiv), 15, 30, 0, 0, pMakeColor(255, 204, 20, 130));
		gInterface.DrawToolTip(gObjUser.m_CursorX + 20, gObjUser.m_CursorY, "Scroll");
	}

	//================================================

	//== Draw Info Mix CH
	gCBUtil.gInfoBox(StartX + 7, StartY + 46 + 130, 170, 100, 0x00000096, 0, 0);
	CustomFont.Draw(CustomFont.FontNormal, StartX + 15, StartY + 180, 0xFFFFFFFF, 0x0, (170 / 2), 0, 1, "Tỷ Lệ Thành Công: ");//"Ty le thanh cong:"); //
	if (gInterface.CH_TyLeThanhCong == -1)
	{
		CustomFont.Draw(CustomFont.FontNormal, StartX + 20 + (170 / 2), StartY + 180, 0xDE1616FF, 0x0, 0, 0, 1, "");//"Cần Đặt Item Chính Vào Trước"); //
	}
	else
	{
		CustomFont.Draw(CustomFont.FontNormal, StartX + 20 + (170 / 2), StartY + 180, 0x19FF9FFF, 0x0, 0, 0, 1, "%d %%", gInterface.CH_TyLeThanhCong);//
	}
	//==================
	CustomFont.Draw(CustomFont.FontNormal, StartX + 15, StartY + 180 + 13, 0xFFFFFFFF, 0x0, (170 / 2), 0, 1, "Yêu Cầu Reset: ");//"Yeu cau Reset:"); //
	if (gInterface.CH_ResetMix == -1)
	{
		CustomFont.Draw(CustomFont.FontNormal, StartX + 20 + (170 / 2), StartY + 180 + 13, 0xDE1616FF, 0x0, 0, 0, 1, "");//"Cần Đặt Item Chính Vào Trước"); //
	}
	else
	{
		CustomFont.Draw(CustomFont.FontNormal, StartX + 20 + (170 / 2), StartY + 180 + 13, 0x19FF9FFF, 0x0, 0, 0, 1, "%d (RS)", gInterface.CH_ResetMix);//
	}
	//=======================
	CustomFont.Draw(CustomFont.FontNormal, StartX + 15, StartY + 180 + 26, 0xFFFFFFFF, 0x0, (170 / 2), 0, 1, "Thành Công");// "Kieu Cong Huong:"); //
	if (gInterface.CH_TypeMix == -1)
	{
		CustomFont.Draw(CustomFont.FontNormal, StartX + 20 + (170 / 2), StartY + 180 + 26, 0xDE1616FF, 0x0, 0, 0, 1, "");//"Cần Đặt Item Chính Vào Trước"); //
	}
	else
	{
		CustomFont.Draw(CustomFont.FontNormal, StartX + 20 + (170 / 2), StartY + 180 + 26, 0x19FF9FFF, 0x0, 0, 0, 1, "%s", "");//
	}
	//======================================================
	CustomFont.Draw(CustomFont.FontNormal, StartX + 15, StartY + 225, 0xFFFFFFFF, 0x0, (170 / 2), 0, 1, "Phí Sử Dụng 1 Lần: ");//"Chi Phi:"); //
	//===============
	CustomFont.Draw(CustomFont.FontNormal, StartX + 15, StartY + 225 + 13, 0xFFBA19FF, 0x0, (170 / 2), 0, 1, "WC: ");//"- WCoin"); //
	if (gInterface.CH_CoinMix[0] == -1)
	{
		CustomFont.Draw(CustomFont.FontNormal, StartX + 20 + (170 / 2), StartY + 225 + 13, 0xDE1616FF, 0x0, 0, 0, 1, ""); //Cần Đặt Item Chính Vào Trước
	}
	else {
		CustomFont.Draw(CustomFont.FontNormal, StartX + 20 + (170 / 2), StartY + 225 + 13, 0x19FF9FFF, 0x0, 0, 0, 1, "%s", BNumberFormat(gInterface.CH_CoinMix[0])); //
	}
	//==============
	CustomFont.Draw(CustomFont.FontNormal, StartX + 15, StartY + 225 + (13 * 2), 0xFFBA19FF, 0x0, (170 / 2), 0, 1, "WP: ");//"- WCoinP"); //
	if (gInterface.CH_CoinMix[1] == -1)
	{
		CustomFont.Draw(CustomFont.FontNormal, StartX + 20 + (170 / 2), StartY + 225 + (13 * 2), 0xDE1616FF, 0x0, 0, 0, 1, ""); //Cần Đặt Item Chính Vào Trước
	}
	else {
		CustomFont.Draw(CustomFont.FontNormal, StartX + 20 + (170 / 2), StartY + 225 + (13 * 2), 0x19FF9FFF, 0x0, 0, 0, 1, "%s", BNumberFormat(gInterface.CH_CoinMix[1])); //
	}

	CustomFont.Draw(CustomFont.FontNormal, StartX + 15, StartY + 225 + (13 * 3), 0xFFBA19FF, 0x0, (170 / 2), 0, 1, "GP: ");//"- GobinP"); //
	//==============
	CustomFont.Draw(CustomFont.FontNormal, StartX + 15, StartY + 225 + (13 * 2), 0xFFBA19FF, 0x0, (170 / 2), 0, 1, "WP: ");//"- WCoinP"); //
	if (gInterface.CH_CoinMix[2] == -1)
	{
		CustomFont.Draw(CustomFont.FontNormal, StartX + 20 + (170 / 2), StartY + 225 + (13 * 3), 0xDE1616FF, 0x0, 0, 0, 1, ""); //Cần Đặt Item Chính Vào Trước
	}
	else {
		CustomFont.Draw(CustomFont.FontNormal, StartX + 20 + (170 / 2), StartY + 225 + (13 * 3), 0x19FF9FFF, 0x0, 0, 0, 1, "%s", BNumberFormat(gInterface.CH_CoinMix[2])); //
	}
	//== Button Mix
	gCBUtil.gInfoBox(StartX + 7, StartY + 50 + 140 + 100, 170, 40, 0x00000096, 0, 0);
	pDrawButton(31419, StartX + 7 + (170 / 2) - 15, StartY + 55 + 140 + 100, 44.0, 35.0, 0, 0); //ButtonMix
	if (pCheckMouseOver(StartX + 7 + (170 / 2) - 15, StartY + 55 + 140 + 100, 44.0, 35.0) == 1 && gInterface.CH_IndexItem[2] != -1)
	{
		if (GetTickCount() - gInterface.Data[eWindow_CongHuong].EventTick > 300)
		{
			if (GetKeyState(1) & 0x8000)
			{
				PlayBuffer(25, 0, 0);
				glColor3f(1.0f, 0.0f, 0.0f);
				gInterface.LockMouseMoveClick = GetTickCount() + 500;
				gInterface.Data[eWindow_CongHuong].EventTick = GetTickCount();
				gInterface.CH_EffectMixOn ^= 1;
				//==== Send Mix
				XULY_CGPACKET pMsg;
				pMsg.header.set(0xFA, 0x17, sizeof(pMsg));
				pMsg.ThaoTac = 1; //RollBack Item
				DataSend((LPBYTE)& pMsg, pMsg.header.size);
			}
		}
		pDrawColorButton(31419, StartX + 7 + (170 / 2) - 15, StartY + 55 + 140 + 100, 44.0, 35.0, 0, 0, pMakeColor(255, 204, 20, 130));
		gInterface.DrawToolTip(gObjUser.m_CursorX + 20, gObjUser.m_CursorY, "Mix Item");
	}
	if (gInterface.CH_EffectMixOn)
	{
		RenderMixEffect(gInterface.CH_EffectMixOn, StartX + 12 + 50 + 45 + 20, StartY + 55);
	}
	//== Draw Info Item In mouse over
	JCCoord B;
	BYTE ItemInfo[3][MAX_ITEM_INFO] = { 0x00 };
	//=== Item Chinh
	if (pCheckMouseOver(StartX + 12, StartY + 55, 2 * 21, 4 * 21) == 1 && gInterface.CH_IndexItem[0] != -1)
	{
		if (GetTickCount() - gInterface.Data[eWindow_CongHuong].EventTick > 300)
		{
			if (GetKeyState(VK_RBUTTON) & 0x8000)
			{
				PlayBuffer(25, 0, 0);
				gInterface.Data[eWindow_CongHuong].EventTick = GetTickCount();
				XULY_CGPACKET pMsg;
				pMsg.header.set(0xFA, 0x16, sizeof(pMsg));
				pMsg.ThaoTac = 0; //RollBack Item
				DataSend((LPBYTE)& pMsg, pMsg.header.size);
			}
		}
		B.X = (int)StartX + 130;
		B.Y = (int)StartY + 55;
		GetInfoLoadItem = BPConvertByteItem(*(DWORD*)(GetInstance() + 36), gInterface.CH_InfoItem[0]);
		BPDrawInfoItem(*(DWORD*)(GetInstance() + 308), B, GetInfoLoadItem, 0, 0, 0);

	}
	//=== Phoi Item
	if (pCheckMouseOver(StartX + 12 + 50, StartY + 55, 2 * 21, 4 * 21) == 1 && gInterface.CH_IndexItem[1] != -1)
	{
		if (GetTickCount() - gInterface.Data[eWindow_CongHuong].EventTick > 300)
		{
			if (GetKeyState(VK_RBUTTON) & 0x8000)
			{
				PlayBuffer(25, 0, 0);
				gInterface.Data[eWindow_CongHuong].EventTick = GetTickCount();
				XULY_CGPACKET pMsg;
				pMsg.header.set(0xFA, 0x16, sizeof(pMsg));
				pMsg.ThaoTac = 2; //RollBack Item
				DataSend((LPBYTE)& pMsg, pMsg.header.size);
			}
		}
		B.X = (int)StartX + 130 + 50;
		B.Y = (int)StartY + 55;
		GetInfoLoadItem = BPConvertByteItem(*(DWORD*)(GetInstance() + 36), gInterface.CH_InfoItem[1]);
		BPDrawInfoItem(*(DWORD*)(GetInstance() + 308), B, GetInfoLoadItem, 0, 0, 0);

	}
	//== Xem Truoc
	if (pCheckMouseOver(StartX + 12 + 50 + 45 + 20, StartY + 55, 2 * 21, 4 * 21) == 1 && gInterface.CH_IndexItem[2] != -1)
	{
		B.X = (int)StartX + 130 + 50 + 45 + 20;
		B.Y = (int)StartY + 55;
		GetInfoLoadItem = BPConvertByteItem(*(DWORD*)(GetInstance() + 36), gInterface.CH_InfoItem[2]);

		BPDrawInfoItem(*(DWORD*)(GetInstance() + 308), B, GetInfoLoadItem, 0, 0, 0);
	}
	pGLSwitch();
	glColor4f(1.0, 1.0, 1.0, 1.0);
	pSetBlend(0);
	DeleteObject(CustomFont.FontNormal);


}
#endif



#if(VONGQUAY_NEW)
#include <cmath>

CNewUIScrollBar* ListVongQuay = nullptr;
int MaxListVQInPage = 5;
int MaxListItemVQInPage = 5;
int SelectTypeVQ = 1;
int Chay = -1;
float CountVong = 0.5;
int solan = 1;

void Interface::OpenWindowVongQuay() //ham goi mo cua so
{
	if (GetTickCount() < gInterface.Data[eWindowVongQuay].EventTick + 500) return;
	gInterface.Data[eWindowVongQuay].EventTick = GetTickCount();
	if (!gInterface.Data[eWindowVongQuay].OnShow)
	{

		XULY_CGPACKET pMsg;
		pMsg.header.set(0xD3, 0x8C, sizeof(pMsg));
		pMsg.ThaoTac = 1;
		DataSend((LPBYTE)&pMsg, pMsg.header.size);

		pMsg.header.set(0xD3, 0x8B, sizeof(pMsg));
		pMsg.ThaoTac = 1; //
		DataSend((LPBYTE)&pMsg, pMsg.header.size);
	}
	else
	{
		gInterface.Data[eWindowVongQuay].OnShow = 0;
	}
}


void Interface::DrawWindowVQ()
{
	// ----
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
		if (gInterface.Data[eWindowVongQuay].OnShow == true)
		{
			gInterface.Data[eWindowVongQuay].OnShow = false;
			pSetCursorFocus = false;
			return;
		}
	}

	if (!gInterface.Data[eWindowVongQuay].OnShow)
	{
		if (ListVongQuay) ListVongQuay = nullptr;
		if (SelectTypeVQ != 1) SelectTypeVQ = 1;
		gInterface.StartRollSau = -1;
		gInterface.IndexItemSau = -1;


		return;
	}

	float WindowW = 420;
	float WindowH = 300;
	gInterface.Data[eWindowVongQuay].Width = WindowW;
	float StartX = (MAX_WIN_WIDTH / 2) - (WindowW / 2);
	float StartY = ((MAX_WIN_HEIGHT - 51) / 2) - (WindowH / 2);

	//if (!gCentral.GiaoDienCash(eWindowVongQuay, &StartX, &StartY, WindowW, WindowH, "Vòng Quay New"))
	//gElemental.gDrawWindowCustom(StartX, StartY, WindowW, WindowH, eWindowVongQuay, "Vòng Quay May Mắn");

	gCBUtil.gDrawWindowCustom(&StartX, &StartY, WindowW, WindowH, eWindowVongQuay, "Vòng Quay May Mắn");

	{

		pSetBlend(true);
		glColor3f(1.0, 1.0, 1.0);


		//CustomFont.Draw(CustomFont.FontBold, StartX, StartY + 25, 0x00FFDDFF, 0x0, WindowW, 0, 3, gOther.Text_NapGame[21]);
		//CustomFont.Draw(CustomFont.FontBold, StartX, StartY + 35, 0xFF9100FF, 0x0, WindowW, 0, 3, gOther.Text_NapGame[22]);
		//CustomFont.Draw(CustomFont.FontBold, StartX, StartY + 50, 0x3CFF00FF, 0x0, WindowW, 0, 3, gOther.Text_NapGame[23], BNumberFormat(TongSoDaNap));

		//===Info Yeu Cau Moc Nap
		float InfoMocNapX = (StartX + 10) + 3;
		float InfoMocNapY = (StartY + 15);
		float TyleInfoYeuCau = 7.5f;
		float WInfo = (WindowW - 20) / 10;
		float WProcess = (WInfo * (TyleInfoYeuCau - 2.7));
		float WButton = 88;
		float HInfo = WindowH - 160;

		gCBUtil.gInfoBox((StartX + WindowW) - 110, InfoMocNapY + 15, 85, 125, 0x00000096, 0, 0);

		gCBUtil.gInfoBox((StartX + WindowW) - 110, InfoMocNapY + 160, 85, 105, 0x00000096, 0, 0);


		//Scroll Bar

		int DataListVQ = mDataVongQuayClient.DanhSachVongQuay.size();
		if (!ListVongQuay)
		{
			ListVongQuay = new CNewUIScrollBar();
			ListVongQuay->Create((StartX + WindowW) - 15, InfoMocNapY + 10, HInfo);
			if (ListVongQuay)
			{
				ListVongQuay->SetMaxPos((DataListVQ <= MaxListVQInPage) ? 0 : (DataListVQ / MaxListVQInPage));
				ListVongQuay->SetPos((StartX + WindowW) - 15, InfoMocNapY + 10);
			}
		}
		if (ListVongQuay)
		{
			if (gInterface.Data[eWindowVongQuay].OnClick)
			{
				ListVongQuay->SetPos((StartX + WindowW) - 15, InfoMocNapY + 10);
				ListVongQuay->SetCurPos(0);
			}
			ListVongQuay->MouseWheelWindow = pCheckMouseOver(InfoMocNapX, InfoMocNapY, WindowW, WindowH);
			ListVongQuay->Render();
			ListVongQuay->UpdateMouseEvent();
			ListVongQuay->Update();
		}

		float KhoangCachYMocNap = 24;
		int MixItemListPage = ListVongQuay->GetCurPos();
		int MaxList = 0;

		for (int n = (MixItemListPage * MaxListVQInPage); n < DataListVQ; n++)
		{

			//==Xem
			if (gElemental.gDrawButton((StartX + WindowW) - 105, InfoMocNapY + 20, 110, 11, mDataVongQuayClient.DanhSachVongQuay[n].Name, WButton) && (GetTickCount() - gInterface.Data[eWindowVongQuay].EventTick) > 300 && gInterface.StartRollSau < 1) //"Xem"
			{

				SelectTypeVQ = mDataVongQuayClient.DanhSachVongQuay[n].IndexVongQuay;
				Chay = -1;
				gInterface.Data[eWindowVongQuay].OnShow = true;
				gInterface.Data[eWindowVongQuay].EventTick = GetTickCount();
				XULY_CGPACKET pMsg;
				pMsg.header.set(0xD3, 0x8B, sizeof(pMsg));
				pMsg.ThaoTac = SelectTypeVQ; //
				DataSend((LPBYTE)&pMsg, pMsg.header.size);
				gInterface.IndexItemSau = -1;
			}




			InfoMocNapY = InfoMocNapY + (KhoangCachYMocNap);
			MaxList++;
			if (MaxList >= MaxListItemVQInPage) break;
		}

		if ((GetTickCount() - gInterface.Data[eTIME].EventTick) > 6000)
		{

			if (gElemental.gDrawButton(StartX + 115, StartY + 200, 100, 11, "Quay", 60) && (GetTickCount() - gInterface.Data[eTIME].EventTick) > 6000) //"Nhận"
			{
				XULY_CGPACKET_SOLAN pMsg;
				pMsg.header.set(0xD3, 0x8A, sizeof(pMsg));
				pMsg.ThaoTac = SelectTypeVQ; //
				pMsg.SoLan = 1;
				//gInterface.DrawMessage(1, "%d", pMsg.ThaoTac);
				DataSend((LPBYTE)&pMsg, pMsg.header.size);
				gInterface.Data[eTIME].EventTick = GetTickCount();
			}
		}




		float PosYCoinNhan = StartY + 185;
		CustomFont.Draw(CustomFont.FontBold, (StartX + WindowW) - 105, PosYCoinNhan - 5, 0xFFDE26FF, 0x3a4b3978, 90, 0, 3, "Yêu Cầu"); //"Yêu Cầu");
		CustomFont.Draw(CustomFont.FontNormal, (StartX + WindowW) - 105, PosYCoinNhan + (10 * 1), 0xFF8214FF, 0x0, WindowW, 0, 1, "+WCoin : %s", BNumberFormat(mDataListItemVongQuayClient.WCYC));			//Text3 = "+ WCoin : %s
		CustomFont.Draw(CustomFont.FontNormal, (StartX + WindowW) - 105, PosYCoinNhan + (10 * 2), 0xFF8214FF, 0x0, WindowW, 0, 1, "+WCoinP :%s", BNumberFormat(mDataListItemVongQuayClient.WPYC));		  //Text4 = "+ WCoinP : %
		CustomFont.Draw(CustomFont.FontNormal, (StartX + WindowW) - 105, PosYCoinNhan + (10 * 3), 0xFF8214FF, 0x0, WindowW, 0, 1, "+GobinP :%s", BNumberFormat(mDataListItemVongQuayClient.GPYC));		  //Text5 = "+ GobinP : %
		if (mDataListItemVongQuayClient.CountItem > 0)
		{
			CustomFont.Draw(CustomFont.FontNormal, (StartX + WindowW) - 105, PosYCoinNhan + (10 * 4), 0xFF8214FF, 0x0, WindowW, 0, 1, "+Cần : %s", BNumberFormat(mDataListItemVongQuayClient.CountItem));		  //Text6 = " + Ruud : % s"
			CustomFont.Draw(CustomFont.FontNormal, (StartX + WindowW) - 105, PosYCoinNhan + (10 * 5) + 5, 0x26FFD7A4, 0x0, WindowW, 0, 1, "%s", BGetItemName(mDataListItemVongQuayClient.IndexYC, 0));//
		}



		int DataListItem = mDataListItemVongQuayClient.ListItemVongQuay.size();
		float Radius = 100.0f; // Set the radius of the circular layout
		float AngleStep = 2 * 3.14159265358979323846 / 12.0f; // Divide the circle into 12 equal angles
		float WBox = 30;
		int BBShowInfoItem = -1;
		DWORD boxColor = 0x00000096;
		unsigned int timeInterval2 = 10; // 5 seconds
		unsigned int currentTime2 = GetTickCount();
		unsigned int colorIndex2 = (currentTime2 / timeInterval2) % 2;



		if (gInterface.StartRollSau >= 1)
		{
			if (Chay >= 12)
			{
				Chay = 0;
				CountVong += 0.1;

			}

			if (colorIndex2 == 0 && CountVong <= 2.3)
			{
				Chay += CountVong;
			}
			if (CountVong >= 2.3)
			{
				Chay += CountVong;
			}

		}
		else
		{
			CountVong = 1;
		}
		for (int n = 0; n < DataListItem; n++)
		{
			ItemBmdStruct* is = pGetItemBmdStruct(mDataListItemVongQuayClient.ListItemVongQuay[n].Index);
			int size = max(is->ItemWidth, is->ItemHeight);

			float itemScale = 1.0;
			float addY = 0;
			switch (size)
			{
			case 4:
				addY = -5;
				break;
			case 3:
				addY = -3;
				break;
			case 2:
				addY = -1;
				break;
			}

			// Calculate polar coordinates for circular layout
			float angle = n * AngleStep;
			float PosXBoxItem = StartX + 125 + Radius * cos(angle);
			float PosYBoxItem = StartY + 140 + Radius * sin(angle);

			if (n == Chay)  // Replace yourNewVariable with the variable you want to compare with
			{
				boxColor = 0xD4966396;
			}
			else
			{
				boxColor = 0x00000096;
			}
			if (solan != 1)
			{
				int roll = rand() % 2;
				switch (roll)
				{
				case 0:
					gCBUtil.gInfoBox(PosXBoxItem, PosYBoxItem, WBox, WBox, 0x00000096, 0, 0);
					break;
				case 1:
					gCBUtil.gInfoBox(PosXBoxItem, PosYBoxItem, WBox, WBox, 0xD4966396, 0, 0);
					break;
				case 2:
					gCBUtil.gInfoBox(PosXBoxItem, PosYBoxItem, WBox, WBox, 0x26E0A596, 0, 0);
					break;
				}
			}


			gCBUtil.gInfoBox(PosXBoxItem, PosYBoxItem, WBox, WBox, boxColor, 0, 0);
			gCBUtil.DrawItem3D(PosXBoxItem + 5, PosYBoxItem + addY + 5, WBox, WBox, mDataListItemVongQuayClient.ListItemVongQuay[n].Index, mDataListItemVongQuayClient.ListItemVongQuay[n].Item.Level, mDataListItemVongQuayClient.ListItemVongQuay[n].Item.ExcellentOption, mDataListItemVongQuayClient.ListItemVongQuay[n].Item.AncientOption, 0, 1.0 / mDataListItemVongQuayClient.ListItemVongQuay[n].SizeBMD);

			if (gInterface.IndexItemSau != -1)
			{
				if (solan == 1)
				{
					Chay = gInterface.IndexItemSau;
				}
				else
				{
					Chay = -1;
				}
				gCBUtil.gInfoBox(InfoMocNapX + 112, StartY + 140, WBox, WBox, 0xD4966396, 0, 0);
				gCBUtil.DrawItem3D(InfoMocNapX + 117, StartY + 145, WBox, WBox, mDataListItemVongQuayClient.ListItemVongQuay[gInterface.IndexItemSau].Index, mDataListItemVongQuayClient.ListItemVongQuay[gInterface.IndexItemSau].Item.Level, mDataListItemVongQuayClient.ListItemVongQuay[gInterface.IndexItemSau].Item.ExcellentOption, mDataListItemVongQuayClient.ListItemVongQuay[gInterface.IndexItemSau].Item.AncientOption, 0, 1.0 / mDataListItemVongQuayClient.ListItemVongQuay[gInterface.IndexItemSau].SizeBMD);
				if (pCheckMouseOver(InfoMocNapX + 112, StartY + 140, WBox, WBox))
				{
					BBShowInfoItem = gInterface.IndexItemSau;
				}
			}





			if (pCheckMouseOver(PosXBoxItem, PosYBoxItem, WBox, WBox))
			{
				BBShowInfoItem = n;
			}
		}

		//===Coin


		if (BBShowInfoItem != -1)
		{
			gPostInterface.DrawItemToolTipText((void*)&mDataListItemVongQuayClient.ListItemVongQuay[BBShowInfoItem].Item, *(int*)0x879340C, *(int*)0x8793410 + 25);
			glColor3f(1, 1, 1);
			pSetBlend(false);
		}


		pGLSwitchBlend();
		pGLSwitch();
		glColor3f(1.0, 1.0, 1.0);
		pSetBlend(false);
	}
}

#endif


#if(B_MOCNAP)
void Interface::OpenWindowMocNap()
{
	if (GetTickCount() < gInterface.Data[eWindowMocNap].EventTick + 300)
	{
		return;

	}




	gInterface.Data[eWindowMocNap].EventTick = GetTickCount();
	if (!gInterface.Data[eWindowMocNap].OnShow)
	{
		XULY_CGPACKET pMsg;
		pMsg.header.set(0xD3, 0x9C, sizeof(pMsg));
		pMsg.ThaoTac = 1;
		DataSend((LPBYTE)& pMsg, pMsg.header.size);
	}
	gInterface.Data[eWindowMocNap].OnShow ^= 1;
}
CNewUIScrollBar* ListMocNap = nullptr;
CNewUIScrollBar* ListItemNhan = nullptr;
int MaxListMocNapInPage = 5;
int MaxListItemInPage = 9;
int SelectTypeMocNap = -1;
void Interface::DrawXemMocNap()
{
	if (!gInterface.Data[eWindowMocNapList].OnShow)
	{
		return;
	}

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
		if (gInterface.Data[eWindowMocNapList].OnShow == true)
		{
			gInterface.Data[eWindowMocNapList].OnShow = false;
			pSetCursorFocus = false;
			return;
		}
	}


	float WindowW = 185;
	float WindowH = 270;

	float StartX = (MAX_WIN_WIDTH / 2) - (WindowW / 2);
	float StartY = 25.0;
	if (!gCBUtil.gDrawWindowCustom(&StartX, &StartY, WindowW, WindowH, eWindowMocNapList, "Mốc Nạp"))
	{

		StartX = StartX + 10;
		StartY = StartY - 5;
		float WInfo = (WindowW - 20);
		float HInfo = WindowH - 100;

		gCBUtil.DrawText((HFONT)pFontBold, StartX + 15, StartY + 35, 0xFF00EEDFF, 0x0, WindowW, 0, 1, "Danh Sách Item Nhận");

		//Scroll Bar
		int DataListItem = mDataListItemMocNapClient.ListItemMocNap.size();
		if (!ListItemNhan)
		{
			ListItemNhan = new CNewUIScrollBar();
			ListItemNhan->Create((StartX + WindowW) - 25, StartY + 35 + 15, 130);
			if (ListItemNhan)
			{
				ListItemNhan->SetMaxPos((DataListItem <= MaxListItemInPage) ? 0 : (DataListItem / MaxListItemInPage) - 1);
				ListItemNhan->SetPos((StartX + WindowW) - 25, StartY + 35 + 15);
			}
		}
		if (ListItemNhan)
		{
			if (gInterface.Data[eWindowMocNapList].OnClick)
			{
				ListItemNhan->SetPos((StartX + WindowW) - 25, StartY + 35 + 15);
				ListItemNhan->SetCurPos(0);
			}
			ListItemNhan->MouseWheelWindow = pCheckMouseOver(StartX + 15, StartY + 35 + 15, WindowW, 130);
			ListItemNhan->Render();
			ListItemNhan->UpdateMouseEvent();
			ListItemNhan->Update();
		}

		//==List Box Item 
		float PosXBoxItemGoc = StartX + 25;
		float PosXBoxItem = StartX + 25;
		float PosYBoxItem = StartY + 55;
		float WBox = 30;
		float KhoangCach = 45;
		int CountNgang = 0;
		int CountDoc = 0;
		int ItemListPage = ListItemNhan->GetCurPos();
		int BBShowInfoItem = -1;
		for (int n = (ItemListPage * MaxListItemInPage); n < DataListItem; n++)
			//for (int n = 0; n < 15; n++)
		{
			ItemBmdStruct* is = pGetItemBmdStruct(mDataListItemMocNapClient.ListItemMocNap[n].Index);
			int size = max(is->ItemWidth, is->ItemHeight);

			float itemScale = 1.0;
			float addY = 0;
			switch (size)
			{
			case 4:
				addY = -5;
				break;
			case 3:
				addY = -3;
				break;
			case 2:
				addY = -1;
				break;
			}
			gCBUtil.gInfoBox(PosXBoxItem, PosYBoxItem, WBox, WBox, 0x00000096, 0, 0);
			gCBUtil.DrawItem3D(PosXBoxItem + 5, PosYBoxItem + addY, WBox, WBox, mDataListItemMocNapClient.ListItemMocNap[n].Index, mDataListItemMocNapClient.ListItemMocNap[n].Item.Level, mDataListItemMocNapClient.ListItemMocNap[n].Item.ExcellentOption, mDataListItemMocNapClient.ListItemMocNap[n].Item.AncientOption, 0, 1.0 / mDataListItemMocNapClient.ListItemMocNap[n].SizeBMD);//Show Item
			gCBUtil.DrawText((HFONT)pFontNormal, PosXBoxItem + 5, PosYBoxItem + 25, 0xE0FF14A5, 0x0, WBox, 0, 4, "x%d", mDataListItemMocNapClient.ListItemMocNap[n].Count);
			if (pCheckMouseOver(PosXBoxItem, PosYBoxItem, WBox, WBox))
			{
				BBShowInfoItem = n;
			}
			PosXBoxItem += KhoangCach;
			CountDoc++;
			CountNgang++;
			if (CountNgang >= 3)
			{
				PosXBoxItem = PosXBoxItemGoc;
				PosYBoxItem += KhoangCach;
				CountNgang = 0;
			}
			if (CountDoc >= MaxListItemInPage) break;
		}

		//===Coin
		float PosYCoinNhan = StartY + 185;
		gCBUtil.DrawText((HFONT)pFontBold, StartX + 15, PosYCoinNhan, 0xFF00EEDFF, 0x0, WindowW, 0, 1, "*Coin Nhận");
		PosYCoinNhan += 5;
		gCBUtil.DrawText((HFONT)pFontNormal, StartX + 25, PosYCoinNhan + (10 * 1), 0xFF8214FF, 0x0, WindowW, 0, 1, "+WCoin : %s", gCBUtil.NumberFormat(mDataListItemMocNapClient.WC));			//Text3 = "+ WCoin : %s
		gCBUtil.DrawText((HFONT)pFontNormal, StartX + 25, PosYCoinNhan + (10 * 2), 0xFF8214FF, 0x0, WindowW, 0, 1, "+WCoinP :%s", gCBUtil.NumberFormat(mDataListItemMocNapClient.WP));		  //Text4 = "+ WCoinP : %
		gCBUtil.DrawText((HFONT)pFontNormal, StartX + 25, PosYCoinNhan + (10 * 3), 0xFF8214FF, 0x0, WindowW, 0, 1, "+GobinP :%s", gCBUtil.NumberFormat(mDataListItemMocNapClient.GP));		  //Text5 = "+ GobinP : %

		gCBUtil.DrawText((HFONT)pFontBold, StartX, PosYCoinNhan + (10 * 5) + 5, 0x14FFC0FF, 0x0, WindowW, 0, 3, "*Phần thưởng bao gồm các Item \n và Coin Nhận !!");
		//===Show Info
		if (BBShowInfoItem != -1)
		{
			gPostInterface.DrawItemToolTipText((void*)& mDataListItemMocNapClient.ListItemMocNap[BBShowInfoItem].Item, *(int*)0x879340C, *(int*)0x8793410 + 25);
			glColor3f(1, 1, 1);
			pSetBlend(false);
		}
	}
}

void Interface::DrawWindowMocNap()
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
		if (gInterface.Data[eWindowMocNap].OnShow == true)
		{
			gInterface.Data[eWindowMocNap].OnShow = false;
			pSetCursorFocus = false;
			return;
		}
	}
	if (!gInterface.Data[eWindowMocNap].OnShow)
	{
		if (ListMocNap) ListMocNap = nullptr;
		if (SelectTypeMocNap != -1) SelectTypeMocNap = -1;
		return;
	}

	float WindowW = 220;
	float WindowH = 270;
	gInterface.Data[eWindowMocNap].Width = WindowW;
	float StartX = (MAX_WIN_WIDTH / 2) - (WindowW / 2);
	float StartY = ((MAX_WIN_HEIGHT - 51) / 2) - (WindowH / 2);

	pSetCursorFocus = true;	 //nếu chuột trong khu vực bảng shop thì ko click di chuyển nv

	if (!gCBUtil.gDrawWindowCustom(&StartX, &StartY, WindowW, WindowH, eWindowMocNap, "Mốc Nạp"))
	{

		pSetBlend(true);
		glColor3f(1.0, 1.0, 1.0);

		int TongSoDaNap = mDataMocNapClient.TongNap;
		int MocDaNhan = mDataMocNapClient.NhanMocNap;
		gCBUtil.DrawText((HFONT)pFontBold, StartX, StartY + 25, 0x00FFDDFF, 0x0, WindowW, 0, 3, "*Hệ thống nhận thưởng theo Mốc Nạp");
		gCBUtil.DrawText((HFONT)pFontBold, StartX, StartY + 35, 0xFF9100FF, 0x0, WindowW, 0, 3, "Quét Mã QR Bên Dưới Để Nạp Tiền Nhanh Nhất !!");
		gCBUtil.DrawText((HFONT)pFontBold, StartX, StartY + 50, 0x3CFF00FF, 0x0, WindowW, 0, 3, "[Bạn Đã Nạp : %s]", gCBUtil.NumberFormat(TongSoDaNap));

		//===Info Yeu Cau Moc Nap
		float InfoMocNapX = (StartX + 10) + 3;
		float InfoMocNapY = (StartY + 65);
		float TyleInfoYeuCau = 7.5f;
		float WInfo = (WindowW - 20) / 10;
		float WProcess = (WInfo * (TyleInfoYeuCau - 2.7));
		float WButton = 38;
		float HInfo = WindowH - 100;
		gCBUtil.DrawText((HFONT)pFontBold, InfoMocNapX, InfoMocNapY, 0xFFDE26FF, 0x3a4b3978, WInfo * TyleInfoYeuCau + 40, 0, 3, "Yêu Cầu"); //"Yêu Cầu");
		//Scroll Bar
		int DataListMocNap = mDataMocNapClient.DanhSachMocNap.size();
		if (!ListMocNap)
		{
			ListMocNap = new CNewUIScrollBar();
			ListMocNap->Create((StartX + WindowW) - 15, InfoMocNapY + 10, HInfo);
			if (ListMocNap)
			{
				ListMocNap->SetMaxPos((DataListMocNap <= MaxListMocNapInPage) ? 0 : (DataListMocNap / MaxListMocNapInPage) - 1);
				ListMocNap->SetPos((StartX + WindowW) - 15, InfoMocNapY + 10);
			}
		}
		if (ListMocNap)
		{
			if (gInterface.Data[eWindowMocNap].OnClick)
			{
				ListMocNap->SetPos((StartX + WindowW) - 15, InfoMocNapY + 10);
				ListMocNap->SetCurPos(0);
			}
			ListMocNap->MouseWheelWindow = pCheckMouseOver(InfoMocNapX, InfoMocNapY, WInfo * TyleInfoYeuCau, HInfo + 10);
			ListMocNap->Render();
			ListMocNap->UpdateMouseEvent();
			ListMocNap->Update();
		}

		float KhoangCachYMocNap = 34;
		int MixItemListPage = ListMocNap->GetCurPos();
		int MaxList = 0;
		for (int n = (MixItemListPage * MaxListMocNapInPage); n < DataListMocNap; n++)
		{
			//==List MocNap
			gInterface.DrawBarForm(InfoMocNapX, InfoMocNapY + 15, WInfo * TyleInfoYeuCau + 40, 30, 0.0, 0.0, 0.0, 0.5);
			gCBUtil.DrawText((HFONT)pFontNormal, InfoMocNapX + 5, InfoMocNapY + 20, 0xFFDE26FF, 0x0, WProcess, 0, 3, "Mốc(%d) %s", mDataMocNapClient.DanhSachMocNap[n].IndexMocNap, gCBUtil.NumberFormat(mDataMocNapClient.DanhSachMocNap[n].GiaTriNap)); //"Mốc(%d) %s"
			//==Process
			gInterface.DrawBarForm(InfoMocNapX + 5, InfoMocNapY + 20 + 11, WProcess, 6, 0.7833, 0.0, 1.0, 0.6); //Process BG
			//=Calc Tyle 
			float PhanTramMocNap = (TongSoDaNap)* 100 / (mDataMocNapClient.DanhSachMocNap[n].GiaTriNap); // Tinh Ty le da nap
			float TyLeTGA = (WProcess * PhanTramMocNap) / 100;
			if (TyLeTGA > WProcess) { TyLeTGA = WProcess; }
			gInterface.DrawBarForm(InfoMocNapX + 5, InfoMocNapY + 20 + 11, TyLeTGA, 6, 0.7833, 0.0, 1.0, 1.0); //Process
			//==Xem
			if (gElemental.gDrawButton(InfoMocNapX + 5 + WProcess + 3, InfoMocNapY + 20, 110, 11, "Xem", WButton) && (GetTickCount() - gInterface.Data[eWindowMocNapList].EventTick) > 300) //"Xem"
			{

				SelectTypeMocNap = mDataMocNapClient.DanhSachMocNap[n].IndexMocNap;
				gInterface.Data[eWindowMocNapList].OnShow = true;
				gInterface.Data[eWindowMocNapList].EventTick = GetTickCount();
				XULY_CGPACKET pMsg;
				pMsg.header.set(0xD3, 0x9B, sizeof(pMsg));
				pMsg.ThaoTac = SelectTypeMocNap; //
				DataSend((LPBYTE)& pMsg, pMsg.header.size);
			}
			if (MocDaNhan < mDataMocNapClient.DanhSachMocNap[n].IndexMocNap) //Kiem tra neu da nhan roi thi khong cho nhan nua
			{
				//==Nhận
				if (gElemental.gDrawButton(InfoMocNapX + 5 + WProcess + 3 + WButton + 3, InfoMocNapY + 20, 110, 11, "Nhận", WButton) && (GetTickCount() - gInterface.Data[eWindowMocNapList].EventTick) > 300) //"Nhận"
				{
					XULY_CGPACKET pMsg;
					pMsg.header.set(0xD3, 0x9A, sizeof(pMsg));
					pMsg.ThaoTac = mDataMocNapClient.DanhSachMocNap[n].IndexMocNap; //
					DataSend((LPBYTE)& pMsg, pMsg.header.size);

				}

			}
			InfoMocNapY = InfoMocNapY + (KhoangCachYMocNap);
			MaxList++;
			if (MaxList >= MaxListMocNapInPage) break;
		}


		pGLSwitchBlend();
		pGLSwitch();
		glColor3f(1.0, 1.0, 1.0);
		pSetBlend(false);
	}
}
#endif

#if(JEWELBANKVER2)

#define GET_ITEM(x,y) (((x)*MAX_ITEM_TYPE)+(y))

int PageBank = 0;
int MaxPerPageBank = 8;
static void BPagePrevAction(LPVOID pClass)
{
	if (GetTickCount() < nInterface.JEWELBANK_WINDOW->lastActionTime + 300) return;
	nInterface.JEWELBANK_WINDOW->lastActionTime = GetTickCount();

	if (PageBank > 0)
	{
		PageBank--;
	}
	//pDrawMessage("-",1);
}
static void BPageNextAction(LPVOID pClass)
{
	if (GetTickCount() < nInterface.JEWELBANK_WINDOW->lastActionTime + 300) return;
	nInterface.JEWELBANK_WINDOW->lastActionTime = GetTickCount();

	if (PageBank < (gInterface.mCListItemBank.size() / MaxPerPageBank))
	{
		PageBank++;
	}
	//	pDrawMessage("+", 1);
}
float FixYItemBMD(int ItemIndex)
{

	switch (ItemIndex)
	{
	case 6159:
	{
				 return 6.f;
	}
		break;
	case 7199:
	{
				 return 9.5f;
	}
		break;
	default:
		break;
	}
	return 0;
}
void NewBankSendGS(int Type, int SelectIndex)
{
	if ((GetTickCount() - nInterface.JEWELBANK_WINDOW->lastActionTime) < 300)
	{
		return;
	}
	//==Tham Gia Than Ma
	REQUEST_RUTGUIBANK pMsg;
	pMsg.header.set(0xFA, 0x20, sizeof(pMsg));
	pMsg.TypeSend = Type;
	pMsg.IndexList = SelectIndex;
	DataSend((LPBYTE)&pMsg, pMsg.header.size);

	nInterface.JEWELBANK_WINDOW->lastActionTime = GetTickCount();
}
void Interface::DrawWindowJewelBankVer2()
{
	if (nInterface.JEWELBANK_WINDOW->onShow == false)
	{
		if (PageBank) PageBank = 0;
		return;
	}

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

		if (nInterface.JEWELBANK_WINDOW->onShow == true)
		{
			nInterface.JEWELBANK_WINDOW->onShow = false;
			pSetCursorFocus = false;
			return;
		}
	}

	gInterface.OpenWindow(ObjWindow::Inventory);

	if (gInterface.mCListItemBank.empty())
	{
		nInterface.JEWELBANK_WINDOW->onShow = false;
	}



	const BYTE state[3] = { 0, 1, 2 };
	float CuaSoW = nInterface.JEWELBANK_WINDOW->Width;
	float CuaSoH = nInterface.JEWELBANK_WINDOW->Height;

	float StartX = nInterface.JEWELBANK_WINDOW->X;
	float StartY = nInterface.JEWELBANK_WINDOW->Y;
	float CenterX = StartX + (CuaSoW / 2);
	float MaxY = StartY + CuaSoH;
	/*float MainCenter = setPosCenterY(320.0);
	float ButtonX = MainCenter - (29.0 / 2);*/

	nInterface.DrawWindowBG(nInterface.JEWELBANK_WINDOW, gConfig.TextTM_NganHangNgoc[0]);

	CustomFont.Draw((HFONT)pFontNormal, StartX, StartY + 45, 0xFF6600FF, 0x0, CuaSoW, 0, 3, gConfig.TextTM_NganHangNgoc[1]);
	CustomFont.Draw((HFONT)pFontNormal, StartX, StartY + 45 + 15, 0xFF6600FF, 0x0, CuaSoW, 0, 3, gConfig.TextTM_NganHangNgoc[2]);

	float StartXItem = StartX + 10;
	float StartYItem = StartY + 75;

	CustomFont.Draw((HFONT)pFontNormal, StartXItem + 36 + 100 + 70, StartYItem + 15, 0xFFFFFFFF, 0xD69015A9, 138, 0, 3, gConfig.TextTM_NganHangNgoc[3]);
	CustomFont.Draw((HFONT)pFontNormal, StartXItem + 36 + 100 + 70 + 138, StartYItem + 15, 0xFFFFFFFF, 0x15D6C9A9, 40, 0, 3, gConfig.TextTM_NganHangNgoc[4]);
	CustomFont.Draw((HFONT)pFontNormal, StartXItem + 36 + 100 + 70 + 138 + 40, StartYItem + 15, 0xFFFFFFFF, 0x9C15D6A9, 40, 0, 3, gConfig.TextTM_NganHangNgoc[5]);
	float KhoangCach = 25;
	//for (int n = 0; n < MaxPerPage; n++)
	for (int n = 0, r = (PageBank * MaxPerPageBank); n < MaxPerPageBank && r < gInterface.mCListItemBank.size(); r++)
	{
		int ItemIndex = gInterface.mCListItemBank[r].ItemIndex;
		int ItemLevel = gInterface.mCListItemBank[r].ItemLevel;


		ItemBmdStruct is = *(ItemBmdStruct*)(*(DWORD*)0x8128AC0 + sizeof(ItemBmdStruct)* ItemIndex);
		int size = max(is.ItemWidth, is.ItemHeight);

		float itemScale = 1.0;
		float addY = FixYItemBMD(ItemIndex);
		int nCount = 0;

		if (n % 2)
		{
			gInterface.DrawBarForm(StartXItem, (StartYItem + (n * KhoangCach)) + 25, CuaSoW - 20, 20, 0.0, 0.0, 0.0, 0.3);//bg
		}
		else
		{
			gInterface.DrawBarForm(StartXItem, (StartYItem + (n * KhoangCach)) + 25, CuaSoW - 20, 20, 0.0, 0.0, 0.0, 0.6);//bg
		}
		gCBUtil.DrawItem3D(StartXItem, (StartYItem + (n * KhoangCach) + addY), 45, 45, ItemIndex, SET_ITEMOPT_LEVEL(ItemLevel), 0, 0, 0, itemScale);//bmd
		CustomFont.Draw((HFONT)pFontNormal, StartXItem + 36, (StartYItem + (n * KhoangCach)) + 28, 0xFFFFFFA9, 0x0, 100, 0, 3, BGetItemName3(ItemIndex, SET_ITEMOPT_LEVEL(ItemLevel))); //Name
		CustomFont.Draw((HFONT)pFontNormal, StartXItem + 36 + 100, (StartYItem + (n * KhoangCach)) + 28, 0xFFDD00A9, 0x0, 60, 0, 3, "x%d", gInterface.mCListItemBank[r].ItemCount); //so luong
		//==ButtonRut 1
		if (UIController.BButton(31618, StartXItem + 36 + 100 + 70 + (28 * nCount), (StartYItem + (n * KhoangCach)) + 25, 25, 22, 25, 22, 3, state))
		{
			NewBankSendGS(eRut1, r);
		}
		CustomFont.Draw((HFONT)pFontNormal, StartXItem + 36 + 100 + 70 + (28 * nCount++), (StartYItem + (n * KhoangCach)) + 30, 0xFFFFFFBE, 0x0, 26, 0, 3, "1");

		//==ButtonRut 10
		if (UIController.BButton(31618, StartXItem + 36 + 100 + 70 + (28 * nCount), (StartYItem + (n * KhoangCach)) + 25, 25, 22, 25, 22, 3, state))
		{
			NewBankSendGS(eRut10, r);
		}
		CustomFont.Draw((HFONT)pFontNormal, StartXItem + 36 + 100 + 70 + (28 * nCount++), (StartYItem + (n * KhoangCach)) + 30, 0xFFFFFFBE, 0x0, 26, 0, 3, "10");
		//==ButtonRut 20
		if (UIController.BButton(31618, StartXItem + 36 + 100 + 70 + (28 * nCount), (StartYItem + (n * KhoangCach)) + 25, 25, 22, 25, 22, 3, state))
		{
			NewBankSendGS(eRut20, r);
		}
		CustomFont.Draw((HFONT)pFontNormal, StartXItem + 36 + 100 + 70 + (28 * nCount++), (StartYItem + (n * KhoangCach)) + 30, 0xFFFFFFBE, 0x0, 26, 0, 3, "20");
		//==ButtonRut 30
		if (UIController.BButton(31618, StartXItem + 36 + 100 + 70 + (28 * nCount), (StartYItem + (n * KhoangCach)) + 25, 25, 22, 25, 22, 3, state))
		{
			NewBankSendGS(eRut30, r);
		}
		CustomFont.Draw((HFONT)pFontNormal, StartXItem + 36 + 100 + 70 + (28 * nCount++), (StartYItem + (n * KhoangCach)) + 30, 0xFFFFFFBE, 0x0, 26, 0, 3, "30");
		//==ButtonRut All
		if (UIController.BButton(31618, StartXItem + 36 + 100 + 70 + (28 * nCount), (StartYItem + (n * KhoangCach)) + 25, 25, 22, 25, 22, 3, state))
		{
			NewBankSendGS(eRutAll, r);
		}
		CustomFont.Draw((HFONT)pFontNormal, StartXItem + 36 + 100 + 70 + (28 * nCount++), (StartYItem + (n * KhoangCach)) + 30, 0xFFFFFFBE, 0x0, 26, 0, 3, "***");
		//==ButtonGui All
		if (UIController.BButton(31617, StartXItem + 36 + 100 + 70 + (28 * nCount), (StartYItem + (n * KhoangCach)) + 25, 38, 23, 38, 23, 3, state))
		{
			NewBankSendGS(eGuiAll, r);
		}
		CustomFont.Draw((HFONT)pFontNormal, StartXItem + 36 + 100 + 70 + (28 * nCount++), (StartYItem + (n * KhoangCach)) + 30, 0xFFFFFFBE, 0x0, 38, 0, 3, gConfig.TextTM_NganHangNgoc[6]);
		//==Auto Pick
		if (gCBUtil.RenderCheckBox(StartXItem + 36 + 100 + 70 + (28 * nCount) + 20, (StartYItem + (n * KhoangCach)) + 28, 0xFFCC00C8, gInterface.mCListItemBank[r].AutoPick, ""))
		{
			NewBankSendGS(eAutoPick, r);
		}
		n++;
	}
	//Next Page
	RenderBitmap(32344, CenterX - (60 / 2), MaxY - 40, 60.f, 22.f, 0, 0, 80.f / 128.f, 30.f / 34.f, 1, 1, 0.0);

	CustomFont.Draw(CustomFont.FontBold, CenterX - (60 / 2), MaxY - 40 + 5, 0xffffffff, 0x0, 60, 0, 3, "%d / %d", PageBank + 1, (gInterface.mCListItemBank.size() / MaxPerPageBank) + 1);
	//

	//
	UIController.Button(32345, CenterX - (60 / 2) - 26, MaxY - 40, 20, 22, 20, 22, 3, state, BPagePrevAction);
	UIController.Button(32346, CenterX + (60 / 2) + 6, MaxY - 40, 20, 22, 20, 22, 3, state, BPageNextAction);



}//===Func calal Open or Offf Window
void Interface::OnOffWindowBank()
{
	if ((GetTickCount() - nInterface.JEWELBANK_WINDOW->lastActionTime) < 500)
	{
		return;
	}
	nInterface.JEWELBANK_WINDOW->lastActionTime = GetTickCount();
	nInterface.JEWELBANK_WINDOW->onShow ^= 1;
}
#endif