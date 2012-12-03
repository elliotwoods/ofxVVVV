#pragma once
#define DllExport _declspec(dllexport)
#include <map>

namespace ofxVVVV {
	template<class Node>
	class Factory {
		typedef std::pair<int, Node*> inserter;
	public:
		Factory() {
			glewInit();
			ofSeedRandom();
			ofResetElapsedTimeCounter();
			this->window = ofPtr<ofAppBaseWindow>(new ofxVVVV::Window());
			this->renderer = ofPtr<ofBaseRenderer>(new ofGLRenderer(false));
			ofSetCurrentWindow(window);
			ofSetCurrentRenderer(renderer);
			this->nextIndex = 0;
			this->frameIndex = 0;
		}

		void setDataPath(string dataPath) {
			ofSetLogLevel(OF_LOG_VERBOSE);
			ofSetDataPathRoot(string(dataPath));
			ofLogToFile("oflog.txt");

			ofLogVerbose() << "Hello!";
			ofLogWarning() << "Data path set to" << ofToDataPath(".", true);
		}

		int create() {
			Host * host = new Host();
			Node * node = new Node();
			node->setHost(host);
			node->setupPins(*host);

			instances.insert(inserter(nextIndex, node));
			return this->nextIndex++;
		}

		void destroy(int handle) {
			while (this->hasInstance(handle)) {
				delete instances.find(handle)->second;
				instances.erase(instances.find(handle));
			}
		}

		bool hasInstance(int handle) {
			return this->instances.count(handle) > 0;
		}

		Node * getInstance(int handle) {
			return this->instances.find(handle)->second;
		}

		void setup(int handle) {
			if (this->hasInstance(handle)) {
				this->getInstance(handle)->setup();
			}
		}

		void update(int handle) {
			if (this->hasInstance(handle)) {
				this->getInstance(handle)->update();
			}
		}

		void draw(int handle) {
			if (this->hasInstance(handle)) {
				while (frameIndex < 10) {
					ofSetCurrentWindow(window);
					ofSetCurrentRenderer(renderer);
					frameIndex++;
				}
				this->getInstance(handle)->draw();
			}
		}

		int getInputCount(int handle) {
			if (this->hasInstance(handle)) {
				return this->getInstance(handle)->getHost().getInputCount();
			}
		}

		int getOutputCount(int handle) {
			if (this->hasInstance(handle)) {
				return this->getInstance(handle)->getHost().getOutputCount();
			}
		}

		void setInputSliceCount(int handle, int PinIndex, int SliceCount) {
			if (this->hasInstance(handle)) {
				this->getInstance(handle)->getHost().getInputPin(PinIndex).setSliceCount(SliceCount);
			}
		}

		int getOutputSliceCount(int handle, int PinIndex) {
			if (this->hasInstance(handle)) {
				return this->getInstance(handle)->getHost().getOutputPin(PinIndex).getSliceCount();
			}
		}

		void setInputValue(int handle, int PinIndex, int SliceIndex, double Value) {
			if (this->hasInstance(handle)) {
				this->getInstance(handle)->getHost().getInputPin(PinIndex)[SliceIndex] = Value;
			}
		}

		double getOutputValue(int handle, int PinIndex, int SliceIndex) {
			if (this->hasInstance(handle)) {
				return this->getInstance(handle)->getHost().getOutputPin(PinIndex)[SliceIndex];
			}
		}

	protected:
		ofPtr<ofBaseRenderer> renderer;
		ofPtr<ofAppBaseWindow> window;
		std::map<int, Node*> instances;
		int nextIndex;
		int frameIndex;
	};
}

ofxVVVV::Factory<NODE_CLASS> factory;

extern "C" {
	DllExport void SetDataPath(char * path, int length) {
		char * path8bit = new char[length];
		for (int i=0; i<length; i++)
			path8bit[i] = path[i*2];
		factory.setDataPath(string(path8bit,length));
	}

	DllExport int NodeCreate() {
		return factory.create();
	}

	DllExport void NodeDestroy(int handle) {
		factory.destroy(handle);
	}
	
	DllExport void NodeSetup(int handle) {
		factory.setup(handle);
	}

	DllExport void NodeUpdate(int handle) {
		factory.update(handle);
	}

	DllExport void NodeDraw(int handle) {
		factory.draw(handle);
	}
	
	DllExport int NodeInputCount(int handle) {
		return factory.getInputCount(handle);
	}

	DllExport int NodeOutputCount(int handle) {
		return factory.getOutputCount(handle);
	}

	DllExport void NodeSetInputSliceCount(int handle, int PinIndex, int SliceCount) {
		factory.setInputSliceCount(handle, PinIndex, SliceCount);
	}

	DllExport void NodeSetInputValue(int handle, int PinIndex, int SliceIndex, double Value) {
		factory.setInputValue(handle, PinIndex, SliceIndex, Value);
	}

	DllExport int NodeGetOutputSliceCount(int handle, int PinIndex) {
		return factory.getOutputSliceCount(handle, PinIndex);
	}

	DllExport double NodeGetOutputValue(int handle, int PinIndex, int SliceIndex) {
		return factory.getOutputValue(handle, PinIndex, SliceIndex);
	}
}