//
//  sphere.cpp
//  raytrace
//
//  Created by Daniel Fuller on 10/27/15.
//  Copyright (c) 2015 Daniel Fuller. All rights reserved.
//

#include "sphere.h"
using namespace std;

sphere::sphere() {
    
}

sphere::sphere(Vertex v, float r) {
    center = v;
    radius = r;
}

Vertex
sphere::getImpactLocation(Vector d, Vertex o) {
    
    Vertex &c = center;
    float &r = radius;

    float B = 2.0f*(d.x*o.x - d.x*c.x + d.y*o.y - d.y*c.y + d.z*o.z - d.z*c.z);
    float C = o.x*o.x - 2.0f*o.x*c.x + c.x*c.x + o.y*o.y - 2.0f*o.y*c.y + c.y*c.y + o.z*o.z - 2.0f*o.z*c.z + c.z*c.z - r*r;
    
    // Calculate Determinant
    float D = B*B - 4.0f*C;
    
    if(D <= 0) {
        // missed the sphere
        return noImpact();
    }
    else {
        // hit the sphere - calculate hit point
        //float A = d.x*d.x + d.y*d.y + d.z*d.z;

        return Vertex(1,1,1);
    }
}