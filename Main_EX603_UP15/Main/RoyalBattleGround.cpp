#include "stdafx.h"
#include "RoyalBattleGround.h"
#include "CustomFont.h"
#include "Interface.h"

cRoyalBattleGround RoyalBattleGround;

cRoyalBattleGround::cRoyalBattleGround()
{
	this->m_State = 0;
	this->m_RemainTime = 0;
	this->m_Kill = 0;
	this->m_Alive = 0;
	this->m_Total = 0;
	this->m_Top = 0;

	this->SetDrawing(false);
	this->SetRect(120, 70, 400, 255);
	this->m_MapEvent = -1;
	for (int n = 0; n < 10; n++)
	{
		memset(m_SinhTonBXH[n].szName, 0, sizeof(m_SinhTonBXH[n].szName));
		m_SinhTonBXH[n].Kill = 0;
	}
	this->SinhTonBXHC;
}

cRoyalBattleGround::~cRoyalBattleGround()
{
}

char*cRoyalBattleGround::GetPhaseName()
{
	switch (this->m_State)
	{
	case 0x1:
		return "Đóng Sau";
		break;
	case 0x2:
		return "Chuẩn bị bắt đầu";
		break;
	case 0x3:
		return "Giai Đoạn 1";
		break;
	case 0x4:
		return "Giai Đoạn 2";
		break;
	case 0x5:
		return "Giai Đoạn 3";
		break;
	case 0x6:
		return "Event Đóng Sau";
		break;
	}
	return "Thời Gian Chờ Mở";
}

char* cRoyalBattleGround::GetTimeRemain()
{
	return "";
}


void cRoyalBattleGround::PhaseRecv(BYTE* lpMsg)
{
	PSWMSG_ROYAL_BATTLE_GROUND_PHASE_RECV* Data = (PSWMSG_ROYAL_BATTLE_GROUND_PHASE_RECV*)lpMsg;
	this->m_State = Data->Phase;
	this->m_RemainTime = Data->Remain;
	this->m_MapEvent = Data->Map;
	this->zoneX = Data->Zone[0];
	this->zoneY = Data->Zone[1];
	this->zoneW = Data->Zone[2];
	this->zoneH = Data->Zone[3];
}
void cRoyalBattleGround::PointRecv(BYTE* lpMsg)
{
	PSWMSG_ROYAL_BATTLE_GROUND_POINT_RECV* Data = (PSWMSG_ROYAL_BATTLE_GROUND_POINT_RECV*)lpMsg;
	this->m_Alive = Data->Alive;
	this->m_Kill = Data->Kill;
	this->m_Total = Data->Total;
	this->m_Top = Data->Top;
	this->m_LiveCount = Data->LiveCount;
}
void cRoyalBattleGround::KillRecv(BYTE* lpMsg)
{
	PSWMSG_ROYAL_BATTLE_GROUND_KILL_RECV* Data = (PSWMSG_ROYAL_BATTLE_GROUND_KILL_RECV*)lpMsg;

	RBG_KILLS kill = { 0 };

	memcpy(kill.Player, Data->Player, sizeof(Data->Player));
	memcpy(kill.Target, Data->Target, sizeof(Data->Target));

	if (this->m_RBGKillLog.size() >= RBG_MAX_KILL_LOG)
	{
		this->m_RBGKillLog.erase(this->m_RBGKillLog.begin());
	}
	this->m_RBGKillLog.push_back(kill);
}
void cRoyalBattleGround::ZoneRecv(BYTE* lpMsg)
{
	PSWMSG_ROYAL_BATTLE_GROUND_ZONE_RECV* Data = (PSWMSG_ROYAL_BATTLE_GROUND_ZONE_RECV*)lpMsg;
	this->SetZone(Data->X, Data->Y, Data->W, Data->H);
}


#define ConvertX							((float(__cdecl*)(float x)) 0x00636420)
#define ConvertY							((float(__cdecl*)(float y)) 0x00636450)

