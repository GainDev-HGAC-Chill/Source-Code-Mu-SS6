#include "stdafx.h"
#include "CNewUIWindowsClient.h"
#include "Interface.h"
#include "Util.h"
#include "CustomFont.h"
#include "TMemory.h"
#include "Defines.h"
#include <sstream>
#include <iomanip>
#include <string>
#include "Protect.h"
#include "Central.h"
#include "UIControl.h"
CNewUIWindowsClient nInterface;

CNewUIWindowsClient::CNewUIWindowsClient()
{
#if(JEWELBANKVER2)
	this->JEWELBANK_WINDOW = new GUIObj(-1, 60, 440, 340, true); // Set X,Y,W,H
#endif

}

CNewUIWindowsClient::~CNewUIWindowsClient()
{


}

void CNewUIWindowsClient::Load() {
	this->CaiDetConMet = 123.45678;
	this->ResizeGuiScaleRateX = pWinWidth / 800;
	this->ResizeGuiScaleRateY = pWinHeight / 600;



}

void CNewUIWindowsClient::DrawGui(short ObjID, float X, float Y, float W, float H, float SourceX, float SourceY, float SourceW, float SourceH, float ScaleW, float ScaleH, bool ScaleUp) {
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
	pNIDrawGUI(gInterface.Data[ObjID].ModelID, X, Y, W, H, SourceX / SourceW, SourceY / SourceH, v1, v2, ScaleUp, 1, 0);
}

void CNewUIWindowsClient::DrawFrame(DWORD ModelID, float X, float Y, float W, float H, float SourceX, float SourceY, float SourceW, float SourceH, float ScaleW, float ScaleH, bool ScaleUp) {
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
	pNIDrawGUI(ModelID, X, Y, W, H, SourceX / SourceW, SourceY / SourceH, v1, v2, ScaleUp, 1, 0);
}

void CNewUIWindowsClient::DrawCircle(DWORD ModelID, float X, float Y, float W, float H, float SourceX, float SourceY, float SourceW, float SourceH, float Scale, bool ScaleUp) {
	pNIDrawGUI(ModelID, X, Y, W, H, SourceX / SourceW, SourceY / SourceH, Scale / (SourceW / W), Scale / (SourceH / H), ScaleUp, 1, 0);
}

float CNewUIWindowsClient::resizeX(float a1) {
	return a1 / ((float)pWinWidth / 800.0f);
}
float CNewUIWindowsClient::resizeY(float a1) {
	return a1 / ((float)pWinHeight / 600.0f);
}


