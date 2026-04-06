// MemScript.h: interface for the CMemScript class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MEMSCRIPT_H__E3834663_DE4A_411E_AF81_38D54EE84216__INCLUDED_)
#define AFX_MEMSCRIPT_H__E3834663_DE4A_411E_AF81_38D54EE84216__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMemScript2
{
public:
	CMemScript2();
	virtual ~CMemScript2();

	bool SetBuffer(char* filename);
	void GetWzAgInfo(char* buff, DWORD* size);
	int GetChar();
	void UnGetChar(int ch);
	int GetToken();
	int GetNumber();
	int GetAsNumber();
	float GetFloat();
	float GetAsFloat();
	char* GetString();
	char* GetAsString();
private:
	char* m_buff;
	DWORD m_size;
	int m_count;
	float m_number;
	char m_string[1024];
	DWORD m_tick;

};

#endif // !defined(AFX_MEMSCRIPT_H__E3834663_DE4A_411E_AF81_38D54EE84216__INCLUDED_)
