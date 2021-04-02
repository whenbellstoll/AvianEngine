#include <GL/glew.h>
#include <GLFW/glfw3.h>


class Gamepad {
public:
	Gamepad();
	~Gamepad();
	int GamepadId;
	int present;
	// GamepadState current
	// GamepadState triggered
	// GamepadState released
	// GamepadState previous
	void SetPresent();
	bool IsPresent();
	void GetState();
	void Process();
	float GetAxis(int axis);
	bool IsPressed(int button);


};