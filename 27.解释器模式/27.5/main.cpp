#include <iostream>
#include "expression.h"
#include <cerrno>

using namespace std;

int main()
{
    PlayContext *context = new PlayContext();
    cout << "上海滩" << endl;
    context->m_text = "O 2 E 0.5 G 0.5 A 3 E 0.5 G 0.5 D 3 E 0.5 G 0.5 A 0.5 O 3 C 1 O 2 A 0.5 G 1 C 0.5 E 0.5 D 3";
    Expression *expression = nullptr;
    try {
        while (context->m_text.size() > 0)
        {
            string str = context->m_text.substr(0, 1);
            if (str == "O")
                expression = new Scale();
            else if (str == "C" || str == "D" || str == "E" || str == "F" || str == "G" || str == "A" || str == "B" || str == "P")
                expression = new Note();

            if (expression == nullptr)
            {
                context->m_text = context->m_text.substr(1);
                continue;
            }

            expression->Interpret(context);
            delete expression;
            expression = nullptr;
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Unknown exception occurred." << std::endl;
    }

    delete context;
    return 0;
}