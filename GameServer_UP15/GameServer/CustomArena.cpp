// CustomArena.cpp: implementation of the CCustomArena class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CustomArena.h"
#include "DSProtocol.h"
#include "EffectManager.h"
#include "Gate.h"
#include "Guild.h"
#include "Map.h"
#include "MapServerManager.h"
#include "MemScript.h"
#include "Message.h"
#include "Notice.h"
#include "ScheduleManager.h"
#include "Util.h"
#include "ItemBagManager.h"

CCustomArena gCustomArena;

CCustomArena::CCustomArena()
{
	//IndexEventHienTai = -1;
	for (int n = 0; n < MAX_CUSTOM_ARENA; n++)
	{

		CUSTOM_ARENA_INFO* lpInfo = &this->m_CustomArenaInfo[n];
		lpInfo->Index = n;
		lpInfo->State = CUSTOM_ARENA_STATE_BLANK;
		lpInfo->RemainTime = 0;
		lpInfo->TargetTime = 0;
		lpInfo->TickCount = GetTickCount();
		lpInfo->EnterEnabled = 0;
		lpInfo->AlarmMinSave = -1;
		lpInfo->AlarmMinLeft = -1;
		this->CleanUser(lpInfo);
	}
	//this->m_CustomArenaSwitch = 0;
	//SoLuotChet = 0;
}

CCustomArena::~CCustomArena(){

}

void CCustomArena::Init()
{
	for (int n = 0; n < MAX_CUSTOM_ARENA; n++)
	{
		if (this->m_CustomArenaSwitch == 0) //Bat/Tat Event
		{
			this->SetState(&this->m_CustomArenaInfo[n], CUSTOM_ARENA_STATE_BLANK);
		}
		else{
			this->SetState(&this->m_CustomArenaInfo[n], CUSTOM_ARENA_STATE_EMPTY);
		}
	}
}

void CCustomArena::ReadCustomArenaInfo(char* section, char* path){
	//this->m_CustomArenaSwitch = GetPrivateProfileInt(section,"CustomArenaSwitch",0,path);
	//this->m_CustomArenaVictimScoreDecrease = GetPrivateProfileInt(section,"CustomArenaVictimScoreDecrease",0,path);
	//this->m_CustomArenaKillerScoreIncrease = GetPrivateProfileInt(section,"CustomArenaKillerScoreIncrease",0,path);
	//GetPrivateProfileString(section,"CustomArenaText1","",this->m_CustomArenaText1,sizeof(this->m_CustomArenaText1),path);
	//GetPrivateProfileString(section,"CustomArenaText2","",this->m_CustomArenaText2,sizeof(this->m_CustomArenaText2),path);
	//GetPrivateProfileString(section,"CustomArenaText3","",this->m_CustomArenaText3,sizeof(this->m_CustomArenaText3),path);
	//GetPrivateProfileString(section,"CustomArenaText4","",this->m_CustomArenaText4,sizeof(this->m_CustomArenaText4),path);
	//GetPrivateProfileString(section,"CustomArenaText5","",this->m_CustomArenaText5,sizeof(this->m_CustomArenaText5),path);
	//GetPrivateProfileString(section,"CustomArenaText6","",this->m_CustomArenaText6,sizeof(this->m_CustomArenaText6),path);
	//GetPrivateProfileString(section,"CustomArenaText7","",this->m_CustomArenaText7,sizeof(this->m_CustomArenaText7),path);
	//GetPrivateProfileString(section,"CustomArenaText8","",this->m_CustomArenaText8,sizeof(this->m_CustomArenaText8),path);
	//GetPrivateProfileString(section,"CustomArenaText9","",this->m_CustomArenaText9,sizeof(this->m_CustomArenaText9),path);
	//GetPrivateProfileString(section,"CustomArenaText10","",this->m_CustomArenaText10,sizeof(this->m_CustomArenaText10),path);
	//GetPrivateProfileString(section,"CustomArenaText11","",this->m_CustomArenaText11,sizeof(this->m_CustomArenaText11),path);
	//GetPrivateProfileString(section,"CustomArenaText12","",this->m_CustomArenaText12,sizeof(this->m_CustomArenaText12),path);
	//GetPrivateProfileString(section,"CustomArenaText13","",this->m_CustomArenaText13,sizeof(this->m_CustomArenaText13),path);
	//GetPrivateProfileString(section,"CustomArenaText14","",this->m_CustomArenaText14,sizeof(this->m_CustomArenaText14),path);
	//GetPrivateProfileString(section,"CustomArenaText15","",this->m_CustomArenaText15,sizeof(this->m_CustomArenaText15),path);
	//GetPrivateProfileString(section,"CustomArenaText16","",this->m_CustomArenaText16,sizeof(this->m_CustomArenaText16),path);
	//GetPrivateProfileString(section,"CustomArenaText17","",this->m_CustomArenaText17,sizeof(this->m_CustomArenaText17),path);
	//GetPrivateProfileString(section,"CustomArenaText18","",this->m_CustomArenaText18,sizeof(this->m_CustomArenaText18),path);
	//GetPrivateProfileString(section,"CustomArenaText19","",this->m_CustomArenaText19,sizeof(this->m_CustomArenaText19),path);
}

