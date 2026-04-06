#pragma once
#if(SLOTPET)
typedef float vec_t;

typedef vec_t vec2_t[2];
typedef vec_t vec3_t[3];
typedef vec_t vec4_t[4];
typedef vec_t vec34_t[3][4];
typedef unsigned long dword;
#define KIND_PLAYER  1
#define KIND_MONSTER 2
#define KIND_NPC     4
#define KIND_TRAP    8

#define Vector(a,b,c,d) {(d)[0]=a;(d)[1]=b;(d)[2]=c;}
#define VectorAvg(a) ( ( (a)[0] + (a)[1] + (a)[2] ) / 3 )
#define VectorSubtract(a,b,c) {(c)[0]=(a)[0]-(b)[0];(c)[1]=(a)[1]-(b)[1];(c)[2]=(a)[2]-(b)[2];}
#define VectorAdd(a,b,c) {(c)[0]=(a)[0]+(b)[0];(c)[1]=(a)[1]+(b)[1];(c)[2]=(a)[2]+(b)[2];}
#define VectorCopy(a,b) {(b)[0]=(a)[0];(b)[1]=(a)[1];(b)[2]=(a)[2];}
#define QuaternionCopy(a,b) {(b)[0]=(a)[0];(b)[1]=(a)[1];(b)[2]=(a)[2];(b)[3]=(a)[3];}
#define VectorScale(a,b,c) {(c)[0]=(b)*(a)[0];(c)[1]=(b)*(a)[1];(c)[2]=(b)*(a)[2];}
#define DotProduct(x,y) ((x)[0]*(y)[0]+(x)[1]*(y)[1]+(x)[2]*(y)[2])
#define VectorFill(a,b) { (a)[0]=(b); (a)[1]=(b); (a)[2]=(b);}



#define assert(_Expression) (void)( (!!(_Expression)) || (_wassert(_CRT_WIDE(#_Expression), _CRT_WIDE(__FILE__), __LINE__), 0) )
_CRTIMP void __cdecl _wassert(_In_z_ const wchar_t* _Message, _In_z_ const wchar_t* _File, _In_ unsigned _Line);

#define TW_SAFEZONE									( 0x0001)
#define TW_SAFEZONE									( 0x0001)
#define TW_CHARACTER								( 0x0002)
#define TW_NOMOVE									( 0x0004)
#define TW_NOGROUND									( 0x0008)
#define TW_WATER									( 0x0010)
#define TW_ACTION									( 0x0020)
#define TW_HEIGHT									( 0x0040)
#define TW_CAMERA_UP								( 0x0080)
#define TW_NOATTACKZONE								( 0x0100)
#define TW_ATT1										( 0x0200)
#define TW_ATT2										( 0x0400)
#define TW_ATT3										( 0x0800)
#define TW_ATT4										( 0x1000)
#define TW_ATT5										( 0x2000)
#define TW_ATT6										( 0x4000)
#define TW_ATT7										( 0x8000)
#define TERRAIN_SCALE								100.f
#define TERRAIN_SIZE								256
#define TERRAIN_SIZE_MASK							255
#define SERVER_LIST_SCENE   0
#define	NON_SCENE			0
#define WEBZEN_SCENE		1
#define LOG_IN_SCENE		2
#define LOADING_SCENE		3
#define CHARACTER_SCENE		4
#define MAIN_SCENE			5
#define DontMove		*(bool*)0x81C03AA
#define MOVEMENT_MOVE    0
#define MOVEMENT_GET     1
#define MOVEMENT_TALK    2
#define MOVEMENT_ATTACK  3
#define MOVEMENT_OPERATE 4
#define MOVEMENT_SKILL	 5

