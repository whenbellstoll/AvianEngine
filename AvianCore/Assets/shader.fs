#version 330 core

in vec2 TexCoord;
out vec4 FragColor;

uniform sampler2D texture1;
uniform float transparentB;
uniform float transparentG;
uniform float transparentR;

void main()
{
    vec4 color = texture(texture1, TexCoord);
    if( color.rgb == vec3(transparentR, transparentG, transparentB) )
	discard;
    FragColor = color;
}