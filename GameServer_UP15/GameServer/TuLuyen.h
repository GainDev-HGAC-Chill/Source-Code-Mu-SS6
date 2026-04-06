#include "user.h"
#include "Protocol.h"
#pragma once
#if(TULUYEN_NEW == 1)
// -------------------------------------------------------------------------------
struct BUY_TU_LUYEN_REQ
{
	PSBMSG_HEAD h;
	int			Number;
};
// -------------------------------------------------------------------------------

void TuLuyenDataSend(int aIndex);

class TuLuyen
{
public:
	// ----
	TuLuyen();
	virtual ~TuLuyen();
	// ----
	void		BUY_TU_LUYEN(LPOBJ lpObj, BUY_TU_LUYEN_REQ *aRecv);

	void		TU_LUYEN_OPTION(LPOBJ lpObj, bool flag);
	// ----
	void	    Load();
	// ----
	int        TU_LUYEN_WCOINC[81];


	int         TU_LUYEN_SAT_THUONG_01;
	int         TU_LUYEN_SAT_THUONGX3_01;
	int         TU_LUYEN_HOAN_HAO_01;
	int         TU_LUYEN_THE_LUC_01;
	int         TU_LUYEN_SD_01;

	int         TU_LUYEN_SAT_THUONG_02;
	int         TU_LUYEN_SAT_THUONGX3_02;
	int         TU_LUYEN_HOAN_HAO_02;
	int         TU_LUYEN_THE_LUC_02;
	int         TU_LUYEN_SD_02;

	int         TU_LUYEN_SAT_THUONG_03;
	int         TU_LUYEN_SAT_THUONGX3_03;
	int         TU_LUYEN_HOAN_HAO_03;
	int         TU_LUYEN_THE_LUC_03;
	int         TU_LUYEN_SD_03;

	int         TU_LUYEN_SAT_THUONG_04;
	int         TU_LUYEN_SAT_THUONGX3_04;
	int         TU_LUYEN_HOAN_HAO_04;
	int         TU_LUYEN_THE_LUC_04;
	int         TU_LUYEN_SD_04;

	int         TU_LUYEN_SAT_THUONG_05;
	int         TU_LUYEN_SAT_THUONGX3_05;
	int         TU_LUYEN_HOAN_HAO_05;
	int         TU_LUYEN_THE_LUC_05;
	int         TU_LUYEN_SD_05;

	int         TU_LUYEN_SAT_THUONG_06;
	int         TU_LUYEN_SAT_THUONGX3_06;
	int         TU_LUYEN_HOAN_HAO_06;
	int         TU_LUYEN_THE_LUC_06;
	int         TU_LUYEN_SD_06;

	int         TU_LUYEN_SAT_THUONG_07;
	int         TU_LUYEN_SAT_THUONGX3_07;
	int         TU_LUYEN_HOAN_HAO_07;
	int         TU_LUYEN_THE_LUC_07;
	int         TU_LUYEN_SD_07;

	int         TU_LUYEN_SAT_THUONG_08;
	int         TU_LUYEN_SAT_THUONGX3_08;
	int         TU_LUYEN_HOAN_HAO_08;
	int         TU_LUYEN_THE_LUC_08;
	int         TU_LUYEN_SD_08;

	int         TU_LUYEN_SAT_THUONG_09;
	int         TU_LUYEN_SAT_THUONGX3_09;
	int         TU_LUYEN_HOAN_HAO_09;
	int         TU_LUYEN_THE_LUC_09;
	int         TU_LUYEN_SD_09;

	int         TU_LUYEN_SAT_THUONG_10;
	int         TU_LUYEN_SAT_THUONGX3_10;
	int         TU_LUYEN_HOAN_HAO_10;
	int         TU_LUYEN_THE_LUC_10;
	int         TU_LUYEN_SD_10;

	int         TU_LUYEN_SAT_THUONG_11;
	int         TU_LUYEN_SAT_THUONGX3_11;
	int         TU_LUYEN_HOAN_HAO_11;
	int         TU_LUYEN_THE_LUC_11;
	int         TU_LUYEN_SD_11;

