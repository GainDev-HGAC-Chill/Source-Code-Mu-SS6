#pragma once

#include "stdafx.h"
#include "import.h"
#include "Protect.h"
#include "Camera.h"
#include "CustomOfflineMode.h"

#define MAX_OBJECT 	500
#define MAX_WIN_WIDTH 640
#define MAX_WIN_HEIGHT 480
#define MAX_WINDOW_EX 100
#define CS_GET_STRUCT(x, y)	   (1124 * x + *(int*) y)
#define pDrawInterfaceNumBer   ((double(__stdcall*)(float X, float Y, int num, float size)) 0x854FE0)
#define pSetItemOption			    ((void(__cdecl*)(ObjectItem * lpItem, BYTE Option, BYTE Special, BYTE Value)) 0x58B910)
void testfunc();

#define IMAGE_FRAME_I3                961630
#define GMT (24 + (gProtect.m_MainInfo.TIME_GMT))


enum ObjectID
{
	eFlag01=1,
	eFlag02, 
	eFlag03,
	eFlag04,
	eFlag05,
	eFlag06,
	eFlag07,
	eFlag08,
	eFlag09,
	eFlag10,
	eFlag11,
	eFlag12,
	eFlag13,
	eFlag14,
	eFlag15,
	eFlag16,
	eFlag17,
	eFlag18,
	eFlag19,
	eFlag20,
	eFlag21,
	eFlag22,

	eFlag23,
	eFlag24,
	eFlag25,
	eFlag26,
	eFlag27,
	eFlag28,
	eFlag29,
	eFlag30,
	eFlag31,

	eTIME,
	eRankPANEL_MAIN,
	eRanking,
	eSAMPLEBUTTON,
	eSAMPLEBUTTON2,
	eVip_MAIN,
	eVip_TITLE,
	eVip_FRAME,
	eVip_FOOTER,
	eVip_DIV,
	eVip_CLOSE,
	eVip_BRONZE,
	eVip_SILVER,
	eVip_GOLD,
	eVip_PLATINUM,
	eVip_STATUS,
#if(RANKINGGOC == 1)
	// ranking 8xteam
	eRanking_MAIN,
	eRanking_CLOSE,
	eRanking_TITLE,
	eRanking_FRAME,
	eRanking_FOOTER,
	eRanking_Select,
	eRanking_BXH1,
	eRanking_BXH2,
	eRanking_BXH3,
	eRanking_BXH4,
	eRanking_BXH5,
	eRanking_BXH6,
	eRanking_BXH10,
	eRanking_BXH11,
	eRanking_BXH12,
	eRanking_BXH13,
	eRanking_BXH14,
	eRanking_BXH15,
	eRanking_BXH7,
	eRanking_BXH8,
	eRanking_BXH9,
	eRanking_Top1,
	eRanking_Top2,
	eRanking_Top3,
	eRanking_Top4,
#endif
	eLogo,
	eEventTimePANEL_MAIN,
	eEventTime_MAIN,
	eEventTime_TITLE,
	eEventTime_CLOSE,

	#if(OFFLINE_MODE_NEW)
	eOFFEXP_MAIN,
	eOFFEXP_TITLE,
	eOFFEXP_FRAME,
	eOFFEXP_FOOTER,
	eOFFEXP_DIV,
	eOFFEXP_CLOSE,
	eOFFEXP_POINT,
	eOFFEXP_CHECKBOX_BUFF,
	eOFFEXP_CHECKBOX_PICK_ZEN,
	eOFFEXP_CHECKBOX_PICK_JEWELS,
	eOFFEXP_CHECKBOX_PICK_EXC,
	eOFFEXP_CHECKBOX_PICK_ANC,
	eOFFEXP_CHECKBOX_SELECTED_HELPER,
	eOFFEXP_BTN_OK,

	eOFFEXP_SKILL1,
	eOFFEXP_SKILL2,
	eOFFEXP_SKILL3,
#endif

	eWindowNPC_BattleRoyale,
	eWindowBXH_BattleRoyale,

	eMenu,
	eMenuBG,
	eMenu_MAIN,
	eMenu_CLOSE,
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

