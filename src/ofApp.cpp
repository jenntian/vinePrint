#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){


	//ofSetCurveResolution(1024);


}

//--------------------------------------------------------------
void ofApp::update(){



}

//--------------------------------------------------------------
void ofApp::draw(){
	
	// START print to pdf
	if (oneShot) {
		ofBeginSaveScreenAsPDF("screenshot-" + ofGetTimestampString() + ".pdf", false);
	}


	ofBackground(220,220,240);

	
	vine(300,150);

	// END print to pdf
	if (oneShot) {
		ofEndSaveScreenAsPDF();
		oneShot = false;
	}

}

void ofApp::vine(int x, int y) {

	// draw line
	ofSetColor(0);
	ofSetLineWidth(7.0);
	ofLine(ofVec3f(x, 0), ofVec3f(x, ofGetHeight()));

	int dir = 1;
	//draw leafs
	ofSetLineWidth(5.0);

	for (int i = 0; i < 12; i++) {
		leaf(x+4*dir, y+i*50, dir);
		dir = -dir;
	}

	
}


void ofApp::leaf(int x, int y, int dir) {

	//ofDrawEllipse(x-dir*20, y, 60, 60);

	ofPath line;
	line.setFilled(false);
	line.setStrokeWidth(4);
	line.setStrokeColor(0);
	line.setFillColor(ofColor(0, 0, 255));

	// line 1 to tip
	ofPoint p1 = ofVec3f(x, y, 0);
	ofPoint p2 = ofVec3f(x-5*dir,y, 0); //curve x,y // seems fine in print... 
	ofPoint p3 = ofVec3f(x+80*dir, y-70, 0); //curve x,y
	ofPoint p4 = ofVec3f(x+150*dir, y-60, 0);

	//line.addVertex(x, y, 0);
	line.curveTo(p1);
	line.curveTo(p2);
	line.curveTo(p3);
	line.curveTo(p4);
	
	// line 2 to beginning
	 p1 = ofVec3f(x+120*dir, y-20, 0);
	 p2 = ofVec3f(x + 30*dir, y, 0); //curve x,y
	 p3 = ofVec3f(x, y, 0); //curve x,y
	 p4 = ofVec3f(x+80*dir,y-80, 0); // come down from x,y

	 line.curveTo(p1);
	 line.curveTo(p2);
	 line.curveTo(p3);
	 line.curveTo(p4);

	// line.curveTo(p4);
	 line.close();

	 ofSetColor(255, 0, 0);
	 line.draw();

	/*ofSetColor(255, 127,0);
	int sizeE = 5;
	//ofDrawEllipse(p1, sizeE, sizeE);
	//ofDrawEllipse(p2, sizeE, sizeE);
	//ofDrawEllipse(p3, sizeE, sizeE);
	ofDrawEllipse(p4, sizeE, sizeE);*/

	



}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
	if (key == 's') {
		oneShot = true;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
