#pragma once

#include <GLFW/glfw3.h>

#include "../API.h"
#include "InputHandler.h"
#include "Key.h"

namespace Euler {

	class EULER_API GLFWInputHandler : public InputHandler {
	private:
		GLFWwindow * window;
		static float mouseX;
		static float mouseY;

	public:
		GLFWInputHandler(GLFWwindow* window);
		~GLFWInputHandler();

		// overriden methods from interface
		void Init();
		void Dispose() ;
		float GetMouseX();
		float GetMouseY();
		void HideCursor();
		bool GetKey(Key key);
		bool GetKeyDown(Key key);
		bool GetKeyUp(Key key);

		// implementation support functions
		static void CursorPosCallback(GLFWwindow* window, double x, double y);
		static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static int Map(Key key);
	};

};
