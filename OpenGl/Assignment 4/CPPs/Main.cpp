#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Shader.h"
#include <Windows.h>
#include "Texture.h"
#include "glm\glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

// Variables for the Wing rotation
float x = 0.0f;
float speed = 0.01;

// Background Colors for interpolation
float backgroundcolor1[] = {0.52f, 0.83f, 0.93f, 1};   // --> Morgen
float backgroundcolor2[] = {0.94f, 0.51f, 0.03f, 1};   // --> Mittag
float backgroundcolor3[] = {0.0f, 0.0f, 0.1f, 1};      // --> Nacht
float alpha = 0.0f;

// Window width and hight and prototypes of the callback functions
const int WIDTH = 700, HEIGHT = 700;
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
void updateBackgroundColor();

int main()
{
	// Setting up the window
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Assignment 4", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	glClearColor(backgroundcolor1[0], backgroundcolor1[1], backgroundcolor1[2], backgroundcolor1[3]);
	glClear(GL_COLOR_BUFFER_BIT);


	// Initilaizing GLEW to use functions like shaders, vao etc..
	glewExperimental = GL_TRUE;

	// Initialize GLEW to setup the OpenGL Functions
	if (glewInit() != GLEW_OK) {
		std::cout << "Failed to initialize GLEW" << std::endl;

	}

	// Catching error when no window was created
	if (window == NULL) {
		std::cout << "No window was created!" << std::endl;
		glfwTerminate();
	}

	// Create Shaders
	Shader HouseShader("Shader/Vertex/HouseVertexShader.vert", "Shader/Fragment/HouseFragmentShader.frag");
	Shader FlagShader("Shader/Vertex/FlagVertexShader.vert", "Shader/Fragment/FlagFragmentShader.frag");
	Shader WingShader("Shader/Vertex/WingVertexShader.vert", "Shader/Fragment/WingFragmentShader.frag");

	// Create Textures
	Texture HouseTexture("Images/house.png");
	Texture HouseTextureNight("Images/house_night.png");
	Texture FlagTexture("Images/flag.png");
	Texture FlagTextureNight("Images/flag_night.png");
	Texture WingTexture("Images/wing.png");
	Texture WingTextureNight("Images/wing_night.png");

	// Binding the Texture Uniforms to the corrosponding Shaders
	WingShader.bind();
	glUniform1i(glGetUniformLocation(WingShader.getProgram(), "DayWingTexture"), 0);
	glUniform1i(glGetUniformLocation(WingShader.getProgram(), "NightWingTexture"), 1);
	WingShader.unbind();

	HouseShader.bind();
	glUniform1i(glGetUniformLocation(HouseShader.getProgram(), "DayHouseTexture"), 0);
	glUniform1i(glGetUniformLocation(HouseShader.getProgram(), "NightHouseTexture"), 1);
	HouseShader.unbind();

	FlagShader.bind();
	glUniform1i(glGetUniformLocation(FlagShader.getProgram(), "DayFlagTexture"), 0);
	glUniform1i(glGetUniformLocation(FlagShader.getProgram(), "NightFlagTexture"), 1);
	FlagShader.unbind();


	// Creating a FloatArray with our Vertex and Texture Data (House)
	GLfloat vertices[] = {
		// Positions                                      // Texture-Coordinates
		0.0f, 0.5f, 0.0f,    /* ----> Top           */    0.5f,0.0,
		-0.5f, 0.0f, 0.0f,   /* ----> Top Left      */    0.0f,0.5f,
		0.5f, 0.0f, 0.0f,    /* ----> Top Right     */    1.0f,0.5f,
		-0.5f,-1.0f, 0.0f,   /* ----> Bottom Left   */    0.0f,1.0f,
		0.5f,-1.0f, 0.0f     /* ----> Bottom Right  */   ,1.0f,1.0f
	};

	GLuint indices[] = {
		3,1,2,
		0,1,2,
		3,4,2,
		1,3,4
	};

	// Generating IDs for VBO VAO and EBO for the House
	GLuint HouseVBO, HouseVAO, HouseEBO;
	glGenVertexArrays(1, &HouseVAO);
	glGenBuffers(1, &HouseVBO);
	glGenBuffers(1, &HouseEBO);

	// Binding VAO first and then initilaising the others
	glBindVertexArray(HouseVAO);
	glBindBuffer(GL_ARRAY_BUFFER, HouseVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, HouseEBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Setting up the attributes @param (index, data per vertex, datatype, normilazied?, stride-> after how many bytes does the next value starts, offset-> where the data starts)
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	// Unbinding the VBO and VAO to avoid mistakes in new initialisations 
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);


	// Creating a FloatArray with our Vertex and Texture Data (Flag)
	GLfloat vertices2[] = {
		// Positions                                  // Tcs
		0.0f, 0.5f, 0.0f, /* ---> Unten Links  */     0.0f,1.0f,
		0.0f,0.9f,0.0f,   /* ---> Oben Links   */     0.0f,0.0f,
		0.6f,0.9f,0.0f,   /* ---> Oben Rechts  */     1.0f,0.0f,
		0.6f,0.5f,0.0f,   /* ---> Unten Rechts */     1.0f,1.0f
	};

	// Flag indices
	GLuint indices2[] = {
		0,1,2,
		0,3,2
	};

	// Generating IDs for VBO VAO and EBO for the Flag
	GLuint FlagVBO, FlagVAO, FlagEBO;
	glGenVertexArrays(1, &FlagVAO);
	glGenBuffers(1, &FlagVBO);
	glGenBuffers(1, &FlagEBO);

	// Binding VAO first and then initilaising the others
	glBindVertexArray(FlagVAO);
	glBindBuffer(GL_ARRAY_BUFFER, FlagVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, FlagEBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices2), indices2, GL_STATIC_DRAW);

	// Setting up the attributes @param (index, data per vertex, datatype, normilazied?, stride-> after how many bytes does the next value starts, offset-> where the data starts)
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	// Unbinding the VBO and VAO to avoid mistakes in new initialisations 
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	// Creating a FloatArray with our Vertex and Texture Data (Wing)
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
	glBindVertexArray(VAO2);
	// vbo setup //
	glBindBuffer(GL_ARRAY_BUFFER, VBO2);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices3), vertices3, GL_STATIC_DRAW);

	// ebo setup //
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO2);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices3), indices3, GL_STATIC_DRAW);

	// vao attributes //
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);


	// GameLoop
	while (!glfwWindowShouldClose(window))
	{
		
		// Updating the uniform alpha on each Shader 
		WingShader.bind();
		int alpha1ValueLocation1 = glGetUniformLocation(WingShader.getProgram(), "alpha");
		glUniform1f(alpha1ValueLocation1, alpha);
		WingShader.unbind();

		HouseShader.bind();
		int alpha1ValueLocation2 = glGetUniformLocation(HouseShader.getProgram(), "alpha");
		glUniform1f(alpha1ValueLocation2, alpha);
		HouseShader.unbind();

		FlagShader.bind();
		int alpha1ValueLocation3 = glGetUniformLocation(FlagShader.getProgram(), "alpha");
		glUniform1f(alpha1ValueLocation3, alpha);
		FlagShader.unbind();

		// Checking if any Input from the window was send
		processInput(window);

		// Update the Backgroundcolor based on the alpha value
		updateBackgroundColor();
		glClear(GL_COLOR_BUFFER_BIT);

		// Rendering the House
		glActiveTexture(GL_TEXTURE0);
		HouseTexture.bind();
		glActiveTexture(GL_TEXTURE1);
		HouseTextureNight.bind();
		HouseShader.bind();

		glBindVertexArray(HouseVAO);
		glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);

		// Rendering the Flag
		glActiveTexture(GL_TEXTURE0);
		FlagTexture.bind();
		glActiveTexture(GL_TEXTURE1);
		FlagTextureNight.bind();

		FlagShader.bind();
		glBindVertexArray(FlagVAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
		FlagShader.unbind();

		//Rendering the Wing 4x with a diffrent transformation and updating the angle to let the wings rotate
		x -= speed;
		for (float i = 0; i <= 270; i += 90) {

			glActiveTexture(GL_TEXTURE0);
			WingTexture.bind();
			glActiveTexture(GL_TEXTURE1);
			WingTextureNight.bind();

			WingShader.bind();
			glm::mat4 transform;
			transform = glm::translate(transform, glm::vec3(0.0f, -0.2f, 0.0f));
			transform = glm::rotate(transform, glm::radians(x) + glm::radians(i), glm::vec3(0.0, 0.0, 1.0));
			transform = glm::translate(transform, glm::vec3(0.2f, 0.5f, 0.0f));

			// Get matrix's uniform location and set matrix
			GLint transformLoc = glGetUniformLocation(WingShader.getProgram(), "transform");
			glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
			glBindVertexArray(VAO2);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
			glBindVertexArray(0);
		}

		// Swap the screen buffers and check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions 
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}

