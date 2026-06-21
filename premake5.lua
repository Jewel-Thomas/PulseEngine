workspace "Pulse"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	startproject "Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDirs = {}
IncludeDirs["GLFW"] = "Pulse/vendor/GLFW/include" 
IncludeDirs["Glad"] = "Pulse/vendor/Glad/include"
IncludeDirs["Imgui"] = "Pulse/vendor/imgui"

include "Pulse/vendor/GLFW"
include "Pulse/vendor/Glad"
include "Pulse/vendor/imgui"

project "Pulse"
	location "Pulse"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" ..outputdir.. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

	pchheader "plspch.h"
	pchsource "%{prj.name}/src/plspch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDirs.GLFW}",
		"%{IncludeDirs.Glad}",
		"%{IncludeDirs.Imgui}"
	}

	links
	{
		"GLFW",
		"opengl32.lib",
		"Glad",
		"ImGui"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"
		buildoptions { "/utf-8" }

		defines
		{
			"PLS_PLATFORM_WINDOWS",
			"PLS_BUILD_DLL",
			"GLFW_INCLUDE_NONE",
			"IMGUI_IMPL_OPENGL_LOADER_CUSTOM"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}
	
	filter "configurations:Debug"
		defines
		{
			"PLS_DEBUG_BUILD",
			"PLS_ENABLE_ASSERTS"
		}
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "PLS_RELEASE_BUILD"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "PLS_DIST_BUILD"
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" ..outputdir.. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Pulse/vendor/spdlog/include",
		"Pulse/src"
	}

	links
	{
		"Pulse"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"
		buildoptions { "/utf-8" }

		defines
		{
			"PLS_PLATFORM_WINDOWS"
		}
	
	filter "configurations:Debug"
		defines "PLS_DEBUG_BUILD"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "PLS_RELEASE_BUILD"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "PLS_DIST_BUILD"
		runtime "Release"
		optimize "On"