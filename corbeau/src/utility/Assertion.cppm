// Created by cabo_ on 12/28/2023.
//
module;

#include <source_location>
#include <sstream>
#include <iostream>

export module Assertion;

import Debug;

namespace corbeau {

    template<typename Target=std::string, typename Source=std::string>
    constexpr auto to(Source arg)->Target
    {
        std::stringstream buf;
        Target result;

        if (!(buf << arg)
            || !(buf >> result)
            || !(buf >> std::ws).eof())
        { throw std::runtime_error{"to<>() failed"}; }

        return result;
    }
}

export namespace corbeau {

    enum class Error_action { ignore, throwing, terminate, log};
    // ReSharper disable once CppDFAConstantFunctionResult
    constexpr auto getDefaultErrAction()
    {
        if constexpr (debug::getEngineBuildMode() == debug::Corbeau_build_mode::debug)
        {
            return Error_action::throwing;
        }
        if constexpr (debug::getEngineBuildMode() == debug::Corbeau_build_mode::development)
        {
            return Error_action::log;
        }
        if constexpr (debug::getEngineBuildMode() == debug::Corbeau_build_mode::testing)
        {
            return Error_action::ignore;
        }
        else
        {
            return Error_action::terminate;
        }
    }
    constexpr Error_action default_error_action = getDefaultErrAction();


    enum class Error_code { gen_error, init_error, unexpected_result_error };
    constexpr Error_code default_error_code = Error_code::gen_error;

    const std::string Error_code_names[] = {"General Error", "Initialization Error", "Unexpected Result Error"};


    template<Error_action action = default_error_action, class C>
    constexpr auto expect(C cond, Error_code x = default_error_code, const std::source_location loc = std::source_location::current())->void
    {
        if constexpr (action == Error_action::log)
            if (!cond())
            {
                std::clog << "expect() Error: '" << Error_code_names[static_cast<int>(x)]
                          << "'\nIn file : '" << loc.file_name()
                          << "'\nOn line : " << loc.line()
                          <<'\n';
            }
        if constexpr (action == Error_action::throwing)
            if (!cond())
            {
                std::cerr << "expect() Error: '" << Error_code_names[static_cast<int>(x)]
                << "'\nIn file : '" << loc.file_name()
                << "'\nOn line : " << loc.line()
                <<'\n';
                static_assert(cond());
            }
        if constexpr (action == Error_action::terminate)
        {
            if (!cond())
                std::terminate();
        }
    }

    /* Corbeau Assertion */
    constexpr auto assert_crb(auto cond)->void requires std::is_function_v<bool()>
    {
        static_assert(cond());
    }
}

