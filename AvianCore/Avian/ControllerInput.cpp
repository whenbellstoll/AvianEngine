#include "ControllerInput.h"
#include <cstring>

Gamepad::Gamepad(int id)
{
	GamepadId = id;
	SetPresent();
	Reset();
}

Gamepad::~Gamepad()
{
}

void Gamepad::SetPresent()
{
	present = glfwJoystickPresent(GamepadId);
}

bool Gamepad::IsPresent()
{
	SetPresent();
	return present;
}

bool Gamepad::GetState()
{
	if (IsPresent())
	{
		currentAxis = glfwGetJoystickAxes(GamepadId, &countAxes);
		const unsigned char * tempButtons = glfwGetJoystickButtons(GamepadId, &countButtons);
		
		if (countButtons < 16)
		{
			for (int i = 0; i < countButtons; i++)
			{
				currentButtons[i] = tempButtons[i];
			}
			return true;
		}

		for (int i = 0; i < 16; i++)
		{
			currentButtons[i] = tempButtons[i];
		}
		return true;
	}
	return false;
}


void Gamepad::Process()
{
	if (GetState())
	{
		// Buttons
		for (int i = 0; i < countButtons; i++)
		{
			// a key is released if it was pressed last frame, but not this frame
			releasedButtons[i] = previousButtons[i] & (~currentButtons[i]);
			// a key is tapped this frame if it was pressed this frame, but not last
			triggeredButtons[i] = currentButtons[i] & (~previousButtons[i]);
		}

		memcpy(previousButtons, currentButtons, sizeof(char) * 16);
	}
}

float Gamepad::GetAxis(int axis)
{
	//out of bounds
	if (axis < 0 || axis >= countAxes)
	{
		return 0.0f;
	}

	return currentAxis[axis];
}

bool Gamepad::IsPressed(unsigned short button)
{
	if (button < 0 || button >= countButtons) return false;
	
	return currentButtons[button];
}

bool Gamepad::IsNotPressed(unsigned short button)
{
	if (button < 0 || button >= countButtons) return false;

	return !currentButtons[button];
}

bool Gamepad::IsTriggered(unsigned short button)
{
	if (button < 0 || button >= countButtons) return false;

	return triggeredButtons[button];
}

bool Gamepad::IsNotTriggered(unsigned short button)
{
	if (button < 0 || button >= countButtons) return false;

	return !triggeredButtons[button];
}

bool Gamepad::Nothing()
{
	unsigned char zeros[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	if (memcmp(currentButtons, zeros, sizeof(currentButtons)) == 0) {
		for (int i = 0; i < countAxes; i++)
		{
			float test = GetAxis(i);
			if (test > 0.01f || test < -0.01f)
			{
				if (i >= 4) // analog triggers, not sticks
				{
					if (test == -1.0f) continue;
				}
				return false;
			}
		}
		return true;
	}

	return false;
}

bool Gamepad::Any()
{
	return false;
}

void Gamepad::Reset()
{
	for (int i = 0; i < 16; i++)
	{
		triggeredButtons[i] = 0;
		currentButtons[i] = 0;
		releasedButtons[i] = 0;
		previousButtons[i] = 0;
	}

}
