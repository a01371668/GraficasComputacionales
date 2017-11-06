/*
*	Autor: Alonso Issac Morales Guti�rrez
*	Matr�cula: A01371668
*	Gr�ficas Computacionales
*	Prof. Oriam De Gyves
*	Shader.h
*/

#pragma once

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <string>
#include "InputFile.h"

class Shader {
public:
	Shader();
	~Shader();
	void CreateShader(std::string path, GLenum type);
	GLuint GetHandle();

private:
	GLuint _shaderHandle;
};