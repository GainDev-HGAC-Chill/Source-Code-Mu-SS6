#pragma once

#if(CUSTOM_GUILD_UPGRADE)

#include "Object.h"
#include "Protocol.h"
#include <vector>

#define MAX_GUILD_USER	80
#define GU_ROW_PER_PAGE	8


struct GUMyGuildMember
{
	char name[11];
	BYTE status;
	int  devote;
};

struct GUMyGuildMemberInfo
{
	BYTE count;
	int TotalDevote;
	int NextDevote;
	short Level;
	GUMyGuildMember Mem[MAX_GUILD_USER];
};

struct GUGuildInfo
{
	char	Name[11];
	char	Master[11];
	int		Devote;
	short	Level;
};

struct GUGuildRankingInfo
{
	BYTE count;
	GUGuildInfo Guild[50];
};

struct PMSG_GUILD_UPGRADE_GUILD_RANKING_RECV
{
	PWMSG_HEAD header;
	BYTE count;
};

struct PSWMSG_GUILD_UPGRADE_ME_RECV {
	PSWMSG_HEAD header;
	int			GuildLevel;
	int			Devote;
};

struct PSWMSG_GUILD_UPGRADE_COUNT_RECV {
	PSWMSG_HEAD header;
	int			count;
};

struct PSWMSG_GUILD_UPGRADE_MY_GUILD_RECV {
	PSWMSG_HEAD header;
	int			count;
	int			TotalDevote;
	int			NextDevote;
	short		Level;
};
//====================================

struct PMSG_GUILD_UPGRADE_REQUEST_SEND
{
	PSBMSG_HEAD h;
	BYTE type;
	int  value;
};
//====================================

struct GG_DEVOTE_ITEM
{
	int		Item;
	int		Level;
	int		Devote;
};
struct GG_SHOP_ITEM
{
	int		Item;
	int		Level;
	int		GuildLevel;
	int		Devote;
	int		Zen;
};

struct GG_DEVOTE_ITEMS
{
	ObjectItem	Item;
	int			Devote;
};
struct GG_SHOP_ITEMS
{
	ObjectItem	Item;
	int			GuildLevel;
	int			Devote;
	int			Zen;
};

typedef void(*PUSHEVENT_CALLBACK_LPVOID)(LPVOID);

enum GuildUpgradeTabs
{
	ggInfo = 1,
	ggRanking,
	ggMyGuild,
	ggDevote,
	ggShop,
};

class cGuildUpgrade
{
public:
	cGuildUpgrade();
	~cGuildUpgrade();
	void Load();
	static void OpenGuildUpgrade(LPVOID pClass);
	static void TabInfoAction(LPVOID pClass);
	static void TabRankingAction(LPVOID pClass);
	static void TabMyGuildAction(LPVOID pClass);
	static void TabDevoteAction(LPVOID pClass);
	static void TabShopAction(LPVOID pClass);
	static void PagePrevAction(LPVOID pClass);
	static void PageNextAction(LPVOID pClass);
	static void ShopBuyAction(LPVOID pClass);
	static void DevoteAction(LPVOID pClass);

	void Clear();
	bool Draw();
	void DrawTabInfo();
	void DrawRankingInfo();
	void DrawMyGuildInfo();
	void DrawDevoteInfo();
	void DrawShopInfo();
	void DrawButton(int IMGcode, float x, float y, float w, float h, float a6, float a7, PUSHEVENT_CALLBACK_LPVOID pCallbackFunc);
	void DrawButton(int IMGcode, float x, float y, float w, float h, float a6, float a7, PUSHEVENT_CALLBACK_LPVOID pCallbackFunc, float uw, float uh);
	void DrawButton(int IMGcode, float x, float y, float w, float h, float uw, float uh, float a8, float a9, PUSHEVENT_CALLBACK_LPVOID pCallbackFunc, bool a11 = false);
	void DrawItem3D(float sx, float sy, float Width, float Height, int Type, int Level, int ExtOption, int Ancient, bool PickUp, float Scale = 1.0f, bool Center = true);
	bool CheckRect();
	bool GetDrawing() { return this->Drawing; }
	void SetDrawing(bool a1) { this->Drawing = a1; }
	void ToggleDrawing() { this->Drawing = !this->Drawing; }
	void SetCurTab(BYTE a1) { this->CurTab = a1; }
	BYTE GetCurTab() { return this->CurTab; }
	void SetRect(float a1, float a2, float a3, float a4);
	BYTE GetCurPage() { return this->CurPage; }
	void SetCurPage(BYTE a1) { this->CurPage = a1; }
	BYTE GetTotalPages() { return this->TotalPages; }
	void SetTotalPages(BYTE a1) { this->TotalPages = a1; }
	short GetCurItemShop() { return this->CurItemShop; }
	void SetCurItemShop(short a1) { this->CurItemShop = a1; }
	void SetSelectedItem(ObjectItem a1) { this->SelectedItem = a1; }
	void SetDevoteItem(ObjectItem a1) { this->CurDevoteItem = a1; }
	void SendRequest(BYTE type, int value);
	void RecvMyGuildInfo(BYTE* lpMsg);
	void RecvGuildRankingInfo(BYTE* lpMsg);
	void RecvDevoteItemInfo(BYTE* lpMsg);
	void RecvShopItemInfo(BYTE* lpMsg);
	void RecvMeInfo(BYTE* lpMsg);
	void RecvDevoteResult(BYTE* lpMsg);
	void BlockMouse();
	BOOL DrawItem3DCenterImage;
	bool Drawing;
private:
	float x;
	float y;
	float w;
	float h;

	BYTE CurTab;
	BYTE CurPage;
	BYTE TotalPages;
	short CurItemShop;
	ObjectItem SelectedItem;
	ObjectItem CurDevoteItem;
	DWORD	   CurDevoteItemOwner;
	int	 CurDevotePrice;
	int  CurDevoteItemHighLight;
	int	 MeDevote;
	short MeGuildLevel;
	bool PickedItemState;
	bool LoadedMyGuild;
	bool LoadedGuildRanking;
	bool LoadedDevoteItems;
	bool LoadedShopItems;
	GUMyGuildMemberInfo myGuildMemberInfo;
	GUGuildRankingInfo  GuildRankingInfo;
	std::vector<GG_DEVOTE_ITEMS> DevoteItems;
	std::vector<GG_SHOP_ITEMS> ShopItems;
	DWORD lastClick;
};

extern cGuildUpgrade GuildUpgrade;

#endif