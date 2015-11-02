//
//  raytracer.cpp
//  raytrace
//
//  Created by Daniel Fuller on 10/27/15.
//  Copyright (c) 2015 Daniel Fuller. All rights reserved.
//

#include "raytracer.h"
using namespace std;

raytracer::raytracer() {
    image = ppm(WINDOW_WIDTH, WINDOW_HEIGHT);
}

float
raytracer::calculatePixelWidth(window w) {
    float viewDistance = w.getLookFrom().getZ();
    float viewportWidth = viewDistance * tan(w.getFieldOfView() * PI / 180) * 2;
    return viewportWidth / WINDOW_WIDTH;
}

ppm
raytracer::render(scene s, window w) {
    
    float viewDistance = w.getLookFrom().getZ();
    float viewportWidth = viewDistance * tan((w.getFieldOfView()/2) * PI / 180) * 2;
    pixelWidth = viewportWidth / WINDOW_WIDTH;
    
    Vertex origin = w.getLookFrom();
    
    // assuming square image
    //float cornerPixelDistance = (WINDOW_WIDTH / 2) * pixelWidth - (pixelWidth / 2);
    
    for(float row=0; row < WINDOW_HEIGHT; row++) {
        float destinationY = (WINDOW_HEIGHT / 2 - row) * pixelWidth - (pixelWidth / 2);
        
        for(float col=0; col < WINDOW_WIDTH; col++) {
            float destinationX = (-WINDOW_WIDTH / 2 + col) * pixelWidth + (pixelWidth / 2);
            
            Vector direction = Vector::Normalize( Vector(destinationX, destinationY, -1.2) );
            
            for(int i = 0; i < s.spheres.size(); i++) {
                //cout << "(" << destinationX << "," << destinationY << ",1), ";
                
                Vertex impactPoint = s.spheres[i].impactedBy(direction, origin);
                
                if( impactPoint.getZ() == -1 ) {
                    
                    image.setPixel(row,col,s.backgroundColor);
                    
                }
                else {
                    
                    image.setPixel(row,col,color(255,255,0));
                }
            }
        }
    }
    
    
    return image;
}