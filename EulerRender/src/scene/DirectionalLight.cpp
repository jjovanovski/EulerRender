#include "DirectionalLight.h"

using namespace Euler;

DirectionalLight::DirectionalLight(Vec3 direction, Vec3 color, float intensity) {
	this->direction = direction;
	this->color = color;
	this->intensity = intensity;
}

DirectionalLight::~DirectionalLight() {
}
