#pragma once
#include <string>
#include <iostream>

using namespace std;

class WorkExperience
{
public:
    string workDate;
    string company;

    WorkExperience* Clone()
    {
        return new WorkExperience(*this);
    }
};

class Resume
{
public:
    Resume(string name) : m_name(name), m_age(0)
    {
        m_work = new WorkExperience();
    }

    ~Resume()
    {
        delete m_work;
        m_work = nullptr;
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

    // 深复制：工作经历也一并克隆出独立对象
    Resume* Clone()
    {
        Resume* obj = new Resume(m_work);
        obj->m_name = m_name;
        obj->m_sex = m_sex;
        obj->m_age = m_age;
        return obj;
    }

private:
    // 供 Clone 调用：克隆工作经历，而不是共享指针
    Resume(WorkExperience* work)
    {
        m_work = work->Clone();
    }

    string m_name;
    string m_sex;
    int m_age;
    WorkExperience* m_work;
};
