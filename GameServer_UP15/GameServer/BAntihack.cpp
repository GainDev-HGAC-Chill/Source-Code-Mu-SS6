#include "stdafx.h"
#include "BAntihack.h"
#include "DSProtocol.h"
#include "EffectManager.h"
#include "Map.h"
#include "MemScript.h"
#include "Notice.h"
#include "Util.h"
#include "ItemOptionRate.h"
#include "ObjectManager.h"
#include "Log.h"
#include "User.h"
#include "Trade.h"
#include "Party.h"
#include "Path.h"
#include "Skill.h"
#include "SkillManager.h"
#include "EffectManager.h"
#include "DSProtocol.h"
#include "Attack.h"

CBAntihack gBAntihack;

CBAntihack::CBAntihack()
{
	this->HackPlayerEditor = new DATA_CONFIG;
	this->HackSpeedMove = new DATA_CONFIG_SPEEDMOVE;
	this->HackSpeedCheck = new DATA_CONFIG;
	this->HackCheckInject = new DATA_CONFIG;
}

CBAntihack::~CBAntihack()
{

}
void CBAntihack::ClearDetectCount(int aIndex)
{
	for (int n = 0; n < 5; n++)
	{
		gObj[aIndex].BHackDetectCount[n] = 0;
	}
}
void CBAntihack::SetUserZeroCache(int aIndex)
{
	//BProtect
	ClearDetectCount(aIndex);
	gObj[aIndex].BHackTimeClearDetectCount = 0;
	gObj[aIndex].BHackBlockSkillTime = 0;
	gObj[aIndex].BHackTimeSendClient = 0;
	gObj[aIndex].BHackWaitRecv = 0;
	gObj[aIndex].BProtectBlockAttack = 0;
	//==CheckSpamRequest
	FillMemory(gObj[aIndex].BTargetIndex, sizeof(gObj[aIndex].BTargetIndex), 0);
	FillMemory(gObj[aIndex].BTargetTime, sizeof(gObj[aIndex].BTargetTime), 0);
	//---Cache Move XY
	gObj[aIndex].BProtect_X = 0;
	gObj[aIndex].BProtect_Y = 0;
	gObj[aIndex].BProtect_MAP = -1;
	gObj[aIndex].BProtect_PV = 0;
	gObj[aIndex].BProtectMove_Time = 0;
	//=== Float Speed Animation
	FillMemory(gObj[aIndex].GroupSkill, sizeof(gObj[aIndex].GroupSkill), 0);
	//===AutoSkill
	gObj[aIndex].UseSkillTime = 0;
	gObj[aIndex].UseFameSpeed = 0.0f;
	gObj[aIndex].UseSkillSkillId = 0xFFFF;

}

void CBAntihack::LoadFileXML(char* FilePath)
{
	this->GhiLogHack = 0;
	this->DelayScan = 1;
	this->DelayClear = 1;
	this->HackPlayerEditor->Clear();
	this->HackSpeedMove->Clear();
	this->HackSpeedCheck->Clear();
	this->HackCheckInject->Clear();
	this->RandomSend = 0;
	//====================

	pugi::xml_document file;
	pugi::xml_parse_result res = file.load_file(FilePath);
	if (res.status != pugi::status_ok) {
		ErrorMessageBox("File %s load fail. Error: %s", FilePath, res.description());
		return;
	}
	//--
	pugi::xml_node oAntihackSystem = file.child("AntihackSystem");
	this->GhiLogHack = oAntihackSystem.attribute("GhiLogHack").as_int();
	this->DelayScan = oAntihackSystem.attribute("DelayScan").as_int();
	this->DelayClear = oAntihackSystem.attribute("DelayClear").as_int();
	//= Mess Load
	pugi::xml_node Message = oAntihackSystem.child("Message");
	for (pugi::xml_node msg = Message.child("Msg"); msg; msg = msg.next_sibling())
	{
		MESSAGE_INFO_ANTIHACK info;

		info.Index = msg.attribute("Index").as_int();

		strcpy_s(info.Message, msg.attribute("Text").as_string());

		this->m_MessageInfoBP.insert(std::pair<int, MESSAGE_INFO_ANTIHACK>(info.Index, info));
	}
	//= HackPlayerEditor
	pugi::xml_node oHackPlayerEditor = oAntihackSystem.child("HackPlayerEditor");
	this->HackPlayerEditor->DebugLog = oHackPlayerEditor.attribute("DebugLog").as_int();
	this->HackPlayerEditor->Enabled = oHackPlayerEditor.attribute("Enabled").as_int();
	this->HackPlayerEditor->NoticeMess = oHackPlayerEditor.attribute("NoticeMess").as_int();
	this->HackPlayerEditor->DetectCount = oHackPlayerEditor.attribute("DetectCount").as_int();
	this->HackPlayerEditor->TypeCheck = oHackPlayerEditor.attribute("TypeCheck").as_int();
	this->HackPlayerEditor->BlockSkillDelay = oHackPlayerEditor.attribute("BlockSkillDelay").as_int();
	//= HackSpeedMove
	pugi::xml_node oHackSpeedMove = oAntihackSystem.child("HackSpeedMove");
	this->HackSpeedMove->DebugLog = oHackSpeedMove.attribute("DebugLog").as_int();
	this->HackSpeedMove->Enabled = oHackSpeedMove.attribute("Enabled").as_int();
	this->HackSpeedMove->NoticeMess = oHackSpeedMove.attribute("NoticeMess").as_int();
	this->HackSpeedMove->DetectCount = oHackSpeedMove.attribute("DetectCount").as_int();
	this->HackSpeedMove->GateMove = oHackSpeedMove.attribute("GateMove").as_int();
	this->HackSpeedMove->SpeedNormal = oHackSpeedMove.attribute("SpeedNormal").as_float();
	this->HackSpeedMove->SpeedPet = oHackSpeedMove.attribute("SpeedPet").as_float();
	this->HackSpeedMove->SpeedWing = oHackSpeedMove.attribute("SpeedWing").as_float();
	//= HackSpeedCheck
	pugi::xml_node oHackSpeedCheck = oAntihackSystem.child("HackSpeedCheck");
	this->HackSpeedCheck->DebugLog = oHackSpeedCheck.attribute("DebugLog").as_int();
	this->HackSpeedCheck->Enabled = oHackSpeedCheck.attribute("Enabled").as_int();
	this->HackSpeedCheck->NoticeMess = oHackSpeedCheck.attribute("NoticeMess").as_int();
	this->HackSpeedCheck->DetectCount = oHackSpeedCheck.attribute("DetectCount").as_int();
	this->HackSpeedCheck->TypeCheck = oHackSpeedCheck.attribute("TypeCheck").as_int();
	this->HackSpeedCheck->BlockSkillDelay = oHackSpeedCheck.attribute("BlockSkillDelay").as_int();
	//= HackCheckInject
	pugi::xml_node oHackCheckInject = oAntihackSystem.child("HackCheckInject");
	this->HackCheckInject->DebugLog = oHackCheckInject.attribute("DebugLog").as_int();
	this->HackCheckInject->Enabled = oHackCheckInject.attribute("Enabled").as_int();
	this->HackCheckInject->NoticeMess = oHackCheckInject.attribute("NoticeMess").as_int();
	this->HackCheckInject->DetectCount = oHackCheckInject.attribute("DetectCount").as_int();
	this->HackCheckInject->TypeCheck = oHackCheckInject.attribute("TypeCheck").as_int();
	this->HackCheckInject->BlockSkillDelay = oHackCheckInject.attribute("BlockSkillDelay").as_int();
	LogAdd(LOG_BLUE, "[AntihackSystem] HPE (%d), HSM (%d), HSC (%d), HCJ (%d)",
		this->HackPlayerEditor->Enabled,
		this->HackSpeedMove->Enabled,
		this->HackSpeedCheck->Enabled,
		this->HackCheckInject->Enabled);
	this->LoadDBAntihack();
	if (this->HackPlayerEditor->Enabled) this->RandomSend++;
	if (this->HackCheckInject->Enabled) this->RandomSend++;
}

