#ifndef _FUNCURSOR_H_
#define _FUNCURSOR_H_

class   Cursor: public node
{
private:
	String name;
	Sprite * sprite;
	unsigned int viewportPositionX;
	unsigned int viewportPositionY;
	bool collisionType;
	unsigned int actor;
	int          li;
	void DefaultActor();
	void __InternalCursorFct();
	void ShowCollisionData(bool);
	void ShowBoundingBox(bool);

public:
	Cursor();
	~Cursor();
	
	const char * Name();
	void         AddSpriteCursor(unsigned int = DEFAULT_CURSOR,unsigned int = 0,unsigned int = 0,bool = PRECISECOLLISION);
	void         AddLocalVariable(unsigned int index);
	void         Animation(unsigned int);
	unsigned int Animation();
	void         Frame(unsigned int);
	unsigned int Frame();
	void         Delay(unsigned int);
	unsigned int Delay();
	bool         CollisionWithSprite(const char * = NULL);
	bool         CollisionWithMap();
	bool         CollisionWithMap(int);
	void         ViewportPositionX(unsigned int,bool = false);
	void         ViewportPositionY(unsigned int,bool = false);
	void         ViewportPosition(unsigned int,unsigned int,bool = false);//last two arguments are reserved
	unsigned int        ViewportPositionX();
	unsigned int        ViewportPositionY();
	bool         IsTriggeredOnSprite(const char *,unsigned char);
	bool         IsPressedOnSprite(const char *,unsigned char);
	bool         IsTriggeredOnMap(int,unsigned char);
	bool         IsPressedOnMap(int,unsigned char);
	bool         InRect(FunRect);
		
	void  Save(File &);
	void  Load(File &);
	Behavior behavior;

	friend void GameLoopBody();
	DYNCREATED
};

#endif