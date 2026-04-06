#include "stdafx.h"
#include "ActiveInvasions.h"
//#include "CustomMonsters.h"
#include "Interface.h"
#include "Defines.h"
//#include "Extras.h"
#include <fstream>
#include <string>
#include "Central.h"
#include "SItemOption.h"
#include "CBUtil.h"
#if(THONG_TIN_BOSS)
CActiveInvasions gActiveInvasions;

CActiveInvasions::CActiveInvasions()
{
	this->m_data.clear();

}

void CActiveInvasions::list_recv(PMSG_ACTIVE_INVASIONS_RECV* lpMsg)
{
	this->m_data.clear();

	for (int n = 0; n < lpMsg->count; n++)
	{
		auto info = reinterpret_cast<PMSG_ACTIVE_INVASIONS*>(reinterpret_cast<BYTE*>(lpMsg)+sizeof(PMSG_ACTIVE_INVASIONS_RECV)+(sizeof(PMSG_ACTIVE_INVASIONS)* n));

		if (info->count._count == 0 && info->count._max_count == 0)
		{
			continue;
		}
		ACTIVE_INVASIONS data;
		data.monster_id = info->monster_id;
		data.count = info->count;

		this->m_data.push_back(data);
	}
	gInterface.Data[eInvasionInfo].OnShow ^= 1;
}

void CActiveInvasions::update_monster_recv(PMSG_INVASION_MONSTER_UPDATE_RECV* lpMsg)
{
	for (auto it = this->m_data.begin(); it != this->m_data.end();)
	{
		if (it->monster_id == lpMsg->monster_id)
		{
			it->count._count = lpMsg->count;

			if (it->count._count == 0 && it->count._max_count == 0)
			{
				it = this->m_data.erase(it);
			}

			break;
		}
		++it;
	}
}


void CActiveInvasions::render()
{
	if (gInterface.CheckWindow(ChatWindow) || gInterface.CheckWindow(FullMap) || gInterface.CheckWindow(SkillTree) || gInterface.CheckWindow(CashShop) || gInterface.CheckWindow(Inventory)
		|| gInterface.CheckWindow(Character) || gInterface.CheckWindow(Quest) || gInterface.CheckWindow(Party) || gInterface.CheckWindow(MuHelper) || gInterface.CheckWindow(Guild) || gInterface.CheckWindow(FriendList))
	{
		gInterface.Data[eInvasionInfo].OnShow = false;
	}
	if (!gInterface.Data[eInvasionInfo].OnShow)
	{
		return;
	}

	float MainWidth = 120.0;
	float MainHeight = 12 + (this->m_data.size() * 12);

	float StartY = 20;

	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);

	PMSG_CUSTOM_EVENTTIME_SEND pMsg;





	gCBUtil.gInfoBox(StartX, StartY, MainWidth, MainHeight, 0x00000096, 0.0, 0);
	if (this->m_data.size() == NULL)
	{
		gInterface.DrawFormat(eExcellent, StartX + 5, StartY + 2, 105, 3, "Boss chưa xuất hiện!");
	}
	else
	{
		for (int i = 0; i < this->m_data.size(); i++)
		{
			char* name = CCustomMonster::GetMonsterName(this->m_data[i].monster_id);
			gInterface.DrawFormat(eWhite, StartX + 5, StartY + 5 + (i * 12), 115, 1, "%d. %s - (%d)", i + 1, name, this->m_data[i].count);
		}
	}
}
#endif
