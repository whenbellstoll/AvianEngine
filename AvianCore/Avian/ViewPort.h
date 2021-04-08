#ifndef _VIEWPORT_H_
#define _VIEWPORT_H_

#include "Node.h"
struct   DeltaScroll
{
	float dx;
	float dy;
};

struct   FRECT
{
	float top,left,bottom,right;
	operator FRECT()
	{
		FRECT r;
		r.top    = (long)top;
		r.left   = (long)left;
		r.right  = (long)right;
		r.bottom = (long)bottom;
		return r;
	}
};

class   ViewPort : public node
{
	float worldWidth;
	float worldHeight;
	float maxViewPortWorldXPos;
	float maxViewPortWorldYPos;
	FRECT rect;
	FRECT viewPort;
	FRECT viewPort1;
	FRECT viewPortScrollingBB;
	FRECT initialBBClone;
	float maxInflateBBRight;
	float maxInflateBBLeft;
	float maxInflateBBTop;
	float maxInflateBBBottom;
	float	dSBBR;				
	float dSBBL;				
	float dSBBT;				
	float dSBBB;
	DeltaScroll deltaScroll;
	DeltaScroll deltaScroll1;
	
	friend class Sprite;
	friend void GameLoopBody();

public:

	ViewPort(float wW = 640,float wH = 480,float worldX = 0,float worldY = 0,float width = 640,float heigth = 480);
	float WorldWidth();
	float WorldHeight();
	void WorldWidth(float);
	void WorldHeight(float);
	void ViewPortWidth(float);
	void ViewPortHeight(float);
	float Width();
	float Height();
	float WorldXPos();
	float WorldYPos();
	float MaxViewPortWorldXPos();
	float MaxViewPortWorldYPos();
	void WorldXPos(float);
	void WorldYPos(float);
	float WorldRightPos();
	float WorldBottomPos(); 
	FRECT WorldRect();
	FRECT  IntWorldRect();
	FRECT Rect();
	const DeltaScroll & Scroll(float dx,float dy);
	const DeltaScroll & CurrentDeltaScroll();
	void ViewPortScrollingBB(float viewPortX,float viewPortY,float width,float heigth);
	float BBWidth();
	float BBHeigth();
	float BBWorldXPos();
	float BBWorldYPos();
	float BBWorldRightPos();
	float BBWorldBottomPos(); 
	FRECT BBWorldRect();
	float BBViewPortXPos();
	float BBViewPortYPos();
	float BBViewPortRightPos();
	float BBViewPortBottomPos(); 
	FRECT BBViewPortRect();
    float MaxInflateBBRight();
	float MaxInflateBBLeft();
	float MaxInflateBBTop();
	float MaxInflateBBBottom();
	void MaxInflateBBRight(float);
	void MaxInflateBBLeft(float);
	void MaxInflateBBTop(float);
	void MaxInflateBBBottom(float);
	float InflateBBRight(float);
	float InflateBBLeft(float);
	float InflateBBTop(float);
	float InflateBBBottom(float);
	FRECT InitialBBClone();
	void RestoreBB();
	void DisplayBB();
	DeltaScroll Offset(float x,float y,bool = true);
	void OffsetVPSBB(float x,float y);
	void Save(File &);
	void Load(File &);

	DYNCREATED
};


#endif