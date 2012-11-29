#pragma once

#include "ofMain.h"

namespace ofxVVVV {
	class Pin {
	public:
		Pin(const string & name) : name(name) { }
		const string & getName() const {return this->name;}
		virtual int getSliceCount() = 0;
	private:
		const string name;
	};
}