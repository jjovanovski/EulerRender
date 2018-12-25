#include "Quaternion.h"

#include <cmath>

using namespace Euler;

Quaternion::Quaternion(float w, float x, float y, float z) {
	this->w = w;
	this->x = x;
	this->y = y;
	this->z = z;
}

Quaternion::~Quaternion() {
}

Quaternion Euler::operator*(const Quaternion & left, const Quaternion & right) {
	float rw = left.w * right.w - left.x * right.x - left.y * right.y - left.z * right.z;
	float rx = left.x * right.w + left.w * right.x + left.y * right.z - left.z * right.y;
	float ry = left.y * right.w + left.w * right.y + left.z * right.x - left.x * right.z;
	float rz = left.z * right.w + left.w * right.z + left.x * right.y - left.y * right.x;

	return Quaternion(rw, rx, ry, rz);
}

/*Quaternion Euler::operator*(const Quaternion & left, const Vec3 & right) {
	float rw = -left.x * right.x - left.y * right.y - left.z * right.z;
	float rx = left.w * right.x + left.y * right.z - left.z * right.y;
	float ry = left.w * right.y + left.z * right.x - left.x * right.z;
	float rz = left.w * right.z + left.x * right.y - left.y * right.x;

	return Quaternion(rw, rx, ry, rz);
}*/

Vec3 Euler::operator*(const Quaternion& left, const Vec3& right) {
	Mat4 rot = left.GetMatrix();
	Vec3 rotated;
	rotated.x = rot.mat[0][0] * right.x + rot.mat[0][1] * right.y + rot.mat[0][2] * right.z;
	rotated.y = rot.mat[1][0] * right.x + rot.mat[1][1] * right.y + rot.mat[1][2] * right.z;
	rotated.z = rot.mat[2][0] * right.x + rot.mat[2][1] * right.y + rot.mat[2][2] * right.z;

	return rotated.Normalized();
}

float Quaternion::Len() {
	return sqrt(Len2());
}

float Quaternion::Len2() {
	return w * w + x * x + y * y + z * z;
}

void Quaternion::Normalize() {
	float len = Len();
	w /= len;
	x /= len;
	y /= len;
	z /= len;
}

Quaternion Quaternion::Normalized() {
	Quaternion q = *this;
	q.Normalize();
	return q;
}

Quaternion Quaternion::Conjugate() {
	Quaternion q(w, -x, -y, -z);
	return q;
}

void Quaternion::SetEuler(float angle, float x, float y, float z) {
	float len = sqrt(x*x + y * y + z * z);
	x /= len;
	y /= len;
	z /= len;

	float sinHalfAngle = sin(angle / 2.0f);
	float cosHalfAngle = cos(angle / 2.0f);

	this->w = cosHalfAngle;
	this->x = x * sinHalfAngle;
	this->y = y * sinHalfAngle;
	this->z = z * sinHalfAngle;
}

Quaternion Euler::Quaternion::Euler(float angle, float x, float y, float z) {
	Quaternion q;
	q.SetEuler(angle, x, y, z);
	return q;
}

Mat4 Quaternion::GetMatrix() const {
	Mat4 qmat;

	qmat.mat[0][0] = 1.0f - 2.0f * (y * y + z * z);			qmat.mat[0][1] = 2.0f * (x * y - z * w);			qmat.mat[0][2] = 2.0f * (x * z + y * w);
	qmat.mat[1][0] = 2.0f * (x * y + z * w);				qmat.mat[1][1] = 1.0f - 2.0f * (x * x + z * z);		qmat.mat[1][2] = 2.0f * (y * z - x * w);
	qmat.mat[2][0] = 2.0f * (x * z - y * w);				qmat.mat[2][1] = 2.0f * (y * z + x * w);			qmat.mat[2][2] = 1.0f - 2.0f * (x * x + y * y);

	qmat.mat[3][3] = 1;

	return qmat;
}
