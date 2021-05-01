
#include "pch.h"
#include "core/Gl_Layer.h"

#include"core/VAO.h"
#include"core/EBO.h"
#include"core/VBO.h"
#include"core/ShaderClass.h"



int main()
{
    GLfloat vertices[] =
    { //               COORDINATES                  /     COLORS           //
        -0.5f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f,     0.8f, 0.3f,  0.02f, // Lower left corner
         0.5f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f,     0.8f, 0.3f,  0.02f, // Lower right corner
         0.0f,  0.5f * float(sqrt(3)) * 2 / 3, 0.0f,     1.0f, 0.6f,  0.32f, // Upper corner
        -0.25f, 0.5f * float(sqrt(3)) * 1 / 6, 0.0f,     0.9f, 0.45f, 0.17f, // Inner left
         0.25f, 0.5f * float(sqrt(3)) * 1 / 6, 0.0f,     0.9f, 0.45f, 0.17f, // Inner right
         0.0f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f,     0.8f, 0.3f,  0.02f  // Inner down
    };
    GLuint indices[] =
    {
        0, 3, 5, // Lower left triangle
        3, 2, 4, // Lower right triangle
        5, 4, 1 // Upper triangle
    };

    GLFWwindow* window = GlLayer::createWindow();
    Shader shaderprogram("resources/vertex.vert","resources/fragment.frag");
    
    VAO vao1;
    vao1.Bind();
    VBO vbo1(vertices,sizeof(vertices),GL_STATIC_DRAW);
    EBO ebo1(indices, sizeof(indices), GL_STATIC_DRAW);
    
    vao1.LinkAttrib(vbo1, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
    vao1.LinkAttrib(vbo1, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));

    vao1.UnBind();
    vbo1.UnBind();
    ebo1.UnBind();

    // Gets ID of uniform called "scale"
    GLuint uniID = glGetUniformLocation(shaderprogram.ID, "scale");
    while (!glfwWindowShouldClose(window))
    {
        // Specify the color of the background
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        // Clean the back buffer and assign the new color to it
        glClear(GL_COLOR_BUFFER_BIT);
        // Tell OpenGL which Shader Program we want to use
        shaderprogram.Activate();
        // Assigns a value to the uniform; NOTE: Must always be done after activating the Shader Program
        glUniform1f(uniID, 0.5f);
        // Bind the VAO so OpenGL knows to use it
        vao1.Bind();
        // Draw primitives, number of indices, datatype of indices, index of indices
        glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
        // Swap the back buffer with the front buffer
        glfwSwapBuffers(window);
        // Take care of all GLFW events
        glfwPollEvents();
    }

    GlLayer::terminate();
    
    return 0;
}

