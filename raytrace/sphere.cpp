//
//  sphere.cpp
//  raytrace
//
//  Created by Daniel Fuller on 10/27/15.
//  Copyright (c) 2015 Daniel Fuller. All rights reserved.
//

#include "sphere.h"

sphere::sphere() {
    
}

sphere::sphere(Vertex v, float r) {
    center = v;
    radius = r;
}