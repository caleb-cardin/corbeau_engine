add_executable(Colibri
        ColibriEditor.cpp
)
target_link_libraries(Colibri PUBLIC CorbeauEngine)
target_compile_features(Colibri PUBLIC cxx_std_20)