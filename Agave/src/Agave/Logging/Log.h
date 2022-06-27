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

    class AGAVE_API Log
    {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return ms_coreLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return ms_clientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> ms_coreLogger;
        static std::shared_ptr<spdlog::logger> ms_clientLogger;
    };
}

///=============================================================================
/// Core Log Macros
///=============================================================================
#define AgCoreLogTrace(...) ::Agave::Log::GetCoreLogger()->trace(__VA_ARGS__);
#define AgCoreLogInfo(...) ::Agave::Log::GetCoreLogger()->info(__VA_ARGS__);
#define AgCoreLogWarn(...) ::Agave::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define AgCoreLogError(...) ::Agave::Log::GetCoreLogger()->error(__VA_ARGS__);

///=============================================================================
/// Client Log Macros
///=============================================================================
#define AgLogTrace(...) ::Agave::Log::GetClientLogger()->trace(__VA_ARGS__);
#define AgLogInfo(...) ::Agave::Log::GetClientLogger()->info(__VA_ARGS__);
#define AgLogWarn(...) ::Agave::Log::GetClientLogger()->warn(__VA_ARGS__);
#define AgLogError(...) ::Agave::Log::GetClientLogger()->error(__VA_ARGS__);

#endif // #ifndef AGAVE_LOG_H