#define DelTtime								*(float*)0xE61610
#define	Q_PI         							3.14159265358979323846f
#define MODEL_SWORD 							1171
#define SceneFlag								*(int*)0xE609E8
#define m_Resolution							*(int*)0xE8C240
#define g_hWnd									*(HWND*)0xE8C578
#define g_hInst									*(HINSTANCE*)0xE8C57C
#define g_hDC									*(HDC*)0xE8C580
#define pCheckInMouse							((bool(__cdecl*)(int x, int y, int w, int h)) 0x00790B10)
#define TransformPosition						((int(__thiscall*)(int thisa, int a2, vec3_t WorldPos, vec3_t Bone1, bool a5)) 0x00545030)
#define BeginRender								((void(__thiscall*)(float a2)) 0x00546860)
#define EndRender								((void(__cdecl*)()) 0x00546880)
#define CLinkBone								((int(__thiscall*)(OBJECT * o, int a2)) 0x004CD7F0)
#define BMDthisa								((int(*)( )) 0x004CDA10)
#define GetBMDModel								((int(__thiscall*)(int thisa, int Type)) 0x00969C50)
#define CreateForce								((void(__cdecl*)(OBJECT* o, vec3_t Pos)) 0x006D8760)
#define CreateParticle							((int(__cdecl*)(int index, vec3_t Posicion, vec3_t Angle, vec3_t color, int a5, float size, OBJECT * pHeroObject)) 0x0074CD30)
#define CreateJoint								((void(__cdecl*)(int Type,vec3_t Position,vec3_t TargetPosition,vec3_t Angle,int SubType, OBJECT *Target,float Scale,short PK, WORD SkillIndex,WORD SkillSerialNum, int iChaIndex, const float* vColor, short int sTargetIndex )) 0x0072D1B0)
#define CreateEffect							((int(__cdecl*) (int Type,vec3_t Position,vec3_t Angle,vec3_t Light,int SubType,OBJECT *Target,short PKKey,WORD SkillIndex,WORD Skill,WORD SkillSerialNum, float Scale, short int sTargetIndex)) 0x006D9070)
#define CreateSprite							((int(__cdecl*)(int Type, vec3_t Position, float Scale, vec3_t Light, OBJECT *Owner, float Rotation, int SubType)) 0x00771310)
#define DeleteEffect							((bool(__cdecl*) (int Type, int o, int a3)) 0x006D8980)
#define MoveEffect								((void(__cdecl*) ( OBJECT *o, int iIndex)) 0x006F1100)
#define RenderEffects							((void(__cdecl*) ( bool bRenderBlendMesh)) 0x00721DB0)
#define TestFrustrum							((bool(__cdecl*) (vec3_t Position,float Range)) 0x005DBFF0)
#define RenderObject							((void(__cdecl*) (OBJECT *o,bool Translate,int Select, int ExtraMon)) 0x005EBBB0)
#define Draw_RenderObjectR						((void(__cdecl*)(OBJECT *o, int Translate, int Select, int ExtraMon)) 0x005DE260)
#define RenderMesh								((void(__thiscall*)(int thisa, int NumMeshs, int RenderFlag, float Alpha, int BlendMesh, float BlendMeshLight, float BlendMeshTexCoordU, float BlendMeshTexCoordV, int MeshTexture)) 0x005468A0)
#define RenderBody								((int(__thiscall*)(int thisa, int RenderFlag,float Alpha,int BlendMesh,float BlendMeshLight,float BlendMeshTexCoordU,float BlendMeshTexCoordV,int HiddenMesh,int Texture)) 0x005494C0)
#define RenderBodyShadow						((void(__thiscall*)(int thisa, int BlendMesh,int HiddenMesh,int StartMeshNumber, int EndMeshNumber)) 0x0054A270)
#define InHellas								((bool(__cdecl*)(signed int a1))0x004DB1C0)
#define g_Direction								((int(__cdecl*)()) 0x004DB250)
#define IsMayaScene								((bool(__thiscall*)(int This)) 0x004E44A0)

#define RenderColor								((void(__cdecl*)(float x,float y,float Width,float Height, float Alpha, int Flag)) 0x006378A0)

#define GetInstance								((int(*)()) 0x00861110)

#define SetActionx								((void(__cdecl*)(OBJECT *o, int Action, bool bBlending)) 0x00542310) 

#define SendMove								((bool(__cdecl*)(int c, int o)) 0x005A3C70)
#define PathFinding2							((bool(__cdecl*)(int sx,int sy,int tx,int ty, int a, float fDistance, int iDefaultWall)) 0x00542D20)

#define CButtonRender							((void(__thiscall*)(BYTE * Sprite)) 0x004018E0)
#define CSpriteRender							((void(__thiscall*)(BYTE * Sprite)) 0x00416C40)
#define CRenderButtons							((void(__thiscall*)(BYTE * thisa)) 0x004AC520)
#define SpiriteSetPosition						((void(__thiscall*)(BYTE * CButton, int cx, int cy, int eChangedPram)) 0x00416640)
#define SpiriteGetHeight						((int(__thiscall*)(BYTE* thisa)) 0x00401C80)

