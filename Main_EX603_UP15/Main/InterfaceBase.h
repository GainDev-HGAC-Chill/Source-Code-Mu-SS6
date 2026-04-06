#pragma once
#define pIsKeyRelease		((bool(__cdecl*)(int)) 0x791050)
#define RenderBitmap		((void(__cdecl*)(int a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9, char a10, char a11, float a12)) 0x00637C60)

typedef void(*PUSHEVENT_CALLBACK_LPVOID)(LPVOID);

struct cIB_Title
{
	bool Enable;
	bool Bold;
	char Title[60];
	DWORD Color;
	DWORD Background;
	cIB_Title()
	{
		Enable = false;
		ZeroMemory(Title, sizeof(Title));
	};
	cIB_Title(char* title, DWORD color = 0xffffffff, DWORD bg = 0x0, bool bold = false)
	{
		Enable = true;
		Bold = bold;
		Color = color;
		Background = bg;
		ZeroMemory(Title, sizeof(Title));
		memcpy_s(Title, sizeof(Title), title, sizeof(Title));
	};
};

class cInterfaceBase
{
public:
	cInterfaceBase();
	~cInterfaceBase();

	void ToggleWindow(bool mode = false);
	void OpenWindow(bool mode = false);
	void CloseWindow(bool mode = false);
	void SetWindow(bool state, bool mode = false);
	bool CheckWindow();
	void SetRect(float a1, float a2, float a3, float a4);
	bool CheckRect(bool mode = true);
	void OnOpen();
	void OnClose();
	void DrawBase();
	void SetTitle(char* title, DWORD color = 0xffffffff, DWORD bg = 0x0, bool bold = false);
	bool IsWorkZone(float, float, float, float, bool mode = false);
	bool IsOnWindow();
	void DrawButton(int IMGcode, float x, float y, float w, float h, float a6, float a7, PUSHEVENT_CALLBACK_LPVOID pCallbackFunc);
protected:
	float x;
	float y;
	float w;
	float h;
	bool Drawing;
	cIB_Title* _Title;
};