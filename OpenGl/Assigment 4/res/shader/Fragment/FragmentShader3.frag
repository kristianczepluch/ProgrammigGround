#version 330 core

out vec4 color;
in vec2 tcs;
uniform sampler2D ourTexture3;

void main(){
color = texture(ourTexture3,tcs);
if(color.a <= 0.1){
discard;
}
}