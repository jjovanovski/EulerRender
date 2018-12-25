#include "Vec3.h"

using namespace Euler;

Vec3::Vec3(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Vec3::~Vec3() {
}

bool Euler::operator==(const Vec3& left, const Vec3& right) {
	return left.x == right.x && left.y == right.y && left.z == right.z;
}

bool Euler::operator!=(const Vec3& left, const Vec3& right) {
	return !(left == right);
}

Vec3 Euler::operator+(const Vec3& left, const Vec3& right) {
	Vec3 result = left;
	result += right;
	return result;
}

Vec3 Euler::operator-(const Vec3& left, const Vec3& right) {
	Vec3 result = left;
	result -= right;
	return result;
}

Vec3 Euler::operator*(const Vec3& left, const Vec3& right) {
	Vec3 result = left;
	result *= right;
	return result;
}

Vec3 Euler::operator/(const Vec3& left, const Vec3& right) {
	Vec3 result = left;
	result /= right;
	return result;
}

Vec3& Vec3::operator+=(const Vec3& right) {
	this->x += right.x;
	this->y += right.y;
	this->z += right.z;
	return *this;
}

Vec3& Vec3::operator-=(const Vec3& right) {
	this->x -= right.x;
	this->y -= right.y;
	this->z -= right.z;
	return *this;
}

Vec3& Vec3::operator*=(const Vec3& right) {
	this->x *= right.x;
	this->y *= right.y;
	this->z *= right.z;
	return *this;
}

Vec3& Vec3::operator/=(const Vec3& right) {
	this->x /= right.x;
	this->y /= right.y;
	this->z /= right.z;
	return *this;
}

float Vec3::Dot(const Vec3& right) {
	return x * right.x + y * right.y + z * right.z;
}

float Vec3::Len() {
	return sqrt(this->Len2());
}

float Vec3::Len2() {
	return x * x + y * y + z * z;
}

void Vec3::Normalize() {
	float len = this->Len();
	this->x /= len;
	this->y /= len;
	this->z /= len;
}

Vec3 Vec3::Normalized() {
	Vec3 normalized = *this;
	normalized.Normalize();
	return normalized;
}