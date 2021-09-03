#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

  ofSetFrameRate(30);
  ofSetWindowTitle("shadowingUI");
  camWidth = 640;
  camHeight = 480;

  projectorOn.addListener(this, &ofApp::sendProjectorOn);
  projectorOff.addListener(this, &ofApp::sendProjectorOff);
  shadowingOn.addListener(this, &ofApp::sendShadowingOn);
  shadowingOff.addListener(this, &ofApp::sendShadowingOff);
  reboot.addListener(this, &ofApp::sendReboot);
  openStartupApplications.addListener(this, &ofApp::sendOpenStartupApplications);
  openTempLog.addListener(this, &ofApp::sendOpenTempLog);
  openConfig.addListener(this, &ofApp::sendOpenConfig);
  // showCamera.addListener(this, &ofApp::toggleCamera);

  gui.setup();
  gui.add(projectorOn.setup("Projector On"));
  gui.add(projectorOff.setup("Projector Off"));
  gui.add(shadowingOn.setup("Shadowing On"));
  gui.add(shadowingOff.setup("Shadowing Off"));
  // gui.add(reboot.setup("Reboot System"));
  gui.add(openStartupApplications.setup("Open Startup Applications"));
  gui.add(showCamera.setup("Toggle Webcam View",false));
  gui.add(openTempLog.setup("Get Temperature Log"));
  gui.add(openConfig.setup("Open Config File"));

  ofSetFullscreen(false);
  // cameraOn = false;
  // output = "opening camera";
  // cout << "opening camera" << endl;
  // vector<ofVideoDevice> devices = vidGrabber.listDevices();
  // for(size_t i = 0; i < devices.size(); i++){
  //     if(devices[i].bAvailable){
  //         //log the device
  //         ofLogNotice() << devices[i].id << ": " << devices[i].deviceName;
  //     }else{
  //         //log the device and note it as unavailable
  //         ofLogNotice() << devices[i].id << ": " << devices[i].deviceName << " - unavailable ";
  //     }
  // }
  // vidGrabber.setDeviceID(0);
  // vidGrabber.setDesiredFrameRate(60);
  // vidGrabber.initGrabber(640, 480);

}

//--------------------------------------------------------------
void ofApp::update(){

  if(lastShowCamera != showCamera){
    toggleCamera();
  }
  lastShowCamera = showCamera;

  if(showCamera){
    vidGrabber.update();
  }
}

//--------------------------------------------------------------
void ofApp::draw(){
  gui.draw();
  ofDrawBitmapString(output,10,250);
  if(showCamera){
    vidGrabber.draw(250,10, camWidth, camHeight);
  }
}

//--------------------------------------------------------------
void ofApp::sendProjectorOn(){
  cout << "sending projector on" << endl;
  output = ofSystem("/usr/local/bin/projectoron.sh");
  cout << "output : " << output << endl;
}

//--------------------------------------------------------------
void ofApp::sendProjectorOff(){
  cout << "sending projector off" << endl;
  output = ofSystem("/usr/local/bin/projectoroff.sh");
  cout << "output : " << output << endl;
}

//--------------------------------------------------------------
void ofApp::sendShadowingOn(){
  cout << "sending shadowing on" << endl;
  //If we use ofSystem it just waits for a response and doesn't progress
  system("nohup /usr/local/bin/teststartshadowing.sh &");
  //output = ofSystem("export DISPLAY=:0; /Downloads/of_v0.11.0_linux64gcc6_release/apps/myApps/ShadowingApp/bin/ShadowingApp &");
  //cout << "output : " << output << endl;
}

//--------------------------------------------------------------
void ofApp::sendShadowingOff(){
  cout << "sending shadowing off" << endl;
  output = ofSystem("/usr/local/bin/stopshadowing.sh");
  cout << "output : " << output << endl;
}

//--------------------------------------------------------------
void ofApp::sendReboot(){
  cout << "sending reboot" << endl;
  output = ofSystem("reboot");
  cout << "output : " << output << endl;
}


void ofApp::sendOpenStartupApplications(){
  cout << "opening startup applications" << endl;
  output = "opening session properties";
  system("gnome-session-properties &");
  // cout << "output : " << output << endl
}



void ofApp::toggleCamera(){
    // cameraOn = !cameraOn;
    if(showCamera){
      output = "opening camera";
      cout << "opening camera" << endl;
      vector<ofVideoDevice> devices = vidGrabber.listDevices();
      vidGrabber.setDeviceID(0);
      vidGrabber.setDesiredFrameRate(60);
      vidGrabber.initGrabber(camWidth, camHeight);
    }else{
      cout << "closing camera" << endl;
      output = "closing camera";
      vidGrabber.close();
    }
}

void ofApp::sendOpenTempLog(){
  cout << "opening temp log" << endl;
  output = "opening temperature logs";
  // system("tail -f /usr/local/bin/temp.log");
  output = ofSystem("tail -n 2 /usr/local/bin/temp.log");
}

void ofApp::sendOpenConfig(){
  cout << "opening config file"<<endl;
  output = "opening config file";
  system("gedit /usr/local/bin/config.txt");
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
