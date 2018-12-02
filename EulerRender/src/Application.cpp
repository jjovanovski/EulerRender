#include "Application.h"

#include <iostream>

using namespace Euler;

Application::Application(int width, int height, const char* title) {
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
}

Application::~Application() {
	glfwTerminate();
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
}

Scene * Application::GetScene() {
	return scene;
}

void Application::SetScene(Scene * scene) {
	this->scene = scene;
}