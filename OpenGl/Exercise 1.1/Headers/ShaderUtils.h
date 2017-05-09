#pragma once
#include <glew.h>

GLuint createVertexShader(GLchar* source);
GLuint createFragmentShader(GLchar* source);
GLuint createShaderProgram(GLuint vertexShader, GLuint fragmentShader);
