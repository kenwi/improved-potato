//
// Created by kenwi on 11/30/16.
//

#ifndef UNTITLED_OBJECT_H
#define UNTITLED_OBJECT_H

#include "Renderer.h"
#include "../../libs.h"
#include "../ImageReader.h"

using namespace std;

namespace Graphics {
    namespace Rendering {
        class Object {
        private:
            ImageReader imageReader;

        public:
            GLuint VAO;
            GLuint VBO;
            GLuint VerticesC;

        public:
            Object() {//: VAO(vao), IndicesC(vertexCount) {

                int index = 0;
                int x, y;

                imageReader.ReadPNG("../Capture.PNG");
                GLfloat vertices[imageReader.width*3];
                this->VerticesC = sizeof(vertices)/sizeof(GLfloat)/3;

                png_bytep row = imageReader.rowPtrs[0];
                for(x=0; x<imageReader.width; x++) {
                    png_byte *ptr = &(row[x*4]);

                    GLfloat r = ptr[0];
                    GLfloat g = ptr[1];
                    GLfloat b = ptr[2];

                    vertices[x] = r/255.f;
                    vertices[x+1] = g/255.f;
                    vertices[x+2] = b/255.f;
                }

                // Generate vertex array object
                glGenVertexArrays(1, &VAO);
                // Generate vertex buffer object
                glGenBuffers(1, &VBO);
                // Bind vertex array
                glBindVertexArray(VAO);
                // Set vertex buffer
                glBindBuffer(GL_ARRAY_BUFFER, VBO);
                glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
                // Set attribute pointers
                glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
                glEnableVertexAttribArray(0);
                // Note that this is allowed, the call to glVertexAttribPointer registered VBO as the
                // currently bound vertex buffer object so afterwards we can safely unbind
                glBindBuffer(GL_ARRAY_BUFFER, 0);
                // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)
                glBindVertexArray(0);
            }
        };
    }
}

/*
GLfloat vertices[] = {
        -0.5f, -0.5f, 0.0f, // Left
        0.5f, -0.5f, 0.0f, // Right
        0.0f,  0.5f, 0.0f,  // Top
        0.0f,  -1.0f, 0.0f,
        1.0f,  -1.0f, 0.0f,
        1.1f,  -1.4f, 1.0f,
        1.0f,  -1.2f, -1.0f
};*/
//GLfloat r = -255; //ptr[0];
//GLfloat g = 0; //ptr[1];
//GLfloat b = -255; //ptr[2];
//vertices[index] = r/255.f;
//vertices[index+1] = g/255.f;
//vertices[index+2] = b/255.f;

/*
for(y=0; y<1; y++) {
    png_bytep row = imageReader.rowPtrs[y];
    for(x=0; x<imageReader.width; x++) {
        png_byte *ptr = &(row[x*4]);

        GLfloat r = ptr[0];
        GLfloat g = ptr[1];
        GLfloat b = ptr[2];

        vertices[index] = r/255.f;
        vertices[index+1] = g/255.f;
        vertices[index+2] = b/255.f;
        index+=3;
        //printf("Pixel at position [ %d - %d ] has RGBA values: %d - %d - %d - %d\n",
        //       x, y, ptr[0], ptr[1], ptr[2], ptr[3]);
    }
}*/

//VerticesC = index/3;


#endif //UNTITLED_OBJECT_H