	int         TU_LUYEN_SAT_THUONG_12;
	int         TU_LUYEN_SAT_THUONGX3_12;
	int         TU_LUYEN_HOAN_HAO_12;
	int         TU_LUYEN_THE_LUC_12;
	int         TU_LUYEN_SD_12;

	int         TU_LUYEN_SAT_THUONG_13;
	int         TU_LUYEN_SAT_THUONGX3_13;
	int         TU_LUYEN_HOAN_HAO_13;
	int         TU_LUYEN_THE_LUC_13;
	int         TU_LUYEN_SD_13;

	int         TU_LUYEN_SAT_THUONG_14;
	int         TU_LUYEN_SAT_THUONGX3_14;
	int         TU_LUYEN_HOAN_HAO_14;
	int         TU_LUYEN_THE_LUC_14;
	int         TU_LUYEN_SD_14;

	int         TU_LUYEN_SAT_THUONG_15;
	int         TU_LUYEN_SAT_THUONGX3_15;
	int         TU_LUYEN_HOAN_HAO_15;
	int         TU_LUYEN_THE_LUC_15;
	int         TU_LUYEN_SD_15;

	int         TU_LUYEN_SAT_THUONG_16;
	int         TU_LUYEN_SAT_THUONGX3_16;
	int         TU_LUYEN_HOAN_HAO_16;
	int         TU_LUYEN_THE_LUC_16;
	int         TU_LUYEN_SD_16;

	int         TU_LUYEN_SAT_THUONG_17;
	int         TU_LUYEN_SAT_THUONGX3_17;
	int         TU_LUYEN_HOAN_HAO_17;
	int         TU_LUYEN_THE_LUC_17;
	int         TU_LUYEN_SD_17;

	int         TU_LUYEN_SAT_THUONG_18;
	int         TU_LUYEN_SAT_THUONGX3_18;
	int         TU_LUYEN_HOAN_HAO_18;
	int         TU_LUYEN_THE_LUC_18;
	int         TU_LUYEN_SD_18;

	int         TU_LUYEN_SAT_THUONG_19;
	int         TU_LUYEN_SAT_THUONGX3_19;
	int         TU_LUYEN_HOAN_HAO_19;
	int         TU_LUYEN_THE_LUC_19;
	int         TU_LUYEN_SD_19;

	int         TU_LUYEN_SAT_THUONG_20;
	int         TU_LUYEN_SAT_THUONGX3_20;
	int         TU_LUYEN_HOAN_HAO_20;
	int         TU_LUYEN_THE_LUC_20;
	int         TU_LUYEN_SD_20;

	int         TU_LUYEN_SAT_THUONG_21;
	int         TU_LUYEN_SAT_THUONGX3_21;
	int         TU_LUYEN_HOAN_HAO_21;
	int         TU_LUYEN_THE_LUC_21;
	int         TU_LUYEN_SD_21;

	int         TU_LUYEN_SAT_THUONG_22;
	int         TU_LUYEN_SAT_THUONGX3_22;
	int         TU_LUYEN_HOAN_HAO_22;
	int         TU_LUYEN_THE_LUC_22;
	int         TU_LUYEN_SD_22;

	int         TU_LUYEN_SAT_THUONG_23;
	int         TU_LUYEN_SAT_THUONGX3_23;
	int         TU_LUYEN_HOAN_HAO_23;
	int         TU_LUYEN_THE_LUC_23;
	int         TU_LUYEN_SD_23;

	int         TU_LUYEN_SAT_THUONG_24;
	int         TU_LUYEN_SAT_THUONGX3_24;
	int         TU_LUYEN_HOAN_HAO_24;
	int         TU_LUYEN_THE_LUC_24;
	int         TU_LUYEN_SD_24;

	int         TU_LUYEN_SAT_THUONG_25;
	int         TU_LUYEN_SAT_THUONGX3_25;
	int         TU_LUYEN_HOAN_HAO_25;
	int         TU_LUYEN_THE_LUC_25;
	int         TU_LUYEN_SD_25;

