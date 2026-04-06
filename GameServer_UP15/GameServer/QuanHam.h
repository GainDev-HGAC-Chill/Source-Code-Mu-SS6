#include "user.h"
#include "Protocol.h"
#pragma once
#if(QUANHAM_NEW == 1)
// -------------------------------------------------------------------------------
struct BUY_QUAN_HAM_REQ
{
	PSBMSG_HEAD h;
	int			Number;
};
// -------------------------------------------------------------------------------

void QuanHamDataSend(int aIndex);

class QuanHam
{
public:
	// ----
	QuanHam();
	virtual ~QuanHam();
	// ----
	void		BUY_QUAN_HAM(LPOBJ lpObj, BUY_QUAN_HAM_REQ *aRecv);
	// ----
	void		QUAN_HAM_OPTION(LPOBJ lpObj, bool flag);
	// ----
	void	    Load();
	// ----

	int         QUAN_HAM_WCOINC[41];

	int         QUAN_HAM_SAT_THUONG_01;
	int         QUAN_HAM_SAT_THUONGX2_01;
	int         QUAN_HAM_PHONG_THU_01;
	int         QUAN_HAM_THE_LUC_01;
	int         QUAN_HAM_SD_01;

	int         QUAN_HAM_SAT_THUONG_02;
	int         QUAN_HAM_SAT_THUONGX2_02;
	int         QUAN_HAM_PHONG_THU_02;
	int         QUAN_HAM_THE_LUC_02;
	int         QUAN_HAM_SD_02;

	int         QUAN_HAM_SAT_THUONG_03;
	int         QUAN_HAM_SAT_THUONGX2_03;
	int         QUAN_HAM_PHONG_THU_03;
	int         QUAN_HAM_THE_LUC_03;
	int         QUAN_HAM_SD_03;

	int         QUAN_HAM_SAT_THUONG_04;
	int         QUAN_HAM_SAT_THUONGX2_04;
	int         QUAN_HAM_PHONG_THU_04;
	int         QUAN_HAM_THE_LUC_04;
	int         QUAN_HAM_SD_04;

	int         QUAN_HAM_SAT_THUONG_05;
	int         QUAN_HAM_SAT_THUONGX2_05;
	int         QUAN_HAM_PHONG_THU_05;
	int         QUAN_HAM_THE_LUC_05;
	int         QUAN_HAM_SD_05;

	int         QUAN_HAM_SAT_THUONG_06;
	int         QUAN_HAM_SAT_THUONGX2_06;
	int         QUAN_HAM_PHONG_THU_06;
	int         QUAN_HAM_THE_LUC_06;
	int         QUAN_HAM_SD_06;

	int         QUAN_HAM_SAT_THUONG_07;
	int         QUAN_HAM_SAT_THUONGX2_07;
	int         QUAN_HAM_PHONG_THU_07;
	int         QUAN_HAM_THE_LUC_07;
	int         QUAN_HAM_SD_07;

	int         QUAN_HAM_SAT_THUONG_08;
	int         QUAN_HAM_SAT_THUONGX2_08;
	int         QUAN_HAM_PHONG_THU_08;
	int         QUAN_HAM_THE_LUC_08;
	int         QUAN_HAM_SD_08;

	int         QUAN_HAM_SAT_THUONG_09;
	int         QUAN_HAM_SAT_THUONGX2_09;
	int         QUAN_HAM_PHONG_THU_09;
	int         QUAN_HAM_THE_LUC_09;
	int         QUAN_HAM_SD_09;

	int         QUAN_HAM_SAT_THUONG_10;
	int         QUAN_HAM_SAT_THUONGX2_10;
	int         QUAN_HAM_PHONG_THU_10;
	int         QUAN_HAM_THE_LUC_10;
	int         QUAN_HAM_SD_10;

	int         QUAN_HAM_SAT_THUONG_11;
	int         QUAN_HAM_SAT_THUONGX2_11;
	int         QUAN_HAM_PHONG_THU_11;
	int         QUAN_HAM_THE_LUC_11;
	int         QUAN_HAM_SD_11;

