#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "ObjectHierarchy.h"

// settings
const unsigned int SCR_WIDTH = 1280;
const unsigned int SCR_HEIGHT = 720;

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
void UpdateCamera();

// Window callbacks
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);

//input
bool keys[1024];

// Global positions
glm::vec3 lightDirection = glm::normalize(glm::vec3(-0.5f, -0.5f, -0.5f));
glm::vec3 cameraPosition = glm::vec3(-10.0f, 5.0f, 5.0f);
glm::vec3 cameraOffset = glm::vec3(0.0f, 3.0f, -12.0f);

// Camera variables
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;
float fov = 45.0f;
float sensitivity = 15.0f;
glm::quat camQuat = glm::quat(glm::vec3(0, 0, 0));
float camYaw, camPitch;
// Camera smoothing variables
glm::vec3 smoothedCameraPosition = glm::vec3(0.0f);
glm::quat smoothedCameraRotation = glm::quat(1.0f, 0.0f, 0.0f, 0.0f);
float cameraLag = 0.1f; // The lower the value, the more laggy the camera is

// Global variables
unsigned int boxVAO, boxEBO;
int boxSize, boxNumIndeces;
glm::mat4 view, projection;
float globalTime = 0.0f;

// Terrain variables
unsigned int terrainVAO, terrainIndexCount, heightmapID, heightNormalID;
unsigned char* heightmapTexture;
unsigned int dirtTexture, grassTexture, rockTexture, snowTexture, sandTexture;

// Car physics variables
glm::vec3 carVelocity = glm::vec3(0.0f);
float carMass = 1430.0f;
float horsepower = 276.0f;
float maxForce = (horsepower * 745.7f); // Force applied in Newtons
float accelerationRate = maxForce / carMass * 0.07f; // Adjusted acceleration
float baseTurnRate = 2.0f; // Base turn rate
float forwardFriction = 0.3f; // Friction coefficient for forward movement
float lateralFriction = 1.0f; // Friction for lateral movement to balance sliding

// Objects
ModelObject* car;
glm::quat carQuat = glm::quat(glm::vec3(0, 0, 0));
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

    // Player
    stbi_set_flip_vertically_on_load(false);
    glDisable(GL_CULL_FACE);
    Shader playerShader("Resources/Shaders/psxVertexShader.glsl", "Resources/Shaders/psxFractalShader.glsl");
    car = new ModelObject();
    car->pos = glm::vec3(0.0f, 0.7f, 10.0f);
    car->rot = glm::vec3(0.0f, 0.0f, 0.0f);
    car->scale = glm::vec3(1.0f, 1.0f, 1.0f);
    car->LoadModel("Resources/Models/nissan_skyline_r32/skyline.obj");
    car->LoadTextures("Resources/Models/nissan_skyline_r32/textures/r32_pixel_art_texture.png");
    car->SetShader(&playerShader);
    cameraPosition = car->pos + cameraOffset;

    // Create objects
    ObjectHierarchy objectHierarchy = ObjectHierarchy();
    objectVec = objectHierarchy.objects;

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
        UpdateCamera();

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
        car->Draw(lightDirection, cameraPosition, view, projection);

        objectVec[0]->rot = glm::vec3(0.0f, 1.0f * globalTime, 0.0f);
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

void UpdateCamera() {
    // Update car position and rotation
    glm::vec3 carForward = carQuat * glm::vec3(0, 0, 1); // Forward direction is +Z
    glm::vec3 targetCameraPosition = car->pos + carForward * cameraOffset.z + glm::vec3(0, cameraOffset.y, 0);
    glm::quat targetCameraRotation = carQuat;

    // Interpolate camera position and rotation for lag effect
    smoothedCameraPosition = glm::mix(smoothedCameraPosition, targetCameraPosition, cameraLag);
    smoothedCameraRotation = glm::slerp(smoothedCameraRotation, targetCameraRotation, cameraLag);

    // Update view matrix with smoothed camera position and orientation
    glm::vec3 camForward = smoothedCameraRotation * glm::vec3(0, 0, 1); // Look direction is +Z
    glm::vec3 camUp = smoothedCameraRotation * glm::vec3(0, 1, 0); // Up direction is +Y
    view = glm::lookAt(smoothedCameraPosition, smoothedCameraPosition + camForward, camUp);
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
void processInput(GLFWwindow* window, float deltaTime)
{
    if (keys[GLFW_KEY_ESCAPE])
        glfwSetWindowShouldClose(window, true);

    glm::vec3 carAcceleration = glm::vec3(0.0f);
    bool carMoved = false;

    if (keys[GLFW_KEY_W])
    {
        carAcceleration += carQuat * glm::vec3(0, 0, accelerationRate); // Forward acceleration
        carMoved = true;
    }
    if (keys[GLFW_KEY_S])
    {
        carAcceleration += carQuat * glm::vec3(0, 0, -accelerationRate); // Backward acceleration
        carMoved = true;
    }

    // Calculate friction
    glm::vec3 forwardDir = carQuat * glm::vec3(0, 0, 1);
    glm::vec3 lateralDir = carQuat * glm::vec3(1, 0, 0);

    // Decompose velocity into forward and lateral components
    float forwardSpeed = glm::dot(carVelocity, forwardDir);
    float lateralSpeed = glm::dot(carVelocity, lateralDir);

    // Apply friction differently based on the direction of motion
    glm::vec3 forwardVelocity = forwardDir * forwardSpeed;
    glm::vec3 lateralVelocity = lateralDir * lateralSpeed;

    forwardVelocity *= (1.0f - forwardFriction * deltaTime);
    lateralVelocity *= (1.0f - lateralFriction * deltaTime);

    carVelocity = forwardVelocity + lateralVelocity;

    // Update car velocity and position
    carVelocity += carAcceleration * deltaTime;
    car->pos += carVelocity * deltaTime;

    // Calculate speed-dependent turn rate
    float speed = glm::length(carVelocity);
    float turnRate = baseTurnRate * glm::clamp(speed / 25.0f, 0.0f, 1.0f); // Adjusted scaling for slower turning response

    // Handle turning only if the car is moving
    if (speed > 0.1f)
    {
        float direction = (forwardSpeed >= 0) ? 1.0f : -1.0f; // Determine direction based on forward speed

        if (keys[GLFW_KEY_A])
        {
            carQuat *= glm::quat(glm::vec3(0, direction * turnRate * deltaTime, 0));
        }
        if (keys[GLFW_KEY_D])
        {
            carQuat *= glm::quat(glm::vec3(0, -direction * turnRate * deltaTime, 0));
        }
    }

    // Update car rotation
    car->rot = glm::eulerAngles(carQuat);

    if(keys[GLFW_KEY_SPACE])
    {
        cameraPosition += camQuat * glm::vec3(0, 1, 0) * sensitivity * deltaTime;
        carMoved = true;
    }
    if(keys[GLFW_KEY_LEFT_CONTROL])
    {
        cameraPosition += camQuat * glm::vec3(0, -1, 0) * sensitivity * deltaTime;
        carMoved = true;
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
    world = glm::translate(world, smoothedCameraPosition);
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