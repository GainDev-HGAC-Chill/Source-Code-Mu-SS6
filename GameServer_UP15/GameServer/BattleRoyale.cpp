#include "stdafx.h"
#include "BattleRoyale.h"
#include "Guild.h"
#include "EffectManager.h"
#include "Notice.h"
#include "ObjectManager.h"
#include "CashShop.h"
#include "Gate.h"
#include "ScheduleManager.h"
#include "MemScript.h"
#include "DSProtocol.h"
#include "ItemManager.h"
#include "Message.h"
#include "ServerInfo.h"
#include "Util.h"
#include "MonsterSetBase.h"
#include "ItemBagManager.h"


CBattleRoyale gBattleRoyale;

CBattleRoyale::CBattleRoyale()
{
	this->m_TickCount = GetTickCount();
	this->m_State = 0;
	this->m_RemainTime = 0;
	this->m_StandTime = 0;
	this->m_CloseTime = 0;
	this->m_TickCount = 0;
	this->m_WarningTime = 0;
	this->m_EventTime = 0;

	this->TotalPlayer = 0;
	for (int n = 0; n < 3; n++)
	{
		this->Coin1[n] = 0;
		this->Coin2[n] = 0;
		this->Coin3[n] = 0;
		this->Bag[n] = 0;
	}

	this->CleanUser();

}

CBattleRoyale::~CBattleRoyale()
{

}

void CBattleRoyale::Init()
{
	if (this->m_BattleRoyaleEnable == 0)
	{
		this->SetState(ROYAL_STATE_BLANK);
	}
	else
	{
		this->SetState(ROYAL_STATE_EMPTY);
	}
}
void CBattleRoyale::ClearConfigCache()
{
	this->m_TickCount = GetTickCount();
	this->m_State = 0;
	this->m_RemainTime = 0;
	this->m_StandTime = 0;
	this->m_CloseTime = 0;
	this->m_TickCount = 0;
	this->m_WarningTime = 0;
	this->m_EventTime = 0;



	this->TotalPlayer = 0;

	for (int n = 0; n < 3; n++)
	{
		this->Coin1[n] = 0;
		this->Coin2[n] = 0;
		this->Coin3[n] = 0;
		this->Bag[n] = 0;
	}

	this->CleanUser();

	//===Mess Clear
	this->m_MessageInfoBP.clear();
	this->m_BattleRoyaleStartTime.clear();
	this->m_BattleRoyale_Items.clear();
	this->m_BattleRoyaleEnable = 0;
	this->m_BattleRoyaleNPC = 0;
	this->m_BattleRoyaleNPCMap = 0;
	this->m_BattleRoyaleNPCX = 0;
	this->m_BattleRoyaleNPCY = 0;
	this->m_BattleRoyaleNPCDir = 0;
	this->BonusKill[0] = 0;
	this->BonusKill[1] = 0;
	this->BonusKill[2] = 0;
	this->ItemBag = 0;
	for (int stt = 0; stt < 10; stt++)
	{
		this->mIndexRank[stt] = -1;
	}
}
void CBattleRoyale::Clear()
{

	this->TotalPlayer = 0;

	this->CleanUser();
}

