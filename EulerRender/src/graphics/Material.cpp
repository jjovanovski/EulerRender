#include "Material.h"

using namespace Euler;

Material::Material(Vec3 diffuse, Vec3 specular, float shininess) {
	this->diffuse = diffuse;
	this->specular = specular;
	this->shininess = shininess;

	diffuseScale.x = 1;
	diffuseScale.y = 1;

	normalScale.x = 1;
	normalScale.y = 1;

	specScale.x = 1;
	specScale.y = 1;
}

Material::~Material() {
	Dispose();
}

void Material::Dispose() {
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

	if (specularmap != nullptr) {
		glActiveTexture(GL_TEXTURE2);
		specularmap->Bind();
		shader->SetInt("specTex", 2);
		shader->SetInt("useSpecMap", 1);
	} else {
		shader->SetInt("useSpecMap", 0);
	}

	shader->SetVec3("material.diffuse", diffuse.x, diffuse.y, diffuse.z);
	shader->SetVec3("material.specular", specular.x, specular.y, specular.z);
	shader->SetVec3("material.emission", emission.x, emission.y, emission.z);
	shader->SetFloat("material.shininess", shininess);
	shader->SetFloat("material.emissionAlpha", emissionAlpha);

	shader->SetVec2("diffuseScale", diffuseScale.x, diffuseScale.y);
	shader->SetVec2("normalScale", normalScale.x, normalScale.y);
	shader->SetVec2("specScale", specScale.x, specScale.y);
}
