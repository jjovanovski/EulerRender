#pragma once

#include "../API.h"

namespace Euler {

	class EULER_API Mat4 {
	public:
		float mat[4][4];

		Mat4();
		Mat4(const Mat4& other);
		~Mat4();

		float Get(int i, int j);
		void Set(int i, int j, float value);

		float* GetPointer();

		Mat4 operator*(const Mat4& right);

	};

}
