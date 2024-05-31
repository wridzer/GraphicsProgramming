#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
//#include "Shader.h"
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
//#include "model.h"
#include "ModelObject.h"
#include <vector>

// settings
const unsigned int SCR_WIDTH = 1200;
const unsigned int SCR_HEIGHT = 900;

// Forward declarations
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window, float deltaTime);
int init(GLFWwindow*& window);
void CreateCube();
unsigned int loadTexture(const char* path, int comp = 0);
void CheckGLError(const std::string& location);
unsigned int GeneratePlane(const char* heightmap, unsigned char*& data, GLenum format, int comp, float hScale, float xzScale, unsigned int& indexCount, unsigned int& heightmapID);
void RenderSkybox(Shader &skyboxShader);
void RenderTerrain(Shader& skyboxShader);

// Window callbacks
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);

//input
bool keys[1024];

// Global positions
glm::vec3 lightDirection = glm::normalize(glm::vec3(-0.5f, -0.5f, -0.5f));
glm::vec3 cameraPosition = glm::vec3(782.9f, 78.5f, 702.8f);

// Camera variables
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;
float fov = 45.0f;
float sensitivity = 15.0f;
glm::quat camQuat = glm::quat(glm::vec3(0, 0, 0));
float camYaw, camPitch;

// Global variables
unsigned int boxVAO, boxEBO;
int boxSize, boxNumIndeces;
glm::mat4 view, projection;
float globalTime = 0.0f;

// Terrain variables
unsigned int terrainVAO, terrainIndexCount, heightmapID, heightNormalID;
unsigned char* heightmapTexture;
unsigned int dirtTexture, grassTexture, rockTexture, snowTexture, sandTexture;

// Objects
ModelObject* backpackObject;
ModelObject* barrelObject, *barrelObject1, *barrelObject2;
ModelObject* vaseObject, *vaseObject1, *vaseObject2, *vaseObject3, *vaseObject4;
std::vector<ModelObject*> objectVec = std::vector<ModelObject*>();

