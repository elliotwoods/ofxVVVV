#pragma once

#include "ofMain.h"
#include "Pin.h"

namespace ofxVVVV {
	class Node : public ofBaseApp {
	public:
		vector<Pin*> & getInputPins();
		vector<Pin*> & getOutputPins();
	protected:
		void addInput(Pin &); ///< This function can only be called from setup()
		void addOutput(Pin &); ///< This function can only be called from setup()
	private:
		vector<Pin*> inputPins;
		vector<Pin*> outputPins;
	};
}