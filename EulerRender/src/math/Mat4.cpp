#include "Mat4.h"

Mat4::Mat4() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			mat[i][j] = 0;
		}
	}
}

Mat4::Mat4(const Mat4& other) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			this->mat[i][j] = other.mat[i][j];
		}
	}
}

Mat4::~Mat4() {
}

float Mat4::Get(int i, int j) {
	return mat[i][j];
}

void Mat4::Set(int i, int j, float value) {
	mat[i][j] = value;
}

float* Mat4::GetPointer() {
	return mat[0];
}

Mat4 Mat4::operator*(const Mat4& right) {
	Mat4 product;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				product.mat[i][j] += this->mat[i][k] * right.mat[k][j];
			}
		}
	}

	return product;
}