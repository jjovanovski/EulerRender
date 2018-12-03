#pragma once

#include "../API.h"

#include "../math/Mat4.h"
#include "../math/Transformation.h"

namespace Euler {

	class EULER_API Camera {
	public:
		float x, y, z;
		float rotx, roty, rotz;

		Camera();
		~Camera();

		Mat4 GetViewMatrix();
	};

}