void CCustomArena::Load(char* path)
{
	//CCustomArena();

	pugi::xml_document file;
	pugi::xml_parse_result res = file.load_file(path);
	if (res.status != pugi::status_ok){
		ErrorMessageBox("File %s load fail. Error: %s", path, res.description());
		return;
	}
	this->m_CustomArenaSwitch = 0;
	this->IndexEventHienTai = -1;
	this->SoLuotChet = 0;
	for (int n = 0; n < MAX_CUSTOM_ARENA; n++)
	{
		this->MapEvent[n] = -1;
		this->m_CustomArenaInfo[n].StartTime.clear();
	}
	pugi::xml_node Principal = file.child("EventDauTruong");

	this->m_CustomArenaSwitch = Principal.attribute("Enable").as_int(); //Bat Tat
	this->m_CustomArenaVictimScoreDecrease = Principal.attribute("ScoreDie").as_int(10); //Diem Tru Khi Chet
	this->m_CustomArenaKillerScoreIncrease = Principal.attribute("ScoreKill").as_int(100); //Diem Cong Khi Giet

	pugi::xml_node ArenaTime = Principal.child("CreateTime");
	for (pugi::xml_node time = ArenaTime.child("Load"); time; time = time.next_sibling()){
		CUSTOM_ARENA_START_TIME info;
		int index = time.attribute("Index").as_int();
		info.Year = time.attribute("Year").as_int();
		info.Month = time.attribute("Month").as_int();
		info.Day = time.attribute("Day").as_int();
		info.DayOfWeek = time.attribute("DayOfWeek").as_int();
		info.Hour = time.attribute("Hour").as_int();
		info.Minute = time.attribute("Minute").as_int();
		info.Second = time.attribute("Second").as_int();
		this->m_CustomArenaInfo[index].StartTime.push_back(info);
	}
	//= Mess Load
	this->m_MessageInfoBP.clear();
	pugi::xml_node Message = Principal.child("Message");
	for (pugi::xml_node msg = Message.child("Msg"); msg; msg = msg.next_sibling())
	{
		MESSAGE_INFO_DAUTRUONG info;

		info.Index = msg.attribute("Index").as_int();

		strcpy_s(info.Message, msg.attribute("Text").as_string());

		this->m_MessageInfoBP.insert(std::pair<int, MESSAGE_INFO_DAUTRUONG>(info.Index, info));
	}


	for (pugi::xml_node load = Principal.child("TypeDauTruong"); load; load = load.next_sibling()){
		int index = load.attribute("Index").as_int();
		strcpy_s(this->m_CustomArenaInfo[index].RuleInfo.Name, load.attribute("Name").as_string());
		this->m_CustomArenaInfo[index].RuleInfo.AlarmTime = load.attribute("AlarmTime").as_int();
		this->m_CustomArenaInfo[index].RuleInfo.StandTime = load.attribute("StandTime").as_int();
		this->m_CustomArenaInfo[index].RuleInfo.EventTime = load.attribute("EventTime").as_int();
		this->m_CustomArenaInfo[index].RuleInfo.WaitTime = load.attribute("WaitTime").as_int();
		this->m_CustomArenaInfo[index].RuleInfo.PKTime = load.attribute("PKTime").as_int();
		this->m_CustomArenaInfo[index].RuleInfo.CloseTime = load.attribute("CloseTime").as_int();
		//==Conifig Item Check
		pugi::xml_node ConfigItemCheck = load.child("ConfigItemCheck");
		this->m_CustomArenaInfo[index].RuleInfo.EventItemID = ConfigItemCheck.attribute("EventItemID").as_int();
		this->m_CustomArenaInfo[index].RuleInfo.EventItemCount = ConfigItemCheck.attribute("EventItemCount").as_int();
		this->m_CustomArenaInfo[index].RuleInfo.mWC = ConfigItemCheck.attribute("WC").as_int();
		this->m_CustomArenaInfo[index].RuleInfo.mWP = ConfigItemCheck.attribute("WP").as_int();
		this->m_CustomArenaInfo[index].RuleInfo.mGP = ConfigItemCheck.attribute("GP").as_int();

		//==Conifig Class
		pugi::xml_node ConfigClass = load.child("ConfigClass");
		this->m_CustomArenaInfo[index].RuleInfo.RequireClass[0] = ConfigClass.attribute("DW").as_int();
		this->m_CustomArenaInfo[index].RuleInfo.RequireClass[1] = ConfigClass.attribute("DK").as_int();
		this->m_CustomArenaInfo[index].RuleInfo.RequireClass[2] = ConfigClass.attribute("FE").as_int();
		this->m_CustomArenaInfo[index].RuleInfo.RequireClass[3] = ConfigClass.attribute("MG").as_int();
		this->m_CustomArenaInfo[index].RuleInfo.RequireClass[4] = ConfigClass.attribute("DL").as_int();
		this->m_CustomArenaInfo[index].RuleInfo.RequireClass[5] = ConfigClass.attribute("SU").as_int();
		this->m_CustomArenaInfo[index].RuleInfo.RequireClass[6] = ConfigClass.attribute("RF").as_int();
		//==Conifig Gate
		pugi::xml_node ConfigGate = load.child("ConfigGate");
		this->m_CustomArenaInfo[index].RuleInfo.StartGate = ConfigGate.attribute("GateCho").as_int();
		this->m_CustomArenaInfo[index].RuleInfo.GateCong1 = ConfigGate.attribute("GateCong1").as_int();
		this->m_CustomArenaInfo[index].RuleInfo.GateCong2 = ConfigGate.attribute("GateCong2").as_int();
		this->m_CustomArenaInfo[index].RuleInfo.FinalGate = ConfigGate.attribute("GateFinal").as_int();

		//==Conifig Check
		pugi::xml_node ConfigCheck = load.child("ConfigCheck");
		this->m_CustomArenaInfo[index].RuleInfo.MinUser = ConfigCheck.attribute("MinUser").as_int();
		this->m_CustomArenaInfo[index].RuleInfo.MaxUser = ConfigCheck.attribute("MaxUser").as_int();
		this->m_CustomArenaInfo[index].RuleInfo.MaxDeath = ConfigCheck.attribute("MaxDeath").as_int();
		this->m_CustomArenaInfo[index].RuleInfo.MinLevel = ConfigCheck.attribute("MinLevel").as_int();
		this->m_CustomArenaInfo[index].RuleInfo.MaxLevel = ConfigCheck.attribute("MaxLevel").as_int();
		this->m_CustomArenaInfo[index].RuleInfo.MinMasterLevel = ConfigCheck.attribute("MinMLevel").as_int();
		this->m_CustomArenaInfo[index].RuleInfo.MaxMasterLevel = ConfigCheck.attribute("MaxMLevel").as_int();
		this->m_CustomArenaInfo[index].RuleInfo.MinReset = ConfigCheck.attribute("MinReset").as_int();
		this->m_CustomArenaInfo[index].RuleInfo.MaxReset = ConfigCheck.attribute("MaxReset").as_int();
		this->m_CustomArenaInfo[index].RuleInfo.MinMasterReset = ConfigCheck.attribute("MinMReset").as_int();
		this->m_CustomArenaInfo[index].RuleInfo.MaxMasterReset = ConfigCheck.attribute("MaxMReset").as_int();
		//==Conifig Phan Thuong Top 1
		pugi::xml_node ConfigRewardTop1 = load.child("ConfigRewardTop1");
		this->m_CustomArenaInfo[index].RuleInfo.EventItemBag[0] = ConfigRewardTop1.attribute("EventItemBag").as_int();
		this->m_CustomArenaInfo[index].RuleInfo.WC[0] = ConfigRewardTop1.attribute("WC").as_int();
		this->m_CustomArenaInfo[index].RuleInfo.WP[0] = ConfigRewardTop1.attribute("WP").as_int();
		this->m_CustomArenaInfo[index].RuleInfo.GP[0] = ConfigRewardTop1.attribute("GP").as_int();
		pugi::xml_node ConfigRewardTop2 = load.child("ConfigRewardTop2");
		this->m_CustomArenaInfo[index].RuleInfo.EventItemBag[1] = ConfigRewardTop2.attribute("EventItemBag").as_int();
		this->m_CustomArenaInfo[index].RuleInfo.WC[1] = ConfigRewardTop2.attribute("WC").as_int();
		this->m_CustomArenaInfo[index].RuleInfo.WP[1] = ConfigRewardTop2.attribute("WP").as_int();
		this->m_CustomArenaInfo[index].RuleInfo.GP[1] = ConfigRewardTop2.attribute("GP").as_int();
		pugi::xml_node ConfigRewardTop3 = load.child("ConfigRewardTop3");
		this->m_CustomArenaInfo[index].RuleInfo.EventItemBag[2] = ConfigRewardTop3.attribute("EventItemBag").as_int();
		this->m_CustomArenaInfo[index].RuleInfo.WC[2] = ConfigRewardTop3.attribute("WC").as_int();
		this->m_CustomArenaInfo[index].RuleInfo.WP[2] = ConfigRewardTop3.attribute("WP").as_int();
		this->m_CustomArenaInfo[index].RuleInfo.GP[2] = ConfigRewardTop3.attribute("GP").as_int();
		pugi::xml_node ConfigRewardTop4 = load.child("ConfigRewardTop4");
		this->m_CustomArenaInfo[index].RuleInfo.EventItemBag[3] = ConfigRewardTop4.attribute("EventItemBag").as_int();
		this->m_CustomArenaInfo[index].RuleInfo.WC[3] = ConfigRewardTop4.attribute("WC").as_int();
		this->m_CustomArenaInfo[index].RuleInfo.WP[3] = ConfigRewardTop4.attribute("WP").as_int();
		this->m_CustomArenaInfo[index].RuleInfo.GP[3] = ConfigRewardTop4.attribute("GP").as_int();
		this->MapEvent[index] = gGate.GetGateMap(this->m_CustomArenaInfo[index].RuleInfo.StartGate);
	}

	LogAdd(LOG_BLUE, "[DauTruongPK] Load OK %d", this->m_CustomArenaSwitch);
}
char* CCustomArena::GetMessage(int index) // OK
{
	std::map<int, MESSAGE_INFO_DAUTRUONG>::iterator it = this->m_MessageInfoBP.find(index);

	if (it == this->m_MessageInfoBP.end())
	{
		char Error[256];
		wsprintf(Error, "Could not find message %d!", index);
		return Error;
	}
	else
	{
		return it->second.Message;
	}
}

