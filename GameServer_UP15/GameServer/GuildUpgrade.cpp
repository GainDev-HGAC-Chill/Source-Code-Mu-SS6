#include "stdafx.h"
#include "GuildUpgrade.h"
#include "Util.h"
#include "Log.h"
#include "Guild.h"
#include "User.h"
#include "GuildClass.h"
#include "MemScript.h"
#include "ItemManager.h"
#include "ESProtocol.h"
#include "DSProtocol.h"
#include "Notice.h"
#include "ServerInfo.h"
#if(CUSTOM_GUILD_UPGRADE == TRUE)

cGuildUpgrade GuildUpgrade;

cGuildUpgrade::cGuildUpgrade()
{
}

cGuildUpgrade::~cGuildUpgrade()
{
}
void cGuildUpgrade::Load(char* path)
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

	this->d_GuildLevel.clear();
	this->d_DevoteItem.clear();
	this->d_ShopItem.clear();

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
				}
				else if (section == 1)
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}

					GG_GUILD_LEVEL info;

					memset(&info, 0, sizeof(info));

					info.Level = lpMemScript->GetNumber();

					info.Devote = lpMemScript->GetAsNumber();

					info.Exp = lpMemScript->GetAsNumber();

					info.Zen = lpMemScript->GetAsNumber();

					this->d_GuildLevel.insert(std::pair<int, GG_GUILD_LEVEL>(info.Level, info));
				}
				else if (section == 2)
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}

					GG_DEVOTE_ITEM info;

					memset(&info, 0, sizeof(info));

					info.Item = lpMemScript->GetNumber() * 512 + lpMemScript->GetAsNumber();

					info.Level = lpMemScript->GetAsNumber();

					info.Devote = lpMemScript->GetAsNumber();

					this->d_DevoteItem.push_back(info);
				}
				else if (section == 3)
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}

					GG_SHOP_ITEM info;

					memset(&info, 0, sizeof(info));

					info.Item = lpMemScript->GetNumber() * 512 + lpMemScript->GetAsNumber();

					info.Level = lpMemScript->GetAsNumber();

					info.GuildLevel = lpMemScript->GetAsNumber();

					info.Devote = lpMemScript->GetAsNumber();

					info.Zen = lpMemScript->GetAsNumber();

					this->d_ShopItem.push_back(info);
				}
				else
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}
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
void cGuildUpgrade::RecvRequest(PMSG_GUILD_UPGRADE_REQUEST_RECV* lpMsg, int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];

	switch (lpMsg->type)
	{
	case 0:
		switch (lpMsg->value)
		{
		case 0: //request info
			break;
		case 1: //request me info
			this->SendMeInfo(aIndex);
			break;
		}
		break;
	case 1:
		switch (lpMsg->value)
		{
		case 0: //request guild ranking
			this->SendGuildRanking(aIndex);
			break;
		}
		break;
	case 2: //tab myguild
		switch (lpMsg->value)
		{
		case 0: //request my guild list
			this->SendMyGuildInfo(aIndex);
			break;
		}
		break;
	case 3: //tab devote
		switch (lpMsg->value)
		{
		case 0: //request devote list
			this->SendDevoteItemInfo(aIndex);
			break;
		}
		break;
	case 4: //tab shop
		switch (lpMsg->value)
		{
		case 0: //request shop list
			this->SendShopItemInfo(aIndex);
			break;
		}
		break;
	case 5:
		this->DevoteItem(aIndex, lpMsg->value);
		break;
	case 6:
		this->BuyShopItem(aIndex, lpMsg->value);
		break;
	}
}
void cGuildUpgrade::DevoteItem(int aIndex, int slot)
{

	LPOBJ lpObj = &gObj[aIndex];

	if (gObjIsConnectedGP(aIndex) == 0 || lpObj->GuildNumber == 0)
	{
		return;
	}
	if (lpObj->Interface.use != 0 || lpObj->ChaosLock != 0 || lpObj->Lock)
	{
		return;
	}
	//------------------------------------------------
	int invMax = gItemManager.GetInventoryMaxValue(lpObj);
	if (slot < 0 || slot >= invMax || this->d_DevoteItem.size() == 0)
	{
		return;
	}
	if (!lpObj->Inventory[slot].IsItem())
	{
		return;
	}

	if (lpObj->Guild->LevelDevote >= gServerInfo.m_GioiHanUpGuild)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Bạn đã đạt cấp độ tối đa cấp %d!", gServerInfo.m_GioiHanUpGuild);
		return;
	}
	for (int n = 0; n < this->d_DevoteItem.size(); n++)
	{
		if (this->d_DevoteItem[n].Item == lpObj->Inventory[slot].m_Index &&
			this->d_DevoteItem[n].Level == lpObj->Inventory[slot].m_Level)
		{
			gItemManager.InventoryDelItem(lpObj->Index, slot);
			gItemManager.GCItemDeleteSend(lpObj->Index, slot, 1);
			this->AddDevote(aIndex, this->d_DevoteItem[n].Devote, this->d_DevoteItem[n].Devote);
			this->SendDevoteResult(aIndex, 1);
			break;
		}
	}
	//------------------------------------------------
	//lpObj->IsChaosMixCompleted = false;
}
void cGuildUpgrade::AddDevote(int aIndex, int Devote, int GuildDevote)
{
	LPOBJ lpObj = &gObj[aIndex];

	if (gObjIsConnectedGP(aIndex) == 0 || lpObj->GuildNumber == 0)
	{
		return;
	}

	if (lpObj->GuildNumber <= 0 || lpObj->Guild == NULL) {
		return;
	}

	SDHP_GUILD_UPGRADE_DEVOTE_UPDATE pMsg;
	pMsg.h.set(0x39, sizeof(SDHP_GUILD_UPGRADE_DEVOTE_UPDATE));
	pMsg.Devote = 0;
	for (int i = 0; i < MAX_GUILD_USER; i++) {
		if (strcmp(lpObj->Name, lpObj->Guild->Names[i]) == 0) {
			lpObj->Guild->Devote[i] += Devote;
			pMsg.Devote = lpObj->Guild->Devote[i];
			break;
		}
	}
	if (GuildDevote)
	{
		lpObj->Guild->TotalDevote += GuildDevote;
		int newLevel = this->GetLevelDevote(lpObj->Guild->TotalDevote);
		if (newLevel != lpObj->Guild->LevelDevote)
		{
			lpObj->Guild->LevelDevote = newLevel;

			for (int n = OBJECT_START_USER; n < MAX_OBJECT; n++)
			{
				if (gObjIsConnectedGP(n) != 0 && gObj[n].Type == OBJECT_USER)
				{
					if (strcmp(gObj[n].GuildName, lpObj->Guild->Name) == 0) //if (gObj[n].GuildNumber == lpObj->GuildNumber)
					{
						this->AddDevoteEff(&gObj[n]);
					}
				}
			}
		}
	}
	pMsg.GuildDevote = lpObj->Guild->TotalDevote;
	pMsg.GuildLevel = lpObj->Guild->LevelDevote;

	memcpy(pMsg.Member, lpObj->Name, sizeof(pMsg.Member));

	ESDataSend((BYTE*)&pMsg, pMsg.h.size);
	this->SendMeInfo(aIndex);
}

