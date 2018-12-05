#include <iostream>
#include <cmath>

#include "Euler.h"

class MyScene : public Euler::Scene {

public:
	Euler::Mesh * sphereMesh;
	Euler::Material * someMaterial;
	Euler::WorldModel * model1;
	Euler::WorldModel * model2;
	float time = 0;

	MyScene() {
		Euler::Vec3 v(1, 1, 1);
		v.Normalize();
		std::cout << v.x << " " << v.y << " " << v.z;

		sphereMesh = new Euler::Sphere(30, 30);

		someMaterial = new Euler::Material();
		someMaterial->shader = shader;
		someMaterial->diffuse = Euler::Vec3(0.4, 0.7f, 0.3f);
		someMaterial->specular = Euler::Vec3(0.1f, 0.1f, 0.1f);

		model1 = new Euler::WorldModel();
		model1->position.x = -2;
		model1->AddMesh(sphereMesh, someMaterial);
		this->AddChild(model1);

		model2 = new Euler::WorldModel();
		model2->position.x = 2;
		model2->AddMesh(sphereMesh, someMaterial);
		this->AddChild(model2);
	}

	~MyScene() {
		delete sphereMesh;
		delete someMaterial;
		delete model1;
		delete model2;
	}

	void Update() {
		time += 0.1f;
		model2->position.x = sin(time);
	}

};

int main(char** args, int argc) {
	Euler::Application app(600, 600, "App test");
	MyScene scene;
	app.SetScene(&scene);
	app.Run();
	
	return 0;
}