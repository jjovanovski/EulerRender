#include "Component.h"

using namespace Euler;

Component::Component() {
	position.x = 0;
	position.y = 0;
	position.z = 0;
	
	scale.x = 1;
	scale.y = 1;
	scale.z = 1;
}

Component::~Component() {
}

void Component::UpdateComponent() {
	this->Update();

	for (int i = 0; i < children.size(); i++) {
		children[i]->UpdateComponent();
	}
}

void Component::DrawComponent() {
	this->Draw();

	for (int i = 0; i < children.size(); i++) {
		children[i]->DrawComponent();
	}
}

void Component::AddChild(Component * component) {
	if (component != nullptr && component != NULL) {
		children.push_back(component);
	}
}