void CNewUIWindowsClient::DrawWindowBG(float a1, float a2) {
	static float v1;
	static float v2;
	static float v3;

	v1 = a2 + 74 / scale_ratio;
	v2 = v1 + 179 / scale_ratio;
	v3 = scale_height / 1.3;
	nInterface.DrawFrame(0xF1003, a1, a2, 325, 74, 652, 106, 1024, 512, scale_width, scale_height, 0);
	nInterface.DrawFrame(0xF1003, a1, v1, 325, 179, 326, 1, 1024, 512, scale_width, scale_height, 0);
	nInterface.DrawFrame(0xF1003, a1, v2, 325, 386, 0, 1, 1024, 495, scale_width, v3, 0);
}
void CNewUIWindowsClient::UpdateButton(GUIButton* gui, float a1, float a2, float a3, float a4)
{
	gui->X = a1;
	gui->Y = a2;
	if (a3)
		gui->Width = a3;
	if (a4)
		gui->Height = a4;
	gui->Max_X = gui->X + gui->Width;
	gui->Max_Y = gui->Y + gui->Height;
}
bool CNewUIWindowsClient::DrawCheckbox(GUICheckbox* gui, float X, float Y, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen = sizeof(Buff)-1;
	ZeroMemory(Buff, BuffLen);
	// ----
	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);

	gui->pos->X = X;
	gui->pos->Y = Y;
	gui->pos->Max_X = gui->pos->X + gui->pos->Width;
	gui->pos->Max_Y = gui->pos->Y + gui->pos->Height;

	return this->DrawCheckbox(gui, Buff);
}
bool CNewUIWindowsClient::DrawCheckbox(GUICheckbox* gui, float X, float Y, float W, float H, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen = sizeof(Buff)-1;
	ZeroMemory(Buff, BuffLen);
	// ----
	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);

	gui->pos->X = X;
	gui->pos->Y = Y;
	gui->pos->Width = W;
	gui->pos->Height = H;
	gui->pos->Max_X = gui->pos->X + gui->pos->Width;
	gui->pos->Max_Y = gui->pos->Y + gui->pos->Height;

	return this->DrawCheckbox(gui, Buff);
}
bool CNewUIWindowsClient::DrawCheckbox(GUICheckbox* gui, LPCSTR Text, ...)
{
	static float v1;
	static float v2;
	static float v3;
	static float v4;
	static float v5;
	static float v6;
	static float v7;
	static float v8;
	static float v9;
	static float v10;
	bool res = false;


	bool hoving = this->IsWorkZone(gui->pos->X, gui->pos->Y, gui->pos->Width, gui->pos->Height);

	v1 = (gui->pos->Width * scale_ratio) / 15;
	v2 = (gui->pos->Height * scale_ratio) / 15;
	v3 = scale_width / v1;
	v4 = scale_height / v2;
	v5 = gui->pos->X + gui->pos->Width + 2 * pWinWidthReal;
	char Buff[2048];
	int BuffLen = sizeof(Buff)-1;
	ZeroMemory(Buff, BuffLen);
	// ----
	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	if (hoving) {
		if (GetKeyState(VK_LBUTTON) & 0x8000) {
			if (gui->lastActionTime + gui->delay <= GetTickCount() && gui->state < 64) {
				if (gui->state == 0)
				{
					gui->state = 64;
				}
				else
				{
					gui->state = 65;
				}
				gui->lastActionTime = GetTickCount();
			}
			if (gui->state == 1 || gui->state == 64)
				nInterface.DrawFrame(0xF1008, gui->pos->X, gui->pos->Y, 15, 15, 874, 178, 1024, 1024, v3, v4, 0); //clicked down
			else
				nInterface.DrawFrame(0xF1008, gui->pos->X, gui->pos->Y, 15, 15, 1010, 123, 1024, 1024, v3, v4, 0); //clicked down
		}
		else {
			if (gui->state == 64) {
				gui->state = 1;
				res = true;
			}
			else if (gui->state == 65) {
				gui->state = 0;
				res = true;
			}
			if (gui->state == 1)
				nInterface.DrawFrame(0xF1008, gui->pos->X, gui->pos->Y, 15, 15, 913, 162, 1024, 1024, v3, v4, 0); //hoving
			else
				nInterface.DrawFrame(0xF1008, gui->pos->X, gui->pos->Y, 15, 15, 853, 162, 1024, 1024, v3, v4, 0);//hoving
		}
	}
	else {
		if (gui->state == 64) {
			gui->state = 1;
			res = true;
		}
		else if (gui->state == 65) {
			gui->state = 0;
			res = true;
		}
		if (gui->state == 1)
			nInterface.DrawFrame(0xF1008, gui->pos->X, gui->pos->Y, 15, 15, 943, 162, 1024, 1024, v3, v4, 0); //normal showing
		else
			nInterface.DrawFrame(0xF1008, gui->pos->X, gui->pos->Y, 15, 15, 868, 162, 1024, 1024, v3, v4, 0); //normal showing
	}



	//else if (gui->state == 1)
	//	nInterface.DrawFrame(0xF1008, gui->pos->X, gui->pos->Y, 15, 15, 853, 162, 1024, 1024, v3, v4, 0); //selected
	textSize tS = nInterface.getTextSize(Buff);

	CustomFont.Draw(CustomFont.FontNormal, v5, gui->pos->Y, 0xffffffff, 0x0, 0, 0, 0, Buff);


	return res;
}

bool CNewUIWindowsClient::DrawButton(GUIButton* gui, float X, float Y, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen = sizeof(Buff)-1;
	ZeroMemory(Buff, BuffLen);
	// ----
	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);

	gui->X = X;
	gui->Y = Y;
	gui->Max_X = gui->X + gui->Width;
	gui->Max_Y = gui->Y + gui->Height;

	return this->DrawButton(gui, Buff);
}

bool CNewUIWindowsClient::DrawButton(GUIButton* gui, float X, float Y, float W, float H, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen = sizeof(Buff)-1;
	ZeroMemory(Buff, BuffLen);
	// ----
	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);

	gui->X = X;
	gui->Y = Y;
	gui->Width = W;
	gui->Height = H;
	gui->Max_X = gui->X + gui->Width;
	gui->Max_Y = gui->Y + gui->Height;

	return this->DrawButton(gui, Buff);
}

