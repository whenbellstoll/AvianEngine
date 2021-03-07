#ifndef _SPRITELIST_H_
#define _SPRITELIST_H_

#include "Constants.h"
#include "List.h"
#include "CollisionData.h"
class Sound;

struct FImp;


class   FrameElem
{
public:
	FrameElem();
	virtual ~FrameElem();
	String ImageName;
	int	Width;
	int	Height;
	COLORREF Transparency;
	float TranslateX;
	float TranslateY;
	unsigned int Delay;
	FImp * pFImp;
	bool hFlip;
	bool vFlip;
	int zRotation;
	/* Hot Spot
	Point HotSpot[MAXHOTSPOTS];
	Point hFHotSpot[MAXHOTSPOTS];
	Point vFHotSpot[MAXHOTSPOTS];
	Point hvFHotSpot[MAXHOTSPOTS];
	void hFHotSpotArray();
	void vFHotSpotArray();
	void hvFHotSpotArray();
	*/
	Rect BBox;
	Rect hFBBox;
	Rect vFBBox;
	Rect hvFBBox;
	void hFBoundingBox();
	void vFBoundingBox();
	void hvFBoundingBox();
    //List collisionList;
	void AddCollisionData(CollisionSegment);
	void AddCollisionData(CollisionCircle);
	//List hFlipCollisionList;
	//List vFlipCollisionList;
	//List hvFlipCollisionList;
	void hFCollisionList();
	void vFCollisionList();
	void hvFCollisionList();
	float centerX;
	float centerdX;
	float hFcenterX;
	float vFcenterX;
	float hvFcenterX;
	float centerY;
	float centerdY;
	float hFcenterY;
	float vFcenterY;
	float hvFcenterY;
	void hFCenter();
	void vFCenter();
	void hvFCenter();
	void FrameFlippingMoves();
	bool  PegRegistered;
	bool  useTransparency;
	void * operator new[](size_t);
	void   operator delete[](void *);
};

class   AnimationElem
{
public:
	AnimationElem();
	virtual ~AnimationElem();
	unsigned int TotalFrames;
	FrameElem *Frames;
	int ConnectTo;
	Sound *soundPointer;
	bool loopSFX;
	bool soundStatus;
	void * operator new[](size_t);
	void   operator delete[](void *);
};

class   SpriteElem
{
public:
	SpriteElem();
	~SpriteElem();
	unsigned int TotalAnimations;
	AnimationElem *Animations;	
};


#endif