	//button event
	eMenu_OPT21,
	eMenu_OPT22,
	eMenu_OPT23,
	eMenu_OPT24,
	eMenu_OPT25,
	eMenu_OPT26,
	eMenu_OPT27,
	eMenu_OPT28,
	eMenu_OPT29,
	eMenu_OPT30,
	eMenu_OPT31,
	eMenu_OPT32,
	eMenu_OPT33,
	eMenu_OPT34,
	eMenu_OPT35,
	eMenu_OPT36,
	eMenu_OPT37,
	eMenu_OPT38,
	eMenu_OPT39,
	eMenu_OPT40,
	eMenu_OPT41,
	eMenu_OPT42,
	eMenu_OPT43,
	eMenu_OPT44,
	eMenu_OPT45,
	eMenu_OPT46,
	eMenu_OPT47,
	eMenu_OPT48,
	eMenu_OPT49,
	eMenu_OPT50,
	eMenu_OPT51,
	eMenu_OPT52,
	eMenu_OPT53,
	eMenu_OPT54,
	eMenu_OPT55,
	eMenu_OPT56,
	eMenu_OPT57,
	eMenu_OPT58,
	eMenu_OPT59,
	eMenu_OPT60,
	eMenu_OPT61,
	eMenu_OPT62,

	eCommand_MAIN,
	eCommand_TITLE,
	eCommand_FRAME,
	eCommand_FOOTER,
	eCommand_DIV,
	eCommand_CLOSE,
	eOFFTRADE_JoB,
	eOFFTRADE_JoS,
	eOFFTRADE_JoC,
	eOFFTRADE_WCC,
	eOFFTRADE_WCP,
	eOFFTRADE_WCG,
	eOFFTRADE_OPEN,
	//Minimap

		//
	ePLAYER_POINT,
	eNULL_MAP,
	eLORENCIA_MAP,
	eDUNGEON_MAP,
	eDEVIAS_MAP,
	eNORIA_MAP,
	eLOSTTOWER_MAP,
	eSTADIUM_MAP,
	eATLANS_MAP,
	eTarkan_MAP,
	eElbeland_MAP,
	eICARUS_MAP,
	eLANDOFTRIALS_MAP,
	eAIDA_MAP,
	eCRYWOLF_MAP,
	eKANTRU_MAP,
	eKANTRU3_MAP,
	eBARRACKS_MAP,
	eCALMNESS_MAP,
	eRAKLION_MAP,
	eVULCANUS_MAP,
	eKALRUTAN_MAP,
	eKALRUTAN2_MAP,
	eCONFIRM_MAIN,
	eCONFIRM_BTN_OK,
	eCONFIRM_BTN_CANCEL,
	eCONFIRM_TITLE,
	eCONFIRM_FRAME,
	eCONFIRM_FOOTER,
	eCONFIRM_DIV,
	eNextCommand,
	ePrevCommand,
	eNextEvent,
	ePrevEvent,
//Ex700
	eMainEx700,
	eQuest,
	eCommunity,
	eSystem,
	//--custom
	eSTORE_CLOSE,
	ex_INFO_2,
	eADVANCE_STAT_INFO,
	//--
	//--s2
	eMainS2right,
	eMainS2middle,
	eMainS2left,
	eSkillBox,
	eDragonLeft,
	eDragonRight,
	eCharacter,
	eInventory,
	eParty,
	eFriend,
	eFastMenu,
	eShop,
	eGuild,
	//--custom money
	eMoney1,
	eMoney2,
	CharacterSelect,
	CharacterSelect_Button1,
	CharacterSelect_Button2,
	CharacterSelect_Button3,
	CharacterSelect_Button4,
	CharacterSelect_Button5,
	CharacterCreate_Button1,
	CharacterCreate_Button2,
	CharacterCreate_Button3,
	CharacterCreate_Button4,
	CharacterCreate_Button5,
	CharacterCreate_Button6,
	CharacterCreate_Button7,
	CharacterCreate_SEND,
	CharacterCreate_CANCEL,
	//chat
	chatbackground,
	MINIMAP_FRAME,
	MINIMAP_TIME_FRAME,
	MINIMAP_BUTTOM,
	ButtonSettings,
	ButtonStart,
	ButtonStop,
	ButtonStartAttack,
	eCamera3DInit,
	eCamera3DSwitch,
	strucMoveInv,
	eMainEx700Exp,
	RuudShopListIzq,
	RuudShopListDer,
	RuudShopWindow,
	RuudShopExit,
	eButton1,
	eButton2,
	eButton3,
	eButton4,
	eButton5,

