#include "expression.h"

#include <iostream>
#include <string>

using namespace std;

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