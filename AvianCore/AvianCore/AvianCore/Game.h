#ifndef __GAME_H__
#define __GAME_H__

class NetworkComponent;

class   Game: public node
{
	int replayExitKey;
	unsigned int userFPS;
	bool showCursor;
	bool recording;
	bool replayMode;
	bool load;
	bool save;
	bool loadInputData;
	bool slowmotion;
	String loadPath;
	String savePath;
	String loadInputDataPath;
	void LoadReplay(const char *);
	void SaveReplayDialog();
	void LoadReplayDialog();
	void RealLoadGame();
	void RealSaveGame();
	void SaveGameDialog();
	void LoadGameDialog();
	void LoadInputData(const char *);

	Array<int> LevelNavigation;
	bool navigation;
	int currentNavigation;

	friend   int APIENTRY FunMain(HINSTANCE,HINSTANCE,LPSTR,int);

public:
	int    li;
	static List gameNodeList;
	int levelNumber;
	int prevNumber;
	bool newLevel;
	String name;
	Behavior behavior;
	Game();
	~Game();
	void Name(const char *);
	const char* Name(void);
	void LevelNumber(int i);
	int LevelNumber(void);
	static GameNode* Search(const char *);
	static GameNode* Search(int);
	void Add(GameNode *gn);
	void Add(GameNode gn);
	void AddLocalVariable(unsigned int);
	void EndGame();
	void LevelName(const char *);
	void ShowCursor(bool);
	bool ShowCursor();
	const char * LevelName();
	void NextLevel();
	void RestartLevel();
	void PreviousLevel();
	void BackwardLevel();
	void ForwardLevel();
	unsigned int WorldWidth();
	unsigned int WorldHeight();
	unsigned int ViewportWidth();
	unsigned int ViewportHeight();
	void Title(const char *);
	bool IsFullScreen();
	Behavior & GetCurrentLevelBehavior();
	void ViewPortPosition(unsigned int ,unsigned int,bool = true);
	unsigned int ViewPortPositionX();
	unsigned int ViewPortPositionY();
	void StartRecording();
	void StopRecording();
	void ReplayExitKey(int);
	void Replay(bool = false);
	void SaveGame();
	void LoadGame();
	bool ReplayMode();
	void SaveReplay();
	void LoadReplay();
	void SaveGame(const char *);
	void LoadGame(const char *);
	void SaveReplay(const char *);
	void LoadReplay(const char *,bool);
	void SaveScreenShot();


	friend   void  GameLoopBody();
	friend   class Keyboard;
	friend   class Mouse;
	friend   void UnknownStateMachine();

	///Network
	NetworkComponent *pNetworkSession;
	HRESULT HostNetworkSession(GUID,DWORD,LPCTSTR,LPCTSTR);
	HRESULT JoinNetworkSession(GUID ,LPCTSTR ,DWORD ,LPCTSTR);
	void CloseNetworkSession();
	void AddToQOut(unsigned char msg,PBYTE data, unsigned int dataSize);
	void SendQOut();
	void ClearQOut();
	bool receivedPackage;
	bool ReceivedFromPlayers();
	void ReceivedFromPlayers(bool);
	_LISTDWORD HandleList;
	//Network
};


#endif
