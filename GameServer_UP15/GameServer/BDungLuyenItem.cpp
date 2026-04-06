#include "stdafx.h"
#include "BDungLuyenItem.h"
#include "Monster.h"
#include "ItemManager.h"
#include "ObjectManager.h"
#include "SkillManager.h"
#include "EffectManager.h"
#include "MasterSkillTree.h"
#include "ServerInfo.h"
#include "MemScript.h"
#include "Util.h"
#include "CashShop.h"
#include "Message.h"
#include "Notice.h"
#include "Trade.h"
#include "DSProtocol.h"
#include "Log.h"
#include "ItemLevel.h"
#include "GameMain.h"
#include "CSProtocol.h"
#include "MonsterSetBase.h"
#include "MapServerManager.h"

#if(CUSTOM_DUNGLUYENITEM)

BDungLuyenItem gBDungLuyenItem;

BDungLuyenItem::BDungLuyenItem()
{
	this->Enable = 0;
	this->mNPCData = new NPC_DATA;
}

BDungLuyenItem::~BDungLuyenItem()
{

}

void BDungLuyenItem::SetNPC()
{
	if (gBDungLuyenItem.Enable)
	{
		MONSTER_SET_BASE_INFO info;
		memset(&info, 0, sizeof(info));

		info.Type = 0;
		info.MonsterClass = gBDungLuyenItem.mNPCData->NPCClass;
		info.Map = gBDungLuyenItem.mNPCData->NPCMap;
		info.Dis = 0;
		info.Dir = gBDungLuyenItem.mNPCData->NPCDir;
		info.X = gBDungLuyenItem.mNPCData->NPCX;
		info.Y = gBDungLuyenItem.mNPCData->NPCY;

		gMonsterSetBase.SetInfo(info);
	}
}
void BDungLuyenItem::LoadConfig(char* FilePath)
{
	this->m_GroupDungLuyenData.clear();
	this->Enable = 0;
	this->mNPCData->Clear();

	pugi::xml_document file;
	pugi::xml_parse_result res = file.load_file(FilePath);
	if (res.status != pugi::status_ok) {
		ErrorMessageBox("File %s load fail. Error: %s", FilePath, res.description());
		return;
	}
	pugi::xml_node oDungLuyenItem = file.child("DungLuyenItem");
	this->Enable = oDungLuyenItem.attribute("Enable").as_int();

	//= Mess Load
	pugi::xml_node Message = oDungLuyenItem.child("Message");
	for (pugi::xml_node msg = Message.child("Msg"); msg; msg = msg.next_sibling())
	{
		DUNGLUYEN_MSG info;

		info.Index = msg.attribute("Index").as_int();

		strncpy_s(info.Message, msg.attribute("Text").as_string(), sizeof(info.Message));

		this->m_MessageInfoBP.insert(std::pair<int, DUNGLUYEN_MSG>(info.Index, info));
	}

	//= Config NPC
	pugi::xml_node EventConfigNPC = oDungLuyenItem.child("NPC");
	this->mNPCData->NPCClass = EventConfigNPC.attribute("NPCClass").as_int();
	this->mNPCData->NPCMap = EventConfigNPC.attribute("NPCMap").as_int();
	this->mNPCData->NPCX = EventConfigNPC.attribute("NPCX").as_int();
	this->mNPCData->NPCY = EventConfigNPC.attribute("NPCY").as_int();
	this->mNPCData->NPCDir = EventConfigNPC.attribute("NPCDir").as_int();
	//=== Load Data
	int mIndex = 0;
	for (pugi::xml_node GroupDungLuyen = oDungLuyenItem.child("GroupDungLuyen"); GroupDungLuyen; GroupDungLuyen = GroupDungLuyen.next_sibling())
	{
		GROUPDUNGLUYEN_DATA infoGroup;
		infoGroup.Index = mIndex++;
		infoGroup.Notice = GroupDungLuyen.attribute("Notice").as_int();
		strncpy_s(infoGroup.Name, GroupDungLuyen.attribute("Name").as_string(), sizeof(infoGroup.Name));
		infoGroup.Rate = GroupDungLuyen.attribute("Rate").as_int();
		infoGroup.TypeFail = GroupDungLuyen.attribute("TypeFail").as_int();
		//Config ItemChinh
		pugi::xml_node ItemChinh = GroupDungLuyen.child("ItemChinh");
		infoGroup.ItemChinh.IndexItem = SafeGetItem(GET_ITEM(ItemChinh.attribute("Type").as_int(), ItemChinh.attribute("Index").as_int()));
		infoGroup.ItemChinh.Level = ItemChinh.attribute("Level").as_int();
		infoGroup.ItemChinh.Skill = ItemChinh.attribute("Skill").as_int();
		infoGroup.ItemChinh.Luck = ItemChinh.attribute("Luck").as_int();
		infoGroup.ItemChinh.Option = ItemChinh.attribute("Option").as_int();
		infoGroup.ItemChinh.Exc = ItemChinh.attribute("Exc").as_int();

		infoGroup.ItemPhu.clear();
		pugi::xml_node ItemPhu = GroupDungLuyen.child("ItemPhu");
		for (pugi::xml_node ItemReq = ItemPhu.child("Item"); ItemReq; ItemReq = ItemReq.next_sibling())
		{
			ITEM_INFO_DATA infoReq;
			infoReq.IndexItem = SafeGetItem(GET_ITEM(ItemReq.attribute("Type").as_int(), ItemReq.attribute("Index").as_int()));
			infoReq.Level = ItemReq.attribute("Level").as_int();
			infoReq.Skill = ItemReq.attribute("Skill").as_int();
			infoReq.Luck = ItemReq.attribute("Luck").as_int();
			infoReq.Option = ItemReq.attribute("Option").as_int();
			infoReq.Exc = ItemReq.attribute("Exc").as_int();
			infoReq.Dur = ItemReq.attribute("Dur").as_int();
			infoGroup.ItemPhu.push_back(infoReq);
		}

		infoGroup.ItemPhu2.clear();
		pugi::xml_node ItemPhu2 = GroupDungLuyen.child("ItemPhu2");
		for (pugi::xml_node ItemReq2 = ItemPhu2.child("Item"); ItemReq2; ItemReq2 = ItemReq2.next_sibling())
		{
			ITEM_INFO_DATA2 infoReq2;
			infoReq2.IndexItem = SafeGetItem(GET_ITEM(ItemReq2.attribute("Type").as_int(), ItemReq2.attribute("Index").as_int()));
			infoReq2.Level = ItemReq2.attribute("Level").as_int();
			infoReq2.Skill = ItemReq2.attribute("Skill").as_int();
			infoReq2.Luck = ItemReq2.attribute("Luck").as_int();
			infoReq2.Option = ItemReq2.attribute("Option").as_int();
			infoReq2.Exc = ItemReq2.attribute("Exc").as_int();
			infoReq2.Dur = ItemReq2.attribute("Dur").as_int();
			infoGroup.ItemPhu2.push_back(infoReq2);
		}

		infoGroup.ItemPhu3.clear();
		pugi::xml_node ItemPhu3 = GroupDungLuyen.child("ItemPhu3");
		for (pugi::xml_node ItemReq3 = ItemPhu3.child("Item"); ItemReq3; ItemReq3 = ItemReq3.next_sibling())
		{
			ITEM_INFO_DATA3 infoReq3;
			infoReq3.IndexItem = SafeGetItem(GET_ITEM(ItemReq3.attribute("Type").as_int(), ItemReq3.attribute("Index").as_int()));
			infoReq3.Level = ItemReq3.attribute("Level").as_int();
			infoReq3.Skill = ItemReq3.attribute("Skill").as_int();
			infoReq3.Luck = ItemReq3.attribute("Luck").as_int();
			infoReq3.Option = ItemReq3.attribute("Option").as_int();
			infoReq3.Exc = ItemReq3.attribute("Exc").as_int();
			infoReq3.Dur = ItemReq3.attribute("Dur").as_int();
			infoGroup.ItemPhu3.push_back(infoReq3);
		}



		//Config KetQua
		pugi::xml_node ItemKetQua = GroupDungLuyen.child("ItemKetQua");
		infoGroup.ItemKetQua.IndexItem = SafeGetItem(GET_ITEM(ItemKetQua.attribute("Type").as_int(), ItemKetQua.attribute("Index").as_int()));
		infoGroup.ItemKetQua.Level = ItemKetQua.attribute("Level").as_int();
		infoGroup.ItemKetQua.Skill = ItemKetQua.attribute("Skill").as_int();
		infoGroup.ItemKetQua.Luck = ItemKetQua.attribute("Luck").as_int();
		infoGroup.ItemKetQua.Option = ItemKetQua.attribute("Option").as_int();
		infoGroup.ItemKetQua.Exc = ItemKetQua.attribute("Exc").as_int();

		this->m_GroupDungLuyenData.insert(std::pair<int, GROUPDUNGLUYEN_DATA>(infoGroup.Index, infoGroup));

	}

	LogAdd(LOG_BLUE, "[DungLuyenItem] Load OK Enable = %d, Size %d", this->Enable, this->m_GroupDungLuyenData.size());
}


