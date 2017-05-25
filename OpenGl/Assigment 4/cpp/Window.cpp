#include <iostream>

// GLEW
#define GLEW_STATIC
#include <glew.h>

// GLFW
#include <glfw3.h>


GLFWwindow* createWindow() {



	const int WIDTH = 700, HEIGHT = 700;

	//Initilaising glfw and catching error when it fails
	if (glfwInit() == false) {
		std::cout << "glfw failed to initilaise!" << std::endl;

	}

	// To run this application opengl 3.3+ is required
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_SAMPLES, 4); //NOIDEA
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //NOIDEA
	glfwWindowHint(GLFW_RESIZABLE, false); // The Window is not resizable

										   // Creating a pointer that holds our window object returned from the glfw function
										   // param width, heights, title, window or fullscreenmode, window to share resources, last 2 are mainly null
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Learning OpenGl", NULL, NULL);

	// Setting the window to our Current context 
	glfwMakeContextCurrent(window);

	// Setting the window position
	glfwSetWindowPos(window, 600, 250);

	// Initilaizing GLEW to use functions like shaders, vao and stuff 
	glewExperimental = GL_TRUE;
	// Initialize GLEW to setup the OpenGL Function pointers
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize GLEW" << std::endl;

	}
	// Sets the Viewport/ rectangle in which our rendering should appear on the screen (from our vector graphic to our defnied size - viewporttransformation) 
	int width, height;

	// Function that get the size of our created window and saves the data in width and height so our Viewport will always get the information from the window we create
	glfwGetFramebufferSize(window, &width, &height);

	//  First 2 parameters (0,0) set the position of the lower left corner, and with and height set the position of the upper right corner
	glViewport(0, 0, width, height);

	// Catching error when no window was created
	if (window == NULL) {
		std::cout << "No window was created!" << std::endl;
		glfwTerminate(); // all Windows will be closed and glfw will turn into an uninitilaized state

	}

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	return window;
}






