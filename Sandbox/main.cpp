#include <iostream>
#include <cmath>

#include "Euler.h"

//class MyScene : public Euler::Scene {
//
//public:
//	Euler::Shader * shader;
//	Euler::Cube * cube;
//	Euler::Sphere * sphere;
//	Euler::Model * cubeModel;
//	Euler::Camera * camera;
//	Euler::Material * material;
//	float a = 0.0f;
//
//	MyScene() {
//		shader = new Euler::Shader(BASIC_SHADER_VERTEX, BASIC_SHADER_FRAGMENT);
//		shader->Use();
//		shader->SetVec3("directionalLight.direction", 0, 0, 0);
//		shader->SetVec3("directionalLight.color", 1.0f, 1.0f, 1.0f);
//		shader->SetFloat("directionalLight.intensity", 0.5f);
//		
//
//		cube = new Euler::Cube;
//		sphere = new Euler::Sphere(30, 30);
//
//		cubeModel = new Euler::Model();
//		cubeModel->mesh = sphere;
//		cubeModel->roty = 5.0f;
//		cubeModel->rotx = 0.0f;
//		//cubeModel->scalex = 0.5f;
//		//cubeModel->scaley = 0.5f;
//		//cubeModel->scalez = 0.5f;
//
//		camera = new Euler::Camera();
//		camera->z -= 7;
//
//		material = new Euler::Material(Euler::Vec3(0.07568, 0.61424, 0.07568), Euler::Vec3(1, 1, 1), 256);
//	}
//
//	~MyScene() {
//		delete shader;
//		delete cube;
//		delete cubeModel;
//		delete camera;
//		delete material;
//	}
//
//	void Update() {
//		//cubeModel->rotx += 0.01f;
//		a += 0.05f;
//	}
//
//	void Draw() {
//		shader->SetVec3("directionalLight.direction", cos(a * 0.5f) * 2.5f, 0, sin(a * 0.5f) * 2.5f);
//		shader->SetVec3("cameraPos", camera->x, camera->y, camera->z);
//
//		shader->SetVec3("objectColor", 0.5f, 0.67f, 1.0f);
//		camera->Draw(cubeModel, shader, material);
//	}
//
//};

int main(char** args, int argc) {
	/*Euler::Application app(600, 600, "App test");
	MyScene scene;
	app.SetScene(&scene);
	app.Run();*/
	
	return 0;
}