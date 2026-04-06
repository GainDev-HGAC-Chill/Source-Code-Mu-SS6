#include "stdafx.h"
#include "RoyalBattleGround.h"
#include "Util.h"
#include "Path.h"
#include "MemScript.h"
#include "ScheduleManager.h"
#include "Map.h"
#include "Notice.h"
#include "DSProtocol.h"
#include "ObjectManager.h"
#include "MasterSkillTree.h"
#include "Protocol.h"
#include "ItemBagManager.h"
#include "Move.h"
#include "CustomRankUser.h"
#include "Gate.h"
cRoyalBattleGround RoyalBattleGround;

cRoyalBattleGround::cRoyalBattleGround()
{

}

cRoyalBattleGround::~cRoyalBattleGround()
{
}

void cRoyalBattleGround::Init()
{
	this->m_TypeCoin = 0;
	this->m_Enable = true;
	this->m_RegenMax = 1;
	this->m_State = RBG_STATE_BLANK;
	this->m_RemainTime = 0;
	this->m_TargetTime = 0;
	this->m_EndTime = 0;
	this->m_TickCount = GetTickCount();
	this->m_TotalPlayerJoin = 0;
	this->m_RBGStartTime.clear();
	this->m_RBG_Items.clear();
	this->m_RBG_Phases.clear();
	this->m_BackupCharacter.clear();
	this->m_SinhTonSkillBlock.clear();
	this->m_Reward.clear();


	this->Read(gPath.GetFullPath("Event\\RoyalBattleGround.dat"));
	this->ClearProc();

	this->SendPhaseToAllUsers();
}
char* GetNameCoinType(int TypeCoin)
{
	switch (TypeCoin)
	{
	case 0:
		return "Zen";
		break;
	case 1:
		return "WC";
		break;
	case 2:
		return "WP";
		break;
	case 3:
		return "GP";
		break;
	default:
		break;
	}
	return "NULL";
}
void cRoyalBattleGround::Read(char* path)
{
	CMemScript* lpMemScript = new CMemScript;

	if (lpMemScript == 0)
	{
		ErrorMessageBox(MEM_SCRIPT_ALLOC_ERROR, path);
		return;
	}

	if (lpMemScript->SetBuffer(path) == 0)
	{
		ErrorMessageBox(lpMemScript->GetLastError());
		delete lpMemScript;
		return;
	}

	this->m_RBGStartTime.clear();
	this->m_RBG_Items.clear();
	this->m_RBG_Phases.clear();
	this->m_Reward.clear();

	try
	{
		while (true)
		{
			if (lpMemScript->GetToken() == TOKEN_END)
			{
				break;
			}

			int section = lpMemScript->GetNumber();

			while (true)
			{
				if (section == 0)
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}


					this->m_Enable = lpMemScript->GetNumber();

					this->m_Timer_Open = lpMemScript->GetAsNumber();

					this->m_Timer_Prepare = lpMemScript->GetAsNumber();

					this->m_Timer_Stage1 = lpMemScript->GetAsNumber();

					this->m_Timer_Stage2 = lpMemScript->GetAsNumber();

					this->m_Timer_Stage3 = lpMemScript->GetAsNumber();

					this->m_Timer_StageEnd = lpMemScript->GetAsNumber();

					//LogAdd(LOG_BLACK, "%d %d %d %d %d %d", this->m_Timer_Open, this->m_Timer_Prepare, this->m_Timer_Stage1, this->m_Timer_Stage2, this->m_Timer_Stage3, this->m_Timer_StageEnd);

				}
				else if (section == 1)
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}

					ROYAL_BATTLE_GROUND_START_TIME info;

					info.Year = lpMemScript->GetNumber();

					info.Month = lpMemScript->GetAsNumber();

					info.Day = lpMemScript->GetAsNumber();

					info.DayOfWeek = lpMemScript->GetAsNumber();

					info.Hour = lpMemScript->GetAsNumber();

					info.Minute = lpMemScript->GetAsNumber();

					info.Second = lpMemScript->GetAsNumber();

					this->m_RBGStartTime.push_back(info);
				}
				else if (section == 2)
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}

					this->m_Map = lpMemScript->GetNumber();

					this->m_GateIn = lpMemScript->GetAsNumber();

					this->m_GateOut = lpMemScript->GetAsNumber();

					this->m_MaxPlayer = lpMemScript->GetAsNumber();

					this->m_RegenMax = lpMemScript->GetAsNumber();

					this->m_RewardBonus = lpMemScript->GetAsNumber();

					this->m_JoinCost = lpMemScript->GetAsNumber();

					this->m_TypeCoin = lpMemScript->GetAsNumber();


				}
				else if (section == 3)
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}

					RBG_Phase info;

					info.id = lpMemScript->GetNumber();

					info.W = lpMemScript->GetAsNumber();

					info.H = lpMemScript->GetAsNumber();

					info.HP = lpMemScript->GetAsNumber();

					info.HPrate = lpMemScript->GetAsFloatNumber();

					info.ItemCnt = lpMemScript->GetAsNumber();

					info.ItemLoop = lpMemScript->GetAsNumber();


					this->m_RBG_Phases.push_back(info);
				}
				else if (section == 4)
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}

					ROYAL_BATTLE_GROUND_REWARD info;

					info.Top = lpMemScript->GetNumber();

					info.Rate = lpMemScript->GetAsNumber();

					info.IDItemBag = lpMemScript->GetAsNumber();

					this->m_Reward.insert(std::pair<int, ROYAL_BATTLE_GROUND_REWARD>(info.Top, info));
				}
				else if (section == 15)
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}

					ROYAL_BATTLE_GROUND_ITEM info;

					info.Index = lpMemScript->GetNumber() * 512 + lpMemScript->GetAsNumber();

					info.Level = lpMemScript->GetAsNumber();

					info.Skill = lpMemScript->GetAsNumber();

					info.Luck = lpMemScript->GetAsNumber();

					info.Opt = lpMemScript->GetAsNumber();

					info.Exc = lpMemScript->GetAsNumber();

					info.Anc = lpMemScript->GetAsNumber();

					info.Socket[0] = lpMemScript->GetAsNumber();

					info.Socket[1] = lpMemScript->GetAsNumber();

					info.Socket[2] = lpMemScript->GetAsNumber();

					info.Socket[3] = lpMemScript->GetAsNumber();

					info.Socket[4] = lpMemScript->GetAsNumber();

					info.SocketBonus = lpMemScript->GetAsNumber();

					this->m_RBG_Items.push_back(info);
				}
				else
				{
					break;
				}
			}
		}
	}
	catch (...)
	{
		ErrorMessageBox(lpMemScript->GetLastError());
	}

	delete lpMemScript;
}

