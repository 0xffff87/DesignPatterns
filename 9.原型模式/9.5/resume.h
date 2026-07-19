#pragma once
#include <string>
#include <iostream>

using namespace std;

// 工作经历（引用类型成员，用于演示浅复制）
class WorkExperience
{
public:
    string workDate;
    string company;
};

class Resume
{
public:
    Resume(string name) : m_name(name), m_age(0), m_ownWork(true)
    {
        m_work = new WorkExperience();
    }

    // 浅复制：值类型成员逐个拷贝，引用成员只复制指针
    Resume(const Resume& resume)
        : m_name(resume.m_name)
        , m_sex(resume.m_sex)
        , m_age(resume.m_age)
        , m_work(resume.m_work)
        , m_ownWork(false)
    {
    }

    ~Resume()
    {
        // 浅复制时多个 Resume 共享同一份 WorkExperience，只由原型负责释放
        if (m_ownWork)
        {
            delete m_work;
            m_work = nullptr;
        }
    }

    void SetPersonalInfo(string sex, int age)
    {
        m_sex = sex;
        m_age = age;
    }

    void SetWorkExperience(string timeArea, string company)
    {
        m_work->workDate = timeArea;
        m_work->company = company;
    }

    void Display()
    {
        cout << m_name << " " << m_sex << " " << m_age << endl;
        cout << "工作经历：" << m_work->workDate << " " << m_work->company << endl;
    }

    // 等价于 C# 的 MemberwiseClone：浅复制
    Resume* Clone() { return new Resume(*this); }

private:
    string m_name;
    string m_sex;
    int m_age;
    WorkExperience* m_work;
    bool m_ownWork;
};
