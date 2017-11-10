/*
*	Autor1: Francisco Geada	Rodriguez	A01168958
*	Autor2: Alonso Morales Gutiérrez	A01371668
*	Gráficas Computacionales
*	Prof. Oriam De Gyves
*/

#pragma once  
#include <string>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <vector>
#include <glm/glm.hpp>

class Shader {
public:
	Shader();
	~Shader();
	void CreateShader(std::string path, GLenum type);
	GLuint GetHandle();

private:
	GLuint _ShaderHandle = 0;
};