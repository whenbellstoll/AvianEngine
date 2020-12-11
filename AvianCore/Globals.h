#ifndef _GLOBALS_H_
#define _GLOBALS_H_

extern HINSTANCE _hInst;								
extern HANDLE _hm;
extern FUNCORE_API SpriteElem	SpriteList[MAXACTORS];
extern int _rw,_rh,_rd;
extern int _wWidth,_wHeight,_sWidth,_sHeight;
extern FUNCORE_API HWND _Ghwnd;
extern String _CD;
extern String BMPPath;
extern String PaletteName;
extern String SoundsPath;
extern String ActorsPath;
extern String MapsPath;
extern String SFXPath;
extern String MusicPath;
extern String DataPath;
extern FUNCORE_API String RTDPath;
extern FUNCORE_API String ArtAssetsPath;
extern bool _paused;
extern bool _GameOver;
extern FUNCORE_API GameNode *gNode;
extern FUNCORE_API Game *myGame;
extern Sprite * _mc;
extern FUNCORE_API bool _IsWindowed;
extern FUNCORE_API bool _IsScreenSaver;
extern FUNCORE_API  Keyboard *pKeyboard;
extern FUNCORE_API  Mouse *pMouse;
extern FUNCORE_API FunCursor *pFunCursor;
extern FUNCORE_API  GeometricsDrawn *pDraw;
extern FUNCORE_API  StateMachine     * SMArray;
extern FUNCORE_API  Timer            * TMArray;
extern FUNCORE_API  PathStateMachine * PSMArray;
extern FUNCORE_API  void            ** FArray;
extern FUNCORE_API  void            ** SMFArray;
extern FUNCORE_API  void            ** LVFArray;
extern FUNCORE_API  node            ** NArray;
extern FUNCORE_API  MovementPattern  * MPArray;
extern FUNCORE_API  GammaRamp * Effect_GammaRamp;
extern FUNCORE_API  OpenClose * Effect_OpenClose;
extern FUNCORE_API  RandomDissolve   * Effect_RandomDissolve;
extern FUNCORE_API  Screen    * pScreen;
extern FUNCORE_API  File      * _LevelFile;
extern FUNCORE_API  File      * _GameFile;
extern FUNCORE_API int maxSMIndex;
extern FUNCORE_API int maxTMIndex;
extern FUNCORE_API int maxPSMIndex;
extern FUNCORE_API int maxFIndex;
extern FUNCORE_API int maxMPIndex;
extern FUNCORE_API int maxNIndex;

#ifdef ERROR_MESSAGES
	extern FUNCORE_API  Console   * pConsole;
	extern FUNCORE_API  UserError    _UE;
	extern unsigned int _GameLoops;
#endif

void ComposePathes();

FUNCORE_API StateMachine     * NewStateMachines(unsigned int);
FUNCORE_API Timer            * NewTimers(unsigned int);
FUNCORE_API PathStateMachine * NewPathStateMachines(unsigned int);
FUNCORE_API MovementPattern  * NewMovementPatterns(unsigned int);
FUNCORE_API void *           * NewVoidPointers(unsigned int);
FUNCORE_API GameNode         * NewGameNode();
FUNCORE_API node *           * NewNodePointers(unsigned int);
FUNCORE_API FunCursor        * NewFunCursor();
FUNCORE_API void               CreateBinaryGameFile(const char *); 
FUNCORE_API void             * GetFunction(int);
FUNCORE_API StateMachine     * GetStateMachine(int);
FUNCORE_API PathStateMachine * GetPathStateMachine(int);
FUNCORE_API Timer            * GetTimer(int);
FUNCORE_API F_B_PV             GetEdgeFunction(int);
FUNCORE_API F_V_I_PV           GetStateFunction(int);
FUNCORE_API F_V_PV             GetTimerFunction(int);       

///network
extern BOOL CALLBACK MsgBoxProc(HWND hWnd,UINT msg, WPARAM wParam, LPARAM lParam);
extern CRITICAL_SECTION csNetwork;
extern CRITICAL_SECTION csGameLoop;
extern _LISTINT nw_AvailablePlayers;
extern bool _netPaused;
extern _MAPINT nw_ConnectedPlayers;
extern HANDLE eventGameLoop;
extern NetworkDialogBox g_ndb;
extern HMODULE GetNDBModule();
extern std::vector<int> SelectedPlayers;
//network

inline int CorrectInteger(float f)
{
	if(f > 0)
	{
		int i = f;
		f-=i;
		if(f > 0.5f)
			return i+1;
		return i;
	}
	else if(f < 0)
	{
		int i = f;
		f-=i;
		if(f >= -0.5f)
			return i;
		return i-1;
	}
	else
		return 0;
}

