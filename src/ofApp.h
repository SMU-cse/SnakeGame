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

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};

