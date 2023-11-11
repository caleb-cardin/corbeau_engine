//
// Created by cabo_ on 11/8/2023.
//

#include "Render.h"

#include "memory/Memory.h"

namespace corbeau {


    std::unique_ptr<Render> Render::makeRender() {
        return std::make_unique<Render>();
    }

    void Render::init()
    {
        API = Render_interface::makeAPI();
        API->initAPI();
    }

    void Render::updateContextSize(int x, int y)
    {
        API->setViewSize(x, y);
    }

    void Render::setClearColor(float r, float g, float b, float a)
    {
        API->setClearColor(r, g, b, a);
    }

    void Render::clear()
    {
        API->clearView();
    }
} // corbeau