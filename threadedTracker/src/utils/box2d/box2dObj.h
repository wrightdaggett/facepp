/*
 *  box2dObj.h
 *  face_
 *
 *  Created by 真鍋 大度 on 11/05/30.
 *  Copyright 2011 Rhizomatiks. All rights reserved.
 *
 */

#pragma once


//#include "baseScene.h"
#include "ofMain.h"

#include "ofxBox2d.h"


class CustomCircle : public ofxBox2dCircle {
	
public:
	
	float radius;
	bool bCollition;
	ofPoint previousVelocity;
	ofPoint currentVelocity;
	CustomCircle() {
		bCollition = false;
		currentVelocity.set(0, 0);
		previousVelocity.set(0, 0);
		color.r = ofRandom(155);
		color.b = ofRandom(255); 
		color.g = ofRandom(255); 
		color2 = color;
	} 
	
	void update(){
		
		bCollition = false;
		currentVelocity=getVelocity();
		float angleDiff = (atan2(previousVelocity.y, previousVelocity.x) - atan2(currentVelocity.y, currentVelocity.x));
		while (angleDiff < -PI) angleDiff += TWO_PI;
		while (angleDiff > PI) angleDiff -= TWO_PI;
		
		if (fabs(angleDiff) > PI/1.3) {
			if (currentVelocity.length() > 2.3){
				bCollition = true;
				//printf("collision %f %f \n", getPosition().x, getPosition().y);
			}
		}
		previousVelocity = currentVelocity;
	}
	
	ofColor color;
	ofColor color2;
	void draw() {
		radius = getRadius();
		
		glPushMatrix();
		glTranslatef(getPosition().x, getPosition().y, 0);
		ofEnableAlphaBlending();
		ofSetColor(color.r, color.g, color.b);
//		ofNoFill();
		ofFill();
		ofEnableSmoothing();
		ofSetCircleResolution(44);		
		ofCircle(0, 0, radius);	
		glPopMatrix();
		//printf("%f %f \n", getPosition().x, getPosition().y);
		bCollition = false;
	}
};


class CustomPoly : public ofxBox2dPolygon {
	
public:
	CustomPoly(){
		
	}
	ofColor color;
	bool bFill;
	
	void draw2(){
		if(body != NULL ) {
			ofNoFill();
			ofSetColor(2, 255, 255, 255);
			
			ofBeginShape();
			for(int i=0; i<vertices.size(); i++) {
				ofVertex(vertices[i].x, vertices[i].y);
			}
			
			ofEndShape();
//			
//			ofSetColor(255, 255,255);
//			ofPoint c = getCenter();
//			ofCircle(c.x, c.y, 1);
//			ofSetColor(0, 0, 0);
			return;
			
		}
		
	}
	
	
};
