///=============================================================================
/// OpenGLShader.cpp
/// Platform/OpenGL
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// OpenGL implementation of Shader
///=============================================================================

///=============================================================================
/// Includes
///=============================================================================
#include "Platform/OpenGL/OpenGLShader.h"
#include "Agave/Core/Assert.h"
#include "Agave/Core/Log.h"
#include <glad/glad.h>
#include <vector>

namespace Agave {

    ///=========================================================================
    ///=========================================================================
    OpenGLShader::OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc)
    {
        // Create an empty vertex shader handle
        uint32_t vertexShader = glCreateShader(GL_VERTEX_SHADER);

        // Send the vertex shader source code to GL
        // Note that std::string's .c_str is NULL character terminated.
        const char* source = vertexSrc.c_str();
        glShaderSource(vertexShader, 1, &source, 0);

        // Compile the vertex shader
        glCompileShader(vertexShader);

        int isCompiled = 0;
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &isCompiled);
        if(isCompiled == GL_FALSE)
        {
            int maxLength = 0;
            glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &maxLength);

            // The maxLength includes the NULL character
            std::vector<char> infoLog(maxLength);
            glGetShaderInfoLog(vertexShader, maxLength, &maxLength, &infoLog[0]);

            // We don't need the shader anymore.
            glDeleteShader(vertexShader);

            // Use the infoLog as you see fit.
            AGAVE_CORE_ERROR("Vertex shader compilation failure!");
            AGAVE_CORE_ERROR("{0}", infoLog.data());
            AGAVE_CORE_ASSERT(false);

            // In this simple program, we'll just leave
            return;
        }

        // Create an empty fragment shader handle
        uint32_t fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

        // Send the fragment shader source code to GL
        // Note that std::string's .c_str is NULL character terminated.
        source = fragmentSrc.c_str();
        glShaderSource(fragmentShader, 1, &source, 0);

        // Compile the fragment shader
        glCompileShader(fragmentShader);

        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &isCompiled);
        if(isCompiled == GL_FALSE)
        {
            int maxLength = 0;
            glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);

            // The maxLength includes the NULL character
            std::vector<char> infoLog(maxLength);
            glGetShaderInfoLog(fragmentShader, maxLength, &maxLength, &infoLog[0]);

            // We don't need the shader anymore.
            glDeleteShader(fragmentShader);
            // Either of them. Don't leak shaders.
            glDeleteShader(vertexShader);

            // Use the infoLog as you see fit.
            AGAVE_CORE_ERROR("Fragment shader compilation failure!");
            AGAVE_CORE_ERROR("{0}", infoLog.data());
            AGAVE_CORE_ASSERT(false);

            // In this simple program, we'll just leave
            return;
        }

        // Vertex and fragment shaders are successfully compiled.
        // Now time to link them together into a program.
        // Get a program object.
        m_renderId = glCreateProgram();

        // Attach our shaders to our program
        glAttachShader(m_renderId, vertexShader);
        glAttachShader(m_renderId, fragmentShader);

        // Link our program
        glLinkProgram(m_renderId);

        // Note the different functions here: glGetProgram* instead of glGetShader*.
        int isLinked = 0;
        glGetProgramiv(m_renderId, GL_LINK_STATUS, &isLinked);
        if(isLinked == GL_FALSE)
        {
            int maxLength = 0;
            glGetProgramiv(m_renderId, GL_INFO_LOG_LENGTH, &maxLength);

            // The maxLength includes the NULL character
            std::vector<char> infoLog(maxLength);
            glGetProgramInfoLog(m_renderId, maxLength, &maxLength, &infoLog[0]);

            // We don't need the program anymore.
            glDeleteProgram(m_renderId);
            // Don't leak shaders either.
            glDeleteShader(vertexShader);
            glDeleteShader(fragmentShader);

            // Use the infoLog as you see fit.
            AGAVE_CORE_ERROR("Shader link failure!");
            AGAVE_CORE_ERROR("{0}", infoLog.data());
            AGAVE_CORE_ASSERT(false);

            // In this simple program, we'll just leave
            return;
        }

        // Always detach shaders after a successful link.
        glDetachShader(m_renderId, vertexShader);
        glDetachShader(m_renderId, fragmentShader);
    }

    OpenGLShader::~OpenGLShader()
    {
        glDeleteProgram(m_renderId);
    }

    void OpenGLShader::Bind() const
    {
        glUseProgram(m_renderId);
    }

    void OpenGLShader::Unbind() const
    {
        glUseProgram(0);
    }
}