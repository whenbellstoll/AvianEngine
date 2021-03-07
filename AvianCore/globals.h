#pragma once

// This should be a pch at some point

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <time.h>

#include "mempack.h"
#include "graphics.h"
#include "sprite.h"
#include "instance.h"
#include "input.h"

struct Global
{
	GLFWwindow* window;

	GLuint VBO, VAO, PBO, program;

	Mempack ramPack;
	Mempack vboPack;
	Mempack pboPack;

	Keyboard keys;
};

extern Global global;

// Right now we allocate almost nothing, but
// the dial will be cranked up in future tutorials,
// when we add more stuff, and get to 3D graphics.
// You can allocate several gigabytes if you want
#define vboSize 0x1000   // 0001 kilobytes <-- just a quad
#define pboSize 0x100000 // 1024 kilobytes
#define ramSize 0x100000 // 1024 kilobytes

// For industry-level engines, please compile
// in x64 instead of x86. All the tutorials are
// x86 because some people dont own x64 computers

// When compiling in x86 mode, malloc fails with
// any amount 2gb or more, 1gb - 1.9gb return a pointer,
// but the engine fails to run if you malloc 1.7gb+