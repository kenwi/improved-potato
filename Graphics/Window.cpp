//
// Created by kenwi on 11/29/16.
//
#include "Window.h"

namespace Graphics {

    using namespace std;

    Window::Window(const char *title, int height, int width) {
        cout << "Calling constructor on Window" << endl;
        _height = height;
        _width = width;
        _title = title;

        if(!Initialize()) {
            cout << "Unable to initialize" << endl;
            glfwTerminate();
        }

        cout << "Finished constructing Window" << endl;
    }

    Window::~Window() {
        cout << "Called destructor on Window" << endl;
        Terminate();
    }

    bool Window::Initialize() {
        if(!glfwInit()) {
            cout << "Failed to init GLFW" << endl;
            return false;
        }
        cout << "Initialized GLFW" << endl;

        if(!(_windowPtr = glfwCreateWindow(_width, _height, _title, nullptr, nullptr)))         {
            cout << "Failed to create window" << endl;
            return false;
        }
        cout << "Created window" << endl;
        glfwMakeContextCurrent(_windowPtr);

        if(!InitGLEW()) {
            cout << "Failed to init GLEW" << endl;
            return false;
        }

        glfwSetWindowUserPointer(_windowPtr, this);

        return true;
    }

    bool Window::InitGLEW() {
        return (glewInit() != GLEW_OK) ? false : true;
    }

    bool Window::Running() {
        return !glfwWindowShouldClose(_windowPtr);
    }

    void Window::Update() {
        glfwPollEvents();
        glfwSwapBuffers(_windowPtr);
    }

    void Window::Terminate() {
        cout << "Terminating window and freeing window pointer" << endl;
        glfwDestroyWindow(_windowPtr);
        glfwTerminate();
    }
}

