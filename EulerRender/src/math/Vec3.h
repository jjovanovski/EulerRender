#pragma once

#include "../API.h"

namespace Euler {

	class EULER_API Vec3 {
	public:
		float x, y, z;

		Vec3(float x = 0, float y = 0, float z = 0);
		~Vec3();
	};

}
