// Created by cabo_ on 12/28/2023.
//
module;


#include <iostream>
#include <vector>

export module Application;

export import Assertion;
export import Allocator;
export import Pointer;


export auto main(int argc, char **argv)->int;

// interface
export namespace corbeau {
    class Application {
    public:
        Application() = default;
        virtual ~Application() = default;

        auto init()->void;
        auto shutdown()->void;

        auto run()->void;
    private:

    };
}

// impl
export namespace corbeau {
    void Application::init()
    {

    }

    void Application::shutdown()
    {

    }

    void Application::run()
    {
    }


}
export extern
auto createApplication()->corbeau::Application*;

export
auto main(int argc, char **argv)->int
{

    const auto app = createApplication();
    app->init();
    app->run();
    app->shutdown();
    delete app;
    return 0;
}