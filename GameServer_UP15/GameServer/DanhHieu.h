#include "user.h"
#include "Protocol.h"
#pragma once
#if(DANHHIEU_NEW == 1)
// -------------------------------------------------------------------------------
struct BUY_DANH_HIEU_REQ
{
	PSBMSG_HEAD h;
	int			Number;
};
// -------------------------------------------------------------------------------

void DanhHieuDataSend(int aIndex);

class DanhHieu
{
public:
	// ----
	DanhHieu();
	virtual ~DanhHieu();
	// ----
	void		BUY_DANH_HIEU(LPOBJ lpObj, BUY_DANH_HIEU_REQ *aRecv);
	// ----
	void		DANH_HIEU_OPTION(LPOBJ lpObj, bool flag);
	// ----
	void	    Load();
	// ----
	int         DANH_HIEU_WCOINC[49];


	int         DANH_HIEU_SAT_THUONG_01;
	int         DANH_HIEU_SAT_THUONGX2_01;
	int         DANH_HIEU_PHONG_THU_01;
	int         DANH_HIEU_THE_LUC_01;
	int         DANH_HIEU_SD_01;




	int         DANH_HIEU_SAT_THUONG_02;
	int         DANH_HIEU_SAT_THUONGX2_02;
	int         DANH_HIEU_PHONG_THU_02;
	int         DANH_HIEU_THE_LUC_02;
	int         DANH_HIEU_SD_02;

	int         DANH_HIEU_SAT_THUONG_03;
	int         DANH_HIEU_SAT_THUONGX2_03;
	int         DANH_HIEU_PHONG_THU_03;
	int         DANH_HIEU_THE_LUC_03;
	int         DANH_HIEU_SD_03;

	int         DANH_HIEU_SAT_THUONG_04;
	int         DANH_HIEU_SAT_THUONGX2_04;
	int         DANH_HIEU_PHONG_THU_04;
	int         DANH_HIEU_THE_LUC_04;
	int         DANH_HIEU_SD_04;

	int         DANH_HIEU_SAT_THUONG_05;
	int         DANH_HIEU_SAT_THUONGX2_05;
	int         DANH_HIEU_PHONG_THU_05;
	int         DANH_HIEU_THE_LUC_05;
	int         DANH_HIEU_SD_05;

	int         DANH_HIEU_SAT_THUONG_06;
	int         DANH_HIEU_SAT_THUONGX2_06;
	int         DANH_HIEU_PHONG_THU_06;
	int         DANH_HIEU_THE_LUC_06;
	int         DANH_HIEU_SD_06;

	int         DANH_HIEU_SAT_THUONG_07;
	int         DANH_HIEU_SAT_THUONGX2_07;
	int         DANH_HIEU_PHONG_THU_07;
	int         DANH_HIEU_THE_LUC_07;
	int         DANH_HIEU_SD_07;

	int         DANH_HIEU_SAT_THUONG_08;
	int         DANH_HIEU_SAT_THUONGX2_08;
	int         DANH_HIEU_PHONG_THU_08;
	int         DANH_HIEU_THE_LUC_08;
	int         DANH_HIEU_SD_08;

	int         DANH_HIEU_SAT_THUONG_09;
	int         DANH_HIEU_SAT_THUONGX2_09;
	int         DANH_HIEU_PHONG_THU_09;
	int         DANH_HIEU_THE_LUC_09;
	int         DANH_HIEU_SD_09;

	int         DANH_HIEU_SAT_THUONG_10;
	int         DANH_HIEU_SAT_THUONGX2_10;
	int         DANH_HIEU_PHONG_THU_10;
	int         DANH_HIEU_THE_LUC_10;
	int         DANH_HIEU_SD_10;

	int         DANH_HIEU_SAT_THUONG_11;
	int         DANH_HIEU_SAT_THUONGX2_11;
	int         DANH_HIEU_PHONG_THU_11;
	int         DANH_HIEU_THE_LUC_11;
	int         DANH_HIEU_SD_11;

	int         DANH_HIEU_SAT_THUONG_12;
	int         DANH_HIEU_SAT_THUONGX2_12;
	int         DANH_HIEU_PHONG_THU_12;
	int         DANH_HIEU_THE_LUC_12;
	int         DANH_HIEU_SD_12;

	int         DANH_HIEU_SAT_THUONG_13;
	int         DANH_HIEU_SAT_THUONGX2_13;
	int         DANH_HIEU_PHONG_THU_13;
	int         DANH_HIEU_THE_LUC_13;
	int         DANH_HIEU_SD_13;

	int         DANH_HIEU_SAT_THUONG_14;
	int         DANH_HIEU_SAT_THUONGX2_14;
	int         DANH_HIEU_PHONG_THU_14;
	int         DANH_HIEU_THE_LUC_14;
	int         DANH_HIEU_SD_14;

