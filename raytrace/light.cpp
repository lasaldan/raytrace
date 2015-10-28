//
//  light.cpp
//  raytrace
//
//  Created by Daniel Fuller on 10/27/15.
//  Copyright (c) 2015 Daniel Fuller. All rights reserved.
//

#include "light.h"

light::light() {
    
}

light::light(Vector v, color::color c) {
    direction = v;
    color = c;
}