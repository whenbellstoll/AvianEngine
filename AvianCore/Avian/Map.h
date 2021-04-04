#ifndef _MAP_H_
#define _MAP_H_

#include "Array.h"
#include "CollisionData.h"
#include "Behavior.h"

class WrappingAlgorithm
{
	Rect rect1,rect2,sourcerect,rect,sources[4],destinations[4],rect1cpy;          
	int w1,w2,h1,h2,rect2x,rect2y,x,y,vpx,vpy,initvpx,initvpy;
	bool InViewPort;
	char type;
	void Compute();
	void Adjust();

public:

	unsigned int ArraySize;
	Rect * Sources();
	Rect * Destinations();
	WrappingAlgorithm();
	WrappingAlgorithm(const Rect & rc1,const Rect & rc2,bool InViewPort,int x,int y);
	void Position(int,int);
	void Load(File &);
	void Save(File &);
};

class Alarm;
extern   Rect zrect ;


struct MapImp;

class  Map :public node
{
public:
	
    enum MapType{MASTERMAP,STANDARDMAP,WRAPPEDMAP};

private:
	
	MapImp * pMapImp;

	WrappingAlgorithm * wa;
	
	int				id;
	//String          name;
	const char*		name;
	//String			fileName;
	const char*		fileName;
	bool			isMasterMap;        
	unsigned  int	height;				
	unsigned  int	width;
	unsigned int	texture;
	unsigned int	startingVertex;
	int             gridRows;
	int             gridColumns;
	float	        worldPositionX;				
	float	        worldPositionY;				
	float 		    viewPortX;			
	float 		    viewPortY;			
	int             maxWorldX;          
	int             maxWorldY;          
	int		    	zOrder;				
	bool			visible;			
	float			scrollingRatioX;	
	float    		scrollingRatioY;	
    float           speedX;             
	float           speedY;             
	COLORREF		transparencyColor;	
	Rect rect,rect1d,s,d,drect;
	bool FollowV;
	bool pauseMap;

	double  bltFlag;
	MapType mType;
	int li;
	bool WL;
	void  InitMasterMap(const char * ,const char *,int);
	void  InitStandardMap(const char * ,const char *,int,int,int,bool,Rect);
	void  InitWrappedMap(const char * ,const char *,int,int,int,bool,Rect);
    void  Id(int);	
	void  Init();
	void  LoadMap();
	void  FreeMap();
	void  DisplayMasterMap();
	void  DisplayStandardMap();
	void  DisplayWrappedMap();
	void  DummyDisplay();
    void  UpdateStandardMap();
	void  UpdateWrappedMap();
	void  (Map::*displayMap)();          


	friend   void  ToggleMode();
	friend   void  RestoreAllSurfaces();
	friend   void  GameLoopBody();
	friend   class Sprite;
	friend   class GameNode;
	friend   class Variable;
	friend void StartEngine();
	friend void StopEngine();

	int alarmCount;
	int alarmMaximum;
	void ShowMapCollision(COLORREF =RGB(0,0,0));
	bool showMapCollision;
	int spacePartitionGridSize;
	bool unused;
	static void ClearVariableMapList();
	void InitCollision();

	friend class Particle;

public:
	// temporarily public
	void  DisplayMap();
	// move to private later

	//Array<node*> alarmList;
    Map();
	Map(const Map &);
	Map(const char*,const char*, MapType,int = 0,int = 0,int = 0,bool = true); 
	~Map();
	static Map* Search(const char *);        
	void Name(const char *);
    const char *Name();
	void FileName(const char*);
	const char* FileName();
	void SetMapType(MapType);
	//Array<node*> collisionList; 
	unsigned int Height();
    unsigned int Width();
    float WorldPositionX();
	float WorldPositionY();
	bool  IsMasterMap();
	void  TransparencyColor(COLORREF);
	COLORREF TransparencyColor();
	bool  UseTransparency();
	void  UseTransparency(bool);
	void  SpeedX(float);
	void  SpeedY(float);
	float SpeedX();
	float SpeedY();
	int   Id();		
    int  ViewPortX();
	int  ViewPortY();
	void  Visible(bool); 
	bool  Visible();
	void  ScrollRatioX(float);
	void  ScrollRatioY(float);
	float ScrollRatioX();
	float ScrollRatioY();
	int  ZOrder();
	void  WorldPositionXInc(float,float);
	void  WorldPositionXDec(float,float);
	void  WorldPositionYInc(float,float);
	void  WorldPositionYDec(float,float);
	void  WorldPositionX(float);
	void  WorldPositionY(float);
	void ShowMapCollision(bool);
	bool Add(Alarm);
	bool Add(Alarm *);
	void AlarmMaximum(int);
	int  AlarmMaximum(void);
	int  AlarmCount(void);
	void AddCollisionData(CollisionSegment);
	void AddCollisionData(CollisionCircle);	
	void RemoveCollisionData(unsigned int,unsigned int = BOTH);
	void InitGrid();
	void SpacePartitionGridSize(unsigned int);
	int SpacePartitionGridSize();
	void AddLocalVariable(unsigned int);
	//Array<Array<Array<node*>>> gridLists;  // access looks like: Array<node *> items = gridLists[x][y];
	
	//Array<Variable *> mapVariableList;
	Behavior behavior;
	void Unused(bool);
	bool Unused();
	void Pause(bool);
	bool Pause();
	void Use(const char *);
	Map  * CreateMap();
	node * Clone();
	void Load(File &);
	void Save(File &);
	DYNCREATED

};

class   MapPTR
{
	Map *mapPtr;
	static Map * dummyMapPtr;
public:
	MapPTR(); 
	MapPTR(Map *);
	MapPTR(const char *);
	Map * operator->();
	Map & operator*();
	MapPTR & operator=(Map *);
	operator Map *();
};

#endif 