void cGuildUpgrade::SendDevoteResult(int aIndex, int result)
{
	LPOBJ lpObj = &gObj[aIndex];

	if (gObjIsConnectedGP(aIndex) == 0 || lpObj->GuildNumber == 0)
	{
		return;
	}

	PSWMSG_GUILD_UPGRADE_MY_GUILD_SEND pMsg = { 0 };

	pMsg.header.set(0xA8, 0x05, sizeof(pMsg));

	pMsg.count = result;

	DataSend(aIndex, (BYTE*)&pMsg, sizeof(pMsg));

}
void cGuildUpgrade::SendGuildRanking(int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];

	if (gObjIsConnectedGP(aIndex) == 0 || lpObj->GuildNumber == 0)
	{
		return;
	}
	gGuildClass.SendListGuild(aIndex);
}

int cGuildUpgrade::GetNextDevote(int Level)
{
	std::map<int, GG_GUILD_LEVEL>::iterator Itor = this->d_GuildLevel.find(Level);
	if (Itor == this->d_GuildLevel.end())
	{
		return 0;
	}
	std::map<int, GG_GUILD_LEVEL>::iterator Itor2 = this->d_GuildLevel.find(Level + 1);
	if (Itor2 == this->d_GuildLevel.end())
	{
		return Itor->second.Devote;
	}
	return Itor2->second.Devote;
}
int cGuildUpgrade::GetLevelDevote(int Devote)
{
	int highest = 0;
	for (std::map<int, GG_GUILD_LEVEL>::iterator it = this->d_GuildLevel.begin(); it != this->d_GuildLevel.end(); ++it)
	{
		if (it->second.Devote <= Devote) {
			if (highest < it->first) {
				highest = it->first;
			}
		}
	}
	return highest;
}
void cGuildUpgrade::SendMyGuildInfo(int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];

	if (gObjIsConnectedGP(aIndex) == 0 || lpObj->GuildNumber == 0)
	{
		return;
	}

	GUILD_INFO_STRUCT * lpGuild = gGuildClass.SearchGuild_Number(lpObj->GuildNumber);

	if (lpGuild != NULL)
	{
		BYTE send[2048];

		PSWMSG_GUILD_UPGRADE_MY_GUILD_SEND pMsg = { 0 };

		pMsg.header.set(0xA8, 0x02, 0);
		int size = sizeof(pMsg);
		pMsg.count = 0;
		pMsg.Level = lpGuild->LevelDevote;
		pMsg.TotalDevote = lpGuild->TotalDevote;
		pMsg.NextDevote = this->GetNextDevote(lpGuild->LevelDevote);

		GUMyGuildMember info;

		for (int n = 0; n < MAX_GUILD_USER; n++)
		{
			if (lpObj->Guild->Use[n] == 0)
			{
				continue;
			}
			memcpy(info.name, lpGuild->Names[n], sizeof(info.name));

			info.devote = lpGuild->Devote[n];
			info.status = lpGuild->GuildStatus[n];

			memcpy(&send[size], &info, sizeof(info));
			size += sizeof(info);
			pMsg.count++;
		}

		if (pMsg.count > 0)
		{
			pMsg.header.size[0] = SET_NUMBERHB(size);
			pMsg.header.size[1] = SET_NUMBERLB(size);

			memcpy(send, &pMsg, sizeof(pMsg));

			DataSend(aIndex, send, size);
		}
	}
}


