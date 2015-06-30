//this version of the snake game created by N. Chase Squires, June 2015
//------
//you may not use the code here verbatim for your lab. Sorry, i'm not
//here to let you outsource your grades to me.
//this code is posted as a guideline only.
#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup(){
	ofBackgroundHex(0xDDDDDD);
	gameover = false;
	score = 0;
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
		if (framecount % 5 == 0){
			if (eaten){
				score++;
				lastX = Snake.getLastX();
				lastY = Snake.getLastY();
				appleX = floor(ofRandom(1, 29));
				appleY = floor(ofRandom(1, 29));
				if (appleX == 29)
					appleX -= 1;
				if (appleY == 29)
					appleY -= 1;
				if (Snake.size() == 1)
					Snake.push_back(lastX, lastY);
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
			/* next if statement is separated from original push-back 
			 *to fix a bug where the first eaten apple does not extend length */
			if (eaten && Snake.size()>1)
				Snake.push_back(lastX, lastY);
			if (Snake.size() > 2){
				for (int i = 2; i < Snake.size(); i++){
					if (Snake.getX_at(0) == Snake.getX_at(i) && Snake.getY_at(0) == Snake.getY_at(i))
						gameover = true;
				}
			}
			if (Snake.getX_at(0) >= 30 || Snake.getX_at(0) < 0 || Snake.getY_at(0) >= 30 || Snake.getY_at(0) < 0)
				gameover = true;
		}
		framecount++;
	}
	else {
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	if (!gameover){
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
	}	else {
		string scoreString = "SCORE: " + ofToString(score);
		ofDrawBitmapString("~~GAME OVER~~",13*sb, 10*sb);
		ofDrawBitmapString(scoreString, 14 * sb, 16 * sb);
	}
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
	else if (key == 'd' && moveDir != 3){
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