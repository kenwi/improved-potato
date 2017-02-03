//
// Created by kenwi on 11/29/16.
//

#ifndef UNTITLED_RENDERER_H
#define UNTITLED_RENDERER_H

#include "../../libs.h"
#include "Object.h"

#include <png.h>
png_byte *loadTexture(const string filename, int &width, int &height);

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
