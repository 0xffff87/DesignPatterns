#pragma once

#include <string>

using namespace std;

class User
{
public:
    User(const string& name) : m_name(name) {}
    string GetName() const { return m_name; }
private:
    string m_name;
};