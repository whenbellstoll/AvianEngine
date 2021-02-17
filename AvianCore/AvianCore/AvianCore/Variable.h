#ifndef _VARIABLE_H_
#define _VARIABLE_H_
class Sound;
class Sprite; 
class Map;
class Alarm;

extern FunRect MummyRect;
extern Random rnText;

class FUNCORE_API Variable:public node
{
	enum{DOUBLE,POINTER,STRING} type;

	union
	{
		double	 d;
		void *	 p;
		char *  cp;
	}u;

	bool onlyIntegerPart;
	bool pauseText;
	char asciiValue[50];

	bool operator<(void *);
	bool operator<=(void *);
	bool operator>(void *);
	bool operator>=(void *);

	friend class GameNode;
	friend void GameLoopBody();
	
	Map *variableMap;
	int id;
	bool inWorld;
	String name;
	bool visible;

	LOGFONT lf;
	HFONT font;
	String fontName;
	int	width;
	float height;
	int weight;
	int italic;
	int strikeOut;
	int underline;

	COLORREF color;
	FunRect rect1;
	COLORREF frameColor;
	COLORREF arrowsColor;

	bool showFrame;
	int hScrollingRatio;
	int vScrollingRatio;
	int hDeltaScroll;
	int vDeltaScroll;

	bool leadingSpaces;

	unsigned int variableLenght;
	int longestLine;
	int largestBloc;
	int TEXTLines;
	char *value;
	FunRect frame;
	int lines;
	int lineSpacing;
	int letterSpacing;
	int leftMargin;
	int topMargin;
	int bottonSpacing;

	int RIGHTSPACE;
	int BOTTOMSPACE;

	RECT bottonRightRect;
	RECT bottonLeftRect;
	RECT bottonUpRect;
	RECT bottonDownRect;

	bool tested;
	bool stop;
	int frameWidth;
	int frameHeight;
	int counter;
	struct CharacterSize{
		LONG x;
		LONG y;
	};
	CharacterSize FontCharactersSize[256];

public:
	friend void RestoreAllSurfaces();
	friend void ToggleMode();
	enum DisplayTypes { RespectingWords, ConsecutiveCharacters, HorizontalScrolling, VerticalScrolling, HVScrolling, NormalVariable };
	enum EffectType  { MummyEffect, CharacterByCharacterEffect, LineByLineEffect, ASCIIEffect, RANDOMDecoding, SEQUENTIALDecoding };
private:
	DisplayTypes displayType;
	EffectType  effectType;

	int hScrollRight;
	int hScrollLeft;
	int vScrollUp;
	int vScrollDown;

	bool htriggered;
	bool vtriggered;

	bool activateOutOfViewport;
	int  maxHScrolling;
	int  maxVScrolling;

	bool topMost;
	bool unused;

	char *	tempvalue;
	int		delay;
	int		tempdelay;
	int		delay2;
	int		tempdelay2;
	int		tempvariableLenght;
	int		tempvariableLenght2;
	int		linesCount;
	Sound *	letterSound;
	int *   indexArray;
	bool	stopEffect;
	int li;

	void	Init();
	bool	Load(const char * = NULL);
	void	ShowFrame(COLORREF);
	void	DisplayConsecutivesCharacter(HDC);
	void	DisplayRespectingWords(HDC);
	void	DisplayConsecutivesCharacterHScrolling(HDC);
	void	DisplayConsecutivesCharacterVScrolling(HDC);
	void	DisplayConsecutivesCharacterHVScrolling(HDC);
	void	ArrowsMouseStatus();
	void	HorizontalScroll();
	void	VerticalScroll();
	void	DrawRightArrow(COLORREF = RGB(255,0,255));
	void	DrawLeftArrow(COLORREF = RGB(255,0,255));
	void	DrawUpArrow(COLORREF = RGB(255,0,255));
	void	DrawDownArrow(COLORREF = RGB(255,0,255));
	void	ArrowsStatus();
	void	GetLongestLineSize();
	void	GetLargestBlocVS();
	void	GetLargestBlocHSHVS();
	void	GetNumberOfLines();
	int		GetRectWordLenght(int);
	