void CCustomArena::MainProc(){
	for (int n = 0; n < MAX_CUSTOM_ARENA; n++)
	{
		CUSTOM_ARENA_INFO* lpInfo = &this->m_CustomArenaInfo[n];
		if ((GetTickCount() - lpInfo->TickCount) >= 1000)
		{
			lpInfo->TickCount = GetTickCount();
			lpInfo->RemainTime = (int)difftime(lpInfo->TargetTime, time(0));
			if (lpInfo->State == CUSTOM_ARENA_STATE_BLANK){
				if (gServerDisplayer.EventCustomArena[n] != -1){
					gServerDisplayer.EventCustomArena[n] = -1;
				}
			}
			else {
				if (lpInfo->State == CUSTOM_ARENA_STATE_EMPTY){
					gServerDisplayer.EventCustomArena[n] = lpInfo->RemainTime;
				}
				else{
					if (gServerDisplayer.EventCustomArena[n] != 0){
						gServerDisplayer.EventCustomArena[n] = 0;
					}
				}
			}
			if (gServerDisplayer.EventCustomArena[n] > 0){
				if (lpInfo->State != CUSTOM_ARENA_STATE_EMPTY && lpInfo->State != CUSTOM_ARENA_STATE_BLANK){
					gServerDisplayer.EventCustomArena[n] = 0;
				}
			}
			if (lpInfo->State >= CUSTOM_ARENA_STATE_EMPTY)
			{
				//LogAdd(LOG_RED, "[DauTruong] State %d, User %d, Remain %d (%d) %d", lpInfo->State, this->GetUserCount(lpInfo), lpInfo->RemainTime, this->IndexEventHienTai, this->SoLuotChet);
				this->SendUserInfoEvent(lpInfo);
			}

			switch (lpInfo->State)
			{
			case CUSTOM_ARENA_STATE_BLANK:
				this->ProcState_BLANK(lpInfo);
				break;
			case CUSTOM_ARENA_STATE_EMPTY:
				this->ProcState_EMPTY(lpInfo);
				break;
			case CUSTOM_ARENA_STATE_STAND:
				this->ProcState_STAND(lpInfo);
				break;
			case CUSTOM_ARENA_STATE_START:
				this->ProcState_START(lpInfo);
				break;
			case CUSTOM_ARENA_STATE_CHOBANKET:
				this->ProcState_CHOBANKET(lpInfo);
				break;
			case CUSTOM_ARENA_STATE_BANKET:
				this->ProcState_BANKET(lpInfo);
				break;
			case CUSTOM_ARENA_STATE_CHOCHUNGKET:
				this->ProcState_CHOCHUNGKET(lpInfo);
				break;
			case CUSTOM_ARENA_STATE_CHUNGKET:
				this->ProcState_CHUNGKET(lpInfo);
				break;
			case CUSTOM_ARENA_STATE_CLEAN:
				this->ProcState_CLEAN(lpInfo);
				break;
			}
		}
	}
}

void CCustomArena::ProcState_BLANK(CUSTOM_ARENA_INFO* lpInfo){

}

void CCustomArena::ProcState_EMPTY(CUSTOM_ARENA_INFO* lpInfo){
	if (lpInfo->RemainTime > 0 && lpInfo->RemainTime <= (lpInfo->RuleInfo.AlarmTime * 60))
	{
		this->MapEvent[lpInfo->Index] = gGate.GetGateMap(lpInfo->RuleInfo.StartGate);
		this->IndexEventHienTai = lpInfo->Index;
		lpInfo->EnterEnabled = 1;
		this->CheckUser(lpInfo);
		if ((lpInfo->AlarmMinSave = (((lpInfo->RemainTime % 60) == 0) ? ((lpInfo->RemainTime / 60) - 1) : (lpInfo->RemainTime / 60))) != lpInfo->AlarmMinLeft){
			lpInfo->AlarmMinLeft = lpInfo->AlarmMinSave;
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, this->GetMessage(0), lpInfo->RuleInfo.Name, (lpInfo->AlarmMinLeft + 1));
		}
	}
	if (lpInfo->RemainTime <= 0)
	{

		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, this->GetMessage(1), lpInfo->RuleInfo.Name);
		this->NoticeSendToAll(lpInfo, 1, this->GetMessage(2), lpInfo->RuleInfo.Name, lpInfo->RuleInfo.StandTime);
		this->SetState(lpInfo, CUSTOM_ARENA_STATE_STAND);
	}
}

void CCustomArena::ProcState_STAND(CUSTOM_ARENA_INFO* lpInfo)
{

	this->CheckUser(lpInfo);
	if (this->GetUserCount(lpInfo) < ((lpInfo->RuleInfo.MinUser == -1) ? 1 : lpInfo->RuleInfo.MinUser))
	{
		this->NoticeSendToAll(lpInfo, 1, this->GetMessage(26), lpInfo->RuleInfo.Name); //Thong Bao Huy Do Khong Du Nguoi
		this->SetState(lpInfo, CUSTOM_ARENA_STATE_EMPTY);
		return;
	}
	if (lpInfo->RemainTime <= 0){
		this->NoticeSendToAll(lpInfo, 0, this->GetMessage(3), lpInfo->RuleInfo.Name);
		this->SetState(lpInfo, CUSTOM_ARENA_STATE_START);
	}
}
//==Vong Loai
void CCustomArena::ProcState_START(CUSTOM_ARENA_INFO* lpInfo)
{
	this->CheckUser(lpInfo);
	if (this->GetUserCount(lpInfo) == 0)
	{
		this->SetState(lpInfo, CUSTOM_ARENA_STATE_EMPTY);
		return;
	}

	if (this->GetUserCount(lpInfo) == 1){
		this->SetState(lpInfo, CUSTOM_ARENA_STATE_CLEAN);
		return;
	}
	if (lpInfo->RemainTime <= 0)
	{

		this->CalcUserRank(lpInfo);
		this->NoticeSendToAll(lpInfo, 0, this->GetMessage(19), (int)(lpInfo->RuleInfo.WaitTime == 0 ? 10 : lpInfo->RuleInfo.WaitTime * 60)); //Ket thuc vong loai sang vong
		this->SetState(lpInfo, CUSTOM_ARENA_STATE_CHOBANKET); //Set trang thai cho`

	}
}
//==Cho Ban Ket
void CCustomArena::ProcState_CHOBANKET(CUSTOM_ARENA_INFO* lpInfo)
{
	this->CheckUser(lpInfo);
	if (this->GetUserCount(lpInfo) == 0) {
		this->SetState(lpInfo, CUSTOM_ARENA_STATE_EMPTY);
		return;
	}
	if (this->GetUserCount(lpInfo) < 4) //It hon 4 thi ve chung ket
	{
		this->CalcUserRank(lpInfo);
		this->NoticeSendToAll(lpInfo, 0, this->GetMessage(21), (int)(lpInfo->RuleInfo.WaitTime == 0 ? 10 : lpInfo->RuleInfo.WaitTime * 60)); //Ket thuc vong loai sang vong
		this->SetState(lpInfo, CUSTOM_ARENA_STATE_CHOCHUNGKET); //Set trang thai cho`
		return;
	}
	if (this->GetUserCount(lpInfo) == 1) {
		this->SetState(lpInfo, CUSTOM_ARENA_STATE_CLEAN);
		return;
	}
	if (lpInfo->RemainTime <= 0)
	{
		SoLuotChet = 0;
		this->NoticeSendToAll(lpInfo, 0, this->GetMessage(20)); //Ket thuc vong loai sang vong
		this->SetState(lpInfo, CUSTOM_ARENA_STATE_BANKET); //Set trang thai cho`
	}
}
//==Ban Ket
void CCustomArena::ProcState_BANKET(CUSTOM_ARENA_INFO* lpInfo)
{
	this->CheckUser(lpInfo);
	if (this->GetUserCount(lpInfo) == 0) {
		this->SetState(lpInfo, CUSTOM_ARENA_STATE_EMPTY);
		return;
	}
	if (this->GetUserCount(lpInfo) < 4) //It hon 4 thi ve chung ket
	{
		this->CalcUserRank(lpInfo);
		this->NoticeSendToAll(lpInfo, 0, this->GetMessage(21)); //Ket thuc vong loai sang vong
		this->SetState(lpInfo, CUSTOM_ARENA_STATE_CHOCHUNGKET); //Set trang thai cho`
		return;
	}
	if (this->GetUserCount(lpInfo) == 1)
	{
		this->SetState(lpInfo, CUSTOM_ARENA_STATE_CLEAN);
		return;
	}
	if (lpInfo->RemainTime <= 0)
	{
		this->NoticeSendToAll(lpInfo, 0, this->GetMessage(21)); //Ket thuc vong loai sang vong
		this->SetState(lpInfo, CUSTOM_ARENA_STATE_CHOCHUNGKET); //Set trang thai cho`
	}
}
//==Cho Chung Ket
void CCustomArena::ProcState_CHOCHUNGKET(CUSTOM_ARENA_INFO* lpInfo)
{
	this->CheckUser(lpInfo);
	if (this->GetUserCount(lpInfo) == 0) {
		this->SetState(lpInfo, CUSTOM_ARENA_STATE_EMPTY);
		return;
	}
	if (this->GetUserCount(lpInfo) == 1)
	{
		this->SetState(lpInfo, CUSTOM_ARENA_STATE_CLEAN);
		return;
	}
	if (lpInfo->RemainTime <= 0)
	{
		SoLuotChet = 0;
		this->NoticeSendToAll(lpInfo, 0, this->GetMessage(22)); //Ket thuc vong loai sang vong
		this->SetState(lpInfo, CUSTOM_ARENA_STATE_CHUNGKET); //Set trang thai cho`
	}
}
//== Chung Ket --> ENd
void CCustomArena::ProcState_CHUNGKET(CUSTOM_ARENA_INFO* lpInfo)
{
	this->CheckUser(lpInfo);
	if (this->GetUserCount(lpInfo) == 0) {
		this->SetState(lpInfo, CUSTOM_ARENA_STATE_EMPTY);
		return;
	}
	if (this->GetUserCount(lpInfo) == 1)
	{
		this->SetState(lpInfo, CUSTOM_ARENA_STATE_CLEAN);
		return;
	}
	if (lpInfo->RemainTime <= 0)
	{
		this->NoticeSendToAll(lpInfo, 0, this->GetMessage(23)); //Ket thuc trao thuong
		this->SetState(lpInfo, CUSTOM_ARENA_STATE_CLEAN); //Set trang thai cho`
	}
}
void CCustomArena::ProcState_CLEAN(CUSTOM_ARENA_INFO* lpInfo){
	this->CheckUser(lpInfo);
	if (lpInfo->RemainTime <= 0)
	{
		this->SetState(lpInfo, CUSTOM_ARENA_STATE_EMPTY);
	}
}