bool CNewUIWindowsClient::DrawButton(GUIButton* gui, LPCSTR Text, ...)
{
	static float v1;
	static float v2;
	static float v3;
	static float v4;
	static float v5;
	static float v6;
	static float v7;
	static float v8;
	static float v9;
	static float v10;
	bool res = false;


	bool hoving = this->IsWorkZone(gui->X, gui->Y, gui->Width, gui->Height);

	v1 = (gui->Width * scale_ratio) / BUTTON_WIDTH;
	v2 = (gui->Height * scale_ratio) / BUTTON_HEIGHT;
	v3 = scale_width / v1;
	v4 = scale_height / v2;

	char Buff[2048];
	int BuffLen = sizeof(Buff)-1;
	ZeroMemory(Buff, BuffLen);
	// ----
	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	if (hoving) {
		if (GetKeyState(VK_LBUTTON) & 0x8000) {
			if (gui->lastActionTime + gui->delay <= GetTickCount() && !gui->clickDown) {
				gui->clickDown = true;
				gui->lastActionTime = GetTickCount();
			}
			nInterface.DrawFrame(0xF1003, gui->X, gui->Y, BUTTON_WIDTH, BUTTON_HEIGHT, 332, 294, 1024, 512, v3, v4, 0);
		}
		else {
			if (gui->clickDown) {
				gui->state = !gui->state;
				res = true;
				gui->clickDown = false;
			}
			nInterface.DrawFrame(0xF1003, gui->X, gui->Y, BUTTON_WIDTH, BUTTON_HEIGHT, 404, 294, 1024, 512, v3, v4, 0);
		}
	}
	else if (gui->state == 1)
		nInterface.DrawFrame(0xF1003, gui->X, gui->Y, BUTTON_WIDTH, BUTTON_HEIGHT, 706, 258, 1024, 512, v3, v4, 0);
	else
		nInterface.DrawFrame(0xF1003, gui->X, gui->Y, BUTTON_WIDTH, BUTTON_HEIGHT, 634, 258, 1024, 512, v3, v4, 0);

	textSize tS = nInterface.getTextSize(Buff);

	v5 = gui->Y + (gui->Height - tS.resize_height) / 2;

	CustomFont.Draw(CustomFont.FontNormal, gui->X, v5, 0xffffffff, 0x0, gui->Width, tS.resize_height, 3, Buff);


	return res;
}
bool CNewUIWindowsClient::DrawWindowBG(GUIObj * gui, LPCSTR Text, ...) {
	static float v1;
	static float v2;
	static float v3;
	static float v4;
	static float v5;
	static float v6;
	static float v7;
	static float v8;
	static float v9;
	static float v10;

	//


	char Buff[2048];
	int BuffLen = sizeof(Buff)-1;
	ZeroMemory(Buff, BuffLen);
	// ----
	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);

	textSize tS = nInterface.getTextSize(Buff);

	if (this->IsWorkZone(gui->X, gui->Y, gui->Width, gui->Height))
	{
		gInterface.LockMouseMoveClick = GetTickCount() + 500;
	}
	//if (gui->X == -1)
	//{
	//	gui->X = setPosCenterX(gui->Width);
	//}
	if (GetKeyState(VK_LBUTTON) & 0x8000)
	{

		if (this->IsWorkZone(gui->X, gui->Y, gui->Width, v3))
		{
			if (!gui->dragging) {
				gui->dragging = true;
				gui->curX = pCursorX;
				gui->curY = pCursorY;
			}
		}
		if (gui->dragging) {
			gui->X += pCursorX - gui->curX;
			gui->Y += pCursorY - gui->curY;
			gui->curX = pCursorX;
			gui->curY = pCursorY;
			gui->Max_X = gui->X + gui->Width;
			gui->Max_Y = gui->Y + gui->Height;
		}
	}
	else {
		if (gui->dragging)
		{
			gui->dragging = false;
		}
	}

	v1 = (1024 / gui->Width) / pWinWidthReal;
	v2 = (1024 / gui->Height) / pWinHeightReal;
	v3 = gui->Height / 1024 * 130;
	v4 = gui->Y + v3 - tS.resize_height - 5 * pWinHeightReal;

	//if (gProtect.m_MainInfo.CustomInterfaceType >= 3)
	//{
	//	nInterface.DrawFrame(0xF1007, gui->X, gui->Y, 1024, 1024, 0, 0, 1024, 1024, v1, v2, 0);

	//	CustomFont.Draw(CustomFont.FontBold, gui->X, v4, 0xffffffff, 0x0, gui->Width, tS.resize_height, 3, Buff);
	//	if (nInterface.Drawbutton(nInterface.CloseWindowsUP, (gui->X + gui->Width) - (nInterface.CloseWindowsUP->data->Width + 10), v4, ""))
	//	{
	//		gui->onShow ^= 1;
	//		//gInterface.Data[eNumWindow].OnShow ^= 1;
	//		//m_Photo->ClosedProcess();
	//	}
	//}
	//else
	{
		float ScaleW = (225 / gui->Width) / pWinWidthReal;
		float ScaleH = (225 / gui->Height) / pWinHeightReal;
		pSetBlend(true);
		glColor3f(1.0, 1.0, 1.0);

		nInterface.DrawFrame(31322, gui->X, gui->Y, 225, 225, 0.0, 0.0, 270, 225, ScaleW, ScaleH); //khung goc ben trai tren

		//==== NGang Tren va Duoi
		for (int i = gui->X + 10; i < (gui->X + gui->Width) - 10; i += 10)
		{
			pDrawButton(31353, i, gui->Y, 10.0, 64.0, 60.0, 0); //khung goc ben trai tren
			pDrawButton(31357, i, (gui->Y + gui->Height) - 45.0, 10.0, 45.0, 60.0, 0); //khung goc ben trai tren
		}

		//=== Nen va thanh doc 2 trai phai
		for (int doc = gui->Y + 10; doc < (gui->Y + gui->Height) - 10; doc += 10)
		{
			pDrawButton(31355, gui->X, doc, 21.0, 10, 0, 0); //Khung giua ben trai
			pDrawButton(31356, (gui->X + gui->Width) - 21.0, doc, 21.0, 10, 0, 0); //Khung giua ben phai
		}
		pDrawButton(31353, gui->X, gui->Y, 60.0, 64.0, 0, 0); //khung goc ben trai tren
		pDrawButton(31353, (gui->X + gui->Width) - 60.0, gui->Y, 60.0, 64.0, 130.0, 0); //khung goc ben phai tren

		pDrawButton(31357, gui->X, (gui->Y + gui->Height) - 45.0, 60.0, 45.0, 0, 0); //khung goc ben trai duoi
		pDrawButton(31357, (gui->X + gui->Width) - 60.0, (gui->Y + gui->Height) - 45.0, 60.0, 45.0, 130.0, 0); //khung goc ben phai duoi

		int CloseX = gui->X + gui->Width - 33.0f;
		int CloseY = gui->Y;
		pDrawGUI(0x7EC5, CloseX, CloseY, 36.0f, 29.0f);
		if (pCheckMouseOver(CloseX, CloseY, 36, 36) == 1)
		{
			if (gInterface.IsWorkZone69(CloseX, CloseY, 36, 36) && pIsKeyRelease(VK_LBUTTON))
			{
				gui->onShow ^= 1;
				//gInterface.Data[eNumWindow].OnShow ^= 1;
			}

			pDrawColorButton(0x7EC5, CloseX, CloseY, 36, 29, 0, 0, pMakeColor(255, 204, 20, 130));
			gInterface.DrawToolTip(pCursorX + 20, pCursorY, "Close");
		}

		CustomFont.Draw((HFONT)pFontBold, gui->X, gui->Y + 7, 0xFFAE00FF, 0x0, gui->Width, tS.resize_height, 3, Buff);

		pGLSwitch();
		EnableAlphaTest(0);
	}


	return this->IsWorkZone(gui->X, gui->Y, gui->Width, gui->Height);

}
//bool CNewUIWindowsClient::DrawWindowBG(GUIObj* gui, LPCSTR Text, ...) {
//	static float v1;
//	static float v2;
//	static float v3;
//	static float v4;
//	static float v5;
//	static float v6;
//	static float v7;
//	static float v8;
//	static float v9;
//	static float v10;
//
//	//
//
//
//	char Buff[2048];
//	int BuffLen = sizeof(Buff) - 1;
//	ZeroMemory(Buff, BuffLen);
//	// ----
//	va_list args;
//	va_start(args, Text);
//	int Len = vsprintf_s(Buff, BuffLen, Text, args);
//	va_end(args);
//
//	textSize tS = nInterface.getTextSize(Buff);
//
//
//	if (GetKeyState(VK_LBUTTON) & 0x8000) {
//
//		if (this->IsWorkZone(gui->X, gui->Y, gui->Width, v3)) {
//			if (!gui->dragging) {
//				gui->dragging = true;
//				gui->curX = pCursorX;
//				gui->curY = pCursorY;
//			}
//		}
//		if (gui->dragging) {
//			gui->X += pCursorX - gui->curX;
//			gui->Y += pCursorY - gui->curY;
//			gui->curX = pCursorX;
//			gui->curY = pCursorY;
//			gui->Max_X = gui->X + gui->Width;
//			gui->Max_Y = gui->Y + gui->Height;
//		}
//	}
//	else {
//		if (gui->dragging) {
//			gui->dragging = false;
//		}
//	}
//
//	v1 = (1024 / gui->Width) / pWinWidthReal;
//	v2 = (1024 / gui->Height) / pWinHeightReal;
//	v3 = gui->Height / 1024 * 130;
//	v4 = gui->Y + v3 - tS.resize_height - 3 * pWinHeightReal;
//
//
//
//	nInterface.DrawFrame(0xF1007, gui->X, gui->Y, 1024, 1024, 0, 0, 1024, 1024, v1, v2, 0);
//	
//	g_pRenderText.SetFont(g_hFontBold);
//	g_pRenderText.SetBgColor(0);
//	g_pRenderText.SetTextColor(eWhite180);
//	g_pRenderText.RenderText(gui->X, v4 - 2, Buff, gui->Width, tS.resize_height, RT3_SORT_CENTER); // NHẬN QUÀ HÀNG NGÀY
//	//
//	//CustomFont.Draw(HFONT(g_hFontBold), gui->X, v4 + 5, 0xffffffff, 0x0, gui->Width, tS.resize_height, 3, Buff);
//
//	return this->IsWorkZone(gui->X, gui->Y, gui->Width, gui->Height);
//
//
//}

