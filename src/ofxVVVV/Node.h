#pragma once

#include "ofMain.h"
#include "Pin.h"

namespace ofxVVVV {
	class Node : public ofBaseApp {
		typedef vector<Pin*> PinVec;
	public:
		virtual string getName() = 0;
		virtual PinVec & getInputPins() { return PinVec(); };
		virtual PinVec & getOutputPins() { return PinVec(); };
	protected:
		void addInput(Pin &); ///< This function can only be called from setup()
		void addOutput(Pin &); ///< This function can only be called from setup()
	private:
		vector<Pin*> inputPins;
		vector<Pin*> outputPins;
	};
}