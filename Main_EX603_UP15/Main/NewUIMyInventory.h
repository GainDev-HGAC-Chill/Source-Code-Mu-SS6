#pragma once
#include "CharacterMachine.h"

#define EQUIPMENT_WEAPON_RIGHT		0
#define EQUIPMENT_WEAPON_LEFT		1
#define EQUIPMENT_HELM				2
#define EQUIPMENT_ARMOR				3
#define EQUIPMENT_PANTS				4
#define EQUIPMENT_GLOVES			5
#define EQUIPMENT_BOOTS				6
#define EQUIPMENT_WING				7
#define EQUIPMENT_HELPER			8
#define EQUIPMENT_AMULET			9
#define EQUIPMENT_RING_RIGHT		10
#define EQUIPMENT_RING_LEFT			11
//--
#define EQUIPMENT_PENTAGRAM			12
#define EQUIPMENT_ERRING_RIGHT		13
#define EQUIPMENT_ERRING_LEFT		14
#define MAX_EQUIPMENT_INDEX			12

typedef struct tagEQUIPMENT_ITEM
{
	int x, y;
	int width, height;
	DWORD dwBgImage;
} EQUIPMENT_ITEM;

#define RenderRepairInfo					((void(__cdecl*)(int sz, int sy, int ip, bool Sell)) 0x005C3D70)
#define RenderItemInfo_						((void(__thiscall*)(int thisa, int sx,int sy,int ip,bool Sell, int Inventype, bool bItemTextListBoxUse)) 0x007E3E30)
#define sub_83CBE0							((int   (__thiscall*)(void *thisa)) 0x0083CBE0)
#define MyInventory_Update					((bool(__thiscall*)(void *thisa)) 0x007DB160)
#define calcMaxDurability					((WORD(__cdecl*)(int ip, ITEM_ATTRIBUTE *p, int Level)) 0x005C2170)
#define GetSlotIndexAtPt					((int(__stdcall*)(unsigned __int8 col, unsigned __int8 fil, int temporal)) 0x0083C770)
#define CreateBugSub_						((bool(__cdecl*)(int Type, int Position, int Owner, int o, int SubType, int LinkBone)) 0x005013B0)
#define PetProcess							((int(*)()) 0x004DB230)
#define IsPetProcess						((bool(__thiscall*)(int thisa, int type)) 0x00925700)
#define Process_DeletePet					((void(__thiscall*)(int thisa, int Owner, int itemType)) 0x009253D0)
#define Process_CreatePet					((bool(__thiscall*)(int thisa, int itemType, int modelType, float* Position, int Owner, int SubType, int LinkBone)) 0x009250E0)
#define g_pNPCShop							((int(__thiscall*)(int Instance)) 0x00861280)
#define SetSellingItem						((void(__thiscall*)(int thls, bool bFlag)) 0x00847FF0)
#define ChangeChaosCastleUnit						((void(__cdecl*)(int Character)) 0x004E6670)
#define pPlayerState				*(int*)0x0E609E8
#define pCheckEffectPlayer			((bool(__thiscall*)(void * This,char a2)) 0x004C8640)
#define pPlayStaticEffect			((int(__cdecl*)(DWORD ModelID, DWORD * Arg1, float Scale, float * Color, int Model, float a6, int a7)) 0x00771310)

namespace SEASON3B
{
	void CreateFlyBug(int, int, int, int, int);
	bool CreatePetProcess(int, int, float *, int, int, int);
}

typedef struct
{
	vec3_t StartPos;
	vec3_t XAxis;
	vec3_t YAxis;
	vec3_t ZAxis;
} OBB_t_ok;


