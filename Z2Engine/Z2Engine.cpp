
#include "pch.h"
#include "core/Gl_Layer.h"
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);


int main()
{
    
    GLFWwindow* window = GlLayer::createWindow();

  

    
    
    glViewport(0, 0, 800, 600);
    
    
    
    
    while (!glfwWindowShouldClose(window))
    {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    
    return 0;
}

