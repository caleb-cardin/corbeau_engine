//
// Created by cabo_ on 11/8/2023.
//
#include "Render_impl_gl.h"



namespace corbeau {

    void Render_impl_gl::initAPI()
    {
        gladLoadGL(glfwGetProcAddress);
    }

    void Render_impl_gl::setViewSize(int width, int height)
    {
        glViewport(0, 0, width, height);
    }

    void Render_impl_gl::setClearColor(float r, float g, float b, float a)
    {
        glClearColor(r, g, b, a);
    }

    void Render_impl_gl::clearView()
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }


} // namespace corbeau