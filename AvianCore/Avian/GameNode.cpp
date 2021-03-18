#include "GameNode.h"

GameNode::GameNode()
{
}

GameNode::~GameNode()
{
}

void GameNode::Execute()
{
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
	// TO DO add spriteList check
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

bool GameNode::Add(Sprite& s)
{
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

void GameNode::PlayMusic(const char*)
{
}

void GameNode::StopMusic(const char*)
{
}

void GameNode::StopMidiFile(const char*)
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

const char* GameNode::ClassName()
{
	return "GameNode";
}

node* GameNode::CreateObject()
{
	return nullptr;//new GameNode(this);
}