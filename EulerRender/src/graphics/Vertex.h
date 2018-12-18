#pragma once

#include "../API.h"

#include "../math/Vec3.h"
#include "../math/Vec2.h"

namespace Euler {

	class EULER_API Vertex {
	public:
		Vec3 position;
		Vec3 normal;
		Vec2 uv;
		Vec3 tangent;

		Vertex(float x = 0, float y = 0, float z = 0, float nx = 0, float ny = 0, float nz = 0, float u = 0, float v = 0, float tx = 0, float ty = 0, float tz = 0);
		~Vertex();
	};

}
