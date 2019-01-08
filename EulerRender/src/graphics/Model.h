#pragma once

#include "../API.h"

#include "Mesh.h"
#include "Material.h"
#include "MeshMaterial.h"
#include "../resources/Disposable.h"

#include <vector>

namespace Euler {

	class EULER_API Model : public Disposable {
	public:
		std::vector<MeshMaterial*> drawables;

		Model();
		~Model();

		void Dispose();

		void AddDrawable(MeshMaterial* drawable);
		//void AddDrawable(Mesh * mesh, Material * material);
	};

}
