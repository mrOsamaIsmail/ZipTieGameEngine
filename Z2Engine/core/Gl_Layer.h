#pragma once
#ifndef _OPENGLCORE
#define _OPENGLCORE
#include "../pch.h"
class GlLayer 
{
	//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
public:
	static inline GLFWwindow* createWindow()
	{	
		iniitializeOpenGL();
		GLFWwindow* wnd = glfwCreateWindow(WNDOW_WIDTH, WNDOW_HEIGHT, WNDOW_TITLE, NULL, NULL);
		if (wnd == NULL) 
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			GlLayer::terminate();
			return nullptr;
		}
		glfwMakeContextCurrent(wnd);
		if (initglad() != 1) 
		{ 
			return nullptr;
		};
		//glfwSetFramebufferSizeCallback(wnd, framebuffer_size_callback);
		return wnd;
	}
	static inline void iniitializeOpenGL()
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GL_V_MAJOR);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GL_V_MINOR);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	}
	static inline void terminate() 
	{
		glfwTerminate();
	}
	static inline int initglad() 
	{
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << "\n";
			return -1;
		}
		else 
		{
			return 1;
		}
	}
	void framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}
};

#endif