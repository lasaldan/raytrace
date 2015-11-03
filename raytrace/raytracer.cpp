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
    
    for(float row=0; row < WINDOW_HEIGHT; row++) {
        float destinationY = (WINDOW_HEIGHT / 2 - row) * pixelWidth - (pixelWidth / 2);
        
        for(float col=0; col < WINDOW_WIDTH; col++) {
            float destinationX = (-WINDOW_WIDTH / 2 + col) * pixelWidth + (pixelWidth / 2);
            
            Vector direction = Vector::Normalize( Vector(destinationX, destinationY, -origin.getZ()) );
            
            color pixelColor = s.backgroundColor;
            
            for(int i = 0; i < s.polygons.size(); i++) {
                Vertex impactPoint = s.polygons[i].getImpactLocation(direction, origin);
                
                if( impactPoint.x == 0 && impactPoint.y == 0 && impactPoint.z == 0)
                    continue;
                
                pixelColor = color(255,0,0);
                  
            }
            
            for(int i = 0; i < s.spheres.size(); i++) {
                //cout << "(" << destinationX << "," << destinationY << ",1), ";
                
                Vertex impactPoint = s.spheres[i].getImpactLocation(direction, origin);
                
                if( impactPoint.x == 0 && impactPoint.y == 0 && impactPoint.z == 0)
                    continue;
                
                pixelColor = s.spheres[i].diffuse;
                
            }
            
            image.setPixel(row,col, pixelColor);
            
        }
    }
    
    
    return image;
}