#include "StdAfx.h"
#include "Defines.h"
#include "Extras.h"
#include "NewUISystem.h"
#include "wsclientline.h"
#include "CharacterMachine.h"
#include "PrintPlayer.h"
#include "ScriptItem.h"
#include "NewUIMyInventory.h"
#include "Interface.h"

#if(SLOTPET)
CCharacterMachine::CCharacterMachine(void)
{
}

CCharacterMachine::~CCharacterMachine(void)
{
}

int GetUINewChatLogWindow()
{
	return ((int(__thiscall*)(int))0x00861180)(GetInstance());
}

int GetUINewMyInventory()
{
	return ((int(__thiscall*)(int))0x00861260)(GetInstance());
}

int GetRepairMode()
{
	return ((int(__thiscall*)(int))0x00834550)(GetUINewMyInventory());
}

zITEM* CreateItem(void *lp)
{
	return CreateItemConvert(*(DWORD *)(GetInstance() + 36), lp);
}

void SendRequest_Repair(char p_Index, char p_AddGold)
{
	CStreamPacketEngine spe;
	spe.Init(0xC1, 0x35);
	spe.Rightshift1((BYTE)(p_Index));
	spe.Rightshift1((BYTE)(p_AddGold));
	spe.Send(0, 0);
}

void AddTextChatList(char* strID, char * strText, int MsgType)
{
	BYTE str_ID[28];
	BYTE str_Text[28];

	CharToString(&str_ID, strID);
	CharToString(&str_Text, strText);
	ChatLog_AddText(GetUINewChatLogWindow(), str_ID, str_Text, MsgType, 0);
}

#define CreateBug                 ((void  (__cdecl*)(int Type, vec3_t Position, OBJECT *Owner, int SubType, int LinkBone)) 0x00501700)
#define sub_501700					((DWORD(__cdecl*)(DWORD, DWORD, DWORD, DWORD, DWORD)) 0x501700)

void CreateEffectEquipping(WORD Type, int pCha, int o)
{
	if (Type != 0xFFFF)
	{
		switch (Type)
		{
		case 6656:
			Create_FlyBug(7827, o + 252, o, 0, 0);
			break;
		case 6658:
			Create_FlyBug(233, o + 252, o, 0, 0);
			break;
		case 6659:
			Create_FlyBug(323, o + 252, o, 0, 0);
			break;
		case 6720:
			CreatePet_Process(Type, (Type + 1171), (float*)(o + 252), pCha, 0, 0);
			break;
		case 6721:
			CreatePet_Process(Type, (Type + 1171), (float*)(o + 252), pCha, 0, 0);
			break;
		case 6723:
			CreatePet_Process(Type, (Type + 1171), (float*)(o + 252), pCha, 0, 0);
			break;
		case 6736:
			CreatePet_Process(Type, (Type + 1171), (float*)(o + 252), pCha, 0, 0);
			break;
		case 6762:
			CreatePet_Process(Type, (Type + 1171), (float*)(o + 252), pCha, 0, 0);
			break;
		case 6779:
			CreatePet_Process(Type, (Type + 1171), (float*)(o + 252), pCha, 0, 0);
			break;
		default:
			Create_FlyBug(Type + 1171, o + 252, o, 0, 0);
			break;
		}
	}
}

void CCharacterMachine::EquipItem(int iIndex, BYTE* pbyItemPacket)
{
	if (iIndex < 0 || iIndex >= 16) { return; }

	zITEM* ip = &this->Equipment[iIndex];
	if (ip->Type != 0xFFFF || ip->Type != -1)
	{
		this->Unequip_Item(iIndex);
	}

	zITEM* TempIp = CreateItem(pbyItemPacket);
	if (NULL != TempIp)
	{
		TempIp->lineal_pos = iIndex;
		TempIp->ex_src_type = ITEM_EX_SRC_EQUIPMENT2;

		if (iIndex == 12)
		{
			*(WORD*)(Hero + 592) = TempIp->Type + 1171;
			CreateEffectEquipping(TempIp->Type, Hero, Hero + 776);
		}

		memcpy(ip, TempIp, sizeof(zITEM));
		DeletePickedItem();
	}
	((void(__cdecl*)(int)) 0x0057F410)(Hero);
}

