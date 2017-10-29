/*
*	Autor: Alonso Issac Morales Gutiérrez
*	Matrícula: A01371668
*	Gráficas Computacionales
*	Prof. Oriam De Gyves
*	Mesh.cpp
*/

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include "Mesh.h"

Mesh::Mesh()
{
	_vertexArrayObject = 0;
	_positionsVertexBufferObject = 0;
	_colorsVertexBufferObject = 0;
	_vertexCount = 0;
	_indiceBufferObject = 0;
	_indiceContador = 0;
	_normalVertexBufferObject = 0;
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &_vertexArrayObject);
	glDeleteBuffers(1, &_colorsVertexBufferObject);
	glDeleteBuffers(1, &_positionsVertexBufferObject);
	glDeleteBuffers(1, &_normalVertexBufferObject);
}

void Mesh::CreateMesh(GLint vertexCount)
{
	_vertexCount = vertexCount;
	glGenVertexArrays(1, &_vertexArrayObject);
}

void Mesh::Draw(GLenum primitive)
{
	glBindVertexArray(_vertexArrayObject);
	if (_indiceContador > 0) {
		glDrawElements(primitive, _indiceContador, GL_UNSIGNED_INT, nullptr);
	}
	else {
		glDrawArrays(primitive, 0, _vertexCount); //Sin indices
	}
	glBindVertexArray(0);
}

 void Mesh::SetPositionAttribute(vector<vec2> positions, GLenum usage, GLuint locationIndex)
{
	if (!positions.empty() && positions.size() == _vertexCount)
	{
		SetAttributeData(_positionsVertexBufferObject, sizeof(vec2) * positions.size(), positions.data(), usage, locationIndex, 2);
	}
}

void Mesh::SetPositionAttribute(vector<vec3> positions, GLenum usage, GLuint locationIndex)
{
	if (!positions.empty() && positions.size() == _vertexCount)
	{
		SetAttributeData(_positionsVertexBufferObject, sizeof(vec3) * positions.size(), positions.data(), usage, locationIndex, 3);
	}
}

void Mesh::SetColorAttribute(vector<vec3> colors, GLenum usage, GLuint locationIndex)
{
	if (!colors.empty() && colors.size() == _vertexCount)
	{
		SetAttributeData(_colorsVertexBufferObject, sizeof(vec3) * colors.size(), colors.data(), usage, locationIndex, 3);
	}
}

void Mesh::SetColorAttribute(vector<vec4> colors, GLenum usage, GLuint locationIndex)
{
	if (!colors.empty() && colors.size() == _vertexCount)
	{
		SetAttributeData(_colorsVertexBufferObject, sizeof(vec4) * colors.size(), colors.data(), usage, locationIndex, 4);
	}
}

void Mesh::SetIndice(std::vector<unsigned int> indices, GLenum usage)
{
	_indiceContador = indices.size();
	if (_indiceBufferObject != 0) {
		_indiceBufferObject = 0;
	}
	glBindVertexArray(_vertexArrayObject);
	glGenBuffers(1, &_indiceBufferObject);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indiceBufferObject);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int)*_indiceContador, indices.data(), usage);
	glBindVertexArray(0);
}

void Mesh::SetNormalAttribute(std::vector<glm::vec3> normals, GLenum usage, GLuint locationIndex)
{
	if (normals.size() > 0 && normals.size() == _vertexCount) {
		SetAttributeData(_normalVertexBufferObject, sizeof(glm::vec3) * normals.size(), normals.data(), usage, locationIndex, 3);
	}
}

void Mesh::SetAttributeData(GLuint & buffer, const GLsizeiptr size, const void * data, GLenum usage, GLuint locationIndex, const GLint components)
{
	if (buffer != 0) glDeleteBuffers(1, &buffer);

	glBindVertexArray(_vertexArrayObject);
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, size, data, usage);
	glEnableVertexAttribArray(locationIndex);
	glVertexAttribPointer(locationIndex, components, GL_FLOAT, GL_FALSE, 0, nullptr);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}