GLvoid cRoyalBattleGround::GetDrawCircle(int ID, float X, float Y, float W, float CurrenX, float CurrenY, float SetScale, int ScaleSize, int ScalePosicion, float Alpha)
{
	float v14; // ST1C_4@1
	float v15; // ST18_4@1
	GLuint vertexcount; // ST1C_4@5
	float v33; // ST1C_4@5
	GLfloat angle; // ST1C_4@5
	GLfloat texturecoord[2]; // [sp+2Ch] [bp-40h]@5
	GLfloat VertexCoord[4]; // [sp+4Ch] [bp-20h]@5

	SetScale = SetScale / 2;
	//--
	W = W / 2;
	X = X + W;
	Y = Y + W;

	if (ScalePosicion)
	{
		X = ConvertX(X);
		Y = ConvertY(Y);
	}

	if (ScaleSize)
	{
		W = ConvertX(W);
	}

	v33 = (double)pWinHeight - Y;

	vertexcount = max(15, w / 12);

	((bool(__cdecl*)(int a1)) 0x00635CF0)(ID);

	glBegin(GL_POLYGON);

	angle = 2.0 * 3.1415926 / vertexcount;
	//--
	if (Alpha > 0.0)
		glColor4f(1.0, 1.0, 1.0, Alpha);
	texturecoord[0] = CurrenX;
	texturecoord[1] = CurrenY;
	glTexCoord2fv(texturecoord);
	//--
	VertexCoord[0] = X;
	VertexCoord[1] = v33;
	VertexCoord[2] = 0.0;
	VertexCoord[3] = 1.0;
	glVertex4fv(VertexCoord);

	for (int i = 0; i < vertexcount; i++)
	{
		texturecoord[0] = (std::cos(angle * i) * SetScale) + CurrenX;
		texturecoord[1] = (std::sin(angle * i) * SetScale) + CurrenY;
		glTexCoord2fv(texturecoord);
		VertexCoord[0] = (std::cos(angle * i) * W) + X;
		VertexCoord[1] = (std::sin(angle * i) * -W) + v33;
		VertexCoord[2] = 0.0;
		VertexCoord[3] = 1.0;
		glVertex4fv(VertexCoord);
	}
	//--
	texturecoord[0] = (1.0 * SetScale) + CurrenX;
	texturecoord[1] = (0.0 * SetScale) + CurrenY;
	glTexCoord2fv(texturecoord);
	//--
	VertexCoord[0] = (1.0 * W) + X;
	VertexCoord[1] = (0.0 * -W) + v33;
	VertexCoord[2] = 0.0;
	VertexCoord[3] = 1.0;
	glVertex4fv(VertexCoord);
	//--
	if (Alpha > 0.0)
		glColor4f(1.0, 1.0, 1.0, 1.0);
	//--
	glEnd();
}
#include "Defines.h"

void cRoyalBattleGround::Draw()
{



	this->DrawJoin();
	if (gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::FriendList)
		|| gInterface.CheckWindow(ObjWindow::MoveList)
		|| gInterface.CheckWindow(ObjWindow::Party)
		|| gInterface.CheckWindow(ObjWindow::Quest)
		|| gInterface.CheckWindow(ObjWindow::NPC_Devin)
		|| gInterface.CheckWindow(ObjWindow::Guild)
		|| gInterface.CheckWindow(ObjWindow::Trade)
		|| gInterface.CheckWindow(ObjWindow::Warehouse)
		|| gInterface.CheckWindow(ObjWindow::ChaosBox)
		|| gInterface.CheckWindow(ObjWindow::CommandWindow)
		|| gInterface.CheckWindow(ObjWindow::PetInfo)
		|| gInterface.CheckWindow(ObjWindow::Shop)
		|| gInterface.CheckWindow(ObjWindow::Inventory)
		|| gInterface.CheckWindow(ObjWindow::Store)
		|| gInterface.CheckWindow(ObjWindow::OtherStore)
		|| gInterface.CheckWindow(ObjWindow::Character)
		|| gInterface.CheckWindow(ObjWindow::DevilSquare)
		|| gInterface.CheckWindow(ObjWindow::BloodCastle)
		|| gInterface.CheckWindow(ObjWindow::CreateGuild)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC)
		|| gInterface.CheckWindow(ObjWindow::SeniorNPC)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC2)
		|| gInterface.CheckWindow(ObjWindow::CastleGateSwitch)
		|| gInterface.CheckWindow(ObjWindow::CatapultNPC)
		|| gInterface.CheckWindow(ObjWindow::CrywolfGate)
		|| gInterface.CheckWindow(ObjWindow::IllusionTemple)
		|| gInterface.CheckWindow(ObjWindow::HeroList)
		|| gInterface.CheckWindow(ObjWindow::ChatWindow)
		|| gInterface.CheckWindow(ObjWindow::FastMenu)
		|| gInterface.CheckWindow(ObjWindow::Options)
		|| gInterface.CheckWindow(ObjWindow::Help)
		|| gInterface.CheckWindow(ObjWindow::FastDial)
		|| gInterface.CheckWindow(ObjWindow::SkillTree)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher1)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher2)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin1)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin2)
		|| gInterface.CheckWindow(ObjWindow::NPC_Duel)
		|| gInterface.CheckWindow(ObjWindow::NPC_Titus)
		|| gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::Lugard)
		|| gInterface.CheckWindow(ObjWindow::QuestList1)
		|| gInterface.CheckWindow(ObjWindow::QuestList2)
		|| gInterface.CheckWindow(ObjWindow::Jerint)
		|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)
		|| gInterface.CheckWindow(ObjWindow::GensInfo)
		|| gInterface.CheckWindow(ObjWindow::NPC_Julia)
		|| gInterface.CheckWindow(ObjWindow::NPC_ChaosMix)
		|| gInterface.CheckWindow(ObjWindow::ExpandInventory)
		|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse)
		|| gInterface.CheckWindow(ObjWindow::MuHelper)
		|| pMapNumber != RoyalBattleGround.m_MapEvent
		)
	{
		return;
	}

	if (this->m_State >= 1 && this->m_State < 8)
	{
		//this->DrawMap();
		this->DrawInfo();
		this->DrawKill();
		this->DrawBXH();
	}

	if (pIsKeyRelease(VK_TAB))
	{
		this->drawmap = !this->drawmap;

	}

	/*float usercurrentx = (double)(*(signed int *)(*(DWORD*)0x7BC4F04 + 172) + 2.5) / 256.0;
	float usercurrenty = (double)(253.5 - *(signed int *)(*(DWORD*)0x7BC4F04 + 176)) / 256.0;*/

	//GetDrawCircle(550000, x - 50, y - 40, 350, usercurrentx, usercurrenty, 0.3, 2, 2, 6.0); //img map

}

