#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup(){
	ofBackgroundHex(0xDDDDDD);
	gameover = false;
	moveDir = 2;
	lastX = -1;
	lastY = -1;
	dirX[0] = 0;
	dirX[1] = 0;
	dirX[2] = 1;
	dirX[3] = -1;

	dirY[0] = 1;
	dirY[1] = -1;
	dirY[2] = 0;
	dirY[3] = 0;
	Snake.push_back(5, 5);
	framecount = 0;
	appleX = floor(ofRandom(1, 29));
	appleY = floor(ofRandom(1, 29));
	if (appleX == 29)
		appleX -= 1;
	if (appleY == 29)
		appleY -= 1;
	eaten = false;
}

//--------------------------------------------------------------
void ofApp::update(){
	//game over check
	if (gameover == false){
		//eaten reset
		eaten = false;

		//eaten test
		if (Snake.getX_at(0) == appleX && Snake.getY_at(0) == appleY)
			eaten = true;
		//---end eaten test---

		//execute every 5 frames
		if (framecount % 4 == 0){
			if (eaten){
				lastX = Snake.getLastX();
				lastY = Snake.getLastY();
				appleX = floor(ofRandom(1, 29));
				appleY = floor(ofRandom(1, 29));
				if (appleX == 29)
					appleX -= 1;
				if (appleY == 29)
					appleY -= 1;
			}
			Snake.change_at(0, Snake.getX_at(0) + dirX[moveDir], Snake.getY_at(0) + dirY[moveDir]);
			if (Snake.size() > 1){
				for (int i = 1; i < Snake.size(); i++){
					Snake.change_at(
						Snake.size() - i,
						Snake.getX_at(Snake.size() - (i + 1)),
						Snake.getY_at(Snake.size() - (i + 1))
						);
				}
			}
			if (eaten)
				Snake.push_back(lastX, lastY);
			Snake.output();
		}
		framecount++;
	}
	else {

	}
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
	for (int i = 0; i < Snake.size(); i++){
		ofSetColor(0, 255, 0);
		ofFill();
		ofRect(Snake.getX_at(i)*sb, Snake.getY_at(i)*sb, sb, sb);
	}
	ofSetColor(255, 0, 0);
	ofFill();
	ofRect(appleX*sb, appleY*sb, sb, sb);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	int newdir = 0;
	if (key == 's' && moveDir != 1){
		newdir = 0;
	}
	else if (key == 'w' && moveDir != 0){
		newdir = 1;
	}
	else if (key == 'd' && moveDir !=3){
		newdir = 2;
	}
	else if (key == 'a' && moveDir != 2){
		newdir = 3;
	}
	else {
		newdir = -1;
	}
	if (newdir != -1){
		moveDir = newdir;
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}