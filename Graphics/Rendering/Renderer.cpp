//
// Created by kenwi on 11/29/16.
//

#include "Renderer.h"
namespace Graphics {
    namespace Rendering {
        Renderer::Renderer() {

        }

        Renderer::~Renderer() {

        }

        void Renderer::Clear() {
            glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
        }

        void Renderer::Render(Object object) {

        }
    }
}


