#include "testApp.h"

//--------------------------------------------------------------
void testNode::setupPins(Host& host){
	testInput.setName("Input");
	testOutput.setName("Output");
	
	host.addInputValuePin(testInput);
	host.addOutputValuePin(testOutput);
}

//--------------------------------------------------------------
void testNode::setup(){
	string shaderPath = "bin\\data\\test";
	ofLogWarning() << "setup";
	ofSetLogLevel(OF_LOG_VERBOSE);
	ofLogWarning() << ofToDataPath(shaderPath, true);
	test.load(shaderPath);
}

//--------------------------------------------------------------
int framenum = 0;
void testNode::update(){
	//ofLogVerbose() << framenum++;
	//if (framenum++ % 30 == 0)
	//	test.load("test");
}

//--------------------------------------------------------------
void testNode::draw(){
	ofBackground(0);
	test.begin();
	ofRect(-0.5,-0.5,1,1);
	test.end();
}

//--------------------------------------------------------------
void testNode::keyPressed(int key){

}

//--------------------------------------------------------------
void testNode::keyReleased(int key){

}

//--------------------------------------------------------------
void testNode::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testNode::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testNode::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testNode::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testNode::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testNode::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testNode::dragEvent(ofDragInfo dragInfo){ 

}