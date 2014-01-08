

#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(0, 0, 0);
	// Load a CSV File.
	csv.loadFile(ofToDataPath("hygxyz.csv"));
    
    // Set mesh mode to points
//    mesh.setMode(OF_PRIMITIVE_POINTS);
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    // GL Settings
	ofEnableDepthTest();
    glEnable(GL_POINT_SMOOTH); // use circular points instead of square points
    
    // Cam stuff
    camX = 0;
    camY = 0;
    camZ = 0;
    cam.setPosition(camX, camY, camZ);
    speed = 1;
    jumpSize = 100;
    
    // Max and min coordinates
    
    // Get x, y, z coordinates from csv data
	cout << "Maximum Size:";
	cout << csv.data[0].max_size() << endl;
    ofLogNotice(ofToString(csv.data.size()));
    for (int i = 0; i < csv.data.size(); i++) {
        // X value
        //ofLogNotice("X: "+ofToString(csv.data[i][17]+" Y: "+ofToString(csv.data[i][18])+" Z: "+ofToString(csv.data[i][19])));
        //
        float x = csv.getFloat(i, 17);
        float y = csv.getFloat(i, 18);
        float z = csv.getFloat(i, 19);
        ofVec3f starVec(x, y, z);
        mesh.addVertex(starVec);
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
    
    // Up key - Forward
    if (key == 357) {
        camZ-=speed*jumpSize;
    }
    
    // Down key - backward
    else if (key == 359) {
        camZ+=speed*jumpSize;
            }
    
    // Left
    else if (key == 356) {
        camX-=speed*jumpSize;
    }
    
    // Right
    else if (key == 358) {
        camX+=speed*jumpSize;
    }
    
    // U - Up
    else if (key == 117) {
        camY+=speed*jumpSize;
    }
    
    // J - Down
    else if (key == 106) {
        camY-=speed*jumpSize;

    }
    
    // I key - Increase speed
    else if (key == 105) {
        speed*jumpSize++;
    }
    // K key - decrease (kill) speed
    else if (key == 107) {
        speed*jumpSize--;
    }
    cam.setPosition(camX, camY, camZ);
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
