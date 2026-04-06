#include "stdafx.h"
#include "NewInterface.h"
#include "Interface.h"
#include "Font.h"
#include "User.h"
//#include "ServerInfo.h"
#include "CustomJewel.h"
#include "HealthBar.h"
#include "Util.h"

CNewInterface gNewInterface;

float diffX = 0;
float diffY = 0;

CNewInterface::CNewInterface()
{
	//this->Load();
}

void CNewInterface::Load()
{
	//g_Console.AddMessage(3,"Interfasce loaded");
	//MsgBox("LOL");
	//this->UserPanelSwitchState();

	this->MsgBoxState = false;
	this->MsgBoxType = -1;
	this->MsgBoxCallback = 0;
	this->MsgBoxCallBackArg1 = 0;
	this->MsgBoxCallBackArg2 = 0;
}

void CNewInterface::Work()
{
	this->DrawMessageBox();
}

void CNewInterface::Bind(DWORD objId, float X, float Y, float Height, float Width)
{
	this->m_Data[objId].EventTick = 0;
	this->m_Data[objId].OnClick = false;
	this->m_Data[objId].OnShow = false;
	this->m_Data[objId].Width = Width;
	this->m_Data[objId].Height = Height;
	this->m_Data[objId].X = X;
	this->m_Data[objId].Y = Y;
	this->m_Data[objId].MaxX = X + Width;
	this->m_Data[objId].MaxY = Y + Height;
	this->leftButtonState = false;
}

void CNewInterface::OpenMessageBox(char* caption, char* Format, ...)
{
	if (this->MsgBoxState)
	{
		return;
	}

	char text[1024] = { 0 };
	va_list va;
	va_start(va, Format);
	vsprintf_s(text, Format, va);
	va_end(va);

	memset(this->MsgBoxCaption, 0, sizeof(this->MsgBoxCaption));
	memset(this->MsgBoxText, 0, sizeof(this->MsgBoxText));

	memcpy(this->MsgBoxCaption, caption, sizeof(this->MsgBoxCaption));
	memcpy(this->MsgBoxText, text, sizeof(this->MsgBoxText));

	this->MsgBoxState = true;
	this->MsgBoxType = 0;
	pSetCursorFocus = true;
}

void CNewInterface::OpenMessageBoxOkCancel(DWORD callback, DWORD CallbackArg1, DWORD CallbackArg2, char* caption, char* Format, ...)
{
	if (this->MsgBoxState)
	{
		return;
	}

	char text[1024] = { 0 };
	va_list va;
	va_start(va, Format);
	vsprintf_s(text, Format, va);
	va_end(va);

	memset(this->MsgBoxCaption, 0, sizeof(this->MsgBoxCaption));
	memset(this->MsgBoxText, 0, sizeof(this->MsgBoxText));

	memcpy(this->MsgBoxCaption, caption, sizeof(this->MsgBoxCaption));
	memcpy(this->MsgBoxText, text, sizeof(this->MsgBoxText));

	this->MsgBoxState = true;
	this->MsgBoxType = 1;
	this->MsgBoxCallback = callback;
	this->MsgBoxCallBackArg1 = CallbackArg1;
	this->MsgBoxCallBackArg2 = CallbackArg2;
	pSetCursorFocus = true;
}


void CNewInterface::DrawMessageBox()
{
	if (!this->MsgBoxState)
	{
		return;
	}
	//this->MsgBoxType = 1;
	float MainWidth = 190.0;
	float MainHeight = 90.0;
	float StartY = 100.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	this->DrawBackground(-1, StartX, StartY, MainWidth, MainHeight, "%s", this->MsgBoxCaption);
	//g_Console.AddMessage(5,this->MsgBoxText);
	this->TextDraw(StartX + MainWidth / 2, StartY + 34, 0, 1, eWhite, 0, 8, gFont[ARIAL_16]->m_Font, this->MsgBoxText);


	if (this->MsgBoxType == 0)
	{
		float BtnHeight = 20.0;
		float BtnWidth = 120.0;
		this->DrawButton(eMessageBoxButton, StartX + MainWidth / 2 - (BtnWidth / 2), StartY + MainHeight - BtnHeight - 10, BtnWidth, BtnHeight, &gNewInterface.Button, &gNewInterface.ButtonOnClick, &gNewInterface.ButtonHover, "CLOSE");
	}
	else if (this->MsgBoxType == 1)
	{
		float BtnHeight = 20.0;
		float BtnWidth = 55.0;
		this->DrawButton(eMessageBoxButton, StartX + MainWidth / 2 - (BtnWidth + 7.5), StartY + MainHeight - BtnHeight - 10, BtnWidth, BtnHeight, &gNewInterface.Button, &gNewInterface.ButtonOnClick, &gNewInterface.ButtonHover, "OKAY");
		this->DrawButton(eMessageBoxButton2, StartX + MainWidth / 2 + (7.5), StartY + MainHeight - BtnHeight - 10, BtnWidth, BtnHeight, &gNewInterface.Button, &gNewInterface.ButtonOnClick, &gNewInterface.ButtonHover, "CLOSE");
	}

}

