//
// Created by kenwi on 11/30/16.
//

#ifndef UNTITLED_SHAPE_H
#define UNTITLED_SHAPE_H

#include "../../../libs.h"

namespace Graphics {
    namespace Rendering {
        namespace Primitives {
            class Shape {
            public:
                Shape();
                ~Shape();
                const GLUSshape& Get() const;

            protected:
                GLUSshape shape;
            };
        }
    }
}

#endif //UNTITLED_SHAPE_H
