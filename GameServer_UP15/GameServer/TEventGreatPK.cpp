// CustomGreatPK.cpp: implementation of the CCustomGreatPK class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TEventGreatPK.h"
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

CCustomGreatPK gCustomGreatPK;

CCustomGreatPK::CCustomGreatPK()
{
	for (int n = 0; n < MAX_CUSTOM_GREATPK; n++)
	{

		CUSTOM_GREATPK_INFO* lpInfo = &this->m_CustomGreatPKInfo[n];
		lpInfo->Index = n;
		lpInfo->State = CUSTOM_GREATPK_STATE_BLANK;
		lpInfo->RemainTime = 0;
		lpInfo->TargetTime = 0;
		lpInfo->TickCount = GetTickCount();
		lpInfo->EnterEnabled = 0;
		lpInfo->AlarmMinSave = -1;
		lpInfo->AlarmMinLeft = -1;
		this->CleanUser(lpInfo);
	}
}

CCustomGreatPK::~CCustomGreatPK(){

}

void CCustomGreatPK::Init()
{
	for (int n = 0; n < MAX_CUSTOM_GREATPK; n++)
	{
		if (this->m_CustomGreatPKSwitch == 0) //Bat/Tat Event
		{
			this->SetState(&this->m_CustomGreatPKInfo[n], CUSTOM_GREATPK_STATE_BLANK);
		}
		else{
			this->SetState(&this->m_CustomGreatPKInfo[n], CUSTOM_GREATPK_STATE_EMPTY);
		}
	}
}

void CCustomGreatPK::ReadCustomGreatPKInfo(char* section, char* path){

}

