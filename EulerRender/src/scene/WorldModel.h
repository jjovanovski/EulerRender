#pragma once

#include "../API.h"

#include <glad\glad.h>

#include "Component.h"
#include "../graphics/Mesh.h"
#include "../graphics/Material.h"
#include "../math/Mat4.h"
#include "../math/Transformation.h"

#include <vector>

namespace Euler {

	struct MeshMaterial {
		Mesh * mesh;
		Material * material;
	};

	class EULER_API WorldModel : public Component {
	private:
		std::vector<MeshMaterial> drawables;

	public:
		WorldModel();
		~WorldModel();

		// override Draw() method from Component
		void Draw();

		void AddMesh(Mesh * mesh, Material * material);

		Mat4 GetModelMatrix();
	};

}
