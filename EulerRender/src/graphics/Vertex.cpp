#include "Vertex.h"

Vertex::Vertex(float x, float y, float z, float nx, float ny, float nz, float u, float v) {
	this->position.x = x;
	this->position.y = y;
	this->position.z = z;

	this->normal.x = nx;
	this->normal.y = ny;
	this->normal.z = nz;

	this->uv.x = u;
	this->uv.y = v;
}

Vertex::~Vertex() {
}
