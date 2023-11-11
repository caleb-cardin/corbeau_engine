//
// Created by cabo_ on 11/9/2023.
//
#pragma once

#include <spdlog/spdlog.h>


namespace corbeau {

//    class Logger {
//
//    };

#define log(...)          spdlog::info(__VA_ARGS__)
#define log_info(...)     spdlog::info(__VA_ARGS__)
#define log_warn(...)     spdlog::warn(__VA_ARGS__)
#define log_error(...)    spdlog::error(__VA_ARGS__)
#define log_critical(...) spdlog::critical(__VA_ARGS__)
} // corbeau
