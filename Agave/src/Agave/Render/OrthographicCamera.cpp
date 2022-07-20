#include "Agave/Render/OrthographicCamera.h"
#include <glm/gtc/matrix_transform.hpp>

namespace Agave {

    OrthographicCamera::OrthographicCamera(float left, float right, float bottom, float top)
        : m_projectionMatrix(glm::ortho(left, right, bottom, top, -1.0f, 1.0f))
        , m_position({ 0.0f, 0.0f, 0.0f })
        , m_rotation(0.0f)
    {
        RecalculateViewMatrix();
    }

    void OrthographicCamera::RecalculateViewMatrix()
    {
        glm::mat4 identityMatrix(1.0f);
        glm::mat4 transform = glm::translate(identityMatrix, m_position) *
            glm::rotate(identityMatrix, glm::radians(m_rotation), glm::vec3(0, 0, 1));

        m_viewMatrix = glm::inverse(transform);
        m_viewProjectionMatrix = m_projectionMatrix * m_viewMatrix;
    }
}