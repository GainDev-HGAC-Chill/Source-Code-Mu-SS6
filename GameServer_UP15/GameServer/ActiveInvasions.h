#pragma once
#include "Protocol.h"
#if(THONG_TIN_BOSS)
struct PMSG_ACTIVE_INVASIONS_SEND
{
	PSWMSG_HEAD header; // C2:F3:E2
	BYTE count;
};

struct PMSG_INVASION_MONSTER_UPDATE_SEND
{
	PSBMSG_HEAD header; // C2:F3:E2
	int monster_id;
	int count;
	int MaxCount;
};

struct InvasionsData
{
	InvasionsData(int count, int max_count) : _count(count), _max_count(max_count) {	}
	InvasionsData() : _count(0), _max_count(0) {}
	int _count;
	int _max_count;
};

struct PMSG_ACTIVE_INVASIONS
{
	int monster_id;
	InvasionsData count;
};

struct BossInfo
{
	int bossindex;
	bool BossRegen;
	int BossMap;
	int BossCount;
};

class CActiveInvasions
{
public:
	CActiveInvasions();
	void monster_add(int monster_id, bool need_send = false);
	void monster_del(int monster_id);
	void send_list_to_client(int aIndex) const;
	void update_by_monster_id(int monster_id);
private:
	std::map<int, InvasionsData> m_data;
};
extern CActiveInvasions gActiveInvasions;
#endif