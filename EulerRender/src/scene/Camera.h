#pragma once

#include "../API.h"

#include "../math/Mat4.h"
#include "../math/Transformation.h"

#include "Component.h"

namespace Euler {

	class EULER_API Camera : public Component {
	public:
		Camera();
		~Camera();

		Mat4 GetViewMatrix();
	};

}
