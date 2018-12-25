#pragma once

#include "../API.h"

#include "Component.h"
#include "Camera.h"
#include "../input/Input.h"

namespace Euler {

	class EULER_API FreeCamera : public Component {

	private:
		Camera * camera;
		float mouseX = 0, mouseY = 0;
		float cameraRotX = 0, cameraRotY = 0;

	public:
		FreeCamera(Camera * camera);
		~FreeCamera();

		void Update();
	};

}
