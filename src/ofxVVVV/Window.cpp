#include "Window.h"

namespace ofxVVVV {
	//---------
	float Window::screenWidth = 1024;
	float Window::screenHeight = 768;
	float Window::windowWidth = 1024;
	float Window::windowHeight = 768;
	float Window::windowX = 0;
	float Window::windowY = 0;

	//---------
	void Window::setWindowPosition(int windowX, int windowY) {
		this->windowX = windowX;
		this->windowY = windowY;
	}

	//---------
	void Window::setWindowSize(int windowWidth, int windowHeight) {
		this->windowWidth = windowWidth;
		this->windowHeight = windowHeight;
	}

	//---------
	void Window::setScreenSize(int screenWidth, int screenHeight) {
		this->screenWidth = screenWidth;
		this->screenHeight = screenHeight;
	}

	//---------
	AutoWindow::AutoWindow() {
		this->windowWidth = 1024;
		this->windowHeight = 768;
		this->frameNum = 0;
		this->frameRate = 30.0f;
		lastFrame = clock();
	}

	//---------
	void AutoWindow::update() {
		const ofRectangle viewport = ofGetCurrentViewport();
		this->windowWidth = viewport.width;
		this->windowHeight = viewport.height;
		clock_t thisFrame = clock();
		this->lastFrameTime = float(thisFrame - lastFrame) / float(CLOCKS_PER_SEC);
		float fps = 1.0f / lastFrameTime;
		this->frameRate = fps * 0.1f + this->frameRate * 0.9f;
		frameNum++;
		lastFrame = clock();
	}
}