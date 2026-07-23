#pragma once
#include "user.h"

class IFactory
{
public:
    virtual IUser *CreateUser() = 0;
};

class SqlserverFactory : public IFactory
{
public:
    IUser *CreateUser() { return new SqlserverUser(); }
};

class AccessFactory : public IFactory
{
public:
    IUser *CreateUser() { return new AccessUser(); }
};