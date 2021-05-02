#include "GameObject.h"

GameObject::GameObject(glm::vec3 initialPosition)
{
	entityHandle = ecs_reg.create();
	transformComponent temp = ecs_reg.emplace<transformComponent>(entityHandle, glm::mat4(1.0f));
	temp.transform = glm::translate(temp.transform,initialPosition);
}

GameObject::GameObject()
{
	entityHandle = ecs_reg.create();
	ecs_reg.emplace<transformComponent>(entityHandle, glm::mat4(1.0f));
}

GameObject::~GameObject()
{
}
