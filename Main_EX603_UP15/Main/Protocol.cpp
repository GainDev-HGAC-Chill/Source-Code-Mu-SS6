#include "stdafx.h"
#include "Protocol.h"
#include "Common.h"
#include "CustomEventTime.h"
#include "CustomRankUser.h"
#include "CustomRanking.h"
#include "HealthBar.h"
#include "Interface.h"
#include "ItemShopValue.h"
#include "Offset.h"
#include "OffTrade.h"
#include "PacketManager.h"
#include "PrintPlayer.h"
#include "Protect.h"
#include "Reconnect.h"
#include "Util.h"
#include "post_item.h"
#include "postInterface.h"
#include "PetProtocol.h"
#include "StatsAdvance.h"
#include "User.h"
#include "PartyBuffs.h"
#include "BuffIcon.h"
#include "Ruud.h"
#include "MiniMapInfo.h"
#include "Central.h"
#include "InterEx.h"
#include "NPCRuud.h"
#include "PartyBar.h"
#include "DanhHieu.h"
#include "QuanHam.h"
#include "TuLuyen.h"
#include "PartySearchSettings.h"
#include "PartySearch.h"
#include "HWID.h"
#include "QuickCommandWindow.h"
#include "HuyHieuCuongHoa.h"

#include "LoginMainWin.h"
#include "ThueFlag.h"
#include "CustomOfflineMode.h"
#include "RoyalBattleGround.h"
#include "ResetSystem.h"
#if(ANTIHACK_NEW)
#include "BAntihack.h"
#endif
#include "GuildUpgrade.h"
#include "NewUIMyInventory.h"
#include "SauCustomHarmony.h"
#if(THONG_TIN_BOSS)
#include "ActiveInvasions.h"
#endif
#if(VONGQUAY_NEW)
VONGQUAYINFO_CLIENT mDataVongQuayClient;
VONGQUAY_CLIENT mDataListItemVongQuayClient;
#endif
#if(B_MOCNAP)
CBINFOMOCNAP_CLIENT mDataMocNapClient;
CBLISTPHANTHUONGMOCNAP_CLIENT mDataListItemMocNapClient;
#endif

#if(DANH_HIEU_NEW == 1)
struct DANHHIEU_UPDATE
{
	PBMSG_HEAD2 h;
	int DANH_HIEU_WCOINC;
	int DANH_HIEU;
};

void DanhHieuRecv(DANHHIEU_UPDATE * aRecv)
{
	gObjUser.DANH_HIEU_WCOINC = aRecv->DANH_HIEU_WCOINC;
	gObjUser.DANH_HIEU = aRecv->DANH_HIEU;
}
#endif


#if(QUAN_HAM_NEW == 1)
struct QUANHAM_UPDATE
{
	PBMSG_HEAD2 h;
	int QUAN_HAM_WCOINC;
	int QUAN_HAM;
};

void QuanHamRecv(QUANHAM_UPDATE * aRecv)
{
	gObjUser.QUAN_HAM_WCOINC = aRecv->QUAN_HAM_WCOINC;
	gObjUser.QUAN_HAM = aRecv->QUAN_HAM;
}
#endif



#if(TU_LUYEN_NEW == 1)
struct TULUYEN_UPDATE
{
	PBMSG_HEAD2 h;
	int TU_LUYEN_WCOINC;
	//4-04-2022
	int TU_LUYEN;
};

void TuLuyenRecv(TULUYEN_UPDATE * aRecv)
{

	gObjUser.TU_LUYEN_WCOINC = aRecv->TU_LUYEN_WCOINC;
	gObjUser.TU_LUYEN = aRecv->TU_LUYEN;

}




#endif

#if(PKEVENT == 1) // OK
struct PKEVENT_UPDATE
{
	PBMSG_HEAD2 h;
	int SurvivorKill;
	int SurvivorDie;
	int SurvivorTotal;
};

void PKEventRecv(PKEVENT_UPDATE * aRecv)
{
	gObjUser.SurvivorKill = aRecv->SurvivorKill;
	gObjUser.SurvivorDie = aRecv->SurvivorDie;
	gObjUser.SurvivorTotal = aRecv->SurvivorTotal;
}
#endif





