#include "stdafx.h"
#include "BAntihack.h"
#include "Import.h"
#include "User.h"
#include "PrintPlayer.h"
#include "Offset.h"
#include "Defines.h"
#include "Extras.h"
#include "Util.h"
CBAntihack gBAntihack;

CBAntihack::CBAntihack()
{
	this->BLevelCache = 0;
}
#define BGetModelPlaySpeed						((int(__thiscall*)(int thisa, int Action)) 0x0051A220)
#define sub_5B0170			(( void(__cdecl*)(int a4, int a5, float a6)) 0x5B0170)
#define sub_5AB0B0			(( void(__cdecl*)(int a4, int a5, float a6)) 0x5AB0B0)
#define sub_5AD040			(( void(__cdecl*)(int a4, int a5, float a6)) 0x5AD040)
#define sub_59FCA0			(( void(__cdecl*)(int a4, int a5, float a6)) 0x59FCA0)
#define sub_5B3310			(( void(__cdecl*)(int a4, int a5, float a6)) 0x5B3310)
#define sub_59B580			(( char(__cdecl*)(int a4, int a5)) 0x59B580)
#define sub_5A0A30			(( char(__cdecl*)(int a4, int a5)) 0x5A0A30)
#define sub_59E590			(( void(__cdecl*)(int a4, int a5)) 0x0059E590)
#define sub_59C260			(( void(__cdecl*)(int a4, int a5)) 0x0059C260)
#define sub_X404D70			((int(__thiscall*)(unsigned __int16* This, int a2, int a3)) 0x00404D70)
DWORD CalcTimeSkill[6] = { 0 };

void AttackSkill_1(int a4, int a5, float a6) 	   //v26 == 2 AttackElf
{

	float FameSpeed = *(float*)(BGetModelPlaySpeed(BMDthisa(), gObjUser.lpViewPlayer->m_Model.AnimationID) + 4);
	gBAntihack.SendLogUseSkill(gObjUser.GetActiveSkill(), FameSpeed);
	sub_5AB0B0(a4, a5, a6);
}

char AttackSkill_6(int a4, int a5) 	   //v26 == >=67 <= 72 AttackElf 22
{
	float FameSpeed = *(float*)(BGetModelPlaySpeed(BMDthisa(), gObjUser.lpViewPlayer->m_Model.AnimationID) + 4);
	gBAntihack.SendLogUseSkill(gObjUser.GetActiveSkill(), FameSpeed);
	return sub_5A0A30(a4, a5);
}
void AttackSkillPhep(int a4, int a5, float a6) 	   //!v26 || v26 == 3 || v26 == 5  AttackWizard
{
	float FameSpeed = *(float*)(BGetModelPlaySpeed(BMDthisa(), gObjUser.lpViewPlayer->m_Model.AnimationID) + 4);
	gBAntihack.SendLogUseSkill(gObjUser.GetActiveSkill(), FameSpeed);
	sub_5B0170(a4, a5, a6);
}
void AttackSkill_2(int a4, int a5, float a6) 	   //v26 == 1,3,4 AttackKnight
{
	float FameSpeed = *(float*)(BGetModelPlaySpeed(BMDthisa(), gObjUser.lpViewPlayer->m_Model.AnimationID) + 4);
	gBAntihack.SendLogUseSkill(gObjUser.GetActiveSkill(), FameSpeed);
	sub_5AD040(a4, a5, a6);
}

void AttackSkill_3(int a4, int a5, float a6) 	   //v26 == 6 RF
{
	float FameSpeed = *(float*)(BGetModelPlaySpeed(BMDthisa(), gObjUser.lpViewPlayer->m_Model.AnimationID) + 4);
	gBAntihack.SendLogUseSkill(gObjUser.GetActiveSkill(), FameSpeed);
	sub_59FCA0(a4, a5, a6);

}
void AttackSkillRF(int a4, int a5) 	   //v26 == 6 RF
{
	float FameSpeed = *(float*)(BGetModelPlaySpeed(BMDthisa(), gObjUser.lpViewPlayer->m_Model.AnimationID) + 4);
	gBAntihack.SendLogUseSkill(gObjUser.GetActiveSkill(), FameSpeed);
	sub_59E590(a4, a5);

}

int __thiscall CBAntihack::SendPacketAttack(unsigned __int16* This, int a2, int a3)
{
	float FameSpeed = *(float*)(BGetModelPlaySpeed(BMDthisa(), gObjUser.lpViewPlayer->m_Model.AnimationID) + 4);
	gBAntihack.SendLogUseSkill(0, FameSpeed);
	return sub_X404D70(This, a2, a3);
}

