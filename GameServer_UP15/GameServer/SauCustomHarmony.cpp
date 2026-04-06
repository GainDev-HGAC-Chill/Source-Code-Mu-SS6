#include "stdafx.h"
#if (CUSTOM_HARMONY)
#include "SauCustomHarmony.h"
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
#include "BCustomItemBank.h"


CustomHarmony gCustomHarmony;

CustomHarmony::CustomHarmony()
{
	this->Enable = 0;
	this->mNPCData = new NPC_DATA;
	this->m_OptItem.clear();
	this->m_OptStaff.clear();
	this->m_OptWeapon.clear();
}

CustomHarmony::~CustomHarmony()
{

}

void CustomHarmony::SetNPC()
{
	if (gCustomHarmony.Enable)
	{
		MONSTER_SET_BASE_INFO info;
		memset(&info, 0, sizeof(info));

		info.Type = 0;
		info.MonsterClass = gCustomHarmony.mNPCData->NPCClass;
		info.Map = gCustomHarmony.mNPCData->NPCMap;
		info.Dis = 0;
		info.Dir = gCustomHarmony.mNPCData->NPCDir;
		info.X = gCustomHarmony.mNPCData->NPCX;
		info.Y = gCustomHarmony.mNPCData->NPCY;

		gMonsterSetBase.SetInfo(info);
	}
}
void CustomHarmony::LoadConfig(char* FilePath)
{
	this->Price = 0;
	this->PriceType = -1;
	this->Rate = 0;
	this->m_OptItem.clear();
	this->m_OptStaff.clear();
	this->m_OptWeapon.clear();
	this->Enable = 0;
	this->mNPCData->Clear();

	pugi::xml_document file;
	pugi::xml_parse_result res = file.load_file(FilePath);
	if (res.status != pugi::status_ok) {
		ErrorMessageBox("File %s load fail. Error: %s", FilePath, res.description());
		return;
	}
	pugi::xml_node oHarmony = file.child("Harmony");
	this->Enable = oHarmony.attribute("Enable").as_int();
	this->PriceType = oHarmony.attribute("PriceType").as_int();
	this->Price = oHarmony.attribute("Price").as_int();
	this->Rate = oHarmony.attribute("Rate").as_int();


	//= Mess Load
	pugi::xml_node Message = oHarmony.child("Message");
	for (pugi::xml_node msg = Message.child("Msg"); msg; msg = msg.next_sibling())
	{
		SAUDATAOHOA info;

		info.Index = msg.attribute("Index").as_int();

		strncpy_s(info.Message, msg.attribute("Text").as_string(), sizeof(info.Message));

		this->m_MessageInfoBP.insert(std::pair<int, SAUDATAOHOA>(info.Index, info));
	}

	//= Config NPC
	pugi::xml_node EventConfigNPC = oHarmony.child("NPC");
	this->mNPCData->NPCClass = EventConfigNPC.attribute("NPCClass").as_int();
	this->mNPCData->NPCMap = EventConfigNPC.attribute("NPCMap").as_int();
	this->mNPCData->NPCX = EventConfigNPC.attribute("NPCX").as_int();
	this->mNPCData->NPCY = EventConfigNPC.attribute("NPCY").as_int();
	this->mNPCData->NPCDir = EventConfigNPC.attribute("NPCDir").as_int();

	pugi::xml_node eWeapon = oHarmony.child("OptWeapon");
	for (pugi::xml_node rWeapon = eWeapon.child("Option"); rWeapon; rWeapon = rWeapon.next_sibling())
	{
		OPTWEAPON infoWeapon;
		infoWeapon.OptIndex = rWeapon.attribute("OptIndex").as_int();
		strncpy_s(infoWeapon.Name, rWeapon.attribute("Name").as_string(), sizeof(infoWeapon.Name));
		infoWeapon.Level = rWeapon.attribute("Level").as_int();
		infoWeapon.Rate = rWeapon.attribute("Rate").as_int();

		this->m_OptWeapon.push_back(infoWeapon);

	}

	pugi::xml_node eStaff = oHarmony.child("OptStaff");
	for (pugi::xml_node rStaff = eStaff.child("Option"); rStaff; rStaff = rStaff.next_sibling())
	{
		OPTSTAFF infoStaff;
		infoStaff.OptIndex = rStaff.attribute("OptIndex").as_int();
		strncpy_s(infoStaff.Name, rStaff.attribute("Name").as_string(), sizeof(infoStaff.Name));
		infoStaff.Level = rStaff.attribute("Level").as_int();
		infoStaff.Rate = rStaff.attribute("Rate").as_int();

		this->m_OptStaff.push_back(infoStaff);

	}

	pugi::xml_node eItem = oHarmony.child("OptItem");
	for (pugi::xml_node rItem = eItem.child("Option"); rItem; rItem = rItem.next_sibling())
	{
		OPTITEM info;
		info.OptIndex = rItem.attribute("OptIndex").as_int();
		strncpy_s(info.Name, rItem.attribute("Name").as_string(), sizeof(info.Name));
		info.Level = rItem.attribute("Level").as_int();
		info.Rate = rItem.attribute("Rate").as_int();

		this->m_OptItem.push_back(info);

	}

	LogAdd(LOG_RED, "[SauHarmony] Load OK Enable = %d, Size %d", this->Enable, this->m_OptWeapon.size());
}