void cGuildUpgrade::SendDevoteItemInfo(int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];

	if (gObjIsConnectedGP(aIndex) == 0 || lpObj->GuildNumber == 0)
	{
		return;
	}
	if (this->d_DevoteItem.size())
	{
		BYTE send[2048];

		PSWMSG_GUILD_UPGRADE_COUNT_SEND pMsg = { 0 };

		pMsg.header.set(0xA8, 0x3, 0);

		int size = sizeof(pMsg);
		pMsg.count = 0;

		GG_DEVOTE_ITEM info;

		for (int n = 0; n < this->d_DevoteItem.size(); n++)
		{
			info.Item = this->d_DevoteItem[n].Item;
			info.Level = this->d_DevoteItem[n].Level;
			info.Devote = this->d_DevoteItem[n].Devote;

			memcpy(&send[size], &info, sizeof(info));
			size += sizeof(info);
			pMsg.count++;
		}

		if (pMsg.count > 0)
		{
			pMsg.header.size[0] = SET_NUMBERHB(size);
			pMsg.header.size[1] = SET_NUMBERLB(size);

			memcpy(send, &pMsg, sizeof(pMsg));

			DataSend(aIndex, send, size);
		}
	}
}
void cGuildUpgrade::SendShopItemInfo(int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];

	if (gObjIsConnectedGP(aIndex) == 0 || lpObj->GuildNumber == 0)
	{
		return;
	}
	if (this->d_ShopItem.size())
	{
		BYTE send[2048];

		PSWMSG_GUILD_UPGRADE_COUNT_SEND pMsg = { 0 };

		pMsg.header.set(0xA8, 0x4, 0);
		int size = sizeof(pMsg);
		pMsg.count = 0;

		GG_SHOP_ITEM info;

		for (int n = 0; n < this->d_ShopItem.size(); n++)
		{
			info.Item = this->d_ShopItem[n].Item;
			info.Level = this->d_ShopItem[n].Level;
			info.GuildLevel = this->d_ShopItem[n].GuildLevel;
			info.Devote = this->d_ShopItem[n].Devote;
			info.Zen = this->d_ShopItem[n].Zen;

			memcpy(&send[size], &info, sizeof(info));
			size += sizeof(info);
			pMsg.count++;
		}

		if (pMsg.count > 0)
		{
			pMsg.header.size[0] = SET_NUMBERHB(size);
			pMsg.header.size[1] = SET_NUMBERLB(size);

			memcpy(send, &pMsg, sizeof(pMsg));

			DataSend(aIndex, send, size);
		}
	}
}

