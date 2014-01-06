

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
        ofLogNotice(ofToString(csv.data[i]));
    }
	
}

//--------------------------------------------------------------
void testApp::update(){
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofSetColor(0);
	ofFill();
	ofDrawBitmapString("CSV FILE", 200, 50);
	
	// Check how many rows exist.
	ofDrawBitmapString("csv rows: " + ofToString(csv.numRows), 200, 70);
	// Check how many column exist.
	// For that we reat the first line from CSV. (data[0])
	ofDrawBitmapString("csv cols: " + ofToString(csv.data[0].size()), 200, 90);
	
	// Print out all rows and cols.
	for(int i=0; i<csv.numRows; i++) {
		for(int j=0; j<csv.data[i].size(); j++) {
			ofDrawBitmapString(csv.data[i][j], 200+j*100, 150+i*20);
		}
	}
	
	ofDrawBitmapString("CSV VECTOR STRING", 200, 350);
	// Read a CSV row as simple String.
	vector<string> dataExample = csv.getFromString("0x11120119][100][40][445][23][543][46][24][56][14][964][12", "][");
	//cout << "dataExample[0]" << dataExample[0] << endl;
	
	// Print the hole CSV data string to console.
	for(int i=0; i<dataExample.size(); i++) {
		ofDrawBitmapString("[" + ofToString(i) + "]: " + ofToString(dataExample[i]), 200, 370+i*20 );
	}
	
	// Show the current mouse recording state
	ofDrawBitmapString("CSV RECORDER", 500, 350);
	ofDrawBitmapString("csv rows: " + ofToString(csvRecorder.numRows), 500, 370);
	
	if (recordingMouse == true) {
		ofDrawBitmapString("state: recording...", 500, 390);
	}
	else {
		ofDrawBitmapString("state: ready", 500, 390);
	}
	
	ofDrawBitmapString("CONTROLS", 200, 690);
	ofDrawBitmapString("s = save csv data / x = clear csvRecorder data / r = save csvRecorder data", 200, 710);
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
