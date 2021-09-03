#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void sendProjectorOn();
		void sendProjectorOff();
		void sendShadowingOn();
		void sendShadowingOff();
		void sendReboot();
		void sendOpenStartupApplications();
		void toggleCamera();
		void sendOpenTempLog();
		void sendOpenConfig();

		ofxPanel gui;
		ofxButton projectorOn;
		ofxButton projectorOff;
		ofxButton shadowingOn;
		ofxButton shadowingOff;
		ofxButton reboot;
		ofxButton openStartupApplications;
		ofxToggle showCamera;
		ofxButton openTempLog;
		ofxButton openConfig;

		bool lastShowCamera;

		string output;

	  ofVideoGrabber vidGrabber;

		int camWidth;
		int camHeight;


};
