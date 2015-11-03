//
//  color.cpp
//  raytrace
//
//  Created by Daniel Fuller on 10/27/15.
//  Copyright (c) 2015 Daniel Fuller. All rights reserved.
//

#include "color.h"
using namespace std;

color::color() {
    color(0,0,0);
}

color::color(float r, float g, float b) {
    red = r;
    green = g;
    blue = b;
}

bool
color::operator==(const color& other) const {
    return other.red == red && other.blue == blue && other.green == green;
}

string
color::toByte() {
    stringstream colordata;
    colordata << hex << red << " ";
    colordata << hex << green << " ";
    colordata << hex << blue << "";
    return colordata.str();
}