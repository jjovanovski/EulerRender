#include "Camera.h"

using namespace Euler;

Camera::Camera() : Component() {
}

Camera::~Camera() {
}

Mat4 Camera::GetViewMatrix() {
	return GetRotation().Conjugate().GetMatrix() * Transformation::Translate(-GetX(), -GetY(), -GetZ());
}

/*void Camera::Draw(Model * model, Shader * shader, Material * material) {
	shader->Use();
	shader->SetMat4("model", &model->GetModelMatrix());
	shader->SetMat4("view", &GetViewMatrix());
	shader->SetMat4("proj", &Transformation::Perspective());

	shader->SetVec3("material.diffuse", material->diffuse.x, material->diffuse.y, material->diffuse.z);
	shader->SetVec3("material.specular", material->specular.x, material->specular.y, material->specular.z);
	shader->SetFloat("material.shininess", material->shininess);

	// refactor this when there will be more meshes per model
	model->mesh->Bind();
	glDrawElements(GL_TRIANGLES, model->mesh->indices.size(), GL_UNSIGNED_INT, 0);
}*/
