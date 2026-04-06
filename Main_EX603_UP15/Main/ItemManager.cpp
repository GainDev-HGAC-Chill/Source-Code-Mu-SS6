#include "stdafx.h"
#include "Defines.h"
#include "ItemManager.h"
#include "InfoLog.h"

CItemManager gItemManager;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CItemManager::CItemManager() // OK
{
	this->m_ItemInfo.clear();
}

CItemManager::~CItemManager() // OK
{

}

void CItemManager::Load(ITEM_INFO* info) // OK
{
	for(int n=0;n < MAX_ITEM2;n++)
	{
		if(info[n].Index < 0 || info[n].Index >= MAX_ITEM2)
		{
			return;
		}
		this->m_ItemInfo.insert(std::pair<int,ITEM_INFO>(info[n].ItemIndex,info[n]));
	}
}

#if (CongHuongV2)
int CItemManager::GetCountPhoiCongHuong(int mIndexItem, int Type) // OK
{
	int GetCount = 0;
	if (mIndexItem == -1)
	{
		return GetCount;
	}
	std::map<int, ITEM_INFO>::iterator itemgoc = gItemManager.m_ItemInfo.find(mIndexItem);

	if (itemgoc != gItemManager.m_ItemInfo.end())
	{
		for (std::map<int, ITEM_INFO>::iterator it = gItemManager.m_ItemInfo.begin(); it != gItemManager.m_ItemInfo.end(); it++)
		{
			if ((it->second.ItemIndex / 512) == (itemgoc->second.ItemIndex / 512))
			{
				if (it->second.Level >= (itemgoc->second.Level) && Type == 1)
				{
					GetCount++;
				}
				else if (Type == 0)
				{
					GetCount++;
				}
				else if (Type == 2 && itemgoc->second.ItemIndex == it->second.ItemIndex)
				{
					GetCount++;
				}
				else {
					continue;
				}
			}
		}
	}

	return GetCount;
}
#endif