#define CWin_SetPosition						((void(__thiscall*)(BYTE* thisa, int x, int y)) 0x004AC070)
#define Spirite_GetXPos							((int(__thiscall*)(BYTE* thisa)) 0x00401C20)
#define Spirite_GetYPos							((int(__thiscall*)(BYTE* thisa)) 0x00401C40)
#define Spirite_GetWidth						((int(__thiscall*)(BYTE* thisa)) 0x00401C60)
#define Spirite_GetHeight						((int(__thiscall*)(BYTE* thisa)) 0x00401C80)

#define CButtonCreate							((void(__thiscall*)(BYTE * CButton, int iWidth, int iHeigth, int iTexture, int nMaxFrame, int nDownFrame, int nActiveFrame, int nDisableFrame, int nCheckUpFrame, int nCheckDownFrame, int nCheckActiveFrame, int nCheckDisableFrame)) 0x00401370)
#define CButtonSetText							((void(__thiscall*)(BYTE * thisa,const char* pszText, DWORD* adwColor)) 0x00401AE0)
#define CButtonEnable							((bool(__thiscall*)(BYTE * CButton)) 0x00416120)
#define CRenderBeginOpengl						((void(__cdecl*)(GLint x, int a2, GLsizei width, GLsizei height)) 0x00636480)
#define CreateCharacterPointer					((int(__cdecl*)(int a3, int a4, char a5, char a6, float a7)) 0x0057DD40)
#define SetAction								((void(__cdecl*)(int o, int Action, bool bBlending)) 0x00542310) 
#define RegisterButton							((void(__thiscall*)(BYTE * thisa, BYTE * CButton)) 0x004AC500)
#define pGetUIChaosMachine							((int(__thiscall*)(int a1)) 0x008612C0)
#define pGetTradeWindow								((int(__thiscall*)(int thisa)) 0x00861540)
#define InventoryCtrl_FindItemAtPt					((ITEM*(__thiscall*)(void* thisa, int x, int y)) 0x007DAC10)
#define InventoryCtrl_FindEmptySlot					((int(__thiscall*)(void* thisa, IN int cx, IN int cy)) 0x007DACA0)
#define InventoryCtrl_RemoveItem					((void(__thiscall*)(int thisa, ITEM* pItem)) 0x007DA480)
#define InventoryCtrl_FindItem						((ITEM*(__thiscall*)(int thisa, int LinealPos)) 0x007DA760)
#define GetMixInventoryEquipmentIndex				((int(__thiscall*)(void *thisa)) 0x0050B840)
#define RemoveItemForSlot							((void(__thiscall*)(int thisa, int slot)) 0x00834320)
#define g_MixRecipeMgr								&*(LPVOID*)0xEBB848
#define BeginBitmap									((void(*)()) 0x637770)
#define EndOpengl									((void(*)()) 0x6366F0)
#define EndBitmap									((void(*)()) 0x00637870)
#define IsStrifeMap									((char(__cdecl*)( int a3)) 0x005D3030)

#define FrameMainBtnProcess							((bool (__thiscall*)(int thisa))0x00811BB0)
#define RenderInputText								((void (__thiscall*)(int a3, int a4, int a5)) 0x00596EF0)
#define InputText									*(int*)0xE8C544
#define g_iChatInputType							*(int*)0xE60960
#define SingleTextInputBox							((int(__thiscall*)(int thisa, int x, int y)) 0x00417EC0)
#define LoadBitmapA									((int(__cdecl*)(char * Folder, int Code, int Arg3, int Arg4, int Arg5, int Arg6)) 0x00772330)
#define pSkillAttribute								*(DWORD*)0x008128ABC
#define CRenderBitmaps								((void(__cdecl*)(int Texture,float x,float y,float Width,float Height,float u,float v,float uWidth,float vHeight,bool Scale,bool StartScale,float Alpha)) 0x00637C60)
#define CGlobalBitmap								((void *(__thiscall*)(LPVOID Screen, int a1)) 0x0042CFE0)
#define WindowWidth									*(GLsizei*)0x00E61E58
#define WindowHeight								*(GLsizei*)0x00E61E5C
#define g_WindowWidth								0xE61E58
#define g_WindowHeight								0xE61E5C
#define g_fScreenRate_x								*(float*)0x00E7C3D4
#define g_fScreenRate_y								*(float*)0x00E7C3D8


