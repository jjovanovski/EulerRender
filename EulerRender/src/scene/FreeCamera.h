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
		float movementSpeed, mouseSensitivityX, mouseSensitivityY;

	public:
		FreeCamera(Camera * camera, float mouseSensitivtyX = 0.002f, float mouseSensitivityY = 0.005f, float movementSpeed = 0.1f);
		~FreeCamera();

		void Update();
	};

}
