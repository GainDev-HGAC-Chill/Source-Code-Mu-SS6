#include "stdafx.h"
#include "CBUtil.h"
#include "Util.h"
#include "Interface.h"
#include "Import.h"
#include "Defines.h"
#include "Protect.h"
#include "TMemory.h"
#include "WindowsStruct.h"
#include  "UITextInputBox.h"
CBUtil gCBUtil;
CBUtil::CBUtil()
{
	//===Lock Mouse Click
	SetOp((LPVOID)0x004D935C, (LPVOID)CBUtil::CheckMouseUse, ASM::CALL);
	SetOp((LPVOID)0x005B67B9, (LPVOID)CBUtil::CheckMouseUse, ASM::CALL);
	SetOp((LPVOID)0x005B832F, (LPVOID)CBUtil::CheckMouseUse, ASM::CALL);
	SetOp((LPVOID)0x005CF380, (LPVOID)CBUtil::CheckMouseUse, ASM::CALL);
	this->DelayMouseLock = 0;
	gCBUtil.LockButtonHover = 0;
	gCBUtil.LockScrollMouse = 0;
	this->vCaptcha = this->generateCaptcha(4);
}


CBUtil::~CBUtil()
{

}

bool  CBUtil::CheckMouseUse(int ThisA)
{
	if (gCBUtil.DelayMouseLock > 0)
	{
		gCBUtil.DelayMouseLock--;
		return 1;
	}
	return ((bool(__thiscall*)(int ThisA)) 0x00860A60)(ThisA);
}
void CBUtil::DrawFrame(DWORD ModelID, float X, float Y, float W, float H, float SourceX, float SourceY, float SourceW, float SourceH, float ScaleW, float ScaleH, bool ScaleUp) {
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
	((void(__cdecl*)(DWORD ModelID, float PosX, float PosY, float Width, float Height, float SourceX, float SourceY, float ScaleX, float ScaleY, bool Scale, bool Arg11, float Arg12)) 0x637C60)(ModelID, X, Y, W, H, SourceX / SourceW, SourceY / SourceH, v1, v2, ScaleUp, 1, 0.0);
}

