#pragma once

#include "../API.h"

namespace Euler {

	class EULER_API Disposable {

	public:
		virtual void Dispose() = 0;

	};

}