int main()
{
    GLFWwindow* window;
    int result = init(window);
    if (result != 0) return result;

    stbi_set_flip_vertically_on_load(true);

    // build and compile our shader program
    Shader SkyboxShader("Resources/Shaders/SkyVertexShader.glsl", "Resources/Shaders/SkyFractalShader.glsl");
    Shader TerrainShader("Resources/Shaders/TerrainVertexShader.glsl", "Resources/Shaders/TerrainFractalShader.glsl");
    Shader modelShader("Resources/Shaders/modelVertex.glsl", "Resources/Shaders/modelFragment.glsl");
    Shader nadjaShader("Resources/Shaders/modelVertex.glsl", "Resources/Shaders/NadjaFractalShader.glsl");

    // Skybox
    SkyboxShader.use();
    CreateCube();

    // Terrain
    TerrainShader.use();
    terrainVAO = GeneratePlane("Resources/Textures/Heightmap2.png", heightmapTexture, GL_RGBA, 4, 300.0f, 5.0f, terrainIndexCount, heightmapID);

    // Load terrain textures
    heightNormalID = loadTexture("Resources/Textures/heightnormal.png");
    dirtTexture = loadTexture("Resources/Textures/dirt.jpg");
    grassTexture = loadTexture("Resources/Textures/grass.png", 4);
    rockTexture = loadTexture("Resources/Textures/rock.jpg");
    snowTexture = loadTexture("Resources/Textures/snow.jpg");
    sandTexture = loadTexture("Resources/Textures/sand.jpg");
    glUniform1i(glGetUniformLocation(TerrainShader.ID, "mainTex"), 0);
    glUniform1i(glGetUniformLocation(TerrainShader.ID, "normalTex"), 1);
    glUniform1i(glGetUniformLocation(TerrainShader.ID, "dirt"), 2);
    glUniform1i(glGetUniformLocation(TerrainShader.ID, "grass"), 3);
    glUniform1i(glGetUniformLocation(TerrainShader.ID, "rock"), 4);
    glUniform1i(glGetUniformLocation(TerrainShader.ID, "snow"), 5);
    glUniform1i(glGetUniformLocation(TerrainShader.ID, "sand"), 6);

    //backpack
    backpackObject = new ModelObject();
    backpackObject->SetShader(&modelShader);
    backpackObject->LoadModel("Resources/backpack/backpack.obj");
    backpackObject->LoadTextures("Resources/backpack/diffuse.jpg", "Resources/backpack/specular.jpg", "Resources/backpack/normal.png", "Resources/backpack/roughness.jpg", "Resources/backpack/ao.jpg");
    backpackObject->pos = glm::vec3(808.0f, 58.0f, 741.0f);
    backpackObject->scale = glm::vec3(2.0f, 2.0f, 2.0f);
    backpackObject->rot = glm::vec3(0.0f, -85.0f, 6.0f);
    objectVec.push_back(backpackObject);

    //barrels
    barrelObject = new ModelObject();
    barrelObject->SetShader(&nadjaShader);
    barrelObject->LoadModel("Resources/Models/Barrels/Barrel_01.obj");
    barrelObject->LoadTextures("Resources/Models/Barrels/diffuse.jpg",
        "Resources/Models/Barrels/specular.jpg",
        "Resources/Models/Barrels/normal.jpg",
        "Resources/Models/Barrels/roughness.jpg",
        "Resources/Models/Barrels/ao.jpg");
    barrelObject->pos = glm::vec3(813.0f, 55.0f, 737.0f);
    barrelObject->scale = glm::vec3(10.0f, 10.0f, 10.0f);
    barrelObject->rot = glm::vec3(0.0f, 0.0f, 20.0f);
    objectVec.push_back(barrelObject);

    barrelObject1 = new ModelObject();
    barrelObject1->SetShader(&nadjaShader);
    barrelObject1->LoadModel("Resources/Models/Barrels/Barrel_02.obj");
    barrelObject1->LoadTextures("Resources/Models/Barrels/diffuse.jpg",
		"Resources/Models/Barrels/specular.jpg",
		"Resources/Models/Barrels/normal.jpg",
		"Resources/Models/Barrels/roughness.jpg",
		"Resources/Models/Barrels/ao.jpg");
    barrelObject1->pos = glm::vec3(825.0f, 54.0f, 734.0f);
    barrelObject1->scale = glm::vec3(10.0f, 10.0f, 10.0f);
    objectVec.push_back(barrelObject1);

    barrelObject2 = new ModelObject();
    barrelObject2->SetShader(&nadjaShader);
    barrelObject2->LoadModel("Resources/Models/Barrels/Barrel_03.obj");
    barrelObject2->LoadTextures("Resources/Models/Barrels/diffuse.jpg",
        "Resources/Models/Barrels/specular.jpg",
        "Resources/Models/Barrels/normal.jpg",
        "Resources/Models/Barrels/roughness.jpg",
        "Resources/Models/Barrels/ao.jpg");
    barrelObject2->pos = glm::vec3(820.0f, 52.0f, 732.0f);
    barrelObject2->scale = glm::vec3(10.0f, 10.0f, 10.0f);
    objectVec.push_back(barrelObject2);

    //vase
    vaseObject = new ModelObject();
    vaseObject->SetShader(&nadjaShader);
    vaseObject->LoadModel("Resources/Models/Pots/Pot_01.obj");
    vaseObject->LoadTextures("Resources/Models/Pots/Pots_group_Material.018_BaseColor.jpeg",
        "Resources/Models/Pots/Pots_group_Material.018_OcclusionRoughnessMetallic.jpeg",
        "Resources/Models/Pots/Pots_group_Material.018_Normal.jpeg",
        "Resources/Models/Pots/Pots_group_Material.018_OcclusionRoughnessMetallic.jpeg",
        "Resources/Models/Pots/Pots_group_Material.018_OcclusionRoughnessMetallic.jpeg");
    vaseObject->pos = glm::vec3(815.0f, 53.0f, 740.0f);
    vaseObject->scale = glm::vec3(10.0f, 10.0f, 10.0f);
    objectVec.push_back(vaseObject);

    vaseObject1 = new ModelObject();
    vaseObject1->SetShader(&nadjaShader);
    vaseObject1->LoadModel("Resources/Models/Pots/Pot_02.obj");
    vaseObject1->LoadTextures("Resources/Models/Pots/Pots_group_Material.018_BaseColor.jpeg",
		"Resources/Models/Pots/Pots_group_Material.018_OcclusionRoughnessMetallic.jpeg",
		"Resources/Models/Pots/Pots_group_Material.018_Normal.jpeg",
		"Resources/Models/Pots/Pots_group_Material.018_OcclusionRoughnessMetallic.jpeg",
		"Resources/Models/Pots/Pots_group_Material.018_OcclusionRoughnessMetallic.jpeg");
    vaseObject1->pos = glm::vec3(807.0f, 56.0f, 739.0f);
    vaseObject1->scale = glm::vec3(10.0f, 10.0f, 10.0f);
    objectVec.push_back(vaseObject1);

    vaseObject2 = new ModelObject();
    vaseObject2->SetShader(&nadjaShader);
    vaseObject2->LoadModel("Resources/Models/Pots/Pot_03.obj");
    vaseObject2->LoadTextures("Resources/Models/Pots/Pots_group_Material.018_BaseColor.jpeg",
		"Resources/Models/Pots/Pots_group_Material.018_OcclusionRoughnessMetallic.jpeg",
		"Resources/Models/Pots/Pots_group_Material.018_Normal.jpeg",
		"Resources/Models/Pots/Pots_group_Material.018_OcclusionRoughnessMetallic.jpeg",
		"Resources/Models/Pots/Pots_group_Material.018_OcclusionRoughnessMetallic.jpeg");
    vaseObject2->pos = glm::vec3(817.0f, 54.0f, 735.0f);
    vaseObject2->scale = glm::vec3(10.0f, 10.0f, 10.0f);
    objectVec.push_back(vaseObject2);

    vaseObject3 = new ModelObject();
    vaseObject3->SetShader(&nadjaShader);
    vaseObject3->LoadModel("Resources/Models/Pots/Pot_04.obj");
    vaseObject3->LoadTextures("Resources/Models/Pots/Pots_group_Material.018_BaseColor.jpeg",
        "Resources/Models/Pots/Pots_group_Material.018_OcclusionRoughnessMetallic.jpeg",
        "Resources/Models/Pots/Pots_group_Material.018_Normal.jpeg",
        "Resources/Models/Pots/Pots_group_Material.018_OcclusionRoughnessMetallic.jpeg",
        "Resources/Models/Pots/Pots_group_Material.018_OcclusionRoughnessMetallic.jpeg");
    vaseObject3->pos = glm::vec3(807.0f, 52.0f, 731.0f);
    vaseObject3->scale = glm::vec3(10.0f, 10.0f, 10.0f);
    objectVec.push_back(vaseObject3);

    vaseObject4 = new ModelObject();
    vaseObject4->SetShader(&nadjaShader);
    vaseObject4->LoadModel("Resources/Models/Pots/Pot_05.obj");
    vaseObject4->LoadTextures("Resources/Models/Pots/Pots_group_Material.018_BaseColor.jpeg",
		"Resources/Models/Pots/Pots_group_Material.018_OcclusionRoughnessMetallic.jpeg",
		"Resources/Models/Pots/Pots_group_Material.018_Normal.jpeg",
		"Resources/Models/Pots/Pots_group_Material.018_OcclusionRoughnessMetallic.jpeg",
		"Resources/Models/Pots/Pots_group_Material.018_OcclusionRoughnessMetallic.jpeg");
    vaseObject4->pos = glm::vec3(796.0f, 53.3f, 737.0f);
    vaseObject4->scale = glm::vec3(10.0f, 10.0f, 10.0f);
    objectVec.push_back(vaseObject4);

    // Matrices
    view = glm::lookAt(cameraPosition, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    projection = glm::perspective(glm::radians(fov), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 5000.0f);

    // uncomment this call to draw in wireframe polygons.
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // render loop
    while (!glfwWindowShouldClose(window))
    {
        float deltaTime = globalTime;
        globalTime = glfwGetTime();
        deltaTime = globalTime - deltaTime;

        // input
        processInput(window, deltaTime);

        // Rendering
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // rendering
        RenderSkybox(SkyboxShader);
        RenderTerrain(TerrainShader);
        for (size_t i = 0; i < objectVec.size(); i++)
        {
            //objectVec[i]->rot = glm::vec3(0.0f, -time, 0.0f);
            objectVec[i]->Draw(lightDirection, cameraPosition, view, projection);
        }

        // glfw: swap buffers and poll IO events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Cleanup
    glDeleteVertexArrays(1, &boxVAO);
    //glDeleteBuffers(1, &VBO);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
void processInput(GLFWwindow* window, float deltaTime)
{
    if (keys[GLFW_KEY_ESCAPE])
        glfwSetWindowShouldClose(window, true);

    bool camChanged = false;
    if(keys[GLFW_KEY_W])
    {
        cameraPosition += camQuat * glm::vec3(0, 0, 1) * sensitivity * deltaTime;
        camChanged = true;
    }
    if(keys[GLFW_KEY_S])
    {
        cameraPosition += camQuat * glm::vec3(0, 0, -1) * sensitivity * deltaTime;
        camChanged = true;
    }
    if (keys[GLFW_KEY_A])
    {
        cameraPosition += camQuat * glm::vec3(1, 0, 0) * sensitivity * deltaTime;
        camChanged = true;
    }
    if (keys[GLFW_KEY_D])
    {
        cameraPosition += camQuat * glm::vec3(-1, 0, 0) * sensitivity * deltaTime;
        camChanged = true;
    }
    if(keys[GLFW_KEY_SPACE])
    {
        cameraPosition += camQuat * glm::vec3(0, 1, 0) * sensitivity * deltaTime;
        camChanged = true;
    }
    if(keys[GLFW_KEY_LEFT_CONTROL])
    {
        cameraPosition += camQuat * glm::vec3(0, -1, 0) * sensitivity * deltaTime;
        camChanged = true;
    }
    if (keys[GLFW_KEY_Q])
    {
        sensitivity -= 0.5f;
        if(sensitivity < 0.5f) sensitivity = 0.5f;
    }
    if (keys[GLFW_KEY_E])
	{
		sensitivity += 0.5f;
	}

    if (camChanged) {
        glm::vec3 camForward = camQuat * glm::vec3(0, 0, 1);
        glm::vec3 camUp = camQuat * glm::vec3(0, 1, 0);

        view = glm::lookAt(cameraPosition, cameraPosition + camForward, camUp);

        std::cout << "Camera position: " << cameraPosition.x << ", " << cameraPosition.y << ", " << cameraPosition.z << std::endl;
    }

}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_PRESS) {
        keys[key] = true;
    }
    else if (action == GLFW_RELEASE) {
		keys[key] = false;
    }
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    float x = (float)xpos;
    float y = (float)ypos;

    if (firstMouse)
    {
		lastX = x;
		lastY = y;
		firstMouse = false;
	}

    float dx = lastX - x;
    float dy = lastY - y;

    lastX = x;
    lastY = y;

    camYaw += dx;
    camPitch = glm::clamp(camPitch - dy, -90.0f, 90.0f);

    if (camYaw > 180.0f) camYaw -= 360.0f;
    if (camYaw < -180.0f) camYaw += 360.0f;

    camQuat = glm::quat(glm::vec3(glm::radians(camPitch), glm::radians(camYaw), 0));

    glm::vec3 camForward = camQuat * glm::vec3(0, 0, 1);
    glm::vec3 camUp = camQuat * glm::vec3(0, 1, 0);

	view = glm::lookAt(cameraPosition, cameraPosition + camForward, camUp);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

int init(GLFWwindow* &window)
{
    // glfw: initialize and configure
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Kinker?", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    // Register callbacks
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetKeyCallback(window, key_callback);

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        glfwTerminate();
        return -2;
    }

    return 0;
}

void CreateCube()
{
    // set up vertex data (and buffer(s)) and configure vertex attributes
    float vertices[] = {
        // positions            //colors            // tex coords   // normals          //tangents      //bitangents
        0.5f, -0.5f, -0.5f,     1.0f, 1.0f, 1.0f,   1.f, 1.f,       0.f, -1.f, 0.f,     -1.f, 0.f, 0.f,  0.f, 0.f, 1.f,
        0.5f, -0.5f, 0.5f,      1.0f, 1.0f, 1.0f,   1.f, 0.f,       0.f, -1.f, 0.f,     -1.f, 0.f, 0.f,  0.f, 0.f, 1.f,
        -0.5f, -0.5f, 0.5f,     1.0f, 1.0f, 1.0f,   0.f, 0.f,       0.f, -1.f, 0.f,     -1.f, 0.f, 0.f,  0.f, 0.f, 1.f,
        -0.5f, -0.5f, -.5f,     1.0f, 1.0f, 1.0f,   0.f, 1.f,       0.f, -1.f, 0.f,     -1.f, 0.f, 0.f,  0.f, 0.f, 1.f,

        0.5f, 0.5f, -0.5f,      1.0f, 1.0f, 1.0f,   1.f, 1.f,       1.f, 0.f, 0.f,     0.f, -1.f, 0.f,  0.f, 0.f, 1.f,
        0.5f, 0.5f, 0.5f,       1.0f, 1.0f, 1.0f,   1.f, 0.f,       1.f, 0.f, 0.f,     0.f, -1.f, 0.f,  0.f, 0.f, 1.f,

        0.5f, 0.5f, 0.5f,       1.0f, 1.0f, 1.0f,   1.f, 0.f,       0.f, 0.f, 1.f,     1.f, 0.f, 0.f,  0.f, -1.f, 0.f,
        -0.5f, 0.5f, 0.5f,      1.0f, 1.0f, 1.0f,   0.f, 0.f,       0.f, 0.f, 1.f,     1.f, 0.f, 0.f,  0.f, -1.f, 0.f,

        -0.5f, 0.5f, 0.5f,      1.0f, 1.0f, 1.0f,   0.f, 0.f,      -1.f, 0.f, 0.f,     0.f, 1.f, 0.f,  0.f, 0.f, 1.f,
        -0.5f, 0.5f, -.5f,      1.0f, 1.0f, 1.0f,   0.f, 1.f,      -1.f, 0.f, 0.f,     0.f, 1.f, 0.f,  0.f, 0.f, 1.f,

        -0.5f, 0.5f, -.5f,      1.0f, 1.0f, 1.0f,   0.f, 1.f,      0.f, 0.f, -1.f,     1.f, 0.f, 0.f,  0.f, 1.f, 0.f,
        0.5f, 0.5f, -0.5f,      1.0f, 1.0f, 1.0f,   1.f, 1.f,      0.f, 0.f, -1.f,     1.f, 0.f, 0.f,  0.f, 1.f, 0.f,

        -0.5f, 0.5f, -.5f,      1.0f, 1.0f, 1.0f,   1.f, 1.f,       0.f, 1.f, 0.f,     1.f, 0.f, 0.f,  0.f, 0.f, 1.f,
        -0.5f, 0.5f, 0.5f,      1.0f, 1.0f, 1.0f,   1.f, 0.f,       0.f, 1.f, 0.f,     1.f, 0.f, 0.f,  0.f, 0.f, 1.f,

        0.5f, -0.5f, 0.5f,      1.0f, 1.0f, 1.0f,   1.f, 1.f,       0.f, 0.f, 1.f,     1.f, 0.f, 0.f,  0.f, -1.f, 0.f,
        -0.5f, -0.5f, 0.5f,     1.0f, 1.0f, 1.0f,   0.f, 1.f,       0.f, 0.f, 1.f,     1.f, 0.f, 0.f,  0.f, -1.f, 0.f,

        -0.5f, -0.5f, 0.5f,     1.0f, 1.0f, 1.0f,   1.f, 0.f,       -1.f, 0.f, 0.f,     0.f, 1.f, 0.f,  0.f, 0.f, 1.f,
        -0.5f, -0.5f, -.5f,     1.0f, 1.0f, 1.0f,   1.f, 1.f,       -1.f, 0.f, 0.f,     0.f, 1.f, 0.f,  0.f, 0.f, 1.f,

        -0.5f, -0.5f, -.5f,     1.0f, 1.0f, 1.0f,   0.f, 0.f,       0.f, 0.f, -1.f,     1.f, 0.f, 0.f,  0.f, 1.f, 0.f,
        0.5f, -0.5f, -0.5f,     1.0f, 1.0f, 1.0f,   1.f, 0.f,       0.f, 0.f, -1.f,     1.f, 0.f, 0.f,  0.f, 1.f, 0.f,

        0.5f, -0.5f, -0.5f,     1.0f, 1.0f, 1.0f,   0.f, 1.f,       1.f, 0.f, 0.f,     0.f, -1.f, 0.f,  0.f, 0.f, 1.f,
        0.5f, -0.5f, 0.5f,      1.0f, 1.0f, 1.0f,   0.f, 0.f,       1.f, 0.f, 0.f,     0.f, -1.f, 0.f,  0.f, 0.f, 1.f,

        0.5f, 0.5f, -0.5f,      1.0f, 1.0f, 1.0f,   0.f, 1.f,       0.f, 1.f, 0.f,     1.f, 0.f, 0.f,  0.f, 0.f, 1.f,
        0.5f, 0.5f, 0.5f,       1.0f, 1.0f, 1.0f,   0.f, 0.f,       0.f, 1.f, 0.f,     1.f, 0.f, 0.f,  0.f, 0.f, 1.f
    };

    unsigned int indices[] = {  // note that we start from 0!
        // DOWN
        0, 1, 2,   // first triangle
        0, 2, 3,    // second triangle
        // BACK
        14, 6, 7,   // first triangle
        14, 7, 15,    // second triangle
        // RIGHT
        20, 4, 5,   // first triangle
        20, 5, 21,    // second triangle
        // LEFT
        16, 8, 9,   // first triangle
        16, 9, 17,    // second triangle
        // FRONT
        18, 10, 11,   // first triangle
        18, 11, 19,    // second triangle
        // UP
        22, 12, 13,   // first triangle
        22, 13, 23,    // second triangle
    };

    int stride = (3 + 3 + 2 + 3 + 3 + 3) * sizeof(float);

    boxSize = sizeof(vertices) / stride;
    boxNumIndeces = sizeof(indices) / sizeof(int);

    unsigned int VBO;
    glGenVertexArrays(1, &boxVAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(boxVAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &boxEBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, boxEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, (void*)0);
    glEnableVertexAttribArray(0);

    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, stride, (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // uv attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, stride, (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    // normal attribute
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, stride, (void*)(8 * sizeof(float)));
    glEnableVertexAttribArray(3);

    // tan attribute
    glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, stride, (void*)(11 * sizeof(float)));
    glEnableVertexAttribArray(4);

    // bitan attribute
    glVertexAttribPointer(5, 3, GL_FLOAT, GL_FALSE, stride, (void*)(14 * sizeof(float)));
    glEnableVertexAttribArray(5);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    //glBindBuffer(GL_ARRAY_BUFFER, 0);
}

unsigned int loadTexture(const char* path, int comp)
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
        if(comp != 0)
            numChannels = comp ;
        GLenum format = NULL;
		if(numChannels == 1)
			format = GL_RED;
		else if(numChannels == 3)
			format = GL_RGB;
		else if(numChannels == 4)
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

void RenderSkybox(Shader &skyboxShader) {
    glDisable(GL_CULL_FACE);
    glDisable(GL_DEPTH);
    glDisable(GL_DEPTH_TEST);

    skyboxShader.use();

    // Set up skybox
    glm::mat4 world = glm::mat4(1.0f);
    world = glm::translate(world, cameraPosition);
    world = glm::scale(world, glm::vec3(10.0f, 10.0f, 10.0f));

    glUniformMatrix4fv(glGetUniformLocation(skyboxShader.ID, "world"),      1, GL_FALSE, glm::value_ptr(world));
    glUniformMatrix4fv(glGetUniformLocation(skyboxShader.ID, "view"),       1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(glGetUniformLocation(skyboxShader.ID, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
    
    glUniform3fv(glGetUniformLocation(skyboxShader.ID, "lightDirection"), 1, glm::value_ptr(lightDirection));
    glUniform3fv(glGetUniformLocation(skyboxShader.ID, "cameraPosition"), 1, glm::value_ptr(cameraPosition));

    //Rendering
    glBindVertexArray(boxVAO);
    glDrawElements(GL_TRIANGLES, boxNumIndeces, GL_UNSIGNED_INT, 0);

    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH);
    glEnable(GL_DEPTH_TEST);
}

void CheckGLError(const std::string& location)
{
    GLenum err;
    while ((err = glGetError()) != GL_NO_ERROR)
    {
        std::cout << "OpenGL error at " << location << ": " << err << std::endl;
    }
}

void RenderTerrain(Shader& terrainShader) {
    glEnable(GL_DEPTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    terrainShader.use();

    // Set up terrain
    glm::mat4 world = glm::mat4(1.0f);

    glUniformMatrix4fv(glGetUniformLocation(terrainShader.ID, "world"), 1, GL_FALSE, glm::value_ptr(world));
    glUniformMatrix4fv(glGetUniformLocation(terrainShader.ID, "view"), 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(glGetUniformLocation(terrainShader.ID, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

    float t = glfwGetTime();
    lightDirection = glm::normalize(glm::vec3(glm::sin(t), -0.5f, glm::cos(t)));
    glUniform3fv(glGetUniformLocation(terrainShader.ID, "lightDirection"), 1, glm::value_ptr(lightDirection));
    glUniform3fv(glGetUniformLocation(terrainShader.ID, "cameraPosition"), 1, glm::value_ptr(cameraPosition));

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, heightmapID);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, heightNormalID);
    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_2D, dirtTexture);
    glActiveTexture(GL_TEXTURE3);
    glBindTexture(GL_TEXTURE_2D, grassTexture);
    glActiveTexture(GL_TEXTURE4);
    glBindTexture(GL_TEXTURE_2D, rockTexture);
    glActiveTexture(GL_TEXTURE5);
    glBindTexture(GL_TEXTURE_2D, snowTexture);
    glActiveTexture(GL_TEXTURE6);
    glBindTexture(GL_TEXTURE_2D, sandTexture);

    // Rendering
    glBindVertexArray(terrainVAO);
    glDrawElements(GL_TRIANGLES, terrainIndexCount, GL_UNSIGNED_INT, 0);
}

unsigned int GeneratePlane(const char* heightmap, unsigned char* &data, GLenum format, int comp, float hScale, float xzScale, unsigned int& indexCount, unsigned int& heightmapID) {
    int width = 0, height = 0, channels;
    if (heightmap != nullptr && data == nullptr) {
        data = stbi_load(heightmap, &width, &height, &channels, comp);
        if (data) {
            glGenTextures(1, &heightmapID);
            glBindTexture(GL_TEXTURE_2D, heightmapID);

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

            glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, 0);
        }
        else {
			std::cout << "Failed to load heightmap" << std::endl;
		}
    }

    int stride = 8;
    float* vertices = new float[(width * height) * stride];
    unsigned int* indices = new unsigned int[(width - 1) * (height - 1) * 6];

    int index = 0;
    for (int i = 0; i < (width * height); i++) {
        // calculate x/z values
        int x = i % width;
        int z = i / width;

        float texHeight = (float)data[i * comp];

        // set position
        vertices[index++] = (float)x * xzScale;
        vertices[index++] = (texHeight / 255.0f) * hScale;
        vertices[index++] = (float)z * xzScale;

        // set normal
        vertices[index++] = 0;
        vertices[index++] = 1;
        vertices[index++] = 0;

        // set uv
        vertices[index++] = (float)x / (float)width;
        vertices[index++] = (float)z / (float)height;
    }

    // OPTIONAL TODO: Calculate normal
    // TODO: Set normal

    index = 0;
    for (int i = 0; i < (width - 1) * (height - 1); i++) {
        int x = i % (width - 1);
        int z = i / (width - 1);

        int vertex = z * width + x;

        indices[index++] = vertex;
        indices[index++] = vertex + width;
        indices[index++] = vertex + width + 1;

        indices[index++] = vertex;
        indices[index++] = vertex + width + 1;
        indices[index++] = vertex + 1;
    }

    unsigned int vertSize = (width * height) * stride * sizeof(float);
    indexCount = ((width - 1) * (height - 1) * 6);

    unsigned int VAO, VBO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertSize, vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount * sizeof(unsigned int), indices, GL_STATIC_DRAW);

    // vertex information!
    // position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * stride, 0);
    glEnableVertexAttribArray(0);
    // normal
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * stride, (void*)(sizeof(float) * 3));
    glEnableVertexAttribArray(1);
    // uv
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(float) * stride, (void*)(sizeof(float) * 6));
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);

    delete[] vertices;
    delete[] indices;

    heightmapTexture = data;
    //stbi_image_free(data);

    return VAO;
}

unsigned int TextureFromFile(const char* path, const string& directory, bool gamma)
{
    string filename = string(path);
    filename = directory + '/' + filename;

    unsigned int textureID;
    glGenTextures(1, &textureID);

    int width, height, nrComponents;
    unsigned char* data = stbi_load(filename.c_str(), &width, &height, &nrComponents, 0);
    if (data)
    {
        GLenum format;
        if (nrComponents == 1)
            format = GL_RED;
        else if (nrComponents == 3)
            format = GL_RGB;
        else if (nrComponents == 4)
            format = GL_RGBA;

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(data);
    }
    else
    {
        std::cout << "Texture failed to load at path: " << path << std::endl;
        stbi_image_free(data);
    }

    return textureID;
}