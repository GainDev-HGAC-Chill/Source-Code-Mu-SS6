#include "stdafx.h"
#include "resource.h"
#include "Controller.h"
#include "CustomCommandInfo.h"
#include "CustomEventTime.h"
#include "CustomRanking.h"
#include "Defines.h"
#include "OffTrade.h"
#include "Protocol.h"
#include "Import.h"
#include "Interface.h"
#include "Protect.h"
#include "TMemory.h"
#include "CSCharacterS13.h"
#include "CMacroUIEx.h"
#include "Camera.h"
#include "TrayModeNew.h"
#include "MiniMap.h"
#include "WindowsStruct.h"
#include "Ruud.h"
#include "Central.h"
#include "User.h"
#include "PartySearchSettings.h"
#include "PartySearch.h"
#include "MiniMap.h"
#include "TuLuyen.h"
#include "DanhHieu.h"
#include "QuanHam.h"

#include "ResetSystem.h"
// ----------------------------------------------------------------------------------------------

Controller	gController;
// ----------------------------------------------------------------------------------------------
#if(NOTICE_MES==1)
char Notice_1[1024];
char Notice_2[1024];
char CameraNotAc[1024];
char CameraOn[1024];
char CameraOff[1024];
char CameraDefault[1024];
char GlowOn[1024];
char GlowOff[1024];
char AutoOn[1024];
char AutoOff[1024];

#endif

void __declspec(naked) iconHook()
{
	static DWORD dwIcon = (DWORD)LoadIcon(gController.Instance, MAKEINTRESOURCE(IDI_ICON1));
	static DWORD dwJmp = 0x004D0E3C;

	_asm
	{
		MOV EAX, dwIcon
		JMP dwJmp
	}
}

bool Controller::Load()
{
	if( !this->MouseHook )
	{
		this->MouseHook = SetWindowsHookEx(WH_MOUSE, this->Mouse, gController.Instance, GetCurrentThreadId());
		// ----
#if(NOTICE_MES==1)

				GetPrivateProfileString("Notice", "Notice_1", "", Notice_1, 1024, ".\\data\\Custom\\Notice.ini");
				GetPrivateProfileString("Notice", "Notice_2", "", Notice_2, 1024, ".\\data\\Custom\\Notice.ini");
				GetPrivateProfileString("Notice", "CameraNotAc", "", CameraNotAc, 1024, ".\\data\\Custom\\Notice.ini");
				GetPrivateProfileString("Message", "CameraOn", "", CameraOn, 1024, ".\\data\\Custom\\Notice.ini");
				GetPrivateProfileString("Message", "CameraOff", "", CameraOff, 1024, ".\\data\\Custom\\Notice.ini");
				GetPrivateProfileString("Message", "CameraDefault", "", CameraDefault, 1024, ".\\data\\Custom\\Notice.ini");
				GetPrivateProfileString("Message", "GlowOn", "", GlowOn, 1024, ".\\data\\Custom\\Notice.ini");
				GetPrivateProfileString("Message", "GlowOff", "", GlowOff, 1024, ".\\data\\Custom\\Notice.ini");
				GetPrivateProfileString("Message", "AutoOn", "", AutoOn, 1024, ".\\data\\Custom\\Notice.ini");
				GetPrivateProfileString("Message", "AutoOff", "", AutoOff, 1024, ".\\data\\Custom\\Notice.ini");

#endif
		if( !this->MouseHook )
		{
			return false;
		}
	}
	// ----
	if( !this->KeyboardHook )
	{
	}
	// ----
	SetOp((LPVOID)0x004D0E2F, iconHook, ASM::CALL);
	return true;
}


