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
	tunnel.setup();
}

//--------------------------------------------------------------
void testNode::update(){
	tunnel.update();
}

//--------------------------------------------------------------
void testNode::draw(){
	ofBackground(0);
	tunnel.draw();
	/*ofEnableSmoothing();
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

	ofDrawBitmapString("hello", 0, 0);*/
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