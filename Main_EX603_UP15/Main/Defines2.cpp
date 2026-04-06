#include "stdafx.h"
#include "Defines2.h"

char * GlobalText(int iNum)
{
	return iGlobalText(GlobalLine, iNum);
}

void RenderModel3D(float x, float y, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse) // code hien thi item
{
	glMatrixMode(0x1701);
	glPushMatrix();
	glLoadIdentity();
	glViewport2(0, 0, *(GLsizei*)g_WindowWidth, *(GLsizei*)g_WindowHeight);
	float v2 = *(float*)g_WindowWidth / *(float*)g_WindowHeight;
	gluPerspective_2(1.f, v2, CameraViewNear, CameraViewFar);
	glMatrixMode(0x1700);
	glPushMatrix();
	glLoadIdentity();
	GetOpenGLMatrixF(CameraMatrixF);
	EnableDepthTestF();
	EnableDepthMaskF();
	glClear(0x100u);
	CRenderItem3D(x, y, Width, Height, ItemID, Level, Excl, Anc, OnMouse);
	EndBitmap();
	glColor3f(1, 1, 1);
	EnableAlphaTest(true);
}