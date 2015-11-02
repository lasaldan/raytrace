//
//  window.h
//  raytrace
//
//  Created by Daniel Fuller on 10/27/15.
//  Copyright (c) 2015 Daniel Fuller. All rights reserved.
//

#ifndef __raytrace__window__
#define __raytrace__window__

#include <stdio.h>
#include "Vertex.h"
#include "Vector.h"

#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 500

class window {
private:
    Vertex cameraLookAt;
    Vertex cameraLookFrom;
    Vector cameraLookUp;
    float fieldOfView;
public:
    window();
    window( Vertex, Vertex );
    
    void setLookAt( Vertex );
    void setLookFrom( Vertex );
    void setLookUp( Vector );
    void setFieldOfView( float );
    
    Vertex getLookFrom();
    float getFieldOfView();
};

#endif /* defined(__raytrace__window__) */
