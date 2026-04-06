#include "stdafx.h"
#include "Skillbar.h"
#include "User.h"
#include "Interface.h"
#include "WindowsStruct.h"
#include "Defines.h"
#include "Offset.h"
#include "Central.h"
#include "Util.h"
#include "TMemory.h"
#include "OffTrade.h"
#include "SItemOption.h"
#include "PrintPlayer.h"
#include "CustomFont.h"
#include "Font.h"
#include "CChatClassic.h"

SkillBox gSkillBox;

int JCPageSlotSkill = 0;

SkillBox::SkillBox()
{
}

SkillBox::~SkillBox()
{
}

bool JCEventButton(int x, int y, int w, int h)
{
	return pCheckMouseOver(x, y, w, h) && *(BYTE*)0x8793386;
}

signed int Bsub_9CEBF0(double a1)
{
	return (signed int)a1;
}

double JCRenderNumber(float a1, float a2, int a3, float a4)
{
	double result; // st7@2
	float v5; // ST44_4@5
	float v6; // ST38_4@5
	signed int i; // [sp+38h] [bp-30h]@3
	float v8; // [sp+3Ch] [bp-2Ch]@3
	signed int v9; // [sp+44h] [bp-24h]@3
	char v10[32]; // [sp+48h] [bp-20h]@3
	float v11; // [sp+70h] [bp+8h]@3

	EnableAlphaTest(1);
	if (a4 >= 0.300000011920929)
	{
		v8 = (a4 - 0.4800000119209290) * 12.0;
		itoa(a3, v10, 10);
		v9 = strlen(v10);
		v11 = a1 - (double)v9 * v8 / 2.0;
		for (i = 0; i < v9; ++i)
		{
			v6 = (double)(v10[i] - 48) * 12.0 / 128.0;
			v5 = (a4 - 0.4000000119209290) * 16.0;
			RenderBitmap(31337, v11, a2, v8, v5, v6, 0.0, 0.09375, 0.875, 1, 1, 0.0);
			v11 = v8 * 0.800000011920929 + v11;
		}
		result = v11;
	}
	else
	{
		result = a1;
	}

	return result;
}

