#pragma once

#include "../API.h"

#include <cmath>
#include "Mat4.h"

namespace Euler {

	class EULER_API Transformation {
	public:
		Transformation();
		~Transformation();

		static Mat4 Identity();
		static Mat4 Translate(float x, float y, float z);
		static Mat4 Scale(float x, float y, float z);
		static Mat4 Rotate(float angle, float x, float y, float z);

		static Mat4 Perspective(float near = 0.1f, float far = 100.0f, float fieldOfView = 60.0f);
	};

}