void CCustomArena::SetState(CUSTOM_ARENA_INFO* lpInfo, int state){
	switch ((lpInfo->State = state)){
	case CUSTOM_ARENA_STATE_BLANK:
		this->SetState_BLANK(lpInfo);
		break;
	case CUSTOM_ARENA_STATE_EMPTY:
		this->SetState_EMPTY(lpInfo);
		break;
	case CUSTOM_ARENA_STATE_STAND:
		this->SetState_STAND(lpInfo);
		break;
	case CUSTOM_ARENA_STATE_START:
		this->SetState_START(lpInfo);
		break;
	case CUSTOM_ARENA_STATE_CHOBANKET:
		this->SetState_CHOBANKET(lpInfo);
		break;
	case CUSTOM_ARENA_STATE_BANKET:
		this->SetState_BANKET(lpInfo);
		break;
	case CUSTOM_ARENA_STATE_CHOCHUNGKET:
		this->SetState_CHOCHUNGKET(lpInfo);
		break;
	case CUSTOM_ARENA_STATE_CHUNGKET:
		this->SetState_CHUNGKET(lpInfo);
		break;
	case CUSTOM_ARENA_STATE_CLEAN:
		this->SetState_CLEAN(lpInfo);
		break;
	}
}

void CCustomArena::SetState_BLANK(CUSTOM_ARENA_INFO* lpInfo){

}

void CCustomArena::SetState_EMPTY(CUSTOM_ARENA_INFO* lpInfo){
	lpInfo->EnterEnabled = 0;
	lpInfo->AlarmMinSave = -1;
	lpInfo->AlarmMinLeft = -1;
	this->ClearUser(lpInfo);
	this->CheckSync(lpInfo);

}

void CCustomArena::SetState_STAND(CUSTOM_ARENA_INFO* lpInfo)
{
	lpInfo->EnterEnabled = 0;
	lpInfo->AlarmMinSave = -1;
	lpInfo->AlarmMinLeft = -1;
	lpInfo->RemainTime = lpInfo->RuleInfo.StandTime * 60;
	lpInfo->TargetTime = (int)(time(0) + lpInfo->RemainTime);
}
void CCustomArena::SetState_START(CUSTOM_ARENA_INFO* lpInfo) {
	lpInfo->EnterEnabled = 0;
	lpInfo->AlarmMinSave = -1;
	lpInfo->AlarmMinLeft = -1;
	lpInfo->RemainTime = lpInfo->RuleInfo.EventTime * 60;
	lpInfo->TargetTime = (int)(time(0) + lpInfo->RemainTime);
	//==Move ra phong cho
	for (int n = 0; n < MAX_CUSTOM_ARENA_USER; n++)
	{
		if (OBJECT_RANGE(lpInfo->User[n].Index) != 0)
		{
			gObjMoveGate(lpInfo->User[n].Index, lpInfo->RuleInfo.GateCong1);
		}
	}
}
void CCustomArena::SetState_CHOBANKET(CUSTOM_ARENA_INFO* lpInfo){
	lpInfo->EnterEnabled = 0;
	lpInfo->AlarmMinSave = -1;
	lpInfo->AlarmMinLeft = -1;
	lpInfo->RemainTime = (lpInfo->RuleInfo.WaitTime == 0 ? 10 : lpInfo->RuleInfo.WaitTime * 60);
	lpInfo->TargetTime = (int)(time(0) + lpInfo->RemainTime);
	this->CalcUserRank(lpInfo); //Lay Xep Hang chuan bi ban ket
	//==Move ra phong cho
	for (int n = 0; n < MAX_CUSTOM_ARENA_USER; n++)
	{
		if (OBJECT_RANGE(lpInfo->User[n].Index) != 0)
		{
			gObjMoveGate(lpInfo->User[n].Index, lpInfo->RuleInfo.StartGate);
		}
	}
}

void CCustomArena::SetState_BANKET(CUSTOM_ARENA_INFO* lpInfo) {
	lpInfo->EnterEnabled = 0;
	lpInfo->AlarmMinSave = -1;
	lpInfo->AlarmMinLeft = -1;
	lpInfo->RemainTime = (lpInfo->RuleInfo.PKTime == 0 ? 30 : lpInfo->RuleInfo.PKTime) * 60;
	lpInfo->TargetTime = (int)(time(0) + lpInfo->RemainTime);
	//==Move ra phong cho
	for (int n = 0; n < MAX_CUSTOM_ARENA_USER; n++)
	{
		if (OBJECT_RANGE(lpInfo->User[n].Index) != 0)
		{
			if (lpInfo->User[n].Rank > 4)
			{
				continue;
			}
			if (lpInfo->User[n].Rank == 1 || lpInfo->User[n].Rank == 3)
			{
				gObjMoveGate(lpInfo->User[n].Index, lpInfo->RuleInfo.GateCong1);
			}
			if (lpInfo->User[n].Rank == 2 || lpInfo->User[n].Rank == 4)
			{
				gObjMoveGate(lpInfo->User[n].Index, lpInfo->RuleInfo.GateCong2);
			}
		}
	}
}
void CCustomArena::SetState_CHOCHUNGKET(CUSTOM_ARENA_INFO* lpInfo) {
	lpInfo->EnterEnabled = 0;
	lpInfo->AlarmMinSave = -1;
	lpInfo->AlarmMinLeft = -1;
	lpInfo->RemainTime = (lpInfo->RuleInfo.WaitTime == 0 ? 10 : lpInfo->RuleInfo.WaitTime * 60);
	lpInfo->TargetTime = (int)(time(0) + lpInfo->RemainTime);
	//==Move ra phong cho
	for (int n = 0; n < MAX_CUSTOM_ARENA_USER; n++)
	{
		if (OBJECT_RANGE(lpInfo->User[n].Index) != 0)
		{
			gObjMoveGate(lpInfo->User[n].Index, lpInfo->RuleInfo.StartGate);
		}
	}
}
void CCustomArena::SetState_CHUNGKET(CUSTOM_ARENA_INFO* lpInfo) {
	lpInfo->EnterEnabled = 0;
	lpInfo->AlarmMinSave = -1;
	lpInfo->AlarmMinLeft = -1;
	lpInfo->RemainTime = (lpInfo->RuleInfo.PKTime == 0 ? 30 : lpInfo->RuleInfo.PKTime) * 60;
	lpInfo->TargetTime = (int)(time(0) + lpInfo->RemainTime);
	//==Move ra phong cho
	for (int n = 0; n < MAX_CUSTOM_ARENA_USER; n++)
	{
		if (OBJECT_RANGE(lpInfo->User[n].Index) != 0)
		{
			if (lpInfo->User[n].Rank > 2)
			{
				continue;
			}
			if (lpInfo->User[n].Rank == 1 || lpInfo->User[n].Rank == 2)
			{
				gObjMoveGate(lpInfo->User[n].Index, lpInfo->RuleInfo.GateCong1);
			}
		}
	}
}
//==Ket THuc

