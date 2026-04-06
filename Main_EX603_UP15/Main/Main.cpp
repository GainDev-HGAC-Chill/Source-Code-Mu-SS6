#include "stdafx.h"
#include "resource.h"
#include "Main.h"
#include "..\\..\\Util\\CCRC32.H"
#include "Common.h"
#include "Controller.h"
#include "CustomBuyVip.h"
#include "CustomCommandInfo.h"
#include "CustomEventTime.h"
#include "CustomItem.h"
#include "CustomJewel.h"
#include "CustomMap.h"
#include "CustomMonster.h"
#include "CustomNpcName.h"
#include "CustomWing.h"
#include "Fix.h"
#include "StaticEffect.h"
#include "DynamicEffect.h"
#include "HackCheck.h"
#include "HealthBar.h"
#include "Item.h"
#include "ItemShopValue.h" 
#include "ItemSmoke.h"
#include "Interface.h"
#include "OffTrade.h"
#include "PacketManager.h"
#include "PrintPlayer.h"
#include "Protect.h"
#include "Protocol.h"
#include "Reconnect.h"
#include "Resolution.h"
#include "User.h"
#include "Util.h"
//--
#include "InterEx.h"
#include "SelectChar.h"
#include "postInterface.h"
#include "StatsAdvance.h"
#include "CustomBow.h"
#include "CustomGloves.h"
#include "CustomPet.h"
#include "Pet.h"
#include "PetHook.h"
#include "CustomCloak.h"
#include "cape.h"
#include "ItemTRSData.h"
#include "CustomEffectRemake.h"
#include "ItemRemake.h"
#include "ItemManager.h"
#include "ItemInfoEx.h"
#include "CSCharacterS13.h"
#include "CustomItemPrice.h"
#include "MonsterGlow.h"
#include "CustomMonsterGlow.h"
#include "ModelEffect.h"
#include "CChatEx.h"
#include "CustomPetEffect.h"
#include "CChatClassic.h"
#include "CMacroUIEx.h"
#include "TrayModeNew.h"
#include "MiniMap.h"
#include "WindowsStruct.h"
#include "SItemOption.h"
#include "ItemTooltip.h"
#include "PetMontura.h"
#include "Central.h"
#include "BuffIcon.h"
#include "MuHelper.h"
//--
#include "Inter3.h"
#include "CChatClassic.h"
#include "cCPetRenderMesh.h"
#include "MultiSelect.h"
#include "ItemTooltip.h"
#include "JCRendernoItemGlow.h"
#include "ItemGlow.h"

#include "CustomNameColor.h"
#include "PartyBar.h"
#include "TMemory.h"
#include "Antilag.h"
#include "CustomPhysicsBody.h"
#include "Rotate360Character.h"
#include "Config.h"
//#include "InfoLog.h"
#include "GetBarPlayer.h"
#if(ANTI_CRACK_MAIN == 1)
#include "AntiCrack.h"
#endif
#include "Font.h"
#include "GLFont.h"
#include "GuildLogo.h"
#include "QuickCommandWindow.h"
#include "MiniMap.h"
#include "WingInvisible.h"
#include "SlideHelp.h"

#include "CNewNotice.h"
//#include "CustomChatTextColor.h"
#include "LoginMainWin.h"
#include "UIControl.h"
#include "CustomServerInfo.h"
#include "AutoLoginWin.h"
#include "MessageBox.h"
#include "Graphics.h"
#include "CustomNPC.h"
#if(ANTIHACK_NEW)
//#include "BAntihack.h"
#endif
#include "NewUIMyInventory.h"
#include "WSclient.h"
#include "CNewUIScene.h"
#include "WeatherEffect.h"
HINSTANCE hins;

#if(REDUCECPU)
__declspec(naked) void ReduceCPU()
{
	static DWORD JmpBack = 0x00662725;

	__asm
	{
		Push 1;
		Call Dword Ptr Ds : [0x0075615C];
		Call Dword Ptr Ds : [0x00756140];
		Jmp[JmpBack];
	}
}
#endif

