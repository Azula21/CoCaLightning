#include "testApp.h"
#include <iostream>

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetFrameRate(20);
    ofSetBackgroundColor(255, 255, 255);
	ofEnableAlphaBlending();
	
	mouseDown = false;
    
    // Make it so the hand can move across the entire Window.
    kHand.handLocationContainer.setWidth(ofGetWindowWidth());
    kHand.handLocationContainer.setHeight(ofGetWindowHeight());
    //lowest x: 670 highest x: 1390
    //lowest y: 1197 highest y: 1460
 
    
    for(int i = 0; i < rainParticles; i++){
        rainPositions.push_back(ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight())));
        rainVelocity.push_back(ofRandom(5,25));
    }
}

//--------------------------------------------------------------
void testApp::update(){
    ofVec2f prev = handLocation;
    kHand.update();
    handLocation = kHand.handLocation;
	
}

//--------------------------------------------------------------
void testApp::draw(){
    //rain
    ofSetColor(100,30);
    ofSetLineWidth(0.5);
    for(int i = 0; i < rainParticles; i++){
        ofSetColor(100,rainVelocity[i]*2);
        rainPositions[i].y += rainVelocity[i];
        if(rainPositions[i].y > ofGetHeight()){rainPositions[i].y = -200;}
        ofDrawLine(rainPositions[i].x, rainPositions[i].y, rainPositions[i].x, rainPositions[i].y+rainVelocity[i]*15);
    }
    //lightning
	ofSetColor(193, 50, 92 , 100); // sets kinect color
	ofRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    //KinectStuff
    kHand.refinedMap.update();


    if (kinectDebug){
        ofSetColor(255,0,0);
        ofDrawBox(handLocation, 10);
    }
    std::cout << "x: " << handLocation.x << " " << "y: " << handLocation.y << std::endl;
    float handx = ofMap(handLocation.x, 87, 500, 1800, 0);
    float handy = ofMap(handLocation.y, 1100, 1460, 0, 1000);

    float offsetX = 512 * handx/ofGetWidth();
    float offsetY = 496 * handy/ofGetHeight();
    //  ofSetColor(0,255,0);
    kHand.refinedMap.draw(ofVec2f(handLocation.x ,handLocation.y));
    //std::cout << "handx: " << handx << " " << "handy: " << handy << std::endl;
    bolt.setup(handx-offsetX,handy-offsetY, ofRandom(0,ofGetWindowHeight()), ofRandom(0, ofGetWindowWidth()), ofRandom(5, 7), ofRandom(100.0,150.0), 2.0);
    //bolt.setup(500,500, ofRandom(0,ofGetWindowHeight()), ofRandom(0, ofGetWindowWidth()), ofRandom(5, 7), ofRandom(100.0,150.0), 2.0);
    bolt.parse();
    bolt.draw();

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
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

	mouseDown = false;
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

