#include <iostream>
#include <cmath>

#include "Euler.h"

#define PI 3.1415926535

using namespace Euler;

class MyScene : public Euler::Scene {

public:
	Euler::Mesh * sphereMesh;
	Euler::Mesh * planeMesh;
	Euler::Material * someMaterial;
	Euler::Texture * brickTexture;
	Euler::Texture * normalTexture;
	Euler::WorldModel * model1;
	Euler::WorldModel * model2;
	WorldModel * nanosuitWorld;
	Euler::FreeCamera * freeCam;
	float time = 0;

	MyScene() {
		Input::HideCursor();

		sphereMesh = new Euler::Sphere(30, 30);
		planeMesh = new Euler::Plane();

		normalTexture = Resources::GetTexture("brick_normal", "brick_normal.jpg");
		brickTexture = Resources::GetTexture("brick_diffuse", "brick_diffuse.jpg");

		someMaterial = Resources::GetMaterial("someMaterial");
		someMaterial->shader = shader;
		someMaterial->texture = brickTexture;
		someMaterial->normalmap = normalTexture;
		someMaterial->diffuse = Euler::Vec3(1, 1, 1);
		someMaterial->specular = Euler::Vec3(0.1f, 0.1f, 0.1f);
		someMaterial->shininess = 30.0f;

		MeshMaterial * sphereMeshMaterial = Resources::GetMeshMaterial("sphereMeshMaterial");
		sphereMeshMaterial->mesh = sphereMesh;
		sphereMeshMaterial->material = someMaterial;
		Model * sphereModel = Resources::GetModel("sphereModel");
		sphereModel->AddDrawable(sphereMeshMaterial);

		MeshMaterial * planeMeshMaterial = Resources::GetMeshMaterial("planeMeshMaterial");
		planeMeshMaterial->mesh = planeMesh;
		planeMeshMaterial->material = someMaterial;
		Model * planeModel = Resources::GetModel("planeModel");
		planeModel->AddDrawable(planeMeshMaterial);

		model1 = new Euler::WorldModel();
		model1->rotation = Quaternion::Euler(-90.0f * 0.0174533f, 1, 0, 0);
		model1->scale = Vec3(55, 55, 55);
		model1->position.y = -1.0f;
		model1->SetModel(planeModel);
		this->AddChild(model1);

		model2 = new Euler::WorldModel();
		model2->position.x = 0;
		model2->SetModel(sphereModel);
		//this->AddChild(model2);
		
		freeCam = new FreeCamera(camera);
		this->AddChild(freeCam);

		/*Model * nanosuit = Resources::GetModel("nanosuit", "nanosuit/nanosuit.obj");
		nanosuitWorld = new WorldModel();
		nanosuitWorld->SetModel(nanosuit);
		nanosuitWorld->scale = Vec3(0.2f, 0.2f, 0.2f);
		this->AddChild(nanosuitWorld);*/
	}

	~MyScene() {
		delete sphereMesh;
		delete planeMesh;
		//delete brickTexture;
		//delete someMaterial;
		delete model1;
		delete model2;
		delete nanosuitWorld;
	}

	void Update() {
		time += 0.02f;
		//model1->rotation = Euler::Quaternion::Euler(time, 1.0f, 0.0f, 0.0f);
		model2->rotation = Euler::Quaternion::Euler(time, 0.0f, 1.0f, 1.0f);
		//model2->position = Euler::Vec3(sin(time), cos(time), 0);
		//model2->rotation.y = time*0.5f;
		//model2->position.x = sin(time);

		//std::cout << someMaterial->shininess << std::endl;
		if (Input::GetKey(Key::NUMPAD_PLUS)) {
			someMaterial->shininess += 1;
		} else if (Input::GetKey(Key::NUMPAD_MINUS)) {
			someMaterial->shininess -= 1;
		}
	}

};

int main(char** args, int argc) {
	Euler::Application app(900, 900, "App test");
	MyScene scene;
	app.SetScene(&scene);
	app.Run();
	
	return 0;
}