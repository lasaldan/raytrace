//
//  raytracer.cpp
//  raytrace
//
//  Created by Daniel Fuller on 10/27/15.
//  Copyright (c) 2015 Daniel Fuller. All rights reserved.
//

#include "raytracer.h"

raytracer::raytracer() {
    image = ppm(WINDOW_WIDTH, WINDOW_HEIGHT);
}

ppm
raytracer::render(scene s, window w) {
    
    image.setPixel(2,2,color(255,255,255));
    image.setPixel(2,4,color(255,255,255));
    image.setPixel(4,3,color(255,255,255));
    image.setPixel(6,2,color(255,255,255));
    image.setPixel(7,3,color(255,255,255));
    image.setPixel(6,4,color(255,255,255));
    
    return image;
}