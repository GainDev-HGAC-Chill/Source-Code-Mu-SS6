#include "StdAfx.h"
#include "user.h"
#include "DanhHieu.h"
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

#if(DANHHIEU_NEW)

DanhHieu gDanhHieu;
// -------------------------------------------------------------------------------
DanhHieu::DanhHieu() // OK
{

}
// -------------------------------------------------------------------------------
DanhHieu::~DanhHieu() // OK
{
}
// -------------------------------------------------------------------------------
void DanhHieu::DANH_HIEU_OPTION(LPOBJ lpObj, bool flag)
{
	if (flag != 0)
	{
		return;
	}

	if (lpObj->rDanhHieu == 0)
	{

	}

	if (lpObj->rDanhHieu == 1)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_01;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_01;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_01;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_01;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_01;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_01;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_01;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_01;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_01;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_01;
	}
	//-----
	if (lpObj->rDanhHieu == 2)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_02;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_02;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_02;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_02;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_02;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_02;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_02;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_02;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_02;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_02;
	}
	//-----
	if (lpObj->rDanhHieu == 3)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_03;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_03;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_03;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_03;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_03;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_03;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_03;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_03;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_03;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_03;
	}
	//-----
	if (lpObj->rDanhHieu == 4)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_04;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_04;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_04;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_04;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_04;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_04;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_04;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_04;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_04;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_04;
	}
	//-----
	if (lpObj->rDanhHieu == 5)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_05;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_05;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_05;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_05;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_05;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_05;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_05;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_05;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_05;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_05;
	}
	//-----
	if (lpObj->rDanhHieu == 6)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_06;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_06;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_06;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_06;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_06;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_06;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_06;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_06;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_06;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_06;
	}
	//-----
	if (lpObj->rDanhHieu == 7)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_07;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_07;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_07;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_07;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_07;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_07;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_07;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_07;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_07;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_07;
	}
	//-----
	if (lpObj->rDanhHieu == 8)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_08;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_08;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_08;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_08;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_08;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_08;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_08;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_08;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_08;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_08;
	}
	//-----
	if (lpObj->rDanhHieu == 9)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_09;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_09;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_09;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_09;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_09;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_09;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_09;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_09;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_09;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_09;
	}
	if (lpObj->rDanhHieu == 10)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_10;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_10;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_10;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_10;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_10;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_10;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_10;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_10;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_10;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_10;
	}
	//-----
	if (lpObj->rDanhHieu == 11)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_11;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_11;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_11;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_11;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_11;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_11;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_11;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_11;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_11;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_11;
	}
	//-----
	if (lpObj->rDanhHieu == 12)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_12;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_12;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_12;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_12;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_12;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_12;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_12;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_12;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_12;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_12;
	}
	//-----
	if (lpObj->rDanhHieu == 13)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_13;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_13;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_13;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_13;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_13;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_13;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_13;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_13;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_13;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_13;
	}
	//-----
	if (lpObj->rDanhHieu == 14)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_14;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_14;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_14;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_14;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_14;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_14;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_14;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_14;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_14;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_14;
	}
	//-----
	if (lpObj->rDanhHieu == 15)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_15;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_15;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_15;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_15;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_15;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_15;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_15;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_15;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_15;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_15;
	}
	//-----
	if (lpObj->rDanhHieu == 16)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_16;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_16;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_16;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_16;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_16;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_16;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_16;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_16;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_16;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_16;
	}
	if (lpObj->rDanhHieu == 17)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_17;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_17;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_17;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_17;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_17;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_17;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_17;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_17;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_17;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_17;
	}
	if (lpObj->rDanhHieu == 18)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_18;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_18;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_18;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_18;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_18;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_18;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_18;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_18;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_18;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_18;
	}
	if (lpObj->rDanhHieu == 19)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_19;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_19;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_19;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_19;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_19;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_19;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_19;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_19;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_19;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_19;
	}
	if (lpObj->rDanhHieu == 20)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_20;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_20;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_20;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_20;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_20;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_20;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_20;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_20;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_20;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_20;
	}
	if (lpObj->rDanhHieu == 21)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_21;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_21;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_21;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_21;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_21;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_21;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_21;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_21;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_21;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_21;
	}
	if (lpObj->rDanhHieu == 22)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_22;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_22;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_22;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_22;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_22;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_22;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_22;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_22;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_22;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_22;
	}
	if (lpObj->rDanhHieu == 23)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_23;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_23;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_23;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_23;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_23;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_23;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_23;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_23;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_23;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_23;
	}
	if (lpObj->rDanhHieu == 24)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_24;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_24;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_24;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_24;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_24;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_24;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_24;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_24;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_24;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_24;
	}
	if (lpObj->rDanhHieu == 25)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_25;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_25;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_25;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_25;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_25;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_25;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_25;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_25;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_25;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_25;
	}
	if (lpObj->rDanhHieu == 26)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_26;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_26;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_26;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_26;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_26;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_26;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_26;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_26;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_26;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_26;
	}
	if (lpObj->rDanhHieu == 27)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_27;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_27;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_27;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_27;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_27;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_27;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_27;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_27;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_27;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_27;
	}
	if (lpObj->rDanhHieu == 28)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_28;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_28;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_28;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_28;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_28;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_28;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_28;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_28;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_28;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_28;
	}

	if (lpObj->rDanhHieu == 29)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_29;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_29;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_29;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_29;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_29;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_29;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_29;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_29;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_29;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_29;
	}


	if (lpObj->rDanhHieu == 30)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_30;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_30;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_30;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_30;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_30;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_30;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_30;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_30;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_30;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_30;
	}

	if (lpObj->rDanhHieu == 31)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_31;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_31;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_31;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_31;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_31;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_31;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_31;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_31;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_31;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_31;
	}
	//-----
	if (lpObj->rDanhHieu == 32)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_32;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_32;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_32;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_32;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_32;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_32;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_32;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_32;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_32;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_32;
	}
	//-----
	if (lpObj->rDanhHieu == 33)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_33;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_33;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_33;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_33;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_33;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_33;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_33;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_33;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_33;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_33;
	}
	//-----
	if (lpObj->rDanhHieu == 34)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_34;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_34;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_34;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_34;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_34;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_34;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_34;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_34;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_34;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_34;
	}
	//-----
	if (lpObj->rDanhHieu == 35)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_35;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_35;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_35;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_35;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_35;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_35;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_35;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_35;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_35;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_35;
	}
	//-----
	if (lpObj->rDanhHieu == 36)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_36;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_36;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_36;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_36;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_36;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_36;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_36;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_36;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_36;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_36;
	}
	if (lpObj->rDanhHieu == 37)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_37;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_37;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_37;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_37;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_37;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_37;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_37;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_37;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_37;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_37;
	}
	if (lpObj->rDanhHieu == 38)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_38;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_38;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_38;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_38;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_38;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_38;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_38;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_38;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_38;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_38;
	}
	if (lpObj->rDanhHieu == 39)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_39;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_39;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_39;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_39;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_39;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_39;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_39;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_39;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_39;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_39;
	}
	if (lpObj->rDanhHieu == 40)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_40;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_40;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_40;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_40;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_40;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_40;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_40;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_40;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_40;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_40;
	}
	if (lpObj->rDanhHieu == 41)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_41;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_41;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_41;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_41;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_41;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_41;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_41;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_41;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_41;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_41;
	}
	if (lpObj->rDanhHieu == 42)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_42;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_42;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_42;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_42;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_42;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_42;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_42;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_42;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_42;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_42;
	}
	if (lpObj->rDanhHieu == 43)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_43;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_43;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_43;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_43;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_43;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_43;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_43;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_43;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_43;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_43;
	}
	if (lpObj->rDanhHieu == 44)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_44;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_44;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_44;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_44;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_44;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_44;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_44;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_44;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_44;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_44;
	}
	if (lpObj->rDanhHieu == 45)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_45;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_45;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_45;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_45;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_45;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_45;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_45;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_45;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_45;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_45;
	}
	if (lpObj->rDanhHieu == 46)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_46;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_46;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_46;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_46;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_46;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_46;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_46;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_46;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_46;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_46;
	}
	if (lpObj->rDanhHieu == 47)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_47;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_47;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_47;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_47;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_47;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_47;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_47;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_47;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_47;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_47;
	}
	if (lpObj->rDanhHieu == 48)
	{
		// Sát Thương	
		lpObj->MagicDamageMin += this->DANH_HIEU_SAT_THUONG_48;
		lpObj->MagicDamageMax += this->DANH_HIEU_SAT_THUONG_48;
		lpObj->PhysiDamageMinLeft += this->DANH_HIEU_SAT_THUONG_48;
		lpObj->PhysiDamageMinRight += this->DANH_HIEU_SAT_THUONG_48;
		lpObj->PhysiDamageMaxLeft += this->DANH_HIEU_SAT_THUONG_48;
		lpObj->PhysiDamageMaxRight += this->DANH_HIEU_SAT_THUONG_48;
		// x2 Sát Thương
		lpObj->DoubleDamageRate += this->DANH_HIEU_SAT_THUONGX2_48;
		// Phòng Thủ
		lpObj->Defense += this->DANH_HIEU_PHONG_THU_48;
		// THỂ LỰC
		lpObj->AddLife += this->DANH_HIEU_THE_LUC_48;
		// SD
		lpObj->AddShield += this->DANH_HIEU_SD_48;
	}




}
// -------------------------------------------------------------------------------
void DanhHieu::Load()
{
	this->DANH_HIEU_WCOINC[1] = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_01", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC[2] = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_02", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC[3] = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_03", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC[4] = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_04", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC[5] = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_05", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC[6] = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_06", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC[7] = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_07", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC[8] = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_08", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC[9] = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_09", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC[10] = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_10", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC[11] = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_11", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC[12] = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_12", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC[13] = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_13", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC[14] = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_14", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC[15] = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_15", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC[16] = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_16", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC[17] = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_17", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC[18] = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_18", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC[19] = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_19", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC[20] = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_20", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC[21] = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_21", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC[22] = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_22", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC[23] = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_23", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC[24] = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_24", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC[25] = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_25", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC[26] = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_26", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC[27] = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_27", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC[28] = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_28", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC[29] = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_29", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC[30] = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_30", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC[31] = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_31", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC[32] = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_32", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC[33] = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_33", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC[34] = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_34", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC[35] = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_35", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC[36] = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_36", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC[37] = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_37", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC[38] = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_38", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC[39] = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_39", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC[40] = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_40", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC[41] = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_41", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC[42] = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_42", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC[43] = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_43", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC[44] = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_44", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC[45] = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_45", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC[46] = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_46", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC[47] = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_47", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_WCOINC[48] = GetPrivateProfileInt("CONFIG", "DANH_HIEU_WCOINC_48", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));







	this->DANH_HIEU_SAT_THUONG_01 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_01", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_02 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_02", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_03 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_03", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_04 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_04", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_05 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_05", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_06 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_06", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_07 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_07", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_08 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_08", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_09 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_09", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_10 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_10", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_11 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_11", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_12 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_12", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_13 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_13", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_14 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_14", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_15 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_15", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_16 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_16", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_17 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_17", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_18 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_18", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_19 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_19", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_20 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_20", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_21 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_21", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_22 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_22", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_23 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_23", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_24 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_24", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_25 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_25", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_26 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_26", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_27 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_27", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_28 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_28", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));

	this->DANH_HIEU_SAT_THUONG_29 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_29", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_30 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_30", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_31 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_31", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_32 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_32", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_33 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_33", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_34 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_34", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_35 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_35", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_36 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_36", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_37 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_37", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_38 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_38", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_39 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_39", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_40 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_40", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_41 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_41", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_42 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_42", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_43 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_43", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_44 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_44", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_45 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_45", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_46 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_46", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_47 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_47", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONG_48 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONG_48", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));




	this->DANH_HIEU_SAT_THUONGX2_01 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_01", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_02 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_02", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_03 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_03", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_04 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_04", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_05 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_05", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_06 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_06", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_07 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_07", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_08 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_08", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_09 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_09", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_10 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_10", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_11 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_11", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_12 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_12", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_13 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_13", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_14 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_14", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_15 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_15", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_16 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_16", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_17 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_17", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_18 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_18", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_19 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_19", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_20 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_20", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_21 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_21", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_22 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_22", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_23 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_23", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_24 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_24", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_25 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_25", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_26 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_26", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_27 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_27", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_28 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_28", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));

	this->DANH_HIEU_SAT_THUONGX2_29 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_29", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_30 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_30", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_31 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_31", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_32 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_32", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_33 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_33", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_34 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_34", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_35 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_35", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_36 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_36", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_37 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_37", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_38 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_38", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_39 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_39", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_40 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_40", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_41 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_41", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_42 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_42", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_43 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_43", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_44 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_44", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_45 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_45", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_46 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_46", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_47 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_47", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SAT_THUONGX2_48 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SAT_THUONGX2_48", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));



	this->DANH_HIEU_PHONG_THU_01 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_01", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_02 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_02", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_03 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_03", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_04 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_04", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_05 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_05", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_06 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_06", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_07 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_07", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_08 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_08", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_09 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_09", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_10 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_10", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_11 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_11", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_12 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_12", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_13 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_13", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_14 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_14", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_15 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_15", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_16 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_16", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_17 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_17", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_18 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_18", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_19 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_19", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_20 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_20", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_21 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_21", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_22 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_22", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_23 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_23", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_24 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_24", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_25 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_25", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_26 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_26", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_27 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_27", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_28 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_28", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));


	this->DANH_HIEU_PHONG_THU_29 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_29", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_30 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_30", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_31 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_31", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_32 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_32", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_33 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_33", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_34 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_34", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_35 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_35", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_36 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_36", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_37 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_37", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_38 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_38", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_39 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_39", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_40 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_40", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_41 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_41", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_42 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_42", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_43 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_43", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_44 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_44", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_45 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_45", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_46 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_46", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_47 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_47", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_PHONG_THU_48 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_PHONG_THU_48", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));



	this->DANH_HIEU_THE_LUC_01 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_01", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_02 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_02", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_03 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_03", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_04 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_04", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_05 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_05", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_06 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_06", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_07 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_07", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_08 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_08", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_09 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_09", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_10 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_10", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_11 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_11", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_12 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_12", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_13 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_13", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_14 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_14", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_15 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_15", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_16 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_16", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_17 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_17", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_18 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_18", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_19 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_19", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_20 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_20", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_21 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_21", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_22 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_22", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_23 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_23", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_24 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_24", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_25 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_25", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_26 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_26", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_27 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_27", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_28 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_28", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));

	this->DANH_HIEU_THE_LUC_29 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_29", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_30 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_30", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_31 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_31", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_32 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_32", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_33 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_33", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_34 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_34", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_35 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_35", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_36 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_36", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_37 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_37", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_38 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_38", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_39 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_39", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_40 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_40", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_41 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_41", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_42 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_42", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_43 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_43", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_44 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_44", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_45 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_45", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_46 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_46", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_47 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_47", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_THE_LUC_48 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_THE_LUC_48", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));

	this->DANH_HIEU_SD_01 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_01", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_02 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_02", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_03 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_03", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_04 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_04", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_05 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_05", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_06 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_06", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_07 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_07", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_08 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_08", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_09 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_09", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_10 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_10", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_11 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_11", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_12 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_12", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_13 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_13", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_14 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_14", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_15 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_15", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_16 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_16", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_17 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_17", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_18 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_18", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_19 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_19", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_20 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_20", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_21 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_21", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_22 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_22", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_23 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_23", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_24 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_24", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_25 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_25", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_26 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_26", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_27 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_27", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_28 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_28", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));

	this->DANH_HIEU_SD_29 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_29", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_30 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_30", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_31 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_31", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_32 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_32", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_33 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_33", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_34 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_34", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_35 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_35", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_36 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_36", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_37 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_37", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_38 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_38", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_39 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_39", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_40 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_40", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_41 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_41", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_42 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_42", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_43 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_43", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_44 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_44", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_45 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_45", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_46 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_46", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_47 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_47", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));
	this->DANH_HIEU_SD_48 = GetPrivateProfileInt("CONFIG", "DANH_HIEU_SD_48", 0, gPath.GetFullPath("Custom\\DevHieuDaiCa\\CustomRanking\\CustomDanhHieu.ini"));



}
// -------------------------------------------------------------------------------
void DanhHieu::BUY_DANH_HIEU(LPOBJ lpObj, BUY_DANH_HIEU_REQ *aRecv)
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
	if (lpObj->rDanhHieu < aRecv->Number)
	{
		if (lpObj->rDanhHieu > 47)
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(884));
			return;
		}

		if (lpObj->Coin1 < this->DANH_HIEU_WCOINC[aRecv->Number])
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(885), this->DANH_HIEU_WCOINC[aRecv->Number]);
			return;
		}
		GDSetCoinSend(lpObj->Index, -(this->DANH_HIEU_WCOINC[aRecv->Number]), 0, 0, "Danh Hiệu");
		//gCashShop.CGCashShopPointRecv(lpObj->Index);
		lpObj->rDanhHieu += 1; // Thay Đổi
		//gNotice.GCNoticeSend(lpObj->Index, 0, 0, 0, 0, 0, 0, gMessage.GetMessage(886), lpObj->rDanhHieu);
		gNotice.GCNoticeSend(lpObj->Index, 0, 0, 0, 0, 0, 0, gMessage.GetMessage(886), lpObj->Name, lpObj->rDanhHieu);

		gCustomRankUser.GCReqRankLevelUser(lpObj->Index, lpObj->Index);
		//GDCharacterInfoSaveSend(lpObj->Index);
		gObjectManager.CharacterCalcAttribute(lpObj->Index);
	}
	//---------------------------------------------------------

	gLog.Output(LOG_DANH_HIEU, "[Danh Hiệu] Nhân Vật [%s] Đã Nâng Cấp [Danh Hiệu] Lên [Cấp %d]", lpObj->Name, lpObj->rDanhHieu);

	DanhHieuDataSend(lpObj->Index);
	//Set Delay
	lpObj->ClickClientSend = GetTickCount();
}

struct DANHHIEU_UPDATE
{
	PBMSG_HEAD3 h;
	int DANH_HIEU_WCOINC;
	int DANH_HIEU;
};

void DanhHieuDataSend(int aIndex)
{
	DANHHIEU_UPDATE rSend;
	LPOBJ lpObj = &gObj[aIndex];
	rSend.h.set((LPBYTE)&rSend, 0xF3, 15, sizeof(rSend));

	rSend.DANH_HIEU_WCOINC = gDanhHieu.DANH_HIEU_WCOINC[lpObj->rDanhHieu + 1];

	DataSend(aIndex, (LPBYTE)&rSend, sizeof(rSend));
}

#endif