enum ErrorMessage
{
	EM_ALARMNOTFOUND_S,
	EM_LOCALVNOTFOUND_I,
	EM_SMNOTFOUND_I,
	EM_SMALREADYADDED_I,
	EM_FNOTFOUND_I,
	EM_FALREADYADDED_I,
	EM_TNOTFOUND_I,
	EM_TALREADYADDED_I,
	EM_CANNOTCLEARB,
	EM_SMNOTADDED_I,
	EM_TNOTADDED_I,
	EM_FNOTADDED_I,
	EM_CANNOTASSIGNTOB,
	EM_BMPNOTFOUND_S,
	EM_ERRORLOADINGBMP_S,
	EM_MASTERMAPCONDITION_S,
	EM_VALIDMAPVX,
	EM_VALIDMAPVY,
	EM_VALIDMAPWX,
	EM_VALIDMAPWY,
	EM_MAPNOTFOUND_S,
	EM_LEVELNOTFOUND_I,
	EM_LEVELNOTFOUND_S,
	EM_CANNOTADDSPRITE_SI,
	EM_SNDNOTFOUND_S,
	EM_SSNDNOTFOUND_S,
	EM_MIDINOTFOUND_S,
	EM_MAINCHARCOND,
	EM_LOCATIONERROR_II,
	EM_MOTIONRECTERROR,
	EM_VECTORNUMBERLESS,
	EM_VECTORNUMBERGREATER,
	EM_PSNOTFOUND_S,
	EM_INVALIDNAME,
	EM_MAPFORPSNOTFOUND_SS,
	EM_STATENOTFOUND_I,
	EM_VNOTFOUND_S,
	EM_CANNOTLOADT_S,
	EM_CANNOTFOLLOWS,
	EM_CANNOTFOLLOWSN,
	EM_FONTNNOTSUPPORTED_S,
	EM_FONTWNOTSUPPORTED_I,
	EM_FONTHNOTSUPPORTED_I,
	EM_FONTWENOTSUPPORTED_I,
	EM_FONTCANNOTBEI,
	EM_FONTCANNOTBES,
	EM_FONTCANNOTBEU,
	EM_DISPLAYTYPESELECTED,
	EM_FRAMEOUTSIDEMAP_SS,
	EM_CANNOTASSIGNTTOM,
	EM_EFFECTTYPELIST,
	EM_EFCANNOTBESET,
	EM_EFCANNOTBESETFS,
	EM_FICANNOTBESETGR,
	EM_FICANNOTBESETFS,
	EM_FOCANNOTBESETGR,
	EM_FOCANNOTBESETFS,
	EM_LRCCANNOTBESETOC,
	EM_LROCANNOTBESETOC,
	EM_TBCCANNOTBESETOC,
	EM_TBOCANNOTBESETOC,
	EM_RCCANNOTBESETOC,
	EM_ROCANNOTBESETOC,
	EM_CCCANNOTBESETOC,
	EM_COCANNOTBESETOC,
	EM_OCCANNOTBESETRD,
	EM_BAWCANNOTBESETRD,
	EM_MCCANNOTBESETRD,
	EM_SPRITENAMENOTFOUND_S,
	EM_SPRITENOTFOUND_I,
	EM_SPRITEPOSITIVESPEED,
	EM_ANIMATIONGEZERO,
	EM_ANIMATIONNOTFOUND_I,
	EM_FRAMEGEZERO,
	EM_FRAMENOTFOUND_I,
	EM_ACTORINDEXPOS,
	EM_ACTORINDEXGMAX_I,
	EM_DIRECTIONNOTFOUND_I,
	EM_ANGLERANGE,
	EM_SMOOTHANGLERANGE,
	EM_GRAVITYPERCENTAGE,
	EM_ERRORTYPEOFMAP_SS,
	EM_MAPDOESNOTEXIST_SS,
	EM_CANNOTSETNULLMAP,
	EM_NUMBEROFHOTSPOTS_I,
	EM_FRICTIONPERCENTAGE,
	EM_COLLISIONIDOFMAPNOTFOUND_IS,
	EM_COLLISIONIDOFSPRITENOTFOUND_I,
	EM_COLLISIONNOTIMPLEMENTED_I,
	EM_HOTPOINTGTMAX_I,
	EM_RIGHTPATHRAYD,
	EM_UPPATHRAYD,
	EM_SMOOTHFACTORG,
	EM_CANNOTGETDISTANCE,
	EM_CANNOTGETDIFFERENCE,
	EM_CANNOTGETRELPOS,
	EM_CANNOTGETFLIPDIRECTION,
	EM_TESTBITVALUERANGE,
	EM_ANIMATIONINDEX,
	EM_SNDNAMENOTFOUND_S,
	EM_STATIONRANGE_I,
	EM_MPNOTFOUND_I,
	SM_PSMNOTFOUND_I,
	EM_LOOKAHEADRAYD,
	EM_CANNOTOPENR_S,
	EM_CANNOTOPENW_S,
	EM_SETDIPLAY256,
	EM_SETDIPLAY16,
	EM_SETDIPLAY24,
	EM_SETDIPLAY32,
	EM_MODENOTSUPPORTED_III,
	EM_NOTSUPPORTEDORNOTFOUND_S,
	EM_NOSETTINGS,
	EM_CANNOTCREATE,
	EM_SNDDRIVERERROR,
	EM_GRAPHICSERROR,
	EM_ERRORLOADINGREPLAY,
	EM_ERRORSAVING,
	EM_ERRORLOADING,
	EM_ERRORSAVINGREPLAY,
	EM_INVALIDOPTION,
	EM_NEWSESSIONFAILED,
	EM_FAILEDTOJOIN,
	EM_INITFAILED,
	EM_CREATESESSIONFAILED,
	EM_PORTFAILED,
	EM_FAILEDTOCONNECT,
	EM_HOSTTERMINATE,
	EM_CONNECTIONLOST,
	EM_SESSIONFULL,
	EM_PLAYERRESIGNED_S,
	EM_PLAYERURESIGNED,

	NUMBEROFERRORS
};

extern const char * ErrorMessages [NUMBEROFERRORS];


#endif