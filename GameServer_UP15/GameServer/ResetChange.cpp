#include "stdafx.h"
#if (RESETCHANGE == 1)
#include "CashShop.h"
#include "ResetChange.h"
#include "DSProtocol.h"
#include "JSProtocol.h"
#include "MemScript.h"
#include "Util.h"
#include "Message.h"
#include "Notice.h"
#include "StatsAdvance.h"
#include "ObjectManager.h"
#include "ServerInfo.h"
#include "CustomRankUser.h"
#include "ResetTable.h"

CResetChange gResetChange;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CResetChange::CResetChange() // OK
{
	this->Init();
}

CResetChange::~CResetChange() // OK
{

}

void CResetChange::Init() // OK
{
	for (int n = 0; n < MAX_RESET_CHANGE; n++)
	{
		this->m_CustomResetChangeInfo[n].Index = -1;
	}
}

void CResetChange::Load(char* path) // OK
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

	this->Init();

	try
	{
		while (true)
		{
			if (lpMemScript->GetToken() == TOKEN_END)
			{
				break;
			}

			if (strcmp("end", lpMemScript->GetString()) == 0)
			{
				break;
			}

			RESETCHANGE_INFO info;

			memset(&info, 0, sizeof(info));

			info.Index = lpMemScript->GetNumber();

			info.ReqReset = lpMemScript->GetAsNumber();

			info.Coin1 = lpMemScript->GetAsNumber();


			this->SetInfo(info);
		}
	}
	catch (...)
	{
		printf(lpMemScript->GetLastError());
	}

	delete lpMemScript;

}

void CResetChange::SetInfo(RESETCHANGE_INFO info) // OK
{
	if (info.Index < 0 || info.Index >= MAX_RESET_CHANGE)
	{
		return;
	}

	this->m_CustomResetChangeInfo[info.Index] = info;
}

RESETCHANGE_INFO* CResetChange::GetInfo(int index) // OK
{
	if (index < 0 || index >= MAX_RESET_CHANGE)
	{
		return 0;
	}

	if (this->m_CustomResetChangeInfo[index].Index != index)
	{
		return 0;
	}

	return &this->m_CustomResetChangeInfo[index];
}

void CResetChange::EnvioResetChange(int aIndex)
{

	if (gObjIsConnected(aIndex) == false)
	{
		return;
	}
	// ---
	LPOBJ lpObj = &gObj[aIndex];
	// ---
	PMSG_RESET_CHANGE pMsg = { 0 };
	// ---
	pMsg.h.set(0xFB, 0xC1, sizeof(pMsg));
	// ---
	pMsg.ReqReset1 = gResetChange.m_CustomResetChangeInfo[0].ReqReset;
	pMsg.RewardWC1 = gResetChange.m_CustomResetChangeInfo[0].Coin1;
	pMsg.ReqReset2 = gResetChange.m_CustomResetChangeInfo[1].ReqReset;
	pMsg.RewardWC2 = gResetChange.m_CustomResetChangeInfo[1].Coin1;
	pMsg.ReqReset3 = gResetChange.m_CustomResetChangeInfo[2].ReqReset;
	pMsg.RewardWC3 = gResetChange.m_CustomResetChangeInfo[2].Coin1;
	pMsg.ReqReset4 = gResetChange.m_CustomResetChangeInfo[3].ReqReset;
	pMsg.RewardWC4 = gResetChange.m_CustomResetChangeInfo[3].Coin1;
	pMsg.ReqReset5 = gResetChange.m_CustomResetChangeInfo[4].ReqReset;
	pMsg.RewardWC5 = gResetChange.m_CustomResetChangeInfo[4].Coin1;
	// ---
	DataSend(aIndex, (LPBYTE)&pMsg, pMsg.h.size);
}


void CResetChange::ResetChange(int aIndex, RESETCHANGE_REQ* lpMsg)
{
	LPOBJ lpObj = &gObj[aIndex];

	if (gObjIsConnectedGP(aIndex) == 0)
	{
		return;
	}


	if (lpMsg->numchange < 1 || lpMsg->numchange > 5)
	{
		return;
	}


	if (lpObj->Reset < m_CustomResetChangeInfo[lpMsg->numchange - 1].ReqReset)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(874));
		return;
	}

	lpObj->Reset = (lpObj->Reset - m_CustomResetChangeInfo[lpMsg->numchange - 1].ReqReset);

	GDSetCoinSend(lpObj->Index, +(m_CustomResetChangeInfo[lpMsg->numchange - 1].Coin1), 0, 0, "ResetChange");		//Nhận Wcoin

	gObjectManager.CharacterCalcAttribute(lpObj->Index);

	GCNewCharacterInfoSend(lpObj);

	GDCharacterInfoSaveSend(lpObj->Index);

	GDResetInfoSaveSend(lpObj->Index, 0, 0, 0);

	gCashShop.CGCashShopPointRecv(lpObj->Index);

	if (gServerInfo.m_CustomRankUserType == 0)
	{
		gCustomRankUser.CheckUpdate(lpObj);			//update rank
	}



	//Set Point mới
	int NewPoints = gResetTable.GetResetPoint_ChangeReset(lpObj);
	lpObj->Strength = gDefaultClassInfo.m_DefaultClassInfo[lpObj->Class].Strength;
	lpObj->Dexterity = gDefaultClassInfo.m_DefaultClassInfo[lpObj->Class].Dexterity;
	lpObj->Energy = gDefaultClassInfo.m_DefaultClassInfo[lpObj->Class].Energy;
	lpObj->Vitality = gDefaultClassInfo.m_DefaultClassInfo[lpObj->Class].Vitality;
	lpObj->Leadership = gDefaultClassInfo.m_DefaultClassInfo[lpObj->Class].Leadership;
	lpObj->LevelUpPoint = NewPoints + gServerInfo.PointDoiReset;


	gObjectManager.CharacterCalcAttribute(lpObj->Index);
	GCNewCharacterInfoSend(lpObj);
	GDCharacterInfoSaveSend(lpObj->Index);


	gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(875)); // Thông báo đổi thành công
}
#endif