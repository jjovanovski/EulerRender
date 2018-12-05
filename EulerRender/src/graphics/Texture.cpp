#include "Texture.h"


#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
#endif

#include <iostream>

using namespace Euler;

Texture::Texture(const char * textureFile) {
	int width, height, channels;
	unsigned char* data = stbi_load(textureFile, &width, &height, &channels, 0);

	id = 0;
	if (data) {
		glGenTextures(1, &id);
		glBindTexture(GL_TEXTURE_2D, id);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	stbi_image_free(data);
}

Texture::~Texture() {
	Dispose();
}

void Texture::Bind() {
	glBindTexture(GL_TEXTURE_2D, id);
}

void Texture::Dispose() {
	glDeleteTextures(1, &id);
	id = 0;
}