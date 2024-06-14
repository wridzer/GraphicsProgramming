#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormal;
layout(location = 2) in vec2 aTexCoords;

noperspective out vec2 TexCoords;
out vec3 Normals;
out vec4 DebugColor;

uniform mat4 world;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    mat4 MVP = projection * view * world;
    vec4 worldPos = world * vec4(aPos, 1.0);
    vec4 viewPos = view * worldPos;
    vec4 projPos = projection * viewPos;

    if(projPos.w < 0.0) {
		projPos.w *= -1.0;
	}

    // Perspective divide to get NDC
    vec3 ndc = projPos.xyz / projPos.w;

    // Convert to screen coordinates
    vec2 screenPos = (ndc.xy + vec2(1.0, 1.0)) * vec2(320.0, 240.0) * 0.5;

    // Apply half-pixel bias and truncate to simulate PSX precision
    vec2 truncatedScreenPos = floor(screenPos + vec2(0.5, 0.5));

    // Convert back to NDC range
    vec2 newNDC = truncatedScreenPos / vec2(320.0, 240.0) * 2.0 - vec2(1.0, 1.0);

    // Set final vertex position
    gl_Position = vec4(newNDC, ndc.z, 1.0);

    // Pass the texture coordinate to the fragment shader
    TexCoords = aTexCoords;
    // not the most efficient, but it works
    Normals = normalize(mat3(inverse(transpose(world))) * aNormal);
}