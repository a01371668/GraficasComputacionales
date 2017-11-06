#include <iostream>
#include "Texture2D.h"
#include <IL/il.h>

Texture2D::Texture2D() {
	ilInit();
	ilEnable(IL_ORIGIN_SET);
	ilOriginFunc(IL_ORIGIN_LOWER_LEFT);
	imageID;
}

Texture2D::~Texture2D() {

}

void Texture2D::LoadTexture(std::string path) {

	const char *path2 = path.c_str();
	ilGenImages(1, &imageID);
	ilBindImage(imageID);
	ilLoadImage(path2);

}

void Texture2D::Bind() {
	glGenTextures(1, &_textureId);
	glBindTexture(GL_TEXTURE_2D, _textureId);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, _textureId);
	glTexImage2D(GL_TEXTURE_2D, 0, ilGetInteger(IL_IMAGE_FORMAT), ilGetInteger(IL_IMAGE_WIDTH),
		ilGetInteger(IL_IMAGE_HEIGHT), 0, ilGetInteger(IL_IMAGE_FORMAT), ilGetInteger(IL_IMAGE_TYPE), ilGetData());
}

void Texture2D::Unbind() {
	ilBindImage(0);
	ilDeleteImages(1, &imageID);
	glBindTexture(GL_TEXTURE_2D, 0);
	glDeleteTextures(1, &_textureId);
}