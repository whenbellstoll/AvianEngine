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
	// layer (what draws on top of what)
	glUniform1f(0, zOrder / 100.0f );

	// position
	glUniform1f(1, mapPositionX);
	glUniform1f(2, mapPositionY);

	// scale
	glUniform1f(3, scaleX);
	glUniform1f(4, scaleY);

	glBindTexture(GL_TEXTURE_2D, fe->texture);
	glDrawArrays(GL_TRIANGLE_STRIP, fe->startingVertex, 4);
}

void Sprite::CheckSpriteCollision(Sprite*)
{
}

void Sprite::UpdateSprite()
{
}

void Sprite::reflect(float, float)
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
}

void Sprite::UpdateMovementPattern()
{
}

void Sprite::GravityFactor()
{
}

node* Sprite::Clone()
{
	return nullptr;
}

bool Sprite::TempCheckCollisionWithMap(float, float, float, float)
{
	return false;
}

bool Sprite::TempCheckCollisionWithMap(float, float, float, float, int)
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
}

Sprite::Sprite(Sprite*)
{
}

Sprite& Sprite::operator=(const Sprite& s)
{
	// TODO: insert return statement here
	return *this;
}

Sprite::Sprite(const Sprite&)
{
}

Sprite::~Sprite()
{
}

void Sprite::Unused(bool)
{
}

bool Sprite::Unused()
{
	return false;
}

const char* Sprite::ClassName()
{
	return "Sprite";
}

void Sprite::Use(const char*)
{
}

Sprite* Sprite::Search(const char*)
{
	return nullptr;
}

Sprite* Sprite::Search(const int)
{
	return nullptr;
}

void Sprite::CheckSameDisplayList(bool)
{
}

bool Sprite::CheckSameDisplayList(void)
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

bool Sprite::GhostCollisionWithSprite(void)
{
	return false;
}

void Sprite::GhostCollisionWithMap(bool)
{
}

bool Sprite::GhostCollisionWithMap(void)
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

float Sprite::Speed(void)
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
		fe->BBox.left = realSpace;
		fe->BBox.right = realSpace + fe->Width;
	}
}

void Sprite::MapPositionY(float y, bool b)
{
	if (!b)
	{
		
		mapPositionY = y;
		float realSpace = (-mapPositionY - 1) * (global.height / 2) * -1;
		fe->BBox.top = realSpace;
		fe->BBox.bottom = realSpace + fe->Height;
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
		fe->BBox.left = realSpaceX;
		fe->BBox.right = realSpaceX + fe->Width;
		float realSpaceY = (y + 1) * (global.height / 2) * -1;
		fe->BBox.top = realSpaceY;
		fe->BBox.bottom = realSpaceY + fe->Height;
		mapPositionX = x;
		mapPositionY = y;
	}
}

void Sprite::MapPositionXInc(float, float, bool)
{
}

void Sprite::MapPositionXDec(float, float, bool)
{
}

void Sprite::MapPositionYInc(float, float, bool)
{
}

void Sprite::MapPositionYDec(float, float, bool)
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

void Sprite::WorldPosition(float, float, bool)
{
}

void Sprite::WorldPositionXInc(float, float, bool)
{
}

void Sprite::WorldPositionXDec(float, float, bool)
{
}

void Sprite::WorldPositionYInc(float, float, bool)
{
}

void Sprite::WorldPositionYDec(float, float, bool)
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

void Sprite::Canned(bool)
{
}

bool Sprite::Canned()
{
	return false;
}

bool Sprite::Pause()
{
	return false;
}

void Sprite::Pause(bool)
{
}

void Sprite::Animation(int)
{
}

int Sprite::Animation()
{
	return 0;
}

void Sprite::Frame(int)
{
}

int Sprite::TotalAnimations()
{
	return 0;
}

int Sprite::TotalFrames()
{
	return 0;
}

int Sprite::Frame()
{
	return 0;
}

bool Sprite::EndOfAnimation(int)
{
	return false;
}

void Sprite::Delay(unsigned int)
{
}

unsigned int Sprite::Delay()
{
	return 0;
}

void Sprite::ActorIndex(int)
{
}

int Sprite::ActorIndex()
{
	return actorIndex;
}

//bool Sprite::CollisionWithSprite(const char* n = NULL)
//{
	//return false;
//}

void Sprite::Reflection(bool)
{
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

void Sprite::VectorDirection(float, float, unsigned int)
{
}

void Sprite::VectorAngle(float, float)
{
}

float Sprite::VectorAngle()
{
	return 0.0f;
}

void Sprite::VariableNumber(int)
{
}

int Sprite::VariableNumber(void)
{
	return 0;
}

float Sprite::DirectionX()
{
	return 0.0f;
}

float Sprite::DirectionY()
{
	return 0.0f;
}

bool Sprite::CollisionWithMap()
{
	return false;
}

void Sprite::CollisionWithMap(bool)
{
}

void Sprite::MainCharacter(bool)
{
}

bool Sprite::MainCharacter(void)
{
	return false;
}

void Sprite::CheckCollisionWithMap(bool)
{
}

bool Sprite::CheckCollisionWithMap(void)
{
	return false;
}

void Sprite::DisplayListNumber(int)
{
}

int Sprite::DisplayListNumber(void)
{
	return 0;
}

void Sprite::DoNotCutDirection(bool)
{
}

bool Sprite::DoNotCutDirection(void)
{
	return false;
}

void Sprite::BelongToMap(const char*)
{
}

const char* Sprite::BelongToMap()
{
	return nullptr;
}

void Sprite::CannedHDirection(bool)
{
}

bool Sprite::CannedHDirection(void)
{
	return false;
}

void Sprite::CannedVDirection(bool)
{
}

bool Sprite::CannedVDirection(void)
{
	return false;
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

int Sprite::AlarmMaximum(void)
{
	return 0;
}

int Sprite::AlarmCount(void)
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

bool Sprite::CollisionWithMap(int)
{
	return false;
}

bool Sprite::CollisionWithSprite(int)
{
	return false;
}

bool Sprite::Collision(int)
{
	return false;
}

void Sprite::ActivateCollisionWithSprite(bool)
{
}

bool Sprite::ActivateCollisionWithSprite()
{
	return false;
}

void Sprite::Follow(Sprite*, unsigned int, unsigned int, unsigned int)
{
}

void Sprite::Follow(const String, unsigned int, unsigned int, unsigned int)
{
}

float Sprite::Distance(Sprite*)
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


