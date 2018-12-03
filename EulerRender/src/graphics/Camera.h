#pragma once

#include "../API.h"

#include "Model.h"
#include "Shader.h"
#include "Material.h"

#include "../math/Transformation.h"

namespace Euler {

	class EULER_API Camera {
	public:
		float x, y, z;
		float rotx, roty, rotz;

		Camera();
		~Camera();

		Mat4 GetViewMatrix();
		void Draw(Model * model, Shader * shader, Material * material);
	};

}