BOOL ProtocolCoreEx(BYTE head,BYTE* lpMsg,int size,int key) // OK
{
	switch(head)
	{

		case 0x11:
			GCDamageRecv((PMSG_DAMAGE_RECV*)lpMsg);
			break;
			//bug no bug
		//case 0x16:
			//GCMonsterDieRecv((PMSG_MONSTER_DIE_RECV*)lpMsg);
			//break;
		case 0x17:
			GCUserDieRecv((PMSG_USER_DIE_RECV*)lpMsg);
			break;
		case 0x26:
			GCLifeRecv((PMSG_LIFE_RECV*)lpMsg);
			break;
		case 0x27:
			GCManaRecv((PMSG_MANA_RECV*)lpMsg);
			break;
		case 0x2C:
			GCFruitResultRecv((PMSG_FRUIT_RESULT_RECV*)lpMsg);
			break;
			//no bug
		case 0x9C:
			GCRewardExperienceRecv((PMSG_REWARD_EXPERIENCE_RECV*)lpMsg);
			break;
		case 0xA3:
			GCQuestRewardRecv((PMSG_QUEST_REWARD_RECV*)lpMsg);
			break;

#if OLD_PKNOTICE
			case 0xA6:
			//gInterface.DrawMessage(1, "MiniMap Window [ON]");
			gInterface.KillRecv(lpMsg);
			break;
#endif

			case 0xA9:
				switch (((lpMsg[0] == 0xC1) ? lpMsg[3] : lpMsg[4]))
				{
				case 0x10:
					RoyalBattleGround.PhaseRecv(lpMsg);
					break;
				case 0x11:
					RoyalBattleGround.PointRecv(lpMsg);
					break;
				case 0x12:
					RoyalBattleGround.KillRecv(lpMsg);
					break;
				case 0x13:
					RoyalBattleGround.ZoneRecv(lpMsg);
					break;
				case 0x14:
					RoyalBattleGround.BEventSinhTon_BXC((PMSG_NEW_HEALTH_BAR_RECV*)lpMsg);
					break;
				}
				break;



		case 0xB1:
			switch(((lpMsg[0]==0xC1)?lpMsg[3]:lpMsg[4]))
			{
				case 0x00:
					gIconBuff.DeleteAllBuff();
					jCRenderRuud.ClearRuudInfo();
					GCMapServerMoveRecv((PMSG_MAP_SERVER_MOVE_RECV*)lpMsg);
					break;

#if(FLAG_SKIN)
					ThueFlag.Clear();
#endif
					break;

				case 0x01:
					gIconBuff.DeleteAllBuff();
					jCRenderRuud.ClearRuudInfo();
					GCMapServerMoveAuthRecv((PMSG_MAP_SERVER_MOVE_AUTH_RECV*)lpMsg);
					break;
			}
			break;



		case 0xF1:
			switch(((lpMsg[0]==0xC1)?lpMsg[3]:lpMsg[4]))
			{
				case 0x00:
					GCConnectClientRecv((PMSG_CONNECT_CLIENT_RECV*)lpMsg);
					break;
				case 0x01:
					GCConnectAccountRecv((PMSG_CONNECT_ACCOUNT_RECV*)lpMsg);
					break;
				case 0x02:
					GCCloseClientRecv((PMSG_CLOSE_CLIENT_RECV*)lpMsg);
					break;

				case 0x12:
					g_pLoginMainWin.ReciveCreateAccount(((lpMsg[0] == 0xC1) ? lpMsg[4] : lpMsg[5]));
					break;

			}
			break;
		case 0xF3:
			switch (((lpMsg[0] == 0xC1) ? lpMsg[3] : lpMsg[4]))
			{

				case 0x00:
					gIconBuff.DeleteAllBuff();
					jCRenderRuud.ClearRuudInfo();
					GCCharacterListRecv((PMSG_CHARACTER_LIST_RECV*)lpMsg);
					break;
				case 0x03:
					GCCharacterInfoRecv((PMSG_CHARACTER_INFO_RECV*)lpMsg);
					break;
				case 0x04:
					GCCharacterRegenRecv((PMSG_CHARACTER_REGEN_RECV*)lpMsg);
					break;
				case 0x05:
					GCLevelUpRecv((PMSG_LEVEL_UP_RECV*)lpMsg);
					break;
				case 0x06:
					GCLevelUpPointRecv((PMSG_LEVEL_UP_POINT_RECV*)lpMsg);
					break;
				case 0x07:
					GCMonsterDamageRecv((PMSG_MONSTER_DAMAGE_RECV*)lpMsg);
					break;

				case 0x32: //Show Window CTC Mini
					GCCTCMiniShowWindow((INFOCTCMINI_SENDCLIENT *)lpMsg);
					break;

				case 0x33: //Show Kill CTC Mini
					GCCTCMiniKill((CTCMINIKILL_SENDCLIENT *)lpMsg);
					break;
				case 0x38: //Info CTC
					GCInfoCTC((INFOCTC_SENDCLIENT *)lpMsg);
					break;

				case 0x39: //Show Kill Monter
					GCCTCKillMonter((CTCKILL_SENDCLIENT *)lpMsg);
					break;

				case 0x50:
					GCMasterInfoRecv((PMSG_MASTER_INFO_RECV*)lpMsg);
					break;
				case 0x51:
					GCMasterLevelUpRecv((PMSG_MASTER_LEVEL_UP_RECV*)lpMsg);
					break;
				case 0xE0:
					GCNewCharacterInfoRecv((PMSG_NEW_CHARACTER_INFO_RECV*)lpMsg);
					return 1;
				case 0xE1:
					GCNewCharacterCalcRecv((PMSG_NEW_CHARACTER_CALC_RECV*)lpMsg);
					return 1;
				case 0xE2:
					GCNewHealthBarRecv((PMSG_NEW_HEALTH_BAR_RECV*)lpMsg);
					return 1;
				case 0xE3:
					GCNewGensBattleInfoRecv((PMSG_NEW_GENS_BATTLE_INFO_RECV*)lpMsg);
					return 1;
				case 0xE4:
					GCNewMessageRecv((PMSG_NEW_MESSAGE_RECV*)lpMsg);
					return 1;
				case 0xE5:
					gCustomRankUser.GCReqRankLevelUser((PMSG_CUSTOM_RANKUSER*)lpMsg);
					return 1;

#if(RANKINGGOC == 1)
				case 0xE6:
					gCustomRanking.GCReqRanking((PMSG_CUSTOM_RANKING_RECV*)lpMsg);
					return 1;
				case 0xE7:
					gCustomRanking.GCReqRankingCount((PMSG_CUSTOM_RANKING_COUNT_RECV*)lpMsg);
					return 1;
#endif
				case 0xE8:
					gCustomEventTime.GCReqEventTime((PMSG_CUSTOM_EVENTTIME_RECV*)lpMsg);
					return 1;
				case 0xE9:
					gItemPrice.GCItemValueRecv((PMSG_ITEM_VALUE_RECV*)lpMsg);
					return 1;
				case 0xEA:
					GCRecvCoin((PMSG_COIN_RECV*)lpMsg);
					return 1;
				case 0xEB:
					gOffTrade.RecvPShop((PMSG_OFFTRADE_RECV*)lpMsg);
					return 1;
				case 0xEC:
					gOffTrade.PShopActiveRecv((PMSG_SHOPACTIVE_RECV*)lpMsg);
					return 1;
				case 0xED:
					GCBuyConfirmRecv((PMSG_ITEM_BUY_RECV*)lpMsg);
					break;
				case 0xEE:
					SetChaosBoxState((PMSG_SET_CHAOSBOX_STATE*)lpMsg);
				return 1;
				//--------------cosas de pet
				case 0xF1:
					GCPetCharSetRecv((PMSG_NEW_PET_CHARSET_RECV*)lpMsg);
					break;
				case 0xF2:
					GCPetCharSetSelectCharacterRecv((PMSG_NEW_SELECT_CHARACTER_CHARSET_RECV*)lpMsg);
					break;
				#if(PARTYSEARCH==1)
					case 0xF0:
						GCPartyListRecv((PMSG_RECV_PARTYLIST*)lpMsg);
						return 1;
					case 0xF8:
						gPartySearchSettings.GCPartySettingsRecv((PMSG_PARTYSETTINGS_RECV*)lpMsg);
						break;
                #endif
				// ADVANCE STATS
				case 0xF3:
					g_StatsAdvance.Recv((PMSG_STATS_ADVANCE*)lpMsg);
					return 1;
				// MasterSkill
				case 0xF4:
					gCRenderEx700.RecvMasterSkill((PMSG_MASTER_SKILL_LIST_SEND *)lpMsg);
					return 1;


				case 0x13:
					gIconBuff.GC_BuffInfo((PMSG_SEND_BUFF_ICON_EX*)lpMsg);
					break;
					break;
				case 0xF9:
					gMiniMap.RecvPartyInfo((MINIMAP_PARTY_INFO_RECV*)lpMsg);
				break;

				#if(DANH_HIEU_NEW == 1)
				case 15:
				DanhHieuRecv((DANHHIEU_UPDATE*)lpMsg);
				break;
				#endif

				#if(QUAN_HAM_NEW == 1)
				case 99:
				QuanHamRecv((QUANHAM_UPDATE*)lpMsg);
				break;
				#endif

				#if(TU_LUYEN_NEW == 1)
				case 100:
				TuLuyenRecv((TULUYEN_UPDATE*)lpMsg);
				break;
				#endif

				#if(PKEVENT == 1) // OK
				case 101:
				PKEventRecv((PKEVENT_UPDATE*)lpMsg);
				break;
				case 102:
				GCInfoPKEvent((INFOPKEVENT_SENDCLIENT *)lpMsg);
				break;
				#endif

				#if(TVTEVENT == 1) // OK
				case 103:
				GCInfoTvTEvent((INFOTVTEVENT_SENDCLIENT *)lpMsg);
				break;
				#endif

			}
			break;

					case 0xF4:
						switch (((lpMsg[0] == 0xC1) ? lpMsg[3] : lpMsg[4]))
						{
						#if(CHIEN_TRUONG_CO)
						case 0x8: //Info chiến trường cổ
							GCInfoCTC((INFOCTC_SENDCLIENT *)lpMsg);
							break;
						case 0x9: //Show Kill Monter chiến trường cổ
							GCCTCKillMonter((CTCKILL_SENDCLIENT *)lpMsg);
							break;
						#endif
						}
						break;


					case 0x4E:
						switch (((lpMsg[0] == 0xC1) ? lpMsg[3] : lpMsg[4]))
						{
#if(SLOTPET)
						case 0x0A:
							g_pMyInventory.ReceiveInventory(lpMsg);
							return 1;
						case 0x0B:
							g_pMyInventory.ReceiveDurability(lpMsg);
							return 1;
						case 0x0C:
							g_pMyInventory.ReceiveDeleteInventory(lpMsg);
							return 1;
						case 0x0D:
							g_pMyInventory.ReceiveItemChange(lpMsg);
							return 1;
#endif	
#if(SOIITEM)
						case 0x0E:
							g_pQuickCommandWindow.ReceiveInventory(lpMsg);
							return 1;
#endif

						}
						break;
						//--
#if(SOIITEM)
					case 0xD2: //soiitem
						switch (lpMsg[3])
						{
						case 0x05:
							g_pQuickCommandWindow.ReceivePeriodItemList(lpMsg);
							break;
						}
						break;
#endif

#if(CUSTOM_GUILD_UPGRADE)
					case 0xA8:
						switch (((lpMsg[0] == 0xC1) ? lpMsg[3] : lpMsg[4]))
						{
							case 0x00:	GuildUpgrade.RecvMeInfo(lpMsg);				break;
							case 0x01:	GuildUpgrade.RecvGuildRankingInfo(lpMsg);	break;
							case 0x02:	GuildUpgrade.RecvMyGuildInfo(lpMsg);		break;
							case 0x03:	GuildUpgrade.RecvDevoteItemInfo(lpMsg);		break;
							case 0x04:	GuildUpgrade.RecvShopItemInfo(lpMsg);		break;
							case 0x05:	GuildUpgrade.RecvDevoteResult(lpMsg);		break;
							
							break;
#endif
						}
						break;



				case 0xFA:
					switch (((lpMsg[0] == 0xC1) ? lpMsg[3] : lpMsg[4]))
						{

#if (CongHuongV2)
					case 0x15:
					{
						 CH_RecvInfoGSSend((PMSG_GSSendInfoClient*)lpMsg);
					}
						break;
					case 0x14: // OPen NPC
					{
						 XULY_CGPACKET* mRecv = (XULY_CGPACKET*)lpMsg;

						 if (!mRecv->ThaoTac) return 1;

						 if (GetTickCount() > gInterface.Data[eWindow_CongHuong].EventTick + 500)
						 {
						   gInterface.Data[eWindow_CongHuong].OnShow ^= 1;
						   gInterface.Data[eWindow_CongHuong].EventTick = GetTickCount();
						 }
					}
					break;
#endif

#if(JEWELBANKVER2)
						case 0x19: //
						{
						//pDrawMessage("0x18", 1);

						PMSG_NEW_HEALTH_BAR_RECV* pMsg = (PMSG_NEW_HEALTH_BAR_RECV*)lpMsg;
						gInterface.mCListItemBank.clear();
						for (int n = 0; n < pMsg->count; n++)
						{
						 USER_BANK_DATA* lpInfo = (USER_BANK_DATA*)(((BYTE*)lpMsg) + sizeof(PMSG_NEW_HEALTH_BAR_RECV)+(sizeof(USER_BANK_DATA)* n));
						 USER_BANK_DATA info;
						 info.ItemIndex = lpInfo->ItemIndex;
						 info.ItemLevel = lpInfo->ItemLevel;
						 info.ItemCount = lpInfo->ItemCount;
						 info.AutoPick = lpInfo->AutoPick;
						 gInterface.mCListItemBank.push_back(info);
						//	g_Console.AddMessage(1, "Set InfoBank (%d) %d , %d  Count = %d (%d)", lpInfo->Index, lpInfo->ItemIndex, lpInfo->ItemLevel, lpInfo->ItemCount, m_UserCustomItemBank.size());
						}
					}
				break;

#endif
			}
		break;

		case 0xFB:
			switch (((lpMsg[0] == 0xC1) ? lpMsg[3] : lpMsg[4]))
			{

			case 0xC1:
				gResetChange.RecibirResetChange((PMSG_RESET_CHANGE*)lpMsg);
				break;


			#if(OFFLINE_MODE_NEW)
				case 0x00:
				gOfflineMode.GCOfflineModeRecv((PMSG_OFFLINEMODE_REQ*)lpMsg);
				break;
			#endif

				case 0xE8:
				gHuyHieuCuongHoa.GCData((PMSG_HUYHIEU_RECV*)lpMsg);
				break;

				#if(FLAG_SKIN)
				case 0x15:
				ThueFlag.RecvData(lpMsg);
				break;
				#endif


				case 0x59:
					gInterface.TvTEventEx((PMSG_TVTEVENT_UPD*)lpMsg);
					break;

#if(THANMA)

					//==Than Ma Chien
				case 0x61:
				{
							 if ((GetTickCount() - gInterface.Data[eWindowNPC_ThanMaChien].EventTick) > 300)
							 {

								 gInterface.Data[eWindowNPC_ThanMaChien].EventTick = GetTickCount();
								 gInterface.Data[eWindowNPC_ThanMaChien].OnShow ^= 1;
							 }
				}
					break;
					//===Set Tiem Than Ma
				case 0x62:
				{
							 PMSG_TIMEEVENT_CUSTOM* mRecv = (PMSG_TIMEEVENT_CUSTOM*)lpMsg;
							 gInterface.m_EventTMMap = mRecv->Map;
							 gInterface.m_EventTMState = mRecv->State;
							 gInterface.m_EventTMTimeCount = mRecv->TimeCount;
							 gInterface.mCalcTimeEventTick = GetTickCount();
							 //gInterface.DrawMessage(1,"TM State %d %d %d", gInterface.m_EventTMMap, gInterface.m_EventTMState, gInterface.m_EventTMTimeCount);

				}
					break;
					//===Set BXH
				case 0x63:
				{
							 PMSG_COUNTLIST_TM* mRecv = (PMSG_COUNTLIST_TM*)lpMsg;
							 gInterface.m_TMChienBXHC = 0;
							 gInterface.m_TMScoreThienThan = mRecv->ScoreAcQuy;
							 gInterface.m_TMScoreAcQuy = mRecv->ScoreThienThan;
							 for (int n = 0; n < 10; n++)
							 {
								 memset(gInterface.m_ThanMaChienBXH[n].Name, 0, sizeof(gInterface.m_ThanMaChienBXH[n].Name));
								 gInterface.m_ThanMaChienBXH[n].Kill = 0;
								 gInterface.m_ThanMaChienBXH[n].Team = 0;
							 }

							 for (int n = 0; n < mRecv->Count; n++)
							 {
								 EVENTHANMA_BXH* lpInfo = (EVENTHANMA_BXH*)(((BYTE*)mRecv) + sizeof(PMSG_COUNTLIST_TM)+(sizeof(EVENTHANMA_BXH)* n));
								 memcpy(gInterface.m_ThanMaChienBXH[n].Name, lpInfo->Name, sizeof(gInterface.m_ThanMaChienBXH[n].Name));
								 gInterface.m_ThanMaChienBXH[n].Kill = lpInfo->Kill;
								 gInterface.m_ThanMaChienBXH[n].Team = lpInfo->Team;
								 gInterface.m_TMChienBXHC++;

								 if (gInterface.m_TMChienBXHC > 10)
								 {
									 break;
								 }
							 }
							 if (mRecv->OpenBXHWindow == 1)
							 {
								 gInterface.Data[eWindowBXH_ThanMaChien].OnShow = 1;
							 }

				}
					break;
#endif



#if(EventSinhTon)

				case 0x65:
				{
							 if ((GetTickCount() - gInterface.Data[eWindowNPC_BattleRoyale].EventTick) > 300)
							 {

								 gInterface.Data[eWindowNPC_BattleRoyale].EventTick = GetTickCount();
								 gInterface.Data[eWindowNPC_BattleRoyale].OnShow ^= 1;
							 }
				}
					break;
					//===Set time GPK
				case 0x66:
				{
							 PMSG_BATTLEROYALE_CUSTOM* mRecv = (PMSG_BATTLEROYALE_CUSTOM*)lpMsg;
							 gInterface.m_EventBattleRoyaleMap = mRecv->Map;
							 gInterface.m_EventBattleRoyaleState = mRecv->State;
							 gInterface.m_EventBattleRoyaleTimeCount = mRecv->TimeCount;
							 gInterface.mBattleRoyaleEventTick = GetTickCount();
							 gInterface.m_DiemGiet = mRecv->Giet;
							 gInterface.m_DiemChet = mRecv->Chet;

				}
					break;
					//===Set BXH
				case 0x67:
				{
							 PMSG_COUNTLIST_BATTLEROYALE * mRecv = (PMSG_COUNTLIST_BATTLEROYALE*)lpMsg;
							 gInterface.m_BattleRoyaleBXHC = 0;
							 for (int n = 0; n < 10; n++)
							 {
								 memset(gInterface.m_BattleRoyaleBXH[n].Name, 0, sizeof(gInterface.m_BattleRoyaleBXH[n].Name));
								 gInterface.m_BattleRoyaleBXH[n].Kill = 0;
								 gInterface.m_BattleRoyaleBXH[n].Death = 0;
							 }

							 for (int n = 0; n < mRecv->Count; n++)
							 {
								 BATTLEROYALE_BXH* lpInfo = (BATTLEROYALE_BXH*)(((BYTE*)mRecv) + sizeof(PMSG_COUNTLIST_BATTLEROYALE)+(sizeof(BATTLEROYALE_BXH)* n));
								 memcpy(gInterface.m_BattleRoyaleBXH[n].Name, lpInfo->Name, sizeof(gInterface.m_BattleRoyaleBXH[n].Name));
								 gInterface.m_BattleRoyaleBXH[n].Kill = lpInfo->Kill;
								 gInterface.m_BattleRoyaleBXH[n].Death = lpInfo->Death;
								 gInterface.m_BattleRoyaleBXHC++;

								 if (gInterface.m_BattleRoyaleBXHC > 10)
								 {
									 break;
								 }
							 }
							 if (mRecv->OpenBXHWindow == 1)
							 {
								 gInterface.Data[eWindowBXH_BattleRoyale].OnShow = 1;
							 }

				}
					break;
#endif

#if(THONG_TIN_BOSS)
				case 0x98:
					gActiveInvasions.list_recv(reinterpret_cast<PMSG_ACTIVE_INVASIONS_RECV*>(lpMsg));
					break;
				case 0x99:
					gActiveInvasions.update_monster_recv((PMSG_INVASION_MONSTER_UPDATE_RECV*)lpMsg);
					break;
#endif

				case 200:
					gInterface.GetInfoClient((PMSG_CLIENT_UPD*)lpMsg);
					break;

			}
			break;



#if (CUSTOM_HARMONY)
				case 0xD5:
					switch (((lpMsg[0] == 0xC1) ? lpMsg[3] : lpMsg[4]))
					{
					case 0x2A:
					{
								 XULY_CGPACKET* mRecv = (XULY_CGPACKET*)lpMsg;
								 if (mRecv->ThaoTac != 111) return 0;
								 if (GetTickCount() > gInterface.Data[eWindowHarmony].EventTick)
								 {
									 gInterface.Data[eWindowHarmony].EventTick = GetTickCount() + 300;
									 gInterface.Data[eWindowHarmony].OnShow ^= 1;
								 }
								 gSauCustomHarmony.SetStateHarmony = true;
					}
						break;
					case 0x2B:
					{
								 DATAOHOA_SENDCLIENT* mRecv = (DATAOHOA_SENDCLIENT*)lpMsg;
								 gSauCustomHarmony.Harmony_ActiveMix = mRecv->ActiveMix;
								 memcpy(gSauCustomHarmony.ItemChuaEp, mRecv->ItemChuaEp, sizeof(gSauCustomHarmony.ItemChuaEp));
								 gSauCustomHarmony.Rate = mRecv->Rate;
								 gSauCustomHarmony.Price = mRecv->Price;
								 gSauCustomHarmony.PriceType = mRecv->PriceType;
								 gSauCustomHarmony.SoLuongDaTaoHoa = mRecv->SoLuongDaTaoHoa;
								 gSauCustomHarmony.IndexRandom = mRecv->IndexRandom;

					}
						break;

					case 0x25:
						gSauCustomHarmony.RecvHarmony((CSEV_COUNTLIST*)lpMsg);
						break;
					}
					break;
#endif


		case 0xFF:
			gInterface.DrawPing();
			break;
			//-- Open Ruud
		case 0xEA:
			jCRenderRuud.LoadRuudShop_Recv((PMSG_ITEMRUUD_LIST_RECV*)lpMsg);
			return 1;
		case 0xEE:
			jCRenderRuud.OpenRuudShop_Recv((PMSG_NPC_TALK_RECV*)lpMsg);
			return 1;
			//--post item

		case 0x78:
			RecvPostItem((PMSG_POSTITEM*)lpMsg);
			break;
		//-- Buff Icon
		case 0x2D:
			gIconBuff.Recv((PMSG_SEND_BUFF_ICON * )lpMsg);
			break;
			//-- Party Buff
		case 0x2E:
			gPartyBuffs.RecvPartyBuffs((PMSG_PARTY_EFFECT_LIST_SEND*)lpMsg);
			break;


#if (takumi12 == 1)
		case 0x79:
			gCentral.CGPartyLifeRecv((PMSG_PARTY_LIFE_SEND *) lpMsg);
			break;
		case 0x7A:
			gCentral.CGPartyListRecv((PMSG_PARTY_LIST_SEND *) lpMsg);
				break;
#endif
		case 0xD3:
			switch (((lpMsg[0] == 0xC1) ? lpMsg[3] : lpMsg[4]))
			{


#if(ANTIHACK_NEW)
			case 0xAA: //
			{
						   gBAntihack.RecvGSInfo((BGUARD_REQ_CHECK*)lpMsg);
			}
				break;
			case 0xAC: //
			{
						   gBAntihack.RecvMouduleDataInfo((PMSG_MODULE_DATA_SEND*)lpMsg);
			}
				break;
#endif


#if(CUSTOM_DUNGLUYENITEM)
			case 0x25:
				gInterface.NhanListItemDungLuyen((CSEV_COUNTLIST*)lpMsg);
				break;
			case 0x2A:
			{
						 XULY_CGPACKET* mRecv = (XULY_CGPACKET*)lpMsg;
						 if (mRecv->ThaoTac != 111) return 0;
						 if (GetTickCount() > gInterface.Data[eWindowDungLuyenItem].EventTick)
						 {
							 gInterface.Data[eWindowDungLuyenItem].EventTick = GetTickCount() + 300;
							 gInterface.Data[eWindowDungLuyenItem].OnShow ^= 1;
						 }
						 gInterface.SetStateDungLuyen = true;
			}
				break;
			case 0x2B:
			{
						 INFOITEM_DUNGLUYENT_CLIENT* mRecv = (INFOITEM_DUNGLUYENT_CLIENT*)lpMsg;
						 memcpy(gInterface.DL_ItemChinh, mRecv->ItemChinh, sizeof(gInterface.DL_ItemChinh));
						 memcpy(gInterface.DL_ItemPhu, mRecv->ItemPhu, sizeof(gInterface.DL_ItemPhu));
						 memcpy(gInterface.DL_ItemKetQua, mRecv->ItemKetQua, sizeof(gInterface.DL_ItemKetQua));
						 gInterface.RateDL = mRecv->Rate;
						 gInterface.TypeDL = mRecv->TypeMix;
						 gInterface.DL_ActiveMix = mRecv->ActiveMix;
						 memcpy(gInterface.TextDL, mRecv->Text, sizeof(gInterface.TextDL));
						 //gInterface.DrawMessage(1, "rate %d , Type %d",gInterface.RateDL,gInterface.TypeDL);

						 gInterface.DL_EffectsMix = false;
			}
				break;

#endif
#if(SAUDOIITEM)
			case 0x6A:
			{
						 XULY_CGPACKET* mRecv = (XULY_CGPACKET*)lpMsg;
						 if (mRecv->ThaoTac != 111) return 0;
						 if (GetTickCount() > gInterface.Data[eWindowDoiItem].EventTick)
						 {
							 gInterface.Data[eWindowDoiItem].EventTick = GetTickCount() + 300;
							 gInterface.Data[eWindowDoiItem].OnShow ^= 1;
						 }
						 gInterface.SetStateDoiItem = true;
			}
				break;
			case 0x6B:
			{
						 INFOITEM_DOIITEM_CLIENT* mRecv = (INFOITEM_DOIITEM_CLIENT*)lpMsg;
						 memcpy(gInterface.SAU_ItemChinh, mRecv->ItemChinh, sizeof(gInterface.SAU_ItemChinh));
						 memcpy(gInterface.SAU_ItemPhu, mRecv->ItemPhu, sizeof(gInterface.SAU_ItemPhu));
						 for (int n = 0; n < 6; n++)
						 {
							 memcpy(gInterface.SAU_ItemKetQua[n], mRecv->ItemKetQua[n], sizeof(gInterface.SAU_ItemKetQua[n]));
						 }
						 gInterface.RateSAU = mRecv->Rate;
						 gInterface.SAU_ActiveMix = mRecv->ActiveMix;
						 gInterface.SAU_EffectsMix = false;
			}
				break;
#endif

#if(VONGQUAY_NEW)
			case 0x8A: //GetList Moc Nap
			{
						   mDataVongQuayClient.Clear();
						   PMSG_VONGQUAY_SEND* mRecv = (PMSG_VONGQUAY_SEND*)lpMsg;

						   for (int i = 0; i < mRecv->count; i++)
						   {
							   ListVongQuaySend lpInfo = *(ListVongQuaySend*)(((BYTE*)lpMsg) + sizeof(PMSG_VONGQUAY_SEND)+(sizeof(ListVongQuaySend)* i));
							   mDataVongQuayClient.DanhSachVongQuay.push_back(lpInfo);
						   }
			}
				break;
			case 0x8B: //Recv List Phan Thuong
			{
						   mDataListItemVongQuayClient.Clear();
						   PMSG_YCVONGQUAY_SEND* mRecv = (PMSG_YCVONGQUAY_SEND*)lpMsg;
						   mDataListItemVongQuayClient.IndexYC = mRecv->IndexYC;
						   mDataListItemVongQuayClient.CountItem = mRecv->CountItem;
						   mDataListItemVongQuayClient.WCYC = mRecv->WCYC;
						   mDataListItemVongQuayClient.WPYC = mRecv->WPYC;
						   mDataListItemVongQuayClient.GPYC = mRecv->GPYC;

						   for (int i = 0; i < mRecv->count; i++)
						   {
							   LISTITEMVONGQUAY_SENDINFO lpInfo = *(LISTITEMVONGQUAY_SENDINFO*)(((BYTE*)lpMsg) + sizeof(PMSG_YCVONGQUAY_SEND)+(sizeof(LISTITEMVONGQUAY_SENDINFO)* i));
							   //==SetINfoItem
							   INFO_VONGQUAY_LOCAL_ITEM infoItemLocal = { 0 };
							   infoItemLocal.SizeBMD = lpInfo.SizeBMD;
							   infoItemLocal.Index = lpInfo.Index;
							   infoItemLocal.Item = *((ObjectItem * (__thiscall*)(int, BYTE*)) 0x007E1B10)(*(DWORD*)(((int(*)()) 0x861110)() + 36), lpInfo.Item);
							   infoItemLocal.Item.Durability = lpInfo.Dur;
							   if (lpInfo.PeriodTime)
							   {
								   infoItemLocal.Item.PeriodItem = 1;
								   infoItemLocal.Item.ExpireDateConvert = lpInfo.PeriodTime;
							   }
							   mDataListItemVongQuayClient.ListItemVongQuay.push_back(infoItemLocal);

						   }
						   gInterface.Data[eWindowVongQuay].OnShow = 1;
			}
				break;
			case 0x8C: //Recv List Phan Thuong
			{
						   XULY_CGPACKET_VONGQUAY* mRecv = (XULY_CGPACKET_VONGQUAY*)lpMsg;
						   //gInterface.DrawMessage(1, "%d ~ %d", mRecv->StartRoll, mRecv->IndexWin);
						   gInterface.StartRollSau = mRecv->StartRoll;
						   gInterface.IndexItemSau = mRecv->IndexWin;
			}
				break;

#endif

#if(B_MOCNAP)
			case 0x9A: //GetList Moc Nap
			{
						   mDataMocNapClient.Clear();
						   PMSG_CBMONAP_SEND* mRecv = (PMSG_CBMONAP_SEND*)lpMsg;
						   mDataMocNapClient.NhanMocNap = mRecv->NhanMocNap;
						   mDataMocNapClient.TongNap = mRecv->TongNap;
						   for (int i = 0; i < mRecv->count; i++)
						   {
							   ListMocNapSend lpInfo = *(ListMocNapSend*)(((BYTE*)lpMsg) + sizeof(PMSG_CBMONAP_SEND)+(sizeof(ListMocNapSend)* i));
							   mDataMocNapClient.DanhSachMocNap.push_back(lpInfo);
						   }
			}
				break;
			case 0x9B: //Recv List Phan Thuong
			{
						   mDataListItemMocNapClient.Clear();
						   PMSG_CBLISTTHUONG_SEND* mRecv = (PMSG_CBLISTTHUONG_SEND*)lpMsg;
						   mDataListItemMocNapClient.WC = mRecv->WC;
						   mDataListItemMocNapClient.WP = mRecv->WP;
						   mDataListItemMocNapClient.GP = mRecv->GP;
						   for (int i = 0; i < mRecv->count; i++)
						   {
							   LISTITEMMOCNAP_SENDINFO lpInfo = *(LISTITEMMOCNAP_SENDINFO*)(((BYTE*)lpMsg) + sizeof(PMSG_CBLISTTHUONG_SEND)+(sizeof(LISTITEMMOCNAP_SENDINFO)* i));
							   //==SetINfoItem
							   INFO_LOCAL_ITEM infoItemLocal = { 0 };
							   infoItemLocal.Count = lpInfo.Count;
							   infoItemLocal.SizeBMD = lpInfo.SizeBMD;
							   infoItemLocal.Index = lpInfo.Index;
							   infoItemLocal.Item = *((ObjectItem * (__thiscall*)(int, BYTE*)) 0x007E1B10)(*(DWORD*)(((int(*)()) 0x861110)() + 36), lpInfo.Item);
							   infoItemLocal.Item.Durability = lpInfo.Dur;
							   if (lpInfo.PeriodTime)
							   {
								   infoItemLocal.Item.PeriodItem = 1;
								   infoItemLocal.Item.ExpireDateConvert = lpInfo.PeriodTime;
							   }
							   mDataListItemMocNapClient.ListItemMocNap.push_back(infoItemLocal);

						   }
			}
				break;
#endif

#if(B_HON_HOAN)
			case 0x01:
			{
				gInterface.m_DataConfigHonHoan.clear();
				CSEV_COUNTLIST* mRecv = (CSEV_COUNTLIST*)lpMsg;
				for (int i = 0; i < mRecv->Count; i++)
				{
					CONFIDATA_HONHOAN lpInfo = *(CONFIDATA_HONHOAN*)(((BYTE*)lpMsg) + sizeof(CSEV_COUNTLIST) + (sizeof(CONFIDATA_HONHOAN) * i));

					gInterface.m_DataConfigHonHoan.insert(std::pair<int, CONFIDATA_HONHOAN>(lpInfo.LvHonHoan, lpInfo));

					//gInterface.m_DataConfigHonHoan.push_back(*lpInfo);

				}

				if ((GetTickCount() - gInterface.Data[eWindow_NangCapHonHoan].EventTick) > 300)
				{
					gInterface.Data[eWindow_NangCapHonHoan].OnShow ^= 1;
					gInterface.Data[eWindow_NangCapHonHoan].EventTick = GetTickCount();
				}
			}
			break;
#endif

			//===RecvInfo Dau Truong PK
			case 0x32:
			{
						 DAUTRUONGEVENT_INFO* mRecv = (DAUTRUONGEVENT_INFO*)lpMsg;
						 gInterface.mDauTruongClearInfo();
						 gInterface.mDauTruong_Rank = mRecv->Rank;
						 gInterface.mDauTruong_Score = mRecv->Score;
						 gInterface.mDauTruong_Time = mRecv->Time;
						 gInterface.mDauTruong_State = mRecv->State;
			}
				break;
				//===Recv Info BXH
			case 0x33:
			{
						 RECVDAUTRUONGEVENT_BXH* mRecv = (RECVDAUTRUONGEVENT_BXH*)lpMsg;
						 gInterface.mDauTruongBXHData.clear();
						 gInterface.mDauTruongClearInfo();
						 for (int n = 0; n < mRecv->Count; n++)
						 {
							 DAUTRUONGEVENT_BXH* lpInfo = (DAUTRUONGEVENT_BXH*)(((BYTE*)lpMsg) + sizeof(RECVDAUTRUONGEVENT_BXH)+(sizeof(DAUTRUONGEVENT_BXH)* n));

							 gInterface.mDauTruongBXHData.push_back(*lpInfo);
						 }
						 gInterface.Data[eWindowEventDauTruong].OnShow ^= 1;
						 //pDrawMessage("Recv Data BXH OK", 1);
			}
				break;




			case 0x34:
			{
				GREATPKEVENT_INFO* mRecv = (GREATPKEVENT_INFO*)lpMsg;
				gInterface.mGreatPKClearInfo();
				gInterface.mGreatPK_Rank = mRecv->Rank;
				gInterface.mGreatPK_Score = mRecv->Score;
				gInterface.mGreatPK_Time = mRecv->Time;
				gInterface.mGreatPK_State = mRecv->State;
			}
			break;
			//===Recv Info BXH
			case 0x35:
			{
				RECVGREATPKEVENT_BXH* mRecv = (RECVGREATPKEVENT_BXH*)lpMsg;
				gInterface.mGreatPKBXHData.clear();
				for (int n = 0; n < mRecv->Count; n++)
				{
					GREATPKEVENT_BXH* lpInfo = (GREATPKEVENT_BXH*)(((BYTE*)lpMsg) + sizeof(RECVGREATPKEVENT_BXH) + (sizeof(GREATPKEVENT_BXH)* n));

					gInterface.mGreatPKBXHData.push_back(*lpInfo);
				}
				gInterface.Data[eWindowEventGreatPK].OnShow ^= 1;
			}
			break;


			case 0x10:
				GCSetSkinModelList((BPMSG_CUSTOM_SKIN_SEND*)lpMsg);
				break;
			case 0x12:
				GCSetInfoSkinSelect((BPMSG_CUSTOM_SKIN_SEND*)lpMsg);
				break;


			}
			break;
	}

	return ProtocolCore(head,lpMsg,size,key);
}