#define BindTexture									((bool(__cdecl*)(int a1)) 0x00635CF0)
#define g_pRenderTextSetFont						((int(__thiscall*)(LPVOID This, int a2)) 0x420120)
//-- Modelos
#define CameraViewNear								*(float*)0xE61E38
#define CameraViewFar								*(float*)0xE61E3C
#define glViewport2									((void(__cdecl*)(GLint x, int a2, GLsizei width, GLsizei height)) 0x006363D0)
#define gluPerspective_2							((int(__cdecl*)(float Fov,float Aspect,float ZNear,float ZFar)) 0x006358A0)
#define gluPerspective								((void(__stdcall*)(GLdouble fovy, GLdouble aspect, GLdouble zNear, GLdouble zFar)) 0x00995FB2)
//void __stdcall gluPerspective(GLdouble fovy, GLdouble aspect, GLdouble zNear, GLdouble zFar)

#define GetOpenGLMatrixF							((void(__cdecl*)(LPVOID a1)) 0x00635830)
#define EnableDepthTestF							((void(*)()) 0x00635DE0)
#define EnableDepthMaskF							((void(*)()) 0x00635E40)
#define CameraMatrixF								(LPVOID)0x87933A0
#define CRenderItem3D								((int(__cdecl*)(float sx,float sy,float Width,float Height,int Type,int Level,int Option1,int ExtOption,bool PickUp)) 0x005CF310)
//--
#define SetPlayerStop										((void(__cdecl*)(int c)) 0x0054EA80)
#define RenderTerrain								((void(__cdecl*)(bool EditFlag))0x005DC820)
#define RenderTerrainTile							((bool(__cdecl*)(float xf, float yf, int xi, int yi, float lodf, int lodi, bool Flag))0x005DA250)
#define SelectXF									*(float*)0x82C6A9C
#define SelectYF									*(float*)0x82C6A98
#define CollisionPosition							(float*)0x8793248
#define CollisionPosition_1							*(float*)0x8793248
#define CollisionPosition_2							*(float*)0x879324C
#define InBloodCastle								((bool(__cdecl*)(int MapNumber)) 0x004E65C0)
#define EnableAlphaTest								((void(__cdecl*)(BYTE Mode)) 0x00635FD0)
#define EnableDepthTest								((void(*)()) 0x00635DE0)
#define EnableDepthMask								((void(*)()) 0x00635E40)
#define sub_637770									((void(*)( )) 0x00637770)
#define sub_636720									((int (*)( )) 0x00636720)
#define DisableAlphaBlend							((void(__cdecl*)( )) 0x00635F50)
#define EndRenderColor								((void(__cdecl*)())0x00637A30)
#define RenderColorx									((void(__cdecl*)(float x,float y,float Width,float Height, float Alpha, int Flag)) 0x006378A0)
#define GetOpenWindow								((int(__thiscall*)(int This, int Code)) 0x0085EC50)
#define MAX_BITMAP_FILE_NAME 256
#define RenderImageD								((void(__cdecl*)(int ModelID, float X, float Y, float W, float H, float CurrentX, float CurrentY)) 0x00790E40)
#define glClearColorBuffer							((void(__cdecl*)(int thisa )) 0x00635EE0)
#define RenderTipText								((void(__cdecl*)(int sx, int sy, LPCSTR Text)) 0x00597220)
#define RenderNumber								((float(__cdecl*)(float x, float y, int iNum, float fScale)) 0x00791000)
#define DeleteBitmap								((void(__cdecl*)(GLuint uiTextureIndex, bool bForce))0x007724E0)
#define Hero										*(DWORD*)0x007BC4F04
#define CharacterAttribute							*(DWORD*)0x008128AC8
//-- texto
#define GetInfoText									((LPVOID(__thiscall*)( )) 0x0041FE10)
#define CRenderTextSetFon							((int (__thiscall*)(int GetTxt, int font)) 0x00420120)
#define CRenderTextSetColor							((int (__thiscall*)(int GetTxt, int info)) 0x00420080)
#define CRenderTextSetBgColor						((int (__thiscall*)(int GetTxt, int info)) 0x004200F0)
#define pRenderText									((int(__thiscall*)(LPVOID thisa, int PosX, int PosY, LPCTSTR Text, int nCount, int nTabPositions, LPINT lpnTabStopPositions, int nTabOrigin)) 0x00420150)
#define iGlobalText									((char*(__thiscall*)(LPVOID thisa, int LineNumber)) 0x00402320)
#define GlobalLine									(LPVOID)0x008128ADC
#define SeparateTextIntoLines						((int(__cdecl*)( const char *lpszText, char *lpszSeparated, int iMaxLine, int iLineSize)) 0x004D5A40)
#define playSound									((int(__cdecl*)(int sound, int o, int a3))0x006D6C20)
#define g_isCharacterBuff							((bool(__thiscall*)(DWORD * thisa, int bufftype)) 0x004C8640)
#define RenderImageB								((void(__cdecl*)(GLuint uiImageType, float x, float y, float width, float height)) 0x00790B50)
#define CGetScreenWidth2							((int(*)()) 0x005C6E80)
#define GetAttributeLife							((void(__cdecl*)( )) 0x0080FA10)
#define GetAttributeSD								((void(__cdecl*)( )) 0x00810420)
#define GetAttributeAG								((void(__cdecl*)( )) 0x00810150)
#define CameraFOV									*(float*)0xE61E40
#define CameraTopViewEnable							*(BYTE*)0x87933F8
#define FogEnable									*(BYTE*)0x87933F9
#define FogDensity									*(float*)0xE61E44
#define FogColor									(float*)0xE61E48
#define CameraMatrixF								(LPVOID)0x87933A0
#define GetOpenGLMatrixF							((void(__cdecl*)(LPVOID a1)) 0x00635830)
#define World										*(DWORD*)0xE61E18
#define MouseOnWindow								*(BYTE*)0x813DDCE