void CCustomArena::SetState_CLEAN(CUSTOM_ARENA_INFO* lpInfo){
	lpInfo->EnterEnabled = 0;
	lpInfo->AlarmMinSave = -1;
	lpInfo->AlarmMinLeft = -1;
	lpInfo->RemainTime = (lpInfo->RuleInfo.CloseTime > 0) ? lpInfo->RuleInfo.CloseTime * 60 : 10;
	lpInfo->TargetTime = (int)(time(0) + lpInfo->RemainTime);
	this->CalcUserRank(lpInfo);
	//=== Trao Thuong
	for (int n = 0; n < MAX_CUSTOM_ARENA_USER; n++)
	{
		if (OBJECT_RANGE(lpInfo->User[n].Index) != 0)
		{
			int Top = lpInfo->User[n].Rank;

			if (lpInfo->RuleInfo.WC[Top - 1] <= 0 && lpInfo->RuleInfo.WP[Top - 1] <= 0 && lpInfo->RuleInfo.GP[Top - 1] <= 0 && lpInfo->RuleInfo.EventItemBag[Top - 1] <= 0)
			{
				continue;
			}
			LPOBJ lpObj = &gObj[lpInfo->User[n].Index];
			switch (Top)
			{
			case 1: //Trao Thuong Top 1
			{

						//================
						if (lpInfo->RuleInfo.WC[Top - 1] > 0 || lpInfo->RuleInfo.WP[Top - 1] > 0 || lpInfo->RuleInfo.GP[Top - 1] > 0)
						{
							GDSetCoinSend(lpObj->Index, lpInfo->RuleInfo.WC[Top - 1], lpInfo->RuleInfo.WP[Top - 1], lpInfo->RuleInfo.GP[Top - 1], "Top1DauTruong");
						}
						if (lpInfo->RuleInfo.EventItemBag[Top - 1] > 0)
						{
							gItemBagManager.DropItemByIndexItemBag(lpInfo->RuleInfo.EventItemBag[Top - 1], lpObj); //Gui Item cho NV
						}
						//=================
						gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, this->GetMessage(5), lpInfo->RuleInfo.Name, gObj[lpInfo->User[n].Index].Name, lpInfo->User[n].Rank);
			}
				break;
			case 2: //Trao Thuong Top 2
			{
						//================
						if (lpInfo->RuleInfo.WC[Top - 1] > 0 || lpInfo->RuleInfo.WP[Top - 1] > 0 || lpInfo->RuleInfo.GP[Top - 1] > 0)
						{
							GDSetCoinSend(lpObj->Index, lpInfo->RuleInfo.WC[Top - 1], lpInfo->RuleInfo.WP[Top - 1], lpInfo->RuleInfo.GP[Top - 1], "Top2DauTruong");
						}
						if (lpInfo->RuleInfo.EventItemBag[Top - 1] != -1)
						{
							gItemBagManager.DropItemByIndexItemBag(lpInfo->RuleInfo.EventItemBag[Top - 1], lpObj); //Gui Item cho NV
						}
						//=================
						gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, this->GetMessage(5), lpInfo->RuleInfo.Name, gObj[lpInfo->User[n].Index].Name, lpInfo->User[n].Rank);
			}
				break;
			case 3: //Trao Thuong Top 1
			{
						//================
						if (lpInfo->RuleInfo.WC[Top - 1] > 0 || lpInfo->RuleInfo.WP[Top - 1] > 0 || lpInfo->RuleInfo.GP[Top - 1] > 0)
						{
							GDSetCoinSend(lpObj->Index, lpInfo->RuleInfo.WC[Top - 1], lpInfo->RuleInfo.WP[Top - 1], lpInfo->RuleInfo.GP[Top - 1], "Top3DauTruong");
						}
						if (lpInfo->RuleInfo.EventItemBag[Top - 1] != -1)
						{
							gItemBagManager.DropItemByIndexItemBag(lpInfo->RuleInfo.EventItemBag[Top - 1], lpObj); //Gui Item cho NV
						}
						//=================
						gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, this->GetMessage(5), lpInfo->RuleInfo.Name, gObj[lpInfo->User[n].Index].Name, lpInfo->User[n].Rank);
			}
				break;
			case 4: //Trao Thuong Top 1
			{
						//================
						if (lpInfo->RuleInfo.WC[Top - 1] > 0 || lpInfo->RuleInfo.WP[Top - 1] > 0 || lpInfo->RuleInfo.GP[Top - 1] > 0)
						{
							GDSetCoinSend(lpObj->Index, lpInfo->RuleInfo.WC[Top - 1], lpInfo->RuleInfo.WP[Top - 1], lpInfo->RuleInfo.GP[Top - 1], "Top4DauTruong");
						}
						if (lpInfo->RuleInfo.EventItemBag[Top - 1] != -1)
						{
							gItemBagManager.DropItemByIndexItemBag(lpInfo->RuleInfo.EventItemBag[Top - 1], lpObj); //Gui Item cho NV
						}
						//=================
						gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, this->GetMessage(5), lpInfo->RuleInfo.Name, gObj[lpInfo->User[n].Index].Name, lpInfo->User[n].Rank);
			}
				break;
			default:
				break;
			}
			//==Save Ranking SQL
			GDRankingCustomArenaSaveSend(lpInfo->User[n].Index, lpInfo->Index, lpInfo->User[n].Score, lpInfo->User[n].Rank);
			gNotice.GCNoticeSend(lpInfo->User[n].Index, 1, 0, 0, 0, 0, 0, this->GetMessage(6), lpInfo->RuleInfo.Name, lpInfo->User[n].Rank, lpInfo->User[n].Score);

		}
	}

}

void CCustomArena::CheckSync(CUSTOM_ARENA_INFO* lpInfo){
	if (lpInfo->StartTime.empty() != 0){
		this->SetState(lpInfo, CUSTOM_ARENA_STATE_BLANK);
		return;
	}
	CTime ScheduleTime;
	CScheduleManager ScheduleManager;
	for (std::vector<CUSTOM_ARENA_START_TIME>::iterator it = lpInfo->StartTime.begin(); it != lpInfo->StartTime.end(); it++){
		ScheduleManager.AddSchedule(it->Year, it->Month, it->Day, it->Hour, it->Minute, it->Second, it->DayOfWeek);
	}
	if (ScheduleManager.GetSchedule(&ScheduleTime) == 0){
		this->SetState(lpInfo, CUSTOM_ARENA_STATE_BLANK);
		return;
	}
	lpInfo->RemainTime = (int)difftime(ScheduleTime.GetTime(), time(0));
	lpInfo->TargetTime = (int)ScheduleTime.GetTime();
}

int CCustomArena::GetState(int index){
	if (index < 0 || index >= MAX_CUSTOM_ARENA){
		return CUSTOM_ARENA_STATE_BLANK;
	}
	return this->m_CustomArenaInfo[index].State;
}

