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
    
    std::cout << argv[1] << std::endl;
    std::cout << "Hello, World!\n";
    return 0;
}
