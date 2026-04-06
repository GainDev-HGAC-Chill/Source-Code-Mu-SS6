#include "StdAfx.h"
#include "Util.h"
#include "Extras.h"
#include "Protocol.h"
#include "NewUIMyInventory.h"
#include "WSclient.h"

#if(SLOTPET)
WSclient g_pWSclient;
using std::string;

WSclient::WSclient(void)
{
}

WSclient::~WSclient(void)
{
}

BOOL ReceiveEquipmentItem(BYTE *ReceiveBuffer, BOOL bEncrypted)
{
	LPPHEADER_SUBCODE_ITEM Data = (LPPHEADER_SUBCODE_ITEM)ReceiveBuffer;

	if (Data->SubCode == 40)
	{
		EquipmentItem = false;
		Character_Machin->EquipItem(Data->Index, Data->Item);
		return TRUE;
	}

	return CReceiveEquipmentItem(ReceiveBuffer, bEncrypted);
}

void ReceiveCreatePlayerViewport(BYTE *ReceiveBuffer)
{
	((void(__cdecl*)(BYTE *)) 0x00641A50)(ReceiveBuffer);
	LPPWHEADER_DEFAULT_WORD Data = (LPPWHEADER_DEFAULT_WORD)ReceiveBuffer;
	int Offset = sizeof(PWHEADER_DEFAULT_WORD);

	for (int i = 0; i< Data->Value; i++)
	{
		LPPCREATE_CHARACTER Data2 = (LPPCREATE_CHARACTER)(ReceiveBuffer + Offset);
		WORD Key = ((WORD)(Data2->KeyH) << 8) + Data2->KeyL;
		Key &= 0x7FFF;

		int iIndex = FindCharacterIndex(Key);
		int pCha = CharactersClient(CList(), FindCharacterIndex(Key));
		//--
		if (pCha)
		{
			int o = pCha + 776;

			if (pCha == Hero)
			{
				Delect_FlyBug(Hero + 776);
			}

			WORD Type = MAKE_NUMBERW(Data2->MuunItem[0], Data2->MuunItem[1]);
			if (Type != 0xFFFF)
			{
				*(WORD*)(pCha + 592) = Type + 1171;
				CreateEffectEquipping(Type, pCha, pCha + 776);
			}
			else
			{
				*(WORD*)(pCha + 592) = 0xFFFF;
				Delect_FlyBug(pCha + 776);
			}
		}

		Offset += (sizeof(PCREATE_CHARACTER)-(sizeof(BYTE)*(MAX_BUFF_SLOT_INDEX - Data2->s_BuffCount)));
	}
}

void ReceiveCreateTransformViewport(BYTE *ReceiveBuffer)
{
	((void(__cdecl*)(BYTE *)) 0x00642130)(ReceiveBuffer);
	LPPWHEADER_DEFAULT_WORD Data = (LPPWHEADER_DEFAULT_WORD)ReceiveBuffer;
	int Offset = sizeof(PWHEADER_DEFAULT_WORD);

	for (int i = 0; i<Data->Value; i++)
	{
		LPPCREATE_TRANSFORM Data2 = (LPPCREATE_TRANSFORM)(ReceiveBuffer + Offset);
		WORD Key = ((WORD)(Data2->KeyH) << 8) + Data2->KeyL;
		Key &= 0x7FFF;

		int iIndex = FindCharacterIndex(Key);
		int pCha = CharactersClient(CList(), FindCharacterIndex(Key));
		//--
		if (pCha)
		{
			int o = pCha + 776;

			if (pCha == Hero)
			{
				Delect_FlyBug(Hero + 776);
			}

			WORD Type = MAKE_NUMBERW(Data2->MuunItem[0], Data2->MuunItem[1]);

			if (Type != 0xFFFF)
			{
				*(WORD*)(pCha + 592) = Type + 1171;
				CreateEffectEquipping(Type, pCha, pCha + 776);
			}
			else
			{
				*(WORD*)(pCha + 592) = 0xFFFF;
				Delect_FlyBug(pCha + 776);
			}
		}
		Offset += (sizeof(PCREATE_CHARACTER)-(sizeof(BYTE)*(MAX_BUFF_SLOT_INDEX - Data2->s_BuffCount)));
	}
}

void WSclient::Init()
{
	SetCompleteHook(0xE8, 0x0066424B, &ReceiveEquipmentItem);
}
#endif