int CBUtil::DrawText(HFONT font, int PosX, int PosY, DWORD color, DWORD bkcolor, int Width, int Height, BYTE Align, LPCTSTR Text, ...)
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
		((int(__thiscall*)(LPVOID This, HFONT a2)) 0x00420120)(((LPVOID(*)()) 0x0041FE10)(), font);
		((void(__thiscall*)(LPVOID This, int r, int g, int b, int h)) 0x00420040)(((LPVOID(*)()) 0x0041FE10)(), (color & 0xff000000) >> 24, (color & 0x00ff0000) >> 16, (color & 0x0000ff00) >> 8, color & 0x000000ff);
		((void(__thiscall*)(LPVOID This, int r, int g, int b, int h)) 0x004200B0)(((LPVOID(*)()) 0x0041FE10)(), (bkcolor & 0xff000000) >> 24, (bkcolor & 0x00ff0000) >> 16, (bkcolor & 0x0000ff00) >> 8, bkcolor & 0x000000ff);
		((int(__thiscall*)(LPVOID This, int PosX, int PosY, LPCTSTR Text, int Width, int Height, LPINT Align, int unknow)) 0x00420150)(((LPVOID(*)()) 0x0041FE10)(), PosX, PosY, Line, Width, Height, (LPINT)Align, 0);
		PosY += 10;
		Line = strtok(NULL, "\n");
		LineCount++;
	}
	return LineCount;
}
void CBUtil::MoveWindows(int eNumWindow)
{
	if (GetKeyState(VK_LBUTTON) & 0x8000 && GetTickCount() - gInterface.Data[eNumWindow].EventTick > 300)
	{
		if (pCheckMouseOver(gInterface.Data[eNumWindow].X, gInterface.Data[eNumWindow].Y, gInterface.Data[eNumWindow].Width - 70, 30))
		{
			if (!gInterface.Data[eNumWindow].OnClick) {
				gInterface.Data[eNumWindow].OnClick = true;
				gInterface.Data[eNumWindow].curX = pCursorX;
				gInterface.Data[eNumWindow].curY = pCursorY;
			}
		}
		if (gInterface.Data[eNumWindow].OnClick)
		{
			gInterface.Data[eNumWindow].X += pCursorX - gInterface.Data[eNumWindow].curX;
			gInterface.Data[eNumWindow].Y += pCursorY - gInterface.Data[eNumWindow].curY;
			gInterface.Data[eNumWindow].curX = pCursorX;
			gInterface.Data[eNumWindow].curY = pCursorY;
			//===
			if (gInterface.Data[eNumWindow].X < 0)
				gInterface.Data[eNumWindow].X = 0;
			if (gInterface.Data[eNumWindow].Y < 0)
				gInterface.Data[eNumWindow].Y = 0;

			if ((gInterface.Data[eNumWindow].X + gInterface.Data[eNumWindow].Width) > MAX_WIN_WIDTH)
				gInterface.Data[eNumWindow].X = MAX_WIN_WIDTH - (gInterface.Data[eNumWindow].Width);
			if ((gInterface.Data[eNumWindow].Y + gInterface.Data[eNumWindow].Height + 46) > MAX_WIN_HEIGHT)
				gInterface.Data[eNumWindow].Y = MAX_WIN_HEIGHT - (gInterface.Data[eNumWindow].Height + 46);
		}
	}
	else {
		if (gInterface.Data[eNumWindow].OnClick)
		{
			gInterface.Data[eNumWindow].OnClick = false;
		}
	}
	//if (pCheckMouseOver(gInterface.Data[eNumWindow].X, gInterface.Data[eNumWindow].Y, gInterface.Data[eNumWindow].Width-50, 35) && *(bool*)0x8793386)
	//{
	//	gInterface.Data[eNumWindow].OnClick = 1;
	//	gInterface.Data[eNumWindow].curX = pCursorX;
	//	gInterface.Data[eNumWindow].curY = pCursorY;
	//}
	//else
	//{
	//	gInterface.Data[eNumWindow].OnClick = 0;
	//}

	//if (gInterface.Data[eNumWindow].OnClick == 1)
	//{
	//	gInterface.Data[eNumWindow].X += pCursorX - gInterface.Data[eNumWindow].curX;
	//	gInterface.Data[eNumWindow].Y += pCursorY - gInterface.Data[eNumWindow].curY;
	//	gInterface.Data[eNumWindow].curX = pCursorX;
	//	gInterface.Data[eNumWindow].curY = pCursorY;
	//}
}

