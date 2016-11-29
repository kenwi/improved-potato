//
// Created by kenwi on 11/29/16.
//

#include "Renderer.h"

Graphics::Renderer::Renderer() {

}

Graphics::Renderer::~Renderer() {

}

void Graphics::Renderer::Clear() {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}
