#include "Resources.h"
#include <iostream>
using namespace Euler;

// declaration of static maps
std::map<std::string, Shader*> Resources::shaders;
std::map<std::string, Mesh*> Resources::meshes;
std::map<std::string, Texture*> Resources::textures;
std::map<std::string, Material*> Resources::materials;
std::map<std::string, MeshMaterial*> Resources::meshMaterials;
std::map<std::string, Model*> Resources::models;

Resources::Resources() {
}

Resources::~Resources() {
}

void Euler::Resources::Init() {

}

void Euler::Resources::Dispose() {
	// dispose shaders
	for (auto const& res : shaders) {
		delete res.second;
	}

	// dispose meshes
	for (auto const& res : meshes) {
		delete res.second;
	}

	// dispose textures
	for (auto const& res : textures) {
		delete res.second;
	}

	// dispose materials
	for (auto const& res : materials) {
		delete res.second;
	}

	// dispose meshMaterials
	for (auto const& res : meshMaterials) {
		delete res.second;
	}

	// dispose models
	for (auto const& res : models) {
		delete res.second;
	}
}

Shader * Euler::Resources::GetShader(std::string name, const char * vertexShaderSource, const char * fragmentShaderSource) {
	if (shaders.find(name) != shaders.end())
		return shaders[name];

	Shader * shader = new Shader(vertexShaderSource, fragmentShaderSource);
	shaders[name] = shader;
	return shader;
}

Mesh * Euler::Resources::GetMesh(std::string name) {
	Mesh * mesh = new Mesh();
	meshes[name] = mesh;
	return mesh;
}

Texture* Euler::Resources::GetTexture(std::string name, std::string path) {
	if (textures.find(name) != textures.end())
		return textures[name];

	const char* pathc = path.c_str();
	Texture * texture = new Texture(pathc);
	textures[name] = texture;
	return texture;
}

Material * Euler::Resources::GetMaterial(std::string name) {
	Material * material = new Material();
	materials[name] = material;
	return material;
}

MeshMaterial * Euler::Resources::GetMeshMaterial(std::string name) {
	MeshMaterial * meshMaterial = new MeshMaterial();
	meshMaterials[name] = meshMaterial;
	return meshMaterial;
}

Model * Euler::Resources::GetModel(std::string name) {
	Model * model = new Model();
	models[name] = model;
	return model;
}

Model * Euler::Resources::GetModel(std::string name, std::string file) {
	Assimp::Importer importer;
	const aiScene * scene = importer.ReadFile(file, aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_GenNormals | aiProcess_CalcTangentSpace);
	
	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
		return nullptr;
	}

	Model * model = GetModel(name);
	
	assimp_ProcessNode(name, file.substr(0, file.find_last_of('/')), scene->mRootNode, scene, model);
	
	return model;
}

void Euler::Resources::assimp_ProcessNode(std::string name, std::string dir, aiNode * node, const aiScene * scene, Model * model) {
	for (int i = 0; i < node->mNumMeshes; i++) {
		aiMesh * mesh = scene->mMeshes[node->mMeshes[i]];
		model->AddDrawable(assimp_ProcessMesh(name + "_mesh_" + std::to_string(i), dir, mesh, scene, model));
	}

	// recurse
	for (int i = 0; i < node->mNumChildren; i++) {
		assimp_ProcessNode(name, dir, node->mChildren[i], scene, model);
	}
}

MeshMaterial * Euler::Resources::assimp_ProcessMesh(std::string name, std::string dir, aiMesh * aiMesh, const aiScene * aiScene, Model * model) {
	Mesh * mesh = Resources::GetMesh(name);
	Material * material = Resources::GetMaterial(name + "_material");
	material->shader = GetShader("WorldShader", nullptr, nullptr);

	// process vertices
	for (int i = 0; i < aiMesh->mNumVertices; i++) {
		Vertex vertex;
		vertex.position = Vec3(aiMesh->mVertices[i].x, aiMesh->mVertices[i].y, aiMesh->mVertices[i].z);
		vertex.normal = Vec3(aiMesh->mNormals[i].x, aiMesh->mNormals[i].y, aiMesh->mNormals[i].z);
		vertex.tangent = Vec3(aiMesh->mTangents[i].x, aiMesh->mTangents[i].y, aiMesh->mTangents[i].z);

		if (aiMesh->mTextureCoords[0]) {
			vertex.uv = Vec2(aiMesh->mTextureCoords[0][i].x, aiMesh->mTextureCoords[0][i].y);
		}

		mesh->vertices.push_back(vertex);
	}

	// process indices
	for (int i = 0; i < aiMesh->mNumFaces; i++) {
		aiFace face = aiMesh->mFaces[i];
		for (int j = 0; j < face.mNumIndices; j++) {
			mesh->indices.push_back(face.mIndices[j]);
		}
	}

	// process material
	if (aiMesh->mMaterialIndex >= 0) {
		aiMaterial * aiMaterial = aiScene->mMaterials[aiMesh->mMaterialIndex];

		// diffuse
		aiString diffuseStr;
		aiMaterial->GetTexture(aiTextureType_DIFFUSE, 0, &diffuseStr);
		std::string diffusePath = dir + "/" + diffuseStr.C_Str();
		Texture * texture = Resources::GetTexture(diffusePath, diffusePath);
		material->texture = texture;

		// normal
		aiString normalStr;
		aiMaterial->GetTexture(aiTextureType_HEIGHT, 0, &normalStr);
		std::string normalPath = dir + "/" + normalStr.C_Str();
		Texture * normal = Resources::GetTexture(normalPath, normalPath);
		material->normalmap = normal;
	}

	mesh->Upload();

	MeshMaterial * meshMaterial = Resources::GetMeshMaterial(name + "_meshMaterial");
	meshMaterial->mesh = mesh;
	meshMaterial->material = material;
	return meshMaterial;
}
