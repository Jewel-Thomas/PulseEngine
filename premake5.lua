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
	IncludeDirs["glm"] = "Pulse/vendor/glm"
	
	include "Pulse/vendor/GLFW"
	include "Pulse/vendor/Glad"
	include "Pulse/vendor/imgui"
	
project "Pulse"
	location "Pulse"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" ..outputdir.. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

	pchheader "plspch.h"
	pchsource "%{prj.name}/src/plspch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDirs.GLFW}",
		"%{IncludeDirs.Glad}",
		"%{IncludeDirs.Imgui}",
		"%{IncludeDirs.glm}"
	}

	links
	{
		"GLFW",
		"opengl32.lib",
		"Glad",
		"ImGui"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	filter "system:windows"
		systemversion "latest"
		buildoptions { "/utf-8" }

		defines
		{
			"PLS_PLATFORM_WINDOWS",
			"GLFW_INCLUDE_NONE"
		}
	
	filter "configurations:Debug"
		defines
		{
			"PLS_DEBUG_BUILD",
			"PLS_ENABLE_ASSERTS"
		}
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "PLS_RELEASE_BUILD"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "PLS_DIST_BUILD"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "on"
	cppdialect "C++17"

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
		"Pulse/src",
		"%{IncludeDirs.glm}",
		"%{IncludeDirs.Imgui}"
	}

	links
	{
		"Pulse",
		"ImGui"
	}

	filter "system:windows"
		systemversion "latest"
		buildoptions { "/utf-8" }

		defines
		{
			"PLS_PLATFORM_WINDOWS"
		}
	
	filter "configurations:Debug"
		defines "PLS_DEBUG_BUILD"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "PLS_RELEASE_BUILD"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "PLS_DIST_BUILD"
		runtime "Release"
		optimize "on"