#pragma once
#include <string>
#include <iostream>

using namespace std;

class Resume
{
public:
    Resume(string name) : m_name(name) { }
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

private:
    string m_name;
    string m_sex;
    int m_age;
    string m_timeArea;
    string m_company;
};