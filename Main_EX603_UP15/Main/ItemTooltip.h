#pragma once
#define MaxLine 2000
#include "Object.h"

struct nInformation
{
	int Index;
	int ItemIndexMin;
	int ItemIndexMax;

	int Exc;
	//--
	char OptionName[32];
	int OptionColor;
	//--
	int TextIndex[15];
	int TextColor[15];
	int LevelItem[15];
};

struct nText
{
	int Index;
	char Text[254];
};

class nCInfo
{
public:
	nCInfo();
	virtual ~nCInfo();
	void loadnInformation(nInformation * info);
	void loadnText(nText * info);
	int nInformationOP(int CurrenLine, ObjectItem* ItemSearch);
	void IniInformation();
public:
	std::map<int, nInformation> m_CustomInfo;
	std::map<int, nText> m_CustomDescripcionInfo;
};

extern nCInfo GInfo;