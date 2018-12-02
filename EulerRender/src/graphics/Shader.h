#pragma once

#include "../API.h"

#include <glad/glad.h>

#include <iostream>
#include <unordered_map>
#include <string>

#include "../math/Mat4.h"

class EULER_API Shader {
private:
	GLuint id;

	std::unordered_map<std::string, GLint> uniformLocations;

public:
	Shader(const char* vertexShaderSource, const char* fragmentShaderSource);
	~Shader();

	void Use();
	void Dispose();

	int GetUniformLocation(std::string name);

	// uniforms setters
	void SetFloat(std::string name, float val);
	void SetVec3(std::string name, float x, float y, float z);
	void SetMat4(std::string name, Mat4* mat);

};

