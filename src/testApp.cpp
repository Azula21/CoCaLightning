#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetFrameRate(20);
    ofSetBackgroundColor(0, 0, 0);
	ofEnableAlphaBlending();
	
	mouseDown = false;
    
    // Make it so the hand can move across the entire Window.
    kHand.handLocationContainer.setWidth(ofGetWindowWidth());
    kHand.handLocationContainer.setHeight(ofGetWindowHeight());
}

//--------------------------------------------------------------
void testApp::update(){
    ofVec2f prev = handLocation;
    kHand.update();
    handLocation = kHand.handLocation;
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofSetColor(193, 50, 92 , 100); // sets kinect color
	ofRectangle(0, 0, ofGetWidth(), ofGetHeight());
    kHand.refinedMap.update();
    float offsetX = 512 * handLocation.x/ofGetWidth();
    float offsetY = 496 * handLocation.y/ofGetHeight();
    //ofSetColor(ofColor::red);
    kHand.refinedMap.draw(ofVec2f(handLocation.x-offsetX ,handLocation.y-offsetY));
    //ofSetColor(255, 255, 255); // Kinect COLOR
    ofNoFill();
		bolt.setup(handLocation.x,handLocation.y, ofRandom(0,ofGetWindowHeight()), ofRandom(0, ofGetWindowWidth()), 3, 120.0,.4);
		bolt.parse();
		bolt.draw();


    
    if (kinectDebug){
        ofSetColor(ofColor::red);
        ofDrawBox(handLocation, 30);
    }

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

	mouseDown = true;
	boltX = ofRandomWidth();
	//bolt.setup(boltX, ofRandom(0, ofGetWindowWidth()), mouseX, mouseY, 6, ofRandom(90, 110), 0.3);
//	bolt.parse();
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

	mouseDown = false;
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

