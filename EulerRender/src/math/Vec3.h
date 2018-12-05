#pragma once

#include "../API.h"

#include <cmath>

namespace Euler {

	class EULER_API Vec3 {
	public:
		float x, y, z;

		Vec3(float x = 0, float y = 0, float z = 0);
		~Vec3();

		friend bool operator==(const Vec3& left, const Vec3& right);
		friend bool operator!=(const Vec3& left, const Vec3& right);

		friend Vec3& operator+(const Vec3& left, const Vec3& right);
		friend Vec3& operator-(const Vec3& left, const Vec3& right);
		friend Vec3& operator*(const Vec3& left, const Vec3& right);
		friend Vec3& operator/(const Vec3& left, const Vec3& right);

		Vec3& operator+=(const Vec3& right);
		Vec3& operator-=(const Vec3& right);
		Vec3& operator*=(const Vec3& right);
		Vec3& operator/=(const Vec3& right);

		float Dot(const Vec3& right);

		float Len();
		float Len2();

		void Normalize();
		Vec3 Normalized();
	};

}
