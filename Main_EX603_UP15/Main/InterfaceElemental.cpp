#include "stdafx.h"
#include "Common.h"
#include "CustomCommandInfo.h"
#include "CustomEventTime.h"
#include "CustomRanking.h"
#include "Interface.h"
#include "InterfaceElemental.h"
#include "Import.h"
#include "Reconnect.h"
#include "TMemory.h"
#include "Defines.h"
#include "OffTrade.h"
#include "Protect.h"
#include "Protocol.h"
#include "PrintPlayer.h"
#include "User.h"
#include "Util.h"
#include "Minimap.h"
#include "StatsAdvance.h"
#include "NPCRuud.h"
#include "Camera.h"
#include "CBNewUiEx.h"
#include "CustomRankUser.h"

CElemental gElemental;

CElemental::CElemental()
{
	this->MsgBoxType = -1;
	this->MsgBoxCallback = 0;
	this->MsgLine = 0;
	this->LockButtonHover = 0;



}


CElemental::~CElemental()
{

}


void CElemental::DrawMessageBox()
{
	if (!gInterface.Data[eWindowMessageBox].OnShow)
	{
		return;
	}
	float CuaSoW = 190;
	float CuaSoH = 90 + (this->MsgLine * 10);

	float StartX = (MAX_WIN_WIDTH / 2) - (CuaSoW / 2);
	float StartY = 45.0;
	pSetBlend(true);
	glColor3f(1.0, 1.0, 1.0);
	gElemental.gDrawWindowCustom(StartX, StartY, CuaSoW, CuaSoH, eWindowMessageBox, this->MsgBoxCaption);
	gElemental.DrawTextA((HFONT)pFontNormal, StartX, StartY + 35, 0xFFFFFFFF, 0x0, CuaSoW, 0, 3, this->MsgBoxText);
	if (this->MsgBoxType == 0)
	{
		float BtnHeight = 20.0;
		float BtnWidth = 120.0;
		if (gElemental.gDrawButton(StartX + CuaSoW / 2 - (BtnWidth / 2), StartY + CuaSoH - BtnHeight - 10, BtnWidth, Main_Font_Height, "CLOSE"))
		{
			gInterface.Data[eWindowMessageBox].OnShow = 0;
		}
	}
	else if (this->MsgBoxType == 1)
	{
		float BtnHeight = 20.0;
		float BtnWidth = 55.0;
		if (gElemental.gDrawButton(StartX + CuaSoW / 2 - (BtnWidth + 7.5), StartY + CuaSoH - BtnHeight - 10, BtnWidth, Main_Font_Height, "OKAY"))
		{
			this->MsgBoxCallback(this);
			this->MsgBoxCallback = 0;
			gInterface.Data[eWindowMessageBox].OnShow = 0;
		}

		if (gElemental.gDrawButton(StartX + CuaSoW / 2 + (7.5), StartY + CuaSoH - BtnHeight - 10, BtnWidth, Main_Font_Height, "CLOSE"))
		{
			gInterface.Data[eWindowMessageBox].OnShow = 0;
		}
	}
	pGLSwitch();
	EnableAlphaTest(0);

}
int DemDong(char* chuoi)
{
	int length = strlen(chuoi), dem = 0;
	for (int i = 0; i < length; i++)
	if (chuoi[i] == '#')
		dem++;
	return dem / 2;
}
void CElemental::OpenMessageBox(char* caption, char* Format, ...)
{
	if (gInterface.Data[eWindowMessageBox].OnShow)
	{
		return;
	}

	char text[1024] = { 0 };
	va_list va;
	va_start(va, Format);
	vsprintf_s(text, Format, va);
	va_end(va);
	this->MsgLine = 0;
	memset(this->MsgBoxCaption, 0, sizeof(this->MsgBoxCaption));
	memset(this->MsgBoxText, 0, sizeof(this->MsgBoxText));

	memcpy(this->MsgBoxCaption, caption, sizeof(this->MsgBoxCaption));
	memcpy(this->MsgBoxText, text, sizeof(this->MsgBoxText));
	this->MsgLine = DemDong(this->MsgBoxText);
	gInterface.Data[eWindowMessageBox].OnShow = true;
	this->MsgBoxType = 0;
	pSetCursorFocus = true;
}

void CElemental::OpenMessageBoxOkCancel(PUSHEVENT_CALLBACK_LPVOID pCallbackFunc, char* caption, char* Format, ...)
{
	if (gInterface.Data[eWindowMessageBox].OnShow)
	{
		return;
	}

	char text[1024] = { 0 };
	va_list va;
	va_start(va, Format);
	vsprintf_s(text, Format, va);
	va_end(va);

	this->MsgLine = 0;
	memset(this->MsgBoxCaption, 0, sizeof(this->MsgBoxCaption));
	memset(this->MsgBoxText, 0, sizeof(this->MsgBoxText));

	memcpy(this->MsgBoxCaption, caption, sizeof(this->MsgBoxCaption));
	memcpy(this->MsgBoxText, text, sizeof(this->MsgBoxText));
	this->MsgLine = DemDong(this->MsgBoxText);
	//gInterface.DrawMessage(1, "DDDD %d %d", this->MsgLine, DemDong(this->MsgBoxText));
	gInterface.Data[eWindowMessageBox].OnShow = true;
	this->MsgBoxType = 1;
	this->MsgBoxCallback = pCallbackFunc;
	pSetCursorFocus = true;
}

