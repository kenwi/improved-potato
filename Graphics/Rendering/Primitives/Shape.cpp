//
// Created by kenwi on 11/30/16.
//

#include "Shape.h"

namespace Graphics {
    namespace Rendering {
        namespace Primitives {
            Shape::Shape() {
                memset(&shape, 0, sizeof(GLUSshape));
            }

            Shape::~Shape() {
               glusShapeDestroyf(&shape);
            }

            const GLUSshape& Shape::Get() const {
                return shape;
            }
        }
    }
}