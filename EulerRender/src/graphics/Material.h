#pragma once

#include "../API.h"
#include "../math/Vec2.h"
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
		Texture * specularmap = nullptr;
		Vec3 ambient, diffuse, specular;
		float shininess;

		Vec2 diffuseScale;
		Vec2 normalScale;
		Vec2 specScale;

		Material(Vec3 diffuse = Vec3(1.0f, 1.0f, 1.0f), Vec3 specular = Vec3(0, 0, 0), float shininess = 32);
		~Material();

		void Dispose();

		void SetupShader();
	};

}
