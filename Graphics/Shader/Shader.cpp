//
// Created by kenwi on 12/1/16.
//

#include "Shader.h"

using namespace Graphics::Shader;

Shader::Shader() {

}

Shader::~Shader() {

}

GLuint Shader::CreateShaderObject(GLenum type) {
    // Create a shader objet and return it's id
    return glCreateShader(type);
}

bool Shader::AttachSourceAndCompile(GLenum shaderID, const GLchar *shaderSource) {
    // Attach the shader source to the shader object
    glShaderSource(shaderID, 1, &shaderSource, nullptr);

    // And comile that shit
    glCompileShader(shaderID);

    // Check compilation status
    GLint success;
    GLchar log[512];
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
    if(!success ) {
        glGetShaderInfoLog(shaderID, 512, nullptr, log);
        return false;
    }
    return  true;
}
