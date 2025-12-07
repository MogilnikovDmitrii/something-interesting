#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int  g_screen_size_x = 1920;
int  g_screen_size_y = 1080;

void glfw_window_size_call_back(GLFWwindow* window,int width,int heigth){
    g_screen_size_x = width;
    g_screen_size_y = heigth;
    glViewport(0,0,g_screen_size_x,g_screen_size_y);
}

void glfw_key_callback(GLFWwindow* window, int key , int scancode , int action , int mode){
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
        glfwSetWindowShouldClose(window,GL_TRUE);
    }
}

int main(void)
{
    /* Initialize the library */
    if (!glfwInit()){
        std::cout << "bro you can't init glfw";
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    GLFWwindow* window = glfwCreateWindow(g_screen_size_x, g_screen_size_y, "My Game", nullptr, nullptr);
    if (!window)
    {
        std:: cout << "glfwCreateWindow don't work";
        glfwTerminate();
        return -1;
    }
    glfwSetWindowSizeCallback(window,glfw_window_size_call_back);
    glfwSetKeyCallback(window,glfw_key_callback);

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    if(!gladLoadGL()){
	    std:: cout << "can't load glad";
	    return -1;
    }
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;

    /* Loop until the user closes the window */
    glClearColor(0,1,1,1);
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
