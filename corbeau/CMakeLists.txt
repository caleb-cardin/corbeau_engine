add_library(CorbeauEngine STATIC
        src/Corbeau.h
        src/utility/Application.cpp
        src/utility/Application.h
        src/utility/Entry_point.h
        src/utility/Window.cpp
        src/utility/Window.h
        platform/win/Window_win.cpp
        platform/win/Window_win.h
        src/utility/Assertion.h
        src/render/Render_interface.h
        src/render/Render_interface.cpp
        driver/opengl/Render_impl_gl.h
        driver/opengl/Render_impl_gl.cpp
        src/render/Render.cpp
        src/render/Render.h
        src/render/Vertex_buffer.cpp
        src/render/Vertex_buffer.h
        src/memory/containers/Dynamic_array.cpp
        src/memory/containers/Dynamic_array.h
        src/memory/Memory.cpp
        src/memory/Memory.h
        src/memory/Allocator.cpp
        src/memory/Allocator.h
        src/utility/Logger.h
)
target_link_libraries(CorbeauEngine PRIVATE glfw glad)
target_include_directories(CorbeauEngine PUBLIC src platform driver ../lib/spdlog/include/)
target_compile_features(CorbeauEngine PUBLIC cxx_std_20)
