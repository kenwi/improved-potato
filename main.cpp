#include "Graphics/Window.h"
#include "Graphics/Shader/Shader.h"
#include "Graphics/Rendering/Renderer.h"
#include "Graphics/Rendering/Primitives/Shape.h"

int main()
{
    using namespace std;
    using namespace Graphics;
    //using namespace Graphics::Shader::
    using namespace Graphics::Rendering;
    using namespace Graphics::Rendering::Primitives;

    Shape shape;
    Renderer renderer;
    Window window("Test", 1024, 768);
    Graphics::Shader::Shader shader;

    while(window.Running() && !shader.CompileError) {
        renderer.Clear();
        window.Update();
    }
    return 0;
}