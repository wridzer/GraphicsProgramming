#version 330 core
layout (location = 0) in vec3 aPos;

out vec4 pixelCoord;

uniform mat4 world;
uniform mat4 view;
uniform mat4 projection;

void main()
{
   gl_Position = projection * view * world * vec4(aPos, 1.0);
   pixelCoord = world * vec4(aPos, 1.0);
}