	int         DANH_HIEU_SAT_THUONG_15;
	int         DANH_HIEU_SAT_THUONGX2_15;
	int         DANH_HIEU_PHONG_THU_15;
	int         DANH_HIEU_THE_LUC_15;
	int         DANH_HIEU_SD_15;

	int         DANH_HIEU_SAT_THUONG_16;
	int         DANH_HIEU_SAT_THUONGX2_16;
	int         DANH_HIEU_PHONG_THU_16;
	int         DANH_HIEU_THE_LUC_16;
	int         DANH_HIEU_SD_16;

	int         DANH_HIEU_SAT_THUONG_17;
	int         DANH_HIEU_SAT_THUONGX2_17;
	int         DANH_HIEU_PHONG_THU_17;
	int         DANH_HIEU_THE_LUC_17;
	int         DANH_HIEU_SD_17;

	int         DANH_HIEU_SAT_THUONG_18;
	int         DANH_HIEU_SAT_THUONGX2_18;
	int         DANH_HIEU_PHONG_THU_18;
	int         DANH_HIEU_THE_LUC_18;
	int         DANH_HIEU_SD_18;

	int         DANH_HIEU_SAT_THUONG_19;
	int         DANH_HIEU_SAT_THUONGX2_19;
	int         DANH_HIEU_PHONG_THU_19;
	int         DANH_HIEU_THE_LUC_19;
	int         DANH_HIEU_SD_19;

	int         DANH_HIEU_SAT_THUONG_20;
	int         DANH_HIEU_SAT_THUONGX2_20;
	int         DANH_HIEU_PHONG_THU_20;
	int         DANH_HIEU_THE_LUC_20;
	int         DANH_HIEU_SD_20;



	int         DANH_HIEU_SAT_THUONG_21;
	int         DANH_HIEU_SAT_THUONGX2_21;
	int         DANH_HIEU_PHONG_THU_21;
	int         DANH_HIEU_THE_LUC_21;
	int         DANH_HIEU_SD_21;

	int         DANH_HIEU_SAT_THUONG_22;
	int         DANH_HIEU_SAT_THUONGX2_22;
	int         DANH_HIEU_PHONG_THU_22;
	int         DANH_HIEU_THE_LUC_22;
	int         DANH_HIEU_SD_22;

	int         DANH_HIEU_SAT_THUONG_23;
	int         DANH_HIEU_SAT_THUONGX2_23;
	int         DANH_HIEU_PHONG_THU_23;
	int         DANH_HIEU_THE_LUC_23;
	int         DANH_HIEU_SD_23;

	int         DANH_HIEU_SAT_THUONG_24;
	int         DANH_HIEU_SAT_THUONGX2_24;
	int         DANH_HIEU_PHONG_THU_24;
	int         DANH_HIEU_THE_LUC_24;
	int         DANH_HIEU_SD_24;

	int         DANH_HIEU_SAT_THUONG_25;
	int         DANH_HIEU_SAT_THUONGX2_25;
	int         DANH_HIEU_PHONG_THU_25;
	int         DANH_HIEU_THE_LUC_25;
	int         DANH_HIEU_SD_25;

	int         DANH_HIEU_SAT_THUONG_26;
	int         DANH_HIEU_SAT_THUONGX2_26;
	int         DANH_HIEU_PHONG_THU_26;
	int         DANH_HIEU_THE_LUC_26;
	int         DANH_HIEU_SD_26;

	int         DANH_HIEU_SAT_THUONG_27;
	int         DANH_HIEU_SAT_THUONGX2_27;
	int         DANH_HIEU_PHONG_THU_27;
	int         DANH_HIEU_THE_LUC_27;
	int         DANH_HIEU_SD_27;

	int         DANH_HIEU_SAT_THUONG_28;
	int         DANH_HIEU_SAT_THUONGX2_28;
	int         DANH_HIEU_PHONG_THU_28;
	int         DANH_HIEU_THE_LUC_28;
	int         DANH_HIEU_SD_28;


	int         DANH_HIEU_SAT_THUONG_29;
	int         DANH_HIEU_SAT_THUONGX2_29;
	int         DANH_HIEU_PHONG_THU_29;
	int         DANH_HIEU_THE_LUC_29;
	int         DANH_HIEU_SD_29;

	int         DANH_HIEU_SAT_THUONG_30;
	int         DANH_HIEU_SAT_THUONGX2_30;
	int         DANH_HIEU_PHONG_THU_30;
	int         DANH_HIEU_THE_LUC_30;
	int         DANH_HIEU_SD_30;

	int         DANH_HIEU_SAT_THUONG_31;
	int         DANH_HIEU_SAT_THUONGX2_31;
	int         DANH_HIEU_PHONG_THU_31;
	int         DANH_HIEU_THE_LUC_31;
	int         DANH_HIEU_SD_31;

