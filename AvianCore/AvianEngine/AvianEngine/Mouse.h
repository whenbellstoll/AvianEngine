#ifndef _MOUSE_H_
#define _MOUSE_H_

#define NORMAL    0
#define LOW       1
#define HIGH      2


struct MouseRelMove
{
	int relx;
	int rely;
	int relz;
};

///Network
struct MouseEvent
{
	unsigned char Event;  
	signed char   Value; 
	unsigned int  XY;
};

//Event
//0x1  rx
//0x2  ry
//0x4  rz
//0x8  b0
//0x10 b1
//0x20 b2

//Network

struct MoImp;

class   Mouse
{
public:
	unsigned int doubleClickAccuracy;
	unsigned int minDoubleClickSpeed;
	unsigned int maxDoubleClickSpeed;
	unsigned int Counter;
	unsigned int LCounter;
	unsigned int RCounter;
	unsigned int MCounter;
	bool         LDoubleClick;
	bool         RDoubleClick;
	bool         MDoubleClick;
	bool         wheel; 

	float Sens;
	int x;
	int y;
	int relx;
	int rely;
	int relz;
	HWND hWnd;
    RECT MotionRect;
	Key  keys[3];
	DWORD elements;
	MoImp * pMoImp;

	DirectInput DirectInputInstance;
	bool isMovingX;
	bool isMovingY;
	bool isMovingZ;
	friend class GameNode;

public:

	DWORD replayFrame;
	Mouse(HWND,HINSTANCE);
	~Mouse();
	bool IsPressed(unsigned char); 
	bool IsTriggered(unsigned char);
	bool IsNotPressed(unsigned char);
	bool IsNotTriggered(unsigned char);
	bool GetKey(unsigned char &);
	bool Nothing();
	bool Any();
	bool HaveWheel();
	void DoubleClickSpeed(unsigned int = 15 );
	void DoubleClickAccuracy(unsigned int = 5);
	unsigned int DoubleClickSpeed();
	unsigned int DoubleClickAccuracy();
	bool IsDoubleClicked(unsigned char);
	unsigned int TapCounter(unsigned char);
	unsigned int HoldCounter(unsigned char);
	void StartReceivingData();
	void StopReceivingData();
	unsigned int Update(MouseEvent * & MouseEvents);
	void ResetKeys();
	int RelX();
	int RelY();
	int ViewportX();
	int ViewportY();
	int Wheel();
	unsigned int WorldX();
	unsigned int WorldY();
	unsigned int X();
	unsigned int Y();
	void Locate(unsigned int,unsigned int);
	bool InRect(FunRect *);
	void SetMotionRect(FunRect *);
	void SetSensitivity(int);
    bool IsMoving();
};


#endif