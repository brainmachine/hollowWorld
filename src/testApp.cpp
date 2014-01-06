

#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	// Load a CSV File.
	csv.loadFile(ofToDataPath("hygxyzSmall.csv"));
	
	cout << "Print out a specific CSV value" << endl;
	cout << csv.data[0][1] << endl;
	// also you can write...
	//cout << csv.data[0].at(1) << endl;
	
	cout << "Print out the first value" << endl;
	cout << csv.data[0].front() << endl;
	
	cout << "Maximum Size:";
	cout << csv.data[0].max_size() << endl;
    for (int i = 0; i < 10; i++) {
        // X value
        ofLogNotice("X: "+ofToString(csv.data[i][17]+" Y: "+ofToString(csv.data[i][18])+" Z: "+ofToString(csv.data[i][19])));
        //
        //
        float x = csv.getFloat(i, 17);
        float y = csv.getFloat(i, 18);
        float z = csv.getFloat(i, 19);
        ofVec3f pos(x, y, z);
        mesh.addVertex(pos);
    }
	
}

//--------------------------------------------------------------
void testApp::update(){
	
}

//--------------------------------------------------------------
void testApp::draw(){
    cam.begin();
	ofScale(2, -2, 2); // flip the y axis and zoom in a bit
	ofRotateY(90);
	mesh.draw();
	cam.end();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
	if (key == 's') {
		// Get a specific value as inegert, float, String etc.
		csv.setInt(0, 0, 2305);
		cout << "getInt: " << csv.getInt(0, 0) << endl;
		csv.setFloat(0, 1, 23.666);
		cout << "getFloat: " << csv.getFloat(0, 1) << endl;
		csv.setString(0, 2, "helloworld");
		cout << "getString: " << csv.getString(0, 2) << endl;
		csv.setBool(0, 3, true);
		cout << "getBool: " << csv.getBool(0, 3) << endl;
		
		// Save File.
		csv.saveFile(ofToDataPath("savefile.csv"));
	}
	else if (key == 'x') {
		// clear all data from csvRecorder
		csvRecorder.clear();
	}
	else if (key == 'r') {
		// Save the recorded values in the csvRecorder ofxCsv object
		csvRecorder.saveFile( ofToDataPath( "MyRecordedMouseData.csv" ));
		ofLog() << "Saved " << csvRecorder.numRows << " rows of mouse data";
	}
	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	
	// Create a new File.
	csv.createFile(ofToDataPath("createfile.csv"));
	
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	
	// Add the current cursor position to the mouseData
	int row = csvRecorder.numRows;
	csvRecorder.setInt(row, 0, x);
	csvRecorder.setInt(row, 1, y);
	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
	// change the recording state for the mouse
	recordingMouse = true;
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	
	// change the recording state for the mouse
	recordingMouse = false;
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
	
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
	
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
	
}