void cGuildUpgrade::SendMeInfo(int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];

	if (gObjIsConnectedGP(aIndex) == 0 || lpObj->GuildNumber == 0)
	{
		return;
	}
	GUILD_INFO_STRUCT * lpGuild = gGuildClass.SearchGuild_Number(lpObj->GuildNumber);

	if (lpGuild != NULL)
	{
		PSWMSG_GUILD_UPGRADE_ME_SEND pMsg = { 0 };

		pMsg.header.set(0xA8, 0x0, sizeof(pMsg));
		pMsg.GuildLevel = lpGuild->LevelDevote;
		pMsg.Devote = 0;
		for (int i = 0; i < MAX_GUILD_USER; i++) {
			if (strcmp(lpObj->Name, lpGuild->Names[i]) == 0) {
				pMsg.Devote = lpGuild->Devote[i];
				break;
			}
		}
		DataSend(aIndex, (LPBYTE)&pMsg, sizeof(pMsg));
	}
}
void cGuildUpgrade::BuyShopItem(int aIndex, int Slot)
{
	LPOBJ lpObj = &gObj[aIndex];

	if (gObjIsConnectedGP(aIndex) == 0 || lpObj->GuildNumber == 0)
	{
		return;
	}

	//anti dupe
	if (lpObj->Interface.type == INTERFACE_CHAOS_BOX
		|| lpObj->Interface.type == INTERFACE_TRADE
		|| lpObj->Interface.type == INTERFACE_WAREHOUSE
		|| lpObj->Interface.type == INTERFACE_PERSONAL_SHOP
		|| lpObj->Interface.type == INTERFACE_CASH_SHOP
		|| lpObj->Interface.type == INTERFACE_TRAINER
		|| lpObj->Interface.use != 0
		|| lpObj->State == OBJECT_DELCMD
		|| lpObj->DieRegen != 0
		|| lpObj->Teleport != 0
		|| lpObj->PShopOpen != 0
		|| lpObj->SkillSummonPartyTime != 0)
	{
		return;
	}

	if (Slot < 0 || Slot >= this->d_ShopItem.size())
	{
		return;
	}
	GG_SHOP_ITEM* BuyItem = &this->d_ShopItem[Slot];
	//find my slot in Guild
	int me = -1;
	for (int i = 0; i < MAX_GUILD_USER; i++) {
		if (strcmp(lpObj->Name, lpObj->Guild->Names[i]) == 0) {
			me = i;
			break;
		}
	}
	if (me != -1 &&
		lpObj->Guild->LevelDevote < BuyItem->GuildLevel ||
		lpObj->Guild->Devote[me] < BuyItem->Devote ||
		lpObj->Money < BuyItem->Zen)
	{
		return;
	}
	// check slot free
	ITEM_INFO ItemInfo;

	if (gItemManager.GetInfo(BuyItem->Item, &ItemInfo) == 0)
	{
		return;
	}
	if (gItemManager.CheckItemInventorySpace(lpObj, ItemInfo.Width, ItemInfo.Height) == 0xFF)
	{
		return;
	}

	GDCreateItemSend(lpObj->Index, 0xEB, 0, 0, BuyItem->Item, BuyItem->Level, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0);
	//send item to player

	this->AddDevote(aIndex, -BuyItem->Devote, 0);
	this->SendDevoteResult(aIndex, 2);
	lpObj->Money -= BuyItem->Zen;

	GCMoneySend(lpObj->Index, lpObj->Money);
}

