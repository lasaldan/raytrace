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
sphere::impactedBy(Vector d, Vertex o) {
    
    //float A = d.x*d.x + d.y*d.y + d.z*d.z;
    //float B = 2*(d.x*o.x - d.x*center.x + d.y*o.y - d.y*center.y * d.z*o.z - d.z*center.z);
    //float C = o.x*o.x - 2*(o.x*center.x) + center.x*center.x - 2*(o.y*center.y) + center.y*center.y + o.z*o.z - 2*(o.z*center.z) + center.z*center.z - radius*radius;
    Vertex &c = center;
    float &r = radius;
    
    //d = Vector(0, .2, 0);
    //o = Vertex(0, 0, 1.2);
    
    
    float B = 2.0f*(d.x*o.x - d.x*c.x + d.y*o.y - d.y*c.y + d.z*o.z - d.z*c.z);
    float C = o.x*o.x - 2.0f*o.x*c.x + c.x*c.x + o.y*o.y - 2.0f*o.y*c.y + c.y*c.y + o.z*o.z - 2.0f*o.z*c.z + c.z*c.z - r*r;
    
    float D = B*B - 4.0f*C;
    
    if(D <= 0) {
        // missed the sphere
        return Vertex(1, 1, -1);
    }
    else {
        // hit the sphere - calculate hit point
        return Vertex();
    }
}