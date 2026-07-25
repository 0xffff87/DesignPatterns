#pragma once
#include <iostream>

using namespace std;

class Work
{
public:
    int GetHour() const { return m_hour; }
    void SetHour(int hour) { m_hour = hour; }
    bool GetTaskFinished() const { return m_finish; }
    void SetTaskFinished(bool finish) { m_finish = finish; }
    void WriteProgram() const 
    {
        if (m_hour < 12) 
        {
            cout << "当前时间：" << m_hour << "，上午工作，精神百倍" << endl;
        } 
        else if (m_hour < 13) 
        {
            cout << "当前时间：" << m_hour << "，中午工作，精神不佳" << endl;
        } 
        else if (m_hour < 17) 
        {
            cout << "当前时间：" << m_hour << "，下午工作，精神百倍" << endl;
        } else 
        {
            if (m_finish)
            {
                cout << "当前时间：" << m_hour << "，下班回家了" << endl;
            }
            else
            {
                if (m_hour < 21)
                {
                    cout << "当前时间：" << m_hour << "，加班哦，疲累之极" << endl;
                }
                else
                {
                    cout << "当前时间：" << m_hour << "，不行了，睡着了" << endl;
                }
            }
        }
    }
private:
    int m_hour;
    bool m_finish;
}; 