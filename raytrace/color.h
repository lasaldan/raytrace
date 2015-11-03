//
//  color.h
//  raytrace
//
//  Created by Daniel Fuller on 10/27/15.
//  Copyright (c) 2015 Daniel Fuller. All rights reserved.
//

#ifndef __raytrace__color__
#define __raytrace__color__

#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

class color {
public:
    float red;
    float green;
    float blue;
    color();
    color(float, float, float);
    std::string toByte();
    bool operator==(const color& rhs) const;
};
#endif /* defined(__raytrace__color__) */
