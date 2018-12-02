#include <iostream>
#include <cmath>

#include "Euler.h"

class MyScene : public Euler::Scene {

public:
	Euler::Shader * shader;
	Euler::Cube * cube;
	Euler::Model * cubeModel;
	Euler::Camera * camera;
	float a = 0.0f;

	MyScene() {
		shader = new Euler::Shader(BASIC_SHADER_VERTEX, BASIC_SHADER_FRAGMENT);
		shader->Use();
		shader->SetVec3("ambientColor", 1.0f, 1.0f, 1.0f);
		shader->SetFloat("ambientIntensity", 0.3f);
		shader->SetVec3("lightPos", 0, 0, 0);
		shader->SetVec3("lightColor", 1.0f, 1.0f, 1.0f);
		shader->SetFloat("lightIntensity", 0.7f);
		
		cube = new Euler::Cube;
		cubeModel = new Euler::Model();
		cubeModel->mesh = cube;
		cubeModel->roty = 45.0f;

		camera = new Euler::Camera();
		camera->z -= 7;
	}

	~MyScene() {
		delete shader;
		delete cube;
		delete cubeModel;
		delete camera;
	}

	void Update() {
		//cubeModel->rotx += 0.01f;
		a += 0.1f;
	}

	void Draw() {
		shader->SetVec3("lightPos", cos(a * 0.5f) * 2.5f, 0, sin(a * 0.5f) * 2.5f);
		shader->SetVec3("cameraPos", camera->x, camera->y, camera->z);

		shader->SetVec3("objectColor", 0.5f, 0.67f, 1.0f);
		camera->Draw(cubeModel, shader);
	}

};

int main(char** args, int argc) {
	Euler::Application app(600, 600, "App test");
	MyScene scene;
	app.SetScene(&scene);
	app.Run();
	
	return 0;
}