//
// Created by cabo_ on 11/8/2023.
//

#pragma once

#include "render/Render_interface.h"
#include <glad/gl.h>
#include <GLFW/glfw3.h>


namespace corbeau {

    class Render_impl_gl : public Render_interface {
    public:
        Render_impl_gl() = default;
        ~Render_impl_gl() override = default;

        void initAPI() override;
        void setViewSize(int width, int height) override;
        void setClearColor(float r, float g, float b, float a) override;
        void clearView() override;
    };

} // namespace corbeau