#pragma once

#include <vector>

#include "../API.h"
#include "../math/Vec3.h"

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
		Vec3 position;
		Vec3 rotation;
		Vec3 scale;

		Component();
		virtual ~Component();

		void AddChild(Component * component);
	};

}
