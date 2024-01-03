// Created by cabo_ on 1/3/2024.
//
export module Debug;


export namespace corbeau::debug {

    const enum class Corbeau_build_mode {
        testing = -1,
        release,
        development,
        debug
    };

    constexpr auto default_build_mode = CORBEAU_DEBUG_MODE;

    // ReSharper disable once CppDFAConstantFunctionResult
    constexpr auto makeCorbeauBuildMode()
    {
        if constexpr (default_build_mode == -1)
            return Corbeau_build_mode::testing;
        if constexpr (default_build_mode == 0)
            return Corbeau_build_mode::release;
        if constexpr (default_build_mode == 1)
            return Corbeau_build_mode::development;
        if constexpr (default_build_mode == 2)
            return Corbeau_build_mode::debug;
    }

    constexpr auto getEngineBuildMode()->Corbeau_build_mode {return makeCorbeauBuildMode();}
}