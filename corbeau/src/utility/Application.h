//
// Created by cabo_ on 11/7/2023.
//
#pragma once

#include <memory>

#include "Window.h"
#include "render/Render.h"
#include "memory/Memory.h"
#include "Logger.h"

namespace corbeau {

    class Application {
    public:
        Application() :
        main_window(Window::makeNewWindow()),
        render(Render::makeRender())
        {
            memory = std::make_unique<Memory>( 32768);
        }
        virtual ~Application() = default;

        void init();
        void shutdown();


        void run();
    private:
        std::unique_ptr<Window> main_window;
        std::unique_ptr<Render> render;
        std::unique_ptr<Memory> memory;
    };
    Application* createApplication();

} // corbeau
