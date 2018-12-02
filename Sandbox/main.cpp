#include <iostream>

#include "Euler.h"

class MyScene : public Scene {

	void Update() {
		std::cout << "Scene update" << std::endl;
	}

	void Draw() {

	}

};

int main(char** args, int argc) {
	Application app(600, 600, "App test");
	MyScene scene;
	app.SetScene(&scene);
	app.Run();

	return 0;
}