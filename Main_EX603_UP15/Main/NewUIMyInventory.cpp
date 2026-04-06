#include "StdAfx.h"
#include "Util.h"
#include "Defines.h"
#include "Defines2.h"
#include "Protocol.h"
#include "ScriptItem.h"
#include "NewUISystem.h"
#include "Wsclientline.h"
#include "NewUIMainFrame.h"
#include "CustomPet.h"
#include "Pet.h"
#include "NewUIMyInventory.h"a


CNewUIMyInventory g_pMyInventory;
CCharacterMachine * Character_Machin;
EQUIPMENT_ITEM m_Slots[3];
BYTE ButterFly[6480];
DNewUIButton * m_BtnMove[2];
int TypeInventory = 1;

CNewUIMyInventory::CNewUIMyInventory(void)
{
}

CNewUIMyInventory::~CNewUIMyInventory(void)
{
}

char RenderPetScale1(int a4, char a5)
{
	float RenderSize;

	if (*(BYTE*)(a4 + 4))
	{
		char v8 = 0;

		if (a5)
		{
			v8 = 1;
		}
		else
		{
			float v5 = *(float*)(a4 + 256) * 0.009999999776482582;
			float v6 = *(float*)(a4 + 252) * 0.009999999776482582;
			v8 = sub_5DBA10(v6, v5, -20.0);
		}

		*(BYTE*)(a4 + 12) = v8;

		if (*(BYTE*)(a4 + 12))
		{
			DWORD dwItemNumber = *(DWORD*)(a4 + 48);

			if (*(DWORD *)(*(DWORD*)(a4 + 472) + 48) != 1163 && *(DWORD*)(a4 + 48) != 7827)
			{
				return 1;
			}

			if (a5)
			{
				*(float*)(a4 + 96) = *(float*)(a4 + 96);
			}
			else if (pPlayerState == 4)
			{

				*(float*)(a4 + 96) = 1.2f;

			}
			else if (dwItemNumber != 384 && dwItemNumber != 386 && dwItemNumber != 385 && dwItemNumber != 387)
			{
				*(float*)(a4 + 96) = 1.0;
			}

			if (gCustomPet2.CheckCustomPetByItem(dwItemNumber - 1171))
			{
				if (pPlayerState != 4)
				{
					*(float*)(a4 + 96) = gCustomPet2.GetScaleView(dwItemNumber - 1171);
				}
				else
				{

					*(float*)(a4 + 96) = gCustomPet2.GetScaleView(dwItemNumber - 1171) + 0.3;


				}
			}

			int v9 = 0;

			if (pCheckEffectPlayer((LPVOID)(*(DWORD*)(a4 + 472) + 484), 18))
			{
				v9 = 10;
			}

			pObjectMaxBug(a4, 0, 0, v9);

			float v10 = (double)((signed int)sub_9CFB8D() % 30 + 70) * 0.009999999776482582;

			if (dwItemNumber == 7827)
			{
				float Color[3];

				Color[0] = v10 * 0.5;
				Color[1] = v10 * 0.800000011920929;
				Color[2] = v10 * 0.6000000238418579;

				pPlayStaticEffect(32002, (DWORD*)(a4 + 252), 1.0, Color, a4, 0.0, 0);
			}
		}
	}
	return 1;
}

void Delect_FlyBug(int Owner)
{
	BYTE *o;
	for (int i = 0; i < 10; ++i)
	{
		o = &ButterFly[648 * i];
		if (ButterFly[648 * i + 4])
		{
			if (*((DWORD *)o + 118) == Owner) { o[4] = false; }
		}
	}
}

void Create_FlyBug(int Type, int Position, int Owner, int SubType, int LinkBone)
{
	if (InChaosCastle(World) != true && (*(DWORD *)(Owner + 48) == MODEL_PLAYER || Type == MODEL_HELPER))
	{
		for (int i = 0; i<10; i++)
		{
			if (CreateBugSub_(Type, Position, Owner, (int)&ButterFly[648 * i], SubType, LinkBone) == FALSE) return;
		}
	}
}

bool CreatePet_Process(int itemType, int modelType, float* Position, int Owner, int SubType, int LinkBone)
{
	return Process_CreatePet(PetProcess(), itemType, modelType, Position, Owner, SubType, LinkBone);
}

void RenderPetBugs()
{
	for (int i = 0; i<10; i++)
	{
		if (RenderPetScale1((int)&ButterFly[648 * i], false) == FALSE) { break; }
	}
	((void(__cdecl*)()) 0x00503950)();
}

void MovePetBugs()
{
	for (int i = 0; i<10; i++)
	{
		if (gCustomPet.PetsMovement((int)&ButterFly[648 * i], false) == FALSE) { break; }
	}

	((void(__cdecl*)()) 0x00503720)();
}

void Teleport_DelectBug(int Owner)
{
	Delect_FlyBug(Owner);
	((void(__cdecl*)(int)) 0x005012D0)(Owner);
}

void DeleteCharacter_DelectMuun(int c, int o)
{
	Delect_FlyBug(o);
	((void(__cdecl*)(int, int)) 0x0057D8B0)(c, o);
}

void ClearCharacters_DelectBug(int Key)
{
	for (int i = 0; i < 400; i++)
	{
		int c = CharactersClient(CList(), i);
		int o = c + 776;

		if (*(bool*)(o + 4) && *(WORD *)(c + 126) != Key)
		{
			Delect_FlyBug(o);
		}
	}
	((void(__cdecl*)(int)) 0x0057D620)(Key);
}

void DeleteCharacter_DelectBug(int Key)
{
	for (int i = 0; i < 400; i++)
	{
		int c = CharactersClient(CList(), i);
		int o = c + 776;

		if (*(bool*)(o + 4) && *(WORD *)(c + 126) == Key)
		{
			Delect_FlyBug(o);
		}
	}
	((void(__cdecl*)(int)) 0x0057D760)(Key);
}

