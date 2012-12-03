#pragma once

#include "ofMain.h"

namespace ofxVVVV {
	class Pin {
	public:
		Pin() { values.resize(1, 0.0); }
		Pin(const string & name) : name(name) { }
		const string & getName() const {return this->name;}
		void setName(const string & name) {this->name = name; }
		int getSliceCount() { return values.size(); };
		void setSliceCount(int SliceCount) { this->values.resize(SliceCount); };
		double & operator[](int index) { return values[index]; }
	private:
		string name;
		vector<double> values;
	};
}