void __cdecl BUseSkillWarrior(int a1, int a2) 	   //v26 == >=67 <= 72
{
	float FameSpeed = *(float*)(BGetModelPlaySpeed(BMDthisa(), gObjUser.lpViewPlayer->m_Model.AnimationID) + 4);
	gBAntihack.SendLogUseSkill(gObjUser.GetActiveSkill(), FameSpeed);
	return sub_59C260(a1, a2);
}
#include "Interface.h"
DWORD TimeSendSkill = 0;
WORD SkillIDSend = -1;
void CBAntihack::SendLogUseSkill(WORD mSkillID, float mFameSpeed)
{
	if ((GetTickCount() - TimeSendSkill) < 500 && SkillIDSend == mSkillID) return;

	USESKILL_LOG pMsg;
	pMsg.header.set(0xD3, 0xAC, sizeof(pMsg)); //==Packet Cuong Beo
	pMsg.SkillID = mSkillID; //
	pMsg.FameSpeed = mFameSpeed; //
	DataSend((LPBYTE)& pMsg, pMsg.header.size);
	//gInterface.DrawMessage(1, "mSkillID %d", mSkillID);
	TimeSendSkill = GetTickCount();
	SkillIDSend = mSkillID;

}
void __cdecl sub_59CC40(float* a1, float* a2) 	   //v26 == >=67 <= 72
{
	float FameSpeed = *(float*)(BGetModelPlaySpeed(BMDthisa(), gObjUser.lpViewPlayer->m_Model.AnimationID) + 4);
	gBAntihack.SendLogUseSkill(gObjUser.GetActiveSkill(), FameSpeed);

	return ((void(__cdecl*)(float* a1, float* a2))0x0059CC40)(a1, a2);
}
void __cdecl AttackCommon(float* a1, float* a2) 	   //v26 == >=67 <= 72
{
	float FameSpeed = *(float*)(BGetModelPlaySpeed(BMDthisa(), gObjUser.lpViewPlayer->m_Model.AnimationID) + 4);
	gBAntihack.SendLogUseSkill(gObjUser.GetActiveSkill(), FameSpeed);

	return ((void(__cdecl*)(float* a1, float* a2))0x005B3310)(a1, a2);
}


BOOL CBAntihack::CheckMuduleName(char* NameModule) // OK
{
	auto pos = std::find(mListModuleItem.begin(), mListModuleItem.end(), NameModule);

	if (pos != mListModuleItem.end())
	{

		return 1;
	}

	return 0;
}

int PrintModules(DWORD processID)
{

	HMODULE hMods[1024];
	HANDLE hProcess;
	DWORD cbNeeded;
	unsigned int i;
	// Print the process identifier.

	// Get a handle to the process.

	hProcess = OpenProcess(PROCESS_QUERY_INFORMATION |
		PROCESS_VM_READ,
		FALSE, processID);
	if (NULL == hProcess)
		return 1;

	// Get a list of all the modules in this process.
	int Count = 1;
	gBAntihack.HackLogSendGS.clear();
	//gBProtect.HackLogSendGS = "LOG: ";
	if (EnumProcessModules(hProcess, hMods, sizeof(hMods), &cbNeeded))
	{
		for (i = 0; i < (cbNeeded / sizeof(HMODULE)); i++)
		{
			TCHAR szModName[MAX_PATH];

			// Get the full path to the module's file.

			if (GetModuleFileNameEx(hProcess, hMods[i], szModName,
				sizeof(szModName) / sizeof(TCHAR)))
			{
				// Print the module name and handle value.

				//_tprintf(TEXT("\t%s (0x%08X)\n"), szModName, hMods[i]);
				//g_Console.AddMessage(2, TEXT("%d %s (0x%08X)"), Count, PathFindFileName(szModName), hMods[i]);
				if (gBAntihack.CheckMuduleName(PathFindFileName(szModName)))
				{
					gBAntihack.isHackDetect = 1;
					gBAntihack.HackLogSendGS += PathFindFileName(szModName);
					gBAntihack.HackLogSendGS += ",";
					//gInterface.DrawMessage(1, TEXT("%d %s (0x%08X) 111"), Count, PathFindFileName(szModName), hMods[i]);
				}

				Count++;
			}
		}
	}

	// Release the handle to the process.

	CloseHandle(hProcess);

	//gBAntihack.HackLogSendGS.clear();
	//gBAntihack.HackLogSendGS = "[Inject Module ###]";
	//gBProtect.SearchProcess();
	return 1;
}

