workspace "GameEngine"
	architecture "x64"
	startproject "SandBox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Logger"
	location "Logger"
	kind "SharedLib"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}	

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"GAME_ENGINE_PLATFORM_WINDOWS",
			"GAME_ENGINE_BUILD_DLL"
		}

	filter "configurations:Debug"
		defines "GAME_ENGINE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "GAME_ENGINE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "GAME_ENGINE_DIST"
		optimize "On"

project "GameEngine"
	location "GameEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"Logger/src"
	}
	
	links
	{
		"Logger"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"GAME_ENGINE_PLATFORM_WINDOWS",
			"GAME_ENGINE_BUILD_DLL"
		}

	filter "configurations:Debug"
		defines "GAME_ENGINE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "GAME_ENGINE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "GAME_ENGINE_DIST"
		optimize "On"

project "SandBox"
	location "SandBox"
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"GameEngine/src",
		"Logger/src"
	}

	links
	{
		"GameEngine",
		"Logger"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"GAME_ENGINE_PLATFORM_WINDOWS"
		}

		postbuildcommands
		{
			{"{COPY} ../bin/" .. outputdir .. "/Logger/*.dll ../bin/" .. outputdir .. "/SandBox"},
			{"{COPY} ../bin/" .. outputdir .. "/GameEngine/*.dll ../bin/" .. outputdir .. "/SandBox"}
		}

	filter "configurations:Debug"
		defines "GAME_ENGINE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "GAME_ENGINE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "GAME_ENGINE_DIST"
		optimize "On"
