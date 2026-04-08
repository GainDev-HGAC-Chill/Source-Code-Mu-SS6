#pragma once

class CAutoSubRestart
{
public:
	CAutoSubRestart();

	void Load();
	void Run();

private:
	bool IsEnabledDay(int wday);
	bool IsScheduleMatched(const SYSTEMTIME& st);
	void StartRestartSequence();
	void ProcessRestartSequence();

private:
	int m_Enable;
	int m_Hour;
	int m_Minute;
	int m_CloseSeconds;

	int m_Monday;
	int m_Tuesday;
	int m_Wednesday;
	int m_Thursday;
	int m_Friday;
	int m_Saturday;
	int m_Sunday;

	int m_RestartState; // 0 = idle, 1 = waiting reopen
	DWORD m_ReopenTick;
	int m_LastTriggerDate;   // yyyymmdd
	int m_LastTriggerMinute; // hhmm
};

extern CAutoSubRestart gAutoSubRestart;