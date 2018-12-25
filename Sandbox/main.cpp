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
		someMaterial->specular = Euler::Vec3(0.6f, 0.6f, 0.6f);

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

		camera->position.y -= 0.5f;

		camera->position = { 0, 0, 0 };
	}

	~MyScene() {
		delete sphereMesh;
		delete planeMesh;
		delete brickTexture;
		delete someMaterial;
		delete model1;
		delete model2;
	}

	float rx = 0, ry = 0, rz = 0;
	float mousex = 0, mousey = 0;
	float camrx = 0, camry = 0;
	void Update() {
		time += 0.02f;
		//model1->rotation = Euler::Quaternion::Euler(time, 1.0f, 0.0f, 0.0f);
		model2->rotation = Euler::Quaternion::Euler(time, 0.0f, 1.0f, 1.0f);
		//model2->position = Euler::Vec3(sin(time), cos(time), 0);
		//model2->rotation.y = time*0.5f;
		//model2->position.x = sin(time);

		float mouseDeltaX = Input::GetMouseX() - mousex;
		float mouseDeltaY = Input::GetMouseY() - mousey;
		std::cout << mouseDeltaY << std::endl;
		mousex = Input::GetMouseX();
		mousey = Input::GetMouseY();
		camrx += mouseDeltaX;
		camry += mouseDeltaY;
		//camera->rotation = Quaternion::Euler(-camrx*0.01f, 0, 1, 0);
		camera->rotation = Quaternion::Euler(-camrx * 0.005f, 0, 1, 0) * Quaternion::Euler(-camry * 0.002f, 1, 0, 0);

		float camspeed = 0.1f;
		Vec3 forwardDir = camera->Forward();
		Vec3 rightDir = camera->Right();
		Vec3 upDir = camera->Up();
		//std::cout << forwardDir.x << " " << forwardDir.y << " " << forwardDir.z << "\t\t\t\t" << rightDir.x << " " << rightDir.y << " " << rightDir.z << "\t\t\t\t" << upDir.x << " " << upDir.y << " " << upDir.z << std::endl;
		if (Input::GetKey(Key::W)) {
			camera->position.x -= forwardDir.x * camspeed;
			camera->position.y -= forwardDir.y * camspeed;
			camera->position.z -= forwardDir.z * camspeed;
		} else if (Input::GetKey(Key::S)) {
			camera->position.x += forwardDir.x * camspeed;
			camera->position.y += forwardDir.y * camspeed;
			camera->position.z += forwardDir.z * camspeed;
		}
		
		if (Input::GetKey(Key::A)) {
			camera->position -= Vec3(rightDir.x * camspeed, rightDir.y * camspeed, rightDir.z * camspeed);
		} else if (Input::GetKey(Key::D)) {
			camera->position += Vec3(rightDir.x * camspeed, rightDir.y * camspeed, rightDir.z * camspeed);
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