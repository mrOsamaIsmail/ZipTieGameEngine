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

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
//#include "core/stbImageLayer.h"
//#define STB_IMAGE_IMPLEMENTATION
//#include "core/stb_image.h"

entt::registry ecs_reg;

#define WNDOW_WIDTH 720
#define WNDOW_HEIGHT 576
//icon path
#define WNDOW_ICON "engine icon.ico"
#define WNDOW_TITLE "Z2ENGINE"

#define GL_V_MAJOR 4
#define GL_V_MINOR 3


#define prnterror(filename,error) std::cout<<"[ERROR] AT "<<filename<<" :: "<<error<<"\a \n"

struct transformComponent 
{
	glm::mat4 transform;
	//?? what next ?
	operator const glm::mat4() const{ return transform; }
	operator glm::mat4() { return transform; }
};


//GUARDS SO THAT TRANSFORM OPERATIONS ARENT IN EVERY TRANSLATION UNIT
#define Z_TRANSFORM_OPERATIONS
#ifdef Z_TRANSFORM_OPERATIONS

void transform_translate(entt::entity GameObjecthandle,glm::vec3 translation)
{
	//auto view = ecs_reg.view<const transformComponent>();
	//view.find(GameObjecthandle)
	transformComponent& trans = ecs_reg.get<transformComponent>(GameObjecthandle);
	trans.transform = glm::translate(trans.transform, translation);
}
void transform_rotate()
{

}
void transform_scale()
{


}
#endif

#endif