void cRoyalBattleGround::MainProc()
{
	DWORD elapsed = GetTickCount() - this->m_TickCount;
	if (this->m_TargetTime == -1 || elapsed < 1000){
		return;
	}
	this->m_TickCount = GetTickCount();
	this->m_RemainTime = (int)difftime(this->m_TargetTime, time(0));

	if (this->m_State == RBG_STATE_BLANK)
	{
		gServerDisplayer.EventRoyalBattleGround = this->m_RemainTime;
	}
	else
	{
		if (gServerDisplayer.EventRoyalBattleGround != 0)
		{
			gServerDisplayer.EventRoyalBattleGround = 0;
		}
	}
	switch (this->m_State)
	{
	case RBG_STATE::RBG_STATE_BLANK:
		this->BlankProc();
		break;
	case RBG_STATE::RBG_STATE_OPEN:
		this->OpenProc();
		break;
	case RBG_STATE::RBG_STATE_PREPARE:
		this->PrepareProc();
		break;
	case RBG_STATE::RBG_STATE_BATTLE_STAGE_1:
		this->Stage1Proc();
		break;
	case RBG_STATE::RBG_STATE_BATTLE_STAGE_2:
		this->Stage2Proc();
		break;
	case RBG_STATE::RBG_STATE_BATTLE_STAGE_3:
		this->Stage3Proc();
		break;
	case RBG_STATE::RBG_STATE_BATTLE_END:
		this->StageEndProc();
		break;
	case RBG_STATE::RBG_STATE_REWARD:
		this->RewardProc();
		break;
	case RBG_STATE::RBG_STATE_CLEAR:
		this->ClearProc();
		break;
	}
}

void cRoyalBattleGround::SetState(int state)
{
	this->m_State = state;
}

void cRoyalBattleGround::CheckSync()
{
	if (this->m_RBGStartTime.empty() != 0)
	{
		this->SetState(RBG_STATE::RBG_STATE_BLANK);
		this->m_TargetTime = -1;
		this->m_EndTime = 0;
		return;
	}

	CTime ScheduleTime;

	CScheduleManager ScheduleManager;

	for (std::vector<ROYAL_BATTLE_GROUND_START_TIME>::iterator it = this->m_RBGStartTime.begin(); it != this->m_RBGStartTime.end(); it++)
	{
		ScheduleManager.AddSchedule(it->Year, it->Month, it->Day, it->Hour, it->Minute, it->Second, it->DayOfWeek);
	}

	if (ScheduleManager.GetSchedule(&ScheduleTime) == 0)
	{
		this->SetState(RBG_STATE::RBG_STATE_BLANK);
		this->m_TargetTime = -1;
		this->m_EndTime = 0;
		return;
	}

	this->m_RemainTime = (int)difftime(ScheduleTime.GetTime(), time(0));

	this->m_TargetTime = (int)ScheduleTime.GetTime();

	this->m_EndTime = (int)ScheduleTime.GetTime() +
		this->m_Timer_Open * 60 +
		this->m_Timer_Prepare * 60 +
		this->m_Timer_Stage1 * 60 +
		this->m_Timer_Stage2 * 60 +
		this->m_Timer_Stage3 * 60 +
		this->m_Timer_StageEnd * 60;
}

bool cRoyalBattleGround::GetEnabled()
{
	return this->m_Enable;
}
int cRoyalBattleGround::GetState()
{
	return this->m_State;
}
bool cRoyalBattleGround::IsOpen()
{
	return this->m_State != RBG_STATE::RBG_STATE_BLANK;
}
bool cRoyalBattleGround::IsPlaying()
{
	return this->m_State != RBG_STATE::RBG_STATE_BLANK && this->m_State != RBG_STATE::RBG_STATE_OPEN;
}
int  cRoyalBattleGround::GetOpenRemainTime()
{
	return this->m_RemainTime;
}
int cRoyalBattleGround::GetPlayRemainTime()
{
	return (int)difftime(this->m_EndTime, time(0));
}

int cRoyalBattleGround::GetRemainTime()
{
	this->m_RemainTime = (int)difftime(this->m_TargetTime, time(0));
	return this->m_RemainTime;
}
void cRoyalBattleGround::BlankProc()
{
	if (this->m_RemainTime <= 0)
	{
		this->m_TargetTime += this->m_Timer_Open * 60;
		this->SetState(RBG_STATE::RBG_STATE_OPEN);
		this->RemoveObject();
		this->SendPhaseToAllUsers();
		gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "[Sinh Tồn] Sẽ mở cửa sau %d phút", this->m_Timer_Open);
		//	LogAdd(LOG_RED, "RBG_STATE::RBG_STATE_OPEN");
	}
}

void cRoyalBattleGround::OpenProc()
{
	if (this->m_RemainTime <= 0)
	{
		if (this->CountMember() < 2)
		{
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "[Sinh Tồn] Bị huỷ do không đủ người !");
			//=== Trả lại phí tham gia
			for (int n = 0; n < RBG_MAX_PLAYER; n++)
			{
				if (OBJECT_RANGE(this->Player[n].Index) == 0 || this->Player[n].Live == 0)
				{
					continue;
				}


				//==Cong Coin
				gNotice.GCNoticeSend(this->Player[n].Index, 1, 0, 0, 0, 0, 0, "[Sinh Tồn] Hoàn lại (%d) (%s)", this->m_JoinCost, GetNameCoinType(this->m_TypeCoin));
				GDSetCoinSend(this->Player[n].Index, +(this->m_TypeCoin == 1 ? this->m_JoinCost : 0), +(this->m_TypeCoin == 2 ? this->m_JoinCost : 0), +(this->m_TypeCoin == 3 ? this->m_JoinCost : 0), "[Royal]Re Coin");
				this->UserMoveOut(this->Player[n].Index);
			}
			this->SetState(RBG_STATE::RBG_STATE_CLEAR);
			return;
		}
		this->m_TargetTime += this->m_Timer_Prepare * 60;
		this->SetState(RBG_STATE::RBG_STATE_PREPARE);
		this->SendPhaseToEventUsers();
		//LogAdd(LOG_RED, "RBG_STATE::RBG_STATE_PREPARE");
	}
	else
	{
		if (this->m_RemainTime % 60 == 0)
		{
			gNotice.GCNoticeSendToAll(0, 0, 0, 0, 0, 0, "[Sinh Tồn] Đóng cửa sau %d phút", this->m_RemainTime / 60);
		}
	}
}

