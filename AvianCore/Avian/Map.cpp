#include "Map.h"

void WrappingAlgorithm::Compute()
{
}

void WrappingAlgorithm::Adjust()
{
}

Rect* WrappingAlgorithm::Sources()
{
	return nullptr;
}

Rect* WrappingAlgorithm::Destinations()
{
	return nullptr;
}

WrappingAlgorithm::WrappingAlgorithm()
{
}

WrappingAlgorithm::WrappingAlgorithm(const Rect& rc1, const Rect& rc2, bool InViewPort, int x, int y)
{
}

void WrappingAlgorithm::Position(int, int)
{
}

void WrappingAlgorithm::Load(File&)
{
}

void WrappingAlgorithm::Save(File&)
{
}

void Map::InitMasterMap(const char*, const char*, int)
{
}

void Map::InitStandardMap(const char*, const char*, int, int, int, bool, Rect)
{
}

void Map::InitWrappedMap(const char*, const char*, int, int, int, bool, Rect)
{
}

void Map::Id(int)
{
}

void Map::Init()
{
}

void Map::LoadMap()
{
}

void Map::FreeMap()
{
}

void Map::DisplayMasterMap()
{
}

void Map::DisplayStandardMap()
{
}

void Map::DisplayWrappedMap()
{
}

void Map::DummyDisplay()
{
}

void Map::UpdateStandardMap()
{
}

void Map::UpdateWrappedMap()
{
}

void Map::DisplayMap()
{
}

void Map::ShowMapCollision(COLORREF)
{
}

void Map::ClearVariableMapList()
{
}

void Map::InitCollision()
{
}

Map::Map()
{
}

Map::Map(const Map&)
{
}

Map::Map(const char*, const char*, MapType, int, int, int, bool, Rect)
{
}

Map::~Map()
{
}

Map* Map::Search(const char*)
{
	return nullptr;
}

void Map::Name(const char*)
{
}

const char* Map::Name()
{
	return nullptr;
}

unsigned int Map::Height()
{
	return 0;
}

unsigned int Map::Width()
{
	return 0;
}

float Map::WorldPositionX()
{
	return 0.0f;
}

float Map::WorldPositionY()
{
	return 0.0f;
}

bool Map::IsMasterMap()
{
	return false;
}

void Map::TransparencyColor(COLORREF)
{
}

COLORREF Map::TransparencyColor()
{
	return COLORREF();
}

bool Map::UseTransparency()
{
	return false;
}

void Map::UseTransparency(bool)
{
}

void Map::SpeedX(float)
{
}

void Map::SpeedY(float)
{
}

float Map::SpeedX()
{
	return 0.0f;
}

float Map::SpeedY()
{
	return 0.0f;
}

int Map::Id()
{
	return 0;
}

int Map::ViewPortX()
{
	return 0;
}

int Map::ViewPortY()
{
	return 0;
}

void Map::Visible(bool)
{
}

bool Map::Visible()
{
	return false;
}

void Map::ScrollRatioX(float)
{
}

void Map::ScrollRatioY(float)
{
}

float Map::ScrollRatioX()
{
	return 0.0f;
}

float Map::ScrollRatioY()
{
	return 0.0f;
}

int Map::ZOrder()
{
	return 0;
}

void Map::WorldPositionXInc(float, float)
{
}

void Map::WorldPositionXDec(float, float)
{
}

void Map::WorldPositionYInc(float, float)
{
}

void Map::WorldPositionYDec(float, float)
{
}

void Map::WorldPositionX(float)
{
}

void Map::WorldPositionY(float)
{
}

void Map::ShowMapCollision(bool)
{
}

//bool Map::Add(Alarm)
//{
//	return false;
//}

bool Map::Add(Alarm*)
{
	return false;
}

void Map::AlarmMaximum(int)
{
}

int Map::AlarmMaximum(void)
{
	return 0;
}

int Map::AlarmCount(void)
{
	return 0;
}

void Map::AddCollisionData(CollisionSegment)
{
}

void Map::AddCollisionData(CollisionCircle)
{
}

void Map::RemoveCollisionData(unsigned int, unsigned int)
{
}

void Map::InitGrid()
{
}

void Map::SpacePartitionGridSize(unsigned int)
{
}

int Map::SpacePartitionGridSize()
{
	return 0;
}

void Map::AddLocalVariable(unsigned int)
{
}

void Map::Unused(bool)
{
}

bool Map::Unused()
{
	return false;
}

void Map::Pause(bool)
{
}

bool Map::Pause()
{
	return false;
}

void Map::Use(const char*)
{
}

Map* Map::CreateMap()
{
	return nullptr;
}

node* Map::Clone()
{
	return nullptr;
}

void Map::Load(File&)
{
}

void Map::Save(File&)
{
}

DYNCREATEIMP(Map);

MapPTR::MapPTR()
{
}

MapPTR::MapPTR(Map*)
{
}

MapPTR::MapPTR(const char*)
{
}

Map* MapPTR::operator->()
{
	return nullptr;
}

Map& MapPTR::operator*()
{
	// TODO: insert return statement here
}

MapPTR& MapPTR::operator=(Map*)
{
	// TODO: insert return statement here
}

MapPTR::operator Map* ()
{
}