LRESULT Controller::Mouse(int Code, WPARAM wParam, LPARAM lParam)
{
	if( GetForegroundWindow() != pGameWindow )
	{
		return CallNextHookEx(gController.MouseHook, Code, wParam, lParam);
	}
	// ----
	MOUSEHOOKSTRUCTEX * Mouse	= (MOUSEHOOKSTRUCTEX*)lParam;
	gController.wMouse = wParam;

	switch(wParam)
	{
	case WM_LBUTTONUP:
	case WM_LBUTTONDOWN:
		{
#if(RANKINGGOC == 1)
			gCustomRanking.EventSelect(wParam);
			gCustomRanking.EventVipWindow_Close(wParam);
#endif
			gInterface.EventVipWindow_Main(wParam);
			gCustomCommandInfo.EventCommandWindow_Close(wParam);
			gCustomCommandInfo.CommandNext(wParam);
			gCustomCommandInfo.CommandPrev(wParam);
			gCustomEventTime.EventEventTimeWindow_Close(wParam);
			gCustomEventTime.EventNext(wParam);
			gCustomEventTime.EventPrev(wParam);
			gInterface.EventNewInterface_All(wParam);

			gInterface.EventDrawMenu_Open(wParam);
			gInterface.EventDrawMenu_Close(wParam);
			gInterface.EventDrawMenu_Op1(wParam);
			gInterface.EventDrawMenu_Op2(wParam);
			gInterface.EventDrawMenu_Op3(wParam);
			gInterface.EventDrawMenu_Op4(wParam);
			gInterface.EventDrawMenu_Op5(wParam);
			gInterface.EventDrawMenu_Op6(wParam);
			gInterface.EventDrawMenu_Op7(wParam);
			gInterface.EventDrawMenu_Op8(wParam);
			gInterface.EventDrawMenu_Op9(wParam);
			gInterface.EventDrawMenu_Op10(wParam);
			gInterface.EventDrawMenu_Op11(wParam);
			gInterface.EventDrawMenu_Op12(wParam);
			gInterface.EventDrawMenu_Op13(wParam);
			gInterface.EventDrawMenu_Op14(wParam);
			gInterface.EventDrawMenu_Op15(wParam);
			gInterface.EventDrawMenu_Op16(wParam);
			gInterface.EventDrawMenu_Op17(wParam);




			//btn move event
			gCustomEventTime.EventDrawMenu_Op21(wParam);
			gCustomEventTime.EventDrawMenu_Op22(wParam);
			gCustomEventTime.EventDrawMenu_Op23(wParam);
			gCustomEventTime.EventDrawMenu_Op24(wParam);
			gCustomEventTime.EventDrawMenu_Op25(wParam);
			gCustomEventTime.EventDrawMenu_Op26(wParam);
			gCustomEventTime.EventDrawMenu_Op27(wParam);
			gCustomEventTime.EventDrawMenu_Op28(wParam);
			gCustomEventTime.EventDrawMenu_Op29(wParam);
			gCustomEventTime.EventDrawMenu_Op30(wParam);
			gCustomEventTime.EventDrawMenu_Op31(wParam);
			gCustomEventTime.EventDrawMenu_Op32(wParam);
			gCustomEventTime.EventDrawMenu_Op33(wParam);
			gCustomEventTime.EventDrawMenu_Op34(wParam);
			gCustomEventTime.EventDrawMenu_Op35(wParam);
			gCustomEventTime.EventDrawMenu_Op36(wParam);
			gCustomEventTime.EventDrawMenu_Op37(wParam);
			gCustomEventTime.EventDrawMenu_Op38(wParam);
			gCustomEventTime.EventDrawMenu_Op39(wParam);
			gCustomEventTime.EventDrawMenu_Op40(wParam);
			gCustomEventTime.EventDrawMenu_Op41(wParam);
			gCustomEventTime.EventDrawMenu_Op42(wParam);
			gCustomEventTime.EventDrawMenu_Op43(wParam);
			gCustomEventTime.EventDrawMenu_Op44(wParam);
			gCustomEventTime.EventDrawMenu_Op45(wParam);
			gCustomEventTime.EventDrawMenu_Op46(wParam);
			gCustomEventTime.EventDrawMenu_Op47(wParam);
			gCustomEventTime.EventDrawMenu_Op48(wParam);
			gCustomEventTime.EventDrawMenu_Op49(wParam);
			gCustomEventTime.EventDrawMenu_Op50(wParam);
			gCustomEventTime.EventDrawMenu_Op51(wParam);
			gCustomEventTime.EventDrawMenu_Op52(wParam);
			gCustomEventTime.EventDrawMenu_Op53(wParam);
			gCustomEventTime.EventDrawMenu_Op54(wParam);
			gCustomEventTime.EventDrawMenu_Op55(wParam);
			gCustomEventTime.EventDrawMenu_Op56(wParam);
			gCustomEventTime.EventDrawMenu_Op57(wParam);
			gCustomEventTime.EventDrawMenu_Op58(wParam);
			gCustomEventTime.EventDrawMenu_Op59(wParam);
			gCustomEventTime.EventDrawMenu_Op60(wParam);
			gCustomEventTime.EventDrawMenu_Op61(wParam);


#if (RESETCHANGE ==1)
			gResetChange.ButtonResetChange(wParam);
#endif


#if(EXBEXO_LOAD_SEND_TINH_NANG)
			gInterface.EVENT_TINHNANG_INTERFACE(wParam);
#endif
			//-----------------------------------------------------------------------------------------------------



            #if(PARTYSEARCH==1)
			    gPartySearch.EventPartySearchWindow_All(wParam);
			    gPartySearch.EventPartySettingsWindow_Main(wParam);
            #endif


#if (CongHuongV2)
			gInterface.EventScrollPos(Mouse, wParam);
#endif


			gInterface.EventConfirm_CANCEL(wParam);
			gInterface.EventConfirm_OK(wParam);
			gCRuudShop.RuudShopEventButton(wParam);
			gCSCharacterS13.SelectCharButton(wParam);
			EventMuOffhelper(wParam);



#if(DANH_HIEU_NEW == 1)
			G_BEXO_DANH_HIEU.BEXO_CLICK_TRANG_DANH_HIEU(wParam);
			G_BEXO_DANH_HIEU.MAIN_DANH_HIEU(wParam);
#endif

#if(QUAN_HAM_NEW == 1)
			G_BEXO_QUAN_HAM.BEXO_CLICK_TRANG_QUAN_HAM(wParam);
			G_BEXO_QUAN_HAM.MAIN_QUAN_HAM(wParam);
#endif

#if(TU_LUYEN_NEW == 1)
			G_BEXO_TU_LUYEN.BEXO_CLICK_TRANG_TU_LUYEN(wParam);
			G_BEXO_TU_LUYEN.MAIN_TU_LUYEN(wParam);
#endif

#if(OFFLINE_MODE_NEW)
			gInterface.EventOffExpWindow_Main(wParam);
#endif

			if(gCRuudShop.RuudRender.Open)
			{
				if ( pCheckMouseOver(gCRuudShop.RuudRender.x, gCRuudShop.RuudRender.y + 10, gCRuudShop.RuudRender.w, 40.0f) == 1 )
				{
					gCRuudShop.RuudRender.Cursor.x = (double)*(DWORD*)0x879340C - gCRuudShop.RuudRender.x;
					gCRuudShop.RuudRender.Cursor.y = (double)*(DWORD*)0x8793410 - gCRuudShop.RuudRender.y;
					if(wParam == WM_LBUTTONDOWN)
					{
						gCRuudShop.RuudRender.Move = 1;
					}
					else
					{
						gCRuudShop.RuudRender.Move = 0;
					}
				}
				else
				{
					gCRuudShop.RuudRender.Move = 0;
				}
			}
			else if(gProtect.m_MainInfo.CustomInterfaceType == 1)
			{
				gInterface.EventNewInterface97_All(wParam);
			}
			else if(gProtect.m_MainInfo.CustomInterfaceType == 2)
			{
				gInterface.EventNewInterface_All(wParam);
			}
			gCMacroUIEx.Button(wParam);
			gOffTrade.EventOffTradeWindow_Main(wParam);
			gOffTrade.EventCloseTradeWindow_Main(wParam);
		}
		
		break;
		case WM_MOUSEMOVE:

			gCRuudShop.MoveWindows(&gCRuudShop.RuudRender,
				((double)*(DWORD*)0x879340C) - gCRuudShop.RuudRender.Cursor.x,
				((double)*(DWORD*)0x8793410) - gCRuudShop.RuudRender.Cursor.y);

			if(GetForegroundWindow() == *(HWND*)(0x00E8C578))
			{
				gCamera.Move(Mouse);
			}
			break;
		case WM_MBUTTONDOWN:
			if(GetForegroundWindow() == *(HWND*)(0x00E8C578))
			{
				gCamera.SetIsMove(1);
				gCamera.SetCursorX(Mouse->pt.x);
				gCamera.SetCursorY(Mouse->pt.y);
			}
			break;
		case WM_MBUTTONUP:
			if(GetForegroundWindow() == *(HWND*)(0x00E8C578))
			{
				gCamera.SetIsMove(0);
			}
			break;
		case WM_MOUSEWHEEL:
			if(GetForegroundWindow() == *(HWND*)(0x00E8C578))
			{
				gCamera.Zoom(Mouse);
			}
			break;
	}
	// ----
	return CallNextHookEx(gController.MouseHook, Code, wParam, lParam);
}
// ----------------------------------------------------------------------------------------------

