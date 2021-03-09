#ifndef _SPRITE_H_
#define _SPRITE_H_
#include "File.h"
#include "Node.h"
#include "Array.h"
#include "CollisionData.h"
#include "SpriteList.h"
class Alarm;
class MovementPattern;

class   Sprite:public node
{
private:
	int id;
	
	//Map *mapPointer;
	String name;
	float mapPositionX;
	float mapPositionY;			
	int viewPortX;
	int viewPortY;			
	float scaleX;																
	float scaleY;																
	float blendingRatio;
	unsigned int zOrder;
	bool mapCollisionFlag;
	bool reflection;			
	int  actorIndex;			
	int changeAnimation;
	int cAnimation;
	int animation;		
	int frame;
	float delay;
	bool visible;
	bool mainCharacter;
	bool toBeDeleted;			
	float friction;
	float  translationX;
	float  translationY;
	float	speed;
	float	directionX;
	float	directionY;
	bool	canned;
	bool    pauseSprite;
	bool	doNotCutDirection;	
	bool	cannedVDirection;	
	bool	cannedHDirection;	
	int		variableNumber;
	int alarmCount;
	int alarmMaximum;
	bool	hFlip;								    
	bool	vFlip;
	bool	hFlipI;
	bool	vFlipI;
	bool    lasthFlip;
	bool    lastvFlip;
	bool    canUpdate;
	bool	autoFlip;
	bool collisionType;
	bool showSpriteCollision;
	bool showSpriteBoundingBox;
	int updateF;
	int updateFC;
	int waitingfor;
	bool activateCollisionWithSprite;

	//void ShowSpriteCollision(COLORREF=RGB(0,0,0));
	//void ShowSpriteBoundingBox(COLORREF =RGB(0,0,0));
	void PegRegistered(int notused);
	void MapPositionForPGX(float);
	void MapPositionForPGY(float);
	void HandleLastFlipPR();
	bool pegRegistered;
	int lastFrame;
	bool ghostCollisionWithSprite;
	bool ghostCollisionWithMap;
	// This method will be private and called from GameLoop, but it is public for demo: void DisplaySprite ();
	//void CheckMapCollision(Map *);
	void CheckSpriteCollision(Sprite *);
	void UpdateSprite();
	bool unused;
	bool checkSameDisplayList;
	bool mapCollision;
	bool spriteCollision;
	unsigned int  newZOrder;
	float MinT;
	//CollisionSegment reflectedSegment;	
	void reflect(float,float);
	void FrictionFactor();
	void UpdateTranslation();
	void UpdateAnimation();
	void ResetMapCollisionFlag();
	void FlipSet();
	void GetTranslation();
	bool showVectorOfTranslation;
	//void ShowVectorOfTranslation(COLORREF);
	Array<String> collidedSprites;
	Array<CollisionData *> ownerCollisionData;
	Array<CollisionData *> mapCollisionData;
	Array<CollisionData *> spriteCollisionData;
	float cannedDirectionX;
	float cannedDirectionY;
	void CannedFactor();
	void HandleAlarms();
	//POINT RayViewportDest(float,float,float,float);
	bool showPath;
	bool showMovementPattern;
	bool playfirst;
	//CollisionSegment *lastSegment;
	int followStatus;

	void UpdateMovementPattern();
	int mpIndex;
	
	friend class GameNode;

	bool gravity;
	float G;
	float speed0;
	float mapPositionX0;
	float mapPositionY0;
	float directionX0;
	float directionY0;
	int timet;
	float speed00;
	float gravityFriction;

	void GravityFactor();


	bool UWP;
	float UWPspeed;
	float UWPdispX;
	float UWPdispY;
//	float IMCMapPositionX;
//	float IMCMapPositionY;
	
	node * Clone();

	bool TempCheckCollisionWithMap(float,float,float,float);
	bool TempCheckCollisionWithMap(float,float,float,float,int);
	bool TempCheckCollisionWithSprite(float,float,float,float);
	Sprite * TempCheckCollisionWithSprite(float,float,float,float,const char *);

	/* PathStateMachine Implementation
	void DisplayPath(bool,COLORREF = RGB(255,0,0));
	//Array<Sprite *> spriteCOLL;

	bool checkPSMCollision;
	bool collisionWithPath;
	void UpdatePSM();
	bool TestPSMCollision();
	*/

