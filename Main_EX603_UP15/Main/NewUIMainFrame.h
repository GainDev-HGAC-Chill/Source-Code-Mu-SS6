#pragma once
#define CharToString			((void*(__thiscall*)(void *thisa, char *a4))0x00409A50)
#define InitializeButton		((void(__thiscall*)(void* thisa)) 0x00779150)
#define DestroyButton			((void(__thiscall*)(void* thisa)) 0x00779250)
#define Constructor_Btn			((void(__stdcall*)(char *thisa,int ObjSize, int ObjCount, void (__thiscall *)(void *) , void (__thiscall *)(void *) )) 0x009CFA13)

typedef struct UIButton
{
	UIButton()
	{
		memset(&this->btn, 0, sizeof(this->btn));
		Constructor_Btn(this->btn, 172, 1, InitializeButton, DestroyButton);
	}

	void SetBtn(char* zbtn)
	{
		memcpy(&this->btn, zbtn, sizeof(this->btn));
	}

	void ChangeButtonImgState(bool imgregister, int imgindex, bool overflg = false, bool isimgwidth = false, bool bClickEffect = false)
	{
		((void(__thiscall*)(char*, bool, int, bool, bool, bool)) 0x00779350)(
			this->btn, imgregister, imgindex, overflg, isimgwidth, bClickEffect);
	}

	void ChangeButtonInfo2(int x, int y, int sx, int sy)
	{
		((void(__thiscall*)(char*, int, int, int, int)) 0x00779410)(this->btn, x, y, sx, sy);
	}

	void ChangeText(char * btname)
	{
		int std_string[7];
		CharToString(&std_string, btname);
		((void(__thiscall*)(char *, int, int, int, int, int, int, int))0x00790970)(
			this->btn, std_string[0], std_string[1], std_string[2], std_string[3], std_string[4], std_string[5], std_string[6]);
	}

	void SetTooltipText(char * btname)
	{
		int std_string[7];
		CharToString(&std_string, btname);
		((void(__thiscall*)(char *, int, int, int, int, int, int, int, bool))0x007853F0)(
			this->btn, std_string[0], std_string[1], std_string[2], std_string[3], std_string[4], std_string[5], std_string[6], true);
	}

	bool UpdateMouseEvent()
	{
		return ((bool(__thiscall*)(char*)) 0x00779860)(this->btn);
	}

	bool Render(bool RendOption = false)
	{
		return ((bool(__thiscall*)(char*, BYTE)) 0x007798F0)(this->btn, RendOption);
	}

	void ChangeImgColor(DWORD eventstate, unsigned int color)
	{
		((void(__thiscall*)(char*, int, unsigned int))0x00779740)(this->btn, eventstate, color);
	}

	char btn[172];
} DNewUIButton;

typedef struct
{
	/*+00*/		__int64	m_loPreExp;
	/*+08*/		__int64	m_loGetExp;
	/*+16*/		BYTE m_ItemHotKey[27];
	/*+43*/		bool m_bExpEffect;
	/*+44*/		DWORD m_dwExpEffectTime;
	/*+48*/		DWORD m_dwPreExp;
	/*+52*/		DWORD m_dwGetExp;
	/*+56*/		DNewUIButton m_BtnCShop;
	/*+228*/	DNewUIButton m_BtnChaInfo;
	/*+400*/	DNewUIButton m_BtnMyInven;
	/*+572*/	DNewUIButton m_BtnFriend;
	/*+744*/	DNewUIButton m_BtnWindow;
	/*+916*/	bool m_bButtonBlink;
} MainFrame;

class CNewUIMainFrame
{
public:
	CNewUIMainFrame(void);
	virtual ~CNewUIMainFrame(void);
};

