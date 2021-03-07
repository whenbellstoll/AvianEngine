#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// Hope to use the Keyboard class from Avian later for this, but this implementation will do for now.
void Input_Update(GLFWwindow* window, int key, int scancode, int action, int mods);
