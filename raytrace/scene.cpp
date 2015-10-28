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
scene::addItem(item i) {
    items.push_back(i);
}

void
scene::addLight(light l) {
    lights.push_back(l);
}