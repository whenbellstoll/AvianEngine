#include "SpriteList.h"

//Frame Element
FrameElem::FrameElem()
{
	ImageName = "";
	TranslateX = 0.0f;
	TranslateY = 0.0f;
	Delay = 0;
	Width = 0;
	Height = 0;
	Transparency = RGB(0, 0, 0);
	hFlip = false;
	vFlip = false;
	zRotation = 0;
	BBox.top = 0;
	BBox.left = 0;
	BBox.bottom = 0;
	BBox.right = 0;
	centerX = 0;
	centerY = 0;
	PegRegistered = false;
	useTransparency = true;
}

FrameElem::~FrameElem()
{

}

void FrameElem::hFBoundingBox()
{

}

void FrameElem::vFBoundingBox()
{

}

void FrameElem::hvFBoundingBox()
{

}

void FrameElem::AddCollisionData(CollisionSegment cs)
{

}

void FrameElem::AddCollisionData(CollisionCircle cc)
{

}

void FrameElem::hFCollisionList()
{

}

void FrameElem::vFCollisionList()
{

}

void FrameElem::hvFCollisionList()
{

}

void FrameElem::hFCenter()
{

}

void FrameElem::vFCenter()
{

}

void FrameElem::hvFCenter()
{

}

void FrameElem::FrameFlippingMoves()
{
}


void* FrameElem::operator new[](size_t st)
{
	return nullptr;
}

void FrameElem::operator delete[](void* v)
{
}


// Animation Element
AnimationElem::AnimationElem()
{
}

AnimationElem::~AnimationElem()
{
}

void* AnimationElem::operator new[](size_t st)
{
	return nullptr;
}

void AnimationElem::operator delete[](void* v)
{
}

// Sprite Element
SpriteElem::SpriteElem()
{
}

SpriteElem::~SpriteElem()
{
}
