#pragma once
#if(SLOTPET)
#define MAX_BUFF_SLOT_INDEX						16
#define MAX_ID_SIZE								10
#define EQUIPMENT_LENGTH						17

typedef struct {
	BYTE         Header[4];
	BYTE         Value;
} PWHEADER_DEFAULT_WORD, *LPPWHEADER_DEFAULT_WORD;

//receive other map character
typedef struct {
	BYTE         KeyH;
	BYTE         KeyL;
	BYTE         PositionX;
	BYTE         PositionY;
	BYTE         Class;
	BYTE         Equipment[EQUIPMENT_LENGTH];
	BYTE         ID[MAX_ID_SIZE];
	BYTE         Target_X;
	BYTE         Target_Y;
	BYTE         Path;
	BYTE         MuunItem[2];
	BYTE         s_BuffCount;
	BYTE         s_BuffEffectState[MAX_BUFF_SLOT_INDEX];
} PCREATE_CHARACTER, *LPPCREATE_CHARACTER;

typedef struct
{
	BYTE         KeyH;
	BYTE         KeyL;
	BYTE         PositionX;
	BYTE         PositionY;
	BYTE         TypeH;
	BYTE         TypeL;
	BYTE         ID[MAX_ID_SIZE];
	BYTE         Target_X;
	BYTE         Target_Y;
	BYTE         Path;
	BYTE         Class;
	BYTE         Equipment[EQUIPMENT_LENGTH];
	BYTE         MuunItem[2];
	BYTE         s_BuffCount;
	BYTE		 s_BuffEffectState[MAX_BUFF_SLOT_INDEX];
} PCREATE_TRANSFORM, *LPPCREATE_TRANSFORM;

#define CReceiveEquipmentItem		((BOOL (__cdecl*)(BYTE *ReceiveBuffer, BOOL bEncrypted)) 0x0064B860)
#define AssignChat					((void (__cdecl*)(char *ID,const char* Text,int Flag)) 0x005999F0)
#define GetInstance						((int(__cdecl*)()) 0x00861110)


class WSclient
{
public:
	WSclient(void);
	virtual ~WSclient(void);

	void Init();
	static bool __thiscall TMessageText(int thisa, int strID, int strText, DWORD MsgType);
};

extern WSclient g_pWSclient;
#endif