void CBattleRoyale::SetNPC()
{
	if (this->m_BattleRoyaleEnable)
	{
		MONSTER_SET_BASE_INFO info;
		memset(&info, 0, sizeof(info));

		info.Type = 0;
		info.MonsterClass = gBattleRoyale.m_BattleRoyaleNPC;
		info.Map = gBattleRoyale.m_BattleRoyaleNPCMap;
		info.Dis = 0;
		info.Dir = gBattleRoyale.m_BattleRoyaleNPCDir;
		info.X = gBattleRoyale.m_BattleRoyaleNPCX;
		info.Y = gBattleRoyale.m_BattleRoyaleNPCY;

		gMonsterSetBase.SetInfo(info);
	}
}
void CBattleRoyale::Load(char* FilePath)
{

	//Clear
	this->ClearConfigCache();
	//=============


	pugi::xml_document file;
	pugi::xml_parse_result res = file.load_file(FilePath);
	if (res.status != pugi::status_ok) {
		ErrorMessageBox("File %s load fail. Error: %s", FilePath, res.description());
		return;
	}

	//--
	pugi::xml_node oBattleRoyale = file.child("BattleRoyale");
	//--
	//==== Load Time
	pugi::xml_node eBattleRoyaleTime = oBattleRoyale.child("EventTime");
	for (pugi::xml_node rBattleRoyaleTime = eBattleRoyaleTime.child("Time"); rBattleRoyaleTime; rBattleRoyaleTime = rBattleRoyaleTime.next_sibling())
	{
		BATTLEROYALE_TIME info;
		info.Year = rBattleRoyaleTime.attribute("Year").as_int();
		info.Month = rBattleRoyaleTime.attribute("Month").as_int();
		info.Day = rBattleRoyaleTime.attribute("Day").as_int();
		info.DayOfWeek = rBattleRoyaleTime.attribute("DayOfWeek").as_int();
		info.Hour = rBattleRoyaleTime.attribute("Hour").as_int();
		info.Minute = rBattleRoyaleTime.attribute("Minute").as_int();
		info.Second = rBattleRoyaleTime.attribute("Second").as_int();
		this->m_BattleRoyaleStartTime.push_back(info);
	}
	//-Config
	pugi::xml_node eEvenNPC = oBattleRoyale.child("EvenNPC");
	this->m_BattleRoyaleEnable = eEvenNPC.attribute("EnabledEvent").as_int();
	this->m_BattleRoyaleNPC = eEvenNPC.attribute("NPCClass").as_int();
	this->m_BattleRoyaleNPCMap = eEvenNPC.attribute("NPCMap").as_int();
	this->m_BattleRoyaleNPCX = eEvenNPC.attribute("NPCX").as_int();
	this->m_BattleRoyaleNPCY = eEvenNPC.attribute("NPCY").as_int();
	this->m_BattleRoyaleNPCDir = eEvenNPC.attribute("NPCDir").as_int();

	//-Config Time
	pugi::xml_node eEventStage = oBattleRoyale.child("EventStage");
	this->m_WarningTime = eEventStage.attribute("WarningTime").as_int();
	this->m_StandTime = eEventStage.attribute("StandTime").as_int();
	this->m_EventTime = eEventStage.attribute("EventTime").as_int();
	this->m_CloseTime = eEventStage.attribute("CloseTime").as_int();

	//-Config All
	pugi::xml_node eEvenConfigAll = oBattleRoyale.child("EventConfig");
	this->EventMap = eEvenConfigAll.attribute("EventMap").as_int();
	this->WaitingGate = eEvenConfigAll.attribute("WaitingGate").as_int();
	this->EventGate = eEvenConfigAll.attribute("EventGate").as_int();
	this->SetSkin = eEvenConfigAll.attribute("SetSkin").as_int();

	this->m_Point = eEvenConfigAll.attribute("LevelUpPoint").as_int();
	this->m_MaxDie = eEvenConfigAll.attribute("MaxDie").as_int();

	this->m_BattleRoyaleMinUsers = eEvenConfigAll.attribute("MinUser").as_int();
	this->m_BattleRoyaleMaxUsers = eEvenConfigAll.attribute("MaxUser").as_int();
	if (this->m_BattleRoyaleMaxUsers > MAX_BATTLEROYALE_USER) { this->m_BattleRoyaleMaxUsers = MAX_BATTLEROYALE_USER; }

	//-Config Yeu Cau
	pugi::xml_node eEventYeuCau = oBattleRoyale.child("EventYeuCau");
	this->ReqZen = eEventYeuCau.attribute("ReqZen").as_int();
	this->ReqWC = eEventYeuCau.attribute("ReqWC").as_int();
	this->ReqWP = eEventYeuCau.attribute("ReqWP").as_int();
	this->ReqGP = eEventYeuCau.attribute("ReqGP").as_int();
	this->ReqItemIndex = eEventYeuCau.attribute("ReqItemIndex").as_int();
	this->ReqItemLevel = eEventYeuCau.attribute("ReqItemLevel").as_int();
	this->ReqItemCount = eEventYeuCau.attribute("ReqItemCount").as_int();
	this->MinLevel = eEventYeuCau.attribute("MinLevel").as_int();
	this->MaxLevel = eEventYeuCau.attribute("MaxLevel").as_int();
	this->MinReset = eEventYeuCau.attribute("MinReset").as_int();
	this->MaxReset = eEventYeuCau.attribute("MaxReset").as_int();
	this->MinMasterReset = eEventYeuCau.attribute("MinMasterReset").as_int();
	this->MaxMasterReset = eEventYeuCau.attribute("MaxMasterReset").as_int();
	//-Config Phan Thuong Khi Kill
	pugi::xml_node eEventRewardKill = oBattleRoyale.child("EventRewardKill");
	this->BonusKill[0] = eEventRewardKill.attribute("WC").as_int();
	this->BonusKill[1] = eEventRewardKill.attribute("WP").as_int();
	this->BonusKill[2] = eEventRewardKill.attribute("GP").as_int();
	this->ItemBag = eEventRewardKill.attribute("ItemBag").as_int();
	//-Config Phan Thuong top 1
	pugi::xml_node eEventRewardTeam = oBattleRoyale.child("Top1");
	this->Coin1[0] = eEventRewardTeam.attribute("WC").as_int();
	this->Coin2[0] = eEventRewardTeam.attribute("WP").as_int();
	this->Coin3[0] = eEventRewardTeam.attribute("GP").as_int();
	this->Bag[0] = eEventRewardTeam.attribute("ItemBag").as_int();
	//============

	//-Config Phan Thuong top 2
	pugi::xml_node eEventRewardTeam1 = oBattleRoyale.child("Top2");
	this->Coin1[1] = eEventRewardTeam1.attribute("WC").as_int();
	this->Coin2[1] = eEventRewardTeam1.attribute("WP").as_int();
	this->Coin3[1] = eEventRewardTeam1.attribute("GP").as_int();
	this->Bag[1] = eEventRewardTeam1.attribute("ItemBag").as_int();
	//============

	//-Config Phan Thuong top 3
	pugi::xml_node eEventRewardTeam2 = oBattleRoyale.child("Top3");
	this->Coin1[2] = eEventRewardTeam2.attribute("WC").as_int();
	this->Coin2[2] = eEventRewardTeam2.attribute("WP").as_int();
	this->Coin3[2] = eEventRewardTeam2.attribute("GP").as_int();
	this->Bag[2] = eEventRewardTeam2.attribute("ItemBag").as_int();
	//============


	//-Config set zone drop item
	pugi::xml_node eEventConfigZone = oBattleRoyale.child("ConfigZone");
	this->S_SetZone[0] = eEventConfigZone.attribute("BeginX").as_int();
	this->S_SetZone[1] = eEventConfigZone.attribute("BeginY").as_int();
	this->S_SetZone[2] = eEventConfigZone.attribute("EndX").as_int();
	this->S_SetZone[3] = eEventConfigZone.attribute("EndY").as_int();

	this->DelayDrop = eEventConfigZone.attribute("DelayDrop").as_int();
	this->DropCount = eEventConfigZone.attribute("DropCount").as_int();
	//============


	//==== Load Item
	pugi::xml_node eBattleRoyaleItem = oBattleRoyale.child("DropItem");
	for (pugi::xml_node rBattleRoyaleItem = eBattleRoyaleItem.child("Item"); rBattleRoyaleItem; rBattleRoyaleItem = rBattleRoyaleItem.next_sibling())
	{
		BATTLEROYALE_ITEM info;
		info.Index = SafeGetItem(GET_ITEM(rBattleRoyaleItem.attribute("Type").as_int(), rBattleRoyaleItem.attribute("Index").as_int()));
		//info.Index = rBattleRoyaleItem.attribute("Index").as_int();
		info.Level = rBattleRoyaleItem.attribute("Level").as_int();
		info.Skill = rBattleRoyaleItem.attribute("Skill").as_int();
		info.Luck = rBattleRoyaleItem.attribute("Luck").as_int();
		info.Opt = rBattleRoyaleItem.attribute("Opt").as_int();
		info.Exc = rBattleRoyaleItem.attribute("Exc").as_int();
		info.Anc = rBattleRoyaleItem.attribute("Anc").as_int();
		info.Socket[0] = rBattleRoyaleItem.attribute("SK1").as_int();
		info.Socket[1] = rBattleRoyaleItem.attribute("SK2").as_int();
		info.Socket[2] = rBattleRoyaleItem.attribute("SK3").as_int();
		info.Socket[3] = rBattleRoyaleItem.attribute("SK4").as_int();
		info.Socket[4] = rBattleRoyaleItem.attribute("SK5").as_int();
		info.SocketBonus = rBattleRoyaleItem.attribute("SocketBonus").as_int();
		this->m_BattleRoyale_Items.push_back(info);
	}


	pugi::xml_node Message = oBattleRoyale.child("MessageInfo");
	for (pugi::xml_node msg = Message.child("Message"); msg; msg = msg.next_sibling())
	{
		MESSAGE_INFO_ROYAL info;

		info.Index = msg.attribute("Index").as_int();

		strcpy_s(info.Message, msg.attribute("Text").as_string());

		this->m_MessageInfoBP.insert(std::pair<int, MESSAGE_INFO_ROYAL>(info.Index, info));
	}

	this->Init();

	LogAdd(LOG_BLUE, "[EventBattleRoyale] On: %d UserMinMax (%d/%d), MapEvent %d Time %d", this->m_BattleRoyaleEnable, this->m_BattleRoyaleMinUsers, this->m_BattleRoyaleMaxUsers, this->EventMap, this->m_BattleRoyaleStartTime.size());
}


