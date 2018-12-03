#pragma once

#include <glad\glad.h>

#include "../API.h"
#include "../graphics/Shader.h"
#include "../math//Transformation.h"
#include "Component.h"
#include "DirectionalLight.h"
#include "Camera.h"

namespace Euler {

	class EULER_API Scene : public Component {
	public:
		DirectionalLight * directionalLight;
		Camera * camera;
		Shader * shader;

		Scene();
		virtual ~Scene();

		void UpdateScene();
		void DrawScene();
	};

}
