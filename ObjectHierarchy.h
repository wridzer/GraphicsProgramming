#pragma once

#include "ModelObject.h"
#include <vector>

class ObjectHierarchy
{

	public:
		ObjectHierarchy();
		~ObjectHierarchy();

		ModelObject* CreateModelObject(
			const char* path,
			const char* texturePath,
			Shader* shader,
			glm::vec3 pos,
			glm::vec3 rot,
			glm::vec3 scale
		);

		std::vector<ModelObject*> objects;
};
