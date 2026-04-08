#include "stdafx.h"
#include "AutoSubRestart.h"
#include "SocketManager.h"
#include "ServerInfo.h"
#include "User.h"
#include "Log.h"
#include "Util.h"

CAutoSubRestart gAutoSubRestart;

CAutoSubRestart::CAutoSubRestart()
{
	this->m_Enable = 0;
	this->m_Hour = 0;
	this->m_Minute = 0;
	this->m_CloseSeconds = 10;

	this->m_Monday = 0;
	this->m_Tuesday = 0;
	this->m_Wednesday = 0;
	this->m_Thursday = 0;
	this->m_Friday = 0;
	this->m_Saturday = 0;
	this->m_Sunday = 0;

	this->m_RestartState = 0;
	this->m_ReopenTick = 0;
	this->m_LastTriggerDate = 0;
	this->m_LastTriggerMinute = -1;
}

void CAutoSubRestart::Load()
{
	char path[MAX_PATH] = { 0 };
	GetModuleFileNameA(0, path, MAX_PATH);

	char* pos = strrchr(path, '\\');
	if (pos != 0)
	{
		*(pos + 1) = 0;
	}
	strcat_s(path, "config.ini");

	this->m_Enable       = GetPrivateProfileIntA("AutoSubRestart", "Enable", 0, path);
	this->m_Hour         = GetPrivateProfileIntA("AutoSubRestart", "Hour", 0, path);
	this->m_Minute       = GetPrivateProfileIntA("AutoSubRestart", "Minute", 0, path);
	this->m_CloseSeconds = GetPrivateProfileIntA("AutoSubRestart", "CloseSeconds", 10, path);

	this->m_Monday    = GetPrivateProfileIntA("AutoSubRestart", "T2", 0, path);
	this->m_Tuesday   = GetPrivateProfileIntA("AutoSubRestart", "T3", 0, path);
	this->m_Wednesday = GetPrivateProfileIntA("AutoSubRestart", "T4", 0, path);
	this->m_Thursday  = GetPrivateProfileIntA("AutoSubRestart", "T5", 0, path);
	this->m_Friday    = GetPrivateProfileIntA("AutoSubRestart", "T6", 0, path);
	this->m_Saturday  = GetPrivateProfileIntA("AutoSubRestart", "T7", 0, path);
	this->m_Sunday    = GetPrivateProfileIntA("AutoSubRestart", "CN", 0, path);

	if (this->m_CloseSeconds < 1)
	{
		this->m_CloseSeconds = 1;
	}

	LogAdd(LOG_BLUE,
		"[AutoSubRestart] Load OK | Enable=%d | Time=%02d:%02d | CloseSeconds=%d | T2=%d T3=%d T4=%d T5=%d T6=%d T7=%d CN=%d",
		this->m_Enable,
		this->m_Hour,
		this->m_Minute,
		this->m_CloseSeconds,
		this->m_Monday,
		this->m_Tuesday,
		this->m_Wednesday,
		this->m_Thursday,
		this->m_Friday,
		this->m_Saturday,
		this->m_Sunday);
}

bool CAutoSubRestart::IsEnabledDay(int wday)
{
	// SYSTEMTIME.wDayOfWeek: 0=CN, 1=T2, 2=T3, 3=T4, 4=T5, 5=T6, 6=T7
	switch (wday)
	{
	case 0: return (this->m_Sunday != 0);
	case 1: return (this->m_Monday != 0);
	case 2: return (this->m_Tuesday != 0);
	case 3: return (this->m_Wednesday != 0);
	case 4: return (this->m_Thursday != 0);
	case 5: return (this->m_Friday != 0);
	case 6: return (this->m_Saturday != 0);
	}

	return false;
}

bool CAutoSubRestart::IsScheduleMatched(const SYSTEMTIME& st)
{
	if (this->m_Enable == 0)
	{
		return false;
	}

	if (this->IsEnabledDay(st.wDayOfWeek) == false)
	{
		return false;
	}

	if (st.wHour != this->m_Hour || st.wMinute != this->m_Minute)
	{
		return false;
	}

	return true;
}

void CAutoSubRestart::StartRestartSequence()
{
	LogAdd(LOG_RED, "[AutoSubRestart] Start restart sequence");

	gObjAllLogOut();
	gObjAllDisconnect();

	gSocketManager.Clean();

	this->m_RestartState = 1;
	this->m_ReopenTick = GetTickCount() + (this->m_CloseSeconds * 1000);

	LogAdd(LOG_RED, "[AutoSubRestart] Sub closed for %d second(s)", this->m_CloseSeconds);
}

void CAutoSubRestart::ProcessRestartSequence()
{
	if (this->m_RestartState != 1)
	{
		return;
	}

	if ((DWORD)GetTickCount() < this->m_ReopenTick)
	{
		return;
	}

	if (gSocketManager.Start((WORD)gServerInfo.m_ServerPort) == 0)
	{
		LogAdd(LOG_RED, "[AutoSubRestart] Reopen sub FAILED on port %d", gServerInfo.m_ServerPort);
		return;
	}

	LogAdd(LOG_BLUE, "[AutoSubRestart] Reopen sub SUCCESS on port %d", gServerInfo.m_ServerPort);

	this->m_RestartState = 0;
	this->m_ReopenTick = 0;
}

void CAutoSubRestart::Run()
{
	if (this->m_Enable == 0)
	{
		return;
	}

	this->ProcessRestartSequence();

	if (this->m_RestartState != 0)
	{
		return;
	}

	SYSTEMTIME st;
	GetLocalTime(&st);

	int today = (st.wYear * 10000) + (st.wMonth * 100) + st.wDay;
	int hhmm = (st.wHour * 100) + st.wMinute;

	if (this->IsScheduleMatched(st) == false)
	{
		return;
	}

	if (this->m_LastTriggerDate == today && this->m_LastTriggerMinute == hhmm)
	{
		return;
	}

	this->m_LastTriggerDate = today;
	this->m_LastTriggerMinute = hhmm;

	this->StartRestartSequence();
}