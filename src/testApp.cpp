

#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(0, 0, 0);
	// Load a CSV File.
	csv.loadFile(ofToDataPath("hygxyzSmall.csv"));
    mesh.setMode(OF_PRIMITIVE_POINTS);
    ofEnableDepthTest();
	glEnable(GL_POINT_SMOOTH); // use circular points instead of square points
	//glPointSize(3); // make the points bigger
    
	cout << "Maximum Size:";
	cout << csv.data[0].max_size() << endl;
    for (int i = 0; i < 2000; i++) {
        // X value
        ofLogNotice("X: "+ofToString(csv.data[i][17]+" Y: "+ofToString(csv.data[i][18])+" Z: "+ofToString(csv.data[i][19])));
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
	mesh.draw();
	cam.end();
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
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	
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
