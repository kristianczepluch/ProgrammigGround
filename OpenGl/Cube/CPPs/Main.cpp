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

// Window width and hight and prototypes of the callback functions
const int WIDTH = 700, HEIGHT = 700;
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
void letItRotate();

int mode = 0;
glm::mat4 model;

int main()
{
	// Setting up the window
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Cube", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glEnable(GL_DEPTH_TEST);


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
	Shader CubeShader("Shader/Vertex/CubeVertexShader.vert", "Shader/Fragment/CubeFragmentShader.frag");

	// Create Textures
	Texture WoodTexture("Images/wood.png", 0);
	Texture ColoredTexture("Images/colored.jpg", 0);

	// Creating a FloatArray with our Vertex and Texture Data (House)
	float vertices[] = {
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
		0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
	};


	// Generating IDs for VBO VAO and EBO for the House
	GLuint HouseVBO, HouseVAO;
	glGenVertexArrays(1, &HouseVAO);
	glGenBuffers(1, &HouseVBO);


	// Binding VAO first and then initilaising the others
	glBindVertexArray(HouseVAO);
	glBindBuffer(GL_ARRAY_BUFFER, HouseVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// Setting up the attributes @param (index, data per vertex, datatype, normilazied?, stride-> after how many bytes does the next value starts, offset-> where the data starts)
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	// Unbinding the VBO and VAO to avoid mistakes in new initialisations 
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	// Creating Transformation Matrices

	model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));

	glm::mat4 view;
	// note that we're translating the scene in the reverse direction of where we want to move
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

	glm::mat4 projection;
	projection = glm::perspective(glm::radians(45.0f), static_cast<float>((WIDTH / HEIGHT)), 0.1f, 100.0f);

	int modelLoc;
	// GameLoop
	while (!glfwWindowShouldClose(window))
	{
		// Clearing the Color and Depth Buffers
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Send the Data to the uniforms 
		modelLoc = glGetUniformLocation(CubeShader.getProgram(), "model");
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

		modelLoc = glGetUniformLocation(CubeShader.getProgram(), "view");
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(view));

		modelLoc = glGetUniformLocation(CubeShader.getProgram(), "projection");
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(projection));

		// Let the Cube rotate / update the model matrix by each render call
		letItRotate();

		// Checking if any Input from the window was send
		processInput(window);

		// Rendering the House
		CubeShader.bind();
		WoodTexture.bind();
		glBindVertexArray(HouseVAO);
		glDrawArrays(GL_TRIANGLES,0,36);
		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);

		// Swap the screen buffers and check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions 
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}

// glfw: whenever the window size changed this callback function executes
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

void rotateForwards() {
	model = glm::rotate(model, (float)glfwGetTime() * glm::radians(-0.05f), glm::vec3(1.0f, 0.0f, 0.0f));
}

void rotateBackwards() {
	model = glm::rotate(model, (float)glfwGetTime() * glm::radians(0.05f), glm::vec3(1.0f, 0.0f, 0.0f));
}
void rotateRight() {
	model = glm::rotate(model, (float)glfwGetTime() * glm::radians(0.05f), glm::vec3(0.0f, 1.0f, 0.0f));
}

void rotateLeft() {
	model = glm::rotate(model, (float)glfwGetTime() * glm::radians(-0.05f), glm::vec3(0.0f, 1.0f, 0.0f));
}

// Our KeyListener-Actions
void processInput(GLFWwindow *window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) glfwSetWindowShouldClose(window, true);
	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) mode = 0;
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) mode = 1;
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) mode = 2;
	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) mode = 3;
}

void letItRotate() {
	if (mode == 0) rotateForwards();
	if (mode == 1) rotateBackwards();
	if (mode == 2) rotateRight();
	if (mode == 3) rotateLeft();
}