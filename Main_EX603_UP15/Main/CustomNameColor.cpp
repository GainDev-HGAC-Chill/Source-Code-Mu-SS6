#include "stdafx.h"
#include "Item.h"
#include "TMemory.h"
#include "Import.h"
#include "CustomNameColor.h"
#include "ToolKit.h"
#include "Defines.h"
//--
CustomNameColor gCustomNameColor;
//--
DWORD DivineWeapon_Buff=0;
DWORD DivineWeapon_Pointer=0;
DWORD DropColorProtect;
DWORD DropColorPointer;

void CustomNameColor::Load()
{
	SetRange((LPVOID)0x007E7827,4,ASM::NOP);
	SetOp((LPVOID)0x007E7827,(LPVOID) this->DivineWeapon,ASM::JMP);
	//--
	SetRange((LPVOID)0x005F479E,10,ASM::NOP);
	SetOp((LPVOID)0x005F479E,(LPVOID) this->DropColor,ASM::JMP);
}

Naked(CustomNameColor::DivineWeapon)
{
	static DWORD DivineWeaponAdress1=0x007E785F;
	static DWORD DivineWeaponAdress2=0x007E7866;
	_asm
	{
		Mov DivineWeapon_Buff,Edx
		MOVSX EDX,WORD PTR SS:[EBP+0x8]
		mov DWORD PTR SS:[EBP+0x8],Edx
		mov DivineWeapon_Pointer,Edx
		Mov Edx,DivineWeapon_Buff
	}
	if(DivineWeapon_Pointer==0x13
		||DivineWeapon_Pointer==0x812
		||DivineWeapon_Pointer==0x0A0A
		||DivineWeapon_Pointer==0x40D
		||DivineWeapon_Pointer==0x0A24
		//--
		||DivineWeapon_Pointer==ITEM(0,60) //Vuốt Thiên Tử 
		||DivineWeapon_Pointer==ITEM(0,61) //Vuốt Thiên Tử (Cấp 2)
		|| DivineWeapon_Pointer == ITEM(0, 85) //Vuốt Thiên Tử (Cấp 2)
		|| DivineWeapon_Pointer == ITEM(0, 86) //Vuốt Thiên Tử (Cấp 2)

		||DivineWeapon_Pointer==ITEM(2,25) //Trượng Thiên Tử (Cấp 2)
		|| DivineWeapon_Pointer == ITEM(2, 44) //Trượng Thiên Tử (Cấp 2)

		|| DivineWeapon_Pointer == ITEM(3, 26) //Đao Thiên Tử (Cấp 2)
		|| DivineWeapon_Pointer == ITEM(3, 27) //Đao Thiên Tử (Cấp 2)
		|| DivineWeapon_Pointer == ITEM(3, 31) //Đao Thiên Tử (Cấp 3)

		||DivineWeapon_Pointer==ITEM(5,49) //Gậy Hỏa Long (Cấp 2)
		||DivineWeapon_Pointer==ITEM(4,30) //Nỏ Hỏa Long (Cấp 2)
		|| DivineWeapon_Pointer == ITEM(4, 44) //Nỏ Hỏa Long (Cấp 2)

		||DivineWeapon_Pointer==ITEM(0,51) //Thiên Tử Kiếm (Cấp 2)
		||DivineWeapon_Pointer==ITEM(5,50) //Gậy Thiên Nữ (Cấp 2)
		||DivineWeapon_Pointer == ITEM(5, 66) //Gậy Thiên Nữ (Cấp 2)
		|| DivineWeapon_Pointer == ITEM(5, 67) //Gậy Thiên Nữ (Cấp 2)


		|| DivineWeapon_Pointer == ITEM(0, 100) //"Gậy Rồng VIP (1)"	
		|| DivineWeapon_Pointer == ITEM(0, 101) //"Gậy Rồng VIP (2)"	
		|| DivineWeapon_Pointer == ITEM(0, 102) //"Gậy Rồng VIP (3)"	
		|| DivineWeapon_Pointer == ITEM(0, 103) //"Gậy Rồng VIP (4)"	
		|| DivineWeapon_Pointer == ITEM(0, 104) //"Gậy Rồng VIP (5)"	
		|| DivineWeapon_Pointer == ITEM(0, 105) //"Gậy Rồng VIP (6)"	
		|| DivineWeapon_Pointer == ITEM(0, 106) //"Gậy Rồng VIP (7)"	
		|| DivineWeapon_Pointer == ITEM(0, 107) //"Gậy Rồng VIP (8)"	
		|| DivineWeapon_Pointer == ITEM(0, 108) //"Gậy Rồng VIP (9)"	
		|| DivineWeapon_Pointer == ITEM(0, 109) //"Gậy Rồng VIP (10)"	
		|| DivineWeapon_Pointer == ITEM(0, 110) //"Gậy Rồng VIP (11)"	
		|| DivineWeapon_Pointer == ITEM(0, 111) //"Gậy Rồng VIP (12)"	
		|| DivineWeapon_Pointer == ITEM(0, 112) //"Gậy Rồng VIP (13)"	
		|| DivineWeapon_Pointer == ITEM(0, 113) //"Gậy Rồng VIP (14)"	
		|| DivineWeapon_Pointer == ITEM(0, 114) //"Gậy Rồng VIP (15)"	

	
		|| DivineWeapon_Pointer == ITEM(1, 100) //"Gậy Rồng VIP (1)"	
		|| DivineWeapon_Pointer == ITEM(1, 101) //"Gậy Rồng VIP (2)"	
		|| DivineWeapon_Pointer == ITEM(1, 102) //"Gậy Rồng VIP (3)"	
		|| DivineWeapon_Pointer == ITEM(1, 103) //"Gậy Rồng VIP (4)"	
		|| DivineWeapon_Pointer == ITEM(1, 104) //"Gậy Rồng VIP (5)"	
		|| DivineWeapon_Pointer == ITEM(1, 105) //"Gậy Rồng VIP (6)"	
		|| DivineWeapon_Pointer == ITEM(1, 106) //"Gậy Rồng VIP (7)"	
		|| DivineWeapon_Pointer == ITEM(1, 107) //"Gậy Rồng VIP (8)"	
		|| DivineWeapon_Pointer == ITEM(1, 108) //"Gậy Rồng VIP (9)"	
		|| DivineWeapon_Pointer == ITEM(1, 109) //"Gậy Rồng VIP (10)"	
		|| DivineWeapon_Pointer == ITEM(1, 110) //"Gậy Rồng VIP (11)"	
		|| DivineWeapon_Pointer == ITEM(1, 111) //"Gậy Rồng VIP (12)"	
		|| DivineWeapon_Pointer == ITEM(1, 112) //"Gậy Rồng VIP (13)"	
		|| DivineWeapon_Pointer == ITEM(1, 113) //"Gậy Rồng VIP (14)"	
		|| DivineWeapon_Pointer == ITEM(1, 114) //"Gậy Rồng VIP (15)"	
	
	
		|| DivineWeapon_Pointer == ITEM(2, 100) //"Gậy Rồng VIP (1)"	
		|| DivineWeapon_Pointer == ITEM(2, 101) //"Gậy Rồng VIP (2)"	
		|| DivineWeapon_Pointer == ITEM(2, 102) //"Gậy Rồng VIP (3)"	
		|| DivineWeapon_Pointer == ITEM(2, 103) //"Gậy Rồng VIP (4)"	
		|| DivineWeapon_Pointer == ITEM(2, 104) //"Gậy Rồng VIP (5)"	
		|| DivineWeapon_Pointer == ITEM(2, 105) //"Gậy Rồng VIP (6)"	
		|| DivineWeapon_Pointer == ITEM(2, 106) //"Gậy Rồng VIP (7)"	
		|| DivineWeapon_Pointer == ITEM(2, 107) //"Gậy Rồng VIP (8)"	
		|| DivineWeapon_Pointer == ITEM(2, 108) //"Gậy Rồng VIP (9)"	
		|| DivineWeapon_Pointer == ITEM(2, 109) //"Gậy Rồng VIP (10)"	
		|| DivineWeapon_Pointer == ITEM(2, 110) //"Gậy Rồng VIP (11)"	
		|| DivineWeapon_Pointer == ITEM(2, 111) //"Gậy Rồng VIP (12)"	
		|| DivineWeapon_Pointer == ITEM(2, 112) //"Gậy Rồng VIP (13)"	
		|| DivineWeapon_Pointer == ITEM(2, 113) //"Gậy Rồng VIP (14)"	
		|| DivineWeapon_Pointer == ITEM(2, 114) //"Gậy Rồng VIP (15)"		
	
	
		|| DivineWeapon_Pointer == ITEM(3, 100) //"Gậy Rồng VIP (1)"	
		|| DivineWeapon_Pointer == ITEM(3, 101) //"Gậy Rồng VIP (2)"	
		|| DivineWeapon_Pointer == ITEM(3, 102) //"Gậy Rồng VIP (3)"	
		|| DivineWeapon_Pointer == ITEM(3, 103) //"Gậy Rồng VIP (4)"	
		|| DivineWeapon_Pointer == ITEM(3, 104) //"Gậy Rồng VIP (5)"	
		|| DivineWeapon_Pointer == ITEM(3, 105) //"Gậy Rồng VIP (6)"	
		|| DivineWeapon_Pointer == ITEM(3, 106) //"Gậy Rồng VIP (7)"	
		|| DivineWeapon_Pointer == ITEM(3, 107) //"Gậy Rồng VIP (8)"	
		|| DivineWeapon_Pointer == ITEM(3, 108) //"Gậy Rồng VIP (9)"	
		|| DivineWeapon_Pointer == ITEM(3, 109) //"Gậy Rồng VIP (10)"	
		|| DivineWeapon_Pointer == ITEM(3, 110) //"Gậy Rồng VIP (11)"	
		|| DivineWeapon_Pointer == ITEM(3, 111) //"Gậy Rồng VIP (12)"	
		|| DivineWeapon_Pointer == ITEM(3, 112) //"Gậy Rồng VIP (13)"	
		|| DivineWeapon_Pointer == ITEM(3, 113) //"Gậy Rồng VIP (14)"	
		|| DivineWeapon_Pointer == ITEM(3, 114) //"Gậy Rồng VIP (15)"	
	
		|| DivineWeapon_Pointer == ITEM(4, 100) //"Gậy Rồng VIP (1)"	
		|| DivineWeapon_Pointer == ITEM(4, 101) //"Gậy Rồng VIP (2)"	
		|| DivineWeapon_Pointer == ITEM(4, 102) //"Gậy Rồng VIP (3)"	
		|| DivineWeapon_Pointer == ITEM(4, 103) //"Gậy Rồng VIP (4)"	
		|| DivineWeapon_Pointer == ITEM(4, 104) //"Gậy Rồng VIP (5)"	
		|| DivineWeapon_Pointer == ITEM(4, 105) //"Gậy Rồng VIP (6)"	
		|| DivineWeapon_Pointer == ITEM(4, 106) //"Gậy Rồng VIP (7)"	
		|| DivineWeapon_Pointer == ITEM(4, 107) //"Gậy Rồng VIP (8)"	
		|| DivineWeapon_Pointer == ITEM(4, 108) //"Gậy Rồng VIP (9)"	
		|| DivineWeapon_Pointer == ITEM(4, 109) //"Gậy Rồng VIP (10)"	
		|| DivineWeapon_Pointer == ITEM(4, 110) //"Gậy Rồng VIP (11)"	
		|| DivineWeapon_Pointer == ITEM(4, 111) //"Gậy Rồng VIP (12)"	
		|| DivineWeapon_Pointer == ITEM(4, 112) //"Gậy Rồng VIP (13)"	
		|| DivineWeapon_Pointer == ITEM(4, 113) //"Gậy Rồng VIP (14)"	
		|| DivineWeapon_Pointer == ITEM(4, 114) //"Gậy Rồng VIP (15)"	
	
	
		|| DivineWeapon_Pointer == ITEM(5, 100) //"Gậy Rồng VIP (1)"	
		|| DivineWeapon_Pointer == ITEM(5, 101) //"Gậy Rồng VIP (2)"	
		|| DivineWeapon_Pointer == ITEM(5, 102) //"Gậy Rồng VIP (3)"	
		|| DivineWeapon_Pointer == ITEM(5, 103) //"Gậy Rồng VIP (4)"	
		|| DivineWeapon_Pointer == ITEM(5, 104) //"Gậy Rồng VIP (5)"	
		|| DivineWeapon_Pointer == ITEM(5, 105) //"Gậy Rồng VIP (6)"	
		|| DivineWeapon_Pointer == ITEM(5, 106) //"Gậy Rồng VIP (7)"	
		|| DivineWeapon_Pointer == ITEM(5, 107) //"Gậy Rồng VIP (8)"	
		|| DivineWeapon_Pointer == ITEM(5, 108) //"Gậy Rồng VIP (9)"	
		|| DivineWeapon_Pointer == ITEM(5, 109) //"Gậy Rồng VIP (10)"	
		|| DivineWeapon_Pointer == ITEM(5, 110) //"Gậy Rồng VIP (11)"	
		|| DivineWeapon_Pointer == ITEM(5, 111) //"Gậy Rồng VIP (12)"	
		|| DivineWeapon_Pointer == ITEM(5, 112) //"Gậy Rồng VIP (13)"	
		|| DivineWeapon_Pointer == ITEM(5, 113) //"Gậy Rồng VIP (14)"	
		|| DivineWeapon_Pointer == ITEM(5, 114) //"Gậy Rồng VIP (15)"	
	
		|| DivineWeapon_Pointer == ITEM(6, 100) //"Gậy Rồng VIP (1)"	
		|| DivineWeapon_Pointer == ITEM(6, 101) //"Gậy Rồng VIP (2)"	
		|| DivineWeapon_Pointer == ITEM(6, 102) //"Gậy Rồng VIP (3)"	
		|| DivineWeapon_Pointer == ITEM(6, 103) //"Gậy Rồng VIP (4)"	
		|| DivineWeapon_Pointer == ITEM(6, 104) //"Gậy Rồng VIP (5)"	
		|| DivineWeapon_Pointer == ITEM(6, 105) //"Gậy Rồng VIP (6)"	
		|| DivineWeapon_Pointer == ITEM(6, 106) //"Gậy Rồng VIP (7)"	
		|| DivineWeapon_Pointer == ITEM(6, 107) //"Gậy Rồng VIP (8)"	
		|| DivineWeapon_Pointer == ITEM(6, 108) //"Gậy Rồng VIP (9)"	
		|| DivineWeapon_Pointer == ITEM(6, 109) //"Gậy Rồng VIP (10)"	
		|| DivineWeapon_Pointer == ITEM(6, 110) //"Gậy Rồng VIP (11)"	
		|| DivineWeapon_Pointer == ITEM(6, 111) //"Gậy Rồng VIP (12)"	
		|| DivineWeapon_Pointer == ITEM(6, 112) //"Gậy Rồng VIP (13)"	
		|| DivineWeapon_Pointer == ITEM(6, 113) //"Gậy Rồng VIP (14)"	
		|| DivineWeapon_Pointer == ITEM(6, 114) //"Gậy Rồng VIP (15)"	









		//--
		)
	{
		_asm{Jmp DivineWeaponAdress1}
	}
	else
	{
		_asm{Jmp DivineWeaponAdress2}
	}
}