struct OBJECT
{
	BYTE arg[4];
	/*+4*/	bool          Live;
	/*+5*/	bool          bBillBoard;
	/*+6*/	bool          m_bCollisionCheck;		//  Ãæµ¹ Ã¼Å© ÇÒ±î?
	/*+7*/	bool          m_bRenderShadow;			//  ±×¸²ÀÚ¸¦ ÂïÀ»±î? ¸»±î?
	/*+8*/	bool          EnableShadow;
	/*+9*/	bool		  LightEnable;
	/*+10*/	bool		  m_bActionStart;
	/*+11*/	bool		  m_bRenderAfterCharacter;
	/*+12*/	bool	      Visible;
	/*+13*/	bool	      AlphaEnable;
	/*+14*/	bool          EnableBoneMatrix;
	/*+15*/	bool		  ContrastEnable;
	/*+16*/	bool          ChromeEnable;
	/*+17*/	unsigned char AI;
	/*+18*/	unsigned short CurrentAction;
	/*+19*/	unsigned short PriorAction;
	/*+20*/		BYTE          ExtState;
	/*+21*/		BYTE          Teleport;
	/*+22*/		BYTE          Kind;
	/*+23*/		WORD		Skill;
	/*+24*/		BYTE		  m_byNumCloth;				// Ãµ °³¼ö
	/*+25*/		BYTE		  m_byHurtByOneToOne;
	/*+26*/		BYTE          WeaponLevel;
	/*+27*/		BYTE          DamageTime;				//  °ø°ÝÀ» ¹ÞÀº Ãæ°Ý ½Ã°£.
	/*+28*/		BYTE          m_byBuildTime;
	/*+29*/		BYTE		  m_bySkillCount;
	/*+30*/		BYTE		  m_bySkillSerialNum;
	/*+31*/		BYTE		  Block;
	/*+32*/	void* m_pCloth;	// Ãµ ºÙÀÌ±â
	/*+40*/	short         ScreenX;
	/*+42*/	short         ScreenY;
	/*+44*/	short         PKKey;
	/*+46*/	short         Weapon;
	/*+48*/	int			  Type;
	/*+52*/	int           SubType;
	/*+56*/	int			  m_iAnimation;				// Ææ¸± ¹ß¹Ù´Ú °ü·Ã ¿¡´Ï¸ÞÀÌ¼Ç Å°°ª
	/*+60*/	int           HiddenMesh;
	/*+64*/	int           LifeTime;
	/*+68*/	int           BlendMesh;
	int           AttackPoint[2];
	int           RenderType;
	int			  InitialSceneFrame;
	int           LinkBone;
	/*92*/		DWORD		  m_dwTime;
	/*+96*/		float         Scale;
	/*+100*/	float         BlendMeshLight;
	/*+104*/	float         BlendMeshTexCoordU;
	/*+108*/	float         BlendMeshTexCoordV;
	/*+112*/	float         Timer;
	/*+116*/	float         m_fEdgeScale;				//  ¿Ü°û¼± ½ºÄÉÀÏ.	
	/*+120*/	float         Velocity;
	/*+124*/	float		  CollisionRange;
	/*+128*/	float         ShadowScale;
	/*+132*/	float         Gravity;
	/*+136*/	float         Distance;
	/*+140*/	float         AnimationFrame;
	/*+144*/	float         PriorAnimationFrame;
	/*+148*/	float	      AlphaTarget;
	/*+152*/	float         Alpha;
	vec3_t        Light;
	vec3_t        Direction;
	vec3_t		  m_vPosSword;				// Ä®³¡ À§Ä¡
	vec3_t		  StartPosition;			// bullet
	vec3_t        BoundingBoxMin;
	vec3_t        BoundingBoxMax;
	vec3_t		  m_vDownAngle;
	vec3_t		  m_vDeadPosition;
	/*+252*/	vec3_t        Position;
	/*+264*/	vec3_t	 	  Angle;
	/*+276*/	vec3_t	 	  HeadAngle;
	/*+288*/	vec3_t	   	  HeadTargetAngle;
	/*+300*/	vec3_t  	  EyeLeft;
	/*+312*/	vec3_t  	  EyeRight;
	/*+324*/	vec3_t		  EyeLeft2;
	/*+336*/	vec3_t		  EyeRight2;
	/*+348*/	vec3_t		  EyeLeft3;
	/*+360*/	vec3_t		  EyeRight3;
	/*+372*/	vec34_t	 	  Matrix;
	vec34_t* BoneTrans;
	OBB_t_ok		  OBB;
	OBJECT* Owner;
	OBJECT* Prior;
	OBJECT* Next;
	BYTE		  m_BuffMap[134];
	short int	  m_sTargetIndex;
	BOOL		  m_bpcroom;
	vec3_t		  m_v3PrePos1;
	vec3_t		  m_v3PrePos2;
};


#define CreateBug                 ((void  (__cdecl*)(int Type, vec3_t Position, OBJECT *Owner, int SubType, int LinkBone)) 0x00501700)

#define MODEL_FENRIR_BLACK					384
#define MODEL_FENRIR_RED					385
#define MODEL_FENRIR_BLUE					386
#define MODEL_FENRIR_GOLD					387
#define MODEL_DARK_HORSE					226
#define MODEL_PEGASUS						323
#define MODEL_UNICON						233
#define MODEL_BUTTERFLY01					176

class CNewUIMyInventory
{
public:
	CNewUIMyInventory(void);
	virtual ~CNewUIMyInventory(void);

	void Init();
	//-- Protocolo
	void ReceiveInventory(BYTE *ReceiveBuffer);
	void ReceiveDropItem(BYTE *ReceiveBuffer);
	void ReceiveDurability(BYTE *ReceiveBuffer);
	void ReceiveItemChange(BYTE *ReceiveBuffer);
	void ReceiveDeleteInventory(BYTE *ReceiveBuffer);
	//--
	static void LoadImages();
	static void Backup_PickedItem();
	static bool __thiscall Update(DWORD *a1);
	static void __thiscall RenderFrame(DWORD thisa);
	static void __thiscall SetButtonInfo(DWORD thisa);
	static void __thiscall Render3D(signed int *thisa);
	static bool __thiscall InventoryProcess(int thisa);
	static void __thiscall RenderEquippedItem(DWORD thisa);
	static bool __thiscall EquipmentWindowProcess(DWORD thisa);
	static void __thiscall SetEquipmentSlotInfo(DWORD thisa);
	static void __thiscall RenderItemToolTip(int thisa, int iSlotIndex);
	static void RenderEquipped(GLuint uiImageType, float x, float y, float width, float height);
	static void __thiscall RenderDetailsText(int thisa, int iPos_x, int iPos_y, LPCSTR pszText, int iBoxWidth, int iBoxHeight, int iSort, OUT SIZE* lpTextSize);
	//--
	static bool __thiscall NewUIManager_Render(int thls);

	static void __thiscall RenderLeft(int thls);
};

extern int TypeInventory;
extern CNewUIMyInventory g_pMyInventory;
extern CCharacterMachine * Character_Machin;