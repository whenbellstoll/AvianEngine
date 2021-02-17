#ifndef _MANAGESURFACES_H_
#define _MANAGESURFACES_H_

    void SetBackgroundToBlack();
	bool InitGraphics();
	void CleanupGraphics();
	void LoadSpritesSurfaces();
	void FreeSpritesSurfaces();
	void RestoreAllSurfaces();
	void RestorePalette();
	void SetCoopAndMode();
	void CreateBasicSurfaces();
	void SetClippers();
	void ToggleMode();
	void SetBackgroundToBlack();
	void FUNCORE_API SetMode(int w,int h,int d);
	int  FUNCORE_API GetBmpWidth(char*);
	int  FUNCORE_API GetBmpHeight(char*);

	extern bool IsLoading; 
	void LoadingFunction();
	class Loading
	{
		public:
		Loading();
		~Loading();
	};


#endif