void CNewInterface::EventMessageBox(DWORD Event)
{
	if (!this->MsgBoxState)
	{
		return;
	}

	if (Event != WM_LBUTTONUP)
	{
		return;
	}

	if (gNewInterface.IsWorkZone(eMessageBoxButton))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gNewInterface.m_Data[eMessageBoxButton].EventTick);

		gNewInterface.m_Data[eMessageBoxButton].OnClick = false;
		if (Delay < 500)
		{
			return;
		}
		gNewInterface.m_Data[eMessageBoxButton].EventTick = GetTickCount();

		if (this->MsgBoxType == 1)
		{
			((void(*)(DWORD, DWORD))this->MsgBoxCallback)(this->MsgBoxCallBackArg1, this->MsgBoxCallBackArg2);
			this->MsgBoxCallback = 0;
			this->MsgBoxCallBackArg1 = 0;
			this->MsgBoxCallBackArg2 = 0;
		}
		this->MsgBoxState = false;
		pSetCursorFocus = false;
	}
	else if (gNewInterface.IsWorkZone(eMessageBoxButton2))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gNewInterface.m_Data[eMessageBoxButton2].EventTick);

		gNewInterface.m_Data[eMessageBoxButton2].OnClick = false;
		if (Delay < 500)
		{
			return;
		}
		gNewInterface.m_Data[eMessageBoxButton2].EventTick = GetTickCount();

		this->MsgBoxState = false;
		pSetCursorFocus = false;
	}
}



void CNewInterface::DrawClose(int Index, int PosX, int PosY, int Color)
{
	m_Data[Index].Width = 10;
	m_Data[Index].Height = 10;
	m_Data[Index].X = PosX;
	m_Data[Index].Y = PosY;
	m_Data[Index].MaxX = PosX + 10;
	m_Data[Index].MaxY = PosY + 10;
	m_Data[Index].Type = objButton;

	this->TextDraw(PosX, PosY, 0, 0, eGold, 0, 0, gFont[ARIAL_16]->m_Font, "X");
}

void CNewInterface::TextDraw(int PosX, int PosY, int Width, int Arg5, int Color, int Arg7, int Align, HGDIOBJ Font, LPCTSTR Format, ...)
{
	char TextBuff[1024] = { 0 };
	va_list va;
	va_start(va, Format);
	vsprintf_s(TextBuff, Format, va);
	va_end(va);

	int v13; // ST1C_4@1
	int v15; // ST20_4@1
	pSetFont(pTextThis(), (int)Font);
	v13 = sub_41FFE0_Addr(pTextThis());
	v15 = sub_420010_Addr(pTextThis());
	SetTextColorByHDC(pTextThis(), Color);
	sub_4200F0_Addr(pTextThis(), Arg7);
	pSetBkColor(pTextThis(), 255, 255, 255, 0);
	pDrawText(pTextThis(), PosX, PosY, TextBuff, Width, Arg5, (int*)Align, 0);
	SetTextColorByHDC(pTextThis(), v13);
	sub_4200F0_Addr(pTextThis(), v15);
}

void CNewInterface::DrawBackground(DWORD Object, float PosX, float PosY, float Width, float Height, LPCTSTR Format, ...)
{
	//g_Console.AddMessage(3,"W = %f H = %f",Width,Height);
	//if( this->m_Data[Object].X == -1 || this->m_Data[Object].Y == -1 )
	//{
	/*this->m_Data[Object].Width = Width;
	this->m_Data[Object].Height = Height;
	this->m_Data[Object].X		= PosX;
	this->m_Data[Object].Y		= PosY;
	this->m_Data[Object].MaxX	= PosX + this->m_Data[Object].Width;
	this->m_Data[Object].MaxY	= PosY + this->m_Data[Object].Height;*/
	//}

	char TextBuff[1024] = { 0 };
	va_list va;
	va_start(va, Format);
	vsprintf_s(TextBuff, Format, va);
	va_end(va);

	this->DrawBarForm(PosX, PosY, Width, Height, 0.0, 0.0, 0.0, 0.7);//Background
	this->DrawBarForm(PosX, PosY, Width, 15, 0.0, 0.0, 0.0, 1.0);//Top
	this->DrawBarForm(PosX, PosY, 5, Height, 0.0, 0.0, 0.0, 1.0);//Left
	this->DrawBarForm(PosX + Width - 5, PosY, 5, Height, 0.0, 0.0, 0.0, 1.0);//Right
	this->DrawBarForm(PosX, PosY + Height - 5, Width, 5, 0.0, 0.0, 0.0, 1.0);//Bottom

	this->TextDraw(PosX + (Width / 2), PosY + 3.5, 0, 1, eGold, 0, 8, gFont[ARIAL_16]->m_Font, TextBuff);
}

