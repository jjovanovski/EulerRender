#include "GLFWInputHandler.h"

using namespace Euler;

float Euler::GLFWInputHandler::mouseX = 0;
float Euler::GLFWInputHandler::mouseY = 0;

GLFWInputHandler::GLFWInputHandler(GLFWwindow * window) {
	this->window = window;

	//glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);

	glfwSetCursorPosCallback(window, CursorPosCallback);
}

GLFWInputHandler::~GLFWInputHandler() {
}

void GLFWInputHandler::Init() {
};

void GLFWInputHandler::Dispose() {
	glfwSetCursorPosCallback(window, nullptr);
};

float GLFWInputHandler::GetMouseX() {
	return mouseX;
};

float GLFWInputHandler::GetMouseY() {
	return mouseY;
};

void GLFWInputHandler::HideCursor() {
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

bool GLFWInputHandler::GetKey(Key key) {
	if (key == MOUSE_LEFT)
		return glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;
	if (key == MOUSE_MIDDLE)
		return glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_MIDDLE) == GLFW_PRESS;
	if (key == MOUSE_RIGHT)
		return glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS;

	int state = glfwGetKey(window, Map(key));
	return state == GLFW_PRESS;
};

bool GLFWInputHandler::GetKeyDown(Key key) {
	return GetKey(key);
};

bool GLFWInputHandler::GetKeyUp(Key key) {
	return GetKey(key);
};

void GLFWInputHandler::CursorPosCallback(GLFWwindow* window, double x, double y) {
	mouseX = (float)x;
	mouseY = (float)y;
}

int GLFWInputHandler::Map(Key key) {
	switch(key) {
	case Key::Q: return GLFW_KEY_Q;
	case Key::W: return GLFW_KEY_W;
	case Key::E: return GLFW_KEY_E;
	case Key::R: return GLFW_KEY_R;
	case Key::T: return GLFW_KEY_T;
	case Key::Y: return GLFW_KEY_Y;
	case Key::U: return GLFW_KEY_U;
	case Key::I: return GLFW_KEY_I;
	case Key::O: return GLFW_KEY_O;
	case Key::P: return GLFW_KEY_P;
	case Key::A: return GLFW_KEY_A;
	case Key::S: return GLFW_KEY_S;
	case Key::D: return GLFW_KEY_D;
	case Key::F: return GLFW_KEY_F;
	case Key::G: return GLFW_KEY_G;
	case Key::H: return GLFW_KEY_H;
	case Key::J: return GLFW_KEY_J;
	case Key::K: return GLFW_KEY_K;
	case Key::L: return GLFW_KEY_L;
	case Key::Z: return GLFW_KEY_Z;
	case Key::X: return GLFW_KEY_X;
	case Key::C: return GLFW_KEY_C;
	case Key::V: return GLFW_KEY_V;
	case Key::B: return GLFW_KEY_B;
	case Key::N: return GLFW_KEY_N;
	case Key::M: return GLFW_KEY_M;

	case Key::ONE: return GLFW_KEY_1;
	case Key::TWO: return GLFW_KEY_2;
	case Key::THREE: return GLFW_KEY_3;
	case Key::FOUR: return GLFW_KEY_4;
	case Key::FIVE: return GLFW_KEY_5;
	case Key::SIX: return GLFW_KEY_6;
	case Key::SEVEN: return GLFW_KEY_7;
	case Key::EIGHT: return GLFW_KEY_8;
	case Key::NINE: return GLFW_KEY_9;
	case Key::ZERO: return GLFW_KEY_0;

	case Key::NUMPAD_ONE: return GLFW_KEY_KP_1;
	case Key::NUMPAD_TWO: return GLFW_KEY_KP_2;
	case Key::NUMPAD_THREE: return GLFW_KEY_KP_3;
	case Key::NUMPAD_FOUR: return GLFW_KEY_KP_4;
	case Key::NUMPAD_FIVE: return GLFW_KEY_KP_5;
	case Key::NUMPAD_SIX: return GLFW_KEY_KP_6;
	case Key::NUMPAD_SEVEN: return GLFW_KEY_KP_7;
	case Key::NUMPAD_EIGHT: return GLFW_KEY_KP_8;
	case Key::NUMPAD_NINE: return GLFW_KEY_KP_9;
	case Key::NUMPAD_ZERO: return GLFW_KEY_KP_0;


	case Key::TILDE: return GLFW_KEY_GRAVE_ACCENT;
	case Key::MINUS: return GLFW_KEY_MINUS;
	case Key::NUMPAD_MINUS: return GLFW_KEY_KP_SUBTRACT;
	case Key::EQUAL: return GLFW_KEY_EQUAL;
	case Key::NUMPAD_PLUS: return GLFW_KEY_KP_ADD;
	case Key::BRACKET_OPEN: return GLFW_KEY_LEFT_BRACKET;
	case Key::BRACKET_CLOSE: return GLFW_KEY_RIGHT_BRACKET;
	case Key::SEMICOLON: return GLFW_KEY_SEMICOLON;
	case Key::APOSTROPHE: return GLFW_KEY_APOSTROPHE;
	case Key::SLASH: return GLFW_KEY_SLASH;
	case Key::COMMA: return GLFW_KEY_COMMA;
	case Key::DOT: return GLFW_KEY_PERIOD;
	case Key::NUMPAD_DOT: return GLFW_KEY_KP_DECIMAL;
	case Key::BACKSLASH: return GLFW_KEY_BACKSLASH;
	case Key::NUMPAD_ASTERISK: return GLFW_KEY_KP_MULTIPLY;

	case Key::CTRL: return GLFW_KEY_LEFT_CONTROL;
	case Key::CTRL_RIGHT: return GLFW_KEY_RIGHT_CONTROL;
	case Key::ALT: return GLFW_KEY_LEFT_ALT;
	case Key::ALT_RIGHT: return GLFW_KEY_RIGHT_ALT;
	case Key::SHIFT: return GLFW_KEY_LEFT_SHIFT;
	case Key::SHIFT_RIGHT: return GLFW_KEY_RIGHT_SHIFT;
	case Key::CAPS_LOCK: return GLFW_KEY_CAPS_LOCK;
	case Key::TAB: return GLFW_KEY_TAB;
	case Key::ESC: return GLFW_KEY_ESCAPE;
	case Key::SPACE: return GLFW_KEY_SPACE;
	case Key::ENTER: return GLFW_KEY_ENTER;
	case Key::NUMPAD_ENTER: return GLFW_KEY_KP_ENTER;
	case Key::BACKSPACE: return GLFW_KEY_BACKSPACE;

	case Key::ARROW_UP: return GLFW_KEY_UP;
	case Key::ARROW_DOWN: return GLFW_KEY_DOWN;
	case Key::ARROW_LEFT: return GLFW_KEY_LEFT;
	case Key::ARROW_RIGHT: return GLFW_KEY_RIGHT;

	default: return -1;
	}
}