void SetCharacterEffectEquip(int c)
{
	char v5; // [sp+3h] [bp-5h]@14
	int v3;
	int v6;

	if (*(DWORD *)(c + 824) == 1163)
	{
		int pt = 0; int dt = 0;
		for (int i = 0; i < 3; i++)
		{
			if (i == 0 || i == 1)
			{
				v6 = (DWORD)&Character_Machin->Equipment[i];
			}
			else
			{
				v6 = (DWORD)&Character_Machin->Equipment[EQUIPMENT_WING];
			}
			if (*(WORD *)v6 == 0xFFFF)
			{
				if (i == 0 || i == 1)
				{
					v6 = CharacterMachine_Equipment(i);
				}
				else
				{
					v6 = CharacterMachine_Equipment(EQUIPMENT_WING);
				}
			}
			if (*(WORD *)v6 == 0xFFFF)
				*(WORD *)(c + (pt * 36) + 448) = 0xFFFF;
			else
				*(WORD *)(c + (pt * 36) + 448) = *(WORD *)v6 + 1171;

			*(BYTE *)(c + (pt * 36) + 450) = (*(DWORD *)(v6 + 2) >> 3) & 0xF;
			if (i == 0 || i == 1)
			{
				*(BYTE *)(c + (pt * 36) + 451) = *(BYTE *)(v6 + 23);
				*(BYTE *)(c + (pt * 36) + 452) = *(BYTE *)(v6 + 24);
			}
			pt++;
		}
		v6 = CharacterMachine_Equipment(EQUIPMENT_HELPER);
		if (*(WORD *)v6 == 0xFFFF)
			*(WORD *)(c + 556) = 0xFFFF;
		else
			*(WORD *)(c + 556) = *(WORD *)v6 + 1171;
		v6 = (DWORD)&Character_Machin->Equipment[12];
		if (*(WORD *)v6 == 0xFFFF)
			*(WORD *)(c + 592) = 0xFFFF;
		else
			*(WORD *)(c + 592) = *(WORD *)v6 + 1171;

		//--
		v5 = 1;
		if (InChaosCastle(World) == 1)
			v5 = 0;
		if ((signed int)*(WORD *)(c + 794) >= 233 && (signed int)*(WORD *)(c + 794) <= 240)
			v5 = 0;
		if ((signed int)*(WORD *)(c + 794) >= 38 && (signed int)*(WORD *)(c + 794) <= 155)
			v5 = 0;
		if (v5)
			SetPlayerStop(c);
		//--
		pt = 0;
		for (int i = EQUIPMENT_HELM; i <= EQUIPMENT_BOOTS; i++)
		{
			v3 = (DWORD)&Character_Machin->Equipment[i];

			if (*(WORD *)v3 == 0xFFFF)
			{
				v3 = CharacterMachine_Equipment(i);
			}
			if (*(WORD *)v3 == 0xFFFF)
			{
				*(WORD *)(c + (pt * 36) + EQUIP_BODY_HELM) = (unsigned __int8)_GetSkinModelIndex(*(BYTE *)(c + 19)) + (pt * MODEL_BODY_NUM) + MODEL_BODY_HELM;
				*(BYTE *)(c + (pt * 36) + 270) = 0;
				*(BYTE *)(c + (pt * 36) + 271) = 0;
				*(BYTE *)(c + (pt * 36) + 272) = 0;
			}
			else
			{
				*(WORD *)(c + (pt * 36) + EQUIP_BODY_HELM) = *(WORD *)v3 + 1171;
				*(BYTE *)(c + (pt * 36) + 270) = (*(DWORD *)(v3 + 2) >> 3) & 0xF;
				*(BYTE *)(c + (pt * 36) + 271) = *(BYTE *)(v3 + 23);
				*(BYTE *)(c + (pt * 36) + 272) = *(BYTE *)(v3 + 24);
			}
			pt++;
		}
		((void(__cdecl*)(int)) 0x004E6670)(c);
		ZzzCharacter_SetCharacterScale(c);
		if (c == Hero)
			((bool(__cdecl*)(int)) 0x00560D80)(Hero);
		((void(__thiscall*)(int)) 0x005958E0)(*(DWORD*)0x8128AC4);
	}
}

bool CNewUIMyInventory::NewUIManager_Render(int thls)
{
	bool ActiveObject = false;
	glAlphaFunc(GL_GREATER, 0.0f);

	ActiveObject = ((bool(__thiscall*)(int)) 0x00815DB0)(thls);

	glAlphaFunc(GL_GREATER, 0.25f);

	return ActiveObject;
}

