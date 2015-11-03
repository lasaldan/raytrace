//
//  sphere.h
//  raytrace
//
//  Created by Daniel Fuller on 10/27/15.
//  Copyright (c) 2015 Daniel Fuller. All rights reserved.
//

#ifndef __raytrace__sphere__
#define __raytrace__sphere__

#include <stdio.h>
#include "Vertex.h"
#include "item.h"

class sphere : public item {
public:
    sphere();
    sphere(Vertex, float);
    Vertex getImpactLocation(Vector d, Vertex o);
private:
    Vertex center;
    float radius;
};

#endif /* defined(__raytrace__sphere__) */
