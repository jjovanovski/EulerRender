#pragma once

// this file should be included only from client's code

#include "API.h"

#include "Application.h"
#include "input\Input.h"

#include "resources\Disposable.h"
#include "resources\Resources.h"

#include "graphics\Mesh.h"
#include "graphics\Shader.h"
#include "graphics\Vertex.h"
#include "graphics\Material.h"
#include "graphics\Texture.h"
#include "graphics\MeshMaterial.h"
#include "graphics\Model.h"
#include "graphics\primitives\Cube.h"
#include "graphics\primitives\Sphere.h"
#include "graphics\primitives\Plane.h"
#include "graphics\shaders\BasicShader.h"
#include "graphics\shaders\WorldShader.h"

#include "scene\Component.h"
#include "scene\Scene.h"
#include "scene\Camera.h"
#include "scene\FreeCamera.h"
#include "scene\DirectionalLight.h"
#include "scene\WorldModel.h"

#include "math\Vec2.h"
#include "math\Vec3.h"
#include "math\Mat4.h"
#include "math\Quaternion.h"
#include "math\Transformation.h"