char* CBattleRoyale::GetMessage(int index) // OK
{
	std::map<int, MESSAGE_INFO_ROYAL>::iterator it = this->m_MessageInfoBP.find(index);

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
void CBattleRoyale::MainProc()
{
	if ((GetTickCount() - this->m_TickCount) >= 1000)
	{
		this->m_TickCount = GetTickCount();

		this->m_RemainTime = (int)difftime(this->TargetTime, time(0));

		if (this->m_BattleRoyaleEnable == 0)
		{
			if (gServerDisplayer.EventBattleRoyale != -1)
			{
				gServerDisplayer.EventBattleRoyale = -1;
			}
		}
		else
		{
			if (this->m_State == ROYAL_STATE_EMPTY)
			{
				gServerDisplayer.EventBattleRoyale = this->m_RemainTime;
			}
			else
			{
				if (gServerDisplayer.EventBattleRoyale != 0)
				{
					gServerDisplayer.EventBattleRoyale = 0;
				}
			}
		}

		//LogAdd(LOG_BLUE, "State %d ~ remain Time %d ", this->m_State, this->m_RemainTime);

		if (this->m_State >= ROYAL_STATE_EMPTY)
		{

			this->SendTimeEventAll(this->m_RemainTime, this->m_State);
		}


		switch (this->m_State)
		{
		case ROYAL_STATE_BLANK:
			this->ProcState_BLANK();
			break;
		case ROYAL_STATE_EMPTY:
			this->ProcState_EMPTY();
			break;
		case ROYAL_STATE_STAND:
			this->ProcState_STAND();
			break;
		case ROYAL_STATE_START:
			this->ProcState_START();
			break;
		case ROYAL_STATE_CLEAN:
			this->ProcState_CLEAN();
			break;
		}
	}
}

void CBattleRoyale::ProcState_BLANK() // OK
{

}

void CBattleRoyale::ProcState_EMPTY() // OK
{
	if (this->m_RemainTime > 0 && this->m_RemainTime <= (this->m_WarningTime * 60))
	{
		this->CheckUser();

		this->EnterEnabled = 1;

		if ((this->AlarmMinSave = (((this->m_RemainTime % 60) == 0) ? ((this->m_RemainTime / 60) - 1) : (this->m_RemainTime / 60))) != this->AlarmMinLeft)
		{
			this->AlarmMinLeft = this->AlarmMinSave;

			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, this->GetMessage(0), (this->AlarmMinLeft + 1));
			//gNotice.GCNoticeSendToAll(0,0,0,0,0,0,gMessage.GetMessage(826));
		}
	}

	if (this->m_RemainTime <= 0)
	{
		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, this->GetMessage(2));
		this->NoticeSendToAll(1, this->GetMessage(3), this->m_StandTime);
		this->SetState(ROYAL_STATE_STAND);
	}
}

void CBattleRoyale::ProcState_STAND() // OK
{
	this->CheckUser();

	if (this->m_RemainTime <= 0)
	{
		if (this->TotalPlayer >= this->m_BattleRoyaleMinUsers)
		{

			for (int n = 0; n<MAX_BATTLEROYALE_USER; n++)
			{
				gObjMoveGate(this->User[n].Index, this->EventGate);

				if (this->SetSkin == 1)
				{
					gObj[this->User[n].Index].Change = 405;
				}

				gObjViewportListProtocolCreate(&gObj[this->User[n].Index]);
				gObjectManager.CharacterUpdateMapEffect(&gObj[this->User[n].Index]);

			}
			this->NoticeSendToAll(0, this->GetMessage(4));
			this->SetState(ROYAL_STATE_START);
		}
		else
		{
			this->NoticeSendToAll(0, this->GetMessage(1));
			this->SetState(ROYAL_STATE_EMPTY);
		}
	}
}

void CBattleRoyale::ProcState_START() // OK
{
	this->CheckUser();

	if (this->GetUserCount() == 0)
	{
		this->SetState(ROYAL_STATE_EMPTY);
		return;
	}

	if (this->GetUserCount() == 1)
	{
		this->SetState(ROYAL_STATE_CLEAN);
		return;
	}

	if (this->m_RemainTime <= 0)
	{
		this->NoticeSendToAll(0, this->GetMessage(5));
		this->SetState(ROYAL_STATE_CLEAN);
		this->m_PhaseLastDrop = GetTickCount();
		this->m_PhaseDropDelay = 999999;
		this->m_PhaseDropCount = 0;
	}
	this->MakeDropItem();
}

void CBattleRoyale::ProcState_CLEAN() // OK
{
	this->CheckUser();

	if (this->m_RemainTime <= 0)
	{
		this->SetState(ROYAL_STATE_EMPTY);
	}
}

void CBattleRoyale::SetState(int state) // OK
{
	switch ((this->m_State = state))
	{
	case ROYAL_STATE_BLANK:
		this->SetState_BLANK();
		break;
	case ROYAL_STATE_EMPTY:
		this->SetState_EMPTY();
		break;
	case ROYAL_STATE_STAND:
		this->SetState_STAND();
		break;
	case ROYAL_STATE_START:
		this->SetState_START();
		break;
	case ROYAL_STATE_CLEAN:
		this->SetState_CLEAN();
		break;
	}
}

void CBattleRoyale::SetState_BLANK() // OK
{

}

void CBattleRoyale::SetState_EMPTY() // OK
{
	this->EnterEnabled = 0;
	this->AlarmMinSave = -1;
	this->AlarmMinLeft = -1;

	this->ClearUser();

	this->CheckSync();
	this->m_PhaseLastDrop = GetTickCount();
	this->m_PhaseDropDelay = 999999;
	this->m_PhaseDropCount = 0;
}

void CBattleRoyale::SetState_STAND() // OK
{
	this->EnterEnabled = 0;
	this->AlarmMinSave = -1;
	this->AlarmMinLeft = -1;
	this->SetZone(this->S_SetZone[0], this->S_SetZone[1], this->S_SetZone[2], this->S_SetZone[3]);
	this->m_RemainTime = this->m_StandTime * 60;
	this->TargetTime = (int)(time(0) + this->m_RemainTime);
}

void CBattleRoyale::SetState_START() // OK
{
	this->EnterEnabled = 0;
	this->AlarmMinSave = -1;
	this->AlarmMinLeft = -1;

	this->m_RemainTime = this->m_EventTime * 60;

	this->m_PhaseLastDrop = GetTickCount();
	this->m_PhaseDropDelay = this->DelayDrop;
	this->m_PhaseDropCount = this->DropCount;

	this->SendTimeEventAll(this->m_RemainTime, this->m_State);

	this->TargetTime = (int)(time(0) + this->m_RemainTime);
}

