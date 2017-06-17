#pragma once
#include glglew.h
class Texture
{
public
	GLuint ID;
	Texture(const GLchar imagePath);
	void bind();
	void unbind();
	~Texture();
};