	int         TU_LUYEN_SAT_THUONG_26;
	int         TU_LUYEN_SAT_THUONGX3_26;
	int         TU_LUYEN_HOAN_HAO_26;
	int         TU_LUYEN_THE_LUC_26;
	int         TU_LUYEN_SD_26;

	int         TU_LUYEN_SAT_THUONG_27;
	int         TU_LUYEN_SAT_THUONGX3_27;
	int         TU_LUYEN_HOAN_HAO_27;
	int         TU_LUYEN_THE_LUC_27;
	int         TU_LUYEN_SD_27;

	int         TU_LUYEN_SAT_THUONG_28;
	int         TU_LUYEN_SAT_THUONGX3_28;
	int         TU_LUYEN_HOAN_HAO_28;
	int         TU_LUYEN_THE_LUC_28;
	int         TU_LUYEN_SD_28;

	int         TU_LUYEN_SAT_THUONG_29;
	int         TU_LUYEN_SAT_THUONGX3_29;
	int         TU_LUYEN_HOAN_HAO_29;
	int         TU_LUYEN_THE_LUC_29;
	int         TU_LUYEN_SD_29;

	int         TU_LUYEN_SAT_THUONG_30;
	int         TU_LUYEN_SAT_THUONGX3_30;
	int         TU_LUYEN_HOAN_HAO_30;
	int         TU_LUYEN_THE_LUC_30;
	int         TU_LUYEN_SD_30;

	int         TU_LUYEN_SAT_THUONG_31;
	int         TU_LUYEN_SAT_THUONGX3_31;
	int         TU_LUYEN_HOAN_HAO_31;
	int         TU_LUYEN_THE_LUC_31;
	int         TU_LUYEN_SD_31;

	int         TU_LUYEN_SAT_THUONG_32;
	int         TU_LUYEN_SAT_THUONGX3_32;
	int         TU_LUYEN_HOAN_HAO_32;
	int         TU_LUYEN_THE_LUC_32;
	int         TU_LUYEN_SD_32;

	int         TU_LUYEN_SAT_THUONG_33;
	int         TU_LUYEN_SAT_THUONGX3_33;
	int         TU_LUYEN_HOAN_HAO_33;
	int         TU_LUYEN_THE_LUC_33;
	int         TU_LUYEN_SD_33;

	int         TU_LUYEN_SAT_THUONG_34;
	int         TU_LUYEN_SAT_THUONGX3_34;
	int         TU_LUYEN_HOAN_HAO_34;
	int         TU_LUYEN_THE_LUC_34;
	int         TU_LUYEN_SD_34;

	int         TU_LUYEN_SAT_THUONG_35;
	int         TU_LUYEN_SAT_THUONGX3_35;
	int         TU_LUYEN_HOAN_HAO_35;
	int         TU_LUYEN_THE_LUC_35;
	int         TU_LUYEN_SD_35;

	int         TU_LUYEN_SAT_THUONG_36;
	int         TU_LUYEN_SAT_THUONGX3_36;
	int         TU_LUYEN_HOAN_HAO_36;
	int         TU_LUYEN_THE_LUC_36;
	int         TU_LUYEN_SD_36;

	int         TU_LUYEN_SAT_THUONG_37;
	int         TU_LUYEN_SAT_THUONGX3_37;
	int         TU_LUYEN_HOAN_HAO_37;
	int         TU_LUYEN_THE_LUC_37;
	int         TU_LUYEN_SD_37;

	int         TU_LUYEN_SAT_THUONG_38;
	int         TU_LUYEN_SAT_THUONGX3_38;
	int         TU_LUYEN_HOAN_HAO_38;
	int         TU_LUYEN_THE_LUC_38;
	int         TU_LUYEN_SD_38;

	int         TU_LUYEN_SAT_THUONG_39;
	int         TU_LUYEN_SAT_THUONGX3_39;
	int         TU_LUYEN_HOAN_HAO_39;
	int         TU_LUYEN_THE_LUC_39;
	int         TU_LUYEN_SD_39;

