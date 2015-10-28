//
//  ppm.h
//  raytrace
//
//  Created by Daniel Fuller on 10/28/15.
//  Copyright (c) 2015 Daniel Fuller. All rights reserved.
//

#ifndef __raytrace__ppm__
#define __raytrace__ppm__

#include <stdio.h>
#include <string>
#include <vector>
#include "color.h"
#include <iostream>
#include <sstream>

#define MAX_VALUE 255
#define PPM_TYPE "P3"

class ppm {
private:
    std::string imageType;
    int imageWidth;
    int imageHeight;
    int maxValue;
    std::vector< std::vector<color> > pixelData;
public:
    ppm();
    ppm(int, int);
    void setPixel(int, int, color);
    color getPixel(int, int);
    std::string toString();
    
    
};

#endif /* defined(__raytrace__ppm__) */
