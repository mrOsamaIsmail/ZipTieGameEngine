#pragma once
#ifndef _OPENGLCORE
#define _OPENGLCORE
#include "../pch.h"

#define STB_IMAGE_IMPLEMENTATION
#include "core/stb_image.h"
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
		setWindowIcon(wnd, WNDOW_ICON);
		glfwMakeContextCurrent(wnd);
		if (initglad() != 1) 
		{ 
			return nullptr;
		};
		//glfwSetFramebufferSizeCallback(wnd, framebuffer_size_callback);
		glViewport(0, 0, WNDOW_WIDTH, WNDOW_HEIGHT);
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
	
	static inline void setWindowIcon(GLFWwindow* window,const char* filename) 
	{
		GLFWimage image;
		int width, height, nrChannels;
		unsigned char* data = stbi_load("container.jpg", &width, &height, &nrChannels, 0);
		image.width = width;
		image.height = height;
		image.pixels = data;
		glfwSetWindowIcon(window,1 ,&image);
		
	}
	
	void framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}
};

#endif