bool CBUtil::gDrawWindowCustom(float* StartX, float* StartY, float CuaSoW, float CuaSoH, int eNumWindow, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen = sizeof(Buff)-1;
	ZeroMemory(Buff, BuffLen);
	// ----
	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);

	if (!gInterface.Data[eNumWindow].OnShow)
	{
		return 1;
	}
	if (!gInterface.Data[eNumWindow].FirstLoad)
	{
		gInterface.Data[eNumWindow].Width = CuaSoW;
		gInterface.Data[eNumWindow].Height = CuaSoH;
		gInterface.Data[eNumWindow].X = *StartX;
		gInterface.Data[eNumWindow].Y = *StartY;
		gInterface.Data[eNumWindow].FirstLoad = true;
	}
	else
	{
		(*StartX) = gInterface.Data[eNumWindow].X;
		(*StartY) = gInterface.Data[eNumWindow].Y;
	}
	MoveWindows(eNumWindow);
	if (pCheckMouseOver(gInterface.Data[eNumWindow].X, gInterface.Data[eNumWindow].Y, CuaSoW, CuaSoH) == 1)
	{
		gCBUtil.DelayMouseLock = 30;
		gInterface.Data[eNumWindow].Hover = true;
	}
	else
	{
		gInterface.Data[eNumWindow].Hover = false;
	}
	float ScaleW = (225 / CuaSoW) / pWinWidthReal;
	float ScaleH = (225 / CuaSoH) / pWinHeightReal;

	pSetBlend(true);
	glColor3f(1.0, 1.0, 1.0);
	if (gProtect.m_MainInfo.CustomInterfaceType == 3)
	{

		//RenderBitmap(61538, StartX, StartY, CuaSoW, 46, 0, 0, 340.f /426.f, 38.f / 422.f, 1, 1, 0);
		RenderBitmap(71526, gInterface.Data[eNumWindow].X - 3, gInterface.Data[eNumWindow].Y - 17, CuaSoW, 46, 0, 0, 200.f / 324.f, 50.f / 677.f, 1, 1, 0); //Title
		RenderBitmap(71526, gInterface.Data[eNumWindow].X - 3, gInterface.Data[eNumWindow].Y + 29, CuaSoW, CuaSoH, 0, 50.f / 677.f, 200.f / 324.f, 395.f / 677.f, 1, 1, 0); //Frame



		if (pCheckMouseOver(Return2X(TransForX((gInterface.Data[eNumWindow].X - 3 + CuaSoW) - 40)), Return2X(TransForY(gInterface.Data[eNumWindow].Y + 7)), Return2X(TransForX(13)), Return2X(TransForX(13))))
		{
			if ((GetKeyState(VK_LBUTTON) & 0x8000) && GetTickCount() - gInterface.Data[eNumWindow].EventTick > 300)
			{

				PlayBuffer(25, 0, 0);
				glColor3f(1.0f, 0.0f, 0.0f);
				gCBUtil.DelayMouseLock = 30;
				gInterface.Data[eNumWindow].Close();
				gInterface.Data[eNumWindow].EventTick = GetTickCount();


			}
			RenderBitmap(71529, TransForX((gInterface.Data[eNumWindow].X - 3 + CuaSoW) - 40), TransForY(gInterface.Data[eNumWindow].Y + 7), TransForX(13), TransForY(13), 0.0, 0.0, 0.6535385251, 0.1583384364, 0, 0, 0);
		}
		else
		{
			RenderBitmap(71529, TransForX((gInterface.Data[eNumWindow].X - 3 + CuaSoW) - 40), TransForY(gInterface.Data[eNumWindow].Y + 7), TransForX(13), TransForY(13), 0.0, 0.3306768537, 0.6535385251, 0.1583384364, 0, 0, 0);
		}
	}
	else
	{
		this->DrawFrame(31322, gInterface.Data[eNumWindow].X, gInterface.Data[eNumWindow].Y, 225, 225, 0.0, 0.0, 270, 225, ScaleW, ScaleH); //khung goc ben trai tren

		//==== NGang Tren va Duoi
		for (int i = gInterface.Data[eNumWindow].X + 10; i < (gInterface.Data[eNumWindow].X + CuaSoW) - 10; i += 10)
		{
			pDrawButton(31353, i, gInterface.Data[eNumWindow].Y, 10.0, 64.0, 60.0, 0); //khung goc ben trai tren
			pDrawButton(31357, i, (gInterface.Data[eNumWindow].Y + CuaSoH) - 45.0, 10.0, 45.0, 60.0, 0); //khung goc ben trai tren
		}

		//=== Nen va thanh doc 2 trai phai
		for (int doc = gInterface.Data[eNumWindow].Y + 10; doc < (gInterface.Data[eNumWindow].Y + CuaSoH) - 10; doc += 10)
		{
			pDrawButton(31355, gInterface.Data[eNumWindow].X, doc, 21.0, 10, 0, 0); //Khung giua ben trai
			pDrawButton(31356, (gInterface.Data[eNumWindow].X + CuaSoW) - 21.0, doc, 21.0, 10, 0, 0); //Khung giua ben phai
		}
		pDrawButton(31353, gInterface.Data[eNumWindow].X, gInterface.Data[eNumWindow].Y, 60.0, 64.0, 0, 0); //khung goc ben trai tren
		pDrawButton(31353, (gInterface.Data[eNumWindow].X + CuaSoW) - 60.0, gInterface.Data[eNumWindow].Y, 60.0, 64.0, 130.0, 0); //khung goc ben phai tren

		pDrawButton(31357, gInterface.Data[eNumWindow].X, (gInterface.Data[eNumWindow].Y + CuaSoH) - 45.0, 60.0, 45.0, 0, 0); //khung goc ben trai duoi
		pDrawButton(31357, (gInterface.Data[eNumWindow].X + CuaSoW) - 60.0, (gInterface.Data[eNumWindow].Y + CuaSoH) - 45.0, 60.0, 45.0, 130.0, 0); //khung goc ben phai duoi
		//======Close
		int CloseX = gInterface.Data[eNumWindow].X + CuaSoW - 33.0f;
		int CloseY = gInterface.Data[eNumWindow].Y;
		pDrawGUI(0x7EC5, CloseX, CloseY, 36.0f, 29.0f);
		if (pCheckMouseOver(CloseX, CloseY, 36, 36) == 1)
		{
			if ((GetKeyState(VK_LBUTTON) & 0x8000) && GetTickCount() - gInterface.Data[eNumWindow].EventTick > 300)
			{

				((signed int(__cdecl*)(int a1, int a2, int a3)) 0x006D6C20)(25, 0, 0);
				glColor3f(1.0f, 0.0f, 0.0f);
				gCBUtil.DelayMouseLock = 30;
				gInterface.Data[eNumWindow].Close();
				gInterface.Data[eNumWindow].EventTick = GetTickCount();

			}
			pDrawColorButton(0x7EC5, CloseX, CloseY, 36, 29, 0, 0, pMakeColor(255, 204, 20, 130));
			gInterface.DrawToolTip(pCursorX + 20, pCursorY, "Close");
		}
		//================================================
	}


	//HFONT FontText = CreateFontA(15, 0, 0, 0, 400, 0, 0, 0, 0x1, 0, 0, 3u, 0, "Arial");
	this->DrawText((HFONT)pFontBold, gInterface.Data[eNumWindow].X, gInterface.Data[eNumWindow].Y + 10, 0xB8E600FF, 0x0, CuaSoW, 0, 3, Buff); //Buoc Vao
	//gInterface.DrawFormat(eShinyGreen, StartX, StartY + 7, CuaSoW, 3, WindowName);
	//DeleteObject(FontText),
	pGLSwitch();
	EnableAlphaTest(0);
	return 0;
}