void CCustomGreatPK::Load(char* path)
{
	pugi::xml_document file;
	pugi::xml_parse_result res = file.load_file(path);
	if (res.status != pugi::status_ok){
		ErrorMessageBox("File %s load fail. Error: %s", path, res.description());
		return;
	}
	this->m_CustomGreatPKSwitch = 0;
	this->IndexEventHienTai = -1;
	this->SoLuotChet = 0;
	for (int n = 0; n < MAX_CUSTOM_GREATPK; n++)
	{
		this->MapEvent[n] = -1;
		this->m_CustomGreatPKInfo[n].StartTime.clear();
	}
	pugi::xml_node Principal = file.child("EventDauTruong");

	this->m_CustomGreatPKSwitch = Principal.attribute("Enable").as_int(); //Bat Tat
	this->m_CustomGreatPKVictimScoreDecrease = Principal.attribute("ScoreDie").as_int(10); //Diem Tru Khi Chet
	this->m_CustomGreatPKKillerScoreIncrease = Principal.attribute("ScoreKill").as_int(100); //Diem Cong Khi Giet

	pugi::xml_node ArenaTime = Principal.child("CreateTime");
	for (pugi::xml_node time = ArenaTime.child("Load"); time; time = time.next_sibling()){
		CUSTOM_GREATPK_START_TIME info;
		int index = time.attribute("Index").as_int();
		info.Year = time.attribute("Year").as_int();
		info.Month = time.attribute("Month").as_int();
		info.Day = time.attribute("Day").as_int();
		info.DayOfWeek = time.attribute("DayOfWeek").as_int();
		info.Hour = time.attribute("Hour").as_int();
		info.Minute = time.attribute("Minute").as_int();
		info.Second = time.attribute("Second").as_int();
		this->m_CustomGreatPKInfo[index].StartTime.push_back(info);
	}
	//= Mess Load
	this->m_MessageInfoBP.clear();
	pugi::xml_node Message = Principal.child("Message");
	for (pugi::xml_node msg = Message.child("Msg"); msg; msg = msg.next_sibling())
	{
		MESSAGE_INFO_GREATPK info;

		info.Index = msg.attribute("Index").as_int();

		strcpy_s(info.Message, msg.attribute("Text").as_string());

		this->m_MessageInfoBP.insert(std::pair<int, MESSAGE_INFO_GREATPK>(info.Index, info));
	}


	for (pugi::xml_node load = Principal.child("TypeDauTruong"); load; load = load.next_sibling()){
		int index = load.attribute("Index").as_int();
		strcpy_s(this->m_CustomGreatPKInfo[index].RuleInfo.Name, load.attribute("Name").as_string());
		this->m_CustomGreatPKInfo[index].RuleInfo.AlarmTime = load.attribute("AlarmTime").as_int();
		this->m_CustomGreatPKInfo[index].RuleInfo.StandTime = load.attribute("StandTime").as_int();
		this->m_CustomGreatPKInfo[index].RuleInfo.EventTime = load.attribute("EventTime").as_int();
		this->m_CustomGreatPKInfo[index].RuleInfo.CloseTime = load.attribute("CloseTime").as_int();
		//==Conifig Item Check
		pugi::xml_node ConfigItemCheck = load.child("ConfigItemCheck");
		this->m_CustomGreatPKInfo[index].RuleInfo.EventItemID = ConfigItemCheck.attribute("EventItemID").as_int();
		this->m_CustomGreatPKInfo[index].RuleInfo.EventItemCount = ConfigItemCheck.attribute("EventItemCount").as_int();
		this->m_CustomGreatPKInfo[index].RuleInfo.mWC = ConfigItemCheck.attribute("WC").as_int();

		//==Conifig Class
		pugi::xml_node ConfigClass = load.child("ConfigClass");
		this->m_CustomGreatPKInfo[index].RuleInfo.RequireClass[0] = ConfigClass.attribute("DW").as_int();
		this->m_CustomGreatPKInfo[index].RuleInfo.RequireClass[1] = ConfigClass.attribute("DK").as_int();
		this->m_CustomGreatPKInfo[index].RuleInfo.RequireClass[2] = ConfigClass.attribute("FE").as_int();
		this->m_CustomGreatPKInfo[index].RuleInfo.RequireClass[3] = ConfigClass.attribute("MG").as_int();
		this->m_CustomGreatPKInfo[index].RuleInfo.RequireClass[4] = ConfigClass.attribute("DL").as_int();
		this->m_CustomGreatPKInfo[index].RuleInfo.RequireClass[5] = ConfigClass.attribute("SU").as_int();
		this->m_CustomGreatPKInfo[index].RuleInfo.RequireClass[6] = ConfigClass.attribute("RF").as_int();
		//==Conifig Gate
		pugi::xml_node ConfigGate = load.child("ConfigGate");
		this->m_CustomGreatPKInfo[index].RuleInfo.StartGate = ConfigGate.attribute("GateEvent").as_int();
		this->m_CustomGreatPKInfo[index].RuleInfo.FinalGate = ConfigGate.attribute("GateFinal").as_int();

		//==Conifig Check
		pugi::xml_node ConfigCheck = load.child("ConfigCheck");
		this->m_CustomGreatPKInfo[index].RuleInfo.MinUser = ConfigCheck.attribute("MinUser").as_int();
		this->m_CustomGreatPKInfo[index].RuleInfo.MaxUser = ConfigCheck.attribute("MaxUser").as_int();
		this->m_CustomGreatPKInfo[index].RuleInfo.MaxDeath = ConfigCheck.attribute("MaxDeath").as_int();
		this->m_CustomGreatPKInfo[index].RuleInfo.MinLevel = ConfigCheck.attribute("MinLevel").as_int();
		this->m_CustomGreatPKInfo[index].RuleInfo.MaxLevel = ConfigCheck.attribute("MaxLevel").as_int();
		this->m_CustomGreatPKInfo[index].RuleInfo.MinMasterLevel = ConfigCheck.attribute("MinMLevel").as_int();
		this->m_CustomGreatPKInfo[index].RuleInfo.MaxMasterLevel = ConfigCheck.attribute("MaxMLevel").as_int();
		this->m_CustomGreatPKInfo[index].RuleInfo.MinReset = ConfigCheck.attribute("MinReset").as_int();
		this->m_CustomGreatPKInfo[index].RuleInfo.MaxReset = ConfigCheck.attribute("MaxReset").as_int();
		this->m_CustomGreatPKInfo[index].RuleInfo.MinMasterReset = ConfigCheck.attribute("MinMReset").as_int();
		this->m_CustomGreatPKInfo[index].RuleInfo.MaxMasterReset = ConfigCheck.attribute("MaxMReset").as_int();
		//==Conifig Phan Thuong Top 1
		pugi::xml_node ConfigRewardTop1 = load.child("ConfigRewardTop1");
		this->m_CustomGreatPKInfo[index].RuleInfo.EventItemBag[0] = ConfigRewardTop1.attribute("EventItemBag").as_int();
		this->m_CustomGreatPKInfo[index].RuleInfo.WC[0] = ConfigRewardTop1.attribute("WC").as_int();
		//
		pugi::xml_node ConfigRewardTop2 = load.child("ConfigRewardTop2");
		this->m_CustomGreatPKInfo[index].RuleInfo.EventItemBag[1] = ConfigRewardTop2.attribute("EventItemBag").as_int();
		this->m_CustomGreatPKInfo[index].RuleInfo.WC[1] = ConfigRewardTop2.attribute("WC").as_int();
		//
		pugi::xml_node ConfigRewardTop3 = load.child("ConfigRewardTop3");
		this->m_CustomGreatPKInfo[index].RuleInfo.EventItemBag[2] = ConfigRewardTop3.attribute("EventItemBag").as_int();
		this->m_CustomGreatPKInfo[index].RuleInfo.WC[2] = ConfigRewardTop3.attribute("WC").as_int();
		//
		pugi::xml_node ConfigRewardTop4 = load.child("ConfigRewardTop4");
		this->m_CustomGreatPKInfo[index].RuleInfo.EventItemBag[3] = ConfigRewardTop4.attribute("EventItemBag").as_int();
		this->m_CustomGreatPKInfo[index].RuleInfo.WC[3] = ConfigRewardTop4.attribute("WC").as_int();
		//
		pugi::xml_node ConfigRewardTop5 = load.child("ConfigRewardTop5");
		this->m_CustomGreatPKInfo[index].RuleInfo.EventItemBag[4] = ConfigRewardTop5.attribute("EventItemBag").as_int();
		this->m_CustomGreatPKInfo[index].RuleInfo.WC[4] = ConfigRewardTop5.attribute("WC").as_int();
	}

	LogAdd(LOG_BLUE, "[DauTruongPK] Load OK %d", this->m_CustomGreatPKSwitch);
}
char* CCustomGreatPK::GetMessage(int index) // OK
{
	std::map<int, MESSAGE_INFO_GREATPK>::iterator it = this->m_MessageInfoBP.find(index);

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

void CCustomGreatPK::MainProc()
{
	for (int n = 0; n < MAX_CUSTOM_GREATPK; n++)
	{
		CUSTOM_GREATPK_INFO* lpInfo = &this->m_CustomGreatPKInfo[n];
		if ((GetTickCount() - lpInfo->TickCount) >= 1000)
		{
			lpInfo->TickCount = GetTickCount();
			lpInfo->RemainTime = (int)difftime(lpInfo->TargetTime, time(0));
			if (lpInfo->State == CUSTOM_GREATPK_STATE_BLANK){
				if (gServerDisplayer.EventCustomGreatPK[n] != -1){
					gServerDisplayer.EventCustomGreatPK[n] = -1;
				}
			}
			else {
				if (lpInfo->State == CUSTOM_GREATPK_STATE_EMPTY){
					gServerDisplayer.EventCustomGreatPK[n] = lpInfo->RemainTime;
				}
				else{
					if (gServerDisplayer.EventCustomGreatPK[n] != 0){
						gServerDisplayer.EventCustomGreatPK[n] = 0;
					}
				}
			}
			if (gServerDisplayer.EventCustomGreatPK[n] > 0){
				if (lpInfo->State != CUSTOM_GREATPK_STATE_EMPTY && lpInfo->State != CUSTOM_GREATPK_STATE_BLANK){
					gServerDisplayer.EventCustomGreatPK[n] = 0;
				}
			}
			if (lpInfo->State >= CUSTOM_GREATPK_STATE_EMPTY)
			{
				this->SendUserInfoEvent(lpInfo);
			}

			switch (lpInfo->State)
			{
			case CUSTOM_GREATPK_STATE_BLANK:
				this->ProcState_BLANK(lpInfo);
				break;
			case CUSTOM_GREATPK_STATE_EMPTY:
				this->ProcState_EMPTY(lpInfo);
				break;
			case CUSTOM_GREATPK_STATE_STAND:
				this->ProcState_STAND(lpInfo);
				break;
			case CUSTOM_GREATPK_STATE_START:
				this->ProcState_START(lpInfo);
				break;
			case CUSTOM_GREATPK_STATE_CLEAN:
				this->ProcState_CLEAN(lpInfo);
				break;
			}
		}
	}
}

void CCustomGreatPK::ProcState_BLANK(CUSTOM_GREATPK_INFO* lpInfo){

}

void CCustomGreatPK::ProcState_EMPTY(CUSTOM_GREATPK_INFO* lpInfo){
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
		this->SetState(lpInfo, CUSTOM_GREATPK_STATE_STAND);
	}
}

