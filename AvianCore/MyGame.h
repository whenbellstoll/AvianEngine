#ifndef __MYGAME_H__
#define __MYGAME_H__

	void LoadGameFile();
	void Mode();
	void Fun();
    void BuildLogic();
	void OnGameStart();
	void OnGameEnd();
	void OnSave(File &);
	void OnLoad(File &);
	void SetDataPath();
	
	extern FUNCORE_API void (*LoadGameFileP)();
    extern FUNCORE_API void (*ModeP)();
	extern FUNCORE_API void (*FunP)();
	extern FUNCORE_API void (*BuildLogicP)();
	extern FUNCORE_API void (*OnGameStartP)();
	extern FUNCORE_API void (*OnGameEndP)();
	extern FUNCORE_API void (*OnSaveP)(File &);
	extern FUNCORE_API void (*OnLoadP)(File &);
	extern FUNCORE_API void (*SetDataPathP)();


#endif
