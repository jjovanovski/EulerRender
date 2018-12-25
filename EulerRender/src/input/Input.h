#pragma once

#include "../API.h"

#include "InputHandler.h"
#include "Key.h"
#include "../math/Vec2.h"

namespace Euler {

	class EULER_API Input {
	private:
		static InputHandler* handler;

	public:
		Input();
		~Input();

		static void Init(InputHandler* handler);
		static void Dispose();

		static Vec2 GetMousePos();
		static float GetMouseX();
		static float GetMouseY();
		static void HideCursor();

		static bool GetKeyDown(Key key);
		static bool GetKey(Key key);
		static bool GetKeyUp(Key key);
	};

};
