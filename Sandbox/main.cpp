#include <iostream>
#include <cmath>

#include "Euler.h"

class MyScene : public Euler::Scene {

public:
	Euler::Mesh * sphereMesh;
	Euler::Mesh * planeMesh;
	Euler::Material * someMaterial;
	Euler::Texture * brickTexture;
	Euler::WorldModel * model1;
	Euler::WorldModel * model2;
	float time = 0;

	MyScene() {
		sphereMesh = new Euler::Sphere(30, 30);
		planeMesh = new Euler::Cube();

		brickTexture = new Euler::Texture("brick_diffuse.jpg");

		someMaterial = new Euler::Material();
		someMaterial->shader = shader;
		someMaterial->texture = brickTexture;
		someMaterial->diffuse = Euler::Vec3(1, 1, 1);
		someMaterial->specular = Euler::Vec3(0.1f, 0.1f, 0.1f);

		model1 = new Euler::WorldModel();
		model1->position.x = -2;
		model1->AddMesh(planeMesh, someMaterial);
		//this->AddChild(model1);

		model2 = new Euler::WorldModel();
		model2->position.x = 0;
		model2->AddMesh(sphereMesh, someMaterial);
		this->AddChild(model2);

		camera->z += 5;
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
		time += 0.1f;
		model2->rotation.y = time*0.5f;
		//model2->position.x = sin(time);
	}

};

int main(char** args, int argc) {
	Euler::Application app(600, 600, "App test");
	MyScene scene;
	app.SetScene(&scene);
	app.Run();
	
	return 0;
}