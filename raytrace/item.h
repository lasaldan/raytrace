//
//  item.h
//  raytrace
//
//  Created by Daniel Fuller on 10/27/15.
//  Copyright (c) 2015 Daniel Fuller. All rights reserved.
//

#ifndef __raytrace__item__
#define __raytrace__item__

#include <stdio.h>
#include "Vertex.h"
#include "Vector.h"
#include "color.h"


class item {
public:
    item();
    //virtual Vertex impactedBy(Vector, Vertex);
    color diffuse;
    color specularHighlight;
    int phongConstant;
    Vertex noImpact();
private:
};

#endif /* defined(__raytrace__item__) */
