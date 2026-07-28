#pragma once

class Singleton 
{
public:
    // 书中返回的是指针，这里改成返回引用，调用时更直接
    // 懒汉式单例：第一次调用 GetInstance 时才创建对象
    // C++11 及以后，函数内静态变量的初始化是线程安全的
    // 如果写成饿汉式，通常会把对象直接做成类外静态成员，或者在类内用 inline static 成员：
    // inline static Singleton instance{};
    // 这样对象会在程序启动阶段就完成初始化，不等第一次调用再创建
    static Singleton& GetInstance()
    {
        static Singleton instance;
        return instance;
    }

private:
    Singleton() = default;
};