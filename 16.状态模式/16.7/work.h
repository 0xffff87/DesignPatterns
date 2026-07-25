#pragma once

class State;

class Work
{
public:
    Work();

    void SetHour(int hour) { m_hour = hour; }
    int GetHour() const { return m_hour; }

    void SetTaskFinished(bool finish) { m_finish = finish; }
    bool GetTaskFinished() const { return m_finish; }

    void SetState(State *state);
    void WriteProgram();

private:
    int m_hour;
    bool m_finish;
    State *m_current;
};