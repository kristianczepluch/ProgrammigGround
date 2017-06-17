#pragma once
#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>; 

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader {
public:
	unsigned int Program;
	Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
	void use();
	~Shader();
};

#endif