//
// Created by kenwi on 11/29/16.
//

#ifndef UNTITLED_WINDOW_H
#define UNTITLED_WINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace Graphics {
    class Window {

    public:
        int MouseX, MouseY;

    private:
        const char *_title;
        int _width, _height;
        GLFWwindow *_windowPtr;

    public:
        Window(const char *title, int height, int width);
        ~Window();
        bool Running();
        void Update();
        void Terminate();

    private:
        bool Initialize();
        bool InitGLEW();
    };
}

#endif //UNTITLED_WINDOW_H
