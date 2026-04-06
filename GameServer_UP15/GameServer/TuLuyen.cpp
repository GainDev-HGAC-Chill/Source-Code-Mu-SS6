#include "StdAfx.h"
#include "user.h"
#include "TuLuyen.h"
#include "DSProtocol.h"
#include "GameMain.h"
#include "Path.h"
#include "MemScript.h"
#include "Util.h"
#include "CashShop.h"
#include "Message.h"
#include "Notice.h"
#include "CustomRankUser.h"
#include "ObjectManager.h"
#include "Log.h"
#if(TULUYEN_NEW == 1)

TuLuyen gTuLuyen;
// -------------------------------------------------------------------------------
TuLuyen::TuLuyen() // OK
{

}
// -------------------------------------------------------------------------------
TuLuyen::~TuLuyen() // OK
{
}
// -------------------------------------------------------------------------------
void TuLuyen::TU_LUYEN_OPTION(LPOBJ lpObj, bool flag)
{
	if (flag != 0)
	{
		return;
	}

	if (lpObj->rTuLuyen == 0)
	{

	}

	if (lpObj->rTuLuyen == 1)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_01;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_01;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_01;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_01;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_01;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_01;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_01;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_01;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_01;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_01;
	}
	//-----
	if (lpObj->rTuLuyen == 2)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_02;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_02;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_02;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_02;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_02;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_02;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_02;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_02;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_02;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_02;
	}
	//-----
	if (lpObj->rTuLuyen == 3)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_03;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_03;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_03;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_03;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_03;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_03;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_03;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_03;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_03;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_03;
	}
	//-----
	if (lpObj->rTuLuyen == 4)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_04;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_04;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_04;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_04;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_04;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_04;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_04;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_04;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_04;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_04;
	}
	//-----
	if (lpObj->rTuLuyen == 5)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_05;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_05;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_05;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_05;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_05;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_05;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_05;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_05;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_05;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_05;
	}
	//-----
	if (lpObj->rTuLuyen == 6)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_06;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_06;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_06;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_06;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_06;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_06;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_06;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_06;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_06;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_06;
	}
	//-----
	if (lpObj->rTuLuyen == 7)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_07;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_07;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_07;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_07;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_07;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_07;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_07;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_07;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_07;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_07;
	}
	//-----
	if (lpObj->rTuLuyen == 8)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_08;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_08;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_08;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_08;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_08;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_08;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_08;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_08;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_08;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_08;
	}
	//-----
	if (lpObj->rTuLuyen == 9)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_09;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_09;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_09;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_09;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_09;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_09;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_09;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_09;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_09;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_09;
	}
	if (lpObj->rTuLuyen == 10)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_10;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_10;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_10;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_10;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_10;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_10;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_10;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_10;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_10;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_10;
	}
	//-----
	if (lpObj->rTuLuyen == 11)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_11;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_11;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_11;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_11;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_11;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_11;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_11;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_11;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_11;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_11;
	}
	//-----
	if (lpObj->rTuLuyen == 12)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_12;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_12;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_12;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_12;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_12;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_12;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_12;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_12;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_12;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_12;
	}
	//-----
	if (lpObj->rTuLuyen == 13)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_13;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_13;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_13;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_13;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_13;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_13;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_13;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_13;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_13;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_13;
	}
	//-----
	if (lpObj->rTuLuyen == 14)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_14;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_14;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_14;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_14;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_14;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_14;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_14;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_14;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_14;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_14;
	}
	//-----
	if (lpObj->rTuLuyen == 15)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_15;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_15;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_15;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_15;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_15;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_15;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_15;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_15;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_15;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_15;
	}
	//-----
	if (lpObj->rTuLuyen == 16)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_16;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_16;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_16;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_16;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_16;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_16;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_16;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_16;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_16;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_16;
	}
	if (lpObj->rTuLuyen == 17)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_17;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_17;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_17;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_17;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_17;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_17;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_17;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_17;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_17;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_17;
	}
	if (lpObj->rTuLuyen == 18)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_18;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_18;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_18;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_18;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_18;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_18;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_18;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_18;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_18;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_18;
	}
	if (lpObj->rTuLuyen == 19)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_19;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_19;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_19;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_19;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_19;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_19;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_19;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_19;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_19;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_19;
	}
	if (lpObj->rTuLuyen == 20)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_20;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_20;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_20;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_20;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_20;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_20;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_20;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_20;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_20;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_20;
	}
	if (lpObj->rTuLuyen == 21)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_21;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_21;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_21;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_21;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_21;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_21;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_21;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_21;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_21;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_21;
	}
	if (lpObj->rTuLuyen == 22)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_22;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_22;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_22;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_22;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_22;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_22;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_22;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_22;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_22;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_22;
	}
	if (lpObj->rTuLuyen == 23)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_23;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_23;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_23;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_23;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_23;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_23;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_23;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_23;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_23;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_23;
	}
	if (lpObj->rTuLuyen == 24)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_24;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_24;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_24;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_24;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_24;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_24;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_24;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_24;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_24;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_24;
	}
	if (lpObj->rTuLuyen == 25)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_25;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_25;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_25;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_25;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_25;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_25;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_25;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_25;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_25;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_25;
	}
	if (lpObj->rTuLuyen == 26)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_26;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_26;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_26;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_26;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_26;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_26;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_26;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_26;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_26;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_26;
	}
	if (lpObj->rTuLuyen == 27)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_27;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_27;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_27;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_27;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_27;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_27;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_27;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_27;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_27;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_27;
	}
	if (lpObj->rTuLuyen == 28)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_28;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_28;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_28;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_28;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_28;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_28;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_28;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_28;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_28;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_28;
	}
	if (lpObj->rTuLuyen == 29)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_29;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_29;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_29;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_29;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_29;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_29;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_29;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_29;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_29;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_29;
	}
	if (lpObj->rTuLuyen == 30)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_30;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_30;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_30;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_30;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_30;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_30;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_30;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_30;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_30;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_30;
	}
	if (lpObj->rTuLuyen == 31)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_31;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_31;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_31;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_31;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_31;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_31;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_31;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_31;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_31;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_31;
	}
	if (lpObj->rTuLuyen == 32)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_32;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_32;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_32;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_32;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_32;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_32;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_32;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_32;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_32;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_32;
	}
	if (lpObj->rTuLuyen == 33)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_33;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_33;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_33;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_33;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_33;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_33;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_33;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_33;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_33;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_33;
	}
	if (lpObj->rTuLuyen == 34)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_34;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_34;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_34;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_34;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_34;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_34;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_34;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_34;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_34;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_34;
	}
	if (lpObj->rTuLuyen == 35)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_35;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_35;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_35;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_35;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_35;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_35;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_35;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_35;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_35;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_35;
	}
	if (lpObj->rTuLuyen == 36)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_36;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_36;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_36;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_36;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_36;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_36;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_36;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_36;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_36;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_36;
	}
	if (lpObj->rTuLuyen == 37)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_37;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_37;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_37;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_37;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_37;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_37;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_37;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_37;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_37;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_37;
	}
	if (lpObj->rTuLuyen == 38)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_38;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_38;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_38;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_38;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_38;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_38;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_38;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_38;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_38;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_38;
	}
	if (lpObj->rTuLuyen == 39)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_39;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_39;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_39;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_39;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_39;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_39;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_39;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_39;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_39;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_39;
	}
	if (lpObj->rTuLuyen == 40)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_40;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_40;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_40;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_40;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_40;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_40;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_40;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_40;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_40;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_40;
	}


	if (lpObj->rTuLuyen == 41)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_41;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_41;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_41;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_41;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_41;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_41;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_41;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_41;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_41;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_41;
	}
	//-----
	if (lpObj->rTuLuyen == 42)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_42;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_42;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_42;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_42;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_42;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_42;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_42;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_42;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_42;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_42;
	}
	//-----
	if (lpObj->rTuLuyen == 43)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_43;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_43;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_43;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_43;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_43;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_43;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_43;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_43;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_43;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_43;
	}
	//-----
	if (lpObj->rTuLuyen == 44)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_44;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_44;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_44;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_44;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_44;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_44;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_44;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_44;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_44;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_44;
	}
	//-----
	if (lpObj->rTuLuyen == 45)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_45;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_45;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_45;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_45;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_45;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_45;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_45;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_45;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_45;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_45;
	}
	//-----
	if (lpObj->rTuLuyen == 46)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_46;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_46;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_46;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_46;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_46;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_46;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_46;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_46;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_46;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_46;
	}
	//-----
	if (lpObj->rTuLuyen == 47)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_47;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_47;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_47;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_47;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_47;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_47;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_47;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_47;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_47;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_47;
	}
	//-----
	if (lpObj->rTuLuyen == 48)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_48;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_48;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_48;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_48;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_48;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_48;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_48;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_48;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_48;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_48;
	}
	//-----
	if (lpObj->rTuLuyen == 49)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_49;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_49;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_49;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_49;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_49;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_49;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_49;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_49;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_49;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_49;
	}
	if (lpObj->rTuLuyen == 50)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_50;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_50;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_50;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_50;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_50;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_50;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_50;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_50;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_50;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_50;
	}
	//-----
	if (lpObj->rTuLuyen == 51)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_51;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_51;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_51;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_51;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_51;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_51;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_51;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_51;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_51;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_51;
	}
	//-----
	if (lpObj->rTuLuyen == 52)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_52;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_52;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_52;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_52;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_52;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_52;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_52;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_52;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_52;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_52;
	}
	//-----
	if (lpObj->rTuLuyen == 53)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_53;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_53;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_53;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_53;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_53;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_53;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_53;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_53;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_53;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_53;
	}
	//-----
	if (lpObj->rTuLuyen == 54)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_54;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_54;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_54;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_54;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_54;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_54;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_54;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_54;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_54;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_54;
	}
	//-----
	if (lpObj->rTuLuyen == 55)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_55;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_55;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_55;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_55;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_55;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_55;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_55;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_55;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_55;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_55;
	}
	//-----
	if (lpObj->rTuLuyen == 56)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_56;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_56;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_56;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_56;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_56;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_56;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_56;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_56;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_56;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_56;
	}
	if (lpObj->rTuLuyen == 57)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_57;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_57;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_57;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_57;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_57;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_57;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_57;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_57;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_57;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_57;
	}
	if (lpObj->rTuLuyen == 58)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_58;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_58;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_58;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_58;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_58;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_58;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_58;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_58;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_58;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_58;
	}
	if (lpObj->rTuLuyen == 59)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_59;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_59;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_59;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_59;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_59;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_59;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_59;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_59;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_59;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_59;
	}
	if (lpObj->rTuLuyen == 60)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_60;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_60;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_60;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_60;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_60;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_60;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_60;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_60;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_60;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_60;
	}
	if (lpObj->rTuLuyen == 61)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_61;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_61;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_61;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_61;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_61;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_61;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_61;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_61;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_61;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_61;
	}
	if (lpObj->rTuLuyen == 62)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_62;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_62;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_62;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_62;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_62;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_62;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_62;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_62;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_62;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_62;
	}
	if (lpObj->rTuLuyen == 63)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_63;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_63;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_63;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_63;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_63;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_63;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_63;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_63;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_63;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_63;
	}
	if (lpObj->rTuLuyen == 64)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_64;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_64;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_64;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_64;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_64;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_64;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_64;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_64;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_64;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_64;
	}
	if (lpObj->rTuLuyen == 65)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_65;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_65;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_65;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_65;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_65;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_65;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_65;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_65;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_65;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_65;
	}
	if (lpObj->rTuLuyen == 66)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_66;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_66;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_66;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_66;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_66;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_66;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_66;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_66;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_66;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_66;
	}
	if (lpObj->rTuLuyen == 67)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_67;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_67;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_67;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_67;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_67;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_67;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_67;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_67;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_67;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_67;
	}
	if (lpObj->rTuLuyen == 68)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_68;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_68;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_68;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_68;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_68;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_68;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_68;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_68;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_68;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_68;
	}
	if (lpObj->rTuLuyen == 69)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_69;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_69;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_69;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_69;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_69;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_69;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_69;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_69;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_69;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_69;
	}
	if (lpObj->rTuLuyen == 70)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_70;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_70;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_70;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_70;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_70;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_70;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_70;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_70;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_70;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_70;
	}
	if (lpObj->rTuLuyen == 71)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_71;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_71;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_71;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_71;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_71;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_71;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_71;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_71;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_71;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_71;
	}
	if (lpObj->rTuLuyen == 72)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_72;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_72;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_72;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_72;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_72;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_72;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_72;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_72;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_72;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_72;
	}
	if (lpObj->rTuLuyen == 73)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_73;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_73;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_73;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_73;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_73;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_73;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_73;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_73;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_73;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_73;
	}
	if (lpObj->rTuLuyen == 74)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_74;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_74;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_74;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_74;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_74;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_74;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_74;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_74;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_74;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_74;
	}
	if (lpObj->rTuLuyen == 75)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_75;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_75;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_75;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_75;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_75;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_75;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_75;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_75;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_75;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_75;
	}
	if (lpObj->rTuLuyen == 76)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_76;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_76;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_76;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_76;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_76;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_76;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_76;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_76;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_76;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_76;
	}
	if (lpObj->rTuLuyen == 77)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_77;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_77;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_77;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_77;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_77;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_77;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_77;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_77;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_77;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_77;
	}
	if (lpObj->rTuLuyen == 78)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_78;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_78;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_78;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_78;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_78;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_78;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_78;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_78;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_78;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_78;
	}
	if (lpObj->rTuLuyen == 79)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_79;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_79;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_79;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_79;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_79;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_79;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_79;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_79;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_79;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_79;
	}
	if (lpObj->rTuLuyen == 80)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->TU_LUYEN_SAT_THUONG_80;
		lpObj->MagicDamageMax += this->TU_LUYEN_SAT_THUONG_80;
		lpObj->PhysiDamageMinLeft += this->TU_LUYEN_SAT_THUONG_80;
		lpObj->PhysiDamageMinRight += this->TU_LUYEN_SAT_THUONG_80;
		lpObj->PhysiDamageMaxLeft += this->TU_LUYEN_SAT_THUONG_80;
		lpObj->PhysiDamageMaxRight += this->TU_LUYEN_SAT_THUONG_80;
		// x3 Sát Thương
		lpObj->TripleDamageRate += this->TU_LUYEN_SAT_THUONGX3_80;
		// Sát Thương Hoàn Hảo
		lpObj->ExcellentDamageRate += this->TU_LUYEN_HOAN_HAO_80;
		// THỂ LỰC
		lpObj->AddLife += this->TU_LUYEN_THE_LUC_80;
		// SD
		lpObj->AddShield += this->TU_LUYEN_SD_80;
	}
}
// -------------------------------------------------------------------------------

