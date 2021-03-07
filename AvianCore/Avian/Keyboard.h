#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_
#include "Input.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

struct KImp;

class   Keyboard
{

public:
	unsigned char tapCount = 0;
	unsigned char holdCount = 0;
	// true for first frame of hold
	int triggered[16];

	// true for every frame of hold
	int press[16];

	// true for first frame of release
	int release[16];

	// raw data for comparison
	int prevFrame[16];
	// not used in current implementation, but may be used in later implementation
	int currFrame[16];

	Keyboard();
	~Keyboard();
	bool IsPressed(unsigned short); 
	bool IsNotPressed(unsigned short); 
	bool IsTriggered(unsigned short);
	bool IsNotTriggered(unsigned short);
	bool GetKey(unsigned char &);
    bool Nothing();
	bool Any();
	const char * GetCharAsString();
	unsigned int GetString(char *, unsigned int); // The string must be a null terminated string
	unsigned int TapCounter(unsigned char);
	unsigned int HoldCounter(unsigned char);
	void StartReceivingData();
	void ProcessKeys();
	void StopReceivingData();
	void Update(GLFWwindow* window, int key, int scancode, int action, int mods);
	void Reset();
};


#endif