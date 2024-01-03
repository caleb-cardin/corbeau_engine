add_executable(Colibri
        ColibriEditor.cppm
)
target_link_libraries(Colibri PUBLIC CorbeauEngine)
target_compile_features(Colibri PUBLIC cxx_std_20)

target_include_directories(Colibri SYSTEM PUBLIC
        C:/VulkanSDK/1.3.268.0/Include)