char* CBAntihack::GetMessage(int index) // OK
{
	std::map<int, MESSAGE_INFO_ANTIHACK>::iterator it = this->m_MessageInfoBP.find(index);

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

int CBAntihack::GetCountXDmgInSpeed(LPOBJ lpObj, int Group) // OK
{
	if (Group == 0)
	{
		return 0;
	}
	for (std::vector<XDAMEHACK_DATA>::iterator it = this->m_XDameData.begin(); it != this->m_XDameData.end(); it++)
	{
		if (it->Group == Group && lpObj->PhysiSpeed >= it->MinSpeed && (lpObj->PhysiSpeed <= it->MaxSpeed || it->MaxSpeed == -1))
		{
			return  it->MaxCount;
		}
	}

	return -1;
}
HACKSPEED_DATA* CBAntihack::GetDataHackSpeed(int SkillID, int SkillType) // OK
{

	for (std::map<int, HACKSPEED_DATA>::iterator it = this->m_HackSpeedCheckDB.begin(); it != this->m_HackSpeedCheckDB.end(); it++)
	{
		if (it == this->m_HackSpeedCheckDB.end())
		{
			return 0;
		}
		if (SkillID == it->second.m_SkillID)
		{
			if (SkillType == it->second.m_SkillType || it->second.m_SkillType == -1)
			{
				return &it->second;
			}
		}
	}

	return 0;
}

void CBAntihack::LoadDBAntihack()
{

	LPSTR path = gPath.GetFullPath("Hack\\AntiHackGSDB.xml");
	pugi::xml_document file;
	pugi::xml_parse_result res = file.load_file(path);

	if (res.status != pugi::status_ok) {
		ErrorMessageBox("File %s load fail. Error: %s", path, res.description());
		return;
	}
	this->m_HackSpeedCheckDB.clear();
	pugi::xml_node eHackSpeedCheckDB = file.child("HackSpeedCheckDB");

	int HackSpeedDBCount = 0;
	for (pugi::xml_node rHackSpeedCheckDB = eHackSpeedCheckDB.child("Config"); rHackSpeedCheckDB; rHackSpeedCheckDB = rHackSpeedCheckDB.next_sibling())
	{
		HACKSPEED_DATA info;

		info.m_SkillID = rHackSpeedCheckDB.attribute("Skill").as_int(0);
		info.m_SkillType = rHackSpeedCheckDB.attribute("SkillType").as_int(0);
		info.m_HitDetect = rHackSpeedCheckDB.attribute("HitDectect").as_int(-1);
		info.m_DelayCountMin = rHackSpeedCheckDB.attribute("CountMaxInSec").as_int(0);
		info.m_DelayMinMs = rHackSpeedCheckDB.attribute("DelayMinMs").as_int(0);
		info.m_DelayType = rHackSpeedCheckDB.attribute("DelayType").as_int(0);
		info.m_DelayValue = rHackSpeedCheckDB.attribute("DelayValue").as_int(0);
		info.m_DelayGroup = rHackSpeedCheckDB.attribute("DelayGroup").as_int(0);
		info.m_XDmgAI = rHackSpeedCheckDB.attribute("XDmgAIGroup").as_int(0);
		this->m_HackSpeedCheckDB.insert(std::pair<int, HACKSPEED_DATA>(HackSpeedDBCount, info));
		HackSpeedDBCount++;
	}
	this->m_XDameData.clear();
	pugi::xml_node oHackXdameCheckDB = file.child("HackXdameCheckDB");
	for (pugi::xml_node rXDmgAI = oHackXdameCheckDB.child("XDmgAI"); rXDmgAI; rXDmgAI = rXDmgAI.next_sibling())
	{
		int Group = rXDmgAI.attribute("Group").as_int();
		for (pugi::xml_node rCheck = rXDmgAI.child("Check"); rCheck; rCheck = rCheck.next_sibling())
		{
			XDAMEHACK_DATA infoXDmg;
			infoXDmg.Group = Group;
			infoXDmg.MinSpeed = rCheck.attribute("MinSpeed").as_int(0);
			infoXDmg.MaxSpeed = rCheck.attribute("MaxSpeed").as_int(0);
			infoXDmg.MaxCount = rCheck.attribute("MaxCount").as_int(0);
			this->m_XDameData.push_back(infoXDmg);
		}
	}

	this->m_HackCheckInjectDB.clear();
	pugi::xml_node eHackCheckInjectDB = file.child("HackCheckInjectDB");

	int HackCheckInjectDBCount = 0;
	for (pugi::xml_node rHackCheckInjectDB = eHackCheckInjectDB.child("BlackList"); rHackCheckInjectDB; rHackCheckInjectDB = rHackCheckInjectDB.next_sibling())
	{
		MODULE_DATA infoModule;

		infoModule.Index = HackCheckInjectDBCount;
		//strcpy_s(infoModule.NameModule, rHackCheckInjectDB.attribute("Name").as_string());
		memcpy(infoModule.NameModule, rHackCheckInjectDB.attribute("Name").as_string(), sizeof(infoModule.NameModule));

		this->m_HackCheckInjectDB.insert(std::pair<int, MODULE_DATA>(HackCheckInjectDBCount, infoModule));
		HackCheckInjectDBCount++;
	}

	LogAdd(LOG_BLUE, "[AntihackSystem]Load DB -> HackSpeedDBCount [%d] XDmgData [%d] InjectDB[%d]", HackSpeedDBCount, this->m_XDameData.size(), this->m_HackCheckInjectDB.size());

}
void CBAntihack::CalculateSkillFloat(int aIndex)
{
	LPOBJ lpUser = &gObj[aIndex];
	float nAttack1 = lpUser->PhysiSpeed * 0.004000000189989805;	//dword ptr [ebp-0x10]
	float nAttack2 = lpUser->PhysiSpeed * 0.002000000094994903;	//dword ptr [ebp-0x8]
	float nMagic1 = lpUser->MagicSpeed * 0.004000000189989805;	//dword ptr [ebp-0xC]
	float nMagic2 = lpUser->MagicSpeed * 0.002000000094994903;	//dword ptr [ebp-0x4]

	for (int n = 0; n < 256; n++)
	{
		lpUser->GroupSkill[n] = 0;
	}

	lpUser->GroupSkill[51] = nAttack1 + 0.300000011920929;
	lpUser->GroupSkill[60] = nAttack1 + 0.300000011920929;
	lpUser->GroupSkill[61] = nAttack1 + 0.300000011920929;
	lpUser->GroupSkill[62] = nAttack1 + 0.2700000107288361;
	lpUser->GroupSkill[63] = nAttack1 + 0.300000011920929;
	lpUser->GroupSkill[64] = nAttack1 + 0.239999994635582;
	lpUser->GroupSkill[65] = nAttack1 + 0.239999994635582;
	lpUser->GroupSkill[66] = 0.3799999952316284;
	lpUser->GroupSkill[67] = 0.3400000035762787;
	lpUser->GroupSkill[71] = nAttack1 + 0.25;
	lpUser->GroupSkill[80] = nAttack1 + 0.25;
	lpUser->GroupSkill[131] = nAttack1 + 0.300000011920929;
	lpUser->GroupSkill[136] = nAttack1 + 0.4000000059604645;
	lpUser->GroupSkill[137] = nAttack1 + 0.300000011920929;
	lpUser->GroupSkill[138] = nAttack1 + 0.2000000029802322;
	lpUser->GroupSkill[145] = nAttack1 + 0.25;
	lpUser->GroupSkill[146] = nMagic2 + 0.2899999916553497;
	lpUser->GroupSkill[147] = nMagic2 + 0.2899999916553497;
	lpUser->GroupSkill[150] = nMagic1 + 0.25;
	lpUser->GroupSkill[152] = nMagic2 + 0.4000000059604645;
	lpUser->GroupSkill[153] = nMagic2 + 0.6000000238418579;
	lpUser->GroupSkill[154] = nMagic2 + 0.5;
	lpUser->GroupSkill[156] = nMagic2 + 0.300000011920929;
	lpUser->GroupSkill[160] = nMagic2 + 0.25;
	lpUser->GroupSkill[168] = nMagic2 + 0.25;
	lpUser->GroupSkill[176] = 0.300000011920929;
	lpUser->GroupSkill[183] = nMagic1 + 0.550000011920929;
	lpUser->GroupSkill[184] = nMagic2 + 0.6899999976158142;
	lpUser->GroupSkill[185] = nMagic2 + 0.3499999940395355;
	lpUser->GroupSkill[247] = nAttack2 + 0.4000000059604645;
	lpUser->GroupSkill[248] = nAttack2 + 0.4000000059604645;
	lpUser->GroupSkill[249] = nAttack2 + 0.4000000059604645;
	lpUser->GroupSkill[250] = nAttack2 + 0.300000011920929;
	lpUser->GroupSkill[253] = nAttack2 + 0.300000011920929;
	lpUser->GroupSkill[255] = 0.3499999940395355;
}
#include "Protect.h"


BOOL CBAntihack::bpSpeedHackCheck(int aIndex, int bIndex, WORD functionID, WORD mskill)
{
	LPOBJ lpObj = &gObj[aIndex];

	int Number = aIndex - OBJECT_START_USER;

	if (bIndex > MAX_OBJECT && bIndex != 0xFFFF)
	{
		return false;
	}



	if (gObjIsConnected(aIndex) == 0)
	{
		return false;
	}


	if (!this->HackSpeedCheck->Enabled || lpObj->Type != OBJECT_USER || lpObj->m_OfflineMode != 0 || lpObj->IsFakeOnline != 0)
	{
		return true;
	}



	if (mskill != lpObj->UseSkillSkillId)
	{
		if (this->HackSpeedCheck->DebugLog >= 1)
		{
			LogAdd(LOG_RED, "[Antihack] Check AutoSkill 1");
		}
		gObj[aIndex].BHackDetectCount[eHackSpeedCheck]++;
		return false;
	}
	else if ((GetTickCount() - lpObj->UseSkillTime) > 5000)
	{
		if (this->HackSpeedCheck->DebugLog >= 1)
		{
			LogAdd(LOG_RED, "[Antihack] Check AutoSkill 2");
		}
		gObj[aIndex].BHackDetectCount[eHackSpeedCheck]++;
		return false;
	}
	else if ((lpObj->UseFameSpeed > 35.0f))
	{
		if (this->HackSpeedCheck->DebugLog >= 1)
		{
			LogAdd(LOG_RED, "[Antihack] Check AutoSkill 3");
		}
		gObj[aIndex].BHackDetectCount[eHackSpeedCheck]++;
		return false;
	}

	if (gObj[aIndex].BHackDetectCount[eHackSpeedCheck] >= this->HackSpeedCheck->DetectCount && this->HackSpeedCheck->DetectCount > 0)
	{
		if (this->HackSpeedCheck->TypeCheck == 1 && gObj[aIndex].BHackBlockSkillTime < GetTickCount())
		{
			gObj[aIndex].BHackBlockSkillTime = GetTickCount() + (this->HackSpeedCheck->BlockSkillDelay * 1000);
		}
		if (this->HackSpeedCheck->NoticeMess != -1)
		{
			gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, this->GetMessage(this->HackSpeedCheck->NoticeMess));
		}
		if (this->GhiLogHack)
		{
			gLog.Output(LOG_HACK, "[HackSpeedCheck][%s][%s] HackSpeedCheck Detect! ", gObj[aIndex].Account, gObj[aIndex].Name);

		}
		return false;
	}
	int iSkillType = -1;
	int iType = 0;
	int iValue = 0;
	int iGroup = 0;
	int iCountMaxInSec = 50;
	int iskill = mskill;
	int iHitDetect = -1;
	int iXDmgAI = -1;
	int iDelayMinInSec = 30;

	if (functionID == 0 || iskill == 0)		//Attack by Hand
	{
		//147 Phep
		iGroup = 80;
		iValue = 6;
		iType = 1;
	}

	if (iskill > MAX_SKILL)
	{
		iGroup = 0;
		iType = 0;
		return false;
	}

	HACKSPEED_DATA* mInfoSpeedChar = this->GetDataHackSpeed(iskill, functionID);

	if (mInfoSpeedChar != 0)
	{
		iSkillType = mInfoSpeedChar->m_SkillType;
		iType = mInfoSpeedChar->m_DelayType;//this->m_DelayType[iskill];
		iValue = mInfoSpeedChar->m_DelayValue;
		iGroup = mInfoSpeedChar->m_DelayGroup;
		iCountMaxInSec = mInfoSpeedChar->m_DelayCountMin;
		iHitDetect = mInfoSpeedChar->m_HitDetect;
		iXDmgAI = this->GetCountXDmgInSpeed(lpObj, mInfoSpeedChar->m_XDmgAI);
		iDelayMinInSec = mInfoSpeedChar->m_DelayMinMs;
	}
	char sBuff[255] = { 0 };
	DWORD nTimeCalc = GetTickCount() - lpObj->BUserAttack[iskill].BPLastAttackTime[functionID];
	int nHitInSec = 0;
	lpObj->BUserAttack[iskill].BPLastAttackTime[functionID] = GetTickCount();


	//if (lpObj->mLastAttackSkillID != iskill)
	//{
	//	lpObj->mLastAttackSkillID = iskill;
	//	return true;
	//}

	if (lpObj->BUserAttack[iskill].mSkillFloatHit[functionID] > iCountMaxInSec && iCountMaxInSec > -1 && (functionID == iSkillType || iSkillType == -1))
	{
		if (this->HackSpeedCheck->DebugLog >= 1)
		{
			LogAdd(LOG_RED, "[iCountMaxInSec][%d]Type %d Skill [%d] Calc [%d] Min (%d)  Detect [%d] MaxInSec [%d]", functionID, iType, iskill, nTimeCalc, iDelayMinInSec, lpObj->BUserAttack[iskill].BPDetectCount[functionID], iCountMaxInSec);
		}
		lpObj->BProtectBlockAttack = 1;
		gObj[aIndex].BHackDetectCount[eHackSpeedCheck]++;
		return false;
	}

	//===Lon hon HitDetect thi chan hoan toan
	if (iHitDetect != -1 && lpObj->BUserAttack[iskill].BPDetectCount[functionID] > iHitDetect)
	{
		lpObj->BProtectBlockAttack = 1;
		gObj[aIndex].BHackDetectCount[eHackSpeedCheck]++;
		return false;
	}

	if (iXDmgAI != -1)
	{

		if (lpObj->BUserAttack[iskill].xDmgCache[functionID] > iXDmgAI)
		{
			if (this->HackSpeedCheck->DebugLog >= 1)
			{
				LogAdd(LOG_RED, "[iXDmgAI] [%d]Skill %d (%d/%d)", functionID, iskill, lpObj->BUserAttack[iskill].xDmgCache[functionID], iXDmgAI);
			}
			lpObj->BProtectBlockAttack = 1;
			gObj[aIndex].BHackDetectCount[eHackSpeedCheck]++;
			return false;
		}
	}

	if (iGroup != 0 && iType == 1 && (functionID == iSkillType || iSkillType == -1))
	{
		this->CalculateSkillFloat(aIndex);
		int i;
		float k = lpObj->GroupSkill[iGroup];
		if (k != 0)
		{

			//LogAdd(LOG_BLUE, "Hack:(%d,%d,%d) %f", iType, iValue, iGroup, k);
			for (i = 0; k <= iValue; i++)
			{
				k = k + lpObj->GroupSkill[iGroup];
			}

			int itimeskill = i * 30;		// 30ms is time of a loop in client

			if (itimeskill > 0)
			{
				nHitInSec = (1000 / itimeskill) + 1;
			}
			else if (iDelayMinInSec > 0 && itimeskill == 0)
			{
				nHitInSec = (1000 / iDelayMinInSec) + 1;
			}
			if (nHitInSec > iCountMaxInSec && iCountMaxInSec != -1)
			{
				nHitInSec = iCountMaxInSec;
			}

			if (this->HackSpeedCheck->DebugLog >= 1)
			{
				//gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[%d][%d/%d]Skill [%d] Calc [%d~%d] Min (%d) Sp (%f/%d) i= %d, Dec %d/%d xDmg %d/%d", functionID, this->mSkillFloatHit[Number], nHitInSec, iskill, nTimeCalc, itimeskill, iDelayMinInSec, k, iValue, i, lpObj->bp_DetectCount, iHitDetect, this->xDmgCache[Number], iXDmgAI);
				LogAdd(LOG_RED, "(%d)[%d][%d/%d]Skill [%d] Calc [%d~%d] Min (%d) Sp (%f/%d) i= %d, HDec %d/%d xDmg %d/%d", bIndex, functionID, lpObj->BUserAttack[iskill].mSkillFloatHit[functionID], nHitInSec, iskill, nTimeCalc, itimeskill, iDelayMinInSec, k, iValue, i, lpObj->BUserAttack[iskill].BPDetectCount[functionID], iHitDetect, lpObj->BUserAttack[iskill].xDmgCache[functionID], iXDmgAI);
			}

			if (nTimeCalc > 0)
			{
				//=== Nho Hon MS Calc && != X
				if ((nTimeCalc < iDelayMinInSec))
				{
					lpObj->BUserAttack[iskill].BPDetectCount[functionID]++;
					return false;
				}
				//=== Nho Hon MS Calc && != X
				if ((nTimeCalc < itimeskill) && i > 0)
				{
					lpObj->BUserAttack[iskill].BPDetectCount[functionID]++;
					return false;
				}
				//===== Vuot Chi So Hit /Sec
				if (lpObj->BUserAttack[iskill].mSkillFloatHit[functionID] > nHitInSec && nHitInSec > 0)
				{
					lpObj->BProtectBlockAttack = 1;
					gObj[aIndex].BHackDetectCount[eHackSpeedCheck]++;
					return false;
				}
			}
			else
			{
				lpObj->BUserAttack[iskill].xDmgCache[functionID]++;

				//if (iXDmgAI > 0)
				//{
				//	lpObj->BPDetectCount[functionID]++;
				//	return false;
				//}
			}
		}
	}
	else if (iType == 2)
	{
		if (this->HackSpeedCheck->DebugLog >= 1)
		{
			LogAdd(LOG_RED, "[%d]Type %d  Skill [%d]  , Delay %d / %d, Detect = %d", functionID, iType, iskill, nTimeCalc, iValue, lpObj->BUserAttack[iskill].BPDetectCount);
		}
		if (nTimeCalc < iValue)
		{
			return false;
		}
	}
	else
	{

		if (this->HackSpeedCheck->DebugLog == 2)
		{
			LogAdd(LOG_RED, "[OK][%d]Type %d Skill [%d]  , Delay %d / %d, Detect = %d", functionID, iType, iskill, nTimeCalc, iValue, lpObj->BUserAttack[iskill].BPDetectCount);
		}
	}

	lpObj->BUserAttack[iskill].mSkillFloatHit[functionID]++;
	return true;
}
void CBAntihack::ViewportProc(int aIndex)
{
	if (OBJECT_RANGE(aIndex) == 0)
	{
		return;
	}

	if (gObj[aIndex].Type != OBJECT_USER || gObj[aIndex].m_OfflineMode == 1 || gObj[aIndex].IsFakeOnline == 1)
	{
		goto Exit;
	}

	if (gObj[aIndex].Connected < OBJECT_ONLINE || gObj[aIndex].Live == 0 || gObj[aIndex].State != OBJECT_PLAYING || gObj[aIndex].Teleport != 0)
	{
		goto Exit;
	}

	//==Check Move Speed s
	if (this->HackSpeedMove->Enabled)
	{
		if ((GetTickCount() - gObj[aIndex].BProtectMove_Time) < 3000 || gObj[aIndex].BProtect_X == 0 && gObj[aIndex].BProtect_Y == 0)
		{
			goto Exit;
		}
		if (gObj[aIndex].RegenOk > 0 || gObj[aIndex].Teleport != 0)
		{
			goto Exit;
		}
		float PhamViChoPhep = 0.0f;

		if (gObj[aIndex].Map >= 18 && (gObj[aIndex].Map <= 23 || gObj[aIndex].Map == 53))
		{
			goto Exit;
		}
		else
		{
			if (gObj[aIndex].BProtect_MAP == gObj[aIndex].Map)
			{

				gObj[aIndex].BProtect_PV = (float)sqrt(pow(((float)gObj[aIndex].X - (float)gObj[aIndex].BProtect_X), (float)2) + pow(((float)gObj[aIndex].Y - (float)gObj[aIndex].BProtect_Y), (float)2));


				//=== Check Item
				if (gObj[aIndex].Inventory[7].IsItem())
				{
					PhamViChoPhep = this->HackSpeedMove->SpeedWing;
				}
				else if (gObj[aIndex].Inventory[8].m_Index == 6660 || gObj[aIndex].Inventory[8].m_Index == 6693) //Chien Ma, Soi TInh
				{
					PhamViChoPhep = this->HackSpeedMove->SpeedPet;
				}
				else
				{
					PhamViChoPhep = this->HackSpeedMove->SpeedNormal;
				}



				if (this->HackSpeedMove->DebugLog != 0)
				{
					gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[DebugMove][%d] Move (%f) || MaxMove (%f)", gObj[aIndex].BHackDetectCount[eHackSpeedMove], gObj[aIndex].BProtect_PV, PhamViChoPhep);
				}

				if (gObj[aIndex].BProtect_PV > PhamViChoPhep && PhamViChoPhep > 0)
				{

					if (this->HackSpeedMove->NoticeMess != -1)
					{
						gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, this->GetMessage(this->HackSpeedMove->NoticeMess));
					}
					gObj[aIndex].BHackDetectCount[eHackSpeedMove]++;

					if (gObj[aIndex].BHackDetectCount[eHackSpeedMove] >= this->HackSpeedMove->DetectCount && this->HackSpeedMove->DetectCount >0
						&& this->HackSpeedMove->GateMove > 0)
					{
						gObjMoveGate(aIndex, this->HackSpeedMove->GateMove);
					}
					else
					{
						gObjTeleport(aIndex, gObj[aIndex].Map, (BYTE)gObj[aIndex].BProtect_X, (BYTE)gObj[aIndex].BProtect_Y);
					}
					if (this->GhiLogHack)
					{
						gLog.Output(LOG_HACK, "[HackSpeedMove][%s][%s]Move : [%f > %f] ToaDoCu: (%d/%d) ToaDoMoi: (%d/%d)", gObj[aIndex].Account, gObj[aIndex].Name, gObj[aIndex].BProtect_PV, PhamViChoPhep, gObj[aIndex].BProtect_X, gObj[aIndex].BProtect_Y, gObj[aIndex].X, gObj[aIndex].Y);

					}//gNotice.GCNoticeSend(aIndex, 0, 0, 0, 0, 0, 0, "[DetectMove] %d > %d", gObj[aIndex].BProtect_PV, PhamViChoPhep);
				}
			}
		}

	}

