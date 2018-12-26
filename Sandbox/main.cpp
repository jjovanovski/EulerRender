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
	Euler::FreeCamera * freeCam;
	float time = 0;

	MyScene() {
		Input::HideCursor();

		sphereMesh = new Euler::Sphere(30, 30);
		planeMesh = new Euler::Plane();

		normalTexture = new Euler::Texture("brick_normal.jpg");
		brickTexture = new Euler::Texture("brick_diffuse.jpg");

		someMaterial = new Euler::Material();
		someMaterial->shader = shader;
		someMaterial->texture = brickTexture;
		someMaterial->normalmap = normalTexture;
		someMaterial->diffuse = Euler::Vec3(1, 1, 1);
		someMaterial->specular = Euler::Vec3(0.1f, 0.1f, 0.1f);
		someMaterial->shininess = 30.0f;

		model1 = new Euler::WorldModel();
		model1->rotation = Quaternion::Euler(-90.0f * 0.0174533f, 1, 0, 0);
		model1->scale = Vec3(55, 55, 55);
		model1->position.y = -1.0f;
		model1->AddMesh(planeMesh, someMaterial);
		this->AddChild(model1);

		model2 = new Euler::WorldModel();
		model2->position.x = 0;
		model2->AddMesh(sphereMesh, someMaterial);
		this->AddChild(model2);
		
		freeCam = new FreeCamera(camera);
		this->AddChild(freeCam);
	}

	~MyScene() {
		delete sphereMesh;
		delete planeMesh;
		delete brickTexture;
		delete someMaterial;
		delete model1;
		delete model2;
	}

	void Update() {
		time += 0.02f;
		//model1->rotation = Euler::Quaternion::Euler(time, 1.0f, 0.0f, 0.0f);
		model2->rotation = Euler::Quaternion::Euler(time, 0.0f, 1.0f, 1.0f);
		//model2->position = Euler::Vec3(sin(time), cos(time), 0);
		//model2->rotation.y = time*0.5f;
		//model2->position.x = sin(time);

		std::cout << someMaterial->shininess << std::endl;
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