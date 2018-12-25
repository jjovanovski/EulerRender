#pragma once

#include "../API.h"
#include "Key.h"

namespace Euler {

	class EULER_API InputHandler {

	public:
		virtual ~InputHandler() {};

		virtual void Init() = 0;
		virtual void Dispose() = 0;

		virtual float GetMouseX() = 0;
		virtual float GetMouseY() = 0;
		virtual void HideCursor() = 0;
		
		virtual bool GetKey(Key key) = 0;
		virtual bool GetKeyDown(Key key) = 0;
		virtual bool GetKeyUp(Key key) = 0;
	};

}