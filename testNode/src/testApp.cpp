#include "testApp.h"

//--------------------------------------------------------------
void testNode::setupPins(Host& host){
	testInput1.setName("Input");
	testInput2.setName("Another input");
	testOutput.setName("Output");
	
	host.addInputValuePin(testInput1);
	//host.addInputValuePin(testInput2);
	host.addOutputValuePin(testOutput);
}

//--------------------------------------------------------------
void testNode::setup(){
	//system("c:\\windows\\notepad.exe");
	tunnel.setup();
}

//--------------------------------------------------------------
void testNode::update(){
	tunnel.update();
}

//--------------------------------------------------------------
void testNode::draw(){
	ofBackground(0);
	/*
	//ofRect(0,0,1,1);
	ofRect(0,0,50,50);
	ofDrawBitmapString("this is some text", 0, 0, 0);
	tunnel.draw();
	ofDrawGrid();
	*/
	ofEnableSmoothing();
	glEnable(GL_DEPTH_TEST);
	ofBackground(0);
	ofDrawGrid();

	ofSetLineWidth(3.0f);
	ofMesh mesh;
	for(float x=-1.0f; x<1.0f; x+=0.01f) {
		float t = ofGetElapsedTimef() + x;
		mesh.addVertex(ofVec3f(x, ofNoise(t*0.8f, 0), ofNoise(0, t*0.8f)));
	}
	mesh.setMode(ofPrimitiveMode::OF_PRIMITIVE_LINE_STRIP);
	mesh.draw();

	ofDrawBitmapString(ofToString(this->testInput1[0]), 0, 0);
}

//--------------------------------------------------------------
void testNode::drawGrid() {
	ofDrawGrid();
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