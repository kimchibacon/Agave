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
    IncludeDir["glad"] = "Agave/vendor/glad/include"
    IncludeDir["imgui"] = "Agave/vendor/imgui"
    IncludeDir["glm"] = "Agave/vendor/glm"

    group "Dependencies"
        include "Agave/vendor/glfw"
        include "Agave/vendor/glad"
        include "Agave/vendor/imgui"
    group ""

    project "Agave"
        location "Agave"
        kind "SharedLib"
        staticruntime "Off"
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
            "%{IncludeDir.glfw}",
            "%{IncludeDir.glad}",
            "%{IncludeDir.imgui}",
            "%{IncludeDir.glm}"
        }

        links { 
            "GLFW",
            "GLAD",
            "ImGui",
            "opengl32.lib"
        }

        filter "system:windows"
            cppdialect "C++11"
            systemversion "latest"

            defines {
                "AGAVE_PLATFORM_WINDOWS",
                "AGAVE_BUILD_DLL",
                "GLFW_INCLUDE_NONE"
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
            runtime "Debug"


        filter "configurations:Release"
            defines "AGAVE_RELEASE"
            optimize "On"
            runtime "Release"

        filter "configurations:Dist"
            defines "AGAVE_DIST"
            optimize "On"
            runtime "Release"

    project "Sandbox"
        location "Sandbox"
        kind "ConsoleApp"
        staticruntime "Off"
        language "C++"
        targetdir ("bin/" .. outputdir .. "/%{prj.name}")
        objdir ("obj/" .. outputdir .. "/%{prj.name}")

        files {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp"
        }

        includedirs {
            "Agave/src",
            "Agave/vendor/spdlog/include",
            "Agave/vendor/glm"
        }

        links {
            "Agave"
        }

        filter "system:windows"
            cppdialect "C++11"
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
            runtime "Debug"

        filter "configurations:Release"
            defines "AGAVE_RELEASE"
            optimize "On"
            runtime "Release"

        filter "configurations:Dist"
            defines "AGAVE_DIST"
            optimize "On"
            runtime "Release"