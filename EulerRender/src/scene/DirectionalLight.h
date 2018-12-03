#pragma once

#include "../API.h"
#include "../math/Vec3.h"
#include "Component.h"

namespace Euler  {

	class EULER_API DirectionalLight : public Component {
	public:
		Vec3 direction, color;
		float intensity;

		DirectionalLight(Vec3 direction, Vec3 color, float intensity);
		~DirectionalLight();
	};

}
