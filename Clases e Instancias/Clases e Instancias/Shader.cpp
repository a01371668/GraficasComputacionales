/*
*	Autor: Alonso Issac Morales Gutiérrez
*	Matrícula: A01371668
*	Gráficas Computacionales
*	Prof. Oriam De Gyves
*	Shader.cpp
*/

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include "Shader.h"
#include <vector>
#include "InputFile.h"
#include <string>

Shader::Shader()
{
	_shaderHandle = 0;
}

Shader::~Shader()
{
	glDeleteShader(_shaderHandle);
}

void Shader::CreateShader(string path, GLenum type)
{
	if (_shaderHandle != 0)  _shaderHandle = 0;
	InputFile ifile;
	ifile.Read(path);
	string vertexShaderSource = ifile.GetContents();
	const GLchar* vertexShaderSourceC = (const GLchar*)vertexShaderSource.c_str();
	_shaderHandle = glCreateShader(type);
	glShaderSource(_shaderHandle, 1, &vertexShaderSourceC, nullptr);
	glCompileShader(_shaderHandle);
}

GLuint Shader::GetHandle()
{
	return _shaderHandle;
}