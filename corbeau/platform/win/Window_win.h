//
// Created by cabo_ on 11/8/2023.
//

#pragma once

#include "utility/Window.h"


#include <GLFW/glfw3.h>

namespace corbeau {

    class Window_win : public Window {
    public:
        Window_win() = default;
        ~Window_win() override = default;

        void init() override;
        void init(int w, int h);
        void shutdown() override;
        void beginUpdate() override;
        void endUpdate() override;

        void close() override;
        bool shouldClose() override;

        void getSize(int* x, int* y) override;

        bool isFullscreen() override;

        void setVsync(bool toggle) override;
        bool isVsync() override;

    private:
        static void error_Callback(int error, const char* description);
        static void key_Callback(GLFWwindow* window, int key, int scancode, int action, int mods);

        GLFWwindow* m_Main_Window = nullptr;
        int m_Width = 1600;
        int m_Height = 900;
    };

} // corbeau
