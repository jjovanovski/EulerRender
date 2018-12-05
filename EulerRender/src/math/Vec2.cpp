#include "Vec2.h"

using namespace Euler;

Vec2::Vec2(float x, float y) {
	this->x = x;
	this->y = y;
}

Vec2::~Vec2() {
}

bool Euler::operator==(const Vec2& left, const Vec2& right) {
	return left.x == right.x && left.y == right.y;
}

bool Euler::operator!=(const Vec2& left, const Vec2& right) {
	return !(left == right);
}

Vec2& Euler::operator+(const Vec2& left, const Vec2& right) {
	Vec2 result = left;
	result += right;
	return result;
}

Vec2& Euler::operator-(const Vec2& left, const Vec2& right) {
	Vec2 result = left;
	result -= right;
	return result;
}

Vec2& Euler::operator*(const Vec2& left, const Vec2& right) {
	Vec2 result = left;
	result *= right;
	return result;
}

Vec2& Euler::operator/(const Vec2& left, const Vec2& right) {
	Vec2 result = left;
	result /= right;
	return result;
}

Vec2& Vec2::operator+=(const Vec2& right) {
	this->x += right.x;
	this->y += right.y;
	return *this;
}

Vec2& Vec2::operator-=(const Vec2& right) {
	this->x -= right.x;
	this->y -= right.y;
	return *this;
}

Vec2& Vec2::operator*=(const Vec2& right) {
	this->x *= right.x;
	this->y *= right.y;
	return *this;
}

Vec2& Vec2::operator/=(const Vec2& right) {
	this->x /= right.x;
	this->y /= right.y;
	return *this;
}

float Vec2::Dot(const Vec2& right) {
	return x * right.x + y * right.y;
}

float Vec2::Len() {
	return sqrt(this->Len2());
}

float Vec2::Len2() {
	return x * x + y * y;
}

void Vec2::Normalize() {
	float len = this->Len();
	this->x /= len;
	this->y /= len;
}

Vec2 Vec2::Normalized() {
	Vec2 normalized = *this;
	normalized.Normalize();
	return normalized;
}