bool CNewUIWindowsClient::IsWorkZone(float a1, float a2, float a3, float a4) {
	return pCursorX <= (a1 + a3) && pCursorX >= a1 && pCursorY <= (a2 + a4) && pCursorY >= a2;
}
void CNewUIWindowsClient::DrawToolTipBG(float a1, float a2, float a3, float a4) {
	float v0 = this->resizeX(8);
	float v1 = v0 / resizeGuiRate;
	float v2 = a3 - v1 * 2;
	float v3 = this->resizeY(7);
	float v4 = this->resizeY(6);
	float v5 = a4 - v3 / resizeGuiRate;
	float wRatio = (v2 / v0) * resizeGuiRate;
	float hRatio = (v5 / v4) * resizeGuiRate;
	//left corner top
	this->DrawGui(eToolTip_ID, a1, a2, 8, 7, 20, 0, 128, 8, 1.5, 1.5);
	//center top
	this->DrawGui(eToolTip_ID, a1 + v1, a2, 8, 7, 10, 0, 128, 8, 1.5 / wRatio, 1.5);
	//right corner top
	//not correctly yet
	this->DrawGui(eToolTip_ID, a1 + this->resizeX(8 + v2 * resizeGuiRateX) / resizeGuiRate, a2, 8, 7, 0, 0, 128, 8, 1.5, 1.5);

	//left body
	this->DrawGui(eToolTip_ID, a1, a2 + v3 / resizeGuiRate, 8, 6, 80, 1, 128, 8, 1.5, 1.5 / hRatio);
	//center body
	this->DrawGui(eToolTip_ID, a1 + v1, a2 + v3 / resizeGuiRate, 8, 6, 70, 1, 128, 8, 1.5 / wRatio, 1.5 / hRatio);
	//right body
	this->DrawGui(eToolTip_ID, a1 + this->resizeX(8 + v2 * resizeGuiRateX) / resizeGuiRate, a2 + v3 / resizeGuiRate, 8, 6, 60, 1, 128, 8, 1.5, 1.5 / hRatio);

	//left corner bottom
	this->DrawGui(eToolTip_ID, a1, a2 + a4, 8, 7, 50, 1, 128, 8, 1.5, 1.5);
	//center body
	this->DrawGui(eToolTip_ID, a1 + v1, a2 + a4, 8, 7, 40, 1, 128, 8, 1.5 / wRatio, 1.5);
	//right corner bottom
	this->DrawGui(eToolTip_ID, a1 + this->resizeX(8 + v2 * resizeGuiRateX) / resizeGuiRate, a2 + a4, 8, 7, 30, 1, 128, 8, 1.5, 1.5);
}

