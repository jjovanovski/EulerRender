#pragma once

#include "../API.h"

#include <glad/glad.h>
#include "Shader.h"
#include "Mesh.h"
#include "../math/Mat4.h"
#include "../math/Transformation.h"

namespace Euler {

	class EULER_API Model {
	public:
		Mesh * mesh;
		float posx, posy, posz;
		float scalex, scaley, scalez;
		float rotx, roty, rotz;

		Model();
		~Model();

		Mat4 GetModelMatrix();
	};

}
