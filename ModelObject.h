#pragma once

#include "model.h"
#include "shader.h"

class ModelObject
{
	public:
		ModelObject();
		~ModelObject();

		void LoadModel(const char* path, bool gamma = false);
		void LoadTextures(const char* diffuse, const char* specular, const char* normal, const char* roughness, const char* ao);
		void Draw(Shader* shader, glm::vec3 lightDirection, glm::vec3 cameraPosition, glm::mat4 view, glm::mat4 projection);


		glm::vec3 pos, rot, scale;
		Model* model;
		unsigned int diffuseMap = 0, specularMap, normalMap, roughnessMap, aoMap;

private:
	unsigned int LoadTexture(const char* path, int comp = 0);
};