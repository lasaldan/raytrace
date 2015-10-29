//
//  scene.cpp
//  raytrace
//
//  Created by Daniel Fuller on 10/27/15.
//  Copyright (c) 2015 Daniel Fuller. All rights reserved.
//

#include "scene.h"

scene::scene() {
    ambientLightColor = color();
    backgroundColor = color();
}

void
scene::setAmbientLightColor(color c) {
    ambientLightColor = c;
}

void
scene::setBackgroundColor(color c) {
    backgroundColor = c;
}

void
scene::addPolygon(polygon p) {
    polygons.push_back(p);
}

void
scene::addSphere(sphere s) {
    spheres.push_back(s);
}

void
scene::addLight(light l) {
    lights.push_back(l);
}