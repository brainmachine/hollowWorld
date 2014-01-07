

#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(0, 0, 0);
	// Load a CSV File.
	csv.loadFile(ofToDataPath("hygxyzSmall.csv"));
    
    // Set mesh mode to points
    mesh.setMode(OF_PRIMITIVE_POINTS);
    
    // GL Settings
	glEnable(GL_POINT_SMOOTH); // use circular points instead of square points
    
    // Cam stuff
    
    // Get x, y, z coordinates from csv data
	cout << "Maximum Size:";
	cout << csv.data[0].max_size() << endl;
    ofLogNotice(ofToString(csv.data.size()));
    for (int i = 0; i < csv.data.size(); i++) {
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
	ofLogNotice(ofToString(key));
    
    // Up
    if (key == 357) {
        
    }
    
    // Down
    if (key == 359) {
        
    }
    
    // Left
    if (key == 356) {
        
    }
    
    // Right
    if (key == 358) {
        
    }
     O:
     O356:
     O358:
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
