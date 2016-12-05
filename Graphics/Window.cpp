//
// Created by kenwi on 11/29/16.
//
#include "Window.h"

namespace Graphics {

    using namespace std;

    Window::Window(const char *title, int width, int height) {
        cout << "Calling constructor on Window. Requesting size = "
             << width << "x" << height << " title = " << title  << endl;

        _title = title;
        _width = width;
        _height = height;

        if(!Initialize()) {
            cout << "Unable to initialize" << endl;
            glfwTerminate();
        }
    }

    Window::~Window() {
        cout << "Called destructor on Window" << endl;
        Terminate();
    }

    bool Window::Initialize() {
        // Use modern approach
        glewExperimental = GL_TRUE;
        if(!glfwInit()) {
            cout << "Failed to init GLFW" << endl;
            return false;
        }
        cout << "Initialized GLFW" << endl;

        // Make sure we're using >=OpenGL 3.3
        cout << "Requesting OpenGL context version above 3.3" << endl;
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

        // Enable OpenGL core profile
        cout << "Enabling OpenGL core profile" << endl;
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        cout << "Disabling windows resizing" << endl;
        glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

        if(nullptr == (_windowPtr = glfwCreateWindow(_width, _height, _title, nullptr, nullptr))) {
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

        SetOpenGLViewPort();

        cout << "Successfully initialized and created window" << endl;
        return true;
    }

    bool Window::InitGLEW() {
        return glewInit() == GLEW_OK;
    }

    bool Window::Running() {
        if(glfwWindowShouldClose(_windowPtr)) {
            cout << "Caught termination singal" << endl;
            return false;
        }
        return true;
    }

    void Window::Update() {
        // Swap the color buffer and output it to the screen (double buffering)
        glfwSwapBuffers(_windowPtr);
    }

    void Window::Terminate() {
        cout << "Terminating window and freeing window pointer" << endl;
        glfwDestroyWindow(_windowPtr);
        glfwTerminate();
    }

    // Should probably be abstracted so we can have multiple viewports
    void Window::SetOpenGLViewPort() {
        cout << "Setting OpenGL Viewport" << endl;
        glfwGetFramebufferSize(_windowPtr, &_width,  &_height);
        glViewport(0, 0, _width, _height);
    }

    void Window::PollEvents() {
        // Poll for events like keyboard input or mouse movement
        glfwPollEvents();
    }
}

