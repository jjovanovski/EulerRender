#include "WorldModel.h"

using namespace Euler;

WorldModel::WorldModel() : Component() {
}


WorldModel::~WorldModel() {
}

void WorldModel::Draw() {
	for (MeshMaterial * drawable : model->drawables) {
		drawable->mesh->Bind();
		drawable->material->SetupShader();
		
		drawable->material->shader->SetMat4("model", &GetModelMatrix());

		glDrawElements(GL_TRIANGLES, drawable->mesh->indices.size(), GL_UNSIGNED_INT, 0);
	}
}

Model * WorldModel::GetModel() {
	return model;
}

void WorldModel::SetModel(Model * model) {
	this->model = model;
}