bool JCEventMouseSkill(int a1)
{
	bool result; // al@2
	unsigned __int8 v5; // ST4F_1@3
	int v6; // ST0C_4@7
	int v7; // ST08_4@7
	int v8; // ST04_4@7
	int v9; // eax@7
	int v10; // ST0C_4@11
	int v11; // ST08_4@11
	int v12; // ST04_4@11
	int v13; // eax@11
	int v14; // ST0C_4@16
	int v15; // ST08_4@16
	int v16; // ST04_4@16
	int v17; // eax@16
	int v18; // ST0C_4@21
	int v19; // ST08_4@21
	int v20; // ST04_4@21
	int v21; // eax@21
	int v22; // ST0C_4@30
	int v23; // ST08_4@30
	int v24; // ST04_4@30
	int v25; // eax@30
	int v26; // ST0C_4@34
	int v27; // ST08_4@34
	int v28; // ST04_4@34
	int v29; // eax@34
	int v30; // ST0C_4@38
	int v31; // ST08_4@38
	int v32; // ST04_4@38
	int v33; // eax@38
	int v34; // ST0C_4@45
	int v35; // ST08_4@45
	int v36; // ST04_4@45
	int v37; // eax@45
	int v38; // ST0C_4@68
	int v39; // ST08_4@68
	int v40; // ST04_4@68
	int v41; // eax@68
	int v42; // ST0C_4@92
	int v43; // ST08_4@92
	int v44; // ST04_4@92
	int v45; // eax@92
	int v46; // ST0C_4@98
	int v47; // ST08_4@98
	int v48; // ST04_4@98
	int v49; // eax@98
	int v50; // ST0C_4@102
	int v51; // ST08_4@102
	int v52; // ST04_4@102
	int v53; // eax@102
	int v54; // ST0C_4@107
	int v55; // ST08_4@107
	int v56; // ST04_4@107
	int v57; // eax@107
	int v58; // ST0C_4@118
	int v59; // ST08_4@118
	int v60; // ST04_4@118
	int v61; // eax@118
	int v62; // [sp+Ch] [bp-54h]@1
	signed int j; // [sp+10h] [bp-50h]@116
	int v64; // [sp+18h] [bp-48h]@84
	signed int i; // [sp+20h] [bp-40h]@73
	unsigned __int16 v66; // [sp+24h] [bp-3Ch]@53
	signed int v67; // [sp+2Ch] [bp-34h]@40
	signed int v68; // [sp+30h] [bp-30h]@40
	unsigned __int16 v69; // [sp+38h] [bp-28h]@76
	float v70; // [sp+40h] [bp-20h]@5
	float v71; // [sp+40h] [bp-20h]@28
	float v72; // [sp+40h] [bp-20h]@40
	float v73; // [sp+40h] [bp-20h]@73
	float v74; // [sp+40h] [bp-20h]@116
	float v75; // [sp+44h] [bp-1Ch]@5
	float v76; // [sp+44h] [bp-1Ch]@28
	float v77; // [sp+44h] [bp-1Ch]@73
	char v78; // [sp+4Bh] [bp-15h]@73
	float v79; // [sp+4Ch] [bp-14h]@73
	signed int v80; // [sp+50h] [bp-10h]@73
	int v81; // [sp+54h] [bp-Ch]@73
	float v82; // [sp+58h] [bp-8h]@5
	float v83; // [sp+58h] [bp-8h]@28
	float v84; // [sp+58h] [bp-8h]@40
	float v85; // [sp+58h] [bp-8h]@85
	float v86; // [sp+58h] [bp-8h]@116
	float v87; // [sp+5Ch] [bp-4h]@5
	float v88; // [sp+5Ch] [bp-4h]@28
	float v89; // [sp+5Ch] [bp-4h]@40
	float v90; // [sp+5Ch] [bp-4h]@73
	float v91; // [sp+5Ch] [bp-4h]@116
	int JCResto; // eax@1

	v62 = a1;
	JCResto = pWinWidth / pWinWidthReal / 2 - 320;

	if (pCheckEffectPlayer((DWORD*)(dword_7BC4F04 + 1260), 98))
	{
		*(BYTE*)(v62 + 64) = 0;
		result = 1;
	}
	else
	{
		v5 = *(BYTE*)(dword_8128AC8 + 118);
		*(BYTE*)(v62 + 65) = 0;
		if ((signed int)v5 > 0)
		{
			//-- skill Use 1 Bar
			v82 = 385.0 + JCResto;
			v87 = 431.0;
			v70 = 32.0;
			v75 = 38.0;

			if (*(DWORD*)(v62 + 80)
				|| byte_8793384
				|| (v6 = Bsub_9CEBF0(v75),
				v7 = Bsub_9CEBF0(v70),
				v8 = Bsub_9CEBF0(v87),
				v9 = Bsub_9CEBF0(v82),
				pCheckMouseOver(v9, v8, v7, v6) != 1))
			{
				if (*(DWORD*)(v62 + 80) != 1
					|| byte_8793384
					|| (v10 = Bsub_9CEBF0(v75),
					v11 = Bsub_9CEBF0(v70),
					v12 = Bsub_9CEBF0(v87),
					v13 = Bsub_9CEBF0(v82),
					pCheckMouseOver(v13, v12, v11, v10)))
				{
					if (*(DWORD*)(v62 + 80) != 1
						|| byte_8793384 != 1 && byte_8793380 != 1
						|| (v14 = (int)(v75),
						v15 = (int)(v70),
						v16 = (int)(v87),
						v17 = (int)(v82),
						pCheckMouseOver(v17, v16, v15, v14) != 1))
					{
						if (*(DWORD*)(v62 + 80) != 2 || byte_8793384 || byte_8793380)
						{
							if (*(DWORD*)(v62 + 80) == 1)
							{
								*(BYTE*)(v62 + 65) = 1;
								*(DWORD*)(v62 + 68) = *(BYTE*)(dword_7BC4F04 + 50);
								*(DWORD*)(v62 + 72) = (int)(v82 - 5.0);
								*(DWORD*)(v62 + 76) = (int)(v87);
								result = 0;
							}
							else if (*(DWORD*)(v62 + 80) == 2)
							{
								result = 0;
							}
							else
							{
								//-- skill 4 icon
								v88 = 431.0;
								v71 = 160.0;
								v76 = 38.0;
								v83 = 222.0 + JCResto;

								if (*(DWORD*)(v62 + 80)
									|| byte_8793384
									|| (v22 = Bsub_9CEBF0(v76),
									v23 = Bsub_9CEBF0(v71),
									v24 = Bsub_9CEBF0(v88),
									v25 = Bsub_9CEBF0(v83),
									pCheckMouseOver(v25, v24, v23, v22) != 1))
								{
									if (*(DWORD*)(v62 + 80) != 3
										|| byte_8793384
										|| (v26 = Bsub_9CEBF0(v76),
										v27 = Bsub_9CEBF0(v71),
										v28 = Bsub_9CEBF0(v88),
										v29 = Bsub_9CEBF0(v83),
										pCheckMouseOver(v29, v28, v27, v26)))
									{
										if (*(DWORD*)(v62 + 80) != 3
											|| byte_8793384 != 1
											|| (v30 = Bsub_9CEBF0(v76),
											v31 = Bsub_9CEBF0(v71),
											v32 = Bsub_9CEBF0(v88),
											v33 = Bsub_9CEBF0(v83),
											pCheckMouseOver(v33, v32, v31, v30) != 1))
										{

											v84 = 190.0 + JCResto;
											v89 = 431.0;
											v72 = 32.0;
											v68 = 0;

											v67 = *(BYTE*)(v62 + 20) != 1 ? 1 : 6;
											while (v68 < 5)
											{
												v84 = v84 + v72;
												if (v67 == 10)
													v67 = 0;
												v34 = (int)((float)38.0);
												v35 = (int)(v72);
												v36 = (int)(v89);
												v37 = (int)(v84);
												if (pCheckMouseOver(v37, v36, v35, v34) == 1)
												{
													if (*(DWORD*)(v62 + 4 * v67 + 24) == -1)
													{
														if (*(DWORD*)(v62 + 80) == 3)
														{
															*(BYTE*)(v62 + 65) = 0;
															*(DWORD*)(v62 + 68) = -1;
														}
														if (*(DWORD*)(v62 + 80) == 4 && !byte_8793384)
															* (DWORD*)(v62 + 80) = 0;
													}
													else
													{
														v66 = *(WORD*)(dword_8128AC8 + 2 * *(DWORD*)(v62 + 4 * v67 + 24) + 120);
														if (v66
															&& ((signed int)v66 < 67 || (signed int)v66 > 72)
															&& *(BYTE*)(dword_8128ABC + 88 * v66 + 55) != 3)
														{
															if (*(DWORD*)(v62 + 80) == 3)
															{
																*(BYTE*)(v62 + 65) = 1;
																*(DWORD*)(v62 + 68) = *(DWORD*)(v62 + 4 * v67 + 24);
																*(DWORD*)(v62 + 72) = (int)(v84 - 5.0);
																*(DWORD*)(v62 + 76) = (int)(v89);
																return 1;
															}
															if (*(DWORD*)(v62 + 80) == 4 && !byte_8793384)
															{
																if (*(DWORD*)(v62 + 68) == *(DWORD*)(v62 + 4 * v67 + 24))
																{
																	*(DWORD*)(v62 + 80) = 0;
																	*(WORD*)(v62 + 84) = *(WORD*)(dword_8128AC8
																		+ 2 * *(BYTE*)(dword_7BC4F04 + 50)
																		+ 120);
																	*(BYTE*)(dword_7BC4F04 + 50) = *(BYTE*)(v62 + 4 * v67 + 24);
																	PlayBuffer(25, 0, 0);
																	return 0;
																}
																*(DWORD*)(v62 + 80) = 0;
															}
														}
													}
												}
												++v68;
												++v67;
											}
											if (*(DWORD*)(v62 + 80) == 4)
											{
												if (byte_8793384
													|| (v38 = (int)((float)38.0),
													v39 = (int)((float)160.0),
													v40 = (int)((float)431.0),
													v41 = (int)((float)222.0),
													pCheckMouseOver(v41, v40, v39, v38)))
												{
													result = 0;
												}
												else
												{
													*(DWORD*)(v62 + 80) = 0;
													result = 1;
												}
											}
											else if (*(BYTE*)(v62 + 64))
											{
												v80 = 0;
												v78 = 0;
												v90 = 334.0;
												v73 = 24.0;
												v77 = 29.5;
												v79 = JCResto + 191.0;
												v81 = *(DWORD*)(v62 + 80);
												for (i = 0; i < 150; ++i)
												{
													v69 = *(WORD*)(dword_8128AC8 + 2 * i + 120);
													if (v69
														&& ((signed int)v69 < 67 || (signed int)v69 > 72)
														&& *(BYTE*)(dword_8128ABC + 88 * v69 + 55) != 3)
													{
														if (v80 == 10)
															v90 = v90 + v77;
														if (v80 == 20)
															v90 = v90 - v77;
														if (v80 >= 10 && v80 < 20)
														{
															v85 = (double)(v80 - 10) * v73 + v79;
														}
														else if (v80 >= 20)
														{
															v85 = (double)(v80 - 20) * v73 + v79;
														}
														else
														{
															v85 = (double)v80 * v73 + v79;
														}
														++v80;

														if (JCPageSlotSkill == 0)
														{
															if (v80 >= 21)
																continue;
														}
														else
														{
															if (v80 < 21)
																continue;
														}
														v42 = (int)(v77);
														v43 = (int)(v73);
														v44 = (int)(v90);
														v45 = (int)(v85);
														if (pCheckMouseOver(v45, v44, v43, v42) == 1)
														{
															v78 = 1;
															if (!*(DWORD*)(v62 + 80) && !byte_8793384)
															{
																*(DWORD*)(v62 + 80) = 5;
																break;
															}
														}
														if (*(DWORD*)(v62 + 80) == 5 && byte_8793384 == 1)
														{
															v46 = (int)(v77);
															v47 = (int)(v73);
															v48 = (int)(v90);
															v49 = (int)(v85);
															if (pCheckMouseOver(v49, v48, v47, v46) == 1)
															{
																*(DWORD*)(v62 + 80) = 6;
																break;
															}
														}
														if (*(DWORD*)(v62 + 80) == 5 && !byte_8793384)
														{
															v50 = (int)(v77);
															v51 = (int)(v73);
															v52 = (int)(v90);
															v53 = (int)(v85);
															if (pCheckMouseOver(v53, v52, v51, v50) == 1)
															{
																*(BYTE*)(v62 + 65) = 1;
																*(DWORD*)(v62 + 68) = i;
																*(DWORD*)(v62 + 72) = (int)(v85);
																*(DWORD*)(v62 + 76) = (int)(v90);
															}
														}
														if (*(DWORD*)(v62 + 80) == 6 && !byte_8793384 && *(DWORD*)(v62 + 68) == i)
														{
															v54 = (int)(v77);
															v55 = (int)(v73);
															v56 = (int)(v90);
															v57 = (int)(v85);
															if (pCheckMouseOver(v57, v56, v55, v54) == 1)
															{
																*(DWORD*)(v62 + 80) = 0;
																*(WORD*)(v62 + 84) = *(WORD*)(dword_8128AC8 + 2 * *(BYTE*)(dword_7BC4F04 + 50) + 120);
																*(BYTE*)(dword_7BC4F04 + 50) = i;
																*(BYTE*)(v62 + 64) = 0;
																PlayBuffer(25, 0, 0);
																return 0;
															}
														}
													}
												}
												if (v81 == *(DWORD*)(v62 + 80))
												{
													if (*(DWORD*)(dword_7BC4F04 + 676))
													{
														v86 = JCResto + 191.0;
														v91 = 379.0;
														v74 = 24.0;
														for (j = 150; j < 154; ++j)
														{
															v58 = (int)((float)38.0);
															v59 = (int)(v74);
															v60 = (int)(v91);
															v61 = (int)(v86);
															if (pCheckMouseOver(v61, v60, v59, v58) == 1)
															{
																v78 = 1;
																if (!*(DWORD*)(v62 + 80) && !byte_8793384)
																{
																	*(DWORD*)(v62 + 80) = 5;
																	return 1;
																}
																if (*(DWORD*)(v62 + 80) == 5 && byte_8793384 == 1)
																{
																	*(DWORD*)(v62 + 80) = 6;
																	return 0;
																}
																if (*(DWORD*)(v62 + 80) == 5)
																{
																	*(BYTE*)(v62 + 65) = 1;
																	*(DWORD*)(v62 + 68) = j;
																	*(DWORD*)(v62 + 72) = (int)(v86);
																	*(DWORD*)(v62 + 76) = (int)(v91);
																}
																if (*(DWORD*)(v62 + 80) == 6 && !byte_8793384 && *(DWORD*)(v62 + 68) == j)
																{
																	*(DWORD*)(v62 + 80) = 0;
																	*(WORD*)(v62 + 84) = *(WORD*)(dword_8128AC8 + 2 * *(BYTE*)(dword_7BC4F04 + 50) + 120);
																	*(BYTE*)(dword_7BC4F04 + 50) = j;
																	*(BYTE*)(v62 + 64) = 0;
																	PlayBuffer(25, 0, 0);
																	return 0;
																}
															}
															v86 = v86 + v74;
														}
													}
													if (v78 || *(DWORD*)(v62 + 80) != 5)
													{
														if (v78 || byte_8793384 || *(DWORD*)(v62 + 80) != 6)
														{
															if (*(DWORD*)(v62 + 80) == 6)
															{
																if (byte_8793384)
																{
																	result = 0;
																}
																else
																{
																	*(DWORD*)(v62 + 80) = 0;
																	result = 1;
																}
															}
															else
															{
																result = 1;
															}
														}
														else
														{
															*(DWORD*)(v62 + 80) = 0;
															result = 0;
														}
													}
													else
													{
														*(DWORD*)(v62 + 80) = 0;
														result = 1;
													}
												}
												else
												{
													result = !*(DWORD*)(v62 + 80) || *(DWORD*)(v62 + 80) == 5;
												}
											}
											else
											{
												result = 1;
											}
										}
										else
										{
											*(DWORD*)(v62 + 80) = 4;
											result = 0;
										}
									}
									else
									{
										*(DWORD*)(v62 + 80) = 0;
										result = 1;
									}
								}
								else
								{
									*(DWORD*)(v62 + 80) = 3;
									result = 1;
								}
							}
						}
						else
						{
							v18 = (int)(v75);
							v19 = (int)(v70);
							v20 = (int)(v87);
							v21 = (int)(v82);
							if (pCheckMouseOver(v21, v20, v19, v18) == 1)
							{
								*(BYTE*)(v62 + 64) = *(BYTE*)(v62 + 64) == 0;
								PlayBuffer(25, 0, 0);
								*(DWORD*)(v62 + 80) = 0;
								result = 0;
							}
							else
							{
								*(DWORD*)(v62 + 80) = 0;
								result = 1;
							}
						}
					}
					else
					{
						*(DWORD*)(v62 + 80) = 2;
						result = 0;
					}
				}
				else
				{
					*(DWORD*)(v62 + 80) = 0;
					result = 1;
				}
			}
			else
			{
				*(DWORD*)(v62 + 80) = 1;
				result = 1;
			}
		}
		else
		{
			result = 1;
		}
	}

	return result;
}

