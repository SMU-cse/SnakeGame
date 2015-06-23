#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup(){
	ofBackgroundHex(0xDDDDDD);
	dirX[0] = 0;
	dirX[1] = 0;
	dirX[2] = -1;
	dirX[3] = 1;
	dirY[0] = 1;
	dirY[1] = -1;
	dirY[2] = 0;
	dirY[3] = 0;
}

//--------------------------------------------------------------
void ofApp::update(){


}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int i = 0; i < w; i++){
		ofSetColor(0, 0, 0);
		ofSetLineWidth(2);
		ofLine(i*sb, 0, i*sb, h*sb);
	}
	for (int i = 0; i < h; i++){
		ofSetColor(0, 0, 0);
		ofSetLineWidth(2);
		ofLine(0, i*sb, w*sb, i*sb);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}