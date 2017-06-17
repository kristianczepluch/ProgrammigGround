#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Shader.h"
#include <Windows.h>
#include "Texture.h"

// Counters for switching shaders, rendering-mode
int Tcounter = 1;
int Mcounter1 = 1;

// Window width and hight and prototypes of the callback functions
const int WIDTH = 700, HEIGHT = 700;
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

int main()
{
	// Setting up the window
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Assignment 3", NULL, NULL);
	if (window == NULL){
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);


	// Initilaizing GLEW to use functions like shaders, vao etc..
	glewExperimental = GL_TRUE;

	// Initialize GLEW to setup the OpenGL Functions
	if (glewInit() != GLEW_OK){
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
	Shader shader("Shader/Vertex/HouseVertexShader1.vert", "Shader/Fragment/HouseFragmentShader1.frag");

	// Create Textures
	Texture texture1("Images/house.png");
	Texture texture2("Images/flag.png");


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


	// GameLoop
	while (!glfwWindowShouldClose(window))
	{
		// Checking if any Input from the window was send
		processInput(window);
		// Clear the Screen
		glClear(GL_COLOR_BUFFER_BIT);

		// If-statement that decides by the counter var which shader should be used (counter changes by pressing t/m)
		if (Tcounter % 2 == 0) {
			HouseShader.use();
			texture1.bind();
		}else shader.use();

		// Rendering the House
		glBindVertexArray(HouseVAO);
		glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);

		// If-statement that decides by the counter var which shader should be used (counter changes by pressing t/m)
		if (Tcounter % 2 == 0) {
			FlagShader.use();
			texture2.bind();
		}else shader.use();

		// Rendering the Flag
		glBindVertexArray(FlagVAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);

		// Swap the screen buffers and check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions 
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}

// Our KeyListener-Actions
void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS) {
		++Tcounter;
		Sleep(200);
	}
	if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS) {
		++Mcounter1;
		Sleep(200);
		if (Mcounter1 % 2 == 0) glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		else glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);	
	}
}

// glfw: whenever the window size changed this callback function executes
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}


