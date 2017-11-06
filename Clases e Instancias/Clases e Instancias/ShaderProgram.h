/*
*	Autor: Alonso Issac Morales Guti�rrez
*	Matr�cula: A01371668
*	Gr�ficas Computacionales
*	Prof. Oriam De Gyves
*	ShaderProgram.h
*/

#pragma once  
#include <string>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <vector>
#include <memory>
#include <glm/glm.hpp>
#include "Shader.h"

class ShaderProgram {
public:
	//Constructores 
	ShaderProgram();
	~ShaderProgram();
	void CreateProgram();
	void AttachShader(std::string name, GLenum type);
	void LinkProgram();
	void Activate();
	void Deactivate();
	void SetAttribute(GLuint locationIndex, std::string name);
	void SetUniformi(std::string name, int value);
	void SetUniformf(std::string name, float value);
	void SetUniformf(std::string name, float x, float y);
	void SetUniformf(std::string name, float x, float y, float z);
	void SetUniformf(std::string name, float x, float y, float z, float w);
	void SetUniformMatrix(std::string name, glm::mat4 matrix);


private:		//variables
	GLuint _programHandle;
	std::vector<std::unique_ptr<Shader>> _attachedShaders;
	void DeleteAndDetachShaders();
	void DeleteProgram();
};