int CCustomArena::GetRemainTime(int index){
	if (index < 0 || index >= MAX_CUSTOM_ARENA){
		return 0;
	}
	CUSTOM_ARENA_INFO* lpInfo = &this->m_CustomArenaInfo[index];
	if (lpInfo->StartTime.empty() != 0){
		return 0;
	}
	CTime ScheduleTime;
	CScheduleManager ScheduleManager;
	for (std::vector<CUSTOM_ARENA_START_TIME>::iterator it = lpInfo->StartTime.begin(); it != lpInfo->StartTime.end(); it++){
		ScheduleManager.AddSchedule(it->Year, it->Month, it->Day, it->Hour, it->Minute, it->Second, it->DayOfWeek);
	}
	if (ScheduleManager.GetSchedule(&ScheduleTime) == 0){
		return 0;
	}
	int RemainTime = (int)difftime(ScheduleTime.GetTime(), time(0));
	return (((RemainTime % 60) == 0) ? (RemainTime / 60) : ((RemainTime / 60) + 1));
}

int CCustomArena::GetEnterEnabled(int index)
{
	if (index < 0 || index >= MAX_CUSTOM_ARENA){
		return 0;
	}
	return this->m_CustomArenaInfo[index].EnterEnabled;
}

int CCustomArena::GetEnteredUserCount(int index){
	if (index < 0 || index >= MAX_CUSTOM_ARENA){
		return CUSTOM_ARENA_STATE_BLANK;
	}
	return this->GetUserCount(&this->m_CustomArenaInfo[index]);
}

bool CCustomArena::CheckEnteredUser(int index, int aIndex){
	if (index < 0 || index >= MAX_CUSTOM_ARENA){
		return 0;
	}
	return ((this->GetUser(&this->m_CustomArenaInfo[index], aIndex) == 0) ? 0 : 1);
}
bool CCustomArena::CheckReqItems(int index, LPOBJ lpObj)
{
	lpObj->ChaosLock = 1;

	if (this->m_CustomArenaInfo[index].RuleInfo.EventItemCount > 0)
	{
		int count = gItemManager.GetInventoryItemCount(lpObj, this->m_CustomArenaInfo[index].RuleInfo.EventItemID, 0);

		if (count < this->m_CustomArenaInfo[index].RuleInfo.EventItemCount)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(25), this->m_CustomArenaInfo[index].RuleInfo.Name, this->m_CustomArenaInfo[index].RuleInfo.EventItemCount, gItemManager.GetItemName(this->m_CustomArenaInfo[index].RuleInfo.EventItemID));
			return false;
		}

		gItemManager.DeleteInventoryItemCount(lpObj, this->m_CustomArenaInfo[index].RuleInfo.EventItemID, 0, this->m_CustomArenaInfo[index].RuleInfo.EventItemCount);

	}
	int CheckWC = this->m_CustomArenaInfo[index].RuleInfo.mWC;
	int CheckWP = this->m_CustomArenaInfo[index].RuleInfo.mWP;
	int CheckGP = this->m_CustomArenaInfo[index].RuleInfo.mGP;

	if (CheckWC > lpObj->Coin1)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(25), this->m_CustomArenaInfo[index].RuleInfo.Name, CheckWC, "WC");
		return false;
	}
	if (CheckWP > lpObj->Coin2)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(25), this->m_CustomArenaInfo[index].RuleInfo.Name, CheckWP, "WP");
		return false;
	}
	if (CheckGP > lpObj->Coin3)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(25), this->m_CustomArenaInfo[index].RuleInfo.Name, CheckGP, "GP");
		return false;
	}
	if (CheckWC > 0 || CheckWP > 0 || CheckGP > 0)
	{
		GDSetCoinSend(lpObj->Index, (CheckWC > 0 ? -CheckWC : 0), (CheckWP > 0 ? -CheckWP : 0), (CheckGP > 0 ? -CheckGP : 0), "DauTruongTruCoin");
	}
	lpObj->ChaosLock = 0;

	return true;
}
bool CCustomArena::CheckEnterEnabled(LPOBJ lpObj, int gate)
{


	for (int n = 0; n < MAX_CUSTOM_ARENA; n++)
	{
		CUSTOM_ARENA_INFO* lpInfo = &this->m_CustomArenaInfo[n];
		//LogAdd(LOG_RED, "CheckEnterEnabled Dau Truong %d %d Map (%d~%d", lpInfo->RuleInfo.StartGate, gate, gGate.GetGateMap(lpInfo->RuleInfo.StartGate), gGate.GetGateMap(gate));
		if (lpInfo->RuleInfo.StartGate != 0)
		{
			if (gGate.GetGateMap(lpInfo->RuleInfo.StartGate) == gGate.GetGateMap(gate)) //Cung Map
			{
				goto CheckDiEvent;
			}
		}
		if (lpInfo->RuleInfo.StartGate != gate)
		{
			continue;
		}

	CheckDiEvent:
		if (OBJECT_RANGE(lpObj->PartyNumber) != 0) {
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(7));
			return 0;
		}
		if (lpObj->Guild != 0 && lpObj->Guild->WarState == 1) {
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(7));
			return 0;
		}
		if (OBJECT_RANGE(lpObj->DuelUser) != 0) {
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(7));
			return 0;
		}
		if (lpObj->PShopOpen != 0) {
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(7));
			return 0;
		}
		if (this->GetEnterEnabled(lpInfo->Index) == 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(8));
			return 0;
		}
		if (this->GetUserCount(lpInfo) >= ((lpInfo->RuleInfo.MaxUser>MAX_CUSTOM_ARENA_USER) ? MAX_CUSTOM_ARENA_USER : lpInfo->RuleInfo.MaxUser)){
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(9));
			return 0;
		}
		if (lpInfo->RuleInfo.MinLevel != -1 && lpInfo->RuleInfo.MinLevel > lpObj->Level){
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(10), lpInfo->RuleInfo.MinLevel);
			return 0;
		}
		if (lpInfo->RuleInfo.MaxLevel != -1 && lpInfo->RuleInfo.MaxLevel < lpObj->Level){
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(11), lpInfo->RuleInfo.MaxLevel);
			return 0;
		}
		if (lpInfo->RuleInfo.MinMasterLevel != -1 && lpInfo->RuleInfo.MinMasterLevel > lpObj->MasterLevel){
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(12), lpInfo->RuleInfo.MinMasterLevel);
			return 0;
		}
		if (lpInfo->RuleInfo.MaxMasterLevel != -1 && lpInfo->RuleInfo.MaxMasterLevel < lpObj->MasterLevel){
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(13), lpInfo->RuleInfo.MaxMasterLevel);
			return 0;
		}
		if (lpInfo->RuleInfo.MinReset != -1 && lpInfo->RuleInfo.MinReset > lpObj->Reset){
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(14), lpInfo->RuleInfo.MinReset);
			return 0;
		}
		if (lpInfo->RuleInfo.MaxReset != -1 && lpInfo->RuleInfo.MaxReset < lpObj->Reset){
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(15), lpInfo->RuleInfo.MaxReset);
			return 0;
		}
		if (lpInfo->RuleInfo.MinMasterReset != -1 && lpInfo->RuleInfo.MinMasterReset > lpObj->MasterReset){
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(16), lpInfo->RuleInfo.MinMasterReset);
			return 0;
		}
		if (lpInfo->RuleInfo.MaxMasterReset != -1 && lpInfo->RuleInfo.MaxMasterReset < lpObj->MasterReset){
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(17), lpInfo->RuleInfo.MaxMasterReset);
			return 0;
		}
		if (lpInfo->RuleInfo.RequireClass[lpObj->Class] == 0 || lpInfo->RuleInfo.RequireClass[lpObj->Class] >(lpObj->ChangeUp + 1))
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(18));
			//LogAdd(LOG_RED, "CheckClass %d > %d", lpInfo->RuleInfo.RequireClass[lpObj->Class], (lpObj->ChangeUp + 1));
			return 0;
		}
		if (this->CheckReqItems(lpInfo->Index, lpObj) == 0)
		{
			return 0;
		}
		gEffectManager.ClearAllEffect(lpObj);
		return this->AddUser(lpInfo, lpObj->Index);
	}
	return 1;
}

