///=============================================================================
/// BufferLayout.h
/// Agave/Render
///
/// Copyright (c) 2022 Joshua Palmer. All rights reserved.
///
/// Buffer layout abstraction
///=============================================================================

#ifndef AGAVE_BUFFER_LAYOUT_H
#define AGAVE_BUFFER_LAYOUT_H

#include "Agave/Core/Base.h"
#include "Agave/Core/Assert.h"
#include <string>
#include <vector>

namespace Agave {

    ///=============================================================================
    /// ShaderDataType
    ///=============================================================================
    enum class ShaderDataType
    {
        None = 0,
        Float, Float2, Float3, Float4,
        Mat3, Mat4,
        Int, Int2, Int3, Int4,
        Bool
    };

    ///=============================================================================
    ///=============================================================================
    static uint32_t ShaderDataTypeSize(ShaderDataType type)
    {
        switch(type)
        {
        case ShaderDataType::Float:     return 4;
        case ShaderDataType::Float2:    return 4 * 2;
        case ShaderDataType::Float3:    return 4 * 3;
        case ShaderDataType::Float4:    return 4 * 4;
        case ShaderDataType::Mat3:      return 4 * 3 * 3;
        case ShaderDataType::Mat4:      return 4 * 4 * 4;
        case ShaderDataType::Int:       return 4;
        case ShaderDataType::Int2:      return 4 * 2;
        case ShaderDataType::Int3:      return 4 * 3;
        case ShaderDataType::Int4:      return 4 * 4;
        case ShaderDataType::Bool:      return 1;
        }

        AGAVE_CORE_ASSERT(false);
        return 0;
    }

    ///=============================================================================
    /// BufferElement
    ///=============================================================================
    struct BufferElement
    {
        ///=========================================================================
        /// Public Members
        ///=========================================================================
        std::string     m_name;
        ShaderDataType  m_type;
        uint32_t        m_size;
        size_t          m_offset;
        bool            m_normalized;

        ///=========================================================================
        /// Ctor/Dtor
        ///=========================================================================
        BufferElement() 
            : m_type(ShaderDataType::None)
            , m_size(0)
            , m_offset(0)
            , m_normalized(false)
        {}

        BufferElement(ShaderDataType type, const std::string& name, bool normalized = false)
            : m_name(name)
            , m_type(type) 
            , m_size(ShaderDataTypeSize(type))
            , m_offset(0)
            , m_normalized(normalized)

        {}

        ///=========================================================================
        /// Public Methods
        ///=========================================================================
        uint32_t GetComponentCount() const
        {
            switch (m_type)
            {
            case ShaderDataType::Float:     return 1;
            case ShaderDataType::Float2:    return 2;
            case ShaderDataType::Float3:    return 3;
            case ShaderDataType::Float4:    return 4;
            case ShaderDataType::Mat3:      return 3 * 3;
            case ShaderDataType::Mat4:      return 4 * 4;
            case ShaderDataType::Int:       return 1;
            case ShaderDataType::Int2:      return 2;
            case ShaderDataType::Int3:      return 3;
            case ShaderDataType::Int4:      return 4;
            case ShaderDataType::Bool:      return 1;
            }

            AGAVE_CORE_ASSERT(false);
            return 0;
        }
    };

    ///=============================================================================
    /// BufferLayout
    ///=============================================================================
    class BufferLayout
    {
    public:
        ///=========================================================================
        /// Ctor/Dtor
        ///=========================================================================
        BufferLayout() 
            : m_stride(0)
        {}

        BufferLayout(const std::initializer_list<BufferElement>& elements)
            : m_elements(elements)
        {
            CalculateOffsetsAndStride();
        }

        ///=========================================================================
        /// Public Methods
        ///=========================================================================
        const std::vector<BufferElement>& GetElements() const { return m_elements; }
        uint32_t GetStride() const { return m_stride; }

        ///=========================================================================
        /// Iterators
        ///=========================================================================
        std::vector<BufferElement>::iterator begin() { return m_elements.begin(); }
        std::vector<BufferElement>::iterator end() { return m_elements.end(); }
        std::vector<BufferElement>::const_iterator begin() const { return m_elements.begin(); }
        std::vector<BufferElement>::const_iterator end() const { return m_elements.end(); }

    private:
        ///=========================================================================
        /// Private Methods
        ///=========================================================================
        void CalculateOffsetsAndStride()
        {
            uint32_t offset = 0;
            m_stride = 0;
            for (auto& element : m_elements)
            {
                element.m_offset = offset;
                offset += element.m_size;
                m_stride += element.m_size;
            }
        }

    private:
        ///=========================================================================
        /// Private Members
        ///=========================================================================
        std::vector<BufferElement> m_elements;
        uint32_t m_stride;
    };
}
#endif // #ifndef AGAVE_BUFFER_LAYOUT_H