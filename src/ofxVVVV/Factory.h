#pragma once
#define DllExport _declspec(dllexport)
#include <map>

namespace ofxVVVV {
	template<class Node>
	class Factory {
		typedef std::pair<int, Node*> inserter;
	public:
		Factory() {
			this->nextIndex = 0;
		}

		int create() {
			Node* node = new Node();
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
				this->getInstance(handle)->draw();
			}
		}

	protected:
		std::map<int, Node*> instances;
		int nextIndex;
	};
}

ofxVVVV::Factory<NODE_CLASS> factory;

extern "C" {
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
}