//
//  polygon.cpp
//  raytrace
//
//  Created by Daniel Fuller on 10/27/15.
//  Copyright (c) 2015 Daniel Fuller. All rights reserved.
//

#include "polygon.h"
#include <iostream>

polygon::polygon() {
    
}
void
polygon::addVertex(Vertex v) {
    vertices.push_back(v);
    
    if(vertices.size() == 3) {
        Vector pt1 = Vector( vertices[0].x, vertices[0].y, vertices[0].z );
        Vector pt2 = Vector( vertices[1].x, vertices[1].y, vertices[1].z );
        Vector pt3 = Vector( vertices[2].x, vertices[2].y, vertices[2].z );
        normal = Vector::Normalize( Vector::Cross( Vector::Minus(pt1, pt2), Vector::Minus(pt2, pt3) ) );
    }
}

Vertex
polygon::getPlaneImpactLocation(Vector& rd, Vertex& ro) {
    
    Vector cameraLocation = Vector(ro.x, ro.y, ro.z);
    Vector toOrigin = Vector(vertices[0].x, vertices[0].y, vertices[0].z);
    
    // Find out how far the plane lies from the origin
    float d = Vector::Dot(toOrigin, normal);
    d = (d<0)? d*-1 : d;
    
    float vd = Vector::Dot(normal, rd);
    
    // Check if ray is parallel to plane in question
    if( vd == 0)
        return noImpact();
    
    float vo = -(Vector::Dot(normal, cameraLocation) + d);
    
    float t = vo / vd;
    
    if(t < 0)
        return noImpact();
    
    if (vd > 0) {
        rd.x = -rd.x;
        rd.y = -rd.y;
        rd.z = -rd.z;
    }
    
    return Vertex( ro.x + rd.x * t, ro.y + rd.y * t, ro.z + rd.z * t);
}

Vertex
polygon::getImpactLocation(Vector rd, Vertex ro) {
    
    Vertex impact = getPlaneImpactLocation(rd, ro);
    
    if(impact.x == 0 && impact.y == 0 && impact.z == 0) {
        return noImpact();
    }
    
    // Determine highest magnitude of normal for projection
    int majorAxis = 0;
    //float absx = (normal.x > 0) ? normal.x : -normal.x;
    //float absy = (normal.y > 0) ? normal.y : -normal.y;
    //float absz = (normal.z > 0) ? normal.z : -normal.z;
    
    Vertex pt1 = vertices[0];
    Vertex pt2 = vertices[1];
    Vertex pt3 = vertices[2];
    
    // ensure there's always an x value for quick testing
    //if(absy > absx)
    //majorAxis = 1;
    //if(absz > absy)
        majorAxis = 2;
    
    // Project onto plane, not using the highest magnitude
    impact[majorAxis] = 0;
    pt1[majorAxis] = 0;
    pt2[majorAxis] = 0;
    pt3[majorAxis] = 0;
    
    // Translate polygon points so the impact is at the origin
    pt1.x = pt1.x + -impact.x;
    pt1.y = pt1.y + -impact.y;
    pt1.z = pt1.z + -impact.z;
        
    pt2.x = pt2.x + -impact.x;
    pt2.y = pt2.y + -impact.y;
    pt2.z = pt2.z + -impact.z;
    
    pt3.x = pt3.x + -impact.x;
    pt3.y = pt3.y + -impact.y;
    pt3.z = pt3.z + -impact.z;
    
    // Set numCrossings to 0 to keep track of how many edges are crossed
    int numCrossings = 0;
    int signHolder = 1;
    int nextSignHolder = -1;
    
    if(pt1.y < 0)
        signHolder = -1;

    for(int i = 0; i < 3; i++) {
        Vertex* current; Vertex* next;
        if(i == 0) { current = &pt1; next = &pt2; } else
        if(i == 1) { current = &pt2; next = &pt3; } else
                   { current = &pt3; next = &pt1; }
        
        if(next->y < 0) nextSignHolder = -1; else nextSignHolder = 1;
        
        if(signHolder != nextSignHolder) {
            if(current->x > 0 && next->x > 0){
                numCrossings++;
            }
            else if( current->x > 0 || next->x > 0) {
                float crossPoint = (current->x - current->y * (next->x - current->x) / (next->y - current->y));
                if( crossPoint > 0 ){
                    numCrossings++;
                }
            }
            signHolder = nextSignHolder;
        }
    }
    
    if(numCrossings % 2 == 1)
        return impact;
    
    return noImpact();
}