void CNewInterface::DrawButton(int Index, float PosX, float PosY, float Width, float Height, MU_4float* Base, MU_4float* OnClick, MU_4float* Hover, LPCTSTR Text/*, ...*/)
{
	/*char TextBuff[1024] = {0};
	va_list va;
	va_start(va, Text);
	vsprintf_s(TextBuff, Text, va);
	va_end(va);*/

	m_Data[Index].Width = Width;
	m_Data[Index].Height = Height;
	m_Data[Index].X = PosX;
	m_Data[Index].Y = PosY;
	m_Data[Index].MaxX = PosX + Width;
	m_Data[Index].MaxY = PosY + Height;
	m_Data[Index].Type = objButton;

	if (m_Data[Index].OnClick)
	{
		DrawBarForm(PosX, PosY, Width, Height, OnClick->Red, OnClick->Green, OnClick->Blue, OnClick->Alpha);
	}
	else if (this->IsWorkZone(Index))
	{
		DrawBarForm(PosX, PosY, Width, Height, Hover->Red, Hover->Green, Hover->Blue, Hover->Alpha);
	}
	else
	{
		DrawBarForm(PosX, PosY, Width, Height, Base->Red, Base->Green, Base->Blue, Base->Alpha);
	}

	if (Text != NULL)
	{
		this->TextDraw(PosX + (Width / 2), PosY + 6, 0, 1, eGold, 0, 8, pFontNormal, Text);
	}
}

void CNewInterface::DrawBarForm(float PosX, float PosY, float Width, float Height, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
	pSetBlend(true);
	glColor4f(red, green, blue, alpha);
	pDrawBarForm(PosX, PosY, Width, Height, 0.0f, 0);
	pGLSwitchBlend();
	pGLSwitch();
	glColor3f(1.0, 1.0, 1.0);
	pSetBlend(false);
}

void CNewInterface::DrawSelectBox(int Index, float PosX, float PosY, float Width, float Height, LPCTSTR Text)
{
	m_Data[Index].Width = Width;
	m_Data[Index].Height = Height;
	m_Data[Index].X = PosX;
	m_Data[Index].Y = PosY;
	m_Data[Index].MaxX = PosX + Width;
	m_Data[Index].MaxY = PosY + Height;
	m_Data[Index].Type = objSelectBox;

	if (Text != NULL)
	{
		this->TextDraw(PosX + (Width / 2), PosY - 1, 0, 0, eGold, 0, 8, pFontNormal, Text);
	}

	this->DrawBarForm(PosX, PosY, Width, Height, 0.0, 0.0, 0.0, 1.0);

	if (m_Data[Index].State == true)
	{
		DrawBarForm(PosX, PosY, Width - Width / 2, Height, 0.0, 0.8, 0.0, 1.0);
		this->TextDraw(PosX + 12, PosY + 2, 0, 0, eWhite, 0, 8, pFontNormal, "ON");

	}
	else
	{

		DrawBarForm(PosX + Width / 2, PosY, Width - Width / 2, Height, 0.8, 0.0, 0.0, 1.0);
		this->TextDraw(PosX + (Width / 2) + 12, PosY + 2, 0, 0, eGold, 0, 8, pFontNormal, "OFF");
	}
}

void CNewInterface::DrawGUI(short ObjectID, float PosX, float PosY)
{
	//this->m_Data[ObjectID].X		= PosX;
	//this->m_Data[ObjectID].Y		= PosY;
	//this->m_Data[ObjectID].MaxX	= PosX + this->m_Data[ObjectID].Width;
	//this->m_Data[ObjectID].MaxY	= PosY + this->m_Data[ObjectID].Height;
	//// ----
	//pDrawGUI(this->m_Data[ObjectID].ModelID, PosX, PosY, 
	//	this->m_Data[ObjectID].Width, this->m_Data[ObjectID].Height);
}

bool CNewInterface::CheckWindow(int index)
{
	return this->m_Data[index].OnShow;
}


bool CNewInterface::IsWorkZone(int Index)
{
	if (gObjUser.m_CursorX < this->m_Data[Index].X || gObjUser.m_CursorX > this->m_Data[Index].MaxX ||
		gObjUser.m_CursorY < this->m_Data[Index].Y || gObjUser.m_CursorY > this->m_Data[Index].MaxY)
	{
		return false;
	}
	return true;
}

bool CNewInterface::IsWorkZone(int x, int y, int maxX, int maxY)
{
	if (gObjUser.m_CursorX < x || gObjUser.m_CursorX > maxX ||
		gObjUser.m_CursorY < y || gObjUser.m_CursorY > maxY)
	{
		return false;
	}
	return true;
}

bool CNewInterface::EventAllWindow(DWORD Event, MOUSEHOOKSTRUCTEX* Mouse)
{

	/*if (gPackSystem.EventPackWindow(Event) == true)
	{
	return 1;
	}*/

	this->EventMessageBox(Event);
	return 0;
	//this->EventSettingsWindow(Event);
}