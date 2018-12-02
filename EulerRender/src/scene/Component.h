#pragma once

#include <vector>

#include "../API.h"

namespace Euler {

	class EULER_API Component {
	private:
		Component * parent = nullptr;
		std::vector<Component*> children;

	protected:
		void UpdateComponent();
		void DrawComponent();
		virtual void Update() {};
		virtual void Draw() {};

	public:
		Component();
		virtual ~Component();

		void AddChild(Component * component);
	};

}
