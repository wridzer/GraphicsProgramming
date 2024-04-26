#version 330 core
out vec4 FragColor; 

in vec3 color;
in vec2 uv;
in vec3 pixelCoord;
in mat3 TBN;
 
uniform sampler2D mainTex;
uniform sampler2D normalTex;
uniform vec3 lightPosition;

void main()
{
    // Normalmap
    vec3 normal = (texture(normalTex, uv).rgb * 2.0 - 1.0) * TBN;

    // Light
    vec3 lightDir = normalize(lightPosition - pixelCoord);
    float lightValue = max(dot(normal, lightDir), 0.0f);

    FragColor = vec4(color, 1.0f) * texture(mainTex, uv) * min(lightValue + 0.1, 1.0);
}