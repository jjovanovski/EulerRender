#include "Sphere.h"

using namespace Euler;

Sphere::Sphere(int rings, int sectors) {
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

			vertices.push_back(Vertex(x, y, z, x, y, z, u, v));

			if (j < sectors) {
				indices.push_back(i*(sectors)+j);
				indices.push_back(i*(sectors)+(j + 1) % sectors);
				indices.push_back((i + 1)*(sectors)+(j + 1) % sectors);

				indices.push_back(i*(sectors)+j);
				indices.push_back((i + 1)*(sectors)+(j + 1) % sectors);
				indices.push_back((i + 1)*(sectors)+j);
			}

			phi += d_phi;
		}
		theta += d_theta;
	}

	Upload();
}

Sphere::~Sphere() {
}
