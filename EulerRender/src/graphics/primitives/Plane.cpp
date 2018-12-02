#include "Plane.h"

Plane::Plane() {
	// add vertices
	vertices.push_back(Vertex(-0.5f, -0.5f, 0.0f,	0.0f, 0.0f, 1.0f,	0.0f, 0.0f));
	vertices.push_back(Vertex(0.5f, -0.5f, 0.0f,	0.0f, 0.0f, 1.0f,	0.0f, 1.0f));
	vertices.push_back(Vertex(0.5f, 0.5f, 0.0f,		0.0f, 0.0f, 1.0f,	1.0f, 1.0f));
	vertices.push_back(Vertex(-0.5f, 0.5f, 0.0f,	0.0f, 0.0f, 1.0f,	1.0f, 0.0f));
	// add indices
	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(2);
	indices.push_back(2);
	indices.push_back(3);
	indices.push_back(0);

	Upload();
}

Plane::~Plane() {
}