// Our KeyListener-Actions
void processInput(GLFWwindow *window){
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) glfwSetWindowShouldClose(window, true);
	if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS) speed += 0.00001;
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) speed -= 0.00001;
	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) alpha += 0.0001;
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) alpha -= 0.0001;
}

// glfw: whenever the window size changed this callback function executes
void framebuffer_size_callback(GLFWwindow* window, int width, int height){
	glViewport(0, 0, width, height);
}

void updateBackgroundColor() {
	if (alpha < 0.6) {
		glClearColor((((alpha*backgroundcolor2[0]) + ((1.0f - alpha)*backgroundcolor1[0]))), ((alpha*backgroundcolor2[1]) +
			((1.0f - alpha)*backgroundcolor1[1])), (((alpha*backgroundcolor2[2]) + ((1.0f - alpha)*backgroundcolor1[2]))),
			(((alpha*backgroundcolor2[3]) + ((1.0f - alpha)*backgroundcolor1[3]))));
	}
	else {
		glClearColor((((alpha*backgroundcolor3[0]) + ((1.0f - alpha)*backgroundcolor2[0]))), ((alpha*backgroundcolor3[1]) +
			((1.0f - alpha)*backgroundcolor2[1])), (((alpha*backgroundcolor3[2]) + ((1.0f - alpha)*backgroundcolor2[2]))),
			(((alpha*backgroundcolor3[3]) + ((1.0f - alpha)*backgroundcolor2[3]))));
	}
}