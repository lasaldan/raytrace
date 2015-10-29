//
//  raytracer.h
//  raytrace
//
//  Created by Daniel Fuller on 10/27/15.
//  Copyright (c) 2015 Daniel Fuller. All rights reserved.
//

#ifndef __raytrace__raytracer__
#define __raytrace__raytracer__

#include <stdio.h>
#include "scene.h"
#include "window.h"
#include "sphere.h"
#include "ppm.h"
#include "math.h"

#define PI 3.14159265358979

class raytracer {
private:
    ppm image;
    float pixelWidth;
    float calculatePixelWidth( window );
public:
    raytracer();
    ppm render(scene, window);
};

#endif /* defined(__raytrace__raytracer__) */