void CBAntihack::GetModuleInject()
{
	if (gBAntihack.isHackDetect != 0) { return; }

	if (PrintModules(GetCurrentProcessId()) == 1)
	{
		RECV_MODULE pMsg;
		pMsg.header.set(0xD3, 0xAB, sizeof(pMsg));
		pMsg.TypeRecv = gBAntihack.isHackDetect; //
		memcpy(pMsg.LogRecv, strdup(gBAntihack.HackLogSendGS.c_str()), sizeof(pMsg.LogRecv));
		DataSend((LPBYTE)& pMsg, pMsg.header.size);
		gBAntihack.isHackDetect = 0;
	}
}
void CBAntihack::RecvMouduleDataInfo(PMSG_MODULE_DATA_SEND* lpMsg)
{

	mListModuleItem.clear();
	//gInterface.DrawMessage(1, "RecvMouduleDataInfo %d", lpMsg->count);
	for (int i = 0; i < lpMsg->count; i++)
	{
		MODULE_DATA* lpInfo = (MODULE_DATA*)(((BYTE*)lpMsg) + sizeof(PMSG_MODULE_DATA_SEND)+(sizeof(MODULE_DATA)* i));
		mListModuleItem.push_back(lpInfo->NameModule);
		//gInterface.DrawMessage(1, "Aa %s",lpInfo->NameModule);
	}
	//===Scan
	if (lpMsg->count > 0)
	{
		gBAntihack.GetModuleInject();
	}
}

void CBAntihack::LoadBB()
{
	this->mListModuleItem.clear();
	this->isHackDetect = 0;
	//====Get Skill Attack
	SetCompleteHook(0xE8, 0x005B5662, &AttackCommon);
	SetCompleteHook(0xE8, 0x005A1ACB, &sub_59CC40);
	SetCompleteHook(0xE8, 0x005B14A2, &sub_59CC40);

	SetCompleteHook(0xE8, 0x005B563F, &AttackSkillPhep);
	SetCompleteHook(0xE8, 0x005B55D0, &AttackSkill_1);
	SetCompleteHook(0xE8, 0x005A1E60, &AttackSkill_2);
	SetCompleteHook(0xE8, 0x005B55F9, &AttackSkill_2);
	SetCompleteHook(0xE8, 0x005A01A5, &AttackSkillRF); //RF
	SetCompleteHook(0xE8, 0x005A021D, &AttackSkillRF); //RF
	SetCompleteHook(0xE8, 0x005A0232, &AttackSkillRF); //RF
	SetCompleteHook(0xE8, 0x005A02DC, &AttackSkillRF); //RF
	SetCompleteHook(0xE8, 0x005A1F8E, &AttackSkillRF); //RF
	SetCompleteHook(0xE8, 0x005B557B, &AttackSkill_6);
	SetCompleteHook(0xE8, 0x0059B4FB, &BUseSkillWarrior);
	SetCompleteHook(0xE8, 0x005A199A, &BUseSkillWarrior);
	SetCompleteHook(0xE8, 0x005A179C, &CBAntihack::SendPacketAttack); //Attack Meele
}
CBAntihack::~CBAntihack()
{

}