void CNewUIWindowsClient::DrawToolTipKG(float x, float y, float w, float h, HFONT font, DWORD color, LPCSTR text, ...) {
	char Buff[2048];
	int BuffLen = sizeof(Buff);
	ZeroMemory(Buff, BuffLen);
	va_list args;
	va_start(args, text);
	int Len = vsprintf_s(Buff, BuffLen, text, args);
	va_end(args);
	nInterface.DrawToolTipBG(x, y, w, h);
	CustomFont.Draw(font, x + 10, y + 3, color, 0x0, w, h, 0, Buff);
}

void CNewUIWindowsClient::DrawToolTipKG_bar(float x, float y, float w, float h, HFONT font, DWORD color, LPCSTR text, ...) {
	char Buff[2048];
	int BuffLen = sizeof(Buff);
	ZeroMemory(Buff, BuffLen);
	va_list args;
	va_start(args, text);
	int Len = vsprintf_s(Buff, BuffLen, text, args);
	va_end(args);
	nInterface.DrawToolTipBG(x, y, w, h);
	CustomFont.Draw(font, x + 18, y + 3, color, 0x0, w, h, 0, Buff);
}

textSize CNewUIWindowsClient::getTextSize(char* a1)
{
	textSize res;
	struct tagSIZE psizl;
	sub_401C10();
	sub_9593B0((HDC)sub_41FF80(pTextThis()), a1, lstrlenA(a1), &psizl);

	if (pCheckWindow(pWindowThis(), 57) == 1)
		res.resize_height = (float)psizl.cy / (*(float*)0xE7C3D8 / 1.3);
	else
		res.resize_height = (float)psizl.cy / (*(float*)0xE7C3D8 / 1.1);
	res.width = (float)psizl.cx / *(float*)0xE7C3D4;
	res.height = (float)psizl.cy;
	res.resize_width = (float)psizl.cx / *(float*)0xE7C3D4;
	return res;
}

