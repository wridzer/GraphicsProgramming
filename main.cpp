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
void RenderSkybox(Shader &skyboxShader, unsigned int cubemapTexture);
unsigned int GeneratePlane(const char* heightmap, unsigned char*& data, GLenum format, int comp, float hScale, float xzScale, unsigned int& indexCount, unsigned int& heightmapID);
void RenderTerrain(Shader& skyboxShader);
void CheckGLError(const std::string& location);
void UpdateCamera();
unsigned int loadCubemap(vector<std::string> faces);

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

// Skybox variables
unsigned int skyboxVAO, skyboxVBO;
int boxSize, boxNumIndeces;

// Terrain variables
unsigned int terrainVAO, terrainIndexCount, heightmapID, heightNormalID;
unsigned char* heightmapTexture;
unsigned int dirtTexture, grassTexture, rockTexture, snowTexture, sandTexture;


// Global variables
glm::mat4 view, projection;
float globalTime = 0.0f;

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

    // Skybox
    Shader SkyboxShader("Resources/Shaders/SkyVertexShader.glsl", "Resources/Shaders/SkyFractalShader.glsl");
    SkyboxShader.use();
    CreateCube();
    std::vector<std::string> faces{
    "Resources/Textures/skybox/Classic Land/right.png",
    "Resources/Textures/skybox/Classic Land/left.png",
    "Resources/Textures/skybox/Classic Land/up.png",
    "Resources/Textures/skybox/Classic Land/down.png",
    "Resources/Textures/skybox/Classic Land/front.png",
    "Resources/Textures/skybox/Classic Land/back.png"
    };
    unsigned int cubemapTexture = loadCubemap(faces);

    // Terrain
    Shader terrainShader("Resources/Shaders/TerrainVertexShader.glsl", "Resources/Shaders/TerrainFractalShader.glsl");
    terrainShader.use();
    terrainVAO = GeneratePlane("Resources/Textures/Heightmap1.png", heightmapTexture, GL_RGBA, 4, 300.0f, 5.0f, terrainIndexCount, heightmapID);
    dirtTexture = TextureFromFile("dirt.jpg", "Resources/Textures", false);
    grassTexture = TextureFromFile("grass.png", "Resources/Textures", false);
    rockTexture = TextureFromFile("rock.jpg", "Resources/Textures", false);
    snowTexture = TextureFromFile("snow.jpg", "Resources/Textures", false);
    sandTexture = TextureFromFile("sand.jpg", "Resources/Textures", false);
    glUniform1i(glGetUniformLocation(terrainShader.ID, "mainTex"), 0);
    glUniform1i(glGetUniformLocation(terrainShader.ID, "normalTex"), 1);
    glUniform1i(glGetUniformLocation(terrainShader.ID, "dirt"), 2);
    glUniform1i(glGetUniformLocation(terrainShader.ID, "grass"), 3);
    glUniform1i(glGetUniformLocation(terrainShader.ID, "rock"), 4);
    glUniform1i(glGetUniformLocation(terrainShader.ID, "snow"), 5);
    glUniform1i(glGetUniformLocation(terrainShader.ID, "sand"), 6);

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
    projection = glm::perspective(glm::radians(fov), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.3f, 5000.0f);

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
        RenderSkybox(SkyboxShader, cubemapTexture);
        RenderTerrain(terrainShader);
        for (size_t i = 0; i < objectVec.size(); i++)
        {
            //objectVec[i]->rot = glm::vec3(0.0f, -time, 0.0f);
            objectVec[i]->Draw(lightDirection, cameraPosition, view, projection);
        }
        car->Draw(lightDirection, cameraPosition, view, projection);

        // glfw: swap buffers and poll IO events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Cleanup
    glDeleteVertexArrays(1, &skyboxVAO);
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
    glEnable(GL_DEPTH_TEST);
    return 0;
}