int JCSkillScale = 0;

void JCSkillRaven(int JCMainSelect)
{
	float v4; // ST18_4@7
	float v5; // ST14_4@7
	signed int i; // [sp+1Ch] [bp-14h]@2
	float v8; // [sp+20h] [bp-10h]@2
	float v9; // [sp+24h] [bp-Ch]@2
	float v10; // [sp+28h] [bp-8h]@2
	float v11; // [sp+2Ch] [bp-4h]@2
	int JCResto; // eax@1

	JCResto = pWinWidth / pWinWidthReal / 2 - 320;

	if (*(DWORD*)(dword_7BC4F04 + 676))
	{
		v10 = JCResto + 191.0;
		v11 = 363.0;
		v8 = 24.0;
		v9 = 38.0;
		for (i = 150; i < 154; ++i)
		{
			if (i == *(BYTE*)(dword_7BC4F04 + 50))
				RenderBitmap(51500, v10 + 4.0, v11 + 4.0, 20.0f, 24.0f, 0.1600000411f, 0.1000000089f, 0.6397998333f, 0.4179990888f, 1, 1, 0);

			v4 = v11 + 6.0;
			v5 = v10 + 6.0;
			JCSkillScale = 1;
			JCLoadSkill(JCMainSelect, i, v5, v4, 20.0, 28.0);
			JCSkillScale = 0;
			v10 = v10 + v8;
		}
	}
}

