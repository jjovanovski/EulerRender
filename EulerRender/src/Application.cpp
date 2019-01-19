#include "Application.h"

#include <iostream>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "input/GLFWInputHandler.h"
#include "resources/Resources.h"

using namespace Euler;

Application::Application(int width, int height, const char* title) {
	// === init glfw ===
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	window = glfwCreateWindow(width, height, title, nullptr, nullptr);
	if (window == nullptr)
		return;

	glfwMakeContextCurrent(window);
	gladLoadGL();

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	// === init input system ===
	InputHandler* glfwInputHandler = new GLFWInputHandler(window);
	Input::Init(glfwInputHandler);

	// === init resources system ===
	Resources::Init();
}

Application::~Application() {
	
}

void Application::Run() {
	if (window == nullptr) return;

	while (!glfwWindowShouldClose(window)) {
		if (scene != nullptr) {
			scene->UpdateScene();
			scene->DrawScene();
		}

		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	Dispose();
}

void Application::Dispose() {
	Resources::Dispose();
	Input::Dispose();
	glfwTerminate();
}

Scene * Application::GetScene() {
	return scene;
}

void Application::SetScene(Scene * scene) {
	this->scene = scene;
}