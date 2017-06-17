#version 330 core

out vec4 color;
in vec2 tcs;
uniform sampler2D ourTexture1;

void main(){
color = texture(ourTexture1, tcs);

if(color.a == 0){
discard;
}

}