void cGuildUpgrade::RemoveDevoteEff(LPOBJ lpObj)
{
	gEffectManager.DelEffect(lpObj, EFFECT_CHRISTMAS1);
}
void cGuildUpgrade::AddDevoteEff(LPOBJ lpObj)
{
	if (lpObj->GuildNumber == 0)
	{
		return;
	}
	int highest = -1;
	GG_GUILD_LEVEL *dl = 0;

	for (std::map<int, GG_GUILD_LEVEL>::iterator it = this->d_GuildLevel.begin(); it != this->d_GuildLevel.end(); ++it)
	{
		if (it->second.Devote <= lpObj->Guild->TotalDevote) {
			if (highest < it->first) {
				highest = it->first;
				dl = &it->second;
			}
		}
	}
	if (highest != -1 && dl != 0)
	{
		if (lpObj->Guild->LevelDevote == 1)
		{
			this->RemoveDevoteEff(lpObj);
			gEffectManager.AddEffect(lpObj, 0, EFFECT_GUILD_BUFF_1, 0, dl->Exp, dl->Zen, 0, 0);
		}
		else if (lpObj->Guild->LevelDevote == 2)
		{
			this->RemoveDevoteEff(lpObj);
			gEffectManager.DelEffect(lpObj, EFFECT_GUILD_BUFF_1);
			gEffectManager.AddEffect(lpObj, 0, EFFECT_GUILD_BUFF_2, 0, dl->Exp, dl->Zen, 0, 0);
		}
		else if (lpObj->Guild->LevelDevote == 3)
		{
			this->RemoveDevoteEff(lpObj);
			gEffectManager.DelEffect(lpObj, EFFECT_GUILD_BUFF_2);
			gEffectManager.AddEffect(lpObj, 0, EFFECT_GUILD_BUFF_3, 0, dl->Exp, dl->Zen, 0, 0);
		}
		else if (lpObj->Guild->LevelDevote == 4)
		{
			this->RemoveDevoteEff(lpObj);
			gEffectManager.DelEffect(lpObj, EFFECT_GUILD_BUFF_3);
			gEffectManager.AddEffect(lpObj, 0, EFFECT_GUILD_BUFF_4, 0, dl->Exp, dl->Zen, 0, 0);
		}
		else if (lpObj->Guild->LevelDevote == 5)
		{
			this->RemoveDevoteEff(lpObj);
			gEffectManager.DelEffect(lpObj, EFFECT_GUILD_BUFF_4);
			gEffectManager.AddEffect(lpObj, 0, EFFECT_GUILD_BUFF_5, 0, dl->Exp, dl->Zen, 0, 0);
		}
	}
}
#endif