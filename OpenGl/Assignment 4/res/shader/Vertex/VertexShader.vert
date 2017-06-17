#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 colorsIn;
layout (location = 2) in vec2 texIn;

out vec3 colors;
out vec2 tcs;
uniform mat4 transform;

void main(){
gl_Position = vec4(position, 1.0f);
colors = colorsIn;
tcs = texIn;
}