Exit:
	gObj[aIndex].BProtect_X = gObj[aIndex].X;
	gObj[aIndex].BProtect_Y = gObj[aIndex].Y;
	gObj[aIndex].BProtect_MAP = gObj[aIndex].Map;

	if (gObj[aIndex].Type == OBJECT_USER && gObj[aIndex].m_OfflineMode == 0 && gObj[aIndex].IsFakeOnline == 0)
	{
		//==Clear In Sec	
		for (int n = 0; n < MAX_SKILL; n++)
		{
			gObj[aIndex].BUserAttack[n].Clear();
		}

		if (gObj[aIndex].BProtectBlockAttack == 1)
		{
			gObj[aIndex].BProtectBlockAttack = 0;
		}
		if (GetTickCount() > gObj[aIndex].BHackTimeSendClient && gObj[aIndex].Connected >= OBJECT_ONLINE)
		{
			if (this->RandomSend > 0)
			{
				srand(static_cast<int>(time(NULL)));
				int Random = (rand() % this->RandomSend) + 1;
				//LogAdd(LOG_RED, "Send Random %d Check (%d)", Random, this->RandomSend);

				switch (Random)
				{
				case 1:
				{
						  //LogAdd(LOG_BLUE, "[Scan] SendPlayerEditor ");
						  this->SendPlayerEditor(aIndex);
				}
					break;
				case 2:
				{
						  //LogAdd(LOG_BLUE, "[Scan] BPModuleDataSend ");
						  this->BPModuleDataSend(aIndex);
				}
					break;
				default:
					break;
				}

			}
			//BPModuleDataSend
			gObj[aIndex].BHackTimeSendClient = GetTickCount() + (this->DelayScan * 1000);
		}
		if (GetTickCount() > gObj[aIndex].BHackTimeClearDetectCount)
		{
			this->ClearDetectCount(aIndex);

			gObj[aIndex].BHackTimeClearDetectCount = GetTickCount() + (this->DelayClear * 1000);
		}
	}

	return;
}