	void	InitEffects();
	void	UpdateEffects();
	void	ChrChrEffect();
	void	LnLnEffect();
	void	AsciiEffect();
	void	RandomDecoding();
	void	SequentialDecoding();
	int		ASCIIRandLowerChar();
	int		ASCIIRandUpperChar();
	int		ASCIIRandNumber();
	int		LinesCount(char * = NULL);
	bool	IndexInIndexArray(int);
	void	UpdateIndexArray(int);
	int		RandIndexArray();
	void	Play();
	
public:
	Variable & Value;
	Variable();
	Variable(Variable *);
	Variable & operator=(const Variable &);
	Variable(const Variable &t);
	virtual ~Variable();
	static  Variable* Search(const char *);
	Variable(double);
	Variable(const int); // for the 0
	Variable(unsigned int); 
	Variable(const char *);
	Variable(void *);
	Variable(const Variable *);
	Variable & operator=(double);
	Variable & operator=(float);
	Variable & operator=(const int);
	Variable & operator=(unsigned int); 
	Variable & operator=(void *);
	Variable & operator=(const char *);
	Variable operator++();
	Variable operator--();
	Variable operator++(int);
	Variable operator--(int);
	bool operator==(const Variable &);
	bool operator==(char);
	bool operator==(unsigned char);
	bool operator==(int);
	bool operator==(unsigned int);
	bool operator==(float);
	bool operator==(const char *);
	bool operator==(void *);
	bool operator!=(const Variable &);
	bool operator!=(char);
	bool operator!=(unsigned char);
	bool operator!=(int);
	bool operator!=(unsigned int);
	bool operator!=(float);
	bool operator!=(const char *);
	bool operator!=(void *);
	bool operator<(const Variable &);
	bool operator<(char);
	bool operator<(unsigned char);
	bool operator<(int);
	bool operator<(unsigned int);
	bool operator<(float);
	bool operator<(const char *);
	bool operator<=(const Variable &);
	bool operator<=(char);
	bool operator<=(unsigned char);
	bool operator<=(int);
	bool operator<=(unsigned int);
	bool operator<=(float);
	bool operator<=(const char *);
	bool operator>(const Variable &);
	bool operator>(char);
	bool operator>(unsigned char);
	bool operator>(int);
	bool operator>(unsigned int);
	bool operator>(float);
	bool operator>(const char *);
	bool operator>=(const Variable &);
	bool operator>=(char);
	bool operator>=(unsigned char);
	bool operator>=(int);
	bool operator>=(unsigned int);
	bool operator>=(float);
	bool operator>=(const char *);

	
	friend FUNCORE_API bool operator==(char,Variable &);
	friend FUNCORE_API bool operator==(unsigned char,Variable &);
	friend FUNCORE_API bool operator==(int,Variable &);
	friend FUNCORE_API bool operator==(unsigned int,Variable &);
	friend FUNCORE_API bool operator==(float,Variable &);
	friend FUNCORE_API bool operator==(const char *,Variable &);
	friend FUNCORE_API bool operator==(void *,Variable &);
	
	friend FUNCORE_API bool operator!=(char,Variable &);
	friend FUNCORE_API bool operator!=(unsigned char,Variable &);
	friend FUNCORE_API bool operator!=(int,Variable &);
	friend FUNCORE_API bool operator!=(unsigned int,Variable &);
	friend FUNCORE_API bool operator!=(float,Variable &);
	friend FUNCORE_API bool operator!=(const char *,Variable &);
	friend FUNCORE_API bool operator!=(void *,Variable &);
	
	friend FUNCORE_API bool operator<(char,Variable &);
	friend FUNCORE_API bool operator<(unsigned char,Variable &);
	friend FUNCORE_API bool operator<(int,Variable &);
	friend FUNCORE_API bool operator<(unsigned int,Variable &);
	friend FUNCORE_API bool operator<(float,Variable &);
	friend FUNCORE_API bool operator<(const char *,Variable &);