void GCDamageRecv(PMSG_DAMAGE_RECV* lpMsg) // OK
{
	int aIndex = MAKE_NUMBERW(lpMsg->index[0], lpMsg->index[1]) & 0x7FFF;

	if (ViewIndex == aIndex)
	{
		ViewCurHP = lpMsg->ViewCurHP;
		ViewCurSD = lpMsg->ViewCurSD;
	}

	ViewDamageHP = lpMsg->ViewDamageHP;
	ViewDamageSD = lpMsg->ViewDamageSD;

	if ((lpMsg->type & 0x10) != 0)
	{
		if (ViewDamageCount < 3)
		{
			ViewDamageTable[ViewDamageCount++] = lpMsg->ViewDamageHP;
			ViewDamageValue = ViewDamageCount;
		}
	}

	if ((lpMsg->type & 0x20) != 0)
	{
		if (ViewDamageCount < 4)
		{
			ViewDamageTable[ViewDamageCount++] = lpMsg->ViewDamageHP;
			ViewDamageValue = ViewDamageCount;
		}
	}
}

void GCMonsterDieRecv(PMSG_MONSTER_DIE_RECV* lpMsg) // OK
{
	ViewDamageHP = lpMsg->ViewDamageHP;
}

void GCUserDieRecv(PMSG_USER_DIE_RECV* lpMsg) // OK
{
	int aIndex = MAKE_NUMBERW(lpMsg->index[0],lpMsg->index[1]) & 0x7FFF;

	if(ViewIndex == aIndex)
	{
		ViewCurHP = 0;
	}
}