void CBAntihack::SendPlayerEditor(int aIndex)
{
	if (!this->HackPlayerEditor->Enabled || gObj[aIndex].Type != OBJECT_USER || gObj[aIndex].m_OfflineMode != 0 || gObj[aIndex].IsFakeOnline != 0)
	{
		return;
	}

	if (gObj[aIndex].Connected < OBJECT_ONLINE)
	{
		return;
	}
	if (gObj[aIndex].BHackWaitRecv > 0)
	{
		return;
	}

	//=Set Time Wait
	gObj[aIndex].BHackWaitRecv = GetTickCount();

	BYTE send[8192];

	BGUARD_REQ_CHECK pRequest;

	pRequest.header.set(0xD3, 0xAA, 0);

	int size = sizeof(pRequest);

	LPOBJ lpUser = &gObj[aIndex];

	pRequest.Level = lpUser->Level;
	pRequest.LevelPoint = lpUser->LevelUpPoint;
	pRequest.Strength = lpUser->Strength + lpUser->AddStrength;
	pRequest.Dexterity = lpUser->Dexterity + lpUser->AddDexterity;
	pRequest.Vitality = lpUser->Vitality + lpUser->AddVitality;
	pRequest.Energy = lpUser->Energy + lpUser->AddEnergy;
	pRequest.Leadership = lpUser->Leadership + lpUser->AddLeadership;
	pRequest.AttackSpeed = lpUser->PhysiSpeed;
	pRequest.MagicSpeed = lpUser->MagicSpeed;

	pRequest.CharSetItem[0] = (lpUser->Inventory[0].IsItem()) ? lpUser->Inventory[0].m_Index : 0;   //Tay Trai
	pRequest.CharSetItem[1] = (lpUser->Inventory[1].IsItem()) ? lpUser->Inventory[1].m_Index : 0;   //Tay Phai

	pRequest.CharSetItem[2] = (lpUser->Inventory[2].IsItem()) ? lpUser->Inventory[2].m_Index : 0;   //Mu
	pRequest.CharSetItem[3] = (lpUser->Inventory[3].IsItem()) ? lpUser->Inventory[3].m_Index : 0;   //Ao
	pRequest.CharSetItem[4] = (lpUser->Inventory[4].IsItem()) ? lpUser->Inventory[4].m_Index : 0;   //Quan
	pRequest.CharSetItem[5] = (lpUser->Inventory[5].IsItem()) ? lpUser->Inventory[5].m_Index : 0;   //Tay
	pRequest.CharSetItem[6] = (lpUser->Inventory[6].IsItem()) ? lpUser->Inventory[6].m_Index : 0;   //Chan

	pRequest.CharSetItem[7] = (lpUser->Inventory[7].IsItem()) ? lpUser->Inventory[7].m_Index : 0;   //Canh

	pRequest.CharSetItem[8] = (lpUser->Inventory[8].IsItem()) ? lpUser->Inventory[8].m_Index : 0;   //Slot Pet

	pRequest.header.size[0] = SET_NUMBERHB(size);
	pRequest.header.size[1] = SET_NUMBERLB(size);
	// ---
	memcpy(send, &pRequest, sizeof(pRequest));

	DataSend(aIndex, send, size);

	return;
}

