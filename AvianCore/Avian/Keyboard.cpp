#include "Keyboard.h"
#include <cstring> //for memcpy and memcmp


Keyboard::Keyboard()
{
	Reset();
}

Keyboard::~Keyboard()
{
}

bool Keyboard::IsPressed(unsigned short key)
{
	return press[key >> 5] & 1 << (key & 0x1f);
}

bool Keyboard::IsNotPressed(unsigned short key)
{
	return !(press[key >> 5] & 1 << (key & 0x1f));
}

bool Keyboard::IsTriggered(unsigned short key)
{
	
	return triggered[key >> 5] & 1 << (key & 0x1f);
}

bool Keyboard::IsNotTriggered(unsigned short key)
{
	return !(triggered[key >> 5] & 1 << (key & 0x1f));
}

bool Keyboard::GetKey(unsigned char& key)
{
	return false;
}

bool Keyboard::Nothing()
{
	int zeros[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	return( memcmp(press,zeros,sizeof(press))==0 );
}

bool Keyboard::Any()
{
	int zeros[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	return(memcmp(press, zeros, sizeof(press)) != 0);
}

const char* Keyboard::GetCharAsString()
{
	// TODO
	const char* cc = "H";
	return cc;
}

unsigned int Keyboard::GetString(char*, unsigned int)
{
	// TODO
	return 0;
}

unsigned int Keyboard::TapCounter(unsigned char key)
{
	// TODO
	return 0;
}

unsigned int Keyboard::HoldCounter(unsigned char key)
{
	// TODO
	return 0;
}

void Keyboard::StartReceivingData()
{
	// Don't need this method at the moment
}

void Keyboard::ProcessKeys()
{
	for (int i = 0; i < 16; i++)
	{
		// a key is released if it was pressed last frame, but not this frame
		release[i] = prevFrame[i] & (~press[i]);
		// a key is tapped this frame if it was pressed this frame, but not last
		triggered[i] = press[i] & (~prevFrame[i]);
	}

	// Should just use one, but the naming is convenient
	memcpy(prevFrame, press, sizeof(int) * 16);
}

void Keyboard::StopReceivingData()
{
	// Don't need this method at the moment
}

void Keyboard::Update(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS)
	{
		// This bit shifting turns 'key' into a 
		// bit index in the entire array, which 
		// holds 512 bits total.

		// toggle bit on
		press[key >> 5] |= 1 << (key & 0x1f);
	}

	if (action == GLFW_RELEASE)
	{
		// toggle bit off
		press[key >> 5] &= ~(1 << (key & 0x1f));
	}
}

void Keyboard::Reset()
{
	for ( int i = 0; i < 16; i++)
	{
		triggered[i] = 0;
		press[i] = 0;
		release[i] = 0;
		currFrame[i] = 0;
		prevFrame[i] = 0;
	}
	
}