void cRoyalBattleGround::DrawJoin()
{


	if (this->m_TickCount + 1000 <= GetTickCount())
	{
		this->m_TickCount = GetTickCount();
		if (this->m_RemainTime > 0)
			this->m_RemainTime--;
		else
			this->m_RemainTime = 0;
	}

	if (pIsKeyRelease(VK_F4))
	{
		this->m_DrawingJoin = !this->m_DrawingJoin;

	}
	if (!this->m_DrawingJoin)
	{
		return;
	}
	//==========
	glAlphaFunc(GL_GREATER, 0.0f);


	//RenderBitmap(31322, x, y, w, h, 0, 0, 190.0f / 256.f, 320.f / 512.f, 1, 1, 0.0);
	CustomFont.Draw(CustomFont.FontBold, x, y, 0x0, 0x171717ff, w, h, 1, " ");

	/*int i = 0;
	for (i = 0; i < 360; i++) {
	pDrawGUI(31344, x + 21 + i, y + 60, 1.0, 14.0);
	pDrawGUI(31345, x + 21 + i, y + 240, 1.0, 14.0);
	}

	for (i = 0; i < 166; i++) {
	pDrawGUI(31346, x + 7, y + 60 + 14 + i, 14.0, 1.0);
	pDrawGUI(31347, x + w - 19, y + 60 + 14 + i, 14.0, 1.0);
	}

	pDrawGUI(31340, x + 7, y + 60, 14.0, 14.0);
	pDrawGUI(31341, x + w - 19, y + 60, 14.0, 14.0);

	pDrawGUI(31342, x + 7, y + 240, 14.0, 14.0);
	pDrawGUI(31343, x + w - 19, y + 240, 14.0, 14.0);
	*/
	RenderBitmap(31355, x, y + 63, 21.0, 159.2f, 0, 0, 21.f / 32.f, 320.f / 512.f, 1, 1, 0.0);
	RenderBitmap(31356, x + w - 21.f, y + 63, 21.0, 159.2f, 0, 0, 21.f / 32.f, 320.f / 512.f, 1, 1, 0.0);

	RenderBitmap(31353, x, y, 60.f, 63.f, 0.0, 0, 60.f / 256.f, 63.f / 64.f, 1, 1, 0.0);
	RenderBitmap(31353, x + 60, y, 70.f, 63.f, 60.f / 256.f, 0, 70.f / 256.f, 63.f / 64.f, 1, 1, 0.0);
	RenderBitmap(31353, x + 130, y, 70.f, 63.f, 60.f / 256.f, 0, 70.f / 256.f, 63.f / 64.f, 1, 1, 0.0);
	RenderBitmap(31353, x + 200, y, 70.f, 63.f, 60.f / 256.f, 0, 70.f / 256.f, 63.f / 64.f, 1, 1, 0.0);
	RenderBitmap(31353, x + 270, y, 70.f, 63.f, 60.f / 256.f, 0, 70.f / 256.f, 63.f / 64.f, 1, 1, 0.0);
	RenderBitmap(31353, x + 340, y, 60.f, 63.f, 130.f / 256.f, 0, 60.f / 256.f, 63.f / 64.f, 1, 1, 0.0);

	RenderBitmap(31357, x, y + 212, 60.f, 63.f, 0.0, 0, 60.f / 256.f, 63.f / 64.f, 1, 1, 0.0);
	RenderBitmap(31357, x + 60, y + 212, 70.f, 63.f, 60.f / 256.f, 0, 70.f / 256.f, 63.f / 64.f, 1, 1, 0.0);
	RenderBitmap(31357, x + 130, y + 212, 70.f, 63.f, 60.f / 256.f, 0, 70.f / 256.f, 63.f / 64.f, 1, 1, 0.0);
	RenderBitmap(31357, x + 200, y + 212, 70.f, 63.f, 60.f / 256.f, 0, 70.f / 256.f, 63.f / 64.f, 1, 1, 0.0);
	RenderBitmap(31357, x + 270, y + 212, 70.f, 63.f, 60.f / 256.f, 0, 70.f / 256.f, 63.f / 64.f, 1, 1, 0.0);
	RenderBitmap(31357, x + 340, y + 212, 60.f, 63.f, 130.f / 256.f, 0, 60.f / 256.f, 63.f / 64.f, 1, 1, 0.0);


	if (pIsKeyRelease(VK_LBUTTON) && gInterface.IsWorkZone4(x + w - 25, y + 5, 20, 18))
	{
		this->m_DrawingJoin = false;
	}

	CustomFont.Draw(CustomFont.FontBold, x + 25, y + 40, 0xFFDE26FF, 0x0, w - 50, 20, 3, "Sự Kiện Sống Còn");

	CustomFont.Draw(CustomFont.FontNormal, x + 25, y + 50, 0xFFDE26FF, 0x0, w - 50, 15, 1, "Người chơi sau khi tham gia sẽ trở về nhân vật mặc định");

	CustomFont.Draw(CustomFont.FontNormal, x + 25, y + 65, 0xFFDE26FF, 0x0, w - 50, 15, 1, "Mỗi người chơi có 15000K Point");

	CustomFont.Draw(CustomFont.FontNormal, x + 25, y + 80, 0xFFDE26FF, 0x0, w - 50, 15, 1, "Khi tham gia sự kiện nhanh chóng tăng điểm ");

	CustomFont.Draw(CustomFont.FontNormal, x + 25, y + 95, 0xFFDE26FF, 0x0, w - 50, 15, 1, "Khi sự kiện bắt đầu người chơi sẽ được dịch chuyển ngẫu nhiên");

	CustomFont.Draw(CustomFont.FontNormal, x + 25, y + 110, 0xFFDE26FF, 0x0, w - 50, 15, 1, "Thu thập vũ khí được thả ở xung quanh map");

	CustomFont.Draw(CustomFont.FontNormal, x + 25, y + 125, 0xFFDE26FF, 0x0, w - 50, 15, 1, "Vòng an toàn sẽ thu hẹp theo mỗi vòng");

	CustomFont.Draw(CustomFont.FontNormal, x + 25, y + 140, 0xFFDE26FF, 0x0, w - 50, 15, 1, "khi ở ngoài vùng an toàn sẽ bị thiêu đốt và mất máu");

	CustomFont.Draw(CustomFont.FontNormal, x + 25, y + 155, 0xFFDE26FF, 0x0, w - 50, 15, 1, "Các người chơi sẽ pk với nhau để giành chiến thắng sau cùng");

	CustomFont.Draw(CustomFont.FontNormal, x + 25, y + 170, 0xFFDE26FF, 0x0, w - 50, 15, 1, "phần thưởng sẽ được thêm vào cho Top 1 2 3");

	CustomFont.Draw(CustomFont.FontNormal, x + 25, y + 185, 0xFFDE26FF, 0x0, w - 50, 15, 1, "hãy sử dụng chiến thuật chiến đấu cẩn thận để giành chiến thắng");

	CustomFont.Draw(CustomFont.FontNormal, x + 25, y + 200, 0xFFDE26FF, 0x0, w - 50, 15, 1, "Chúc các bạn tham gia event vui vẻ");




	if (pIsKeyRelease(VK_LBUTTON) && gInterface.IsWorkZone(x + w - 25, y + 5, 20, 18))
	{
		this->m_DrawingJoin = false;
	}

	glAlphaFunc(GL_GREATER, 0.25f);

	CustomFont.Draw(CustomFont.FontBold, x, y + 12, 0xffffffff, 0x0, w, 0, 3, "Sinh Tồn");

	RoyalBattleGround.DrawButton(32331, x + 14 + 75 * 4, y + h - 40, 73, 27, 128.0, 128.0, RoyalBattleGround.JoinAction);

	int totalseconds = this->m_RemainTime;
	int hours = totalseconds / 3600;
	int minutes = (totalseconds / 60) % 60;
	int seconds = totalseconds % 60;
	char zTimeText[60] = { 0 };
	if (hours > 23)
	{
		int days = hours / 24;
		sprintf(zTimeText, "%d day(s)+\0", days);
	}
	else if (hours)
	{
		sprintf(zTimeText, "%02d:%02d:%02d\0", hours, minutes, seconds);
	}
	else
	{
		sprintf(zTimeText, "%02d:%02d\0", minutes, seconds);
	}

	if (this->m_State == 1)
	{
		CustomFont.Draw(CustomFont.FontNormal, x + 14 + 75 * 4, y + h - 32.5, 0xffffffff, 0x0, 73, 0, 3, "Tham Gia");
	}
	else if (this->m_State == 0 && this->m_RemainTime)
	{
		CustomFont.Draw(CustomFont.FontNormal, x + 14 + 75 * 4, y + h - 32.5, 0xffffffff, 0x0, 73, 0, 3, zTimeText);
	}
	else
	{
		CustomFont.Draw(CustomFont.FontNormal, x + 14 + 75 * 4, y + h - 32.5, 0xffffffff, 0x0, 73, 0, 3, "Đóng!");
	}


	CustomFont.Draw(CustomFont.FontNormal, x + 14 + 75 * 4, y + h - 52.5, 0xffffffff, 0x0, 73, 0, 3, "state: %d", this->m_State);
}
//==================

