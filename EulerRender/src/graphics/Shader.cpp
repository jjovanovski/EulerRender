#include "Shader.h"

using namespace Euler;

Shader::Shader(const char* vertexShaderSource, const char* fragmentShaderSource) {
	int success;
	char infoLog[512];

	// compile vertex shader
	GLint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "Failed to compile vertex shader: " << infoLog << std::endl;

		glDeleteShader(vertexShader);
		return;
	}

	// compile fragment shader
	GLint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "Failed to compile fragment shader: " << infoLog << std::endl;

		glDeleteShader(fragmentShader);
		return;
	}

	// link both to shader program
	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << infoLog << std::endl;
	}

	// detach and delete shaders (shader program remains compiled&linked in memory)
	glDetachShader(shaderProgram, vertexShader);
	glDetachShader(shaderProgram, fragmentShader);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	this->id = shaderProgram;
}


Shader::~Shader() {
	Dispose();
}

void Shader::Use() {
	glUseProgram(id);
}

void Shader::Dispose() {
	glDeleteProgram(id);
}

int Shader::GetUniformLocation(std::string name) {
	int uniformLocation = -1;
	if (uniformLocations.find(name) != uniformLocations.end()) {
		uniformLocation = uniformLocations[name];
	} else {
		uniformLocation = glGetUniformLocation(id, name.c_str());
		uniformLocations[name] = uniformLocation;
	}

	return uniformLocation;
}

void Shader::SetInt(std::string name, int value) {
	glUniform1i(GetUniformLocation(name), value);
}

void Shader::SetFloat(std::string name, float value) {
	glUniform1f(GetUniformLocation(name), value);
}

void Shader::SetVec2(std::string name, float x, float y) {
	glUniform2f(GetUniformLocation(name), x, y);
}

void Shader::SetVec3(std::string name, float x, float y, float z) {
	glUniform3f(GetUniformLocation(name), x, y, z);
}

void Shader::SetMat4(std::string name, Mat4* mat) {
	glUniformMatrix4fv(GetUniformLocation(name), 1, GL_TRUE, mat->GetPointer());
}