void cRoyalBattleGround::PrepareProc()
{
	if (this->m_RemainTime <= 0)
	{

		this->CalcUserRank();
		this->m_TargetTime += this->m_Timer_Stage1 * 60;
		this->SetState(RBG_STATE::RBG_STATE_BATTLE_STAGE_1);
		this->MakeZonePhase(1);
		this->SendPhaseToEventUsers();
		this->MoveUserPosition();
		//LogAdd(LOG_RED, "RBG_STATE::RBG_STATE_BATTLE_STAGE_1");
	}
}

void cRoyalBattleGround::Stage1Proc()
{
	if (this->m_RemainTime <= 0)
	{
		this->m_TargetTime += this->m_Timer_Stage2 * 60;
		this->SetState(RBG_STATE::RBG_STATE_BATTLE_STAGE_2);
		this->ThuongCoin(RBG_STATE::RBG_STATE_BATTLE_STAGE_1);
		this->MakeZonePhase(2);
		this->SendPhaseToEventUsers();
		//LogAdd(LOG_RED, "RBG_STATE::RBG_STATE_BATTLE_STAGE_2");
	}
	else
	{
		//zone 1
		this->MakeDropItem();
		this->DangerousZone();
	}
}
void cRoyalBattleGround::Stage2Proc()
{
	if (this->m_RemainTime <= 0)
	{
		this->m_TargetTime += this->m_Timer_Stage3 * 60;
		this->SetState(RBG_STATE::RBG_STATE_BATTLE_STAGE_3);
		this->ThuongCoin(RBG_STATE::RBG_STATE_BATTLE_STAGE_2);
		this->MakeZonePhase(3);
		this->SendPhaseToEventUsers();
		//	LogAdd(LOG_RED, "RBG_STATE::RBG_STATE_BATTLE_STAGE_3");
	}
	else
	{
		//zone 2
		this->MakeDropItem();
		this->DangerousZone();
	}
}
void cRoyalBattleGround::Stage3Proc()
{
	if (this->m_RemainTime <= 0)
	{
		this->m_TargetTime += this->m_Timer_StageEnd * 60;
		this->SetState(RBG_STATE::RBG_STATE_BATTLE_END);
		this->ThuongCoin(RBG_STATE::RBG_STATE_BATTLE_STAGE_3);
		this->SendPhaseToEventUsers();
		//LogAdd(LOG_RED, "RBG_STATE::RBG_STATE_BATTLE_END");
		GCServerMsgStringSendToMap(this->m_Map, 0, "[Sinh Tồn] Kết thúc Sự Kiện, chuẩn bị trao thưởng!!", this->m_TotalPlayerJoin, this->m_TotalReward);
	}
	else
	{
		//zone 3
		this->MakeDropItem();
		this->DangerousZone();
	}
}
void cRoyalBattleGround::StageEndProc()
{
	if (this->m_RemainTime <= 0)
	{
		this->SetState(RBG_STATE::RBG_STATE_REWARD);
		//LogAdd(LOG_RED, "RBG_STATE::RBG_STATE_REWARD");
	}
}

void cRoyalBattleGround::RewardProc()
{
	//==Trao Thuong Top
	for (int i = 0; i < RBG_MAX_PLAYER; i++)
	{
		int aIndex = this->Player[i].Index;
		if (aIndex != -1)
		{
			if (gObjIsConnectedGP(aIndex) == 0) //Bo Qua neu khong online
			{
				//gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "Event was ended!");
				continue;
			}
			std::map<int, ROYAL_BATTLE_GROUND_REWARD>::iterator it = this->m_Reward.find(this->Player[i].Rank);
			if (it == this->m_Reward.end())
			{
				continue;
			}

			this->RollBackCharacterInfo(aIndex); //Khoi Phuc Do Truoc

			if (it->second.IDItemBag != -1)
			{
				LogAdd(LOG_RED, "[Royal] Thưởng Top %d (ItemBag %d)", this->Player[i].Rank, it->second.IDItemBag);
				gItemBagManager.DropItemByIndexItemBag(it->second.IDItemBag, &gObj[aIndex]); //Gui Item cho NV
			}
			int CongCoin = (this->m_TotalReward * it->second.Rate) / 100;
			gNotice.GCNoticeSend(aIndex, 0, 0, 0, 0, 0, 0, "[%s] Hạng (%d) Nhận được: %d (%s)", gObj[aIndex].Name, this->Player[i].Rank, CongCoin, GetNameCoinType(this->m_TypeCoin));
			if (this->m_TypeCoin > 0)
			{
				//==Cong Coin
				GDSetCoinSend(aIndex, +(this->m_TypeCoin == 1 ? CongCoin : 0), +(this->m_TypeCoin == 2 ? CongCoin : 0), +(this->m_TypeCoin == 3 ? CongCoin : 0), "[EventChayBo]ThuongTop");
			}
			else
			{
				//==CongZen
				gObj[aIndex].Money += (int)CongCoin;
				GCMoneySend(aIndex, gObj[aIndex].Money);
			}
			//==Thuong Xong Da' Ra Ngoai
			this->DelMember(aIndex);
		}
	}



	this->SetState(RBG_STATE::RBG_STATE_CLEAR);
	//LogAdd(LOG_RED, "RBG_STATE::RBG_STATE_CLEAR");
}
void cRoyalBattleGround::ClearProc()
{
	this->CheckSync();
	this->SetState(RBG_STATE::RBG_STATE_BLANK);
	this->SendPhaseToEventUsers();
	//clean session
	this->ClearSection();
	//LogAdd(LOG_RED, "RBG_STATE::RBG_STATE_BLANK");
}
void cRoyalBattleGround::ClearSection()
{
	this->DelAllMembers();
	this->SetZone(0, 0, 255, 255);
	this->m_TotalReward = this->m_RewardBonus;
}

void cRoyalBattleGround::ChangeUserInfo()
{
	for (int i = 0; i < RBG_MAX_PLAYER; i++)
	{
		int aIndex = this->Player[i].Index;
		if (aIndex != -1)
		{
			if (gObjIsConnectedGP(aIndex) == 0)
			{
				this->DelMember(aIndex);
				continue;
			}
			//this->BackupAddUser(aIndex);
			this->ChangeUserInfo(aIndex);
		}
	}
}

