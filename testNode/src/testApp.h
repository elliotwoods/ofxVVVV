#pragma once

#include "ofMain.h"
#include "ofxVVVV.h"

#define NODE_CLASS testNode

class testNode : public ofxVVVV::Node{

	public:
		string getName() { return "testNode"; };
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};

#include "ofxVVVV/Factory.h"