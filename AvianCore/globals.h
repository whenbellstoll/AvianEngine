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
#include "Avian/SpriteFull.h"
#include "Avian/Keyboard.h"
#include "Avian/Constants.h"
#include "InputUpdate.h"
#include "Avian/Clip.h"
#include "Avian/CollisionData.h"
#include "Avian/Behavior.h"
#include "ComplieTime/GameFunctions.h"
#include "ComplieTime/LoadAnimations.h"
#include "ComplieTime/LevelFunctions.h"
#include "Avian/Map.h"
#include "Avian/GameNode.h"
#include "Avian/Game.h"



struct Global
{
	GLFWwindow* window;

	GLuint VBO, VAO, PBO, program;

	Mempack ramPack;
	Mempack levelPack;
	Mempack mapvboPack;
	Mempack mappboPack;
	Mempack vboPack;
	Mempack pboPack;

	Keyboard keyboard;
	Game * game;

	int width, height;
};

extern Keyboard *  pKeyboard;

extern SpriteElem SpriteList[MAXACTORS];

extern Global global;

// Behavior
//void** NewVoidPointers(unsigned int);

extern    void** FArray;
extern   int maxFIndex;

// Right now we allocate almost nothing, but
// the dial will be cranked up in future tutorials,
// when we add more stuff, and get to 3D graphics.
// You can allocate several gigabytes if you want
#define vboSize		0x1000   // 0001 kilobytes <-- just a quad
#define pboSize		0x100000 // 1024 kilobytes
#define ramSize		0x100000 // 1024 kilobytes
#define levelSize	0x100000 // 2048 kilobytes
#define mapvboSize	0x1000
#define mappboSize	0x100000
// For industry-level use, please compile in x64 
// instead of x86. When compiling in x86 mode,
// malloc fails with any amount 2gb or more, 1gb - 1.9gb
// return a pointer, but the engine fails to run if 
// you malloc 1.7gb+