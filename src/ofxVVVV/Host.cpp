#include "Host.h"

namespace ofxVVVV {
	//--------
	void Host::addInputValuePin(Pin & pin) {
		this->inputs.push_back(&pin);
	}

	//--------
	void Host::addOutputValuePin(Pin & pin) {
		this->outputs.push_back(&pin);
	}
}