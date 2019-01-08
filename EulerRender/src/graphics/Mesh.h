#pragma once

#include "../API.h"

#include <glad/glad.h>
#include <vector>

#include "Vertex.h"
#include "../resources/Disposable.h"

namespace Euler {

	class EULER_API Mesh : public Disposable {
	private:
		GLuint vao, vbo, ebo;

	public:
		std::vector<Vertex> vertices;
		std::vector<unsigned int> indices;

		Mesh();
		virtual ~Mesh();

		void Dispose();

		void Upload();
		void Bind();
	};

}

