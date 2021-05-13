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
#include "Avian/Mouse.h"
#include "Avian/ControllerInput.h"
#include "Avian/ViewPort.h"



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

	// Input
	Keyboard keyboard;
	Mouse mouse;

	int width, height;
};

extern Keyboard *  pKeyboard;
extern Mouse * pMouse;
extern Gamepad * pGamepadOne;
extern Gamepad * pGamepadTwo;
extern Gamepad * pGamepadThree;
extern Gamepad * pGamepadFour;
extern Game * myGame;

extern SpriteElem SpriteList[MAXACTORS];

extern Global global;

// Fast sqrt
double inline __declspec (naked) __fastcall fastsqrtASM(double n) // this function isn't actually fast! It's only fast in debug mode.
{
	_asm fld qword ptr[esp + 4]
	_asm fsqrt
	_asm ret 8
}

float inline fastsqrt(float x) // John Carmack's Q_sqrt function, made to return sqrt instead of inverse sqrt
{
	const float xhalf = 0.5f * x;

	union // get bits for floating value
	{
		float x;
		int i;
	} u;
	u.x = x;
	u.i = 0x5f3759df - (u.i >> 1);  // gives initial guess y0
	return x * u.x * (1.5f - xhalf * u.x * u.x);// Newton step, repeating increases accuracy 
}

float inline fastinvsqrt(float x) // John Carmack's Q_sqrt function in the flesh.
{
	const float xhalf = 0.5f * x;

	union // get bits for floating value
	{
		float x;
		int i;
	} u;
	u.x = x;
	u.i = 0x5f3759df - (u.i >> 1);  // gives initial guess y0
	return u.x * (1.5f - xhalf * u.x * u.x); // Newton step, repeating increases accuracy 
}



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