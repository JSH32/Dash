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

#ifdef DS_ENABLE_ASSERTS
	#define DS_ASSERT(x, ...) { if(!(x)) { DS_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define DS_CORE_ASSERT(x, ...) { if(!(x)) { DS_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define DS_ASSERT(x, ...);
	#define DS_CORE_ASSERT(x, ...);
#endif

#define BIT(x) (1 << x)