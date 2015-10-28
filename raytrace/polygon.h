//
//  polygon.h
//  raytrace
//
//  Created by Daniel Fuller on 10/27/15.
//  Copyright (c) 2015 Daniel Fuller. All rights reserved.
//

#ifndef __raytrace__polygon__
#define __raytrace__polygon__

#include <stdio.h>
#include <vector>
#include "Vertex.h"
#include "item.h"

class polygon : public item {
public:
    polygon();
    void addVertex(Vertex);
    std::vector<Vertex> vertices;
};

#endif /* defined(__raytrace__polygon__) */
