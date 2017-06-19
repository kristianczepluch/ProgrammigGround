#version 330 core

out vec4 color;
in vec2 tcs;
uniform sampler2D WoodTexture;

void main(){

color = texture(WoodTexture,tcs);

}