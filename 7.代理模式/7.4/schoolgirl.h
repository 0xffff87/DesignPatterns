#pragma once

#include <string>
#include <iostream>

using namespace std;

class Schoolgirl
{
public:
    Schoolgirl(const string& name) : m_name(name) {}
    string GetName() const { return m_name; }
private:
    string m_name;
};