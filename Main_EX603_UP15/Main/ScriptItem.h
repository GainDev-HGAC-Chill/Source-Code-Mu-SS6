#pragma once
#if(SLOTPET)
#define MAX_LINE_ITEM_BMD		0x2000
const BYTE EXT_A_SET_OPTION = 1;
const BYTE EXT_B_SET_OPTION = 2;

#define AT_EXCELLENT_DAMAGE					93
#define AT_IMPROVE_DAMAGE_LEVEL				94
#define AT_IMPROVE_DAMAGE_PERCENT			95
#define AT_IMPROVE_MAGIC_LEVEL				96
#define AT_IMPROVE_MAGIC_PERCENT			97
#define AT_IMPROVE_ATTACK_SPEED				98
#define AT_IMPROVE_GAIN_LIFE				99
#define AT_IMPROVE_GAIN_MANA				100


#define Information_ItemConvert				((char (__cdecl*)(ITEM *ip, unsigned __int8 Attribute1, unsigned __int8 Attribute2, unsigned __int8 Attribute3)) 0x0058B910)
#define IsCepterItem						((bool (__cdecl*)(int Type)) 0x0058B8D0)
#define BuxConvert							((int(__cdecl*)(BYTE * Buffer, int Size)) 0x004071A0)
typedef char textlist[100];
#define GlobalText							((char*(__thiscall*)(LPVOID thisa, int LineNumber)) 0x00402320)

inline DWORD GenerateCheckSum2(BYTE* pbyBuffer, DWORD dwSize, WORD wKey);

typedef struct
{
	char Name[30];
	bool TwoHand;
	WORD Level;
	BYTE m_byItemSlot;
	WORD m_wSkillIndex;
	BYTE Width;
	BYTE Height;
	BYTE DamageMin;
	BYTE DamageMax;
	BYTE SuccessfulBlocking;
	BYTE Defense;
	BYTE MagicDefense;
	BYTE WeaponSpeed;
	BYTE WalkSpeed;
	BYTE Durability;
	BYTE MagicDur;
	BYTE MagicPower;
	WORD RequireStrength;
	WORD RequireDexterity;
	WORD RequireEnergy;
	WORD  RequireVitality;
	WORD RequireCharisma;
	WORD RequireLevel;
	BYTE Value;
	int  iZen;
	BYTE  AttType;
	BYTE RequireClass[7];
	BYTE Resistance[7];
} ITEM_ATTRIBUTE;

extern ITEM_ATTRIBUTE* ItemAttribute;

#define Information_ItemConvert				((char (__cdecl*)(ITEM *ip, unsigned __int8 Attribute1, unsigned __int8 Attribute2, unsigned __int8 Attribute3)) 0x0058B910)
#define IsCepterItem						((bool (__cdecl*)(int Type)) 0x0058B8D0)
#define ItemAttribute( Type )				(ITEM_ATTRIBUTE*)(*(DWORD*)0x008128AC0 + 84 * Type)

class CScriptItem
{
public:
	CScriptItem(void);
	virtual ~CScriptItem(void);
	static void OpenItemScript(char* FileName);
public:
	void Init();
};
extern CScriptItem g_ScriptItem;
#endif

