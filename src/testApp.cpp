

#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(0, 0, 0);
	// Load a CSV File.
	csv.loadFile(ofToDataPath("hygxyz.csv"));
    
    // Set mesh mode to points
    mesh.setMode(OF_PRIMITIVE_POINTS);
//    mesh.setMode(OF_PRIMITIVE_TRIANGLES);
    // GL Settings
	ofEnableDepthTest();
    glEnable(GL_POINT_SMOOTH); // use circular points instead of square points
    
    // Cam stuff
    camX = 0;
    camY = 0;
    camZ = 0;
   // cam.setPosition(camX, camY, camZ);
   
    speed = 1;
    jumpSize = 10;
    counter = 0;
    
    // Max and min coordinates
    maxX, maxY, maxZ, minX, minY, minZ = 0;
    
    
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
        
        //min and max values
        if (maxX < x) {
            maxX = x;
        }
        if (maxY < y) {
            maxY = y;
        }
        if (maxZ < z) {
            maxZ = z;
        }
        if (minX > x) {
            minX = x;
        }
        if (minY > y) {
            minY = y;
        }
        if (minZ > z) {
            minZ = z;
        }
    }
    
     cam.setPosition(maxX, maxY, minZ); // start at the edge of the universe
    
	ofLogNotice("maxX "+ofToString(maxX)+" maxY "+ofToString(maxY)+" maxZ" + ofToString(maxZ));
    ofLogNotice("minX "+ofToString(minX)+" minY "+ofToString(minY)+" minZ" + ofToString(minZ));
}

//--------------------------------------------------------------
void testApp::update(){
    counter++;
    if (counter < csv.data.size()) {
        ofLine(csv.getFloat(17, counter), csv.getFloat(18, counter),csv.getFloat(17, counter+1), csv.getFloat(18, counter+1));
    
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    cam.begin();
	mesh.draw();
	cam.end();
}

//--------------------------------------------------------------
void getExtremeVec(ofVec3f vector) {

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
