#ifndef  __MAIN_CPP__
#define __MAIN_CPP__

#include "Graphics/Window.h"
#include "Graphics/Shader/Shader.h"
#include "Graphics/Rendering/Renderer.h"
#include "Graphics/Rendering/Primitives/Shape.h"
#include "Utils/Timer.h"

int main()
{
    using namespace std;
    using namespace chrono;
    using namespace Graphics;
    //using namespace Graphics::Shader;
    using namespace Graphics::Rendering;
    using namespace Graphics::Rendering::Primitives;
	
    Shape shape;
    Renderer renderer;
    Window window("Test", 1024, 768);
	
    Shader::Shader shader;
    Object object;
    Utils::Timer timer;
	__int64  fps;

    cout << "Entering game loop" << endl;
    while(window.Running() && !shader.CompileError) {
        window.PollEvents();
        renderer.Clear();

        glUseProgram(shader.ShaderProgram);
        glBindVertexArray(object.VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);

        window.Update();

        if((fps = timer.GetCurrentFPS()) > 0)
            cout << "FPS = " << fps << endl;
    }
    glDeleteVertexArrays(1, &object.VAO);
    glDeleteBuffers(1, &object.VBO);
    return 0;
}

#endif