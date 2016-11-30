// Source is inspired by https://github.com/onurhb

#include <iostream>
#include "Graphics/Window.h"
#include "Graphics/Rendering/Renderer.h"

int main()
{
    using namespace std;
    using namespace Graphics;
    using namespace Graphics::Rendering;

    Renderer renderer;
    Window window("Test", 1024, 768);
    while(window.Running()) {
        renderer.Clear();
        window.Update();
    }
    return 0;
}