int CBAntihack::GetLargerFrame()
{
	if (pFrameValue1 > MAX_FRAME_VALUE)
	{
		return pFrameValue1;
	}
	else if (pFrameValue2 > MAX_FRAME_VALUE)
	{
		return pFrameValue2;
	}
	else if (pFrameValue3 > MAX_FRAME_VALUE)
	{
		return pFrameValue3;
	}
	else if (pFrameValue4 > MAX_FRAME_VALUE)
	{
		return pFrameValue4;
	}

	return 0;
}
void CBAntihack::RecvGSInfo(BGUARD_REQ_CHECK* pRequest)
{

	gObjUser.Refresh();
	int BLevelCache = *(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x0E);
	//pDrawMessage("gBProtect BGUARD_REQ_CHECK", 0);
	BGUARD_ANS_CHECK pResult;
	pResult.header.set(0xD3, 0xAA, sizeof(pResult)); //Up Level

	ZeroMemory(pResult.Data, sizeof(pResult.Data));

	for (int i = 0; i < emMaxCheckVars; i++)
	{
		pResult.Data[i].Status = true;
	}
	//char DebugText[255];
	//sprintf(DebugText, " Str %d~%d", pRequest->LevelPoint, ViewPoint);
	//pDrawMessage (DebugText, 0 );	

	if (gObjUser.lpPlayer->Level != this->BLevelCache && this->BLevelCache != 0 && gObjUser.lpPlayer->Level > pRequest->Level + MAX_LEVEL_VALUE)
	{
		pResult.Data[emLevel].Status = false;
		pResult.Data[emLevel].Value = gObjUser.lpPlayer->Level;
	}

	if (ViewPoint != pRequest->LevelPoint)
	{
		pResult.Data[emLevelPoint].Status = false;
		pResult.Data[emLevelPoint].Value = ViewPoint;
	}

	if (pRequest->Strength < 65535)
	{
		if ((ViewStrength + ViewAddStrength) > pRequest->Strength + MAX_STAT_LIMIT || pRequest->Strength > (ViewStrength + ViewAddStrength) + MAX_STAT_LIMIT)
		{
			pResult.Data[emStrength].Status = false;
			pResult.Data[emStrength].Value = (ViewStrength + ViewAddStrength);
		}
	}

	if (pRequest->Dexterity < 65535)
	{
		if ((ViewDexterity + ViewAddDexterity) > pRequest->Dexterity + MAX_STAT_LIMIT || pRequest->Dexterity > (ViewDexterity + ViewAddDexterity) + MAX_STAT_LIMIT)
		{
			pResult.Data[emDexterity].Status = false;
			pResult.Data[emDexterity].Value = (ViewDexterity + ViewAddDexterity);
		}
	}

	if (pRequest->Vitality < 65535)
	{
		if ((ViewVitality + ViewAddVitality) > pRequest->Vitality + MAX_STAT_LIMIT || pRequest->Vitality > (ViewVitality + ViewAddVitality) + MAX_STAT_LIMIT)
		{
			pResult.Data[emVitality].Status = false;
			pResult.Data[emVitality].Value = (ViewVitality + ViewAddVitality);
		}
	}

	if (pRequest->Energy < 65535)
	{
		if ((ViewEnergy + ViewAddEnergy) > pRequest->Energy + MAX_STAT_LIMIT || pRequest->Energy > (ViewEnergy + ViewAddEnergy) + MAX_STAT_LIMIT)
		{
			pResult.Data[emEnergy].Status = false;
			pResult.Data[emEnergy].Value = (ViewEnergy + ViewAddEnergy);
		}
	}

	if (pRequest->Leadership < 65535)
	{
		if ((ViewLeadership + ViewAddLeadership) > pRequest->Leadership + MAX_STAT_LIMIT || pRequest->Leadership > (ViewLeadership + ViewAddLeadership) + MAX_STAT_LIMIT)
		{
			pResult.Data[emLeadership].Status = false;
			pResult.Data[emLeadership].Value = (ViewLeadership + ViewAddLeadership);
		}
	}

	int MaxSpeedCountCheck = MAX_SPEED_LIMIT;

	if (gObjUser.lpViewPlayer->WeaponFirstExcellent || gObjUser.lpViewPlayer->WeaponSecondExcellent)
	{
		MaxSpeedCountCheck = (MAX_SPEED_LIMIT * 1.5);
	}

	if ((gObjUser.lpPlayer->AttackSpeed > (pRequest->AttackSpeed + MaxSpeedCountCheck))
		|| (gObjUser.lpPlayer->MagicSpeed > (pRequest->MagicSpeed + MaxSpeedCountCheck)))
	{
		//if(pRequest->AttackSpeed < 1400 &&	pRequest->MagicSpeed < 1400) {
		pResult.Data[emAttackSpeed].Status = false;
		pResult.Data[emAttackSpeed].Value = gObjUser.lpPlayer->AttackSpeed;
		pResult.Data[emMagicSpeed].Value = gObjUser.lpPlayer->MagicSpeed;
		//}
	}

	if (gObjUser.lpViewPlayer->PetSlot != -1)
	{
		if ((gObjUser.lpViewPlayer->PetSlot - 1171) != pRequest->CharSetItem[8])
		{
			pResult.Data[emPetSlot].Status = false;
			pResult.Data[emPetSlot].Value = (gObjUser.lpViewPlayer->PetSlot - 1171);
			gObjUser.lpViewPlayer->PetSlot = pRequest->CharSetItem[8] + 1171;
		}
	}

	if (gObjUser.lpViewPlayer->WeaponFirstSlot != -1 && !InChaosCastle(pMapNumber)) {

		if ((gObjUser.lpViewPlayer->WeaponFirstSlot - 1171) != pRequest->CharSetItem[0])
		{
			pResult.Data[emWeaponFirstSlot].Status = false;
			pResult.Data[emWeaponFirstSlot].Value = (gObjUser.lpViewPlayer->WeaponFirstSlot - 1171);
			gObjUser.lpViewPlayer->WeaponFirstSlot = pRequest->CharSetItem[0] + 1171;
		}
	}

	if (gObjUser.lpViewPlayer->WeaponSecondSlot != -1 && !InChaosCastle(pMapNumber)) {

		if ((gObjUser.lpViewPlayer->WeaponSecondSlot - 1171) != pRequest->CharSetItem[1])
		{
			pResult.Data[emWeaponSecondSlot].Status = false;
			pResult.Data[emWeaponSecondSlot].Value = (gObjUser.lpViewPlayer->WeaponSecondSlot - 1171);
			gObjUser.lpViewPlayer->WeaponSecondSlot = pRequest->CharSetItem[1] + 1171;
		}
	}

	if (gObjUser.lpViewPlayer->HelmSlot >= ITEM2(7, 0) && gObjUser.lpViewPlayer->HelmSlot < ITEM2(7, 512)) {

		if ((gObjUser.lpViewPlayer->HelmSlot - 1171) != pRequest->CharSetItem[2])
		{
			pResult.Data[emHelmSlot].Status = false;
			pResult.Data[emHelmSlot].Value = (gObjUser.lpViewPlayer->HelmSlot - 1171);
			//gObjUser.lpViewPlayer->HelmSlot =  pRequest->CharSetItem[2]+1171;
		}
	}

	if (gObjUser.lpViewPlayer->ArmorSlot >= ITEM2(8, 0) && gObjUser.lpViewPlayer->ArmorSlot < ITEM2(8, 512)) {



		if ((gObjUser.lpViewPlayer->ArmorSlot - 1171) != pRequest->CharSetItem[3])
		{
			pResult.Data[emArmorSlot].Status = false;
			pResult.Data[emArmorSlot].Value = (gObjUser.lpViewPlayer->ArmorSlot - 1171);
			//gObjUser.lpViewPlayer->ArmorSlot =  pRequest->CharSetItem[3]+1171;
		}
	}


	if (gObjUser.lpViewPlayer->PantsSlot >= ITEM2(9, 0) && gObjUser.lpViewPlayer->PantsSlot < ITEM2(9, 512)) {

		if ((gObjUser.lpViewPlayer->PantsSlot - 1171) != pRequest->CharSetItem[4])
		{
			pResult.Data[emPantsSlot].Status = false;
			pResult.Data[emPantsSlot].Value = (gObjUser.lpViewPlayer->PantsSlot - 1171);
			//gObjUser.lpViewPlayer->PantsSlot =  pRequest->CharSetItem[4]+1171;
		}
	}

	if (gObjUser.lpViewPlayer->GlovesSlot >= ITEM2(10, 0) && gObjUser.lpViewPlayer->GlovesSlot < ITEM2(10, 512)) {

		if ((gObjUser.lpViewPlayer->GlovesSlot - 1171) != pRequest->CharSetItem[5])
		{
			pResult.Data[emGlovesSlot].Status = false;
			pResult.Data[emGlovesSlot].Value = (gObjUser.lpViewPlayer->GlovesSlot - 1171);
			//gObjUser.lpViewPlayer->GlovesSlot =  pRequest->CharSetItem[5]+1171;
		}
	}

	if (gObjUser.lpViewPlayer->BootsSlot >= ITEM2(11, 0) && gObjUser.lpViewPlayer->BootsSlot < ITEM2(11, 512)) {

		if ((gObjUser.lpViewPlayer->BootsSlot - 1171) != pRequest->CharSetItem[6])
		{
			pResult.Data[emBootsSlot].Status = false;
			pResult.Data[emBootsSlot].Value = (gObjUser.lpViewPlayer->BootsSlot - 1171);
			//gObjUser.lpViewPlayer->BootsSlot =  pRequest->CharSetItem[6]+1171;
		}
	}

	if (gObjUser.lpViewPlayer->WingsSlot != -1) {

		if ((gObjUser.lpViewPlayer->WingsSlot - 1171) != pRequest->CharSetItem[7] && (gObjUser.lpViewPlayer->WingsSlot - 1171) != 6279 && pRequest->CharSetItem[7] != 6193)
		{
			pResult.Data[emWingsSlot].Status = false;
			pResult.Data[emWingsSlot].Value = (gObjUser.lpViewPlayer->WingsSlot - 1171);
			gObjUser.lpViewPlayer->WingsSlot = pRequest->CharSetItem[7] + 1171;
		}
	}

	DataSend((BYTE*)& pResult, pResult.header.size);


}