#define ItemValue									((int(__cdecl*)(int a1, int a2))0x0058E3B0)
#define ConvertGold									((void(__cdecl*)(double dGold, char* szText, int iDecimals)) 0x005C1170)
#define ConvertTaxGold								((void(__cdecl*)(DWORD Gold, char* szText)) 0x005C1560)

#define MouseLButton								*(bool*)0x8793386
#define MouseLButtonPop								*(bool*)0x8793385
#define MouseLButtonPush							*(bool*)0x8793384
#define MouseRButton								*(bool*)0x8793383
#define MouseRButtonPop								*(bool*)0x8793382
#define MouseRButtonPush							*(bool*)0x8793381
#define MouseLButtonDBClick							*(bool*)0x8793380
#define MouseWheel									*(int*)0x879337C
#define MouseRButtonPress							*(DWORD*)0x8793400
#define MouseX										*(int*)0x879340C
#define MouseY										*(int*)0x8793410
#define TargetX										*(DWORD*)0x81C038C
#define TargetY										*(DWORD*)0x81C0388
#define RButtonPressTime							*(float*)0x81C03E4
#define WorldTime									*(float*)0x5EF5A1C
#define RButtonPopTime								*(float*)0x81C03E0
#define PlayBuffer									((signed int(__cdecl*)(int a1, int a2, int a3)) 0x006D6C20)
#define CRenderBitmapRotate							((void(__cdecl*)(int x, float y, float w, float h, float giro, float a9, float a10, float a11, float a12, float a13))0x00637E80)
#define EnableAlphaBlend							((void(__cdecl*)()) 0x00636070)
#define CharacterMachine							*(DWORD*)0x8128AC4
#define IsRepeat									((bool  (__cdecl*)(int iVirtKey))0x00791090)
#define IsRelease									((bool  (__cdecl*)(int iVirtKey))0x00791050)
#define IsPress										((bool  (__cdecl*)(int iVirtKey))0x00791070)
#define CharacterMachineEquip( x )					*(WORD *) ( *(DWORD*)0x8128AC4 + 107 * x + 4672 )
#define MouseUpdateTime								*(DWORD*)0x81C03B4
#define MouseUpdateTimeMax							*(DWORD*)0xE616D0
#define ResetMouseLButton							((void(__cdecl*)()) 0x0083C080)
#define ResetMouseRButton							((void(__cdecl*)()) 0x0083C0A0)
#define AccessModel									((void(__cdecl*)(int Type, char *Dir, char *FileName,int i)) 0x00614D10)
#define OpenTexture									((void(__cdecl*)(int Model,char *SubFolder,int Wrap, int Type,bool Check)) 0x00614710)
#define new_Class									((int(__cdecl*)(int Type)) 0x009D00C5)
#define StrCmp										((int(__cdecl*)( BYTE *a1, BYTE *a2)) 0x009D09B0)
#define InChaosCastle								((bool(__cdecl*)(int a1)) 0x004E65A0)
#define SetCharacterClass							((void(__cdecl*)(int pHero)) 0x0057F410)
#define SendActionPlayer							((void(__cdecl*)(int o, int Action, bool bBlending)) 0x00542310)
#define GetEquipedBowType							((int(__cdecl*)(int pChar)) 0x00587950)
#define ZzzCharacter_SetAttackSpeed					((void(__cdecl*)()) 0x005509C0)
#define ZzzCharacter_IsFemale						((BOOL(__cdecl*)(int byClass)) 0x0049CE10)
#define ZzzCharacter_SetCharacterScale				((void(__cdecl*)(int Character)) 0x0057F020)
#define CharactersClient							((int   (__thiscall*)(int List, int num)) 0x0096A4C0)
#define CList										((int   (*)( )) 0x00402BC0)
#define FindCharacterIndex							((int   (__cdecl*)(int Key)) 0x0057D9A0)
#define ConvertItemType								((int   (__cdecl*)(BYTE* Item)) 0x0058AA80)
#define DeleteBug									((void (__cdecl*)(OBJECT *Owner)) 0x005012D0)
#define GOBoid_CreateBug							((void(__cdecl*)(int Type, vec3_t Position, OBJECT *Owner, int SubType, int LinkBone)) 0x00501700)
#define g_Models									((int(__thiscall*)(int thisa, int Type)) 0x00969C50)
#define bthisa										((int(*)( )) 0x004CDA10)
#define TERRAIN_INDEX_REPEAT						((int(__cdecl*)(unsigned __int8 a1, unsigned __int8 a2)) 0x005D6700)
#define GetUI3D										((int(__thiscall*)(int thisa))0x00861AA0)
#define CreateItemConvertByte						((ITEM* (__thiscall*)(int a1, void *lp)) 0x007E1B10)
#define RenderUI2DEffect							((void(__thiscall*)(int thisa, float fZOrder, void (__thiscall *)(LPVOID, DWORD ,DWORD), LPVOID pClass, DWORD dwParamA, DWORD dwParamB)) 0x00772EA0)
#define UI2DEffectCallEquip							((void(__thiscall*)(LPVOID pClass, DWORD dwParamA, DWORD dwParamB)) 0x00835C70)
#define UI2DEffectCallSkill							((void(__thiscall*)(LPVOID pClass, DWORD dwParamA, DWORD dwParamB)) 0x00815040)
#define RenderItemInfo								((void(__thiscall*)(int thisa, int sx,int sy,ITEM *ip,bool Sell, int Inventype, bool bItemTextListBoxUse)) 0x007E3E30)
#define RenderNumArrow								((bool(__thiscall*)(int thisa, int iX, int iY)) 0x007E02B0)
#define RenderEquipedHelperLife						((bool(__thiscall*)(int thisa, int iX, int iY)) 0x007DFDB0)
#define RenderEquipedPetLife						((bool(__thiscall*)(int thisa, int iX, int iY)) 0x007E0180)
#define RenderSummonMonsterLife						((bool(__thiscall*)(int thisa, int iX, int iY)) 0x007E0220)
#define	CreateBarHP									((int(__stdcall*)(int PosX, int PosY, char * name, int currentLife, int MaxLife, bool a6)) 0x007DFA60)
#define	sub_7DFA60					                ((int(__stdcall*)(signed int PosX, signed int PosY, int a3, signed int a4, signed int a5, char a6)) 0x7DFA60)
#define Defineclass									((BYTE(__cdecl*)(BYTE userclass)) 0x00405230)
#define _GetSkinModelIndex							((char(__cdecl*)(char byClass)) 0x00587500)
#define PartyNumber									*(DWORD*)0x81F6B6C
#define IsPartyMember								((bool (__stdcall*)(int index))0x0051C5C0)
#define IsPartyMemberChar							((bool (__stdcall*)(int c))0x0051C5F0)
#define DeleteParts									((void(__cdecl*)(int c)) 0x004EFF70)
#define LevelConvert								((int(__cdecl*)(BYTE Level)) 0x0057FC30)