void StartAddress(LPVOID lpThreadParameter)
{
	HANDLE v1;
	HANDLE v2;

	while ( TRUE )
	{
		Sleep(5000);

		v1 = GetCurrentProcess();
		SetProcessWorkingSetSize(v1, 0xFFFFFFFF, 0xFFFFFFFF);

		v2 = GetCurrentProcess();
		SetThreadPriority(v2, -2);
//Fixx Diss Main
		if (*(int*)0x0E609E8 == 5 && (char*)*(DWORD*)(0x8128AC4) == NULL)
		ExitProcess(0);


	}
}

__declspec(naked) void OffButtonQuestInStats()
{
	static DWORD ButtonAddress = 0x0077EBB5;
	_asm{jmp ButtonAddress}
}

__declspec(naked) void OffButtonPetsInStats()
{
	static DWORD ButtonAddress = 0x0077EC5E;
	_asm{jmp ButtonAddress}
}

__declspec(naked) void OffButtonSkillMasterInStats()
{
	static DWORD ButtonAddress = 0x0077ECE7;
	_asm{jmp ButtonAddress}
}

__declspec(naked) void OffButtonInventoryExt()
{
	static DWORD ButtonAddress = 0x00836A28;
	_asm{jmp ButtonAddress}
}

__declspec(naked) void OffButtonOpenStore()
{
	static DWORD ButtonAddress = 0x008369B4;
	_asm{jmp ButtonAddress}
}
__declspec(naked) void OffButtonRepeirInInventory()
{
	static DWORD ButtonAddress = 0x00836941;
	_asm{jmp ButtonAddress}
}
//=== MuError.dmp
#include <dbghelp.h>
#pragma comment(lib,"dbghelp.lib")
//===
bool ExceptionCallback(EXCEPTION_POINTERS* pExceptionInfo)
{
	char path[MAX_PATH];

	SYSTEMTIME SystemTime;

	GetLocalTime(&SystemTime);

	wsprintf(path, "%d-%d-%d_%dh%dm%ds.dmp", SystemTime.wYear, SystemTime.wMonth, SystemTime.wDay, SystemTime.wHour, SystemTime.wMinute, SystemTime.wSecond);

	HANDLE file = CreateFile(path, GENERIC_WRITE, FILE_SHARE_WRITE, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);

	if (file != INVALID_HANDLE_VALUE)
	{
		MINIDUMP_EXCEPTION_INFORMATION mdei;

		mdei.ThreadId = GetCurrentThreadId();

		mdei.ExceptionPointers = pExceptionInfo;

		mdei.ClientPointers = 0;

		if (MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), file, (MINIDUMP_TYPE)(MiniDumpScanMemory + MiniDumpWithIndirectlyReferencedMemory), &mdei, 0, 0) != 0)
		{
			CloseHandle(file);
		}
	}

	return 1;
}


