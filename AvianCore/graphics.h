#pragma once

#include "globals.h"

void CheckShader(GLuint shader);

void CheckProgram(GLuint program);

void InitOpenGL();

void onResize(GLFWwindow* window, int, int);

void CleanOpenGL();