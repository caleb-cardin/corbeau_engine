//
// Created by cabo_ on 11/8/2023.
//

#pragma once

#include "Application.h"

extern corbeau::Application* corbeau::createApplication(); // NOLINT(*-redundant-declaration)

int main(int argc, char** argv)
{
    auto app = corbeau::createApplication();
    app->init();
    app->run();
    app->shutdown();
    delete app;
    return 0;
}
