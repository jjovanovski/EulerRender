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
	}

	Component * semaphore;
	WorldModel * semBox;
	WorldModel * semRed;
	WorldModel * semYellow;
	WorldModel * semGreen;
	void addSemaphore() {
		Material * semBoxMat = Resources::GetMaterial("semBoxMat");
		semBoxMat->diffuse = Vec3(0.1f, 0.1f, 0.1f);
		semBoxMat->specular = Vec3(0.1f, 0.1f, 0.1f);
		semBoxMat->shininess = 64.0f;
		semBoxMat->shader = shader;

		Material * semRedMat = Resources::GetMaterial("semRedMat");
		semRedMat->shader = shader;
		semRedMat->diffuse = Vec3(0.2f, 0.0f, 0.0f);
		semRedMat->emission = Vec3(1.0f, 0.0f, 0.0f);

		Material * semYellowMat = Resources::GetMaterial("semYellowMat");
		semYellowMat->shader = shader;
		semYellowMat->diffuse = Vec3(0.2f, 0.2f, 0.0f);
		semYellowMat->emission = Vec3(1.0f, 1.0f, 0.0f);

		Material * semGreenMat = Resources::GetMaterial("semGreenMat");
		semGreenMat->shader = shader;
		semGreenMat->diffuse = Vec3(0.0f, 0.2f, 0.0f);
		semGreenMat->emission = Vec3(0.0f, 1.0f, 0.0f);

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

		float scale = 0.1f;

		semaphore = new Component();
		this->AddChild(semaphore);

		semBox = new WorldModel();
		semBox->SetModel(semBoxModel);
		semBox->SetScale(Vec3(scale*1.2f, scale*3.5f, scale));
		semBox->SetPosition(Vec3(0.0f, 0.0f, -scale/2.0f));
		semaphore->AddChild(semBox);

		semRed = new WorldModel();
		semRed->SetModel(semRedModel);
		semRed->SetScale(Vec3(scale, scale, scale));
		semRed->SetPosition(Vec3(0, scale*2.1f, 0.0f));
		semaphore->AddChild(semRed);

		semYellow = new WorldModel();
		semYellow->SetModel(semYellowModel);
		semYellow->SetScale(Vec3(scale, scale, scale));
		semaphore->AddChild(semYellow);

		semGreen = new WorldModel();
		semGreen->SetModel(semGreenModel);
		semGreen->SetScale(Vec3(scale, scale, scale));
		semGreen->SetPosition(Vec3(0, -scale * 2.1f, 0.0f));
		semaphore->AddChild(semGreen);

		semaphore->SetPosition(0, 1, 0);
	}

	~MyScene() {
		delete planeMesh;
		delete sphereMesh;
		delete cubeMesh;

		delete ground;
		delete semaphore;
		delete semBox;
		delete semRed;
		delete semYellow;
		delete semGreen;
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

	int color = 0;	// 0 = red, 1 = yellow, 2 = green
	int counter = 0;
	void Update() {
		counter++;
		if (counter == 60) {
			counter = 0;
			color = (color + 1) % 3;

			if (color == 0) {
				//Resources::GetMaterial("semRedMat")->diffuse = Vec3(1, 0, 0);
				Resources::GetMaterial("semRedMat")->emissionAlpha = 0.7f;

				//Resources::GetMaterial("semYellowMat")->diffuse = Vec3(0.1f, 0.1f, 0.1f);
				Resources::GetMaterial("semYellowMat")->emissionAlpha = 0.0f;

				//Resources::GetMaterial("semGreenMat")->diffuse = Vec3(0.1f, 0.1f, 0.1f);
				Resources::GetMaterial("semGreenMat")->emissionAlpha = 0.0f;
			}
			else if (color == 1) {
				//Resources::GetMaterial("semRedMat")->diffuse = Vec3(0.1f, 0.1f, 0.1f);
				Resources::GetMaterial("semRedMat")->emissionAlpha = 0.0f;

				//Resources::GetMaterial("semYellowMat")->diffuse = Vec3(1, 1, 0);
				Resources::GetMaterial("semYellowMat")->emissionAlpha = 0.7f;

				//Resources::GetMaterial("semGreenMat")->diffuse = Vec3(0.1f, 0.1f, 0.1f);
				Resources::GetMaterial("semGreenMat")->emissionAlpha = 0.0f;
			}
			else {
				//Resources::GetMaterial("semRedMat")->diffuse = Vec3(0.1f, 0.1f, 0.1f);
				Resources::GetMaterial("semRedMat")->emissionAlpha = 0.0f;

				//Resources::GetMaterial("semYellowMat")->diffuse = Vec3(0.1f, 0.1f, 0.1f);
				Resources::GetMaterial("semYellowMat")->emissionAlpha = 0.0f;

				//Resources::GetMaterial("semGreenMat")->diffuse = Vec3(0, 1, 0);
				Resources::GetMaterial("semGreenMat")->emissionAlpha = 0.7f;
			}
		}

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
	}

};

int main(char** args, int argc) {
	Euler::Application app(900, 900, "App test");
	MyScene scene;
	app.SetScene(&scene);
	app.Run();
	
	return 0;
}