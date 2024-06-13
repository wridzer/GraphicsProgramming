#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormal;
layout(location = 2) in vec2 aTexCoords;

noperspective out vec2 TexCoords;
out vec3 Normals;

uniform mat4 world;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    // Transform vertex by the model, view, and projection matrices
    vec4 pos = projection * view * world * vec4(aPos, 1.0f);

    // Divide by W to get Normalized Device Coordinates
    pos.xyz /= pos.w;

    // Convert to screen coordinates, add half-pixel bias, and truncate
    pos.xy = floor((pos.xy + vec2(1.0f, 1.0f)) * vec2(320.0f, 240.0f) * 0.5f + vec2(0.5f, 0.5f));

    // Convert back to -1.0 to 1.0 range
    pos.xy = pos.xy / vec2(320.0f, 240.0f) / 0.5f - vec2(1.0f, 1.0f);

    // Output the final vertex position
    gl_Position = vec4(pos.xyz, 1.0f);

    // Pass the texture coordinate to the fragment shader
    TexCoords = aTexCoords;
    // not the most efficient, but it works
    Normals = normalize(mat3(inverse(transpose(world))) * aNormal);
}