//============================
void cRoyalBattleGround::BEventSinhTon_BXC(PMSG_NEW_HEALTH_BAR_RECV* lpMsg)
{
	SinhTonBXHC = 0;
	for (int n = 0; n < 10; n++)
	{
		memset(m_SinhTonBXH[n].szName, 0, sizeof(m_SinhTonBXH[n].szName));
		m_SinhTonBXH[n].Kill = 0;
	}

	for (int n = 0; n < lpMsg->count; n++)
	{
		BEVENTDATA_BXH* lpInfo = (BEVENTDATA_BXH*)(((BYTE*)lpMsg) + sizeof(PMSG_NEW_HEALTH_BAR_RECV)+(sizeof(BEVENTDATA_BXH)* n));
		memcpy(m_SinhTonBXH[n].szName, lpInfo->szName, sizeof(m_SinhTonBXH[n].szName));
		m_SinhTonBXH[n].Kill = lpInfo->Kill;
		SinhTonBXHC++;

		if (SinhTonBXHC > 10)
		{
			break;
		}
	}
}
#include "Central.h"
void cRoyalBattleGround::DrawBXH()
{
	float X = MAX_WIN_WIDTH - 125;
	float Y = 150;
	float BXHSinhTonW = 110;
	float BXHSinhTonH = 150;

	//gCentral.gInfoBox(X, Y, BXHSinhTonW, BXHSinhTonH,BxhBattle,TRUE,"Ranking Killer");
	gCentral.gInfoBox(X, Y, BXHSinhTonW, BXHSinhTonH, 0x00000096, 0, 0);
	//====================================
	CustomFont.Draw(CustomFont.FontBold, X + BXHSinhTonW / 3, Y, 0xFABB00FF, 0x0, BXHSinhTonW / 3, 0, 3, "Xếp Hạng"); //
	CustomFont.Draw(CustomFont.FontBold, X, Y + 7, 0xFABB00FF, 0x0, BXHSinhTonW / 3, 0, 3, "Top"); //
	CustomFont.Draw(CustomFont.FontBold, X + BXHSinhTonW / 3, Y + 7, 0xFABB00FF, 0x0, BXHSinhTonW / 3, 0, 3, "Name"); //
	CustomFont.Draw(CustomFont.FontBold, X + ((BXHSinhTonW / 3) * 2), Y + 7, 0xFABB00FF, 0x0, BXHSinhTonW / 3, 0, 3, "Kill"); //

	DWORD ColorTextRank = 0xE0DFDCFF;
	for (int i = 0; i < SinhTonBXHC; i++)
	{
		if (i % 2)
		{
			ColorTextRank = 0xA3A3A3FF;
		}
		else {
			ColorTextRank = 0xE0DFDCFF;
		}
		if (i < 3) { ColorTextRank = 0xFFE240FF; }
		CustomFont.Draw(CustomFont.FontBold, X, Y + (7 + 15) + (i * 12), ColorTextRank, (i < 3) ? 0xFFE2400F : 0x0, BXHSinhTonW / 3, 0, 3, "%d", i + 1); //
		CustomFont.Draw(CustomFont.FontBold, X + BXHSinhTonW / 3, Y + (7 + 15) + (i * 12), ColorTextRank, (i < 3) ? 0xFFE2400F : 0x0, BXHSinhTonW / 3, 0, 3, m_SinhTonBXH[i].szName); //
		CustomFont.Draw(CustomFont.FontBold, X + ((BXHSinhTonW / 3) * 2), Y + (7 + 15) + (i * 12), ColorTextRank, (i < 3) ? 0xFFE2400F : 0x0, BXHSinhTonW / 3, 0, 3, "%d", m_SinhTonBXH[i].Kill); //

	}
}
void cRoyalBattleGround::DrawInfo()
{

	int totalseconds = this->m_RemainTime;
	int hours = totalseconds / 3600;
	int minutes = (totalseconds / 60) % 60;
	int seconds = totalseconds % 60;
	char zTimeText[60] = { 0 };
	if (hours > 23)
	{
		int days = hours / 24;
		sprintf(zTimeText, "%d day(s)+\0", days);
	}
	else if (hours)
	{
		sprintf(zTimeText, "%02d:%02d:%02d\0", hours, minutes, seconds);
	}
	else
	{
		sprintf(zTimeText, "%02d:%02d\0", minutes, seconds);
	}


	float ToaDoX = MAX_WIN_WIDTH - 120;
	float ToaDoY = MAX_WIN_HEIGHT - (460 - 300);
	EnableAlphaTest(1);
	glColor4f(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0f, 1.0f, 1.0f);
	//Khung INfo
	float KhungInfoX = ToaDoX - 2;
	float KhungInfoY = ToaDoY + 20;
	RenderBitmap(31672, KhungInfoX, KhungInfoY, 110, 83.0, 0, 0, 0.95, 0.6, 1, 1, 0.0);
	CustomFont.Draw(CustomFont.FontNormal, KhungInfoX + 15, KhungInfoY + 12, 0xFA0000FF, 0x0, (110 / 2), 0, 1, "Kill: %d", this->m_Kill); //Buoc Vao
	CustomFont.Draw(CustomFont.FontNormal, KhungInfoX + (110 / 2) - 15, KhungInfoY + 12, 0xFACC00FF, 0x0, (110 / 2), 0, 4, "Top: %d", this->m_Top); //Buoc Vao
	CustomFont.Draw(CustomFont.FontNormal, KhungInfoX, KhungInfoY + 8 + 15 * 2, 0x008EFAFF, 0x0, 110, 0, 3, "Live: %d/%d", this->m_Alive, this->m_Total); //Buoc Vao
	//==Time
	CustomFont.Draw(CustomFont.FontNormal, KhungInfoX, KhungInfoY + 8 + 15 * 3, 0x0FFBFFff, 0x0, 110, 0, 3, "%s", this->GetPhaseName());
	CustomFont.Draw(CustomFont.FontNormal, KhungInfoX, KhungInfoY + 8 + (15 * 3) + 10, 0xffffffff, 0x0, 110, 0, 3, "%s", zTimeText);

	//CustomFont.Draw(CustomFont.FontNormal, KhungInfoX, KhungInfoY-15, 0xffffffff, 0x0, 110, 0, 3, "(%d/%d) W %d", (int)RoyalBattleGround.zoneX, (int)RoyalBattleGround.zoneY, (int)RoyalBattleGround.zoneW);
}