void CElemental::gDrawWindowCustom(float StartX, float StartY, float CuaSoW, float CuaSoH, int eNumWindow, char* WindowName)
{
	if (!gInterface.Data[eNumWindow].OnShow)
	{
		return;
	}
	pSetCursorFocus = true; //Khoa Chuot

	if (pCheckMouseOver(StartX, StartY, CuaSoW, CuaSoH) == 1)
	{
		this->LockMouse = GetTickCount() + 500;
	}

	float ScaleW = (225 / CuaSoW) / pWinWidthReal;
	float ScaleH = (225 / CuaSoH) / pWinHeightReal;

	pSetBlend(true);
	glColor3f(1.0, 1.0, 1.0);

	this->DrawFrame(31322, StartX, StartY, 225, 225, 0.0, 0.0, 270, 225, ScaleW, ScaleH); //khung goc ben trai tren

	//==== NGang Tren va Duoi
	for (int i = StartX + 10; i < (StartX + CuaSoW) - 10; i += 10)
	{
		pDrawButton(31353, i, StartY, 10.0, 64.0, 60.0, 0); //khung goc ben trai tren
		pDrawButton(31357, i, (StartY + CuaSoH) - 45.0, 10.0, 45.0, 60.0, 0); //khung goc ben trai tren
	}

	//=== Nen va thanh doc 2 trai phai
	for (int doc = StartY + 10; doc < (StartY + CuaSoH) - 10; doc += 10)
	{
		pDrawButton(31355, StartX, doc, 21.0, 10, 0, 0); //Khung giua ben trai
		pDrawButton(31356, (StartX + CuaSoW) - 21.0, doc, 21.0, 10, 0, 0); //Khung giua ben phai
	}
	pDrawButton(31353, StartX, StartY, 60.0, 64.0, 0, 0); //khung goc ben trai tren
	pDrawButton(31353, (StartX + CuaSoW) - 60.0, StartY, 60.0, 64.0, 130.0, 0); //khung goc ben phai tren

	pDrawButton(31357, StartX, (StartY + CuaSoH) - 45.0, 60.0, 45.0, 0, 0); //khung goc ben trai duoi
	pDrawButton(31357, (StartX + CuaSoW) - 60.0, (StartY + CuaSoH) - 45.0, 60.0, 45.0, 130.0, 0); //khung goc ben phai duoi
	//======Close
	int CloseX = StartX + CuaSoW - 33.0f;
	int CloseY = StartY;
	pDrawGUI(0x7EC5, CloseX, CloseY, 36.0f, 29.0f);
	if (pCheckMouseOver(CloseX, CloseY, 36, 36) == 1)
	{
		if (pIsKeyPress(VK_LBUTTON) && GetTickCount() - gInterface.Data[eNumWindow].EventTick > 300)
		{

			PlayBuffer(25, 0, 0);
			glColor3f(1.0f, 0.0f, 0.0f);
			gInterface.Data[eNumWindow].OnShow ^= 1;
			gInterface.Data[eNumWindow].EventTick = GetTickCount();
			pSetCursorFocus = false; // mo khoa

		}
		pDrawColorButton(0x7EC5, CloseX, CloseY, 36, 29, 0, 0, pMakeColor(255, 204, 20, 130));
		gInterface.DrawToolTip(gObjUser.m_CursorX + 20, gObjUser.m_CursorY, "Close");
	}
	//================================================

	gInterface.DrawFormat(eShinyGreen, StartX, StartY + 7, CuaSoW, 3, WindowName);
	pGLSwitch();
	EnableAlphaTest(0);
}

