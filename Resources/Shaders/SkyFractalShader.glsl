#version 330 core
out vec4 FragColor; 

in vec4 pixelCoord;
 
uniform vec3 lightDirection;
uniform vec3 cameraPosition;

vec3 lerp(vec3 a, vec3 b, float t)
{
	return a  + (b - a) * t;
}

void main()
{
    vec3 topColor = vec3(68.0 / 255.0, 108.0 / 255.0, 179.0 / 255.0);
    vec3 botColor = vec3(188.0 / 255.0, 214.0 / 255.0, 231.0 / 255.0);

    // Sun
    vec3 sunColor = vec3(1.0, 1.0, 0.8);
    vec3 viewDir = normalize(pixelCoord.rgb - cameraPosition);
    float sun = max(pow(dot(-viewDir, lightDirection), 128), 0.0);


    FragColor = vec4(lerp(botColor, topColor, max(viewDir.y, 0.0f)) + sun * sunColor, 1) ;
}