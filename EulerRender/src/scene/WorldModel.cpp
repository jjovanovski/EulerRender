#include "WorldModel.h"

using namespace Euler;
#include <iostream>
WorldModel::WorldModel() {
}


WorldModel::~WorldModel() {
}

void WorldModel::Draw() {
	for (MeshMaterial drawable : drawables) {
		drawable.mesh->Bind();
		drawable.material->SetupShader();
		
		drawable.material->shader->SetMat4("model", &GetModelMatrix());

		glDrawElements(GL_TRIANGLES, drawable.mesh->indices.size(), GL_UNSIGNED_INT, 0);
	}
}

void WorldModel::AddMesh(Mesh * mesh, Material * material) {
	drawables.push_back({ mesh, material });
}

Mat4 WorldModel::GetModelMatrix() {
	return Transformation::Translate(position.x, position.y, position.z)
		* rotation.GetMatrix()
		* Transformation::Scale(scale.x, scale.y, scale.z)
		* Transformation::Identity();
}
