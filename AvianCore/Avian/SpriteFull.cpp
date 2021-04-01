#include "SpriteFull.h"
#include "../globals.h"
// Private Methods
void Sprite::PegRegistered(int notused)
{
}

void Sprite::MapPositionForPGX(float)
{
}

void Sprite::MapPositionForPGY(float)
{
}

void Sprite::HandleLastFlipPR()
{
}

void Sprite::DisplaySprite()
{
	UpdateAnimation();
	// layer (what draws on top of what)
	glUniform1f(0, zOrder / 100.0f );

	// position
	glUniform1f(1, mapPositionX);
	glUniform1f(2, mapPositionY);

	// scale
	glUniform1f(3, scaleX);
	glUniform1f(4, scaleY);

	// transparent color
	GLint pos = glGetUniformLocation(global.program, "transparentB");
	if (pos != -1)
	{
		glUniform1f(pos, SpriteList[actorIndex].Animations[animation].Frames[frame].Transparency.b / 255.0f);
		glUniform1f(pos + 1, SpriteList[actorIndex].Animations[animation].Frames[frame].Transparency.g / 255.0f);
		glUniform1f(pos + 2, SpriteList[actorIndex].Animations[animation].Frames[frame].Transparency.r / 255.0f);

	}

	glBindTexture(GL_TEXTURE_2D, SpriteList[actorIndex].Animations[animation].Frames[frame].texture);
	glDrawArrays(GL_TRIANGLE_STRIP, SpriteList[actorIndex].Animations[animation].Frames[frame].startingVertex, 4);
}

void Sprite::CheckSpriteCollision(Sprite* s)
{

}

void Sprite::UpdateSprite()
{
	UpdateTranslation();
	DisplaySprite();
	behavior->Update((void *)this);
}

void Sprite::reflect(float x, float y)
{

}

void Sprite::FrictionFactor()
{

}

void Sprite::UpdateTranslation()
{

}

void Sprite::UpdateAnimation()
{
	
	float frameElapsed = 60 * dt; // assume 60 fps for now
	delay -= frameElapsed;
	
	if (delay <= 0)
	{
		frame++;
		if (frame >= SpriteList[actorIndex].Animations[animation].TotalFrames)
		{
			frame = 0;
		}
		delay = SpriteList[actorIndex].Animations[animation].Frames[frame].Delay;
	}
}

void Sprite::ResetMapCollisionFlag()
{
}

void Sprite::FlipSet()
{

}

void Sprite::GetTranslation()
{

}

void Sprite::CannedFactor()
{

}

void Sprite::HandleAlarms()
{
	// not yet
}

void Sprite::UpdateMovementPattern()
{
}

void Sprite::GravityFactor()
{
}


bool Sprite::TempCheckCollisionWithMap(float, float, float, float)
{
	return false;
}

bool Sprite::TempCheckCollisionWithMap(float, float, float, float, int)
{
	return false;
}

bool Sprite::TempCheckCollisionWithSprite(float x, float y, float px, float py)
{
	return false;
}

Sprite* Sprite::TempCheckCollisionWithSprite(float px, float py, float cpx, float cpy, const char* name )
{
	return nullptr;
}

//Public Methods

Sprite::Sprite()
{
	zOrder = 0;
	mapPositionX = 0.0f;
	mapPositionY = 0.0f;
	scaleX = 1.0f;
	scaleY = 1.0f;
	animation = 0;
}

Sprite::Sprite(Sprite* s)
{
}

Sprite& Sprite::operator=(const Sprite& s)
{
	// TODO: insert return statement here
	return *this;
}

Sprite::Sprite(const Sprite& s)
{
	zOrder = 0;
	mapPositionX = 0.0f;
	mapPositionY = 0.0f;
	scaleX = 1.0f;
	scaleY = 1.0f;
	animation = 0;
}

Sprite::~Sprite()
{
}

void Sprite::Unused(bool b)
{
	unused = b;
}

bool Sprite::Unused()
{
	return unused;
}

void Sprite::Use(const char* c)
{
}

