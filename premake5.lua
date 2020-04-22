-- Variables
output = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Workspace
workspace "Dash"
	architecture "x64"
	
	configurations {
		"Debug",
		"Release",
		"Dist"
	}

-- Include directories relative to root
IncludeDir = {}
IncludeDir["GLFW"] = "Dash/deps/GLFW/include"
IncludeDir["Glad"] = "Dash/deps/Glad/include"

include "Dash/deps/GLFW"
include "Dash/deps/Glad"

-- Engine project
project "Dash"
	location "Dash"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. output .. "/%{prj.name}")
	objdir ("bin/obj/" .. output .. "/%{prj.name}")

	pchheader "dspch.h"
	pchsource "Dash/src/dspch.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/src",
		"%{prj.name}/deps/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}"
	}

	links {
		"GLFW",
		"Glad",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"DS_PLATFORM_WINDOWS",
			"DS_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. output .. "/Game")
		}

	filter "configurations:Debug"
		defines "DS_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "DS_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "DS_DIST"
		buildoptions "/MD"
		optimize "On"

-- Game project
project "Game"
	location "Game"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. output .. "/%{prj.name}")
	objdir ("bin/obj/" .. output .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"Dash/deps/spdlog/include",
		"Dash/src"
	}

	links {
		"Dash"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"DS_PLATFORM_WINDOWS"
		}
		
	filter "configurations:Debug"
		defines "DS_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "DS_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "DS_DIST"
		buildoptions "/MD"
		optimize "On"