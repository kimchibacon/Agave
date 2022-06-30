workspace "Agave"
    architecture "x64"
    startproject "Sandbox"

    configurations {
        "Debug",
        "Release",
        "Dist"
    }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    -- Include directories relative to root folder (solution directory)
    IncludeDir = {}
    IncludeDir["glfw"] = "Agave/vendor/glfw/include"

    include "Agave/vendor/glfw"

    project "Agave"
        location "Agave"
        kind "SharedLib"
        language "C++"
        targetdir ("bin/" .. outputdir .. "/%{prj.name}")
        objdir ("obj/" .. outputdir .. "/%{prj.name}")

        files {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp"
        }

        includedirs {
            "%{prj.name}/src",
            "%{prj.name}/vendor/spdlog/include",
            "%{IncludeDir.glfw}"
        }

        links { 
            "GLFW",
            "opengl32.lib"
        }

        filter "system:windows"
            cppdialect "C++11"
            staticruntime "On"
            systemversion "latest"

        defines {
            "AGAVE_PLATFORM_WINDOWS",
            "AGAVE_BUILD_DLL"
        }

        postbuildcommands {
            -- Copy engine dll to Sandbox
            ("{mkdir} ../bin/" .. outputdir .. "/Sandbox"),
            ("{copy} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

        filter "configurations:Debug"
            defines { 
                "AGAVE_DEBUG",
                "AGAVE_ENABLE_ASSERTS"
            } 
            symbols "On"

        filter "configurations:Release"
            defines "AGAVE_RELEASE"
            optimize "On"

        filter "configurations:Dist"
            defines "AGAVE_DIST"
            optimize "On"

    project "Sandbox"
        location "Sandbox"
        kind "ConsoleApp"
        language "C++"
        targetdir ("bin/" .. outputdir .. "/%{prj.name}")
        objdir ("obj/" .. outputdir .. "/%{prj.name}")

        files {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp"
        }

        includedirs {
            "Agave/src",
            "Agave/vendor/spdlog/include"
        }

        links {
            "Agave"
        }

        filter "system:windows"
            cppdialect "C++11"
            staticruntime "On"
            systemversion "latest"

        defines {
            "AGAVE_PLATFORM_WINDOWS"
        }

        filter "configurations:Debug"
            defines { 
                "AGAVE_DEBUG",
                "AGAVE_ENABLE_ASSERTS"
            } 
            symbols "On"

        filter "configurations:Release"
            defines "AGAVE_RELEASE"
            optimize "On"

        filter "configurations:Dist"
            defines "AGAVE_DIST"
            optimize "On"