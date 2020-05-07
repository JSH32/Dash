-- Variables
output = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Workspace
workspace "Dash"
	architecture "x64"
	startproject "Game"
	
	configurations {
		"Debug",
		"Release",
		"Dist"
	}

-- Include directories relative to root
IncludeDir = {}
IncludeDir["GLFW"] = "Dash/deps/GLFW/include"
IncludeDir["Glad"] = "Dash/deps/Glad/include"
IncludeDir["ImGui"] = "Dash/deps/imgui"
IncludeDir["glm"] = "Dash/deps/glm"

-- Grouping because undiagnosed OCD
group "Dependencies" 
	include "Dash/deps/GLFW"
	include "Dash/deps/Glad"
	include "Dash/deps/imgui"

-- Apparently this is needed to stop all projects from being grouped as deps
group ""

-- Engine project
project "Dash"
	location "Dash"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. output .. "/%{prj.name}")
	objdir ("bin/obj/" .. output .. "/%{prj.name}")

	pchheader "dspch.h"
	pchsource "Dash/src/dspch.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	defines {
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs {
		"%{prj.name}/src",
		"%{prj.name}/deps/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links {
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines {
			"DS_PLATFORM_WINDOWS",
			"DS_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "DS_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "DS_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "DS_DIST"
		runtime "Debug"
		optimize "on"

-- Game project
project "Game"
	location "Game"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. output .. "/%{prj.name}")
	objdir ("bin/obj/" .. output .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"Dash/deps/spdlog/include",
		"Dash/src",
		"Dash/deps",
		"%{IncludeDir.glm}"
	}

	links {
		"Dash"
	}

	filter "system:windows"
		systemversion "latest"

		defines {
			"DS_PLATFORM_WINDOWS"
		}
		
	filter "configurations:Debug"
		defines "DS_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "DS_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "DS_DIST"
		runtime "Release"
		optimize "on"