void GCLifeRecv(PMSG_LIFE_RECV* lpMsg) // OK
{
	if(lpMsg->type == 0xFE)
	{
		ViewMaxHP = lpMsg->ViewHP;
		ViewMaxSD = lpMsg->ViewSD;
	}

	if(lpMsg->type == 0xFF)
	{
		ViewCurHP = ((ViewCurHP==0)?ViewCurHP:lpMsg->ViewHP);
		ViewCurSD = lpMsg->ViewSD;
	}
}

void GCManaRecv(PMSG_MANA_RECV* lpMsg) // OK
{
	if(lpMsg->type == 0xFE)
	{
		ViewMaxMP = lpMsg->ViewMP;
		ViewMaxBP = lpMsg->ViewBP;
	}

	if(lpMsg->type == 0xFF)
	{
		ViewCurMP = lpMsg->ViewMP;
		ViewCurBP = lpMsg->ViewBP;
	}
}

void GCFruitResultRecv(PMSG_FRUIT_RESULT_RECV* lpMsg) // OK
{
	if(lpMsg->result == 0 || lpMsg->result == 3 || lpMsg->result == 6 || lpMsg->result == 17)
	{
		ViewValue = lpMsg->ViewValue;
		ViewPoint = lpMsg->ViewPoint;
		ViewStrength = lpMsg->ViewStrength;
		ViewDexterity = lpMsg->ViewDexterity;
		ViewVitality = lpMsg->ViewVitality;
		ViewEnergy = lpMsg->ViewEnergy;
		ViewLeadership = lpMsg->ViewLeadership;
	}
}

