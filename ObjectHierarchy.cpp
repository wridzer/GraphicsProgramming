#include "ObjectHierarchy.h"

ObjectHierarchy::ObjectHierarchy()
{
	// shader
	Shader* shader = new Shader(
		"Resources/Shaders/psxVertexShader.glsl",
		"Resources/Shaders/psxFractalShader.glsl"
	);

	for (size_t i = 0; i < 100; i++)
	{
		// building
		int buildingType = rand() % 9;
		string buildingPath = "Resources/Models/buildings/building" + to_string(buildingType) + ".obj";

		ModelObject* building = CreateModelObject(
			shader,
			buildingPath.c_str(),
			"",
			glm::vec3(-15.0f, 0.0f, i * 50.0f),
			glm::vec3(0.0f, glm::radians(90.0f), 0.0f)
		);
		objects.push_back(building);

		// Tree
		ModelObject* tree = CreateModelObject(
			shader,
			"Resources/Models/tree/tree.obj",
			"Resources/Models/tree/textures/pinetree.png",
			glm::vec3(6.3f, 0.0f, i * 6.3f)
		);
		objects.push_back(tree);

		// road
		ModelObject* road = CreateModelObject(
			shader,
			"Resources/Models/road/road.obj",
			"Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
			glm::vec3(0.0f, 0.0f, i * 6.3f)
		);
		objects.push_back(road);
	}
}

ModelObject* ObjectHierarchy::CreateModelObject(
	Shader* shader,
	const char* modelPath,
	const char* texturePath,
	glm::vec3 pos,
	glm::vec3 rot,
	glm::vec3 scale
	)
{
	ModelObject* object = new ModelObject();
	object->pos = pos;
	object->rot = rot;
	object->scale = scale;
	object->LoadModel(modelPath, false);
	if(texturePath != "")
		object->LoadTextures(texturePath);
	object->SetShader(shader);
	return object;
}

ObjectHierarchy::~ObjectHierarchy()
{
	for (int i = 0; i < objects.size(); i++)
	{
		delete objects[i];
	}
}