	int         TU_LUYEN_SAT_THUONG_40;
	int         TU_LUYEN_SAT_THUONGX3_40;
	int         TU_LUYEN_HOAN_HAO_40;
	int         TU_LUYEN_THE_LUC_40;
	int         TU_LUYEN_SD_40;


	int         TU_LUYEN_SAT_THUONG_41;
	int         TU_LUYEN_SAT_THUONGX3_41;
	int         TU_LUYEN_HOAN_HAO_41;
	int         TU_LUYEN_THE_LUC_41;
	int         TU_LUYEN_SD_41;

	int         TU_LUYEN_SAT_THUONG_42;
	int         TU_LUYEN_SAT_THUONGX3_42;
	int         TU_LUYEN_HOAN_HAO_42;
	int         TU_LUYEN_THE_LUC_42;
	int         TU_LUYEN_SD_42;

	int         TU_LUYEN_SAT_THUONG_43;
	int         TU_LUYEN_SAT_THUONGX3_43;
	int         TU_LUYEN_HOAN_HAO_43;
	int         TU_LUYEN_THE_LUC_43;
	int         TU_LUYEN_SD_43;

	int         TU_LUYEN_SAT_THUONG_44;
	int         TU_LUYEN_SAT_THUONGX3_44;
	int         TU_LUYEN_HOAN_HAO_44;
	int         TU_LUYEN_THE_LUC_44;
	int         TU_LUYEN_SD_44;

	int         TU_LUYEN_SAT_THUONG_45;
	int         TU_LUYEN_SAT_THUONGX3_45;
	int         TU_LUYEN_HOAN_HAO_45;
	int         TU_LUYEN_THE_LUC_45;
	int         TU_LUYEN_SD_45;

	int         TU_LUYEN_SAT_THUONG_46;
	int         TU_LUYEN_SAT_THUONGX3_46;
	int         TU_LUYEN_HOAN_HAO_46;
	int         TU_LUYEN_THE_LUC_46;
	int         TU_LUYEN_SD_46;

	int         TU_LUYEN_SAT_THUONG_47;
	int         TU_LUYEN_SAT_THUONGX3_47;
	int         TU_LUYEN_HOAN_HAO_47;
	int         TU_LUYEN_THE_LUC_47;
	int         TU_LUYEN_SD_47;

	int         TU_LUYEN_SAT_THUONG_48;
	int         TU_LUYEN_SAT_THUONGX3_48;
	int         TU_LUYEN_HOAN_HAO_48;
	int         TU_LUYEN_THE_LUC_48;
	int         TU_LUYEN_SD_48;

	int         TU_LUYEN_SAT_THUONG_49;
	int         TU_LUYEN_SAT_THUONGX3_49;
	int         TU_LUYEN_HOAN_HAO_49;
	int         TU_LUYEN_THE_LUC_49;
	int         TU_LUYEN_SD_49;

	int         TU_LUYEN_SAT_THUONG_50;
	int         TU_LUYEN_SAT_THUONGX3_50;
	int         TU_LUYEN_HOAN_HAO_50;
	int         TU_LUYEN_THE_LUC_50;
	int         TU_LUYEN_SD_50;

	int         TU_LUYEN_SAT_THUONG_51;
	int         TU_LUYEN_SAT_THUONGX3_51;
	int         TU_LUYEN_HOAN_HAO_51;
	int         TU_LUYEN_THE_LUC_51;
	int         TU_LUYEN_SD_51;

	int         TU_LUYEN_SAT_THUONG_52;
	int         TU_LUYEN_SAT_THUONGX3_52;
	int         TU_LUYEN_HOAN_HAO_52;
	int         TU_LUYEN_THE_LUC_52;
	int         TU_LUYEN_SD_52;

