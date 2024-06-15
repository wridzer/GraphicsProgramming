#include "ObjectHierarchy.h"

ObjectHierarchy::ObjectHierarchy()
{
    // shader
    Shader* shader = new Shader(
        "Resources/Shaders/psxVertexShader.glsl",
        "Resources/Shaders/psxFractalShader.glsl"
    );

    ModelObject* object;

    object = CreateModelObject(
        shader,
        "Resources/Models/road/intersection.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(1.0f, 0.0f, 1.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(1.0f, 0.0f, 26.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(115.5f, 0.0f, 1.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(1.0f, 0.0f, -113.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(102.8f, 0.0f, 1.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(1.0f, 0.0f, 77.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(90.0f, 0.0f, 1.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(1.0f, 0.0f, -62.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(77.2f, 0.0f, 1.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(1.0f, 0.0f, 51.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(64.5f, 0.0f, 1.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(1.0f, 0.0f, -88.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(51.8f, 0.0f, 1.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(1.0f, 0.0f, 102.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(39.0f, 0.0f, 1.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(1.0f, 0.0f, -37.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(26.2f, 0.0f, 1.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(1.0f, 0.0f, 38.8f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-24.2f, 0.0f, 1.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(1.0f, 0.0f, -100.8f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-37.0f, 0.0f, 1.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(1.0f, 0.0f, 89.8f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-49.8f, 0.0f, 1.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(1.0f, 0.0f, -49.8f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-62.5f, 0.0f, 1.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(1.0f, 0.0f, 64.2f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-75.2f, 0.0f, 1.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(1.0f, 0.0f, -75.2f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-88.0f, 0.0f, 1.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(1.0f, 0.0f, 115.2f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-100.8f, 0.0f, 1.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(1.0f, 0.0f, -24.2f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-113.5f, 0.0f, 1.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/tree/tree.obj",
        "Resources/Models/tree/textures/pinetree.png",
        glm::vec3(-14.0f, 0.0f, -11.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/tree/tree.obj",
        "Resources/Models/tree/textures/pinetree.png",
        glm::vec3(-130.0f, 0.0f, -6.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/tree/tree.obj",
        "Resources/Models/tree/textures/pinetree.png",
        glm::vec3(129.0f, 0.0f, -6.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/tree/tree.obj",
        "Resources/Models/tree/textures/pinetree.png",
        glm::vec3(-14.0f, 0.0f, -94.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/tree/tree.obj",
        "Resources/Models/tree/textures/pinetree.png",
        glm::vec3(-10.0f, 0.0f, -76.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(270.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/tree/tree.obj",
        "Resources/Models/tree/textures/pinetree.png",
        glm::vec3(-27.0f, 0.0f, -14.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/tree/tree.obj",
        "Resources/Models/tree/textures/pinetree.png",
        glm::vec3(-116.0f, 0.0f, 11.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/tree/tree.obj",
        "Resources/Models/tree/textures/pinetree.png",
        glm::vec3(12.0f, 0.0f, 111.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/tree/tree.obj",
        "Resources/Models/tree/textures/pinetree.png",
        glm::vec3(17.0f, 0.0f, 117.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(45.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building9.obj",
        "",
        glm::vec3(18.0f, 0.0f, -11.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building9.obj",
        "",
        glm::vec3(-11.0f, 0.0f, 113.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building9.obj",
        "",
        glm::vec3(-102.5f, 0.0f, -11.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(-0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building8.obj",
        "",
        glm::vec3(13.5f, 0.0f, 14.8f),
        glm::vec3(glm::radians(0.0f), glm::radians(270.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building8.obj",
        "",
        glm::vec3(114.2f, 0.0f, 13.8f),
        glm::vec3(glm::radians(0.0f), glm::radians(180.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building8.obj",
        "",
        glm::vec3(-12.8f, 0.0f, -110.8f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building8.obj",
        "",
        glm::vec3(-11.5f, 0.0f, 67.2f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building8.obj",
        "",
        glm::vec3(-13.0f, 0.0f, -58.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(180.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building7.obj",
        "",
        glm::vec3(-76.2f, 0.0f, 15.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(180.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building7.obj",
        "",
        glm::vec3(32.0f, 0.0f, 15.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(180.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building6.obj",
        "",
        glm::vec3(-48.0f, 0.0f, -13.8f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building6.obj",
        "",
        glm::vec3(90.2f, 0.0f, 15.8f),
        glm::vec3(glm::radians(0.0f), glm::radians(180.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building5.obj",
        "",
        glm::vec3(-79.2f, 0.0f, -14.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building5.obj",
        "",
        glm::vec3(-14.0f, 0.0f, 89.8f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building5.obj",
        "",
        glm::vec3(59.0f, 0.0f, 16.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(180.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building5.obj",
        "",
        glm::vec3(16.0f, 0.0f, -100.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(270.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building4.obj",
        "",
        glm::vec3(15.8f, 0.0f, -32.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(270.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building4.obj",
        "",
        glm::vec3(-13.8f, 0.0f, 47.2f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building4.obj",
        "",
        glm::vec3(102.0f, 0.0f, -13.8f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building3.obj",
        "",
        glm::vec3(38.0f, 0.0f, -13.2f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building3.obj",
        "",
        glm::vec3(15.2f, 0.0f, 95.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(270.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building3.obj",
        "",
        glm::vec3(-100.2f, 0.0f, 15.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(180.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building2.obj",
        "",
        glm::vec3(-44.0f, 0.0f, 17.8f),
        glm::vec3(glm::radians(0.0f), glm::radians(180.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building2.obj",
        "",
        glm::vec3(-31.2f, 0.0f, -84.8f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building2.obj",
        "",
        glm::vec3(69.8f, 0.0f, -16.2f),
        glm::vec3(glm::radians(0.0f), glm::radians(-0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building2.obj",
        "",
        glm::vec3(18.0f, 0.0f, -65.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(270.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building1.obj",
        "",
        glm::vec3(-14.5f, 0.0f, -35.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building1.obj",
        "",
        glm::vec3(16.5f, 0.0f, 39.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(270.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building0.obj",
        "",
        glm::vec3(-13.0f, 0.0f, 21.8f),
        glm::vec3(glm::radians(0.0f), glm::radians(89.9f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building0.obj",
        "",
        glm::vec3(15.0f, 0.0f, 69.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(269.9f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/intersection.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(1.0f, 0.0f, 242.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/intersection.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-240.5f, 0.0f, 1.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-240.5f, 0.0f, 26.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-126.0f, 0.0f, 1.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-240.5f, 0.0f, -113.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-138.8f, 0.0f, 1.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-240.5f, 0.0f, 77.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-151.5f, 0.0f, 1.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-240.5f, 0.0f, -62.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-164.2f, 0.0f, 1.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-240.5f, 0.0f, 51.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-177.0f, 0.0f, 1.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-240.5f, 0.0f, -88.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-189.8f, 0.0f, 1.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-240.5f, 0.0f, 102.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-202.5f, 0.0f, 1.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-240.5f, 0.0f, -37.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-215.2f, 0.0f, 1.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-240.5f, 0.0f, 38.8f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-265.8f, 0.0f, 1.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-240.5f, 0.0f, -100.8f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-278.5f, 0.0f, 1.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-240.5f, 0.0f, 89.8f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-291.2f, 0.0f, 1.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-240.5f, 0.0f, -49.8f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-304.0f, 0.0f, 1.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-240.5f, 0.0f, 64.2f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-316.8f, 0.0f, 1.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-240.5f, 0.0f, -75.2f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-329.5f, 0.0f, 1.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-240.5f, 0.0f, 115.2f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-342.2f, 0.0f, 1.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-240.5f, 0.0f, -24.2f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-355.0f, 0.0f, 1.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/tree/tree.obj",
        "Resources/Models/tree/textures/pinetree.png",
        glm::vec3(-255.5f, 0.0f, -11.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/tree/tree.obj",
        "Resources/Models/tree/textures/pinetree.png",
        glm::vec3(-371.5f, 0.0f, -6.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/tree/tree.obj",
        "Resources/Models/tree/textures/pinetree.png",
        glm::vec3(-112.5f, 0.0f, -6.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/tree/tree.obj",
        "Resources/Models/tree/textures/pinetree.png",
        glm::vec3(-255.5f, 0.0f, -94.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/tree/tree.obj",
        "Resources/Models/tree/textures/pinetree.png",
        glm::vec3(-251.5f, 0.0f, -76.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(270.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/tree/tree.obj",
        "Resources/Models/tree/textures/pinetree.png",
        glm::vec3(-268.5f, 0.0f, -14.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/tree/tree.obj",
        "Resources/Models/tree/textures/pinetree.png",
        glm::vec3(-357.5f, 0.0f, 11.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/tree/tree.obj",
        "Resources/Models/tree/textures/pinetree.png",
        glm::vec3(-229.5f, 0.0f, 111.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/tree/tree.obj",
        "Resources/Models/tree/textures/pinetree.png",
        glm::vec3(-224.5f, 0.0f, 117.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(45.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building9.obj",
        "",
        glm::vec3(-223.5f, 0.0f, -11.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building9.obj",
        "",
        glm::vec3(-252.5f, 0.0f, 113.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building9.obj",
        "",
        glm::vec3(-344.0f, 0.0f, -11.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(-0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building8.obj",
        "",
        glm::vec3(-228.0f, 0.0f, 14.8f),
        glm::vec3(glm::radians(0.0f), glm::radians(270.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building8.obj",
        "",
        glm::vec3(-127.2f, 0.0f, 13.8f),
        glm::vec3(glm::radians(0.0f), glm::radians(180.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building8.obj",
        "",
        glm::vec3(-254.2f, 0.0f, -110.8f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building8.obj",
        "",
        glm::vec3(-253.0f, 0.0f, 67.2f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building8.obj",
        "",
        glm::vec3(-254.5f, 0.0f, -58.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(180.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building7.obj",
        "",
        glm::vec3(-317.8f, 0.0f, 15.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(180.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building7.obj",
        "",
        glm::vec3(-209.5f, 0.0f, 15.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(180.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building6.obj",
        "",
        glm::vec3(-289.5f, 0.0f, -13.8f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building6.obj",
        "",
        glm::vec3(-151.2f, 0.0f, 15.8f),
        glm::vec3(glm::radians(0.0f), glm::radians(180.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building5.obj",
        "",
        glm::vec3(-320.8f, 0.0f, -14.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building5.obj",
        "",
        glm::vec3(-255.5f, 0.0f, 89.8f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building5.obj",
        "",
        glm::vec3(-182.5f, 0.0f, 16.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(180.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building5.obj",
        "",
        glm::vec3(-225.5f, 0.0f, -100.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(270.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building4.obj",
        "",
        glm::vec3(-225.8f, 0.0f, -32.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(270.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building4.obj",
        "",
        glm::vec3(-255.2f, 0.0f, 47.2f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building4.obj",
        "",
        glm::vec3(-139.5f, 0.0f, -13.8f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building3.obj",
        "",
        glm::vec3(-203.5f, 0.0f, -13.2f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building3.obj",
        "",
        glm::vec3(-226.2f, 0.0f, 95.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(270.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building3.obj",
        "",
        glm::vec3(-341.8f, 0.0f, 15.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(180.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building2.obj",
        "",
        glm::vec3(-285.5f, 0.0f, 17.8f),
        glm::vec3(glm::radians(0.0f), glm::radians(180.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building2.obj",
        "",
        glm::vec3(-272.8f, 0.0f, -84.8f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building2.obj",
        "",
        glm::vec3(-171.8f, 0.0f, -16.2f),
        glm::vec3(glm::radians(0.0f), glm::radians(-0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building2.obj",
        "",
        glm::vec3(-223.5f, 0.0f, -65.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(270.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building1.obj",
        "",
        glm::vec3(-256.0f, 0.0f, -35.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building1.obj",
        "",
        glm::vec3(-225.0f, 0.0f, 39.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(270.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building0.obj",
        "",
        glm::vec3(-254.5f, 0.0f, 21.8f),
        glm::vec3(glm::radians(0.0f), glm::radians(89.9f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building0.obj",
        "",
        glm::vec3(-226.5f, 0.0f, 69.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(269.9f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(1.0f, 0.0f, 267.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(115.5f, 0.0f, 242.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(1.0f, 0.0f, 128.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(102.8f, 0.0f, 242.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(1.0f, 0.0f, 318.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(90.0f, 0.0f, 242.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(1.0f, 0.0f, 179.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(77.2f, 0.0f, 242.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(1.0f, 0.0f, 293.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(64.5f, 0.0f, 242.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(1.0f, 0.0f, 153.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(51.8f, 0.0f, 242.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(1.0f, 0.0f, 344.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(39.0f, 0.0f, 242.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(1.0f, 0.0f, 204.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(26.2f, 0.0f, 242.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(1.0f, 0.0f, 280.2f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-24.2f, 0.0f, 242.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(1.0f, 0.0f, 140.8f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-37.0f, 0.0f, 242.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(1.0f, 0.0f, 331.2f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-49.8f, 0.0f, 242.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(1.0f, 0.0f, 191.8f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-62.5f, 0.0f, 242.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(1.0f, 0.0f, 305.8f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-75.2f, 0.0f, 242.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(1.0f, 0.0f, 166.2f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-88.0f, 0.0f, 242.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(1.0f, 0.0f, 356.8f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-100.8f, 0.0f, 242.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(1.0f, 0.0f, 217.2f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-113.5f, 0.0f, 242.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/tree/tree.obj",
        "Resources/Models/tree/textures/pinetree.png",
        glm::vec3(-14.0f, 0.0f, 230.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/tree/tree.obj",
        "Resources/Models/tree/textures/pinetree.png",
        glm::vec3(-130.0f, 0.0f, 235.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/tree/tree.obj",
        "Resources/Models/tree/textures/pinetree.png",
        glm::vec3(129.0f, 0.0f, 235.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/tree/tree.obj",
        "Resources/Models/tree/textures/pinetree.png",
        glm::vec3(-14.0f, 0.0f, 147.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/tree/tree.obj",
        "Resources/Models/tree/textures/pinetree.png",
        glm::vec3(-10.0f, 0.0f, 165.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(270.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/tree/tree.obj",
        "Resources/Models/tree/textures/pinetree.png",
        glm::vec3(-27.0f, 0.0f, 227.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/tree/tree.obj",
        "Resources/Models/tree/textures/pinetree.png",
        glm::vec3(-116.0f, 0.0f, 252.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/tree/tree.obj",
        "Resources/Models/tree/textures/pinetree.png",
        glm::vec3(12.0f, 0.0f, 352.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/tree/tree.obj",
        "Resources/Models/tree/textures/pinetree.png",
        glm::vec3(17.0f, 0.0f, 358.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(45.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building9.obj",
        "",
        glm::vec3(18.0f, 0.0f, 230.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building9.obj",
        "",
        glm::vec3(-11.0f, 0.0f, 354.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building9.obj",
        "",
        glm::vec3(-102.5f, 0.0f, 230.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(-0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building8.obj",
        "",
        glm::vec3(13.5f, 0.0f, 256.2f),
        glm::vec3(glm::radians(0.0f), glm::radians(270.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building8.obj",
        "",
        glm::vec3(114.2f, 0.0f, 255.2f),
        glm::vec3(glm::radians(0.0f), glm::radians(180.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building8.obj",
        "",
        glm::vec3(-12.8f, 0.0f, 130.8f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building8.obj",
        "",
        glm::vec3(-11.5f, 0.0f, 308.8f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building8.obj",
        "",
        glm::vec3(-13.0f, 0.0f, 183.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(180.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building7.obj",
        "",
        glm::vec3(-76.2f, 0.0f, 256.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(180.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building7.obj",
        "",
        glm::vec3(32.0f, 0.0f, 256.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(180.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building6.obj",
        "",
        glm::vec3(-48.0f, 0.0f, 227.8f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building6.obj",
        "",
        glm::vec3(90.2f, 0.0f, 257.2f),
        glm::vec3(glm::radians(0.0f), glm::radians(180.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building5.obj",
        "",
        glm::vec3(-79.2f, 0.0f, 227.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building5.obj",
        "",
        glm::vec3(-14.0f, 0.0f, 331.2f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building5.obj",
        "",
        glm::vec3(59.0f, 0.0f, 257.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(180.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building5.obj",
        "",
        glm::vec3(16.0f, 0.0f, 141.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(270.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building4.obj",
        "",
        glm::vec3(15.8f, 0.0f, 209.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(270.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building4.obj",
        "",
        glm::vec3(-13.8f, 0.0f, 288.8f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building4.obj",
        "",
        glm::vec3(102.0f, 0.0f, 227.8f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building3.obj",
        "",
        glm::vec3(38.0f, 0.0f, 228.2f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building3.obj",
        "",
        glm::vec3(15.2f, 0.0f, 336.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(270.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building3.obj",
        "",
        glm::vec3(-100.2f, 0.0f, 257.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(180.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building2.obj",
        "",
        glm::vec3(-44.0f, 0.0f, 259.2f),
        glm::vec3(glm::radians(0.0f), glm::radians(180.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building2.obj",
        "",
        glm::vec3(-31.2f, 0.0f, 156.8f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building2.obj",
        "",
        glm::vec3(69.8f, 0.0f, 225.2f),
        glm::vec3(glm::radians(0.0f), glm::radians(-0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building2.obj",
        "",
        glm::vec3(18.0f, 0.0f, 176.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(270.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building1.obj",
        "",
        glm::vec3(-14.5f, 0.0f, 206.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building1.obj",
        "",
        glm::vec3(16.5f, 0.0f, 280.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(270.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building0.obj",
        "",
        glm::vec3(-13.0f, 0.0f, 263.2f),
        glm::vec3(glm::radians(0.0f), glm::radians(89.9f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building0.obj",
        "",
        glm::vec3(15.0f, 0.0f, 310.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(269.9f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/intersection.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-240.5f, 0.0f, 242.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-240.5f, 0.0f, 267.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-126.0f, 0.0f, 242.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-240.5f, 0.0f, 128.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-138.8f, 0.0f, 242.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-240.5f, 0.0f, 318.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-151.5f, 0.0f, 242.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-240.5f, 0.0f, 179.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-164.2f, 0.0f, 242.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-240.5f, 0.0f, 293.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-177.0f, 0.0f, 242.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-240.5f, 0.0f, 153.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-189.8f, 0.0f, 242.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-240.5f, 0.0f, 344.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-202.5f, 0.0f, 242.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-240.5f, 0.0f, 204.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-215.2f, 0.0f, 242.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-240.5f, 0.0f, 280.2f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-265.8f, 0.0f, 242.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-240.5f, 0.0f, 140.8f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-278.5f, 0.0f, 242.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-240.5f, 0.0f, 331.2f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-291.2f, 0.0f, 242.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-240.5f, 0.0f, 191.8f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-304.0f, 0.0f, 242.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-240.5f, 0.0f, 305.8f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-316.8f, 0.0f, 242.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-240.5f, 0.0f, 166.2f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-329.5f, 0.0f, 242.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-240.5f, 0.0f, 356.8f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-342.2f, 0.0f, 242.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-240.5f, 0.0f, 217.2f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/road/road.obj",
        "Resources/Models/road/textures/imgonline-com-ua-pixelizationqJrcMp70EhTY.jpeg",
        glm::vec3(-355.0f, 0.0f, 242.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(2.0f, 2.0f, 2.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/tree/tree.obj",
        "Resources/Models/tree/textures/pinetree.png",
        glm::vec3(-255.5f, 0.0f, 230.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/tree/tree.obj",
        "Resources/Models/tree/textures/pinetree.png",
        glm::vec3(-371.5f, 0.0f, 235.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/tree/tree.obj",
        "Resources/Models/tree/textures/pinetree.png",
        glm::vec3(-112.5f, 0.0f, 235.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/tree/tree.obj",
        "Resources/Models/tree/textures/pinetree.png",
        glm::vec3(-255.5f, 0.0f, 147.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/tree/tree.obj",
        "Resources/Models/tree/textures/pinetree.png",
        glm::vec3(-251.5f, 0.0f, 165.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(270.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/tree/tree.obj",
        "Resources/Models/tree/textures/pinetree.png",
        glm::vec3(-268.5f, 0.0f, 227.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/tree/tree.obj",
        "Resources/Models/tree/textures/pinetree.png",
        glm::vec3(-357.5f, 0.0f, 252.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/tree/tree.obj",
        "Resources/Models/tree/textures/pinetree.png",
        glm::vec3(-229.5f, 0.0f, 352.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/tree/tree.obj",
        "Resources/Models/tree/textures/pinetree.png",
        glm::vec3(-224.5f, 0.0f, 358.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(45.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building9.obj",
        "",
        glm::vec3(-223.5f, 0.0f, 230.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building9.obj",
        "",
        glm::vec3(-252.5f, 0.0f, 354.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building9.obj",
        "",
        glm::vec3(-344.0f, 0.0f, 230.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(-0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building8.obj",
        "",
        glm::vec3(-228.0f, 0.0f, 256.2f),
        glm::vec3(glm::radians(0.0f), glm::radians(270.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building8.obj",
        "",
        glm::vec3(-127.2f, 0.0f, 255.2f),
        glm::vec3(glm::radians(0.0f), glm::radians(180.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building8.obj",
        "",
        glm::vec3(-254.2f, 0.0f, 130.8f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building8.obj",
        "",
        glm::vec3(-253.0f, 0.0f, 308.8f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building8.obj",
        "",
        glm::vec3(-254.5f, 0.0f, 183.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(180.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building7.obj",
        "",
        glm::vec3(-317.8f, 0.0f, 256.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(180.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building7.obj",
        "",
        glm::vec3(-209.5f, 0.0f, 256.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(180.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building6.obj",
        "",
        glm::vec3(-289.5f, 0.0f, 227.8f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building6.obj",
        "",
        glm::vec3(-151.2f, 0.0f, 257.2f),
        glm::vec3(glm::radians(0.0f), glm::radians(180.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building5.obj",
        "",
        glm::vec3(-320.8f, 0.0f, 227.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building5.obj",
        "",
        glm::vec3(-255.5f, 0.0f, 331.2f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building5.obj",
        "",
        glm::vec3(-182.5f, 0.0f, 257.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(180.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building5.obj",
        "",
        glm::vec3(-225.5f, 0.0f, 141.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(270.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building4.obj",
        "",
        glm::vec3(-225.8f, 0.0f, 209.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(270.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building4.obj",
        "",
        glm::vec3(-255.2f, 0.0f, 288.8f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building4.obj",
        "",
        glm::vec3(-139.5f, 0.0f, 227.8f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building3.obj",
        "",
        glm::vec3(-203.5f, 0.0f, 228.2f),
        glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building3.obj",
        "",
        glm::vec3(-226.2f, 0.0f, 336.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(270.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building3.obj",
        "",
        glm::vec3(-341.8f, 0.0f, 257.0f),
        glm::vec3(glm::radians(0.0f), glm::radians(180.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building2.obj",
        "",
        glm::vec3(-285.5f, 0.0f, 259.2f),
        glm::vec3(glm::radians(0.0f), glm::radians(180.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building2.obj",
        "",
        glm::vec3(-272.8f, 0.0f, 156.8f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building2.obj",
        "",
        glm::vec3(-171.8f, 0.0f, 225.2f),
        glm::vec3(glm::radians(0.0f), glm::radians(-0.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building2.obj",
        "",
        glm::vec3(-223.5f, 0.0f, 176.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(270.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building1.obj",
        "",
        glm::vec3(-256.0f, 0.0f, 206.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(90.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building1.obj",
        "",
        glm::vec3(-225.0f, 0.0f, 280.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(270.0f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building0.obj",
        "",
        glm::vec3(-254.5f, 0.0f, 263.2f),
        glm::vec3(glm::radians(0.0f), glm::radians(89.9f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);

    object = CreateModelObject(
        shader,
        "Resources/Models/buildings/building0.obj",
        "",
        glm::vec3(-226.5f, 0.0f, 310.5f),
        glm::vec3(glm::radians(0.0f), glm::radians(269.9f), glm::radians(0.0f)),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );
    objects.push_back(object);
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
    if (texturePath != "")
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
