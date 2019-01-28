#pragma once

#include "../API.h"

#include "../math/Mat4.h"
#include "../math/Transformation.h"

#include "Component.h"

namespace Euler {

	class EULER_API Camera : public Component {
	public:
		float nearPlane = 0.1f;
		float farPlane = 100.0f;
		float fieldOfView = 60.0f;

		Camera();
		~Camera();

		Mat4 GetViewMatrix();
	};

}
