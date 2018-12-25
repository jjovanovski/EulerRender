#include "Input.h"

using namespace Euler;

InputHandler* Euler::Input::handler = nullptr;

Input::Input() {
}

Input::~Input() {
}

void Euler::Input::Init(InputHandler * inputHandler) {
	handler = inputHandler;

	if(handler != nullptr)
		handler->Init();
}

void Euler::Input::Dispose() {
	if (handler != nullptr) {
		handler->Dispose();
		delete handler;
		handler = nullptr;
	}
}

Vec2 Euler::Input::GetMousePos() {
	return Vec2(handler->GetMouseX(), handler->GetMouseY());
}

float Euler::Input::GetMouseX() {
	return handler->GetMouseX();
}

float Euler::Input::GetMouseY() {
	return handler->GetMouseY();
}

void Euler::Input::HideCursor() {
	handler->HideCursor();
}

bool Euler::Input::GetKey(Key key) {
	return handler->GetKey(key);
}

bool Euler::Input::GetKeyDown(Key key) {
	return handler->GetKeyDown(key);
}

bool Euler::Input::GetKeyUp(Key key) {
	return handler->GetKeyUp(key);
}