	//-- Button Option New
	eButtonOption1,
	eButtonOption2,
	eButtonOption3,
	eButtonOption4,
	eButtonOption5,
	eButtonOption6,
	eButtonOption7,
	eButtonOption8,

	eConfigHelper,

	eNEWS_MAIN,
	eNEWS_TITLE,
	eNEWS_FRAME,
	eNEWS_FOOTER,
	eNEWS_DIV,
	eNEWS_INFOBG,
	eNEWS_CLOSE,
	eNEWS_BACK,

#if(DANH_HIEU_NEW)
	EXBEXO_DANH_HIEU_MAIN,
	EXBEXO_DANH_HIEU_CLOSE,
	EXBEXO_DANH_HIEU_NANG_CAP,
	eDANH_HIEU1,
	eDANH_HIEU2,
#endif

#if(QUAN_HAM_NEW)
	EXBEXO_QUAN_HAM_MAIN,
	EXBEXO_QUAN_HAM_CLOSE,
	EXBEXO_QUAN_HAM_NANG_CAP,
	eQUAN_HAM1,
	eQUAN_HAM2,
#endif


#if(TU_LUYEN_NEW)
	EXBEXO_TU_LUYEN_MAIN,
	EXBEXO_TU_LUYEN_CLOSE,
	EXBEXO_TU_LUYEN_NANG_CAP,
	eTU_LUYEN1,
	eTU_LUYEN2,
#endif


#if (RESETCHANGE == 1)
	eRESETCHANGE,
	eBOTON1,
	eBOTON2,
	eBOTON3,
	eBOTON4,
	eBOTON5,
#endif


#if(THANMA)
	//===Than Ma Chien
	eWindowNPC_ThanMaChien,
	eWindowBXH_ThanMaChien,
#endif
	eWindowEventGreatPK,
	eWindowEventDauTruong,

	eDameGray,
	eDameColor,


	eCuaSoCTC,
	eTimeCTC,
	eCTCMiniWindow,



#if(EXBEXO_LOAD_SEND_TINH_NANG)
	EXBEXO_AUTORESET_INTERFACE,
	EXBEXO_QUESTCLASS_INTERFACE,
	EXBEXO_OFFATTACK_INTERFACE,
	EXBEXO_UYTHAC_INTERFACE,
	EXBEXO_TAYDIEM_INTERFACE,
	EXBEXO_TAYDIEMMASTER_INTERFACE,
#endif

#if(PARTYSEARCH==1)
	ePARTYSETTINGS_MAIN,
	ePARTYSETTINGS_TITLE,
	ePARTYSETTINGS_FRAME,
	ePARTYSETTINGS_FOOTER,
	ePARTYSETTINGS_DIV,
	ePARTYSETTINGS_CLOSE,
	ePARTYSETTINGS_SYSTEM_ACTIVE,
	ePARTYSETTINGS_ONLY_GUILD,
	ePARTYSETTINGS_ONE_CLASS,
	ePARTYSETTINGS_DARK_WIZARD,
	ePARTYSETTINGS_DARK_KNIGHT,
	ePARTYSETTINGS_ELF,
	ePARTYSETTINGS_MAGIC_GLADIATOR,
	ePARTYSETTINGS_DARK_LORD,
	ePARTYSETTINGS_SUMMONER,
	ePARTYSETTINGS_RAGE_FIGHTER,
	ePARTYSETTINGS_LEVEL_MINUS,
	ePARTYSETTINGS_LEVEL_PLUS,
	ePARTYSETTINGS_OK,
	ePARTYSEARCH_LEFT,
	ePARTYSEARCH_RIGHT,
	ePARTYSEARCH_MAIN,
	ePARTYSEARCH_TITLE,
	ePARTYSEARCH_FRAME,
	ePARTYSEARCH_FOOTER,
	ePARTYSEARCH_DIV,
	ePARTYSEARCH_CLOSE,
#endif
	eTVTHUD,

#if(CAMERA)
	eCAMERA_MAIN,
	eCAMERA_BUTTON1,
	eCAMERA_BUTTON2,
	eCAMERA_BUTTON_UP1,
	eCAMERA_BUTTON_UP2,
#endif
#if(B_HON_HOAN)
	eWindow_NangCapHonHoan,
#endif
#if(FLAG_SKIN)
	eMAIN_ThueFlag,
#endif

#if(THONG_TIN_BOSS)
	eInvasionInfo,
#endif
#if(VONGQUAY_NEW)
	eWindowVongQuay,
#endif
#if(B_MOCNAP)
	eWindowMocNap,
	eWindowMocNapList,
#endif

