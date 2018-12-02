#pragma once

#include "../API.h"

#include <glad/glad.h>
#include <vector>

#include "Vertex.h"

namespace Euler {

	class EULER_API Mesh {
	private:
		GLuint vao, vbo, ebo;

	public:
		std::vector<Vertex> vertices;
		std::vector<unsigned int> indices;

		Mesh();
		virtual ~Mesh();

		void Upload();
		void Bind();
		void Dispose();
	};

}

