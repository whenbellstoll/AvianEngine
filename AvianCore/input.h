#pragma once

struct Keyboard
{
	// 32 bits per int
	// 512 bits per array
	// enough for all these 
	// https://www.glfw.org/docs/3.3/group__keys.html

	// true for first frame of hold
	int tap[16];

	// true for every frame of hold
	int hold[16];

	// true for first frame of release
	int release[16];

	// raw data for comparison
	int prevFrame[16];
	int currFrame[16];
};

// In the future when we use game controllers,
// which only have ~10 buttons, there will only
// be one int for tap, one for hold, and one for release

void Input_Update(GLFWwindow* window, int key, int scancode, int action, int mods);
void Input_ProcessState();
bool Input_KeyTap(char key);
bool Input_KeyHold(char key);
bool Input_KeyRelease(char key);