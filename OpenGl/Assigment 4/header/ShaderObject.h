#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glew.h>

class ShaderObject
{
public:
	ShaderObject(const GLchar* vertexPath, const GLchar* fragmentPath);
	GLuint getShaderID();
	void use();
	~ShaderObject();
private:
	GLuint Program;
};

