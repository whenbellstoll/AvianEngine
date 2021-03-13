#include "../globals.h"

// this function is for spatial optimization, not quite there yet
bool CollisionSegment::ChopCandidateInterval(double&, double&, double, double)
{
	return false;
}

CollisionSegment::CollisionSegment()
{
	originX = 0;
	originY = 0;
	magnitudeX = 0;
	magnitudeY = 0;
	segmentAttribute = 0;
	id = 0;
	numPathState = 0;
	edgeCollision = false;
	directionX = 0;
	directionY = 0;
	normalX = 0;
	normalY = 0;
	NorX = 0;
	NorY = 0;
	MinT = 0;
}

CollisionSegment::CollisionSegment(const CollisionSegment& cs)
{
	originX = cs.originX;
	originY = cs.originY;
	magnitudeX = cs.magnitudeX;
	magnitudeY = cs.magnitudeY;
	segmentAttribute = cs.segmentAttribute;
	id = cs.id;
	numPathState = cs.numPathState;
	edgeCollision = cs.edgeCollision;
	directionX = cs.directionX;
	directionY = cs.directionY;
	normalX = cs.normalX;
	normalY = cs.normalY;
	NorX = cs.NorX;
	NorY = cs.NorY;
	MinT = cs.MinT;
}

// I've never used this constructor I've forgotten what the two extra floats are for, assuming NorX and NorY for now
CollisionSegment::CollisionSegment(float x1, float y1, float x2, float y2, float nx, float ny, int idi , unsigned char c, int ii)
{
	originX = x1;
	originY = y1;
	magnitudeX = x2 - x1;
	magnitudeY = y2 - y1;
	segmentAttribute = c;
	id = idi;
	numPathState = ii;
	edgeCollision = true;
	float length = sqrt(((double)magnitudeX * (double)magnitudeX) + ((double)magnitudeY * (double)magnitudeY));
	directionX = magnitudeX / length;
	directionY = magnitudeY / length;
	magnitudeX = length;
	magnitudeY = length;
	normalX = -directionY;
	normalY = directionX;
	NorX = nx;
	NorY = ny;
	MinT = 1.5f;
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
	float length = sqrt( ((double)magnitudeX * (double)magnitudeX) + ((double)magnitudeY * (double)magnitudeY) );
	directionX = magnitudeX / length;
	directionY = magnitudeY / length;
	magnitudeX = length;
	magnitudeY = length;
	normalX = -directionY;
	normalY = directionX;
	NorX = 200;
	NorY = 200;
	MinT = 1.5f;

}

CollisionSegment& CollisionSegment::operator=(const CollisionSegment& cs)
{
	originX = cs.originX;
	originY = cs.originY;
	magnitudeX = cs.magnitudeX;
	magnitudeY = cs.magnitudeY;
	segmentAttribute = cs.segmentAttribute;
	id = cs.id;
	numPathState = cs.numPathState;
	edgeCollision = cs.edgeCollision;
	directionX = cs.directionX;
	directionY = cs.directionY;
	normalX = cs.normalX;
	normalY = cs.normalY;
	NorX = cs.NorX;
	NorY = cs.NorY;
	MinT = cs.MinT;
	return *this;
}	
CollisionSegment::operator bool() const
{
	return false;
}

node* CollisionSegment::Clone()
{
	return new CollisionSegment(*this);
}

