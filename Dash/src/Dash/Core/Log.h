#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Dash
{
	class DASH_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}


// Core log
#define DS_CORE_TRACE(...)   ::Dash::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define DS_CORE_INFO(...)    ::Dash::Log::GetCoreLogger()->info(__VA_ARGS__)
#define DS_CORE_WARN(...)    ::Dash::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define DS_CORE_ERROR(...)   ::Dash::Log::GetCoreLogger()->error(__VA_ARGS__)
#define DS_CORE_FATAL(...)   ::Dash::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log
#define DS_TRACE(...)        ::Dash::Log::GetClientLogger()->trace(__VA_ARGS__)
#define DS_INFO(...)         ::Dash::Log::GetClientLogger()->info(__VA_ARGS__)
#define DS_WARN(...)         ::Dash::Log::GetClientLogger()->warn(__VA_ARGS__)
#define DS_ERROR(...)        ::Dash::Log::GetClientLogger()->error(__VA_ARGS__)
#define DS_FATAL(...)        ::Dash::Log::GetClientLogger()->critical(__VA_ARGS__)