void CBAntihack::GetResultPlayerEditor(BGUARD_ANS_CHECK* pResult, int aIndex)
{
	//LogAdd(LOG_RED, "Debug Send BProtect GetCheckResult 2");

	if (!this->HackPlayerEditor->Enabled || gObj[aIndex].Type != OBJECT_USER || gObj[aIndex].m_OfflineMode != 0 || gObj[aIndex].IsFakeOnline != 0)
	{
		return;
	}

	if (gObj[aIndex].CloseType != -1) {

		return;
	}
	LPOBJ lpUser = &gObj[aIndex];


	char* MemberType[] = { "Level", "LevelPoint", "Strength", "Dexterity", "Vitality", "Energy", "Leadership", "AttackSpeed", "MagicSpeed", "FrameValue", "Animation", "PetSlot"
		, "HelmSlot", "ArmorSlot", "PantsSlot", "GlovesSlot", "BootsSlot", "WeaponFirstSlot", "WeaponSecondSlot", "WingsSlot", "HackEditMain" };

	//=Clear Time Wait
	gObj[aIndex].BHackWaitRecv = 0;

	bool Disconnect = false;
	int OriginalValue = 0;
	int IsStatusHack = 0;
	for (int i = 0; i < emMaxCheckVars; i++)
	{
		if (!pResult->Data[i].Status)
		{
			IsStatusHack++;
			switch (i)
			{
			case emLevel: {
							  OriginalValue = lpUser->Level;

			}
				break;
			case emLevelPoint: {
								   OriginalValue = lpUser->LevelUpPoint;
			}
				break;
			case emStrength: {
								 OriginalValue = lpUser->Strength;
			}
				break;
			case emDexterity: {
								  OriginalValue = lpUser->Dexterity;
			}
				break;
			case emVitality: {
								 OriginalValue = lpUser->Vitality;
			}
				break;
			case emEnergy: {
							   OriginalValue = lpUser->Energy;
			}
				break;
			case emLeadership: {
								   OriginalValue = lpUser->Leadership;
			}
				break;
			case emAttackSpeed: {
									OriginalValue = lpUser->PhysiSpeed;
			}
				break;
			case emMagicSpeed: {
								   OriginalValue = lpUser->MagicSpeed;
			}
				break;

			case emPetSlot: {
								OriginalValue = lpUser->Inventory[8].m_Index;
			}
				break;
			case emHelmSlot: {
								 OriginalValue = lpUser->Inventory[2].m_Index;
			}
				break;
			case emArmorSlot: {
								  OriginalValue = lpUser->Inventory[3].m_Index;
			}
				break;
			case emPantsSlot: {
								  OriginalValue = lpUser->Inventory[4].m_Index;
			}
				break;
			case emGlovesSlot: {
								   OriginalValue = lpUser->Inventory[5].m_Index;
			}
				break;
			case emBootsSlot: {
								  OriginalValue = lpUser->Inventory[6].m_Index;
			}
				break;

			case emWeaponFirstSlot: {	 //Trai
										OriginalValue = lpUser->Inventory[0].m_Index;
			}
				break;

			case emWeaponSecondSlot: {	  //Phai
										 OriginalValue = lpUser->Inventory[1].m_Index;
			}
				break;

			case emWingsSlot: {	  //Canh
								  OriginalValue = lpUser->Inventory[7].m_Index;

			}
				break;

			case emEditGame:
			{
							   OriginalValue = 0;
							   if (pResult->Data[i].Value == 2)
							   {
								   return;
							   }
			}
				break;
			}

			//==Fix MiniWing
			if (OriginalValue >= 6274 && OriginalValue <= 6279) break;

			gObj[aIndex].BHackDetectCount[eHackPlayerEditor]++;
			if (gObj[aIndex].BHackDetectCount[eHackPlayerEditor] >= this->HackPlayerEditor->DetectCount && this->HackPlayerEditor->DetectCount >0)
			{
				char Mes[256];

				if (this->HackPlayerEditor->NoticeMess != -1)
				{
					gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, this->GetMessage(this->HackPlayerEditor->NoticeMess));
				}
				if (this->GhiLogHack)
				{
					gLog.Output(LOG_HACK, "[HackPlayerEditor][%s][%s] [%s] Ori: %d | Edit: %d", gObj[aIndex].Account, gObj[aIndex].Name, MemberType[i], OriginalValue, pResult->Data[i].Value);
				}
				if (this->HackPlayerEditor->TypeCheck == 1 && gObj[aIndex].BHackBlockSkillTime < GetTickCount())
				{
					gObj[aIndex].BHackBlockSkillTime = GetTickCount() + (this->HackPlayerEditor->BlockSkillDelay * 1000);
				}
			}

		}
	}
	if (this->HackPlayerEditor->DebugLog != 0)
	{
		gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[HackPlayerEditor][%d] Status Hack (%d)", gObj[aIndex].BHackDetectCount[eHackPlayerEditor], IsStatusHack);
	}
}
BOOL CBAntihack::CheckAttackBlock(int aIndex)   //Kiem Tra Block Khi Attack
{
	if (gObj[aIndex].Type != OBJECT_USER || gObj[aIndex].m_OfflineMode != 0 || gObj[aIndex].IsFakeOnline != 0)
	{
		return 1;
	}

	LPOBJ lpObj = &gObj[aIndex];

	if (gObj[aIndex].CloseType != -1 || gObj[aIndex].BProtectBlockAttack)
	{

		return 0;
	}

	if (gEffectManager.CheckStunEffect(lpObj) != 0)
	{
		return 0;
	}

	if ((GetTickCount() - gObj[aIndex].BHackWaitRecv) > 3000 && gObj[aIndex].BHackWaitRecv > 0)
	{
		//LogAdd(LOG_RED, "[%s][%s] Mat Ket Noi Antihack", gObj[aIndex].Account, gObj[aIndex].Name);
		return 0;
	}
	if (gObj[aIndex].BHackBlockSkillTime > GetTickCount())
	{
		char Mes[256];
		float TimeBlock = (gObj[aIndex].BHackBlockSkillTime - GetTickCount()) / 1000;
		wsprintf(Mes, "[System] %s", this->GetMessageA(0));
		gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, Mes, (int)TimeBlock + 1);
		return 0;
	}
	return 1;
}
void CBAntihack::BPModuleDataSend(int Index)
{
	if (!this->HackCheckInject->Enabled)
	{
		return;
	}

	if (gObjIsConnected(Index) == false)
	{
		return;
	}
	if (gObj[Index].BHackWaitRecv > 0)
	{
		return;
	}
	//=Set Time Wait
	gObj[Index].BHackWaitRecv = GetTickCount();

	BYTE send[4096];

	PMSG_MODULE_DATA_SEND pMsg;

	pMsg.header.set(0xD3, 0xAC, 0);

	int size = sizeof(pMsg);

	pMsg.count = 0;


	for (int i = 0; i < this->m_HackCheckInjectDB.size(); i++)
	{
		if (size + sizeof(this->m_HackCheckInjectDB[i]) > 4096)
		{
			break;
		}
		//LogAdd(LOG_BLUE, "Send Moudule %s %d", this->m_HackCheckInjectDB[i].NameModule, pMsg.count);
		memcpy(&send[size], &this->m_HackCheckInjectDB[i], sizeof(this->m_HackCheckInjectDB[i]));
		size += sizeof(this->m_HackCheckInjectDB[i]);
		pMsg.count++;

	}

	pMsg.header.size[0] = SET_NUMBERHB(size);
	pMsg.header.size[1] = SET_NUMBERLB(size);
	// ---
	memcpy(send, &pMsg, sizeof(pMsg));

	DataSend(Index, send, size);
}