void GCRewardExperienceRecv(PMSG_REWARD_EXPERIENCE_RECV* lpMsg) // OK
{
	gObjUser.Refresh();
	ViewDamageHP = lpMsg->ViewDamageHP;
}

void GCQuestRewardRecv(PMSG_QUEST_REWARD_RECV* lpMsg) // OK
{
	int aIndex = MAKE_NUMBERW(lpMsg->index[0],lpMsg->index[1]) & 0x7FFF;

	if(ViewIndex == aIndex)
	{
		ViewPoint = lpMsg->ViewPoint;
	}
}

void GCMapServerMoveRecv(PMSG_MAP_SERVER_MOVE_RECV* lpMsg) // OK
{
	ReconnectOnMapServerMove(lpMsg->IpAddress,lpMsg->ServerPort);
}

void GCMapServerMoveAuthRecv(PMSG_MAP_SERVER_MOVE_AUTH_RECV* lpMsg) // OK
{
	ReconnectOnMapServerMoveAuth(lpMsg->result);
}

void GCConnectClientRecv(PMSG_CONNECT_CLIENT_RECV* lpMsg) // OK
{
	gHwid.SendHwid();
	ViewIndex = MAKE_NUMBERW(lpMsg->index[0],lpMsg->index[1]);
}

void GCConnectAccountRecv(PMSG_CONNECT_ACCOUNT_RECV* lpMsg) // OK
{
	ReconnectOnConnectAccount(lpMsg->result);
}

void GCCloseClientRecv(PMSG_CLOSE_CLIENT_RECV* lpMsg) // OK
{
	ReconnectOnCloseClient(lpMsg->result);
}

void GCCharacterListRecv(PMSG_CHARACTER_LIST_RECV* lpMsg) // OK
{
	ReconnectOnCharacterList();
}

void GCCharacterInfoRecv(PMSG_CHARACTER_INFO_RECV* lpMsg) // OK
{
	ReconnectOnCharacterInfo();

	ObjectDir = lpMsg->Dir;
	ViewReset = lpMsg->ViewReset;
	ViewPoint = lpMsg->ViewPoint;
	ViewCurHP = lpMsg->ViewCurHP;
	ViewMaxHP = lpMsg->ViewMaxHP;
	ViewCurMP = lpMsg->ViewCurMP;
	ViewMaxMP = lpMsg->ViewMaxMP;
	ViewCurBP = lpMsg->ViewCurBP;
	ViewMaxBP = lpMsg->ViewMaxBP;
	ViewCurSD = lpMsg->ViewCurSD;
	ViewMaxSD = lpMsg->ViewMaxSD;
	ViewStrength = lpMsg->ViewStrength;
	ViewDexterity = lpMsg->ViewDexterity;
	ViewVitality = lpMsg->ViewVitality;
	ViewEnergy = lpMsg->ViewEnergy;
	ViewLeadership = lpMsg->ViewLeadership;

	*(WORD*)(*(DWORD*)(MAIN_VIEWPORT_STRUCT)+0x07E) = 0;

	*(BYTE*)(*(DWORD*)(MAIN_VIEWPORT_STRUCT)+0x30C) = 0;

	switch(((*(BYTE*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x0B)) & 7))
	{
	//	case 0:
	//		SetByte(0x00556C38,((gProtect.m_MainInfo.DWMaxAttackSpeed>=0xFFFF)?0x02:0x0F));
	//		break;
	//	case 1:
	//		SetByte(0x00556C38,((gProtect.m_MainInfo.DKMaxAttackSpeed>=0xFFFF)?0x0F:0x0F));
	//		break;
	//	case 2:
	//		SetByte(0x00556C38,((gProtect.m_MainInfo.FEMaxAttackSpeed>=0xFFFF)?0x02:0x0F));
	//		break;
	//	case 3:
	//		SetByte(0x00556C38,((gProtect.m_MainInfo.MGMaxAttackSpeed>=0xFFFF)?0x02:0x0F));
	//		break;
	//	case 4:
	//		SetByte(0x00556C38,((gProtect.m_MainInfo.DLMaxAttackSpeed>=0xFFFF)?0x02:0x0F));
	//		break;
	//	case 5:
	//		SetByte(0x00556C38,((gProtect.m_MainInfo.SUMaxAttackSpeed>=0xFFFF)?0x02:0x0F)); 
	//		break;
	//	case 6:
	//		SetByte(0x00556C38,((gProtect.m_MainInfo.RFMaxAttackSpeed>=0xFFFF)?0x0F:0x0F));
	//		break;

	//}

	case 0:
		SetByte(0x00556C38, ((gProtect.m_MainInfo.DWMaxAttackSpeed >= 0xFFFF) ? 0x03 : 0x0F));
		break;
	case 1:
		SetByte(0x00556C38, ((gProtect.m_MainInfo.DKMaxAttackSpeed >= 0xFFFF) ? 0x04 : 0x0F));
		break;
	case 2:
		SetByte(0x00556C38, ((gProtect.m_MainInfo.FEMaxAttackSpeed >= 0xFFFF) ? 0x03 : 0x0F));
		break;
	case 3:
		SetByte(0x00556C38, ((gProtect.m_MainInfo.MGMaxAttackSpeed >= 0xFFFF) ? 0x03 : 0x0F));
		break;
	case 4:
		SetByte(0x00556C38, ((gProtect.m_MainInfo.DLMaxAttackSpeed >= 0xFFFF) ? 0x03 : 0x0F));
		break;
	case 5:
		SetByte(0x00556C38, ((gProtect.m_MainInfo.SUMaxAttackSpeed >= 0xFFFF) ? 0x03 : 0x0F));
		break;
	case 6:
		SetByte(0x00556C38, ((gProtect.m_MainInfo.RFMaxAttackSpeed >= 0xFFFF) ? 0x0F : 0x0F));
		break;
	}
}

