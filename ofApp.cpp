#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(239);
	ofSetWindowTitle("Insta");

	ofNoFill();
	ofSetColor(39);
	ofSetLineWidth(1.5);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateX(90);

	float radius = 300;

	ofBeginShape();
	for (int deg = 0; deg < 360; deg += 1) {

		float x = radius * cos(deg * DEG_TO_RAD);
		float y = radius * sin(deg * DEG_TO_RAD);

		float noise_value = ofNoise(x * 0.005, y * 0.005, ofGetFrameNum() * 0.008);
		int z = noise_value * 10 + 1;
		z = z * 40 - 200;

		ofVertex(x, y, z);
	}
	ofEndShape(true);

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}