#define GetBaseClass									((BYTE(__cdecl*)(BYTE iClass)) 0x00405230)
#define GetStepClass									((BYTE(__cdecl*)(BYTE byClass)) 0x005875C0)
#define FontHeight										*(DWORD *)0x81C0380
//-- Utilidad PickUp

#define EnableUse										*(int*)0x8793738
#define EquipmentItem									*(bool*)0x81F6BEF
#define SendDropItem									*(DWORD*)0xE61FCC
#define SendGetItem										*(DWORD*)0xE61FC8
#define ms_pPickedItem									*(DWORD*)0x9816F7C
#define GetPickedItem									((int   (*)( )) 0x007DD0F0)
#define DeletePickedItem								((void  (*)( )) 0x007DD1B0)
#define GetOwnerInventory								((int (__thiscall*)(int Picket)) 0x007D9410)
#define PickedItem_CanMove								((bool (__thiscall*)(int m_pNewInventoryCtrl, int iTargetIndex, ITEM* pItemObj)) 0x007DC670)
#define pOwner_AddItem									((int (__thiscall*)(int thisa, int iColumnX, int iRowY, int pItem)) 0x007DA1F0)


//#define GetTargetLinealPos								((bool (__stdcall*)(int m_pNewInventoryCtrl)) 0x007D95E0)
#define HidePickedItem									((void (__thiscall*)(int pPickedItem)) 0x007D9660)
#define BackupPickedItem								((void (__thiscall*)( )) 0x007DD230)
#define CharacterMachine_Equipment( x )					*(DWORD*)0x8128AC4 + 107 * x + 4672

