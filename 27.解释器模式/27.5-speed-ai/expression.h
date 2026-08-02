#pragma once

#include "playcontext.h"

#include <functional>
#include <initializer_list>
#include <memory>
#include <string>
#include <unordered_map>

class Expression;

class ExpressionFactory
{
public:
    using Creator = std::function<std::unique_ptr<Expression>()>;

    static ExpressionFactory &Instance();

    void Register(const std::string &key, const std::string &typeName, Creator creator);
    std::unique_ptr<Expression> Create(const std::string &key) const;
    bool IsSupported(const std::string &key) const;
    const std::string &TypeNameOf(const std::string &key) const;

private:
    std::unordered_map<std::string, std::pair<std::string, Creator>> registry_;
};

#define REGISTER_EXPRESSION_CLASS(ClassName, TypeName, ...) \
public: \
    static bool RegisterSelf() { \
        auto &factory = ExpressionFactory::Instance(); \
        std::initializer_list<std::string> keys = {__VA_ARGS__}; \
        for (const auto &key : keys) { \
            factory.Register(key, TypeName, []() { return std::make_unique<ClassName>(); }); \
        } \
        return true; \
    } \
    static bool registered_; \
private:

class Expression
{
public:
    virtual ~Expression() = default;
    void Interpret(PlayContext *context);
    virtual void Excute(const std::string& key, double value) = 0;
};

class Note : public Expression
{
    REGISTER_EXPRESSION_CLASS(Note, "Note", "C", "D", "E", "F", "G", "A", "B", "P")
public:
    void Excute(const std::string& key, double value) override;
};

class Scale : public Expression
{
    REGISTER_EXPRESSION_CLASS(Scale, "Scale", "O")
public:
    void Excute(const std::string& key, double value) override;
};

class Speed : public Expression
{
    REGISTER_EXPRESSION_CLASS(Speed, "Speed", "T")
public:
    void Excute(const std::string& key, double value) override;
};