	/* Movement Pattern Implementation
	MovementPattern * MP;
	float t111x;
	float t111y;
	float t222x;
	float t222y;
	float delta;
	int currentVectorPath;
	bool loop;
	bool closed;
	void DisplayPattern(bool,COLORREF = RGB(255,0,0));
	float mpmpx;
	float mpmpy;
	int li;
	*/
		
public:
	
	Sprite();
	Sprite(Sprite *);								 
	Sprite & operator=(const Sprite &s);
	Sprite(const Sprite &);
	virtual ~Sprite();
	//Array<Alarm *> alarmList;
	//Array<Variable> LocalVariables;
	//PathStateMachineTraverser *  psmt;
	int  displayListNumber;
	float dt;
	// Eventually this will be replaced by the GameNode "SpriteList", but I don't have scene graphs at the moment.
	SpriteElem* se;
	void Unused(bool);
	bool Unused();
	void Use(const char *);
 	static Sprite* Search(const char *);
	///Network
	static Sprite* Search(const int); // Search using the ID
	//Network
	void CheckSameDisplayList(bool);
	bool CheckSameDisplayList(void);

	// This will be private later
	void DisplaySprite();
	// This will be private later

	void CheckSameType(bool);
	bool CheckSameType(void);

	void CheckCollisionWithSprite(bool);
	bool CheckCollisionWithSprite();
	void GhostCollisionWithSprite(bool);
	bool GhostCollisionWithSprite(void);
	void GhostCollisionWithMap(bool);
	bool GhostCollisionWithMap(void);
	void ChangePathState(unsigned int);
	unsigned int NearestStationNumber(bool);
	float TranslationX();
	float TranslationY();
	float Speed(void);
	void Speed(float);
	void SpeedDec(float,float=0);
	void SpeedInc(float,float=15);
	bool  SpeedGreater(float);
	bool  SpeedGreaterEqual(float);
	bool  SpeedLess(float);
	bool  SpeedLessEqual(float);
	const char *Name();
	void Name(const char *);
	void Visible (bool);
	bool Visible ();
	void Visible(const char *name,bool vis);
	void DeleteFlag(bool);
	bool DeleteFlag();
	//void BelongToMapPtr(Map *);
	//Map *BelongToMapPtr();
	void Id(int);
	int Id();
	void MapPositionX(float f,bool  b= false);
	void MapPositionY(float f,bool b = false);
	float MapPositionX ();
	float MapPositionY ();
	void MapPosition(float x,float y,bool b = false);
	void MapPositionXInc(float x,float max,bool b = false);
	void MapPositionXDec(float x,float min,bool b = false);
	void MapPositionYInc(float y,float max,bool b = false);
	void MapPositionYDec(float y,float min,bool b = false);

	float LeftPosition();
	float TopPosition();
	float WorldPositionX ();
	float WorldPositionY ();
	void WorldPositionX(float,bool = false);
	void WorldPositionY(float,bool = false);
	void WorldPosition(float,float,bool = false);
	void WorldPositionXInc(float,float,bool = false);
	void WorldPositionXDec(float,float,bool = false);
	void WorldPositionYInc(float,float,bool = false);
	void WorldPositionYDec(float,float,bool = false);

