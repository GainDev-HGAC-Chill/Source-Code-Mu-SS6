#include "stdafx.h"
#include "GuildUpgrade.h"
#include "Util.h"
#include "Interface.h"
#include "CustomFont.h"
#include "Offset.h"
//#include "CNewUIWindowsClient.h"
#include "postInterface.h"

/*
------ ElfCheat -------
Guild Upgrade feature
v1.0
-----------------------
*/

#if(CUSTOM_GUILD_UPGRADE)

cGuildUpgrade GuildUpgrade;

cGuildUpgrade::cGuildUpgrade()
{
	this->Load();
	this->SetDrawing(false);
	this->SetRect(35, 30, 400, 255);
	this->Clear();
}
cGuildUpgrade::~cGuildUpgrade()
{
}
char* GetStatus(BYTE status)
{
	switch (status)
	{
	case 128:
		return (char*)pGetTextLine(pTextLineThis, 1300);
		break;
	case 64:
		return (char*)pGetTextLine(pTextLineThis, 1301);
		break;
	case 32:
		return (char*)pGetTextLine(pTextLineThis, 1302);
		break;
	}
	return "Member";
}
void hook_sub_790B50(int a1, float a2, float a3, float a4, float a5)
{
	pDrawGUI(a1, a2, a3, a4, a5);
	GuildUpgrade.DrawButton(31327, 450 + 64, 390, 64.0, 29.f, 64.0, 128.0, GuildUpgrade.OpenGuildUpgrade);
	gInterface.DrawFormat(-1, 450 + 64, 400, 64, 3, "Nâng Cấp");
}
bool CheckNPCShop()
{
	return gInterface.CheckWindow(12) || GuildUpgrade.CheckRect();
}
bool InGameShopIsInGameShopRect(float _x, float _y)
{
	if (GuildUpgrade.DrawItem3DCenterImage)
		return true;
	if (pCheckWindow(pWindowThis(), 65))
		return _x >= 0 && _x < 640 && _y < 429 && _y >= 0;
	return false;
}
void cGuildUpgrade::Load()
{
	SetCompleteHook(0xE8, 0x7CD940 + 0x317, hook_sub_790B50);
	SetCompleteHook(0xE8, 0x834600 + 0x11C, CheckNPCShop);
	SetCompleteHook(0xE8, 0x005CF3AC, &InGameShopIsInGameShopRect);
}
void cGuildUpgrade::SetRect(float a1, float a2, float a3, float a4)
{
	this->x = a1;
	this->y = a2;
	this->w = a3;
	this->h = a4;
}
void cGuildUpgrade::Clear()
{
	this->SetCurTab(GuildUpgradeTabs::ggInfo);
	this->SetCurPage(1);
	this->SetTotalPages(1);
	this->SetCurItemShop(-1);
	this->CurDevoteItem.ItemID = -1;
	this->SelectedItem.ItemID = -1;
	this->CurDevotePrice = 0;
	this->CurDevoteItemHighLight = -1;
	this->LoadedMyGuild = false;
	this->MeDevote = 0;
	this->MeGuildLevel = 0;
	this->LoadedGuildRanking = false;
	this->LoadedMyGuild = false;
	this->LoadedDevoteItems = false;
	this->LoadedShopItems = false;
}
void cGuildUpgrade::OpenGuildUpgrade(LPVOID pClass)
{
	cGuildUpgrade* This = (cGuildUpgrade*)pClass;
	This->Clear();
	This->ToggleDrawing(); //
}
void cGuildUpgrade::TabInfoAction(LPVOID pClass)
{
	cGuildUpgrade* This = (cGuildUpgrade*)pClass;
	This->SetCurTab(GuildUpgradeTabs::ggInfo);
}
void cGuildUpgrade::TabRankingAction(LPVOID pClass)
{
	cGuildUpgrade* This = (cGuildUpgrade*)pClass;
	This->SetCurTab(GuildUpgradeTabs::ggRanking);
	This->SetCurPage(1);
	if (This->LoadedGuildRanking == false)
	{
		This->SendRequest(1, 0);
	}
	else {
		This->SetTotalPages(1 + floor((float)This->GuildRankingInfo.count / (float)GU_ROW_PER_PAGE));
	}
}
void cGuildUpgrade::TabMyGuildAction(LPVOID pClass)
{
	cGuildUpgrade* This = (cGuildUpgrade*)pClass;
	This->SetCurTab(GuildUpgradeTabs::ggMyGuild);
	This->SetCurPage(1);
	if (This->LoadedMyGuild == false)
	{
		This->SendRequest(2, 0);
	}
	else {
		This->SetTotalPages(1 + floor((float)This->myGuildMemberInfo.count / (float)GU_ROW_PER_PAGE));
	}
}
void cGuildUpgrade::TabDevoteAction(LPVOID pClass)
{
	cGuildUpgrade* This = (cGuildUpgrade*)pClass;
	This->SetCurTab(GuildUpgradeTabs::ggDevote);
	This->SendRequest(0, 1); //get me info
	if (This->LoadedDevoteItems == false)
	{
		This->SendRequest(3, 0);
	}
	else {
		This->SetTotalPages(1 + floor((float)This->DevoteItems.size() / (float)GU_ROW_PER_PAGE));
	}
	This->SetCurPage(1);
	gInterface.OpenWindow(13);
}
void cGuildUpgrade::TabShopAction(LPVOID pClass)
{
	cGuildUpgrade* This = (cGuildUpgrade*)pClass;
	This->SendRequest(0, 1); //get me info
	if (This->LoadedShopItems == false)
	{
		This->SendRequest(4, 0);
	}
	else {
		This->SetTotalPages(1 + floor((float)This->ShopItems.size() / (float)GU_ROW_PER_PAGE));
	}
	This->SetCurPage(1);
	This->SetCurTab(GuildUpgradeTabs::ggShop);
}
void cGuildUpgrade::PagePrevAction(LPVOID pClass)
{
	cGuildUpgrade* This = (cGuildUpgrade*)pClass;
	if (This->GetCurPage() > 1)
		This->SetCurPage(This->GetCurPage() - 1);
}
void cGuildUpgrade::PageNextAction(LPVOID pClass)
{
	cGuildUpgrade* This = (cGuildUpgrade*)pClass;
	if (This->GetCurPage() < This->GetTotalPages())
		This->SetCurPage(This->GetCurPage() + 1);
}
void cGuildUpgrade::ShopBuyAction(LPVOID pClass)
{
	cGuildUpgrade* This = (cGuildUpgrade*)pClass;
	This->SendRequest(6, This->GetCurItemShop());
}
void cGuildUpgrade::DevoteAction(LPVOID pClass)
{
	cGuildUpgrade* This = (cGuildUpgrade*)pClass;
	int Slot = This->CurDevoteItem.PosX + This->CurDevoteItem.PosY * 8 + (This->CurDevoteItemOwner ? 12 : 0);
	This->SendRequest(5, Slot);
}
void cGuildUpgrade::DrawButton(int IMGcode, float x, float y, float w, float h, float a6, float a7, PUSHEVENT_CALLBACK_LPVOID pCallbackFunc) {
	if (gInterface.IsWorkZone1(x, y, w, h))
	{
		if (GetTickCount() - gInterface.Data[eTIME].EventTick > 300) //Click
		{
			if (GetKeyState(VK_LBUTTON) & 0x8000)
			{
				RenderBitmap(IMGcode, x, y, w, h, 0.0, h / a7 * 2.0, w / a6, h / a7, 1, 1, 0.0);
			}
			else
			{
				RenderBitmap(IMGcode, x, y, w, h, 0.0, h / a7, w / a6, h / a7, 1, 1, 0.0);
			}
			if (pIsKeyPress(VK_LBUTTON))
			{
				gInterface.Data[eTIME].EventTick = GetTickCount();
				pCallbackFunc(this);
				return;
			}
		}

		return;
	}
	else {
		RenderBitmap(IMGcode, x, y, w, h, 0.0, 0.0, w / a6, h / a7, 1, 1, 0.0);
	}
	return;
}
void cGuildUpgrade::DrawButton(int IMGcode, float x, float y, float w, float h, float a6, float a7, PUSHEVENT_CALLBACK_LPVOID pCallbackFunc, float uw, float uh) {
	if (gInterface.IsWorkZone1(x, y, uw, uh))
	{
		if (GetTickCount() - gInterface.Data[eTIME].EventTick > 300) //Click
		{
			if (GetKeyState(VK_LBUTTON) & 0x8000)
			{
				RenderBitmap(IMGcode, x, y, uw, uh, 0.0, h / a7 * 2.0, w / a6, h / a7, 1, 1, 0.0);
			}
			else
			{
				RenderBitmap(IMGcode, x, y, uw, uh, 0.0, h / a7, w / a6, h / a7, 1, 1, 0.0);
			}
			if (pIsKeyPress(VK_LBUTTON))
			{
				gInterface.Data[eTIME].EventTick = GetTickCount();
				pCallbackFunc(this);
				return;
			}
		}
		return;
	}
	else {
		RenderBitmap(IMGcode, x, y, uw, uh, 0.0, 0.0, w / a6, h / a7, 1, 1, 0.0);
	}
	return;
}
void cGuildUpgrade::DrawButton(int IMGcode, float x, float y, float w, float h, float uw, float uh, float a8, float a9, PUSHEVENT_CALLBACK_LPVOID pCallbackFunc, bool a11) {
	if (gInterface.IsWorkZone1(x, y, w, h))
	{
		if (GetTickCount() - gInterface.Data[eTIME].EventTick > 300) //Click
		{
			RenderBitmap(IMGcode, x, y, w, h, 0.0, uh / a9, uw / a8, uh / a9, 1, 1, 0.0);
			if (pIsKeyPress(VK_LBUTTON) || (a11 && GetKeyState(VK_LBUTTON) & 0x8000))
			{
				gInterface.Data[eTIME].EventTick = GetTickCount();
				pCallbackFunc(this);
				return;
			}
		}
		return;
	}
	else {
		RenderBitmap(IMGcode, x, y, w, h, 0.0, 0.0, uw / a8, uh / a9, 1, 1, 0.0);
	}
	return;
}
bool cGuildUpgrade::Draw()
{
	if (!this->Drawing) {
		return false;
	}
	//==========
	glAlphaFunc(GL_GREATER, 0.0f);

	CustomFont.Draw(CustomFont.FontBold, x, y, 0x0, 0x171717ff, w, h, 1, " ");

	int i = 0;
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

	glAlphaFunc(GL_GREATER, 0.25f);
	gInterface.DrawFormat(-1, x, y + 12, w, 3, "Nâng Cấp Guild");

	GuildUpgrade.DrawButton(32331, x + 14, y + 31.5, 73, 27, 128.0, 128.0, GuildUpgrade.TabInfoAction);
	GuildUpgrade.DrawButton(32331, x + 14 + 75, y + 31.5, 73, 27, 128.0, 128.0, GuildUpgrade.TabRankingAction);
	GuildUpgrade.DrawButton(32331, x + 14 + 75 * 2, y + 31.5, 73, 27, 128.0, 128.0, GuildUpgrade.TabMyGuildAction);
	GuildUpgrade.DrawButton(32331, x + 14 + 75 * 3, y + 31.5, 73, 27, 128.0, 128.0, GuildUpgrade.TabDevoteAction);
	GuildUpgrade.DrawButton(32331, x + 14 + 75 * 4, y + 31.5, 73, 27, 128.0, 128.0, GuildUpgrade.TabShopAction);

	gInterface.DrawFormat(-1, x + 14, y + 40, 73, 3, "Giới Thiệu");
	gInterface.DrawFormat(-1, x + 14 + 75 * 1, y + 40, 73, 3, "Xếp Hạng");
	gInterface.DrawFormat(-1, x + 14 + 75 * 2, y + 40, 73, 3, "Guild Của Bạn");
	gInterface.DrawFormat(-1, x + 14 + 75 * 3, y + 40, 73, 3, "Cống Hiến");
	gInterface.DrawFormat(-1, x + 14 + 75 * 4, y + 40, 73, 3, "Shop Guild");

	pSetCursorFocus = true;

	switch (this->CurTab)
	{
	case GuildUpgradeTabs::ggRanking:	this->DrawRankingInfo();		break;
	case GuildUpgradeTabs::ggMyGuild:	this->DrawMyGuildInfo();		break;
	case GuildUpgradeTabs::ggDevote:	this->DrawDevoteInfo();			break;
	case GuildUpgradeTabs::ggShop:		this->DrawShopInfo();			break;
	case GuildUpgradeTabs::ggInfo:	default:this->DrawTabInfo();		break;
	}

	if (pIsKeyPress(VK_LBUTTON) && gInterface.IsWorkZone1(x + w - 25, y + 5, 20, 18))
	{
		this->Drawing = false;
	}
	return gInterface.IsWorkZone1(x, y, w, h);
}
void cGuildUpgrade::DrawTabInfo()
{
	CustomFont.Draw(CustomFont.FontBold, x + 25, y + 70, 0xffff00ff, 0x0, w - 50, 20, 3, "XÂY DỰNG BANG HỘI - Xây Dựng Một Cộng Đồng Guild Phát Triển");

	CustomFont.Draw(CustomFont.FontNormal, x + 25, y + 90, 0xffffffff, 0x0, w - 50, 15, 1, "- Điều Kiện: Ở trong 1 guild.");

	CustomFont.Draw(CustomFont.FontNormal, x + 25, y + 100, 0xffffffff, 0x0, w - 50, 15, 1, "- Thể Lệ Tham Gia:");

	CustomFont.Draw(CustomFont.FontNormal, x + 25, y + 110, 0xffffffff, 0x0, w - 50, 15, 1, "- Khi Săn Boss , Tham gia event , sự kiện  , bạn sẽ nhận được điểm cống hiến,");

	CustomFont.Draw(CustomFont.FontNormal, x + 25, y + 120, 0xffffffff, 0x0, w - 50, 15, 1, "và tìm kiếm các item cần thiết để đóng góp điểm.");

	CustomFont.Draw(CustomFont.FontNormal, x + 25, y + 130, 0xffffffff, 0x0, w - 50, 15, 1, "- Các Guild có điểm xây dựng cao sẽ hưởng các quyền lợi riêng");

	CustomFont.Draw(CustomFont.FontNormal, x + 25, y + 140, 0xffffffff, 0x0, w - 50, 15, 1, "- Ngoài ra điểm còn để mua các vật phẩm trong shop guild,");

	CustomFont.Draw(CustomFont.FontNormal, x + 25, y + 150, 0xffffffff, 0x0, w - 50, 15, 1, "- Shop item thay đổi thay cấp độ guild , rất nhiều item giá trị đang chờ bạn.");

	CustomFont.Draw(CustomFont.FontNormal, x + 25, y + 160, 0xffffffff, 0x0, w - 50, 15, 1, "-Tiêu Diệt Các loại boss để nhận số điểm khác nhau");

	CustomFont.Draw(CustomFont.FontNormal, x + 25, y + 170, 0xffffffff, 0x0, w - 50, 15, 1, "-Tham gia BC DV CC để gia tăng điểm cống hiến");

	CustomFont.Draw(CustomFont.FontNormal, x + 25, y + 180, 0xffffffff, 0x0, w - 50, 15, 1, "-Mọi vấn đề xin vui lòng liên hệ ADMIN để được giải quyết");

	CustomFont.Draw(CustomFont.FontNormal, x + 25, y + 190, 0xffffffff, 0x0, w - 50, 15, 1, "-Chúc các bạn chơi game vui vẻ !");
}
void cGuildUpgrade::DrawRankingInfo()
{
	int i, j;
	char* text[5] = { "#", "Guild", "Chủ Hội", "Điểm Cống Hiến", "Cấp độ Guild" };
	for (i = 0; i < 5; i++)
		CustomFont.Draw(CustomFont.FontNormal, x + 30 + 70 * i, y + 70, 0xffffffff, 0xff222299, 60, 0, 3, text[i]);

	if (this->LoadedGuildRanking == false) {
		char buf[25];
		int step = GetTickCount() / 1000 % 4;
		sprintf(buf, "Loading data%%.%ds", step);
		CustomFont.Draw(CustomFont.FontNormal, x + 30, y + 125, 0xffffffff, 0x0, w - 60, 0, 3, buf, "...");
	}
	else
	{
		int m = GU_ROW_PER_PAGE;
		if (this->CurPage == this->TotalPages) {
			m = this->GuildRankingInfo.count % GU_ROW_PER_PAGE;
		}

		for (i = 0; i < m; i++)
		{
			CustomFont.Draw(CustomFont.FontNormal, x + 30 + 70 * 0, y + 85 + 15 * i, 0xffffffff, 0x0, 60, 0, 3, "%d", i + 1 + (this->CurPage - 1) * GU_ROW_PER_PAGE);
			CustomFont.Draw(CustomFont.FontNormal, x + 30 + 70 * 1, y + 85 + 15 * i, 0xffffffff, 0x0, 60, 0, 3, this->GuildRankingInfo.Guild[i + (this->CurPage - 1) * GU_ROW_PER_PAGE].Name);
			CustomFont.Draw(CustomFont.FontNormal, x + 30 + 70 * 2, y + 85 + 15 * i, 0xffffffff, 0x0, 60, 0, 3, this->GuildRankingInfo.Guild[i + (this->CurPage - 1) * GU_ROW_PER_PAGE].Master);
			CustomFont.Draw(CustomFont.FontNormal, x + 30 + 70 * 3, y + 85 + 15 * i, 0xffffffff, 0x0, 60, 0, 3, "%d", this->GuildRankingInfo.Guild[i + (this->CurPage - 1) * GU_ROW_PER_PAGE].Devote);
			CustomFont.Draw(CustomFont.FontNormal, x + 30 + 70 * 4, y + 85 + 15 * i, 0xffffffff, 0x0, 60, 0, 3, "%d", this->GuildRankingInfo.Guild[i + (this->CurPage - 1) * GU_ROW_PER_PAGE].Level);
		}


		RenderBitmap(32344, x + 135 + 50, y + h - 25, 50.f, 18.f, 0, 0, 80.f / 128.f, 30.f / 34.f, 1, 1, 0.0);

		CustomFont.Draw(CustomFont.FontBold, x + 135 + 50, y + h - 20, 0xffffffff, 0x0, 50, 0, 3, "%d / %d", this->CurPage, this->TotalPages);

		GuildUpgrade.DrawButton(32345, x + 120 + 50, y + h - 24, 20, 22, 32.f, 128.f, GuildUpgrade.PagePrevAction, 15, 16);
		GuildUpgrade.DrawButton(32346, x + 185 + 50, y + h - 24, 20, 22, 32.f, 128.f, GuildUpgrade.PageNextAction, 15, 16);
	}
}
void cGuildUpgrade::DrawMyGuildInfo()
{
	int i, j;
	char* text[5] = { "#", "Nhân Vật", "Chức Vụ", "Cống Hiến", "Phần Thưởng Guild" };
	for (i = 0; i < 4; i++)
		CustomFont.Draw(CustomFont.FontNormal, x + 30 + 60 * i, y + 70, 0xffffffff, 0xff222299, 50, 0, 3, text[i]);

	CustomFont.Draw(CustomFont.FontNormal, x + 30 + 60 * 4, y + 70, 0xffffffff, 0xff222299, 110, 0, 3, text[4]);

	if (this->LoadedMyGuild == false) {
		char buf[25];
		int step = GetTickCount() / 1000 % 4;
		sprintf(buf, "Loading data%%.%ds", step);
		CustomFont.Draw(CustomFont.FontNormal, x + 30, y + 125, 0xffffffff, 0x0, w - 60, 0, 3, buf, "...");
	}
	else {
		int m = GU_ROW_PER_PAGE;
		if (this->CurPage == this->TotalPages) {
			m = this->myGuildMemberInfo.count % GU_ROW_PER_PAGE;
		}
		for (i = 0; i < m; i++)
		{
			CustomFont.Draw(CustomFont.FontNormal, x + 30 + 60 * 0, y + 85 + 15 * i, 0xffffffff, 0x0, 50, 0, 3, "%d", i + 1 + (this->CurPage - 1) * GU_ROW_PER_PAGE);
			CustomFont.Draw(CustomFont.FontNormal, x + 30 + 60 * 1, y + 85 + 15 * i, 0xffffffff, 0x0, 50, 0, 3, this->myGuildMemberInfo.Mem[i + (this->CurPage - 1) * GU_ROW_PER_PAGE].name);
			CustomFont.Draw(CustomFont.FontNormal, x + 30 + 60 * 2, y + 85 + 15 * i, 0xffffffff, 0x0, 50, 0, 3, GetStatus(this->myGuildMemberInfo.Mem[i + (this->CurPage - 1) * GU_ROW_PER_PAGE].status));
			CustomFont.Draw(CustomFont.FontNormal, x + 30 + 60 * 3, y + 85 + 15 * i, 0xffffffff, 0x0, 50, 0, 3, "%s", gInterface.NumberFormat(this->myGuildMemberInfo.Mem[i + (this->CurPage - 1) * GU_ROW_PER_PAGE].devote));
		}
		RenderBitmap(32344, x + 135 + 50, y + h - 25, 50.f, 18.f, 0, 0, 80.f / 128.f, 30.f / 34.f, 1, 1, 0.0);
		CustomFont.Draw(CustomFont.FontBold, x + 135 + 50, y + h - 20, 0xffffffff, 0x0, 50, 0, 3, "%d / %d", this->CurPage, this->TotalPages);
		GuildUpgrade.DrawButton(32345, x + 120 + 50, y + h - 24, 20, 22, 32.f, 128.f, GuildUpgrade.PagePrevAction, 15, 16);
		GuildUpgrade.DrawButton(32346, x + 185 + 50, y + h - 24, 20, 22, 32.f, 128.f, GuildUpgrade.PageNextAction, 15, 16);
		CustomFont.Draw(CustomFont.FontNormal, x + 30 + 60 * 4, y + 85, 0xffffffff, 0x0, 110, 0, 3, "Cấp Độ: %d", this->myGuildMemberInfo.Level);
		CustomFont.Draw(CustomFont.FontNormal, x + 30 + 60 * 4, y + 100, 0xffffffff, 0x22ff2220, 110, 0, 3, "%d/%d", this->myGuildMemberInfo.TotalDevote, this->myGuildMemberInfo.NextDevote);
	}
}
void cGuildUpgrade::DrawDevoteInfo()
{
	int i, j;
	CustomFont.Draw(CustomFont.FontNormal, x + 20, y + 70, 0xffffffff, 0xff222299, 110, 0, 3, "Vật Phẩm");

	CustomFont.Draw(CustomFont.FontNormal, x + 140, y + 70, 0xffffffff, 0xff222299, 60, 0, 3, "Điểm Cống Hiến");


	if (this->LoadedDevoteItems == false) {
		char buf[25];
		int step = GetTickCount() / 1000 % 4;
		sprintf(buf, "Loading data%%.%ds", step);
		CustomFont.Draw(CustomFont.FontNormal, x + 30, y + 125, 0xffffffff, 0x0, w - 60, 0, 6, buf, "...");
	}
	else {
		int m = GU_ROW_PER_PAGE;
		if (this->CurPage == this->TotalPages) {
			m = this->DevoteItems.size() % GU_ROW_PER_PAGE;
		}
		int Hoving = -1;
		DWORD Clr;
		for (i = 0; i < m; i++)
		{
			if (i + (this->CurPage - 1) * GU_ROW_PER_PAGE == this->CurDevoteItemHighLight) {
				Clr = 0xffff22ff;
			}
			else {
				Clr = 0xffffffff;
			}
			CustomFont.Draw(CustomFont.FontNormal, x + 20, y + 85 + 15 * i, Clr, 0x0, 110, 0, 1, (char*)*(DWORD*)0x8128AC0 + 84 * *(WORD *)(DWORD)&this->DevoteItems[i + (this->CurPage - 1) * GU_ROW_PER_PAGE].Item);
			CustomFont.Draw(CustomFont.FontNormal, x + 140, y + 85 + 15 * i, Clr, 0x0, 50, 0, 3, "%s", gInterface.NumberFormat(this->DevoteItems[i + (this->CurPage - 1) * GU_ROW_PER_PAGE].Devote));
			if (gInterface.IsWorkZone1(x + 20, y + 85 + 15 * i, 110, 15))
			{
				Hoving = i + (this->CurPage - 1) * GU_ROW_PER_PAGE;
			}
		}

		RenderBitmap(32344, x + 135 - 50, y + h - 25, 50.f, 18.f, 0, 0, 80.f / 128.f, 30.f / 34.f, 1, 1, 0.0);
		CustomFont.Draw(CustomFont.FontBold, x + 135 - 50, y + h - 20, 0xffffffff, 0x0, 50, 0, 3, "%d / %d", this->CurPage, this->TotalPages);
		GuildUpgrade.DrawButton(32345, x + 120 - 50, y + h - 24, 20, 22, 32.f, 128.f, GuildUpgrade.PagePrevAction, 15, 16);
		GuildUpgrade.DrawButton(32346, x + 185 - 50, y + h - 24, 20, 22, 32.f, 128.f, GuildUpgrade.PageNextAction, 15, 16);

		for (i = 0; i < 184; i++) {
			pDrawGUI(31346, x + 205, y + 60 + 2 + i, 14.0, 1.0);
		}

		CustomFont.Draw(CustomFont.FontNormal, x + 240, y + 75, 0xffffffff, 0xff222299, 120, 0, 3, "Đặt vật phẩm cống hiến tại đây");

		bool onZone = gInterface.IsWorkZone1(x + 260, y + 95, 75.f, 75.f);

		if (this->CurDevoteItem.ItemID != -1){
			if (onZone && ((int(*)()) 0x007DD0F0)()) {
				CustomFont.Draw(CustomFont.FontNormal, x + 262, y + 97, 0x0, 0xa1252590, 70.f, 70.f, 1, " ");
			}
		}
		else if (onZone && ((int(*)()) 0x007DD0F0)()) {
			CustomFont.Draw(CustomFont.FontNormal, x + 262, y + 97, 0x0, 0x255ba190, 70.f, 70.f, 1, " ");
		}
		RenderBitmap(31749, x + 260, y + 95, 75.f, 75.f, 0, 0, 173.0 / 256.f, 87.0 / 128.f, 1, 1, 0.0);

		if (this->CurDevoteItem.ItemID != -1)
			CustomFont.Draw(CustomFont.FontBold, x + 208, y + 170, this->CurDevotePrice ? 0xffff22ff : 0xff2222ff, 0x0, 180, 0, 6, (char*)*(DWORD*)0x8128AC0 + 84 * this->CurDevoteItem.ItemID);

		CustomFont.Draw(CustomFont.FontNormal, x + 208, y + 185, 0xffffffff, 0x0, 180, 0, 3, "Điểm Cống Hiến: %s", gInterface.NumberFormat(this->CurDevotePrice));


		GuildUpgrade.DrawButton(32331, x + 272.5, y + 200, 73, 27, 128.0, 128.0, GuildUpgrade.DevoteAction, 50, 23);

		CustomFont.Draw(CustomFont.FontNormal, x + 208, y + 222.5 - 15, 0xffffffff, 0x0, 180, 0, 3, "Cống Hiến");

		RenderBitmap(31395, x + w - 118, y + h - 24, 100.f, 16.f, 0, 0, 170.f / 256.f, 21.f / 32.f, 1, 1, 0.0);
		CustomFont.Draw(CustomFont.FontNormal, x + w - 115, y + h - 21, 0xffffffff, 0x0, 40, 0, 3, "Cống Hiến");
		CustomFont.Draw(CustomFont.FontNormal, x + w - 70, y + h - 21, 0xffffffff, 0x0, 0, 0, 1, "%s", gInterface.NumberFormat(this->MeDevote));

		if (Hoving != -1) {
			ObjectItem* tItem = &this->DevoteItems[Hoving].Item;

			gPostInterface.DrawItemToolTipText((void*)&this->DevoteItems[Hoving].Item, pCursorX + 25, pCursorY);

			GuildUpgrade.DrawItem3D(pCursorX + 15, pCursorY - 5, 75.f, 75.f,
				tItem->ItemID, tItem->Level, tItem->ExcellentOption, tItem->AncientOption, 0);
			EnableAlphaTest(true);
			glColor4f(1.f, 1.f, 1.f, 1.f);
		}

		if (this->CurDevoteItem.ItemID != -1){
			GuildUpgrade.DrawItem3D(x + 260, y + 95, 75.f, 75.f,
				this->CurDevoteItem.ItemID, this->CurDevoteItem.Level, this->CurDevoteItem.ExcellentOption, this->CurDevoteItem.AncientOption, 0);
			if (onZone) {
				gPostInterface.DrawItemToolTipText((void*)&this->CurDevoteItem, pCursorX + 25, pCursorY);
				EnableAlphaTest(true);
				glColor4f(1.f, 1.f, 1.f, 1.f);
				if (pIsKeyPress(VK_LBUTTON))
				{
					if (this->PickedItemState == false){
						this->PickedItemState = true;
					}
					else {
						DWORD v34 = ((DWORD(*)()) 0x599F10)();
						if (v34 == 0xFFFFFFFF)
						{
							((bool(__cdecl*)(DWORD, DWORD))0x007DD100)(this->CurDevoteItemOwner, (DWORD)&this->CurDevoteItem);
							//remove item
							this->CurDevoteItem.ItemID = -1;
							this->CurDevotePrice = 0;
							this->CurDevoteItemHighLight = -1;
						}
					}
				}
			}
		}

	}
}
void cGuildUpgrade::DrawShopInfo()
{
	int i;
	CustomFont.Draw(CustomFont.FontNormal, x + 20, y + 70, 0xffffffff, 0xff222299, 15, 0, 3, "#");
	CustomFont.Draw(CustomFont.FontNormal, x + 85, y + 70, 0xffffffff, 0xff222299, 50, 0, 3, "Vật Phẩm");
	CustomFont.Draw(CustomFont.FontNormal, x + 190, y + 70, 0xffffffff, 0xff222299, 35, 0, 3, "Cấp Guild");
	CustomFont.Draw(CustomFont.FontNormal, x + 270, y + 70, 0xffffffff, 0xff222299, 70, 0, 3, "Điểm Cống Hiến");
	//CustomFont.Draw(CustomFont.FontNormal, x + 230, y + 70, 0xffffffff, 0xff222299, 50, 0, 6, "Gcent");
	//CustomFont.Draw(CustomFont.FontNormal, x + 290, y + 70, 0xffffffff, 0xff222299, 50, 0, 6, "Zen");

	if (this->LoadedShopItems == false) {
		char buf[25];
		int step = GetTickCount() / 1000 % 4;
		sprintf(buf, "Loading data%%.%ds", step);
		CustomFont.Draw(CustomFont.FontNormal, x + 30, y + 125, 0xffffffff, 0x0, w - 60, 0, 6, buf, "...");
	}
	else {
		int m = GU_ROW_PER_PAGE;
		if (this->CurPage == this->TotalPages) {
			m = this->ShopItems.size() % GU_ROW_PER_PAGE;
		}
		int Hoving = -1;
		for (i = 0; i < m; i++)
		{
			CustomFont.Draw(CustomFont.FontNormal, x + 20, y + 85 + 15 * i, 0xffffffff, 0x0, 15, 0, 3, "%d", i + 1 + (this->CurPage - 1) * GU_ROW_PER_PAGE);
			CustomFont.Draw(CustomFont.FontNormal, x + 35, y + 85 + 15 * i, 0xffffffff, 0x0, 150, 0, 3, (char*)*(DWORD*)0x8128AC0 + 84 * *(WORD *)(DWORD)&this->ShopItems[i + (this->CurPage - 1) * GU_ROW_PER_PAGE].Item);
			CustomFont.Draw(CustomFont.FontNormal, x + 175, y + 85 + 15 * i, 0xffffffff, 0x0, 70, 0, 3, "%d", this->ShopItems[i + (this->CurPage - 1) * GU_ROW_PER_PAGE].GuildLevel);
			CustomFont.Draw(CustomFont.FontNormal, x + 270, y + 85 + 15 * i, 0xffffffff, 0x0, 70, 0, 3, "%s", gInterface.NumberFormat(this->ShopItems[i + (this->CurPage - 1) * GU_ROW_PER_PAGE].Devote));
			//CustomFont.Draw(CustomFont.FontNormal, x + 230, y + 85 + 15 * i, 0xffffffff, 0x0, 50, 0, 6, "0");
			//CustomFont.Draw(CustomFont.FontNormal, x + 290, y + 85 + 15 * i, 0xffffffff, 0x0, 50, 0, 6, "%s", nInterface.NumberFormat(this->ShopItems[i + (this->CurPage - 1) * GU_ROW_PER_PAGE].Zen));

			if (this->MeGuildLevel >= this->ShopItems[i + (this->CurPage - 1) * GU_ROW_PER_PAGE].GuildLevel &&
				this->MeDevote >= this->ShopItems[i + (this->CurPage - 1) * GU_ROW_PER_PAGE].Devote) {
				if (gInterface.IsWorkZone1(x + 350, y + 80 + 15 * i, 30, 16))
				{
					GuildUpgrade.SetCurItemShop(i + GU_ROW_PER_PAGE * (this->CurPage - 1));
				}
				GuildUpgrade.DrawButton(32340, x + 350, y + 80 + 15 * i, 52, 26, 64.f, 128.f, GuildUpgrade.ShopBuyAction, 30, 15);
				CustomFont.Draw(CustomFont.FontNormal, x + 350, y + 83 + 15 * i, 0xffffffff, 0x0, 30, 0, 3, "Mua");
			}
			if (gInterface.IsWorkZone1(x + 45, y + 85 + 15 * i, 70, 15))
			{
				Hoving = i + (this->CurPage - 1) * GU_ROW_PER_PAGE;
			}
		}

		if (Hoving != -1) {
			gPostInterface.DrawItemToolTipText((void*)&this->ShopItems[Hoving].Item, pCursorX + 25, pCursorY);
			EnableAlphaTest(true);
			glColor4f(1.f, 1.f, 1.f, 1.f);
		}

		RenderBitmap(32344, x + 135 + 50, y + h - 25, 50.f, 18.f, 0, 0, 80.f / 128.f, 30.f / 34.f, 1, 1, 0.0);
		CustomFont.Draw(CustomFont.FontBold, x + 135 + 50, y + h - 20, 0xffffffff, 0x0, 50, 0, 3, "%d / %d", this->CurPage, this->TotalPages);
		GuildUpgrade.DrawButton(32345, x + 120 + 50, y + h - 24, 20, 22, 32.f, 128.f, GuildUpgrade.PagePrevAction, 15, 16);
		GuildUpgrade.DrawButton(32346, x + 185 + 50, y + h - 24, 20, 22, 32.f, 128.f, GuildUpgrade.PageNextAction, 15, 16);
	}
	RenderBitmap(31395, x + w - 118, y + h - 24, 100.f, 16.f, 0, 0, 170.f / 256.f, 21.f / 32.f, 1, 1, 0.0);
	CustomFont.Draw(CustomFont.FontNormal, x + w - 115, y + h - 21, 0xffffffff, 0x0, 40, 0, 3, "Cống Hiến");
	CustomFont.Draw(CustomFont.FontNormal, x + w - 70, y + h - 21, 0xffffffff, 0x0, 0, 0, 1, "%s", gInterface.NumberFormat(this->MeDevote));
}
bool cGuildUpgrade::CheckRect()
{
	if (!this->Drawing || this->CurTab != GuildUpgradeTabs::ggDevote) {
		return false;
	}
	if (gInterface.IsWorkZone1(x + 260, y + 95, 75.f, 75.f) && ((int(*)()) 0x007DD0F0)()) {
		if (this->CurDevoteItem.ItemID != -1) {
			this->PickedItemState = false;
			((void(*)()) 0x007DD230)();
		}
		else {
			int pOwner = ((DWORD(__thiscall*)(int)) 0x007D9410)(((int(*)()) 0x007DD0F0)());
			ObjectItem item = *(ObjectItem*)((int(__thiscall*)(int)) 0x007D9430)(((int(*)()) 0x007DD0F0)());
			this->SetDevoteItem(item);
			this->CurDevoteItemOwner = pOwner;
			this->PickedItemState = false;
			((void(*)()) 0x007DD1B0)();
			this->CurDevotePrice = 0;
			this->CurDevoteItemHighLight = -1;
			for (int i = 0; i < this->DevoteItems.size(); i++) {
				if (item.ItemID == this->DevoteItems[i].Item.ItemID &&
					item.Level == this->DevoteItems[i].Item.Level) {
					this->CurDevotePrice = this->DevoteItems[i].Devote;
					this->CurDevoteItemHighLight = i;
					this->SetCurPage(1 + floor((float)this->CurDevoteItemHighLight / (float)GU_ROW_PER_PAGE));
					break;
				}
			}
		}

	}
	return gInterface.IsWorkZone1(x, y, w, h);
}
void cGuildUpgrade::DrawItem3D(float sx, float sy, float Width, float Height, int Type, int Level, int ExtOption, int Ancient, bool PickUp, float Scale, bool Center)
{
	glMatrixMode(0x1701);
	glPushMatrix();
	glLoadIdentity();
	sub_6363D0_Addr(0, 0, *(GLsizei*)0x00E61E58, *(GLsizei*)0x00E61E5C);
	float v2 = *(float*)0x00E61E58 / *(float*)0x00E61E5C;
	sub_6358A0_Addr(Scale, v2, *(float*)0xE61E38, *(float*)0xE61E3C);
	glMatrixMode(0x1700);
	glPushMatrix();
	glLoadIdentity();
	sub_635830_Addr((LPVOID)0x87933A0);
	sub_635DE0_Addr();
	sub_635E40_Addr();
	GuildUpgrade.DrawItem3DCenterImage = Center;
	pDrawItemModel(sx, sy, Width, Height, Type, Level, ExtOption, Ancient, PickUp);
	GuildUpgrade.DrawItem3DCenterImage = false;
	testfunc();
	glColor3f(1, 1, 1);
	pSetBlend(false);
	return;
}
void cGuildUpgrade::SendRequest(BYTE type, int value)
{
	PMSG_GUILD_UPGRADE_REQUEST_SEND pRequest;
	pRequest.h.set(0xF8, 0x4C, sizeof(pRequest));
	pRequest.type = type;
	pRequest.value = value;
	DataSend((LPBYTE)&pRequest, pRequest.h.size);
}
void cGuildUpgrade::RecvMyGuildInfo(BYTE* lpMsg)
{
	PSWMSG_GUILD_UPGRADE_MY_GUILD_RECV* Data = (PSWMSG_GUILD_UPGRADE_MY_GUILD_RECV*)lpMsg;
	if (Data->count > 0) {
		this->myGuildMemberInfo.count = Data->count;
		this->myGuildMemberInfo.Level = Data->Level;
		this->myGuildMemberInfo.NextDevote = Data->NextDevote;
		this->myGuildMemberInfo.TotalDevote = Data->TotalDevote;

		int Offset = sizeof(PSWMSG_GUILD_UPGRADE_MY_GUILD_RECV);

		for (int i = 0; i < Data->count; i++) {

			GUMyGuildMember* Data2 = (GUMyGuildMember*)(lpMsg + Offset);

			this->myGuildMemberInfo.Mem[i].devote = Data2->devote;
			this->myGuildMemberInfo.Mem[i].status = Data2->status;
			memcpy(this->myGuildMemberInfo.Mem[i].name, Data2->name, sizeof(Data2->name));
			Offset += sizeof(GUMyGuildMember);
		}
		this->LoadedMyGuild = true;
		this->SetTotalPages(1 + floor((float)Data->count / (float)GU_ROW_PER_PAGE));
		this->SetCurPage(1);
	}
}
void cGuildUpgrade::RecvGuildRankingInfo(BYTE* lpMsg)
{
	PSWMSG_GUILD_UPGRADE_COUNT_RECV* Data = (PSWMSG_GUILD_UPGRADE_COUNT_RECV*)lpMsg;
	if (Data->count > 0) {
		int Offset = sizeof(PSWMSG_GUILD_UPGRADE_COUNT_RECV);
		for (int i = 0; i < Data->count; i++) {
			GUGuildInfo* Data2 = (GUGuildInfo*)(lpMsg + Offset);
			this->GuildRankingInfo.Guild[i].Devote = Data2->Devote;
			this->GuildRankingInfo.Guild[i].Level = Data2->Level;
			memcpy(this->GuildRankingInfo.Guild[i].Name, Data2->Name, sizeof(Data2->Name));
			memcpy(this->GuildRankingInfo.Guild[i].Master, Data2->Master, sizeof(Data2->Master));

			Offset += sizeof(GUGuildInfo);
		}

		this->GuildRankingInfo.count = Data->count;
		this->LoadedGuildRanking = true;
		this->SetTotalPages(1 + floor((float)Data->count / (float)GU_ROW_PER_PAGE));
		this->SetCurPage(1);
	}
}
void cGuildUpgrade::RecvDevoteItemInfo(BYTE* lpMsg)
{
	this->DevoteItems.clear();
	PSWMSG_GUILD_UPGRADE_COUNT_RECV* Data = (PSWMSG_GUILD_UPGRADE_COUNT_RECV*)lpMsg;
	if (Data->count > 0) {
		int Offset = sizeof(PSWMSG_GUILD_UPGRADE_COUNT_RECV);
		for (int i = 0; i < Data->count; i++) {
			GG_DEVOTE_ITEM* Data2 = (GG_DEVOTE_ITEM*)(lpMsg + Offset);

			GG_DEVOTE_ITEMS Info = {};

			Info.Devote = Data2->Devote;

			DWORD dwAddress = (DWORD)&	Info.Item;
			*(WORD *)dwAddress = Data2->Item;
			pSetItemOption(&Info.Item, Data2->Level * 8, 0, 0);
			this->DevoteItems.push_back(Info);

			Offset += sizeof(GG_DEVOTE_ITEM);
		}

		this->LoadedDevoteItems = true;
		this->SetTotalPages(1 + floor((float)this->DevoteItems.size() / (float)GU_ROW_PER_PAGE));
		this->SetCurPage(1);
	}
}
void cGuildUpgrade::RecvShopItemInfo(BYTE* lpMsg)
{
	this->ShopItems.clear();

	PSWMSG_GUILD_UPGRADE_COUNT_RECV* Data = (PSWMSG_GUILD_UPGRADE_COUNT_RECV*)lpMsg;
	if (Data->count > 0) {
		int Offset = sizeof(PSWMSG_GUILD_UPGRADE_COUNT_RECV);
		for (int i = 0; i < Data->count; i++) {
			GG_SHOP_ITEM* Data2 = (GG_SHOP_ITEM*)(lpMsg + Offset);

			GG_SHOP_ITEMS Info = {};

			Info.Devote = Data2->Devote;
			Info.GuildLevel = Data2->GuildLevel;
			Info.Zen = Data2->Zen;

			DWORD dwAddress = (DWORD)&	Info.Item;
			*(WORD *)dwAddress = Data2->Item;
			pSetItemOption(&Info.Item, Data2->Level * 8, 0, 0);
			this->ShopItems.push_back(Info);

			Offset += sizeof(GG_SHOP_ITEM);
		}

		this->LoadedShopItems = true;
		this->SetTotalPages(1 + floor((float)this->ShopItems.size() / (float)GU_ROW_PER_PAGE));
		this->SetCurPage(1);
	}
}
void cGuildUpgrade::RecvMeInfo(BYTE* lpMsg)
{
	PSWMSG_GUILD_UPGRADE_ME_RECV* Data = (PSWMSG_GUILD_UPGRADE_ME_RECV*)lpMsg;
	this->MeDevote = Data->Devote;
	this->MeGuildLevel = Data->GuildLevel;
}
void cGuildUpgrade::RecvDevoteResult(BYTE* lpMsg)
{
	PSWMSG_GUILD_UPGRADE_COUNT_RECV* Data = (PSWMSG_GUILD_UPGRADE_COUNT_RECV*)lpMsg;
	switch (Data->count)
	{
	case 1://done
		this->CurDevoteItem.ItemID = -1;
		this->CurDevotePrice = 0;
		this->CurDevoteItemHighLight = -1;
		this->LoadedMyGuild = false;
		this->LoadedGuildRanking = false;
		break;
	default:
		break;
	}
}
#endif