bool CCustomArena::CheckPlayerJoined(LPOBJ lpObj, LPOBJ lpTarget)
{
	if (lpObj->Index == lpTarget->Index)
	{
		return 0;
	}
	if (this->MapEvent[this->IndexEventHienTai] == lpObj->Map)
	{
		//LogAdd(LOG_RED, "Get Target PK lpObj %s lpTarget %s",lpObj->Name, lpTarget->Name);
		for (int n = 0; n < MAX_CUSTOM_ARENA; n++)
		{
			if (this->GetState(n) != CUSTOM_ARENA_STATE_BLANK){
				if (this->CheckEnteredUser(n, lpObj->Index) != 0){
					return 1;
				}
			}
		}
	}

	return 0;
}

bool CCustomArena::CheckPlayerTarget(LPOBJ lpObj, LPOBJ lpTarget){
	if (this->MapEvent[this->IndexEventHienTai] == lpObj->Map)
	{
		for (int n = 0; n < MAX_CUSTOM_ARENA; n++){
			if (this->GetState(n) == CUSTOM_ARENA_STATE_START){
				if (this->CheckEnteredUser(n, lpObj->Index) != 0){
					return 1;
				}
			}
		}
	}
	return 0;
}

bool CCustomArena::AddUser(CUSTOM_ARENA_INFO* lpInfo, int aIndex){
	if (OBJECT_RANGE(aIndex) == 0){
		return 0;
	}
	if (this->GetUser(lpInfo, aIndex) != 0){
		return 0;
	}
	for (int n = 0; n < MAX_CUSTOM_ARENA_USER; n++)
	{
		if (OBJECT_RANGE(lpInfo->User[n].Index) != 0){
			continue;
		}
		lpInfo->User[n].Index = aIndex;
		lpInfo->User[n].Score = 0;
		lpInfo->User[n].Rank = 0;
		lpInfo->User[n].UserKillCount = 0;
		lpInfo->User[n].UserKillStreak = 0;
		lpInfo->User[n].UserDeathCount = 0;
		lpInfo->User[n].UserDeathStreak = 0;
		this->NoticeSendToAll(lpInfo, 1, this->GetMessage(24), lpInfo->RuleInfo.Name, this->GetUserCount(lpInfo));
		//LogAdd(LOG_RED, "[DauTruong] Add User %s tham gia !",gObj[aIndex].Name);
		return 1;
	}


	return 0;
}

bool CCustomArena::DelUser(CUSTOM_ARENA_INFO* lpInfo, int aIndex){
	if (OBJECT_RANGE(aIndex) == 0){
		return 0;
	}
	CUSTOM_ARENA_USER* lpUser = this->GetUser(lpInfo, aIndex);
	if (lpUser == 0){
		return 0;
	}
	lpUser->Reset();
	return 1;
}

CUSTOM_ARENA_USER* CCustomArena::GetUser(CUSTOM_ARENA_INFO* lpInfo, int aIndex){
	if (OBJECT_RANGE(aIndex) == 0){
		return 0;
	}
	for (int n = 0; n < MAX_CUSTOM_ARENA_USER; n++){
		if (lpInfo->User[n].Index == aIndex){
			return &lpInfo->User[n];
		}
	}
	return 0;
}

void CCustomArena::CleanUser(CUSTOM_ARENA_INFO* lpInfo){
	for (int n = 0; n < MAX_CUSTOM_ARENA_USER; n++)
	{
		lpInfo->User[n].Reset();
	}
}

void CCustomArena::ClearUser(CUSTOM_ARENA_INFO* lpInfo)
{
	for (int n = 0; n < MAX_CUSTOM_ARENA_USER; n++){
		if (OBJECT_RANGE(lpInfo->User[n].Index) == 0)
		{
			continue;
		}
		this->SendUserInfoEvent(lpInfo, 1); //Send Clear Info
		gObjMoveGate(lpInfo->User[n].Index, lpInfo->RuleInfo.FinalGate);
		lpInfo->User[n].Reset();
	}
}

void CCustomArena::CheckUser(CUSTOM_ARENA_INFO* lpInfo){
	for (int n = 0; n < MAX_CUSTOM_ARENA_USER; n++)
	{
		if (OBJECT_RANGE(lpInfo->User[n].Index) == 0){
			continue;
		}
		if (gObjIsConnected(lpInfo->User[n].Index) == 0){
			this->DelUser(lpInfo, lpInfo->User[n].Index);
			continue;
		}
		//LogAdd(LOG_RED, "Check User (%d) %d ~ %d", lpInfo->Index, gGate.GetGateMap(lpInfo->RuleInfo.StartGate), gObj[lpInfo->User[n].Index].Map);
		if (gGate.GetGateMap(lpInfo->RuleInfo.StartGate) != gObj[lpInfo->User[n].Index].Map)
		{
			this->DelUser(lpInfo, lpInfo->User[n].Index);
			continue;
		}
	}
}

int CCustomArena::GetUserCount(CUSTOM_ARENA_INFO* lpInfo){
	int count = 0;
	for (int n = 0; n < MAX_CUSTOM_ARENA_USER; n++)
	{
		if (OBJECT_RANGE(lpInfo->User[n].Index) != 0){
			count++;
		}
	}
	return count;
}

void CCustomArena::CalcUserRank(CUSTOM_ARENA_INFO* lpInfo)
{
	for (int stt = 0; stt < CacheTop; stt++)
	{
		this->mIndexRank[stt] = -1;
	}
	for (int n = 0; n < MAX_CUSTOM_ARENA_USER; n++)
	{
		if (OBJECT_RANGE(lpInfo->User[n].Index) == 0){
			continue;
		}
		int rank = MAX_CUSTOM_ARENA_USER;
		for (int i = 0; i < MAX_CUSTOM_ARENA_USER; i++)
		{
			if (OBJECT_RANGE(lpInfo->User[i].Index) == 0){
				rank--;
				continue;
			}
			if (lpInfo->User[n].Index == lpInfo->User[i].Index){
				rank--;
				continue;
			}
			if (lpInfo->User[n].Score > lpInfo->User[i].Score){
				rank--;
				continue;
			}
			if (lpInfo->User[n].Score == lpInfo->User[i].Score && n < i){
				rank--;
				continue;
			}
		}
		lpInfo->User[n].Rank = (rank + 1);

		if (lpInfo->User[n].Rank >= 1 && lpInfo->User[n].Rank <= CacheTop)
		{
			int Stt = lpInfo->User[n].Rank - 1;
			this->mIndexRank[Stt] = n;
			//LogAdd(LOG_RED, "GETRANK %d ~ %d", this->mIndexRank[Stt], n);
		}
	}
}

bool CCustomArena::GetUserRespawnLocation(LPOBJ lpObj, int* gate, int* map, int* x, int* y, int* dir, int* level){

	if (this->MapEvent[this->IndexEventHienTai] != lpObj->Map)
	{
		return 0;
	}
	for (int n = 0; n < MAX_CUSTOM_ARENA; n++)
	{
		CUSTOM_ARENA_INFO* lpInfo = &this->m_CustomArenaInfo[n];
		if (this->GetState(lpInfo->Index) < CUSTOM_ARENA_STATE_START && this->GetState(lpInfo->Index) > CUSTOM_ARENA_STATE_CHUNGKET)
		{
			continue;
		}
		CUSTOM_ARENA_USER* lpUser = this->GetUser(lpInfo, lpObj->Index);
		if (lpUser == 0){
			continue;
		}
		if (lpInfo->RuleInfo.MaxDeath != -1 && lpUser->UserDeathCount >= lpInfo->RuleInfo.MaxDeath){
			if (gGate.GetGate(lpInfo->RuleInfo.FinalGate, gate, map, x, y, dir, level) != 0){
				GDRankingCustomArenaSaveSend(lpUser->Index, lpInfo->Index, lpUser->Score, 0);
				this->DelUser(lpInfo, lpObj->Index);
				return 1;
			}
		}
		else
		{
			if (this->GetState(lpInfo->Index) == CUSTOM_ARENA_STATE_START)
			{
				if (gGate.GetGate(lpInfo->RuleInfo.GateCong1, gate, map, x, y, dir, level) != 0)
				{
					return 1;
				}

			}
			else
			{
				//== VOng Khac VOng lOai thi die ra ngoi cho`
				if (gGate.GetGate(lpInfo->RuleInfo.StartGate, gate, map, x, y, dir, level) != 0)
				{
					return 1;
				}
			}
		}
	}
	return 0;
}

