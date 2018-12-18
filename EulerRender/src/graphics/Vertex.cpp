#include "Vertex.h"

using namespace Euler;

Vertex::Vertex(float x, float y, float z, float nx, float ny, float nz, float u, float v, float tx, float ty, float tz) {
	this->position.x = x;
	this->position.y = y;
	this->position.z = z;

	this->normal.x = nx;
	this->normal.y = ny;
	this->normal.z = nz;

	this->uv.x = u;
	this->uv.y = v;

	this->tangent.x = tx;
	this->tangent.y = ty;
	this->tangent.z = tz;
}

Vertex::~Vertex() {
}