void cRoyalBattleGround::DrawKill()
{
	if (this->m_KillTickCount + 15000 <= GetTickCount())
	{
		if (this->m_RBGKillLog.size())
		{
			this->m_RBGKillLog.erase(this->m_RBGKillLog.begin());
		}
		this->m_KillTickCount = GetTickCount();
	}

	for (int i = 0; i < this->m_RBGKillLog.size(); i++)
	{
		CustomFont.Draw(CustomFont.FontNormal, MAX_WIN_WIDTH - 160, 20 + 13 * i, 0xffffffff, 0x0, 140.0, 0, 4, "%s  KILL  %s", this->m_RBGKillLog[i].Player, this->m_RBGKillLog[i].Target);
		CustomFont.Draw(CustomFont.FontNormal, MAX_WIN_WIDTH - 160, 20 + 13 * i, 0xff2222ff, 0x0, 140.0, 0, 4, "KILL  %s", this->m_RBGKillLog[i].Target);
		CustomFont.Draw(CustomFont.FontNormal, MAX_WIN_WIDTH - 160, 20 + 13 * i, 0xffffffff, 0x0, 140.0, 0, 4, "%s", this->m_RBGKillLog[i].Target);
	}
}

void cRoyalBattleGround::DrawMap()
{
	if (!this->drawmap)
	{
		return;
	}

	pSetBlend(1);

	glColor4f(0.0, 0.0, 0.0, 0.5);
	//pDrawBarForm(480, 5, 150.0, 245.0, 0, 0);
	//384
	float RenderMapX = (MAX_WIN_WIDTH / 2) - (384 / 2);
	float RenderMapY = (MAX_WIN_HEIGHT / 2) - (384 / 2) - 30;
	WORD* TerrainWall = (WORD*)0x82C6AA0;
	WORD wall;

	for (int _x = 0; _x < 255; _x++)
	{
		for (int _y = 0; _y < 255; _y++)
		{
			wall = TerrainWall[BTERRAIN_INDEX(_x, _y)];
			/*if((wall & 0x0004) == 0x0004)
			{
			glColor4f(1.0, 0.1, 0.1, 1.0);
			}
			else */
			if ((wall & 0x0004) != 0x0004 && (wall & 0x0008) != 0x0008 && (wall & 0x0010) != 0x0010)
			{
				glColor4f(0.615, 0.7478, 0.75, 0.75);
			}
			else
			{
				glColor4f(0.0, 0.0, 0.0, 0.0);
			}
			//pDrawBarForm(492 + (_y *1.5), 105 + (_x *1.5), 1.5, 1.5, 0, 0);
			pDrawBarForm(RenderMapX + (_y *1.5), RenderMapY + (_x *1.5), 1.5, 1.5, 0, 0);
		}
	}

	float playerX = *(DWORD*)(*(DWORD*)0x007BC4F04 + 172);
	float playerY = 256 - *(DWORD*)(*(DWORD*)0x007BC4F04 + 176);

	glColor4f(1.0, 1.0, 1.0, 1.0);
	//pDrawBarForm(491 + playerX / 2, 104 + playerY / 2, 3.0, 3.0, 0, 0);
	pDrawBarForm((RenderMapX - 1) + (playerX *1.5), (RenderMapY - 1) + (playerY * 1.5), 3.0, 3.0, 0, 0);

	//glColor4f(0.1, 1.0, 0.1, 0.5);
	//pDrawBarForm(491 + zoneY / 2, 104 + zoneX / 2, zoneW / 2, zoneH / 2, 0, 0);
	//==Khung Bo
	glColor4f(1.0, 0.1, 0.1, 0.35);
	//pDrawBarForm((RenderMapX - 1), (RenderMapY - 1), zoneY * 1.5, 255 * 1.5, 0, 0);
	//pDrawBarForm((RenderMapX - 1) + (zoneY + zoneH) * 1.5, (RenderMapY - 1), (255 - zoneY - zoneH) * 1.5, 255 * 1.5, 0, 0);
	//pDrawBarForm((RenderMapX - 1) + zoneY * 1.5, (RenderMapY - 1) + (zoneX + zoneW) * 1.5, zoneH * 1.5, (255 - zoneX - zoneW) * 1.5, 0, 0);
	//pDrawBarForm((RenderMapX - 1) + zoneY * 1.5, (RenderMapY - 1), zoneH * 1.5, zoneX * 1.5, 0, 0);
	glColor4f(1.0, 1.0, 1.0, 1.0);
	pSetBlend(1);
	if (RoyalBattleGround.m_State >= 2 && pMapNumber == RoyalBattleGround.m_MapEvent)
	{
		//==Khung Bo
		glColor4f(1.0, 0.6667, 0, 0.35);
		float ViTriX = RoyalBattleGround.zoneX;
		float ViTriY = (255 - RoyalBattleGround.zoneY);
		pDrawBarForm((RenderMapX - 1) + (ViTriX* 1.8700005f), (RenderMapY + 2) + ((ViTriY *  1.8700005f) - (RoyalBattleGround.zoneW *  1.8700005f)), (RoyalBattleGround.zoneW *  1.8700005f), (RoyalBattleGround.zoneH *  1.8700005f), 0, 0);

	}


	pGLSwitch();

	pSetBlend(1);
	glColor4f(1.0, 1.0, 1.0, 1.0);

}

