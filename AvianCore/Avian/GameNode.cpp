#include "../globals.h"
#include "GameNode.h"

GameNode::GameNode()
{
	spriteCount = 0;
	mapCount = 0;
	variableCount = 0;
	soundCount = 0;
	musicCount = 0;
	particleSystemCount = 0;
	
	
	
	
}

GameNode::~GameNode()
{
}

void GameNode::Execute(float dt)
{
	// Update objects
	// Maps
	for (int i = 0; i < mapList.NumberOfElements(); i++)
	{
		Map* m = (Map*)mapList[i];
		printf("Name of Map being drawn: %s \n", m->Name());
		m->DisplayMap();
	}
	// Sprites
	for (int i = 0; i < spriteList.NumberOfElements(); i++)
	{
		Sprite* s = (Sprite*)spriteList[i];
		s->dt = dt;
		printf("Name of Sprite being drawn: %i \n", s->ActorIndex());
		s->DisplaySprite();
		//s->UpdateSprite();
	}
	// sound effects
	// music
	// particleSystems
}

void GameNode::Id(int i)
{
	id = i;
}

int GameNode::Id()
{
	return id;
}

void GameNode::Name(const char* n)
{
	name = n;
}

const char* GameNode::Name()
{
	return name;
}

void GameNode::PaletteName(const char* n)
{
}

GameNode* GameNode::Search(const char* n)
{
	return nullptr;
}

bool GameNode::Add(Sprite* s)
{
	if (spriteList.NumberOfElements() == spriteMaximum)	return false;
	
	spriteList.InsertBack(s);
	return true;
}

bool GameNode::AddSFX(const char*, const char*, bool, int)
{
	return false;
}

bool GameNode::AddMusic(const char*, const char*, bool)
{
	return false;
}

bool GameNode::AddMap(const char* name, const char* filename, Map::MapType mT)
{
	if (mapList.NumberOfElements() == mapMaximum) return false;

	// Allocate Map and Set Variables
	Map* m = (Map*)MEMPACK_AllocMem(&global.levelPack, sizeof(Map), "AddMapGameNode");
	m->Name(name);
	m->FileName(filename);
	m->SetMapType(mT);
	mapList.InsertBack(m);

	return true;
}

bool GameNode::Add(Sprite& s)
{
	if (spriteList.NumberOfElements() + 1 > spriteMaximum)
	{
		return false;
	}

	spriteList.InsertBack(&s);
	return true;
}

void GameNode::AddLocalVariable(unsigned int i)
{
}

unsigned int GameNode::WorldWidth()
{
	return worldWidth;
}

unsigned int GameNode::WorldHeight()
{
	return worldHeight;
}

void GameNode::WorldWidth(unsigned int i)
{
	worldWidth = i;
}

void GameNode::WorldHeight(unsigned int i)
{
	worldHeight = i;
}

void GameNode::GetNewVariableStates()
{
}

void GameNode::DisplayTextNoMap()
{
}

void GameNode::UpdateScreen()
{
}

void GameNode::PlaySFX(const char* n)
{
}

void GameNode::PlayMusic(const char* n)
{
}

void GameNode::StopMusic(const char* n)
{
}

void GameNode::StopMidiFile(const char* n)
{
}

void GameNode::InitFPS()
{
}

void GameNode::EndTimer()
{
}

void GameNode::StartTimer()
{
}

void GameNode::FPStoMS(unsigned int)
{
}

void GameNode::Idle()
{
}

bool GameNode::ShowScrollingBoundingBox()
{
	return showScrollingBoundingBox;
}

void GameNode::ShowScrollingBoundingBox(bool b)
{
	showScrollingBoundingBox = b;
}

bool GameNode::QuitOnEscape()
{
	return quitOnEscape;
}

void GameNode::QuitOnEscape(bool b)
{
	quitOnEscape = b;
}

void GameNode::ViewPortPosition(unsigned int, unsigned int, bool)
{
}

void GameNode::DeleteCursor()
{
}

void GameNode::UpdateCursor()
{
}

void GameNode::Save(File&)
{
}

void GameNode::Load(File&)
{
}

DYNCREATEIMP(GameNode);