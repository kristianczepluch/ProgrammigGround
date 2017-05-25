#include <iostream>
#define GLEW_STATIC
#include <glew.h>
#include <glfw3.h>
#include "../Headers/window.h";
#include "../../../../../Documents/Visual Studio 2017/Projects/LearningOpenGl/LearningOpenGl/ShaderObject.h"
#include "../../../../../Documents/Visual Studio 2017/Projects/LearningOpenGl/LearningOpenGl/SOIL2/SOIL2/SOIL2.h"
#include "../../../../../Documents/Visual Studio 2017/Projects/LearningOpenGl/LearningOpenGl/glm/glm.hpp"
#include "../../../../../Documents/Visual Studio 2017/Projects/LearningOpenGl/LearningOpenGl/glm/gtc/matrix_transform.hpp"
#include "../../../../../Documents/Visual Studio 2017/Projects/LearningOpenGl/LearningOpenGl/glm/gtc/type_ptr.hpp"





int main()
{
	// Create Window //
	GLFWwindow* window = createWindow();

	// Creating a Shader using the Shader Class //
	ShaderObject shader("../../../../../Documents/Visual Studio 2017/Projects/LearningOpenGl/LearningOpenGl/VertexShader.vert", "../../../../../Documents/Visual Studio 2017/Projects/LearningOpenGl/LearningOpenGl/FragmentShader.frag");

	// Creating the second Shader for the Flag //

	ShaderObject shader2("../../../../../Documents/Visual Studio 2017/Projects/LearningOpenGl/LearningOpenGl/VertexShader2.vert", "../../../../../Documents/Visual Studio 2017/Projects/LearningOpenGl/LearningOpenGl/FragmentShader2.frag");

	// Creating the second Shader for the Flag //

	ShaderObject shader3("../../../../../Documents/Visual Studio 2017/Projects/LearningOpenGl/LearningOpenGl/VertexShader3.vert", "../../../../../Documents/Visual Studio 2017/Projects/LearningOpenGl/LearningOpenGl/FragmentShader3.frag");



	// Creating a FloatArray with our VertexData //
	GLfloat vertices[] = {
		// Positions                                 // Colors                         // Texture Coordinates (invertet by y axis cuz png)
		0.0f, 0.5f, 0.0f,   /** Spitze       0 */    1.0f,0.0f,0.0f,  /** Rot */        0.5f,0.0f,
		-0.5f, 0.0f, 0.0f,   /** Oben Links   1 */    0.0f,1.0f,0.0f,  /** Grün */       0.0f,0.5f,
		0.5f, 0.0f, 0.0f,   /** Oben Rechts  2 */    0.0f,0.0f,1.0f,  /** Blau */       1.0f,0.5f,
		-0.5f,-1.0f, 0.0f,   /** Unten Links  3 */    1.0f,1.0f,0.0f,  /** Gelb */       0.0f,1.0f,
		0.5f,-1.0f, 0.0f    /** Unten Rechts 4 */   ,0.0f,1.0f,1.0f,  /** Cyan */       1.0f,1.0f
	};

	GLuint indices[] = {
		3,1,2,
		0,1,2,
		3,4,2,
		1,3,4

	};

	// generating IDs //
	GLuint VBO, VAO, EBO, texture;
	glGenVertexArrays(1, &VAO);
	glGenTextures(1, &texture);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	// Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s). //
	glBindVertexArray(VAO);

	// Bind the Texture, telling OpenGL its a 2D texture //
	glBindTexture(GL_TEXTURE_2D, texture);

	// Image wird mit Soil geladen //
	int width, height;
	unsigned char* image = SOIL_load_image("../../../../../Documents/Visual Studio 2017/Projects/LearningOpenGl/res/house.png", &width, &height, 0, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glBindTexture(GL_TEXTURE_2D, 0);


	// vbo setup //
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// ebo setup //
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// setting the attritbutes of the data //
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	// Flag Data
	GLfloat vertices2[] = {
		// Positions       // Tcs
		0.0f, 0.5f, 0.0f,     0.0f,1.0f,
		0.0f,0.9f,0.0f,       0.0f,0.0f,
		0.6f,0.9f,0.0f,       1.0f,0.0f,
		0.6f,0.5f,0.0f,       1.0f,1.0f
	};

	// Flag indices
	GLuint indices2[] = {
		0,1,2,
		0,3,2
	};

	// rendering the flag
	GLuint VBO1, VAO1, EBO1, texture1;
	glGenVertexArrays(1, &VAO1);
	glGenBuffers(1, &VBO1);
	glGenBuffers(1, &EBO1);
	glGenTextures(1, &texture1);
	glBindVertexArray(VAO1);

	// vbo setup //
	glBindBuffer(GL_ARRAY_BUFFER, VBO1);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);

	glBindTexture(GL_TEXTURE_2D, texture1);
	int width1, height1;
	unsigned char* image1 = SOIL_load_image("../../../../../Documents/Visual Studio 2017/Projects/LearningOpenGl/res/flag.png", &width1, &height1, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width1, height1, 0, GL_RGBA, GL_UNSIGNED_BYTE, image1);
	glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glBindTexture(GL_TEXTURE_2D, 0);


	// ebo setup //
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO1);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices2), indices2, GL_STATIC_DRAW);

	// vao attributes //
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	// Wing Data
	GLfloat vertices3[] = {
		// Positions       // Tcs
		0.2f, 0.2f, 0.0f,     1.0f,0.0f,
	    -0.2f,0.2f,0.0f,      0.0f,0.0f,
		-0.2f,-0.5f,0.0f,     0.0f,1.0f,
		0.2f,-0.5f,0.0f,      1.0f,1.0f
	};

	// Flag indices
	GLuint indices3[] = {
		0,1,2,
		0,3,2
	};

	//  Creating the wing VAO
	GLuint VBO2, VAO2, EBO2, texture2;
	glGenVertexArrays(1, &VAO2);
	glGenBuffers(1, &VBO2);
	glGenBuffers(1, &EBO2);
	glGenTextures(1, &texture2);
	glBindVertexArray(VAO2);
	// vbo setup //
	glBindBuffer(GL_ARRAY_BUFFER, VBO2);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices3), vertices3, GL_STATIC_DRAW);

	glBindTexture(GL_TEXTURE_2D, texture2);
	int width2, height2;
	unsigned char* image2 = SOIL_load_image("../../../../../Documents/Visual Studio 2017/Projects/LearningOpenGl/res/wing.png", &width2, &height2, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width2, height2, 0, GL_RGBA, GL_UNSIGNED_BYTE, image2);
	glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glBindTexture(GL_TEXTURE_2D, 0);

	// ebo setup //
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO2);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices3), indices3, GL_STATIC_DRAW);

	// vao attributes //
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	
	

	
	float x = 0.0f;
	while (!glfwWindowShouldClose(window))
	{
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();
		x -= 0.9f;
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Draw our first triangle
		// Draw the House VAO with the first shader

		// Draw the HOUSE VAO
		shader.use();
		glBindTexture(GL_TEXTURE_2D, texture); 
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);
		glBindTexture(GL_TEXTURE_2D, 0);

		//Draw the FLAG VAO with the second shader
		shader2.use();
		glBindTexture(GL_TEXTURE_2D, texture1); // Jetzt bitte 1 xD
		glBindVertexArray(VAO1);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindTexture(GL_TEXTURE_2D, 0);

		//Draw the Wing VAO with the third shader
		for (float i = 0; i <= 270; i += 90) {
			shader3.use();
			glm::mat4 transform;
			transform = glm::translate(transform, glm::vec3(0.0f, -0.2f, 0.0f));
			transform = glm::rotate(transform, glm::radians(x)+glm::radians(i), glm::vec3(0.0, 0.0, 1.0));
			transform = glm::translate(transform, glm::vec3(0.2f, 0.5f, 0.0f));

			// Get matrix's uniform location and set matrix
			GLint transformLoc = glGetUniformLocation(shader3.getShaderID(), "transform");
			glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));


			glBindTexture(GL_TEXTURE_2D, texture2); // Für 1 macht er es aber 2 und 3 haben beide die letzte textur xD
			glBindVertexArray(VAO2);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
			glBindVertexArray(0);
		}
		// Swap the screen buffers
		glfwSwapBuffers(window);
	}
	glfwTerminate();
	return 0;
}


