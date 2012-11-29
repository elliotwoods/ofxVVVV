#pragma once

#include "ofMain.h"
#include "ofAppBaseWindow.h"

namespace ofxVVVV {
	class Window : public ofAppBaseWindow {
	public:
		ofPoint	getWindowPosition() {return ofPoint(windowX, windowY); }
		ofPoint	getWindowSize(){return ofPoint(this->getWidth(), this->getHeight()); }
		ofPoint	getScreenSize(){return ofPoint(screenWidth, screenHeight); }
		int getWidth() { return windowWidth; }
		int getHeight() { return windowHeight; }

		void setWindowPosition(int windowX, int windowY);
		void setWindowSize(int windowWidth, int windowHeight);
		void setScreenSize(int screenWidth, int screenHeight);

	private:
		static float screenWidth, screenHeight;
		static float windowWidth, windowHeight;
		static float windowX, windowY;
	};

	class AutoWindow : public ofAppBaseWindow {
	public:
		AutoWindow();
		ofPoint	getWindowPosition() {return ofPoint(0, 0); }
		ofPoint	getWindowSize() { return ofPoint(windowWidth, windowHeight); }
		ofPoint	getScreenSize(){return getWindowSize(); }
		int getWidth() { return this->windowWidth; }
		int getHeight() { return this->windowHeight; }
		
		int		getFrameNum() { return this->frameNum; }
		float	getFrameRate() { return this->frameRate; }
		double  getLastFrameTime() { return this->lastFrameTime; }

		void	update();

	private:
		int windowWidth;
		int windowHeight;

		int frameNum;
		clock_t lastFrame;
		float lastFrameTime;
		float frameRate;
	};


}