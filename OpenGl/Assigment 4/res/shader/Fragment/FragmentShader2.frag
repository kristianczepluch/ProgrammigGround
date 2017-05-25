#version 330 core

out vec4 color;
in vec2 tcs;

uniform sampler2D ourTexture2;

void main(){
color = texture(ourTexture2,tcs);
if(color.a <= 0.1){
discard;
}
}