void TuLuyen::Load()
{
	this->TU_LUYEN_WCOINC[1] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_01", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[2] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_02", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[3] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_03", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[4] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_04", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[5] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_05", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[6] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_06", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[7] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_07", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[8] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_08", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[9] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_09", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[10] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_10", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[11] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_11", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[12] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_12", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[13] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_13", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[14] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_14", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[15] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_15", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[16] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_16", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[17] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_17", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[18] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_18", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[19] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_19", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[20] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_20", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[21] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_21", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[22] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_22", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[23] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_23", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[24] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_24", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[25] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_25", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[26] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_26", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[27] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_27", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[28] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_28", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[29] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_29", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[30] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_30", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[31] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_31", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[32] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_32", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[33] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_33", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[34] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_34", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[35] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_35", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[36] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_36", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[37] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_37", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[38] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_38", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[39] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_39", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[40] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_40", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[41] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_41", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[42] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_42", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[43] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_43", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[44] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_44", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[45] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_45", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[46] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_46", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[47] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_47", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[48] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_48", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[49] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_49", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[50] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_50", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[51] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_51", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[52] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_52", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[53] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_53", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[54] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_54", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[55] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_55", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[56] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_56", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[57] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_57", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[58] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_58", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[59] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_59", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[60] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_60", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[61] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_61", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[62] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_62", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[63] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_63", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[64] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_64", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[65] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_65", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[66] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_66", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[67] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_67", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[68] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_68", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[69] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_69", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[70] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_70", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[71] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_71", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[72] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_72", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[73] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_73", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[74] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_74", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[75] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_75", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[76] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_76", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[77] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_77", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[78] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_78", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[79] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_79", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_WCOINC[80] = GetPrivateProfileInt("CONFIG", "TU_LUYEN_WCOINC_80", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));

	this->TU_LUYEN_SAT_THUONG_01 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_01", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_02 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_02", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_03 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_03", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_04 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_04", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_05 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_05", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_06 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_06", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_07 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_07", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_08 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_08", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_09 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_09", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_10 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_10", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_11 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_11", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_12 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_12", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_13 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_13", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_14 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_14", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_15 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_15", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_16 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_16", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_17 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_17", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_18 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_18", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_19 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_19", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_20 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_20", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_21 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_21", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_22 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_22", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_23 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_23", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_24 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_24", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_25 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_25", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_26 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_26", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_27 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_27", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_28 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_28", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_29 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_29", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_30 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_30", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_31 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_31", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_32 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_32", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_33 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_33", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_34 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_34", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_35 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_35", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_36 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_36", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_37 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_37", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_38 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_38", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_39 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_39", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_40 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_40", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));

	this->TU_LUYEN_SAT_THUONG_41 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_41", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_42 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_42", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_43 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_43", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_44 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_44", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_45 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_45", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_46 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_46", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_47 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_47", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_48 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_48", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_49 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_49", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_50 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_50", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_51 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_51", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_52 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_52", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_53 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_53", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_54 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_54", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_55 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_55", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_56 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_56", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_57 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_57", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_58 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_58", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_59 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_59", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_60 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_60", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_61 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_61", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_62 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_62", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_63 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_63", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_64 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_64", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_65 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_65", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_66 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_66", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_67 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_67", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_68 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_68", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_69 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_69", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_70 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_70", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_71 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_71", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_72 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_72", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_73 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_73", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_74 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_74", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_75 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_75", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_76 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_76", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_77 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_77", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_78 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_78", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_79 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_79", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONG_80 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONG_80", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));

	this->TU_LUYEN_SAT_THUONGX3_01 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_01", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_02 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_02", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_03 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_03", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_04 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_04", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_05 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_05", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_06 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_06", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_07 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_07", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_08 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_08", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_09 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_09", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_10 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_10", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_11 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_11", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_12 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_12", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_13 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_13", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_14 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_14", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_15 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_15", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_16 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_16", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_17 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_17", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_18 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_18", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_19 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_19", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_20 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_20", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_21 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_21", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_22 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_22", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_23 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_23", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_24 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_24", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_25 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_25", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_26 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_26", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_27 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_27", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_28 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_28", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_29 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_29", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_30 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_30", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_31 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_31", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_32 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_32", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_33 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_33", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_34 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_34", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_35 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_35", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_36 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_36", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_37 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_37", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_38 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_38", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_39 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_39", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_40 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_40", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));

	this->TU_LUYEN_SAT_THUONGX3_41 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_41", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_42 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_42", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_43 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_43", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_44 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_44", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_45 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_45", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_46 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_46", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_47 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_47", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_48 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_48", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_49 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_49", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_50 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_50", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_51 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_51", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_52 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_52", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_53 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_53", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_54 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_54", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_55 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_55", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_56 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_56", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_57 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_57", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_58 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_58", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_59 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_59", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_60 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_60", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_61 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_61", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_62 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_62", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_63 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_63", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_64 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_64", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_65 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_65", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_66 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_66", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_67 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_67", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_68 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_68", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_69 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_69", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_70 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_70", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_71 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_71", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_72 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_72", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_73 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_73", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_74 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_74", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_75 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_75", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_76 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_76", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_77 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_77", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_78 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_78", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_79 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_79", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SAT_THUONGX3_80 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SAT_THUONGX3_80", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));

	this->TU_LUYEN_HOAN_HAO_01 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_01", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_02 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_02", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_03 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_03", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_04 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_04", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_05 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_05", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_06 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_06", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_07 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_07", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_08 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_08", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_09 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_09", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_10 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_10", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_11 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_11", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_12 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_12", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_13 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_13", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_14 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_14", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_15 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_15", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_16 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_16", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_17 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_17", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_18 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_18", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_19 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_19", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_20 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_20", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_21 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_21", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_22 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_22", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_23 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_23", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_24 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_24", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_25 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_25", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_26 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_26", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_27 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_27", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_28 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_28", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_29 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_29", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_30 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_30", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_31 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_31", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_32 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_32", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_33 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_33", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_34 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_34", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_35 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_35", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_36 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_36", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_37 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_37", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_38 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_38", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_39 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_39", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_40 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_40", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));

	this->TU_LUYEN_HOAN_HAO_41 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_41", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_42 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_42", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_43 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_43", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_44 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_44", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_45 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_45", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_46 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_46", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_47 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_47", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_48 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_48", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_49 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_49", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_50 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_50", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_51 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_51", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_52 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_52", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_53 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_53", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_54 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_54", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_55 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_55", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_56 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_56", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_57 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_57", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_58 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_58", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_59 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_59", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_60 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_60", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_61 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_61", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_62 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_62", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_63 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_63", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_64 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_64", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_65 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_65", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_66 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_66", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_67 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_67", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_68 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_68", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_69 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_69", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_70 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_70", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_71 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_71", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_72 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_72", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_73 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_73", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_74 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_74", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_75 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_75", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_76 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_76", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_77 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_77", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_78 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_78", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_79 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_79", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_HOAN_HAO_80 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_HOAN_HAO_80", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));



	this->TU_LUYEN_THE_LUC_01 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_01", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_02 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_02", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_03 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_03", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_04 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_04", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_05 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_05", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_06 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_06", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_07 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_07", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_08 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_08", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_09 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_09", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_10 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_10", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_11 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_11", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_12 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_12", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_13 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_13", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_14 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_14", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_15 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_15", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_16 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_16", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_17 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_17", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_18 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_18", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_19 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_19", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_20 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_20", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_21 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_21", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_22 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_22", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_23 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_23", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_24 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_24", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_25 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_25", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_26 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_26", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_27 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_27", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_28 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_28", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_29 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_29", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_30 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_30", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_31 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_31", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_32 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_32", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_33 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_33", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_34 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_34", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_35 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_35", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_36 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_36", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_37 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_37", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_38 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_38", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_39 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_39", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_40 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_40", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));

	this->TU_LUYEN_THE_LUC_41 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_41", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_42 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_42", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_43 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_43", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_44 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_44", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_45 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_45", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_46 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_46", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_47 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_47", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_48 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_48", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_49 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_49", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_50 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_50", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_51 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_51", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_52 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_52", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_53 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_53", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_54 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_54", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_55 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_55", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_56 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_56", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_57 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_57", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_58 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_58", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_59 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_59", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_60 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_60", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_61 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_61", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_62 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_62", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_63 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_63", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_64 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_64", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_65 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_65", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_66 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_66", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_67 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_67", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_68 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_68", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_69 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_69", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_70 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_70", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_71 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_71", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_72 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_72", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_73 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_73", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_74 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_74", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_75 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_75", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_76 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_76", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_77 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_77", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_78 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_78", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_79 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_79", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_THE_LUC_80 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_THE_LUC_80", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));


	this->TU_LUYEN_SD_01 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_01", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_02 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_02", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_03 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_03", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_04 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_04", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_05 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_05", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_06 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_06", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_07 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_07", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_08 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_08", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_09 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_09", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_10 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_10", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_11 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_11", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_12 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_12", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_13 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_13", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_14 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_14", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_15 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_15", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_16 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_16", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_17 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_17", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_18 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_18", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_19 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_19", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_20 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_20", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_21 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_21", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_22 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_22", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_23 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_23", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_24 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_24", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_25 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_25", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_26 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_26", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_27 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_27", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_28 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_28", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_29 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_29", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_30 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_30", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_31 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_31", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_32 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_32", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_33 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_33", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_34 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_34", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_35 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_35", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_36 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_36", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_37 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_37", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_38 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_38", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_39 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_39", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_40 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_40", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));


	this->TU_LUYEN_SD_41 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_41", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_42 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_42", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_43 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_43", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_44 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_44", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_45 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_45", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_46 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_46", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_47 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_47", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_48 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_48", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_49 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_49", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_50 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_50", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_51 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_51", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_52 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_52", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_53 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_53", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_54 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_54", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_55 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_55", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_56 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_56", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_57 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_57", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_58 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_58", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_59 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_59", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_60 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_60", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_61 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_61", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_62 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_62", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_63 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_63", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_64 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_64", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_65 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_65", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_66 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_66", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_67 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_67", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_68 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_68", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_69 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_69", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_70 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_70", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_71 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_71", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_72 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_72", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_73 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_73", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_74 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_74", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_75 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_75", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_76 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_76", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_77 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_77", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_78 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_78", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_79 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_79", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));
	this->TU_LUYEN_SD_80 = GetPrivateProfileInt("CONFIG", "TU_LUYEN_SD_80", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomTuLuyen.ini"));


}
// -------------------------------------------------------------------------------
void TuLuyen::BUY_TU_LUYEN(LPOBJ lpObj, BUY_TU_LUYEN_REQ *aRecv)
{

#if(CHECK_USER == 1)
	if (lpObj->Interface.type == INTERFACE_CHAOS_BOX
		|| lpObj->Interface.type == INTERFACE_TRADE
		|| lpObj->Interface.type == INTERFACE_PARTY
		|| lpObj->Interface.type == INTERFACE_WAREHOUSE
		|| lpObj->Interface.type == INTERFACE_PERSONAL_SHOP
		|| lpObj->Interface.type == INTERFACE_CASH_SHOP
		|| lpObj->Interface.type == INTERFACE_TRAINER
		|| lpObj->Interface.use != 0
		|| lpObj->State == OBJECT_DELCMD
		|| lpObj->DieRegen != 0
		|| lpObj->Teleport != 0
		|| lpObj->PShopOpen != 0
		|| lpObj->ChaosLock != 0
		|| lpObj->SkillSummonPartyTime != 0)
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(659));
		return;
	}
	//// Delay Khi Click
	//if ((GetTickCount() - lpObj->ClickClientSend) < 1000)
	//{
	//	gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(42));
	//	return;
	//}
