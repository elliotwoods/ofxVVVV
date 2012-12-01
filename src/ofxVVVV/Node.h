#pragma once

#include "ofMain.h"
#include "Pin.h"
#include "Host.h"

namespace ofxVVVV {
	class Node : public ofBaseApp {
		typedef vector<Pin*> PinVec;
	public:
		virtual ~Node() { delete this->host; }

		virtual void setupPins(Host &) = 0;

		virtual string getName() = 0;
		virtual PinVec & getInputPins() { return PinVec(); };
		virtual PinVec & getOutputPins() { return PinVec(); };

		void setHost(Host * host) { this->host = host; }
		Host & getHost() { return * this->host; }
	protected:
		void addInput(Pin &); ///< This function can only be called from setup()
		void addOutput(Pin &); ///< This function can only be called from setup()
	private:
		Host * host;
	};
}