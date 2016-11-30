//
// Created by kenwi on 11/30/16.
//

#ifndef UNTITLED_OBJECT_H
#define UNTITLED_OBJECT_H

#include <iostream>

using namespace std;
namespace Graphics {
    namespace Rendering {
        struct Object {
            GLuint VAO;
            GLuint IndicesC;

            Object(GLuint vao, GLuint vertexCount) : VAO(vao), IndicesC(vertexCount) {
                cout << "Creating object: vao = " << vao << " indices = " << vertexCount << endl;
            }
        };
    }
}


#endif //UNTITLED_OBJECT_H