	eWindowDoiItem,
	eWindow_CongHuong,
	//--
	eWindowDungLuyenItem,

	eWindowElemental,
	eWindowHarmony,
	eToolTip_ID,

	eWindow_SkinModel,
	eWindow_SkinModelNext,
	eWindow_SkinModelPREV,

	eThongTinDonnate,
	eWindowMessageBox,


};
#if(B_HON_HOAN)
enum ImgHonHoan
{
	eImgHonHoan = 20000,
	eDemoHonHoan = eImgHonHoan + 100,
};
#endif

#if(JEWELBANKVER2)
enum TypeRutGuiBank
{
	eRut1,
	eRut10,
	eRut20,
	eRut30,
	eRutAll,
	eGuiAll,
	eAutoPick,

};

#endif


struct InterfaceElement
{
	DWORD	ModelID;
	float	Width;
	float	Height;
	float	X;
	float	Y;
	float	MaxX;
	float	MaxY;
	DWORD	EventTick;
	bool	OnClick;
	bool	OnShow;
	BYTE	Attribute;
	long	OpenedValue;
	BYTE	Speed;
	char	StatValue[20];
	bool	ByClose;
	bool	FirstLoad;
	//int		Type;

	float  curX;
	float	curY;
	bool	Hover;

	void Open()
	{
		this->OnShow = true; pSetCursorFocus = true;
		this->ByClose = false;
	};

	void Open(int Value, int Speed)
	{
		this->OnShow = true; pSetCursorFocus = true;
		this->OpenedValue = Value;
		this->Speed = Speed;
		this->ByClose = false;
		this->FirstLoad = true;
	};

	void Close()
	{
		this->OnShow = false;
		pSetCursorFocus = false;
		this->ByClose = false;
	};

	void Close(int Value, int Speed)
	{
		this->OnShow = false; pSetCursorFocus = false;
		this->OpenedValue = Value;
		this->Speed = Speed;
		this->ByClose = false;
	}

	void CloseAnimated(int Speed)
	{
		pSetCursorFocus = false;
		//this->OpenedValue = Value;
		this->Speed = Speed;
		this->ByClose = true;
	}

	bool Check()
	{
		return this->OnShow;
	}
};
struct InterfaceObject
{
	DWORD	ModelID;
	float	Width;
	float	Height;
	float	X;
	float	Y;
	float	MaxX;
	float	MaxY;
	DWORD	EventTick;
	bool	OnClick;
	bool	OnShow;
	DWORD	Attribute;
	long	OpenedValue;
	BYTE	Speed;
	char	StatValue[20];
	bool	ByClose;
	bool	FirstLoad;
	//int		Type;

	void Open()
	{
		this->OnShow = true; pSetCursorFocus = true;
		this->ByClose = false;
	};

	void Open(int Value, int Speed)
	{
		this->OnShow = true; pSetCursorFocus = true;
		this->OpenedValue = Value;
		this->Speed = Speed;
		this->ByClose = false;
		this->FirstLoad = true;
	};

	void Close()
	{
		this->OnShow = false;
		pSetCursorFocus = false;
		this->ByClose = false;
	};

	void Close(int Value, int Speed)
	{
		this->OnShow = false; pSetCursorFocus = false;
		this->OpenedValue = Value;
		this->Speed = Speed;
		this->ByClose = false;
	}

	void CloseAnimated(int Speed)
	{
		pSetCursorFocus = false;
		//this->OpenedValue = Value;
		this->Speed = Speed;
		this->ByClose = true;
	}

	bool Check()
	{
		return this->OnShow;
	}

};

//======================================================
struct PMSG_TVTEVENT_UPD
{
	PSBMSG_HEAD	h;
	int ScoreRed;
	int ScoreBlue;
	int KillCount;
	int DieCount;
	int TotalPlayer;
};
//======================================================

struct PMSG_CLIENT_UPD
{
	PSBMSG_HEAD	h;
	int DanhHieu;
	int QuanHam;
	int TuLuyen;
	int PartyNumberD;

};