	friend FUNCORE_API bool operator<=(char,Variable &);
	friend FUNCORE_API bool operator<=(unsigned char,Variable &);
	friend FUNCORE_API bool operator<=(int,Variable &);
	friend FUNCORE_API bool operator<=(unsigned int,Variable &);
	friend FUNCORE_API bool operator<=(float,Variable &);
	friend FUNCORE_API bool operator<=(const char *,Variable &);
	
	friend FUNCORE_API bool operator>(char,Variable &);
	friend FUNCORE_API bool operator>(unsigned char,Variable &);
	friend FUNCORE_API bool operator>(int,Variable &);
	friend FUNCORE_API bool operator>(unsigned int,Variable &);
	friend FUNCORE_API bool operator>(float,Variable &);
	friend FUNCORE_API bool operator>(const char *,Variable &);
	
	friend FUNCORE_API bool operator>=(char,Variable &);
	friend FUNCORE_API bool operator>=(unsigned char,Variable &);
	friend FUNCORE_API bool operator>=(int,Variable &);
	friend FUNCORE_API bool operator>=(unsigned int,Variable &);
	friend FUNCORE_API bool operator>=(float,Variable &);
	friend FUNCORE_API bool operator>=(const char *,Variable &);

	Variable & operator+=(double);
	friend FUNCORE_API Variable operator+(const Variable &,double);
	friend FUNCORE_API Variable operator+(double,const Variable &);

	Variable & operator+=(int);
	friend FUNCORE_API Variable operator+(const Variable &,int);
	friend FUNCORE_API Variable operator+(int,const Variable &);

	Variable & operator+=(float);
	friend FUNCORE_API Variable operator+(const Variable &,float);
	friend FUNCORE_API Variable operator+(float,const Variable &);

	Variable & operator+=(const char *);
	friend FUNCORE_API Variable operator+(const Variable &,char *);
	friend FUNCORE_API Variable operator+(const char *,const Variable &);

	Variable & operator+=(const Variable &);
	friend FUNCORE_API Variable operator+(const Variable &,const Variable &);

	Variable & operator-=(double);
	friend FUNCORE_API Variable operator-(const Variable &,double);
	friend FUNCORE_API Variable operator-(double,const Variable &);

	Variable & operator-=(int);
	friend FUNCORE_API Variable operator-(const Variable &,int);
	friend FUNCORE_API Variable operator-(int,const Variable &);

	Variable & operator-=(float);
	friend FUNCORE_API Variable operator-(const Variable &,float);
	friend FUNCORE_API Variable operator-(float,const Variable &);

	Variable & operator-=(const Variable &);
	friend FUNCORE_API Variable operator-(const Variable &,const Variable &);

	Variable & operator*=(double);
	friend FUNCORE_API Variable operator*(const Variable &,double);
	friend FUNCORE_API Variable operator*(double,const Variable &);

	Variable & operator*=(int);
	friend FUNCORE_API Variable operator*(const Variable &,int);
	friend FUNCORE_API Variable operator*(int,const Variable &);

	Variable & operator*=(float);
	friend FUNCORE_API Variable operator*(const Variable &,float);
	friend FUNCORE_API Variable operator*(float,const Variable &);

	Variable & operator*=(const Variable &);
	friend FUNCORE_API Variable operator*(const Variable &,const Variable &);

	Variable & operator/=(double);
	friend FUNCORE_API Variable operator/(const Variable &,double);
	friend FUNCORE_API Variable operator/(double,const Variable &);

	Variable & operator/=(int);
	friend FUNCORE_API Variable operator/(const Variable &,int);
	friend FUNCORE_API Variable operator/(int,const Variable &);

	Variable & operator/=(float);
	friend FUNCORE_API Variable operator/(const Variable &,float);
	friend FUNCORE_API Variable operator/(float,const Variable &);

	Variable & operator/=(const Variable &);
	friend FUNCORE_API Variable operator/(const Variable &,const Variable &);

	Variable & operator%=(double);
	friend FUNCORE_API Variable operator%(const Variable &,double);
	friend FUNCORE_API Variable operator%(double,const Variable &);