void JCSkillSelectBar(int JCMainSelect)
{
	float v4; // ST18_4@17
	float v5; // ST14_4@17
	int v7; // [sp+20h] [bp-2Ch]@13
	int v8; // [sp+24h] [bp-28h]@7
	int v9; // [sp+2Ch] [bp-20h]@18
	signed int v10; // [sp+30h] [bp-1Ch]@2
	float v11; // [sp+34h] [bp-18h]@4
	signed int i; // [sp+40h] [bp-Ch]@4
	float v13; // [sp+44h] [bp-8h]@4
	float v14; // [sp+48h] [bp-4h]@4
	int JCResto; // eax@1

	JCMainSelect = *(DWORD*)(GetInstance() + 32);
	JCResto = pWinWidth / pWinWidthReal / 2 - 320;

	if ((signed int)* (BYTE*)(dword_8128AC8 + 118) > 0)
	{
		v10 = 1;
		if (*(BYTE*)(JCMainSelect + 20))
			v10 = 6;
		v13 = 190.0 + JCResto;
		v14 = 431.0;
		v11 = 32.0;

		for (i = 0; i < 5; ++i)
		{
			v13 = v13 + v11;
			v8 = i + v10;
			if (i + v10 == 10)
				v8 = 0;
			if (*(DWORD*)(JCMainSelect + 4 * v8 + 24) != -1
				&& (*(DWORD*)(JCMainSelect + 4 * v8 + 24) < 120
				|| *(DWORD*)(JCMainSelect + 4 * v8 + 24) >= 124
				|| *(DWORD*)(dword_7BC4F04 + 676)))
			{
				v7 = dword_8128ABC + 88 * *(WORD*)(dword_8128AC8 + 2 * *(DWORD*)(JCMainSelect + 4 * v8 + 24) + 120);
				if (!v7 || *(BYTE*)(v7 + 55) != 3)
				{
					if (*(BYTE*)(dword_7BC4F04 + 50) == *(DWORD*)(JCMainSelect + 4 * v8 + 24))
						pDrawGUI(31313, v13, v14, v11, 38.0);
					v4 = v14 + 6.0;
					v5 = v13 + 6.0;
					JCSkillScale = 0;
					JCLoadSkill(JCMainSelect, *(DWORD*)(JCMainSelect + 4 * v8 + 24), v5, v4, 20.0, 28.0);
				}
			}
		}
	}

	v9 = dword_8128ABC + 88 * *(WORD*)(dword_8128AC8 + 2 * *(BYTE*)(dword_7BC4F04 + 50) + 120);

	if (v9 && *(BYTE*)(v9 + 55) != 3)
	{
		JCSkillScale = 0;
		JCLoadSkill(JCMainSelect, *(BYTE*)(dword_7BC4F04 + 50), JCResto + 392.0, 437.0, 20.0, 28.0);
	}
}

