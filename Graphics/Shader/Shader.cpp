//
// Created by kenwi on 12/1/16.
//

#include <stdlib.h>
#include <string.h>

#include <vector>
#include <iostream>
#include <fstream>

#include "Shader.h"

using namespace std;
using namespace Graphics::Shader;

/*
const GLchar* vertexShaderSource = "#version 330 core\n"
        "layout (location = 0) in vec3 position;\n"
        "void main()\n"
        "{\n"
        "gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
        "}\0";
*/

const GLchar* vertexShaderSource =
        "#version 330 core\n"
        "layout(location = 0) in vec3 position;\n"
        "uniform mat4 MVP;\n"
        "void main()\n"
        "{\n"
        "gl_Position = MVP * vec4(position, 1);\n"
        "}\0";


const GLchar* fragmentShaderSource = "#version 330 core\n"
        "out vec3 color;\n"
        "void main()\n"
        "{\n"
        "color = vec3(1,0,0);\n"
        "}\n\0";

//"color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
Shader::Shader() {
    if(this->Disabled)
        return;

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

GLuint Shader::CreateShaderObject(const GLenum type) {
    // Create a shader object and return it's id
    return glCreateShader(type);
}

bool Shader::AttachSourceAndCompile(const GLenum shaderId, const GLchar *shaderSource) {
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

bool Shader::LinkShader(const GLuint vertexShaderId, const GLuint fragmentShaderId) {
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
    ShaderProgram = shaderProgram;

    // Remove shader after it's been linked to the shader program
    cout << "Deleting vertex shader " << vertexShaderId << endl;
    glDeleteShader(vertexShaderId);
    cout << "Deleting fragment shader " << fragmentShaderId << endl;
    glDeleteShader(fragmentShaderId);

    return true;
}

bool Shader::CheckStatus(const GLenum status, const GLuint shaderId) {
    this->CompileError = false;
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
#include <string>
GLuint Shader::LoadShaders(const char * vertex_file_path,const char * fragment_file_path)
{
    // Create the shaders
    GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

    // Read the Vertex Shader code from the file
    std::string VertexShaderCode;
    std::ifstream VertexShaderStream(vertex_file_path, std::ios::in);
    if(VertexShaderStream.is_open()){
        std::string Line = "";
        while(getline(VertexShaderStream, Line))
            VertexShaderCode += "\n" + Line;
        VertexShaderStream.close();
    }else{
        printf("Impossible to open %s. Are you in the right directory ? Don't forget to read the FAQ !\n", vertex_file_path);
        getchar();
        return 0;
    }

    // Read the Fragment Shader code from the file
    std::string FragmentShaderCode;
    std::ifstream FragmentShaderStream(fragment_file_path, std::ios::in);
    if(FragmentShaderStream.is_open()){
        std::string Line = "";
        while(getline(FragmentShaderStream, Line))
            FragmentShaderCode += "\n" + Line;
        FragmentShaderStream.close();
    }

    GLint Result = GL_FALSE;
    int InfoLogLength;


    // Compile Vertex Shader
    printf("Compiling shader : %s\n", vertex_file_path);
    char const * VertexSourcePointer = VertexShaderCode.c_str();
    glShaderSource(VertexShaderID, 1, &VertexSourcePointer , NULL);
    glCompileShader(VertexShaderID);

    // Check Vertex Shader
    glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if ( InfoLogLength > 0 ){
        std::vector<char> VertexShaderErrorMessage(InfoLogLength+1);
        glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
        printf("%s\n", &VertexShaderErrorMessage[0]);
    }



    // Compile Fragment Shader
    printf("Compiling shader : %s\n", fragment_file_path);
    char const * FragmentSourcePointer = FragmentShaderCode.c_str();
    glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer , NULL);
    glCompileShader(FragmentShaderID);

    // Check Fragment Shader
    glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if ( InfoLogLength > 0 ){
        std::vector<char> FragmentShaderErrorMessage(InfoLogLength+1);
        glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
        printf("%s\n", &FragmentShaderErrorMessage[0]);
    }



    // Link the program
    printf("Linking program\n");
    GLuint ProgramID = glCreateProgram();
    glAttachShader(ProgramID, VertexShaderID);
    glAttachShader(ProgramID, FragmentShaderID);
    glLinkProgram(ProgramID);

    // Check the program
    glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
    glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if ( InfoLogLength > 0 ){
        std::vector<char> ProgramErrorMessage(InfoLogLength+1);
        glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
        printf("%s\n", &ProgramErrorMessage[0]);
    }


    glDetachShader(ProgramID, VertexShaderID);
    glDetachShader(ProgramID, FragmentShaderID);

    glDeleteShader(VertexShaderID);
    glDeleteShader(FragmentShaderID);

    this->ShaderProgram = ProgramID;
    return ProgramID;
}


