//
//  scene.h
//  raytrace
//
//  Created by Daniel Fuller on 10/27/15.
//  Copyright (c) 2015 Daniel Fuller. All rights reserved.
//

#ifndef __raytrace__scene__
#define __raytrace__scene__

#include <stdio.h>
#include <vector>
#include "color.h"
#include "item.h"
#include "light.h"
#include "polygon.h"
#include "sphere.h"

class scene {
public:
    color backgroundColor;
    color ambientLightColor;
    std::vector<sphere> spheres;
    std::vector<polygon> polygons;
    std::vector<light> lights;
    scene();
    void setBackgroundColor(color);
    void setAmbientLightColor(color);
    void addSphere(sphere);
    void addPolygon(polygon);
    void addLight(light);
};

#endif /* defined(__raytrace__scene__) */
