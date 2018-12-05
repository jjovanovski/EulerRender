#pragma once

#include "../API.h"\

#include <cmath>

namespace Euler {

	class EULER_API Vec2 {
	public:
		float x, y;

		Vec2(float x = 0, float y = 0);
		~Vec2();

		friend bool operator==(const Vec2& left, const Vec2& right);
		friend bool operator!=(const Vec2& left, const Vec2& right);

		friend Vec2& operator+(const Vec2& left, const Vec2& right);
		friend Vec2& operator-(const Vec2& left, const Vec2& right);
		friend Vec2& operator*(const Vec2& left, const Vec2& right);
		friend Vec2& operator/(const Vec2& left, const Vec2& right);

		Vec2& operator+=(const Vec2& right);
		Vec2& operator-=(const Vec2& right);
		Vec2& operator*=(const Vec2& right);
		Vec2& operator/=(const Vec2& right);

		float Dot(const Vec2& right);

		float Len();
		float Len2();

		void Normalize();
		Vec2 Normalized();
	};

}
