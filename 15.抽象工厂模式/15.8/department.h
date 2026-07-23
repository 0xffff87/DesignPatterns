#pragma once
#include <string>
#include <iostream>

using namespace std;


class Department
{
    // 书中没有实现
};

class IDepartment
{
public:
    virtual ~IDepartment() = default;
    virtual void Insert(Department *department) = 0;
    virtual Department *GetDepartment(int id) = 0;
};

class SqlserverDepartment : public IDepartment
{
public:
    void Insert(Department *department)
    {
        cout << "在SQL Server中给Department表增加一条记录" << endl;
    }
    Department *GetDepartment(int id)
    {
        cout << "在SQL Server中根据ID得到Department表的一条记录" << endl;
        return nullptr;
    }
};

class AccessDepartment : public IDepartment
{
public:
    void Insert(Department *department)
    {
        cout << "在Access中给Department表增加一条记录" << endl;
    }
    Department *GetDepartment(int id)
    {
        cout << "在Access中根据ID得到Department表的一条记录" << endl;
        return nullptr;
    }
};