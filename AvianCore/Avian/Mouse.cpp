#include "Mouse.h"

Mouse::Mouse()
{
}

Mouse::~Mouse()
{
}

bool Mouse::IsPressed(unsigned char key)
{
	return press[key] & 1;
}

bool Mouse::IsNotPressed(unsigned char key)
{
	return !(press[key] & 1);
}

bool Mouse::IsTriggered(unsigned char key)
{

	return triggered[key] & 1;
}

bool Mouse::IsNotTriggered(unsigned char key)
{
	return !(triggered[key] & 1);
}

bool Mouse::GetKey(unsigned char& key)
{
	return false;
}

bool Mouse::Nothing()
{
	int zeros[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	return(memcmp(press, zeros, sizeof(press)) == 0);
}

bool Mouse::Any()
{
	int zeros[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	return(memcmp(press, zeros, sizeof(press)) != 0);
}

void Mouse::Process()
{
	for (int i = 0; i < 16; i++)
	{
		// a key is released if it was pressed last frame, but not this frame
		release[i] = prevFrame[i] & (~press[i]);
		// a key is tapped this frame if it was pressed this frame, but not last
		triggered[i] = press[i] & (~prevFrame[i]);
	}

	// Should just use one, but the naming is convenient
	memcpy(prevFrame, press, sizeof(char) * 16);
}