#pragma once
#include "sprite.h"

// Some engines call this Entity,
// some call it Instance, same thing

struct Instance
{
	SpriteStruct* sprite;

	float depth;
	float posX;
	float posY;
	float scaleX;
	float scaleY;
};

void Instance_Draw(Instance* instance);