	Variable & operator%=(int);
	friend FUNCORE_API Variable operator%(const Variable &,int);
	friend FUNCORE_API Variable operator%(int,const Variable &);

	Variable & operator%=(float);
	friend FUNCORE_API Variable operator%(const Variable &,float);
	friend FUNCORE_API Variable operator%(float,const Variable &);

	Variable & operator%=(const Variable &);
	friend FUNCORE_API Variable operator%(const Variable &,const Variable &);

	bool operator!();
	operator double();
	operator long();
	operator int();
	operator unsigned int();
	operator float();
	operator bool();
	operator char();
	operator unsigned char();
	operator const char *(); 
	operator void *();
	operator Sprite *();
	operator Map *();
	operator Alarm*();
	operator Variable*();
	
	void OnlyIntegerPart(bool);
	bool OnlyIntegerPart();
	void Pause(bool);
	bool Pause();
	
	const char * AsciiValue();
	void AddLocalVariable(unsigned int);

	void ObjectCopy(const Variable *);
	void ObjectCopy(const Variable &);

	void	DisplayText();
	void	Id(int);
	int		Id();
	void	Name(const char *);
	const char*	Name(void);
	void	InWorld(bool);
	bool	InWorld();
	void	ShowFrame(bool);
	bool	ShowFrame();
	void	Save(char * = NULL);
	void	Color(COLORREF);
	void	LineSpacing(unsigned int);
	void	LetterSpacing(unsigned int);
	void	FontName(const char *);
	void	Width(unsigned int);
	void	Height(float);
	void	Weight(unsigned int);
	void	Italic(bool);
	void	StrikeOut(bool);
	void	Underline(bool);
	void	Visible(bool);
	bool	Visible();
	void	LeadingSpaces(bool);
	void	HScrollRightKey(int);
	void	HScrollLeftKey(int);
	void	VScrollUpKey(int);
	void	VScrollDownKey(int);
	void	HScrollTriggered(bool);
	void	VScrollTriggered(bool);
	void	ActivateOutOfViewport(bool);
	void	HDeltaScroll(unsigned int);
	void	VDeltaScroll(unsigned int);
	void	CenterViewport();
	void	LeftMargin(unsigned int);
	void	TopMargin(unsigned int);
	bool	LoadTextFile(const char * = NULL);
	static  void UpdateTextMaps();
	void	DisplayTextMap();
	void	DisplayTextNoMap();
	void	FrameColor(COLORREF = RGB(255,0,255));
	void	ArrowsSize(unsigned int);
	void	ArrowsColor(COLORREF = RGB(255,0,255));
	void	DisplayType(DisplayTypes);
	void	Frame(FunRect);
	FunRect	Frame();
	void	BelongToMap(const char *);

	void	Effect(EffectType);
	void	Delay(unsigned int,unsigned int = 0);
	void	LetterSound(const char *);

	unsigned int LineSpacing();
	unsigned int LetterSpacing();
	unsigned int Width();
	float Height();
	unsigned int Weight();
	bool Italic();
	bool StrikeOut();
	bool Underline();
	COLORREF FrameColor();
	unsigned int ArrowsSize();
	COLORREF ArrowsColor();

	void TopMost(bool);
	bool TopMost();
	void Unused(bool);
	bool Unused();
	void Use(const char *);
	Variable * CreateVariable();
	Variable * CreateText();

	COLORREF Color();
	void Move(float,float);
	void Follow(Sprite *,int = 0);
	void Follow(const char *,int = 0);
	node* Clone();
	void Save(File &);
	void Load(File &);
#ifdef ERROR_MESSAGES
	friend class Console;
#endif

	Behavior behavior;

	DYNCREATED
};

class FUNCORE_API VariablePTR
{
	Variable *variablePtr;
	static Variable * dummyVariablePtr;
public:
	VariablePTR(); 
	VariablePTR(Variable *);
	VariablePTR(const char *);
	Variable * operator->();
	Variable & operator*();
	VariablePTR & operator=(Variable*);
	operator Variable *();
};

typedef Variable	Text;
typedef VariablePTR TextPTR;


#endif
