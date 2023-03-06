#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //when using a single array to represent a 2d array use: linearINdex = (row * numCols) + col; 
    large_image.load("cat100.jpg");
    small_image.load("cat28.jpg");
    font.load("franklinGothic.otf", 20);
    
    //dimensions of image
//    dim = small_image.getWidth();
    dim = large_image.getWidth();

    
    //prime the filter to make changes as 3x3 matrix
//    for(int i = 0; i < 3; i++){
//        vector <int> tmp;
//
//        tmp.push_back(-1);
//        tmp.push_back(0);
//        tmp.push_back(1);
//
//
//        filter.push_back(tmp);
//    }
    
    
    for(int i = -1; i <= 1; i++){
        
        vector <int> tmp;
        
        tmp.push_back(i);
        tmp.push_back(i);
        tmp.push_back(i);
        filter.push_back(tmp);

    }
    
    
    //loops through the image for each pixel (ignoring all the edge pixels)
    //the 1 / -1 offset is to account for edges with no neighboring pixels:
    for(int x = 1; x < dim - 1; x++){
        for(int y = 1; y < dim - 1; y++){
            vector<int> tmp_color;
            
            
//            tmp_color = run_filter(small_image, x, y, filter);
            tmp_color = run_filter(large_image, x, y, filter);
            
            //            tmp_color = run_filter(small_image, x, y, rand_filter);
//                        tmp_color = run_filter(large_image, x, y, rand_filter);
            
            final_image.push_back(tmp_color);
            
        }
    }
    

    

}

//--------------------------------------------------------------
vector<int> ofApp::run_filter(ofImage img, int x, int y, vector<vector<int>> filter){

    vector<int> rgb;
   
    
    int sumR = 0;
    int sumG = 0;
    int sumB = 0;
    
    //this is looping through the filter which should not be hard coded but is a 3x3
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
        
            ofColor temp_color;
            int factor = filter[i + 1][j + 1];
            
            int x_exp = x + i;
            int y_exp = y + j;
            int stop = 0;
            
            temp_color = img.getColor(x + i, y + j);
            
            sumR += temp_color.r * factor;
            sumG += temp_color.g * factor;
            sumB += temp_color.b * factor;
            
        }
    }
    
    rgb.push_back(sumR);
    rgb.push_back(sumG);
    rgb.push_back(sumB);

    
    return rgb;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    large_image.draw(10,10);
//    small_image.draw( 200, 10);
    
    font.drawString("Press 'r' to run a random filter", 10, 150);
    
    if(final_image.size()>0){
        
        
        font.drawString(ofToString(filter[0][0]), 250, 40);
        font.drawString(ofToString(filter[0][1]), 280, 40);
        font.drawString(ofToString(filter[0][2]), 310, 40);
        
        font.drawString(ofToString(filter[1][0]), 250, 70);
        font.drawString(ofToString(filter[1][1]), 280, 70);
        font.drawString(ofToString(filter[1][2]), 310, 70);
        
        font.drawString(ofToString(filter[2][0]), 250, 100);
        font.drawString(ofToString(filter[2][1]), 280, 100);
        font.drawString(ofToString(filter[2][2]), 310, 100);
        
        
        ofPushStyle();
        int i = 0;
        for(int x = 1; x < dim - 1; x++){
            for(int y = 1; y < dim - 1; y++){
                ofSetColor(final_image[i][0], final_image[i][1], final_image[i][2], 255);
                ofDrawRectangle(x + 120, y + 10, 1, 1);
                i += 1;
            }
        }
        if(i > dim * dim){
            i = 0;
        }
        ofPopStyle();
    }
    
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    
    if(key == 'c' || key == 'C'){
        filter.clear();
        final_image.clear();
        
    }
    
    if(key == 'r' || key == 'R'){
    
      
        filter.clear();
        final_image.clear();
        
        for(int i = -1; i <= 1; i++){
            
            vector <int> tmp;
            
            tmp.push_back(ofRandom(-2,2));
            tmp.push_back(ofRandom(-2,2));
            tmp.push_back(ofRandom(-2,2));

            filter.push_back(tmp);

        }
    
        
        
        //loops through the image for each pixel (ignoring all the edge pixels)
        //the 1 / -1 offset is to account for edges with no neighboring pixels:
        for(int x = 1; x < dim - 1; x++){
            for(int y = 1; y < dim - 1; y++){
                vector<int> tmp_color;
                
                tmp_color = run_filter(large_image, x, y, filter);
                
                final_image.push_back(tmp_color);
                
            }
        }
        
        
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