Naked(CustomNameColor::DropColor)
{
	_asm
	{
		Mov DropColorProtect,Eax
		MOV EDX,DWORD PTR SS:[EBP-0x18]
		Mov Eax,DWORD PTR DS:[EDX+0x30]
		Mov DropColorPointer,Eax
		Mov Eax,DropColorProtect
	}
	if(DropColorPointer==0x253B)
	{
		_asm{
			Mov DropColorPointer,0x005F47AA//Cam
			Jmp DropColorPointer
		}
	}
	else if(
		
			DropColorPointer==ITEM2(0,60) //Vuốt Thiên Tử 
		  ||DropColorPointer==ITEM2(0,61)//Vuốt Thiên Tử (Cấp 2)
		  || DropColorPointer == ITEM2(0, 85)//Vuốt Thiên Tử (Cấp 2)
		  || DropColorPointer == ITEM2(0, 86)//Vuốt Thiên Tử (Cấp 2)

		  ||DropColorPointer==ITEM2(2,25)//Trượng Thiên Tử (Cấp 2)
		  || DropColorPointer == ITEM2(2, 44)//Trượng Thiên Tử (Cấp 2)

		  || DropColorPointer == ITEM2(3, 26)//Đao Thiên Tử (Cấp 2)
		  || DropColorPointer == ITEM2(3, 27)//Đao Thiên Tử (Cấp 2)
		  || DropColorPointer == ITEM2(3, 31)//Đao Thiên Tử (Cấp 2)

		  ||DropColorPointer==ITEM2(5,49)//Gậy Hỏa Long (Cấp 2)
		  ||DropColorPointer==ITEM2(4,30)//Nỏ Hỏa Long (Cấp 2)
		  || DropColorPointer == ITEM2(4, 44)//Nỏ Hỏa Long (Cấp 2)

		  ||DropColorPointer==ITEM2(0,51)//Thiên Tử Kiếm (Cấp 2)
		  ||DropColorPointer==ITEM2(5,50)//Gậy Thiên Nữ (Cấp 2)
		  || DropColorPointer == ITEM2(5, 66)//Gậy Thiên Nữ (Cấp 2)
		  || DropColorPointer == ITEM2(5, 67)//Gậy Thiên Nữ (Cấp 2)

		  || DropColorPointer == ITEM2(0, 100) //"Gậy Rồng VIP (1)"	
		  || DropColorPointer == ITEM2(0, 101) //"Gậy Rồng VIP (2)"	
		  || DropColorPointer == ITEM2(0, 102) //"Gậy Rồng VIP (3)"	
		  || DropColorPointer == ITEM2(0, 103) //"Gậy Rồng VIP (4)"	
		  || DropColorPointer == ITEM2(0, 104) //"Gậy Rồng VIP (5)"	
		  || DropColorPointer == ITEM2(0, 105) //"Gậy Rồng VIP (6)"	
		  || DropColorPointer == ITEM2(0, 106) //"Gậy Rồng VIP (7)"	
		  || DropColorPointer == ITEM2(0, 107) //"Gậy Rồng VIP (8)"	
		  || DropColorPointer == ITEM2(0, 108) //"Gậy Rồng VIP (9)"	
		  || DropColorPointer == ITEM2(0, 109) //"Gậy Rồng VIP (10)"	
		  || DropColorPointer == ITEM2(0, 110) //"Gậy Rồng VIP (11)"	
		  || DropColorPointer == ITEM2(0, 111) //"Gậy Rồng VIP (12)"	
		  || DropColorPointer == ITEM2(0, 112) //"Gậy Rồng VIP (13)"	
		  || DropColorPointer == ITEM2(0, 113) //"Gậy Rồng VIP (14)"	
		  || DropColorPointer == ITEM2(0, 114) //"Gậy Rồng VIP (15)"	


		  || DropColorPointer == ITEM2(1, 100) //"Gậy Rồng VIP (1)"	
		  || DropColorPointer == ITEM2(1, 101) //"Gậy Rồng VIP (2)"	
		  || DropColorPointer == ITEM2(1, 102) //"Gậy Rồng VIP (3)"	
		  || DropColorPointer == ITEM2(1, 103) //"Gậy Rồng VIP (4)"	
		  || DropColorPointer == ITEM2(1, 104) //"Gậy Rồng VIP (5)"	
		  || DropColorPointer == ITEM2(1, 105) //"Gậy Rồng VIP (6)"	
		  || DropColorPointer == ITEM2(1, 106) //"Gậy Rồng VIP (7)"	
		  || DropColorPointer == ITEM2(1, 107) //"Gậy Rồng VIP (8)"	
		  || DropColorPointer == ITEM2(1, 108) //"Gậy Rồng VIP (9)"	
		  || DropColorPointer == ITEM2(1, 109) //"Gậy Rồng VIP (10)"	
		  || DropColorPointer == ITEM2(1, 110) //"Gậy Rồng VIP (11)"	
		  || DropColorPointer == ITEM2(1, 111) //"Gậy Rồng VIP (12)"	
		  || DropColorPointer == ITEM2(1, 112) //"Gậy Rồng VIP (13)"	
		  || DropColorPointer == ITEM2(1, 113) //"Gậy Rồng VIP (14)"	
		  || DropColorPointer == ITEM2(1, 114) //"Gậy Rồng VIP (15)"	


		  || DropColorPointer == ITEM2(2, 100) //"Gậy Rồng VIP (1)"	
		  || DropColorPointer == ITEM2(2, 101) //"Gậy Rồng VIP (2)"	
		  || DropColorPointer == ITEM2(2, 102) //"Gậy Rồng VIP (3)"	
		  || DropColorPointer == ITEM2(2, 103) //"Gậy Rồng VIP (4)"	
		  || DropColorPointer == ITEM2(2, 104) //"Gậy Rồng VIP (5)"	
		  || DropColorPointer == ITEM2(2, 105) //"Gậy Rồng VIP (6)"	
		  || DropColorPointer == ITEM2(2, 106) //"Gậy Rồng VIP (7)"	
		  || DropColorPointer == ITEM2(2, 107) //"Gậy Rồng VIP (8)"	
		  || DropColorPointer == ITEM2(2, 108) //"Gậy Rồng VIP (9)"	
		  || DropColorPointer == ITEM2(2, 109) //"Gậy Rồng VIP (10)"	
		  || DropColorPointer == ITEM2(2, 110) //"Gậy Rồng VIP (11)"	
		  || DropColorPointer == ITEM2(2, 111) //"Gậy Rồng VIP (12)"	
		  || DropColorPointer == ITEM2(2, 112) //"Gậy Rồng VIP (13)"	
		  || DropColorPointer == ITEM2(2, 113) //"Gậy Rồng VIP (14)"	
		  || DropColorPointer == ITEM2(2, 114) //"Gậy Rồng VIP (15)"		


		  || DropColorPointer == ITEM2(3, 100) //"Gậy Rồng VIP (1)"	
		  || DropColorPointer == ITEM2(3, 101) //"Gậy Rồng VIP (2)"	
		  || DropColorPointer == ITEM2(3, 102) //"Gậy Rồng VIP (3)"	
		  || DropColorPointer == ITEM2(3, 103) //"Gậy Rồng VIP (4)"	
		  || DropColorPointer == ITEM2(3, 104) //"Gậy Rồng VIP (5)"	
		  || DropColorPointer == ITEM2(3, 105) //"Gậy Rồng VIP (6)"	
		  || DropColorPointer == ITEM2(3, 106) //"Gậy Rồng VIP (7)"	
		  || DropColorPointer == ITEM2(3, 107) //"Gậy Rồng VIP (8)"	
		  || DropColorPointer == ITEM2(3, 108) //"Gậy Rồng VIP (9)"	
		  || DropColorPointer == ITEM2(3, 109) //"Gậy Rồng VIP (10)"	
		  || DropColorPointer == ITEM2(3, 110) //"Gậy Rồng VIP (11)"	
		  || DropColorPointer == ITEM2(3, 111) //"Gậy Rồng VIP (12)"	
		  || DropColorPointer == ITEM2(3, 112) //"Gậy Rồng VIP (13)"	
		  || DropColorPointer == ITEM2(3, 113) //"Gậy Rồng VIP (14)"	
		  || DropColorPointer == ITEM2(3, 114) //"Gậy Rồng VIP (15)"	

		  || DropColorPointer == ITEM2(4, 100) //"Gậy Rồng VIP (1)"	
		  || DropColorPointer == ITEM2(4, 101) //"Gậy Rồng VIP (2)"	
		  || DropColorPointer == ITEM2(4, 102) //"Gậy Rồng VIP (3)"	
		  || DropColorPointer == ITEM2(4, 103) //"Gậy Rồng VIP (4)"	
		  || DropColorPointer == ITEM2(4, 104) //"Gậy Rồng VIP (5)"	
		  || DropColorPointer == ITEM2(4, 105) //"Gậy Rồng VIP (6)"	
		  || DropColorPointer == ITEM2(4, 106) //"Gậy Rồng VIP (7)"	
		  || DropColorPointer == ITEM2(4, 107) //"Gậy Rồng VIP (8)"	
		  || DropColorPointer == ITEM2(4, 108) //"Gậy Rồng VIP (9)"	
		  || DropColorPointer == ITEM2(4, 109) //"Gậy Rồng VIP (10)"	
		  || DropColorPointer == ITEM2(4, 110) //"Gậy Rồng VIP (11)"	
		  || DropColorPointer == ITEM2(4, 111) //"Gậy Rồng VIP (12)"	
		  || DropColorPointer == ITEM2(4, 112) //"Gậy Rồng VIP (13)"	
		  || DropColorPointer == ITEM2(4, 113) //"Gậy Rồng VIP (14)"	
		  || DropColorPointer == ITEM2(4, 114) //"Gậy Rồng VIP (15)"	


		  || DropColorPointer == ITEM2(5, 100) //"Gậy Rồng VIP (1)"	
		  || DropColorPointer == ITEM2(5, 101) //"Gậy Rồng VIP (2)"	
		  || DropColorPointer == ITEM2(5, 102) //"Gậy Rồng VIP (3)"	
		  || DropColorPointer == ITEM2(5, 103) //"Gậy Rồng VIP (4)"	
		  || DropColorPointer == ITEM2(5, 104) //"Gậy Rồng VIP (5)"	
		  || DropColorPointer == ITEM2(5, 105) //"Gậy Rồng VIP (6)"	
		  || DropColorPointer == ITEM2(5, 106) //"Gậy Rồng VIP (7)"	
		  || DropColorPointer == ITEM2(5, 107) //"Gậy Rồng VIP (8)"	
		  || DropColorPointer == ITEM2(5, 108) //"Gậy Rồng VIP (9)"	
		  || DropColorPointer == ITEM2(5, 109) //"Gậy Rồng VIP (10)"	
		  || DropColorPointer == ITEM2(5, 110) //"Gậy Rồng VIP (11)"	
		  || DropColorPointer == ITEM2(5, 111) //"Gậy Rồng VIP (12)"	
		  || DropColorPointer == ITEM2(5, 112) //"Gậy Rồng VIP (13)"	
		  || DropColorPointer == ITEM2(5, 113) //"Gậy Rồng VIP (14)"	
		  || DropColorPointer == ITEM2(5, 114) //"Gậy Rồng VIP (15)"	

		  || DropColorPointer == ITEM2(6, 100) //"Gậy Rồng VIP (1)"	
		  || DropColorPointer == ITEM2(6, 101) //"Gậy Rồng VIP (2)"	
		  || DropColorPointer == ITEM2(6, 102) //"Gậy Rồng VIP (3)"	
		  || DropColorPointer == ITEM2(6, 103) //"Gậy Rồng VIP (4)"	
		  || DropColorPointer == ITEM2(6, 104) //"Gậy Rồng VIP (5)"	
		  || DropColorPointer == ITEM2(6, 105) //"Gậy Rồng VIP (6)"	
		  || DropColorPointer == ITEM2(6, 106) //"Gậy Rồng VIP (7)"	
		  || DropColorPointer == ITEM2(6, 107) //"Gậy Rồng VIP (8)"	
		  || DropColorPointer == ITEM2(6, 108) //"Gậy Rồng VIP (9)"	
		  || DropColorPointer == ITEM2(6, 109) //"Gậy Rồng VIP (10)"	
		  || DropColorPointer == ITEM2(6, 110) //"Gậy Rồng VIP (11)"	
		  || DropColorPointer == ITEM2(6, 111) //"Gậy Rồng VIP (12)"	
		  || DropColorPointer == ITEM2(6, 112) //"Gậy Rồng VIP (13)"	
		  || DropColorPointer == ITEM2(6, 113) //"Gậy Rồng VIP (14)"	
		  || DropColorPointer == ITEM2(6, 114) //"Gậy Rồng VIP (15)"	











		)
	{
		_asm
		{
			Mov DropColorPointer,0x005F4918//Tím
			Jmp DropColorPointer
		}
	}
	else if(DropColorPointer==ITEM2(14,14)
		||DropColorPointer==ITEM2(5,50))
	{
		_asm
		{
			mov DropColorPointer,0x005F439E//Màu vàng
			jmp DropColorPointer
		}
	}
	else
		{
		_asm{
			Mov DropColorPointer,0x005F47BC//Kế tiếp
			Jmp DropColorPointer
		}
	}
}
