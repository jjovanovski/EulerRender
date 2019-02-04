#include "FreeCamera.h"

using namespace Euler;
#include <iostream>
FreeCamera::FreeCamera(Camera * camera, float mouseSensitivityX, float mouseSensitivityY, float movementSpeed) : Component() {
	this->camera = camera;
	this->mouseSensitivityX = mouseSensitivityX;
	this->mouseSensitivityY = mouseSensitivityY;
	this->movementSpeed = movementSpeed;

	this->cameraRotX = 0;
	this->cameraRotY = 0;

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
	
	camera->SetRotation(Quaternion::Euler(cameraRotY * mouseSensitivityY, 0, 1, 0) * Quaternion::Euler(cameraRotX * mouseSensitivityX, 1, 0, 0));

	// keyboard movement
	Vec3 forwardDir = camera->Forward();
	Vec3 rightDir = camera->Right();
	if (Input::GetKey(Key::W)) {
		camera->SetPosition(camera->GetPosition() - Vec3(forwardDir.x * movementSpeed, forwardDir.y * movementSpeed, forwardDir.z * movementSpeed));
	} else if (Input::GetKey(Key::S)) {
		camera->SetPosition(camera->GetPosition() + Vec3(forwardDir.x * movementSpeed, forwardDir.y * movementSpeed, forwardDir.z * movementSpeed));
	}
	if (Input::GetKey(Key::A)) {
		camera->SetPosition(camera->GetPosition() - Vec3(rightDir.x * movementSpeed, rightDir.y * movementSpeed, rightDir.z * movementSpeed));
	} else if (Input::GetKey(Key::D)) {
		camera->SetPosition(camera->GetPosition() + Vec3(rightDir.x * movementSpeed, rightDir.y * movementSpeed, rightDir.z * movementSpeed));
	}
}