Sprite* Sprite::Search(const char* c)
{
	return nullptr;
}

Sprite* Sprite::Search(const int i)
{
	return nullptr;
}

void Sprite::CheckSameDisplayList(bool)
{
}

bool Sprite::CheckSameDisplayList()
{
	return false;
}

void Sprite::CheckSameType(bool)
{
}

bool Sprite::CheckSameType()
{
	return false;
}

void Sprite::CheckCollisionWithSprite(bool)
{
}

bool Sprite::CheckCollisionWithSprite()
{
	return false;
}

void Sprite::GhostCollisionWithSprite(bool)
{
}

bool Sprite::GhostCollisionWithSprite()
{
	return false;
}

void Sprite::GhostCollisionWithMap(bool)
{
}

bool Sprite::GhostCollisionWithMap()
{
	return false;
}

void Sprite::ChangePathState(unsigned int)
{
}

unsigned int Sprite::NearestStationNumber(bool)
{
	return 0;
}

float Sprite::TranslationX()
{
	return 0.0f;
}

float Sprite::TranslationY()
{
	return 0.0f;
}

float Sprite::Speed()
{
	return 0.0f;
}

void Sprite::Speed(float)
{
}

void Sprite::SpeedDec(float, float)
{
}

void Sprite::SpeedInc(float, float)
{
}

bool Sprite::SpeedGreater(float)
{
	return false;
}

bool Sprite::SpeedGreaterEqual(float)
{
	return false;
}

bool Sprite::SpeedLess(float)
{
	return false;
}

bool Sprite::SpeedLessEqual(float)
{
	return false;
}

const char* Sprite::Name()
{
	return name;
}

void Sprite::Name(const char* n)
{
	name = n;
}

void Sprite::Visible(bool)
{
}

bool Sprite::Visible()
{
	return false;
}

void Sprite::Visible(const char* name, bool vis)
{
}

void Sprite::DeleteFlag(bool b)
{
	toBeDeleted = b;
}

bool Sprite::DeleteFlag()
{
	return toBeDeleted;
}

void Sprite::Id(int)
{
}

int Sprite::Id()
{
	return 0;
}

void Sprite::MapPositionX(float x, bool b)
{
	if (!b)
	{
		
		mapPositionX = x;
		float realSpace = (mapPositionX + 1) * (global.width / 2);
		//se->Animations->Frames->BBox.left = realSpace;
		//se->Animations->Frames->BBox.right = realSpace + se->Animations->Frames->Width;
	}
}

void Sprite::MapPositionY(float y, bool b)
{
	if (!b)
	{
		
		mapPositionY = y;
		float realSpace = (-mapPositionY - 1) * (global.height / 2) * -1;
		//se->Animations->Frames->BBox.top = realSpace;
		//se->Animations->Frames->BBox.bottom = realSpace + se->Animations->Frames->Height;
	}
}

float Sprite::MapPositionX()
{
	return mapPositionX;
}

float Sprite::MapPositionY()
{
	return mapPositionY;
}

void Sprite::MapPosition(float x, float y, bool b)
{
	if (!b)
	{
		float realSpaceX = (x + 1) * (global.width / 2);
		//se->Animations->Frames->BBox.left = realSpaceX;
		//se->Animations->Frames->BBox.right = realSpaceX + se->Animations->Frames->Width;
		float realSpaceY = (y + 1) * (global.height / 2) * -1;
		//se->Animations->Frames->BBox.top = realSpaceY;
		//se->Animations->Frames->BBox.bottom = realSpaceY + se->Animations->Frames->Height;
		mapPositionX = x;
		mapPositionY = y;
	}
}

void Sprite::MapPositionXInc(float inc, float max, bool b)
{
}

void Sprite::MapPositionXDec(float dec, float min, bool b)
{
}

void Sprite::MapPositionYInc(float inc, float max, bool b)
{
}

void Sprite::MapPositionYDec(float dec, float min, bool b)
{
}

float Sprite::LeftPosition()
{
	return 0.0f;
}