void SwitchEventSkill(int num, int x, int y)
{
	int JCMainSelect; // [sp+30h] [bp-2Ch]@15

	JCMainSelect = *(DWORD*)(GetInstance() + 32);

	EnableAlphaTest(1);
	glColor4f(1.0, 1.0, 1.0, 1.0);

	if ((signed int)* (BYTE*)(dword_8128AC8 + 118) > 0 && *(BYTE*)(JCMainSelect + 64) == 1)
	{
		RenderBitmap(61547, x + 245, y + 12, 17, 42, 0.0, 0.0, 0.2399999946, 1.0, 1, 1, 0);

		if (pCheckMouseOver(x + 247, y + 14, 17, 42) == 1)
		{
			gInterface.LockMouseMoveClick = GetTickCount() + 100;
		}
		if (num > 20)
		{
			if (JCPageSlotSkill == 1)
			{
				//-- Boton Arriba
				if (JCEventButton(x + 247, y + 14, 13, 13))
				{
					JCPageSlotSkill = 0;
					RenderBitmap(61547, x + 247, y + 14, 13, 13, 0.3870000243, 0.4429999888, 0.1380000114, 0.2490001172, 1, 1, 0);
					PlayBuffer(25, 0, 0);

				}
				else
				{
					RenderBitmap(61547, x + 247, y + 14, 13, 13, 0.3870000243, 0.7100000381, 0.1380000114, 0.2490001172, 1, 1, 0);
				}
			}
			else
			{
				RenderBitmap(61547, x + 247, y + 14, 13, 13, 0.3870000243, 0.1729999632, 0.1380000114, 0.2490001172, 1, 1, 0);
			}
			//-- Boton Abajo
			if (JCPageSlotSkill == 0)
			{
				if (JCEventButton(x + 247, y + 38, 13, 13))
				{
					JCPageSlotSkill = 1;
					RenderBitmap(61547, x + 247, y + 38, 13, 13, 0.2470000237, 0.4429999888, 0.1380000114, 0.2490001172, 1, 1, 0);
					PlayBuffer(25, 0, 0);

				}
				else
				{
					RenderBitmap(61547, x + 247, y + 38, 13, 13, 0.2470000237, 0.7100000381, 0.1380000114, 0.2490001172, 1, 1, 0);
				}
			}
			else
			{
				RenderBitmap(61547, x + 247, y + 38, 13, 13, 0.2470000237, 0.1729999632, 0.1380000114, 0.2490001172, 1, 1, 0);
			}
		}
		else
		{
			//-- Arriba
			RenderBitmap(61547, x + 247, y + 14, 13, 13, 0.3870000243, 0.1729999632, 0.1380000114, 0.2490001172, 1, 1, 0);
			//-- Abajo
			RenderBitmap(61547, x + 247, y + 38, 13, 13, 0.2470000237, 0.1729999632, 0.1380000114, 0.2490001172, 1, 1, 0);
		}
	}
}