struct GREATPKEVENT_BXH
{
	int Rank;
	int Score;
	char Name[11];
};


struct INFO_KILLS
{
	char	Player[11];
	char	Target[11];
	BYTE	ON;
};

struct PSWMSG_KILL_RECV
{
	PBMSG_HEAD header;
	char	Player[11];
	char	Target[11];
	BYTE	ON;
};

struct DATA_NOTICEPK
{
	int Delay;
	DWORD	Color;
	DWORD	Time;
	char	Mess[90];
};

struct DAUTRUONGEVENT_BXH
{
	int Rank;
	int Score;
	char Name[11];
};

#if(CUSTOM_DUNGLUYENITEM)
struct ITEM_INFO_DATA
{
	int IndexItem;
	int Level;
	int Skill;
	int Luck;
	int Option;
	int Exc;
	int Dur;
};

#if(JEWELBANKVER2)
struct USER_BANK_DATA
{
	int ItemIndex;
	int ItemLevel;
	int ItemCount;
	int AutoPick;
	void Clear()
	{
	ItemIndex = -1;
	ItemLevel = 0;
	ItemCount = 0;
	AutoPick = 0;
	}
};
//==== Packer Rut Gui Ngoc
struct REQUEST_RUTGUIBANK
{
	PSBMSG_HEAD header; // C3:F3:03
	BYTE TypeSend;
	short IndexList;
};
#endif

//typedef struct CSEV_COUNTLIST
//{
//	PSWMSG_HEAD header;
//	int Count;
//};
#endif


class Interface
{
public:
	void		Load();
	static void LoadImages();
	static int		LoadImg(char * Folder, DWORD ID);
	void		LoadImages2(char * Folder, int Code, int Arg3, int Arg4, int Arg5);
	static void LoadModels();
	static void Work();
	int ConfirmSlot;
	float PetY;
	float PetX;
	int lastReport;
	int frameCount;
	int frameRate;
	char FPS_REAL[30];
	void UPDATE_FPS();
	void guiMonitore();
	int iniciador;
	int msPing;
	int lastSend;
	int validar;
	char ServerPing[50];
	char ultimoPing[50];
	int ultimo_Ping;
	char ServerRTT[50];
	char ultimoRTT[50];
	int ultimo_RTT;
	//--
	InterfaceElement Data[MAX_OBJECT];

	WORD		mGreatPK_Rank;
	WORD		mGreatPK_Score;
	DWORD		mGreatPK_Time;
	BYTE		mGreatPK_State;
	void mGreatPKClearInfo()
	{
		mGreatPK_Rank = 0;
		mGreatPK_Score = 0;
		mGreatPK_Time = 0;
		mGreatPK_State = 0;
	}
	void EventGreatPKShow();
	std::vector<GREATPKEVENT_BXH> mGreatPKBXHData;
	//--


#if(VONGQUAY_NEW)
	int StartRollSau;
	int IndexItemSau;
	void Interface::OpenWindowVongQuay();
	void Interface::DrawWindowVQ();
#endif

#if(B_MOCNAP)
	void Interface::DrawXemMocNap();
	void Interface::DrawWindowMocNap();
	void Interface::OpenWindowMocNap();
#endif
#if(CUSTOM_DUNGLUYENITEM)
	std::vector<ITEM_INFO_DATA> m_DungLuyenInfoList;
	void NhanListItemDungLuyen(CSEV_COUNTLIST* lpMsg);
	void DrawDungLuyenItem();
	bool DL_ActiveMix;
	bool DL_EffectsMix;
	bool SetStateDungLuyen;
	BYTE DL_ItemChinh[16];
	BYTE DL_ItemPhu[3][16];
	BYTE DL_ItemKetQua[16];
	int RateDL;
	int TypeDL;
	char TextDL[100];
#endif

#if(SAUDOIITEM)
	void DrawInfoItemSet();
	void DrawDoiItem();
	bool SAU_ActiveMix;
	bool SAU_EffectsMix;
	bool SetStateDoiItem;
	BYTE SAU_ItemChinh[16];
	BYTE SAU_ItemPhu[3][16];
	BYTE SAU_ItemKetQua[6][16];
	int RateSAU;
#endif
#if(CongHuongV2)
	int  m_ScrollPos;
	void EventScrollPos(MOUSEHOOKSTRUCTEX* Mouse, WPARAM wParam);
	BOOL CH_EffectMixOn;
	int CH_IndexItem[3];
	int CH_CoinMix[3];
	int CH_TyLeThanhCong;
	int CH_ResetMix;
	int CH_TypeMix;
	int CH_CheckLvItem;
	BYTE CH_InfoItem[3][12];
	void XoaDataCongHuong();
	void DrawWindowCongHuong();
	DWORD LockMouseMoveClick;
#endif





public:
	Interface();
	virtual ~Interface();
	void RenderObjectSystem();
	//--------------------------------------
	void TvTEventEx(PMSG_TVTEVENT_UPD * aRecv);
	int m_ScoreRed;
	int m_ScoreBlue;
	int m_KillCount;
	int m_DieCount;
	int m_TotalPlayer;
	//--------------------------------------