void cRoyalBattleGround::MoveUserPosition()
{
	for (int i = 0; i < RBG_MAX_PLAYER; i++)
	{
		int aIndex = this->Player[i].Index;
		if (aIndex != -1)
		{
			if (gObjIsConnectedGP(aIndex) == 0)
			{
				this->DelMember(aIndex);
				continue;
			}
			LPOBJ lpObj = &gObj[aIndex];
			int x, y;
			if (this->GetPosRandomFromBo(&x, &y) == 0)
			{
				continue;
			}

			//== Tele vao Event
			EventTeleport(lpObj->Index, this->m_Map, x, y);
			//LogAdd(LOG_RED,"MoveUserPosition %s Map %d (%d/%d)", lpObj->Name, lpObj->Map, x, y);
		}
	}
}

bool cRoyalBattleGround::CheckUserList(int aIndex)
{
	if (!this->IsOpen())
	{
		return false;
	}
	for (int i = 0; i < RBG_MAX_PLAYER; i++)
	{
		if (this->Player[i].Index == aIndex)
		{
			return true;
		}
	}
	return false;
}

bool cRoyalBattleGround::CheckUserPostion(int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];

	if (gObjIsConnectedGP(aIndex) == 0)
	{
		return false;
	}

	if (!this->IsOpen())
	{
		return false;
	}
	bool isEventUser = this->CheckUserList(aIndex);
	if (!isEventUser && lpObj->Map == this->m_Map)
	{
		//move to other map.
		gObjMoveGate(lpObj->Index, this->m_GateOut);
		return true;
	}
	else if (isEventUser && lpObj->Map != this->m_Map)
	{
		this->DelMember(aIndex);
	}

	return false;
}

void cRoyalBattleGround::RemoveObject()
{
	//LogAdd(LOG_RED, "RemoveObject()");
	for (int n = 0; n < MAX_OBJECT_MONSTER; n++)
	{
		if (gObj[n].Type != OBJECT_MONSTER && gObj[n].Type != OBJECT_NPC)
		{
			continue;
		}

		if (gObj[n].Map != this->m_Map)
		{
			continue;
		}

#if(GAMESERVER_TYPE==1)
		if (gObj[n].CsNpcType != 0)
		{
			continue;
		}
#endif
		gObjDel(n);
	}
}

void cRoyalBattleGround::MemberRequestJoin(int aIndex)
{
	if (this->AddMember(aIndex))
	{
		LogAdd(LOG_GREEN, "Add member: %s", gObj[aIndex].Name);
		this->SendPhaseToUser(aIndex);
		this->BackupAddUser(aIndex);
		this->ChangeUserInfo(aIndex);
		this->SendPointToEventUsers();
		return;
	}
	LogAdd(LOG_GREEN, "Add member failed!");
}

bool cRoyalBattleGround::AddMember(int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];

	if (gObjIsConnectedGP(aIndex) == 0)
	{
		return false;
	}

	this->CountMember();

	if (this->m_TotalPlayer >= RBG_MAX_PLAYER)
	{
		gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "Sự kiện đã đủ người");
		//
		return false;
	}

	if (this->m_State != RBG_STATE_OPEN)
	{
		gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "Chưa đến thời gian tham gia!");
		return false;
	}

	int bestChoice = -1;
	int worstChoice = -1;
	for (int i = 0; i < RBG_MAX_PLAYER; i++)
	{
		if (this->Player[i].Index == aIndex)
		{
			return false;
		}
		else if (bestChoice == -1 && this->Player[i].Index == -1)
		{
			bestChoice = i;
		}
	}
	if (bestChoice != -1)
	{
		if (m_TypeCoin == 0)
		{
			if (lpObj->Money < this->m_JoinCost)
			{
				gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "Không đủ Zen!");
				return false;
			}
			/*
			cost
			*/
			lpObj->Money -= this->m_JoinCost;
			GCMoneySend(lpObj->Index, lpObj->Money);
		}
		else
		{
			if (this->m_TypeCoin == 1 && lpObj->Coin1 < this->m_JoinCost)
			{
				gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "Không đủ WCoin!");
				return false;
			}
			if (this->m_TypeCoin == 2 && lpObj->Coin2 < this->m_JoinCost)
			{
				gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "Không đủ WCoinP!");
				return false;
			}
			if (this->m_TypeCoin == 3 && lpObj->Coin3 < this->m_JoinCost)
			{
				gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "Không đủ GobinP!");
				return false;
			}
			//==Tru Coin
			GDSetCoinSend(aIndex, -(this->m_TypeCoin == 1 ? this->m_JoinCost : 0), -(this->m_TypeCoin == 2 ? this->m_JoinCost : 0), -(this->m_TypeCoin == 3 ? this->m_JoinCost : 0), "[EventChayBo]CoinThamgia");
		}

		this->m_TotalReward += this->m_JoinCost;

		this->Player[bestChoice].Index = aIndex;
		this->Player[bestChoice].Point = 0;
		this->Player[bestChoice].Live = true;
		gObjMoveGate(lpObj->Index, this->m_GateIn);
		this->CountMember();
		//LogAdd(LOG_GREEN, "Add slot %d index: %d", bestChoice, aIndex);
		this->m_TotalPlayerJoin++; //Dem Tong Nguoi Tham gia
		GCServerMsgStringSendToMap(this->m_Map, 1, "[Royal]Tổng %d người tham gia (Tổng Thưởng %d [%s])", this->m_TotalPlayerJoin, this->m_TotalReward, GetNameCoinType(this->m_TypeCoin));
		//gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "Da Co %d nguoi tham gia (Coin Thuong %d)", this->m_TotalPlayerJoin, this->m_TotalReward);
		return true;
	}
	gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "Join battle failed!");
	return false;
}
bool cRoyalBattleGround::DelMember(int aIndex)
{
	for (int i = 0; i < RBG_MAX_PLAYER; i++)
	{
		if (this->Player[i].Index == aIndex)
		{
			this->Player[i].Index = -1;
			this->Player[i].Point = 0;
			this->Player[i].Live = false;

			if (gObjIsConnectedGP(aIndex))
			{
				//LogAdd(LOG_GREEN, "Del slot %d index: %d", i, aIndex);
				gObjMoveGate(aIndex, this->m_GateOut);
				this->RollBackCharacterInfo(aIndex);
				this->BackupDelUser(aIndex);
				this->SendPhaseToUser(aIndex, true);
			}
			return true;
		}
	}
	return false;
}
bool cRoyalBattleGround::DelAllMembers()
{
	for (int i = 0; i < RBG_MAX_PLAYER; i++)
	{
		if (this->Player[i].Index != -1)
		{
			if (gObjIsConnectedGP(this->Player[i].Index))
			{
				gObjMoveGate(this->Player[i].Index, this->m_GateOut);
			}
		}
		this->Player[i].Reset();
	}
	this->m_TotalPlayerJoin = 0;
	return true;
}
int  cRoyalBattleGround::CountMember()
{
	this->m_TotalPlayer = 0;
	for (int i = 0; i < RBG_MAX_PLAYER; i++)
	{
		if (this->Player[i].Index != -1)
		{
			if (gObjIsConnectedGP(this->Player[i].Index) == 0)
			{
				this->DelMember(this->Player[i].Index);
				continue;
			}

			this->m_TotalPlayer++;
		}
	}
	return this->m_TotalPlayer;
}

