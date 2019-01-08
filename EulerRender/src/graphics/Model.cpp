#include "Model.h"

using namespace Euler;

Model::Model() {
}

Model::~Model() {
	Dispose();
}

void Euler::Model::Dispose() {
}

void Model::AddDrawable(MeshMaterial* drawable) {
	drawables.push_back(drawable);
}

/*void Model::AddDrawable(Mesh * mesh, Material * material) {

}*/
