#pragma once
#include "UITextInputBox.h"

#define LODWORD(h)					((DWORD)(__int64(h) & __int64(0xffffffff)))
#define PlayBuffer			((signed int(__cdecl*)(int a1, int a2, int a3)) 0x006D6C20)
class CBUtil
{
public:
	CBUtil();
	virtual ~CBUtil();
	bool gDrawWindowCustom(float* StartX, float* StartY, float CuaSoW, float CuaSoH, int eNumWindow, LPCSTR Text, ...);
	void DrawFrame(DWORD ModelID, float X, float Y, float W, float H, float SourceX = 0, float SourceY = 0, float SourceW = 225, float SourceH = 225, float ScaleW = 1.5f, float ScaleH = 1.5f, bool ScaleUp = 0);
	void MoveWindows(int eNumWindow);
	//===Lock MOuse
	static bool __thiscall CheckMouseUse(int ThisA);
	DWORD DelayMouseLock;
	bool LockButtonHover;
	bool LockScrollMouse;
	int DrawText(HFONT font, int PosX, int PosY, DWORD color, DWORD bkcolor, int Width, int Height, BYTE Align, LPCTSTR Text, ...);
	void gInfoBox(float PosX, float PosY, float Width, float Height, DWORD bkcolor, float bAlpha, int Arg6);
	void gItemBoxInv(int X, int Y, int Doc, int Ngang, int Use);
	void RenderMixEffect(int type, int x, int y);
	char* NumberFormat(int Number);
	char* fNumberFormat(float number);
	char* NumberFormat(DWORD Number);
	bool gDrawButton(float PosX, float PosY, float SizeButton, int FontSize, char* ButtonText, float mSizeButtonW = 0.0f, bool IsEnter = false);
	bool RenderCheckBox(float PosX, float PosY, DWORD TextColor, bool Checkis, LPCSTR Text, ...);
	bool gDrawButtonGUI(int IDGUID, float PosX, float PosY, float SizeW, float SizeH, int TypeButton = 0);
	//==
	void DrawBarForm(float PosX, float PosY, float Width, float Height, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
	void		RenderCaptchaNumber(float PosX, float PosY, CUITextInputBox* a6, LPCSTR Text, ...);
	bool		check_Captcha(std::string& captcha, std::string& user_input);
	std::string generateCaptcha(int n);
	std::string vCaptcha;

	int CBUtil::GetTimeGMT();
	void CBUtil::BRenderTimeCountDown(float x, float y, float w, int MatchTime, int FontSize = 18);
	void CBUtil::DrawItem3D(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int ExtOption, int Ancient, bool PickUp, float Scale, bool Center = true);


};
extern CBUtil gCBUtil;
