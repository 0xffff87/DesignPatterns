#pragma once
#include <string>
#include <iostream>

using namespace std;

class Resume
{
public:
    Resume(string name) : m_name(name), m_age(0) { }

    Resume(const Resume& resume)
    {
        m_name = resume.m_name;
        m_sex = resume.m_sex;
        m_age = resume.m_age;
        m_timeArea = resume.m_timeArea;
        m_company = resume.m_company;
    }

    void SetPersonalInfo(string sex, int age)
    {
        m_sex = sex;
        m_age = age;
    }

    void SetWorkExperience(string timeArea, string company)
    {
        m_timeArea = timeArea;
        m_company = company;
    }
    
    void Display()
    {
        cout << m_name << " " << m_sex << " " << m_age << " "
             << "工作经历：" << m_timeArea << " " << m_company << endl;
    }

    // MemberwiseClone 是 C# 里 Object 基类提供的一个受保护方法，用来做浅拷贝
    // 如果某个成员是指针/引用指向别的对象，新旧简历会共享那块内部对象
    Resume* Clone() { return new Resume(*this); }

private:
    string m_name;
    string m_sex;
    int m_age;
    string m_timeArea;
    string m_company;
};