int  cRoyalBattleGround::GetPoint(int aIndex)
{
	for (int i = 0; i < RBG_MAX_PLAYER; i++)
	{
		if (this->Player[i].Index == aIndex)
		{
			return this->Player[i].Point;
		}
	}
	return 0;
}

int  cRoyalBattleGround::GetTop(int aIndex)
{
	this->CalcUserRank();
	for (int i = 0; i < RBG_MAX_PLAYER; i++)
	{
		if (this->Player[i].Index == aIndex)
		{
			return this->Player[i].Rank;
		}
	}
	return 0;
}
void cRoyalBattleGround::SendPointToUser(int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];

	if (gObjIsConnectedGP(aIndex) == 0)
	{
		return;
	}

	PSWMSG_ROYAL_BATTLE_GROUND_POINT_SEND pMsg = { 0 };

	pMsg.header.set(0xA9, 0x11, sizeof(pMsg));

	pMsg.Alive = this->m_TotalPlayer;

	pMsg.Total = this->m_TotalPlayerJoin;

	pMsg.Kill = this->GetPoint(aIndex);

	pMsg.Top = this->GetTop(aIndex);

	DataSend(aIndex, (BYTE*)&pMsg, sizeof(pMsg));
}
//===NEW
void cRoyalBattleGround::SendBXH(int aIndex)
{
	this->CalcUserRank();

	BYTE send[4096];

	PMSG_NEW_HEALTH_BAR_SEND pMsg;

	pMsg.header.set(0xA9, 0x14, 0);

	int size = sizeof(pMsg);

	pMsg.count = 0;

	BEVENTDATA_BXH info;

	int CountRank = 0;
	for (int n = 0; n < 10; n++)
	{
		if (OBJECT_RANGE(this->Player[this->mIndexRank[n]].Index) == 0)
		{
			continue;
		}
		if (this->Player[this->mIndexRank[n]].Rank > 0 && this->Player[this->mIndexRank[n]].Rank <= 10)
		{
			memcpy(info.szName, gObj[this->Player[this->mIndexRank[n]].Index].Name, sizeof(info.szName));
			info.Kill = this->Player[this->mIndexRank[n]].Point;
			pMsg.count++;

			memcpy(&send[size], &info, sizeof(info));
			size += sizeof(info);

			//LogAdd(LOG_RED, "DEBUG BXH %d) %s %d", CountRank + 1, this->User[this->mIndexRank[n]].name, this->User[this->mIndexRank[n]].Index);
			CountRank++;
		}

	}
	pMsg.header.size[0] = SET_NUMBERHB(size);
	pMsg.header.size[1] = SET_NUMBERLB(size);
	// ---
	memcpy(send, &pMsg, sizeof(pMsg));

	DataSend(aIndex, send, size);
}
void cRoyalBattleGround::SendPointToEventUsers()
{
	for (int i = 0; i < RBG_MAX_PLAYER; i++)
	{
		if (this->Player[i].Index != -1)
		{
			this->SendPointToUser(this->Player[i].Index);
			this->SendBXH(this->Player[i].Index);
		}
	}
}
void cRoyalBattleGround::SendPhaseToUser(int aIndex, bool Close)
{
	LPOBJ lpObj = &gObj[aIndex];

	if (gObjIsConnectedGP(aIndex) == 0)
	{
		return;
	}

	PSWMSG_ROYAL_BATTLE_GROUND_PHASE_SEND pMsg = { 0 };

	pMsg.header.set(0xA9, 0x10, sizeof(pMsg));

	pMsg.Phase = Close ? this->m_State : RBG_STATE::RBG_STATE_BLANK;

	pMsg.Remain = this->m_RemainTime;
	pMsg.Map = this->m_Map;

	pMsg.Zone[0] = this->m_Zone[0];
	pMsg.Zone[1] = this->m_Zone[1];
	pMsg.Zone[2] = this->m_Zone[2];
	pMsg.Zone[3] = this->m_Zone[3];

	DataSend(aIndex, (BYTE*)&pMsg, sizeof(pMsg));
}
void cRoyalBattleGround::SendPhaseToAllUsers()
{
	this->GetRemainTime();
	for (int n = OBJECT_START_USER; n < MAX_OBJECT; n++)
	{
		if (gObjIsConnectedGP(n) != 0)
		{
			this->SendPhaseToUser(n);
		}
	}
}

void cRoyalBattleGround::SendPhaseToEventUsers()
{
	this->GetRemainTime();
	for (int i = 0; i < RBG_MAX_PLAYER; i++)
	{
		if (this->Player[i].Index != -1)
		{
			if (gObjIsConnectedGP(this->Player[i].Index) != 0)
			{
				this->SendPhaseToUser(this->Player[i].Index);
			}
		}
	}
}

void cRoyalBattleGround::SendKillToEventUsers(int aIndex, int bIndex)
{
	PSWMSG_ROYAL_BATTLE_GROUND_KILL_SEND pMsg = { 0 };

	pMsg.header.set(0xA9, 0x12, sizeof(pMsg));

	pMsg.ComboKill = 0;

	pMsg.Rank = 0;

	memcpy(pMsg.Player, gObj[aIndex].Name, sizeof(gObj[aIndex].Name));

	memcpy(pMsg.Target, gObj[bIndex].Name, sizeof(gObj[bIndex].Name));

	//LogAdd(LOG_BLUE, "%s kill %s %d %d", pMsg.Player, pMsg.Target, aIndex, bIndex);
	for (int i = 0; i < RBG_MAX_PLAYER; i++)
	{
		if (this->Player[i].Index != -1)
		{
			if (gObjIsConnectedGP(this->Player[i].Index) != 0)
			{
				DataSend(this->Player[i].Index, (BYTE*)&pMsg, sizeof(pMsg));
			}
		}
	}
}

