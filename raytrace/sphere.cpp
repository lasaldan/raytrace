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

Vertex
sphere::impactedBy(Vector d, Vertex o) {
    
    //float A = d.x*d.x + d.y*d.y + d.z*d.z;
    //float B = 2*(d.x*o.x - d.x*center.x + d.y*o.y - d.y*center.y * d.z*o.z - d.z*center.z);
    //float C = o.x*o.x - 2*(o.x*center.x) + center.x*center.x - 2*(o.y*center.y) + center.y*center.y + o.z*o.z - 2*(o.z*center.z) + center.z*center.z - radius*radius;
    
    float B = 2*(d.x*o.x - d.x*center.x + d.y*o.y - d.y*center.y + d.z*o.z - d.z*center.z);
    float C = o.x*o.x - 2*(o.x*center.x) + center.x*center.x - 2*(o.y*center.y) + center.y*center.y + o.z*o.z - 2*(o.z*center.z) + center.z*center.z - radius*radius;
    
    float D = B*B - 4*C;
    
    if(D < -5.8)
        return Vertex(1, 1, -1);
    else
        return Vertex();
}