void cRoyalBattleGround::ClearSession()
{
	this->m_State = 0;
	this->m_RemainTime = 0;
	this->m_Alive = 0;
	this->m_Kill = 0;
	this->m_DrawingJoin = false;
	this->SetZone(5, 5, 245, 245);

	this->m_RBGKillLog.clear();

	this->m_KillTickCount = GetTickCount();
}
void cRoyalBattleGround::SetRect(float a1, float a2, float a3, float a4)
{
	this->x = a1;
	this->y = a2;
	this->w = a3;
	this->h = a4;
}
void cRoyalBattleGround::SetZone(float a1, float a2, float a3, float a4)
{
	this->zoneX = a1;
	this->zoneY = a2;
	this->zoneW = a3;
	this->zoneH = a4;
}

bool cRoyalBattleGround::IsOnWindow()
{
	return *(HWND*)0x0E8C578 == GetForegroundWindow();
}
bool cRoyalBattleGround::IsWorkZone(float x, float y, float w, float h, bool mode)
{
	if (mode)
		return IsOnWindow() && * (int*)0x879340C >= x && *(int*)0x879340C <= x + w && *(int*)0x8793410 >= y && *(int*)0x8793410 <= y + h;
	return *(int*)0x879340C >= x && *(int*)0x879340C <= x + w && *(int*)0x8793410 >= y && *(int*)0x8793410 <= y + h;
}

