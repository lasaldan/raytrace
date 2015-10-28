//
//  main.h
//  raytrace
//
//  Created by Daniel Fuller on 10/27/15.
//  Copyright (c) 2015 Daniel Fuller. All rights reserved.
//

#ifndef raytrace_main_h
#define raytrace_main_h

#define DIFFUSE 0
#define SCENELL 1
#define CUSTOM 2

#include <fstream>
#include <string>
#include <iostream>
#include "scene.h"
#include "window.h"
#include "sphere.h"
#include "polygon.h"
#include "light.h"
#include "Vector.h"
#include "raytracer.h"
#include "ppm.h"

scene scene;
window window;
raytracer raytracer;
ppm image;

#endif
