#include "FreeCamera.h"

using namespace Euler;

FreeCamera::FreeCamera(Camera * camera, float mouseSensitivityX, float mouseSensitivityY, float movementSpeed) : Component() {
	this->camera = camera;
	this->mouseSensitivityX = mouseSensitivityX;
	this->mouseSensitivityY = mouseSensitivityY;
	this->movementSpeed = movementSpeed;

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
	
	camera->rotation = Quaternion::Euler(cameraRotY * mouseSensitivityY, 0, 1, 0) * Quaternion::Euler(cameraRotX * mouseSensitivityX, 1, 0, 0);

	// keyboard movement
	Vec3 forwardDir = camera->Forward();
	Vec3 rightDir = camera->Right();
	if (Input::GetKey(Key::W)) {
		camera->position -= Vec3(forwardDir.x * movementSpeed, forwardDir.y * movementSpeed, forwardDir.z * movementSpeed);
	} else if (Input::GetKey(Key::S)) {
		camera->position += Vec3(forwardDir.x * movementSpeed, forwardDir.y * movementSpeed, forwardDir.z * movementSpeed);
	}
	if (Input::GetKey(Key::A)) {
		camera->position -= Vec3(rightDir.x * movementSpeed, rightDir.y * movementSpeed, rightDir.z * movementSpeed);
	} else if (Input::GetKey(Key::D)) {
		camera->position += Vec3(rightDir.x * movementSpeed, rightDir.y * movementSpeed, rightDir.z * movementSpeed);
	}
}