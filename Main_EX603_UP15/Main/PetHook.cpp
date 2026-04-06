#include "stdafx.h"
#include "Protect.h"
#include "PetHook.h"
#include "Util.h"
#include "Defines.h"
#include "Import.h"
#include "TMemory.h"
#include "Pet.h"
#include "cape.h"
#include "CharacterMachine.h"

ObjCreateBug gObjCreateBug = (ObjCreateBug)0x00501700;
ObjCreatePet gObjCreatePet = (ObjCreatePet)0x00835E40;
#define Hero * (DWORD*)0x007BC4F04

void gObjCreatePetEx(int ItemId)
{
	int ItemSwitch = *(WORD*)ItemId;
	int PetPreview = LODWORD(pPreviewPetThis) + 776;
	int PetHP;
	PetHP = *(BYTE*)(oUserObjectStruct_ + 5550);

	for (std::map<int, CUSTOM_PET_INFO>::iterator it = gCustomPet2.m_CustomPetInfo.begin(); it != gCustomPet2.m_CustomPetInfo.end(); it++)
	{
		if (ItemSwitch == it->second.ItemIndex)
		{
			switch (it->second.PetType)
			{
			case 0:
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 9:
			case 10:
			case 11:
			{
					   gObjCreateBug(ItemSwitch + 1171, PetPreview + 252, PetPreview, 0, 0);
					   break;
			}
			case 8:
			{
					  CreateEffectEquipping(ItemSwitch, Hero, Hero + 776);
					  break;
			}
			}
		}
	}

	if (gCloak.isCloak(ItemSwitch))
	{
		pRefreshViewport(oUserPreviewStruct, oUserPreviewStruct + 776, 0);
	}
	gObjCreatePet(ItemId);
}

//----- (00501330) --------------------------------------------------------
bool ResetPetPreviewEx(WORD *a1)
{
	bool result; // al@2

	if (a1)
	{
		result = *a1 == 6656
			|| *a1 == 6657
			|| *a1 == 6658
			|| *a1 == 6659
			|| *a1 == 6660
			|| *a1 == 6661
			|| *a1 == 6693
			|| (*a1 >= ITEM(13, 200) && *a1 <= ITEM(13, 512)
			|| gCloak.isCloak(*a1));
	}
	else
	{
		result = 0;
	}
	return result;
}

void gObjCreatePetExHook()
{
	SetOp((LPVOID)0x00836481, (LPVOID)ResetPetPreviewEx, ASM::CALL);
	SetOp((LPVOID)0x007DD304, (LPVOID)gObjCreatePetEx, ASM::CALL);
	SetOp((LPVOID)0x00833B08, (LPVOID)gObjCreatePetEx, ASM::CALL);
}