void DelectIndexPetBug(OBJECT* Owner, int Index)
{
	BYTE * Butterfles = (BYTE*)0x8791550;

	for (int i = 0; i < 10; i++)
	{
		OBJECT *o = (OBJECT*)&Butterfles[648 * i];
		if (o->Live)
		{
			if (o->Owner == Owner && o->Type == Index)
			{
				o->Live = false;
				break;
			}
		}
	}
}

void CCharacterMachine::Unequip_Item(int iIndex)
{
	if (iIndex < 0 || iIndex >= 16) { return; }

	zITEM* ip = &this->Equipment[iIndex];

	ip->Type = -1;
	ip->Level = 0;
	ip->Number = -1;
	ip->Option1 = 0;
	ip->ExtOption = 0;
	ip->SocketCount = 0;
	for (int j = 0; j < MAX_SOCKETS_; ++j)
	{
		ip->SocketSeedID[j] = SOCKET_EMPTY_;
		ip->SocketSphereLv[j] = 0;
	}
	ip->SocketSeedSetOption = 0;

	if (iIndex == 12)
	{
		Delect_FlyBug(Hero + 776);
		*(WORD*)(Hero + 592) = 0xFFFF;
		((void(__cdecl*)(int)) 0x0057F410)(Hero);
	}
}

void CCharacterMachine::UnequipAllItems()
{
	for (int i = 0; i < 16; i++)
	{
		this->Unequip_Item(i);
	}
}

bool CCharacterMachine::IsEquipable(int iIndex, zITEM* pItem)
{
	if (pItem == NULL)
		return false;

	ITEM_ATTRIBUTE* pItemAttr = ItemAttribute(pItem->Type);
	BYTE byFirstClass = GetBaseClass(*(BYTE *)(Hero + 19));
	bool bEquipable = false;

	if (pItemAttr->RequireClass[byFirstClass])
	{
		bEquipable = true;
	}
	else if (byFirstClass == Magic_Gladiator && pItemAttr->RequireClass[Dark_Wizard]
		&& pItemAttr->RequireClass[Dark_Knight])
	{
		bEquipable = true;
	}

	BYTE byStepClass = GetStepClass(*(BYTE *)(Hero + 19));
	if (pItemAttr->RequireClass[byFirstClass] > byStepClass)
	{
		return false;
	}

	if (bEquipable == false)
		return false;

	bEquipable = false;

	if (pItemAttr->m_byItemSlot == iIndex)
	{
		bEquipable = true;
	}
	else if (pItemAttr->m_byItemSlot || iIndex != 1)
	{
		if (pItemAttr->m_byItemSlot == 10 && iIndex == 11)
			bEquipable = true;
	}
	else if (byFirstClass != Dark_Knight
		&& byFirstClass != Magic_Gladiator
		&& byFirstClass != Rage_Fighter)
	{
		if (byFirstClass == Summoner &&
			(pItem->Type < 2560 || pItem->Type > 2560 + MAX_ITEM_INDEX))
		{
			bEquipable = true;
		}
	}
	else
	{
		if (pItemAttr->TwoHand)
		{
			bEquipable = false;
			return false;
		}
		bEquipable = true;
	}

	if (byFirstClass == Fairy_Elf)
	{
		zITEM *l = &this->Equipment[1];
		if (iIndex == 0 && l->Type != 2048 + 7
			&& (l->Type >= 2048 && l->Type < 2048 + MAX_ITEM_INDEX))
		{
			if (pItem->Type != 2048 + 15)
				bEquipable = false;
		}
	}

	if (byFirstClass == Rage_Fighter)
	{
		if (iIndex == 5)
		{
			bEquipable = false;
		}
		else if (pItemAttr->m_byItemSlot == 0)
		{
			bEquipable = RageEquipmentWeapon((int)&*(LPVOID*)0xEBCD98, iIndex, pItem->Type);
		}
	}

	if (bEquipable == false)
		return false;

	DWORD wStrength = ViewStrength + ViewAddStrength;
	DWORD wDexterity = ViewDexterity + ViewAddDexterity;
	DWORD wEnergy = ViewEnergy + ViewAddEnergy;
	DWORD wVitality = ViewVitality + ViewAddVitality;
	DWORD wCharisma = ViewLeadership + ViewAddLeadership;

	DWORD wLevel = *(WORD *)(*(DWORD *)0x8128AC8 + 14);


	if (pItem->RequireStrength > wStrength)
		return false;
	if (pItem->RequireDexterity > wDexterity)
		return false;
	if (pItem->RequireEnergy > wEnergy)
		return false;
	if (pItem->RequireVitality > wVitality)
		return false;
	if (pItem->RequireCharisma > wCharisma)
		return false;
	if (pItem->RequireLevel > wLevel)
		return false;

	return bEquipable;
}

