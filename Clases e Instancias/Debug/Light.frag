#version 330

in vec3 InterpolatedColor;
in vec3 IterpolatedVertexNormal;
in vec3 PixelPosition;
in vec2 IterpolatedTextCoord:

out vec4 FragColor;

uniform vec3 LightColor;
uniform vec3 LightPosition;
uniform vec3 CamaraPosition;
uniform mat4 modelMatrix;
uniform sampler2D DiffuseTexture;
uniform sampler2D DiffuseTexture2;

 void main() {
	vec3 ambient = 1.0f * normalize(LightColor);
	vec3 L = normalize(LightPosition - PixelPosition);
	mat3 NormalMatrix = transpose(inverse(mat3(modelMatrix)));
	vec3 IterpolatedNormal = normalize(NormalMatrix * IterpolatedVertexNormal);
	vec3 diffuse = dot(normalize(IterpolatedNormal), L) * normalize(LightColor);
	vec3 R = normalize(reflect(-L, IterpolatedNormal));
	vec3 V = normalize(CamaraPosition - PixelPosition);
	vec3 specular = 0.5f * pow(dot(V, R), 32) * normalize(LightColor);
	vec4 texA = texture2D(DiffuseTexture, IterpolatedTextCoor);
	vec4 texB = texture2D(DiffuseTexture2, IterpolatedTextCoor);
	vec4 mix1 = mix(texA, texB, 0.5f);

	FragColor = vec4((ambient + diffuse + specular) * mix1, 1.0f);
 }