float Sprite::TopPosition()
{
	return 0.0f;
}

float Sprite::WorldPositionX()
{
	return 0.0f;
}

float Sprite::WorldPositionY()
{
	return 0.0f;
}

void Sprite::WorldPositionX(float x, bool b)
{
	if (!b)
	{
		mapPositionX = x;
	}

}

void Sprite::WorldPositionY(float y, bool b)
{
	if (!b)
	{
		mapPositionY = y;
	}
}

void Sprite::WorldPosition(float x, float y, bool b)
{

}

void Sprite::WorldPositionXInc(float inc, float max, bool b)
{
}

void Sprite::WorldPositionXDec(float dec, float min, bool b)
{
}

void Sprite::WorldPositionYInc(float inc, float max, bool b)
{
}

void Sprite::WorldPositionYDec(float dec, float min, bool b)
{
}

void Sprite::ScaleX(float x)
{
	scaleX = x;
}

void Sprite::ScaleY(float y)
{
	scaleY = y;
}

float Sprite::ScaleX()
{
	return scaleX;
}

float Sprite::ScaleY()
{
	return scaleY;
}

void Sprite::ZOrder(unsigned int i)
{
	zOrder = i;
}

unsigned int Sprite::ZOrder()
{
	return zOrder;
}

void Sprite::Canned(bool b)
{
	canned = b;
}

bool Sprite::Canned()
{
	return canned;
}

bool Sprite::Pause()
{
	return pauseSprite;
}

void Sprite::Pause(bool b)
{
	pauseSprite = b;
}

void Sprite::Animation(int i)
{
	if (i != animation)
	{
		animation = i;
		frame = 0;
	}

	if (animation >= SpriteList[actorIndex].TotalAnimations || animation <= 0 )
	{
		animation = 0;
	}
}

int Sprite::Animation()
{
	return animation;
}

void Sprite::Frame(int i)
{
	frame = i;
	if (animation >= SpriteList[actorIndex].TotalAnimations || animation <= 0)
	{
		frame = 0;
	}
}

int Sprite::TotalAnimations()
{
	return SpriteList[actorIndex].TotalAnimations;
}

int Sprite::TotalFrames()
{
	return SpriteList[actorIndex].Animations[animation].TotalFrames;
}

int Sprite::Frame()
{
	return frame;
}

bool Sprite::EndOfAnimation(int i)
{
	return (delay <= 0 && i == animation && frame == (SpriteList[actorIndex].Animations[animation].TotalFrames - 1) );
}

void Sprite::Delay(unsigned int ui)
{
	delay = ui;
}

float Sprite::Delay()
{
	return delay;
}

void Sprite::ActorIndex(int i)
{
	actorIndex = i;
	if (i <= 0 || i > MAXACTORS)
	{
		actorIndex = 0;
	}
}

int Sprite::ActorIndex()
{
	return actorIndex;
}

bool Sprite::CollisionWithSprite(const char* n)
{
	return false;
}

void Sprite::Reflection(bool b)
{
	reflection = b;
}

bool Sprite::InViewport()
{
	return false;
}

unsigned int Sprite::CannedDirection()
{
	return 0;
}

void Sprite::CannedDirection(unsigned int direction)
{
}

void Sprite::VectorDirection(float x, float y, unsigned int mag)
{
}

void Sprite::VectorAngle(float ang, float gaming)
{
}

float Sprite::VectorAngle()
{
	return 0.0f;
}

void Sprite::VariableNumber(int i)
{
}

int Sprite::VariableNumber()
{
	return 0;
}

float Sprite::DirectionX()
{
	return directionX;
}

float Sprite::DirectionY()
{
	return directionY;
}

bool Sprite::CollisionWithMap()
{
	return false;
}

void Sprite::CollisionWithMap(bool b)
{
}

void Sprite::MainCharacter(bool b)
{
	mainCharacter = b;
}

bool Sprite::MainCharacter()
{
	return mainCharacter;
}

void Sprite::CheckCollisionWithMap(bool b)
{
	mapCollision = b;
}