void CCustomGreatPK::ProcState_STAND(CUSTOM_GREATPK_INFO* lpInfo)
{

	this->CheckUser(lpInfo);
	if (this->GetUserCount(lpInfo) < ((lpInfo->RuleInfo.MinUser == -1) ? 1 : lpInfo->RuleInfo.MinUser)){
		this->SetState(lpInfo, CUSTOM_GREATPK_STATE_EMPTY);
		return;
	}
	if (lpInfo->RemainTime <= 0){
		this->NoticeSendToAll(lpInfo, 0, this->GetMessage(3), lpInfo->RuleInfo.Name);
		this->SetState(lpInfo, CUSTOM_GREATPK_STATE_START);
	}
}
//==Vong Loai
void CCustomGreatPK::ProcState_START(CUSTOM_GREATPK_INFO* lpInfo)
{
	this->CheckUser(lpInfo);
	if (this->GetUserCount(lpInfo) == 0){
		this->SetState(lpInfo, CUSTOM_GREATPK_STATE_EMPTY);
		return;
	}

	if (this->GetUserCount(lpInfo) == 1){
		this->SetState(lpInfo, CUSTOM_GREATPK_STATE_CLEAN);
		return;
	}
	if (lpInfo->RemainTime <= 0)
	{

		this->NoticeSendToAll(lpInfo, 0, this->GetMessage(23)); //Ket thuc trao thuong
		this->SetState(lpInfo, CUSTOM_GREATPK_STATE_CLEAN); //Set trang thai cho`

	}
}

void CCustomGreatPK::ProcState_CLEAN(CUSTOM_GREATPK_INFO* lpInfo){
	this->CheckUser(lpInfo);
	if (lpInfo->RemainTime <= 0){
		this->SetState(lpInfo, CUSTOM_GREATPK_STATE_EMPTY);
	}
}

void CCustomGreatPK::SetState(CUSTOM_GREATPK_INFO* lpInfo, int state){
	switch ((lpInfo->State = state)){
	case CUSTOM_GREATPK_STATE_BLANK:
		this->SetState_BLANK(lpInfo);
		break;
	case CUSTOM_GREATPK_STATE_EMPTY:
		this->SetState_EMPTY(lpInfo);
		break;
	case CUSTOM_GREATPK_STATE_STAND:
		this->SetState_STAND(lpInfo);
		break;
	case CUSTOM_GREATPK_STATE_START:
		this->SetState_START(lpInfo);
		break;
	case CUSTOM_GREATPK_STATE_CLEAN:
		this->SetState_CLEAN(lpInfo);
		break;
	}
}