	void GetInfoClient(PMSG_CLIENT_UPD * aRecv);
	int m_DanhHieu;
	int m_QuanHam;
	int m_TuLuyen;
	int m_PartyNumber;
	//
	//

//-- System Windows
	void OpenVipWindow(){ this->Data[eVip_MAIN].OnShow = true; };
	void CloseVipWindow() { this->Data[eVip_MAIN].OnShow = false; }
	bool CheckVipWindow() { return this->Data[eVip_MAIN].OnShow; };
	void DrawVipWindow();
	bool EventVipWindow_Main(DWORD Event);
	bool EventVipWindow_Close(DWORD Event);
	bool EventVipWindow_Bronze(DWORD Event);
	bool EventVipWindow_Silver(DWORD Event);
	bool EventVipWindow_Gold(DWORD Event);
	bool EventVipWindow_Platinum(DWORD Event);
	bool EventVipWindow_StatusVip(DWORD Event);
	//--
	void DrawMenu();
	bool EventDrawMenu_Open(DWORD Event);
	void OpenMenuWindow() { this->Data[eMenu_MAIN].OnShow = true; };
	void CloseMenuWindow() {this->Data[eMenu_MAIN].OnShow = false; };
	bool CheckMenuWindow() { return this->Data[eMenu_MAIN].OnShow; };
	void DrawMenuOpen();
	bool EventDrawMenu_Close(DWORD Event);
	bool EventDrawMenu_Op1(DWORD Event);
	bool EventDrawMenu_Op2(DWORD Event);
	bool EventDrawMenu_Op3(DWORD Event);
	bool EventDrawMenu_Op4(DWORD Event);
	bool EventDrawMenu_Op5(DWORD Event);
	bool EventDrawMenu_Op6(DWORD Event);
	bool EventDrawMenu_Op7(DWORD Event);
	bool EventDrawMenu_Op8(DWORD Event);
	bool EventDrawMenu_Op9(DWORD Event);
	bool EventDrawMenu_Op10(DWORD Event);
	bool EventDrawMenu_Op11(DWORD Event);
	bool EventDrawMenu_Op12(DWORD Event);
	bool EventDrawMenu_Op13(DWORD Event);
	bool EventDrawMenu_Op14(DWORD Event);
	bool EventDrawMenu_Op15(DWORD Event);
	bool EventDrawMenu_Op16(DWORD Event);
	bool EventDrawMenu_Op17(DWORD Event);

	//--
	void CloseEventTimeWindow() { this->Data[eEventTimePANEL_MAIN].OnShow = false; }
	void CloseERankWindow() { this->Data[eRankPANEL_MAIN].OnShow = false; }
	void CloseECommandWindow() { this->Data[eCommand_MAIN].OnShow = false; }

	void DrawConfirmOpen();
	bool EventConfirm_OK(DWORD Event);
	bool EventConfirm_CANCEL(DWORD Event);



	bool gDrawButtonThongTinDonate(float PosX, float PosY);


	void WindowsKG();


//-- Funtions
	void BindObject(short ObjectID, DWORD ModelID, float Width, float Height, float X, float Y);
	void DrawGUI(short ObjectID, float PosX, float PosY);
	void DrawGUI2(short ObjectID, float PosX, float PosY);
	void WindowDraw(short ObjectID, float PosX, float PosY);

