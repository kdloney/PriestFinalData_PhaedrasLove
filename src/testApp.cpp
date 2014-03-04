#include "testApp.h"

//--------------------------------------------------------------



const int width = 800;
const int height = 600;


void testApp::setup(){
    
	ofSetVerticalSync(true);
	ofBackground(0, 0, 0);
	ofEnableSmoothing();
	glEnable(GL_DEPTH_TEST);
    ofEnableLighting();
    
    ofSetFrameRate(10);
    ofSetSphereResolution(10);
    
	ofSetWindowTitle("Phaedra's Love");
    
    priestVar = 10;
    priestVarCross = 1;
    

    
	mainOutputSyphonServer.setName("Screen Output");
    
	mClient.setup();
    
    //using Syphon app Simple Server, found at http://syphon.v002.info/
    mClient.set("","Simple Server");
	
    tex.allocate(200, 100, GL_RGBA);
    
	//--
	// Setup cameras
    
	iMainCamera = 0;
	bCamParent = false;
    
    
	// front
	camFront.scale = 70;
	cameras[0] = &camFront;
    
    
	setupViewports();
    
}

//--------------------------------------------------------------
void testApp::setupViewports(){
	//call here whenever we resize the window
    
    
	//--
	// Define viewports
    
	//float xOffset = ofGetWidth() / 1;
	//float yOffset = ofGetHeight() / N_CAMERAS;
    
    float xOffset = ofGetWidth();
	float yOffset = ofGetHeight();
    
	//viewMain.x = xOffset;
	//viewMain.y = 0;
	//viewMain.width = xOffset * 2;
	//viewMain.height = ofGetHeight();
    
    
	for(int i = 0; i < N_CAMERAS; i++){
        
		viewGrid[i].x = xOffset;
		viewGrid[i].y = yOffset * i;
		//viewGrid[i].width = xOffset;
		//viewGrid[i].height = yOffset;
	}
    
	//
	//--
}

//--------------------------------------------------------------
void testApp::update(){
    
    
    
    
}


//--------------------------------------------------------------
void testApp::draw(){
    
    //Accused
    ofPopMatrix();
    nodeSwarm.init(1721, 10*priestVar, 100*priestVar, 75*priestVar, 10, 250, 250, 0, 190);
    ofPushMatrix();
    
    //Sued
    ofPopMatrix();
    nodeSwarm2.init(1281, 15*priestVar, 100*priestVar, 75*priestVar, 15, 201, 151, 0, 190);
    ofPushMatrix();
    
    //Sued
    ofPopMatrix();
    nodeSwarm3.init(424, 30*priestVar, 15*priestVar , 70*priestVar, 30, 255, 255, 255, 255);
    ofPushMatrix();
    
    //Arrested
    ofPopMatrix();
    nodeSwarm4.init(69, 60*priestVar, 15*priestVar , 80*priestVar, 15, 255, 200, 200, 255);
    ofPushMatrix();
    
    //Charged
    ofPopMatrix();
    nodeSwarm5.init(20, 60*priestVar, 15*priestVar , 80*priestVar, 20, 100, 255, 255, 255);
    ofPushMatrix();
    
    //Indicted
    ofPopMatrix();
    nodeSwarm6.init(14, 60*priestVar, 15*priestVar , 80*priestVar, 20, 255, 100, 100, 255);
    ofPushMatrix();
    
    //Settled
    ofPopMatrix();
    nodeSwarm7.init(363, 10*priestVar, 30*priestVar , 80*priestVar, 20, 150, 180, 30, 255);
    ofPushMatrix();
    
    //Aquitted
    ofPopMatrix();
    nodeSwarm8.init(12, 10*priestVar, 20*priestVar , 80*priestVar, 20, 255, 255, 50, 255);
    ofPushMatrix();
    
    //Cleared
    ofPopMatrix();
    nodeSwarm9.init(10, 10*priestVar, 10 *priestVar, 10*priestVar, 20, 200, 200, 255, 255);
    ofPushMatrix();
    
    //NotGuilty
    ofPopMatrix();
    nodeSwarm10.init(1, 10*priestVar, 10 *priestVar, 10*priestVar, 20, 255, 255, 0, 255);
    ofPushMatrix();
    
    //PoliceReport
    ofPopMatrix();
    nodeSwarm11.init(1, 10*priestVar, 100*priestVar , 50*priestVar, 20, 255, 0, 0, 255);
    ofPushMatrix();
    
    //Reinstated
    ofPopMatrix();
    nodeSwarm12.init(3, 10*priestVar, 100 *priestVar, 50*priestVar, 20, 255, 100, 100, 255);
    ofPushMatrix();
    
    //Sentenced
    ofPopMatrix();
    nodeSwarm13.init(1, 60*priestVar, 15*priestVar , 70*priestVar, 20, 255, 255, 200, 255);
    ofPushMatrix();
    
    
    
	// draw main viewport
	cameras[iMainCamera]->begin(viewMain);
	drawScene(iMainCamera);
    
    
	cameras[iMainCamera]->end();
    
	// draw side viewports
	for(int i = 0; i < N_CAMERAS; i++){
		cameras[i]->begin(viewGrid[i]);
		drawScene(i);
		cameras[i]->end();
	}
    
	//
    
	//--
	// Draw annotations (text, gui, etc)
    
	ofPushStyle();
	glDepthFunc(GL_ALWAYS); // draw on top of everything
    
    
	// restore the GL depth function
	glDepthFunc(GL_LESS);
	ofPopStyle();
    
	//
	//--
}