void CBattleRoyale::SendTimeEventAll(int time, int State)
{

	for (int n = 0; n < MAX_BATTLEROYALE_USER; n++)
	{
		if (OBJECT_RANGE(this->User[n].Index) != 0)
		{
			PMSG_BATTLEROYALE_CUSTOM pMsg;
			pMsg.h.set(0xFB, 0x66, sizeof(pMsg));
			pMsg.Map = this->EventMap;
			pMsg.TimeCount = (DWORD)this->m_RemainTime;
			pMsg.State = State;
			pMsg.Giet = this->User[n].Kills;
			pMsg.Chet = this->User[n].Deaths;
			DataSend(this->User[n].Index, (LPBYTE)& pMsg, pMsg.h.size);
		}

	}
}


void CBattleRoyale::SetState_CLEAN() // OK
{
	this->EnterEnabled = 0;
	this->AlarmMinSave = -1;
	this->AlarmMinLeft = -1;
	this->m_RemainTime = this->m_CloseTime * 60;
	this->TargetTime = (int)(time(0) + this->m_RemainTime);

	this->CalcUserRank();

	for (int n = 0; n < MAX_BATTLEROYALE_USER; n++)
	{
		if (OBJECT_RANGE(this->User[n].Index) != 0)
		{




			int Top = User[n].Rank;

			LPOBJ lpObj = &gObj[this->User[n].Index];

			switch (Top)
			{
			case 1: //Trao Thuong Top 1
			{
						if (this->Coin1[0] > 0 || this->Coin2[0] > 0 || this->Coin3[0] > 0)
						{
							GDSetCoinSend(lpObj->Index, this->Coin1[0], this->Coin2[0], this->Coin3[0], "BattleRoyale Top 1");
							gCashShop.CGCashShopPointRecv(lpObj->Index);
						}
						if (this->Bag[0] > 0)
						{
							gItemBagManager.DropItemByIndexItemBag(this->Bag[0], lpObj); //Gui Item cho NV
						}
						gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, this->GetMessage(10), gObj[User[n].Index].Name, this->User[n].Rank);
			}
				break;
			case 2: //Trao Thuong Top 2
			{
						if (this->Coin1[1] > 0 || this->Coin2[1] > 0 || this->Coin3[1] > 0)
						{
							GDSetCoinSend(lpObj->Index, this->Coin1[1], this->Coin2[1], this->Coin3[1], "BattleRoyale Top 2");
							gCashShop.CGCashShopPointRecv(lpObj->Index);
						}
						if (this->Bag[1] > 0)
						{
							gItemBagManager.DropItemByIndexItemBag(this->Bag[1], lpObj); //Gui Item cho NV
						}
						gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, this->GetMessage(10), gObj[User[n].Index].Name, this->User[n].Rank);
			}
				break;
			case 3: //Trao Thuong Top 3
			{
						if (this->Coin1[2] > 0 || this->Coin2[2] > 0 || this->Coin3[2] > 0)
						{
							GDSetCoinSend(lpObj->Index, this->Coin1[2], this->Coin2[2], this->Coin3[2], "BattleRoyale Top 3");
							gCashShop.CGCashShopPointRecv(lpObj->Index);
						}
						if (this->Bag[2] > 0)
						{
							gItemBagManager.DropItemByIndexItemBag(this->Bag[2], lpObj); //Gui Item cho NV
						}
						gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, this->GetMessage(10), gObj[User[n].Index].Name, this->User[n].Rank);
			}
				break;
			}
		}

	}

}

void CBattleRoyale::CheckSync() // OK
{
	if (this->m_BattleRoyaleStartTime.empty() != 0)
	{
		this->SetState(ROYAL_STATE_BLANK);
		return;
	}

	CTime ScheduleTime;

	CScheduleManager ScheduleManager;

	for (std::vector<BATTLEROYALE_TIME>::iterator it = this->m_BattleRoyaleStartTime.begin(); it != this->m_BattleRoyaleStartTime.end(); it++)
	{
		ScheduleManager.AddSchedule(it->Year, it->Month, it->Day, it->Hour, it->Minute, it->Second, it->DayOfWeek);
	}

	if (ScheduleManager.GetSchedule(&ScheduleTime) == 0)
	{
		this->SetState(ROYAL_STATE_BLANK);
		return;
	}

	this->m_RemainTime = (int)difftime(ScheduleTime.GetTime(), time(0));

	this->TargetTime = (int)ScheduleTime.GetTime();
}

int CBattleRoyale::GetState() // OK
{
	return this->m_State;
}

bool CBattleRoyale::Dialog(LPOBJ lpObj, LPOBJ lpNpc)
{
	if (!this->m_BattleRoyaleEnable) return false;

	if (lpNpc->Class == this->m_BattleRoyaleNPC &&
		lpNpc->Map == this->m_BattleRoyaleNPCMap &&
		lpNpc->X == this->m_BattleRoyaleNPCX &&
		lpNpc->Y == this->m_BattleRoyaleNPCY)
	{
		XULY_CGPACKET2 pMsg;
		pMsg.header.set(0xFB, 0x65, sizeof(pMsg));
		pMsg.ThaoTac = 1;
		DataSend(lpObj->Index, (BYTE*)& pMsg, pMsg.header.size);
		//this->AddUser(lpObj->Index);

		return 1;
	}

	return false;
}

void CBattleRoyale::CGOpenWindowNPC(XULY_CGPACKET2* aRecv, int aIndex)
{
	//LogAdd(LOG_RED, "DEBUG CGOpenWindowNPC");
	if (!this->m_BattleRoyaleEnable)
	{
		return;
	}
	if (gObjIsConnectedGP(aIndex) == 0)
	{
		return;
	}

	LPOBJ lpObj = &gObj[aIndex];

	if ((GetTickCount() - lpObj->ClickClientSend) < 2000)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(963));
		return;
	}
	//=== Send Client Open Windows
	if (!this->CheckEnterEnabled(lpObj))
	{
		return;
	}
	//=== Send Time & Stage ve Client

	lpObj->ClickClientSend = GetTickCount();
	return;
}
bool CBattleRoyale::CheckEnterEnabled(LPOBJ lpObj)
{
	if (this->GetEnterEnabled() == 0)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(7));
		return 0;
	}
	if (OBJECT_RANGE(lpObj->PartyNumber) != 0)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(6));
		return 0;
	}

	if (lpObj->Guild != 0 && lpObj->Guild->WarState == 1)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(6));
		return 0;
	}

	if (OBJECT_RANGE(lpObj->DuelUser) != 0)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(6));
		return 0;
	}

	if (lpObj->PShopOpen != 0)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(6));
		return 0;
	}

	if (this->GetUserCount() >= this->m_BattleRoyaleMaxUsers)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(6));
		return 0;
	}

	if (this->MinLevel != -1 && this->MinLevel > lpObj->Level)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(224), this->MinLevel);
		return 0;
	}

	if (this->MaxLevel != -1 && this->MaxLevel < lpObj->Level)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(230), this->MaxLevel);
		return 0;
	}

	if (this->MinReset != -1 && this->MinReset > lpObj->Reset)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(231), this->MinReset);
		return 0;
	}

	if (this->MaxReset != -1 && this->MaxReset < lpObj->Reset)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(232), this->MaxReset);
		return 0;
	}

	if (this->MinMasterReset != -1 && this->MinMasterReset > lpObj->MasterReset)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(818), this->MinMasterReset);
		return 0;
	}

	if (this->MaxMasterReset != -1 && this->MaxMasterReset < lpObj->MasterReset)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(819), this->MaxMasterReset);
		return 0;
	}

	if (this->CheckReqItems(lpObj) == 0)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(8));
		return 0;
	}

	gEffectManager.ClearAllEffect(lpObj);


	return this->AddUser(lpObj->Index);
}