	void DrawGUI3(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY);
	void DrawTimeUI();
	int DrawFormat(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...);
	void DrawIMG(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY);
	void ResetDrawIMG(short ObjectID);
	int DrawMessage(int Mode, LPCSTR Text, ...);
	void DrawItem(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse);
	void DrawItem2(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse);

#if(JEWELBANKVER2)
	//bool RenderCheckBox(float PosX, float PosY, DWORD TextColor, bool Checkis, LPCSTR Text, ...);
	//void DrawItem3D(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int ExtOption, int Ancient, bool PickUp, float Scale = 1.0f, bool Center = true);
	void DrawWindowJewelBankVer2();
	std::vector<USER_BANK_DATA> mCListItemBank;
	void OnOffWindowBank();
#endif


	void DrawWindow(int ObjMain, int ObjTitle, int ObjFrame, int ObjFooter, int Repeat, float X, float Y, char* Text);
	bool CheckWindow(int WindowID);
	int CloseWindow(int WindowID);
	int OpenWindow(int WindowID);
	bool IsWorkZone2(float X, float Y, float MaxX, float MaxY);
	bool   IsWorkZone4(float, float, float, float);
	bool IsWorkZone69(float, float, float, float);

#if(EventSinhTon)
	void DrawBattleRoyaleALL();
	DWORD	m_EventBattleRoyaleTimeCount;
	int m_EventBattleRoyaleState;
	int m_EventBattleRoyaleMap;
	int mBattleRoyaleEventTick;
	int m_BattleRoyaleBXHC;
	int m_DiemGiet;
	int m_DiemChet;
	BATTLEROYALE_BXH m_BattleRoyaleBXH[10];
	void BattleRoyaleReset() // OK
	{
		this->m_BattleRoyaleBXHC = 0;
		this->mBattleRoyaleEventTick = 0;
		this->m_DiemGiet = 0;
		this->m_DiemChet = 0;
		this->m_EventBattleRoyaleTimeCount = 0;
	}
#endif

	bool IsWorkZone(short ObjectID);
	//-- Mover MiniMapa
	bool	IsWorkZone(float X, float Y, float MaxX, float MaxY, bool a5 = false);

