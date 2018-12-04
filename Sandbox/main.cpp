#include <iostream>
#include <cmath>

#include "Euler.h"

class MyScene : public Euler::Scene {

public:
	Euler::Mesh * sphereMesh;
	Euler::Material * someMaterial;
	Euler::WorldModel * model;

	MyScene() {
		sphereMesh = new Euler::Sphere(30, 30);

		someMaterial = new Euler::Material();
		someMaterial->shader = shader;
		someMaterial->diffuse = Euler::Vec3(0.4, 0.7f, 0.3f);

		model = new Euler::WorldModel();
		model->AddMesh(sphereMesh, someMaterial);
		this->AddChild(model);
	}

	~MyScene() {
		delete sphereMesh;
		delete someMaterial;
		delete model;
	}

	void Update() {

	}

};

int main(char** args, int argc) {
	Euler::Application app(600, 600, "App test");
	MyScene scene;
	app.SetScene(&scene);
	app.Run();
	
	return 0;
}