char JCSkillSwitchBar(int JCMainSelect)
{
	float v4; // ST18_4@26
	float v5; // ST14_4@26
	char v9; // [sp+37h] [bp-25h]@9
	float v10; // [sp+38h] [bp-24h]@3
	signed int v11; // [sp+3Ch] [bp-20h]@3
	signed int v12; // [sp+40h] [bp-1Ch]@6
	float v13; // [sp+44h] [bp-18h]@3
	float v14; // [sp+48h] [bp-14h]@3
	signed int i; // [sp+50h] [bp-Ch]@3
	float v16; // [sp+54h] [bp-8h]@16
	float v17; // [sp+58h] [bp-4h]@3
	int JCResto; // eax@1

	JCMainSelect = *(DWORD*)(GetInstance() + 32);
	JCResto = pWinWidth / pWinWidthReal / 2 - 320;

	EnableAlphaTest(1);
	glColor4f(1.0, 1.0, 1.0, 1.0);

	if ((signed int)* (BYTE*)(dword_8128AC8 + 118) > 0 && *(BYTE*)(JCMainSelect + 64) == 1)
	{
		v17 = 334.0;
		v13 = 24.0;
		v14 = 29.5;
		v10 = JCResto + 191.0;
		v11 = 0;

		RenderBitmap(61546, JCResto + 191.3, 335.0, 243.5, 60.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0);

		for (i = 0; i < 150; ++i)
		{
			v12 = *(WORD*)(dword_8128AC8 + 2 * i + 120);
			if (*(WORD*)(dword_8128AC8 + 2 * i + 120) && (v12 < 67 || v12 > 72))
			{
				v9 = *(BYTE*)(dword_8128ABC + 88 * v12 + 55);

				if (v9 != 1 && v9 != 3)
				{
					if (v11 == 10)
						v17 = v17 + v14;
					if (v11 == 20)
						v17 = v17 - v14;
					if (v11 >= 10 && v11 < 20)
					{
						v16 = (double)(v11 - 10) * v13 + v10;
					}
					else if (v11 >= 20)
					{
						v16 = (double)(v11 - 20) * v13 + v10;
					}
					else
					{
						v16 = (double)v11 * v13 + v10;
					}

					++v11;

					if (JCPageSlotSkill == 0)
					{
						if (v11 >= 21)
							continue;
					}
					else
					{
						if (v11 < 21)
							continue;
					}

					if (i == *(BYTE*)(dword_7BC4F04 + 50))
						RenderBitmap(51500, v16 + 4.0, v17 + 4.0, 20.0f, 24.0f, 0.1600000411f, 0.1000000089f, 0.6397998333f, 0.4179990888f, 1, 1, 0);

					v4 = v17 + 6.0;
					v5 = v16 + 6.0;

					JCSkillScale = 1;
					JCLoadSkill(JCMainSelect, i, v5, v4, 20.0, 28.0);
					JCSkillScale = 0;

				}
			}
		}
		JCSkillRaven(JCMainSelect);
	}

	if (*(BYTE*)(JCMainSelect + 65) == 1 && *(DWORD*)(JCMainSelect + 16))
	{
		JCMultiSkillLine(*(DWORD*)(JCMainSelect + 16), 5.5, (int)0x815040, JCMainSelect, 0, 0);
		*(BYTE*)(JCMainSelect + 65) = 0;
	}

	SwitchEventSkill(v11, JCResto + 191.0, 334.0);

	pGLSwitch();
	EnableAlphaTest(0);

	return 1;
}