void CBAntihack::RecvClientModule(RECV_MODULE* pResult, int aIndex)
{
	if (gObj[aIndex].Connected < OBJECT_ONLINE)
	{
		return;
	}
	if (gObj[aIndex].Type != OBJECT_USER || gObj[aIndex].m_OfflineMode != 0 || gObj[aIndex].IsFakeOnline != 0 || !this->HackCheckInject->Enabled)
	{
		return;
	}
	//=Clear Time Wait
	gObj[aIndex].BHackWaitRecv = 0;

	if (pResult->TypeRecv == 1)
	{
		LogAdd(LOG_RED, "[HackCheckInject]Acc [%s] Char [%s] TypeLog: %s ", gObj[aIndex].Account, gObj[aIndex].Name, pResult->LogRecv);
		if (this->GhiLogHack)
		{
			gLog.Output(LOG_HACK, "[HackCheckInject]Acc [%s] Char [%s] Module Inject [%s] ", gObj[aIndex].Account, gObj[aIndex].Name, pResult->LogRecv);
		}
		if (this->HackCheckInject->NoticeMess > 0)
		{
			gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, this->GetMessage(this->HackCheckInject->NoticeMess));
		}
		gObj[aIndex].BProtectBlockAttack = 1;

		if (this->HackCheckInject->TypeCheck == 1)
		{
			gObj[aIndex].BHackBlockSkillTime = GetTickCount() + (this->HackCheckInject->BlockSkillDelay * 1000);
		}
		//LogAdd(LOG_RED, "RECV_MODULE %d [%s]", pResult->TypeRecv, pResult->LogRecv);
	}

}

