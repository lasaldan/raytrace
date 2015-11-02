//
//  main.cpp
//  raytrace
//
//  Created by Daniel Fuller on 10/27/15.
//  Copyright (c) 2015 Daniel Fuller. All rights reserved.
//

#include <iostream>
#include "main.h"

int main(int argc, const char * argv[]) {
    if (argc == 1) {
        std::cout << "raytrace must be called with a parameter [0-2]" << std::endl;
        std::cout << "0: scenell" << std::endl;
        std::cout << "1: diffuse" << std::endl;
        std::cout << "2: custom" << std::endl;
        return 0;
    }
    
    int sceneId = atoi(argv[1]);
    
    scene = scene::scene();
    window = window::window();
    raytracer = raytracer::raytracer();
    
    switch (sceneId) {
        case DIFFUSE: {
            std::cout << "Setting up Diffuse Scene..." << std::endl;
            break;
        }
        case SCENELL: {
            std::cout << "Setting up Scenell Scene..." << std::endl;
            
            scene.setBackgroundColor( color(.2*255,.2*255,.2*255) );
            scene.setAmbientLightColor( color(0,0,0) );
            
            sphere s = sphere( Vertex(0, .3 ,0), .2);
            
            polygon p1 = polygon();
            p1.addVertex( Vertex(0, -.5, .5) );
            p1.addVertex( Vertex(1, .5, 0) );
            p1.addVertex( Vertex(0, -.5, -.5) );
            
            polygon p2 = polygon();
            p2.addVertex( Vertex(0, -.5, .5) );
            p2.addVertex( Vertex(-1, .5, 0) );
            p2.addVertex( Vertex(0, -.5, -.5) );
            
            scene.addSphere( s );
            scene.addPolygon( p1 );
            scene.addPolygon( p2 );
            
            scene.addLight( light( Vector(0,1,0), color(255,255,255) ) );
            
            window.setFieldOfView( 55 );
            window.setLookAt( Vertex(0,0,0) );
            window.setLookFrom( Vertex(0,0,1.2) );
            window.setLookUp( Vector(0.0f,1.0f,0.0f) );
            
            break;
        }
        case CUSTOM: {
            std::cout << "Setting up Custom Scene..." << std::endl;
            break;
        }
        default: {
            break;
        }
    }
    
    std::cout << "Raytracing Image..." << std::endl;
    image = raytracer.render(scene, window);
    
    std::cout << "Writing Image..." << std::endl;
    std::ofstream imageFile("/Users/Daniel/workspace/raytrace/raytrace/renders/image.ppm");
    imageFile << image.toString();
    imageFile.close();
    
    return 0;
}
