#ifndef _CLIP_H_
#define _CLIP_H_

#include "Constants.h"

	enum {TOPC=0X01, BOTTOMC=0X02, RIGHTC=0X04, LEFTC=0X08};
	typedef unsigned int outcode;

	//-------------------------------------------------------------------------
	//Definition:	The first four arguments of this function are the coordinates
	//		of the ending points of the line 
	//		The second four arguments are another line
	//		This function test if the lines intersect
	//Arguments:	Eight float
	//Modifies what:None
	//Functions calling this function:
	//				Sprite::CheckMapCollision()
	//Functions called by this function:
	//				CompOutCode(float,float,float,float,float,float)
	//Example:
	//-------------------------------------------------------------------------
	bool CSLineOnLine(float, float, float, float, float, float, float, float);

	//-------------------------------------------------------------------------
	//Definition:	The first four arguments of this function are the coordinates
	//		of the ending points of the line 
	//		The second four arguments are the top-left and right-bottom
	//		points of the bounding box of the sprite
	//		This function test if the line intersect the rectangle BBox
	//Arguments:	Eight float
	//Modifies what:None
	//Functions calling this function:
	//				Sprite::CheckMapCollision()
	//Functions called by this function:
	//				CompOutCode(float,float,float,float,float,float)
	//Example:
	//-------------------------------------------------------------------------
	bool CSLineClipping(float,float,float,float,float,float,float,float);

	//-------------------------------------------------------------------------
	//Definition:	The first two arguments are the coordinates of a point, the
	//		last four arguments are the top-left and the right-bottom 
	//		points of a rectangle bounding box
	//		This function test if the point is inside or outside the 
	//		rectangle
	//Arguments:	six float
	//Modifies what:None
	//Functions calling this function:
	//				CSLineClipping(float,float,float,float,float,float,float,float)
	//Functions called by this function:
	//				None
	//Example:
	//-------------------------------------------------------------------------
	outcode CompOutCode(float,float,float,float,float,float);

	//-------------------------------------------------------------------------
	//Definition:	The first two arguments are the coordinates of the center of
	//				a circle, the third argument is the radius of the circle, the
	//				last four arguments are the top-left and the right-bottom 
	//				points of a rectangle bounding box
	//				This function test if the circle intersect with the rectangle
	//Arguments:	seven float
	//Modifies what:None
	//Functions calling this function:
	//				Sprite::CheckMapCollision()
	//Functions called by this function:
	//				None
	//Example:
	//-------------------------------------------------------------------------
	bool CSCircleClipping(float,float,float,float,float,float,float);

//	bool IntersectRectangles(const Rect &,const Rect &);
	bool IntersectRectangles1(const Rect &,const Rect &);
	bool IntersectRectangles2(Rect &,const Rect &,const Rect &);
	//bool IntersectRectangles3(const FRECT & ,const FRECT & );
	

#endif
