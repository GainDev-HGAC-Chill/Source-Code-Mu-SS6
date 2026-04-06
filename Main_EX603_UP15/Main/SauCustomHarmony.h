#pragma once
// CustomHealthBar.h: interface for the CCustomHealthBar class.
//
//////////////////////////////////////////////////////////////////////

#pragma once
#include "Protocol.h"

#if (CUSTOM_HARMONY)
#define BPConvertByteItem ((int (__thiscall*)(int a1, void *lp)) 0x7E1B10)
struct OPTITEM
{
	int OptIndex;
	char Name[60];
	int Level;
	int Rate;
};


struct DATAOHOA_SENDCLIENT
{
	PSWMSG_HEAD header;
	BYTE ActiveMix;
	BYTE ItemChuaEp[16];
	int Rate;
	int Price;
	int PriceType;
	int SoLuongDaTaoHoa;
	int IndexRandom;

};


class SauCustomHarmony
{
public:
	SauCustomHarmony();
	virtual ~SauCustomHarmony();
	void Init();

	void DrawHarmony();
	void RecvHarmony(CSEV_COUNTLIST* lpMsg);
	std::vector<OPTITEM> m_HarmonyInfoList;
	char* GetNamePrice();
	bool Harmony_ActiveMix;
	bool Harmony_EffectsMix;
	bool SetStateHarmony;
	BYTE ItemChuaEp[16];
	int Rate;
	int Price;
	int PriceType;
	int SoLuongDaTaoHoa;
	int IndexRandom;

private:

};

extern SauCustomHarmony gSauCustomHarmony;
#endif