#pragma once

#include "../../API.h"

#include <cmath>
#include "../Mesh.h"

namespace Euler {

	class EULER_API Sphere : public Mesh {
	public:
		Sphere(int rings, int sectors);
		~Sphere();
	};

}
