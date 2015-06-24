#include "ofMain.h"
#include "ofApp.h"
#include "LinkedList.h"
#include "Node.h"
//========================================================================
int main( ){
	std::cout << ofGetFrameRate() << std::endl;
	ofSetFrameRate(30);
	ofSetupOpenGL(600,600,OF_WINDOW);			// <-------- setup the GL context
	ofSetVerticalSync(false);

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too
	ofRunApp(new ofApp());

}
