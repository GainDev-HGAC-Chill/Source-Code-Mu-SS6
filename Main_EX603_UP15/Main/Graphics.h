#pragma once
#include <windows.h>
//

//#define pWinWidth				*(GLsizei*)0x0E61E58
//#define pWinHeight				*(GLsizei*)0x0E61E5C

class Graphics
{
public:
	Graphics();
	// ----
	void		Load();
	static void	InterfaceDraw();
	static int  SelectDraw();
	void InitOGLHook();
}; extern Graphics gGraphics;