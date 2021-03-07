#version 330 core

layout(location = 0) in vec2 aPos;
layout(location = 1) in vec2 aTexCoord;

out vec2 TexCoord;

// always sort alphabetically,
// that's how OpenGL sets location
// index for each by default
uniform float layer;
uniform float posX;
uniform float posY;
uniform float scaleX;
uniform float scaleY;

void main()
{
    gl_Position = vec4(
		aPos.x * scaleX + posX,
		aPos.y * scaleY + posY, 
		layer, 
		1.0);
	
    TexCoord = vec2(aTexCoord.x, aTexCoord.y);
}