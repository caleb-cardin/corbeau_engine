//
// Created by cabo_ on 11/8/2023.
//

#pragma once

#include <string>
#include <iostream>

namespace corbeau {

    enum class Error_action { ignore, throwing, terminating, logging};

    constexpr Error_action default_Error_Action = Error_action::throwing;

    enum class Error_code { range_error, length_error, init_error };
    static std::string Error_Name[] = { "range_error", "length_error", "init_error"};

    template<Error_action action = default_Error_Action, class C>
    constexpr void expect(C cond, Error_code x)
    {
        if constexpr (action == Error_action::logging)
            if (!cond()) std::cerr << "expect() failure: " << int(x) << ' ' << Error_Name[int(x)] << '\n';
        if constexpr (action == Error_action::throwing)
            if (!cond()) throw x;
        if constexpr (action == Error_action::terminating)
            if (!cond()) std::terminate();

    }

} // namespace corbeau