char* CustomHarmony::GetMessage(int index) // OK
{
	std::map<int, SAUDATAOHOA>::iterator it = this->m_MessageInfoBP.find(index);

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
void CustomHarmony::SetStateInterface(int aIndex, int Type)
{

	if (Type == 1)
	{
		gObj[aIndex].Interface.state = 1;
		gObj[aIndex].Interface.use = 1;
		gObj[aIndex].Interface.type = INTERFACE_DATAOHOA;
		gObj[aIndex].Transaction = 0;
		gObjInventoryTransaction(aIndex);
	}
	else
	{


		if (gObj[aIndex].SAUTAOHOA_StatusMix > 0) //SAVE Neu Da Mix
		{
			if (gObj[aIndex].SAUTAOHOA_StatusMix == 1)
			{
				gItemManager.InventoryInsertItem(aIndex, gObj[aIndex].SAUTAOHOA_ItemChuaEp);
			}
			else
			{
				gItemManager.InventoryInsertItem(aIndex, gObj[aIndex].SAUTAOHOA_ItemDaEp);
			}
		}
		else
		{
			gObjInventoryRollback(aIndex);
		}

		//==Clear Cache

		gObj[aIndex].SAUTAOHOA_ItemChuaEp.Clear();
		gObj[aIndex].SAUTAOHOA_ItemDaEp.Clear();
		gObj[aIndex].SAUDATAO_IndexRandom = -1;
		gObj[aIndex].SAUTAOHOA_StatusMix = -1;
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
#include "RandomManager.h"

char* SauGetMoneyType[4] =
{
	"Zen",//84
	"Wcoin",//83
	"WcoinP",//91
	"GP", //10
};

void CustomHarmony::ProcMix(int aIndex)
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

	if (lpObj->Interface.type != INTERFACE_DATAOHOA)
	{

		return;
	}
	if (!lpObj->SAUTAOHOA_ItemChuaEp.IsItem())
	{
		return;
	}

	int GetSlotItemBank = gBCustomItemBank.CheckInfoListItemBank(7210, 0);
	if (GetSlotItemBank < 1)
	{
		return;
	}

	if (gObj[aIndex].BankJewelData[GetSlotItemBank].ItemCount <= 0)
	{
		gNotice.GCNoticeSend(aIndex, 0, 0, 0, 0, 0, 0, this->GetMessage(5));// That Bai
		return;
	}

	switch (this->PriceType)
	{
	case 0:
	{
			  if (this->Price > lpObj->Money)
			  {
				  gNotice.GCNoticeSend(aIndex, 0, 0, 0, 0, 0, 0, this->GetMessage(4), BNumberFormat(this->Price), SauGetMoneyType[this->PriceType]);
				  return;
			  }
	}
		break;
	case 1:
	{
			  if (this->Price > lpObj->Coin1)
			  {
				  gNotice.GCNoticeSend(aIndex, 0, 0, 0, 0, 0, 0, this->GetMessage(4), BNumberFormat(this->Price), SauGetMoneyType[this->PriceType]);
				  return;
			  }
	}
		break;
	case 2:
	{
			  if (this->Price > lpObj->Coin2)
			  {
				  gNotice.GCNoticeSend(aIndex, 0, 0, 0, 0, 0, 0, this->GetMessage(4), BNumberFormat(this->Price), SauGetMoneyType[this->PriceType]);
				  return;
			  }
	}
		break;
	case 3:
	{
			  if (this->Price > lpObj->Coin3)
			  {
				  gNotice.GCNoticeSend(aIndex, 0, 0, 0, 0, 0, 0, this->GetMessage(4), BNumberFormat(this->Price), SauGetMoneyType[this->PriceType]);
				  return;
			  }
	}
		break;

	default:
		break;
	}




	switch (this->PriceType)
	{
	case 0:
	{
			  lpObj->Money -= this->Price;
			  GCMoneySend(lpObj->Index, lpObj->Money);
	}
		break;
	case 1:
	{


			  GDSetCoinSend(lpObj->Index, (this->Price > 0) ? (-this->Price) : 0, 0, 0, "Xoay Đá Tạo Hóa");
			  gCashShop.CGCashShopPointRecv(lpObj->Index);

	}
		break;
	case 2:
	{

			  GDSetCoinSend(lpObj->Index, 0, (this->Price > 0) ? (-this->Price) : 0, 0, "Xoay Đá Tạo Hóa");
			  gCashShop.CGCashShopPointRecv(lpObj->Index);

	}
		break;
	case 3:
	{

			  GDSetCoinSend(lpObj->Index, 0, 0, (this->Price > 0) ? (-this->Price) : 0, "Xoay Đá Tạo Hóa");
			  gCashShop.CGCashShopPointRecv(lpObj->Index);
	}
		break;

	default:
		break;
	}

	if (GetSlotItemBank != -1)
	{
		gBCustomItemBank.CongTruBank(aIndex, 7210, 0, -1);
	}

	gObj[aIndex].SAUTAOHOA_StatusMix = 1;

	gObjInventoryCommit(aIndex); //Save Trang Thai Da Mix

	int RandomRate = (GetLargeRand() % 100);

	if (RandomRate <= this->Rate)
	{
		gObj[aIndex].SAUTAOHOA_StatusMix = 2; //Set Trang Thai neu co thoat ra thi van luu item Ket qua
		//==Clear Item Chinh Neu Mix Thanh Cong
		CRandomManager RandomManager;
		WORD iIndex = 0;

		CRandomManager RandomMng;

		if (lpObj->SAUTAOHOA_ItemChuaEp.m_Index >= GET_ITEM(0, 0) && lpObj->SAUTAOHOA_ItemChuaEp.m_Index < GET_ITEM(5, 0) && lpObj->SAUTAOHOA_ItemChuaEp.m_Index != GET_ITEM(4, 7) && lpObj->SAUTAOHOA_ItemChuaEp.m_Index != GET_ITEM(4, 15))
		{
			for (int n = 0; n < this->m_OptWeapon.size(); n++)
			{
				RandomMng.AddElement(n, this->m_OptWeapon[n].Rate);
			}

			RandomMng.GetRandomElement(&iIndex);
			lpObj->SAUDATAO_IndexRandom = iIndex;
			lpObj->SAUTAOHOA_ItemDaEp.m_JewelOfHarmonyOption = this->m_OptWeapon[iIndex].OptIndex;
		}
		else if (lpObj->SAUTAOHOA_ItemChuaEp.m_Index >= GET_ITEM(5, 0) && lpObj->SAUTAOHOA_ItemChuaEp.m_Index < GET_ITEM(6, 0))
		{
			for (int n = 0; n < this->m_OptStaff.size(); n++)
			{
				RandomMng.AddElement(n, this->m_OptStaff[n].Rate);
			}

			RandomMng.GetRandomElement(&iIndex);
			lpObj->SAUDATAO_IndexRandom = iIndex;
			lpObj->SAUTAOHOA_ItemDaEp.m_JewelOfHarmonyOption = this->m_OptStaff[iIndex].OptIndex;
		}
		else if (lpObj->SAUTAOHOA_ItemChuaEp.m_Index >= GET_ITEM(6, 0) && lpObj->SAUTAOHOA_ItemChuaEp.m_Index < GET_ITEM(12, 0))
		{
			for (int n = 0; n < this->m_OptItem.size(); n++)
			{
				RandomMng.AddElement(n, this->m_OptItem[n].Rate);
			}

			RandomMng.GetRandomElement(&iIndex);
			lpObj->SAUDATAO_IndexRandom = iIndex;
			lpObj->SAUTAOHOA_ItemDaEp.m_JewelOfHarmonyOption = this->m_OptItem[iIndex].OptIndex;
		}

	}
	else
	{

		lpObj->SAUDATAO_IndexRandom = -1;
		gNotice.GCNoticeSend(aIndex, 0, 0, 0, 0, 0, 0, this->GetMessage(3));// That Bai
	}

	SendInfoItemCache(aIndex);
}


void CustomHarmony::SendListItemPoint(int Index, int type)
{
	if (gObjIsConnected(Index) == false)
	{
		return;
	}

	if (!this->Enable || !this->m_OptWeapon.size() || !this->m_OptStaff.size() || !this->m_OptItem.size())
	{
		//gNotice.GCNoticeSend(Index, 1, 0, 0, 0, 0, 0, this->GetMessage(0));
		return;
	}
	LPOBJ lpObj = &gObj[Index];
	BYTE send[4096];

	VCSEV_COUNTLIST pMsg;
	pMsg.header.set(0xD5, 0x25, sizeof(pMsg));

	int size = sizeof(pMsg);

	pMsg.Count = 0;

	switch (type)
	{
	case 0:
		for (int i = 0; i < this->m_OptWeapon.size(); i++)
		{
			if (size + sizeof(this->m_OptWeapon[i]) > 4096)
			{
				LogAdd(LOG_RED, "[DaTaoHoa] Data qua dai !!");
				return;
			}
			memcpy(&send[size], &this->m_OptWeapon[i], sizeof(this->m_OptWeapon[i]));
			size += sizeof(this->m_OptWeapon[i]);

			pMsg.Count++;

			//LogAdd(LOG_RED, "%s %d", this->m_OptWeapon[i].Name, pMsg.Count);
		}
		break;
	case 1:
		for (int i = 0; i < this->m_OptStaff.size(); i++)
		{
			if (size + sizeof(this->m_OptStaff[i]) > 4096)
			{
				LogAdd(LOG_RED, "[DaTaoHoa] Data qua dai !!");
				return;
			}
			memcpy(&send[size], &this->m_OptStaff[i], sizeof(this->m_OptStaff[i]));
			size += sizeof(this->m_OptStaff[i]);

			pMsg.Count++;
		}
		break;
	case 2:
		for (int i = 0; i < this->m_OptItem.size(); i++)
		{
			if (size + sizeof(this->m_OptItem[i]) > 4096)
			{
				LogAdd(LOG_RED, "[DaTaoHoa] Data qua dai !!");
				return;
			}
			memcpy(&send[size], &this->m_OptItem[i], sizeof(this->m_OptItem[i]));
			size += sizeof(this->m_OptItem[i]);

			pMsg.Count++;
		}
		break;


	}
	pMsg.header.size[0] = SET_NUMBERHB(size);

	pMsg.header.size[1] = SET_NUMBERLB(size);

	memcpy(send, &pMsg, sizeof(pMsg));
	DataSend(Index, send, size);


}


void CustomHarmony::SendInfoItemCache(int aIndex)
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

	if (lpObj->Interface.type != INTERFACE_DATAOHOA)
	{

		return;
	}


	BYTE send[8192];

	DATAOHOA_SENDCLIENT pMsg;

	pMsg.header.set(0xD5, 0x2B, 0);

	int size = sizeof(pMsg);

	pMsg.ActiveMix = 1;

	if (!lpObj->SAUTAOHOA_ItemChuaEp.IsItem())
	{

		pMsg.ActiveMix = 0;
	}

	gItemManager.ItemByteConvert(pMsg.ItemChuaEp, lpObj->SAUTAOHOA_ItemChuaEp); // Set Info Item

	int indexngoc = gBCustomItemBank.CheckInfoListItemBank(7210, 0);
	pMsg.Rate = this->Rate;
	pMsg.Price = this->Price;
	pMsg.PriceType = this->PriceType;
	pMsg.SoLuongDaTaoHoa = gObj[aIndex].BankJewelData[indexngoc].ItemCount;
	pMsg.IndexRandom = lpObj->SAUDATAO_IndexRandom;

	if (lpObj->SAUTAOHOA_ItemChuaEp.m_Index >= GET_ITEM(0, 0) && lpObj->SAUTAOHOA_ItemChuaEp.m_Index < GET_ITEM(5, 0) && lpObj->SAUTAOHOA_ItemChuaEp.m_Index != GET_ITEM(4, 7) && lpObj->SAUTAOHOA_ItemChuaEp.m_Index != GET_ITEM(4, 15))
	{
		this->SendListItemPoint(aIndex, 0);
	}
	else if (lpObj->SAUTAOHOA_ItemChuaEp.m_Index >= GET_ITEM(5, 0) && lpObj->SAUTAOHOA_ItemChuaEp.m_Index < GET_ITEM(6, 0))
	{
		this->SendListItemPoint(aIndex, 1);
	}
	else if (lpObj->SAUTAOHOA_ItemChuaEp.m_Index >= GET_ITEM(6, 0) && lpObj->SAUTAOHOA_ItemChuaEp.m_Index < GET_ITEM(12, 0))
	{
		this->SendListItemPoint(aIndex, 2);
	}

	pMsg.header.size[0] = SET_NUMBERHB(size);
	pMsg.header.size[1] = SET_NUMBERLB(size);
	// ---
	memcpy(send, &pMsg, sizeof(pMsg));

	DataSend(aIndex, send, size);
}

void CustomHarmony::ProcItemSend(int aIndex, int SlotItem)
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

	if (lpObj->Interface.type != INTERFACE_DATAOHOA)
	{

		return;
	}

	if (gItemManager.CheckItemMoveToTrade(lpObj, &lpObj->Inventory[SlotItem], 0) == 0)
	{
		gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, this->GetMessage(1));//
		return;
	}

	if (gItemManager.ChaosBoxHasItem(lpObj) || gItemManager.TradeHasItem(lpObj))
	{
		return;
	}
	if (!lpObj->Inventory[SlotItem].IsItem())
	{
		//Vi tri nay khong co Item do
		gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, this->GetMessage(1));//
		return;
	}
	//if (gObj[aIndex].DL_StatusMix > 0)
	//{
	//	gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, this->GetMessage(6));// That Bai
	//	return;
	//}
	//==Cache Item Chinh

	if (lpObj->Inventory[SlotItem].m_Index > 6144)
	{
		//Vi tri nay khong co Item do
		gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, this->GetMessage(1));//
		return;
	}

	if (!lpObj->SAUTAOHOA_ItemChuaEp.IsItem())
	{

		lpObj->SAUTAOHOA_ItemChuaEp = lpObj->Inventory[SlotItem];
		//=== Set Item Ket Qua
		lpObj->SAUTAOHOA_ItemDaEp = lpObj->Inventory[SlotItem];


		//=== Send Del item
		gItemManager.InventoryDelItem(aIndex, SlotItem);
		gItemManager.GCItemDeleteSend(aIndex, SlotItem, 1);

		this->SendInfoItemCache(aIndex);
		//====
		return;

	}

}
void CustomHarmony::BackItem(int aIndex, int BackSlot)
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

	if (lpObj->Interface.type != INTERFACE_DATAOHOA)
	{

		return;
	}
	BYTE SlotRecv = 0xFF;
	switch (BackSlot)
	{
	case 0: //Item Chinh
	{

				if (lpObj->SAUTAOHOA_ItemChuaEp.IsItem())
				{
					SlotRecv = gItemManager.InventoryInsertItem(aIndex, lpObj->SAUTAOHOA_ItemChuaEp); // Roll back lai Item
					lpObj->SAUTAOHOA_ItemChuaEp.Clear();
					lpObj->SAUTAOHOA_ItemDaEp.Clear();
				}
	}
		break;

	case 4: //Item KQ
	{
				if (lpObj->SAUTAOHOA_ItemDaEp.IsItem() && !lpObj->DL_ItemChinh.IsItem())
				{
					SlotRecv = gItemManager.InventoryInsertItem(aIndex, lpObj->SAUTAOHOA_ItemDaEp); // Roll back lai Item
					lpObj->SAUTAOHOA_ItemChuaEp.Clear();
					lpObj->SAUTAOHOA_ItemDaEp.Clear();
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

bool CustomHarmony::Dialog(LPOBJ lpObj, LPOBJ lpNpc)
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
		pMsg.header.set(0xD5, 0x2A, sizeof(pMsg));
		pMsg.ThaoTac = 111;	//Open NPC
		DataSend(lpObj->Index, (BYTE*)& pMsg, pMsg.header.size);
		SetStateInterface(lpObj->Index, 1);
		return true;
	}

	return false;
}

#endif