void GCCharacterRegenRecv(PMSG_CHARACTER_REGEN_RECV* lpMsg) // OK
{
	ViewCurHP = lpMsg->ViewCurHP;
	ViewCurMP = lpMsg->ViewCurMP;
	ViewCurBP = lpMsg->ViewCurBP;
	ViewCurSD = lpMsg->ViewCurSD;
}

void GCLevelUpRecv(PMSG_LEVEL_UP_RECV* lpMsg) // OK
{
	ViewPoint = lpMsg->ViewPoint;

	ViewMaxHP = lpMsg->ViewMaxHP;
	ViewMaxMP = lpMsg->ViewMaxMP;
	ViewMaxBP = lpMsg->ViewMaxBP;
	ViewMaxSD = lpMsg->ViewMaxSD;
	ViewExperience = lpMsg->ViewExperience;
	ViewNextExperience = lpMsg->ViewNextExperience;

	ViewCurMP = ViewMaxMP;
	ViewCurBP = ViewMaxBP;
	*(WORD *)(*(DWORD *)0x8128AC8 + 36) = *(WORD *)(*(DWORD *)0x8128AC8 + 40); //-- Mana
	*(WORD *)(*(DWORD *)0x8128AC8 + 64) = *(WORD *)(*(DWORD *)0x8128AC8 + 66); //-- BP
}

void GCLevelUpPointRecv(PMSG_LEVEL_UP_POINT_RECV* lpMsg) // OK
{
	if(lpMsg->result >= 16 && lpMsg->result <= 20)
	{
		ViewPoint = lpMsg->ViewPoint;
		ViewMaxHP = lpMsg->ViewMaxHP;
		ViewMaxMP = lpMsg->ViewMaxMP;
		ViewMaxBP = lpMsg->ViewMaxBP;
		ViewMaxSD = lpMsg->ViewMaxSD;
		ViewStrength = lpMsg->ViewStrength;
		ViewDexterity = lpMsg->ViewDexterity;
		ViewVitality = lpMsg->ViewVitality;
		ViewEnergy = lpMsg->ViewEnergy;
		ViewLeadership = lpMsg->ViewLeadership;
	}
}

void GCMonsterDamageRecv(PMSG_MONSTER_DAMAGE_RECV* lpMsg) // OK
{
	ViewCurHP = lpMsg->ViewCurHP;
	ViewCurSD = lpMsg->ViewCurSD;
	ViewDamageHP = lpMsg->ViewDamageHP;
	ViewDamageSD = lpMsg->ViewDamageSD;
}

void GCMasterInfoRecv(PMSG_MASTER_INFO_RECV* lpMsg) // OK
{
	ViewMaxHP = lpMsg->ViewMaxHP;
	ViewMaxMP = lpMsg->ViewMaxMP;
	ViewMaxBP = lpMsg->ViewMaxBP;
	ViewMaxSD = lpMsg->ViewMaxSD;
}

void GCMasterLevelUpRecv(PMSG_MASTER_LEVEL_UP_RECV* lpMsg) // OK
{
	ViewMaxHP = lpMsg->ViewMaxHP;
	ViewMaxMP = lpMsg->ViewMaxMP;
	ViewMaxBP = lpMsg->ViewMaxBP;
	ViewMaxSD = lpMsg->ViewMaxSD;
	ViewMasterExperience = lpMsg->ViewMasterExperience;
	ViewMasterNextExperience = lpMsg->ViewMasterNextExperience;
	ViewCurMP = ViewMaxMP;
	ViewCurBP = ViewMaxBP;

	*(WORD *)(*(DWORD *)0x8128AC8 + 64) = *(WORD *)(*(DWORD *)0x8128AC8 + 66);
}

void GCNewCharacterInfoRecv(PMSG_NEW_CHARACTER_INFO_RECV* lpMsg) // OK
{
	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x0E) = lpMsg->Level;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x74) = lpMsg->LevelUpPoint;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x18) = lpMsg->Strength;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x1A) = lpMsg->Dexterity;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x1C) = lpMsg->Vitality;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x1E) = lpMsg->Energy;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x20) = lpMsg->Leadership;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x22) = lpMsg->Life;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x26) = lpMsg->MaxLife;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x24) = lpMsg->Mana;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x28) = lpMsg->MaxMana;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x40) = lpMsg->BP;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x42) = lpMsg->MaxBP;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x2A) = lpMsg->Shield;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x2C) = lpMsg->MaxShield;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x4C) = lpMsg->FruitAddPoint;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x4E) = lpMsg->MaxFruitAddPoint;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x50) = lpMsg->FruitSubPoint;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x52) = lpMsg->MaxFruitSubPoint;

	*(DWORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x10) = lpMsg->Experience;

	*(DWORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x14) = lpMsg->NextExperience;

	//EXTRA
	ViewReset = lpMsg->ViewReset;
	ViewPoint = lpMsg->ViewPoint;
	ViewCurHP = lpMsg->ViewCurHP;
	ViewMaxHP = lpMsg->ViewMaxHP;
	ViewCurMP = lpMsg->ViewCurMP;
	ViewMaxMP = lpMsg->ViewMaxMP;
	ViewCurBP = lpMsg->ViewCurBP;
	ViewMaxBP = lpMsg->ViewMaxBP;
	ViewCurSD = lpMsg->ViewCurSD;
	ViewMaxSD = lpMsg->ViewMaxSD;
	ViewStrength = lpMsg->ViewStrength;
	ViewDexterity = lpMsg->ViewDexterity;
	ViewVitality = lpMsg->ViewVitality;
	ViewEnergy = lpMsg->ViewEnergy;
	ViewLeadership = lpMsg->ViewLeadership;
}

void GCNewCharacterCalcRecv(PMSG_NEW_CHARACTER_CALC_RECV* lpMsg) // OK
{
	ViewCurHP = lpMsg->ViewCurHP;
	ViewMaxHP = lpMsg->ViewMaxHP;
	ViewCurMP = lpMsg->ViewCurMP;
	ViewMaxMP = lpMsg->ViewMaxMP;
	ViewCurBP = lpMsg->ViewCurBP;
	ViewMaxBP = lpMsg->ViewMaxBP;
	ViewCurSD = lpMsg->ViewCurSD;
	ViewMaxSD = lpMsg->ViewMaxSD;
	ViewAddStrength = lpMsg->ViewAddStrength;
	ViewAddDexterity = lpMsg->ViewAddDexterity;
	ViewAddVitality = lpMsg->ViewAddVitality;
	ViewAddEnergy = lpMsg->ViewAddEnergy;
	ViewAddLeadership = lpMsg->ViewAddLeadership;
	ViewPhysiDamageMin = lpMsg->ViewPhysiDamageMin;
	ViewPhysiDamageMax = lpMsg->ViewPhysiDamageMax;
	ViewMagicDamageMin = lpMsg->ViewMagicDamageMin;
	ViewMagicDamageMax = lpMsg->ViewMagicDamageMax;
	ViewCurseDamageMin = lpMsg->ViewCurseDamageMin;
	ViewCurseDamageMax = lpMsg->ViewCurseDamageMax;
	ViewMulPhysiDamage = lpMsg->ViewMulPhysiDamage;
	ViewDivPhysiDamage = lpMsg->ViewDivPhysiDamage;
	ViewMulMagicDamage = lpMsg->ViewMulMagicDamage;
	ViewDivMagicDamage = lpMsg->ViewDivMagicDamage;
	ViewMulCurseDamage = lpMsg->ViewMulCurseDamage;
	ViewDivCurseDamage = lpMsg->ViewDivCurseDamage;
	ViewMagicDamageRate = lpMsg->ViewMagicDamageRate;
	ViewCurseDamageRate = lpMsg->ViewCurseDamageRate;
	ViewPhysiSpeed = lpMsg->ViewPhysiSpeed;
	ViewMagicSpeed = lpMsg->ViewMagicSpeed;
	ViewAttackSuccessRate = lpMsg->ViewAttackSuccessRate;
	ViewAttackSuccessRatePvP = lpMsg->ViewAttackSuccessRatePvP;
	ViewDefense = lpMsg->ViewDefense;
	ViewDefenseSuccessRate = lpMsg->ViewDefenseSuccessRate;
	ViewDefenseSuccessRatePvP = lpMsg->ViewDefenseSuccessRatePvP;
	ViewDamageMultiplier = lpMsg->ViewDamageMultiplier;
	ViewRFDamageMultiplierA = lpMsg->ViewRFDamageMultiplierA;
	ViewRFDamageMultiplierB = lpMsg->ViewRFDamageMultiplierB;
	ViewRFDamageMultiplierC = lpMsg->ViewRFDamageMultiplierC;
	ViewDarkSpiritAttackDamageMin = lpMsg->ViewDarkSpiritAttackDamageMin;
	ViewDarkSpiritAttackDamageMax = lpMsg->ViewDarkSpiritAttackDamageMax;
	ViewDarkSpiritAttackSpeed = lpMsg->ViewDarkSpiritAttackSpeed;
	ViewDarkSpiritAttackSuccessRate = lpMsg->ViewDarkSpiritAttackSuccessRate;
}

