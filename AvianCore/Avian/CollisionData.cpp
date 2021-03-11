#include "CollisionData.h"

bool CollisionSegment::ChopCandidateInterval(double&, double&, double, double)
{
	return false;
}

CollisionSegment::CollisionSegment()
{
}

CollisionSegment::CollisionSegment(const CollisionSegment&)
{
}

CollisionSegment::CollisionSegment(float x1, float y1, float x2, float y2, float nx, float ny, int idi , unsigned char c, int ii)
{
}

CollisionSegment::CollisionSegment(float x1, float y1, float x2, float y2, int idi, unsigned char c, int i)
{
	originX = x1;
	originY = y1;
	magnitudeX = x2 - x1;
	magnitudeY = y2 - y1;
	segmentAttribute = c;
	id = idi;
	numPathState = i;
	edgeCollision = true;
	normalX = magnitudeY;
	normalY = -magnitudeX;
}

CollisionSegment& CollisionSegment::operator=(const CollisionSegment& s)
{
	// TODO: insert return statement here
}

CollisionSegment::operator bool() const
{
}

node* CollisionSegment::Clone()
{
	return nullptr;
}

ClassType CollisionSegment::Type()
{
	return ClassType::ColSegment;
}

float CollisionSegment::OriginX()
{
	return originX;
}

float CollisionSegment::OriginY()
{
	return originY;
}

float CollisionSegment::DirectionX()
{
	return directionX;
}

float CollisionSegment::DirectionY()
{
	return directionY;
}

void CollisionSegment::DirectionX(float dx)
{
	directionX = dx;
}

void CollisionSegment::DirectionY(float dy)
{
	directionY = dy;
}

float CollisionSegment::MagnitudeX()
{
	return magnitudeX;
}

float CollisionSegment::MagnitudeY()
{
	return magnitudeY;
}

float CollisionSegment::NormalX()
{
	return normalX;
}

float CollisionSegment::NormalY()
{
	return normalY;
}

void CollisionSegment::NormalX(float nx)
{
	normalX = nx;
}

void CollisionSegment::NormalY(float ny)
{
	normalY = ny;
}

bool CollisionSegment::DetectCollision(CollisionSegment* cs, float worldpositionX1, float worldpositionY1, float worldpositionX2, float worldpositionY2, float vectX, float vectY, float speed)
{
	return false;
}

bool CollisionSegment::DetectCollision(CollisionCircle*, float worldpositionX1, float worldpositionY1, float worldpositionX2, float worldpositionY2, float vectX, float vectY, float speed)
{
	return false;
}

int CollisionSegment::Id()
{
	return id;
}

void CollisionSegment::Id(int i)
{
	id = i;
}

CollisionSegment CollisionSegment::OppositeSegmentDirection(CollisionSegment&)
{
	return CollisionSegment();
}

void CollisionSegment::OriginX(float ox)
{
	originX = ox;
}

void CollisionSegment::OriginY(float oy)
{
	originY = oy;
}

void* CollisionSegment::operator new(size_t st)
{
	void* p;
	return p;
}

void CollisionSegment::operator delete(void* v)
{
}

void CollisionSegment::Save(File& f)
{
}

void CollisionSegment::Load(File&)
{
}

//
// Collision Circle
//


CollisionCircle::CollisionCircle(float x, float y, float r, int i, unsigned char a)
{
	originX = x;
	originY = y;
	radius = r;
	id = i;
	circleAttribute = a;
}

CollisionCircle::CollisionCircle(const CollisionCircle& c)
{
	originX = c.originX;
	originY = c.originY;
	radius = c.radius;
	id = c.id;
	circleAttribute = c.circleAttribute;
	NorX = c.NorX;
	NorY = c.NorY;
	MinT = c.MinT;
}

CollisionCircle& CollisionCircle::operator=(const CollisionCircle& s)
{
	originX = s.originX;
	originY = s.originY;
	radius = s.radius;
	id = s.id;
	circleAttribute = s.circleAttribute;
	NorX = s.NorX;
	NorY = s.NorY;
	MinT = s.MinT;
	
}

node* CollisionCircle::Clone()
{
	return nullptr;
}

ClassType CollisionCircle::Type()
{
	return ClassType::ColCircle;
}

float CollisionCircle::OriginX()
{
	return originX;
}

float CollisionCircle::OriginY()
{
	return originY;
}

float CollisionCircle::Radius()
{
	return radius;
}

bool CollisionCircle::DetectCollision(CollisionSegment*, float worldpositionX1, float worldpositionY1, float worldpositionX2, float worldpositionY2, float vectX, float vectY, float speed)
{
	return false;
}

bool CollisionCircle::DetectCollision(CollisionCircle*, float worldpositionX1, float worldpositionY1, float worldpositionX2, float worldpositionY2, float vectX, float vectY, float speed)
{
	return false;
}

int CollisionCircle::Id()
{
	return 0;
}

void CollisionCircle::Id(int)
{
}

void* CollisionCircle::operator new(size_t)
{
	return nullptr;
}

void CollisionCircle::operator delete(void*)
{
}

void CollisionCircle::Save(File&)
{
}

void CollisionCircle::Load(File&)
{
}
