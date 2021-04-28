#ifndef _GAMENODE_H_
#define _GAMENODE_H_
#include "Array.h"
#include "List.h"
#include "SpriteFull.h"
#include "Map.h"

class ParticleSystem;
class   GameNode:public node
{
protected:
	int	id;
	const char * name;
	unsigned int worldWidth;
	unsigned int worldHeight;
	double endTime;
	double startTime;
	bool showScrollingBoundingBox;
	bool quitOnEscape;
	bool usePalette;
	String paletteName;
	int li;

public:
	GameNode();
    ~GameNode();

	const char * levelName;
	Behavior * behavior;
	int	spriteCount;
	int	mapCount;
	int	variableCount;
	int soundCount;
	int musicCount;
	int particleSystemCount;
	int spriteMaximum = 1024;
	int mapMaximum = 1024;
	int variableMaximum = 1024;
	int soundMaximum = 512;
	int musicMaximum = 128;
	int particleSystemMaximum = 1024;
	Array<node *> mapList;
	Array<node*> spriteList;
	Array<node *> variableList;
	Array<node *> soundList;
	Array<node *> musicList;
	Array<node *> particleSystemList;
	//void UpdateParticleSystem(Map *);
	//bool Add(ParticleSystem *);
    //ViewPort viewPort;
	void (*gameNodeLevelFunction)(GameNode*);
	void (*gameNodeActorsFunction)(GameNode *);
	void (*transitionFunction)(GameNode *);
	void (*endLevelFunction)(GameNode *);
	bool transitionDone;
	void Execute(float);
	void Id(int);
	int Id(void);
	void Name(const char *);
	const char* Name(void);
	void PaletteName(const char *);
	GameNode* Search(const char *);
	bool Add(Sprite *);
	bool Add(Map *);
    //bool Add(Variable *);
	//bool Add(Sound *);
	//bool Add(StreamedSound *);
	bool AddSFX(const char *,const char *,bool = false,int = 50);
	bool AddMusic(const char *,const char *,bool = false);
	bool AddMap(const char *,const char *,Map::MapType);
	bool Add(Map &);
	//bool Add(Variable &);
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
	void StopMusic(const char *);
	void StopMidiFile(const char *);
	void InitFPS();
	float currentFPS;
	unsigned int userFPS;
	double currentGameLoopTime;
	double userGameLoopTime;
	void EndTimer();
	void StartTimer();
	void FPStoMS(unsigned int);
	void Idle();
	bool ShowScrollingBoundingBox();
	void ShowScrollingBoundingBox(bool);
	bool QuitOnEscape();
	void QuitOnEscape(bool);
	void ViewPortPosition(unsigned int ,unsigned int,bool = true); 
	void DeleteCursor();	
	void UpdateCursor();

	void Save(File &);
	void Load(File &);

	/*
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
	*/
	DYNCREATED
};


#endif