void cRoyalBattleGround::KillProc(int aIndex, int bIndex)
{
	LPOBJ lpObj = &gObj[aIndex];
	LPOBJ lpTarget = &gObj[bIndex];

	if (gObjIsConnectedGP(aIndex) == 0 || gObjIsConnectedGP(bIndex) == 0)
	{
		return;
	}
	if (lpObj->Type != OBJECT_USER || lpTarget->Type != OBJECT_USER)
	{
		return;
	}

	if (!this->CheckUserList(aIndex) || !this->CheckUserList(bIndex))
	{
		return;
	}
	this->CountMember();
	this->AddPlayerPoint(aIndex, 1);
	this->SendKillToEventUsers(aIndex, bIndex);
	//this->RewardProc(bIndex);
	this->DelMember(bIndex);
	this->CountMember();
	this->SendPointToEventUsers();
}

void cRoyalBattleGround::AddPlayerPoint(int aIndex, int point)
{
	for (int i = 0; i < RBG_MAX_PLAYER; i++)
	{
		if (this->Player[i].Index == aIndex)
		{
			if (gObjIsConnectedGP(this->Player[i].Index) != 0)
				this->Player[i].Point += point;
		}
	}
}

void cRoyalBattleGround::SetPlayerPoint(int aIndex, int point)
{
	for (int i = 0; i < RBG_MAX_PLAYER; i++)
	{
		if (this->Player[i].Index == aIndex)
		{
			if (gObjIsConnectedGP(this->Player[i].Index) != 0)
				this->Player[i].Point = point;
		}
	}
}

//void cRoyalBattleGround::RewardProc(int aIndex)
//{
//	this->CountMember();
//	LogAdd(LOG_RED, "RewardProc: %d player left -> top %d", this->m_TotalPlayer, this->m_TotalPlayer);
//
//	for (int i = 0; i < this->m_Reward.size(); i++)
//	{
//		if (this->m_Reward[i].Top == this->m_TotalPlayer)
//		{
//			gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "You're top %d!", this->m_TotalPlayer);
//		}
//	}
//}
void cRoyalBattleGround::RecvRequest(BYTE* lpMsg, int aIndex)
{
	PMSG_ROYAL_BATTLE_GROUND_REQUEST_RECV* Data = (PMSG_ROYAL_BATTLE_GROUND_REQUEST_RECV*)lpMsg;
	switch (Data->type)
	{
	case 0x0:
		switch (Data->value)
		{
		case 0x0:
			//req info
			break;
		case 0x1:
			this->MemberRequestJoin(aIndex);
			//join;
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}

}

RBG_Phase* cRoyalBattleGround::GetPhase(int id)
{
	for (int i = 0; i < this->m_RBG_Phases.size(); i++)
	{
		if (this->m_RBG_Phases[i].id == id)
		{
			return &this->m_RBG_Phases[i];
		}
	}

	return 0;
}

void cRoyalBattleGround::MakeZonePhase(int id)
{
	RBG_Phase *phase = this->GetPhase(id);
	if (phase != 0)
	{
		if (!this->m_Zone[0] && !this->m_Zone[1])
		{
			this->SetZone(GetLargeRand() % (256 - phase->W), GetLargeRand() % (256 - phase->H), phase->W, phase->H);
		}
		else
		{
			this->SetZone(this->m_Zone[0] + GetLargeRand() % (256 - phase->W - this->m_Zone[0]),
				this->m_Zone[1] + GetLargeRand() % (256 - phase->H - this->m_Zone[1]), phase->W, phase->H);
		}
		this->m_PhaseLastDrop = GetTickCount();
		this->m_PhaseDropDelay = phase->ItemLoop;
		this->m_PhaseDropCount = phase->ItemCnt;
		this->m_ZoneHP = phase->HP;
		this->m_ZoneHPrate = phase->HPrate;
		this->SendPhaseToEventUsers();
	}
	else
	{

		this->SetZone(0, 0, 255, 255);
		this->m_PhaseLastDrop = GetTickCount();
		this->m_PhaseDropDelay = 999999;
		this->m_PhaseDropCount = 0;
		this->m_ZoneHP = 0;
		this->m_ZoneHPrate = 0;
		this->SendPhaseToEventUsers();
	}
}

void cRoyalBattleGround::SetZone(short X, short Y, short W, short H)
{
	this->m_Zone[0] = X;
	this->m_Zone[1] = Y;
	this->m_Zone[2] = W;
	this->m_Zone[3] = H;
}

void cRoyalBattleGround::MakeDropItem()
{
	if (this->m_RBG_Items.size() == 0 || !this->m_PhaseDropCount || this->m_PhaseLastDrop + this->m_PhaseDropDelay > GetTickCount())
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

			if (gMap[this->m_Map].CheckAttr(x, y, 4) == 0 && gMap[this->m_Map].CheckAttr(x, y, 8) == 0)
			{
				ROYAL_BATTLE_GROUND_ITEM* item = &this->m_RBG_Items[GetLargeRand() % this->m_RBG_Items.size()];

				GDCreateItemSend(this->Player[0].Index, this->m_Map, x, y, item->Index, (BYTE)item->Level, 0, item->Skill, item->Luck, item->Opt, -1, item->Exc, item->Anc, 0, 0, 0, 0, 0);
				break;
			}
		}
		//LogAdd(LOG_BLACK, "Drop at: %d:%d", x, y);
	}
}

void cRoyalBattleGround::DangerousZone()
{
	for (int i = 0; i < RBG_MAX_PLAYER; i++)
	{
		if (this->Player[i].Index != -1)
		{
			if (gObjIsConnectedGP(this->Player[i].Index) != 0)
			{
				if (this->CheckSafeZone(this->Player[i].Index))
				{
					continue;
				}
				this->ZoneHitUser(this->Player[i].Index);
			}
		}
	}
}

