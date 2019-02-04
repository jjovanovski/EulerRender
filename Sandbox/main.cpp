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
	Mesh * sphereMesh;
	Mesh * planeMesh;
	Mesh * cubeMesh;

	FreeCamera * freeCam;

	WorldModel * ground;

	MyScene() {
		Input::HideCursor();

		// set-up the skybox
		skybox = Resources::GetSkybox("sunset", {"sunset/xp.png", "sunset/xn.png", "sunset/yp.png", "sunset/yn.png", "sunset/zp.png", "sunset/zn.png"});

		// create primitive meshes that can be shader between any objects
		planeMesh = new Euler::Plane(16);
		sphereMesh = new Euler::Sphere(30, 30);
		cubeMesh = new Euler::Cube();

		// add the free move camera as component
		freeCam = new FreeCamera(camera, 0.0015f, 0.0035f, 0.05f);
		this->AddChild(freeCam);

		//directionalLight->color = Vec3(1.0f, 1.0f, 0.4f);
		directionalLight->direction = Vec3(-1, -0.5f, -1).Normalized();

		// set the camera position a little above the ground
		camera->SetPosition(Vec3(0, 0.2f, 3.0f));

		// create the scene
		addGround();
		addSemaphore();
		//addCar();

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

	Component * semaphore;
	void addSemaphore() {
		Material * semBoxMat = Resources::GetMaterial("semBoxMat");
		semBoxMat->diffuse = Vec3(0.1f, 0.1f, 0.1f);
		semBoxMat->specular = Vec3(0.1f, 0.1f, 0.1f);
		semBoxMat->shininess = 64.0f;
		semBoxMat->shader = shader;

		Material * semRedMat = Resources::GetMaterial("semRedMat");
		semRedMat->shader = shader;
		semRedMat->diffuse = Vec3(1.0f, 0.0f, 0.0f);

		Material * semYellowMat = Resources::GetMaterial("semYellowMat");
		semYellowMat->shader = shader;
		semYellowMat->diffuse = Vec3(1.0f, 1.0f, 0.0f);

		Material * semGreenMat = Resources::GetMaterial("semGreenMat");
		semGreenMat->shader = shader;
		semGreenMat->diffuse = Vec3(0.0f, 1.0f, 0.0f);

		MeshMaterial * semBoxMM = Resources::GetMeshMaterial("semBoxMM");
		semBoxMM->material = semBoxMat;
		semBoxMM->mesh = cubeMesh;

		MeshMaterial * semRedMM = Resources::GetMeshMaterial("semRedMM");
		semRedMM->material = semRedMat;
		semRedMM->mesh = sphereMesh;

		MeshMaterial * semYellowMM = Resources::GetMeshMaterial("semYellowMM");
		semYellowMM->material = semYellowMat;
		semYellowMM->mesh = sphereMesh;

		MeshMaterial * semGreenMM = Resources::GetMeshMaterial("semGreenMM");
		semGreenMM->material = semGreenMat;
		semGreenMM->mesh = sphereMesh;

		Model * semBoxModel = Resources::GetModel("semBoxModel");
		semBoxModel->AddDrawable(semBoxMM);
		Model * semRedModel = Resources::GetModel("semRedModel");
		semRedModel->AddDrawable(semRedMM);
		Model * semYellowModel = Resources::GetModel("semYellowModel");
		semYellowModel->AddDrawable(semYellowMM);
		Model * semGreenModel = Resources::GetModel("semGreenModel");
		semGreenModel->AddDrawable(semGreenMM);

		float scale = 0.3f;

		semaphore = new Component();
		this->AddChild(semaphore);

		WorldModel * semBox = new WorldModel();
		semBox->SetModel(semBoxModel);
		semBox->SetScale(Vec3(scale*1.2f, scale*3.5f, scale));
		semBox->SetPosition(Vec3(0.0f, 0.0f, -scale/2.0f));
		semaphore->AddChild(semBox);

		WorldModel * semRed = new WorldModel();
		semRed->SetModel(semRedModel);
		semRed->SetScale(Vec3(scale, scale, scale));
		semRed->SetPosition(Vec3(0, scale*2.1f, 0.0f));
		semaphore->AddChild(semRed);

		WorldModel * semYellow = new WorldModel();
		semYellow->SetModel(semYellowModel);
		semYellow->SetScale(Vec3(scale, scale, scale));
		semaphore->AddChild(semYellow);

		WorldModel * semGreen = new WorldModel();
		semGreen->SetModel(semGreenModel);
		semGreen->SetScale(Vec3(scale, scale, scale));
		semGreen->SetPosition(Vec3(0, -scale * 2.1f, 0.0f));
		semaphore->AddChild(semGreen);
	}

	WorldModel * car;
	void addCar() {
		Model * carmodel = Resources::GetModel("car1", "game/CreativeAssembly/objects/building.fbx");

		car = new WorldModel();

		car->SetModel(carmodel);
		car->SetScale( Vec3(0.005f, 0.005f, 0.005f));
		//car->rotation = Quaternion::Euler(PI / 2.0f, 1, 0, 0);
		this->AddChild(car);
	}

	~MyScene() {
		delete planeMesh;
		delete sphereMesh;
		delete cubeMesh;

		delete ground;
		delete semaphore;
	}

	void addGround() {
		Texture * groundDiffuse = Resources::GetTexture("groundDiffuse", "game/sand/sand_diffuse.jpg");
		Texture * groundNormal = Resources::GetTexture("groundNormal", "game/sand/sand_normal.jpg");
		Texture * groundSpecular = Resources::GetTexture("groundSpecular", "game/sand/sand_roughness.jpg");

		Material * groundMaterial = Resources::GetMaterial("groundMaterial");
		groundMaterial->shader = Resources::GetShader("WorldShader");
		groundMaterial->texture = groundDiffuse;
		groundMaterial->normalmap = groundNormal;
		groundMaterial->specularmap = groundSpecular;
		groundMaterial->diffuseScale = Vec2(17, 17);
		groundMaterial->normalScale = Vec2(17, 17);
		groundMaterial->specScale = Vec2(17, 17);
		groundMaterial->diffuse = Vec3(0.6f, 0.6f, 0.6f);
		groundMaterial->specular = Vec3(1, 1, 1);
		groundMaterial->shininess = 32;

		MeshMaterial * groundMeshMaterial = Resources::GetMeshMaterial("groundMeshMaterial");
		groundMeshMaterial->mesh = planeMesh;
		groundMeshMaterial->material = groundMaterial;

		Model * groundModel = Resources::GetModel("ground");
		groundModel->AddDrawable(groundMeshMaterial);

		ground = new WorldModel();
		ground->SetModel(groundModel);
		ground->SetScale(Vec3(30, 30, 30));
		ground->SetRotation(Quaternion::Euler(-90 * DEG_RAD, 1, 0, 0));
		AddChild(ground);
	}

	void Update() {
		Vec3 offset(0.1f, 0.1f, 0.1f);
		if (Input::GetKey(Key::NUMPAD_PLUS)) {
			semaphore->SetPosition(semaphore->GetX() + 0.1f, semaphore->GetY() + 0.1f, semaphore->GetZ() + 0.1f);
		} else if(Input::GetKey(Key::NUMPAD_MINUS)) {
			semaphore->SetPosition(semaphore->GetX() - 0.1f, semaphore->GetY() - 0.1f, semaphore->GetZ() - 0.1f);
		}

		if (Input::GetKey(Key::NUMPAD_FIVE)) {
			std::cout << semaphore->GetScaleX() << std::endl;
			semaphore->SetScale(semaphore->GetScaleX() + 0.01f, semaphore->GetScaleY() + 0.01f, semaphore->GetScaleZ() + 0.01f);
		}
		else if(Input::GetKey(Key::NUMPAD_TWO)) {
			semaphore->SetScale(semaphore->GetScaleX() - 0.01f, semaphore->GetScaleY() - 0.01f, semaphore->GetScaleZ() - 0.01f);
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