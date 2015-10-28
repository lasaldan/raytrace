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
#include "ppm.h"

class raytracer {
private:
    ppm image;
public:
    raytracer();
    ppm render(scene, window);
};

#endif /* defined(__raytrace__raytracer__) */