void CNewUIWindowsClient::UpdatePosition(position* pos, float a2, float a3, float a4, float a5)
{
	if (a2)
		pos->X = a2;
	if (a3)
		pos->Y = a3;
	if (a4)
		pos->Width = a4;
	if (a5)
		pos->Height = a5;
	pos->Max_X = pos->X + pos->Width;
	pos->Max_Y = pos->Y + pos->Height;
}

bool CNewUIWindowsClient::DrawAnimation(GUIAnimation* gui, float a2, float a3, float a4, float a5)
{
	float v1;
	float v2;
	float v3;
	float v4;

	this->UpdatePosition(gui->pos, a2, a3, a4, a5);

	if (gui->step + 1 > gui->maxStep)
		gui->step = 0;

	BYTE cellX = gui->step % (int)(gui->Resource->SourceHeight / gui->Resource->CellHeight);
	BYTE cellY = (gui->step - cellX) / (gui->Resource->SourceWidth / gui->Resource->CellWidth);


	v1 = cellX * gui->Resource->CellWidth; //resource X
	v2 = cellY * gui->Resource->CellHeight; //resource Y
	v3 = pWinWidthReal; //scale X;
	v4 = pWinHeightReal; //scale Y;

	this->DrawFrame(gui->Resource->ID, gui->pos->X, gui->pos->Y, gui->pos->Width, gui->pos->Height, v1, v2, 1024, 512, v3, v4);

	//---
	if (gui->lastActionTime <= GetTickCount())
	{
		gui->step++;
		gui->lastActionTime = GetTickCount() + gui->delay;
	}
	return false;
}

bool CNewUIWindowsClient::DrawBG(DWORD ModelID, float X, float Y, float W, float H, float rW, float rH, float sX, float sY, float sW, float sH)
{
	float v1;
	float v2;
	float v3;
	float v4;
	v1 = (W * scale_ratio) / rW;
	v2 = (H * scale_ratio) / rH;
	v3 = scale_width / v1;
	v4 = scale_height / v2;

	this->DrawGui(ModelID, X, Y, rW, rH, sX, sY, sW, sH, v3, v4);
	return true;
}

