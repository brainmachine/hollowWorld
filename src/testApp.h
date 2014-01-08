#pragma once

#include "ofMain.h"
#include "ofxCsv.h"

using namespace wng;

class testApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
	
    ofxCsv csv;
    ofxCsv csvRecorder;
	
    bool recordingMouse;
    
    ofEasyCam cam;
    float camX, camY, camZ;
    float maxX, maxY, maxZ;
    float minX, minY, minZ;
    
    ofVec3f camPos;
    
    ofMesh mesh;
    
};
/*
 
 00 StarID,
 01 HIP,
 02 HD,
 03 HR,
 04 Gliese,
 05 BayerFlamsteed,
 06 ProperName,
 07 RA,
 08 Dec,
 09 Distance,
 10 PMRA,
 11 PMDec,
 12 RV,
 13 Mag,
 14 AbsMag,
 15 Spectrum,
 16 ColorIndex,
 17 X,
 18 Y,
 19 Z,
 20 VX,
 21 VY,
 22 VZ
 
 */