extern "C" _declspec(dllexport) void EntryProc() // OK
{
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)StartAddress, 0, 0, 0);

	if(gProtect.ReadMainFile("Data\\Local\\ServerInfo.bmd") == 0)
	{
		MessageBox(0,"ServerInfo.bmd corrupt!","Error",MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}

	if(gProtect.ReadTooltipTRSData( "Data\\Local\\TooltipTRSData.bmd" ) == 0)
	{
		MessageBox(0, "Data\\Local\\TooltipTRSData.bmd missing or File corrupt!" ,"Error", MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}

	if(gProtect.ReadMakeViewTRSData("Data\\Local\\MakeWorldTRSData.bmd") == 0)
	{
		MessageBox(0,"Data\\Local\\MakeWorldTRSData.bmd missing or File corrupt!","Error", MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}

	if(gProtect.ReadPetEffectBMD("Data\\Local\\EffectTRSData.bmd") == 0)
	{
		MessageBox(0,"Data\\Local\\EffectTRSData.bmd missing or File corrupt!","Error", MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}
	
	//gInfoLog.Load();

#if(REDUCECPU)
	//-
	SetCompleteHook(0xE9, 0x0066271F, &ReduceCPU);
	//-
#endif
	MemorySet(0x82AC07, 0x90, 0x5);  // TAC DUNG CPU
	MemorySet(0x82B03D, 0x90, 0x5);  // TAC DUNG CPU
	MemorySet(0x82B0A7, 0x90, 0x5);  // TAC DUNG CPU
	MemorySet(0x82B18B, 0x90, 0x5);  // TAC DUNG CPU
	MemorySet(0x82B1FA, 0x90, 0x5);  // TAC DUNG CPU
	MemorySet(0x82B21B, 0x90, 0x5);  // TAC DUNG CPU
	MemorySet(0x82B2CB, 0x90, 0x5);  // TAC DUNG CPU
	MemorySet(0x82B339, 0x90, 0x5);  // TAC DUNG CPU
	MemorySet(0x82B3B7, 0x90, 0x5);  // TAC DUNG CPU
	MemorySet(0x82B3CA, 0x90, 0x5);  // TAC DUNG CPU
	MemorySet(0x82B772, 0x90, 0x5);  // TAC DUNG CPU



	SetByte(0x00E61144, 0xA0); // Accent
	SetByte(0x004D1E69, 0xEB); // Crack (mu.exe)
	SetByte(0x004D228D, 0xE9); // Crack (SharkGuard)
	SetByte(0x004D228E, 0x8B); // Crack (SharkGuard)
	SetByte(0x004D228F, 0x00); // Crack (SharkGuard)
	SetByte(0x004D2290, 0x00); // Crack (SharkGuard)
	SetByte(0x004D2291, 0x00); // Crack (SharkGuard)
	SetByte(0x004D559C, 0xEB); // Crack (ResourceGuard)
	SetByte(0x00633F7A, 0xEB); // Crack (ResourceGuard)
	SetByte(0x00634403, 0xEB); // Crack (ResourceGuard)
	SetByte(0x0063E6C4, 0xEB); // Crack (ResourceGuard)
	SetByte(0x004D2246, 0xEB); // Crack (ResourceGuard)
	SetByte(0x00501163, 0xEB); // Crack (ResourceGuard)
	SetByte(0x0040AF0A, 0x00); // Crack (ResourceGuard)
	SetByte(0x0040B4BC, 0x50); // Login Screen
	SetByte(0x0040B4C5, 0x50); // Login Screen
	SetByte(0x0040B4CF, 0x18); // Login Screen
	SetByte(0x0040AF0A, 0x00); // Login Screen
	SetByte(0x0040AFD5, 0xEB); // Login Screen
	SetByte(0x00777FD6, 0x70); // Item Text Limit
	SetByte(0x00777FD7, 0x17); // Item Text Limit
	SetByte(0x004EBEC7, 0x3C); // Item Text Limit
	SetByte(0x005C4004, 0x3C); // Item Text Limit
	SetByte(0x007E40BB, 0x3C); // Item Text Limit
	SetByte(0x0081B546, 0x3C); // Item Text Limit
	SetByte(0x0081B58D, 0x3C); // Item Text Limit
	SetByte(0x0086E284, 0x3C); // Item Text Limit
	SetByte(0x0086E44C, 0x3C); // Item Text Limit
	SetByte(0x0086E573, 0x3C); // Item Text Limit
	SetByte(0x0086F8FC, 0x3C); // Item Text Limit
	SetByte(0x007DA373, 0xB7); // Item Type Limit
	SetByte(0x007E1C44, 0xB7); // Item Type Limit
	SetByte(0x0052100D, 0xEB); // Ctrl Fix
	//SetByte((LPVOID)0x0052101B,0x02); //Fix CTRL Freeze
	SetByte(0x009543C4, 0x00); // Move Vulcanus
	SetByte(0x004D128F, 0x1D); // Fix Resolucion 640x480

	SetCompleteHook(0xE9, 0x005880F0, 0x0058811F); //Fix gm wing on Blood castle
	SetDword(0x00588444 + 3, 4095);


	SetCompleteHook(0xE9, 0x004D1CF0, &ExceptionCallback);

	//SetCompleteHook(0xE9, 0x004D1CF0, 0x004D1DC2); //-- Remoce MuError.DMP
	//MemorySet(0x00D20170, 0x90, 0x1B); //-- Remove Creation MuError.log

	SetByte(0x0064CBD1,((gProtect.m_MainInfo.HelperActiveAlert==0) ? 0xEB : 0x75)); //-- Helper Message Box
	SetByte(0x0064CBD0,(BYTE)gProtect.m_MainInfo.HelperActiveLevel); //-- Helper Active Level
	SetByte(0x0095CEEF,(BYTE)gProtect.m_MainInfo.HelperActiveLevel); //-- Helper Active Level
	SetByte(0x0095CF14,(BYTE)gProtect.m_MainInfo.HelperActiveLevel); //-- Helper Active Level
	SetByte(0x00E61F68,(gProtect.m_MainInfo.ClientVersion[0]+1)); //-- Version
	SetByte(0x00E61F69,(gProtect.m_MainInfo.ClientVersion[2]+2)); //-- Version
	SetByte(0x00E61F6A,(gProtect.m_MainInfo.ClientVersion[3]+3)); //-- Version
	SetByte(0x00E61F6B,(gProtect.m_MainInfo.ClientVersion[5]+4)); //-- Version
	SetByte(0x00E61F6C,(gProtect.m_MainInfo.ClientVersion[6]+5)); //-- Version

	//Remover Limite de Zen Storage
	SetByte((PVOID)(0x007AF175 + 1), 9);
	SetByte((PVOID)(0x007AF415 + 1), 9);
	SetByte((PVOID)(0x007AF795 + 1), 9);
	SetByte((PVOID)(0x007B0315 + 1), 9);

	SetWord(0x00E609E4,(gProtect.m_MainInfo.IpAddressPort)); //-- IpAddressPort
	SetDword(0x004D9D3B,(DWORD)&FrameValue);
	SetDword(0x004DAC60,(DWORD)&FrameValue);
	SetDword(0x7B55338,(DWORD)10);
	SetDword(0x004D597B,(DWORD)&MainTickCount);
	SetDword(0x004DA289,(DWORD)&MainTickCount);
	SetDword(0x004DA297,(DWORD)&MainTickCount);
	SetDword(0x004DA3A2,(DWORD)&MainTickCount);
	SetDword(0x004DA3CE,(DWORD)&MainTickCount);
	SetDword(0x004DA3D9,(DWORD)&MainTickCount);
	SetDword(0x0063D326,(DWORD)&MainTickCount);
	SetDword(0x00642112,(DWORD)&MainTickCount);
	SetDword(0x004D0E09,(DWORD)gProtect.m_MainInfo.WindowName);
	SetDword(0x004D9F55,(DWORD)gProtect.m_MainInfo.ScreenShotPath);

	//SetDword(0x00954148 + 1, (DWORD)gProtect.m_MainInfo.ServerName1); //-> (Gold)
	//SetDword(0x00954115 + 1, (DWORD)gProtect.m_MainInfo.ServerName2); //-> (Gold PVP)
	//SetDword(0x009540E2 + 1, (DWORD)gProtect.m_MainInfo.ServerName3); //-> (Non-PVP)
	//SetDword(0x009540AC + 1, (DWORD)gProtect.m_MainInfo.ServerName4); //-> Sem Nada


	MemorySet(0x00792B7F, 0x90, 0x05);	// Fix Button Crywolf Gatekeeper (Third Quest)

	SetCompleteHook(0xE9, 0x0095DFBE, 0x0095DFD3); // Helper + Inventory

	SetByte(0x005C914B+3, 0x00); //-- LuckItemmove

	MemorySet(0x0063E908,0x90,20); //-- C1:F3:04

	SetCompleteHook(0xE9, 0x0064452A, 0x00644537); //-- Fix montura


	//SetCompleteHook(0xE9, 0x0071AE92, 0x00720894); //Fix RF Skill
	//SetCompleteHook(0xE9, 0x0071B1A3, 0x00720894); //Fix RF Skill

	SetCompleteHook(0xE9, 0x0071B1A3, 0x00720894); //-- Fix RF
	SetCompleteHook(0xE9, 0x0095DFBE, 0x0095DFD3); //-- Fix RF

	SetFloat(0xD477AC, 0.0); //Fix ItemStack in Itemtoolip/Shop   
	MemorySet(0x005AD691, 0x90, 0x05); //fix move skill LAG


	//glow gmsign
	//SetCompleteHook(0xE9, 0x005E496C, 0x005E4A3F); // glow gmsign
	//-------------------------------------------------------------------

	SetRange(0x008429CB, 0x59, 0x90); //Xóa tên quái vật ở giữa màn hình chính.

	FixEffectCitys(); // fix tuyet roi


	InitGuildIcon();

	//SetByte((PVOID)(0x81C03FA), 0x01);	//Muốn Show tên NV logo guil không cần trỏ chuột thêm


	MemoryCpy(0x00E611B2,gProtect.m_MainInfo.IpAddress,sizeof(gProtect.m_MainInfo.IpAddress)); //-- IpAddress

	MemoryCpy(0x00E61F70,gProtect.m_MainInfo.ClientSerial,sizeof(gProtect.m_MainInfo.ClientSerial)); //-- ClientSerial

	SetCompleteHook(0xFF,0x0065FD79,&ProtocolCoreEx);
	
	SetCompleteHook(0xE9,0x004DA280,&CheckTickCount1);
	
	SetCompleteHook(0xE9,0x004DA3A1,&CheckTickCount2);
	
	SetCompleteHook(0xE8,0x005B96E8,&DrawNewHealthBar);

	VirtualizeOffset(0x004D9D39,12);

	VirtualizeOffset(0x004D9D45,7);

	VirtualizeOffset(0x004D9EFC,15);

	VirtualizeOffset(0x004DAC5C,8);

	VirtualizeOffset(0x005451F7,5);

	VirtualizeOffset(0x00545230,8);

	VirtualizeOffset(0x005A52E9,8);

	LoadReferenceAddressTable((HMODULE)hins, MAKEINTRESOURCE(IDR_BIN1),(DWORD)&NewAddressData1);

	LoadReferenceAddressTable((HMODULE)hins, MAKEINTRESOURCE(IDR_BIN2),(DWORD)&NewAddressData2);

	LoadReferenceAddressTable((HMODULE)hins, MAKEINTRESOURCE(IDR_BIN3),(DWORD)&NewAddressData3);



	gCustomMessage.LoadEng(gProtect.m_MainInfo.EngCustomMessageInfo);

	gCustomMessage.LoadPor(gProtect.m_MainInfo.PorCustomMessageInfo);

	gCustomMessage.LoadSpn(gProtect.m_MainInfo.SpnCustomMessageInfo);

	gCustomJewel.Load(gProtect.m_MainInfo.CustomJewelInfo);

	gCustomWing.Load(gProtect.m_MainInfo.CustomWingInfo);

	gCustomItem.Load(gProtect.m_MainInfo.CustomItemInfo);

	gCustomBuyVip.Load(gProtect.m_MainInfo.CustomBuyVipInfo);

	gCustomCommandInfo.Load(gProtect.m_MainInfo.CustomCommandInfo);

	gCustomEventTime.Load(gProtect.m_MainInfo.CustomEventInfo);

	gFog.Load(gProtect.m_MainInfo.CustomFog);

	gSmokeEffect.Load(gProtect.m_MainInfo.CustomSmokeEffect);

	gCustomMonster.Load(gProtect.m_MainInfo.CustomMonsters);

	gCustomMonster.LoadBossClass(gProtect.m_MainInfo.CustomBossClass); //Boss Class

	gNPCName.Load(gProtect.m_MainInfo.CustomNPCName);
	//--
	gCustomBattleGloves.Load(gProtect.m_MainInfo.CustomGloves);

	gCustomBow.Load(gProtect.m_MainInfo.CustomBowInfo);

	gCustomPet2.Load(gProtect.m_MainInfo.CustomPetInfo);

	gCloak.Load(gProtect.m_MainInfo.m_CustomCloak);

	ItemTRSData.Load(gProtect.m_MainInfo.CustomPosition);

	gCustomRemake.Load(gProtect.m_MainInfo.CustomRemake);

	gItemManager.Load(gProtect.m_MainInfo.m_ItemInfoEx);

	gCustomModelEffect.Load(gProtect.m_MainInfo.m_CustomModelInfo);
	//--
	gCustomCEffectPet.Load(gProtect.m_ReadBMD.m_PetCEffectBMD);

	gCustomWingEffect.Load(gProtect.m_ReadBMD.CustomWingEffectInfo);

	gDynamicWingEffect.Load(gProtect.m_ReadBMD.DynamicWingEffectInfo);

	cRender.Load(gProtect.m_ReadBMD.RenderMeshPet);

	gCustomMonsterGlow.LoadGlow(gProtect.m_ReadBMD.m_CustomMonsterGlow);

	gCustomMonsterGlow.LoadBrightness(gProtect.m_ReadBMD.m_CustomMonsterbrightness);

	JCEffectMonster.Load( gProtect.m_ReadBMD.m_CustomMonsterEffect );


	JCRemoveGlow.Load( gProtect.m_ReadBMD.m_JCWRemoveGlow );

#if UPDATE > 15
	JCRender.Load( gProtect.m_ReadBMD.m_JCWRenderMesh );
#endif
//--
	gIconBuff.LoadEng(gProtect.m_ReadTooltipTRSData.m_TooltipTRSDataEng);
	
	gIconBuff.LoadSpn(gProtect.m_ReadTooltipTRSData.m_TooltipTRSDataSpn);
	
	gIconBuff.LoadPor(gProtect.m_ReadTooltipTRSData.m_TooltipTRSDataPor);

	GInfo.loadnInformation( gProtect.m_ReadTooltipTRSData.m_TRSTooltipData );

	GInfo.loadnText( gProtect.m_ReadTooltipTRSData.m_TRSTooltipText );
//--
#if UPDATE >= 15
	gSelectCharRamdon.LoadMultiChar(gProtect.m_MakeViewTRSData.m_RenderSelect);
#endif
//--
	gPacketManager.LoadEncryptionKey("Data\\Enc1.dat");

	gPacketManager.LoadDecryptionKey("Data\\Dec2.dat");

	gProtect.CheckLauncher();

	gProtect.CheckInstance();

	gProtect.CheckClientFile();

	gProtect.CheckHackFile();

	gProtect.CheckPluginFile1();

	gProtect.CheckPluginFile2();

	gProtect.CheckPluginFile3();

	gProtect.CheckPluginFile4();

	gProtect.CheckPluginFile5();

	gProtect.CheckCameraFile();

	gProtect.CheckMaxGameInstances();

	InitHackCheck();

	gTrayMode.Load();

	InitCommon();

	g_MSGServerInfo.Load();

	gSlide.Load();

	gRenderNotice.Load();

	//gCChatTextColor.Load();


	JCRemoveGlow.Init();


#if UPDATE > 15
	JCRender.Init();
#endif
	gConfig.Load();

	gCentral.InitCentral();//-- Control: camara||mouse

	QTPary.Load();

	gItemInfoEx.Load();

	gMuHelper.LoadHelper();

	if(gProtect.m_MainInfo.SelectCharAnimate == 1)
	{
		gSelectChar.Load();
	}

	#if UPDATE >= 15
	gSelectCharRamdon.InitMultiChar();
	#endif

	if(gProtect.m_MainInfo.SelectCharS13 == 1)
	{
		gCSCharacterS13.Load();
	}

	ItemTRSData.Init();

	if(gProtect.m_MainInfo.DisableCustomCloack == 0)
	{
		gCapeAnimation.Load();
	}

	if(gProtect.m_MainInfo.DisableCustomPet == 0)
	{
		gCustomPet.Load();

		gObjCreatePetExHook();

		gCustomCEffectPet.Init();

		initmontura();
	}


	gRenderMap.MiniMapload();

	InitItem();

	InitJewel();

	InitPrintPlayer();

	gCustomNameColor.Load();

#if(RECONNECT == 1)
	InitReconnect();
#endif

	InitResolution();

	gController.Load();

	InitWing();

	gObjUser.Load();

	gInterface.RenderObjectSystem();

	gCMacroUIEx.Load();
	
	g_MSGServerInfo.Load();



	InitFonts();

	//gCustomPhysicsBody.Load(); //danglam

	switch(gProtect.m_MainInfo.CustomInterfaceType)
	{
		case 1:
		case 2:
			InitInter3();
			gCChatClassic.Load();
			break;
		case 3:
			InitSeason15();
		case 4:
			gCRenderEx700.Init();
			gCChatEx.Load();
			break;
	}
	
	if(gProtect.m_MainInfo.DisableAdvance == 0)
	{
		g_StatsAdvance.Load();	//<-- Advanced
	}
	gOffTrade.Init();

	gFog.Init();

	if(gProtect.m_MainInfo.CustomMonsterEnable == 1)
	{
		gCustomMonster.InitMonster();
	}

	InitloadGlow();

	if(gProtect.m_MainInfo.DisableCustomBow == 0)
	{
		gCustomBow.Init();
	}

	if(gProtect.m_MainInfo.DisableCustomClaws == 0)
	{
		gCustomBattleGloves.Init();
	}

	gCustomMap.Load();

	if(gProtect.m_MainInfo.EnableShopValueSystem == 1)
	{
		gItemPrice.Init();
	}

	if(gProtect.m_MainInfo.CsSkill == 1)
	{
		//Liberar CS Skills
		SetByte((0x005B89C3+3), 0x00);
		SetByte((0x005B89C9+3), 0x00);
		SetByte((0x005B89CF+3), 0x00);
		SetByte((0x005B89D5+3), 0x00);
		SetByte((0x005B89DB+3), 0x00);
		SetByte((0x005B89E1+3), 0x00);
		SetWord((0x005B89E7+3), 0x00);
		SetByte((0x005C6314+2), 0x00);
		SetByte((0x005C6327+2), 0x00);
		SetByte((0x005C633A+2), 0x00);
		SetByte((0x005C634D+2), 0x00);
		SetByte((0x005C6360+2), 0x00);
		SetByte((0x005C6373+2), 0x00);
		SetWord((0x005C6386+2), 0x00);
	}

	if(gProtect.m_MainInfo.RemoveClass == 3)
	{
		SetByte(0x004030D1+3,6);
	}

	if(gProtect.m_MainInfo.RemoveClass == 2)
	{
		SetByte(0x004030D1+3,5);
	}
	if(gProtect.m_MainInfo.RemoveClass == 1)
	{
		SetByte(0x004030D1+3,4);
	}

	SetWord(0x00405B7C, gProtect.m_MainInfo.ReduceMemory);
	SetWord(0x0040CC40, gProtect.m_MainInfo.ReduceMemory);
	
	if(gProtect.m_MainInfo.DisableTree == 1)
	{
		MemorySet(0x008193F0,0x90,0xC8); //Remove Master Skill Tree Window(A Buttom)
	}

	if(gProtect.m_MainInfo.EffectPlus15 == 0)
	{
		MemorySet(0x006097B0,0x90,0x69D);
	}

	if(gProtect.m_MainInfo.DisableGens == 1)
	{
		MemorySet(0x007C5AD2, 0x90, 0x05);			//-> Disable Gens (Key B)
	}

	if(gProtect.m_MainInfo.DisableTabMap == 1)
	{
		MemorySet(0x0062F876, 0x90, 0x30);			//-> Disable ViewMap (Key TAB)
	}
	//-- disables
	if(gProtect.m_MainInfo.DisableRepeirInInventory == 1)
	{
		SetCompleteHook(0xE9, 0x0083693C, &OffButtonRepeirInInventory);
	}

	if(gProtect.m_MainInfo.DisableButtonOpenStore == 1)
	{
		SetCompleteHook(0xE9, 0x008369AF, &OffButtonOpenStore);
	}

	if(gProtect.m_MainInfo.DisableButtonInventoryExt == 1)
	{
		SetCompleteHook(0xE9, 0x00836A23, &OffButtonInventoryExt);
	}

	if(gProtect.m_MainInfo.DisableButtonQuestInStats == 1)
	{
		SetCompleteHook(0xE9, 0x0077EBB0, &OffButtonQuestInStats);
	}

	if(gProtect.m_MainInfo.DisableButtonPetsInStats == 1)
	{
		SetCompleteHook(0xE9, 0x0077EC59, &OffButtonPetsInStats);
	}

	if(gProtect.m_MainInfo.DisableButtonSkillMaster == 1)
	{
		SetCompleteHook(0xE9, 0x0077ECE2, &OffButtonSkillMasterInStats);
	}

	if(gProtect.m_MainInfo.DisableEffectRemake == 0)
	{
		gCreateEffect.Load();
	}

	if(gProtect.m_MainInfo.CustomInterfaceType == 1)
	{
		SetByte(0x005528A0, 0xC3); // [Fix] Remover Recuo PVP
		MemorySet(0x008684F0, 0x90, 0x52);			//-> Disable FastMenu (Key U)
	}

	if(gProtect.m_MainInfo.DisableHelper == 1)
	{
		MemorySet(0x0085B6AC, 0x90, 0x05);			//-> Remove Helper Top Screen
		MemorySet(0x0085CC50, 0x90, 0x05);			//-> Disable Helper (Key Z)
		MemorySet(0x007D40A2, 0x90, 0x05);			//-> Disable Helper (Key Home)
	}

	if(gProtect.m_MainInfo.DisableSocketInvetori == 1)
	{
		RemoveSocket();
	}

	if (gProtect.m_MainInfo.AlwaysnameShowType != 0)
	{
		JumPlayer.Load();
	}

	gPostInterface.Load();	//<-- post item

	gCItemSetOption.Load();

	InitAttackSpeed(); //-- Fix Agilidad

	gGraphics.Load();


	SetRange(0x0077EECD, 0x18, 0x90); //-- Press Middle Mouse button to add stats quickly



	#if(SOIITEM)
		g_pQuickCommandWindow.szInit();
	#endif
	


	//Fix to avoid some must-haves being killed or killed at nightfall
	SetCompleteHook(0xE8, 0x0059AFFA, 0x0059B00E);
	SetCompleteHook(0xE9, 0x0059AFFA, 0x0059B00E);

	SetCompleteHook(0xE9, 0x007D399F, 0x007D39D8); // Tắt Quest (T)
	SetCompleteHook(0xE9, 0x0077EB65, 0x0077EC0E); // Tắt Quest ở trạng thái ký tự

	//-> Disable Button Friend
	SetByte((PVOID)(0x007D37A1 + 1), 0xFF);			//disable (F) Key
	
	//-> Disable FastMenu (Key U)
	MemorySet(0x008684F0, 0x90, 0x52);				//-> Disable FastMenu (Key U)
	
	//Minimap hover
	SetByte(0x0082BAB5 + 1, 0); // Âêëþ÷åíèå îòîáðàæåíèÿ âñåõ íïö íà ìèíèêàðòå
	SetRange(0x0082BAB7, 0x2, ASM::NOP);
	SetRange(0x0082B7FA, 0xA0, ASM::NOP);
	
	gMessageBoxPopUp.InitPopUp();
	g_pRenderText2.Init();
	AutoLogin.Load();
	gNPC.Load(); //NPC CUSTOM 


#if(SLOTPET)
	g_pMyInventory.Init();
	g_pWSclient.Init();
#endif


#if(ANTI_CRACK_MAIN == 1)

	MainProtection();
#endif

#if(ANTIHACK_NEW)
	//gBAntihack.LoadBB();
#endif


if (gProtect.m_MainInfo.EnableDKTK != 0)
{
g_pLoginMainWin.Init();
}

if (gProtect.m_MainInfo.CustomSelectServerX700 == 1){
	CScene();
}


}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) // OK
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		hins = (HINSTANCE)hModule;
		gController.Instance = hModule;

		//Fixx Diss Main
		if (*(int*)0x0E609E8 == 5 && (char*)*(DWORD*)(0x8128AC4) == NULL)
			ExitProcess(0);

		break;
	case DLL_PROCESS_DETACH:
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	}

	return 1;
}