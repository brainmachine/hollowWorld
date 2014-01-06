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
    
};
/*
 01 StarID,
 02 HIP,
 03 HD,
 04 HR,
 05 Gliese,
 06 BayerFlamsteed,
 07 ProperName,
 08 RA,
 09 Dec,
 10 Distance,
 11 PMRA,
 12 PMDec,
 13 RV,
 14 Mag,
 15 AbsMag,
 16 Spectrum,
 17 ColorIndex,
 18 X,
 19 Y,
 20 Z,
 21 VX,
 22 VY,
 23 VZ
 */