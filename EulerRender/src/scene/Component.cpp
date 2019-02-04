#include "Component.h"

using namespace Euler;

Component::Component() {
	position.x = 0;
	position.y = 0;
	position.z = 0;
	
	scale.x = 1;
	scale.y = 1;
	scale.z = 1;

	worldPosition = position;
	worldScale = scale;
	worldRotation = rotation;

	modelMatrix = Transformation::Identity();
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
		component->parent = this;

		// update child's world coordinates
		component->SetPosition(component->worldPosition - worldPosition);
		component->SetScale(component->worldScale.x / worldScale.x, component->worldScale.y / worldScale.y, component->worldScale.z / worldScale.z);
		// TODO: update rotation
	}
}

Vec3 Component::Forward() {
	return (rotation * Vec3(0, 0, 1)).Normalized();
}

Vec3 Component::Right() {
	return (rotation * Vec3(1, 0, 0)).Normalized();
}

Vec3 Component::Up() {
	return (rotation * Vec3(0, 1, 0)).Normalized();
}

Mat4 Component::GetModelMatrix() {
	return modelMatrix;
}

void Component::UpdateModelMatrix() {
	modelMatrix = Transformation::Translate(worldPosition.x, worldPosition.y, worldPosition.z)
		* rotation.GetMatrix()
		* Transformation::Scale(worldScale.x, worldScale.y, worldScale.z);
}

void Component::UpdateWorldPosition() {
	// update self's world position depending on the parent
	if (parent != nullptr) {
		this->worldPosition = parent->worldPosition + this->position;
	}
	else {
		this->worldPosition = this->position;
	}

	UpdateModelMatrix();

	// update children positions
	for (int i = 0; i < children.size(); i++) {
		children[i]->UpdateWorldPosition();
	}
}

void Component::UpdateWorldRotation() {
	if (parent != nullptr) {
		this->worldRotation = this->rotation * parent->worldRotation;
	}
	else {
		this->worldRotation = this->rotation;
	}

	UpdateModelMatrix();

	for (int i = 0; i < children.size(); i++) {
		children[i]->UpdateWorldRotation();
	}
}

void Component::UpdateWorldScale(Vec3 origin) {
	// update self' world scale depending on the parent
	if (parent != nullptr) {
		Vec3 newWorldScale = Vec3(parent->worldScale.x * this->scale.x, parent->worldScale.y * this->scale.y, parent->worldScale.z * this->scale.z);

		Vec3 worldPositionOffset = worldPosition - origin;
		worldPositionOffset.x *= (newWorldScale.x / worldScale.x);
		worldPositionOffset.y *= (newWorldScale.y / worldScale.y);
		worldPositionOffset.z *= (newWorldScale.z / worldScale.z);
		worldPositionOffset = worldPositionOffset + origin;

		worldPositionOffset = worldPositionOffset - parent->worldPosition;

		SetPosition(worldPositionOffset);

		this->worldScale = newWorldScale;
	}
	else {
		this->worldScale = scale;
	}
	
	UpdateModelMatrix();

	// update children scales
	for (int i = 0; i < children.size(); i++) {
		children[i]->UpdateWorldScale(origin);
	}
}
