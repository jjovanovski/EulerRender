#pragma once

#include "../API.h"

#include <glad/glad.h>

namespace Euler {

	class EULER_API Texture {
	private:
		unsigned int id;

	public:
		Texture(const char * textureFile);
		~Texture();

		void Bind();
		void Dispose();
	};

}