void CCustomGreatPK::SetState_BLANK(CUSTOM_GREATPK_INFO* lpInfo){

}

void CCustomGreatPK::SetState_EMPTY(CUSTOM_GREATPK_INFO* lpInfo){
	lpInfo->EnterEnabled = 0;
	lpInfo->AlarmMinSave = -1;
	lpInfo->AlarmMinLeft = -1;
	this->ClearUser(lpInfo);
	this->CheckSync(lpInfo);

}

void CCustomGreatPK::SetState_STAND(CUSTOM_GREATPK_INFO* lpInfo)
{
	lpInfo->EnterEnabled = 0;
	lpInfo->AlarmMinSave = -1;
	lpInfo->AlarmMinLeft = -1;
	lpInfo->RemainTime = lpInfo->RuleInfo.StandTime * 60;
	lpInfo->TargetTime = (int)(time(0) + lpInfo->RemainTime);
}
void CCustomGreatPK::SetState_START(CUSTOM_GREATPK_INFO* lpInfo) {
	lpInfo->EnterEnabled = 0;
	lpInfo->AlarmMinSave = -1;
	lpInfo->AlarmMinLeft = -1;
	lpInfo->RemainTime = lpInfo->RuleInfo.EventTime * 60;
	lpInfo->TargetTime = (int)(time(0) + lpInfo->RemainTime);
}
//==Ket THuc

void CCustomGreatPK::SetState_CLEAN(CUSTOM_GREATPK_INFO* lpInfo){
	lpInfo->EnterEnabled = 0;
	lpInfo->AlarmMinSave = -1;
	lpInfo->AlarmMinLeft = -1;
	this->CalcUserRank(lpInfo);
	//=== Trao Thuong
	for (int n = 0; n < MAX_CUSTOM_GREATPK_USER; n++)
	{
		if (OBJECT_RANGE(lpInfo->User[n].Index) != 0)
		{
			int TopGreatPK = lpInfo->User[n].Rank;

			LPOBJ lpObj = &gObj[lpInfo->User[n].Index];

			switch (TopGreatPK)
			{
			case 1:
			{
				GDRankingCustomGreatPKSaveSend(lpInfo->User[n].Index, lpInfo->Index, lpInfo->User[n].Score, lpInfo->User[n].Rank);
				gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, this->GetMessage(5), lpInfo->RuleInfo.Name, gObj[lpInfo->User[n].Index].Name, lpInfo->User[n].Rank);
				gNotice.GCNoticeSend(lpInfo->User[n].Index, 1, 0, 0, 0, 0, 0, this->GetMessage(6), lpInfo->RuleInfo.Name, lpInfo->User[n].Rank, lpInfo->User[n].Score);
				GDSetCoinSend(lpObj->Index, lpInfo->RuleInfo.WC[0], 0, 0, "Top1DauTruong");
				gItemBagManager.DropItemByIndexItemBag(lpInfo->RuleInfo.EventItemBag[0], lpObj);
			}
			break;
			case 2:
			{
				GDRankingCustomGreatPKSaveSend(lpInfo->User[n].Index, lpInfo->Index, lpInfo->User[n].Score, lpInfo->User[n].Rank);
				gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, this->GetMessage(5), lpInfo->RuleInfo.Name, gObj[lpInfo->User[n].Index].Name, lpInfo->User[n].Rank);
				gNotice.GCNoticeSend(lpInfo->User[n].Index, 1, 0, 0, 0, 0, 0, this->GetMessage(6), lpInfo->RuleInfo.Name, lpInfo->User[n].Rank, lpInfo->User[n].Score);
				GDSetCoinSend(lpObj->Index, lpInfo->RuleInfo.WC[1], 0, 0, "Top2DauTruong");
				gItemBagManager.DropItemByIndexItemBag(lpInfo->RuleInfo.EventItemBag[1], lpObj);
			}
			break;
			case 3:
			{
				GDRankingCustomGreatPKSaveSend(lpInfo->User[n].Index, lpInfo->Index, lpInfo->User[n].Score, lpInfo->User[n].Rank);
				gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, this->GetMessage(5), lpInfo->RuleInfo.Name, gObj[lpInfo->User[n].Index].Name, lpInfo->User[n].Rank);
				gNotice.GCNoticeSend(lpInfo->User[n].Index, 1, 0, 0, 0, 0, 0, this->GetMessage(6), lpInfo->RuleInfo.Name, lpInfo->User[n].Rank, lpInfo->User[n].Score);
				GDSetCoinSend(lpObj->Index, lpInfo->RuleInfo.WC[2], 0, 0, "Top3DauTruong");
				gItemBagManager.DropItemByIndexItemBag(lpInfo->RuleInfo.EventItemBag[2], lpObj);
			}
			break;
			case 4:
			{
				GDRankingCustomGreatPKSaveSend(lpInfo->User[n].Index, lpInfo->Index, lpInfo->User[n].Score, lpInfo->User[n].Rank);
				gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, this->GetMessage(5), lpInfo->RuleInfo.Name, gObj[lpInfo->User[n].Index].Name, lpInfo->User[n].Rank);
				gNotice.GCNoticeSend(lpInfo->User[n].Index, 1, 0, 0, 0, 0, 0, this->GetMessage(6), lpInfo->RuleInfo.Name, lpInfo->User[n].Rank, lpInfo->User[n].Score);
				GDSetCoinSend(lpObj->Index, lpInfo->RuleInfo.WC[3], 0, 0, "Top4DauTruong");
				gItemBagManager.DropItemByIndexItemBag(lpInfo->RuleInfo.EventItemBag[3], lpObj);
			}
			break;
			case 5:
			{
				GDRankingCustomGreatPKSaveSend(lpInfo->User[n].Index, lpInfo->Index, lpInfo->User[n].Score, lpInfo->User[n].Rank);
				gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, this->GetMessage(5), lpInfo->RuleInfo.Name, gObj[lpInfo->User[n].Index].Name, lpInfo->User[n].Rank);
				gNotice.GCNoticeSend(lpInfo->User[n].Index, 1, 0, 0, 0, 0, 0, this->GetMessage(6), lpInfo->RuleInfo.Name, lpInfo->User[n].Rank, lpInfo->User[n].Score);
				GDSetCoinSend(lpObj->Index, lpInfo->RuleInfo.WC[4], 0, 0, "Top5DauTruong");
				gItemBagManager.DropItemByIndexItemBag(lpInfo->RuleInfo.EventItemBag[4], lpObj);
			}
			break;
			default:
				break;
			}
			GDRankingCustomGreatPKSaveSend(lpInfo->User[n].Index, lpInfo->Index, lpInfo->User[n].Score, lpInfo->User[n].Rank);
			gNotice.GCNoticeSend(lpInfo->User[n].Index, 1, 0, 0, 0, 0, 0, this->GetMessage(6), lpInfo->RuleInfo.Name, lpInfo->User[n].Rank, lpInfo->User[n].Score);

			/*if (lpInfo->User[n].Rank == 1)
			{
			GDRankingCustomGreatPKSaveSend(lpInfo->User[n].Index, lpInfo->Index, lpInfo->User[n].Score, lpInfo->User[n].Rank);
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, this->GetMessage(5), lpInfo->RuleInfo.Name, gObj[lpInfo->User[n].Index].Name, lpInfo->User[n].Rank);
			gNotice.GCNoticeSend(lpInfo->User[n].Index, 1, 0, 0, 0, 0, 0, this->GetMessage(6), lpInfo->RuleInfo.Name, lpInfo->User[n].Rank, lpInfo->User[n].Score);
			GDSetCoinSend(lpObj->Index, lpInfo->RuleInfo.WC, 0, 0, "Top1DauTruong");
			gItemBagManager.DropItemByIndexItemBag(lpInfo->RuleInfo.EventItemBag, lpObj);
			}
			else
			{
			GDRankingCustomGreatPKSaveSend(lpInfo->User[n].Index, lpInfo->Index, lpInfo->User[n].Score, lpInfo->User[n].Rank);
			gNotice.GCNoticeSend(lpInfo->User[n].Index, 1, 0, 0, 0, 0, 0, this->GetMessage(6), lpInfo->RuleInfo.Name, lpInfo->User[n].Rank, lpInfo->User[n].Score);
			}*/
		}
	}

	lpInfo->RemainTime = lpInfo->RuleInfo.CloseTime * 60;

	lpInfo->TargetTime = (int)(time(0) + lpInfo->RemainTime);
}

