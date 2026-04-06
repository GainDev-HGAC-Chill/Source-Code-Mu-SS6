#include "stdafx.h"
#include "Defines.h"
#include "Import.h"
#include "Interface.h"
#include "Offset.h"
#include "Protect.h"
#include "Util.h"
#include "HealthBar.h"
#include "Import.h"
#include "Object.h"
#include "PrintPlayer.h"
#include "WindowsStruct.h"
#include "CustomRankUser.h"
#include "DanhHieu.h"
#include "Config.h"
#include "User.h"
#include "CustomFont.h"

int ImgTag = 0;

CCustomRankUser::CCustomRankUser()
{
	memset(this->m_Data, 0, sizeof(this->m_Data));
}

CCustomRankUser gCustomRankUser;

void CCustomRankUser::RenderShowLogRank(DWORD ViewPortAddr, int index, int PosX, int PosY)
{
	int maxData = sizeof(this->m_Data) / sizeof(this->m_Data[0]);

	if (index < 0 || index >= maxData)
	{
		return;
	}
	if (*(BYTE*)(ViewPortAddr + 0xE) == 0 && gProtect.m_MainInfo.RankUserOnlyOnSafeZone != 0)
	{
		return; //continue;
	}

	ObjectPreview* Object = &*(ObjectPreview*)(ViewPortAddr);
	int rank = this->m_Data[index].m_Rank;

	// Trong file nay ban chi render rank tu 0 den 30
	if (rank < 0 || rank > 30)
	{
		rank = 0;
	}

	if ((((pMapNumber)<18) ? 0 : ((pMapNumber)>23) ? (((pMapNumber) == 53) ? 1 : 0) : 1) == 1) //Disable in Chaos Castle
	{
		return; //continue;
	}
	if (gProtect.m_MainInfo.RankUserShowOverHead != 0)
	{
		glColor3f(1.0, 1.0, 1.0);
		pSetBlend(true);
		pGLSwitchBlend();

		pDrawImage(gInterface.Data[rank + 1].ModelID, (float)PosX + 24, (float)PosY - 68, 60.0, 60.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);

		pGLSwitch();
		pGLSwitch();
		glColor3f(1.0, 1.0, 1.0);
	}
	if (ViewPortAddr == *(DWORD *)0x7BC4F04 && (pCursorX >= PosX) && ((float)pCursorX <= (float)PosX + 50) && (pCursorY >= PosY + 20) && (pCursorY < PosY + 85))
	{
		this->LoadInfoUser(index, PosX, PosY, (char*)(ViewPortAddr + 0x38));
	}


	if (MinimizarOfRank == 1)
	{
	}
	if (MinimizarOfRank == 0)
	{


	//RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX+24, (float)PosY - 107, Return2X(TransForX(60)), 60, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
		//======================================
		int TitleDanhHieu = this->m_Data[index].m_rDanhHieu;
		int TitleTuLuyen = this->m_Data[index].m_rTuLuyen;
		int TitleQuanHam = this->m_Data[index].m_rQuanHam;

#if(DANH_HIEU_NEW == 1)

		pSetBlend(true);
		glColor3f(1.0, 1.0, 1.0);

		if (gProtect.m_MainInfo.MenuButtons[9] == 1)
		{
			switch (this->m_Data[index].m_rDanhHieu)
			{
			case 0:
				//gInterface.DrawToolTip((float)PosX - 130, (float)PosY + 200, "no info ...");
				break;
			case 1:
				RenderBitmap(90101, (float)PosX - 16.0f, (float)PosY - 75.0f, 146, 90, 0, 0, 1, 1, 1, 1, 0.0);
				break;
			case 2:
				RenderBitmap(90102, (float)PosX - 16.0f, (float)PosY - 65.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
				break;
			case 3:
				RenderBitmap(90103, (float)PosX - 30.0f, (float)PosY - 68.0f, 185, 80, 0, 0, 1, 1, 1, 1, 0.0);
				break;
			case 4:
				RenderBitmap(90104, (float)PosX - 16.0f, (float)PosY - 65.0f, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
				break;
			case 5:						                           //  215,77
				RenderBitmap(90105, (float)PosX - 30.0f, (float)PosY - 62.0f, 185, 60, 0, 0, 1, 1, 1, 1, 0.0);
				break;
			case 6:						                           //  215,77
				RenderBitmap(90106, (float)PosX - 20.0f, (float)PosY - 60.0f, 155, 60, 0, 0, 1, 1, 1, 1, 0.0);
				break;
			case 7:						                           //  215,77
				RenderBitmap(90107, (float)PosX - 20.0f, (float)PosY - 58.0f, 157, 50, 0, 0, 1, 1, 1, 1, 0.0);
				break;
			case 8:						                           //  215,77
				RenderBitmap(90108, (float)PosX - 30.0f, (float)PosY - 58.0f, 186, 55, 0, 0, 1, 1, 1, 1, 0.0);
				break;
			case 9:						                           //  215,77
				RenderBitmap(90109, (float)PosX - 40.0f, (float)PosY - 57.0f, 210, 55, 0, 0, 1, 1, 1, 1, 0.0);
				break;
			case 10:					                            //  215,77
				RenderBitmap(90110, (float)PosX - 20.0f, (float)PosY - 56.0f, 159, 50, 0, 0, 1, 1, 1, 1, 0.0);
				break;
			case 11:					                            //  215,77
				RenderBitmap(90111, (float)PosX - 20.0f, (float)PosY - 55.0f, 159, 50, 0, 0, 1, 1, 1, 1, 0.0);
				break;
			case 12:					                            //  215,77
				RenderBitmap(90112, (float)PosX - 30.0f, (float)PosY - 60.0f, 186, 65, 0, 0, 1, 1, 1, 1, 0.0);
				break;
			case 13:                                                       //  215,77 
				RenderBitmap(90113, (float)PosX - 20.0f, (float)PosY - 60.0f, 156, 65, 0, 0, 1, 1, 1, 1, 0.0);
				break;
			case 14:                                                       //  215,77 
				RenderBitmap(90114, (float)PosX - 16.0f, (float)PosY - 56.0f, 146, 50, 0, 0, 1, 1, 1, 1, 0.0);
				break;
			case 15:                                                       //  215,77
				RenderBitmap(90115, (float)PosX - 16.0f, (float)PosY - 58.0f, 146, 55, 0, 0, 1, 1, 1, 1, 0.0);
				break;
			case 16:                                                       //  215,77
				RenderBitmap(90116, (float)PosX - 20.0f, (float)PosY - 61.0f, 156, 70, 0, 0, 1, 1, 1, 1, 0.0);
				break;
			case 17:                                                       //  215,77 
				RenderBitmap(90117, (float)PosX - 20.0f, (float)PosY - 59.0f, 156, 65, 0, 0, 1, 1, 1, 1, 0.0);
				break;
			case 18:                                                       //  215,77
				RenderBitmap(90118, (float)PosX - 16.0f, (float)PosY - 60.0f, 148, 60, 0, 0, 1, 1, 1, 1, 0.0);
				break;
			case 19:                                                       //  215,77
				RenderBitmap(90119, (float)PosX - 17.0f, (float)PosY - 57.0f, 146, 55, 0, 0, 1, 1, 1, 1, 0.0);
				break;
			case 20:                                                       //  215,77
				RenderBitmap(90120, (float)PosX - 20.0f, (float)PosY - 59.0f, 157, 60, 0, 0, 1, 1, 1, 1, 0.0);
				break;
			case 21:
				RenderBitmap(90121, (float)PosX - 20.0f, (float)PosY - 57.0f, 160, 50, 0, 0, 1, 1, 1, 1, 0.0);
				break;
			case 22:
				RenderBitmap(90122, (float)PosX - 20.0f, (float)PosY - 57.0f, 156, 58, 0, 0, 1, 1, 1, 1, 0.0);
				break;
			case 23:
				RenderBitmap(90123, (float)PosX - 20.0f, (float)PosY - 57.0f, 156, 55, 0, 0, 1, 1, 1, 1, 0.0);
				break;
			case 24:
				RenderBitmap(90124, (float)PosX - 20.0f, (float)PosY - 57.0f, 156, 55, 0, 0, 1, 1, 1, 1, 0.0);
				break;
			case 25:
				RenderBitmap(90125, (float)PosX - 20.0f, (float)PosY - 57.0f, 156, 50, 0, 0, 1, 1, 1, 1, 0.0);
				break;
			case 26:
				RenderBitmap(90126, (float)PosX - 20.0f, (float)PosY - 60.0f, 160, 70, 0, 0, 1, 1, 1, 1, 0.0);
				break;
			case 27:
				RenderBitmap(90127, (float)PosX - 30.0f, (float)PosY - 55.0f, 186, 50, 0, 0, 1, 1, 1, 1, 0.0);
				break;
			case 28:
				RenderBitmap(90128, (float)PosX - 30.0f, (float)PosY - 57.0f, 186, 55, 0, 0, 1, 1, 1, 1, 0.0);
				break;
			case 29:
				RenderBitmap(90129, (float)PosX - 20.0f, (float)PosY - 60.0f, 156, 60, 0, 0, 1, 1, 1, 1, 0.0);
				break;
			case 30:
				RenderBitmap(90130, (float)PosX - 20.0f, (float)PosY - 55.0f, 156, 45, 0, 0, 1, 1, 1, 1, 0.0);
				break;
			case 31:
				RenderBitmap(90131, (float)PosX - 20.0f, (float)PosY - 55.0f, 156, 50, 0, 0, 1, 1, 1, 1, 0.0);
				break;
			case 32:
				RenderBitmap(90132, (float)PosX - 20.0f, (float)PosY - 55.0f, 156, 50, 0, 0, 1, 1, 1, 1, 0.0);
				break;
			case 33:
				RenderBitmap(90133, (float)PosX - 20.0f, (float)PosY - 55.0f, 156, 50, 0, 0, 1, 1, 1, 1, 0.0);
				break;
			case 34:
				RenderBitmap(90134, (float)PosX - 20.0f, (float)PosY - 57.0f, 156, 50, 0, 0, 1, 1, 1, 1, 0.0);
				break;
			case 35:
				RenderBitmap(90135, (float)PosX - 20.0f, (float)PosY - 55.0f, 156, 50, 0, 0, 1, 1, 1, 1, 0.0);
				break;
			case 36:
				RenderBitmap(90136, (float)PosX - 20.0f, (float)PosY - 55.0f, 156, 50, 0, 0, 1, 1, 1, 1, 0.0);
				break;

			case 37:
				RenderBitmap(90137, (float)PosX - 20.0f, (float)PosY - 55.0f, 156, 45, 0, 0, 1, 1, 1, 1, 0.0);
				break;
			case 38:
				RenderBitmap(90138, (float)PosX - 20.0f, (float)PosY - 55.0f, 156, 50, 0, 0, 1, 1, 1, 1, 0.0);
				break;
			case 39:
				RenderBitmap(90139, (float)PosX - 30.0f, (float)PosY - 58.0f, 186, 60, 0, 0, 1, 1, 1, 1, 0.0);
				break;
			case 40:
				RenderBitmap(90140, (float)PosX - 30.0f, (float)PosY - 55.0f, 186, 50, 0, 0, 1, 1, 1, 1, 0.0);
				break;
			case 41:
				RenderBitmap(90141, (float)PosX - 20.0f, (float)PosY - 56.0f, 156, 55, 0, 0, 1, 1, 1, 1, 0.0);
				break;
			case 42:
				RenderBitmap(90142, (float)PosX - 20.0f, (float)PosY - 57.0f, 156, 50, 0, 0, 1, 1, 1, 1, 0.0);
				break;
			case 43:
				RenderBitmap(90143, (float)PosX - 20.0f, (float)PosY - 60.0f, 156, 60, 0, 0, 1, 1, 1, 1, 0.0);
				break;
			case 44:
				RenderBitmap(90144, (float)PosX - 20.0f, (float)PosY - 57.0f, 156, 55, 0, 0, 1, 1, 1, 1, 0.0);
				break;
			case 45:
				RenderBitmap(90145, (float)PosX - 20.0f, (float)PosY - 57.0f, 156, 55, 0, 0, 1, 1, 1, 1, 0.0);
				break;
			case 46:
				RenderBitmap(90146, (float)PosX - 35.0f, (float)PosY - 55.0f, 188, 50, 0, 0, 1, 1, 1, 1, 0.0);
				break;
			case 47:
				RenderBitmap(90147, (float)PosX - 30.0f, (float)PosY - 55.0f, 186, 50, 0, 0, 1, 1, 1, 1, 0.0);
				break;
			case 48:
				RenderBitmap(90148, (float)PosX - 32.0f, (float)PosY - 55.0f, 184, 50, 0, 0, 1, 1, 1, 1, 0.0);
				break;


				pGLSwitchBlend();
				pGLSwitch();
				glColor3f(1.0, 1.0, 1.0);
				pSetBlend(false);

			}
		}
#endif

#if(TU_LUYEN_NEW == 1)

		if (gProtect.m_MainInfo.MenuButtons[10] == 1)
		{
			{

				switch (this->m_Data[index].m_rQuanHam)
				{
				case 1:
					RenderBitmap(10108, (float)PosX + 3.0f, (float)PosY - 72.0f, 85, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 2:
					RenderBitmap(10109, (float)PosX + 3.0f, (float)PosY - 72.0f, 85, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 3:
					RenderBitmap(10110, (float)PosX + 3.0f, (float)PosY - 72.0f, 85, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 4:
					RenderBitmap(10111, (float)PosX + 3.0f, (float)PosY - 72.0f, 85, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 5:
					RenderBitmap(10112, (float)PosX + 3.0f, (float)PosY - 72.0f, 85, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 6:
					RenderBitmap(10113, (float)PosX + 3.0f, (float)PosY - 72.0f, 85, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;

				case 7:
					RenderBitmap(10114, (float)PosX + 3.0f, (float)PosY - 72.0f, 85, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;

				case 8:
					RenderBitmap(10115, (float)PosX + 3.0f, (float)PosY - 72.0f, 85, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;

				case 9:
					RenderBitmap(10116, (float)PosX + 3.0f, (float)PosY - 72.0f, 85, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;

				case 10:
					RenderBitmap(10117, (float)PosX + 3.0f, (float)PosY - 72.0f, 85, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;

				case 11:
					RenderBitmap(10118, (float)PosX + 3.0f, (float)PosY - 72.0f, 85, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;

				case 12:
					RenderBitmap(10119, (float)PosX + 3.0f, (float)PosY - 72.0f, 85, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;

				case 13:
					RenderBitmap(10120, (float)PosX + 3.0f, (float)PosY - 72.0f, 85, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;

				case 14:
					RenderBitmap(10121, (float)PosX + 3.0f, (float)PosY - 72.0f, 85, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 15:
					RenderBitmap(10122, (float)PosX + 3.0f, (float)PosY - 72.0f, 85, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;

				case 16:
					RenderBitmap(10123, (float)PosX + 3.0f, (float)PosY - 72.0f, 85, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;

				case 17:
					RenderBitmap(10124, (float)PosX + 3.0f, (float)PosY - 72.0f, 85, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;

				case 18:
					RenderBitmap(10125, (float)PosX + 3.0f, (float)PosY - 72.0f, 85, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;

				case 19:
					RenderBitmap(10126, (float)PosX + 3.0f, (float)PosY - 72.0f, 85, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 20:
					RenderBitmap(10127, (float)PosX + 3.0f, (float)PosY - 72.0f, 85, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;

				case 21:
					RenderBitmap(10128, (float)PosX - 12.0f, (float)PosY - 77.0f, 110, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 22:
					RenderBitmap(10129, (float)PosX - 12.0f, (float)PosY - 77.0f, 110, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 23:
					RenderBitmap(10130, (float)PosX - 12.0f, (float)PosY - 77.0f, 110, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 24:
					RenderBitmap(10131, (float)PosX - 12.0f, (float)PosY - 77.0f, 110, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 25:
					RenderBitmap(10132, (float)PosX - 12.0f, (float)PosY - 77.0f, 110, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 26:
					RenderBitmap(10133, (float)PosX - 12.0f, (float)PosY - 77.0f, 110, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;

				case 27:
					RenderBitmap(10134, (float)PosX - 12.0f, (float)PosY - 77.0f, 110, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;

				case 28:
					RenderBitmap(10135, (float)PosX - 12.0f, (float)PosY - 77.0f, 110, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;

				case 29:
					RenderBitmap(10136, (float)PosX - 12.0f, (float)PosY - 77.0f, 110, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;

				case 30:
					RenderBitmap(10137, (float)PosX - 12.0f, (float)PosY - 77.0f, 110, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;

				case 31:
					RenderBitmap(10138, (float)PosX - 12.0f, (float)PosY - 77.0f, 110, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;

				case 32:
					RenderBitmap(10139, (float)PosX - 12.0f, (float)PosY - 77.0f, 110, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;

				case 33:
					RenderBitmap(10140, (float)PosX - 12.0f, (float)PosY - 77.0f, 110, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;

				case 34:
					RenderBitmap(10141, (float)PosX - 12.0f, (float)PosY - 77.0f, 110, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 35:
					RenderBitmap(10142, (float)PosX - 12.0f, (float)PosY - 77.0f, 110, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;

				case 36:
					RenderBitmap(10143, (float)PosX - 12.0f, (float)PosY - 77.0f, 110, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;

				case 37:
					RenderBitmap(10144, (float)PosX - 12.0f, (float)PosY - 77.0f, 110, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;

				case 38:
					RenderBitmap(10145, (float)PosX - 12.0f, (float)PosY - 77.0f, 110, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;

				case 39:
					RenderBitmap(10146, (float)PosX - 12.0f, (float)PosY - 77.0f, 110, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 40:
					RenderBitmap(10147, (float)PosX - 12.0f, (float)PosY - 77.0f, 110, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;



					pGLSwitchBlend();
					pGLSwitch();
					glColor3f(1.0, 1.0, 1.0);
					pSetBlend(false);

				}
			}
		}
#endif

#if(TU_LUYEN_NEW == 1)
		if (gProtect.m_MainInfo.MenuButtons[11] == 1)
		{

			{
				switch (this->m_Data[index].m_rTuLuyen)
				{

				case 0:
					break;


				case 1:
					RenderBitmap(20128, (float)PosX + 10.0f, (float)PosY - 90.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 2:
					RenderBitmap(20129, (float)PosX + 10.0f, (float)PosY - 90.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 3:
					RenderBitmap(20130, (float)PosX + 10.0f, (float)PosY - 90.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 4:
					RenderBitmap(20131, (float)PosX + 10.0f, (float)PosY - 90.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 5:
					RenderBitmap(20132, (float)PosX + 10.0f, (float)PosY - 90.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 6:
					RenderBitmap(20133, (float)PosX + 10.0f, (float)PosY - 90.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 7:
					RenderBitmap(20134, (float)PosX + 10.0f, (float)PosY - 90.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 8:
					RenderBitmap(20135, (float)PosX + 10.0f, (float)PosY - 90.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 9:
					RenderBitmap(20136, (float)PosX + 10.0f, (float)PosY - 90.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 10:
					RenderBitmap(20137, (float)PosX + 10.0f, (float)PosY - 90.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 11:
					RenderBitmap(20138, (float)PosX + 10.0f, (float)PosY - 90.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 12:
					RenderBitmap(20139, (float)PosX + 10.0f, (float)PosY - 90.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 13:
					RenderBitmap(20140, (float)PosX + 10.0f, (float)PosY - 90.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 14:
					RenderBitmap(20141, (float)PosX + 10.0f, (float)PosY - 90.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 15:
					RenderBitmap(20142, (float)PosX + 10.0f, (float)PosY - 90.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 16:
					RenderBitmap(20143, (float)PosX + 10.0f, (float)PosY - 90.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 17:
					RenderBitmap(20144, (float)PosX + 10.0f, (float)PosY - 90.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 18:
					RenderBitmap(20145, (float)PosX + 10.0f, (float)PosY - 90.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 19:
					RenderBitmap(20146, (float)PosX + 10.0f, (float)PosY - 90.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 20:
					RenderBitmap(20147, (float)PosX + 10.0f, (float)PosY - 90.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 21:
					RenderBitmap(20148, (float)PosX + 10.0f, (float)PosY - 90.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 22:
					RenderBitmap(20149, (float)PosX + 10.0f, (float)PosY - 90.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 23:
					RenderBitmap(20150, (float)PosX + 10.0f, (float)PosY - 90.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 24:
					RenderBitmap(20151, (float)PosX + 10.0f, (float)PosY - 90.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 25:
					RenderBitmap(20152, (float)PosX + 10.0f, (float)PosY - 90.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 26:
					RenderBitmap(20153, (float)PosX + 10.0f, (float)PosY - 90.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 27:
					RenderBitmap(20154, (float)PosX + 10.0f, (float)PosY - 90.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 28:
					RenderBitmap(20155, (float)PosX + 10.0f, (float)PosY - 90.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 29:
					RenderBitmap(20156, (float)PosX + 10.0f, (float)PosY - 90.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 30:
					RenderBitmap(20157, (float)PosX + 10.0f, (float)PosY - 90.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 31:
					RenderBitmap(20158, (float)PosX + 10.0f, (float)PosY - 90.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 32:
					RenderBitmap(20159, (float)PosX + 10.0f, (float)PosY - 90.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 33:
					RenderBitmap(20160, (float)PosX + 10.0f, (float)PosY - 90.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 34:
					RenderBitmap(20161, (float)PosX + 10.0f, (float)PosY - 90.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 35:
					RenderBitmap(20162, (float)PosX + 10.0f, (float)PosY - 90.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 36:
					RenderBitmap(20163, (float)PosX + 10.0f, (float)PosY - 90.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 37:
					RenderBitmap(20164, (float)PosX + 10.0f, (float)PosY - 90.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 38:
					RenderBitmap(20165, (float)PosX + 10.0f, (float)PosY - 90.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 39:
					RenderBitmap(20166, (float)PosX + 10.0f, (float)PosY - 90.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 40:
					RenderBitmap(20167, (float)PosX + 10.0f, (float)PosY - 90.0f, 95, 23, 0, 0, 1, 1, 1, 1, 0.0);
					break;

				case 41:
					RenderBitmap(20168, (float)PosX - 3.0f, (float)PosY - 93.0f, 115, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 42:
					RenderBitmap(20169, (float)PosX - 3.0f, (float)PosY - 93.0f, 115, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 43:
					RenderBitmap(20170, (float)PosX - 3.0f, (float)PosY - 93.0f, 115, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 44:
					RenderBitmap(20171, (float)PosX - 3.0f, (float)PosY - 93.0f, 115, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 45:
					RenderBitmap(20172, (float)PosX - 3.0f, (float)PosY - 93.0f, 115, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 46:
					RenderBitmap(20173, (float)PosX - 3.0f, (float)PosY - 93.0f, 115, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 47:
					RenderBitmap(20174, (float)PosX - 3.0f, (float)PosY - 93.0f, 115, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 48:
					RenderBitmap(20175, (float)PosX - 3.0f, (float)PosY - 93.0f, 115, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 49:
					RenderBitmap(20176, (float)PosX - 3.0f, (float)PosY - 93.0f, 115, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 50:
					RenderBitmap(20177, (float)PosX - 3.0f, (float)PosY - 93.0f, 115, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 51:
					RenderBitmap(20178, (float)PosX - 3.0f, (float)PosY - 93.0f, 115, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 52:
					RenderBitmap(20179, (float)PosX - 3.0f, (float)PosY - 93.0f, 115, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 53:
					RenderBitmap(20180, (float)PosX - 3.0f, (float)PosY - 93.0f, 115, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 54:
					RenderBitmap(20181, (float)PosX - 3.0f, (float)PosY - 93.0f, 115, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 55:
					RenderBitmap(20182, (float)PosX - 3.0f, (float)PosY - 93.0f, 115, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 56:
					RenderBitmap(20183, (float)PosX - 3.0f, (float)PosY - 93.0f, 115, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 57:
					RenderBitmap(20184, (float)PosX - 3.0f, (float)PosY - 93.0f, 115, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 58:
					RenderBitmap(20185, (float)PosX - 3.0f, (float)PosY - 93.0f, 115, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 59:
					RenderBitmap(20186, (float)PosX - 3.0f, (float)PosY - 93.0f, 115, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 60:
					RenderBitmap(20187, (float)PosX - 3.0f, (float)PosY - 93.0f, 115, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 61:
					RenderBitmap(20188, (float)PosX - 3.0f, (float)PosY - 93.0f, 115, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 62:
					RenderBitmap(20189, (float)PosX - 3.0f, (float)PosY - 93.0f, 115, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 63:
					RenderBitmap(20190, (float)PosX - 3.0f, (float)PosY - 93.0f, 115, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 64:
					RenderBitmap(20191, (float)PosX - 3.0f, (float)PosY - 93.0f, 115, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 65:
					RenderBitmap(20192, (float)PosX - 3.0f, (float)PosY - 93.0f, 115, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 66:
					RenderBitmap(20193, (float)PosX - 3.0f, (float)PosY - 93.0f, 115, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 67:
					RenderBitmap(20194, (float)PosX - 3.0f, (float)PosY - 93.0f, 115, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 68:
					RenderBitmap(20195, (float)PosX - 3.0f, (float)PosY - 93.0f, 115, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 69:
					RenderBitmap(20196, (float)PosX - 3.0f, (float)PosY - 93.0f, 115, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 70:
					RenderBitmap(20197, (float)PosX - 3.0f, (float)PosY - 93.0f, 115, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 71:
					RenderBitmap(20198, (float)PosX - 3.0f, (float)PosY - 93.0f, 115, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 72:
					RenderBitmap(20199, (float)PosX - 3.0f, (float)PosY - 93.0f, 115, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 73:
					RenderBitmap(20200, (float)PosX - 3.0f, (float)PosY - 93.0f, 115, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 74:
					RenderBitmap(20201, (float)PosX - 3.0f, (float)PosY - 93.0f, 115, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 75:
					RenderBitmap(20202, (float)PosX - 3.0f, (float)PosY - 93.0f, 115, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 76:
					RenderBitmap(20203, (float)PosX - 3.0f, (float)PosY - 93.0f, 115, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 77:
					RenderBitmap(20204, (float)PosX - 3.0f, (float)PosY - 93.0f, 115, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 78:
					RenderBitmap(20205, (float)PosX - 3.0f, (float)PosY - 93.0f, 115, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 79:
					RenderBitmap(20206, (float)PosX - 3.0f, (float)PosY - 93.0f, 115, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 80:
					RenderBitmap(20207, (float)PosX - 3.0f, (float)PosY - 93.0f, 115, 30, 0, 0, 1, 1, 1, 1, 0.0);
					break;

					pGLSwitchBlend();
					pGLSwitch();
					glColor3f(1.0, 1.0, 1.0);
					pSetBlend(false);
				}
			}

		}
#endif


	//	if (this->m_Data[index].m_rVipTaiKhoan == 1)
	//	{
	//		if (ImgTag > 600) ImgTag = 0;
	//		pDrawButton(0x9960, (float)PosX - 15, (float)PosY - 110, Return2X(TransForX(120)), 40, (ImgTag % 5) * 120, (ImgTag / 600) * 40);
	//		ImgTag++;
	//	}
	//	if (this->m_Data[index].m_rVipTaiKhoan == 2)
	//	{
	//		if (ImgTag > 600) ImgTag = 0;
	//		pDrawButton(0x9961, (float)PosX - 15, (float)PosY - 110, Return2X(TransForX(120)), 40, (ImgTag % 5) * 120, (ImgTag / 600) * 40);
	//		ImgTag++;
	//	}
	//	if (this->m_Data[index].m_rVipTaiKhoan == 3)
	//	{
	//		if (ImgTag > 600) ImgTag = 0;
	//		pDrawButton(0x9962, (float)PosX - 15, (float)PosY - 110, Return2X(TransForX(120)), 40, (ImgTag % 5) * 120, (ImgTag / 600) * 40);
	//		ImgTag++;
	//	}
	//	pGLSwitchBlend();
	//	pGLSwitch();
	//	glColor3f(1.0, 1.0, 1.0);
	//	pSetBlend(false);
	//}



			if (TitleDanhHieu <= 0)
			{

				glColor3f(1.0, 1.0, 1.0);
				pSetBlend(true);
				pGLSwitchBlend();

				if (this->m_Data[index].m_Rank)
				{
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 70, 70.0, 40.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 1){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 70, 70.0, 40.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 2){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 70, 70.0, 40.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 3){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 70, 70.0, 40.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 4){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 70, 70.0, 40.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 5){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 70, 70.0, 40.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}

				else if (this->m_Data[index].m_Rank == 6){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 70, 70.0, 40.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 7){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 70, 70.0, 40.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}

				else if (this->m_Data[index].m_Rank == 8){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 70, 70.0, 40.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 9){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 70, 70.0, 40.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}

				else if (this->m_Data[index].m_Rank == 10){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 70, 70.0, 40.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 11){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 70, 70.0, 40.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}

				else if (this->m_Data[index].m_Rank == 12){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 73, 70.0, 40.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}

				else if (this->m_Data[index].m_Rank == 13){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 70, 70.0, 40.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}

				else if (this->m_Data[index].m_Rank == 14){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 70, 70.0, 40.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 15){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 70, 70.0, 40.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}

				else if (this->m_Data[index].m_Rank == 16){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 70, 70.0, 40.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 17){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 70, 70.0, 40.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}

				else if (this->m_Data[index].m_Rank == 18){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 70, 70.0, 40.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 19){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 70, 70.0, 40.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}

				else if (this->m_Data[index].m_Rank == 20){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 70, 70.0, 35.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}

				else if (this->m_Data[index].m_Rank == 21){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 70, 70.0, 35.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 22){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 70, 70.0, 35.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 23){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 70, 70.0, 35.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 24){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 70, 70.0, 35.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 25){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 70, 70.0, 35.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 26){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 70, 70.0, 35.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 27){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 70, 70.0, 35.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 28){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 70, 70.0, 35.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 29){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 70, 70.0, 35.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 30){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 70, 70.0, 35.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}




				else{}
			}
			else
			if (TitleTuLuyen <= 0)
			{
				if (this->m_Data[index].m_Rank)
				{
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 81, 70.0, 40.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}

				if (this->m_Data[index].m_Rank == 0){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 81, 70.0, 40.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 1){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 81, 70.0, 40.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 2){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 81, 70.0, 40.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 3){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 81, 70.0, 40.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 4){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 81, 70.0, 40.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 5){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 81, 70.0, 40.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}

				else if (this->m_Data[index].m_Rank == 6){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 81, 70.0, 40.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 7){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 81, 70.0, 40.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}

				else if (this->m_Data[index].m_Rank == 8){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 81, 70.0, 40.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 9){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 81, 70.0, 40.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}

				else if (this->m_Data[index].m_Rank == 10){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 81, 70.0, 40.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 11){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 81, 70.0, 40.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}

				else if (this->m_Data[index].m_Rank == 12){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 81, 70.0, 40.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}

				else if (this->m_Data[index].m_Rank == 13){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 81, 70.0, 40.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}

				else if (this->m_Data[index].m_Rank == 14){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 81, 70.0, 40.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 15){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 81, 70.0, 40.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}

				else if (this->m_Data[index].m_Rank == 16){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 81, 70.0, 40.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 17){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 81, 70.0, 40.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}

				else if (this->m_Data[index].m_Rank == 18){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 81, 70.0, 40.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 19){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 81, 70.0, 40.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}

				else if (this->m_Data[index].m_Rank == 20){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 81, 70.0, 35.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 21){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 81, 70.0, 35.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 22){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 81, 70.0, 35.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 23){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 81, 70.0, 35.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 24){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 81, 70.0, 35.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 25){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 81, 70.0, 35.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 26){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 81, 70.0, 35.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 27){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 81, 70.0, 35.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 28){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 81, 70.0, 35.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 29){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 81, 70.0, 35.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 30){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 20, (float)PosY - 81, 70.0, 35.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}


				else{}
			}
			else
			{

				if (this->m_Data[index].m_Rank)
				{
				}

				if (this->m_Data[index].m_Rank == 0){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 24, (float)PosY - 115, 60.0, 30.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}

				else if (this->m_Data[index].m_Rank == 1){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 24, (float)PosY - 115, 60.0, 30.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 2){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 24, (float)PosY - 115, 60.0, 30.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 3){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 24, (float)PosY - 115, 60.0, 30.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 4){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 24, (float)PosY - 115, 60.0, 30.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 5){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 24, (float)PosY - 115, 60.0, 30.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}

				else if (this->m_Data[index].m_Rank == 6){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 24, (float)PosY - 115, 60.0, 30.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 7){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 24, (float)PosY - 115, 60.0, 30.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}

				else if (this->m_Data[index].m_Rank == 8){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 24, (float)PosY - 115, 60.0, 30.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 9){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 24, (float)PosY - 115, 60.0, 30.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}

				else if (this->m_Data[index].m_Rank == 10){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 24, (float)PosY - 115, 60.0, 30.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 11){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 24, (float)PosY - 115, 60.0, 30.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}

				else if (this->m_Data[index].m_Rank == 12){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 24, (float)PosY - 115, 60.0, 30.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}

				else if (this->m_Data[index].m_Rank == 13){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 24, (float)PosY - 115, 60.0, 30.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}

				else if (this->m_Data[index].m_Rank == 14){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 24, (float)PosY - 115, 60.0, 30.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 15){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 24, (float)PosY - 115, 60.0, 30.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}

				else if (this->m_Data[index].m_Rank == 16){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 24, (float)PosY - 115, 60.0, 30.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 17){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 24, (float)PosY - 115, 60.0, 30.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}

				else if (this->m_Data[index].m_Rank == 18){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 24, (float)PosY - 115, 60.0, 30.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 19){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 24, (float)PosY - 115, 60.0, 30.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}

				else if (this->m_Data[index].m_Rank == 20){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 24, (float)PosY - 115, 60.0, 30.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}

				else if (this->m_Data[index].m_Rank == 21){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 24, (float)PosY - 115, 60.0, 30.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 22){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 24, (float)PosY - 115, 60.0, 30.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 23){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 24, (float)PosY - 115, 60.0, 30.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 24){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 24, (float)PosY - 115, 60.0, 30.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 25){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 24, (float)PosY - 115, 60.0, 30.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 26){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 24, (float)PosY - 115, 60.0, 30.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 27){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 24, (float)PosY - 115, 60.0, 30.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 28){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 24, (float)PosY - 115, 60.0, 30.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 29){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 24, (float)PosY - 115, 60.0, 30.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if (this->m_Data[index].m_Rank == 30){
					RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 24, (float)PosY - 115, 60.0, 30.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}


				else{}

				pGLSwitch();
				pGLSwitch();
				glColor3f(1.0, 1.0, 1.0);
			}
		}

	}

void CCustomRankUser::DrawInfo()
{

	VAngle Angle;

	int PosX, PosY;

	DWORD ViewportAddress = ((DWORD(__thiscall*)(void*, DWORD))0x0096A4C0)(((void*(*)())0x00402BC0)(), pViewAttackTargetID);

	ObjectPreview* Object = &*(ObjectPreview*)(ViewportAddress);

	if (!ViewportAddress || *(BYTE*)(ViewportAddress + 0x320) != 1)
	{
		return; //continue;
	}

	int index = *(WORD*)(ViewportAddress + 0x7E);
	int maxData = sizeof(this->m_Data) / sizeof(this->m_Data[0]);

	if (index < 0 || index >= maxData)
	{
		return;
	}
	char* name = (char*)(ViewportAddress + 0x38);


	if (this->m_Data[index].m_Enabled == false)
	{
		return; //continue;
	}

	if (*(BYTE*)(ViewportAddress + 0xE) == 0 && gProtect.m_MainInfo.RankUserOnlyOnSafeZone != 0)
	{
		return; //continue;
	}

	if ((((pMapNumber)<18) ? 0 : ((pMapNumber)>23) ? (((pMapNumber) == 53) ? 1 : 0) : 1) == 1) //Disable in Chaos Castle
	{
		return; //continue;
	}

	Angle.X = *(float*)(ViewportAddress + 0x404);

	Angle.Y = *(float*)(ViewportAddress + 0x408);

	Angle.Z = *(float*)(ViewportAddress + 0x40C) + *(float*)(ViewportAddress + 0x3E8) + 100.0f;

	pGetPosFromAngle(&Angle, &PosX, &PosY);

	PosX -= 42;







	this->LoadInfoUser(index, PosX, PosY, name);
}

void CCustomRankUser::LoadInfoUser(int index, int PosX, int PosY, char* name)
{
	int maxData = sizeof(this->m_Data) / sizeof(this->m_Data[0]);

	if (index < 0 || index >= maxData)
	{
		return;
	}

	int rank = this->m_Data[index].m_Rank;

	if (rank < 0 || rank > 30)
	{
		rank = 0;
	}
	if ((!gInterface.Data[eMenu_MAIN].OnShow &&
		!gInterface.Data[eVip_MAIN].OnShow &&
		!gInterface.Data[eEventTimePANEL_MAIN].OnShow &&
		!gInterface.Data[eCommand_MAIN].OnShow &&
		!gInterface.Data[eRankPANEL_MAIN].OnShow) &&
		!gInterface.CheckWindow(35))
	{
		if (gProtect.m_MainInfo.RankUserType != 4 && gProtect.m_MainInfo.RankUserShowOverHead != 0)
		{
			pSetBlend(true);
			glColor4f((GLfloat)0.0, (GLfloat)0.0, (GLfloat)0.0, (float)0.8);
			pDrawBarForm((float)(PosX + 2), (float)(PosY - 76), 75, 10, 0.0f, 0);
			pGLSwitchBlend();
			pGLSwitch();
			glColor3f(1.0, 1.0, 1.0);
			pSetBlend(false);

			this->DrawFormat(eGold, PosX + 7, PosY - 75, 70, 3, "%s", this->m_Data[index].szTitleRank);
		}

		if (gProtect.m_MainInfo.RankUserNeedAltKey != 0 && !(GetKeyState(VK_MENU) & 0x8000))
		{
			return; //continue;
		}

		if (gProtect.m_MainInfo.RankUserType == 0)
		{
			return; //continue;
		}


		pSetBlend(true);

		char classename[20] = { 0 };

		switch (this->m_Data[index].m_Classe)
		{
		case 1:
			sprintf(classename, "Soul Master");
			break;
		case 2:
			sprintf(classename, "Grand Master");
			break;
		case 16:
			sprintf(classename, "Dark Knight");
			break;
		case 17:
			sprintf(classename, "Blade Knight");
			break;
		case 18:
			sprintf(classename, "Blade Master");
			break;
		case 32:
			sprintf(classename, "Fairy Elf");
			break;
		case 33:
			sprintf(classename, "Muse Elf");
			break;
		case 34:
			sprintf(classename, "High Elf");
			break;
		case 48:
			sprintf(classename, "Magic Gladiator");
			break;
		case 50:
			sprintf(classename, "Duel Master");
			break;
		case 64:
			sprintf(classename, "Dark Lord");
			break;
		case 66:
			sprintf(classename, "Lord Emperor");
			break;
		case 80:
			sprintf(classename, "Summoner");
			break;
		case 81:
			sprintf(classename, "Bloody Summoner");
			break;
		case 82:
			sprintf(classename, "Dimension Master");
			break;
		case 96:
			sprintf(classename, "Rage Fighter");
			break;
		case 98:
			sprintf(classename, "Fist Master");
			break;
		default:
			sprintf(classename, "Dark Wizard");
			break;
		}

		if (gProtect.m_MainInfo.RankUserType == 2)
		{
			glColor4f(0.0, 0.0, 0.0, 0.8);
			pDrawBarForm((float)(PosX + 40), (float)(PosY - 8), 135, 80, 0.0f, 0);
			pGLSwitchBlend();

			this->DrawFormat(eRed2, PosX + 60, PosY - 4, 90, 3, "Rank: %s", this->m_Data[index].szTitleRank);

			this->DrawFormat(eWhite, PosX + 60, PosY + 8, 15, 1, "Lvl:");
			this->DrawFormat(eWhite, PosX + 60, PosY + 18, 15, 1, "Str:");
			this->DrawFormat(eWhite, PosX + 60, PosY + 28, 15, 1, "Agi:");
			this->DrawFormat(eWhite, PosX + 60, PosY + 38, 15, 1, "Vit:");
			this->DrawFormat(eWhite, PosX + 60, PosY + 48, 15, 1, "Ene:");
			this->DrawFormat(eWhite, PosX + 60, PosY + 58, 15, 1, "Com:");

			this->DrawFormat(eGold, PosX + 80, PosY + 8, 45, 1, "%d ", this->m_Data[index].m_Level);
			this->DrawFormat(eGold, PosX + 80, PosY + 18, 45, 1, "%d ", this->m_Data[index].m_For);
			this->DrawFormat(eGold, PosX + 80, PosY + 28, 45, 1, "%d ", this->m_Data[index].m_Agi);
			this->DrawFormat(eGold, PosX + 80, PosY + 38, 45, 1, "%d ", this->m_Data[index].m_Vit);
			this->DrawFormat(eGold, PosX + 80, PosY + 48, 45, 1, "%d ", this->m_Data[index].m_Ene);
			this->DrawFormat(eGold, PosX + 80, PosY + 58, 45, 1, "%d ", this->m_Data[index].m_Com);

			int posM = 0;

			if (gProtect.m_MainInfo.RankUserShowReset != 0)
			{
				this->DrawFormat(eWhite, PosX + 120, PosY + 8, 25, 1, "Resets:");
				this->DrawFormat(eGold, PosX + 147, PosY + 8, 37, 1, "%d", this->m_Data[index].m_Resets);
			}
			else
			{
				posM -= 10;
			}

			if (gProtect.m_MainInfo.RankUserShowMasterReset != 0)
			{
				this->DrawFormat(eWhite, PosX + 120, PosY + 18 + posM, 25, 1, gCustomMessage.GetMessage(68));
				this->DrawFormat(eGold, PosX + 147, PosY + 18 + posM, 37, 1, "%d", this->m_Data[index].m_MResets);
			}
			else
			{
				posM -= 10;
			}

			this->DrawFormat(eWhite, PosX + 120, PosY + 28 + posM, 25, 1, "Kills:");
			this->DrawFormat(eWhite, PosX + 120, PosY + 38 + posM, 25, 1, "Deaths:");
			this->DrawFormat(eGold, PosX + 147, PosY + 28 + posM, 37, 1, "%d", this->m_Data[index].m_Kills);
			this->DrawFormat(eGold, PosX + 147, PosY + 38 + posM, 37, 1, "%d", this->m_Data[index].m_Deads);

			this->DrawFormat(eAncient, PosX + 120, PosY + 48 + posM, 60, 1, "%s", this->m_Data[index].m_Vip);
			this->DrawFormat(eOrange, PosX + 120, PosY + 58 + posM, 60, 1, "%s", classename);

		}
		else if (gProtect.m_MainInfo.RankUserType == 1)
		{

			glColor4f(0.0, 0.0, 0.0, 0.8);
			pDrawBarForm((float)(PosX + 40), (float)(PosY - 8), 120.0f, 76.0f, 0.0f, 0);
			pGLSwitchBlend();

			this->DrawFormat(eWhite, PosX + 50, PosY - 2, 15, 1, "Lvl:");

			int posM = 0;

			if (gProtect.m_MainInfo.RankUserShowReset != 0)
			{
				this->DrawFormat(eWhite, PosX + 50, PosY + 8, 25, 1, "Resets:");
				this->DrawFormat(eGold, PosX + 87, PosY + 8, 37, 1, "%d", this->m_Data[index].m_Resets);
			}
			else
			{
				posM -= 10;
			}

			if (gProtect.m_MainInfo.RankUserShowMasterReset != 0)
			{
				this->DrawFormat(eWhite, PosX + 50, PosY + 18 + posM, 25, 1, gCustomMessage.GetMessage(68));
				this->DrawFormat(eGold, PosX + 87, PosY + 18 + posM, 37, 1, "%d", this->m_Data[index].m_MResets);
			}
			else
			{
				posM -= 10;
			}

			this->DrawFormat(eWhite, PosX + 50, PosY + 28 + posM, 25, 1, "Kills:");
			this->DrawFormat(eWhite, PosX + 50, PosY + 38 + posM, 25, 1, "Deaths:");

			this->DrawFormat(eGold, PosX + 87, PosY - 2, 45, 1, "%d ", this->m_Data[index].m_Level);
			this->DrawFormat(eGold, PosX + 87, PosY + 28 + posM, 37, 1, "%d", this->m_Data[index].m_Kills);
			this->DrawFormat(eGold, PosX + 87, PosY + 38 + posM, 37, 1, "%d", this->m_Data[index].m_Deads);

			this->DrawFormat(eAncient, PosX + 50, PosY + 48 + posM, 60, 1, "%s", this->m_Data[index].m_Vip);
			this->DrawFormat(eOrange, PosX + 50, PosY + 58 + posM, 60, 1, "%s", classename);

			this->DrawFormat(eGold, PosX + 100, PosY - 5, 70, 3, "%s", this->m_Data[index].szTitleRank);
			this->DrawFormat(eGold, PosX + 100, PosY + 59, 70, 3, "%s", name);
			pSetBlend(true);
			glColor3f(1.0, 1.0, 1.0);
			RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 110, (float)PosY + 9, 78.0, 78.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
			pGLSwitchBlend();
			pGLSwitch();
			glColor3f(1.0, 1.0, 1.0);
			pSetBlend(false);
		}
		else if (gProtect.m_MainInfo.RankUserType == 3)
		{

			glColor4f((GLfloat)0.0, (GLfloat)0.0, (GLfloat)0.0, (float)0.8);
			pDrawBarForm((float)(PosX + 40), (float)(PosY - 5), 80, 85, 0.0f, 0);
			pGLSwitchBlend();

			this->DrawFormat(eSocket, PosX + 40, PosY - 4, 80, 3, "INFO");

			this->DrawFormat(eWhite, PosX + 50, PosY + 8, 15, 1, "Lvl:");

			int posM = 0;

			if (gProtect.m_MainInfo.RankUserShowReset != 0)
			{
				this->DrawFormat(eWhite, PosX + 50, PosY + 18, 25, 1, "Resets:");
				this->DrawFormat(eGold, PosX + 87, PosY + 18, 37, 1, "%d", this->m_Data[index].m_Resets);
			}
			else
			{
				posM -= 10;
			}

			if (gProtect.m_MainInfo.RankUserShowMasterReset != 0)
			{
				this->DrawFormat(eWhite, PosX + 50, PosY + 28 + posM, 25, 1, gCustomMessage.GetMessage(68));
				this->DrawFormat(eGold, PosX + 87, PosY + 28 + posM, 37, 1, "%d", this->m_Data[index].m_MResets);
			}
			else
			{
				posM -= 10;
			}

			this->DrawFormat(eWhite, PosX + 50, PosY + 38 + posM, 25, 1, "Kills:");
			this->DrawFormat(eWhite, PosX + 50, PosY + 48 + posM, 25, 1, "Deaths:");

			this->DrawFormat(eGold, PosX + 87, PosY + 8, 45, 1, "%d ", this->m_Data[index].m_Level);
			this->DrawFormat(eGold, PosX + 87, PosY + 38 + posM, 37, 1, "%d", this->m_Data[index].m_Kills);
			this->DrawFormat(eGold, PosX + 87, PosY + 48 + posM, 37, 1, "%d", this->m_Data[index].m_Deads);

			this->DrawFormat(eAncient, PosX + 50, PosY + 58 + posM, 60, 1, "%s", this->m_Data[index].m_Vip);
			this->DrawFormat(eOrange, PosX + 50, PosY + 68 + posM, 60, 1, "%s", classename);
		}
		else if (gProtect.m_MainInfo.RankUserType == 4)
		{

			glColor4f((GLfloat)0.0, (GLfloat)0.0, (GLfloat)0.0, (float)0.8);
			pDrawBarForm((float)(PosX + 2), (float)(PosY - 76), 75, 10, 0.0f, 0);
			pGLSwitchBlend();

			this->DrawFormat(eGold, PosX + 7, PosY - 75, 70, 3, "%s", this->m_Data[index].szTitleRank);
		}
		else
		{
			glColor4f(0.0, 0.0, 0.0, 0.8);
			pDrawBarForm((float)(PosX + 40), (float)(PosY - 8), 185, 80, 0.0f, 0);
			pGLSwitchBlend();

			this->DrawFormat(eRed2, PosX + 60, PosY - 6, 105, 3, "Character Status:");

			this->DrawFormat(eWhite, PosX + 60, PosY + 8, 15, 1, "Lvl:");
			this->DrawFormat(eWhite, PosX + 60, PosY + 18, 15, 1, "Str:");
			this->DrawFormat(eWhite, PosX + 60, PosY + 28, 15, 1, "Agi:");
			this->DrawFormat(eWhite, PosX + 60, PosY + 38, 15, 1, "Vit:");
			this->DrawFormat(eWhite, PosX + 60, PosY + 48, 15, 1, "Ene:");
			this->DrawFormat(eWhite, PosX + 60, PosY + 58, 15, 1, "Com:");

			this->DrawFormat(eGold, PosX + 80, PosY + 8, 45, 1, "%d ", this->m_Data[index].m_Level);
			this->DrawFormat(eGold, PosX + 80, PosY + 18, 45, 1, "%d ", this->m_Data[index].m_For);
			this->DrawFormat(eGold, PosX + 80, PosY + 28, 45, 1, "%d ", this->m_Data[index].m_Agi);
			this->DrawFormat(eGold, PosX + 80, PosY + 38, 45, 1, "%d ", this->m_Data[index].m_Vit);
			this->DrawFormat(eGold, PosX + 80, PosY + 48, 45, 1, "%d ", this->m_Data[index].m_Ene);
			this->DrawFormat(eGold, PosX + 80, PosY + 58, 45, 1, "%d ", this->m_Data[index].m_Com);

			int posM = 0;

			if (gProtect.m_MainInfo.RankUserShowReset != 0)
			{
				this->DrawFormat(eWhite, PosX + 120, PosY + 8, 25, 1, "Resets:");
				this->DrawFormat(eGold, PosX + 147, PosY + 8, 37, 1, "%d", this->m_Data[index].m_Resets);
			}
			else
			{
				posM -= 10;
			}

			if (gProtect.m_MainInfo.RankUserShowMasterReset != 0)
			{
				this->DrawFormat(eWhite, PosX + 120, PosY + 18 + posM, 25, 1, gCustomMessage.GetMessage(68));
				this->DrawFormat(eGold, PosX + 147, PosY + 18 + posM, 37, 1, "%d", this->m_Data[index].m_MResets);
			}
			else
			{
				posM -= 10;
			}

			this->DrawFormat(eWhite, PosX + 120, PosY + 28 + posM, 25, 1, "Kills:");
			this->DrawFormat(eWhite, PosX + 120, PosY + 38 + posM, 25, 1, "Deaths:");
			this->DrawFormat(eGold, PosX + 147, PosY + 28 + posM, 37, 1, "%d", this->m_Data[index].m_Kills);
			this->DrawFormat(eGold, PosX + 147, PosY + 38 + posM, 37, 1, "%d", this->m_Data[index].m_Deads);

			this->DrawFormat(eAncient, PosX + 120, PosY + 48 + posM, 60, 1, "%s", this->m_Data[index].m_Vip);
			this->DrawFormat(eOrange, PosX + 120, PosY + 58 + posM, 60, 1, "%s", classename);

			this->DrawFormat(eGold, PosX + 133, PosY - 5, 126, 3, "%s", this->m_Data[index].szTitleRank);
			this->DrawFormat(eGold, PosX + 133, PosY + 59, 126, 3, "%s", name);
			pSetBlend(true);
			glColor3f(1.0, 1.0, 1.0);
			RenderBitmap(gInterface.Data[rank + 1].ModelID, (float)PosX + 170, (float)PosY + 5, Return2X(TransForX(78)), 78, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
			pGLSwitchBlend();
			pGLSwitch();
			glColor3f(1.0, 1.0, 1.0);
			pSetBlend(false);
		}

	}

	pGLSwitch();
	glColor3f(1.0, 1.0, 1.0);
}






int CCustomRankUser::DrawFormat(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...)
{
	char Buff[2048] = { 0 };
	// ---
	int BuffLen = sizeof(Buff) - 1;
	// ---
	ZeroMemory(Buff, BuffLen);
	// ---
	va_list args;
	// ---
	va_start(args, Text);
	// ---
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	// ---
	va_end(args);
	// ---
	int LineCount = 0;
	// ---
	char * Line = strtok(Buff, "\n");
	// ---
	while (Line != NULL)
	{
		pDrawColorText(Line, PosX, PosY, Width, 5, Color, 9, Align);
		// ---
		PosY += 10;
		// ---
		Line = strtok(NULL, "\n");
	}
	// ---
	return PosY;
}

void CCustomRankUser::GCReqRankLevelUser(PMSG_CUSTOM_RANKUSER* aRecv)
{
	if (aRecv == NULL)
	{
		return;
	}

	int maxData = sizeof(this->m_Data) / sizeof(this->m_Data[0]);

	if (aRecv->iIndex < 0 || aRecv->iIndex >= maxData)
	{
		return;
	}

	int safeRank = aRecv->iRank;

	if (safeRank < 0 || safeRank > 30)
	{
		safeRank = 0;
	}

	this->m_Data[aRecv->iIndex].m_Enabled = true;
	this->m_Data[aRecv->iIndex].m_Level = aRecv->iLevel;
	this->m_Data[aRecv->iIndex].m_Resets = aRecv->iReset;
	this->m_Data[aRecv->iIndex].m_MResets = aRecv->iMReset;
	this->m_Data[aRecv->iIndex].m_Kills = aRecv->iKills;
	this->m_Data[aRecv->iIndex].m_Deads = aRecv->iDeads;
	this->m_Data[aRecv->iIndex].m_For = aRecv->iFor;
	this->m_Data[aRecv->iIndex].m_Agi = aRecv->iAgi;
	this->m_Data[aRecv->iIndex].m_Ene = aRecv->iEne;
	this->m_Data[aRecv->iIndex].m_Vit = aRecv->iVit;
	this->m_Data[aRecv->iIndex].m_Com = aRecv->iCom;
	this->m_Data[aRecv->iIndex].m_Classe = aRecv->iClasse;
	this->m_Data[aRecv->iIndex].m_Rank = safeRank;
	this->m_Data[aRecv->iIndex].m_rDanhHieu = aRecv->irDanhHieu;
	this->m_Data[aRecv->iIndex].m_rQuanHam = aRecv->irQuanHam;
	this->m_Data[aRecv->iIndex].m_rTuLuyen = aRecv->irTuLuyen;
	this->m_Data[aRecv->iIndex].m_rVipTaiKhoan = aRecv->irVipTaiKhoan;
#if(B_HON_HOAN)
	this->m_Data[aRecv->iIndex].m_CapDoHonHoan = aRecv->CapDoHonHoan;
#endif
#if(FLAG_SKIN)
	this->m_Data[aRecv->iIndex].m_Flag = aRecv->Flag;
#endif
}

bool CPreviewManager::ObjCheck(int index, int pThis)
{
	if (pThis == NULL)
	{
		return false;
	}
	// ---
	if (!CS_GET_STRUCT(index, pThis))
	{
		return false;
	}
	// ---
	return true;
}

bool CPreviewManager::ObjSelect(int index, int pThis)
{
	if (pThis == NULL)
	{
		return false;
	}
	// ---
	this->Index = *(WORD*)(CS_GET_STRUCT(index, pThis) + 86);
	this->Live = *(BYTE*)(CS_GET_STRUCT(index, pThis) + 616);
	this->Type = *(BYTE*)(CS_GET_STRUCT(index, pThis) + 634);
	this->IsSafeZone = *(BYTE*)(CS_GET_STRUCT(index, pThis) + 14);
	// ---
	this->Angle.X = *(float*)(CS_GET_STRUCT(index, pThis) + 864);
	this->Angle.Y = *(float*)(CS_GET_STRUCT(index, pThis) + 868);
	this->Angle.Z = *(float*)(CS_GET_STRUCT(index, pThis) + 872) + *(float*)(CS_GET_STRUCT(index, pThis) + 836) + 100.0f;
	// ---
	return true;
}

