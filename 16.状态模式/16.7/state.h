#pragma once

class Work;

class State
{
public:
    virtual ~State() {}
    virtual void WriteProgram(Work *work) = 0;
};

// 上午工作状态
class ForenoonState : public State
{
public:
    void WriteProgram(Work *work) override;
};

// 中午工作状态
class NoonState : public State
{
public:
    void WriteProgram(Work *work) override;
};

// 下午工作状态
class AfternoonState : public State
{
public:
    void WriteProgram(Work *work) override;
};

// 晚上工作状态
class EveningState : public State
{
public:
    void WriteProgram(Work *work) override;
};

// 睡眠状态
class SleepingState : public State
{
public:
    void WriteProgram(Work *work) override;
};

// 下班休息状态
class RestState : public State
{
public:
    void WriteProgram(Work *work) override;
};