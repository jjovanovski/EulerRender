#pragma once

#include "../API.h"
#include "../math/Vec3.h"

namespace Euler {

	class EULER_API Material {
	public:
		Vec3 ambient, diffuse, specular;
		float shininess;

		Material(Vec3 ambient = Vec3(1.0f, 1.0f, 1.0f), Vec3 diffuse = Vec3(1.0f, 1.0f, 1.0f), Vec3 specular = Vec3(1.0f, 1.0f, 1.0), float shininess = 128.0f);
		~Material();
	};

}
