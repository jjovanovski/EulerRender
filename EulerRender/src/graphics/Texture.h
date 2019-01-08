#pragma once

#include "../API.h"
#include "../resources/Disposable.h"

#include <glad/glad.h>

namespace Euler {

	class EULER_API Texture : public Disposable {
	private:
		unsigned int id;

	public:
		Texture(const char * textureFile);
		~Texture();

		void Bind();
		void Dispose();
	};

}