CollisionType CollisionSegment::Type()
{
	return CollisionType::ColSegment;
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
	// Function written with assumption that cs is the stationary collider and we are the ones moving.
	// we need to do some normal checking here
	// For the collision segment that is moving, we check if the movement is against its normals
	// Ex:		
	//     ____|____|____  Will not collide with anything
	//          ||
	//			\/
	// For the collision that is stationary, we check if the movement is aligned with its normals
	//Ex:
	//		|
	//		|
	//     --
	//		|	 <= ___|___|___		Will not collide
	//		|
	//	   --
	//		|
	//		|
	if (vectX > 0 && (normalX < 0 || cs->NormalX() > 0) )
	{
		return false;
	}
	else if (vectX < 0 && (normalX > 0 || cs->NormalX() < 0))
	{
		return false;
	}
	
	if (vectY > 0 && (normalY < 0 || cs->NormalY() > 0))
	{
		return false;
	}
	else if (vectY < 0 && (normalY > 0 || cs->NormalY() < 0))
	{
		return false;
	}



	float x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;
	x1 = originX + worldpositionX1;
	x2 = x1 + (directionX * magnitudeX);
	y1 = originY + worldpositionY1;
	y2 = y1 + (directionY * magnitudeY);

	x3 = cs->OriginX() + worldpositionX2;
	x4 = x3 + (cs->DirectionX() * cs->MagnitudeX());
	y3 = cs->OriginY() + worldpositionY2;
	y4 = y3 + (cs->DirectionY() * cs->MagnitudeY());

	// projected line
	x5 = x1 + (vectX * speed);
	x6 = x2 + (vectX * speed);
	y5 = y1 + (vectY * speed);
	y6 = y2 + (vectY * speed);

	// treat the projection as a box and check all four sides
	return(
		CSLineOnLine(x1, y1, x2, y2, x3, y3, x4, y4) || // original lines
		CSLineOnLine(x3, y3, x4, y4, x5, y5, x6, y6) || // this line vs projection
		CSLineOnLine(x3, y3, x4, y4, x3, y3, x5, y5) ||
		CSLineOnLine(x3, y3, x4, y4, x6, y6, x4, y4)
		);

}

bool CollisionSegment::DetectCollision(CollisionCircle* cc, float worldpositionX1, float worldpositionY1, float worldpositionX2, float worldpositionY2, float vectX, float vectY, float speed)
{
	if (vectX > 0 && normalX < 0 )
	{
		return false;
	}
	else if (vectX < 0 && normalX > 0 )
	{
		return false;
	}

	if (vectY > 0 && normalY < 0 )
	{
		return false;
	}
	else if (vectY < 0 && normalY > 0 )
	{
		return false;
	}



	float x1, y1, x2, y2, x3, y3, x4, y4;
	x1 = originX + worldpositionX1;
	x2 = x1 + (directionX * magnitudeX);
	y1 = originY + worldpositionY1;
	y2 = y1 + (directionY * magnitudeY);

	// projected line
	x3 = x1 + (vectX * speed);
	x4 = x2 + (vectX * speed);
	y3 = y1 + (vectY * speed);
	y4 = y2 + (vectY * speed);
	
	float ccX = cc->OriginX() + worldpositionX2;
	float ccY = cc->OriginY() + worldpositionY2;



	// treat the projection as a box and check all four sides
	return(
		CSCircleClipping(ccX, ccY, cc->Radius(), x1, , , float bottomY) // original lines
		);
}

int CollisionSegment::Id()
{
	return id;
}

void CollisionSegment::Id(int i)
{
	id = i;
}

CollisionSegment CollisionSegment::OppositeSegmentDirection(CollisionSegment& cs)
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
	p = MEMPACK_AllocMem(&global.ramPack, st, "CollisionSegment");
	return p;
}

void CollisionSegment::operator delete(void* v)
{
	return;
}

void CollisionSegment::Save(File& f)
{
}

void CollisionSegment::Load(File& f)
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
	MinT = 1.5f;
	NorX = 200;
	NorY = 200;
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
	return new CollisionCircle(*this);
}

CollisionType CollisionCircle::Type()
{
	return CollisionType::ColCircle;
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

bool CollisionCircle::DetectCollision(CollisionSegment* cs, float worldpositionX1, float worldpositionY1, float worldpositionX2, float worldpositionY2, float vectX, float vectY, float speed)
{
	return false;
}

bool CollisionCircle::DetectCollision(CollisionCircle* cs, float worldpositionX1, float worldpositionY1, float worldpositionX2, float worldpositionY2, float vectX, float vectY, float speed)
{
	return false;
}

int CollisionCircle::Id()
{
	return id;
}

void CollisionCircle::Id(int i)
{
	id = i;
}

void* CollisionCircle::operator new(size_t st)
{
	void* p;
	p = MEMPACK_AllocMem(&global.ramPack, st, "CollisionCircle");
	return p;
}

void CollisionCircle::operator delete(void*)
{
	return;
}

void CollisionCircle::Save(File&)
{
}

void CollisionCircle::Load(File&)
{
}

const char* CollisionCircle::ClassName()
{
	return "CollisionCircle";
}

const char* CollisionSegment::ClassName()
{
	return "CollisionSegment";
}