bool Sprite::CheckCollisionWithMap()
{
	return mapCollision;
}

void Sprite::DisplayListNumber(int i)
{
	displayListNumber = i;
}

int Sprite::DisplayListNumber()
{
	return displayListNumber;
}

void Sprite::DoNotCutDirection(bool b)
{
	doNotCutDirection = b;
}

bool Sprite::DoNotCutDirection()
{
	return doNotCutDirection;
}

void Sprite::BelongToMap(const char* n)
{
	
}

const char* Sprite::BelongToMap()
{
	return nullptr;
}

void Sprite::CannedHDirection(bool b)
{
	cannedHDirection = b;
}

bool Sprite::CannedHDirection()
{
	return cannedHDirection;
}

void Sprite::CannedVDirection(bool b)
{
	cannedVDirection = b;
}

bool Sprite::CannedVDirection()
{
	return cannedVDirection;
}

float Sprite::HotSpotX(int)
{
	return 0.0f;
}

float Sprite::HotSpotY(int)
{
	return 0.0f;
}

bool Sprite::AddAlarm(const char*)
{
	return false;
}

void Sprite::AlarmMaximum(int)
{
}

int Sprite::AlarmMaximum()
{
	return 0;
}

int Sprite::AlarmCount()
{
	return 0;
}

Sprite* Sprite::CreateSprite()
{
	return nullptr;
}

void Sprite::Friction(float)
{
}

bool Sprite::Reflection()
{
	return false;
}

bool Sprite::CollisionType()
{
	return false;
}

void Sprite::CollisionType(bool)
{
}

void Sprite::ShowSpriteCollision(bool b)
{
}

void Sprite::ShowSpriteBoundingBox(bool)
{
}

void Sprite::PegRegistered(bool)
{
}

bool Sprite::PegRegistered()
{
	return false;
}

void Sprite::ShowVectorOfTranslation(bool)
{
}

int Sprite::ViewportX()
{
	return 0;
}

int Sprite::ViewportY()
{
	return 0;
}

bool Sprite::CollisionWithMap(int i)
{
	return false;
}

bool Sprite::CollisionWithSprite(int i)
{
	return false;
}

bool Sprite::Collision(int i)
{
	return false;
}

void Sprite::ActivateCollisionWithSprite(bool b)
{
	activateCollisionWithSprite = b;
}

bool Sprite::ActivateCollisionWithSprite()
{
	return activateCollisionWithSprite;
}

void Sprite::Follow(Sprite* s, unsigned int i, unsigned int , unsigned int)
{
}

void Sprite::Follow(const String, unsigned int, unsigned int, unsigned int)
{
}

float Sprite::Distance(Sprite* s)
{
	return 0.0f;
}

float Sprite::DistanceX(Sprite*)
{
	return 0.0f;
}

float Sprite::DistanceY(Sprite*)
{
	return 0.0f;
}

float Sprite::DifferenceX(Sprite*)
{
	return 0.0f;
}

float Sprite::DifferenceY(Sprite*)
{
	return 0.0f;
}

bool Sprite::Left(Sprite*)
{
	return false;
}

bool Sprite::Right(Sprite*)
{
	return false;
}

bool Sprite::Up(Sprite*)
{
	return false;
}

bool Sprite::Down(Sprite*)
{
	return false;
}

bool Sprite::SameHFlip(Sprite*)
{
	return false;
}

bool Sprite::SameVFlip(Sprite*)
{
	return false;
}

bool Sprite::HFlip()
{
	return false;
}

bool Sprite::VFlip()
{
	return false;
}

void Sprite::HFlip(bool)
{
}

void Sprite::VFlip(bool)
{
}

void Sprite::AutoFlip(bool)
{
}

bool Sprite::AutoFlip()
{
	return false;
}

bool Sprite::OwnerCollisionDataFlagBit(unsigned int)
{
	return false;
}

bool Sprite::SpriteCollisionDataFlagBit(unsigned int)
{
	return false;
}

bool Sprite::MapCollisionDataFlagBit(unsigned int)
{
	return false;
}

