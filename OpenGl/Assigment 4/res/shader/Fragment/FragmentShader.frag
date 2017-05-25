#version 330 core
in vec3 colors;
in vec2 tcs;
out vec4 color;

uniform sampler2D ourTexture1;

void main(){
color = texture(ourTexture1, tcs);
}