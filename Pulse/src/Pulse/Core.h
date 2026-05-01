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
