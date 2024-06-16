#version 330 core
out vec4 FragColor; 

in vec3 color;
in vec2 uv;
in vec3 pixelCoord;
in mat3 TBN;
 
uniform sampler2D mainTex;
uniform sampler2D normalTex;
uniform vec3 lightPosition;
uniform vec3 cameraPosition;

uniform float borderScale;

void main()
{
    // Normalmap
    vec3 normal = texture(normalTex, uv).rgb;
    normal = normalize(normal * 2.0 - 1.0);
    normal = normal * TBN;

    // Light
    vec3 lightDir = normalize(lightPosition - pixelCoord);
    float dotproduct = dot(normal, lightDir);
    float shadingAmount = step(borderScale, dotproduct);
    float lightValue = max(shadingAmount, 0.0f);

    // Specular data
    vec3 viewDir = normalize(pixelCoord - cameraPosition);
    vec3 reflectedLight = normalize(-reflect(-lightDir, normal));
    float specValue = pow(max(dot(reflectedLight, viewDir), 0.0), 16);
    
    // Seperate RGB and RGBA
    vec4 outputValue = vec4(color, 1.0f) * texture(mainTex, uv);
    outputValue.rgb = outputValue.rgb * min(lightValue + 0.1, 1.0) + specValue;

    FragColor = outputValue;
    //FragColor = vec4(color, 1.0f) * texture(mainTex, uv) * min(lightValue + 0.1, 1.0);

}