///=============================================================================
/// Log.h
/// Agave/Logging
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// Logging wrapper for spdlog library
///=============================================================================

#ifndef AGAVE_LOG_H
#define AGAVE_LOG_H

///=============================================================================
/// Includes
///=============================================================================
#include "Agave/Core/Base.h"
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Agave {

    ///=========================================================================
    ///=========================================================================
    class AGAVE_API Log
    {
    public:
        static void Init();

        static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return ms_coreLogger; }
        static std::shared_ptr<spdlog::logger>& GetClientLogger() { return ms_clientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> ms_coreLogger;
        static std::shared_ptr<spdlog::logger> ms_clientLogger;
    };
}

///=============================================================================
/// Core Log Macros
///=============================================================================
#define AGAVE_CORE_TRACE(...) ::Agave::Log::GetCoreLogger()->trace(__VA_ARGS__);
#define AGAVE_CORE_INFO(...) ::Agave::Log::GetCoreLogger()->info(__VA_ARGS__);
#define AGAVE_CORE_WARN(...) ::Agave::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define AGAVE_CORE_ERROR(...) ::Agave::Log::GetCoreLogger()->error(__VA_ARGS__);

///=============================================================================
/// Client Log Macros
///=============================================================================
#define AGAVE_TRACE(...) ::Agave::Log::GetClientLogger()->trace(__VA_ARGS__);
#define AGAVE_INFO(...) ::Agave::Log::GetClientLogger()->info(__VA_ARGS__);
#define AGAVE_WARN(...) ::Agave::Log::GetClientLogger()->warn(__VA_ARGS__);
#define AGAVE_ERROR(...) ::Agave::Log::GetClientLogger()->error(__VA_ARGS__);

#endif // #ifndef AGAVE_LOG_H