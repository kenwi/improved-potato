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
            //GLuint _shaderId;

        public:
            Shader();
            ~Shader();
            bool CompileError;
            GLuint ShaderProgram;

        private:
            GLuint CreateShaderObject(const GLenum type);
            bool AttachSourceAndCompile(const GLenum shaderId, const GLchar *shaderSource );
            bool LinkShader(const GLuint vertexShaderId, const GLuint fragmentShaderId);
            bool CheckStatus(const GLenum status, const GLuint shaderId);
        };
    }
}

#endif //IMPROVED_POTATO_SHADER_H
