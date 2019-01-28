#include "Scene.h"

#include "../graphics/shaders/WorldShader.h"
#include "../resources/Resources.h"

using namespace Euler;

Scene::Scene() {
	skyboxShader = Resources::GetShader("SkyboxShader", WORLD_SKYBOX_SHADER_VERTEX, WORLD_SKYBOX_SHADER_FRAGMENT);
	shader = Resources::GetShader("WorldShader", WORLD_SHADER_VERTEX, WORLD_SHADER_FRAGMENT);
	
	directionalLight = new DirectionalLight(Vec3(-1, -1, -1).Normalized(), Vec3(1, 1, 1), 1.0f);
	camera = new Camera();
	camera->position.z += 5;
}

Scene::~Scene() {
	delete directionalLight;
	delete camera;
}

void Scene::UpdateScene() {
	this->UpdateComponent();
}

void Scene::DrawScene() {
	glClearColor(0.2f, 0.2f, 0.6f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	shader->Use();

	// direction light settings
	shader->SetVec3("directionalLight.direction", directionalLight->direction.x, directionalLight->direction.y, directionalLight->direction.z);
	shader->SetVec3("directionalLight.color", directionalLight->color.x, directionalLight->color.y, directionalLight->color.z);
	shader->SetFloat("directionalLight.intensity", directionalLight->intensity);

	// TODO: other lights settings

	// camera settings
	shader->SetVec3("cameraPos", camera->position.x, camera->position.y, camera->position.z);
	shader->SetMat4("view", &camera->GetViewMatrix());
	shader->SetMat4("proj", &Transformation::Perspective(camera->nearPlane, camera->farPlane, camera->fieldOfView));
	
	// draw skybox
	if (skybox != NULL && skybox != nullptr) {
		Mat4 skyboxViewMat = camera->GetViewMatrix();
		skyboxViewMat.mat[0][3] = 0;
		skyboxViewMat.mat[1][3] = 0;
		skyboxViewMat.mat[2][3] = 0;

		skyboxShader->Use();
		skyboxShader->SetMat4("view", &skyboxViewMat);
		skyboxShader->SetMat4("proj", &Transformation::Perspective());

		skybox->Draw();
	}

	this->DrawComponent();
}