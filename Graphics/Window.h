//
// Created by kenwi on 11/29/16.
//

#ifndef UNTITLED_WINDOW_H
#define UNTITLED_WINDOW_H

#include "../libs.h"

namespace Graphics {
    class Window {

    public:
        //int MouseX, MouseY;

    private:
        const char *_title;
        int _width, _height;
        GLFWwindow *_windowPtr;

    public:
        Window(const char *title, const int height, const int width);
        ~Window();
        bool Running();
        void Update();
        void Terminate();
        void SetOpenGLViewPort();
        void PollEvents();

    private:
        bool Initialize();
        bool InitGLEW();
    };
}

#endif //UNTITLED_WINDOW_H
