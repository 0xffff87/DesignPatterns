#pragma once
#include "department.h"
#include "user.h"

class IFactory
{
public:
    virtual IUser *CreateUser() = 0;
    virtual IDepartment *CreateDepartment() = 0;
};

class SqlserverFactory : public IFactory
{
public:
    IUser *CreateUser() { return new SqlserverUser(); }
    IDepartment *CreateDepartment() { return new SqlserverDepartment(); }
};

class AccessFactory : public IFactory
{
public:
    IUser *CreateUser() { return new AccessUser(); }
    IDepartment *CreateDepartment() { return new AccessDepartment(); }
};