#pragma once

#include "../API.h"

#include "Vec3.h"
#include "Mat4.h"

namespace Euler {

	class EULER_API Quaternion {
	public:
		float w, x, y, z;

	public:
		Quaternion(float w = 1, float x = 0, float y = 0, float z = 0);
		~Quaternion();

		friend EULER_API Quaternion operator*(const Quaternion& left, const Quaternion& right);
		friend EULER_API Quaternion operator*(const Quaternion& left, const Vec3& right);

		float Len();
		float Len2();
		void Normalize();
		Quaternion Normalized();
		Quaternion Conjugate();

		void SetEuler(float angle, float x, float y, float z);
		static Quaternion Euler(float angle, float x, float y, float z);
		Mat4 GetMatrix();
	};

}