bool CCharacterMachine::UnEquipmentWindowProcess(int m_iPointedSlot, int TypeInventory)
{
	if (m_iPointedSlot == -1)
	{
		return false;
	}

	if (gInterface.CheckWindow(ObjWindow::Shop) || gInterface.CheckWindow(ObjWindow::Warehouse) ||
		gInterface.CheckWindow(ObjWindow::ExpandWarehouse) || gInterface.CheckWindow(ObjWindow::Trade)
		|| gInterface.CheckWindow(ObjWindow::ChaosBox)) //Không cho di chuyển khi checkWindow
	{
		return 0;
	}

	int InitPointed = (TypeInventory == 1) ? 0 : 8;

	if (IsPress(VK_RBUTTON) && GetRepairMode() != REPAIR_MODE_ON && EquipmentItem == false)
	{
		ResetMouseRButton();

		if (GetPickedItem() == NULL)
		{
			int v24; int iSrcType, nDstIndex;

			if ((m_iPointedSlot >= 0 && m_iPointedSlot < InitPointed) || m_iPointedSlot >= 12)
			{
				iSrcType = 40;
				v24 = (DWORD)&this->Equipment[m_iPointedSlot];
			}
			else
			{
				iSrcType = 0;
				v24 = CharacterMachine_Equipment(m_iPointedSlot);
			}

			if (*(WORD*)v24 != 0xFFFF)
			{
				nDstIndex = MyFindEmptySlot(GetUINewMyInventory(), v24, 0);

				if (-1 != nDstIndex)
				{
					if (CreatePickedItem(NULL, (const void*)v24))
					{
						if (iSrcType == 40)
						{
							Unequip_Item(m_iPointedSlot);
						}
						else
						{
							UnequipItem((void*)GetUINewMyInventory(), m_iPointedSlot);
						}
						SendRequestEquipment(iSrcType, m_iPointedSlot, v24, 0, nDstIndex + 12);
						HidePickedItem(GetPickedItem());
						playSound(29, 0, 0);
					}
					return true;
				}
			}
		}
	}
	return false;
}

#include "Interface.h"

