#pragma once

//--------------------------------------------------------------
//
//
// ADVANCED 3D EXAMPLE
//		ofNode3d, ofCamera, ofEasyCam
//
//
//--------------------------------------------------------------


#include "ofMain.h"

// Custom objects for this example
#include "Swarm.h"

//#include "Grid.h"
#include "OrthoCamera.h"
#include "ofxSyphon.h"

#define N_CAMERAS 1

class testApp : public ofBaseApp {
    
public:
    void setup();
    void update();
    void draw();
    
    void setupViewports();
    void drawScene(int iCameraDraw);
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    
    //cameras (all these inherit from ofCamera)
    ofEasyCam camEasyCam;
    orthoCamera camFront;
    orthoCamera camTop;
    orthoCamera camLeft;
    
    //cameras have parent?
    bool bCamParent;
    
    //camera pointers
    ofCamera * cameras[N_CAMERAS];
    int iMainCamera;
    
    //viewports
    ofRectangle viewMain;
    ofRectangle viewGrid[N_CAMERAS];
    
    //my custom node
    swarm nodeSwarm;
    swarm nodeSwarm2;
    swarm nodeSwarm3;
    swarm nodeSwarm4;
    swarm nodeSwarm5;
    swarm nodeSwarm6;
    swarm nodeSwarm7;
    swarm nodeSwarm8;
    swarm nodeSwarm9;
    swarm nodeSwarm10;
    swarm nodeSwarm11;
    swarm nodeSwarm12;
    swarm nodeSwarm13;
    
    
    // grid nodeGrid;
    
    
    ofLight light;
    
    float 	counter;
	bool	bSmooth;
	
    ofTexture tex;
    
	ofxSyphonServer mainOutputSyphonServer;
	ofxSyphonServer individualTextureSyphonServer;
	
	ofxSyphonClient mClient;
    
    float priestVar;
    float priestVarCross;
    
    ofTrueTypeFont	verdana14;
    ofTrueTypeFont	verdana30;
    
    bool bFirst;
    string typeStr;
    

    
};