void CElemental::gInfoBox(float PosX, float PosY, float Width, float Height, DWORD bkcolor, float Arg5, int Arg6)
{
	float Red = (float)((bkcolor & 0xff000000) >> 24) / 255.0f;
	float Green = (float)((bkcolor & 0x00ff0000) >> 16) / 255.0f;
	float Blue = (float)((bkcolor & 0x0000ff00) >> 8) / 255.0f;
	float Alpha = (float)(bkcolor & 0x000000ff) / 255.0f;
	pSetBlend(1);
	if (bkcolor)
	{
		glColor4f(Red, Green, Blue, Alpha);
		pDrawBarForm(PosX, PosY, Width + 6.5, Height + 5, Arg5, Arg6); //central
	}
	float RightX = PosX - 2.0f;
	float LeftX = (PosX + Width) - 2.0f;
	float TopY = PosY - 2.0f;
	float DownY = (PosY + Height) - 2.0f;
	bool horizontal = true;
	bool vertical = true;
	//--
	float IniciarX = PosX - 2.0f;
	float w = 14.0f;
	//--
	float IniciarY = PosY - 2.0f;
	float H = 14.0f;

	pSetBlend(true);
	glColor3f(1.0, 1.0, 1.0);

	while (vertical || horizontal)
	{
		if (vertical)
		{
			IniciarX += 14.0f;

			if ((IniciarX + w) > LeftX)
			{
				vertical = false;
				w = LeftX - IniciarX;
			}
			pDrawGUI(31344, IniciarX, TopY, w, 14.0f); //Ngang

			pDrawGUI(31345, IniciarX, DownY, w, 14.0f); //Ngang 2
		}
		//-- abajo
		if (horizontal)
		{
			IniciarY += 14.0f;

			if ((IniciarY + H) > DownY)
			{
				horizontal = false;
				H = DownY - IniciarY;
			}

			pDrawGUI(31346, RightX, IniciarY, 14.0f, H); // Doc 1

			pDrawGUI(31347, LeftX, IniciarY, 14.0f, H); //Doc 2
		}
	}

	pDrawGUI(31340, RightX, TopY, 14.0f, 14.0f); //Goc tren ben trai

	pDrawGUI(31341, LeftX, TopY, 14.0f, 14.0f); //Goc tren ben phai

	pDrawGUI(31342, RightX, DownY, 14.0f, 14.0f);  //Goc duoi trai

	pDrawGUI(31343, LeftX, DownY, 14.0f, 14.0f);  //Goc Duoi phai

	pGLSwitch();
	EnableAlphaTest(0);
}

void CElemental::DrawFrame(DWORD ModelID, float X, float Y, float W, float H, float SourceX, float SourceY, float SourceW, float SourceH, float ScaleW, float ScaleH, bool ScaleUp) {
	float v1, v2;

	if (W) {
		W /= ScaleW;
		v1 = ScaleW / (SourceW / W);
	}
	else {
		v1 = ScaleW;
	}

	if (H) {
		H /= ScaleH;
		v2 = ScaleH / (SourceH / H);
	}
	else {
		v2 = ScaleH;
	}
	RenderBitmap(ModelID, X, Y, W, H, SourceX / SourceW, SourceY / SourceH, v1, v2, ScaleUp, 1, 0.0);
}

bool CElemental::gDrawButton(float PosX, float PosY, float SizeButton, int FontSize, char* ButtonText, float mSizeButtonW)
{
	pSetBlend(true);
	glColor3f(1.0, 1.0, 1.0);
	//============Button
	float SizeButtonW = SizeButton;
	float SizeButtonH = (SizeButton * 20) / 100;
	if (mSizeButtonW != 0)
	{
		SizeButtonW = mSizeButtonW;
	}

	float StartX = PosX;
	float StartY = PosY;
	bool mreturn = false;
	//=====================Button 1
	if (pCheckMouseOver(StartX, StartY, SizeButtonW, SizeButtonH) == 1 && !this->LockButtonHover)
	{
		glColor3f(1.0f, 0.6742f, 0.15f);
		if (GetTickCount() - gInterface.Data[eWindowElemental].EventTick > 300) //Click
		{
			if (GetKeyState(1) & 0x8000)
			{

				glColor3f(0.72f, 0.438f, 0.0432f);


				gInterface.Data[eWindowElemental].EventTick = GetTickCount();
				mreturn = true;
			}
		}
	}
	else {
		glColor3f(1.0f, 1.0f, 1.0f);

	}
	RenderBitmap(31563, StartX, StartY, SizeButtonW, SizeButtonH, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);
	gInterface.DrawFormat(eShinyGreen, StartX, StartY + (SizeButtonH / 2) - (FontSize / 2.5), SizeButtonW, 3, ButtonText);
	//=====================================
	glColor3f(1.0f, 1.0f, 1.0f); //Xoa mau
	DeleteObject(ButtonText);
	pGLSwitch();
	EnableAlphaTest(0);
	return mreturn;
}
void CElemental::DrawText(HFONT font, int PosX, int PosY, DWORD color, DWORD bkcolor, int Width, int Height, BYTE Align, LPCTSTR Text, ...)
{
	char Buff[2048];
	int BuffLen = sizeof(Buff)-1;
	ZeroMemory(Buff, BuffLen);

	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);

	int LineCount = 0;

	char* Line = strtok(Buff, "\n##");

	while (Line != NULL)
	{
		pSetFont(pTextThis(), (int)font);
		pSetTextColor(pTextThis(), (color & 0xff000000) >> 24, (color & 0x00ff0000) >> 16, (color & 0x0000ff00) >> 8, color & 0x000000ff);
		pSetBackgroundTextColor(pTextThis(), (bkcolor & 0xff000000) >> 24, (bkcolor & 0x00ff0000) >> 16, (bkcolor & 0x0000ff00) >> 8, bkcolor & 0x000000ff);
		pDrawText(pTextThis(), PosX, PosY, Line, Width, Height, (LPINT)Align, 0);
		PosY += 10;
		Line = strtok(NULL, "\n##");
		pSetFont(pTextThis(), (int)pFontNormal);
	}
}