BOOL CBAntihack::BAntihackPacketRecv(BYTE head, BYTE* recvlpMsg, int size, int aIndex, int encrypt, int serial)
{
	LPOBJ lpObj = &gObj[aIndex];
	WORD bIndex = 0xFFFF;
	int skill = 0;

	if (lpObj->Type != OBJECT_USER)
	{
		return true;
	}
	switch (head)
	{
	case PROTOCOL_CODE2:
	{
						   PMSG_ATTACK_RECV* lpMsg = (PMSG_ATTACK_RECV*)recvlpMsg;
						   bIndex = MAKE_NUMBERW(lpMsg->index[0], lpMsg->index[1]);

						   //if (!this->CheckFameSpeedUseSkill(0, aIndex, skill))
						   //{
						   //	return false;
						   //}

						   if (!this->bpSpeedHackCheck(aIndex, bIndex, 0, skill))
						   {
							   return false;
						   }
	}
		break;
	case 0x4A:
	{
				 PMSG_RAGE_FIGHTER_SKILL_ATTACK_RECV* lpMsg = (PMSG_RAGE_FIGHTER_SKILL_ATTACK_RECV*)recvlpMsg;
				 skill = MAKE_NUMBERW(lpMsg->skill[0], lpMsg->skill[1]);
				 bIndex = MAKE_NUMBERW(lpMsg->index[0], lpMsg->index[1]);
				 //if (!this->CheckFameSpeedUseSkill(1, aIndex, skill))
				 //{
				 //	return false;
				 //}

				 if (!this->bpSpeedHackCheck(aIndex, bIndex, 1, skill))
				 {
					 return false;
				 }
	}
		break;
	case 0x4B:
	{
				 PMSG_SKILL_DARK_SIDE_RECV* lpMsg = (PMSG_SKILL_DARK_SIDE_RECV*)recvlpMsg;
				 skill = MAKE_NUMBERW(lpMsg->skill[0], lpMsg->skill[1]);
				 bIndex = MAKE_NUMBERW(lpMsg->index[0], lpMsg->index[1]);
				 //if (!this->CheckFameSpeedUseSkill(2, aIndex, skill))
				 //{
				 //	return false;
				 //}

				 if (!this->bpSpeedHackCheck(aIndex, bIndex, 2, skill))
				 {
					 return false;
				 }
	}
		break;
	case 0x19:
	{
				 PMSG_SKILL_ATTACK_RECV* lpMsg = (PMSG_SKILL_ATTACK_RECV*)recvlpMsg;
				 skill = MAKE_NUMBERW(lpMsg->skill[0], lpMsg->skill[1]);
				 bIndex = MAKE_NUMBERW(lpMsg->index[0], lpMsg->index[1]);
				 //LogAdd(LOG_BLACK, "SKill Send %d", skill);
				 //if (!this->CheckFameSpeedUseSkill(3, aIndex, skill))
				 //{
				 //	return false;
				 //}

				 if (!this->bpSpeedHackCheck(aIndex, bIndex, 3, skill))
				 {
					 return false;
				 }
	}
		break;
	case 0x1E:
	{

				 PMSG_DURATION_SKILL_ATTACK_RECV* lpMsg = (PMSG_DURATION_SKILL_ATTACK_RECV*)recvlpMsg;
				 skill = MAKE_NUMBERW(lpMsg->skill[0], lpMsg->skill[1]);
				 bIndex = MAKE_NUMBERW(lpMsg->index[0], lpMsg->index[1]);
				 //if (!this->CheckFameSpeedUseSkill(5, aIndex, skill))
				 //{
				 //	return false;
				 //}

				 if (!this->bpSpeedHackCheck(aIndex, bIndex, 5, skill))
				 {
					 return false;
				 }
	}
		break;
	case 0xD3:
		switch (((recvlpMsg[0] == 0xC1) ? recvlpMsg[3] : recvlpMsg[4]))
		{
		case 0xAA:		gBAntihack.GetResultPlayerEditor((BGUARD_ANS_CHECK*)recvlpMsg, aIndex);	break;
		case 0xAB:		gBAntihack.RecvClientModule((RECV_MODULE*)recvlpMsg, aIndex);			break;
		case 0xAC:
		{
					 USESKILL_LOG* lpMsg = (USESKILL_LOG*)recvlpMsg;
					 lpObj->UseSkillTime = GetTickCount();
					 lpObj->UseFameSpeed = lpMsg->FameSpeed;
					 lpObj->UseSkillSkillId = lpMsg->SkillID;
					 return false;
		}
			break;
		}
		break;
		//==Fix Spam Trade
	case 0x36:
	{

				 PMSG_TRADE_REQUEST_RECV* lpMsg = (PMSG_TRADE_REQUEST_RECV*)recvlpMsg;
				 bIndex = MAKE_NUMBERW(lpMsg->index[0], lpMsg->index[1]);
				 if (bIndex == lpObj->BTargetIndex[1] && (GetTickCount() - lpObj->BTargetTime[1]) < 1000)
				 {
					 gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[SpamCheck]Vui long thao tac cham lai!");
					 lpObj->BTargetTime[1] = GetTickCount();
					 return false;
				 }
				 else
				 {
					 lpObj->BTargetIndex[1] = bIndex;
					 lpObj->BTargetTime[1] = GetTickCount();
				 }

	}
		break;
		//==Fix Spam Party
	case 0x40:
	{

				 PMSG_PARTY_REQUEST_RECV* lpMsg = (PMSG_PARTY_REQUEST_RECV*)recvlpMsg;
				 bIndex = MAKE_NUMBERW(lpMsg->index[0], lpMsg->index[1]);
				 if (bIndex == lpObj->BTargetIndex[0] && (GetTickCount() - lpObj->BTargetTime[0]) < 1000)
				 {
					 gNotice.GCNoticeSend(aIndex, 1, 0, 0, 0, 0, 0, "[SpamCheck]Vui long thao tac cham lai!");
					 lpObj->BTargetTime[0] = GetTickCount();
					 return false;
				 }
				 else
				 {
					 lpObj->BTargetIndex[0] = bIndex;
					 lpObj->BTargetTime[0] = GetTickCount();
				 }

	}
		break;
	}
	return true;
}


