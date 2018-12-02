#include "Model.h"

using namespace Euler;

Model::Model() {
	mesh = nullptr;
	
	posx = 0;
	posy = 0;
	posz = 0;

	scalex = 1;
	scaley = 1;
	scalez = 1;

	rotx = 0;
	roty = 0;
	rotz = 0;
}

Model::~Model() {
}

Mat4 Model::GetModelMatrix() {
	return Transformation::Translate(posx, posy, posz) 
		* Transformation::Rotate(rotx, 1, 0, 0) * Transformation::Rotate(roty, 0, 1, 0) * Transformation::Rotate(rotz, 0, 0, 1)
		* Transformation::Scale(scalex, scaley, scalez) 
		* Transformation::Identity();
}