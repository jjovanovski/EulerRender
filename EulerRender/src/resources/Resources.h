#pragma once

#include "../API.h"

#include <string>
#include <map>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "../graphics/Shader.h"
#include "../graphics/Texture.h"
#include "../graphics/Material.h"
#include "../graphics/Mesh.h"
#include "../graphics/MeshMaterial.h"
#include "../graphics/Model.h"
#include "../graphics/Vertex.h"
#include "../graphics/Skybox.h"
#include "../math/Vec2.h"
#include "../math/Vec3.h"

namespace Euler {

	class EULER_API Resources {
	private:
		static std::map<std::string, Shader*> shaders;
		static std::map<std::string, Mesh*> meshes;
		static std::map<std::string, Texture*> textures;
		static std::map<std::string, Material*> materials;
		static std::map<std::string, MeshMaterial*> meshMaterials;
		static std::map<std::string, Model*> models;
		static std::map<std::string, Skybox*> skyboxes;

		// helper function, decouple this code in the future
		static void assimp_ProcessNode(std::string name, std::string dir, aiNode * node, const aiScene * scene, Model * model);
		static MeshMaterial* assimp_ProcessMesh(std::string name, std::string dir, aiMesh * mesh, const aiScene * scene, Model * model);

	public:
		Resources();
		~Resources();

		static void Init();
		static void Dispose();

		static Shader * GetShader(std::string name, const char* vertexShaderSource, const char* fragmentShaderSource);

		static Mesh * GetMesh(std::string name);

		static Texture * GetTexture(std::string name, std::string file);

		static Material * GetMaterial(std::string name);
		
		static MeshMaterial * GetMeshMaterial(std::string name);

		static Model * GetModel(std::string name);
		static Model * GetModel(std::string name, std::string file);

		static Skybox * GetSkybox(std::string name, std::vector<std::string> textures);
	};

}
