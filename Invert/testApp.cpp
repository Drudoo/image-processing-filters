//
//  Copyright 2014 Frederik Vanggaard
//
//   Licensed under the Apache License, Version 2.0 (the "License");
//   you may not use this file except in compliance with the License.
//   You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
//   Unless required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BASIS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permissions and
//   limitations under the License.
//
//
//  testApp.cpp
//  
//
//  Created by Frederik Vanggaard on 2014-03-16
//
//  Contact: contact@drudoo.com
//  
//

#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    w = 320; //setup width and height of the video stream. 
	h = 240; //Too big can cause lag when trying to processing all the pixels.
	
    //Initialize the video grabber.
	vidGrabber.setVerbose(true); 
	vidGrabber.initGrabber(w,h);
    
    //Creates a new unsigned char that can hold 320*240*3=230400 pixels.
    output = new unsigned char[w*h*3];

    //Allocated a new video texture 
    videoTexture.allocate(w,h,GL_RGB);
}

//--------------------------------------------------------------
void testApp::update(){

    //Prior to OF 8.0, use .grabFrame() instead of .update().     
    vidGrabber.update();
    
    //If there is a new frame do the following.
    if (vidGrabber.isFrameNew()) {
        int totalPixels = w*h*3;
        unsigned char * pixels = vidGrabber.getPixels(); //grab all the pixels from the video.
        for (int i = 0; i < totalPixels; i++) { //For every pixel in the image 
            output[i] = 255 - pixels[i]; //Subtract the pixel value from 255.
        }
        
        //Loads the new pixels into the texture.
        videoTexture.loadData(output, w, h, GL_RGB);
    }
}

//--------------------------------------------------------------
void testApp::draw(){

    ofSetColor(255);
    vidGrabber.draw(0, 0); //Draw the raw video.
    videoTexture.draw(w,0,w,h); //Then draw the inverted video next to it.
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------

void testApp::keyReleased(int key){
    
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
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
    
}