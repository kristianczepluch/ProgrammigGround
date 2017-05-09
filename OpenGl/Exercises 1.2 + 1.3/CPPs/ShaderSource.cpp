#include <iostream>
#include <glew.h>

GLchar* getTriangleVertexSource() {
	GLchar* vertexShaderSource =
		"#version 330 core\n"
		"layout (location = 0) in vec3 position;\n"
		"void main()\n"
		"{\n"
		"gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
		"}";

	return vertexShaderSource;
}

GLchar* getTriangleFragmentSource() {
	GLchar* fragmentShaderSource =
		"#version 330 core\n"
		"out vec4 color;\n"
		"void main()\n"
		"{\n"
		"color = vec4(1.0f,0.0f,0.0f, 1.0f);\n"
		"}";
	return fragmentShaderSource;
        
}

GLchar* getTriangleVertexSource2() {
	GLchar* vertexShaderSource =
		"#version 330 core\n"
		"layout (location = 0) in vec3 position;\n"
		"void main()\n"
		"{\n"
		"gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
		"}";

	return vertexShaderSource;
}

GLchar* getTriangleFragmentSource2() {
	GLchar* fragmentShaderSource =
		"#version 330 core\n"
		"out vec4 color;\n"
		"void main()\n"
		"{\n"
		"color = vec4(1.0f,1.0f,0.0f, 1.0f);\n"
		"}";
	return fragmentShaderSource;

}