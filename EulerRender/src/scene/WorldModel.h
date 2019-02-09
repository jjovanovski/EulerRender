#pragma once

#include "../API.h"

#include <glad/glad.h>

#include "Component.h"
#include "../graphics/Mesh.h"
#include "../graphics/Material.h"
#include "../graphics/Model.h"
#include "../graphics/MeshMaterial.h"
#include "../math/Mat4.h"
#include "../math/Transformation.h"

#include <vector>

namespace Euler {
	
	class EULER_API WorldModel : public Component {
	private:
		Model * model;

	public:
		WorldModel();
		~WorldModel();

		// override Draw() method from Component
		void Draw();

		Model * GetModel();
		void SetModel(Model * model);
	};

}
