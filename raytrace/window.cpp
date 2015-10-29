//
//  window.cpp
//  raytrace
//
//  Created by Daniel Fuller on 10/27/15.
//  Copyright (c) 2015 Daniel Fuller. All rights reserved.
//

#include "window.h"


window::window() {
    
}

window::window( Vertex lookFrom, Vertex lookAt ) {
    cameraLookAt = lookAt;
    cameraLookFrom = lookFrom;
}

void
window::setLookAt( Vertex v ) {
    cameraLookAt = v;
}

void
window::setLookFrom( Vertex v ) {
    cameraLookFrom = v;
}

void
window::setLookUp( Vector v ) {
    cameraLookUp = v;
}

void
window::setFieldOfView( float f ) {
    fieldOfView = f;
}

Vertex
window::getLookFrom() {
    return cameraLookFrom;
}

float
window::getFieldOfView() {
    return fieldOfView;
}