//
// Created by cabo_ on 11/7/2023.
//

#include "Application.h"
#include "memory/containers/Dynamic_array.h"

namespace corbeau {

    void Application::init() {
        main_window->init();
        render->init();

    }

    void Application::shutdown() {
        main_window->shutdown();
    }

    void Application::run() {


        Dynamic_array<float> dyn_array {10, memory->Allocator};
        auto f = 0.f;
        log_info("START1");
        for (int i = 0; i < 20000; i++)
        {
            dyn_array.add_element(f);
            f += 1.f;
        }
        log_info("END1");
        f = 0.f;
        std::vector<float> vec_arr { 10 };
        log_info("START2");
        for (int i = 0; i < 20000; i++)
        {
            vec_arr.emplace_back(f);
            f += 1.f;
        }
        log_info("END2");
        log_info("This is an info log message with runtime values: {}", 42);
        log_warn("This is a warning log message with runtime values: {}", 42);
        log_error("This is an error log message with runtime values: {}", 42);
        log_critical("This is a critical log message with runtime values: {}", 42);

        int x{}, y{};
        while (!main_window->shouldClose())
        {
            main_window->beginUpdate();
            main_window->getSize(&x, &y);

            render->updateContextSize(x, y);
            render->setClearColor(0.2f, 0.f, 0.2f, 1.f);
            render->clear();

            main_window->endUpdate();
        }

    }
} // corbeau