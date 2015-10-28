//
//  item.cpp
//  raytrace
//
//  Created by Daniel Fuller on 10/27/15.
//  Copyright (c) 2015 Daniel Fuller. All rights reserved.
//

#include "item.h"


item::item() {
    diffuse = color(0,0,0);
    specularHighlight = color(0,0,0);
    phongConstant = 4;
}

Vertex
item::impactedBy(Vector v) {
    return Vertex(NULL, NULL, NULL);
}