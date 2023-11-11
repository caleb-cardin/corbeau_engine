//
// Created by cabo_ on 11/8/2023.
//

#pragma once

#include <memory>

namespace corbeau {

    class Render_interface {
    public:
        virtual ~Render_interface() = default;

        virtual void initAPI() = 0;
        virtual void setViewSize(int width, int height) = 0;
        virtual void setClearColor(float r, float g, float b, float a) = 0;
        virtual void clearView() = 0;


        static std::unique_ptr<Render_interface> makeAPI();
    };

} // namespace corbeau