bool CBattleRoyale::CheckReqItems(LPOBJ lpObj)
{

	if (lpObj->Money < this->ReqZen)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(9));
		return false;
	}
	lpObj->Money -= this->ReqZen;
	GCMoneySend(lpObj->Index, lpObj->Money);

	if (lpObj->Coin1 < this->ReqWC || lpObj->Coin2 < this->ReqWP || lpObj->Coin3 < this->ReqGP)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(9));
		return false;
	}
	if (this->ReqWC > 0 || this->ReqWP > 0 || this->ReqGP > 0)
	{
		GDSetCoinSend(lpObj->Index, -(this->ReqWC), -(this->ReqWP), -(this->ReqGP), "TruCoinBattleRoyal");
		gCashShop.CGCashShopPointRecv(lpObj->Index);
	}

	lpObj->ChaosLock = 1;

	int count = gItemManager.GetInventoryItemCount(lpObj, this->ReqItemIndex, this->ReqItemLevel);

	if (count < this->ReqItemCount)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(8));
		return false;
	}

	gItemManager.DeleteInventoryItemCount(lpObj, this->ReqItemIndex, this->ReqItemLevel, this->ReqItemCount);

	lpObj->ChaosLock = 0;
	return true;
}

int CBattleRoyale::GetEnterEnabled() // OK
{
	return this->EnterEnabled;
}

int CBattleRoyale::GetEnteredUserCount() // OK
{
	return this->GetUserCount();
}

bool CBattleRoyale::CheckEnteredUser(int aIndex) // OK
{
	return ((this->GetUser(aIndex) == 0) ? 0 : 1);
}

bool CBattleRoyale::CheckPlayerTarget(LPOBJ lpObj) // OK
{
	if (this->GetState() == ROYAL_STATE_START)
	{
		if (this->EventMap == lpObj->Map)
		{
			if (this->CheckEnteredUser(lpObj->Index) != 0)
			{
				return 1;
			}
		}
	}
	return 0;
}

bool CBattleRoyale::CheckPlayerJoined(LPOBJ lpObj, LPOBJ lpTarget) // OK
{
	if (this->GetState() != ROYAL_STATE_BLANK)
	{
		if (this->EventMap == lpObj->Map)
		{
			if (this->CheckEnteredUser(lpObj->Index) != 0)
			{
				return 1;
			}
		}
	}
	return 0;

}



bool CBattleRoyale::AddUser(int aIndex) // OK
{
	if (OBJECT_RANGE(aIndex) == 0)
	{
		return 0;
	}

	if (this->GetUser(aIndex) != 0)
	{
		return 0;
	}

	for (int n = 0; n < MAX_BATTLEROYALE_USER; n++)
	{
		if (OBJECT_RANGE(this->User[n].Index) != 0)
		{
			continue;
		}
		this->BackupAddUser(aIndex);
		this->ChangeUserInfo(aIndex);
		this->User[n].Index = aIndex;
		this->User[n].Available = 1;
		this->TotalPlayer++;
		gObjMoveGate(aIndex, this->WaitingGate);
		return 1;
	}
	return 0;
}

bool CBattleRoyale::DelUser(int aIndex) // OK
{
	if (OBJECT_RANGE(aIndex) == 0)
	{
		return 0;
	}

	BATTLEROYALE_EVENT_USER* lpUser = this->GetUser(aIndex);

	if (lpUser == 0)
	{
		return 0;
	}


	lpUser->Reset();
	this->TotalPlayer--;
	return 1;
}

BATTLEROYALE_EVENT_USER* CBattleRoyale::GetUser(int aIndex) // OK
{
	if (OBJECT_RANGE(aIndex) == 0)
	{
		return 0;
	}

	for (int n = 0; n < MAX_BATTLEROYALE_USER; n++)
	{
		if (this->User[n].Index == aIndex)
		{
			return &this->User[n];
		}
	}
	return 0;
}

void CBattleRoyale::CleanUser() // OK
{
	for (int n = 0; n < MAX_BATTLEROYALE_USER; n++)
	{
		this->User[n].Reset();
		this->TotalPlayer = 0;
	}
}

void CBattleRoyale::ClearUser() // OK
{
	for (int n = 0; n < MAX_BATTLEROYALE_USER; n++)
	{
		if (OBJECT_RANGE(this->User[n].Index) == 0)
		{
			continue;
		}

		gObjMoveGate(this->User[n].Index, 17);

		if (this->SetSkin == 1)
		{
			gObj[this->User[n].Index].Change = -1;
		}
		this->RollBackCharacterInfo(this->User[n].Index);
		this->BackupDelUser(this->User[n].Index);
		gObjViewportListProtocolCreate(&gObj[this->User[n].Index]);
		gObjectManager.CharacterUpdateMapEffect(&gObj[this->User[n].Index]);

		this->User[n].Reset();

		this->TotalPlayer--;
	}
}

void CBattleRoyale::CheckUser() // OK
{
	for (int n = 0; n < MAX_BATTLEROYALE_USER; n++)
	{
		if (OBJECT_RANGE(this->User[n].Index) == 0)
		{
			continue;
		}

		if (gObjIsConnected(this->User[n].Index) == 0)
		{
			this->DelUser(this->User[n].Index);
			continue;
		}

		if (gObj[this->User[n].Index].Map != this->EventMap)
		{
			this->DelUser(this->User[n].Index);
			continue;
		}
	}
}

int CBattleRoyale::GetUserCount() // OK
{
	int count = 0;

	for (int n = 0; n < MAX_BATTLEROYALE_USER; n++)
	{
		if (OBJECT_RANGE(this->User[n].Index) != 0)
		{
			count++;
		}
	}

	return count;
}

bool CBattleRoyale::GetUserRespawnLocation(LPOBJ lpObj, int* gate, int* map, int* x, int* y, int* dir, int* level) // OK
{
	if (this->m_BattleRoyaleEnable == 0)
	{
		return 0;
	}

	if (this->GetState() != ROYAL_STATE_START)
	{
		return 0;
	}

	BATTLEROYALE_EVENT_USER* lpUser = this->GetUser(lpObj->Index);

	if (lpUser == 0)
	{
		return 0;
	}


	if (gGate.GetGate(this->EventGate, gate, map, x, y, dir, level) != 0)
	{
		return 1;
	}


	return 0;
}