std::string commify(unsigned long long n, char c)
{
	std::string s;
	int cnt = 0;
	do
	{
		s.insert(0, 1, char('0' + n % 10));
		n /= 10;
		if (++cnt == 3 && n)
		{
			s.insert(0, 1, c);
			cnt = 0;
		}
	} while (n);
	return s;
}


const char* CNewUIWindowsClient::NumberFormat(float Number) {
	std::stringstream stream;
	stream << std::fixed << std::setprecision(2) << Number;
	return stream.str().c_str();
}

char* CNewUIWindowsClient::NumberFormat(int Number) {


	if (Number < 0) { return "0"; }

	char OutPut[15];

	if (Number < 1000) {
		sprintf(OutPut, "%d", Number);
		return strdup(OutPut);
	}
	else if (Number < 1000000) {
		int part1 = Number % 1000;
		int part2 = (Number - part1) / 1000;
		sprintf(OutPut, "%d,%03d", part2, part1);
		return strdup(OutPut);
	}
	else if (Number < 1000000000) {
		int part1 = Number % 1000;
		Number = (Number - part1) / 1000;
		int part2 = Number % 1000;
		Number = (Number - part2) / 1000;
		int part3 = Number % 1000;

		sprintf(OutPut, "%d,%03d,%03d", part3, part2, part1);
		return strdup(OutPut);
	}
	else {
		int part1 = Number % 1000;
		Number = (Number - part1) / 1000;
		int part2 = Number % 1000;
		Number = (Number - part2) / 1000;
		int part3 = Number % 1000;
		int part4 = (Number - part3) / 1000;

		sprintf(OutPut, "%d,%03d,%03d,%03d", part4, part3, part2, part1);
		return strdup(OutPut);
	}
	return "0";
}


char* CNewUIWindowsClient::NumberFormat(DWORD Number) {


	if (Number < 0) { return "0"; }

	char OutPut[15];

	if (Number < 1000) {
		sprintf(OutPut, "%u", Number);
		return strdup(OutPut);
	}
	else if (Number < 1000000) {
		int part1 = Number % 1000;
		int part2 = (Number - part1) / 1000;
		sprintf(OutPut, "%u,%03u", part2, part1);
		return strdup(OutPut);
	}
	else if (Number < 1000000000) {
		int part1 = Number % 1000;
		Number = (Number - part1) / 1000;
		int part2 = Number % 1000;
		Number = (Number - part2) / 1000;
		int part3 = Number % 1000;

		sprintf(OutPut, "%u,%03u,%03u", part3, part2, part1);
		return strdup(OutPut);
	}
	else {
		int part1 = Number % 1000;
		Number = (Number - part1) / 1000;
		int part2 = Number % 1000;
		Number = (Number - part2) / 1000;
		int part3 = Number % 1000;
		int part4 = (Number - part3) / 1000;

		sprintf(OutPut, "%u,%03u,%03u,%03u", part4, part3, part2, part1);
		return strdup(OutPut);
	}
	return "0";
}


bool CNewUIWindowsClient::Drawbutton(GUIbutton* gui, float X, float Y, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen = sizeof(Buff)-1;
	ZeroMemory(Buff, BuffLen);
	// ----
	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);

	gui->data->X = X;
	gui->data->Y = Y;
	gui->data->Max_X = gui->data->X + gui->data->Width;
	gui->data->Max_Y = gui->data->Y + gui->data->Height;
	return this->Drawbutton(gui, Buff);
}