void CCustomGreatPK::CheckSync(CUSTOM_GREATPK_INFO* lpInfo){
	if (lpInfo->StartTime.empty() != 0){
		this->SetState(lpInfo, CUSTOM_GREATPK_STATE_BLANK);
		return;
	}
	CTime ScheduleTime;
	CScheduleManager ScheduleManager;
	for (std::vector<CUSTOM_GREATPK_START_TIME>::iterator it = lpInfo->StartTime.begin(); it != lpInfo->StartTime.end(); it++){
		ScheduleManager.AddSchedule(it->Year, it->Month, it->Day, it->Hour, it->Minute, it->Second, it->DayOfWeek);
	}
	if (ScheduleManager.GetSchedule(&ScheduleTime) == 0){
		this->SetState(lpInfo, CUSTOM_GREATPK_STATE_BLANK);
		return;
	}
	lpInfo->RemainTime = (int)difftime(ScheduleTime.GetTime(), time(0));
	lpInfo->TargetTime = (int)ScheduleTime.GetTime();
}

int CCustomGreatPK::GetState(int index){
	if (index < 0 || index >= MAX_CUSTOM_GREATPK){
		return CUSTOM_GREATPK_STATE_BLANK;
	}
	return this->m_CustomGreatPKInfo[index].State;
}

int CCustomGreatPK::GetRemainTime(int index){
	if (index < 0 || index >= MAX_CUSTOM_GREATPK){
		return 0;
	}
	CUSTOM_GREATPK_INFO* lpInfo = &this->m_CustomGreatPKInfo[index];
	if (lpInfo->StartTime.empty() != 0){
		return 0;
	}
	CTime ScheduleTime;
	CScheduleManager ScheduleManager;
	for (std::vector<CUSTOM_GREATPK_START_TIME>::iterator it = lpInfo->StartTime.begin(); it != lpInfo->StartTime.end(); it++){
		ScheduleManager.AddSchedule(it->Year, it->Month, it->Day, it->Hour, it->Minute, it->Second, it->DayOfWeek);
	}
	if (ScheduleManager.GetSchedule(&ScheduleTime) == 0){
		return 0;
	}
	int RemainTime = (int)difftime(ScheduleTime.GetTime(), time(0));
	return (((RemainTime % 60) == 0) ? (RemainTime / 60) : ((RemainTime / 60) + 1));
}

