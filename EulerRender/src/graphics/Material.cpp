#include "Material.h"

using namespace Euler;

Material::Material(Vec3 diffuse, Vec3 specular, float shininess) {
	this->diffuse = diffuse;
	this->specular = specular;
	this->shininess = shininess;
}

Material::~Material() {
}

void Material::SetupShader() {
	shader->Use();

	shader->SetVec3("material.diffuse", diffuse.x, diffuse.y, diffuse.z);
	shader->SetVec3("material.specular", specular.x, specular.y, specular.z);
	shader->SetFloat("material.shininess", shininess);
}