bool cRoyalBattleGround::CheckSafeZone(int aIndex)
{
	if (this->m_State != RBG_STATE_BATTLE_STAGE_1 &&
		this->m_State != RBG_STATE_BATTLE_STAGE_2 &&
		this->m_State != RBG_STATE_BATTLE_STAGE_3)
	{
		return true;
	}

	LPOBJ lpObj = &gObj[aIndex];

	if (gObjIsConnectedGP(aIndex) == 0)
		return true;
	//gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "State(%d ~ %d) ", lpObj->X >= this->m_Zone[0] && lpObj->X <= (this->m_Zone[0] + this->m_Zone[2]), lpObj->Y >= this->m_Zone[1] && lpObj->Y <= (this->m_Zone[1] + this->m_Zone[3]));

	if (lpObj->X >= this->m_Zone[0] && lpObj->X <= (this->m_Zone[0] + this->m_Zone[2]) &&
		lpObj->Y >= this->m_Zone[1] && lpObj->Y <= (this->m_Zone[1] + this->m_Zone[3]))
	{
		//this->m_Zone[0] = X;
		//this->m_Zone[1] = Y;
		//this->m_Zone[2] = W;
		//this->m_Zone[3] = H;
		return true;
	}
	return false;
}

void cRoyalBattleGround::ZoneHitUser(int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];

	if (gObjIsConnectedGP(aIndex) == 0)
		return;

	if (this->m_ZoneHP || this->m_ZoneHPrate)
	{
		int TruMauNgoaiBo = (lpObj->Life*this->m_ZoneHPrate);
		TruMauNgoaiBo += this->m_ZoneHP;
		lpObj->Life -= TruMauNgoaiBo;

		gEffectManager.AddEffect(lpObj, 0, EFFECT_SWORD_SLASH, 20, 0, 0, 0, 0);//ok
		gObjectManager.CharacterLifeCheck(lpObj, lpObj, (TruMauNgoaiBo), 0, 0, 0, 0, lpObj->Shield);
	}
}

bool CBBackUpCharacter(int aIndex) // OK
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



bool CBResetCharacter(int aIndex) // OK
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
bool cRoyalBattleGround::BackupAddUser(int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];

	if (gObjIsConnectedGP(aIndex) == 0)
		return false;

	for (int i = 0; i < this->m_BackupCharacter.size(); i++)
	{
		OBJECTSTRUCT bu = this->m_BackupCharacter[i];
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
	CBBackUpCharacter(aIndex);
	//==End
	this->m_BackupCharacter.push_back(nObj);
	return true;
}

OBJECTSTRUCT cRoyalBattleGround::BackupGetUser(int aIndex)
{
	for (int i = 0; i < this->m_BackupCharacter.size(); i++)
	{
		OBJECTSTRUCT cObj = this->m_BackupCharacter[i];
		if (cObj.Index == aIndex)
		{
			return cObj;
		}
	}
	OBJECTSTRUCT nObj;
	nObj.Index = -1;

	return nObj;
}
bool cRoyalBattleGround::BackupDelUser(int aIndex)
{
	for (int i = 0; i < this->m_BackupCharacter.size(); i++)
	{
		OBJECTSTRUCT cObj = this->m_BackupCharacter[i];
		if (cObj.Index == aIndex)
		{
			this->m_BackupCharacter.erase(this->m_BackupCharacter.begin() + i);
			return true;
		}
	}
	return false;
}

bool cRoyalBattleGround::RollBackCharacterInfo(int aIndex)
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
	CBResetCharacter(aIndex);
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

void cRoyalBattleGround::ChangeUserInfo(int aIndex)
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
	//for (n = 0; n < MAX_SKILL_LIST; n++){
	//	gSkillManager.DelSkill(lpObj, n);
	//}

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

	lpObj->LevelUpPoint = 15000;
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

	//LogAdd(LOG_BLUE, "[%d][%s]Cur point: %d", aIndex, lpObj->Name, lpObj->LevelUpPoint);

	return;
}


void cRoyalBattleGround::StartBattle()
{
	this->ClearProc();

	this->m_RemainTime = 10;

	this->m_TargetTime = time(0) + 10;

	this->m_EndTime = this->m_TargetTime +
		this->m_Timer_Open * 60 +
		this->m_Timer_Prepare * 60 +
		this->m_Timer_Stage1 * 60 +
		this->m_Timer_Stage2 * 60 +
		this->m_Timer_Stage3 * 60 +
		this->m_Timer_StageEnd * 60;

	this->SendPhaseToAllUsers();
}

bool cRoyalBattleGround::CheckPrepareZone(int aIndex)
{
	return this->m_State != RBG_STATE_BATTLE_STAGE_1 &&
		this->m_State != RBG_STATE_BATTLE_STAGE_2 &&
		this->m_State != RBG_STATE_BATTLE_STAGE_3 &&
		this->CheckUserList(aIndex);
}

bool cRoyalBattleGround::IsOnMapEvent(int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];

	if (gObjIsConnectedGP(aIndex) == 0)
		return false;

	return lpObj->Map == this->m_Map;
}

void cRoyalBattleGround::UserMoveOut(int aIndex)
{

	LPOBJ lpObj = &gObj[aIndex];

	if (gObjIsConnectedGP(aIndex) == 0)
		return;
	//LogAdd(LOG_RED, "MOVE OUT %d | %d %d", aIndex, lpObj->Map, this->m_Map);

	if (this->m_State >= RBG_STATE_BATTLE_STAGE_1 && this->m_State <= RBG_STATE_BATTLE_END)
	{
		this->KillProc(aIndex, aIndex);
		return;
	}

	this->DelMember(aIndex);
	this->CountMember();
	this->SendPointToEventUsers();
	return;
}

//========== New