//ChongDupeBangMove
//------------------------------------------------
bool  CBAntihack::CheckUserMove(LPOBJ lpObj)
{
	if (
		/*Check Interface May Chao*/
		lpObj->Interface.type == INTERFACE_CHAOS_BOX
		/*Check Interface Trade*/
		|| lpObj->Interface.type == INTERFACE_TRADE
		/*Check Interface Thung Do*/
		|| lpObj->Interface.type == INTERFACE_WAREHOUSE
		/*Check Interface SHOP*/
		|| lpObj->Interface.type == INTERFACE_PERSONAL_SHOP
		/*Check Interface XSHOP*/
		|| lpObj->Interface.type == INTERFACE_CASH_SHOP
		/*Check Interface Nguoi choi khi hien cua so bat ky thuoc gs quan ly*/
		|| lpObj->Interface.use != 0
		/*Check trong tinh trang chet*/
		|| lpObj->DieRegen != 0
		//LAM HET MOT LUOT => TY ONG TIM CAI CUA SO PET THEM VAO NHE
		/*Check trong tinh trang di chuyen(map nay sang map khac)*/
		|| lpObj->Teleport != 0
		/*Check trong tinh trang mo cua hang ca nhan*/
		|| lpObj->PShopOpen != 0
		/*Check trong tinh dang quay do*/
		|| lpObj->ChaosLock != 0
		/*Check tinh trang di chuyen bang trieu hoi dl*/
		|| lpObj->SkillSummonPartyTime != 0
		)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, "Vui long dong tat ca cua so");
		return 0;
	}
	else
	{
		return 1;
	}

}

//------------------------------------------------