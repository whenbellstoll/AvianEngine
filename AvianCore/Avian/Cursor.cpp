#include "Cursor.h"



DYNCREATEIMP(Cursor);

void Cursor::__InternalCursorFct()
{
}

Cursor::Cursor()
{
}

Cursor::~Cursor()
{
}

void Cursor::DefaultActor()
{
}

void Cursor::ShowCollisionData(bool b) 
{
}

void Cursor::ShowBoundingBox(bool b)
{
}

const char* Cursor::Name()
{
	return name;
}

void Cursor::AddSpriteCursor(unsigned int, unsigned int, unsigned int, bool)
{
}

void Cursor::AddLocalVariable(unsigned int index)
{
}

void Cursor::Animation(unsigned int i)
{
}

unsigned int Cursor::Animation()
{
	return 0;
}

void Cursor::Frame(unsigned int i)
{
}

unsigned int Cursor::Frame()
{
	return 0;
}

void Cursor::Delay(unsigned int i)
{
}

unsigned int Cursor::Delay()
{
	return 0;
}

bool Cursor::CollisionWithSprite(const char*)
{
	return false;
}

bool Cursor::CollisionWithMap()
{
	return false;
}

bool Cursor::CollisionWithMap(int)
{
	return false;
}

void Cursor::ViewportPositionX(unsigned int, bool)
{
}

void Cursor::ViewportPositionY(unsigned int, bool)
{
}

void Cursor::ViewportPosition(unsigned int, unsigned int, bool)
{
}

unsigned int Cursor::ViewportPositionX()
{
	return 0;
}

unsigned int Cursor::ViewportPositionY()
{
	return 0;
}

bool Cursor::IsTriggeredOnSprite(const char*, unsigned char)
{
	return false;
}

bool Cursor::IsPressedOnSprite(const char*, unsigned char)
{
	return false;
}

bool Cursor::IsTriggeredOnMap(int, unsigned char)
{
	return false;
}

bool Cursor::IsPressedOnMap(int, unsigned char)
{
	return false;
}

bool Cursor::InRect(Rect)
{
	return false;
}

void Cursor::Save(File&)
{
}

void Cursor::Load(File&)
{
}
