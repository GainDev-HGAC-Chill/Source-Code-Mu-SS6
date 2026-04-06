#pragma once
#include "User.h"
#include "Protocol.h"
#if (JEWELBANKVER2)
struct DATA_LIST_ITEMBANK
{
	int Active;
	int AutoLoot;
	int ItemIndex;
	int ItemLevel;
	int Cum10Index;
	int Cum10Level;
	int Cum20Index;
	int Cum20Level;
	int Cum30Index;
	int Cum30Level;
	int MaxCountType[4];
	int MaxRut;
};

struct MESSAGE_INFO_ITEMBANK
{
	int Index;
	char Message[256];
};

//**********************************************//
//********** GameServer -> DataServer **********//
//**********************************************//
struct GSSENDDS_COUNT_ITEMBANK
{
	PSWMSG_HEAD header;
	char AccountID[11];
	int aIndex;
	int Count;
};
enum TypeRutGuiBank
{
	eRut1,
	eRut10,
	eRut20,
	eRut30,
	eRutAll,
	eGuiAll,
	eAutoPick,
};
//==== Packer Rut Gui Ngoc
struct REQUEST_RUTGUIBANK
{
	PSBMSG_HEAD header; // C3:F3:03
	BYTE TypeSend;
	short IndexList;
};

class BCustomItemBank
{
public:
	BCustomItemBank();
	~BCustomItemBank();
	int Enable;
	void BCustomItemBank::Load(char* FilePath);
	std::vector<DATA_LIST_ITEMBANK> mListItemBank;
	void BCustomItemBank::GSSendDSGetData(int aIndex);
	void BCustomItemBank::DSSetInfoUserBankItem(GSSENDDS_COUNT_ITEMBANK* lpMsg);
	int BCustomItemBank::CheckInfoListItemBank(int ItemIndex, int ItemLevel);
	void BCustomItemBank::GSSendDSSaveDataUser(int aIndex);
	void BCustomItemBank::UserSendClientInfo(int aIndex);
	bool BCustomItemBank::CongTruBank(int aIndex, int ItemIndex, int ItemLevel, int Vaule);
	int BCustomItemBank::CheckCountItemBank(int aIndex, int ItemIndex, int ItemLevel);
	bool ClientSendRutOrGui(REQUEST_RUTGUIBANK* lpMsg, int aIndex);
	int BCustomItemBank::GetInventoryItemCountBank(LPOBJ lpObj, int index, int level);
	void BCustomItemBank::DeleteInventoryItemCountBank(LPOBJ lpObj, int index, int level, int count);
	void BCustomItemBank::ReloadInfoChar();
	bool BCustomItemBank::CheckItemBankAutoPick(int aIndex, int ItemIndex, int ItemLevel);
private:
	//===Mess
	std::map<int, MESSAGE_INFO_ITEMBANK> m_MessageInfoBP;
	char* GetMessage(int index);
};

extern BCustomItemBank gBCustomItemBank;
#endif