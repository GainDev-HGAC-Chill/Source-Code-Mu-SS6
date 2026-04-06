#include "StdAfx.h"
#include "Defines2.h"
#include "NewUISystem.h"

CNewUISystem g_pNewUISystem;

CNewUISystem::CNewUISystem()
{
}

CNewUISystem::~CNewUISystem()
{
}

bool CNewUISystem::IsVisible(DWORD dwKey)
{
	return CNewUISystem_IsVisible(GetInstance(), dwKey);
}

void CNewUISystem::Hide(DWORD dwKey)
{
	CNewUISystem_HideSystem(GetInstance(), dwKey);
}

void CNewUISystem::Show(DWORD dwKey)
{
	CNewUISystem_ShowSystem(GetInstance(), dwKey);
}

void CNewUISystem::ShowInterface(DWORD dwKey, bool bShow)
{
	CNewUIManager_ShowInterface(GetNewUIManager((void*)GetInstance()), dwKey, bShow);
}

void CNewUISystem::Toggle(DWORD dwKey)	//. Show <-> Hide
{
	CNewUISystem_ToggleSystem(GetInstance(), dwKey);
}

void CNewUISystem::HideAll()
{
	CNewUISystem_HideAll(GetInstance());
}

int CNewUISystem::GetUI_NewMyInventory()
{
	return CNewUISystem_GetUI_NewMyInventory(GetInstance());
}

int CNewUISystem::GetOwnerMyInventory()
{
	return CNewUISystem_GetInventoryCtrl((void*)*(DWORD *)(GetInstance() + 40), GetOwnerInventory(GetPickedItem()));
}

int CNewUISystem::GetTargetOwnerMyInventory()
{
	return CNewUISystem_GetTargetInventoryCtrl((void*)*(DWORD *)(GetInstance() + 40), (WORD **)GetPickedItem());
}

int CNewUISystem::GetOwnerShopInventory()
{
	return MyShop_pNewInventoryCtrl(*(DWORD *)(GetInstance() + 84));
}

int CNewUISystem::GetOwnerMyTrade()
{
	return Trade_pNewInventoryCtrl(*(DWORD *)(GetInstance() + 124));
}

int CNewUISystem::GetOwnerMixInventory()
{
	return MyMix_pNewInventoryCtrl(*(DWORD *)(GetInstance() + 52));
}
