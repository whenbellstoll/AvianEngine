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
		global.keyboard.press[key >> 5] |= 1 << (key & 0x1f);
	}

	if (action == GLFW_RELEASE)
	{
		// toggle bit off
		global.keyboard.press[key >> 5] &= ~(1 << (key & 0x1f));
	}
}