LRESULT Controller::Keyboard(int Code, WPARAM wParam, LPARAM lParam)
{
	
	if( GetForegroundWindow() != pGameWindow )
	{
		return CallNextHookEx(gController.KeyboardHook, Code, wParam, lParam);
	}

	if (Code < 0) return CallNextHookEx(gController.KeyboardHook, Code, wParam, lParam);
	
	if( (Code == HC_ACTION) && (wParam == WM_KEYDOWN))
	{
		KBDLLHOOKSTRUCT Hook = *((KBDLLHOOKSTRUCT*)lParam);
		gController.wKeyBord = wParam;
		switch(Hook.vkCode)
		{
			// --


		//case VK_F8:
		//{
		//	gCustomRanking.OpenWindow();
		//}
		break;	

		case 0x48:
		{
			gCustomEventTime.OpenWindow();
		}
		break;

		case VK_ESCAPE:
		{

			if (gInterface.Data[eCommand_MAIN].OnShow == true && (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4))
			{
				gInterface.Data[eCommand_MAIN].OnShow = false;

				pSetCursorFocus = false;

				return -1;
			}

			if (gInterface.Data[eRankPANEL_MAIN].OnShow == true && (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4))
			{
				gInterface.Data[eRankPANEL_MAIN].OnShow = false;

				pSetCursorFocus = false;

				return -1;
			}

			if (gInterface.Data[eEventTimePANEL_MAIN].OnShow == true && (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4))
			{
				gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;

				pSetCursorFocus = false;

				return -1;
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

			//if (gInterface.Data[eJewelBank_MAIN].OnShow == true)
			//{
			//	gInterface.Data[eJewelBank_MAIN].OnShow == false;

			//	if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
			//	{
			//		pSetCursorFocus = false;
			//	}
			//}

			//if (gInterface.Data[eLuckySpin].OnShow == true)
			//{
			//	gInterface.Data[eLuckySpin].OnShow = false;

			//	if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
			//	{
			//		pSetCursorFocus = false;
			//	}
			//}


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


			if (gInterface.CheckVipWindow())
			{
				gInterface.CloseVipWindow();
				return -1;
			}

			if (gInterface.CheckMenuWindow())
			{
				gInterface.CloseMenuWindow();
				return -1;
			}

		}
		break;
		case VK_SNAPSHOT:
		{
			gInterface.Data[eLogo].EventTick = GetTickCount()+1500;
			return CallNextHookEx(gController.KeyboardHook, Code, wParam, lParam);
		}
		break;

		default:
		break;
		}

	} 
	return (LRESULT) NULL;
	
}
// ----------------------------------------------------------------------------------------------


LRESULT Controller::Window(HWND Window, DWORD Message, WPARAM wParam, LPARAM lParam)
{
	switch(Message)
	{

	case TRAYMODE_ICON_MESSAGE:
		{
			switch(lParam)
			{
			case WM_LBUTTONDBLCLK:
				{
					gTrayMode.SwitchState();
				}
				break;
			}
		}
		break;
	}
	// ----
	return CallWindowProc((WNDPROC)gTrayMode.TempWindowProc, Window, Message, wParam, lParam);
}


