#include "MeshMaterial.h"

using namespace Euler;

MeshMaterial::MeshMaterial() {

}

MeshMaterial::MeshMaterial(Mesh * mesh, Material * material) {
	this->mesh = mesh;
	this->material = material;
}

MeshMaterial::~MeshMaterial() {
	Dispose();
}

void MeshMaterial::Dispose() {

}