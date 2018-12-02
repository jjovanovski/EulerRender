#include "Scene.h"

Scene::Scene() {
}

Scene::~Scene() {
}

void Scene::UpdateScene() {
	this->UpdateComponent();
}

void Scene::DrawScene() {
	glClearColor(0.2f, 0.2f, 0.6f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	this->DrawComponent();
}