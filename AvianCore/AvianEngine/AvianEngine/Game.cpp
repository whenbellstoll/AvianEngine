#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::Name(const char*)
{
}

const char* Game::Name(void)
{
	return nullptr;
}

void Game::LevelNumber(int i)
{
}

int Game::LevelNumber(void)
{
	return 0;
}

GameNode* Game::Search(const char*)
{
	return nullptr;
}

GameNode* Game::Search(int)
{
	return nullptr;
}

void Game::Add(GameNode* gn)
{
}

void Game::Add(GameNode gn)
{
}

void Game::AddLocalVariable(unsigned int)
{
}

void Game::EndGame()
{
}

void Game::LevelName(const char*)
{
}

void Game::ShowCursor(bool b)
{
	showCursor = b;
}

bool Game::ShowCursor()
{
	return showCursor;
}

const char* Game::LevelName()
{
	return nullptr;
}

void Game::NextLevel()
{
}

void Game::RestartLevel()
{
}

void Game::PreviousLevel()
{
}

void Game::BackwardLevel()
{
}

void Game::ForwardLevel()
{
}

unsigned int Game::WorldWidth()
{
	return 0;
}

unsigned int Game::WorldHeight()
{
	return 0;
}

unsigned int Game::ViewportWidth()
{
	return 0;
}

unsigned int Game::ViewportHeight()
{
	return 0;
}

void Game::Title(const char*)
{
}

bool Game::IsFullScreen()
{
	return false;
}

Behavior& Game::GetCurrentLevelBehavior()
{
	// TODO: insert return statement here
}

void Game::ViewPortPosition(unsigned int, unsigned int, bool)
{
}

unsigned int Game::ViewPortPositionX()
{
	return 0;
}

unsigned int Game::ViewPortPositionY()
{
	return 0;
}

void Game::StartRecording()
{
}

void Game::StopRecording()
{
}

void Game::ReplayExitKey(int)
{
}

void Game::Replay(bool)
{
}

void Game::SaveGame()
{
}

void Game::LoadGame()
{
}

bool Game::ReplayMode()
{
	return false;
}

void Game::SaveReplay()
{
}

void Game::LoadReplay()
{
}

void Game::SaveGame(const char*)
{
}

void Game::LoadGame(const char*)
{
}

void Game::SaveReplay(const char*)
{
}

void Game::LoadReplay(const char*, bool)
{
}

void Game::SaveScreenShot()
{
}

void Game::LoadReplay(const char*)
{
}

void Game::SaveReplayDialog()
{
}

void Game::LoadReplayDialog()
{
}

void Game::RealLoadGame()
{
}

void Game::RealSaveGame()
{
}

void Game::SaveGameDialog()
{
}

void Game::LoadGameDialog()
{
}

void Game::LoadInputData(const char*)
{
}
