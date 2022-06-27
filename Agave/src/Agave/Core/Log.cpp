///=============================================================================
/// Log.cpp
/// Agave/Logging
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// Logging wrapper for spdlog library
///=============================================================================

///=============================================================================
/// Includes
///=============================================================================
#include "Agave/Core/Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Agave {

    std::shared_ptr<spdlog::logger> Log::ms_coreLogger = nullptr;
    std::shared_ptr<spdlog::logger> Log::ms_clientLogger = nullptr;

    ///=========================================================================
    ///=========================================================================
    void Log::Init()
    {
        spdlog::set_pattern("%^[%T] %n: %v%$");
        ms_coreLogger = spdlog::stdout_color_mt("AGAVE");
        ms_coreLogger->set_level(spdlog::level::trace);

        ms_clientLogger = spdlog::stdout_color_mt("APP");
        ms_clientLogger->set_level(spdlog::level::trace);
    }
}