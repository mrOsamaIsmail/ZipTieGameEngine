#pragma once
#ifndef __PCH
#define __PCH

#include <iostream>
#include <glad/glad.h>
#include <glfw3.h>
#include <entt.hpp>
#include <string.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>

//#include "core/stbImageLayer.h"
//#define STB_IMAGE_IMPLEMENTATION
//#include "core/stb_image.h"

#define WNDOW_WIDTH 720
#define WNDOW_HEIGHT 576
//icon path
#define WNDOW_ICON "engine icon.ico"
#define WNDOW_TITLE "Z2ENGINE"

#define GL_V_MAJOR 4
#define GL_V_MINOR 3


#define prnterror(filename,error) std::cout<<"[ERROR] AT "<<filename<<" :: "<<error<<"\a \n"

#endif