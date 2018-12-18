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
		shader->SetFloat("useTexture", 1.0f);
	} else {
		shader->SetFloat("useTexture", 0.0f);
	}

	if (normalmap != nullptr) {
		glActiveTexture(GL_TEXTURE1);
		normalmap->Bind();
		shader->SetInt("normalTex", 1);
		shader->SetFloat("useNormalMap", 1.0f);
	} else {
		shader->SetFloat("useNormalMap", 0.0f);
	}

	shader->SetVec3("material.diffuse", diffuse.x, diffuse.y, diffuse.z);
	shader->SetVec3("material.specular", specular.x, specular.y, specular.z);
	shader->SetFloat("material.shininess", shininess);
}
