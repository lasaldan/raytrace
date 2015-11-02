//
//  collision.h
//  raytrace
//
//  Created by Daniel Fuller on 11/2/15.
//  Copyright (c) 2015 Daniel Fuller. All rights reserved.
//

#ifndef __raytrace__collision__
#define __raytrace__collision__

#include <stdio.h>
#include "item.h"
#include "Vertex.h"

class collision {
private:
    item target;
    Vertex collisionPoint;
};

#endif /* defined(__raytrace__collision__) */
