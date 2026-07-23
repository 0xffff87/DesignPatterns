#pragma once
#include <string>
#include <iostream>

using namespace std;


class User
{
public:
    void SetId(int id) { m_id = id; }
    int GetId() { return m_id; }
    void SetName(string name) { m_name = name; }
    string GetName() { return m_name; }
private:
    int m_id;
    string m_name;
};

class IUser
{
public:
    void Insert(User *user);
    User *GetUser(int id);
};

class SqlserverUser : public IUser
{
public:
    void Insert(User *user)
    {
        cout << "在SQL Server中给User表增加一条记录" << endl;
    }
    User *GetUser(int id)
    {
        cout << "在SQL Server中根据ID得到User表的一条记录" << endl;
        return nullptr;
    }
};

class AccessUser : public IUser
{
public:
    void Insert(User *user)
    {
        cout << "在Access中给User表增加一条记录" << endl;
    }
    User *GetUser(int id)
    {
        cout << "在Access中根据ID得到User表的一条记录" << endl;
        return nullptr;
    }
};