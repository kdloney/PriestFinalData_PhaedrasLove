#pragma once
#include "ofMain.h"

#define SPRING_CONSTANT 0.05f
#define MAX_VELOCITY 30.0f

// This 'swarm' object demonstrates a simple particle system
//  with 'simple harmonic motion'
class swarm : public ofNode {
	struct particle {
		ofVec3f position;
		ofVec3f velocity;
		ofColor color;
	};



	public:
		swarm();
		void init(int nParticles, float xDis, float yDis, float zDis, float velocityDispersion, float rVal, float gVal, float bVal, float aVal);
		void customDraw();
		ofLight light;

	protected:
		// we call this update function ourselves
		//  at the beginning of customDraw
		void update();

		// objects
		vector<particle>particles;
};