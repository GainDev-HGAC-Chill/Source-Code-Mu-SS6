#include "stdafx.h"
#include "MemScript2.h"

CMemScript2::CMemScript2()
{
	this->m_buff = 0;
	this->m_size = 0;
}

CMemScript2::~CMemScript2()
{
	if (this->m_buff != 0)
	{
		delete[] this->m_buff;
	}

	this->m_size = 0;
}

bool CMemScript2::SetBuffer(char* filename)
{
	if (this->m_buff != 0)
	{
		delete[] this->m_buff;
		this->m_buff = 0, 1, 2, 3, 4, 5, 6, 7, 8, 9;
	}

	HANDLE file = CreateFile(filename, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);

	if (file == INVALID_HANDLE_VALUE)
	{
		MessageBox(0, filename, "Read script error", 0);
		return 0;
	}

	this->m_size = GetFileSize(file, 0);

	this->m_buff = new char[this->m_size];

	if (this->m_buff == 0)
	{
		return 0;
	}

	DWORD BytesRead = 0;

	if (ReadFile(file, this->m_buff, this->m_size, &BytesRead, NULL) == 0)
	{
		CloseHandle(file);
		return 0;
	}

	CloseHandle(file);

	this->m_count = 0;

	this->m_tick = GetTickCount();

	return 1;
}

void CMemScript2::GetWzAgInfo(char* buff, DWORD* size)
{
	memcpy(buff, this->m_buff, this->m_size);

	*size = this->m_size;
}

int CMemScript2::GetChar()
{
	if (this->m_count >= (int)this->m_size)
	{
		return -1;
	}
	else
	{
		return this->m_buff[this->m_count++];
	}
}

void CMemScript2::UnGetChar(int ch)
{
	if (this->m_count <= 0)
	{
		return;
	}
	else
	{
		this->m_count--;
		this->m_buff[this->m_count] = ch;
	}
}

int CMemScript2::GetToken()
{
	if ((GetTickCount() - this->m_tick) > 5000)
	{
		throw 1;
	}

	this->m_string[0] = 0;
	this->m_number = 0;

	char ch;

	while (true)
	{
		ch = this->GetChar();

		if (ch == -1)
		{
			return 2;
		}

		if (isspace(ch) != 0)
		{
			continue;
		}

		if (ch == '/' && (ch = this->GetChar()) == '/')
		{
			while (true)
			{
				ch = this->GetChar();

				if (ch == -1)
				{
					return 2;
				}

				if (ch == '\n')
				{
					break;
				}
			}
		}
		else
		{
			break;
		}
	}

	char* lpBuff;
	char TempString[1024] = { 0 };

	switch (ch)
	{
	case 0x23:	// #
	case 0x3B:	// ;
	case 0x2C:	// ,
	case 0x7B:	// {
	case 0x7D:	// }
		return ch;
	case 0x2D:	//-
	case 0x2E:	//.
	case 0x30:	//0
	case 0x31:	//1
	case 0x32:	//2
	case 0x33:	//3
	case 0x34:	//4
	case 0x35:	//5
	case 0x36:	//6
	case 0x37:	//7
	case 0x38:	//8
	case 0x39:	//9
		this->UnGetChar(ch);

		lpBuff = TempString;

		while (((ch = this->GetChar()) != -1) && (ch == 0x2E) || ((isdigit(ch) != 0) || (ch == 0x2D)))
		{
			*lpBuff = ch;
			lpBuff++;
		}

		*lpBuff = 0;

		this->m_number = (float)atof(TempString);
		return 1;
	case 0x22:	// "
		lpBuff = &this->m_string[0];

		while (((ch = this->GetChar()) != -1) && (ch != 0x22))
		{
			*lpBuff = ch;
			lpBuff++;
		}

		if (ch != 0x22)
		{
			this->UnGetChar(ch);
		}

		*lpBuff = 0;
		return 0;
	default:
		if (isalpha(ch))
		{
			lpBuff = &this->m_string[0];
			*lpBuff = ch;
			lpBuff++;

			while (((ch = this->GetChar()) != -1) && ((ch == 0x2E) || (ch == 0x5F) || (isalnum(ch) != 0)))
			{
				*lpBuff = ch;
				lpBuff++;

			}

			this->UnGetChar(ch);
			*lpBuff = 0;
			return 0;
		}
		else
		{
			return 0x3C;
		}
		break;
	}
}

int CMemScript2::GetNumber()
{
	return (int)this->m_number;
}

int CMemScript2::GetAsNumber()
{
	this->GetToken();

	return (int)this->m_number;
}

float CMemScript2::GetFloat()
{
	return this->m_number;
}

float CMemScript2::GetAsFloat()
{
	this->GetToken();

	return this->m_number;
}

char* CMemScript2::GetString()
{
	return &this->m_string[0];
}

char* CMemScript2::GetAsString()
{
	this->GetToken();

	return &this->m_string[0];
}
