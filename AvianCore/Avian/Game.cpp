#include "../globals.h"

Game::Game()
{
}

Game::~Game()
{
	gameNodeList.~Array();
	LevelNavigation.~Array();
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
	if (levelNumber == i) return;
	GameNode* temp = Search(i);
	if (!temp) return;

	myGame->currentLevel->endLevelFunction(myGame->currentLevel);
	myGame->currentLevel = temp;
	myGame->currentLevel->gameNodeLevelFunction(myGame->currentLevel);
	prevNumber = levelNumber;
	levelNumber = i;
}

int Game::LevelNumber()
{
	return levelNumber;
}

GameNode* Game::Search(const char* n)
{
	for (int i = 0; i < gameNodeList.NumberOfElements(); i++)
	{
		GameNode* gn = (GameNode*)gameNodeList[i];
		if (!strcmp(n, gn->Name())) return gn;
	}
	return nullptr;
}

GameNode* Game::Search(int i)
{
	if (i < gameNodeList.NumberOfElements())
	{
		return (GameNode*)gameNodeList[i];
	}
	return nullptr;
}


void Game::Add(GameNode* gn)
{
	gameNodeList.InsertBack(gn);
}

void Game::Add(GameNode gn)
{
	gameNodeList.InsertBack(&gn);
}

void Game::AddLocalVariable(unsigned int)
{
}

void Game::EndGame()
{
}

void Game::LevelName(const char* n)
{
	GameNode* temp = Search(n);
	if (!temp) return;
	if (levelNumber == temp->Id()) return;
	
	// end the current level
	myGame->currentLevel->endLevelFunction(myGame->currentLevel);
	myGame->currentLevel = temp;
	myGame->currentLevel->gameNodeLevelFunction(myGame->currentLevel);
	prevNumber = levelNumber;
	levelNumber = myGame->currentLevel->Id();
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
	return "Nothing_At_All";//Search(levelNumber)->Name();
}

void Game::NextLevel()
{
	myGame->currentLevel->endLevelFunction(myGame->currentLevel);
	myGame->currentLevel = Search(levelNumber + 1);
	myGame->currentLevel->gameNodeLevelFunction(myGame->currentLevel);
	prevNumber = levelNumber;
	levelNumber++;
}

void Game::RestartLevel()
{
	myGame->currentLevel->endLevelFunction(myGame->currentLevel);
	myGame->currentLevel->gameNodeLevelFunction(myGame->currentLevel);
}

void Game::PreviousLevel()
{
	myGame->currentLevel->endLevelFunction(myGame->currentLevel);
	myGame->currentLevel = Search(levelNumber + 1);
	myGame->currentLevel->gameNodeLevelFunction(myGame->currentLevel);
	prevNumber = levelNumber;
	levelNumber++;
}

void Game::BackwardLevel()
{
	// ????
}

void Game::ForwardLevel()
{
	// ????
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

void Game::Title(const char* n)
{
	glfwSetWindowTitle(global.window, n);
}

bool Game::IsFullScreen()
{
	return false;
}

Behavior& Game::GetCurrentLevelBehavior()
{
	// TODO: insert return statement here
	Behavior* b = nullptr;
	return *b;
}

/*
Behavior& Game::GetCurrentLevelBehavior()
{
	GameNode* gn = Search(levelNumber);
	return &gn->behavior;
}
*/

void Game::ViewPortPosition(unsigned int ui, unsigned int uii, bool b)
{
	GameNode* gn = Search(levelNumber);
	//gn->ViewPortPosition(ui, uii, b);
}

unsigned int Game::ViewPortPositionX()
{
	return (int)myGame->currentLevel->viewPort.WorldXPos();
	
}

unsigned int Game::ViewPortPositionY()
{
	return (int)myGame->currentLevel->viewPort.WorldYPos();
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
	File file = File(n, Mode::WRITE);
	Search(levelNumber)->Save(file);
}

void Game::LoadGame(const char* n)
{
	File file = File(n, Mode::READ);
	//file.Read(gameNodeList.Head());
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