bool CNewUIWindowsClient::Drawbutton(GUIbutton* gui, LPCSTR Text, ...)
{
	static float v1;
	static float v2;
	static float v3;
	static float v4;
	static float v5;
	static float v6;
	static float v7;
	static float v8;
	static float v9;
	static float v10;
	bool res = false;


	bool hoving = this->IsWorkZone(gui->data->X, gui->data->Y, gui->data->Width, gui->data->Height);

	v1 = gui->normalFrame->ScaleX ? gui->normalFrame->ScaleX / pWinWidthReal : pWinWidthReal;
	v2 = gui->normalFrame->ScaleY ? gui->normalFrame->ScaleY / pWinWidthReal : pWinWidthReal;

	v3 = gui->hoverFrame->ScaleX ? gui->hoverFrame->ScaleX / pWinWidthReal : pWinWidthReal;
	v4 = gui->hoverFrame->ScaleY ? gui->hoverFrame->ScaleY / pWinWidthReal : pWinWidthReal;

	v5 = gui->clickedFrame->ScaleX ? gui->clickedFrame->ScaleX / pWinWidthReal : pWinWidthReal;
	v6 = gui->clickedFrame->ScaleY ? gui->clickedFrame->ScaleY / pWinWidthReal : pWinWidthReal;

	char Buff[2048];
	int BuffLen = sizeof(Buff)-1;
	ZeroMemory(Buff, BuffLen);
	// ----
	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);

	textSize tS = nInterface.getTextSize(Buff);


	//CustomFont.Draw(CustomFont.FontNormal, gui->data->X, gui->data->Y, 0xffffffff, 0xff000055, gui->data->Width, gui->data->Height, 0, " ");
	if (gui->data->state == 4)
	{
		nInterface.DrawFrame(gui->disabledFrame->ID, gui->data->X, gui->data->Y, gui->disabledFrame->CellWidth, gui->disabledFrame->CellHeight,
			gui->disabledFrame->SourceX, gui->disabledFrame->SourceY, gui->disabledFrame->SourceWidth, gui->disabledFrame->SourceHeight, v3, v4);


		v5 = gui->data->Y + (gui->data->Height - tS.resize_height) / 2;
		CustomFont.Draw(CustomFont.FontNormal, gui->data->X, v5 + 1, gui->disabledFrame->TextColor, gui->disabledFrame->TextBGColor, gui->data->Width, tS.resize_height, 3, Buff);

		return res;
	}
	if (hoving) {
		if (GetKeyState(VK_LBUTTON) & 0x8000) { //clicked
			if (gui->data->lastActionTime + gui->data->delay <= GetTickCount() && !gui->data->clickDown) {
				gui->data->clickDown = true;
				gui->data->lastActionTime = GetTickCount();
			}
			nInterface.DrawFrame(gui->clickedFrame->ID, gui->data->X, gui->data->Y, gui->clickedFrame->CellWidth, gui->clickedFrame->CellHeight,
				gui->clickedFrame->SourceX, gui->clickedFrame->SourceY, gui->clickedFrame->SourceWidth, gui->clickedFrame->SourceHeight, v5, v6);

			v5 = gui->data->Y + (gui->data->Height - tS.resize_height) / 2;
			CustomFont.Draw(CustomFont.FontNormal, gui->data->X, v5 + 1, gui->clickedFrame->TextColor, gui->clickedFrame->TextBGColor, gui->data->Width, tS.resize_height, 3, Buff);
		}
		else { //hoving
			if (gui->data->clickDown) {
				gui->data->state = !gui->data->state;
				res = true;
				gui->data->clickDown = false;
			}
			nInterface.DrawFrame(gui->hoverFrame->ID, gui->data->X, gui->data->Y, gui->hoverFrame->CellWidth, gui->hoverFrame->CellHeight,
				gui->hoverFrame->SourceX, gui->hoverFrame->SourceY, gui->hoverFrame->SourceWidth, gui->hoverFrame->SourceHeight, v3, v4);

			v5 = gui->data->Y + (gui->data->Height - tS.resize_height) / 2;
			CustomFont.Draw(CustomFont.FontNormal, gui->data->X, v5 + 1, gui->hoverFrame->TextColor, gui->hoverFrame->TextBGColor, gui->data->Width, tS.resize_height, 3, Buff);
		}
	}
	else //normal
	{

		nInterface.DrawFrame(gui->normalFrame->ID, gui->data->X, gui->data->Y, gui->normalFrame->CellWidth, gui->normalFrame->CellHeight,
			gui->normalFrame->SourceX, gui->normalFrame->SourceY, gui->normalFrame->SourceWidth, gui->normalFrame->SourceHeight, v1, v2);

		v5 = gui->data->Y + (gui->data->Height - tS.resize_height) / 2;
		CustomFont.Draw(CustomFont.FontNormal, gui->data->X, v5 + 1, gui->normalFrame->TextColor, gui->normalFrame->TextBGColor, gui->data->Width, tS.resize_height, 3, Buff);
	}


	return res;
}
