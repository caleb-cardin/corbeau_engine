//
// Created by cabo_ on 11/8/2023.
//
#pragma once

#include <memory>

namespace corbeau {

    class Window {
    public:
        virtual ~Window() = default;


        virtual void init() = 0;
        virtual void shutdown() = 0;

        virtual void beginUpdate() = 0;
        virtual void endUpdate() = 0;

        virtual void close() = 0;
        virtual bool shouldClose() = 0;

        virtual void getSize(int* x, int* y) = 0;

        virtual bool isFullscreen() = 0;

        virtual void setVsync(bool toggle) = 0;
        virtual bool isVsync() = 0;

        static std::unique_ptr<Window> makeNewWindow();

    protected:




    private:



    };

} // corbeau