int Sprite::FrameCenterX()
{
	return 0;
}

int Sprite::FrameCenterY()
{
	return 0;
}

unsigned int Sprite::Width()
{
	return 0;
}

unsigned int Sprite::Height()
{
	return 0;
}

bool Sprite::InWorld()
{
	return false;
}

void Sprite::ChangeSFX(int, const char*)
{
}

void Sprite::DeleteSFX(int)
{
}

void Sprite::AnimationLoopSFX(int, bool)
{
}

void Sprite::AnimationSoundStatus(int, bool)
{
}

void Sprite::ShortestPath(unsigned int)
{
}

void Sprite::StopShortestPath()
{
}

bool Sprite::EndOfShortestPath()
{
	return false;
}

void Sprite::EnablePath(bool)
{
}

bool Sprite::EnablePath()
{
	return false;
}

void Sprite::ApplyPathStateMachine(unsigned int)
{
}

void Sprite::MainCharWorldPosition(float x, float y)
{
}

void Sprite::ShowPath(bool)
{
}

bool Sprite::ShowPath()
{
	return false;
}

void Sprite::Save(File&)
{
}

void Sprite::Load(File&)
{
}

Sprite* Sprite::LookAheadCollisionWithSprite(unsigned int, unsigned int, const char*)
{
	return nullptr;
}

bool Sprite::LookAheadCollisionWithMap(unsigned int, unsigned int, int)
{
	return false;
}

Sprite* Sprite::CollisionWithSpritePtr(const char*)
{
	return nullptr;
}

bool Sprite::CollisionWithPath()
{
	return false;
}

void Sprite::MovementPatternLoop(bool)
{
}

bool Sprite::MovementPatternLoop()
{
	return false;
}

void Sprite::ApplyMovementPattern(int)
{
}

void Sprite::ShowMovementPattern(bool)
{
}

bool Sprite::ShowMovementPattern()
{
	return false;
}

void Sprite::StartMovementPattern(bool, bool)
{
}

void Sprite::StartMovementPattern(bool)
{
}

void Sprite::StopMovementPattern()
{
}

bool Sprite::EndOfMovementPattern()
{
	return false;
}

bool Sprite::ApplyingMovementPattern()
{
	return false;
}

const char* Sprite::MovementPatternName()
{
	return nullptr;
}

bool Sprite::Gravity()
{
	return false;
}

void Sprite::Gravity(bool, float)
{
}

void Sprite::GravityFriction(float)
{
}

float Sprite::GravityFriction()
{
	return 0.0f;
}

void Sprite::AddLocalVariable(unsigned int)
{
}

void* Sprite::operator new(size_t)
{
	return nullptr;
}

void Sprite::operator delete(void*)
{
}

float Sprite::SpeedX()
{
	return 0.0f;
}

void Sprite::SpeedX(float)
{
}

float Sprite::SpeedY()
{
	return 0.0f;
}

void Sprite::SpeedY(float)
{
}

void Sprite::SpeedXDec(float, float)
{
}

void Sprite::SpeedXInc(float, float)
{
}

void Sprite::SpeedYDec(float, float)
{
}

void Sprite::SpeedYInc(float, float)
{
}

void Sprite::GhostCollision(bool)
{
}

bool Sprite::GhostCollision()
{
	return false;
}

bool Sprite::LookAheadCollision(unsigned int, unsigned int, unsigned int)
{
	return false;
}

DYNCREATEIMP(Sprite);


// SpritPTR Locator

SpritePTR::SpritePTR()
{
}

SpritePTR::SpritePTR(Sprite*)
{
}

SpritePTR::SpritePTR(const char*)
{
}

Sprite* SpritePTR::operator->()
{
	return nullptr;
}

Sprite& SpritePTR::operator*()
{
	// TODO: insert return statement here
	return *spritePtr;
}

SpritePTR& SpritePTR::operator=(Sprite*)
{
	// TODO: insert return statement here
	return *this;
}

SpritePTR::operator Sprite* ()
{
	return *this;
}


