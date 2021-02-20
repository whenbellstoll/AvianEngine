#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_


struct KImp;

class   Keyboard
{

	HWND hWnd;
	Key  keys[256];
	DWORD elements;
	KImp * pKImp;
	DirectInput DirectInputInstance;

public:

	DWORD replayFrame;
	Keyboard(HWND,HINSTANCE);
	~Keyboard();
	bool IsPressed(unsigned char); 
	bool IsNotPressed(unsigned char); 
	bool IsTriggered(unsigned char);
	bool IsNotTriggered(unsigned char);
	bool GetKey(unsigned char &);
    bool Nothing();
	bool Any();
	const char * GetCharAsString();
	unsigned int GetString(char *, unsigned int); // The string must be a null terminated string
	unsigned int TapCounter(unsigned char);
	unsigned int HoldCounter(unsigned char);
	void StartReceivingData();
	void StopReceivingData();
	unsigned int Update(PBYTE& keysPressed);
	void Reset();
};


#endif