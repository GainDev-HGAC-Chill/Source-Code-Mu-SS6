#include "StdAfx.h"
#include "ThuongDanhBoss.h"
#include "MemScript.h"
#include "Message.h"
#include "Notice.h"
#include "Util.h"
#include "ItemManager.h"
#include "Util.h"
#include "GameMain.h"
#include "DSProtocol.h"

ThuongDanhBoss gThuongDanhBoss;

ThuongDanhBoss::ThuongDanhBoss(void)
{
}

ThuongDanhBoss::~ThuongDanhBoss(void)
{
}

void ThuongDanhBoss::Init()
{
	m_ThuongBoss.clear();
}

void ThuongDanhBoss::Load(char* path) // OK
{
	CMemScript* lpMemScript = new CMemScript;

	if (lpMemScript == 0)
	{
		ErrorMessageBox(MEM_SCRIPT_ALLOC_ERROR, path);
		return;
	}

	if (lpMemScript->SetBuffer(path) == 0)
	{
		ErrorMessageBox(lpMemScript->GetLastError());
		delete lpMemScript;
		return;
	}

	this->Init();

	try
	{
		while (true)
		{
			if (lpMemScript->GetToken() == TOKEN_END)
			{
				break;
			}

			int section = lpMemScript->GetNumber();

			while (true)
			{
				if (section == 0)
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}

					THUONG_DANH_BOSS info;

					info.IdMonter = lpMemScript->GetNumber();

					info.Diem = lpMemScript->GetAsNumber();

					info.Notice = lpMemScript->GetAsNumber();

					this->m_ThuongBoss.push_back(info);
				}

				else
				{
					break;
				}
			}
		}
	}
	catch (...)
	{
		ErrorMessageBox(lpMemScript->GetLastError());
	}

	delete lpMemScript;
}



void ThuongDanhBoss::Thuong(LPOBJ lpObj, LPOBJ lpTarget)
{
	for (std::vector<THUONG_DANH_BOSS>::iterator it = this->m_ThuongBoss.begin(); it != this->m_ThuongBoss.end(); it++)
	{
		if (it->IdMonter == lpObj->Class)
		{
			this->GDRankingBosSaveSend(lpTarget->Index, it->Diem);
			if (it->Notice == 0)
				gNotice.GCNoticeSendToAll(1, 0, 0, 0, 0, 0, "[%s] Đã Tiêu Diệt [%s] Nhận Được Thêm [%d] Điểm Đánh Boss", lpTarget->Name, lpObj->Name, it->Diem);
		}
	}

}

void ThuongDanhBoss::GDRankingBosSaveSend(int aIndex, DWORD Score)
{

	LPOBJ lpObj = &gObj[aIndex];
	SDHP_RANKING_BOS_SAVE_SEND pMsg;

	pMsg.header.set(0x3B, sizeof(pMsg));

	pMsg.index = aIndex;

	memcpy(pMsg.account, lpObj->Account, sizeof(pMsg.account));

	memcpy(pMsg.name, lpObj->Name, sizeof(pMsg.name));

	pMsg.score = Score;
	gDataServerConnection.DataSend((BYTE*)&pMsg, pMsg.header.size);
}