	int         DANH_HIEU_SAT_THUONG_32;
	int         DANH_HIEU_SAT_THUONGX2_32;
	int         DANH_HIEU_PHONG_THU_32;
	int         DANH_HIEU_THE_LUC_32;
	int         DANH_HIEU_SD_32;

	int         DANH_HIEU_SAT_THUONG_33;
	int         DANH_HIEU_SAT_THUONGX2_33;
	int         DANH_HIEU_PHONG_THU_33;
	int         DANH_HIEU_THE_LUC_33;
	int         DANH_HIEU_SD_33;

	int         DANH_HIEU_SAT_THUONG_34;
	int         DANH_HIEU_SAT_THUONGX2_34;
	int         DANH_HIEU_PHONG_THU_34;
	int         DANH_HIEU_THE_LUC_34;
	int         DANH_HIEU_SD_34;

	int         DANH_HIEU_SAT_THUONG_35;
	int         DANH_HIEU_SAT_THUONGX2_35;
	int         DANH_HIEU_PHONG_THU_35;
	int         DANH_HIEU_THE_LUC_35;
	int         DANH_HIEU_SD_35;


	int         DANH_HIEU_SAT_THUONG_36;
	int         DANH_HIEU_SAT_THUONGX2_36;
	int         DANH_HIEU_PHONG_THU_36;
	int         DANH_HIEU_THE_LUC_36;
	int         DANH_HIEU_SD_36;


	int         DANH_HIEU_SAT_THUONG_37;
	int         DANH_HIEU_SAT_THUONGX2_37;
	int         DANH_HIEU_PHONG_THU_37;
	int         DANH_HIEU_THE_LUC_37;
	int         DANH_HIEU_SD_37;

	int         DANH_HIEU_SAT_THUONG_38;
	int         DANH_HIEU_SAT_THUONGX2_38;
	int         DANH_HIEU_PHONG_THU_38;
	int         DANH_HIEU_THE_LUC_38;
	int         DANH_HIEU_SD_38;

	int         DANH_HIEU_SAT_THUONG_39;
	int         DANH_HIEU_SAT_THUONGX2_39;
	int         DANH_HIEU_PHONG_THU_39;
	int         DANH_HIEU_THE_LUC_39;
	int         DANH_HIEU_SD_39;

	int         DANH_HIEU_SAT_THUONG_40;
	int         DANH_HIEU_SAT_THUONGX2_40;
	int         DANH_HIEU_PHONG_THU_40;
	int         DANH_HIEU_THE_LUC_40;
	int         DANH_HIEU_SD_40;

	int         DANH_HIEU_SAT_THUONG_41;
	int         DANH_HIEU_SAT_THUONGX2_41;
	int         DANH_HIEU_PHONG_THU_41;
	int         DANH_HIEU_THE_LUC_41;
	int         DANH_HIEU_SD_41;

	int         DANH_HIEU_SAT_THUONG_42;
	int         DANH_HIEU_SAT_THUONGX2_42;
	int         DANH_HIEU_PHONG_THU_42;
	int         DANH_HIEU_THE_LUC_42;
	int         DANH_HIEU_SD_42;

	int         DANH_HIEU_SAT_THUONG_43;
	int         DANH_HIEU_SAT_THUONGX2_43;
	int         DANH_HIEU_PHONG_THU_43;
	int         DANH_HIEU_THE_LUC_43;
	int         DANH_HIEU_SD_43;

	int         DANH_HIEU_SAT_THUONG_44;
	int         DANH_HIEU_SAT_THUONGX2_44;
	int         DANH_HIEU_PHONG_THU_44;
	int         DANH_HIEU_THE_LUC_44;
	int         DANH_HIEU_SD_44;

	int         DANH_HIEU_SAT_THUONG_45;
	int         DANH_HIEU_SAT_THUONGX2_45;
	int         DANH_HIEU_PHONG_THU_45;
	int         DANH_HIEU_THE_LUC_45;
	int         DANH_HIEU_SD_45;

	int         DANH_HIEU_SAT_THUONG_46;
	int         DANH_HIEU_SAT_THUONGX2_46;
	int         DANH_HIEU_PHONG_THU_46;
	int         DANH_HIEU_THE_LUC_46;
	int         DANH_HIEU_SD_46;

	int         DANH_HIEU_SAT_THUONG_47;
	int         DANH_HIEU_SAT_THUONGX2_47;
	int         DANH_HIEU_PHONG_THU_47;
	int         DANH_HIEU_THE_LUC_47;
	int         DANH_HIEU_SD_47;

	int         DANH_HIEU_SAT_THUONG_48;
	int         DANH_HIEU_SAT_THUONGX2_48;
	int         DANH_HIEU_PHONG_THU_48;
	int         DANH_HIEU_THE_LUC_48;
	int         DANH_HIEU_SD_48;











	// ----
}; extern DanhHieu gDanhHieu;

#endif
// -------------------------------------------------------------------------------