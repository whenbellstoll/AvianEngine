#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::Name(const char* n)
{
	name = n;
}

const char* Game::Name(void)
{
	return (const char*)name;
}

void Game::LevelNumber(int i)
{
	prevNumber = levelNumber;
	levelNumber = i;
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
	return Search(levelNumber)->Name();
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
	GameNode* gn = Search(levelNumber);
	return &gn->behavior;
}

void Game::ViewPortPosition(unsigned int ui, unsigned int uii, bool b)
{
	GameNode* gn = Search(levelNumber);
	gn->ViewPortPosition(ui, uii, b);
}

unsigned int Game::ViewPortPositionX()
{
	GameNode* gn = Search(levelNumber);
	return gn->viewPort.WorldXPos();
}

unsigned int Game::ViewPortPositionY()
{
	GameNode* gn = Search(levelNumber);
	return gn->viewPort.WorldXPos();
}

void Game::StartRecording()
{
	//not yet
}

void Game::StopRecording()
{
	//not yet
}

void Game::ReplayExitKey(int)
{
	//not yet
}

void Game::Replay(bool)
{
	//not yet
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
	// not yet
}

void Game::LoadReplay()
{
	// not yet
}

void Game::SaveGame(const char* n)
{
	File file = File(n, File::Mode::WRITE);
	Search(levelNumber)->Save(&file);
}

void Game::LoadGame(const char* n)
{
	File file = File(n, File::Mode::READ);
	file.Read(gameNodeList.Head());
}

void Game::SaveReplay(const char*)
{
	// not yet
}

void Game::LoadReplay(const char*, bool)
{
	// not yet
}

void Game::SaveScreenShot()
{
	// not yet
}

void Game::LoadReplay(const char*)
{
	// not yet
}

void Game::SaveReplayDialog()
{
	// not yet

}

void Game::LoadReplayDialog()
{
	// not yet
}

void Game::RealLoadGame()
{
	// not yet
}

void Game::RealSaveGame()
{
	//
}

void Game::LoadInputData(const char*)
{
	// not yet
}
