//
// Created by kenwi on 11/30/16.
//

#ifndef UNTITLED_LIBS_H
#define UNTITLED_LIBS_H

//#include "GLUS/src/GL/glus.h"
//#include <GLUS/src/GL/glus.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

#endif //UNTITLED_LIBS_H

/*
    TIFF* tif = TIFFOpen("/home/kenwi/Desktop/Vardo-heightmap-full-color.tiff", "r");
    if(tif) {
        uint32 imagelength;
        tsize_t scanline;
        void *buf;
        uint32 row, col;

        TIFFGetField(tif, TIFFTAG_IMAGELENGTH, &imagelength);
        scanline = TIFFScanlineSize(tif);
        buf = _TIFFmalloc(scanline);
        for(row=0; row<imagelength; row++) {
            TIFFReadScanline(tif, buf, row);
            for(col=0; col<scanline; col++) {
                printf("%d ", *buf);
            }
            printf("\n");
        }
        _TIFFfree(buf);
        TIFFClose(tif);
    }
*/