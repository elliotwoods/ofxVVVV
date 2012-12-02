#pragma once

#include "ofMain.h"
#include "ofxVVVV.h"

#define NODE_CLASS testNode

using namespace ofxVVVV;

#define CUBE_COUNT 50
#define DUST_COUNT 1000

class testNode : public Node{

	public:
		testNode() { }
		void setupPins(Host &);
		string getName() { return "testNode"; };

		void setup();
		void update();
		void draw();
		void drawCubes();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		Pin testInput;
		Pin testOutput;

		ofShader test;
};

#include "ofxVVVV/Factory.h"