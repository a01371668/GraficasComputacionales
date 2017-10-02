/*
*	Autor: Alonso Issac Morales Guti�rrez
*	Matr�cula: A01371668
*	Gr�ficas Computacionales
*	Prof. Oriam De Gyves
*	Shader.h
*/

#pragma once
using namespace std;
using namespace glm;
#include <string>

class Shader
{
private:
	GLuint _shaderHandle;

public:
	Shader();
	~Shader();
	void CreateShader(string path, GLenum type);
	GLuint GetHandle();
};