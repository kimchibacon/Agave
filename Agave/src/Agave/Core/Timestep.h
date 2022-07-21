#ifndef AGAVE_TIMESTEP_H
#define AGAVE_TIMESTEP_H

namespace Agave {

    class Timestep
    {
    public:
        Timestep(float time = 0.0f)
            : m_time(time)
        {}

    public:
        float GetSeconds() const { return m_time; }
        float GetMilliseconds() const { return m_time * 1000; }

        operator float() const { return m_time; }

    private:
        float m_time;
    };
}

#endif // #ifndef AGAVE_TIMESTEP_H