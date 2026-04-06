#pragma once
#include "Interface.h"

class ThongTinDonate
{
public:
	ThongTinDonate();
	~ThongTinDonate();
	void Load();
	//--
	void ThongTinDonateOpen();
	void OpenThongTinDonateOK() { gInterface.Data[eThongTinDonnate].OnShow = true; };
	//--

}; extern ThongTinDonate gThongTinDonate;
