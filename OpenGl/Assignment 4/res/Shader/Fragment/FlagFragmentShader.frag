#version 330 core

out vec4 color;
in vec2 tcs;
uniform float alpha;
uniform sampler2D DayFlagTexture;
uniform sampler2D NightFlagTexture;

void main(){
vec4 color1 = texture(DayFlagTexture,tcs);
vec4 color2 = texture(NightFlagTexture,tcs);
color = ((alpha*color2)+((1-alpha)*color1));


if(color.a == 0){
discard;
}

}