#include "stdafx.h"

#include "Import.h"
#include "InterfaceBase.h"
#include "CustomFont.h"

cInterfaceBase::cInterfaceBase()
{
	SetWindow(false);
}

cInterfaceBase::~cInterfaceBase()
{
}

void cInterfaceBase::ToggleWindow(bool mode)
{
	SetWindow(!CheckWindow(), mode);
}
void cInterfaceBase::OpenWindow(bool mode)
{
	SetWindow(true, mode);
}
void cInterfaceBase::CloseWindow(bool mode)
{
	SetWindow(false, mode);
}
void cInterfaceBase::SetWindow(bool state, bool mode)
{
	this->Drawing = state;
	if (mode)
		CheckWindow() ? OnOpen() : OnClose();
}
bool cInterfaceBase::CheckWindow()
{
	return this->Drawing;
}
void cInterfaceBase::SetRect(float a1, float a2, float a3, float a4)
{
	this->x = a1;
	this->y = a2;
	this->w = a3;
	this->h = a4;
}
bool cInterfaceBase::CheckRect(bool mode)
{
	return CheckWindow() && IsWorkZone(x, y, w, h + 30, mode);
}
void cInterfaceBase::OnOpen()
{
	//do smt
	//pDrawMessage("OnOpen", 1);
}
void cInterfaceBase::OnClose()
{
	//do smt
	//pDrawMessage("OnClose", 0);
}
void cInterfaceBase::DrawBase()
{

	//==========
	glAlphaFunc(GL_GREATER, 0.0f);

	CustomFont.Draw(CustomFont.FontBold, x, y, 0x0, 0x373b45ff, w, h + 30, 1, " ");


	RenderBitmap(31355, x, y + 63, 21.0, 189.2f, 0, 0, 21.f / 32.f, 320.f / 512.f, 1, 1, 0.0);
	RenderBitmap(31356, x + w - 21.f, y + 63, 21.0, 189.2f, 0, 0, 21.f / 32.f, 320.f / 512.f, 1, 1, 0.0);

	RenderBitmap(31353, x, y, 60.f, 63.f, 0.0, 0, 60.f / 256.f, 63.f / 64.f, 1, 1, 0.0);
	RenderBitmap(31353, x + 60, y, 70.f, 63.f, 60.f / 256.f, 0, 70.f / 256.f, 63.f / 64.f, 1, 1, 0.0);
	RenderBitmap(31353, x + 130, y, 70.f, 63.f, 60.f / 256.f, 0, 70.f / 256.f, 63.f / 64.f, 1, 1, 0.0);
	RenderBitmap(31353, x + 200, y, 70.f, 63.f, 60.f / 256.f, 0, 70.f / 256.f, 63.f / 64.f, 1, 1, 0.0);
	RenderBitmap(31353, x + 270, y, 70.f, 63.f, 60.f / 256.f, 0, 70.f / 256.f, 63.f / 64.f, 1, 1, 0.0);
	RenderBitmap(31353, x + 340, y, 60.f, 63.f, 130.f / 256.f, 0, 60.f / 256.f, 63.f / 64.f, 1, 1, 0.0);

	pDrawButton(31357, x, y + 242, 60.0, 45.0, 0, 0);
	pDrawButton(31357, x + 60, y + 242, 70.0, 45.0, 60.0, 0);
	pDrawButton(31357, x + 130, y + 242, 70.0, 45.0, 60.0, 0);
	pDrawButton(31357, x + 200, y + 242, 70.0, 45.0, 60.0, 0);
	pDrawButton(31357, x + 270, y + 242, 70.0, 45.0, 60.0, 0);
	pDrawButton(31357, x + 340, y + 242, 60.0, 45.0, 130.0, 0);


	if (IsWorkZone(x + w - 25, y + 5, 20, 18, false))
	{
		if (pIsKeyRelease(VK_LBUTTON) && IsOnWindow())
			this->SetWindow(false, true);
		((int(__cdecl*)(int X, int Y, LPCSTR Text)) 0x00597220)(x + w - 25, y + 25, "Close");
	}

	glAlphaFunc(GL_GREATER, 0.25f);


	if (_Title->Enable)
		CustomFont.Draw(_Title->Bold ? CustomFont.FontBold : CustomFont.FontNormal, x, y + 12, _Title->Color, _Title->Background, w, 0, 3, _Title->Title);
}
void cInterfaceBase::SetTitle(char* title, DWORD color, DWORD bg, bool bold)
{
	this->_Title = new cIB_Title(title, color, bg, bold);
}

bool cInterfaceBase::IsOnWindow()
{
	return *(HWND*)0x0E8C578 == GetForegroundWindow();
}
bool cInterfaceBase::IsWorkZone(float x, float y, float w, float h, bool mode)
{
	if (mode)
		return IsOnWindow() && * (int*)0x879340C >= x && *(int*)0x879340C <= x + w && *(int*)0x8793410 >= y && *(int*)0x8793410 <= y + h;
	return *(int*)0x879340C >= x && *(int*)0x879340C <= x + w && *(int*)0x8793410 >= y && *(int*)0x8793410 <= y + h;
}
void cInterfaceBase::DrawButton(int IMGcode, float x, float y, float w, float h, float a6, float a7, PUSHEVENT_CALLBACK_LPVOID pCallbackFunc) {
	if (IsWorkZone(x, y, w, h, true)) {
		if (GetKeyState(VK_LBUTTON) & 0x8000) {
			RenderBitmap(IMGcode, x, y, w, h, 0.0, h / a7 * 2.0, w / a6, h / a7, 1, 1, 0.0);
		}
		else {
			RenderBitmap(IMGcode, x, y, w, h, 0.0, h / a7, w / a6, h / a7, 1, 1, 0.0);
		}
		if (pIsKeyRelease(VK_LBUTTON))
		{
			pCallbackFunc(this);
			return;
		}
		return;
	}
	else {
		RenderBitmap(IMGcode, x, y, w, h, 0.0, 0.0, w / a6, h / a7, 1, 1, 0.0);
	}
	return;
}