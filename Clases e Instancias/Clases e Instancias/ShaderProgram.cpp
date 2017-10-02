/*
*	Autor: Alonso Issac Morales Gutiérrez
*	Matrícula: A01371668
*	Gráficas Computacionales
*	Prof. Oriam De Gyves
*	ShaderProgram.cpp
*/

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include "Shader.h"
#include "ShaderProgram.h"
#include <vector>
#include <memory>

ShaderProgram::ShaderProgram()
{
	_programHandle = 0;
}

ShaderProgram::~ShaderProgram()
{
	DeleteProgram();
}

void ShaderProgram::CreateProgram()
{
	_programHandle = glCreateProgram();
}

void ShaderProgram::AttachShader(string path, GLenum type)
{
	unique_ptr<Shader> shader(new Shader);
	shader->CreateShader(path, type);
	_attachedShaders.push_back(std::move(shader));
}

void ShaderProgram::LinkProgram()
{
	for (auto& i : _attachedShaders) {
		glAttachShader(_programHandle, i->GetHandle());
	}
	glLinkProgram(_programHandle);
	DeleteAndDetachShaders();
}

void ShaderProgram::Activate()
{
	glUseProgram(_programHandle);
}

void ShaderProgram::Deactivate()
{
	glUseProgram(0);
}

void ShaderProgram::SetAttribute(GLuint locationIndex, string name)
{
	glBindAttribLocation(_programHandle, locationIndex, name.c_str());
}

void ShaderProgram::SetUniformf(string name, float value)
{
	GLint resolutionUniformLocation = glGetUniformLocation(_programHandle, name.c_str());
	glUniform1f(resolutionUniformLocation, value);
}

void ShaderProgram::SetUniformf(string name, float x, float y)
{
	GLint resolutionUniformLocation = glGetUniformLocation(_programHandle, name.c_str());
	glUniform2f(resolutionUniformLocation, x, y);
}

void ShaderProgram::SetUniformf(string name, float x, float y, float z)
{
	GLint resolutionUniformLocation = glGetUniformLocation(_programHandle, name.c_str());
	glUniform3f(resolutionUniformLocation, x, y, z);
}

void ShaderProgram::SetUniformf(string name, float x, float y, float z, float w)
{
	GLint resolutionUniformLocation = glGetUniformLocation(_programHandle, name.c_str());
	glUniform4f(resolutionUniformLocation, x, y, z, w);
}

void ShaderProgram::DeleteAndDetachShaders()
{
	for (auto& i : _attachedShaders) {
		glDetachShader(_programHandle, i->GetHandle());
		glDeleteShader(i->GetHandle());
	}
}

void ShaderProgram::DeleteProgram()
{
	DeleteAndDetachShaders();
	glDeleteProgram(_programHandle);
}