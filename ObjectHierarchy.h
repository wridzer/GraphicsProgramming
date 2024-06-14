#pragma once

#include "ModelObject.h"
#include <vector>

class ObjectHierarchy
{

	public:
		ObjectHierarchy();
		~ObjectHierarchy();

		ModelObject* CreateModelObject(
			Shader* shader,
			const char* path,
			const char* texturePath = "",
			glm::vec3 pos = glm::vec3(0.0f, 0.0f, 0.0f),
			glm::vec3 rot = glm::vec3(0.0f, 0.0f, 0.0f),
			glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f)
		);

		std::vector<ModelObject*> objects;
};
