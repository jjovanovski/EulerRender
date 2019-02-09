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
		directionalLight->direction = Vec3(-0.5f, -0.5f, -.5f).Normalized();

		// set the camera position a little above the ground
		camera->SetPosition(Vec3(0, 0.2f, 3.0f));

		// create the scene
		addGround();
		addSemaphore();
		addMaterialSpheres();
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

		semaphore->SetPosition(4.0f, 0.5f, 0);
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

		delete diffuseSphere;
		delete specSphere;
		delete textureSphere;
		delete normalSphere;
	}

	void addGround() {
		Texture * groundDiffuse = Resources::GetTexture("groundDiffuse", "game/ground.jpg");
		Texture * groundNormal = Resources::GetTexture("groundNormal", "game/ground_normal.jpg");
		Texture * groundSpecular = Resources::GetTexture("groundSpecular", "game/ground_specular.jpg");

		Material * groundMaterial = Resources::GetMaterial("groundMaterial");
		groundMaterial->shader = Resources::GetShader("WorldShader");
		groundMaterial->texture = groundDiffuse;
		groundMaterial->normalmap = groundNormal;
		groundMaterial->specularmap = groundSpecular;
		groundMaterial->diffuseScale = Vec2(17, 17);
		groundMaterial->normalScale = Vec2(17, 17);
		groundMaterial->specScale = Vec2(17, 17);
		groundMaterial->diffuse = Vec3(0.3f, 0.3f, 0.3f);
		groundMaterial->specular = Vec3(1, 1, 1);
		groundMaterial->shininess = 128;

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

	WorldModel * diffuseSphere;
	WorldModel * specSphere;
	WorldModel * textureSphere;
	WorldModel * normalSphere;
	void addMaterialSpheres() {
		Material * diffuseMat = Resources::GetMaterial("diffuseMat");
		diffuseMat->shader = shader;
		diffuseMat->diffuse = Vec3(0.2f, 0.9f, 0.3f);
		diffuseMat->specular = Vec3(0, 0, 0);

		Material * specMat = Resources::GetMaterial("specMat");
		specMat->shader = shader;
		specMat->diffuse = Vec3(0.2f, 0.9f, 0.3f);
		specMat->specular = Vec3(1.0f, 1.0f, 1.0f);
		specMat->shininess = 64;

		Material * textureMat = Resources::GetMaterial("textureMat");
		textureMat->shader = shader;
		textureMat->texture = Resources::GetTexture("brickTexture", "brick_diffuse.jpg");

		Material * normalMapMat = Resources::GetMaterial("normalMapMat");
		normalMapMat->shader = shader;
		normalMapMat->texture = Resources::GetTexture("brickTexture", "brick_diffuse.jpg");
		normalMapMat->normalmap = Resources::GetTexture("brickNormalMap", "brick_normal.jpg");


		MeshMaterial * diffuseMM = Resources::GetMeshMaterial("diffuseMM");
		diffuseMM->material = diffuseMat;
		diffuseMM->mesh = sphereMesh;

		MeshMaterial * specMM = Resources::GetMeshMaterial("specMM");
		specMM->material = specMat;
		specMM->mesh = sphereMesh;

		MeshMaterial * textureMM = Resources::GetMeshMaterial("textureMM");
		textureMM->material = textureMat;
		textureMM->mesh = sphereMesh;

		MeshMaterial * normalMM = Resources::GetMeshMaterial("normalMM");
		normalMM->material = normalMapMat;
		normalMM->mesh = sphereMesh;

		Model * diffuseModel = Resources::GetModel("diffuseModel");
		diffuseModel->AddDrawable(diffuseMM);
		Model * specModel = Resources::GetModel("specModel");
		specModel->AddDrawable(specMM);
		Model * textureModel = Resources::GetModel("textureModel");
		textureModel->AddDrawable(textureMM);
		Model * normalModel = Resources::GetModel("normalModel");
		normalModel->AddDrawable(normalMM);

		diffuseSphere = new WorldModel();
		diffuseSphere->SetModel(diffuseModel);
		diffuseSphere->SetPosition(-2, 0.5f, 0);
		diffuseSphere->SetScale(Vec3(0.5f, 0.5f, 0.5f));
		this->AddChild(diffuseSphere);

		specSphere = new WorldModel();
		specSphere->SetModel(specModel);
		specSphere->SetPosition(-0.75f, 0.5f, 0);
		specSphere->SetScale(Vec3(0.5f, 0.5f, 0.5f));
		this->AddChild(specSphere);

		textureSphere = new WorldModel();
		textureSphere->SetModel(textureModel);
		textureSphere->SetPosition(0.75f, 0.5f, 0);
		textureSphere->SetScale(Vec3(0.5f, 0.5f, 0.5f));
		this->AddChild(textureSphere);

		normalSphere = new WorldModel();
		normalSphere->SetModel(normalModel);
		normalSphere->SetPosition(2.0f, 0.5f, 0);
		normalSphere->SetScale(Vec3(0.5f, 0.5f, 0.5f));
		this->AddChild(normalSphere);
	}

	int color = 0;	// 0 = red, 1 = yellow, 2 = green
	int counter = 0;
	float frameCounter = 0;
	bool transormationsActive = true;
	void Update() {
		counter++;
		if (counter == 60) {
			counter = 0;
			color = (color + 1) % 3;

			if (color == 0) {
				Resources::GetMaterial("semRedMat")->diffuse = Vec3(1, 0, 0);
				Resources::GetMaterial("semRedMat")->emissionAlpha = 0.7f;

				Resources::GetMaterial("semYellowMat")->diffuse = Vec3(0.1f, 0.1f, 0.1f);
				Resources::GetMaterial("semYellowMat")->emissionAlpha = 0.0f;

				Resources::GetMaterial("semGreenMat")->diffuse = Vec3(0.1f, 0.1f, 0.1f);
				Resources::GetMaterial("semGreenMat")->emissionAlpha = 0.0f;
			}
			else if (color == 1) {
				Resources::GetMaterial("semRedMat")->diffuse = Vec3(0.1f, 0.1f, 0.1f);
				Resources::GetMaterial("semRedMat")->emissionAlpha = 0.0f;

				Resources::GetMaterial("semYellowMat")->diffuse = Vec3(1, 1, 0);
				Resources::GetMaterial("semYellowMat")->emissionAlpha = 0.7f;

				Resources::GetMaterial("semGreenMat")->diffuse = Vec3(0.1f, 0.1f, 0.1f);
				Resources::GetMaterial("semGreenMat")->emissionAlpha = 0.0f;
			}
			else {
				Resources::GetMaterial("semRedMat")->diffuse = Vec3(0.1f, 0.1f, 0.1f);
				Resources::GetMaterial("semRedMat")->emissionAlpha = 0.0f;

				Resources::GetMaterial("semYellowMat")->diffuse = Vec3(0.1f, 0.1f, 0.1f);
				Resources::GetMaterial("semYellowMat")->emissionAlpha = 0.0f;

				Resources::GetMaterial("semGreenMat")->diffuse = Vec3(0, 1, 0);
				Resources::GetMaterial("semGreenMat")->emissionAlpha = 0.7f;
			}
		}

		if (Input::GetKeyUp(Key::SPACE)) {
			transormationsActive = !transormationsActive;
		}

		if (transormationsActive) {
			frameCounter += 0.01f;
			float scale = sin(frameCounter)*0.25f + 0.25f;
			diffuseSphere->SetPosition(diffuseSphere->GetX(), sin(frameCounter)*0.25f + 0.75f, 0);
			specSphere->SetScale(scale, scale, scale);
			textureSphere->SetRotation(Quaternion::Euler(frameCounter, 1, 1, 0));
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