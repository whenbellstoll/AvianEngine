#include "globals.h"

void Instance_Draw(Instance* instance)
{
	// always sort alphabetically,
	// that's how OpenGL sets location
	// index for each by default

	// This would be much more optimal with UBOs
	// that update according to what changes, rather
	// than uniforms that always update, but the
	// point of this series is to teach topics that
	// aren't graphics

	// layer (what draws on top of what)
	glUniform1f(0, instance->depth);

	// position
	glUniform1f(1, instance->posX);
	glUniform1f(2, instance->posY);

	// scale
	glUniform1f(3, instance->scaleX);
	glUniform1f(4, instance->scaleY);

	glBindTexture(GL_TEXTURE_2D, instance->sprite->texture);
	glDrawArrays(GL_TRIANGLE_STRIP, instance->sprite->startingVertex, 4);
}