int CCustomGreatPK::GetEnterEnabled(int index)
{
	if (index < 0 || index >= MAX_CUSTOM_GREATPK){
		return 0;
	}
	return this->m_CustomGreatPKInfo[index].EnterEnabled;
}

int CCustomGreatPK::GetEnteredUserCount(int index){
	if (index < 0 || index >= MAX_CUSTOM_GREATPK){
		return CUSTOM_GREATPK_STATE_BLANK;
	}
	return this->GetUserCount(&this->m_CustomGreatPKInfo[index]);
}

bool CCustomGreatPK::CheckEnteredUser(int index, int aIndex){
	if (index < 0 || index >= MAX_CUSTOM_GREATPK){
		return 0;
	}
	return ((this->GetUser(&this->m_CustomGreatPKInfo[index], aIndex) == 0) ? 0 : 1);
}
bool CCustomGreatPK::CheckReqItems(int index, LPOBJ lpObj)
{
	lpObj->ChaosLock = 1;

	if (this->m_CustomGreatPKInfo[index].RuleInfo.EventItemCount > 0)
	{
		int count = gItemManager.GetInventoryItemCount(lpObj, this->m_CustomGreatPKInfo[index].RuleInfo.EventItemID, 0);

		if (count < this->m_CustomGreatPKInfo[index].RuleInfo.EventItemCount)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(25), this->m_CustomGreatPKInfo[index].RuleInfo.Name, this->m_CustomGreatPKInfo[index].RuleInfo.EventItemCount, gItemManager.GetItemName(this->m_CustomGreatPKInfo[index].RuleInfo.EventItemID));
			return false;
		}

		gItemManager.DeleteInventoryItemCount(lpObj, this->m_CustomGreatPKInfo[index].RuleInfo.EventItemID, 0, this->m_CustomGreatPKInfo[index].RuleInfo.EventItemCount);

	}
	int CheckWC = this->m_CustomGreatPKInfo[index].RuleInfo.mWC;

	if (CheckWC > lpObj->Coin1)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(25), this->m_CustomGreatPKInfo[index].RuleInfo.Name, CheckWC, "WC");
		return false;
	}

	if (CheckWC > 0)
	{
		GDSetCoinSend(lpObj->Index, (CheckWC > 0 ? -CheckWC : 0), 0, 0, "DauTruongTruCoin");
	}
	lpObj->ChaosLock = 0;

	return true;
}
bool CCustomGreatPK::CheckEnterEnabled(LPOBJ lpObj, int gate)
{

	if (OBJECT_RANGE(lpObj->PartyNumber) != 0){
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(7));
		return 0;
	}
	if (lpObj->Guild != 0 && lpObj->Guild->WarState == 1){
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(7));
		return 0;
	}
	if (OBJECT_RANGE(lpObj->DuelUser) != 0){
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(7));
		return 0;
	}
	if (lpObj->PShopOpen != 0){
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(7));
		return 0;
	}

	for (int n = 0; n < MAX_CUSTOM_GREATPK; n++){
		CUSTOM_GREATPK_INFO* lpInfo = &this->m_CustomGreatPKInfo[n];

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
		if (this->CheckReqItems(lpInfo->Index, lpObj) == 0)
		{
			return 0;
		}
		if (this->GetEnterEnabled(lpInfo->Index) == 0)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(8));
			return 0;
		}
		if (this->GetUserCount(lpInfo) >= ((lpInfo->RuleInfo.MaxUser>MAX_CUSTOM_GREATPK_USER) ? MAX_CUSTOM_GREATPK_USER : lpInfo->RuleInfo.MaxUser)){
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
			return 0;
		}

		gEffectManager.ClearAllEffect(lpObj);
		return this->AddUser(lpInfo, lpObj->Index);
	}
	return 1;
}

bool CCustomGreatPK::CheckPlayerJoined(LPOBJ lpObj, LPOBJ lpTarget)
{
	if (lpObj->Index == lpTarget->Index)
	{
		return 0;
	}
	if (this->MapEvent[this->IndexEventHienTai] == lpObj->Map)
	{
		for (int n = 0; n < MAX_CUSTOM_GREATPK; n++)
		{
			if (this->GetState(n) != CUSTOM_GREATPK_STATE_BLANK){
				if (this->CheckEnteredUser(n, lpObj->Index) != 0){
					return 1;
				}
			}
		}
	}

	return 0;
}

bool CCustomGreatPK::CheckPlayerTarget(LPOBJ lpObj, LPOBJ lpTarget){
	if (this->MapEvent[this->IndexEventHienTai] == lpObj->Map)
	{
		for (int n = 0; n < MAX_CUSTOM_GREATPK; n++){
			if (this->GetState(n) == CUSTOM_GREATPK_STATE_START){
				if (this->CheckEnteredUser(n, lpObj->Index) != 0){
					return 1;
				}
			}
		}
	}
	return 0;
}

