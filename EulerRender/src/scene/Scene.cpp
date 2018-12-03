#include "Scene.h"

#include "../graphics/shaders/BasicShader.h"

using namespace Euler;

Scene::Scene() {
	shader = new Shader(BASIC_SHADER_VERTEX, BASIC_SHADER_FRAGMENT);
	directionalLight = new DirectionalLight(Vec3(1, 1, 0), Vec3(1, 1, 1), 0.7f);
	camera = new Camera();
}

Scene::~Scene() {
	delete directionalLight;
	delete camera;
	delete shader;
}

void Scene::UpdateScene() {
	this->UpdateComponent();
}

void Scene::DrawScene() {
	glClearColor(0.2f, 0.2f, 0.6f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// direction light settings
	shader->SetVec3("directionalLight.direction", directionalLight->direction.x, directionalLight->direction.y, directionalLight->direction.z);
	shader->SetVec3("directionalLight.color", directionalLight->color.x, directionalLight->color.y, directionalLight->color.z);
	shader->SetFloat("directionalLight.intensity", directionalLight->intensity);

	// camera settings
	shader->SetVec3("cameraPosition", camera->x, camera->y, camera->z);
	shader->SetMat4("view", &camera->GetViewMatrix());
	shader->SetMat4("projection", &Transformation::Perspective());

	this->DrawComponent();
}