#include "globals.h"

void Input_Update(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS)
	{
		// This bit shifting turns 'key' into a 
		// bit index in the entire array, which 
		// holds 512 bits total. This was used in
		// CTR to store bits depending on what 
		// has been unlocked in Adventure Mode

		// toggle bit on
		global.keys.hold[key >> 5] |= 1 << (key & 0x1f);
	}

	if (action == GLFW_RELEASE)
	{
		// toggle bit off
		global.keys.hold[key >> 5] &= ~(1 << (key & 0x1f));
	}
}

void Input_ProcessState()
{
	Keyboard* pKeys = &global.keys;

	for (int i = 0; i < 16; i++)
	{
		// a key is released if it was pressed last frame, but not this frame
		pKeys->release[i] = pKeys->prevFrame[i] & (~pKeys->hold[i]);

		// a key is tapped this frame if it was pressed this frame, but not last
		pKeys->tap[i] = pKeys->hold[i] & (~pKeys->prevFrame[i]);
	}

	// Should just use one, but the naming is convenient
	memcpy(pKeys->prevFrame, pKeys->hold, sizeof(int) * 16);
}

bool Input_KeyTap(char key)
{
	return global.keys.tap[key >> 5] & 1 << (key & 0x1f);
}

bool Input_KeyHold(char key)
{
	return global.keys.hold[key >> 5] & 1 << (key & 0x1f);
}

bool Input_KeyRelease(char key)
{
	return global.keys.release[key >> 5] & 1 << (key & 0x1f);
}