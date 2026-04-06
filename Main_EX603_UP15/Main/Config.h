#ifndef _Config_H
#define _Config_H

class cConfig
{
public:
	void Load();
	//===================================================
#if(TextHDC_NEW)
	char TextVN[500][500];
	char ToggleAuto_TextVN[120][120];

#if(DANH_HIEU_NEW)
	char TextVN_DanhHieu[500][500];
#endif
#if(QUAN_HAM_NEW)
	char TextVN_QuanHam[210][210];
#endif
#if(TU_LUYEN_NEW)
	char TextVN_TuLuyen[410][410];
#endif
	char TextTM_ThanMaChien[50][120];

	char TextTM_NganHangNgoc[50][120];

#endif


};
extern cConfig gConfig;
//===================================================
#define TEXTVN_FILE "./Data/Custom/TextVN.dat"
extern int Server;
#endif