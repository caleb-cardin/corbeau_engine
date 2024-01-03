add_library(CorbeauEngine STATIC
        Corbeau.cppm
        src/Application.cppm
        src/utility/Assertion.cppm
        src/utility/Logger.cppm
        src/engine/threads/Threading.cppm
        src/memory/Memory.cppm
        src/render/Render.cppm
        src/memory/Allocator.cppm
        src/memory/Pointer.cppm
        src/core/math/Math.cppm
        src/core/math/Vector.cppm
        src/core/math/Matrix.cppm
        src/utility/Debug.cppm
)
target_link_libraries(CorbeauEngine PRIVATE glfw)
target_link_libraries(CorbeauEngine PRIVATE
        C:/VulkanSDK/1.3.268.0/Lib/vulkan-1.lib)
target_include_directories(CorbeauEngine PUBLIC src )
target_include_directories(CorbeauEngine SYSTEM PUBLIC
        ../lib/spdlog/include/
        C:/VulkanSDK/1.3.268.0/Include)

target_compile_features(CorbeauEngine PUBLIC cxx_std_20)
if (CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_definitions(CorbeauEngine PRIVATE -DDEBUG=1)
    target_compile_definitions(CorbeauEngine PRIVATE -DCORBEAU_DEBUG_MODE=2)
elseif (CMAKE_BUILD_TYPE MATCHES RelWithDebInfo)
    target_compile_definitions(CorbeauEngine PRIVATE -DCORBEAU_DEBUG_MODE=1)
elseif (CMAKE_BUILD_TYPE MATCHES Release)
target_compile_definitions(CorbeauEngine PRIVATE -DCORBEAU_DEBUG_MODE=0)
else ()

endif()
