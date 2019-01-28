#include <iostream>
#include <cmath>
#include <stdlib.h>  
#include <stdio.h>  
#include <time.h>

#include "Euler.h"

#define PI 3.1415926535f
#define DEG_RAD PI/180.0f
#define RAD_DEG 180.0f/PI

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

	WorldModel * ground;

	MyScene() {
		Input::HideCursor();

		// set-up the skybox
		skybox = Resources::GetSkybox("sunset", {"sunset/xp.png", "sunset/xn.png", "sunset/yp.png", "sunset/yn.png", "sunset/zp.png", "sunset/zn.png"});

		// create plane mesh that can be shader between any objects
		planeMesh = new Euler::Plane(16);

		// add the free move camera as component
		freeCam = new FreeCamera(camera, 0.0015f, 0.0035f, 0.05f);
		this->AddChild(freeCam);

		//directionalLight->color = Vec3(1.0f, 1.0f, 0.4f);
		directionalLight->direction = Vec3(-1, -0.2f, -1).Normalized();

		// set the camera position a little above the ground
		camera->position = Vec3(0, 0.2f, 0);

		// create the scene
		addGround();
		addCar();

		/*sphereMesh = new Euler::Sphere(30, 30);

		brickTexture = Resources::GetTexture("ground", "game/ground.jpg");
		normalTexture = Resources::GetTexture("ground_normal", "game/ground_normal.jpg");

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

		directionalLight->intensity = 1.5f;

		Model * nanosuit = Resources::GetModel("nanosuit", "man/GTP_BMan_Jack_07_Stg_Lsn_Adl_Ccs_Gry_Mgr.obj");
		nanosuitWorld = new WorldModel();
		nanosuitWorld->SetModel(nanosuit);
		nanosuitWorld->scale = Vec3(0.02f, 0.02f, 0.02f);
		this->AddChild(nanosuitWorld);*/
	}

	WorldModel * car;
	void addCar() {
		Model * carmodel = Resources::GetModel("car1", "game/CreativeAssembly/objects/building.fbx");

		car = new WorldModel();

		car->SetModel(carmodel);
		car->scale = Vec3(0.005f, 0.005f, 0.005f);
		//car->rotation = Quaternion::Euler(PI / 2.0f, 1, 0, 0);
		this->AddChild(car);
	}

	~MyScene() {
		delete planeMesh;
		delete ground;
		delete car;
	}

	void addGround() {
		Texture * groundDiffuse = Resources::GetTexture("groundDiffuse", "game/groundDirty.jpg");
		Texture * groundNormal = Resources::GetTexture("groundNormal", "game/ground_normal.jpg");
		Texture * groundSpecular = Resources::GetTexture("groundSpecular", "game/ground_specular.jpg");

		Material * groundMaterial = Resources::GetMaterial("groundMaterial");
		groundMaterial->shader = Resources::GetShader("WorldShader");
		groundMaterial->texture = groundDiffuse;
		groundMaterial->normalmap = groundNormal;
		groundMaterial->specularmap = groundSpecular;
		groundMaterial->diffuseScale = Vec2(7, 7);
		groundMaterial->normalScale = Vec2(7, 7);
		groundMaterial->specScale = Vec2(7, 7);
		groundMaterial->diffuse = Vec3(0.3f, 0.3f, 0.35f);
		groundMaterial->specular = Vec3(1, 1, 1);
		groundMaterial->shininess = 64;

		MeshMaterial * groundMeshMaterial = Resources::GetMeshMaterial("groundMeshMaterial");
		groundMeshMaterial->mesh = planeMesh;
		groundMeshMaterial->material = groundMaterial;

		Model * groundModel = Resources::GetModel("ground");
		groundModel->AddDrawable(groundMeshMaterial);

		ground = new WorldModel();
		ground->SetModel(groundModel);
		ground->scale = Vec3(10, 10, 10);
		ground->rotation = Quaternion::Euler(-90 * DEG_RAD, 1, 0, 0);
		AddChild(ground);
	}

	void Update() {
		if (Input::GetKey(Key::NUMPAD_PLUS)) {
			std::cout << camera->fieldOfView << std::endl;
			camera->fieldOfView += 0.1f;
		} else if(Input::GetKey(Key::NUMPAD_MINUS)) {
			camera->fieldOfView -= 0.1f;
		}

		/*time += 0.02f;
		//model1->rotation = Euler::Quaternion::Euler(time, 1.0f, 0.0f, 0.0f);
		//model2->rotation = Euler::Quaternion::Euler(time, 0.0f, 1.0f, 1.0f);
		//model2->position = Euler::Vec3(sin(time), cos(time), 0);
		//model2->rotation.y = time*0.5f;
		//model2->position.x = sin(time);
		
		//std::cout << someMaterial->shininess << std::endl;
		if (Input::GetKey(Key::NUMPAD_PLUS)) {
			someMaterial->shininess += 1;
		} else if (Input::GetKey(Key::NUMPAD_MINUS)) {
			someMaterial->shininess -= 1;
		}*/
	}

};

int main(char** args, int argc) {
	Euler::Application app(900, 900, "App test");
	MyScene scene;
	app.SetScene(&scene);
	app.Run();
	
	return 0;
}