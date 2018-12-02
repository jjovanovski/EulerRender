#pragma once

#include <glad\glad.h>

#include "../API.h"
#include "Component.h"

class EULER_API Scene : public Component {
public:
	Scene();
	virtual ~Scene();

	void UpdateScene();
	void DrawScene();
};

