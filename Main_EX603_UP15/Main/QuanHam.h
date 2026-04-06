#pragma once
#include "Import.h"
#include "Interface.h"
#include "Protocol.h"

#if(QUAN_HAM_NEW == 1)

struct BUY_QUAN_HAM_REQ
{
	PSBMSG_HEAD h;
	int			Number;
};

//-----------------------------------------------------------------------------------------------------------------------------------------------------
class BEXO_QUAN_HAM
{
public:
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	BEXO_QUAN_HAM();
	void DRAW_QUAN_HAM();
	bool HIENTHIQUAN_HAM;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	int TRANG_QUAN_HAM;
	void BEXO_CLICK_TRANG_QUAN_HAM(DWORD ClickMouse);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	float MainWidth;
	float MainHeight;
	float StartY;
	float StartX;
	DWORD ClickTick;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	void		OPEN_WINDOW_QUAN_HAM() { gInterface.Data[EXBEXO_QUAN_HAM_MAIN].OnShow = true; pSetCursorFocus = true; };
	void		CLOSE_WINDOW_QUAN_HAM() { gInterface.Data[EXBEXO_QUAN_HAM_MAIN].OnShow = false; pSetCursorFocus = false; };
	bool		CHECK_WINDOW_QUAN_HAM() { return gInterface.Data[EXBEXO_QUAN_HAM_MAIN].OnShow; };

	void		DRAW_WINDOW_QUAN_HAM();

	bool		MAIN_QUAN_HAM(DWORD Event);
	bool		CLOSE_QUAN_HAM(DWORD Event);

	void BUY_QUAN_HAM(int Number);

	//-----------------------------------------------------------------------------------------------------------------------------------------------------
}; extern BEXO_QUAN_HAM G_BEXO_QUAN_HAM;
//===================================================================================================================================================================

#endif