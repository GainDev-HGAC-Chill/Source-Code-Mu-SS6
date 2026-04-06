// ResetTable.h: interface for the CResetTable class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#include "User.h"

struct RESET_TABLE_INFO_VIP
{
	int MinReset;
	int MaxReset;
	int Level[MAX_ACCOUNT_LEVEL];
	int Money[MAX_ACCOUNT_LEVEL];
	int Point[MAX_ACCOUNT_LEVEL];
	int PointKeep[MAX_ACCOUNT_LEVEL];
	int WCoinC[MAX_ACCOUNT_LEVEL];
	int GoblinPoint[MAX_ACCOUNT_LEVEL];
};

class CResetTableVip
{
public:
	CResetTableVip();
	virtual ~CResetTableVip();
	void Load(char* path);
	int GetResetLevel(LPOBJ lpObj);
	int GetResetMoney(LPOBJ lpObj);
	int GetResetPoint(LPOBJ lpObj);
	int GetResetPointkeep(LPOBJ lpObj);
	int GetResetTienTe(LPOBJ lpObj);
	int GetResetTienTeWCoinC(LPOBJ lpObj);
private:
	std::vector<RESET_TABLE_INFO_VIP> m_ResetTableInfo;
	RESET_TABLE_INFO_VIP m_ResetTable;
};

extern CResetTableVip gResetTableVip;
