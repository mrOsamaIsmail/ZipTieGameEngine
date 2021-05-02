//HEADER GUARDS
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
//ENABLES TRANSFORM OPERTAIONS TO BE INCLUDED IN THIS TRANSLATION UNIT
#define Z_TRANSFORM_OPERATIONS

#include "../pch.h"


class GameObject 
{
public:
	entt::entity entityHandle;
	GameObject(glm::vec3 initialPosition);
	GameObject();
	~GameObject();
	

};





#endif // !GAMEOBJECT_H