	int         TU_LUYEN_SAT_THUONG_53;
	int         TU_LUYEN_SAT_THUONGX3_53;
	int         TU_LUYEN_HOAN_HAO_53;
	int         TU_LUYEN_THE_LUC_53;
	int         TU_LUYEN_SD_53;

	int         TU_LUYEN_SAT_THUONG_54;
	int         TU_LUYEN_SAT_THUONGX3_54;
	int         TU_LUYEN_HOAN_HAO_54;
	int         TU_LUYEN_THE_LUC_54;
	int         TU_LUYEN_SD_54;

	int         TU_LUYEN_SAT_THUONG_55;
	int         TU_LUYEN_SAT_THUONGX3_55;
	int         TU_LUYEN_HOAN_HAO_55;
	int         TU_LUYEN_THE_LUC_55;
	int         TU_LUYEN_SD_55;

	int         TU_LUYEN_SAT_THUONG_56;
	int         TU_LUYEN_SAT_THUONGX3_56;
	int         TU_LUYEN_HOAN_HAO_56;
	int         TU_LUYEN_THE_LUC_56;
	int         TU_LUYEN_SD_56;

	int         TU_LUYEN_SAT_THUONG_57;
	int         TU_LUYEN_SAT_THUONGX3_57;
	int         TU_LUYEN_HOAN_HAO_57;
	int         TU_LUYEN_THE_LUC_57;
	int         TU_LUYEN_SD_57;

	int         TU_LUYEN_SAT_THUONG_58;
	int         TU_LUYEN_SAT_THUONGX3_58;
	int         TU_LUYEN_HOAN_HAO_58;
	int         TU_LUYEN_THE_LUC_58;
	int         TU_LUYEN_SD_58;

	int         TU_LUYEN_SAT_THUONG_59;
	int         TU_LUYEN_SAT_THUONGX3_59;
	int         TU_LUYEN_HOAN_HAO_59;
	int         TU_LUYEN_THE_LUC_59;
	int         TU_LUYEN_SD_59;

	int         TU_LUYEN_SAT_THUONG_60;
	int         TU_LUYEN_SAT_THUONGX3_60;
	int         TU_LUYEN_HOAN_HAO_60;
	int         TU_LUYEN_THE_LUC_60;
	int         TU_LUYEN_SD_60;

	int         TU_LUYEN_SAT_THUONG_61;
	int         TU_LUYEN_SAT_THUONGX3_61;
	int         TU_LUYEN_HOAN_HAO_61;
	int         TU_LUYEN_THE_LUC_61;
	int         TU_LUYEN_SD_61;

	int         TU_LUYEN_SAT_THUONG_62;
	int         TU_LUYEN_SAT_THUONGX3_62;
	int         TU_LUYEN_HOAN_HAO_62;
	int         TU_LUYEN_THE_LUC_62;
	int         TU_LUYEN_SD_62;

	int         TU_LUYEN_SAT_THUONG_63;
	int         TU_LUYEN_SAT_THUONGX3_63;
	int         TU_LUYEN_HOAN_HAO_63;
	int         TU_LUYEN_THE_LUC_63;
	int         TU_LUYEN_SD_63;

	int         TU_LUYEN_SAT_THUONG_64;
	int         TU_LUYEN_SAT_THUONGX3_64;
	int         TU_LUYEN_HOAN_HAO_64;
	int         TU_LUYEN_THE_LUC_64;
	int         TU_LUYEN_SD_64;

	int         TU_LUYEN_SAT_THUONG_65;
	int         TU_LUYEN_SAT_THUONGX3_65;
	int         TU_LUYEN_HOAN_HAO_65;
	int         TU_LUYEN_THE_LUC_65;
	int         TU_LUYEN_SD_65;

	int         TU_LUYEN_SAT_THUONG_66;
	int         TU_LUYEN_SAT_THUONGX3_66;
	int         TU_LUYEN_HOAN_HAO_66;
	int         TU_LUYEN_THE_LUC_66;
	int         TU_LUYEN_SD_66;

