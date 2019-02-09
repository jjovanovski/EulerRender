#pragma once

#include "../API.h"
#include "../resources/Disposable.h"
#include "../graphics/Mesh.h"

#include <glad/glad.h>
#include <vector>
#include <string>

namespace Euler {

	class EULER_API Skybox : public Disposable {
	private:
		unsigned int id;
		Mesh * skyboxMesh;

	public:
		Skybox(std::vector<std::string> textures);
		~Skybox();

		void Draw();
		void Dispose();
	};

}
