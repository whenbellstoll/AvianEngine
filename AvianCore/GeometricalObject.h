#ifndef __GEOMETRYDRAWN_H__
#define __GEOMETRYDRAWN_H__

class FUNCORE_API GeometricsDrawn : public node
{
public:
	GeometricsDrawn();
	~GeometricsDrawn();
	void Line(float,float,COLORREF =RGB(0,0,0));
	void Line(float,float,float,float,COLORREF =RGB(0,0,0));
	void Circle(float,float,float,COLORREF =RGB(0,0,0));	
};


#endif