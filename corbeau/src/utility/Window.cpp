//
// Created by cabo_ on 11/8/2023.
//
#include "Window.h"

#include "win/Window_win.h"

namespace corbeau {

    std::unique_ptr<Window> Window::makeNewWindow()
    {
        return std::make_unique<Window_win>();
    }

} // corbeau