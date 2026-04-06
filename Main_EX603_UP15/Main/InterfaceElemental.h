#pragma once
#include "stdafx.h"
#include "import.h"
#include "Protocol.h"
typedef char tooltiparray[100];
typedef void(*PUSHEVENT_CALLBACK_LPVOID)(LPVOID);

class CElemental
{
public:
	CElemental();
	~CElemental();

	void	DrawWindow();
	void gDrawWindowCustom(float StartX, float StartY, float CuaSoW, float CuaSoH, int eNumWindow, char* WindowName);
	void gInfoBox(float PosX, float PosY, float Width, float Height, DWORD bkcolor, float Arg5, int Arg6);
	bool gDrawButton(float PosX, float PosY, float SizeButton, int FontSize, char* ButtonText, float mSizeButtonW = 0);
	void DrawFrame(DWORD ModelID, float X, float Y, float W, float H, float SourceX = 0, float SourceY = 0, float SourceW = 225, float SourceH = 225, float ScaleW = 1.5f, float ScaleH = 1.5f, bool ScaleUp = 0);
	void CElemental::DrawText(HFONT font, int PosX, int PosY, DWORD color, DWORD bkcolor, int Width, int Height, BYTE Align, LPCTSTR Text, ...);

	char MsgBoxCaption[50];
	char MsgBoxText[512];
	int MsgBoxType;
	int MsgLine;
	PUSHEVENT_CALLBACK_LPVOID MsgBoxCallback;
	void CElemental::DrawMessageBox();
	void CElemental::OpenMessageBox(char* caption, char* Format, ...);
	void CElemental::OpenMessageBoxOkCancel(PUSHEVENT_CALLBACK_LPVOID pCallbackFunc, char* caption, char* Format, ...);

	DWORD  LockMouse;
	bool LockButtonHover;
private:

};
extern CElemental gElemental;