//
//  polygon.cpp
//  raytrace
//
//  Created by Daniel Fuller on 10/27/15.
//  Copyright (c) 2015 Daniel Fuller. All rights reserved.
//

#include "polygon.h"

polygon::polygon() {
    
}
void
polygon::addVertex(Vertex v) {
    vertices.push_back(v);
}