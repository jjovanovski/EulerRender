#include "FreeCamera.h"

using namespace Euler;

FreeCamera::FreeCamera(Camera * camera) : Component() {
	this->camera = camera;

	Input::HideCursor();
}

FreeCamera::~FreeCamera() {
}

void FreeCamera::Update() {
	// mouse movement
	float mouseDeltaX = mouseX - Input::GetMouseX();
	float mouseDeltaY = mouseY - Input::GetMouseY();

	mouseX = Input::GetMouseX();
	mouseY = Input::GetMouseY();

	cameraRotX += mouseDeltaY;
	cameraRotY += mouseDeltaX;
	
	camera->rotation = Quaternion::Euler(cameraRotY * 0.005f, 0, 1, 0) * Quaternion::Euler(cameraRotX * 0.002f, 1, 0, 0);

	// keyboard movement
	float camspeed = 0.1f;
	Vec3 forwardDir = camera->Forward();
	Vec3 rightDir = camera->Right();
	if (Input::GetKey(Key::W)) {
		camera->position -= Vec3(forwardDir.x * camspeed, forwardDir.y * camspeed, forwardDir.z * camspeed);
	} else if (Input::GetKey(Key::S)) {
		camera->position += Vec3(forwardDir.x * camspeed, forwardDir.y * camspeed, forwardDir.z * camspeed);
	}
	if (Input::GetKey(Key::A)) {
		camera->position -= Vec3(rightDir.x * camspeed, rightDir.y * camspeed, rightDir.z * camspeed);
	} else if (Input::GetKey(Key::D)) {
		camera->position += Vec3(rightDir.x * camspeed, rightDir.y * camspeed, rightDir.z * camspeed);
	}
}