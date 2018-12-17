#include "Transformation.h"

#include "Quaternion.h"

using namespace Euler;

Transformation::Transformation() {
}


Transformation::~Transformation() {
}

Mat4 Transformation::Identity() {
	Mat4 identity;
	identity.mat[0][0] = 1;
	identity.mat[1][1] = 1;
	identity.mat[2][2] = 1;
	identity.mat[3][3] = 1;

	return identity;
}

Mat4 Transformation::Translate(float x, float y, float z) {
	Mat4 translate = Identity();
	translate.mat[0][3] = x;
	translate.mat[1][3] = y;
	translate.mat[2][3] = z;
	translate.mat[3][3] = 1;

	return translate;
}

Mat4 Transformation::Scale(float x, float y, float z) {
	Mat4 identity;
	identity.mat[0][0] = x;
	identity.mat[1][1] = y;
	identity.mat[2][2] = z;
	identity.mat[3][3] = 1;

	return identity;
}

Mat4 Transformation::Rotate(float angle, float x, float y, float z) {
	return Quaternion::Euler(angle, x, y, z).GetMatrix();
}

Mat4 Transformation::Perspective() {
	Mat4 perspective;
	
	float PI = 3.14f;
	float fov = 45.0f;

	float n = 0.1f;
	float f = 10.0f;
	float t = n * tan((PI / 180.0f) * fov / 2.0f);
	float b = -t;
	float r = t * 1.0f;
	float l = -r;

	perspective.mat[0][0] = (2*n)/(r-l);
	perspective.mat[1][1] = (2 * n) / (t - b);
	perspective.mat[2][2] = -(f + n) / (f - n);
	perspective.mat[3][2] = -1;
	perspective.mat[2][3] = -(2 * f*n) / (f - n);
	perspective.mat[0][2] = (r + l) / (r - l);
	perspective.mat[1][2] = (t + b) / (t - b);


	return perspective;
}