//
// Created by kenwi on 12/1/16.
//

#include "Shader.h"

using namespace std;
using namespace Graphics::Shader;

const GLchar* vertexShaderSource = "#version 330 core\n"
        "layout (location = 0) in vec3 position;\n"
        "void main()\n"
        "{\n"
        "gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
        "}\0";
const GLchar* fragmentShaderSource = "#version 330 core\n"
        "out vec4 color;\n"
        "void main()\n"
        "{\n"
        "color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
        "}\n\0";

Shader::Shader() {
    cout << "Creating vertex shader" << endl;
    GLuint vertexShader = CreateShaderObject(GL_VERTEX_SHADER);
    if(AttachSourceAndCompile(vertexShader, vertexShaderSource)) {
        cout << "Successfully attached vertex shader source" << endl;
    }
    cout << "Creating fragment shader" << endl;
    GLuint fragmentShader = CreateShaderObject(GL_FRAGMENT_SHADER);
    if(AttachSourceAndCompile(fragmentShader, fragmentShaderSource)) {
        cout << "Successfully attached fragment shader source" << endl;
    }

    LinkShader(vertexShader, fragmentShader);
}

Shader::~Shader() {

}

GLuint Shader::CreateShaderObject(GLenum type) {
    // Create a shader object and return it's id
    return glCreateShader(type);
}

bool Shader::AttachSourceAndCompile(GLenum shaderId, const GLchar *shaderSource) {
    // Attach the shader source to the shader object
    glShaderSource(shaderId, 1, &shaderSource, NULL);

    // And compile that shit
    glCompileShader(shaderId);

    if(CheckStatus(GL_COMPILE_STATUS, shaderId)) {
        cout << "Status for shader " << shaderId << " is OK" << endl;
        return true;
    }
    cout << "Status for shader " << shaderId << " is ERROR" << endl;
    return false;
}

bool Shader::LinkShader(GLuint vertexShaderId, GLuint fragmentShaderId) {
    cout << "Linking vertex shader " << vertexShaderId << " and fragment shader " << fragmentShaderId <<  endl;
    // Link the shader
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShaderId);
    glAttachShader(shaderProgram, fragmentShaderId);
    glLinkProgram(shaderProgram);

    cout << "Checking shader program " << shaderProgram << endl;
    if(!CheckStatus(GL_LINK_STATUS, shaderProgram)) {
        cout << "Status for shader " << shaderProgram << " is ERROR" << endl;
        return false;
    }
    cout << "Status for shader " << shaderProgram << " is OK" << endl;
    this->ShaderProgram = shaderProgram;

    // Remove shader after it's been linked to the shader program
    cout << "Deleting vertex shader " << vertexShaderId << endl;
    glDeleteShader(vertexShaderId);
    cout << "Deleting fragment shader " << fragmentShaderId << endl;
    glDeleteShader(fragmentShaderId);

    return true;
}

bool Shader::CheckStatus(GLenum status, GLuint shaderId) {
    cout << "Checking status = " << status << " for shader = " << shaderId << endl;
    // Check compilation status
    GLint success;
    GLchar log[512];
    glGetShaderiv(shaderId, status, &success);
    if(!success ) {
        glGetShaderInfoLog(shaderId, 512, nullptr, log);
        cout << "ERROR::SHADER::PROGRAM::FAILED\n" << log << endl;
        this->CompileError = true;
        return false;
    }
    return true;
}


