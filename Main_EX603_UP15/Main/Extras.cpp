#include "stdafx.h"
#include "Extras.h"

#if(SLOTPET)
char* GlobalTextx(int iNum)
{
	return iGlobalText(GlobalLine, iNum);
}

inline void TEXCOORD(float* c, float u, float v)
{
	c[0] = u;
	c[1] = v;
}

void AngleMatrix(const vec3_t angles, float(*matrix)[4])
{
	float		angle;
	float		sr, sp, sy, cr, cp, cy;

	angle = angles[2] * (Q_PI * 2 / 360);
	sy = sinf(angle);
	cy = cosf(angle);
	angle = angles[1] * (Q_PI * 2 / 360);
	sp = sinf(angle);
	cp = cosf(angle);
	angle = angles[0] * (Q_PI * 2 / 360);
	sr = sinf(angle);
	cr = cosf(angle);

	// matrix = (Z * Y) * X
	matrix[0][0] = cp * cy;
	matrix[1][0] = cp * sy;
	matrix[2][0] = -sp;
	matrix[0][1] = sr * sp * cy + cr * -sy;
	matrix[1][1] = sr * sp * sy + cr * cy;
	matrix[2][1] = sr * cp;
	matrix[0][2] = (cr * sp * cy + -sr * -sy);
	matrix[1][2] = (cr * sp * sy + -sr * cy);
	matrix[2][2] = cr * cp;
	matrix[0][3] = 0.0;
	matrix[1][3] = 0.0;
	matrix[2][3] = 0.0;
}

void VectorRotate(const vec3_t in1, const float in2[3][4], vec3_t out)
{
	//assert(in1 != out && "in1°ú outÀº ´Ù¸¥ °ªÀ̀¿©¾ß ÇƠ´Ï´Ù.!");
	out[0] = DotProduct(in1, in2[0]);
	out[1] = DotProduct(in1, in2[1]);
	out[2] = DotProduct(in1, in2[2]);
}

void AngleQuaternion(const vec3_t angles, vec4_t quaternion)
{
	float		angle;
	float		sr, sp, sy, cr, cp, cy;

	// FIXME: rescale the inputs to 1/2 angle
	angle = angles[2] * 0.5;
	sy = sinf(angle);
	cy = cosf(angle);
	angle = angles[1] * 0.5;
	sp = sinf(angle);
	cp = cosf(angle);
	angle = angles[0] * 0.5;
	sr = sinf(angle);
	cr = cosf(angle);

	quaternion[0] = sr * cp * cy - cr * sp * sy; // X
	quaternion[1] = cr * sp * cy + sr * cp * sy; // Y
	quaternion[2] = cr * cp * sy - sr * sp * cy; // Z
	quaternion[3] = cr * cp * cy + sr * sp * sy; // W
}

void QuaternionMatrix(const vec4_t quaternion, float(*matrix)[4])
{

	matrix[0][0] = 1.0 - 2.0 * quaternion[1] * quaternion[1] - 2.0 * quaternion[2] * quaternion[2];
	matrix[1][0] = 2.0 * quaternion[0] * quaternion[1] + 2.0 * quaternion[3] * quaternion[2];
	matrix[2][0] = 2.0 * quaternion[0] * quaternion[2] - 2.0 * quaternion[3] * quaternion[1];

	matrix[0][1] = 2.0 * quaternion[0] * quaternion[1] - 2.0 * quaternion[3] * quaternion[2];
	matrix[1][1] = 1.0 - 2.0 * quaternion[0] * quaternion[0] - 2.0 * quaternion[2] * quaternion[2];
	matrix[2][1] = 2.0 * quaternion[1] * quaternion[2] + 2.0 * quaternion[3] * quaternion[0];

	matrix[0][2] = 2.0 * quaternion[0] * quaternion[2] + 2.0 * quaternion[3] * quaternion[1];
	matrix[1][2] = 2.0 * quaternion[1] * quaternion[2] - 2.0 * quaternion[3] * quaternion[0];
	matrix[2][2] = 1.0 - 2.0 * quaternion[0] * quaternion[0] - 2.0 * quaternion[1] * quaternion[1];
}

inline void GetNearRandomPos(vec3_t Pos, int iRange, vec3_t NewPos)
{
	VectorCopy(Pos, NewPos);
	NewPos[0] += (float)(rand() % (iRange * 2 + 1) - iRange);
	NewPos[1] += (float)(rand() % (iRange * 2 + 1) - iRange);
	NewPos[2] += (float)(rand() % (iRange * 2 + 1) - iRange);
}

void AngleMatrix_S6(const vec3_t angles, float(*matrix)[4])
{
	float		angle;
	float		sr, sp, sy, cr, cp, cy;

	angle = angles[2] * (Q_PI * 2 / 360);
	sy = sinf(angle);
	cy = cosf(angle);
	angle = angles[1] * (Q_PI * 2 / 360);
	sp = sinf(angle);
	cp = cosf(angle);
	angle = angles[0] * (Q_PI * 2 / 360);
	sr = sinf(angle);
	cr = cosf(angle);

	// matrix = (Z * Y) * X
	matrix[0][0] = cp * cy;
	matrix[1][0] = cp * sy;
	matrix[2][0] = -sp;
	matrix[0][1] = sr * sp * cy + cr * -sy;
	matrix[1][1] = sr * sp * sy + cr * cy;
	matrix[2][1] = sr * cp;
	matrix[0][2] = (cr * sp * cy + -sr * -sy);
	matrix[1][2] = (cr * sp * sy + -sr * cy);
	matrix[2][2] = cr * cp;
	matrix[0][3] = 0.0;
	matrix[1][3] = 0.0;
	matrix[2][3] = 0.0;
}

void VectorRotate_S6(const vec3_t in1, const float in2[3][4], vec3_t out)
{
	out[0] = DotProduct(in1, in2[0]);
	out[1] = DotProduct(in1, in2[1]);
	out[2] = DotProduct(in1, in2[2]);
}
#endif