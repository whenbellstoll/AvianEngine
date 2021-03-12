#ifndef _COLLISIONDATA_H
#define _COLLISIONDATA_H
#include "Node.h"
#include "File.h"
#include "Clip.h"
enum CollisionType { ColSegment, ColCircle };

class CollisionData : public node
{
public:
	virtual CollisionType Type() = 0;
	virtual ~CollisionData() {}
};

class CollisionCircle;

class   CollisionSegment : public CollisionData
{
	float originX;
	float originY;
	float directionX;
	float directionY;
	float magnitudeX;
	float magnitudeY;
	int id;
	static bool ChopCandidateInterval(double&, double&, double, double);

public:
	CollisionSegment();
	CollisionSegment(const CollisionSegment&);
	CollisionSegment(float, float, float, float, float, float, int = 0, unsigned char = 0, int = 0);
	CollisionSegment(float, float, float, float, int = 0, unsigned char = 0, int = 0);
	CollisionSegment& operator=(const CollisionSegment& s);
	operator bool() const;
	node* Clone();
	int numPathState;
	float NorX;
	float NorY;
	float normalX;
	float normalY;
	float MinT;
	unsigned char segmentAttribute;
	bool edgeCollision;
	CollisionType Type();
	float OriginX();
	float OriginY();
	float DirectionX();
	float DirectionY();
	void DirectionX(float);
	void DirectionY(float);
	float MagnitudeX();
	float MagnitudeY();
	float NormalX();
	float NormalY();
	void NormalX(float);
	void NormalY(float);
	bool DetectCollision(CollisionSegment*, float worldpositionX1, float worldpositionY1, float worldpositionX2, float worldpositionY2, float vectX, float vectY, float speed);
	bool DetectCollision(CollisionCircle*, float worldpositionX1, float worldpositionY1, float worldpositionX2, float worldpositionY2, float vectX, float vectY, float speed);
	int Id();
	void Id(int);
	CollisionSegment OppositeSegmentDirection(CollisionSegment&);
	//static bool LineClippingConvexeShape(CollisionSegment &, List &);
	void OriginX(float);
	void OriginY(float);
	void* operator new(size_t);
	void   operator delete(void*);
	void Save(File&);
	void Load(File&);
	DYNCREATED
};

class   CollisionCircle :public CollisionData
{
	float originX;
	float originY;
	float radius;
	int id;
public:
	CollisionCircle(float = 0, float = 0, float = 0, int = 0, unsigned char = 0);
	CollisionCircle(const CollisionCircle& c);
	CollisionCircle& operator=(const CollisionCircle& s);
	node* Clone();
	float NorX;
	float NorY;
	float MinT;
	unsigned char circleAttribute;
	CollisionType Type();
	float OriginX();
	float OriginY();
	float Radius();
	bool DetectCollision(CollisionSegment*, float worldpositionX1, float worldpositionY1, float worldpositionX2, float worldpositionY2, float vectX, float vectY, float speed);
	bool DetectCollision(CollisionCircle*, float worldpositionX1, float worldpositionY1, float worldpositionX2, float worldpositionY2, float vectX, float vectY, float speed);
	int Id();
	void Id(int);
	void* operator new(size_t);
	void   operator delete(void*);
	void Save(File&);
	void Load(File&);
	DYNCREATED

};

#endif // !COLLISIONDATA_H



