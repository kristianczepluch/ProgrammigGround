#include <iostream>
#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"



Texture::Texture(const GLchar* imagePath, int colorValue) {
	glGenTextures(1, &ID);
	glBindTexture(GL_TEXTURE_2D, ID);
	// Setting up the texture
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Load and generate the texture
	int width, height, nrChannels;
	unsigned char *data = stbi_load(imagePath, &width, &height, &nrChannels, 0);
	if (data)
	{
		if(colorValue==0) glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		else glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::bind() {
	glBindTexture(GL_TEXTURE_2D, ID);
}

void Texture::unbind() {
	glBindTexture(GL_TEXTURE_2D, 0);
}

GLuint Texture::getProgram() {
	return ID;
}

Texture::~Texture() {
}