char* BDungLuyenItem::GetMessage(int index) // OK
{
	std::map<int, DUNGLUYEN_MSG>::iterator it = this->m_MessageInfoBP.find(index);

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
void BDungLuyenItem::SetStateInterface(int aIndex, int Type)
{

	if (Type == 1)
	{
		gObj[aIndex].Interface.state = 1;
		gObj[aIndex].Interface.use = 1;
		gObj[aIndex].Interface.type = INTERFACE_DUNGLUYENITEM;
		gObj[aIndex].Transaction = 0;
		gObjInventoryTransaction(aIndex);
	}
	else
	{


		if (gObj[aIndex].DL_StatusMix > 0) //SAVE Neu Da Mix
		{
			if (gObj[aIndex].DL_StatusMix == 1)
			{
				gItemManager.InventoryInsertItem(aIndex, gObj[aIndex].DL_ItemChinh);
			}
			else
			{
				gItemManager.InventoryInsertItem(aIndex, gObj[aIndex].DL_ItemKetQua);
			}
		}
		else
		{
			gObjInventoryRollback(aIndex);
		}

		//==Clear Cache
		gObj[aIndex].DL_IndexMix = -1;
		gObj[aIndex].DL_ItemChinh.Clear();
		gObj[aIndex].DL_ItemKetQua.Clear();
		gObj[aIndex].DL_ItemPhu[0].Clear();
		gObj[aIndex].DL_ItemPhu[1].Clear();
		gObj[aIndex].DL_ItemPhu[2].Clear();
		gObj[aIndex].DL_StatusMix = -1;
		SendInfoItemCache(aIndex);
		gItemManager.GCItemListSend(aIndex);
		gObjectManager.CharacterMakePreviewCharSet(aIndex);
		gItemManager.GCItemEquipmentSend(aIndex);

		gObj[aIndex].Interface.use = 0;
		gObj[aIndex].Interface.type = INTERFACE_NONE;
		gObj[aIndex].Interface.state = 0;
		gObj[aIndex].TargetNumber = -1;

	}
}

void BDungLuyenItem::ProcMix(int aIndex)
{

	if (!OBJMAX_RANGE(aIndex))
	{
		return;
	}


	LPOBJ lpObj = &gObj[aIndex];

	if (lpObj->Type != OBJECT_USER || lpObj->m_OfflineMode != 0 || lpObj->IsFakeOnline != 0 || !this->Enable)
	{
		return;

	}

	if (lpObj->Interface.type != INTERFACE_DUNGLUYENITEM || lpObj->DL_IndexMix == -1)
	{

		return;
	}
	if (!lpObj->DL_ItemChinh.IsItem()
		|| !lpObj->DL_ItemChinh.IsItem()
		|| !lpObj->DL_ItemKetQua.IsItem()
		|| !lpObj->DL_ItemPhu[0].IsItem()
		|| !lpObj->DL_ItemPhu[1].IsItem()
		|| !lpObj->DL_ItemPhu[2].IsItem())
	{

		return;
	}
	std::map<int, GROUPDUNGLUYEN_DATA>::iterator it = this->m_GroupDungLuyenData.find(lpObj->DL_IndexMix);

	if (it == this->m_GroupDungLuyenData.end())
	{

		return;
	}
	if (gObj[aIndex].DL_StatusMix > 0)
	{
		gNotice.GCNoticeSend(aIndex, 0, 0, 0, 0, 0, 0, this->GetMessage(6));// That Bai
		return;
	}


	gObj[aIndex].DL_StatusMix = 1;

	gObjInventoryCommit(aIndex); //Save Trang Thai Da Mix
	//==Clear Item Phu
	for (int n = 0; n < 3; n++)
	{
		lpObj->DL_ItemPhu[n].Clear();
	}
	int RandomRate = (GetLargeRand() % 100);
	//LogAdd(LOG_RED, "[%s] Mix Rate %d / %d", it->second.Name,RandomRate, it->second.Rate);
	char tmp[255];
	char tmp2[255];
	if (RandomRate <= it->second.Rate)
	{
		gObj[aIndex].DL_StatusMix = 2; //Set Trang Thai neu co thoat ra thi van luu item Ket qua
		//==Clear Item Chinh Neu Mix Thanh Cong
		lpObj->DL_ItemChinh.Clear();

		//==Thong Bao

		if (it->second.Notice == 1)
		{ //Thong Bao trong Sub
			gNotice.GCNoticeSend(lpObj->Index, 0, 0, 0, 0, 0, 0, this->GetMessage(5), lpObj->Name, it->second.Name);
		}
		else if (it->second.Notice == 2)
		{ //Thong Bao Toan Sub
			wsprintf(tmp, this->GetMessage(5), lpObj->Name, it->second.Name);
			GDGlobalNoticeSend(gMapServerManager.GetMapServerGroup(), 0, 0, 0, 0, 0, 0, tmp);
		}
		else if (it->second.Notice == 3)
		{ //Thong Bao Toan Sub
			wsprintf(tmp, this->GetMessage(5), lpObj->Name, it->second.Name);
			wsprintf(tmp2, "[%s] %s", gServerInfo.m_ServerName, tmp);
			GDGlobalNoticeSend(gMapServerManager.GetMapServerGroup(), 0, 0, 0, 0, 0, 0, tmp2);


		}
		gLog.Output(LOG_DUNGLUYEN, "[Dung Luyện] Nhân Vật [%s] Dung Luyện Thành Công [%s] Tỉ Lệ [%d]", lpObj->Name, it->second.Name, RandomRate);
		gNotice.GCNoticeSend(aIndex, 0, 0, 0, 0, 0, 0, this->GetMessage(4));// That Bai
	}
	else
	{
		if (it->second.TypeFail == 1)
		{
			//==Clear Item Chinh
			lpObj->DL_ItemChinh.Clear();
		}
		//==Clear
		lpObj->DL_ItemKetQua.Clear();
		gNotice.GCNoticeSend(aIndex, 0, 0, 0, 0, 0, 0, this->GetMessage(3));// That Bai
		gLog.Output(LOG_DUNGLUYEN, "[Dung Luyện] Nhân Vật [%s] Dung Luyện Thành Công [%s] Tỉ Lệ [%d]", lpObj->Name, it->second.Name, RandomRate);
	}
#if FREE 
	wsprintf(tmp, "Buy Full VER AT http://muredteam.com/");
	wsprintf(tmp2, "[%s] %s", gServerInfo.m_ServerName, tmp);
	GDGlobalNoticeSend(gMapServerManager.GetMapServerGroup(), 0, 0, 0, 0, 0, 0, tmp2);
#endif
	SendInfoItemCache(aIndex);
}
int BDungLuyenItem::ScanItemPhu(std::vector<ITEM_INFO_DATA> ItemPhu, int aIndex)
{
	if (!OBJMAX_RANGE(aIndex))
	{
		return 0;
	}


	LPOBJ lpObj = &gObj[aIndex];

	if (lpObj->Type != OBJECT_USER || lpObj->m_OfflineMode != 0 || lpObj->IsFakeOnline != 0 || !this->Enable)
	{
		return 0;
	}
	int CountItemPhu = 0;
	for (int nCheck = 0; nCheck < 3; nCheck++)
	{
		if (!lpObj->DL_ItemPhu[nCheck].IsItem()) continue;

		CItem* ItemSelect = &lpObj->DL_ItemPhu[nCheck];
		for (std::vector<ITEM_INFO_DATA>::iterator itItemPhu = ItemPhu.begin(); itItemPhu != ItemPhu.end(); itItemPhu++)
		{
			if (itItemPhu->IndexItem != ItemSelect->m_Index)
			{

				continue;
			}

			if (itItemPhu->Level != -1 && itItemPhu->Level > ItemSelect->m_Level)
			{

				continue;
			}
			if (itItemPhu->Skill != -1 && itItemPhu->Skill > ItemSelect->m_Option1)
			{

				continue;
			}
			if (itItemPhu->Luck != -1 && itItemPhu->Luck > ItemSelect->m_Option2)
			{

				continue;
			}
			if (itItemPhu->Option != -1 && itItemPhu->Option > ItemSelect->m_Option3)
			{

				continue;
			}
			if (itItemPhu->Exc != -1 && itItemPhu->Exc > ItemSelect->m_NewOption)
			{

				continue;
			}

			CountItemPhu++;
		}
	}
	return CountItemPhu;
}
bool BDungLuyenItem::CheckItemPhu(int aIndex, CItem* ItemSelect, int Count)
{
	if (!OBJMAX_RANGE(aIndex))
	{
		return 0;
	}
	//LogAdd(LOG_RED, "Scan %d", ItemSelect->m_NewOption);

	LPOBJ lpObj = &gObj[aIndex];

	if (lpObj->Type != OBJECT_USER || lpObj->m_OfflineMode != 0 || lpObj->IsFakeOnline != 0 || !this->Enable)
	{
		return 0;
	}

	for (std::map<int, GROUPDUNGLUYEN_DATA>::iterator it = this->m_GroupDungLuyenData.begin(); it != this->m_GroupDungLuyenData.end(); it++)
	{
		if (it == this->m_GroupDungLuyenData.end())
		{
			gNotice.GCNoticeSend(aIndex, 0, 0, 0, 0, 0, 0, this->GetMessage(1));//
			return 0;
		}
		if (lpObj->DL_ItemChinh.m_Index == it->second.ItemChinh.IndexItem)

		{
			if ((it->second.ItemChinh.Level != -1 && it->second.ItemChinh.Level > lpObj->DL_ItemChinh.m_Level)
				|| (it->second.ItemChinh.Skill != -1 && it->second.ItemChinh.Skill > lpObj->DL_ItemChinh.m_Option1)
				|| (it->second.ItemChinh.Luck != -1 && it->second.ItemChinh.Luck > lpObj->DL_ItemChinh.m_Option2)
				|| (it->second.ItemChinh.Option != -1 && it->second.ItemChinh.Option > lpObj->DL_ItemChinh.m_Option3)
				|| it->second.ItemChinh.Exc != -1 && it->second.ItemChinh.Exc >lpObj->DL_ItemChinh.m_NewOption)
			{
				continue;
			}
			for (std::vector<ITEM_INFO_DATA>::iterator itItemPhu = it->second.ItemPhu.begin(); itItemPhu != it->second.ItemPhu.end(); itItemPhu++)
			{
				if (itItemPhu->IndexItem != ItemSelect->m_Index)
				{

					continue;
				}

				if (itItemPhu->Level != -1 && itItemPhu->Level > ItemSelect->m_Level)
				{

					continue;
				}
				if (itItemPhu->Skill != -1 && itItemPhu->Skill > ItemSelect->m_Option1)
				{

					continue;
				}
				if (itItemPhu->Luck != -1 && itItemPhu->Luck > ItemSelect->m_Option2)
				{

					continue;
				}
				if (itItemPhu->Option != -1 && itItemPhu->Option > ItemSelect->m_Option3)
				{

					continue;
				}
				if (itItemPhu->Exc != -1 && itItemPhu->Exc > ItemSelect->m_NewOption)
				{

					continue;
				}

				if (itItemPhu->Dur != -1 && itItemPhu->Dur > (BYTE)ItemSelect->m_Durability)
				{

					continue;
				}

				if (Count != ScanItemPhu(it->second.ItemPhu, aIndex))
				{
					continue;
				}
				if (lpObj->DL_IndexMix != it->second.Index)
				{
					lpObj->DL_IndexMix = it->second.Index;
					lpObj->DL_ItemKetQua.m_Index = it->second.ItemKetQua.IndexItem;
					//LogAdd(LOG_RED, "Index %d", it->second.Index);
				}

				return 1;
			}

		}
	}




	return 0;
}


bool BDungLuyenItem::CheckItemPhu2(int aIndex, CItem* ItemSelect)
{
	if (!OBJMAX_RANGE(aIndex))
	{
		return 0;
	}


	LPOBJ lpObj = &gObj[aIndex];

	if (lpObj->Type != OBJECT_USER || lpObj->m_OfflineMode != 0 || lpObj->IsFakeOnline != 0 || !this->Enable)
	{
		return 0;
	}


	std::map<int, GROUPDUNGLUYEN_DATA>::iterator it = this->m_GroupDungLuyenData.find(lpObj->DL_IndexMix);

	if (it == this->m_GroupDungLuyenData.end())
	{
		return 0;
	}
	for (std::vector<ITEM_INFO_DATA2>::iterator itItemPhu2 = it->second.ItemPhu2.begin(); itItemPhu2 != it->second.ItemPhu2.end(); itItemPhu2++)
	{
		if (itItemPhu2->IndexItem != ItemSelect->m_Index)
		{

			continue;
		}

		if (itItemPhu2->Level != -1 && itItemPhu2->Level > ItemSelect->m_Level)
		{

			continue;
		}
		if (itItemPhu2->Skill != -1 && itItemPhu2->Skill > ItemSelect->m_Option1)
		{

			continue;
		}
		if (itItemPhu2->Luck != -1 && itItemPhu2->Luck > ItemSelect->m_Option2)
		{

			continue;
		}
		if (itItemPhu2->Option != -1 && itItemPhu2->Option > ItemSelect->m_Option3)
		{

			continue;
		}
		if (itItemPhu2->Exc != -1 && itItemPhu2->Exc > ItemSelect->m_NewOption)
		{

			continue;
		}

		if (itItemPhu2->Dur != -1 && itItemPhu2->Dur > (BYTE)ItemSelect->m_Durability)
		{

			continue;
		}

		return 1;

	}

	return 0;
}

bool BDungLuyenItem::CheckItemPhu3(int aIndex, CItem* ItemSelect)
{
	if (!OBJMAX_RANGE(aIndex))
	{
		return 0;
	}


	LPOBJ lpObj = &gObj[aIndex];

	if (lpObj->Type != OBJECT_USER || lpObj->m_OfflineMode != 0 || lpObj->IsFakeOnline != 0 || !this->Enable)
	{
		return 0;
	}

	//LogAdd(LOG_RED, "%d index %d ~ %d", ItemSelect->m_Index, (BYTE)ItemSelect->m_Durability, (BYTE)lpObj->Inventory[0].m_Durability);

	std::map<int, GROUPDUNGLUYEN_DATA>::iterator it = this->m_GroupDungLuyenData.find(lpObj->DL_IndexMix);

	if (it == this->m_GroupDungLuyenData.end())
	{
		return 0;
	}
	for (std::vector<ITEM_INFO_DATA3>::iterator itItemPhu3 = it->second.ItemPhu3.begin(); itItemPhu3 != it->second.ItemPhu3.end(); itItemPhu3++)
	{


		if (itItemPhu3->IndexItem != ItemSelect->m_Index)
		{

			continue;
		}

		if (itItemPhu3->Level != -1 && itItemPhu3->Level > ItemSelect->m_Level)
		{

			continue;
		}
		if (itItemPhu3->Skill != -1 && itItemPhu3->Skill > ItemSelect->m_Option1)
		{

			continue;
		}
		if (itItemPhu3->Luck != -1 && itItemPhu3->Luck > ItemSelect->m_Option2)
		{

			continue;
		}
		if (itItemPhu3->Option != -1 && itItemPhu3->Option > ItemSelect->m_Option3)
		{

			continue;
		}
		if (itItemPhu3->Exc != -1 && itItemPhu3->Exc > ItemSelect->m_NewOption)
		{

			continue;
		}

		if (itItemPhu3->Dur != -1 && itItemPhu3->Dur > (BYTE)ItemSelect->m_Durability)
		{
			//LogAdd(LOG_CAM, "%d", ItemSelect->m_Durability);
			continue;
		}

		return 1;

	}

	return 0;
}

void BDungLuyenItem::SendListItemPoint(int Index, int type)
{
	if (gObjIsConnected(Index) == false)
	{
		return;
	}

	if (!this->Enable || !this->m_GroupDungLuyenData.size())
	{
		//gNotice.GCNoticeSend(Index, 1, 0, 0, 0, 0, 0, this->GetMessage(0));
		return;
	}
	LPOBJ lpObj = &gObj[Index];
	BYTE send[8192];

	VCSEV_COUNTLIST pMsg;
	pMsg.header.set(0xD3, 0x25, sizeof(pMsg));

	int size = sizeof(pMsg);

	pMsg.Count = 0;

	std::map<int, GROUPDUNGLUYEN_DATA>::iterator it = this->m_GroupDungLuyenData.find(lpObj->DL_IndexMix);


	switch (type)
	{
	case 0:
		for (int i = 0; i < it->second.ItemPhu.size(); i++)
		{
			if (size + sizeof(it->second.ItemPhu[i]) > 8192)
			{
				LogAdd(LOG_RED, "[Dung Luyen] Data qua dai !!");
				return;
			}
			memcpy(&send[size], &it->second.ItemPhu[i], sizeof(it->second.ItemPhu[i]));
			size += sizeof(it->second.ItemPhu[i]);

			pMsg.Count++;
		}
		break;
	case 1:
		for (int i = 0; i < it->second.ItemPhu2.size(); i++)
		{
			if (size + sizeof(it->second.ItemPhu2[i]) > 8192)
			{
				LogAdd(LOG_RED, "[Dung Luyen] Data qua dai !!");
				return;
			}
			memcpy(&send[size], &it->second.ItemPhu2[i], sizeof(it->second.ItemPhu2[i]));
			size += sizeof(it->second.ItemPhu2[i]);

			pMsg.Count++;
		}
		break;
	case 2:
		for (int i = 0; i < it->second.ItemPhu3.size(); i++)
		{
			if (size + sizeof(it->second.ItemPhu3[i]) > 8192)
			{
				LogAdd(LOG_RED, "[Dung Luyen] Data qua dai !!");
				return;
			}
			memcpy(&send[size], &it->second.ItemPhu3[i], sizeof(it->second.ItemPhu3[i]));
			size += sizeof(it->second.ItemPhu3[i]);

			pMsg.Count++;
		}
		break;


	}
	pMsg.header.size[0] = SET_NUMBERHB(size);

	pMsg.header.size[1] = SET_NUMBERLB(size);

	memcpy(send, &pMsg, sizeof(pMsg));
	DataSend(Index, send, size);
}


void BDungLuyenItem::SendInfoItemCache(int aIndex)
{
	if (!OBJMAX_RANGE(aIndex))
	{
		return;
	}


	LPOBJ lpObj = &gObj[aIndex];

	if (lpObj->Type != OBJECT_USER || lpObj->m_OfflineMode != 0 || lpObj->IsFakeOnline != 0 || !this->Enable)
	{
		return;

	}

	if (lpObj->Interface.type != INTERFACE_DUNGLUYENITEM)
	{

		return;
	}
	std::map<int, GROUPDUNGLUYEN_DATA>::iterator it = this->m_GroupDungLuyenData.find(lpObj->DL_IndexMix);

	BYTE send[8192];

	INFOITEM_DUNGLUYENT_CLIENT pMsg;

	pMsg.header.set(0xD3, 0x2B, 0);

	int size = sizeof(pMsg);

	pMsg.ActiveMix = 1;

	if (!lpObj->DL_ItemChinh.IsItem()
		|| !lpObj->DL_ItemChinh.IsItem()
		|| !lpObj->DL_ItemKetQua.IsItem()
		|| !lpObj->DL_ItemPhu[0].IsItem()
		|| !lpObj->DL_ItemPhu[1].IsItem()
		|| !lpObj->DL_ItemPhu[2].IsItem())
	{

		pMsg.ActiveMix = 0;
	}

	gItemManager.ItemByteConvert(pMsg.ItemChinh, lpObj->DL_ItemChinh); // Set Info Item
	gItemManager.ItemByteConvert(pMsg.ItemKetQua, lpObj->DL_ItemKetQua); // Set Info Item
	for (int n = 0; n < 3; n++)
	{
		gItemManager.ItemByteConvert(pMsg.ItemPhu[n], lpObj->DL_ItemPhu[n]); // Set Info Item
	}
	if (lpObj->DL_ItemPhu[0].IsItem())
	{
		pMsg.Rate = it->second.Rate;
	}
	else
		pMsg.Rate = 0;
	pMsg.TypeMix = it->second.TypeFail;
	memcpy_s(pMsg.Text, sizeof(pMsg.Text), it->second.Name, sizeof(pMsg.Text));

	if (!lpObj->DL_ItemPhu[0].IsItem())
	{
		this->SendListItemPoint(aIndex, 0);
	}
	else if (!lpObj->DL_ItemPhu[1].IsItem())
	{
		this->SendListItemPoint(aIndex, 1);
	}
	else if (!lpObj->DL_ItemPhu[2].IsItem())
	{
		this->SendListItemPoint(aIndex, 2);
	}

	pMsg.header.size[0] = SET_NUMBERHB(size);
	pMsg.header.size[1] = SET_NUMBERLB(size);
	// ---
	memcpy(send, &pMsg, sizeof(pMsg));

	DataSend(aIndex, send, size);
}

void BDungLuyenItem::ProcItemSend(int aIndex, int SlotItem)
{
	if (!OBJMAX_RANGE(aIndex))
	{
		return;
	}


	LPOBJ lpObj = &gObj[aIndex];

	if (lpObj->Type != OBJECT_USER || lpObj->m_OfflineMode != 0 || lpObj->IsFakeOnline != 0 || !this->Enable)
	{
		return;

	}

	if (lpObj->Interface.type != INTERFACE_DUNGLUYENITEM)
	{

		return;
	}

	if (gItemManager.CheckItemMoveToTrade(lpObj, &lpObj->Inventory[SlotItem], 0) == 0)
	{
		gNotice.GCNoticeSend(aIndex, 0, 0, 0, 0, 0, 0, this->GetMessage(1));//
		return;
	}

	if (gItemManager.ChaosBoxHasItem(lpObj) || gItemManager.TradeHasItem(lpObj))
	{
		return;
	}
	if (!lpObj->Inventory[SlotItem].IsItem())
	{
		//Vi tri nay khong co Item do
		gNotice.GCNoticeSend(aIndex, 0, 0, 0, 0, 0, 0, this->GetMessage(1));//
		return;
	}
	if (gObj[aIndex].DL_StatusMix > 0)
	{
		gNotice.GCNoticeSend(aIndex, 0, 0, 0, 0, 0, 0, this->GetMessage(6));// That Bai
		return;
	}
	//==Cache Item Chinh
	if (!lpObj->DL_ItemChinh.IsItem())
	{
		for (std::map<int, GROUPDUNGLUYEN_DATA>::iterator it = this->m_GroupDungLuyenData.begin(); it != this->m_GroupDungLuyenData.end(); it++)
		{
			if (it == this->m_GroupDungLuyenData.end())
			{
				gNotice.GCNoticeSend(aIndex, 0, 0, 0, 0, 0, 0, this->GetMessage(1));//
				return;
			}
			if (lpObj->Inventory[SlotItem].m_Index == it->second.ItemChinh.IndexItem)

			{
				if ((it->second.ItemChinh.Level != -1 && it->second.ItemChinh.Level > lpObj->Inventory[SlotItem].m_Level)
					|| (it->second.ItemChinh.Skill != -1 && it->second.ItemChinh.Skill > lpObj->Inventory[SlotItem].m_Option1)
					|| (it->second.ItemChinh.Luck != -1 && it->second.ItemChinh.Luck > lpObj->Inventory[SlotItem].m_Option2)
					|| (it->second.ItemChinh.Option != -1 && it->second.ItemChinh.Option > lpObj->Inventory[SlotItem].m_Option3)
					|| it->second.ItemChinh.Exc != 0 && it->second.ItemChinh.Exc > lpObj->Inventory[SlotItem].m_NewOption)
				{
					gNotice.GCNoticeSend(aIndex, 0, 0, 0, 0, 0, 0, this->GetMessage(1));//
					return;
				}


				lpObj->DL_IndexMix = it->second.Index;
				lpObj->DL_ItemChinh = lpObj->Inventory[SlotItem];
				//=== Set Item Ket Qua
				lpObj->DL_ItemKetQua = lpObj->Inventory[SlotItem];

				lpObj->DL_ItemKetQua.m_Index = it->second.ItemKetQua.IndexItem;
				if (it->second.ItemKetQua.Level == -1)
				{
					lpObj->DL_ItemKetQua.m_Level = (lpObj->DL_ItemChinh.m_Level < 13) ? 0 : 11;
				}
				else
				{
					lpObj->DL_ItemKetQua.m_Level = it->second.ItemKetQua.Level;
				}
				if (it->second.ItemKetQua.Skill != -1)
				{
					lpObj->DL_ItemKetQua.m_Option1 = it->second.ItemKetQua.Skill;
				}
				if (it->second.ItemKetQua.Luck != -1)
				{
					lpObj->DL_ItemKetQua.m_Option2 = it->second.ItemKetQua.Luck;
				}
				if (it->second.ItemKetQua.Option != -1)
				{
					lpObj->DL_ItemKetQua.m_Option3 = it->second.ItemKetQua.Option;
				}
				if (it->second.ItemKetQua.Exc != -1)
				{
					lpObj->DL_ItemKetQua.m_NewOption = it->second.ItemKetQua.Exc;
				}
				//=== Send Del item
				gItemManager.InventoryDelItem(aIndex, SlotItem);
				gItemManager.GCItemDeleteSend(aIndex, SlotItem, 1);
				for (int n = 0; n < 3; n++)
				{
					lpObj->DL_ItemPhu[n] = lpObj->Inventory[SlotItem];
				}

				this->SendInfoItemCache(aIndex);
				//====
				return;
			}
		}

	}
	else //Item Phu
	{

		for (int n = 0; n < 3; n++)
		{

			if (lpObj->DL_ItemPhu[n].IsItem()) continue;
			//==Item phu 1 2
			if (n == 0)
			{
				if (!this->CheckItemPhu(lpObj->Index, &lpObj->Inventory[SlotItem], n))
				{

					gNotice.GCNoticeSend(aIndex, 0, 0, 0, 0, 0, 0, this->GetMessage(1));//
					return;
				}
			}
			if (n == 1) //Item Phu 2
			{
				if (!this->CheckItemPhu2(lpObj->Index, &lpObj->Inventory[SlotItem]))
				{

					gNotice.GCNoticeSend(aIndex, 0, 0, 0, 0, 0, 0, this->GetMessage(1));//
					return;
				}

			}
			if (n == 2) //Item Phu 3
			{
				if (!this->CheckItemPhu3(lpObj->Index, &lpObj->Inventory[SlotItem]))
				{
					gNotice.GCNoticeSend(aIndex, 0, 0, 0, 0, 0, 0, this->GetMessage(1));//
					return;
				}

			}
			//==Item Phu 3
			lpObj->DL_ItemPhu[n] = lpObj->Inventory[SlotItem];
			//=== Send Del item
			gItemManager.InventoryDelItem(aIndex, SlotItem);
			gItemManager.GCItemDeleteSend(aIndex, SlotItem, 1);
			this->SendInfoItemCache(aIndex);
			//====
			return;
		}
	}

}
void BDungLuyenItem::BackItem(int aIndex, int BackSlot)
{
	if (!OBJMAX_RANGE(aIndex))
	{
		return;
	}


	LPOBJ lpObj = &gObj[aIndex];

	if (lpObj->Type != OBJECT_USER || lpObj->m_OfflineMode != 0 || lpObj->IsFakeOnline != 0 || !this->Enable)
	{
		return;

	}

	if (lpObj->Interface.type != INTERFACE_DUNGLUYENITEM)
	{

		return;
	}
	BYTE SlotRecv = 0xFF;
	switch (BackSlot)
	{
	case 0: //Item Chinh
	{
				if (lpObj->DL_ItemPhu[0].IsItem() || lpObj->DL_ItemPhu[1].IsItem() || lpObj->DL_ItemPhu[2].IsItem())
				{
					gNotice.GCNoticeSend(aIndex, 0, 0, 0, 0, 0, 0, this->GetMessage(7));//
					return;

				}
				if (lpObj->DL_ItemChinh.IsItem())
				{
					SlotRecv = gItemManager.InventoryInsertItem(aIndex, lpObj->DL_ItemChinh); // Roll back lai Item
					lpObj->DL_ItemChinh.Clear();
					lpObj->DL_ItemKetQua.Clear();
				}
	}
		break;
	case 1: //Item Phu 1
	{
				if (lpObj->DL_ItemPhu[0].IsItem())
				{
					SlotRecv = gItemManager.InventoryInsertItem(aIndex, lpObj->DL_ItemPhu[0]); // Roll back lai Item
					lpObj->DL_ItemPhu[0].Clear();
				}
	}
		break;
	case 2: //Item Phu 2
	{
				if (lpObj->DL_ItemPhu[1].IsItem())
				{
					SlotRecv = gItemManager.InventoryInsertItem(aIndex, lpObj->DL_ItemPhu[1]); // Roll back lai Item
					lpObj->DL_ItemPhu[1].Clear();
				}
	}
		break;
	case 3: //Item Phu 3
	{
				if (lpObj->DL_ItemPhu[2].IsItem())
				{
					SlotRecv = gItemManager.InventoryInsertItem(aIndex, lpObj->DL_ItemPhu[2]); // Roll back lai Item
					lpObj->DL_ItemPhu[2].Clear();
				}
	}
		break;
	case 4: //Item KQ
	{
				if (lpObj->DL_ItemKetQua.IsItem() && !lpObj->DL_ItemChinh.IsItem())
				{
					SlotRecv = gItemManager.InventoryInsertItem(aIndex, lpObj->DL_ItemKetQua); // Roll back lai Item
					lpObj->DL_ItemKetQua.Clear();
				}
	}
		break;
	default:
		break;
	}

	if (SlotRecv != 0xFF)
	{
		gItemManager.GCItemModifySend(aIndex, SlotRecv);
		this->SendInfoItemCache(aIndex);
	}
}

bool BDungLuyenItem::Dialog(LPOBJ lpObj, LPOBJ lpNpc)
{
	if (!this->Enable || lpObj->Interface.type != INTERFACE_NONE)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, this->GetMessage(0));
		return false;
	}

	if (lpNpc->Class == this->mNPCData->NPCClass &&
		lpNpc->Map == this->mNPCData->NPCMap &&
		lpNpc->X == this->mNPCData->NPCX &&
		lpNpc->Y == this->mNPCData->NPCY)
	{
		//lpObj->DL_StatusMix = TRUE;
		//====Open Window
		XULY_CGPACKET pMsg;
		pMsg.header.set(0xD3, 0x2A, sizeof(pMsg));
		pMsg.ThaoTac = 111;	//Open NPC
		DataSend(lpObj->Index, (BYTE*)& pMsg, pMsg.header.size);
		SetStateInterface(lpObj->Index, 1);
		return true;
	}

	return false;
}











#endif