void GCNewHealthBarRecv(PMSG_NEW_HEALTH_BAR_RECV* lpMsg) // OK
{
	ClearNewHealthBar();

	for(int n=0;n < lpMsg->count;n++)
	{
		PMSG_NEW_HEALTH_RECV* lpInfo = (PMSG_NEW_HEALTH_RECV*)(((BYTE*)lpMsg)+sizeof(PMSG_NEW_HEALTH_BAR_RECV)+(sizeof(PMSG_NEW_HEALTH_RECV)*n));

		InsertNewHealthBar(lpInfo->index, lpInfo->type, lpInfo->rate, lpInfo->rate2);
	}
}

void GCNewGensBattleInfoRecv(PMSG_NEW_GENS_BATTLE_INFO_RECV* lpMsg) // OK
{
	GensBattleMapCount = lpMsg->GensBattleMapCount;

	GensMoveIndexCount = lpMsg->GensMoveIndexCount;

	memcpy(GensBattleMap,lpMsg->GensBattleMap,sizeof(GensBattleMap));

	memcpy(GensMoveIndex,lpMsg->GensMoveIndex,sizeof(GensMoveIndex));
}

void GCNewMessageRecv(PMSG_NEW_MESSAGE_RECV* lpMsg) // OK
{
	PMSG_NEW_MESSAGE_RECV pMsg;
	pMsg.header.set(0xF3,0xE4,sizeof(pMsg));
	DataSend((BYTE*)&pMsg,sizeof(pMsg));
}


//Cashshop Fix
void OpenCashShopSend(BYTE type)
{
	PMSG_CASH_SHOP_OPEN_RECV pMsg;
	pMsg.OpenType = type;
	pMsg.header.set(0xD2,0x02,sizeof(pMsg));
	DataSend((BYTE*)&pMsg,sizeof(pMsg));
}

bool CashShopSwitchState()
{
	sub_861900_Addr((int)pWindowThis());

	if ( !sub_944E50_Addr() )
		return 0;

	void* v48 = sub_93F370_Addr();

	if ( sub_93FCA0_Addr((int)v48) == 1 )
	{
		if ( !sub_93F600_Addr((CHAR *)sub_93F370_Addr()) )
			return 0;
	}

	if ( sub_93FD10_Addr((int)sub_93F370_Addr()) == 1 )
	{
		if ( sub_93F950_Addr((CHAR *)sub_93F370_Addr()) == 1 )
		{
			BYTE* v53 = (BYTE *)sub_941030_Addr((BYTE*)sub_93F370_Addr());
			int v55 = sub_941000_Addr((BYTE*)sub_93F370_Addr());
			BYTE* v57 = (BYTE *)sub_861900_Addr((int)pWindowThis());
			sub_944FE0_Addr(v57, v55, v53);
		}
	}

	if ( pCheckWindow(pWindowThis(), 65) )
	{
		OpenCashShopSend(1);
		pCloseWindow(pWindowThis(), 65);
	}
	else
	{
		if ( !sub_9406C0_Addr((BYTE*)sub_93F370_Addr()) )
		{
			OpenCashShopSend(0);
			sub_9406A0_Addr((BYTE*)sub_93F370_Addr(), 1);
			char* v62 = (char *)sub_8611E0_Addr((DWORD*)pWindowThis());
			sub_815130_Addr(v62, 0, 1);
		}
	}
}


void DataSend(BYTE* lpMsg,DWORD size) // OK
{
	BYTE EncBuff[2048];

	if(gPacketManager.AddData(lpMsg,size) != 0 && gPacketManager.ExtractPacket(EncBuff) != 0)
	{
		BYTE send[2048];

		memcpy(send,EncBuff,size);

		if(EncBuff[0] == 0xC3 || EncBuff[0] == 0xC4)
		{
			if(EncBuff[0] == 0xC3)
			{
				BYTE save = EncBuff[1];

				EncBuff[1] = (*(BYTE*)(MAIN_PACKET_SERIAL))++;

				size = gPacketManager.Encrypt(&send[2],&EncBuff[1],(size-1))+2;

				EncBuff[1] = save;

				send[0] = 0xC3;
				send[1] = LOBYTE(size);
			}
			else
			{
				BYTE save = EncBuff[2];

				EncBuff[2] = (*(BYTE*)(MAIN_PACKET_SERIAL))++;

				size = gPacketManager.Encrypt(&send[3],&EncBuff[2],(size-2))+3;

				EncBuff[2] = save;

				send[0] = 0xC4;
				send[1] = HIBYTE(size);
				send[2] = LOBYTE(size);
			}
		}

		((void(__thiscall*)(void*,BYTE*,DWORD))0x00405110)((void*)0x08793750,send,size);
	}
}

void GCRecvCoin(PMSG_COIN_RECV* lpMsg) // OK
{
	Coin1 = lpMsg->Coin1;
	Coin2 = lpMsg->Coin2;
	Coin3 = lpMsg->Coin3;
	Ruud = lpMsg->Ruud;
}

void GCBuyConfirmRecv(PMSG_ITEM_BUY_RECV* lpMsg) // OK
{
	gInterface.Data[eCONFIRM_MAIN].OnShow = true;
	pSetCursorFocus = true;
	gInterface.ConfirmSlot = lpMsg->slot;
}




//======================================= lo nuevo
//--post item
bool RecvPostItem(PMSG_POSTITEM * lpMsg) {

	void * item_post = PostItem::AddItem ( &lpMsg->item_data[0] );

	if ( item_post == nullptr ) { return false; }

	char Name[11] = { '\0' };
	char Messase[61] = { '\0' };
	char Messase_API[70] = { '\0' };
	memcpy_s ( &Name[0], 10, &lpMsg->chatid[0], 10 );
	memcpy_s ( &Messase[0], 60, &lpMsg->chatmsg[0], 60 );
	int len = strlen ( Messase );

	
	// ----
	// Cat text Excillent
	if ( ( BYTE ) Messase[0] == 0xC4 &&
			( BYTE ) Messase[1] == 0x90 &&
			( BYTE ) Messase[2] == 0xE1 &&
			( BYTE ) Messase[3] == 0xBB &&
			( BYTE ) Messase[4] == 0x93 &&
			( BYTE ) Messase[5] == 0x20 &&
			( BYTE ) Messase[6] == 0x68 &&
			( BYTE ) Messase[7] == 0x6F &&
			( BYTE ) Messase[8] == 0xC3 &&
			( BYTE ) Messase[9] == 0xA0 &&
			( BYTE ) Messase[10] == 0x6E &&
			( BYTE ) Messase[11] == 0x20 &&
			( BYTE ) Messase[12] == 0x68 &&
			( BYTE ) Messase[13] == 0xE1 &&
			( BYTE ) Messase[14] == 0xBA &&
			( BYTE ) Messase[15] == 0xA3 &&
			( BYTE ) Messase[16] == 0x6F &&
			( BYTE ) Messase[17] == 0x20 ) {
		strcpy_s ( &Messase[0], 61, &Messase[18] );
	}
	// Cat bot ten neu qua dai
	if ( len > 25 ) 
	{
		for ( int i = 20; i < len; ++i ) 
		{
			if ( isalpha ( Messase[i] ) || Messase[i] == ' ' ) 
			{
				Messase[i] = '.';
				Messase[i + 1] = '.';
				Messase[i + 2] = '.';
				Messase[i + 3] = '\0';
			}
		}
	}
	//push this node to eItemNode
	for (int i = 0; i < 19; i++)
	{
		gPostItem.eItemNode[i] = gPostItem.eItemNode[i + 1];
	}
	gPostItem.eItemNode[19] = (DWORD)item_post;
	//end eItemNode
	sprintf_s( Messase_API, "[Bán] %s_[%08X]", Messase, (DWORD)item_post);
	gPostItem.draw_character_head_chat_text_ = true;
	newInterface::DrawChat ( gPostItem.PostItemColor, &Name[0], &Messase_API[0] );
	// ----

	if ( !gPostItem.draw_character_head_chat_text_ ) 
	{ // da lay duoc base_address
		// xu ly doan chat tren dau nhan vat
		char message[256] = { 0 };
		char * chat_text_first = CharacterHeadChatTextFirst ( gPostItem.draw_character_head_chat_text_base_address_ );
		char * chat_text_last = CharacterHeadChatTextLast ( gPostItem.draw_character_head_chat_text_base_address_ );
		unsigned long msgfirst_len = strlen ( chat_text_first );
		unsigned long msglast_len = strlen ( chat_text_last );
		strcpy_s ( message, sizeof ( message ), chat_text_first );
		strcat_s ( message, chat_text_last );
		unsigned long message_len = strlen ( message );

		if ( message[message_len - 1 - 8 - 2] != '_' ||
				message[message_len - 1 - 8 - 1] != '[' ||
				message[message_len - 1] != ']' ) 
		{
		}
		else 
		{
			message[message_len - 1 - 8 - 2] = '\0';  // cat bo doan duoi

			// copy lai
			if ( msgfirst_len ) 
			{
				memcpy_s ( chat_text_first, 0x50, message, msgfirst_len );
				chat_text_first[msgfirst_len] = '\0';
			}

			if ( msglast_len ) 
			{
				memcpy_s ( chat_text_last, 0x50, &message[msgfirst_len], msglast_len );
				chat_text_last[msglast_len] = '\0';
			}
		}
	}
	return true;
}

