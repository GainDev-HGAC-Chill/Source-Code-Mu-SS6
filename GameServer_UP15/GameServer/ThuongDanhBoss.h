#pragma once
#include "StdAfx.h"
#include "user.h"
#include "Protocol.h"

struct THUONG_DANH_BOSS
{
	int IdMonter;
	int Diem;
	int Notice;
};

struct SDHP_RANKING_BOS_SAVE_SEND
{
	PBMSG_HEAD header; // C1:3D
	WORD index;
	char account[11];
	char name[11];
	DWORD score;
};

class ThuongDanhBoss
{
public:
	ThuongDanhBoss(void);
	~ThuongDanhBoss(void);
	void	Init();
	void	Load(char *path);
	void Thuong(LPOBJ lpObj, LPOBJ lpTarget);
	void GDRankingBosSaveSend(int aIndex, DWORD Score);

private:

	std::vector<THUONG_DANH_BOSS> m_ThuongBoss;

};

extern ThuongDanhBoss gThuongDanhBoss;