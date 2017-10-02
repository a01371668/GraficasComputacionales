/*
*	Autor: Alonso Issac Morales Gutiérrez
*	Matrícula: A01371668
*	Gráficas Computacionales
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