int CBattleRoyale::ReturnMaxReset()
{
	int MaxRes = 0;
	int Index = 0;
	int UserIndex = 0;

	for (int n = 0; n < MAX_BATTLEROYALE_USER; n++)
	{
		LPOBJ lpObj = &gObj[this->User[n].Index];
		if (OBJECT_RANGE(lpObj->Index) == 0)
		{
			continue;
		}

		if (!this->User[n].Available)
		{
			continue;
		}

		if (lpObj->Reset >= MaxRes)
		{
			MaxRes = lpObj->Reset;
			Index = lpObj->Index;
			UserIndex = n;
		}
	}
	this->User[UserIndex].Available = 0;
	return Index;
}

void CBattleRoyale::UserDieProc(LPOBJ lpObj, LPOBJ lpTarget) // OK
{
	if (this->m_BattleRoyaleEnable == 0)
	{
		return;
	}

	if (this->GetState() != ROYAL_STATE_START)
	{
		return;
	}

	BATTLEROYALE_EVENT_USER* lpUserA = this->GetUser(lpObj->Index);

	if (lpUserA == 0)
	{
		return;
	}

	BATTLEROYALE_EVENT_USER* lpUserB = this->GetUser(lpTarget->Index);

	if (lpUserB == 0)
	{
		return;
	}

	lpUserA->Deaths++;
	lpUserB->Kills++;
	//=== Cong Coin Kill
	if (this->BonusKill[0] > 0 || this->BonusKill[1] > 0 || this->BonusKill[2] > 0)
	{
		GDSetCoinSend(lpUserB->Index, this->BonusKill[0], this->BonusKill[1], this->BonusKill[2], "BattleRoyaleCoinKill");
		gCashShop.CGCashShopPointRecv(lpObj->Index);
	}

	if (this->ItemBag > 0)
	{
		gItemBagManager.DropItemByIndexItemBag(this->ItemBag, lpTarget); //Gui Item cho NV
	}

	if (lpUserA->Deaths >= this->m_MaxDie && this->m_MaxDie != -1)
	{

		gObjMoveGate(lpUserA->Index, 17);

		this->RollBackCharacterInfo(lpUserA->Index);
		this->BackupDelUser(lpUserA->Index);

		gObjViewportListProtocolCreate(&gObj[this->User[lpUserA->Index].Index]);
		gObjectManager.CharacterUpdateMapEffect(&gObj[this->User[lpUserA->Index].Index]);

		this->User[lpUserA->Index].Reset();

		this->TotalPlayer--;

		this->DelUser(lpUserA->Index);

	}

	//== Tinh Toan Rank
	this->CalcUserRank();
	this->SendBXHVeClient();

}

void CBattleRoyale::NoticeSendToAll(int type, char* message, ...) // OK
{
	char buff[256];

	va_list arg;
	va_start(arg, message);
	vsprintf_s(buff, message, arg);
	va_end(arg);

	for (int n = 0; n < MAX_BATTLEROYALE_USER; n++)
	{
		if (OBJECT_RANGE(this->User[n].Index) != 0)
		{
			gNotice.GCNoticeSend(this->User[n].Index, type, 0, 0, 0, 0, 0, buff);
		}
	}
}

void CBattleRoyale::StartTM()
{
	time_t theTime = time(NULL);
	struct tm *aTime = localtime(&theTime);

	//int day = aTime->tm_mday;
	//int month = aTime->tm_mon + 1;
	//int year = aTime->tm_year + 1900;

	int hour = aTime->tm_hour;
	int minute = aTime->tm_min + 1;


	if (minute >= 60)
	{
		hour++;
		minute = minute - 60;
	}

	BATTLEROYALE_TIME info;

	info.Year = -1;

	info.Month = -1;

	info.Day = -1;

	info.DayOfWeek = -1;

	info.Hour = hour;

	info.Minute = minute;

	info.Second = 0;

	this->m_BattleRoyaleStartTime.push_back(info);

	LogAdd(LOG_EVENT, "[Set BattleRoyale] At %2d:%2d:00", hour, minute);

	this->Init();
}

void CBattleRoyale::CalcUserRank() // OK
{
	for (int stt = 0; stt < 10; stt++)
	{
		this->mIndexRank[stt] = -1;
	}
	for (int n = 0; n < MAX_BATTLEROYALE_USER; n++)
	{
		if (OBJECT_RANGE(this->User[n].Index) == 0)
		{
			continue;
		}

		int rank = MAX_BATTLEROYALE_USER;

		for (int i = 0; i < MAX_BATTLEROYALE_USER; i++)
		{
			if (OBJECT_RANGE(this->User[i].Index) == 0)
			{
				rank--;
				continue;
			}

			if (this->User[n].Index == this->User[i].Index)
			{
				rank--;
				continue;
			}

			if (this->User[n].Kills > this->User[i].Kills)
			{
				rank--;
				continue;
			}

			if (this->User[n].Kills == this->User[i].Kills && n < i)
			{
				rank--;
				continue;
			}
		}

		this->User[n].Rank = (rank + 1);
		if (this->User[n].Rank >= 1 && this->User[n].Rank <= 10)
		{
			int Stt = this->User[n].Rank - 1;
			this->mIndexRank[Stt] = n;
			//LogAdd(LOG_RED, "GETRANK %d ~ %d", this->mIndexRank[Stt], n);
		}
	}
}

void CBattleRoyale::SendBXHVeClient()
{

	BYTE send[4096];

	PMSG_COUNTLIST_ROYAL pMsg;

	pMsg.header.set(0xFB, 0x67, 0);

	int size = sizeof(pMsg);

	pMsg.Count = 0;

	pMsg.OpenBXHWindow = 0;

	BATTLEROYALE_BXH info;

	for (int n = 0; n < 10; n++)
	{
		if (OBJECT_RANGE(this->User[this->mIndexRank[n]].Index) == 0)
		{
			continue;
		}
		if (this->User[this->mIndexRank[n]].Rank > 0 && this->User[this->mIndexRank[n]].Rank <= 10)
		{
			memcpy(info.Name, gObj[this->User[this->mIndexRank[n]].Index].Name, sizeof(info.Name));
			info.Kill = this->User[this->mIndexRank[n]].Kills;
			info.Team = this->User[this->mIndexRank[n]].Deaths;
			pMsg.Count++;

			memcpy(&send[size], &info, sizeof(info));
			size += sizeof(info);
		}

	}
	pMsg.header.size[0] = SET_NUMBERHB(size);
	pMsg.header.size[1] = SET_NUMBERLB(size);
	// ---
	memcpy(send, &pMsg, sizeof(pMsg));

	for (int n = 0; n < MAX_BATTLEROYALE_USER; n++)
	{
		if (OBJECT_RANGE(this->User[n].Index) != 0)
		{
			DataSend(this->User[n].Index, send, size);
		}
	}
}
#include "MasterSkillTree.h"
#include "CustomRankUser.h"