bool cRoyalBattleGround::CheckRect()
{
	return this->m_DrawingJoin && IsWorkZone(x, y, w, h);
}

void cRoyalBattleGround::DrawButton(int IMGcode, float x, float y, float w, float h, float a6, float a7, PUSHEVENT_CALLBACK_LPVOID pCallbackFunc, float uw, float uh) {
	if (gInterface.IsWorkZone(x, y, uw, uh)) {
		if (GetKeyState(VK_LBUTTON) & 0x8000) {
			RenderBitmap(IMGcode, x, y, uw, uh, 0.0, h / a7 * 2.0, w / a6, h / a7, 1, 1, 0.0);
		}
		else {
			RenderBitmap(IMGcode, x, y, uw, uh, 0.0, h / a7, w / a6, h / a7, 1, 1, 0.0);
		}
		if (pIsKeyRelease(VK_LBUTTON))
		{
			pCallbackFunc(this);
			return;
		}
		return;
	}
	else {
		RenderBitmap(IMGcode, x, y, uw, uh, 0.0, 0.0, w / a6, h / a7, 1, 1, 0.0);
	}
	return;
}

void cRoyalBattleGround::DrawButton(int IMGcode, float x, float y, float w, float h, float a6, float a7, PUSHEVENT_CALLBACK_LPVOID pCallbackFunc) {
	if (gInterface.IsWorkZone4(x, y, w, h)) {
		if (GetKeyState(VK_LBUTTON) & 0x8000) {
			RenderBitmap(IMGcode, x, y, w, h, 0.0, h / a7 * 2.0, w / a6, h / a7, 1, 1, 0.0);
		}
		else {
			RenderBitmap(IMGcode, x, y, w, h, 0.0, h / a7, w / a6, h / a7, 1, 1, 0.0);
		}
		if (pIsKeyRelease(VK_LBUTTON))
		{
			pCallbackFunc(this);
			return;
		}
		return;
	}
	else {
		RenderBitmap(IMGcode, x, y, w, h, 0.0, 0.0, w / a6, h / a7, 1, 1, 0.0);
	}
	return;
}

void cRoyalBattleGround::JoinAction(LPVOID pClass)
{
	cRoyalBattleGround* This = (cRoyalBattleGround*)pClass;
	if (This->m_State == 1)
	{
		This->SendRequest(0, 1);
		This->m_DrawingJoin = false;
		return;
	}

}
void cRoyalBattleGround::SendRequest(BYTE type, int value)
{
	PMSG_ROYAL_BATTLE_GROUND_REQUEST_SEND pRequest;
	pRequest.h.set((LPBYTE)&pRequest, 0xFB, 0x33, sizeof(pRequest));
	pRequest.type = type;
	pRequest.value = value;
	DataSend((LPBYTE)&pRequest, pRequest.h.size);
}