#define GetInventSourceLinealPos						((int(__stdcall*)(int thisa, int a2))0x0083C480)
#define GetInventSTargetLinealPos						((int(__thiscall*)(int thisa, int a2, int a3))0x0083C440)

#define GetTargetLinealPos								((int(__thiscall*)(WORD **thisa, void *a2))0x007D95E0)
#define GetSourceLinealPos								((int(__thiscall*)(int thisa))0x007D94E0)
#define CreateItemPick									((ITEM* (__stdcall*)(ITEM*)) 0x007E1E50)
#define SetPickItem										((bool  (__cdecl*)(int a4, const void *a5)) 0x007DD100)
#define CreatePickedItem								((bool(__cdecl*)(int a4, const void *a5)) 0x007DD100)

#define SendRequestEquipmentItem						((bool (__cdecl*)(BYTE SourceFlag, BYTE SourceSlot, ITEM* pItem, BYTE TargetFlag, BYTE TargetSlot)) 0x005BD850)
#define EmptyBufferString								((int (__thiscall*)(void* strMsg))0x00409AD0)
#define CreateOkMessageBox								((bool(__cdecl*)(LPVOID strMsg, DWORD dwColor, float fPriority)) 0x00790A10)
#define LoadWaveFile									((VOID(__cdecl*)(int Buffer, CHAR* strFileName, int MaxChannel, bool Enable)) 0x006D6800)
#define RenderPlane3D									((void(__cdecl*)(float Width,float Height,int Matrix)) 0x00636C90)
#define Link_Bone										((int(__thiscall*)(int o, int a2)) 0x004CD7F0)


enum VERTEX_POS { LT, LB, RB, RT, POS_MAX };
#pragma pack(push, 1)
typedef struct
{
	GLuint	BitmapIndex;
	char	FileName[MAX_BITMAP_FILE_NAME];
	float	Width;
	float	Height;
	char	Components;
	GLuint	TextureNumber;
	BYTE	Ref;
	BYTE* Buffer;

private:
	friend class CBitmapCache;
	DWORD	dwCallCount;
} BITMAP_t;
#pragma pack(pop)

struct SScrCoord
{
	float	fX, fY;
};

struct STexCoord
{
	float	fTU, fTV;
};


char* GlobalTextx(int iNum);
GLvoid RenderColorCircle(float x, float y, float Width);
void AngleMatrix_S6(const vec3_t angles, float matrix[3][4]);
extern inline void GetNearRandomPos(vec3_t Pos, int iRange, vec3_t NewPos);
void VectorRotate_S6(const vec3_t in1, const float in2[3][4], vec3_t out);
void RenderRound(float x, float y, float Radio, GLfloat r, GLfloat g, GLfloat b, GLfloat a);
void RenderBitmapRound(GLuint uiImage, float x, float y, float Radio, float su, float sv, float uw, float vh);
void RenderImageF(GLuint Image, float x, float y, float width, float height, float su, float sv, float uw, float vh);
void Sprite_Render(GLuint uiImageType, float fScrWidth, float fScrHeight, int nOrgWidth, int nOrgHeight, float fScaleX, float fScaleY);
#endif