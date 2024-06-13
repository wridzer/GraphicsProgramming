#include "ObjectHierarchy.h"

ObjectHierarchy::ObjectHierarchy()
{
	// shader
	Shader* shader = new Shader(
		"Resources/Shaders/psxVertexShader.glsl",
		"Resources/Shaders/psxFractalShader.glsl"
	);

	//// building
	//ModelObject* building = new ModelObject();
	//building->pos = glm::vec3(0.0f, 0.0f, 0.0f);
	//building->rot = glm::vec3(0.0f, 0.0f, 0.0f);
	//building->scale = glm::vec3(1.0f, 1.0f, 1.0f);
	//building->LoadModel(, false);
	//building->LoadTextures();
	//building->SetShader(shader);
	//objects.push_back(building);

	//// tree
	//ModelObject* tree = new ModelObject();
	//tree->pos = glm::vec3(0.0f, 0.0f, 0.0f);
	//tree->rot = glm::vec3(0.0f, 0.0f, 0.0f);
	//tree->scale = glm::vec3(1.0f, 1.0f, 1.0f);
	//tree->LoadModel("resources/objects/tree/tree.obj", false);
	//tree->LoadTextures();
	//tree->SetShader(shader);
	//objects.push_back(tree);

	for (size_t i = 0; i < 3; i++)
	{
		// road
		ModelObject* road = CreateModelObject(
			"Resources/Models/road/road.obj",
			"Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
			shader,
			glm::vec3(0.0f, 0.0f, i * 6.3f),
			glm::vec3(0.0f, 0.0f, 0.0f),
			glm::vec3(1.0f, 1.0f, 1.0f)
		);
		objects.push_back(road);
	}

	// car
	stbi_set_flip_vertically_on_load(false);
	ModelObject* car = CreateModelObject(
		"Resources/Models/nissan_skyline_r32/skyline.obj",
		"Resources/Models/nissan_skyline_r32/textures/r32_pixel_art_texture.png",
		shader,
		glm::vec3(0.0f, 1.0f, 0.0f),
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(1.0f, 1.0f, 1.0f)
	);
	objects.push_back(car);

}

ModelObject* ObjectHierarchy::CreateModelObject(
	const char* modelPath,
	const char* texturePath,
	Shader* shader,
	glm::vec3 pos = glm::vec3(0.0f, 0.0f, 0.0f),
	glm::vec3 rot = glm::vec3(0.0f, 0.0f, 0.0f),
	glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f)
	)
{
	ModelObject* object = new ModelObject();
	object->pos = pos;
	object->rot = rot;
	object->scale = scale;
	object->LoadModel(modelPath, false);
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
