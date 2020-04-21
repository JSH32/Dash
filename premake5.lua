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
		"%{prj.name}/deps/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"DS_PLATFORM_WINDOWS",
			"DS_BUILD_DLL"
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. output .. "/Game")
		}

	filter "configurations:Debug"
		defines "DS_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "DS_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DS_DIST"
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
		symbols "On"

	filter "configurations:Release"
		defines "DS_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DS_DIST"
		optimize "On"