bool CCharacterMachine::EquipmentWindowProcess()
{
	int v16 = GetUINewMyInventory();
	int m_iPointedSlot = *(int *)(v16 + 284);

	if (m_iPointedSlot == -1)
	{
		return 0;
	}

	if (gInterface.CheckWindow(ObjWindow::Shop) || gInterface.CheckWindow(ObjWindow::Warehouse) ||
		gInterface.CheckWindow(ObjWindow::ExpandWarehouse) || gInterface.CheckWindow(ObjWindow::Trade)
		|| gInterface.CheckWindow(ObjWindow::ChaosBox)) //Không cho duy chuyển pet khi CheckWindow 
	{
		return 0;
	}

	if (IsRelease(VK_LBUTTON))
	{
		int pPickedItem = GetPickedItem();
		if (pPickedItem)
		{
			zITEM* pItemObj = (zITEM*)pPicked_GetItem(pPickedItem);

			if (pItemObj->bPeriodItem && pItemObj->bExpiredPeriod)
			{
				AddTextChatList("", GlobalTextx(22859), TYPE_ERROR_MESSAGE);
				BackupPickedItem();
				ResetMouseLButton();
				return false;
			}

			zITEM* pItemSlot = &this->Equipment[m_iPointedSlot];
			if (pItemSlot && pItemSlot->Type != 65535)
			{
				return true;
			}

			if (this->IsEquipable(m_iPointedSlot, pItemObj))
			{
				int InOwoner = g_pNewUISystem.GetOwnerMyInventory();

				if (InOwoner != -1)
				{
					int iSourceIndex = GetInventSourceLinealPos(GetSourceLinealPos(GetPickedItem()), InOwoner);
					int iTargetIndex = m_iPointedSlot;
					SendRequestEquipment(REQUEST_INVENTORY, iSourceIndex + 12, (int)pItemObj, REQUEST_EQUIPMENT, iTargetIndex);
					return true;
				}
				else if (GetOwnerInventory(GetPickedItem()) == g_pNewUISystem.GetOwnerMixInventory())
				{
					int iSourceIndex = GetSourceLinealPos(GetPickedItem());
					int iTargetIndex = m_iPointedSlot;
					SendRequestEquipment(GetMixInventoryEquipmentIndex(g_MixRecipeMgr), iSourceIndex, (int)pItemObj, 40, iTargetIndex);
					return true;
				}
				else if (GetOwnerInventory(GetPickedItem()) == g_pNewUISystem.GetOwnerShopInventory())
				{
					int iSourceIndex = GetSourceLinealPos(GetPickedItem());
					int iTargetIndex = m_iPointedSlot;
					SendRequestEquipment(4, iSourceIndex + 204, (int)pItemObj, 40, iTargetIndex);
					return true;
				}
				else if (GetOwnerInventory(GetPickedItem()) == g_pNewUISystem.GetOwnerMyTrade())
				{
					int iSourceIndex = GetSourceLinealPos(GetPickedItem());
					int iTargetIndex = m_iPointedSlot;
					SendRequestEquipment(1, iSourceIndex, (int)pItemObj, 40, iTargetIndex);

					int myTrade = *(DWORD *)(GetInstance() + 124);
					if (*(BYTE *)(myTrade + 3841))
						AlertTrade(myTrade);

					*(DWORD *)(myTrade + 3844) = 150;
					return true;
				}
				else if (pItemObj->ex_src_type == ITEM_EX_SRC_EQUIPMENT1 && EquipmentItem == false)
				{
					if (GetSourceLinealPos(GetPickedItem()) == m_iPointedSlot)
					{
						SendRequestEquipment(0, pItemObj->lineal_pos, (int)pItemObj, 40, m_iPointedSlot);
						return true;
					}
					BackupPickedItem();
				}
				else if (pItemObj->ex_src_type == ITEM_EX_SRC_EQUIPMENT2 && EquipmentItem == false)
				{
					if (GetSourceLinealPos(GetPickedItem()) == m_iPointedSlot)
					{
						BackupPickedItem();
					}
				}
			}
		}
		else
		{
			if (GetRepairMode() != REPAIR_MODE_ON)
			{
				zITEM* pEquippedItem = &this->Equipment[m_iPointedSlot];

				if (pEquippedItem->Type != 65535)
				{
					if (CreatePickedItem(NULL, pEquippedItem))
					{
						Unequip_Item(m_iPointedSlot);
					}
				}
			}
			else
			{
				zITEM* pEquippedItem = &this->Equipment[m_iPointedSlot];

				if (pEquippedItem->Type != 65535)
				{
					if (*(bool *)(v16 + 1028) == true)
					{
						SendRequest_Repair(m_iPointedSlot, 1);
					}
				}
			}
		}
	}
	else if (IsPress(VK_RBUTTON) && GetRepairMode() != REPAIR_MODE_ON && EquipmentItem == false)
	{
		ResetMouseRButton();

		if (GetPickedItem() == NULL)
		{
			zITEM* pItemObj = &this->Equipment[m_iPointedSlot];

			if (pItemObj->Type != 0xFFFF)
			{
				int nDstIndex = MyFindEmptySlot(GetUINewMyInventory(), (int)pItemObj, 0);

				if (-1 != nDstIndex)
				{
					if (CreatePickedItem(NULL, pItemObj))
					{
						Unequip_Item(m_iPointedSlot);
					}

					SendRequestEquipment(40, m_iPointedSlot, (int)pItemObj, 0, nDstIndex + 12);
					playSound(29, 0, 0);
				}
			}
			return true;
		}
	}
	return false;
}
#endif