#endif
	//---------------------------------------------------------
	if (lpObj->rTuLuyen < aRecv->Number)
	{
		if (lpObj->rTuLuyen > 79)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(878));
			return;
		}

		if (lpObj->Coin1 < this->TU_LUYEN_WCOINC[aRecv->Number])
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(879), this->TU_LUYEN_WCOINC[aRecv->Number]);
			return;
		}
		GDSetCoinSend(lpObj->Index, -(this->TU_LUYEN_WCOINC[aRecv->Number]), 0, 0, "Tu Luyện");
		//gCashShop.CGCashShopPointRecv(lpObj->Index);
		lpObj->rTuLuyen += 1; // Thay Đổi
		//gNotice.GCNoticeSend(lpObj->Index, 0, 0, 0, 0, 0, 0, gMessage.GetMessage(880), lpObj->rTuLuyen);
		gNotice.GCNoticeSend(lpObj->Index, 0, 0, 0, 0, 0, 0, gMessage.GetMessage(880), lpObj->Name, lpObj->rTuLuyen);

		gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
		//GDCharacterInfoSaveSend(lpObj->Index);
		gObjectManager.CharacterCalcAttribute(lpObj->Index);
	}
	//---------------------------------------------------------

	gLog.Output(LOG_TU_LUYEN, "[Tu Luyện] Nhân Vật [%s] Đã Nâng Cấp [Tu Luyện] Lên [Cấp %d]", lpObj->Name, lpObj->rTuLuyen);

	TuLuyenDataSend(lpObj->Index);
	//Set Delay
	lpObj->ClickClientSend = GetTickCount();


}

struct TULUYEN_UPDATE
{
	PBMSG_HEAD3 h;
	int TU_LUYEN_WCOINC;
	//4-04-2022
	int TU_LUYEN;
};

void TuLuyenDataSend(int aIndex)
{
	TULUYEN_UPDATE rSend;
	LPOBJ lpObj = &gObj[aIndex];
	rSend.h.set((LPBYTE)&rSend, 0xF3, 100, sizeof(rSend));

	rSend.TU_LUYEN_WCOINC = gTuLuyen.TU_LUYEN_WCOINC[lpObj->rTuLuyen + 1];

	//4-04-2022
	rSend.TU_LUYEN = lpObj->rTuLuyen;
	DataSend(aIndex, (LPBYTE)&rSend, sizeof(rSend));
}


#endif