void testApp::drawScene(int iCameraDraw){
    
    ofPushMatrix();
    light.enable();
    light.setPointLight();
    light.setSpecularColor(255);
    light.setPosition(0, 0, 10);
    ofPopMatrix();
    
    ofPushMatrix();
    light.setSpotlight();
    light.setSpecularColor(255);
    light.setPosition(0, 0, 0);
    ofPopMatrix();
    
    ofPushMatrix();
    light.setPointLight();
    light.setSpecularColor(255);
    light.setPosition(0, 0, 60);
    ofPopMatrix();
    
    //Accused
    ofPushMatrix();
	nodeSwarm.draw();
    ofPopMatrix();
    
    //Sued
    ofPushMatrix();
    ofTranslate(0, 0);
    nodeSwarm2.draw();
    ofPopMatrix();
    
    //Convicted
    ofPushMatrix();
    ofTranslate(0, 15,10);
    nodeSwarm3.draw();
    ofPopMatrix();
    
    //Arrested
    ofPushMatrix();
    ofTranslate(0, 15);
    nodeSwarm4.draw();
    ofPopMatrix();
    
    //Charged
    ofPushMatrix();
    ofTranslate(0, 15);
    nodeSwarm5.draw();
    ofPopMatrix();
    
    //Indicted
    ofPushMatrix();
    ofTranslate(0, 15);
    nodeSwarm6.draw();
    ofPopMatrix();
    
    //Settled
    ofPushMatrix();
    ofTranslate(0, -40);
    nodeSwarm7.draw();
    ofPopMatrix();
    
    //Aquitted
    ofPushMatrix();
    ofTranslate(0, -30);
    nodeSwarm8.draw();
    ofPopMatrix();
    
    //Cleared
    ofPushMatrix();
    ofTranslate(0, -55);
    nodeSwarm9.draw();
    ofPopMatrix();
    
    //NotGuilty
    ofPushMatrix();
    ofTranslate(0, -55);
    nodeSwarm10.draw();
    ofPopMatrix();
    
    //PoliceReport
    ofPushMatrix();
    ofTranslate(0, 0);
    nodeSwarm11.draw();
    ofPopMatrix();
    
    //Reinstated
    ofPushMatrix();
    ofTranslate(0, 0);
    nodeSwarm12.draw();
    ofPopMatrix();
    
    //Sentenced
    ofPushMatrix();
    ofTranslate(0, 15);
    nodeSwarm13.draw();
    ofPopMatrix();
    
	    
    
	// First check if we're already drawing the view through the easycam
	// If so, don't draw the frustum preview.
	if(iCameraDraw != 0){
        
		ofPushStyle();
		ofPushMatrix();
        
		//--
		// Create transform for box->frustum
        
		// In 'camera space' the bounds of
		//  the view are defined by a box
		//  with bounds -1->1 in each axis
		//
		// To convert from camera to world
		//  space, we multiply by the inverse
		//  camera matrix of the camera, i.e
		//  inverse of the ViewProjection
		//  matrix.
		//
		// By applying this transformation
		//  our box in camera space is
		//  transformed into a frustum in
		//  world space.
		//
        
		// The camera's matricies are dependant on
		//  the aspect ratio of the viewport.
		//  (Which is why we use the viewport as
		//  an argument when we begin the camera.
		//
		// If this camera is fullscreen we'll use
		//   viewMain, else we'll use viewGrid[0]
		ofRectangle boundsToUse;
		if(iMainCamera == 0){
			boundsToUse = viewMain;
		}
		else{
			boundsToUse = viewGrid[0];
		}
        
		// Now lets get the inverse ViewProjection
		//  for the camera
		ofMatrix4x4 inverseCameraMatrix;
		inverseCameraMatrix.makeInvertOf(camEasyCam.getModelViewProjectionMatrix(boundsToUse));
        
		// By default, we can say
		//	'we are drawing in world space'
		//
		// The camera matrix performs
		//	world->camera
		//
		// The inverse camera matrix performs
		//	camera->world
		//
		// Our box is in camera space, if we
		//	want to draw that into world space
		//	we have to apply the camera->world
		//	transformation.
		//
        
		// This syntax is a little messy.
		// What it's saying is, send the data
		//  from the inverseCameraMatrix object
		//  to OpenGL, and apply that matrix to
		//  the current OpenGL transform
		ofMultMatrix( inverseCameraMatrix );
        
		//
		//--
        
        
        
		//--
		// Draw box in camera space
		// (i.e. frustum in world space)
        
		ofNoFill();
		// i.e. a box -1, -1, -1 to +1, +1, +1
		ofBox(0, 0, 0, 2.0f);
		//
		//--
        
               
		ofPopStyle();
		ofPopMatrix();
	}
    
    
    // Syphon Stuff
    
    mClient.draw(50, 50);
    
	mainOutputSyphonServer.publishScreen();

    

    // labels
    //ofSetColor(255, 255, 255);
    //ofDrawBitmapString("Phaedra's Love: Morals", -90, 65);
    //ofDrawBitmapString("Press and hold 'p' to see the morals of our world more clearly", -90, 55);

 

    
	//
	//--
}

//--------------------------------------------------------------



//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
	if(key == 'f'){
		ofToggleFullscreen();
        
	}
  
    if(key == 'p'){
        if(priestVar > priestVarCross){
            priestVar--;
        }
    }
    
    /*
    if(key == 'p'){
        for(int i=10; i>0; i--){
            priestVar = i;
        }
    }
*/

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
    

    if(key == 'p'){
        
        for(int i=0; i<12; i++){
          priestVar = i++;
        }
       // priestVar = 10;
    }
     
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
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
	setupViewports();
}