bool CCustomGreatPK::AddUser(CUSTOM_GREATPK_INFO* lpInfo, int aIndex){
	if (OBJECT_RANGE(aIndex) == 0){
		return 0;
	}
	if (this->GetUser(lpInfo, aIndex) != 0){
		return 0;
	}
	for (int n = 0; n < MAX_CUSTOM_GREATPK_USER; n++)
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
		return 1;
	}
	return 0;
}

bool CCustomGreatPK::DelUser(CUSTOM_GREATPK_INFO* lpInfo, int aIndex){
	if (OBJECT_RANGE(aIndex) == 0){
		return 0;
	}
	CUSTOM_GREATPK_USER* lpUser = this->GetUser(lpInfo, aIndex);
	if (lpUser == 0){
		return 0;
	}
	lpUser->Reset();
	return 1;
}

CUSTOM_GREATPK_USER* CCustomGreatPK::GetUser(CUSTOM_GREATPK_INFO* lpInfo, int aIndex){
	if (OBJECT_RANGE(aIndex) == 0){
		return 0;
	}
	for (int n = 0; n < MAX_CUSTOM_GREATPK_USER; n++){
		if (lpInfo->User[n].Index == aIndex){
			return &lpInfo->User[n];
		}
	}
	return 0;
}

void CCustomGreatPK::CleanUser(CUSTOM_GREATPK_INFO* lpInfo){
	for (int n = 0; n < MAX_CUSTOM_GREATPK_USER; n++){
		lpInfo->User[n].Reset();
	}
}

void CCustomGreatPK::ClearUser(CUSTOM_GREATPK_INFO* lpInfo){
	for (int n = 0; n < MAX_CUSTOM_GREATPK_USER; n++){
		if (OBJECT_RANGE(lpInfo->User[n].Index) == 0){
			continue;
		}
		gObjMoveGate(lpInfo->User[n].Index, lpInfo->RuleInfo.FinalGate);
		lpInfo->User[n].Reset();
	}
}

void CCustomGreatPK::CheckUser(CUSTOM_GREATPK_INFO* lpInfo){
	for (int n = 0; n < MAX_CUSTOM_GREATPK_USER; n++)
	{
		if (OBJECT_RANGE(lpInfo->User[n].Index) == 0){
			continue;
		}
		if (gObjIsConnected(lpInfo->User[n].Index) == 0){
			this->DelUser(lpInfo, lpInfo->User[n].Index);
			continue;
		}

		if (gGate.GetGateMap(lpInfo->RuleInfo.StartGate) != gObj[lpInfo->User[n].Index].Map)
		{
			this->DelUser(lpInfo, lpInfo->User[n].Index);
			continue;
		}
	}
}

int CCustomGreatPK::GetUserCount(CUSTOM_GREATPK_INFO* lpInfo){
	int count = 0;
	for (int n = 0; n < MAX_CUSTOM_GREATPK_USER; n++)
	{
		if (OBJECT_RANGE(lpInfo->User[n].Index) != 0){
			count++;
		}
	}
	return count;
}

void CCustomGreatPK::CalcUserRank(CUSTOM_GREATPK_INFO* lpInfo)
{
	for (int stt = 0; stt < CacheTop; stt++)
	{
		this->mIndexRank[stt] = -1;
	}
	for (int n = 0; n < MAX_CUSTOM_GREATPK_USER; n++)
	{
		if (OBJECT_RANGE(lpInfo->User[n].Index) == 0){
			continue;
		}
		int rank = MAX_CUSTOM_GREATPK_USER;
		for (int i = 0; i < MAX_CUSTOM_GREATPK_USER; i++)
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
		}
	}
}

bool CCustomGreatPK::GetUserRespawnLocation(LPOBJ lpObj, int* gate, int* map, int* x, int* y, int* dir, int* level){

	if (this->MapEvent[this->IndexEventHienTai] != lpObj->Map)
	{
		return 0;
	}
	for (int n = 0; n < MAX_CUSTOM_GREATPK; n++)
	{
		CUSTOM_GREATPK_INFO* lpInfo = &this->m_CustomGreatPKInfo[n];
		if (this->GetState(lpInfo->Index) != CUSTOM_GREATPK_STATE_START)
		{
			continue;
		}

		CUSTOM_GREATPK_USER* lpUser = this->GetUser(lpInfo, lpObj->Index);
		if (lpUser == 0){
			continue;
		}
		if (lpInfo->RuleInfo.MaxDeath != -1 && lpUser->UserDeathCount >= lpInfo->RuleInfo.MaxDeath){
			if (gGate.GetGate(lpInfo->RuleInfo.FinalGate, gate, map, x, y, dir, level) != 0){
				GDRankingCustomGreatPKSaveSend(lpUser->Index, lpInfo->Index, lpUser->Score, 0);
				this->DelUser(lpInfo, lpObj->Index);
				return 1;
			}
		}
		else
		{
			if (gGate.GetGate(lpInfo->RuleInfo.StartGate, gate, map, x, y, dir, level) != 0)
			{
				return 1;
			}
		}
	}
	return 0;
}