//--- pet
void GCPetCharSetRecv(PMSG_NEW_PET_CHARSET_RECV* lpMsg)
{
	ClearNewPetCharSet();

	for (int n = 0; n < lpMsg->count; n++)
	{
		NEW_PET_STRUCT* lpInfo = (NEW_PET_STRUCT*)(((BYTE*)lpMsg) + sizeof(PMSG_NEW_PET_CHARSET_RECV)+(sizeof(NEW_PET_STRUCT)*n));

		InsertNewPetCharSet(lpInfo->index, lpInfo->PetCharSet);
	}
}

void GCPetCharSetSelectCharacterRecv(PMSG_NEW_SELECT_CHARACTER_CHARSET_RECV* lpMsg)
{
	ClearNewPetCharSetSelectCharacter();

	for (int n = 0; n < lpMsg->count; n++)
	{
		PMSG_NEW_CHARACTER_CHARSET_RECV* lpInfo = (PMSG_NEW_CHARACTER_CHARSET_RECV*)(((BYTE*)lpMsg) + sizeof(PMSG_NEW_SELECT_CHARACTER_CHARSET_RECV)+(sizeof(PMSG_NEW_CHARACTER_CHARSET_RECV)*n));

		InsertNewPetCharSetSelectCharacter(lpInfo->Name, lpInfo->PetCharSet);
	}
}

void SetChaosBoxState(PMSG_SET_CHAOSBOX_STATE* Data){
	pChaosBoxState = Data->state;
	return;
}


#if(PARTYSEARCH==1)
void GCPartyListRecv(PMSG_RECV_PARTYLIST* lpMsg){
	gPartySearch.ClearPartyList();
	for (int n = 0; n<lpMsg->Count; n++){
		PMSG_PARTYSEARCH_PARTYLIST* lpInfo = (PMSG_PARTYSEARCH_PARTYLIST*)(((BYTE*)lpMsg) + sizeof(PMSG_RECV_PARTYLIST)+(sizeof(PMSG_PARTYSEARCH_PARTYLIST)*n));
		gPartySearch.InsertPartyList(lpInfo);
	}
	gPartySearch.SwitchPartySearchWindowState();
}
#endif
//=======================
//-- RUUD
//=======================

#if(CHIEN_TRUONG_CO)
void GCInfoCTC(INFOCTC_SENDCLIENT* lpMsg) // OK
{
	//if((GetTickCount()-gInterface.Data[eCuaSoCTC].EventTick) > 1000)
	{
		CTC_TimeConLai = lpMsg->TimeConLai;
		CTC_PointKillQuai = lpMsg->PointKillQuai;
		CTC_PartyKillPoint = lpMsg->PartyKillPoint;
		CTC_MonterYeuCau = lpMsg->MonterYeuCau;
		gInterface.Data[eCuaSoCTC].OnShow = lpMsg->TYPE;
		gInterface.Data[eCuaSoCTC].EventTick = GetTickCount();
	}
}

void GCCTCKillMonter(CTCKILL_SENDCLIENT* lpMsg) // OK
{
	CTC_QuaiVatDaKill = lpMsg->QuaiKill;
}
#endif

// Protocol.cpp
// =========== CTC Mini
void GCCTCMiniShowWindow(INFOCTCMINI_SENDCLIENT* lpMsg) // OK
{
	if ((GetTickCount() - gInterface.Data[eCTCMiniWindow].EventTick) > 300)
	{
		gInterface.Data[eCTCMiniWindow].EventTick = GetTickCount();
		gInterface.Data[eCTCMiniWindow].OnShow ^= 1;
	}
	CheckVaoLanhDia = lpMsg->GuildWinOld;
}


void GCCTCMiniKill(CTCMINIKILL_SENDCLIENT* lpMsg) // OK
{
	CTCMINI_TimeCTCMini = lpMsg->TimeCTCMini;
	for (int n = 0; n < 3; n++) //Them Cong
	{
		CTCMINI_Cong[n] = lpMsg->Cong[n];
		CTCMINI_Tru[n] = lpMsg->Tru[n];
	}
}


#if(PKEVENT == 1)
void GCInfoPKEvent(INFOPKEVENT_SENDCLIENT* lpMsg) // OK
{
	PKEvent_TimeConLai = lpMsg->TimeConLaiPKEvent;
}
#endif

#if(TVTEVENT == 1)
void GCInfoTvTEvent(INFOTVTEVENT_SENDCLIENT* lpMsg) // OK
{
	TvTEvent_TimeConLai = lpMsg->TimeConLaiTvTEvent;
}
#endif


#include "Character.h"
//=== Set List Skin Model
void GCSetSkinModelList(BPMSG_CUSTOM_SKIN_SEND* lpMsg)
{
	gInterface.m_SkinModelData.clear();

	for (int i = 0; i < lpMsg->count; i++)
	{
		BCUSTOM_SKINMODEL_DATA* lpInfo = (BCUSTOM_SKINMODEL_DATA*)(((BYTE*)lpMsg) + sizeof(BPMSG_CUSTOM_SKIN_SEND) + (sizeof(BCUSTOM_SKINMODEL_DATA) * i));

		gInterface.m_SkinModelData.push_back(*lpInfo);
		//g_Console.AddMessage(3, "GCSetSkinModelList [%d] %d", lpInfo->SkinIndex, lpInfo->StatusBuy);
	}
	
	//if (gInterface.m_SkinModelData.size())
	//{
	//	if ((GetTickCount() - gInterface.WindowSkin->lastActionTime) >= 1000 && !gInterface.WindowSkin->onShow)
	//	{
	//		gInterface.WindowSkin->onShow ^= 1;
	//		gInterface.WindowSkin->lastActionTime = GetTickCount();
	//	}
	//}
}
void GCSetInfoSkinSelect(BPMSG_CUSTOM_SKIN_SEND* lpMsg)
{
	//SAFE_DELETE(gInterface.m_SkinModelInfoSelect);
	gInterface.m_SkinModelInfoSelect.clear();
	gInterface.SelectInfoSkin = false;
	for (int i = 0; i < lpMsg->count; i++)
	{
		SKIN_MODEL_DATA* lpInfo = (SKIN_MODEL_DATA*)(((BYTE*)lpMsg) + sizeof(BPMSG_CUSTOM_SKIN_SEND) + (sizeof(SKIN_MODEL_DATA) * i));

		gInterface.m_SkinModelInfoSelect.push_back(*lpInfo);
		//SkinSelect = lpInfo->SkinIndex + MODELSKINFIX;

		//gInterface.DrawMessage(3, "GCSetInfoSkinSelect %d [%d] %d",i, gInterface.m_SkinModelInfoSelect[i].Coin, gInterface.m_SkinModelInfoSelect[i].ValueOp[0]);
		gInterface.SelectInfoSkin = true;
	}
	//pDrawMessage("OK INFO", 1);

}
bool CBGetStatusBuySkin(int SkinIndex)
{
	for (int i = 0; i < gInterface.m_SkinModelData.size(); i++)
	{
		if (gInterface.m_SkinModelData[i].SkinIndex == SkinIndex && gInterface.m_SkinModelData[i].StatusBuy)
		{
			return 1;
		}
	}
	return 0;
}

#if (CongHuongV2)
void CH_RecvInfoGSSend(PMSG_GSSendInfoClient* pMsg)
{
	if (pMsg->mCH_IndexItem[0] != -1)
	{
		gInterface.CH_EffectMixOn = 0;
		gInterface.CH_TyLeThanhCong = pMsg->mCH_TyLeThanhCong;
		gInterface.CH_ResetMix = pMsg->mCH_ResetMix;
		gInterface.CH_TypeMix = pMsg->mCH_TypeMix;
		gInterface.CH_CheckLvItem = pMsg->mCH_CheckLvItem;;
		for (int n = 0; n < 3; n++)
		{
			gInterface.CH_IndexItem[n] = pMsg->mCH_IndexItem[n];
			gInterface.CH_CoinMix[n] = pMsg->mCH_CoinMix[n];
			memset(gInterface.CH_InfoItem[n], 0x0, sizeof(gInterface.CH_InfoItem[n]));
			memcpy(gInterface.CH_InfoItem[n], pMsg->mCH_InfoItem[n], sizeof(gInterface.CH_InfoItem[n]));
		}
	}
	else {
		gInterface.m_ScrollPos = 0;

		gInterface.CH_EffectMixOn = 0;
		gInterface.CH_TyLeThanhCong = -1;
		gInterface.CH_ResetMix = -1;
		gInterface.CH_TypeMix = -1;
		gInterface.CH_CheckLvItem = 0;
		for (int n = 0; n < 3; n++)
		{
			gInterface.CH_IndexItem[n] = -1;
			gInterface.CH_CoinMix[n] = -1;
			ZeroMemory(gInterface.CH_InfoItem[n], sizeof(gInterface.CH_InfoItem[n]));
		}
	}
}
#endif


