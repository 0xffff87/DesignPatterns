#include "work.h"
#include "state.h"

Work::Work() : m_hour(0), m_finish(false)
{
    m_current = new ForenoonState();
}

void Work::SetState(State *state)
{
    m_current = state;
}

void Work::WriteProgram()
{
    m_current->WriteProgram(this);
}
