#pragma once
#include "StdAfx.h"
#if (CUSTOM_HARMONY)
#include "Protocol.h"
#include "DSProtocol.h"
#include "User.h"
#include "OfflineMode.h"
#include "ItemManager.h"
#include "BDungLuyenItem.h"

#define eMessageBox				255
struct SAUDATAOHOA
{
	int Index;
	char Message[256];
};


struct OPTWEAPON
{
	int OptIndex;
	char Name[60];
	int Level;
	int Rate;
};

struct OPTSTAFF
{
	int OptIndex;
	char Name[60];
	int Level;
	int Rate;
};

struct OPTITEM
{
	int OptIndex;
	char Name[60];
	int Level;
	int Rate;
};


struct DATAOHOA_SENDCLIENT
{
	PSWMSG_HEAD header;
	BYTE ActiveMix;
	BYTE ItemChuaEp[16];
	int Rate;
	int Price;
	int PriceType;
	int SoLuongDaTaoHoa;
	int IndexRandom;

};


class CustomHarmony
{
public:
	CustomHarmony();
	virtual ~CustomHarmony();
	int Enable;
	NPC_DATA* mNPCData;
	void LoadConfig(char* FilePath);
	bool CustomHarmony::Dialog(LPOBJ lpObj, LPOBJ lpNpc);
	void SetNPC();
	int PriceType;
	int Price;
	int Rate;
	void CustomHarmony::SetStateInterface(int aIndex, int Type = 0);
	std::vector<OPTWEAPON> m_OptWeapon;
	std::vector<OPTSTAFF> m_OptStaff;
	std::vector<OPTITEM> m_OptItem;
	void CustomHarmony::SendInfoItemCache(int aIndex);
	void CustomHarmony::SendListItemPoint(int Index, int type);
	void CustomHarmony::ProcItemSend(int aIndex, int SlotItem);
	void CustomHarmony::BackItem(int aIndex, int BackSlot);
	void CustomHarmony::ProcMix(int aIndex);
private:
	//===Mess
	std::map<int, SAUDATAOHOA> m_MessageInfoBP;
	char* GetMessage(int index);

};

extern CustomHarmony gCustomHarmony;
#endif