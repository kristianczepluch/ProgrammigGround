#version 330 core

out vec4 color;
in vec2 tcs;
uniform sampler2D DayHouseTexture;
uniform sampler2D NightHouseTexture;
uniform float alpha;

void main(){

vec4 color1 = texture(DayHouseTexture,tcs);
vec4 color2 = texture(NightHouseTexture,tcs);
color = ((alpha*color2)+((1-alpha)*color1));

}