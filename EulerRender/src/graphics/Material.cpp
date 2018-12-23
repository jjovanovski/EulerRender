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

	if (texture != nullptr) {
		glActiveTexture(GL_TEXTURE0);
		texture->Bind();
		shader->SetInt("diffuseTex", 0);
		shader->SetInt("useTexture", 1);
	} else {
		shader->SetInt("useTexture", 0);
	}

	if (normalmap != nullptr) {
		glActiveTexture(GL_TEXTURE1);
		normalmap->Bind();
		shader->SetInt("normalTex", 1);
		shader->SetInt("useNormalMap", 1);
	} else {
		shader->SetInt("useNormalMap", 0);
	}

	shader->SetVec3("material.diffuse", diffuse.x, diffuse.y, diffuse.z);
	shader->SetVec3("material.specular", specular.x, specular.y, specular.z);
	shader->SetFloat("material.shininess", shininess);
}
