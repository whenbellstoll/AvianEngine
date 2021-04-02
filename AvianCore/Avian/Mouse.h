#ifndef MOUSE_HEADER
#define MOUSE_HEADER

#define NORMAL    0
#define LOW       1
#define HIGH      2

#include "SpriteFull.h"

class   AvianMouse
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
    Rect MotionRect;
	// true for first frame of hold
	char triggered[16];

	// true for every frame of hold
	char press[16];

	// true for first frame of release
	char release[16];

	// raw data for comparison
	char prevFrame[16];
	// not used in current implementation, but may be used in later implementation
	char currFrame[16];



public:
	AvianMouse();
	~AvianMouse();
	bool IsPressed(unsigned char c); 
	bool IsTriggered(unsigned char c);
	bool IsNotPressed(unsigned char c);
	bool IsNotTriggered(unsigned char c);
	bool GetKey(unsigned char & c);
	bool Nothing();
	bool Any();
	void Process();
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
	unsigned int Update();
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
	void Locate(unsigned int i,unsigned int ni);
	bool InRect(Rect * r);
	void SetMotionRect(Rect * r);
	void SetSensitivity(int i);
    bool IsMoving();
};
#endif