void CreateCube()
{
    float skyboxVertices[] = {
        // positions          
        -1.0f,  1.0f, -1.0f,
        -1.0f, -1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,
         1.0f,  1.0f, -1.0f,
        -1.0f,  1.0f, -1.0f,

        -1.0f, -1.0f,  1.0f,
        -1.0f, -1.0f, -1.0f,
        -1.0f,  1.0f, -1.0f,
        -1.0f,  1.0f, -1.0f,
        -1.0f,  1.0f,  1.0f,
        -1.0f, -1.0f,  1.0f,

         1.0f, -1.0f, -1.0f,
         1.0f, -1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,

        -1.0f, -1.0f,  1.0f,
        -1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f, -1.0f,  1.0f,
        -1.0f, -1.0f,  1.0f,

        -1.0f,  1.0f, -1.0f,
         1.0f,  1.0f, -1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
        -1.0f,  1.0f,  1.0f,
        -1.0f,  1.0f, -1.0f,

        -1.0f, -1.0f, -1.0f,
        -1.0f, -1.0f,  1.0f,
         1.0f, -1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,
        -1.0f, -1.0f,  1.0f,
         1.0f, -1.0f,  1.0f
    };

    // skybox VAO
    glGenVertexArrays(1, &skyboxVAO);
    glGenBuffers(1, &skyboxVBO);
    glBindVertexArray(skyboxVAO);
    glBindBuffer(GL_ARRAY_BUFFER, skyboxVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
}

void RenderSkybox(Shader& skyboxShader, unsigned int cubemapTexture) {
    glDepthFunc(GL_LEQUAL); // Change depth function so skybox is drawn at the farthest depth
    glDepthMask(GL_FALSE);
    skyboxShader.use();

    // Remove the translation part of the view matrix
    glm::mat4 view = glm::mat4(glm::mat3(glm::lookAt(smoothedCameraPosition, smoothedCameraPosition + smoothedCameraRotation * glm::vec3(0, 0, -1), smoothedCameraRotation * glm::vec3(0, 1, 0))));
    glm::mat4 projection = glm::perspective(glm::radians(fov), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);

    skyboxShader.setMat4("view", view);
    skyboxShader.setMat4("projection", projection);

    glBindVertexArray(skyboxVAO);
    glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);

    glDepthFunc(GL_LESS); // Set depth function back to default
    glDepthMask(GL_TRUE);
}

void RenderTerrain(Shader& terrainShader) {
    glEnable(GL_DEPTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    terrainShader.use();

    // Set up terrain
    glm::mat4 world = glm::mat4(1.0f);
    world = glm::translate(world, glm::vec3(-1000.0f, -0.5f, -1000.0f));

    glUniformMatrix4fv(glGetUniformLocation(terrainShader.ID, "world"), 1, GL_FALSE, glm::value_ptr(world));
    glUniformMatrix4fv(glGetUniformLocation(terrainShader.ID, "view"), 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(glGetUniformLocation(terrainShader.ID, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

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

unsigned int GeneratePlane(const char* heightmap, unsigned char*& data, GLenum format, int comp, float hScale, float xzScale, unsigned int& indexCount, unsigned int& heightmapID) {
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

void CheckGLError(const std::string& location)
{
    GLenum err;
    while ((err = glGetError()) != GL_NO_ERROR)
    {
        std::cout << "OpenGL error at " << location << ": " << err << std::endl;
    }
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
        else
        {
            stbi_image_free(data);
            return 0;
        }

        glBindTexture(GL_TEXTURE_2D, textureID);

        // Set texture parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

        // Upload texture data
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);


        // Generate mipmaps
        glGenerateMipmap(GL_TEXTURE_2D);

        stbi_image_free(data);
    }
    else
    {
        std::cout << "Texture failed to load at path: " << filename << std::endl;
        stbi_image_free(data);
        return 0;
    }

    return textureID;
}

unsigned int loadCubemap(std::vector<std::string> faces)
{
    unsigned int textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);

    int width, height, nrChannels;
    for (unsigned int i = 0; i < faces.size(); i++)
    {
        unsigned char* data = stbi_load(faces[i].c_str(), &width, &height, &nrChannels, 0);
        if (data)
        {
            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i,
                0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            stbi_image_free(data);
        }
        else
        {
            std::cout << "Cubemap texture failed to load at path: " << faces[i] << std::endl;
            stbi_image_free(data);
        }
    }
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

    return textureID;
}