void CBattleRoyale::ChangeUserInfo()
{
	for (int i = 0; i < MAX_BATTLEROYALE_USER; i++)
	{
		int aIndex = this->User[i].Index;
		if (aIndex != -1)
		{
			if (gObjIsConnectedGP(aIndex) == 0)
			{
				this->DelUser(aIndex);
				continue;
			}
			//this->BackupAddUser(aIndex);
			this->ChangeUserInfo(aIndex);
		}
	}
}

void CBattleRoyale::ChangeUserInfo(int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];
	int n;

	if (gObjIsConnectedGP(aIndex) == 0)
		return;
	//save it first
	GDCharacterInfoSaveSend(lpObj->Index);

	//delete item
	int MaxValue = gItemManager.GetInventoryMaxValue(lpObj);
	for (n = 0; n < MaxValue; n++)
	{
		gItemManager.InventoryDelItem(lpObj->Index, n);
		gItemManager.GCItemDeleteSend(lpObj->Index, n, 1);
	}
	for (int o = INVENTORY_EXT4_SIZE; o < INVENTORY_FULL_SIZE; o++)
	{
		gItemManager.InventoryDelItem(lpObj->Index, o);
		gItemManager.GCItemDeleteSend(lpObj->Index, o, 1);
	}
	//delete buff

	for (n = 0; n < MAX_EFFECT_LIST; n++)
	{
		lpObj->EffectBackup[n] = lpObj->Effect[n];
		gEffectManager.DelEffect(lpObj, n);
	}

	//delete skill
	for (n = 0; n < MAX_SKILL_LIST; n++)
	{
		lpObj->SkillBackup[n] = lpObj->Skill[n];
		lpObj->Skill[n].Clear();
	}

	lpObj->MasterLevel = 1;

	lpObj->MasterPoint = 0;

	for (int n = 0; n < MAX_MASTER_SKILL_LIST; n++)
	{
		lpObj->MasterSkillBackup[n] = lpObj->MasterSkill[n];
		lpObj->MasterSkill[n].Clear();
	}

	gMasterSkillTree.GCMasterSkillListSend(lpObj->Index);

	gSkillManager.GCSkillListSend(lpObj, 0);

	gMasterSkillTree.GCMasterInfoSend(lpObj);

	lpObj->Money = 123456;

	GCMoneySend(aIndex, lpObj->Money);

	//delete stat
	lpObj->Strength = 50;
	lpObj->Dexterity = 50;
	lpObj->Vitality = 50;
	lpObj->Energy = 50;
	lpObj->Leadership = 0;

	lpObj->AddStrength = 0;
	lpObj->AddDexterity = 0;
	lpObj->AddVitality = 0;
	lpObj->AddEnergy = 0;
	lpObj->AddLeadership = 0;

	lpObj->LevelUpPoint = this->m_Point;
	lpObj->Level = 400;
	lpObj->ChangeSkin = 0;

	lpObj->rDanhHieu = 0;
	lpObj->rQuanHam = 0;
	lpObj->rTuLuyen = 0;
	lpObj->UserSkinPick = 0;
	lpObj->CapDoHonHoan = 0;
	lpObj->Flag = 0;
	lpObj->CheckFlag = 0;


	gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
	//===Info Item Send
	gItemManager.GCItemListSend(lpObj->Index);
	GCMoneySend(lpObj->Index, lpObj->Money);
	gObjectManager.CharacterMakePreviewCharSet(lpObj->Index);
	gItemManager.GCItemEquipmentSend(lpObj->Index);
	//===Info Char Point Send
	gObjectManager.CharacterCalcAttribute(lpObj->Index);
	GCNewCharacterInfoSend(lpObj);
	//====
	//=== Fix SKin Tào Lao
	gSkillManager.SkillChangeUse(lpObj->Index);
	gObjViewportListProtocolCreate(lpObj);
	gObjectManager.CharacterUpdateMapEffect(lpObj);
	//LogAdd(LOG_BLUE, "[%d][%s]Cur point: %d", aIndex, lpObj->Name, lpObj->LevelUpPoint);

	return;
}



bool SauBackUpCharacter(int aIndex) // OK
{
	if (OBJECT_RANGE(aIndex) == 0)
	{
		return 0;
	}

	LPOBJ lpObj = &gObj[aIndex];

	if (lpObj->CB_Status == 1)
	{
		return 0;
	}

	for (int n = 0; n < MAX_SKILL_LIST; n++)
	{
		lpObj->SkillBackup[n] = lpObj->Skill[n];
	}

	for (int n = 0; n < INVENTORY_SIZE; n++)
	{
		lpObj->Inventory2[n] = lpObj->Inventory1[n];
	}

#if(GAMESERVER_UPDATE>=802)

	for (int n = 0; n < EVENT_INVENTORY_SIZE; n++)
	{
		lpObj->EventInventory2[n] = lpObj->EventInventory1[n];
	}

#endif

	memcpy(lpObj->InventoryMap2, lpObj->InventoryMap1, INVENTORY_SIZE);

#if(GAMESERVER_UPDATE>=802)

	memcpy(lpObj->EventInventoryMap2, lpObj->EventInventoryMap1, EVENT_INVENTORY_SIZE);

#endif

	gObjSetInventory2Pointer(lpObj);

	gObjSetEventInventory2Pointer(lpObj);

	lpObj->CB_Status = 1;
	return 1;
}

OBJECTSTRUCT CBattleRoyale::BackupGetUser(int aIndex)
{
	for (int i = 0; i < this->m_BackupCharacterBattleRoyale.size(); i++)
	{
		OBJECTSTRUCT cObj = this->m_BackupCharacterBattleRoyale[i];
		if (cObj.Index == aIndex)
		{
			return cObj;
		}
	}
	OBJECTSTRUCT nObj;
	nObj.Index = -1;

	return nObj;
}

bool CBattleRoyale::BackupDelUser(int aIndex)
{
	for (int i = 0; i < this->m_BackupCharacterBattleRoyale.size(); i++)
	{
		OBJECTSTRUCT cObj = this->m_BackupCharacterBattleRoyale[i];
		if (cObj.Index == aIndex)
		{
			this->m_BackupCharacterBattleRoyale.erase(this->m_BackupCharacterBattleRoyale.begin() + i);
			return true;
		}
	}
	return false;
}

bool CBattleRoyale::BackupAddUser(int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];

	if (gObjIsConnectedGP(aIndex) == 0)
		return false;

	for (int i = 0; i < this->m_BackupCharacterBattleRoyale.size(); i++)
	{
		OBJECTSTRUCT bu = this->m_BackupCharacterBattleRoyale[i];
		if (bu.Index == aIndex)
		{
			this->BackupDelUser(aIndex);
			goto PUSH_IT;
			return true;
		}
	}
