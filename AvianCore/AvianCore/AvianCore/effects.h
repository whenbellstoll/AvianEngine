#ifndef _EFFECTS_H_
#define _EFFECTS_H_

struct ScreenImp;

class   Screen
{
	ScreenImp * pScreenImp;	
	DWORD bitDepth;
	DWORD rs;
	DWORD gs;
	DWORD bs;
	DWORD rb;
	DWORD gb;
	DWORD bb;
	PALETTEENTRY *pe;
	HPALETTE     hp;
	LOGPALETTE   *lp;
	COLORREF     color;
	int          palIndex;

public:
	Screen();
	~Screen();
	void Color(COLORREF c);
	void PaletteColor(unsigned char);
	void Start();
    void Stop();
	void SetPixel(int x,int y,COLORREF c);
	void SetPixel(int x,int y);
	COLORREF GetPixel(int x,int y);
	void Rect(int x,int y,int w,int h,COLORREF c);
	void PaletteRect(int x,int y,int w,int h,unsigned char);
};

struct GImp;

class   GammaRamp:public node
{
	GImp * pGImp;
	int effectNumber;
	int loops;
	int stay;
	int requestedLoops;
	bool isRunning;
	float valueToAdd;
	bool restoreOnStop;
	void Update();
	friend void GameLoopBody();
	
public:
	GammaRamp();
	~GammaRamp();
	void Filter(COLORREF c,int loops);
	void FadeIn(int loops);
	void FadeOut(int loops,int stay = 0,bool restore = true);
	bool IsRunning();
	void Stop();
	void Save(File &);
	void Load(File &);
	
	DYNCREATED
};


class   OpenClose:public node
{
	COLORREF color;
	int effectNumber;
	int loops;
	int requestedLoops;
	bool isRunning;
	float valueToAdd;
	float valueToAddX;
	float valueToAddY;
	float radius;
	int stay;
	void Update();
	friend void GameLoopBody();

public:
	OpenClose();
	void LeftRightClose(COLORREF c,int nloops,int stay = 0);
	void LeftRightOpen(COLORREF c,int nloops);
	void TopBottomClose(COLORREF c,int nloops,int stay = 0);
	void TopBottomOpen(COLORREF c,int nloops);
	void RectOpen(COLORREF c,int nloops);
	void RectClose(COLORREF c,int nloops,int stay=0);
	void CircleOpen(COLORREF c,int nloops);
	void CircleClose(COLORREF c,int nloops,int stay=0);
	bool IsRunning();
	void Stop();
	void Save(File &);
	void Load(File &);
	DYNCREATED
};

class   RandomDissolve:public node
{
	int d1,d2;
	int nRects;
	bool ** rectangles;
	COLORREF color;
	int loops;
	int stay;
	int requestedLoops;
	bool isRunning;
	int effectNumber;
	void Update();
	friend void GameLoopBody();
	Random rn;

public:
	RandomDissolve();
	void OneColor(COLORREF c,int nloops,int stay = 0);
	void MultiColor(int nloops,int stay = 0);
	void BlackAndWhite(int nloops,int stay = 0);
	bool IsRunning();
	void Stop();
	~RandomDissolve();
	void Save(File &);
	void Load(File &);
	DYNCREATED
};


#endif
