#pragma once
#include <string>
#include <map>
#include <functional>
#include <stdexcept>

using namespace std;

// 用「类名 -> 创建函数」注册表，模仿 C# 的
// Assembly.Load(...).CreateInstance("命名空间.类名")
class Reflect
{
public:
    using Creator = function<void*()>;

    static void Register(const string& className, Creator creator)
    {
        Registry()[className] = creator;
    }

    static void* CreateInstance(const string& className)
    {
        auto it = Registry().find(className);
        if (it == Registry().end())
        {
            throw runtime_error("CreateInstance failed: " + className);
        }
        return it->second();
    }

private:
    static map<string, Creator>& Registry()
    {
        static map<string, Creator> registry;
        return registry;
    }
};

// 静态注册：程序启动时把具体类挂到注册表
template <typename T>
struct AutoRegister
{
    AutoRegister(const char* className)
    {
        Reflect::Register(className, []() -> void* { return new T(); });
    }
};

#define REGISTER_CLASS(ClassName) \
    static AutoRegister<ClassName> g_auto_register_##ClassName(#ClassName)