	int         QUAN_HAM_SAT_THUONG_12;
	int         QUAN_HAM_SAT_THUONGX2_12;
	int         QUAN_HAM_PHONG_THU_12;
	int         QUAN_HAM_THE_LUC_12;
	int         QUAN_HAM_SD_12;

	int         QUAN_HAM_SAT_THUONG_13;
	int         QUAN_HAM_SAT_THUONGX2_13;
	int         QUAN_HAM_PHONG_THU_13;
	int         QUAN_HAM_THE_LUC_13;
	int         QUAN_HAM_SD_13;

	int         QUAN_HAM_SAT_THUONG_14;
	int         QUAN_HAM_SAT_THUONGX2_14;
	int         QUAN_HAM_PHONG_THU_14;
	int         QUAN_HAM_THE_LUC_14;
	int         QUAN_HAM_SD_14;

	int         QUAN_HAM_SAT_THUONG_15;
	int         QUAN_HAM_SAT_THUONGX2_15;
	int         QUAN_HAM_PHONG_THU_15;
	int         QUAN_HAM_THE_LUC_15;
	int         QUAN_HAM_SD_15;

	int         QUAN_HAM_SAT_THUONG_16;
	int         QUAN_HAM_SAT_THUONGX2_16;
	int         QUAN_HAM_PHONG_THU_16;
	int         QUAN_HAM_THE_LUC_16;
	int         QUAN_HAM_SD_16;

	int         QUAN_HAM_SAT_THUONG_17;
	int         QUAN_HAM_SAT_THUONGX2_17;
	int         QUAN_HAM_PHONG_THU_17;
	int         QUAN_HAM_THE_LUC_17;
	int         QUAN_HAM_SD_17;

	int         QUAN_HAM_SAT_THUONG_18;
	int         QUAN_HAM_SAT_THUONGX2_18;
	int         QUAN_HAM_PHONG_THU_18;
	int         QUAN_HAM_THE_LUC_18;
	int         QUAN_HAM_SD_18;

	int         QUAN_HAM_SAT_THUONG_19;
	int         QUAN_HAM_SAT_THUONGX2_19;
	int         QUAN_HAM_PHONG_THU_19;
	int         QUAN_HAM_THE_LUC_19;
	int         QUAN_HAM_SD_19;

	int         QUAN_HAM_SAT_THUONG_20;
	int         QUAN_HAM_SAT_THUONGX2_20;
	int         QUAN_HAM_PHONG_THU_20;
	int         QUAN_HAM_THE_LUC_20;
	int         QUAN_HAM_SD_20;

	int         QUAN_HAM_SAT_THUONG_21;
	int         QUAN_HAM_SAT_THUONGX2_21;
	int         QUAN_HAM_PHONG_THU_21;
	int         QUAN_HAM_THE_LUC_21;
	int         QUAN_HAM_SD_21;

	int         QUAN_HAM_SAT_THUONG_22;
	int         QUAN_HAM_SAT_THUONGX2_22;
	int         QUAN_HAM_PHONG_THU_22;
	int         QUAN_HAM_THE_LUC_22;
	int         QUAN_HAM_SD_22;

	int         QUAN_HAM_SAT_THUONG_23;
	int         QUAN_HAM_SAT_THUONGX2_23;
	int         QUAN_HAM_PHONG_THU_23;
	int         QUAN_HAM_THE_LUC_23;
	int         QUAN_HAM_SD_23;

	int         QUAN_HAM_SAT_THUONG_24;
	int         QUAN_HAM_SAT_THUONGX2_24;
	int         QUAN_HAM_PHONG_THU_24;
	int         QUAN_HAM_THE_LUC_24;
	int         QUAN_HAM_SD_24;

	int         QUAN_HAM_SAT_THUONG_25;
	int         QUAN_HAM_SAT_THUONGX2_25;
	int         QUAN_HAM_PHONG_THU_25;
	int         QUAN_HAM_THE_LUC_25;
	int         QUAN_HAM_SD_25;

	int         QUAN_HAM_SAT_THUONG_26;
	int         QUAN_HAM_SAT_THUONGX2_26;
	int         QUAN_HAM_PHONG_THU_26;
	int         QUAN_HAM_THE_LUC_26;
	int         QUAN_HAM_SD_26;