void JCShowSlotSkill(int ImageID, float PosX, float PosY, float Width, float Height, float CurrentMoveX, float CurrentMoveY, float ScaleX, float ScaleY, bool ScaleSize, bool ScalePosition, bool ScaleAlpha)
{
	if (JCSkillScale == 1)
	{
		RenderBitmap(ImageID, PosX, PosY, 16.0f, 20.0f, CurrentMoveX, CurrentMoveY, ScaleX, ScaleY, ScaleSize, ScalePosition, ScaleAlpha);
	}
	else
	{
		RenderBitmap(ImageID, PosX, PosY, Width, Height, CurrentMoveX, CurrentMoveY, ScaleX, ScaleY, ScaleSize, ScalePosition, ScaleAlpha);
	}
}

void JCShownumberSkill(float x, float y, int number, float scale)
{
	if (JCSkillScale == 1)
	{
		JCRenderNumber(x - 5.0f, y - 5.0f, number, 0.9);
	}
	else
	{
		JCRenderNumber(x, y, number, 1.0);
	}

}

void JCShowTimerBar(int Skillnumber, float x, float y, float w, float h)
{
	if (JCSkillScale == 1)
	{
		JCTimerSkillBar(Skillnumber, x, y, 16.0f, 20.0f);
	}
	else
	{
		JCTimerSkillBar(Skillnumber, x, y, w, h);
	}
}

