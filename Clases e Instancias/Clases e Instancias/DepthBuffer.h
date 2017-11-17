#pragma once

#include <GL/glew.h>

class DepthBuffer {
public:
	DepthBuffer();
	~DepthBuffer();

	void Create(int resolution);

	void Bind();
	void Unbind();
	void BindDepthMap();
	void UnbindDepthMap();

private:
	GLuint _framebuffer;
	GLuint _depthmap;
	GLsizei _resolution;

};