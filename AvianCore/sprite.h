#pragma once

struct SpriteStruct
{
	unsigned int texture;
	unsigned int startingVertex;
};

SpriteStruct* Sprite_Init(const char* filename);