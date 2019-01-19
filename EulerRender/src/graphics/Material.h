#pragma once

#include "../API.h"
#include "../math/Vec3.h"
#include "../graphics/Shader.h"
#include "../graphics/Texture.h"
#include "../resources/Disposable.h"

namespace Euler {

	class EULER_API Material : public Disposable {
	public:
		Shader * shader = nullptr;
		Texture * texture = nullptr;
		Texture * normalmap = nullptr;
		Vec3 ambient, diffuse, specular;
		float shininess;

		Material(Vec3 diffuse = Vec3(1.0f, 1.0f, 1.0f), Vec3 specular = Vec3(0, 0, 0), float shininess = 32);
		~Material();

		void Dispose();

		void SetupShader();
	};

}