void CNewUIMyInventory::LoadImages()
{
	((void(__cdecl*)())0x00836A60)();

	LoadBitmapA("Interface\\InGameShop\\ingame_Bt_page_L.tga", 32342, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\InGameShop\\ingame_Bt_page_R.tga", 32343, GL_LINEAR, GL_CLAMP, 1, 0);

	//LoadBitmapA("Interface\\newui_item_earring.tga", 891551, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\newui_item_muunv2.tga", 891552, GL_LINEAR, GL_CLAMP, 1, 0);
	//LoadBitmapA("Interface\\newui_item_earring1.tga", 891553, GL_LINEAR, GL_CLAMP, 1, 0);
	//LoadBitmapA("Interface\\newui_item_muunv21.tga", 891554, GL_LINEAR, GL_CLAMP, 1, 0);

	//LoadBitmapA("Interface\\GFx\\newui_item_pentagram.tga", 61550, GL_LINEAR, GL_CLAMP, 1, 0);
	//LoadBitmapA("Interface\\GFx\\newui_item_earring.tga", 61551, GL_LINEAR, GL_CLAMP, 1, 0);
	//LoadBitmapA("Interface\\GFx\\none.tga", 81551, GL_LINEAR, GL_CLAMP, 1, 0);
	Character_Machin = new CCharacterMachine;
}

void CNewUIMyInventory::ReceiveInventory(BYTE *ReceiveBuffer)
{
	Character_Machin->UnequipAllItems();
	LPPHEADER_DEFAULT_SUBCODE_WORD DataRecv = (LPPHEADER_DEFAULT_SUBCODE_WORD)ReceiveBuffer;
	int Offset = sizeof(PHEADER_DEFAULT_SUBCODE_WORD);

	for (int i = 0; i < DataRecv->Value; i++)
	{
		LPPRECEIVE_INVENTORY Data = (LPPRECEIVE_INVENTORY)(ReceiveBuffer + Offset);

		Character_Machin->EquipItem(Data->Index, Data->Item);
		Offset += sizeof(PRECEIVE_INVENTORY);
	}
}

void CNewUIMyInventory::ReceiveDurability(BYTE *ReceiveBuffer)
{
	LPPHEADER_DEFAULT_VALUE_DUR Data = (LPPHEADER_DEFAULT_VALUE_DUR)ReceiveBuffer;
	if (Data->Key != 0xFF)
	{
		zITEM* ip = &Character_Machin->Equipment[Data->Key];
		if (ip->Type != 65535)
		{
			ip->Durability = Data->Value;
		}
	}
}

void CNewUIMyInventory::ReceiveDeleteInventory(BYTE *ReceiveBuffer)
{
	LPPHEADER_DEFAULT_SUBCODE Data = (LPPHEADER_DEFAULT_SUBCODE)ReceiveBuffer;

	if (Data->SubCode != 0xff)
	{
		if (ms_pPickedItem)
		{
			DeletePickedItem();
			return;
		}
		Character_Machin->Unequip_Item(Data->SubCode);
	}

	if (Data->Value)
	{
		//EnableUse = 0;
	}
}

bool g_CheckBugLive(OBJECT* Owner, int Index)
{
	BYTE* Butterfles = (BYTE*)0x8791550;

	for (int i = 0; i < 10; i++)
	{
		OBJECT* o = (OBJECT*)&Butterfles[648 * i];

		if (o->Owner == Owner && o->Type == Index)
		{
			if (o->Live)
			{
				return true;
			}
		}
	}
	return false;
}

void g_DeleteMuunBug(OBJECT* Owner, int Index)
{
	BYTE* Butterfles = (BYTE*)0x8791550;

	for (int i = 0; i < 10; i++)
	{
		OBJECT* o = (OBJECT*)&Butterfles[648 * i];
		int type = gCustomPet2.GetInfoPetType(o->Type - 1171);

		if (o->Owner == Owner &&
			(o->Type != Index &&
			o->Type != MODEL_FENRIR_BLACK &&
			o->Type != MODEL_FENRIR_RED &&
			o->Type != MODEL_FENRIR_BLUE &&
			o->Type != MODEL_FENRIR_GOLD &&
			o->Type != MODEL_DARK_HORSE &&
			o->Type != MODEL_PEGASUS &&
			o->Type != MODEL_UNICON &&
			o->Type != MODEL_BUTTERFLY01 &&
			(type == 8 && type > -1)))
		{
			o->Live = false;
		}
	}
}

void CNewUIMyInventory::ReceiveItemChange(BYTE *ReceiveBuffer)
{
	LPPSCHANGE_CHARACTER Data = (LPPSCHANGE_CHARACTER)ReceiveBuffer;

	int Key = ((int)(Data->KeyH) << 8) + Data->KeyL;

	int c = CharactersClient(CList(), FindCharacterIndex(Key));

	if (c == NULL) { return; }

	int Type = ConvertItemType(Data->Item);
	BYTE Level = Data->Item[1] & 0xF;
	BYTE Option = Data->Item[3] & 63;
	BYTE ExtOption = Data->Item[4];

	OBJECT* pHeroObject = &*(OBJECT*)(c + 776);

	switch (Data->Item[1] >> 4)
	{
	case 12:
		if (Type == 0x1FFF)
		{
			g_DeleteMuunBug(pHeroObject, *(WORD*)(c + 556));
		}
		else
		{
			if (!g_CheckBugLive(pHeroObject, Type + 1171))
			{
				CreateBug(Type + 1171, pHeroObject->Position, pHeroObject, 0, 0);
			}
		}
		break;
	}

	ChangeChaosCastleUnit(c);
	ZzzCharacter_SetCharacterScale(c);
}

char ResetEquipmentLevel(int thisa)
{
	int v3; // ST08_4@1

	int pt = 0;
	for (int i = EQUIPMENT_WEAPON_RIGHT; i <= EQUIPMENT_BOOTS; i++)
	{
		v3 = (DWORD)&Character_Machin->Equipment[i];

		if (*(WORD *)v3 == 0xFFFF)
		{
			v3 = CharacterMachine_Equipment(i);
		}
		if (i >= EQUIPMENT_HELM)
		{
			if (*(WORD *)v3 == 0xFFFF)
			{
				*(BYTE *)(Hero + (pt * 36) + 270) = 0;
			}
			else
			{
				*(BYTE *)(Hero + (pt * 36) + 270) = (*(DWORD *)(v3 + 2) >> 3) & 0xF;
			}
			pt++;
		}
		else
		{
			if (*(WORD *)v3 == 0xFFFF)
			{
				*(BYTE *)(Hero + (i * 36) + 450) = 0;
			}
			else
			{
				*(BYTE *)(Hero + (i * 36) + 450) = (*(DWORD *)(v3 + 2) >> 3) & 0xF;
			}
		}
	}
	return ((bool(__cdecl*)(int)) 0x00560D80)(Hero);
}

void CNewUIMyInventory::SetButtonInfo(DWORD thlsa)
{
	((void(__thiscall*)(DWORD))0x00836880)(thlsa);

	POINT m_Pos;

	m_Pos.x = *(DWORD*)(thlsa + 36);
	m_Pos.y = *(DWORD*)(thlsa + 40);

	m_BtnMove[0] = new DNewUIButton;
	m_BtnMove[1] = new DNewUIButton;
	//--
	//m_BtnMove[0]->ChangeButtonImgState(1, 32342, 1, 0, 0);
	//m_BtnMove[1]->ChangeButtonImgState(1, 32343, 1, 0, 0);
	//m_BtnMove[0]->ChangeButtonInfo2(m_Pos.x + 30, m_Pos.y + 5, 20, 23);
	//m_BtnMove[1]->ChangeButtonInfo2(m_Pos.x + 140, m_Pos.y + 5, 20, 23);
}

void CNewUIMyInventory::SetEquipmentSlotInfo(DWORD thisa)
{
	POINT m_Pos;

	m_Pos.x = *(DWORD*)(thisa + 36);
	m_Pos.y = *(DWORD*)(thisa + 40);

	//if (m_BtnMove[0] != NULL && m_BtnMove[1] != NULL)
	//{
	//	m_BtnMove[0]->ChangeButtonInfo2(m_Pos.x + 30, m_Pos.y + 5, 20, 23);
	//	m_BtnMove[1]->ChangeButtonInfo2(m_Pos.x + 140, m_Pos.y + 5, 20, 23);
	//}
	/*	//-- Slot
	if(gProtect.m_MainInfo.CustomInterfaceType == 0)
	{
	g_pNewMyInventory.SetEquipmentSlotInfo(EQUIPMENT_PET_1, 891552, m_Pos.x+54, m_Pos.y+62, 28, 28);
	g_pNewMyInventory.SetEquipmentSlotInfo(EQUIPMENT_ERRING_RIGHT, 891551, m_Pos.x+54, m_Pos.y+118, 28, 28);
	g_pNewMyInventory.SetEquipmentSlotInfo(EQUIPMENT_ERRING_LEFT, 891551, m_Pos.x+114, m_Pos.y+118, 28, 28);
	}
	else if(gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
	g_pNewMyInventory.SetEquipmentSlotInfo(EQUIPMENT_PET_1, 891552, m_Pos.x+54, m_Pos.y+62, 28, 28);
	g_pNewMyInventory.SetEquipmentSlotInfo(EQUIPMENT_ERRING_RIGHT, 891551, m_Pos.x+54, m_Pos.y+118, 28, 28);
	g_pNewMyInventory.SetEquipmentSlotInfo(EQUIPMENT_ERRING_LEFT, 891551, m_Pos.x+114, m_Pos.y+118, 28, 28);
	}
	else if(gProtect.m_MainInfo.CustomInterfaceType == 3) //-- ẽ700? yes
	{
	g_pNewMyInventory.SetEquipmentSlotInfo(EQUIPMENT_PET_1, 891554, m_Pos.x+74, m_Pos.y+62, 28, 28);
	g_pNewMyInventory.SetEquipmentSlotInfo(EQUIPMENT_ERRING_RIGHT, 891553, m_Pos.x+74, m_Pos.y+99, 28, 28);
	g_pNewMyInventory.SetEquipmentSlotInfo(EQUIPMENT_ERRING_LEFT, 891553, m_Pos.x+123, m_Pos.y+99, 28, 28);
	}*/

	//-- pet
	m_Slots[0].x = m_Pos.x + 54;
	m_Slots[0].y = m_Pos.y + 62;
	m_Slots[0].width = 28;
	m_Slots[0].height = 28;
	m_Slots[0].dwBgImage = 891552;
	//////-- earring
	//m_Slots[1].x = m_Pos.x + 54;
	//m_Slots[1].y = m_Pos.y + 118;
	//m_Slots[1].width = 28;
	//m_Slots[1].height = 28;
	//m_Slots[1].dwBgImage = 891551;

	//m_Slots[2].x = m_Pos.x + 114;
	//m_Slots[2].y = m_Pos.y + 118;
	//m_Slots[2].width = 28;
	//m_Slots[2].height = 28;
	//m_Slots[2].dwBgImage = 891551;

	((void(__thiscall*)(DWORD))0x00836510)(thisa);
}

void CNewUIMyInventory::RenderFrame(DWORD thisa)
{
	((void(__thiscall*)(DWORD))0x00836EC0)(thisa);

	m_BtnMove[0]->Render();
	m_BtnMove[1]->Render();
}

bool CNewUIMyInventory::EquipmentWindowProcess(DWORD thisa)
{
	//if (m_BtnMove[0]->UpdateMouseEvent())
	//{
	//	TypeInventory = (TypeInventory == 1) ? 2 : 1;
	//	PlayBuffer(25, 0, 0);
	//	return true;
	//}
	//if (m_BtnMove[1]->UpdateMouseEvent())
	//{
	//	TypeInventory = (TypeInventory == 2) ? 1 : 2;
	//	PlayBuffer(25, 0, 0);
	//	return true;
	//}
	int m_iPointedSlot = *(DWORD*)(thisa + 284);
	int InitPointed = (TypeInventory == 1) ? EQUIPMENT_WEAPON_RIGHT : EQUIPMENT_HELPER;

	if (Character_Machin->UnEquipmentWindowProcess(m_iPointedSlot, TypeInventory))
	{
		return true;
	}

	if ((m_iPointedSlot >= EQUIPMENT_WEAPON_RIGHT && m_iPointedSlot < InitPointed) || m_iPointedSlot >= MAX_EQUIPMENT_INDEX)
	{
		if (Character_Machin->EquipmentWindowProcess())
		{
			return true;
		}
	}
	else
	{
		if (m_iPointedSlot != -1 && IsRelease(VK_LBUTTON))
		{
			int pPickedItem = GetPickedItem();

			if (pPickedItem)
			{
				int pOwner = GetOwnerInventory(pPickedItem);
				if (pOwner == NULL)
				{
					zITEM* ip = (zITEM*)pPicked_GetItem(pPickedItem);

					if (ip->ex_src_type == ITEM_EX_SRC_EQUIPMENT2 && EquipmentItem == false)
					{
						if (Is_EquipItem(m_iPointedSlot, (int)ip))
						{
							if (GetSourceLinealPos(GetPickedItem()) == m_iPointedSlot)
							{
								SendRequestEquipment(40, ip->lineal_pos, (int)ip, 0, m_iPointedSlot);
								return true;
							}
							BackupPickedItem();
						}
					}
				}
			}
		}
		return ((bool(__thiscall*)(DWORD)) 0x00837A30)(thisa);
	}
	return false;
}

int FindItemOwner(void* thisa, int v24)
{
	if (v24 == NULL)
	{
		return -1;
	}
	signed int i;
	int v9;
	int v10;

	v10 = 0; v9 = -1;
	int a7 = 0;
	for (i = sub_83CBE0(thisa); a7 < i; i = sub_83CBE0(thisa))
	{
		if (FindItemAtPt_ctrl(*((DWORD **)thisa + a7 + 6), MouseX, MouseY) == v24)
		{
			v9 = (int)(*((DWORD **)thisa + a7 + 6));
			break;
		}
		++a7;
	}
	return v9;
}

#include "Central.h"

bool CNewUIMyInventory::InventoryProcess(int thisa)
{

	if (!pCheckInMouse(0, 0, CGetScreenWidth2(), 429))
	{
		if (IsRepeat(VK_CONTROL) && IsPress(VK_RBUTTON) && GetRepairMode() != REPAIR_MODE_ON && EquipmentItem == false)
		{
			if (GetPickedItem() == NULL)
			{
				ResetMouseRButton();

				int iSrcIndex, v7; zITEM* ip;

				ip = (zITEM*)FindItemAtPt((void*)thisa, MouseX, MouseY, &v7);

				if (ip != NULL)
				{
					iSrcIndex = GetSlotIndexAtPt(ip->x, ip->y, v7);

					SendRequestEquipment(50, iSrcIndex + 12, (int)ip, 50, iSrcIndex + 12);
				}
				return true;
			}
		}
		else
		{
			if (IsPress(VK_RBUTTON) && GetRepairMode() != REPAIR_MODE_ON && EquipmentItem == false)
			{
				if (GetPickedItem() == NULL)
				{
					int v24, v7; int iSrcType, iSrcIndex, iDstType, nDstIndex;
					bool bEquipable = false;

					if (g_pNewUISystem.IsVisible(8) || g_pNewUISystem.IsVisible(7)) //-- bauls
					{
						goto LABEL_45;
					}
					else
					{
						v7 = -1;
						zITEM* ip;
						int Machine = pGetUIChaosMachine(GetInstance());
						bEquipable = false; int pOwner = NULL;
						int MixRecipe = GetMixInventoryEquipmentIndex(g_MixRecipeMgr);

						if (g_pNewUISystem.IsVisible(9)) //-- chaos machine
						{
							if (pCheckInMouse(*(DWORD *)(Machine + 20), *(DWORD *)(Machine + 24), 190, 429))
							{
								ip = (zITEM*)FindItemAtPt_ctrl((void*)*(DWORD **)(Machine + 16), MouseX, MouseY);
								if (ip)
								{
									iSrcType = MixRecipe;
									iSrcIndex = ip->x + ip->y * 8;
									iDstType = REQUEST_INVENTORY;
									nDstIndex = MyFindEmptySlot(thisa, (int)ip, 0);

									if (nDstIndex != -1)
									{
										bEquipable = true;
										pOwner = (int)(*(DWORD **)(Machine + 16));
									}
								}
							}
							else
							{
								ip = (zITEM*)FindItemAtPt((void*)thisa, MouseX, MouseY, &v7);

								if (ip)
								{
									ITEM_ATTRIBUTE* pItemAttr = ItemAttribute(ip->Type);
									iSrcType = REQUEST_INVENTORY;
									iSrcIndex = GetSlotIndexAtPt(ip->x, ip->y, v7);
									{
										CStreamPacketEngine p;

										p.Init(0xC1, 0x26);
										p.Rightshift1((BYTE)(iSrcIndex + 12)); // inventory slot bên server
										p.Rightshift1((BYTE)0xFF);             // TargetSlot
										p.Rightshift1((BYTE)0);                // type

										p.Send(TRUE);

										ResetMouseRButton();
										return true;
									}
									iDstType = MixRecipe;
									nDstIndex = FindEmptySlot_ctrl((void*)*(DWORD *)(Machine + 16), pItemAttr->Width, pItemAttr->Height);

									if (nDstIndex != -1)
									{
										bEquipable = true;
										pOwner = FindItemOwner((void*)thisa, (int)ip);
									}
								}
							}
						}
						else
						{
							ip = (zITEM*)FindItemAtPt((void*)thisa, MouseX, MouseY, &v7);

							if (ip)
							{
								iSrcType = REQUEST_INVENTORY;
								iSrcIndex = GetSlotIndexAtPt(ip->x, ip->y, v7);

								int ItemLevel = ((*(DWORD*)((BYTE*)ip + 2)) >> 3) & 15;

								if (ip->Type == ITEM(14, 11) && ItemLevel >= 8 && ItemLevel <= 12)
								{
									CStreamPacketEngine p;

									p.Init(0xC1, 0x26);
									p.Rightshift1((BYTE)(iSrcIndex + 12));
									p.Rightshift1((BYTE)0xFF);
									p.Rightshift1((BYTE)0);

									p.Send(TRUE);

									ResetMouseRButton();
									return true;
								}

								ITEM_ATTRIBUTE* pItemAttr = ItemAttribute(ip->Type);

								nDstIndex = pItemAttr->m_byItemSlot;

								if (nDstIndex >= 0 && nDstIndex < 15)
								{
									if (TypeInventory == 1)
										iDstType = (nDstIndex >= 12) ? REQUEST_EQUIPMENT : REQUEST_INVENTORY;
									else
										iDstType = ((nDstIndex >= 0 && nDstIndex < 8) || nDstIndex >= 12) ? REQUEST_EQUIPMENT : REQUEST_INVENTORY;

									if (iDstType == REQUEST_INVENTORY)
									{
										bEquipable = Is_EquipItem(nDstIndex, (int)ip);
										v24 = CharacterMachine_Equipment(nDstIndex);

										if (*(WORD *)v24 != 0xFFFF && ((nDstIndex == 0 && !pItemAttr->TwoHand) || nDstIndex == 10))
										{
											nDstIndex += 1;
										}

										if (*(WORD *)v24 != 0xFFFF)
										{
											bEquipable = false;
										}
									}
									else if (iDstType == REQUEST_EQUIPMENT)
									{
										bEquipable = Character_Machin->IsEquipable(nDstIndex, ip);

										v24 = (DWORD)&Character_Machin->Equipment[nDstIndex];

										if (*(WORD *)v24 != 0xFFFF && nDstIndex == 0 && !pItemAttr->TwoHand)
										{
											nDstIndex += 1;
											v24 = (DWORD)&Character_Machin->Equipment[nDstIndex];
										}

										if (*(WORD *)v24 != 0xFFFF)
										{
											bEquipable = false;
										}
									}
								}
								else
								{
									bEquipable = false;
								}

								if (bEquipable == true)
								{
									pOwner = FindItemOwner((void*)thisa, (int)ip);
								}
							}
						}

						if (bEquipable == true)
						{
							if (pOwner)
							{
								if (CreatePickedItem(pOwner, ip))
								{
									if (iSrcType == REQUEST_INVENTORY)
									{
										RemoveItemForSlot(thisa, iSrcIndex);
										SendRequestEquipment(iSrcType, iSrcIndex + 12, (int)ip, iDstType, nDstIndex);
									}
									else if (iSrcType == MixRecipe)
									{
										RemoveItem_ctrl(pOwner, (int)ip);
										SendRequestEquipment(iSrcType, iSrcIndex, (int)ip, iDstType, nDstIndex + 12);
									}
									HidePickedItem(GetPickedItem());
									playSound(29, 0, 0);
									return true;
								}
							}
						}
					}
				}
			}
		}
	}
LABEL_45:
	return ((bool(__thiscall*)(int)) 0x00838240)(thisa);
}

void CNewUIMyInventory::RenderItemToolTip(int thisa, int iSlotIndex)
{
	int InitPointed = (TypeInventory == 1) ? 0 : 8;
	int m_iPointedSlot = *(DWORD *)(thisa + 284);

	if (m_iPointedSlot != -1)
	{
		int v24;
		if ((m_iPointedSlot >= 0 && m_iPointedSlot < InitPointed) || m_iPointedSlot >= 12)
		{
			v24 = (DWORD)&Character_Machin->Equipment[m_iPointedSlot];
		}
		else
		{
			v24 = CharacterMachine_Equipment(m_iPointedSlot);
		}

		int targetcx, targetcy;
		if (v24 != NULL && *(WORD *)v24 != 0xFFFF)
		{
			*(BYTE *)(v24 + 66) = iSlotIndex;
			if (m_iPointedSlot >= 12)
			{
				targetcx = m_Slots[m_iPointedSlot - 12].x + m_Slots[m_iPointedSlot - 12].width / 2;
				targetcy = m_Slots[m_iPointedSlot - 12].y + m_Slots[m_iPointedSlot - 12].height / 2;
			}
			else
			{
				targetcx = *(DWORD *)(thisa + 20 * m_iPointedSlot + 44) + (*(DWORD *)(thisa + 20 * m_iPointedSlot + 52) / 2);
				targetcy = *(DWORD *)(thisa + 20 * m_iPointedSlot + 48) + (*(DWORD *)(thisa + 20 * m_iPointedSlot + 56) / 2);
			}

			if (*(DWORD *)(thisa + 1020))
			{
				RenderRepairInfo(targetcx, targetcy, v24, false);
			}
			else
			{
				RenderItemInfo_(GetUI3D(GetInstance()), targetcx, targetcy, v24, false, 0, false);
			}
		}
	}
}

void CNewUIMyInventory::Render3D(signed int *thisa)
{
	float height;
	float width;
	float x, y;
	signed int *v5;
	int v7;
	signed int i;

	v5 = thisa;
	int  InitPointed = (TypeInventory == 1) ? 0 : 8;

	for (i = 0; i < 15; ++i)
	{
		if (i < 12)
		{
			v7 = (i < InitPointed) ? (DWORD)&Character_Machin->Equipment[i] : CharacterMachine_Equipment(i);

			if (v7 != NULL && (signed int)*(WORD *)v7 >= 0)
			{
				y = (i == 3) ? ((double)v5[24] - 10.0) : ((double)v5[5 * i + 9]);

				glColor4f(1.0, 1.0, 1.0, 1.0);
				height = (double)(v5[5 * i + 11] - 4);
				width = (double)(v5[5 * i + 10] - 4);
				x = (double)(v5[5 * i + 8] + 1);
				CRenderItem3D(x, y, width, height, *(WORD *)v7, *(DWORD *)(v7 + 2), *(BYTE *)(v7 + 23), *(BYTE *)(v7 + 24), 0);
			}
		}
		else
		{
			v7 = (DWORD)&Character_Machin->Equipment[i];

			if ((signed int)*(WORD *)v7 >= 0)
			{
				int j = i - 12;
				y = (double)m_Slots[j].y;
				glColor4f(1.0, 1.0, 1.0, 1.0);
				height = (double)(m_Slots[j].height - 4);
				width = (double)(m_Slots[j].width - 4);
				x = (double)m_Slots[j].x + 1;
				CRenderItem3D(x, y, width, height, *(WORD *)v7, *(DWORD *)(v7 + 2), *(BYTE *)(v7 + 23), *(BYTE *)(v7 + 24), 0);
			}
		}
	}
}

bool CNewUIMyInventory::Update(DWORD *a1)
{
	int i, v5;
	DWORD *v3; signed int j;

	v3 = a1; v5 = 0;
	for (i = sub_83CBE0(a1); v5 < i; i = sub_83CBE0(v3))
	{
		if (v3[v5 + 6] && !MyInventory_Update((void *)v3[v5 + 6]))
			return 0;
		++v5;
	}
	if ((unsigned __int8)(*(int(__thiscall **)(DWORD *))(*v3 + 24))(v3))
	{
		v3[71] = -1;
		for (j = 0; j < 15; ++j)
		{

			if (j >= 12)
			{
				if (pCheckInMouse(m_Slots[j - 12].x + 1, m_Slots[j - 12].y,
					m_Slots[j - 12].width - 4, m_Slots[j - 12].height - 4))
				{
					v3[71] = j;
					return 1;
				}
			}
			else
			{
				if (pCheckInMouse(v3[5 * j + 11] + 1, v3[5 * j + 12], v3[5 * j + 13] - 4, v3[5 * j + 14] - 4))
				{
					v3[71] = j;
					return 1;
				}
			}
			v3[71] = -1;
		}
	}
	return 1;
}

void CNewUIMyInventory::RenderDetailsText(int thisa, int iPos_x, int iPos_y, LPCSTR pszText, int iBoxWidth, int iBoxHeight, int iSort, OUT SIZE* lpTextSize)
{
	char pszText_1[256];
	sprintf_s(pszText_1, "%s [ %d ]", pszText, TypeInventory);
	((void(__thiscall*)(int, int, int, LPCSTR, int, int, int, OUT SIZE *))0x00420150)(
		thisa, iPos_x, iPos_y, pszText_1, 190, iBoxHeight, iSort, lpTextSize);
}

void CNewUIMyInventory::RenderEquipped(GLuint uiImageType, float x, float y, float width, float height)
{
	if (uiImageType == 31358 || uiImageType == 31359 || uiImageType == 31360
		|| uiImageType == 31365 || uiImageType == 31366 || uiImageType == 61550)
	{
		CRenderBitmaps(uiImageType, x, y, width, height, 0.0, 0.0, 46.f / 64.f, 46.f / 64.f, true, true, 0.0);
	}
	else if (uiImageType == 31362 || uiImageType == 31363 || uiImageType == 31364)
	{
		CRenderBitmaps(uiImageType, x, y, width, height, 0.0, 0.0, 46.f / 64.f, 66.f / 128.f, true, true, 0.0);
	}
	else if (uiImageType == 31361)
	{
		CRenderBitmaps(uiImageType, x, y, width, height, 0.0, 0.0, 61.f / 64.f, 46.f / 64.f, true, true, 0.0);
	}
	else
	{
		CRenderBitmaps(uiImageType, x, y, width, height, 0.0, 0.0, 28.f / 32.f, 28.f / 32.f, true, true, 0.0);
	}
}

void CNewUIMyInventory::RenderEquippedItem(DWORD thisa)
{
	int  InitPointed = (TypeInventory == 1) ? 0 : 8;
	int m_iPointedSlot = *(DWORD *)(thisa + 284);

	int v32 = (int)thisa;
	float cx, cy, width, height;
	BYTE byFirstClass = GetBaseClass(*(BYTE *)(Hero + 19));

	for (int i = 0; i < 15; i++)
	{
		if ((i == 2 && byFirstClass == 3)
			|| (i == 5 && byFirstClass == 6))
		{
			continue;
		}

		EnableAlphaTest(true);
		if (i < 12)
		{
			height = (double)*((signed int *)v32 + 5 * i + 14);
			width = (double)*((signed int *)v32 + 5 * i + 13);
			cy = (double)*((signed int *)v32 + 5 * i + 12);
			cx = (double)*((signed int *)v32 + 5 * i + 11);
			RenderEquipped(*((DWORD *)v32 + 5 * i + 15), cx, cy, width, height);
		}
		else
		{
			height = (double)m_Slots[i - 12].height;
			width = (double)m_Slots[i - 12].width;
			cy = (double)m_Slots[i - 12].y;
			cx = (double)m_Slots[i - 12].x;
			RenderEquipped(m_Slots[i - 12].dwBgImage, cx, cy, width, height);
		}
		DisableAlphaBlend();

		int v41;
		if ((i >= 0 && i < InitPointed) || i >= 12)
		{
			v41 = (DWORD)&Character_Machin->Equipment[i];
		}
		else
		{
			v41 = CharacterMachine_Equipment(i);
		}

		if (*(WORD *)v41 != 0xFFFF)
		{
			ITEM_ATTRIBUTE* pItemAttr = ItemAttribute(*(WORD *)v41);
			int iLevel = (*(DWORD *)(v41 + 2) >> 3) & 15;
			int iMaxDurability = calcMaxDurability(v41, pItemAttr, iLevel);

			if (i != 11 && i != 10 || (*(WORD *)v41 != 6676 || iLevel != 1) && iLevel != 2)
			{
				if (*(BYTE *)(v41 + 97) != 1 || *(BYTE *)(v41 + 98))
				{
					if ((signed int)*(BYTE *)(v41 + 22) > 0)
					{
						if ((double)iMaxDurability * 0.2f < (double)*(BYTE *)(v41 + 22))
						{
							if ((double)iMaxDurability * 0.3f < (double)*(BYTE *)(v41 + 22))
							{
								if ((double)iMaxDurability * 0.5 < (double)*(BYTE *)(v41 + 22))
								{
									if ((m_iPointedSlot >= 0 && m_iPointedSlot < InitPointed)
										|| i >= 12)
									{
										if (Character_Machin->IsEquipable(i, (zITEM*)v41))
											continue;
									}
									else
									{
										if (Is_EquipItem(i, v41))
											continue;
									}
									glColor4f(1.0, 0.0, 0.0, 0.25);
								}
								else
								{
									glColor4f(1.0, 1.0, 0.0, 0.25);
								}
							}
							else
							{
								glColor4f(1.0, 0.5, 0.0, 0.25);
							}
						}
						else
						{
							glColor4f(1.f, 0.15f, 0.f, 0.25f);
						}
					}
					else
					{
						glColor4f(1.0, 0.0, 0.0, 0.25);
					}
					EnableAlphaTest(true);
					RenderColor(cx + 1, cy + 1, width - 4, height - 4, 0.0, 0);
					EndRenderColor();
				}
			}
		}
	}
	int pPickedItem = GetPickedItem();

	if (pPickedItem)
	{
		if (m_iPointedSlot != -1)
		{
			int v23 = pPicked_GetItem(pPickedItem); int v24;

			if (v23)
			{
				bool equipa = false;
				if ((m_iPointedSlot >= 0 && m_iPointedSlot < InitPointed) || m_iPointedSlot >= 12)
				{
					equipa = Character_Machin->IsEquipable(m_iPointedSlot, (zITEM*)v23);
					v24 = (DWORD)&Character_Machin->Equipment[m_iPointedSlot];
				}
				else
				{
					equipa = Is_EquipItem(m_iPointedSlot, v23);
					v24 = CharacterMachine_Equipment(m_iPointedSlot);
				}

				if ((*(WORD *)v24 != 0xFFFF || !equipa)
					&& ((byFirstClass != 6 || m_iPointedSlot != 5) && (byFirstClass != 3 || m_iPointedSlot != 2)))
				{
					glColor4f(0.89999998, 0.1, 0.1, 0.40000001);

					if (m_iPointedSlot >= 12)
					{
						height = (double)m_Slots[m_iPointedSlot - 12].height;
						width = (double)m_Slots[m_iPointedSlot - 12].width;
						cy = (double)m_Slots[m_iPointedSlot - 12].y;
						cx = (double)m_Slots[m_iPointedSlot - 12].x;
					}
					else
					{
						height = (double)(*(DWORD *)(v32 + 20 * m_iPointedSlot + 56));
						width = (double)(*(DWORD *)(v32 + 20 * m_iPointedSlot + 52));
						cy = (double)*(signed int *)(v32 + 20 * m_iPointedSlot + 48);
						cx = (double)(*(DWORD *)(v32 + 20 * m_iPointedSlot + 44));
					}
					EnableAlphaTest(true);
					RenderColor(cx + 1, cy + 1, width - 4, height - 4, 0.0, 0);
					EndRenderColor();
				}
			}
		}
	}
	else
	{
		if (m_iPointedSlot != -1 && *(DWORD *)(v32 + 20))
		{
			if (m_iPointedSlot != *(DWORD *)(v32 + 1032))
			{
				if (m_iPointedSlot == 8)
				{
					if (*(WORD *)(*(DWORD *)0x8128AC4 + 5528) == 6660)
					{
						CStreamPacketEngine spe;
						spe.Init(0xC1, 0xA9);
						spe.Rightshift1(1);
						spe.Rightshift1(0);
						spe.Rightshift1(8);
						spe.Send(0, 0);
					}
				}
				else if (m_iPointedSlot == 1 && TypeInventory == 1)
				{
					if (*(WORD *)(*(DWORD *)0x8128AC4 + 4779) == 6661)
					{
						CStreamPacketEngine spe;
						spe.Init(0xC1, 0xA9);
						spe.Rightshift1(01);
						spe.Rightshift1(0);
						spe.Rightshift1(1);
						spe.Send(0, 0);
					}
				}
			}
			RenderUI2DEffect(*(DWORD *)(v32 + 20), 5.5, UI2DEffectCallEquip, (LPVOID)v32, m_iPointedSlot, 0);
		}
	}
}
#include "PetHook.h"
#define sub_404B60					((void (__cdecl*)( )) 0x00404B60)
#define sub_4F8C30					((DWORD(__cdecl*)(DWORD)) 0x4F8C30)
#define sub_4FA780					((int(__thiscall*)(int This, int a2)) 0x4FA780)
#define pGetPetInfo					((int(__cdecl*)(char a1)) 0x4F9930)

void CNewUIMyInventory::Backup_PickedItem()
{
	if (ms_pPickedItem && EquipmentItem == false)
	{
		int pOwner = GetOwnerInventory(ms_pPickedItem);
		int v9 = (int)GetMouseItem(ms_pPickedItem);
		if (pOwner)
		{
			pOwner_AddItem(pOwner, *(BYTE*)(v9 + 67), *(BYTE*)(v9 + 68), v9);
			DeletePickedItem();
		}
		else if (*(BYTE*)(v9 + 68) == ITEM_EX_SRC_EQUIPMENT1)
		{
			char* v8 = (char*)(*(DWORD*)0x8128AC4 + 107 * *(BYTE*)(v9 + 67) + 4672);
			memcpy(v8, (const void*)v9, 0x6Bu);
			//
			if (*(WORD*)v8 == 6660 || *(WORD*)v8 == 6661)
			{
				((void(__stdcall*)(int)) 0x00835E40)((int)v8);
			}
			else
			{
				gObjCreatePetEx((int)v8);
			}

			if (*(WORD*)v8 == 6661 && !InChaosCastle(World))
			{
				CStreamPacketEngine spe;
				spe.Init(0xC1, 0xA9);
				spe.Rightshift1(0);
				spe.Rightshift1(0);
				spe.Rightshift1(1);
				spe.Send(0, 0);
				sub_404B60();
				sub_4F8C30(*(DWORD*)0x7BC4F04);
				sub_4FA780(*(DWORD*)(*(DWORD*)0x7BC4F04 + 676), pGetPetInfo(*(char*)v8));
			}
			if (*(WORD*)v8 == 6660 && !InChaosCastle(World))
			{
				CStreamPacketEngine spe;
				spe.Init(0xC1, 0xA9);
				spe.Rightshift1(1);
				spe.Rightshift1(0);
				spe.Rightshift1(8);
				spe.Send(0, 0);
				sub_404B60();
			}
			DeletePickedItem();
		}
		else if (*(BYTE*)(v9 + 68) == ITEM_EX_SRC_EQUIPMENT2)
		{
			char* v8 = (char*)&Character_Machin->Equipment[*(BYTE*)(v9 + 67)];
			memcpy(v8, (const void*)v9, 0x6Bu);
			gObjCreatePetEx((int)v8);
			DeletePickedItem();
		}
	}
}

__declspec(naked) void Inventory_Process()
{
	static DWORD ex_src_type = -1;
	static DWORD addrjmp = 0x00838E7E;
	_asm
	{
		mov     edx, dword ptr ss : [ebp - 0x20]
			movzx   eax, byte ptr ds : [edx + 0x44]
			mov     ex_src_type, eax
	}

	if (ex_src_type == ITEM_EX_SRC_EQUIPMENT1 || ex_src_type == ITEM_EX_SRC_EQUIPMENT2)
	{
		addrjmp = 0x00838E7E;
	}
	else
	{
		addrjmp = 0x00838F24;
	}

	_asm
	{
		jmp[addrjmp]
	}
}

bool SendInventoryEquip(BYTE iSrcType, BYTE iSrcIndex, int ip, BYTE iDstType, BYTE iDstIndex)
{
	zITEM* IP = (zITEM*)ip;

	if (IP->ex_src_type == ITEM_EX_SRC_EQUIPMENT2)
	{
		iSrcType = REQUEST_EQUIPMENT;
	}
	return SendRequestEquipment(iSrcType, iSrcIndex, ip, iDstType, iDstIndex);
}

bool SendRequestStore(BYTE iSrcType, BYTE iSrcIndex, int ip, BYTE iDstType, BYTE iDstIndex)
{
	zITEM* IP = (zITEM*)ip;

	if (IP->ex_src_type == ITEM_EX_SRC_EQUIPMENT2)
	{
		iSrcType = 40;
	}
	return SendRequestEquipment(iSrcType, iSrcIndex, ip, iDstType, iDstIndex);
}

void SendRequestSetSalePrice(int pPickedItem, BYTE offset, int money)
{
	zITEM* ip = (zITEM*)pPicked_GetItem(pPickedItem);

	CStreamPacketEngine spe;
	spe.Init(0xC1, 0x3F);

	if (ip->ex_src_type == ITEM_EX_SRC_EQUIPMENT2)
		spe.Rightshift1((BYTE)0x09);
	else
		spe.Rightshift1((BYTE)0x01);
	spe.Rightshift1((BYTE)offset);
	spe.Rightshift3((INT)money);
	spe.Send(TRUE);
}

__declspec(naked) void PersonalShopItemValue_1()
{
	static DWORD addr = 0x0079AB01;

	_asm
	{
		mov      eax, dword ptr ss : [ebp - 0x1040]
			push     eax
			movzx    edx, byte ptr ss : [ebp - 0x1041]
			push     edx
			mov      ecx, dword ptr ss : [ebp - 0x18]
			push     ecx
			call[SendRequestSetSalePrice]
			JMP[addr]
	}
}

__declspec(naked) void PersonalShopItemValue_2()
{
	static DWORD addr = 0x007AFD5E;

	_asm
	{
		mov      eax, dword ptr ss : [ebp - 0x120]
			push     eax
			movzx    edx, byte ptr ss : [ebp - 0x1265]
			push     edx
			mov      ecx, dword ptr ss : [ebp - 0x23C]
			push     ecx
			call[SendRequestSetSalePrice]
			JMP[addr]
	}
}

__declspec(naked) void SendRequestItemToTrade_1()
{
	static DWORD addr = 0x00865532;
	static DWORD ex_src_type = 0;

	_asm
	{
		mov      edx, dword ptr ss : [ebp - 0x8]
			movzx    eax, byte ptr ds : [edx + 0x44]
			mov      ex_src_type, eax
	}

	addr = 0x00865532;
	if (ex_src_type == 1 || ex_src_type == 2)
	{
		addr = 0x008654DB;
	}

	_asm
	{
		JMP[addr]
	}
}

__declspec(naked) void Mix_Process()
{
	static DWORD addr = 0x00865532;
	static DWORD ex_src_type = 0;

	_asm
	{
		mov      ecx, dword ptr ss : [ebp - 0x8]
			movzx    edx, byte ptr ds : [ecx + 0x44]
			mov      ex_src_type, edx
	}

	addr = 0x0082F904;
	if (ex_src_type == 1 || ex_src_type == 2)
	{
		addr = 0x0082F864;
	}

	_asm
	{
		JMP[addr]
	}
}

void SendRequestSell(int pPickedItem)
{
	int p_Index = GetSourceLinealPos(pPickedItem);
	zITEM* ip = (zITEM*)pPicked_GetItem(pPickedItem);

	CStreamPacketEngine spe;
	if (ip->ex_src_type == ITEM_EX_SRC_EQUIPMENT2)
	{
		p_Index = ip->lineal_pos;
		spe.Init(0xC1, 0x4E);
		spe.Rightshift1((BYTE)(0x0A));
		spe.Rightshift1((BYTE)(p_Index));
		spe.Send();
	}
	else
	{
		spe.Init(0xC1, 0x33);
		spe.Rightshift1((BYTE)(p_Index));
		spe.Send();
	}
	SetSellingItem(g_pNPCShop(GetInstance()), true);
}

__declspec(naked) void UpdateMouseNPCShop()
{
	static DWORD addr = 0x00847AC2;

	_asm
	{
		push     ecx
			call[SendRequestSell]
			JMP[addr]
	}
}
#include "Import.h"
#include "Protect.h"
BYTE PetEquipedHPBar(int iX, int iY, int mode)
{
	char result;

	int PetHP;

	int PetSlot = *(WORD*)(Hero + 556);

	int petmodo = gCustomPet2.GetInfoPetType(PetSlot - 1171);

	if ((PetSlot < 7827 || PetSlot > 7831)
		&& PetSlot != 7891
		&& PetSlot != 7892
		&& PetSlot != 7894
		&& PetSlot != 7907
		&& PetSlot != 7933
		&& PetSlot != 7950
		&& PetSlot != 7864
		&& (petmodo == -1))
	{
		result = 0;
	}
	else
	{
		ITEM_ATTRIBUTE *Attribute = ItemAttribute(PetSlot - 1171);

		char PetName[255] = { 0, };
		switch (PetSlot)
		{
		case 7827:
			wsprintf(PetName, pGetTextLine(pTextLineThis, 353));
			break;
		case 7828:
			wsprintf(PetName, (char *)oUserTextObject + 84 * (*(WORD *)(oUserPreviewStruct + 556) - 1171));
			break;
		case 7829:
			wsprintf(PetName, pGetTextLine(pTextLineThis, 355));
			break;
		case 7830:
			wsprintf(PetName, pGetTextLine(pTextLineThis, 354));
			break;
		case 7831:
			wsprintf(PetName, pGetTextLine(pTextLineThis, 1187));
			break;
		case 7864:
			wsprintf(PetName, pGetTextLine(pTextLineThis, 1916));
			break;
		case 7891:
			wsprintf(PetName, (char *)(oUserTextObject + 564480));
			break;
		case 7892:
			wsprintf(PetName, (char *)(oUserTextObject + 564564));
			break;
		case 7894:
			wsprintf(PetName, (char *)(oUserTextObject + 564732));
			break;
		case 7907:
			wsprintf(PetName, (char *)(oUserTextObject + 565824));
			break;
		case 7933:
			wsprintf(PetName, (char *)(oUserTextObject + 568008));
			break;
		case 7950:
			wsprintf(PetName, (char *)(oUserTextObject + 569436));
			break;
		default:
			wsprintf(PetName, (char *)oUserTextObject + 84 * (*(WORD *)(oUserPreviewStruct + 556) - 1171));
			break;
		}

		PetHP = *(BYTE*)(*(DWORD*)0x8128AC4 + 5550);

		int StartPosX = CGetScreenWidth2() - ((PartyNumber > 0) ? 125 : 60);


		sub_7DFA60(iX, iY, (int)&PetName, PetHP, 255, 0);

		result = 1;
	}

	return result;
}

BYTE RenderEquipPetLife(int sx, int sy)
{
	BYTE t = 0;
	int Type = Character_Machin->Equipment[12].Type;

	if (Type != 0xFFFF)
	{
		ITEM_ATTRIBUTE *Attribute = ItemAttribute(Type);
		BYTE Dur = Character_Machin->Equipment[12].Durability;

		int StartPosX = CGetScreenWidth2() - ((PartyNumber > 0) ? 125 : 60);

		CreateBarHP(sx, sy, Attribute->Name, Dur, 255, 0);;

		t = 1;
	}
	return t;
}

void CNewUIMyInventory::RenderLeft(int thisa)
{
	POINT g_dir; // eax@9

	g_dir.x = *(DWORD *)(thisa + 16);
	g_dir.y = *(DWORD *)(thisa + 20);

	if (Defineclass(*(BYTE *)(Hero + 19)) == 2 && RenderNumArrow(thisa, g_dir.x, g_dir.y))
	{
		g_dir.y += 11;
	}
	if (Defineclass(*(BYTE *)(Hero + 19)) == 4 && RenderEquipedPetLife(thisa, g_dir.x, g_dir.y))
	{
		g_dir.y += 24;
	}
	if (PetEquipedHPBar(g_dir.x, g_dir.y, 1))
	{
		g_dir.y += 24;
	}
#if(SLOTPET)
	if (RenderEquipPetLife(g_dir.x, g_dir.y))
	{
		g_dir.y += 24;
	}
#endif
	if (Defineclass(*(BYTE *)(Hero + 19)) == 2)
	{
		if (RenderSummonMonsterLife(thisa, g_dir.x, g_dir.y))
			g_dir.y += 24;
	};
}

void CNewUIMyInventory::Init()
{
	SetCompleteHook(0xE9, 0x00838E6E, &Inventory_Process);
	SetCompleteHook(0xE8, 0x00838F15, &SendInventoryEquip);

	SetCompleteHook(0xE8, 0x0048E504, &RenderPetScale1);
	SetCompleteHook(0xE8, 0x00503986, &RenderPetScale1);

	SetCompleteHook(0xE9, 0x0082F854, &Mix_Process);
	//SetCompleteHook(0xE9, 0x00847A4A, &UpdateMouseNPCShop);
	SetCompleteHook(0xE8, 0x0079AB1A, &SendRequestStore);
	SetCompleteHook(0xE8, 0x007AFD7D, &SendRequestStore);
	SetCompleteHook(0xE8, 0x0082F8F6, &SendRequestStore); //-- mix
	//SetCompleteHook(0xE8, 0x00865697, &SendRequestStore); //-- trade
	SetCompleteHook(0xE9, 0x0079AA8A, &PersonalShopItemValue_1);
	SetCompleteHook(0xE9, 0x007AFCE7, &PersonalShopItemValue_2);
	SetCompleteHook(0xE9, 0x008654CF, &SendRequestItemToTrade_1);

	SetCompleteHook(0xE8, 0x008337A8, &CNewUIMyInventory::LoadImages);
	//SetCompleteHook(0xE8, 0x008337B8, &CNewUIMyInventory::SetButtonInfo);
	//SetCompleteHook(0xE8, 0x0083510E, &CNewUIMyInventory::RenderFrame);
	SetCompleteHook(0xE8, 0x0083469C, &CNewUIMyInventory::InventoryProcess); // EQUIP RIGHT CLICK
	SetCompleteHook(0xE8, 0x00834682, &CNewUIMyInventory::EquipmentWindowProcess);

	SetCompleteHook(0xE9, 0x00834FD0, &CNewUIMyInventory::Update);
	SetCompleteHook(0xE9, 0x008353D0, &CNewUIMyInventory::Render3D);
	SetCompleteHook(0xE8, 0x008370EE, &CNewUIMyInventory::RenderEquipped);
	SetCompleteHook(0xE8, 0x00835CDB, &CNewUIMyInventory::RenderItemToolTip);
	//SetCompleteHook(0xE8, 0x00837902, &CNewUIMyInventory::RenderDetailsText);
	SetCompleteHook(0xE8, 0x0083514C, &CNewUIMyInventory::RenderEquippedItem);
	SetCompleteHook(0xE8, 0x008337B0, &CNewUIMyInventory::SetEquipmentSlotInfo);
	SetCompleteHook(0xE8, 0x0083443C, &CNewUIMyInventory::SetEquipmentSlotInfo);

	SetCompleteHook(0xE8, 0x007850BA, &ResetEquipmentLevel);
	SetCompleteHook(0xE9, 0x0057F410, &SetCharacterEffectEquip);
	SetCompleteHook(0xE9, 0x007DD230, &CNewUIMyInventory::Backup_PickedItem);
	SetCompleteHook(0xE8, 0x00860B2F, &CNewUIMyInventory::NewUIManager_Render);

	//-- system pet
	SetCompleteHook(0xE8, 0x004D6EA5, &MovePetBugs);
	SetCompleteHook(0xE8, 0x004D7787, &MovePetBugs);
	SetCompleteHook(0xE8, 0x004D9568, &MovePetBugs);
	SetCompleteHook(0xE8, 0x004D7348, &RenderPetBugs);
	SetCompleteHook(0xE8, 0x004D7A98, &RenderPetBugs);
	SetCompleteHook(0xE8, 0x004D9A65, &RenderPetBugs);
	//--
	SetCompleteHook(0xE8, 0x00641777, &Teleport_DelectBug);
	SetCompleteHook(0xE8, 0x005604CA, &DeleteCharacter_DelectMuun);
	SetCompleteHook(0xE8, 0x0056F5B3, &DeleteCharacter_DelectMuun);
	SetCompleteHook(0xE8, 0x004E17F3, &DeleteCharacter_DelectBug);
	SetCompleteHook(0xE8, 0x004F6E1F, &DeleteCharacter_DelectBug);
	SetCompleteHook(0xE8, 0x0063D4AC, &DeleteCharacter_DelectBug);
	SetCompleteHook(0xE8, 0x0063D626, &DeleteCharacter_DelectBug);
	SetCompleteHook(0xE8, 0x0064365B, &DeleteCharacter_DelectBug);
	SetCompleteHook(0xE8, 0x004D7955, &ClearCharacters_DelectBug);
	SetCompleteHook(0xE8, 0x004EF6A1, &ClearCharacters_DelectBug);
	SetCompleteHook(0xE8, 0x0062EAC3, &ClearCharacters_DelectBug);
	SetCompleteHook(0xE8, 0x006312D3, &ClearCharacters_DelectBug);
	SetCompleteHook(0xE8, 0x006316B4, &ClearCharacters_DelectBug);
	SetCompleteHook(0xE8, 0x00634659, &ClearCharacters_DelectBug);
	SetCompleteHook(0xE8, 0x0063EC49, &ClearCharacters_DelectBug);
	SetCompleteHook(0xE8, 0x00640BF5, &ClearCharacters_DelectBug);
	SetCompleteHook(0xE8, 0x007DF83E, &CNewUIMyInventory::RenderLeft);
}

namespace SEASON3B
{
	void CreateFlyBug(int, int, int, int, int)
	{
	}

	bool CreatePetProcess(int, int, float *, int, int, int)
	{
		return false;
	}
}