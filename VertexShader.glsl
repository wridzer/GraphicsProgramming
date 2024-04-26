#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 vColor;
layout (location = 2) in vec2 vUV;
layout (location = 3) in vec3 vNormal;
layout (location = 4) in vec3 vTangent;
layout (location = 5) in vec3 vBitangent;

out vec3 color;
out vec2 uv;
out mat3 TBN;
out vec3 pixelCoord;

uniform mat4 world;
uniform mat4 view;
uniform mat4 projection;


void main()
{
   gl_Position = projection * view * world * vec4(aPos, 1.0);
   color = vColor;
   uv = vUV;
   vec3 n = mat3(world) * vNormal;
   vec3 t = normalize(mat3(world) * vTangent); 
   vec3 b = normalize(mat3(world) * vBitangent); 
   TBN = mat3(t, b, n);
   pixelCoord = mat3(world) * aPos;
}