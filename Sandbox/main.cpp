#include <iostream>
#include <cmath>

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
	float time = 0;

	WorldModel * ground;

	MyScene() {
		Input::HideCursor();

		// set-up the skybox
		skybox = Resources::GetSkybox("sunset", {"sunset/xp.png", "sunset/xn.png", "sunset/yp.png", "sunset/yn.png", "sunset/zp.png", "sunset/zn.png"});

		// create plane mesh that can be shader between any objects
		planeMesh = new Euler::Plane();

		// add the free move camera as component
		freeCam = new FreeCamera(camera);
		this->AddChild(freeCam);

		// create the scene
		addGround();

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

	~MyScene() {
		delete planeMesh;
		delete ground;
	}

	void addGround() {
		Texture * groundDiffuse = Resources::GetTexture("groundDiffuse", "game/ground.jpg");
		Texture * groundNormal = Resources::GetTexture("groundNormal", "game/ground_normal.jpg");

		Material * groundMaterial = Resources::GetMaterial("groundMaterial");
		groundMaterial->shader = Resources::GetShader("WorldShader");
		groundMaterial->texture = groundDiffuse;
		groundMaterial->normalmap = groundNormal;
		groundMaterial->diffuseScale = Vec2(16, 16);
		groundMaterial->normalScale = Vec2(16, 16);
		groundMaterial->diffuse = Vec3(0.4f, 0.4f, 0.4f);
		groundMaterial->specular = Vec3(0.4f, 0.4f, 0.4f);
		groundMaterial->shininess = 10.0f;

		MeshMaterial * groundMeshMaterial = Resources::GetMeshMaterial("groundMeshMaterial");
		groundMeshMaterial->mesh = planeMesh;
		groundMeshMaterial->material = groundMaterial;

		Model * groundModel = Resources::GetModel("ground");
		groundModel->AddDrawable(groundMeshMaterial);

		ground = new WorldModel();
		ground->SetModel(groundModel);
		ground->scale = Vec3(50, 50, 50);
		ground->rotation = Quaternion::Euler(-90 * DEG_RAD, 1, 0, 0);
		AddChild(ground);
	}

	void Update() {
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