bool CCustomArena::UserDieProc(LPOBJ lpObj, LPOBJ lpTarget)
{
	if (this->IndexEventHienTai == -1)
	{
		return 0;
	}
	if (this->MapEvent[this->IndexEventHienTai] != lpObj->Map || this->MapEvent[this->IndexEventHienTai] != lpTarget->Map)
	{
		return 0;
	}
	for (int n = 0; n < MAX_CUSTOM_ARENA; n++)
	{
		CUSTOM_ARENA_INFO* lpInfo = &this->m_CustomArenaInfo[n];
		if (this->GetState(lpInfo->Index) < CUSTOM_ARENA_STATE_START && this->GetState(lpInfo->Index) > CUSTOM_ARENA_STATE_CHUNGKET){
			continue;
		}
		CUSTOM_ARENA_USER* lpUserA = this->GetUser(lpInfo, lpObj->Index);
		if (lpUserA == 0){
			return 0;
		}
		CUSTOM_ARENA_USER* lpUserB = this->GetUser(lpInfo, lpTarget->Index);
		if (lpUserB == 0){
			return 0;
		}

		if (this->GetState(lpInfo->Index) == CUSTOM_ARENA_STATE_BANKET || this->GetState(lpInfo->Index) == CUSTOM_ARENA_STATE_CHUNGKET)
		{

			int DiemNguoiChet = lpUserA->Score;
			int RankNguoiChet = lpUserA->Rank;

			if (lpUserB->Rank > RankNguoiChet)
			{
				lpUserA->Rank = lpUserB->Rank;
				lpUserA->Score = lpUserB->Score;
				//~~~
				lpUserB->Rank = RankNguoiChet;
				lpUserB->Score = DiemNguoiChet;
			}
			this->SoLuotChet++;
			//LogAdd(LOG_BLUE, "UserDieProc SoLuotChet %d A %d B %d (-%d/+%d)", this->SoLuotChet, lpUserA->Score, lpUserB->Score, this->m_CustomArenaVictimScoreDecrease, this->m_CustomArenaKillerScoreIncrease);

			if ((this->SoLuotChet > 1 && this->GetState(lpInfo->Index) == CUSTOM_ARENA_STATE_BANKET))
			{
				this->SetState(lpInfo, CUSTOM_ARENA_STATE_CHOCHUNGKET);
			}
			else if ((this->SoLuotChet > 0 && this->GetState(lpInfo->Index) == CUSTOM_ARENA_STATE_CHUNGKET))  //Co 2 thang hoi sinh thi ket thuc
			{
				this->SetState(lpInfo, CUSTOM_ARENA_STATE_CLEAN);
				//return 1;
			}
		}
		else
		{
			lpUserA->Score -= ((lpUserA->Score > this->m_CustomArenaVictimScoreDecrease) ? this->m_CustomArenaVictimScoreDecrease : lpUserA->Score);
			lpUserA->UserKillStreak = 0;
			lpUserA->UserDeathCount++;
			lpUserA->UserDeathStreak++;
			//==Nguoi Giet
			lpUserB->Score += this->m_CustomArenaKillerScoreIncrease;
			lpUserB->UserKillCount++;
			lpUserB->UserKillStreak++;
			lpUserB->UserDeathStreak = 0;
			//LogAdd(LOG_BLUE, "UserDieProc A %d B %d (-%d/+%d)", lpUserA->Score, lpUserB->Score, this->m_CustomArenaVictimScoreDecrease,this->m_CustomArenaKillerScoreIncrease);

		}
		this->CalcUserRank(lpInfo); //Tinh Toan Xep Hang
	}
	return 1;
}

void CCustomArena::NoticeSendToAll(CUSTOM_ARENA_INFO* lpInfo, int type, char* message, ...){
	char buff[256];
	va_list arg;
	va_start(arg, message);
	vsprintf_s(buff, message, arg);
	va_end(arg);
	for (int n = 0; n < MAX_CUSTOM_ARENA_USER; n++){
		if (OBJECT_RANGE(lpInfo->User[n].Index) != 0){
			gNotice.GCNoticeSend(lpInfo->User[n].Index, type, 0, 0, 0, 0, 0, buff);
		}
	}
}

void CCustomArena::DataSendToAll(CUSTOM_ARENA_INFO* lpInfo, BYTE* lpMsg, int size){
	for (int n = 0; n < MAX_CUSTOM_ARENA_USER; n++){
		if (OBJECT_RANGE(lpInfo->User[n].Index) != 0)
		{
			DataSend(lpInfo->User[n].Index, lpMsg, size);
		}
	}
}

void CCustomArena::StartCustomArena(int index){
	CTime CurrentTime = CTime::GetTickCount();
	int hour = (int)CurrentTime.GetHour();
	int minute = (int)CurrentTime.GetMinute() + 2;
	if (minute >= 60){
		hour++;
		minute = minute - 60;
	}
	CUSTOM_ARENA_START_TIME info;
	info.Year = (int)CurrentTime.GetYear();
	info.Month = (int)CurrentTime.GetMonth();
	info.Day = (int)CurrentTime.GetDay();
	info.DayOfWeek = -1;
	info.Hour = hour;
	info.Minute = minute;
	info.Second = 0;
	this->m_CustomArenaInfo[index].StartTime.push_back(info);
	//LogAdd(LOG_EVENT,"[Set CustomArena Start] Index %d At %2d:%2d:00",index,hour,minute);
	this->SetState(&this->m_CustomArenaInfo[index], CUSTOM_ARENA_STATE_EMPTY);
}

char* CCustomArena::GetArenaName(int index){
	return this->m_CustomArenaInfo[index].RuleInfo.Name;
}


void CCustomArena::SendUserInfoEvent(CUSTOM_ARENA_INFO* lpInfo, int Clear)
{
	for (int n = 0; n < MAX_CUSTOM_ARENA_USER; n++)
	{
		if (OBJECT_RANGE(lpInfo->User[n].Index) != 0)
		{
			//===========Send Info
			DAUTRUONGEVENT_INFO pMsg;
			pMsg.header.set(0xD3, 0x32, sizeof(pMsg));
			pMsg.Rank = (WORD)lpInfo->User[n].Rank;
			pMsg.Score = (WORD)lpInfo->User[n].Score;//Diem
			pMsg.State = (BYTE)((Clear == 1) ? 0 : lpInfo->State);
			pMsg.Time = (DWORD)((Clear == 1 || lpInfo->RemainTime < 1) ? 0 : lpInfo->RemainTime);//Time
			DataSend(lpInfo->User[n].Index, (BYTE*)& pMsg, pMsg.header.size);
			//===
		}
	}
}

//===Get List > Send Client
void CCustomArena::SendBXHInfo(int aIndex)
{
	if (!this->m_CustomArenaSwitch || this->IndexEventHienTai == -1)
	{
		return;
	}

	if (gObjIsConnected(aIndex) == false)
	{
		return;
	}
	CUSTOM_ARENA_INFO* lpInfo = &this->m_CustomArenaInfo[this->IndexEventHienTai];

	this->CalcUserRank(lpInfo);

	BYTE send[4096];

	RECVDAUTRUONGEVENT_BXH pMsg;

	pMsg.header.set(0xD3, 0x33, 0);

	int size = sizeof(pMsg);

	pMsg.Count = 0;

	DAUTRUONGEVENT_BXH info;


	for (int n = 0; n < CacheTop; n++)
	{
		if (OBJECT_RANGE(lpInfo->User[this->mIndexRank[n]].Index) == 0)
		{
			continue;
		}
		info.Rank = lpInfo->User[this->mIndexRank[n]].Rank;
		info.Score = lpInfo->User[this->mIndexRank[n]].Score;
		memcpy(info.Name, gObj[lpInfo->User[this->mIndexRank[n]].Index].Name, sizeof(info.Name) - 1);

		pMsg.Count++;

		memcpy(&send[size], &info, sizeof(info));
		size += sizeof(info);

	}

	pMsg.header.size[0] = SET_NUMBERHB(size);
	pMsg.header.size[1] = SET_NUMBERLB(size);
	// ---
	memcpy(send, &pMsg, sizeof(pMsg));

	DataSend(aIndex, send, size);

}