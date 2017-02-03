#include "Graphics/Window.h"
#include "Graphics/Shader/Shader.h"
#include "Graphics/Rendering/Renderer.h"
#include "Graphics/Rendering/Primitives/Shape.h"
#include "Graphics/ImageReader.h"

#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/transform.hpp>

int main()
{
    using namespace std;
    using namespace glm;
    using namespace Graphics;
    using namespace Graphics::Rendering;

    Renderer renderer;
    Window window("Test", 1024, 768);
    Graphics::Shader::Shader shader;
    Object object;

    shader.LoadShaders("../SimpleTransform.vertexshader", "../SingleColor.fragmentshader");

    // Get a handle for our "MVP" uniform
    GLuint MatrixID = glGetUniformLocation(shader.ShaderProgram, "MVP");

    // Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
    glm::mat4 Projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
    // Or, for an ortho camera :
    //glm::mat4 Projection = glm::ortho(-2.f,2.f,-2.f,2.f,-20.0f,20.0f); // In world coordinates

    // Camera matrix
    glm::mat4 View       = glm::lookAt(
            glm::vec3(1,0,-3), // Camera is at (4,3,3), in World Space
            glm::vec3(0,0,0), // and looks at the origin
            glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
    );
    // Model matrix : an identity matrix (model will be at the origin)
    glm::mat4 Model      = glm::mat4(1.0f);
    // Our ModelViewProjection : multiplication of our 3 matrices
    glm::mat4 MVP        = Projection * View * Model; // Remember, matrix multiplication is the other way around

    while(window.Running() && !shader.CompileError) {
        renderer.Clear();

        glUseProgram(shader.ShaderProgram);
        glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
        glBindVertexArray(object.VAO);

        glDrawArrays(GL_POINTS, 0, object.VerticesC);

        glDisableVertexAttribArray(object.VAO);

        window.Update();
    }
    glDeleteVertexArrays(1, &object.VAO);
    glDeleteBuffers(1, &object.VBO);
    return 0;
}