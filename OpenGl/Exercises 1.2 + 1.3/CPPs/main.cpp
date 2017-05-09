#include <iostream>
#define GLEW_STATIC
#include <glew.h>
#include <glfw3.h>
#include "Window.h";
#include "ShaderUtils.h";
#include "ShaderSource.h";
#include "Triangle.h";

// Program, which renders 2 Triangles next to each other with 2 diffrent VAO/VBOs with the GL_DRAW_ELEMENTS Function (Task 1.2)
// and also they use 2 diffrent Shaderprograms which make one of the triangles yellow and the other one red

int main()
{
	 //Create Window
	 GLFWwindow* window = createWindow(); 

	 // Get the ShaderSource
	 GLchar* vertexShaderSource = getTriangleVertexSource();
	 GLchar* fragmentShaderSource = getTriangleFragmentSource();

	 //Compile Shader
	 GLuint vertexShader = createVertexShader(vertexShaderSource);
	 GLuint fragmentShader = createFragmentShader(fragmentShaderSource);

	 //Link Shader
	 GLuint shaderProgram = createShaderProgram(vertexShader, fragmentShader);

	 // Clean Shader
	 glDeleteShader(vertexShader);
	 glDeleteShader(fragmentShader);

	 // Get the ShaderSource
	 vertexShaderSource = getTriangleVertexSource2();
	 fragmentShaderSource = getTriangleFragmentSource2();

	 //Compile Shader
	 vertexShader = createVertexShader(vertexShaderSource);
	 fragmentShader = createFragmentShader(fragmentShaderSource);

	 //Link Shader
	 GLuint shaderProgram2 = createShaderProgram(vertexShader, fragmentShader);


	// Creating a FloatArray with our first VertexData
	 GLfloat vertices[] = {
		 // Positions         
		 -0.2f,0.5f,0.0f,
		 -0.2f,-0.5f,0.0f,
		 -1.0f,-0.5f,0.0f,
	 };

	 // Creating a FloatArray with our second VertexData
	 GLfloat vertices2[] = {
		 // Positions         
		 0.2f,0.5f,0.0f,
		 0.2f,-0.5f,0.0f,
		 1.0f,-0.5f,0.0f,
	 };

	 GLuint indices[] = {
		 3,1,2,
		 0,1,2,
		 3,4,2,
		 1,3,4

	 };


	 GLuint VBO, VAO;
	 glGenVertexArrays(1, &VAO);
	 glGenBuffers(1, &VBO);
	 //glGenBuffers(1, &EBO);
	 // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
	 glBindVertexArray(VAO);
	 glBindBuffer(GL_ARRAY_BUFFER, VBO);
	 glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	 //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	 //glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	 glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	
	 glEnableVertexAttribArray(0);

	 glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind

	 glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs), remember: do NOT unbind the EBO, keep it bound to this VAO


						   // Uncommenting this call will result in wireframe polygons.
						   //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	 GLuint VBO2, VAO2;	 
	 glGenVertexArrays(1, &VAO2);
	 glGenBuffers(1, &VBO2);
	 glBindVertexArray(VAO2);
	 glBindBuffer(GL_ARRAY_BUFFER, VBO2);
	 glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);
	 glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	 glEnableVertexAttribArray(0);
	 glBindBuffer(GL_ARRAY_BUFFER, 0);
	 glBindVertexArray(0);

	 glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	 glClear(GL_COLOR_BUFFER_BIT);

	while (!glfwWindowShouldClose(window))
	{
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();

		// Draw our first triangle
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		//glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glUseProgram(shaderProgram2);
		glBindVertexArray(VAO2);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);

		// Swap the screen buffers
		glfwSwapBuffers(window);
	}
	glfwTerminate();
	return 0;
}


