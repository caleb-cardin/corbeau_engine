//
// Created by cabo_ on 11/8/2023.
//
#include "Render_interface.h"

#include <memory>


#include "opengl/Render_impl_gl.h"


namespace corbeau {

    std::unique_ptr<Render_interface> Render_interface::makeAPI()
    {
        return std::make_unique<Render_impl_gl>();
    }


} // namespace corbeau