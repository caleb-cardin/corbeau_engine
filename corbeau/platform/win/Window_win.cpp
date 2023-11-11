//
// Created by cabo_ on 11/8/2023.
//

#include "Window_win.h"

#include "utility/Assertion.h"

namespace corbeau {
    void Window_win::init()
    {
        if (!glfwInit())
        {
            expect([]() {return false;}, Error_code::init_error);
        }
        glfwSetErrorCallback(error_Callback);

        m_Main_Window = glfwCreateWindow(
                m_Width, m_Height, "Corbeau Main Window", nullptr, nullptr
                );
        expect([this]() {return m_Main_Window;}, Error_code::init_error);


        glfwSetKeyCallback(m_Main_Window, key_Callback);
        glfwMakeContextCurrent(m_Main_Window);

    }

    void Window_win::init(int w, int h)
    {
        m_Width = w;
        m_Height = h;
        init();
    }

    void Window_win::shutdown()
    {
        glfwDestroyWindow(m_Main_Window);

        glfwTerminate();
    }

    void Window_win::beginUpdate()
    {
        glfwGetFramebufferSize(m_Main_Window, &m_Width, &m_Height);
    }

    void Window_win::endUpdate()
    {
        glfwSwapBuffers(m_Main_Window);
        glfwPollEvents();
    }

    void Window_win::close()
    {
        glfwSetWindowShouldClose(m_Main_Window ,1);
    }

    bool Window_win::shouldClose()
    {
        return glfwWindowShouldClose(m_Main_Window);
    }

    void Window_win::getSize(int* x, int* y)
    {
        *x = m_Width;
        *y = m_Height;
    }

    bool Window_win::isFullscreen()
    {
        return false;
    }

    void Window_win::setVsync(bool toggle)
    {

    }

    bool Window_win::isVsync()
    {
        return false;
    }

    void Window_win::error_Callback(int error, const char *description)
    {
        fprintf(stderr, "Error: %s\n", description);
    }

    void Window_win::key_Callback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
            glfwSetWindowShouldClose(window, GLFW_TRUE);
    }

} // corbeau