workspace "Pulse"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDirs = {}
IncludeDirs["GLFW"] = "Pulse/vendor/GLFW/include" 
IncludeDirs["Glad"] = "Pulse/vendor/Glad/include" 

include "Pulse/vendor/GLFW"
include "Pulse/vendor/Glad"

project "Pulse"
	location "Pulse"
	kind "SharedLib"
	language "C++"

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
		"%{IncludeDirs.Glad}"
	}

	links
	{
		"GLFW",
		"opengl32.lib",
		"Glad"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		buildoptions { "/utf-8" }

		defines
		{
			"PLS_PLATFORM_WINDOWS",
			"PLS_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir.. "/Sandbox")
		}
	
	filter "configurations:Debug"
		defines
		{
			"PLS_DEBUG_BUILD",
			"PLS_ENABLE_ASSERTS"
		}
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "PLS_RELEASE_BUILD"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "PLS_DIST_BUILD"
		buildoptions "/MD"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

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
		staticruntime "On"
		systemversion "latest"
		buildoptions { "/utf-8" }

		defines
		{
			"PLS_PLATFORM_WINDOWS"
		}
	
	filter "configurations:Debug"
		defines "PLS_DEBUG_BUILD"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "PLS_RELEASE_BUILD"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "PLS_DIST_BUILD"
		buildoptions "/MD"
		optimize "On"