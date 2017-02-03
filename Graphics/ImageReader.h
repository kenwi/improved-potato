//
// Created by kenwi on 1/31/17.
//

#ifndef IMPROVED_POTATO_IMAGEREADER_H
#define IMPROVED_POTATO_IMAGEREADER_H

#include <png.h>

namespace Graphics {
    class ImageReader {
    public:
        ImageReader();
        void ReadPNG(const char *filename);
        png_bytep *rowPtrs;
        int width, height;
    private:

        png_byte colorType, bitDepth;
        png_structp pngPtr;
        png_infop infoPtr;
    };
}

#endif //IMPROVED_POTATO_IMAGEREADER_H
