//
// Created by kenwi on 12/1/16.
//

#ifndef IMPROVED_POTATO_SHADER_H
#define IMPROVED_POTATO_SHADER_H

#include "../../libs.h"

namespace Graphics {
    namespace Shader {
        class Shader {

        private:
            GLuint _id;

        public:
            Shader();
            ~Shader();

        private:
            GLuint CreateShaderObject(GLenum type);
            bool AttachSourceAndCompile(GLenum shaderID, const GLchar *shaderSource );
        };
    }
}

#endif //IMPROVED_POTATO_SHADER_H
