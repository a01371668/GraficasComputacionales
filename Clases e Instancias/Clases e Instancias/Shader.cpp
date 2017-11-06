/*
*	Autor: Alonso Issac Morales Gutiérrez
*	Matrícula: A01371668
*	Gráficas Computacionales
*	Prof. Oriam De Gyves
*	Shader.cpp
*/

#include "Shader.h"

Shader::Shader() {
	_shaderHandle = 0;
}

Shader::~Shader() {
	glDeleteShader(_shaderHandle);
}

void Shader::CreateShader(std::string path, GLenum type) {
	InputFile ifile;
	if (!ifile.Read(path)) return;
	std::string source = ifile.GetContents();

	if (_shaderHandle)
		glDeleteShader(_shaderHandle);

	_shaderHandle = glCreateShader(type);

	const GLchar *source_c = (const GLchar*)source.c_str();
	glShaderSource(_shaderHandle, 1, &source_c, nullptr);

	glCompileShader(_shaderHandle);

}

GLuint Shader::GetHandle() {
	return _shaderHandle;
}