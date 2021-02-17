#ifndef _GAMENODE_H_
#define _GAMENODE_H_

struct KeyboardInputKeys{
		Array<unsigned char> KInputKeys;
	};

class ParticleSystem;
class FUNCORE_API GameNode:public node
{
protected:
	int	id;
	String name;
	unsigned int worldWidth;
	unsigned int worldHeight;
	DWORD endTime;
	DWORD startTime;
	bool showScrollingBoundingBox;
	bool quitOnEscape;
	String paletteName;
	int li;

public:
	GameNode();
    ~GameNode();

	String levelName;
	Behavior behavior;
	int	spriteCount;
	int	mapCount;
	int	variableCount;
	int soundCount;
	int streamedSoundCount;
	int midiFileCount;
	int particleSystemCount;
	int	spriteMaximum;
	int	mapMaximum;
	int	variableMaximum;
	int soundMaximum;
	int streamedSoundMaximum;
	int midiFileMaximum;
	int particleSystemMaximum;
	List mapList;
	List spriteList[kMaxSpriteType];
	List variableList;
	List soundList;
	List streamedSoundList;
	List midiFileList;
	List particleSystemList;
	void UpdateParticleSystem(Map *);
	bool Add(ParticleSystem *);
    ViewPort viewPort;
	void (*gameNodeLevelFunction)(GameNode*);
	void (*gameNodeActorsFunction)(GameNode *);
	void (*transitionFunction)(GameNode *);
	void (*endLevelFunction)(GameNode *);
	bool transitionDone;
	void Execute();
	void Id(int);
	int Id(void);
	void Name(const char *);
	const char* Name(void);
	void PaletteName(const char *);
	GameNode* Search(const char *);
	bool Add(Sprite *);
	bool Add(Map *);
    bool Add(Variable *);
	bool Add(Sound *);
	bool Add(StreamedSound *);
	bool Add(MidiFile *);
	bool AddSFX(const char *,const char *,bool = false,int = 50);
	bool AddMusic(const char *,const char *,bool = false);
    bool AddMidiFile(const char *,const char *,bool = false);
	bool AddMap(const char *,const char *,Map::MapType);
	bool Add(Map &);
	bool Add(Variable &);
	bool Add(Sprite &);
	void AddLocalVariable(unsigned int);
	unsigned int WorldWidth();
	unsigned int WorldHeight();
  	void WorldWidth(unsigned int);
	void WorldHeight(unsigned int);
    void GetNewVariableStates();
	void DisplayTextNoMap();
	void UpdateScreen();
	void PlaySFX(const char *);
	void PlayMusic(const char *);
	void PlayMidiFile(const char *);
	void StopMusic(const char *);
	void StopMidiFile(const char *);
	void InitFPS();
	float currentFPS;
	unsigned int userFPS;
	DWORD currentGameLoopTime;
	DWORD userGameLoopTime;
	void EndTimer();
	void StartTimer();
	void FPStoMS(unsigned int);
	void Idle();
	bool ShowScrollingBoundingBox();
	void ShowScrollingBoundingBox(bool);
	bool QuitOnEscape();
	void QuitOnEscape(bool);
	void ViewPortPosition(unsigned int ,unsigned int,bool = true); 
	void DeleteFunCursor();

	Array<unsigned char> MInputData1;
	Array<MouseRelMove> MInputData2;
	Array<KeyboardInputKeys> KInputKeysNumber;
	
	void UpdateCursor();

	void Save(File &);
	void Load(File &);

	///Network
	void NResetKM();
	unsigned int defaultPort;
	unsigned int returnLevel;
	bool bNetworked;
	unsigned int minJoin;
	unsigned int maxJoin;
	GUID guidGame;
	bool HostNetworkSession(GUID);
	bool JoinNetworkSession(GUID);
	void WaitForOtherPlayers();
	//Network

	DYNCREATED
};


#endif
