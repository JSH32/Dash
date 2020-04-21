#pragma once

#ifdef DS_PLATFORM_WINDOWS
	#ifdef DS_BUILD_DLL
		#define DASH_API _declspec(dllexport)
	#else
		#define DASH_API _declspec(dllimport)
	#endif
#else
	#error Dash is currently only supported on the Windows platform!
#endif