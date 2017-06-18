#version 330 core

out vec4 color;
in vec2 tcs;
uniform sampler2D DayWingTexture;
uniform sampler2D NightWingTexture;
uniform float alpha;

void main(){
vec4 color1 = texture(DayWingTexture,tcs);
vec4 color2 = texture(NightWingTexture,tcs);
color = ((alpha*color2)+((1-alpha)*color1));

if(color.a == 0.0){
discard;
    }
}