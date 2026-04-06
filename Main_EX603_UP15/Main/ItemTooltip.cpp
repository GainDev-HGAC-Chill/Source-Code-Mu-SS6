#include "stdafx.h"
#include "ItemTooltip.h"
#include "Object.h"
#include "Util.h"
#include "SItemOption.h"
#include "Common.h"
#include "Import.h"
#include "Offset.h"
#include "Console.h"

nCInfo GInfo;


nCInfo::nCInfo()
{
	this->m_CustomInfo.clear();
	this->m_CustomDescripcionInfo.clear();
}

nCInfo::~nCInfo()
{
}



void nCInfo::loadnInformation(nInformation * info) // OK
{
	for (int n = 0; n < MaxLine; n++)
	{
		if (info[n].ItemIndexMin < 0 || info[n].ItemIndexMax > 7680)
		{
			return;
		}
		//this->m_CustomInfo.push_back(info[n]);
		this->m_CustomInfo.insert(std::pair<int, nInformation>(info[n].Index, info[n]));
	}
}

void nCInfo::loadnText(nText * info) // OK
{
	for (int n = 0; n < MaxLine; n++)
	{
		if (info[n].Index < 0 || info[n].Index > 7680)
		{
			return;
		}
		this->m_CustomDescripcionInfo.insert(std::pair<int, nText>(info[n].Index, info[n]));
	}
}


char * nGetTextLine(int TextIndex)
{
	std::map<int, nText>::iterator it = GInfo.m_CustomDescripcionInfo.find(TextIndex);

	if (it != GInfo.m_CustomDescripcionInfo.end())
	{
		return it->second.Text;
	}

	return "no found";
}
#define pGetSpecialOptionText ((void(__cdecl*)(int Type, char* Text, BYTE Option, BYTE Value, int iMana)) 0x005C2F70)//GetSpecialOptionText
int nCInfo::nInformationOP(int CurrenLine, ObjectItem* ItemSearch)
{
	//std::map<int, nInformation>::iterator it = GInfo.m_CustomInfo.find( ItemSearch );
	//
	//if(it !=  GInfo.m_CustomInfo.end())
	//{
	//	tooltiparray * TooltipLine = (tooltiparray*)NewAddressData3;
	//	int * ColorTexto = (int*)NewAddressData1;
	//	int * LineWeight = (int*)NewAddressData2;
	//
	//	wsprintf(TooltipLine[ CurrenLine ], it->second.OptionName);
	//	ColorTexto[ CurrenLine ] = it->second.OptionColor;
	//	LineWeight[ CurrenLine++ ] = 1;
	//
	//	wsprintf(TooltipLine[CurrenLine++], "\n");
	//
	//	for( int i = 0 ; i < 15 ; i++ )
	//	{
	//		if( it->second.TextIndex[ i ] == -1) { continue; }
	//		wsprintf(TooltipLine[ CurrenLine ], "%s", nGetTextLine( it->second.TextIndex[ i ] ));
	//		ColorTexto[ CurrenLine ] = it->second.TextColor[ i ];
	//		LineWeight[ CurrenLine++ ] = 0;
	//	}
	//}

	for (std::map<int, nInformation>::iterator it = GInfo.m_CustomInfo.begin(); it != GInfo.m_CustomInfo.end(); it++)
	{
		if (it == GInfo.m_CustomInfo.end())
		{
			return 0;
		}
		if (ItemSearch->ItemID >= it->second.ItemIndexMin && ItemSearch->ItemID <= it->second.ItemIndexMax)
		{

			bool SetColorGray = false;
			//g_Console.AddMessage(1, "Exc %d/%d Lv %d/%d Skill %d", 
			//	(BYTE*)ItemSearch->ExcellentOption, it->second.Exc, 
			//	(ItemSearch->Level >> 3) & 15, it->second.Level, 
			//	ItemSearch->SpecialType[0]);,
			//	ItemSearch->SpecialValue[1]);
			//	);
			//SpecialValue[0] =  Opt Life


			tooltiparray * TooltipLine = (tooltiparray*)NewAddressData3;
			int * ColorTexto = (int*)NewAddressData1;
			int * LineWeight = (int*)NewAddressData2;

			wsprintf(TooltipLine[CurrenLine], it->second.OptionName);

			ColorTexto[CurrenLine] = it->second.OptionColor;
			LineWeight[CurrenLine++] = 1;

			wsprintf(TooltipLine[CurrenLine++], "\n");

			LineWeight[CurrenLine++] = 0;
			for (int i = 0; i < 15; i++)
			{
				if ((it->second.LevelItem[i] >(int)((ItemSearch->Level >> 3) & 15) && it->second.LevelItem[i] != -1) || ((int)ItemSearch->ExcellentOption < it->second.Exc  && it->second.Exc != -1))
				{
					SetColorGray = true;
				}

				if (it->second.TextIndex[i] == -1) { continue; }
				wsprintf(TooltipLine[CurrenLine], "%s", nGetTextLine(it->second.TextIndex[i]));
				if (SetColorGray)
				{
					ColorTexto[CurrenLine] = 10;
				}
				else {
					ColorTexto[CurrenLine] = it->second.TextColor[i];
				}
				LineWeight[CurrenLine++] = 0;
			}

		}
	}
	return CurrenLine;
}