bool cRoyalBattleGround::UserDieProc(LPOBJ lpObj, LPOBJ lpTarget)
{
	if (!this->IsOnMapEvent(lpObj->Index))
	{
		return 0;
	}
	if (!RoyalBattleGround.CheckUserList(lpObj->Index))
	{
		return 0;
	}
	if (this->m_State < RBG_STATE_PREPARE && this->m_State > RBG_STATE_BATTLE_STAGE_3)
	{
		return 0;
	}

	RBG_Player* lpUserA = this->GetUser(lpObj->Index);

	if (lpUserA == 0)
	{
		return 0;
	}

	RBG_Player* lpUserB = this->GetUser(lpTarget->Index);

	if (lpUserB == 0)
	{
		return 0;
	}

	lpUserA->Regen++; //HOi SInh

	if (lpUserA->Point > 0)
	{
		lpUserA->Point -= 1;//- Diem Kill
	}
	LogAdd(LOG_RED, "%s Kill %s", lpObj->Name, lpTarget->Name);

	if (lpUserB->Index != lpUserA->Index)
	{
		lpUserB->Point += 1; //Diem Kill	
		this->SendKillToEventUsers(lpUserB->Index, lpUserA->Index);
	}
	//===Chet nhieu hon so lan cho phep
	if (lpUserA->Regen >= 5)
	{
		//this->RewardProc(lpUserA->Index);
		this->DelMember(lpUserA->Index);
	}
	this->CountMember();
	this->SendPointToEventUsers();
	return 1;
}
void cRoyalBattleGround::CalcUserRank() // OK
{

	for (int stt = 0; stt < 10; stt++)
	{
		this->mIndexRank[stt] = -1;
	}
	for (int n = 0; n < RBG_MAX_PLAYER; n++)
	{
		if (OBJECT_RANGE(this->Player[n].Index) == 0)
		{
			continue;
		}

		int rank = RBG_MAX_PLAYER;

		for (int i = 0; i < RBG_MAX_PLAYER; i++)
		{
			if (OBJECT_RANGE(this->Player[i].Index) == 0 || this->Player[i].Live == 0)
			{
				rank--;
				continue;
			}

			if (this->Player[n].Index == this->Player[i].Index)
			{
				rank--;
				continue;
			}

			if (this->Player[n].Point > this->Player[i].Point)
			{
				rank--;
				continue;
			}
			if (this->Player[n].Point == this->Player[i].Point && this->Player[n].Regen < this->Player[i].Regen)
			{
				rank--;
				continue;
			}
			if (this->Player[n].Point == this->Player[i].Point && n < i)
			{
				rank--;
				continue;
			}
		}

		this->Player[n].Rank = (rank + 1);

		if (this->Player[n].Rank >= 1 && this->Player[n].Rank <= 10)
		{
			int Stt = this->Player[n].Rank - 1;
			this->mIndexRank[Stt] = n;
			//LogAdd(LOG_RED, "GETRANK %d ~ %d", this->mIndexRank[Stt], n);
		}
		///LogAdd(LOG_BLUE, "[BXH] %s R(%d), K(%d), L(%d),Re(%d)", this->User[n].name, this->User[n].Rank, this->User[n].Score, this->User[n].Live, this->User[n].Regen);
	}
	//this->SendUserData();
}
RBG_Player* cRoyalBattleGround::GetUser(int aIndex) // OK
{
	if (OBJECT_RANGE(aIndex) == 0)
	{
		return 0;
	}
	for (int i = 0; i < RBG_MAX_PLAYER; i++)
	{
		if (this->Player[i].Index == aIndex)
		{
			return &this->Player[i];
		}
	}

	return 0;
}


bool cRoyalBattleGround::GetPosRandomFromBo(int* x, int* y)
{
	int px, py;
	while (true)
	{
		px = this->m_Zone[0] + (GetLargeRand() % ((this->m_Zone[2] + this->m_Zone[0]) - this->m_Zone[0]));
		py = this->m_Zone[1] + (GetLargeRand() % ((this->m_Zone[3] + this->m_Zone[1]) - this->m_Zone[1]));

		if (gMap[this->m_Map].CheckAttr(px, py, 4) == 0 && gMap[this->m_Map].CheckAttr(px, py, 8) == 0)
		{
			//gObjTeleport(lpObj->Index, this->m_Map, x, y);
			(*x) = px;
			(*y) = py;
			return 1;
			break;
		}
	}
	return 0;
}

//==Hoi SInh
bool cRoyalBattleGround::GetUserRespawnLocation(LPOBJ lpObj, int* gate, int* map, int* x, int* y, int* dir, int* level) // OK
{
	if (this->m_Enable == 0)
	{
		return 0;
	}


	if (this->m_State < RBG_STATE_BATTLE_STAGE_1 && this->m_State > RBG_STATE_BATTLE_STAGE_3)
	{
		return 0;
	}

	RBG_Player* lpUser = this->GetUser(lpObj->Index);

	if (lpUser == 0)
	{
		return 0;
	}

	if (this->m_RegenMax != -1 && lpUser->Regen >= this->m_RegenMax)
	{
		if (gGate.GetGate(this->m_GateOut, gate, map, x, y, dir, level) != 0)
		{
			this->DelMember(lpObj->Index);
			this->CountMember();
			this->SendPointToEventUsers();
			return 1;
		}

	}
	else
	{
		int xX, yY;
		if (this->GetPosRandomFromBo(&xX, &yY) == 0)
		{
			return 1;
		}
		(*gate) = 0;
		(*map) = lpObj->Map;
		(*x) = xX;
		(*y) = yY;
		(*dir) = 3;
		(*level) = 0;
		//== Tele vao Event
		//EventTeleport(lpObj->Index, this->m_Map, xX, yY);
		//LogAdd(LOG_RED, "[SinhTon] GetUserRespawnLocatio %s Map %d (%d/%d)", lpObj->Name,lpObj->Map,xX,yY);
		return 1;
	}


	return 0;
}
//==Thuong Theo Moi Vong
void cRoyalBattleGround::ThuongCoin(int State) // OK
{
}


void cRoyalBattleGround::EventTeleport(int aIndex, int map, int x, int y) // OK
{
	if (OBJECT_RANGE(aIndex) == 0)
	{
		return;
	}

	if (MAP_RANGE(map) == 0)
	{
		return;
	}

	LPOBJ lpObj = &gObj[aIndex];

	lpObj->State = OBJECT_DELCMD;


	lpObj->X = x;
	lpObj->Y = y;
	lpObj->TX = x;
	lpObj->TY = y;
	lpObj->Map = map;
	lpObj->PathCount = 0;
	lpObj->Teleport = 0;
	lpObj->ViewState = 0;
	lpObj->MiniMapState = 0;
	lpObj->MiniMapValue = -1;

	gObjClearViewport(lpObj);

	gMove.GCTeleportSend(aIndex, 1, lpObj->Map, (BYTE)lpObj->X, (BYTE)lpObj->Y, lpObj->Dir);

	gObjViewportListProtocolCreate(lpObj);

	gObjectManager.CharacterUpdateMapEffect(lpObj);

	lpObj->RegenMapNumber = lpObj->Map;
	lpObj->RegenMapX = (BYTE)lpObj->X;
	lpObj->RegenMapY = (BYTE)lpObj->Y;
	lpObj->RegenOk = 1;
}