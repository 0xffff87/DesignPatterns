#pragma once

#include <string>
#include <iostream>
#include <unordered_map>
#include "user.h"

using namespace std;

class WebSite
{
public:
    virtual ~WebSite() = default; // 这里需要一个虚构析函数，以确保派生类的析构函数被正确调用
    virtual void Use(const User& user) = 0;
};

class ConcreteWebSite : public WebSite
{
public:
    ConcreteWebSite(const string& name) : m_name(name) {}
    void Use(const User& user) override
    {
        cout << "网站分类: " << m_name << "，用户: " << user.GetName() << endl;
    }
private:
    string m_name;
};

class WebSiteFactory
{
public:
    WebSite* GetWebSiteCategory(const string& key)
    {
        if (m_websites.find(key) == m_websites.end())
        {
            m_websites[key] = new ConcreteWebSite(key);
        }
        return m_websites[key];
    }

    int GetWebSiteCount() const
    {
        return m_websites.size();
    }
private:
    unordered_map<string, WebSite*> m_websites;
};