void CBUtil::gInfoBox(float PosX, float PosY, float Width, float Height, DWORD bkcolor, float bAlpha, int Arg6)
{
	float Red = (float)((bkcolor & 0xff000000) >> 24) / 255.0f;
	float Green = (float)((bkcolor & 0x00ff0000) >> 16) / 255.0f;
	float Blue = (float)((bkcolor & 0x0000ff00) >> 8) / 255.0f;
	float Alpha = (float)(bkcolor & 0x000000ff) / 255.0f;
	if (bAlpha > 0) { Alpha -= (bAlpha / 255.0f); }
	pSetBlend(1);
	if (bkcolor)
	{
		glColor4f(Red, Green, Blue, Alpha);
		pDrawBarForm(PosX, PosY, Width + 6.5, Height + 5, 0, Arg6); //central
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

//----- (1003C1B0) --------------------------------------------------------
void CBUtil::gItemBoxInv(int X, int Y, int Doc, int Ngang, int Use)
{
	float v6; // [esp+0h] [ebp-34h]
	float v7; // [esp+4h] [ebp-30h]
	GLfloat red; // [esp+8h] [ebp-2Ch]
	GLfloat green; // [esp+Ch] [ebp-28h]
	int j; // [esp+2Ch] [ebp-8h]
	int i; // [esp+30h] [ebp-4h]

	for (i = 0; i < Doc; ++i)
	{
		for (j = 0; j < Ngang; ++j)
		{
			pSetBlend(1);
			if (Use)
			{
				//glColor4f(1.0, 0.69999999, 0.0, 0.60000002);
				glColor4f(0.30000001, 0.5, 0.5, 0.60000002);
			}
			else
			{
				glColor4f(0.3, 0.3, 0.3, 0.60000002);
			}
			v7 = (float)(Y + 20 * i);
			v6 = (float)(X + 20 * j);
			pDrawBarForm(LODWORD(v6), LODWORD(v7), 20.0, 20.0, 0.0, 0);
			pSetBlend(true);
			glColor3f(1.0, 1.0, 1.0);
			green = (float)(Y + 20 * i);
			red = (float)(X + 20 * j);
			pDrawGUI(31339, LODWORD(red), LODWORD(green), 21.0, 21.0);
			pGLSwitch();
			EnableAlphaTest(0);
		}
	}
}


//----- (1000CFF0) --------------------------------------------------------
void CBUtil::RenderMixEffect(int type, int x, int y)
{
	int result; // eax
	float v4; // [esp+28h] [ebp-48h]
	float v5; // [esp+30h] [ebp-40h]
	GLfloat red; // [esp+44h] [ebp-2Ch]
	GLfloat green; // [esp+4Ch] [ebp-24h]
	float v8; // [esp+58h] [ebp-18h]
	float v9; // [esp+5Ch] [ebp-14h]
	float v10; // [esp+60h] [ebp-10h]
	float v11; // [esp+64h] [ebp-Ch]
	int j; // [esp+68h] [ebp-8h]
	int i; // [esp+6Ch] [ebp-4h]

	if (type > 0)
	{
		for (i = 1; i <= 4; ++i)
		{
			for (j = 1; j <= 2; ++j)
			{
				pSetBlend(1);
				pGLSwitchBlend();
				green = (double)(rand() % 4 + 4) * 0.1000000014901161;
				red = (double)(rand() % 6 + 6) * 0.1000000014901161;
				glColor3f(red, green, 0.2);
				v11 = (double)((int)0x5EF5A1C % 100) * 20.0;
				v8 = (double)(rand() % 10) + 5.0;
				v9 = (float)(x + rand() % (20 * j + 1));
				v10 = (float)(y + rand() % (20 * i + 1));
				((void(__cdecl*)(int x, float y, float w, float h, float giro, float a9, float a10, float a11, float a12, float a13))0x00637E80)(32113, LODWORD(v9), LODWORD(v10), LODWORD(v8), LODWORD(v8), 0.0, 0.0, 0.0, 1.0, 1.0);
				((void(__cdecl*)(int x, float y, float w, float h, float giro, float a9, float a10, float a11, float a12, float a13))0x00637E80)(32113, LODWORD(v9), LODWORD(v10), LODWORD(v8), LODWORD(v8), LODWORD(v11), 0.0, 0.0, 1.0, 1.0);
				v5 = v8 * 3.0;
				((void(__cdecl*)(int x, float y, float w, float h, float giro, float a9, float a10, float a11, float a12, float a13))0x00637E80)(32114, LODWORD(v9), LODWORD(v10), LODWORD(v5), LODWORD(v5), LODWORD(v11), 0.0, 0.0, 1.0, 1.0);
				v4 = v8 * 6.0;
				((void(__cdecl*)(int x, float y, float w, float h, float giro, float a9, float a10, float a11, float a12, float a13))0x00637E80)(32002, LODWORD(v9), LODWORD(v10), LODWORD(v4), LODWORD(v4), 0.0, 0.0, 0.0, 1.0, 1.0);
				pGLSwitch();
				glColor4f(1.0, 1.0, 1.0, 1.0);
				pSetBlend(0);
			}
		}
	}
}

#include <iostream>
#include <sstream>
#include <iomanip>
#include <locale> // Để sử dụng std::numpunct
char* CBUtil::fNumberFormat(float number)
{
	std::ostringstream stream;
	stream.imbue(std::locale("")); // Để sử dụng định dạng hàng nghìn của ngôn ngữ hiện tại
	stream << std::fixed << std::setprecision(2) << number;
	std::string formattedNumber = stream.str();
	formattedNumber.erase(formattedNumber.find_last_not_of('0'), std::string::npos);
	return strdup(formattedNumber.c_str());
}

char* CBUtil::NumberFormat(int Number)
{


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


char* CBUtil::NumberFormat(DWORD Number)
{


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

bool CBUtil::gDrawButton(float PosX, float PosY, float SizeButton, int FontSize, char* ButtonText, float mSizeButtonW, bool IsEnter)
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
	float ScaleX = 0.0, ScaleY = 0.227;
	HFONT FontTextButton = CreateFontA(FontSize, 0, 0, 0, 700, 0, 0, 0, 0x1, 0, 0, 3u, 0, "Arial");
	//=====================Button 1
	if (pCheckMouseOver(StartX, StartY, SizeButtonW, SizeButtonH) == 1 && !gCBUtil.LockButtonHover)
	{
		gCBUtil.DelayMouseLock = 30;
		ScaleX = ScaleY;
		if (GetTickCount() - gInterface.Data[eTIME].EventTick > 500) //Click
		{
			if (GetKeyState(VK_LBUTTON) & 0x8000)
			{

				ScaleX = ScaleY * 2;
				gInterface.Data[eTIME].EventTick = GetTickCount();
				PlayBuffer(25, 0, 0);
				mreturn = true;
			}
		}
	}
	if ((GetKeyState(VK_RETURN) & 0x8000) && IsEnter)
	{
		gInterface.CloseWindow(ChatWindow);
		PlayBuffer(25, 0, 0);
		mreturn = true;

	}
	//31563
	//RenderBitmap(31563, StartX, StartY, SizeButtonW, SizeButtonH, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);
	if (gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		RenderBitmap(81524, StartX, StartY, SizeButtonW, SizeButtonH, 0.0, ScaleX, 0.830, ScaleY, 1, 1, 0);
	}
	else
	{
		RenderBitmap(31326, StartX, StartY, SizeButtonW, SizeButtonH, 0.0, ScaleX, 0.830, ScaleY, 1, 1, 0);
	}
	this->DrawText(FontTextButton, StartX, StartY + (SizeButtonH / 2) - (FontSize / 2.5), 0xE6FCF7FF, 0x0, SizeButtonW, 0, 3, ButtonText); //Buoc Vao
	//=====================================
	glColor3f(1.0f, 1.0f, 1.0f); //Xoa mau
	DeleteObject(FontTextButton);
	DeleteObject(ButtonText);
	pGLSwitch();
	EnableAlphaTest(0);
	return mreturn;
}

bool CBUtil::RenderCheckBox(float PosX, float PosY, DWORD TextColor, bool Checkis, LPCSTR Text, ...)
{
	bool mreturn = false;
	char Buff[2048];
	int BuffLen = sizeof(Buff)-1;
	ZeroMemory(Buff, BuffLen);
	// ----
	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);

	if (Checkis)
	{
		pDrawButton(31593, PosX, PosY, 15.0, 15.0, 0.0, 0.0);
	}
	else
	{
		pDrawButton(31593, PosX, PosY, 15.0, 15.0, 0.0, 15.0);
	}
	this->DrawText((HFONT)pFontBold, PosX + 20, PosY + 3, TextColor, 0x0, 0, 0, 1, Text);

	if (pCheckMouseOver(PosX, PosY, 15, 15) == 1)
	{
		if ((GetKeyState(VK_LBUTTON) & 0x8000) && GetTickCount() - gInterface.Data[eTIME].EventTick > 500)
		{
			gInterface.Data[eTIME].EventTick = GetTickCount();
			PlayBuffer(25, 0, 0);
			this->DelayMouseLock = 30;
			mreturn = true;
		}
	}
	return mreturn;
}

bool CBUtil::gDrawButtonGUI(int IDGUID, float PosX, float PosY, float SizeW, float SizeH, int TypeButton)
{
	bool mreturn = false;
	//=====================Button 1

	if (TypeButton == 3)
	{
		if (pCheckMouseOver(PosX, PosY, SizeW, SizeH) == 1)
		{
			this->DelayMouseLock = 30;

			if ((GetKeyState(VK_LBUTTON) & 0x8000) && GetTickCount() - gInterface.Data[eTIME].EventTick > 500 && !gCBUtil.LockButtonHover)
			{
				gInterface.Data[eTIME].EventTick = GetTickCount();
				PlayBuffer(25, 0, 0);
				mreturn = true;
				pDrawButton(IDGUID, PosX, PosY, SizeW, SizeH, 0.0, SizeH * 2);
			}
			else {
				pDrawButton(IDGUID, PosX, PosY, SizeW, SizeH, 0.0, SizeH * 1);
			}

		}
		else {
			pDrawButton(IDGUID, PosX, PosY, SizeW, SizeH, 0.0, 0.0);
		}
	}
	else if (TypeButton == 2)
	{
		if (pCheckMouseOver(PosX, PosY, SizeW, SizeH) == 1)
		{
			this->DelayMouseLock = 30;

			if ((GetKeyState(VK_LBUTTON) & 0x8000) && GetTickCount() - gInterface.Data[eTIME].EventTick > 500 && !gCBUtil.LockButtonHover)
			{
				gInterface.Data[eTIME].EventTick = GetTickCount();
				PlayBuffer(25, 0, 0);
				mreturn = true;
				pDrawButton(IDGUID, PosX, PosY, SizeW, SizeH, 0.0, SizeH * 1);
			}
			else {
				pDrawButton(IDGUID, PosX, PosY, SizeW, SizeH, 0.0, 0.0);
			}

		}
		else {
			pDrawButton(IDGUID, PosX, PosY, SizeW, SizeH, 0.0, 0.0);
		}
	}

	else
	{
		if (pCheckMouseOver(PosX, PosY, SizeW, SizeH) == 1)
		{
			this->DelayMouseLock = 30;
			if (GetTickCount() - gInterface.Data[eTIME].EventTick > 500 && !gCBUtil.LockButtonHover) //Click
			{
				if ((GetKeyState(VK_LBUTTON) & 0x8000))
				{
					gInterface.Data[eTIME].EventTick = GetTickCount();
					PlayBuffer(25, 0, 0);
					mreturn = true;
				}
			}
			pDrawColorButton(IDGUID, PosX, PosY, SizeW, SizeH, 0, 0, pMakeColor(255, 204, 20, 130));
		}
		else
		{
			pDrawGUI(IDGUID, PosX, PosY, SizeW, SizeH);
		}
	}

	return mreturn;
}
std::string CBUtil::generateCaptcha(int n)
{
	time_t t;
	srand((unsigned)time(&t));
	char* required_chars = "0123456789";
	std::string captcha = "";
	while (n--)
		captcha.push_back(required_chars[rand() % sizeof(required_chars)]);
	return captcha;
}
void CBUtil::DrawBarForm(float PosX, float PosY, float Width, float Height, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
	pSetBlend(true);
	glColor4f(red, green, blue, alpha);
	pDrawBarForm(PosX, PosY, Width, Height, 0.0f, 0);
	pGLSwitchBlend();
	pGLSwitch();
	glColor3f(1.0, 1.0, 1.0);
	pSetBlend(false);
}
bool CBUtil::check_Captcha(std::string& captcha, std::string& user_input)
{
	return captcha.compare(user_input) == 0;
}
void CBUtil::RenderCaptchaNumber(float PosX, float PosY, CUITextInputBox* a6, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen = sizeof(Buff)-1;
	ZeroMemory(Buff, BuffLen);
	// ----
	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);


	CBUtil::DrawBarForm(PosX, PosY + 3.5, 120, 17, 0.0, 0.0, 0.0, 1.0);
	CBUtil::DrawBarForm(PosX + 2, PosY + 4, 50, 15, 1.0, 0.2167, 0.0, 1.0);
	CBUtil::DrawText((HFONT)pFontBold, PosX + 2, PosY + 4 + 2, 0xFFFFFFB8, 0x0, 50, 0, 3, Buff); //Ma Xac Nhan
	a6->SetPosition(PosX + 60, PosY + 6.5);
	a6->Render();

	if (pCheckMouseOver(PosX - 5, PosY - 5, 120, 30) == 1)
	{

		if (GetKeyState(VK_LBUTTON) & 0x8000)
		{
			a6->GiveFocus(1);
			PlayBuffer(25, 0, 0);
		}
	}
	//gCentral.DrawStringInput(PosX + 60, PosY + 5, 50, 13, 3, a6, 0x57575750, 0x0, 0xFFFFFFFF);

}

int CBUtil::GetTimeGMT()
{
	time_t rawTime;
	struct tm* timeInfo;

	time(&rawTime);
	timeInfo = gmtime(&rawTime);

	timeInfo->tm_hour += 7;
	return mktime(timeInfo);
}


void CBUtil::BRenderTimeCountDown(float x, float y, float w, int MatchTime, int FontSize)
{
	if (MatchTime < 0) return;
	char lpszStr[256];
	char lpszStrS[10];
	int iMinute = MatchTime / 60;
	DWORD ColorText = 0xE6FCF7FF;
	wsprintf(lpszStr, " %.2d :", iMinute);

	int iSecondTime = MatchTime - (iMinute * 60);
	if (iSecondTime >= 0)
	{
		wsprintf(lpszStrS, " %.2d", iSecondTime);
		strcat(lpszStr, lpszStrS);
	}

	if (iMinute < 5)
	{
		ColorText = 0xFF2121FF;
	}
	if (iMinute < 15)
	{
		wsprintf(lpszStrS, ": %.2d", ((int)WorldTime % 60));
		strcat(lpszStr, lpszStrS);
	}
	HFONT FontTextTime = CreateFontA(FontSize, 0, 0, 0, 700, 0, 0, 0, 0x1, 0, 0, 3u, 0, "Arial");
	gCBUtil.DrawText(FontTextTime, x, y, ColorText, 0x0, w, 0, 3, lpszStr); //
	DeleteObject(FontTextTime);

}


void CBUtil::DrawItem3D(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int ExtOption, int Ancient, bool PickUp, float Scale, bool Center)
{
	float x = PosX;
	float y = PosY;

	if (ItemID >= ITEM(0, 0) && ItemID < ITEM(1, 0))
	{
		x = PosX - 10;
		if (ItemID == ITEM(0, 16) || ItemID == ITEM(0, 19)) {
			y = PosY + 30;
			//g_Console.AddMessage(1, "DrawItem3D %d", ItemID);
		}
		else if ((ItemID >= ITEM(0, 32) && ItemID <= ITEM(0, 35)) /*|| gCustomBattleGloves.CheckGloves(ItemID) == true*/) { y = PosY + 15; }
		else if (ItemID >= ITEM(0, 15) && ItemID < ITEM(0, 32)) { y = PosY + 25; }
		else if (ItemID > ITEM(0, 35)) { y = PosY + 20; }
		else if (ItemID == ITEM(0, 0)) { y = PosY + 30; }
		else { y = PosY + 20; }
	}
	else if (ItemID >= ITEM(3, 0) && ItemID < ITEM(4, 0))
	{
		y = PosY + 30;
	}
	else if (ItemID >= ITEM(7, 0) && ItemID < ITEM(8, 0)) { y = PosY + 25; }
	else if (ItemID >= ITEM(8, 0) && ItemID < ITEM(9, 0))
	{
		if ((ItemID >= ITEM(8, 2) && ItemID <= ITEM(8, 4))
			|| ItemID == ITEM(8, 7) || ItemID == ITEM(8, 8)
			|| ItemID == ITEM(8, 15))
		{
			y = PosY + 20;
		}
		else if (ItemID == ITEM(8, 34) || ItemID == ITEM(8, 35)) { y = PosY + 25; }
		else if (ItemID <= ITEM(8, 73)) { y = PosY + 25; }
		else if (ItemID > ITEM(8, 73)) { y = PosY + 35; }
	}
	else if (ItemID >= ITEM(9, 0) && ItemID < ITEM(12, 0)) { y = PosY + 25; }
	else if (ItemID >= 2048)
	{
		y = PosY + 25;

		if (ItemID == ITEM(12, 40)) { y = PosY + 10; }
	}
	else { y = PosY + 20; }
	PosX = x;
	PosY = y - 25;
	pSetBlend(true);
	glMatrixMode(0x1701);
	glPushMatrix();
	glLoadIdentity();
	sub_6363D0_Addr(0, 0, *(GLsizei*)0x00E61E58, *(GLsizei*)0x00E61E5C);
	float v2 = *(float*)0x00E61E58 / *(float*)0x00E61E5C;
	sub_6358A0_Addr(Scale, v2, *(float*)0xE61E38, *(float*)0xE61E3C);
	glMatrixMode(0x1700);
	glPushMatrix();
	glLoadIdentity();
	sub_635830_Addr((LPVOID)0x87933A0);
	sub_635DE0_Addr();
	sub_635E40_Addr();
	glClear(0x100);


	pDrawItemModel(PosX, PosY, Width, Height, ItemID, Level, ExtOption, Ancient, PickUp);

	sub_636720_Addr();
	glMatrixMode(0x1700u);
	glPopMatrix();
	glMatrixMode(0x1701u);
	glPopMatrix();
	glColor3f(1, 1, 1);
	pSetBlend(false);
	return;
}

