#pragma once
#include <gl\glew.h>
class Texture
{
public:
	GLuint ID;
	Texture(const GLchar* imagePath);
	void bind();
	void unbind();
	GLuint getProgram();
	~Texture();
};
