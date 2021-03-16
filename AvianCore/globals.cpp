#include "globals.h"

void** NewVoidPointers(unsigned int i)
{
	void** vArray;
	vArray = (void**)malloc(i * sizeof(void*));
	return vArray;
}