void Borde(float PosX, float PosY, float Width, float Height, float Arg5, int Arg6)
{
	glColor4f(0.0, 0.0, 0.0, 0.80000001);

	pDrawBarForm(PosX, PosY, Width, Height, Arg5, Arg6); //central
	glEnable(0xDE1u);

	glColor4f(0.0, 0.0, 0.0, 1.00000001);

	pDrawBarForm(PosX, PosY, 2, Height, Arg5, Arg6); //central

	pDrawBarForm(PosX + Width - 2, PosY, 2, Height, Arg5, Arg6); //central

	pDrawBarForm(PosX, PosY, Width, 2, Arg5, Arg6); //central

	pDrawBarForm(PosX, PosY + Height - 2, Width, 2, Arg5, Arg6); //central
	glEnable(0xDE1u);
}

void GetTextColor(int ColorTexto)
{
	SetTextColorByHDC(pTextThis(), -1);

	switch (ColorTexto)
	{
	case 0:
	case TEXT_WHITE:
	case TEXT_WHITE_RED:
	case TEXT_WHITE_BLUE:
	case TEXT_WHITE_YELLOW:
		glColor3f(1.0, 1.0, 1.0);
		break;
	case TEXT_BLUE:
		glColor3f(0.5f, 0.69999999f, 1.0);
		break;
	case TEXT_GRAY:
		glColor3f(0.40000001f, 0.40000001f, 0.40000001f);
		break;
	case TEXT_GREN_BLUE:
		glColor3f(1.0, 1.0, 1.0);
		break;
	case TEXT_RED:
		glColor3f(1.0, 0.2f, 0.1);
		break;
	case TEXT_GOLD:
		glColor3f(1.0, 0.80000001f, 0.1);
		break;
	case TEXT_GREN:
		glColor3f(0.1, 1.0, 0.5f);
		break;
	case TEXT_PINK:
		glColor3f(1.0, 0.1, 1.0);
		break;
	case TEXT_PINK2:
		glColor3f(0.80000001f, 0.5, 0.80000001f);
		break;
	case TEXT_PURPLE:
		glColor3f(0.69999999f, 0.40000001f, 1.0);
		break;
	case TEXT_ORANGE:
		glColor3f(0.89999998f, 0.41999999f, 0.039999999f);
		break;
	default:
		break;
	}

	switch (ColorTexto)
	{
	case TEXT_WHITE_RED:
		pSetBackgroundTextColor(pTextThis(), 0xA0u, 0, 0, 0xFFu);
		break;
	case TEXT_WHITE_BLUE:
		pSetBackgroundTextColor(pTextThis(), 0, 0, 0xA0u, 0xFFu);
		break;
	case TEXT_WHITE_YELLOW:
		pSetBackgroundTextColor(pTextThis(), 0xA0u, 0x66u, 0, 0xFFu);
		break;
	case TEXT_GREN_BLUE:
		pSetBackgroundTextColor(pTextThis(), 0x3Cu, 0x3Cu, 0xC8u, 0xFFu);
		pSetTextColor(pTextThis(), 0, 0xFFu, 0, 0xFFu);
		break;
	case 15: //-- DeepPink1
		pSetBackgroundTextColor(pTextThis(), 255, 20, 147, 0xFFu);
		pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
		break;
	case 16: //-- RoyalBlue1
		pSetBackgroundTextColor(pTextThis(), 72, 118, 255, 0xFFu);
		pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
		break;
	case 17: //-- SlateBlue1
		pSetBackgroundTextColor(pTextThis(), 131, 111, 255, 0xFFu);
		pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
		break;
	case 18: //-- Azure2
		pSetBackgroundTextColor(pTextThis(), 224, 238, 238, 0xFFu);
		pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
		break;
	case 19: //-- DarkSlateGray1
		pSetBackgroundTextColor(pTextThis(), 151, 255, 255, 0xFFu);
		pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
		break;
	case 20: //-- SlateGray1
		pSetBackgroundTextColor(pTextThis(), 198, 226, 255, 0xFFu);
		pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
		break;
	case 21: //-- MistyRose1
		pSetBackgroundTextColor(pTextThis(), 255, 228, 225, 0xFFu);
		pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
		break;
	case 22: //-- LightSlateBlue
		pSetBackgroundTextColor(pTextThis(), 132, 112, 255, 0xFFu);
		pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
		break;
	case 23: //-- DeepSkyBlue1
		pSetBackgroundTextColor(pTextThis(), 0, 191, 255, 0xFFu);
		pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
		break;
	case 24: //-- Turquoise1
		pSetBackgroundTextColor(pTextThis(), 0, 245, 255, 0xFFu);
		pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
		break;
	default:
		sub_4200F0_Addr(pTextThis(), 0);
		break;
	}
}
