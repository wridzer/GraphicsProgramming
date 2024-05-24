#version 330 core
out vec4 FragColor;

in vec2 TexCoords;
in vec3 Normals;
in vec4 FragPos;

uniform sampler2D texture_diffuse1;
uniform sampler2D texture_specular1;
uniform sampler2D texture_normal1;
uniform sampler2D texture_roughness1;
uniform sampler2D texture_ao1;

uniform vec3 cameraPosition;
uniform vec3 lightDirection;

float lerp(float a, float b, float t) {
    return a + (b - a) * t;
}

vec3 lerp(vec3 a, vec3 b, float t) {
    return a + (b - a) * t;
}

vec4 lerp(vec4 a, vec4 b, float t) {
    return a + (b - a) * t;
}

void main()
{
    vec4 diffuse = texture(texture_diffuse1, TexCoords);
    vec4 specTex = texture(texture_specular1, TexCoords);

    float light = max(dot(-lightDirection, Normals), 0.0);

    vec3 viewDir = normalize(FragPos.rgb - cameraPosition);
    vec3 refl = reflect(lightDirection, Normals);

    float ambientOcclusion = texture(texture_ao1, TexCoords).r;

    float roughness = texture(texture_roughness1, TexCoords).g;
    float spec = pow(max(dot(-viewDir, refl), 0.0), lerp(1, 128, roughness));
    vec3 specular = spec * specTex.bbb;

    // Fog
    float dist = length(FragPos.rgb - cameraPosition);
    float fog = pow(clamp((dist - 250) / 1000, 0.0, 1.0), 2);

    vec3 topColor = vec3(68.0 / 255.0, 108.0 / 255.0, 179.0 / 255.0);
    vec3 botColor = vec3(188.0 / 255.0, 214.0 / 255.0, 231.0 / 255.0);
    vec3 fogColor = lerp(botColor, topColor, max(viewDir.y, 0.0f));

    vec4 output = lerp(diffuse * max(light * ambientOcclusion, 0.2 * ambientOcclusion) + vec4(specular, 0), vec4(fogColor, 1.0), fog);

    FragColor = output;
}