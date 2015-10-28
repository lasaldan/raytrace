//
//  light.h
//  raytrace
//
//  Created by Daniel Fuller on 10/27/15.
//  Copyright (c) 2015 Daniel Fuller. All rights reserved.
//

#ifndef __raytrace__light__
#define __raytrace__light__

#include <stdio.h>
#include "color.h"
#include "Vector.h"

class light {
public:
    color color;
    Vector direction;
    light();
    light(Vector, color::color);
};

#endif /* defined(__raytrace__light__) */
