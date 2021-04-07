#include "globals.h"

void Input_Update(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS)
	{
		// This bit shifting turns 'key' into a 
		// bit index in the entire array, which 
		// holds 512 bits total.

		// toggle bit on
		pKeyboard->press[key >> 5] |= 1 << (key & 0x1f);
	}

	if (action == GLFW_RELEASE)
	{
		// toggle bit off
		pKeyboard->press[key >> 5] &= ~(1 << (key & 0x1f));
	}
}

void Mouse_Update(GLFWwindow* window, int key, int action, int mods)
{
	if (action == GLFW_PRESS)
	{
		// toggle bit on
		pMouse->press[key] = 1;
	}

	if (action == GLFW_RELEASE)
	{
		// toggle bit off
		pMouse->press[key] = 0;
	}
}

void Mouse_Position_Update(GLFWwindow* window, double xpos, double ypos)
{
}
