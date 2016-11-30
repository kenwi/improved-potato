//
// Created by kenwi on 11/29/16.
//

#ifndef UNTITLED_RENDERER_H
#define UNTITLED_RENDERER_H

#include "GL/glew.h"
#include "Object.h"

namespace Graphics{
    namespace Rendering {
        class Renderer {
        public:
            Renderer();
            ~Renderer();

            void Clear();
            void Render(Object object);
        };
    }
}

#endif //UNTITLED_RENDERER_H
