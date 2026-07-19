#pragma once

#include "op.h"

class IFactory
{
public:
    virtual ~IFactory() = default;
    virtual Op* CreateOperation() = 0;
};

class AddFactory : public IFactory
{
public:
    Op* CreateOperation() override { return new AddOp(); }
};

class SubFactory : public IFactory
{
public:
    Op* CreateOperation() override { return new SubOp(); }
};

class MulFactory : public IFactory
{
public:
    Op* CreateOperation() override { return new MulOp(); }
};

class DivFactory : public IFactory
{
public:
    Op* CreateOperation() override { return new DivOp(); }
};
