//this version of the snake game created by N. Chase Squires, June 2015
//------
//you may not use the code here verbatim for your lab. Sorry, i'm not
//here to let you outsource your grades to me.
//this code is posted as a guideline only.
#pragma once

#include "ofMain.h"
#include "LinkedList.h"
#include "Node.h"


class ofApp : public ofBaseApp{

	public:
		int w = 30; //30 blocks wide
		int h = 30; //30 blocks tall
		int sb = 20; //20px Space Between each line
		int dirX[4];
		int dirY[4];
		int moveDir;
		LinkedList Snake;
		int appleX;
		int appleY;
		int lastX;
		int lastY;
		bool eaten;
		bool gameover;
		int score;


		int framecount;

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};

