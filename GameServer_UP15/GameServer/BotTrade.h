
#define MAX_BOTTRADER	10

struct MixesItems
{
	int Type;
	BYTE LevelMin;
	BYTE LevelMax;
	BYTE OptionMin;
	BYTE OptionMax;
	BYTE Luck;
	BYTE Skill;
	BYTE Exc;
	BYTE DongThan;
};

struct MixesItemsT
{
	int Type;
	BYTE LevelMax;
	BYTE OptionMax;
	BYTE Luck;
	BYTE Skill;
	BYTE Exc;
	BYTE DongThan;
};

struct BotTraderBodyItems
{
	int num;
	int level;
	int opt;
	bool Enabled;
};

struct Mixes
{
	int Index;
	char Name[256];
	int	PriceType;
	int PriceCount;
	int SuccessRate;
	MixesItems i_Keep[64];
	MixesItems i_Success[64];
	int i_KeepItem;
	int i_SuccessCount;
};

struct MixesT
{
	int Index;
	MixesItems i_Need[64];
	int i_NeedCount;
};


struct botTraderStruct
{
	int index;
	BYTE Class;
	BOOL OnlyVip;
	char Name[11];
	BYTE Map;
	BYTE X;
	BYTE Y;
	BYTE Dir;
	bool Enabled;
	BotTraderBodyItems body[9];
	int MixesIndex[50];
	int MixesCount;
};

class ObjBotTrader
{
public:
	void Read(char * FilePath);
	void MakeBot();
	int GetBotIndex(int aIndex);
	BOOL IsInTrade(int aIndex);
	BOOL TradeOpen(int index, int nindex);
	void TradeOk(int aIndex);
	void TradeCancel(int aIndex);
private:
	bool Enabled;
	BYTE TradeMix(int aIndex, int BotNum);
	bool SearchSameIDNumber(int mIndex, int To);
	BYTE BoxExcOptions(int maxOptions);
	botTraderStruct bot[MAX_BOTTRADER];
	Mixes Mix[1024];
	MixesT MixT[1024];
	int MixCount;
	int MixNumber(int index);
	int ItemCount(int aIndex);
};

extern ObjBotTrader BotTrader;
