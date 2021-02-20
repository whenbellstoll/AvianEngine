#ifndef __MYGAME_H__
#define __MYGAME_H__
#include "File.h"
	void LoadGameFile();
	void Mode();
	void Avian();
    void BuildLogic();
	void OnGameStart();
	void OnGameEnd();
	void OnSave(File &);
	void OnLoad(File &);
	void SetDataPath();
	
	extern   void (*LoadGameFileP)();
    extern   void (*ModeP)();
	extern   void (*AvianP)();
	extern   void (*BuildLogicP)();
	extern   void (*OnGameStartP)();
	extern   void (*OnGameEndP)();
	extern   void (*OnSaveP)(File &);
	extern   void (*OnLoadP)(File &);
	extern   void (*SetDataPathP)();


#endif
