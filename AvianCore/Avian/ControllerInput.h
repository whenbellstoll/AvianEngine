#include <GL/glew.h>
#include <GLFW/glfw3.h>


class Gamepad {
public:
	Gamepad(int id);
	~Gamepad();
	int GamepadId;
	int present;
	int countAxes;
	int countButtons;
	 unsigned char currentButtons[16];
	unsigned char triggeredButtons[16];
	unsigned char releasedButtons[16];
	unsigned char previousButtons[16];
	const float* previousAxis;
	const float* currentAxis;
	void SetPresent();
	bool IsPresent();
	bool GetState();
	void Process();
	float GetAxis(int axis);
	bool IsPressed(unsigned short button);
	bool IsNotPressed(unsigned short button);
	bool IsTriggered(unsigned short button);
	bool IsNotTriggered(unsigned short button);
	bool Nothing();
	bool Any();
	void Reset();

};