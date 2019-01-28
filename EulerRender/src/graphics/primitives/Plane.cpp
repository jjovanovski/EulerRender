#include "Plane.h"

using namespace Euler;

Plane::Plane(int subplanes) {
	for (int i = 0; i < subplanes; i++) {
		for (int j = 0; j < subplanes; j++) {
			float u = (float)j / (subplanes-1);
			float v = (float)i / (subplanes-1);
			float x = -1.0f + 2.0f * u;
			float y = -1.0f + 2.0f * v;

			vertices.push_back(Vertex(x, y, 0, 0, 0, 1, u, v, 1, 0, 0));
		}
	}

	for (int i = 0; i < subplanes * (subplanes -1); i += subplanes) {
		for (int j = 0; j < subplanes -1; j++) {
			int idx = i + j;

			indices.push_back(idx);
			indices.push_back(idx + 1);
			indices.push_back(idx + subplanes + 1);

			indices.push_back(idx);
			indices.push_back(idx + subplanes + 1);
			indices.push_back(idx + subplanes);
		}
	}

	/*// add vertices
	vertices.push_back(Vertex(-0.5f, 0.5f, 0.0f,	0.0f, 0.0f, 1.0f,	0.0f, 1.0f,		1.0f, 0.0f, 0.0f));
	vertices.push_back(Vertex(-0.5f, -0.5f, 0.0f,	0.0f, 0.0f, 1.0f,	0.0f, 0.0f,		1.0f, 0.0f, 0.0f));
	vertices.push_back(Vertex(0.5f, -0.5f, 0.0f,	0.0f, 0.0f, 1.0f,	1.0f, 0.0f,		1.0f, 0.0f, 0.0f));
	vertices.push_back(Vertex(0.5f, 0.5f, 0.0f,		0.0f, 0.0f, 1.0f,	1.0f, 1.0f,		1.0f, 0.0f, 0.0f));
	// add indices
	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(2);

	indices.push_back(0);
	indices.push_back(2);
	indices.push_back(3);*/

	Upload();
}

Plane::~Plane() {
}
