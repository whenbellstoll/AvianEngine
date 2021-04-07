#include "SpriteFull.h"
class   Cursor: public node
{
private:
	const char * name;
	Sprite * sprite;
	unsigned int viewportPositionX;
	unsigned int viewportPositionY;
	bool collisionType;
	unsigned int actor;
	int          li;
	void __InternalCursorFct();


public:
	Cursor();
	~Cursor();

	void DefaultActor();
	void ShowCollisionData(bool);
	void ShowBoundingBox(bool);
	const char * Name();
	void         AddSpriteCursor(unsigned int = 0,unsigned int = 0,unsigned int = 0,bool = false);
	void         AddLocalVariable(unsigned int index);
	void         Animation(unsigned int i);
	unsigned int Animation();
	void         Frame(unsigned int i);
	unsigned int Frame();
	void         Delay(unsigned int i);
	unsigned int Delay();
	bool         CollisionWithSprite(const char * = nullptr);
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
	bool         InRect(Rect);
		
	void  Save(File &);
	void  Load(File &);
	Behavior behavior;

	DYNCREATED
};
