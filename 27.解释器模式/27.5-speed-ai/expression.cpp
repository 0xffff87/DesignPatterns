#include "expression.h"

#include <iostream>
#include <string>

using namespace std;

ExpressionFactory &ExpressionFactory::Instance()
{
    static ExpressionFactory factory;
    return factory;
}

void ExpressionFactory::Register(const std::string &key, const std::string &typeName, Creator creator)
{
    registry_[key] = {typeName, std::move(creator)};
}

std::unique_ptr<Expression> ExpressionFactory::Create(const std::string &key) const
{
    auto it = registry_.find(key);
    if (it == registry_.end())
    {
        return nullptr;
    }
    return it->second.second();
}

bool ExpressionFactory::IsSupported(const std::string &key) const
{
    return registry_.find(key) != registry_.end();
}

const std::string &ExpressionFactory::TypeNameOf(const std::string &key) const
{
    static const std::string empty;
    auto it = registry_.find(key);
    if (it == registry_.end())
    {
        return empty;
    }
    return it->second.first;
}

void Expression::Interpret(PlayContext *context)
{
    if (context->m_text.empty())
    {
        return;
    }
    else 
    {
        string playKey = context->m_text.substr(0, 1);
        context->m_text = context->m_text.substr(2);
        size_t pos = context->m_text.find(' ');
        double playValue = std::stod(context->m_text.substr(0, pos));
        context->m_text = context->m_text.substr(pos + 1);
        Excute(playKey, playValue);
    }
}


bool Note::registered_ = Note::RegisterSelf();

void Note::Excute(const std::string& key, double value)
{
    string note = "";
    if (key == "C")
        note = "1";
    else if (key == "D")
        note = "2";
    else if (key == "E")
        note = "3";
    else if (key == "F")
        note = "4";
    else if (key == "G")
        note = "5";
    else if (key == "A")
        note = "6";
    else if (key == "B")
        note = "7";
    cout << note << " ";
}

bool Scale::registered_ = Scale::RegisterSelf();

void Scale::Excute(const std::string& key, double value)
{
    string scale = "";
    switch (static_cast<int>(value))
    {
    case 1:
        scale = "低音";
        break;
    case 2:
        scale = "中音";
        break;
    case 3:
        scale = "高音";
        break;
    default:
        break;
    }
    cout << scale << " ";
}

bool Speed::registered_ = Speed::RegisterSelf();

void Speed::Excute(const std::string& key, double value)
{
    string speed = "";
    if (value < 500.0)
        speed = "快速";
    else if (value >= 1000.0)
        speed = "慢速";
    else
        speed = "中速";
    cout << speed << " ";
}