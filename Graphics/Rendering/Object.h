//
// Created by kenwi on 11/30/16.
//

#ifndef UNTITLED_OBJECT_H
#define UNTITLED_OBJECT_H

//#include <iostream>

#include "../../libs.h"

using namespace std;
namespace Graphics {
    namespace Rendering {
        class Object {
        public:
            GLuint VAO;
            GLuint VBO;
            //GLuint IndicesC;

        public:
            Object() {//: VAO(vao), IndicesC(vertexCount) {
                //cout << "Creating object: vao = " << vao << " indices = " << vertexCount << endl;

                GLfloat vertices[] = {
                        -0.5f, -0.5f, 0.0f, // Left
                        0.5f, -0.5f, 0.0f, // Right
                        0.0f,  0.5f, 0.0f  // Top
                };
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
                // Note that this is allowed, the call to glVertexAttribPointer registered VBO as the
                // currently bound vertex buffer object so afterwards we can safely unbind
                glBindBuffer(GL_ARRAY_BUFFER, 0);
                // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)
                glBindVertexArray(0);
                cout << "Created Object VAO = " << VAO << ", VBO = " << VBO << endl;
            }
        };
    }
}


#endif //UNTITLED_OBJECT_H
