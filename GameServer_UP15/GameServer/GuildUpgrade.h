#pragma once

#if(CUSTOM_GUILD_UPGRADE == TRUE)

#include "Protocol.h"

struct PMSG_GUILD_UPGRADE_REQUEST_RECV
{
	PSBMSG_HEAD h;
	BYTE type;
	int  value;
};


struct GUMyGuildMember
{
	char name[11];
	BYTE status;
	int  devote;
};

struct PMSG_GUILD_UPGRADE_MY_GUILD_SEND
{
	PWMSG_HEAD header;
	BYTE count;
	int TotalDevote;
	int NextDevote;
	short Level;
};

struct GUGuildInfo
{
	char	Name[11];
	char	Master[11];
	int		Devote;
	short	Level;
};

struct PMSG_GUILD_UPGRADE_GUILD_RANKING_SEND
{
	PWMSG_HEAD header;
	BYTE count;
};

struct PSWMSG_GUILD_UPGRADE_ME_SEND {
	PSWMSG_HEAD header;
	int			GuildLevel;
	int			Devote;
};

struct PSWMSG_GUILD_UPGRADE_COUNT_SEND {
	PSWMSG_HEAD header;
	int			count;
};

struct PSWMSG_GUILD_UPGRADE_MY_GUILD_SEND {
	PSWMSG_HEAD header;
	int			count;
	int			TotalDevote;
	int			NextDevote;
	short		Level;
};

struct SDHP_GUILD_UPGRADE_DEVOTE_UPDATE
{
	PBMSG_HEAD h; // C1:37 [RECV/SEND]
	char Member[11];
	int  Devote;
	int  GuildLevel;
	int  GuildDevote;
};

//================================================================
struct GG_GUILD_LEVEL
{
	int		Level;
	int		Devote;
	int		Exp;
	int		Zen;
};
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
//================================================================
class cGuildUpgrade
{
public:
	cGuildUpgrade();
	~cGuildUpgrade();
	void RecvRequest(PMSG_GUILD_UPGRADE_REQUEST_RECV* lpMsg, int aIndex);
	void SendGuildRanking(int aIndex);
	void SendMyGuildInfo(int aIndex);
	void SendDevoteItemInfo(int aIndex);
	void SendShopItemInfo(int aIndex);
	void SendMeInfo(int aIndex);
	int  GetNextDevote(int Level);
	int  GetLevelDevote(int Devote);
	void DevoteItem(int aIndex, int slot);
	void SendDevoteResult(int aIndex, int result);
	void AddDevote(int aIndex, int Devote, int GuildDevote);
	void BuyShopItem(int aIndex, int Slot);
	void Load(char* File);
	void AddDevoteEff(LPOBJ lpUser);
	void RemoveDevoteEff(LPOBJ lpUser);
private:
	std::map<int, GG_GUILD_LEVEL> d_GuildLevel;
	std::vector<GG_DEVOTE_ITEM> d_DevoteItem;
	std::vector<GG_SHOP_ITEM> d_ShopItem;
	GG_SHOP_ITEM SuperKhung;
};

extern cGuildUpgrade GuildUpgrade;

#endif