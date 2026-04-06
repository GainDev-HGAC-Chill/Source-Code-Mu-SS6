#pragma once
#include "StdAfx.h"
#include "Protocol.h"
#include "DSProtocol.h"
#include "User.h"
#include "OfflineMode.h"
#include "ItemManager.h"
#if(CUSTOM_DUNGLUYENITEM)
#define eMessageBox				255
struct DUNGLUYEN_MSG
{
	int Index;
	char Message[256];
};
struct NPC_DATA
{
	int NPCClass;
	int NPCMap;
	int NPCX;
	int NPCY;
	int NPCDir;
	void Clear()
	{
		NPCClass = -1;
		NPCMap = 0;
		NPCX = 0;
		NPCY = 0;
		NPCDir = 0;
	}
};
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

struct ITEM_INFO_DATA2
{
	int IndexItem;
	int Level;
	int Skill;
	int Luck;
	int Option;
	int Exc;
	int Dur;
};

struct ITEM_INFO_DATA3
{
	int IndexItem;
	int Level;
	int Skill;
	int Luck;
	int Option;
	int Exc;
	int Dur;
};

struct GROUPDUNGLUYEN_DATA
{
	int Index;
	int Notice;
	char Name[90];
	int Rate;
	int TypeFail;
	ITEM_INFO_DATA ItemChinh;
	std::vector<ITEM_INFO_DATA> ItemPhu;
	std::vector<ITEM_INFO_DATA2> ItemPhu2;
	std::vector<ITEM_INFO_DATA3> ItemPhu3;
	ITEM_INFO_DATA ItemKetQua;

};

typedef struct VCSEV_COUNTLIST
{
	PSWMSG_HEAD header;
	int Count;

};
struct INFOITEM_DUNGLUYENT_CLIENT
{
	PSWMSG_HEAD header;
	BYTE ActiveMix;
	BYTE ItemChinh[16];
	BYTE ItemPhu[3][16];
	BYTE ItemKetQua[16];
	int Rate;
	int TypeMix;
	char Text[100];
	int IndexPhu[3];
};

class BDungLuyenItem
{
public:
	BDungLuyenItem();
	virtual ~BDungLuyenItem();
	int Enable;
	NPC_DATA* mNPCData;
	void LoadConfig(char* FilePath);
	bool BDungLuyenItem::Dialog(LPOBJ lpObj, LPOBJ lpNpc);
	std::map<int, GROUPDUNGLUYEN_DATA> m_GroupDungLuyenData;
	bool BDungLuyenItem::CheckItemPhu(int aIndex, CItem* ItemSelect, int Count);
	bool BDungLuyenItem::CheckItemPhu2(int aIndex, CItem* ItemSelect);
	bool BDungLuyenItem::CheckItemPhu3(int aIndex, CItem* ItemSelect);
	int ScanItemPhu(std::vector<ITEM_INFO_DATA> ItemPhu, int aIndex);
	void BDungLuyenItem::SetStateInterface(int aIndex, int Type = 0);
	void BDungLuyenItem::ProcItemSend(int aIndex, int SlotItem);
	void BDungLuyenItem::SendInfoItemCache(int aIndex);
	void BDungLuyenItem::BackItem(int aIndex, int BackSlot);
	void BDungLuyenItem::ProcMix(int aIndex);
	void BDungLuyenItem::SendListItemPoint(int Index, int type);
	void SetNPC();
private:
	//===Mess
	std::map<int, DUNGLUYEN_MSG> m_MessageInfoBP;
	char* GetMessage(int index);

};

extern BDungLuyenItem gBDungLuyenItem;



#endif