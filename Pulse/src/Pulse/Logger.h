#pragma once
#include <memory>
#include "spdlog/spdlog.h"
#include "Core.h"

namespace Pulse {

	class Pulse_API Logger
	{
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	};

}


#ifdef PLS_DEBUG
	// Engine Log Macros
	#define PLS_CORE_TRACE(...)		do { ::Pulse::Logger::GetCoreLogger()->trace(__VA_ARGS__); } while(0)
	#define PLS_CORE_DEBUG(...)		do { ::Pulse::Logger::GetCoreLogger()->debug(__VA_ARGS__);} while(0)
	#define PLS_CORE_INFO(...)		do { ::Pulse::Logger::GetCoreLogger()->info(__VA_ARGS__);  } while(0)
	#define PLS_CORE_WARN(...)		do { ::Pulse::Logger::GetCoreLogger()->warn(__VA_ARGS__);  } while(0)
	#define PLS_CORE_ERROR(...)		do { ::Pulse::Logger::GetCoreLogger()->error(__VA_ARGS__); } while(0)
	#define PLS_CORE_FATAL(...)		do { ::Pulse::Logger::GetCoreLogger()->critical(__VA_ARGS__); } while(0)

	// Application Log Macros
	#define PLS_TRACE(...)			do { ::Pulse::Logger::GetClientLogger()->trace(__VA_ARGS__); } while(0)
	#define PLS_DEBUG(...)			do { ::Pulse::Logger::GetClientLogger()->debug(__VA_ARGS__); } while(0)
	#define PLS_INFO(...)			do { ::Pulse::Logger::GetClientLogger()->info(__VA_ARGS__); } while(0)
	#define PLS_WARN(...)			do { ::Pulse::Logger::GetClientLogger()->warn(__VA_ARGS__); } while(0)
	#define PLS_ERROR(...)			do { ::Pulse::Logger::GetClientLogger()->error(__VA_ARGS__); } while(0)
	#define PLS_FATAL(...)			do { ::Pulse::Logger::GetClientLogger()->critical(__VA_ARGS__); } while(0)
#else
	// Engine Log Macros
	#define PLS_CORE_TRACE(...)		((void)0)
	#define PLS_CORE_DEBUG(...)		((void)0)
	#define PLS_CORE_INFO(...)		((void)0)
	#define PLS_CORE_WARN(...)		((void)0)
	#define PLS_CORE_ERROR(...)		((void)0)
	#define PLS_CORE_FATAL(...)		((void)0)

	// Application Log Macros
	#define PLS_TRACE(...)			((void)0)
	#define PLS_DEBUG(...)			((void)0)
	#define PLS_INFO(...)			((void)0)
	#define PLS_WARN(...)			((void)0)
	#define PLS_ERROR(...)			((void)0)
	#define PLS_FATAL(...)			((void)0)
#endif

