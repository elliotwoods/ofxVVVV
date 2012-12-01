#pragma once

#include "ofMain.h"
#include "Pin.h"

namespace ofxVVVV {
	class Host {
	public:
		void addInputValuePin(Pin & pin);
		void addOutputValuePin(Pin & pin);
		int getInputCount() const { return this->inputs.size(); };
		int getOutputCount() const { return this->outputs.size(); };
		Pin & getInputPin(int PinIndex) { return * this->inputs[PinIndex]; }
		Pin & getOutputPin(int PinIndex) { return * this->outputs[PinIndex]; }
	protected:
		vector<Pin*> inputs;
		vector<Pin*> outputs;
	};
}