bool CCustomGreatPK::UserDieProc(LPOBJ lpObj, LPOBJ lpTarget)
{
	if (this->IndexEventHienTai == -1)
	{
		return 0;
	}
	if (this->MapEvent[this->IndexEventHienTai] != lpObj->Map || this->MapEvent[this->IndexEventHienTai] != lpTarget->Map)
	{
		return 0;
	}
	for (int n = 0; n < MAX_CUSTOM_GREATPK; n++)
	{
		CUSTOM_GREATPK_INFO* lpInfo = &this->m_CustomGreatPKInfo[n];

		if (this->GetState(lpInfo->Index) != CUSTOM_GREATPK_STATE_START)
		{
			continue;
		}
		CUSTOM_GREATPK_USER* lpUserA = this->GetUser(lpInfo, lpObj->Index);
		if (lpUserA == 0){
			return 0;
		}
		CUSTOM_GREATPK_USER* lpUserB = this->GetUser(lpInfo, lpTarget->Index);
		if (lpUserB == 0){
			return 0;
		}
		//
		lpUserA->Score -= ((lpUserA->Score > this->m_CustomGreatPKVictimScoreDecrease) ? this->m_CustomGreatPKVictimScoreDecrease : lpUserA->Score);
		lpUserA->UserKillStreak = 0;
		lpUserA->UserDeathCount++;
		lpUserA->UserDeathStreak++;
		//==Nguoi Giet
		lpUserB->Score += this->m_CustomGreatPKKillerScoreIncrease;
		lpUserB->UserKillCount++;
		lpUserB->UserKillStreak++;
		lpUserB->UserDeathStreak = 0;
		//
		gItemBagManager.DropItemBySpecialValue(ITEM_BAG_GREATPK_DONE, lpTarget, lpObj->Map, lpObj->X, lpObj->Y);
		//	
		this->CalcUserRank(lpInfo);
	}
	return 1;
}

void CCustomGreatPK::NoticeSendToAll(CUSTOM_GREATPK_INFO* lpInfo, int type, char* message, ...){
	char buff[256];
	va_list arg;
	va_start(arg, message);
	vsprintf_s(buff, message, arg);
	va_end(arg);
	for (int n = 0; n < MAX_CUSTOM_GREATPK_USER; n++){
		if (OBJECT_RANGE(lpInfo->User[n].Index) != 0){
			gNotice.GCNoticeSend(lpInfo->User[n].Index, type, 0, 0, 0, 0, 0, buff);
		}
	}
}

void CCustomGreatPK::DataSendToAll(CUSTOM_GREATPK_INFO* lpInfo, BYTE* lpMsg, int size){
	for (int n = 0; n < MAX_CUSTOM_GREATPK_USER; n++){
		if (OBJECT_RANGE(lpInfo->User[n].Index) != 0)
		{
			DataSend(lpInfo->User[n].Index, lpMsg, size);
		}
	}
}

void CCustomGreatPK::StartCustomGreatPK(int index){
	CTime CurrentTime = CTime::GetTickCount();
	int hour = (int)CurrentTime.GetHour();
	int minute = (int)CurrentTime.GetMinute() + 2;
	if (minute >= 60){
		hour++;
		minute = minute - 60;
	}
	CUSTOM_GREATPK_START_TIME info;
	info.Year = (int)CurrentTime.GetYear();
	info.Month = (int)CurrentTime.GetMonth();
	info.Day = (int)CurrentTime.GetDay();
	info.DayOfWeek = -1;
	info.Hour = hour;
	info.Minute = minute;
	info.Second = 0;

	this->m_CustomGreatPKInfo[0].StartTime.push_back(info);
	LogAdd(LOG_EVENT, "[Set GreatPK Event Start] At %2d:%2d:00", hour, minute);
	this->SetState(&this->m_CustomGreatPKInfo[0], CUSTOM_GREATPK_STATE_EMPTY);
}

char* CCustomGreatPK::GetArenaName(int index){
	return this->m_CustomGreatPKInfo[index].RuleInfo.Name;
}


void CCustomGreatPK::SendUserInfoEvent(CUSTOM_GREATPK_INFO* lpInfo)
{
	for (int n = 0; n < MAX_CUSTOM_GREATPK_USER; n++)
	{
		if (OBJECT_RANGE(lpInfo->User[n].Index) != 0)
		{
			//===========Send Info
			GREATPKEVENT_INFO pMsg;
			pMsg.header.set(0xD3, 0x34, sizeof(pMsg));
			pMsg.Rank = (WORD)lpInfo->User[n].Rank;
			pMsg.Score = (WORD)lpInfo->User[n].Score;//Diem
			pMsg.State = (BYTE)lpInfo->State;
			pMsg.Time = (DWORD)lpInfo->RemainTime;//Time
			DataSend(lpInfo->User[n].Index, (BYTE*)& pMsg, pMsg.header.size);
			//===
		}
	}
}

//===Get List > Send Client
void CCustomGreatPK::SendBXHInfo(int aIndex)
{
	if (!this->m_CustomGreatPKSwitch || this->IndexEventHienTai == -1)
	{
		return;
	}

	if (gObjIsConnected(aIndex) == false)
	{
		return;
	}
	CUSTOM_GREATPK_INFO* lpInfo = &this->m_CustomGreatPKInfo[this->IndexEventHienTai];

	this->CalcUserRank(lpInfo);

	BYTE send[4096];

	RECVGREATPKEVENT_BXH pMsg;

	pMsg.header.set(0xD3, 0x35, 0);

	int size = sizeof(pMsg);

	pMsg.Count = 0;

	GREATPKEVENT_BXH info;


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