#include "Camera.h"

using namespace Euler;

Camera::Camera() {
	x = 0;
	y = 0;
	z = 0;

	rotx = 0;
	roty = 0;
	rotz = 0;
}

Camera::~Camera() {
}

Mat4 Camera::GetViewMatrix() {
	return Transformation::Translate(x, y, z) * Transformation::Rotate(rotx, 1, 0, 0) * Transformation::Rotate(roty, 0, 1, 0) * Transformation::Rotate(rotz, 0, 0, 1) * Transformation::Identity();
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
