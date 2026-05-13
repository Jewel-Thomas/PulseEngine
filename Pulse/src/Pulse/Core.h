#pragma once

#ifdef PLS_PLATFORM_WINDOWS
	#ifdef PLS_BUILD_DLL
		#define Pulse_API __declspec(dllexport)
	#else
		#define Pulse_API __declspec(dllimport)
	#endif
#else
	#error Pulse currently supported for windows only. Other Platform support coming soon!
#endif

#ifdef PLS_ENABLE_ASSERTS
	#define PLS_ASSERT(x, ...)          do { if(!x) { PLS_ERROR("Assertion Failed : {0}", __VA_ARGS__); __debugbreak(); } } while(0)
	#define PLS_CORE_ASSERT(x, ...)     do { if(!x) { PLS_CORE_ERROR("Assertion Failed : {0}", __VA_ARGS__); __debugbreak(); } } while(0)
#else
	#define PLS_ASSERT(x, ...)          ((void)0)
	#define PLS_CORE_ASSERT(x, ...)     ((void)0)
#endif

#define BIT(x) (1 << x)
