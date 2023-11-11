//
// Created by cabo_ on 11/8/2023.
//

#pragma once

#include <memory>

#include "Render_interface.h"

namespace corbeau {

    class Render {
    public:
        Render() = default;
        ~Render() = default;

        void init();
        void updateContextSize(int x, int y);
        void setClearColor(float r, float g, float b, float a);
        void clear();

        static std::unique_ptr<Render> makeRender();
    private:
        std::unique_ptr<Render_interface> API = nullptr;

    };

} // corbeau
