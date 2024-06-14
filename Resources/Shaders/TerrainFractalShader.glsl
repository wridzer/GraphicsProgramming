#version 330 core
out vec4 FragColor; 

in vec2 uv;
in vec4 pixelCoord;
 
uniform sampler2D mainTex;
uniform sampler2D normalTex;
uniform sampler2D dirt, grass, rock, snow, sand;

uniform vec3 lightDirection;
uniform vec3 cameraPosition;

vec3 lerp(vec3 a, vec3 b, float t)
{
	return a + (b - a) * t;
}

void main()
{
    // Normalmap
    vec3 normal = texture(normalTex, uv).rgb;
    normal = normalize(normal * 2.0 - 1.0);
    normal.gb = normal.bg;
    normal.r = -normal.r;
    normal.b = -normal.b;

    // Light
    float lightValue = max(-dot(normal, lightDirection), 0.0f);

    // Specular data
    vec3 viewDir = normalize(pixelCoord.rgb - cameraPosition);
    vec3 reflectedLight = normalize(-reflect(-lightDirection, normal));
    float specValue = pow(max(dot(reflectedLight, viewDir), 0.01), 2048);
    
    // Build color -> sand, grass, dirt, rock, snow
    float height = pixelCoord.y;
    float dist = length(pixelCoord.rgb - cameraPosition);
    float uvLerp = clamp((dist - 250) / 150, -1.0, 1.0) * 0.5 + 0.5;

    float gs = clamp((height - 50) / 10, -1.0, 1.0) * 0.5 + 0.5;
    float sd = clamp((height - 100) / 10, -1.0, 1.0) * 0.5 + 0.5;
    float dr = clamp((height - 150) / 10, -1.0, 1.0) * 0.5 + 0.5;
    float rd = clamp((height - 200) / 10, -1.0, 1.0) * 0.5 + 0.5;

    vec3 sandColorClose = texture(sand, uv * 100).rgb;
    vec3 grassColorClose = texture(grass, uv * 100).rgb;
    vec3 dirtColorClose = texture(dirt, uv * 100).rgb;
    vec3 rockColorClose = texture(rock, uv * 100).rgb;
    vec3 snowColorClose = texture(snow, uv * 100).rgb;

    vec3 sandColorFar = texture(sand, uv * 10).rgb;
    vec3 grassColorFar = texture(grass, uv * 10).rgb;
    vec3 dirtColorFar = texture(dirt, uv * 10).rgb;
    vec3 rockColorFar = texture(rock, uv * 10).rgb;
    vec3 snowColorFar = texture(snow, uv * 10).rgb;

    vec3 dirtColor = lerp(dirtColorClose, dirtColorFar, uvLerp);
    vec3 grassColor = lerp(grassColorClose, grassColorFar, uvLerp);
    vec3 rockColor = lerp(rockColorClose, rockColorFar, uvLerp);
    vec3 snowColor = lerp(snowColorClose, snowColorFar, uvLerp);
    vec3 sandColor = lerp(sandColorClose, sandColorFar, uvLerp);

    vec3 diffuse = lerp(lerp(lerp(lerp(grassColor, sandColor, gs), dirtColor, sd), rockColor, dr), snowColor, rd);

    // Fog
    float fog = pow( clamp((dist - 250) / 1000, 0.0, 1.0), 2);

    vec3 topColor = vec3(68.0 / 255.0, 108.0 / 255.0, 179.0 / 255.0);
    vec3 botColor = vec3(188.0 / 255.0, 214.0 / 255.0, 231.0 / 255.0);
    vec3 fogColor = lerp(botColor, topColor, max(viewDir.y, 0.0f));

    // Seperate RGB and RGBA
    vec4 outputColor = vec4( lerp( diffuse * min(lightValue + 0.1, 1.0), fogColor, fog), 1.0);// + specValue * color.rgb;
    //outputColor.rgb = outputColor.rgb + specValue * outputColor.rgb;

    FragColor = outputColor;
}