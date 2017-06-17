#version 330 core

out vec4 color;

void main(){
color=vec4(gl_FragCoord.x/700,gl_FragCoord.y/700,gl_FragCoord.z/700,1.0f);
}