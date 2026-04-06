#pragma once

class CStreamPacketEngine
{
public:
	CStreamPacketEngine(void);
	virtual ~CStreamPacketEngine(void);

	void Init(BYTE byType, BYTE byHeadCode);
	void Rightshift1(BYTE bits);
	void Rightshift2(DWORD bits);
	void Rightshift3(INT bits);
	void Leftshift(BYTE bits);
	void AddData(void *pSrc, WORD wSize, BOOL bXor = TRUE);
	void Send(BOOL bEncrypt = FALSE, BOOL bForceC4 = FALSE);
private:
	BYTE* thisa;
};
