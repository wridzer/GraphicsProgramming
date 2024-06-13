#ifndef MODEL_OBJECT_H
#define MODEL_OBJECT_H

#pragma once

#include "model.h"
#include "shader.h"

class ModelObject
{
	public:
		ModelObject();
		~ModelObject();

		void SetShader(Shader* shader);
		void LoadModel(const char* path, bool gamma = false);
		void LoadTextures(const char* diffuse, const char* specular, const char* normal, const char* roughness, const char* ao);
		void LoadTextures(const char* diffuse);
		void LoadTextures(const char* diffuse, const char* ao);
		void Draw(glm::vec3 lightDirection, glm::vec3 cameraPosition, glm::mat4 view, glm::mat4 projection);


		glm::vec3 pos, rot, scale;
		Model* model;
		Shader* shader;
		unsigned int diffuseMap, specularMap, normalMap, roughnessMap, aoMap;

private:
	unsigned int LoadTexture(const char* path, int comp = 0);
};

#endif