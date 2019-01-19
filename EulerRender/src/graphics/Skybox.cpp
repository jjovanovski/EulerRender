#include "Skybox.h"

#include <iostream>
using namespace Euler;

Skybox::Skybox(std::vector<std::string> textures) {
	// create texture
	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_CUBE_MAP, id);

	int width, height, channels;
	for (int i = 0; i < textures.size(); i++) {
		unsigned char* data = stbi_load(textures[i].c_str(), &width, &height, &channels, 0);
		if (data) {
			if (channels == 4) {
				glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			} else {
				glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			}
		}

		stbi_image_free(data);
	}

	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	skyboxMesh = new Mesh();
	int rings = 30;
	int sectors = 30;
	float d_theta = 180.0f / rings;
	float d_phi = 360.0f / sectors;
	float theta = -90.0f;
	float phi = 0.0f;

	float PI = 3.141592f;
	float DEG = PI / 180.0f;

	float x, y, z;
	for (int i = 0; i <= rings; i++) {
		phi = 0.0f;
		for (int j = 0; j < sectors; j++) {
			float x = cos(theta*DEG)*cos(phi*DEG);
			float y = cos(theta*DEG)*sin(phi*DEG);
			float z = sin(theta*DEG);

			float u = atan2(x, z) / (2.0 * PI) + 0.5f;
			float v = y * 0.5f + 0.5f;

			float normalLen = x * x + y * y + z * z;
			float dot = y;
			float tx = 0 - x * (dot / normalLen);
			float ty = 1 - y * (dot / normalLen);
			float tz = 0 - z * (dot / normalLen);

			skyboxMesh->vertices.push_back(Vertex(x, y, z, x, y, z, 3 * u, v, tx, ty, tz));

			if (j < sectors) {
				skyboxMesh->indices.push_back((i + 1)*(sectors)+(j + 1) % sectors);
				skyboxMesh->indices.push_back(i*(sectors)+(j + 1) % sectors);
				skyboxMesh->indices.push_back(i*(sectors)+j);

				skyboxMesh->indices.push_back((i + 1)*(sectors)+j);
				skyboxMesh->indices.push_back((i + 1)*(sectors)+(j + 1) % sectors);
				skyboxMesh->indices.push_back(i*(sectors)+j);
			}

			phi += d_phi;
		}
		theta += d_theta;
	}

	skyboxMesh->Upload();

	/*// create mesh
	float skyboxVertices[] = {
		// Front face
		-1.0, -1.0,  1.0,
		1.0, -1.0,  1.0,
		1.0,  1.0,  1.0,
		-1.0,  1.0,  1.0,

		// Back face
		-1.0, -1.0, -1.0,
		-1.0,  1.0, -1.0,
		1.0,  1.0, -1.0,
		1.0, -1.0, -1.0,

		// Top face
		-1.0,  1.0, -1.0,
		-1.0,  1.0,  1.0,
		1.0,  1.0,  1.0,
		1.0,  1.0, -1.0,

		// Bottom face
		-1.0, -1.0, -1.0,
		1.0, -1.0, -1.0,
		1.0, -1.0,  1.0,
		-1.0, -1.0,  1.0,

		// Right face
		1.0, -1.0, -1.0,
		1.0,  1.0, -1.0,
		1.0,  1.0,  1.0,
		1.0, -1.0,  1.0,

		// Left face
		-1.0, -1.0, -1.0,
		-1.0, -1.0,  1.0,
		-1.0,  1.0,  1.0,
		-1.0,  1.0, -1.0
	};
	skyboxMesh = new Mesh();
	for (int i = 0; i < 3 * 4 * 6; i += 3) {
		skyboxMesh->vertices.push_back(Vertex(skyboxVertices[i], skyboxVertices[i + 1], skyboxVertices[i + 2]));
	}

	int skyboxIndices[] = {
		0,  1,  2,      0,  2,  3,    // front
		4,  5,  6,      4,  6,  7,    // back
		8,  9,  10,     8,  10, 11,   // top
		12, 13, 14,     12, 14, 15,   // bottom
		16, 17, 18,     16, 18, 19,   // right
		20, 21, 22,     20, 22, 23,   // left
	};
	// add the indices in reversed winding order
	for (int i = 35; i >= 0; i--) {
		skyboxMesh->indices.push_back(skyboxIndices[i]);
	}

	skyboxMesh->Upload();*/
}

Skybox::~Skybox() {
	Dispose();
}

void Skybox::Dispose() {
	delete skyboxMesh;
	glDeleteTextures(1, &id);
}

void Skybox::Draw() {
	glDepthMask(GL_FALSE);

	skyboxMesh->Bind();
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, id);
	glDrawElements(GL_TRIANGLES, skyboxMesh->indices.size(), GL_UNSIGNED_INT, 0);

	glDepthMask(GL_TRUE);
}