	int         QUAN_HAM_SAT_THUONG_27;
	int         QUAN_HAM_SAT_THUONGX2_27;
	int         QUAN_HAM_PHONG_THU_27;
	int         QUAN_HAM_THE_LUC_27;
	int         QUAN_HAM_SD_27;

	int         QUAN_HAM_SAT_THUONG_28;
	int         QUAN_HAM_SAT_THUONGX2_28;
	int         QUAN_HAM_PHONG_THU_28;
	int         QUAN_HAM_THE_LUC_28;
	int         QUAN_HAM_SD_28;

	int         QUAN_HAM_SAT_THUONG_29;
	int         QUAN_HAM_SAT_THUONGX2_29;
	int         QUAN_HAM_PHONG_THU_29;
	int         QUAN_HAM_THE_LUC_29;
	int         QUAN_HAM_SD_29;

	int         QUAN_HAM_SAT_THUONG_30;
	int         QUAN_HAM_SAT_THUONGX2_30;
	int         QUAN_HAM_PHONG_THU_30;
	int         QUAN_HAM_THE_LUC_30;
	int         QUAN_HAM_SD_30;

	int         QUAN_HAM_SAT_THUONG_31;
	int         QUAN_HAM_SAT_THUONGX2_31;
	int         QUAN_HAM_PHONG_THU_31;
	int         QUAN_HAM_THE_LUC_31;
	int         QUAN_HAM_SD_31;

	int         QUAN_HAM_SAT_THUONG_32;
	int         QUAN_HAM_SAT_THUONGX2_32;
	int         QUAN_HAM_PHONG_THU_32;
	int         QUAN_HAM_THE_LUC_32;
	int         QUAN_HAM_SD_32;

	int         QUAN_HAM_SAT_THUONG_33;
	int         QUAN_HAM_SAT_THUONGX2_33;
	int         QUAN_HAM_PHONG_THU_33;
	int         QUAN_HAM_THE_LUC_33;
	int         QUAN_HAM_SD_33;

	int         QUAN_HAM_SAT_THUONG_34;
	int         QUAN_HAM_SAT_THUONGX2_34;
	int         QUAN_HAM_PHONG_THU_34;
	int         QUAN_HAM_THE_LUC_34;
	int         QUAN_HAM_SD_34;

	int         QUAN_HAM_SAT_THUONG_35;
	int         QUAN_HAM_SAT_THUONGX2_35;
	int         QUAN_HAM_PHONG_THU_35;
	int         QUAN_HAM_THE_LUC_35;
	int         QUAN_HAM_SD_35;

	int         QUAN_HAM_SAT_THUONG_36;
	int         QUAN_HAM_SAT_THUONGX2_36;
	int         QUAN_HAM_PHONG_THU_36;
	int         QUAN_HAM_THE_LUC_36;
	int         QUAN_HAM_SD_36;

	int         QUAN_HAM_SAT_THUONG_37;
	int         QUAN_HAM_SAT_THUONGX2_37;
	int         QUAN_HAM_PHONG_THU_37;
	int         QUAN_HAM_THE_LUC_37;
	int         QUAN_HAM_SD_37;

	int         QUAN_HAM_SAT_THUONG_38;
	int         QUAN_HAM_SAT_THUONGX2_38;
	int         QUAN_HAM_PHONG_THU_38;
	int         QUAN_HAM_THE_LUC_38;
	int         QUAN_HAM_SD_38;

	int         QUAN_HAM_SAT_THUONG_39;
	int         QUAN_HAM_SAT_THUONGX2_39;
	int         QUAN_HAM_PHONG_THU_39;
	int         QUAN_HAM_THE_LUC_39;
	int         QUAN_HAM_SD_39;

	int         QUAN_HAM_SAT_THUONG_40;
	int         QUAN_HAM_SAT_THUONGX2_40;
	int         QUAN_HAM_PHONG_THU_40;
	int         QUAN_HAM_THE_LUC_40;
	int         QUAN_HAM_SD_40;

	// ----
}; extern QuanHam gQuanHam;

#endif
// -------------------------------------------------------------------------------