#pragma once

#include "../API.h"

#include "Mesh.h"
#include "Material.h"
#include "../resources/Disposable.h"

namespace Euler {

	class EULER_API MeshMaterial : public Disposable {
	public:
		Mesh * mesh = nullptr;
		Material * material = nullptr;

		MeshMaterial();
		MeshMaterial(Mesh * mesh, Material * material);
		~MeshMaterial();

		void Dispose();
	};

}
