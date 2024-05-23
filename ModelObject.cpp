#include "ModelObject.h"
#include <glm/gtc/type_ptr.hpp>

ModelObject::ModelObject()
{
	pos = glm::vec3(0.0f);
	rot = glm::vec3(0.0f);
	scale = glm::vec3(1.0f);
	model = nullptr;
	diffuseMap = 0;
	specularMap = 0;
	normalMap = 0;
	roughnessMap = 0;
	aoMap = 0;
}

ModelObject::~ModelObject()
{
	delete model;
}

void ModelObject::LoadModel(const char* path, bool gamma)
{
	model = new Model(path, gamma);
}

void ModelObject::LoadTextures(const char* diffuse, const char* specular, const char* normal, const char* roughness, const char* ao)
{
	diffuseMap = LoadTexture(diffuse);
	specularMap = LoadTexture(specular);
	normalMap = LoadTexture(normal);
	roughnessMap = LoadTexture(roughness);
	aoMap = LoadTexture(ao);
}

void ModelObject::Draw(Shader* shader, glm::vec3 lightDirection, glm::vec3 cameraPosition, glm::mat4 view, glm::mat4 projection)
{
	shader->use();
	shader->setInt("material.diffuse", 0);
	shader->setInt("material.specular", 1);
	shader->setInt("material.normal", 2);
	shader->setInt("material.roughness", 3);
	shader->setInt("material.ao", 4);

	// Set up model
	glm::mat4 world = glm::mat4(1.0f);
	world = glm::translate(world, pos);
	world = world * glm::mat4(glm::quat(rot));
	world = glm::scale(world, scale);

	glUniformMatrix4fv(glGetUniformLocation(shader->ID, "world"), 1, GL_FALSE, glm::value_ptr(world));
	glUniformMatrix4fv(glGetUniformLocation(shader->ID, "view"), 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(glGetUniformLocation(shader->ID, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

	glUniform3fv(glGetUniformLocation(shader->ID, "lightDirection"), 1, glm::value_ptr(lightDirection));
	glUniform3fv(glGetUniformLocation(shader->ID, "cameraPosition"), 1, glm::value_ptr(cameraPosition));

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, diffuseMap);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, specularMap);
	glActiveTexture(GL_TEXTURE2);
	glBindTexture(GL_TEXTURE_2D, normalMap);
	glActiveTexture(GL_TEXTURE3);
	glBindTexture(GL_TEXTURE_2D, roughnessMap);
	glActiveTexture(GL_TEXTURE4);
	glBindTexture(GL_TEXTURE_2D, aoMap);

	model->Draw(shader->ID);
}

unsigned int ModelObject::LoadTexture(const char* path, int comp)
{
	unsigned int textureID;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height, numChannels;
	unsigned char* data = stbi_load(path, &width, &height, &numChannels, comp);
	if (data)
	{
		if (comp != 0)
			numChannels = comp;
		GLenum format = NULL;
		if (numChannels == 1)
			format = GL_RED;
		else if (numChannels == 3)
			format = GL_RGB;
		else if (numChannels == 4)
			format = GL_RGBA;

		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}

	stbi_image_free(data);

	glBindTexture(GL_TEXTURE_2D, 0);

	return textureID;
}