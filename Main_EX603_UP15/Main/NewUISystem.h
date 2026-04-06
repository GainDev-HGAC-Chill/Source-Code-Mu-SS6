#pragma once
#define GetInstance												((int(*)()) 0x00861110)
#define GetNewUIOption											((int(__thiscall*)(int thisa)) 0x00861620)
#define GetRenderLevel											((int(__thiscall*)(int thisa)) 0x00849EC0)
#define GetNewUIManager											((int(__thiscall*)(void* thisa)) 0x00860B50)
#define GetNewUI3DRenderMng										((int(__thiscall*)(int thisa)) 0x00860B60)
#define GetNewUIHotKey											((int(__thiscall*)(int thisa)) 0x00860B80)
#define IsImpossibleHideInterface								((bool(__stdcall*)(int dwKey)) 0x00860CE0)
#define CNewUISystem_IsVisible									((bool(__thiscall*)(int thisa, int dwKey)) 0x0085EC20)
#define CNewUISystem_HideSystem									((void(__thiscall*)(int thisa, int dwKey)) 0x0085F9A0)
#define CNewUISystem_ShowSystem									((void(__thiscall*)(int thisa, int dwKey)) 0x0085EC50)
#define CNewUISystem_ToggleSystem								((void(__thiscall*)(int thisa, int dwKey)) 0x00860660)
#define CNewUISystem_HideAll									((void(__thiscall*)(int thisa)) 0x008606B0)
#define CNewUISystem_LoadMainSceneInterface						((bool(__thiscall*)(int *thisa)) 0x0085A330)
#define PetInfoWindow_OpenningProcess							((void(__thiscall*)(int thisa)) 0x0084EAE0)
#define CNewUIManager_ShowInterface								((void(__thiscall*)(int thisa, DWORD dwKey, bool bShow)) 0x00815F50)
#define sub_83CBE0												((int   (__thiscall*)(void *thisa)) 0x0083CBE0)
#define CNewUISystem_GetUI_NewItemMng							((int(__thiscall*)(int thisa))0x00861240)
#define CNewUISystem_GetUI_NewMyInventory						((int(__thiscall*)(int thisa))0x00861260)
#define CNewUISystem_GetUI_NewMyShopInventory					((int(__thiscall*)(int thisa))0x00861400)
#define CNewUISystem_GetUI_NewTrade								((int(__thiscall*)(int thisa))0x00861540)
#define AlertTrade												((void(__thiscall*)(int thisa))0x00865B60)
#define CNewUISystem_GetInventoryCtrl							((int(__thiscall*)(void *thisa, int a2))0x0083C710)
#define CNewUISystem_GetTargetInventoryCtrl						((signed int(__thiscall*)(void *thisa, WORD **a2))0x0083C6B0)
#define MyShop_pNewInventoryCtrl								((int(__thiscall*)(int thisa))0x00668850)
#define MyMix_pNewInventoryCtrl									((int(__thiscall*)(int thisa))0x0082C780)
#define Trade_pNewInventoryCtrl									((int(__thiscall*)(int thisa))0x007D9130)
#define CNewUIInventoryCtrl_Create								((void  (__thiscall*)(char *thisa, char* pNew3DRenderMng, char* pNewItemMng, char* pOwner, int x, int y, int nColumn, int nRow)) 0x007D9ED0)

class CNewUISystem
{
public:
	CNewUISystem();
	virtual ~CNewUISystem();
	void ShowInterface(DWORD dwKey, bool bShow = true);
	bool IsVisible(DWORD dwKey);
	void Show(DWORD dwKey);
	void Hide(DWORD dwKey);
	void Toggle(DWORD dwKey);
	void HideAll();

	int GetUI_NewMyInventory();
	int GetOwnerMyInventory();
	int GetTargetOwnerMyInventory();

	int GetOwnerShopInventory();
	int GetOwnerMixInventory();
	int GetOwnerMyTrade();
	void Init();
	static bool __thiscall LoadMainSceneInterface(int* thisa);

};

extern CNewUISystem g_pNewUISystem;