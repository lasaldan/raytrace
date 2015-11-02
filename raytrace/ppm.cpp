//
//  ppm.cpp
//  raytrace
//
//  Created by Daniel Fuller on 10/28/15.
//  Copyright (c) 2015 Daniel Fuller. All rights reserved.
//

#include "ppm.h"

ppm::ppm() {
    
}

ppm::ppm(int w, int h) {
    imageType = PPM_TYPE;
    imageWidth = w;
    imageHeight = h;
    pixelData.resize(h);
    for(int i=0; i<h; i++) {
        pixelData[i].resize(w);
    }
}

void
ppm::setPixel(int row, int col, color val) {
    pixelData[row][col] = val;
}

color
ppm::getPixel(int row, int col) {
    return pixelData[row][col];
}

std::string
ppm::toString() {
    std::stringstream filedata;
    filedata << imageType << "\n";
    filedata << imageWidth << " ";
    filedata << imageHeight << "\n";
    filedata << MAX_VALUE << "\n";
    
    for(int row=0; row<imageHeight; row++) {
        for(int col=0; col<imageWidth; col++) {
            filedata << pixelData[row][col].toByte() << " \n";
        }
        filedata << " \n";
    }
    
    return filedata.str();
}