void RenderNumberHP(float a4, float a5, int Number, float a7)
{
	int Wide = pWinWidth / pWinWidthReal / 2 - 320;

	JCRenderNumber(a4 + Wide + 2, a5, Number, a7);
}

void RenderNumberMP(float a4, float a5, int Number, float a7)
{
	int Wide = pWinWidth / pWinWidthReal / 2 - 320;

	JCRenderNumber(a4 + Wide - 5, (a5), Number, a7);
}

void RenderNumber(float a4, float a5, int Number, float a7)
{
	int Wide = pWinWidth / pWinWidthReal / 2 - 320;

	JCRenderNumber(a4 + Wide, a5, Number, a7);
}

char ChatWindowsClassic(MUChat* This)
{
	This->WindowPosX = 0;

	This->WindowPosY = 368;

	sub_7889B0(This);

	return 1;
}

int sub_790B10(int v13, int v12, int v11, int v10)
{
	glColor4f(1.0, 1.0, 1.0, 1.0);

	return pCheckMouseOver(v13, v12, v11, v10);
}

void SkillBox::Load()
{
	SetCompleteHook(0xE9, 0x008126C0, &JCEventMouseSkill); //-- Skill event
	SetCompleteHook(0xE9, 0x00813970, &JCSkillSwitchBar); //-- Skill Switch
	SetCompleteHook(0xE8, 0x0080F833, &JCSkillSelectBar); //-- Skill barr / Select
	SetCompleteHook(0xE8, 0x00814DC1, &JCShowSlotSkill);
	SetCompleteHook(0xE8, 0x00814D4D, &JCShowSlotSkill);
	SetCompleteHook(0xE8, 0x00814E63, &JCShownumberSkill);
	SetCompleteHook(0xE8, 0x00814F0D, &JCShowTimerBar);
	//
	SetCompleteHook(0xE8, 0x0080FF28, &RenderNumberHP); //-- HP
	SetCompleteHook(0xE8, 0x008100BB, &RenderNumberMP); //-- MP
	SetCompleteHook(0xE8, 0x00810389, &RenderNumber); //-- SD
	SetCompleteHook(0xE8, 0x00810659, &RenderNumber); //-- BP
	SetCompleteHook(0xE8, 0x0078B09A, &ChatWindowsClassic);
	SetCompleteHook(0xE8, 0x0080FF56, &sub_790B10);
}