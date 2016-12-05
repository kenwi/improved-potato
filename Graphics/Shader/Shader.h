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
            GLuint CreateShaderObject(GLenum type);
            bool AttachSourceAndCompile(GLenum shaderId, const GLchar *shaderSource );
            bool LinkShader(GLuint vertexShaderId, GLuint fragmentShaderId);
            bool CheckStatus(GLenum status, GLuint shaderId);
        };
    }
}

#endif //IMPROVED_POTATO_SHADER_H
