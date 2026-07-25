#include "state.h"
#include "work.h"
#include <iostream>

using namespace std;

void ForenoonState::WriteProgram(Work *work)
{
    if (work->GetHour() < 12)
    {
        cout << "当前时间：" << work->GetHour() << "点 上午工作，精神百倍" << endl;
    }
    else
    {
        work->SetState(new NoonState());
        work->WriteProgram();
    }
}

void NoonState::WriteProgram(Work *work)
{
    if (work->GetHour() < 13)
    {
        cout << "当前时间：" << work->GetHour() << "点 中午工作，困了" << endl;
    }
    else
    {
        work->SetState(new AfternoonState());
        work->WriteProgram();
    }
}

void AfternoonState::WriteProgram(Work *work)
{
    if (work->GetHour() < 17)
    {
        cout << "当前时间：" << work->GetHour() << "点 下午工作，精神百倍" << endl;
    }
    else
    {
        work->SetState(new EveningState());
        work->WriteProgram();
    }
}

void EveningState::WriteProgram(Work *work)
{
    if (work->GetTaskFinished())
    {
        work->SetState(new RestState());
        work->WriteProgram();
    }
    else
    {
        if (work->GetHour() < 21)
        {
            cout << "当前时间：" << work->GetHour() << "点 加班哦，疲惫之极" << endl;
        }
        else
        {
            work->SetState(new SleepingState());
            work->WriteProgram();
        }
    }
}

void SleepingState::WriteProgram(Work *work)
{
    cout << "当前时间：" << work->GetHour() << "点 不行了，睡着了" << endl;
}

void RestState::WriteProgram(Work *work)
{
    cout << "当前时间：" << work->GetHour() << "点 下班回家了" << endl;
}