	void  ScaleX(float);
	void  ScaleY(float);
	float ScaleX();
	float ScaleY();
	void ZOrder(unsigned int);
	unsigned int ZOrder();
	void Canned(bool);
	bool Canned();
	bool Pause();
	void Pause(bool);
	void Animation(int);
	int Animation();	
	void Frame(int);
	int TotalAnimations();
	int TotalFrames();
	int Frame();
	bool EndOfAnimation(int);
	void Delay(unsigned int);
	float Delay();
	void ActorIndex(int);
	int ActorIndex();
	bool CollisionWithSprite(const char * n = NULL);
	void Reflection(bool);
	bool InViewport();
	unsigned int CannedDirection();
	void CannedDirection(unsigned int direction);
	void VectorDirection(float,float,unsigned int=0);
	void VectorAngle(float,float=0);
	float VectorAngle();
	void VariableNumber(int);
	int VariableNumber(void);
	float DirectionX();
	float DirectionY();	
	bool CollisionWithMap();
	void CollisionWithMap(bool);
	void MainCharacter(bool);
	bool MainCharacter(void);
	void CheckCollisionWithMap(bool);
	bool CheckCollisionWithMap(void);
	void DisplayListNumber(int);
	int DisplayListNumber(void);
	void DoNotCutDirection(bool);
	bool DoNotCutDirection(void);
	void BelongToMap(const char *);
	const char * BelongToMap();
	void CannedHDirection(bool);
	bool CannedHDirection(void);
	void CannedVDirection(bool);
	bool CannedVDirection(void);
	float HotSpotX(int);
	float HotSpotY(int);
	bool AddAlarm(const char *);
	void AlarmMaximum(int);
	int  AlarmMaximum(void);
	int  AlarmCount(void);
	Sprite * CreateSprite();
	void Friction(float);
	bool Reflection();
	bool CollisionType();
	void CollisionType(bool);
	void ShowSpriteCollision(bool b);
	void ShowSpriteBoundingBox(bool);
	void PegRegistered(bool);
	bool PegRegistered();
	void ShowVectorOfTranslation(bool);
	int ViewportX();
	int ViewportY();
	bool CollisionWithMap(int);
	bool CollisionWithSprite(int);
	bool Collision(int);
	void ActivateCollisionWithSprite(bool);
	bool ActivateCollisionWithSprite();
	//bool SpriteToMapRay(unsigned int,float,float,unsigned int,bool = true,COLORREF = RGB(255,0,0));
	//Sprite * SpriteToSpriteRay(unsigned int,float,float,unsigned int,bool = true,COLORREF = RGB(255,0,0));
	//FunPoint HotSpot(unsigned int);
	void Follow(Sprite *,unsigned int = 0,unsigned int = 0,unsigned int = 0);
	void Follow(const String, unsigned int = 0,unsigned int = 0,unsigned int = 0);
	float Distance(Sprite *);
	float DistanceX(Sprite *);
	float DistanceY(Sprite *);
	float DifferenceX(Sprite *);
	float DifferenceY(Sprite *);
	bool Left(Sprite *);
	bool Right(Sprite *);
	bool Up(Sprite *);
	bool Down(Sprite *);
	bool SameHFlip(Sprite *);
	bool SameVFlip(Sprite *);
	bool HFlip();
	bool VFlip();
	void HFlip(bool);
	void VFlip(bool);
	void AutoFlip(bool);
	bool AutoFlip();
	bool OwnerCollisionDataFlagBit(unsigned int);
	bool SpriteCollisionDataFlagBit(unsigned int);
	bool MapCollisionDataFlagBit(unsigned int);
	int FrameCenterX();
	int FrameCenterY();
	unsigned int Width();
	unsigned int Height();
	bool InWorld();
	friend void GameLoopBody();
	void ChangeSFX(int,const char *);
	void DeleteSFX(int); 
	void AnimationLoopSFX(int,bool);
	void AnimationSoundStatus(int,bool);
	//void FollowPathRight(unsigned int = 0,unsigned int = DOWN,unsigned int = 0,bool = true,COLORREF = RGB(255,0,0));
	//void FollowPathLeft(unsigned int = 0,unsigned int = DOWN,unsigned int = 0,bool = true,COLORREF = RGB(255,0,0));
	//void FollowPathUp(unsigned int = 0,unsigned int = RIGHT,unsigned int = 0,bool = true,COLORREF = RGB(255,0,0));
	//void FollowPathDown(unsigned int = 0,unsigned int = RIGHT,unsigned int = 0,bool = true,COLORREF = RGB(255,0,0));
	void ShortestPath(unsigned int);
	void StopShortestPath();
	bool EndOfShortestPath();
	void EnablePath(bool);
	bool EnablePath();

	void ApplyPathStateMachine(unsigned int);
	
	//this function is under construction;
	void MainCharWorldPosition(float x,float y);

	void ShowPath(bool);
	bool ShowPath();
	
	void Save(File &);
	void Load(File &);
	
//	bool LookAheadCollision(unsigned int,unsigned int,unsigned int);
	Sprite * LookAheadCollisionWithSprite(unsigned int,unsigned int,const char * = NULL);
	bool LookAheadCollisionWithMap(unsigned int,unsigned int,int = -1);

