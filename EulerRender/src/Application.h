#pragma once

#include "API.h"

#include <glad\glad.h>
#include <GLFW\glfw3.h>

#include "scene\Scene.h"

namespace Euler {

	class EULER_API Application {
	private:
		GLFWwindow * window = nullptr;
		int width, height;
		char* title;

		Scene * scene = nullptr;

	public:
		Application(int width, int height, const char* title);
		virtual ~Application();

		void Run();

		Scene * GetScene();
		void SetScene(Scene * scene);
	};

}
