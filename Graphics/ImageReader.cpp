//
// Created by kenwi on 1/31/17.
//

#include "ImageReader.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <iostream>

void abort_(const char * s, ...)
{
    va_list args;
    va_start(args, s);
    vfprintf(stderr, s, args);
    fprintf(stderr, "\n");
    va_end(args);
    abort();
}

namespace Graphics {
    ImageReader::ImageReader() {

    }

    void ImageReader::ReadPNG(const char *filename) {
        png_byte header[8];

        FILE *fp = fopen(filename, "rb");
        if(!fp) {
            abort_("File could not be opened.");
        }

        fread(header, 1, 8, fp);
        if(png_sig_cmp(header, 0, 8)) {
            abort_("Not a png");
        }

        this->pngPtr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
        if (!this->pngPtr)
            abort_("[read_png_file] png_create_read_struct failed");

        this->infoPtr = png_create_info_struct(this->pngPtr);
        if (!this->infoPtr)
            abort_("[read_png_file] png_create_info_struct failed");

        if (setjmp(png_jmpbuf(this->pngPtr)))
            abort_("[read_png_file] Error during init_io");

        png_init_io(this->pngPtr, fp);
        png_set_sig_bytes(this->pngPtr, 8);

        png_read_info(this->pngPtr, this->infoPtr);

        width = png_get_image_width(this->pngPtr, this->infoPtr);
        height = png_get_image_height(this->pngPtr, this->infoPtr);
        this->colorType = png_get_color_type(this->pngPtr, this->infoPtr);
        this->bitDepth = png_get_bit_depth(this->pngPtr, this->infoPtr);

        int number_of_passes = png_set_interlace_handling(this->pngPtr);
        png_read_update_info(this->pngPtr, this->infoPtr);

        /* read file */
        if (setjmp(png_jmpbuf(this->pngPtr)))
            abort_("[read_png_file] Error during read_image");

        int y;
        this->rowPtrs = (png_bytep*) malloc(sizeof(png_bytep) * height);
        for (y=0; y<height; y++) {
            this->rowPtrs[y] = (png_byte*) malloc(png_get_rowbytes(this->pngPtr,this->infoPtr));
        }
        png_read_image(this->pngPtr, this->rowPtrs);
        fclose(fp);
    }
}