PUSH_IT:
	OBJECTSTRUCT nObj;

	nObj = gObj[aIndex];
	memcpy(&nObj.Effect, gObj[aIndex].Effect, sizeof(gObj[aIndex].Effect));
	memcpy(&nObj.Skill, gObj[aIndex].Skill, sizeof(gObj[aIndex].Skill));
	//==BackupITem
	SauBackUpCharacter(aIndex);
	//==End
	this->m_BackupCharacterBattleRoyale.push_back(nObj);
	return true;
}

bool SauResetCharacter(int aIndex) // OK
{
	if (OBJECT_RANGE(aIndex) == 0)
	{
		return 0;
	}

	LPOBJ lpObj = &gObj[aIndex];

	if (lpObj->CB_Status != 1)
	{
		return 0;
	}

	for (int n = 0; n < MAX_SKILL_LIST; n++)
	{
		lpObj->Skill[n] = lpObj->SkillBackup[n];
	}

	for (int n = 0; n < INVENTORY_SIZE; n++)
	{
		lpObj->Inventory2[n].Clear();
	}

#if(GAMESERVER_UPDATE>=802)

	for (int n = 0; n < EVENT_INVENTORY_SIZE; n++)
	{
		lpObj->EventInventory2[n].Clear();
	}

#endif


	gObjSetInventory1Pointer(lpObj);



	gObjSetEventInventory1Pointer(lpObj);

	lpObj->CB_Status = 0;
	return 1;
}

bool CBattleRoyale::RollBackCharacterInfo(int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];

	if (gObjIsConnectedGP(aIndex) == 0)
		return false;

	OBJECTSTRUCT lpObjBackup = this->BackupGetUser(aIndex);
	if (lpObjBackup.Index == -1)
	{

		return false;
	}
	//==Khoi Phuc ITem
	SauResetCharacter(aIndex);
	//End

	for (int n = 0; n < MAX_EFFECT_LIST; n++){
		lpObj->Effect[n] = lpObj->EffectBackup[n];
	}


	for (int n = 0; n < MAX_MASTER_SKILL_LIST; n++)
	{
		lpObj->MasterSkill[n] = lpObj->MasterSkillBackup[n];
	}

	gMasterSkillTree.GCMasterSkillListSend(lpObj->Index);

	gMasterSkillTree.GCMasterInfoSend(lpObj);

	gObj[aIndex].Money = lpObjBackup.Money;

	gObj[aIndex].MasterLevel = lpObjBackup.MasterLevel;
	gObj[aIndex].MasterPoint = lpObjBackup.MasterPoint;
	gObj[aIndex].Level = lpObjBackup.Level;
	gObj[aIndex].LevelUpPoint = lpObjBackup.LevelUpPoint;

	gObj[aIndex].Strength = lpObjBackup.Strength;
	gObj[aIndex].Dexterity = lpObjBackup.Dexterity;
	gObj[aIndex].Vitality = lpObjBackup.Vitality;
	gObj[aIndex].Energy = lpObjBackup.Energy;
	gObj[aIndex].Leadership = lpObjBackup.Leadership;
	gObj[aIndex].AddStrength = lpObjBackup.AddStrength;
	gObj[aIndex].AddDexterity = lpObjBackup.AddDexterity;
	gObj[aIndex].AddVitality = lpObjBackup.AddVitality;
	gObj[aIndex].AddEnergy = lpObjBackup.AddEnergy;
	gObj[aIndex].AddLeadership = lpObjBackup.AddLeadership;

	gObj[aIndex].rDanhHieu = lpObjBackup.rDanhHieu;
	gObj[aIndex].rQuanHam = lpObjBackup.rQuanHam;
	gObj[aIndex].rTuLuyen = lpObjBackup.rTuLuyen;
	gObj[aIndex].UserSkinPick = lpObjBackup.UserSkinPick;
	gObj[aIndex].CapDoHonHoan = lpObjBackup.CapDoHonHoan;
	gObj[aIndex].Flag = lpObjBackup.Flag;
	gObj[aIndex].CheckFlag = lpObjBackup.CheckFlag;
	gObj[aIndex].PKLevel = lpObjBackup.PKLevel;


	//this->lpObjCpy(lpObj, lpObjBackup);

	gSkillManager.GCSkillListSend(lpObj, 0);


	GCMoneySend(aIndex, lpObj->Money);

	gObjectManager.CharacterCalcAttribute(lpObj->Index);
	GCNewCharacterInfoSend(lpObj);

	if (gSkillManager.SkillChangeUse(aIndex) != 0)
	{
		gObjViewportListProtocolCreate(&gObj[aIndex]);
		gObjectManager.CharacterUpdateMapEffect(&gObj[aIndex]);
	}
	//===Info Item Send
	gItemManager.GCItemListSend(lpObj->Index);
	GCMoneySend(lpObj->Index, lpObj->Money);
	gObjectManager.CharacterMakePreviewCharSet(lpObj->Index);
	gItemManager.GCItemEquipmentSend(lpObj->Index);
	//===Info Char Point Send
	gObjectManager.CharacterCalcAttribute(lpObj->Index);
	GCNewCharacterInfoSend(lpObj);

	this->BackupDelUser(aIndex);
	GDCharacterInfoSaveSend(lpObj->Index);

	return true;
}
#include "Map.h"

void CBattleRoyale::SetZone(short X, short Y, short W, short H)
{
	this->m_Zone[0] = X;
	this->m_Zone[1] = Y;
	this->m_Zone[2] = W;
	this->m_Zone[3] = H;
}

void CBattleRoyale::MakeDropItem()
{
	if (this->m_BattleRoyale_Items.size() == 0 || !this->m_PhaseDropCount || this->m_PhaseLastDrop + this->m_PhaseDropDelay > GetTickCount())
	{
		return;
	}

	this->m_PhaseLastDrop = GetTickCount();

	for (int i = 0; i < this->m_PhaseDropCount; i++)
	{

		short x, y;
		while (true)
		{
			x = this->m_Zone[0] + GetLargeRand() % this->m_Zone[2];
			y = this->m_Zone[1] + GetLargeRand() % this->m_Zone[3];

			if (gMap[this->EventMap].CheckAttr(x, y, 4) == 0 && gMap[this->EventMap].CheckAttr(x, y, 8) == 0)
			{
				BATTLEROYALE_ITEM* item = &this->m_BattleRoyale_Items[GetLargeRand() % this->m_BattleRoyale_Items.size()];

				GDCreateItemSend(this->User[0].Index, this->EventMap, x, y, item->Index, (BYTE)item->Level, 0, item->Skill, item->Luck, item->Opt, -1, item->Exc, item->Anc, 0, 0, 0, 0, 0);
				break;
			}
		}
		//LogAdd(LOG_BLACK, "Drop at: %d:%d", x, y);
	}
}