#pragma once

#include "../../API.h"

#include "../Mesh.h"

namespace Euler {

	class EULER_API Plane : public Mesh {
	public:
		Plane(int subplanes = 4);
		~Plane();
	};

}