	float GetResizeX(short ObjectID);
	int DrawToolTip(int X, int Y, LPCSTR Text, ...);
	float DrawRepeatGUI(short MonsterID, float X, float Y, int Count);
	float DrawRepeatGUIScale(short MonsterID, float X, float Y,float ScaleX, float ScaleY, int Count);
	void DrawColoredGUI(short ObjectID, float X, float Y, DWORD Color);
	void DrawButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY);
	void DrawButtonRender(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY);
	void DrawLogo(bool active);
	void CloseCustomWindow();

	//Mini Map
	void DrawMiniMap();
	bool MiniMapCheck();
	bool CombinedChecks();
	bool CheckMap();
	void SwitchMiniMap();

	void	MiniMapMini();

	// ex700
	void DrawInterfaceCustom();
	// s2
	void DrawInterfaceS2Menu();
	void DrawInterface97Menu();
	void EventNewInterface_All(DWORD Event);
	void EventNewInterface97_All(DWORD Event);
	void DrawCoord();
	void DrawInterfaceDragonLS3();
	void DrawInterfaceDragonRS3();
	// Advanced Stats
	bool WindowEx[MAX_WINDOW_EX];
	bool CheckWindowEx(int WindowID);
	void DrawBarForm(float PosX,float PosY,float Width,float Height,GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
	//--
	void OpenConfig(int type);
	void SwitchCamera();
	void SwitchChatExpand();
	void SwitchHideDanhHieu();
	void CameraInit();

	void DrawShowIcon();
	int TimeInterface;

	void SwitchAntiLag1();
	void SwitchAntiLag2();

	int  AntiLag1;
	int  AntiLag2;


	static void DrawItemToolTipText(void * item, int x, int y);
	bool Button(DWORD Event, int WinID, int ButtonID, bool Type);
	bool		ButtonEx(DWORD Event, int ButtonID, bool Type);
	int			DrawToolTipEx(DWORD Color, int PosX, int PosY, int Width, int Height, int Align, LPCSTR Text, ...);
	void		DrawText(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...);

	void DrawPing();
	void SendPingRecv();
	void NewLoadInterface();
	static void DrawZenAndRud(int a1, int a2, int a3, int a4);

	BOOL        is_auto;
	BOOL        is_autotron;

	void	    TvTEvent();





#if(CHIEN_TRUONG_CO)
	void		DrawChienTruongCo();
	void		DrawTimeCTC();
#endif

	//////CTCmini//////////
	void		DrawCTCMiNiMap();
	void		DrawCTCMiniWindow();


#if(EXBEXO_LOAD_SEND_TINH_NANG)
	void		DRAW_TINHNANG_INTERFACE();
	bool		EVENT_TINHNANG_INTERFACE(DWORD Event);
	bool		EVENT_AUTORESET_INTERFACE(DWORD Event);
	bool		EVENT_LAMNHIEMVU_INTERFACE(DWORD Event);
	bool		EVENT_OFFATTACK_INTERFACE(DWORD Event);
	bool		EVENT_UYTHAC_INTERFACE(DWORD Event);
	bool		EVENT_TAYDIEM_INTERFACE(DWORD Event);
	bool		EVENT_TAYDIEM_MASTER_INTERFACE(DWORD Event);
#endif
	//---------------------------------------------------------------------------------------------------------------------------------

#if (THANMA)
	//=== Event Chien Truong Than Ma
	void DrawTMAllWindows();
	int	m_EventTMTimeCount;
	int m_EventTMState;
	int m_EventTMMap;
	int mCalcTimeEventTick;
	int m_TMScoreThienThan;
	int m_TMScoreAcQuy;
	int m_TMChienBXHC;
	EVENTHANMA_BXH m_ThanMaChienBXH[10];
	void TMReset() // OK
	{
		this->m_TMChienBXHC = 0;
		this->m_TMScoreThienThan = 0;
		this->m_TMScoreAcQuy = 0;
		this->mCalcTimeEventTick = 0;
		this->m_EventTMTimeCount = 0;
	}
#endif


	bool IsWorkZone1(float, float, float, float);
	char* NumberFormat(int Number);
	char* NumberFormat(DWORD Number);


	std::vector<BCUSTOM_SKINMODEL_DATA> m_SkinModelData;
	std::vector<SKIN_MODEL_DATA> m_SkinModelInfoSelect;
	bool SelectInfoSkin;

#if(B_HON_HOAN)
	std::map<int, CONFIDATA_HONHOAN> m_DataConfigHonHoan;
#endif

	void SetCursorFocus();
	float ImagesNumber(BYTE Color, float x, float y, int iNum, float fScale);


	void gDrawWindowCustom(float StartX, float StartY, float CuaSoW, float CuaSoH, int eNumWindow, char* WindowName);
	void gInfoBox(float PosX, float PosY, float Width, float Height, DWORD bkcolor, float Arg5, int Arg6);
	bool gDrawButton(float PosX, float PosY, float SizeButton, int FontSize, char* ButtonText);
	void DrawFrame(DWORD ModelID, float X, float Y, float W, float H, float SourceX = 0, float SourceY = 0, float SourceW = 225, float SourceH = 225, float ScaleW = 1.5f, float ScaleH = 1.5f, bool ScaleUp = 0);

#if(THONG_TIN_BOSS)
	void Interface::DrawBtnTTBOSS();
#endif

#if(OFFLINE_MODE_NEW)
	void		DrawOffExpWindow();
	bool		EventOffExpWindow_Main(DWORD Event);
	void		SwitchOffExpWindoState() { (Data[eOFFEXP_MAIN].OnShow == true) ? Data[eOFFEXP_MAIN].Close() : gOfflineMode.CGOfflineModeSend(); };
#endif

	//--------------------------------------
#if OLD_PKNOTICE
	BYTE mKillON;
	std::vector<INFO_KILLS> m_KillLog;
	void KillRecv(BYTE*);
	void DrawKill();
	int m_KillInterface;
#endif

	//--------------------------------------
	WORD		mDauTruong_Rank;
	WORD		mDauTruong_Score;
	DWORD		mDauTruong_Time;
	BYTE		mDauTruong_State;
	void mDauTruongClearInfo()
	{
		mDauTruong_Rank = 0;
		mDauTruong_Score = 0;
		mDauTruong_Time = 0;
		mDauTruong_State = 0;
	}
	void DrawNoticePKSystem();
	std::vector<DATA_NOTICEPK> m_DataNoticePK;
	void EventDauTruongShow();
	std::vector<DAUTRUONGEVENT_BXH> mDauTruongBXHData;
	//--------------------------------------




private:
	
};
extern Interface gInterface;