	Sprite * CollisionWithSpritePtr(const char * = NULL);

	bool CollisionWithPath();

	void MovementPatternLoop(bool);
	bool MovementPatternLoop();
	void ApplyMovementPattern(int);
	void ShowMovementPattern(bool);
	bool ShowMovementPattern();
	void StartMovementPattern(bool,bool);
	void StartMovementPattern(bool = false);
	void StopMovementPattern();
	bool EndOfMovementPattern();
	bool ApplyingMovementPattern();
	const char * MovementPatternName();

	bool Gravity();
	void Gravity(bool,float = 20);
	void GravityFriction(float = 0);
	float GravityFriction();

	void AddLocalVariable(unsigned int);

	void * operator new(size_t);
	void   operator delete(void *);

	//Behavior behavior;
	friend class MovementPattern;
	friend class SpritePTR;
	friend class PathStateMachine;
	friend class PathStateMachineTraverser;

	///Network
	/* bool Player;
	bool playerSelected;
	//Key Keys[256];
	//_LISTMSG Q_in;
	//void AddToQ(_NETMSGQ&);
	void ClearQ();
	void HandleQ();
	bool IsActiveNetworkPlayer();
	bool Keyboard_IsPressed(unsigned char); 
	bool Keyboard_IsNotPressed(unsigned char); 
	bool Keyboard_IsTriggered(unsigned char);
	bool Keyboard_IsNotTriggered(unsigned char);
	bool Keyboard_GetKey(unsigned char &);
    bool Keyboard_Nothing();
	bool Keyboard_Any();
    
	unsigned int Keyboard_TapCounter(unsigned char);
	unsigned int Keyboard_HoldCounter(unsigned char);
	void Keyboard_Reset();

	//for The Mouse

	unsigned int Counter;
	unsigned int LCounter;
	unsigned int RCounter;
	unsigned int MCounter;
	bool         LDoubleClick;
	bool         RDoubleClick;
	bool         MDoubleClick;
	int m_x;
	int m_y;
	unsigned int m_X;
	unsigned int m_Y;
	int relx;
	int rely;
	int relz;
	//Key  Mousekeys[3];
	bool isMovingX;
	bool isMovingY;
	bool isMovingZ;

	bool Mouse_IsPressed(unsigned char); 
	bool Mouse_IsTriggered(unsigned char);
	bool Mouse_IsNotPressed(unsigned char);
	bool Mouse_IsNotTriggered(unsigned char);
	bool Mouse_GetKey(unsigned char &);
	bool Mouse_Nothing();
	bool Mouse_Any();
	bool Mouse_IsDoubleClicked(unsigned char);
	unsigned int Mouse_TapCounter(unsigned char);
	unsigned int Mouse_HoldCounter(unsigned char);
	int Mouse_RelX();
	int Mouse_RelY();
	int Mouse_Wheel();
	int Mouse_ViewportX();
	int Mouse_ViewportY();
	unsigned int Mouse_WorldX();
	unsigned int Mouse_WorldY();
	bool Mouse_InRect( Rect *);
    bool Mouse_IsMoving();
	void Mouse_Reset();
	//Network
	*/
	//Backward
	float SpeedX();
	void  SpeedX(float);
	float SpeedY();
	void  SpeedY(float);
	void  SpeedXDec(float,float);
	void  SpeedXInc(float,float);
	void  SpeedYDec(float,float);
	void  SpeedYInc(float,float);
	void  GhostCollision(bool);
	bool  GhostCollision();
	bool  LookAheadCollision(unsigned int,unsigned int,unsigned int);
	///////////

	DYNCREATED
};



class   SpritePTR
{
	Sprite *spritePtr;
	static Sprite * dummySpritePtr;
public:
	SpritePTR(); 
	SpritePTR(Sprite *);
	SpritePTR(const char *);
	Sprite * operator->();
	Sprite & operator*();
	SpritePTR & operator=(Sprite *);
	operator Sprite *();

};

struct QueryImp;

class   Query
{
	QueryImp * p;
public:
	Query(bool (*)(Sprite *));
	~Query();
	Sprite * operator[](unsigned int);
	unsigned int Count();
};

#endif 