	int         TU_LUYEN_SAT_THUONG_67;
	int         TU_LUYEN_SAT_THUONGX3_67;
	int         TU_LUYEN_HOAN_HAO_67;
	int         TU_LUYEN_THE_LUC_67;
	int         TU_LUYEN_SD_67;

	int         TU_LUYEN_SAT_THUONG_68;
	int         TU_LUYEN_SAT_THUONGX3_68;
	int         TU_LUYEN_HOAN_HAO_68;
	int         TU_LUYEN_THE_LUC_68;
	int         TU_LUYEN_SD_68;

	int         TU_LUYEN_SAT_THUONG_69;
	int         TU_LUYEN_SAT_THUONGX3_69;
	int         TU_LUYEN_HOAN_HAO_69;
	int         TU_LUYEN_THE_LUC_69;
	int         TU_LUYEN_SD_69;

	int         TU_LUYEN_SAT_THUONG_70;
	int         TU_LUYEN_SAT_THUONGX3_70;
	int         TU_LUYEN_HOAN_HAO_70;
	int         TU_LUYEN_THE_LUC_70;
	int         TU_LUYEN_SD_70;

	int         TU_LUYEN_SAT_THUONG_71;
	int         TU_LUYEN_SAT_THUONGX3_71;
	int         TU_LUYEN_HOAN_HAO_71;
	int         TU_LUYEN_THE_LUC_71;
	int         TU_LUYEN_SD_71;

	int         TU_LUYEN_SAT_THUONG_72;
	int         TU_LUYEN_SAT_THUONGX3_72;
	int         TU_LUYEN_HOAN_HAO_72;
	int         TU_LUYEN_THE_LUC_72;
	int         TU_LUYEN_SD_72;

	int         TU_LUYEN_SAT_THUONG_73;
	int         TU_LUYEN_SAT_THUONGX3_73;
	int         TU_LUYEN_HOAN_HAO_73;
	int         TU_LUYEN_THE_LUC_73;
	int         TU_LUYEN_SD_73;

	int         TU_LUYEN_SAT_THUONG_74;
	int         TU_LUYEN_SAT_THUONGX3_74;
	int         TU_LUYEN_HOAN_HAO_74;
	int         TU_LUYEN_THE_LUC_74;
	int         TU_LUYEN_SD_74;

	int         TU_LUYEN_SAT_THUONG_75;
	int         TU_LUYEN_SAT_THUONGX3_75;
	int         TU_LUYEN_HOAN_HAO_75;
	int         TU_LUYEN_THE_LUC_75;
	int         TU_LUYEN_SD_75;

	int         TU_LUYEN_SAT_THUONG_76;
	int         TU_LUYEN_SAT_THUONGX3_76;
	int         TU_LUYEN_HOAN_HAO_76;
	int         TU_LUYEN_THE_LUC_76;
	int         TU_LUYEN_SD_76;

	int         TU_LUYEN_SAT_THUONG_77;
	int         TU_LUYEN_SAT_THUONGX3_77;
	int         TU_LUYEN_HOAN_HAO_77;
	int         TU_LUYEN_THE_LUC_77;
	int         TU_LUYEN_SD_77;

	int         TU_LUYEN_SAT_THUONG_78;
	int         TU_LUYEN_SAT_THUONGX3_78;
	int         TU_LUYEN_HOAN_HAO_78;
	int         TU_LUYEN_THE_LUC_78;
	int         TU_LUYEN_SD_78;

	int         TU_LUYEN_SAT_THUONG_79;
	int         TU_LUYEN_SAT_THUONGX3_79;
	int         TU_LUYEN_HOAN_HAO_79;
	int         TU_LUYEN_THE_LUC_79;
	int         TU_LUYEN_SD_79;

	int         TU_LUYEN_SAT_THUONG_80;
	int         TU_LUYEN_SAT_THUONGX3_80;
	int         TU_LUYEN_HOAN_HAO_80;
	int         TU_LUYEN_THE_LUC_80;
	int         TU_LUYEN_SD_80;


}; extern TuLuyen gTuLuyen;

#endif
// -------------------------------------------------------------------------------